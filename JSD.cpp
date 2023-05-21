#include<iostream>
using namespace std;

//job structure
struct Job{
    string id;
    int dl;
    int prof;
};

//arrange in profit decreasing order
void arrange(Job arr[],int n){
    //bulbul sort
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1;j++){
            if(arr[i].prof<arr[i+1].prof){
                //swap
                Job temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
            }
        }
    }
}

//main jsd function
void JSD(Job arr[],int n,string res[],bool slot[],int& proft){
    //inisialise the result and slot arrays 
    for(int i=0;i<n;i++){
        slot[i]=false;
        res[i]="";
    }
    proft=0;
    for(int i=0;i<n;i++){
        for(int j=min(n,arr[i].dl)-1;j>=0;j--){
            if(slot[j]==false){
                res[j]=arr[i].id;
                slot[j]=true;
                proft+=arr[i].prof;
                break;
            }
        }
    }
}



//main function
int main(void){
    int n;  //number of jobs
    cout<<"enter the number of jobs: ";
    cin>>n;

    Job arr[n];  //array of Jobs
    for(int i=0;i<n;i++){
        cout<<"enter the job name: ";
        cin>>arr[i].id;
        cout<<"enter the deadline: ";
        cin>>arr[i].dl;
        cout<<"enter the profit: ";
        cin>>arr[i].prof;
    }

    arrange(arr,n); //arraged in max-min profit order

    string result[n];
    bool slot[n];
    int profit;
    JSD(arr,n,result,slot,profit);
    for(int i=0;i<n-1;i++){
        cout<<result[i]<<"";
    }
    cout<<endl<<"The total profit is "<<profit<<endl;
    return 0;
}