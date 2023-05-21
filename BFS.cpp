#include<iostream>
using namespace std;
#define N 500
class Queue{
    int arr[N];
    int front=-1;
    int rear=-1;
    public:
        bool isEmpty(){                 //isEmpty
            if(rear==front){
                return true;
            }
            return false;
        }
        void enqueue(int item){         //push in queue
            arr[++rear]=item;
            return;
        }
        int dequeue(){                 //pop from queue
            int x=arr[front];
            front++;
            return x;
        }
};


//main funtion
int main(void){
    Queue q;
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
    cout<<i;
    visit[i]=1;
    q.enqueue(i);
    while(q.isEmpty()==false){
        int expo=q.dequeue();
        for(int j=0;j<7;j++){
            if(mat[expo][j]==1 && visit[j]==0){
                visit[j]=1;
                cout<<j;
                q.enqueue(j);
            }
        }
    }
    return 0;
}