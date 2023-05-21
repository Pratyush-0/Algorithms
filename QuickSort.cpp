#include<iostream>
using namespace std;

//printing array
void printArray (int arr[], int n){
    cout<<"the array is: "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

//partition funtion
int partition(int arr[],int l,int h){
    int pivot=arr[l];
    int i=l,j=h;
    while(i<j){
       while(arr[i]<=pivot && i<=h){
        i++;
       }
    
        while(arr[j]>pivot && j>=0){
            j--;
        }
        if(i<j){
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    
    arr[l]=arr[j];
    arr[j]=pivot;
    return j;
}

//quicksort funtion
void quickSort(int arr[], int l,int h){
    if(l<h){
        int j=partition(arr,l,h);
        quickSort(arr,l,j-1);
        quickSort(arr,j+1,h);
    }
    // printArray(arr,h+1);
    return;
}



//main funtion
int main(void){
    int n=7;
    // cout<<"enter the size of the element:";
    // cin>>n;
    int arr[7]={12,43,76,3,65,41,88};
    // for(int i=0;i<n;i++){
    //     cout<<"enter the element to be inserted:";
    //     cin>>arr[i];
    // }
    // cout<<endl; 

   
    printArray(arr,n);
    quickSort(arr,0,n-1);
    printArray(arr,n);                                  
    

    return 0;
}