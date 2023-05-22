#include<iostream>
using namespace std;
int n=4;
int grf[4][4]={
    {0,1,3,6},
    {9999,0,1,9999},
    {9999,9999,0,1},
    {9999,9999,9999,0}
};
int temp[4][4];
//floyd warshalh function
void floyd(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            temp[i][j]=grf[i][j];
        }
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                temp[i][j]=min(temp[i][j],temp[i][k]+temp[k][j]);
            }
        }
    }
    //print result
    for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<temp[i][j]<<" ";
            }
            cout<<endl;
        }
}

//main function
int main(void){
    floyd();

    return 0;
}