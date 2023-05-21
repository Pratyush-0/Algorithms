#include<iostream>
using namespace std;

//cell stucture
struct cell{
    int wt;
    int val; 
};

//sorting the array of items
void arrange(cell arr[],int n){
    //bubble sort
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            double r1=arr[j].val/arr[j].wt;
            double r2=arr[j+1].val/arr[j+1].wt;
            if(r1<r2){
                //swap
                cell temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }

}


//Knapsack funtion
void knapSack(cell arr[],int n,int cap,double sakitem[]){
    for(int i=0;i<n;i++){
        sakitem[i]=0.0;
    }
    for(int i=0;i<n;i++){
        if(arr[i].wt<=cap){
            sakitem[i]=1.0;
            cap-=arr[i].wt;
        }
        else if (arr[i].wt>cap){
            sakitem[i]=(double)cap/(double)arr[i].wt;
            return;
        }
    }
    return;
}


//main function
int main(void){

    int cap;//max capasity of the sack
    cout<<"enter the capacity of the sack: ";
    cin>>cap;

    int n;//number of items avalible
    cout<<"enter the number of items avalible: ";
    cin>>n;

    //input of items in structure array
    cell items[n];
    for(int i=0;i<n;i++){
        cout<<"enter the the weight of the item: ";
        cin>>items[i].wt;
        cout<<"enter the the value of the item: ";
        cin>>items[i].val;
    }
    
    arrange(items,n);  //arrange the items in non-decreasing order of the ratios

    double sackitem[n];//output array

    knapSack(items,n,cap,sackitem); //calling knapsack

    double profit=0.0;
    for(int i=0;i<n;i++){
        profit+=items[i].val*sackitem[i];
    }
    cout<<"total profit= "<<profit;
    
    return 0;
}