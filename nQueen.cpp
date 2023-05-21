#include<iostream>
using namespace std;

bool isSafe(int** arr,int x,int y,int n){
    
    //no queen on top
    for(int row=0;row<x;row++){
        if(arr[row][y]==1){
            return false;
        }
    }

    //no queen on left diagonal
    int row=x;
    int col=y;
    while(row>=0 && col>=0){
        if(arr[row][col]==1){
            return false;
        }
        row--;
        col--;
    }

    //no queen on right diagonal
    row=x;
    col=y;
    while(row>=0 && col<n){
        if(arr[row][col]==1){
            return false;
        }
        row--;
        col++;
    }

    //when no attact
    return true;
}


bool nQueen(int** arr,int x,int n){
    //when the row count becomes equal to n then all quens placed
    if(x>=n){
        return true;
    }
    for(int col=0;col<n;col++){
        if(isSafe(arr,x,col,n)){
            arr[x][col]=1;
            if(nQueen(arr,x+1,n)){
                return true;
            }
            arr[x][col]=0; //backtract
        }
    }
    return false;

}

//main function
int main(void){
    int n;
    cout<<"enter the number of queens: ";
    cin>>n;
    int** arr=new int*[n];
    for(int i=0;i<n;i++){
        arr[i]=new int[n];
        for(int j=0;j<n;j++){
            arr[i][j]=0;
        }
    }

    if(nQueen(arr,0,n)){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<arr[i][j]<<"  ";
            }
            cout<<endl;
        }
    }

    return 0;
}