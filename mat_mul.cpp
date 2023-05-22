#include<iostream>
using namespace std;

int arr[]={5,4,6,2,7};
int m[5][5]={
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0}
};
int par[5][5]={
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0}
};

// void initial(){
//     for(int i;i<n;i++){
//         for(int j)
//     }
//}
int cost(int i,int j){
    if(i==j){
        return 0;
    }
    return m[i][j];
}

void matAss(int i,int mid,int j){
    int ct=cost(i,mid)+cost(mid+1,j)+arr[i-1]*arr[mid]*arr[j];
    if(m[i][j]!=0){
        if(ct<m[i][j]){
            m[i][j]=ct;
            par[i][j]=mid;
        }
        return;
    }
    m[i][j]=ct;
    par[i][j]=mid;
}

void matMul(int n){
    int i,j,d;
    for(d=1;d<n-1;d++){
        for(i=1;i<n-d;i++){
            for(j=i;j<i+d;j++){
                matAss(i,j,d+i);
            }
        }
    }
}

//main function
int main(void){
    // int n;
    // cout<<"Enter the number of dimentions in the array: ";
    // cin>>n;
    // int arr[n];
    // for(int i=0;i<n;i++){
    //     cout<<"Enter the dimention: ";
    //     cin>>arr[i];
    // }
    int n=5;
    matMul(n);

    cout<<"matrix of waits: "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<m[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"matrix of paranthisis: "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<par[i][j]<<" ";
        }
        cout<<endl;
    }


    return 0;
}