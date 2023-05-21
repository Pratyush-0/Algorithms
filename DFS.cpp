#include<iostream>
using namespace std;
#define N 500
class Stack{
    int top=-1;
    int arr[N];
    public:
        bool isEmpty(){
            if(top==-1){
                return true;
            }
            return false;
        }
        void push(int item){
            top++;
            arr[top]=item;
            return;
        }
         int pop(){
            int x=arr[top];
            top--;
            return x;
         }
};

int main(void){
    Stack s;
    int mat[7][7]={
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0},
    };
    int visit[7]={0,0,0,0,0,0,0};
    int i=0;
    visit[i]=1; 
    s.push(i);
    cout<<i;
    while (s.isEmpty() == true){
        int expo=s.pop();
        for(int j=0;j<7;j++){
            if(mat[expo][j]==1 && visit[j]==0){
                visit[j]=1;
                cout<<j;
                s.push(j);
            }
        }
    }
    
    return 0;
}