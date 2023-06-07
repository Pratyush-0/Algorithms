#include<iostream>
using namespace std;

struct edge{
    int st,end,wt;
};

//display 
void display(int k,int parent[]){
    if(k==-1){
        return;
    }
    display(parent[k],parent);
    cout<<k<<"--";
    return;
}

//belman_ford funciton
void bellmanFord(edge edset[],int ed,int vt,int src){
    int dist[vt];
    int parent[vt];
    for(int i=0;i<vt;i++){
        dist[i]=9999;
        parent[i]=-1;
    }
    dist[src]=0;
    int u,v,w;
    for(int j=0;j<vt-1;j++){
        for(int i=0;i<ed;i++){
            u=edset[i].st;
            v=edset[i].end;
            w=edset[i].wt;
            if(dist[u]+w<dist[v]){
                dist[v]=dist[u]+w;
                parent[v]=u;
            }
        }
    }
    for(int i=0;i<vt;i++){
        display(i,parent);
        cout<<">"<<dist[i]<<endl;
    }
}

//main function
int main(void){
    int v,e;
    cout<<"enter the number of vertexs: ";
    cin>>v;
    cout<<"enter the number of edges: ";
    cin>>e;
    edge edSet[e];
    for(int i=0;i<e;i++){
        cout<<"Enter the starting vertex: ";
        cin>>edSet[i].st;
        cout<<"Enter the ending vertex: ";
        cin>>edSet[i].end;
        cout<<"Enter the weight vertex: ";
        cin>>edSet[i].wt;
    }
    int src;
    cout<<"enter the source vertex: ";
    cin>>src;
    bellmanFord(edSet,e,v,src);

    return 0;
}