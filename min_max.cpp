#include<iostream>
using namespace std;

void min_max(int arr[],int low,int high,int &max,int &min){
    if(low==high){
        max=arr[low];
        min=arr[low];
        return;
    }
    if(low+1==high){
        if(arr[low]<=arr[high]){
            min=arr[low];
            max=arr[high];
        }
        else{
            min=arr[high];
            max=arr[low];
        }
        return;
    }
    int mid=(high+low)/2;
    int maxl,minl,maxr,minr;
    min_max(arr,low,mid,maxl,minl);
    min_max(arr,mid+1,high,maxr,minr);
    if(maxl<maxr) max=maxr;
    if(maxl>maxr) max=maxl;
    if(minl>minr) min=minr;
    if(minl<minr) min=minl;
    return;
}

int main(void){
    int n=5;
    int arr[n]={10,3,64,33,45};
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int max=arr[0], min=arr[0];
    min_max(arr,0,n-1,max,min);
    cout<<"max term is "<<max<<"min term is "<<min<<endl;
    return 0;
}