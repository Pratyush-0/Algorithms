#include<iostream>
using namespace std;
//strut of the array cell
struct Edge{
    int start;
    int end;
    int wt;
};

void sort(Edge arr[],int ne){
    //bulbul sort
    for(int i=0;i<ne-1;i++){
        for(int j=0;j<ne-i-1;j++){
            if(arr[j].wt>arr[j+1].wt){
                Edge temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

//find if in set
int find(int f,int set[]){
    while(set[f]!=f){
        f=set[f];
    }
    return set[f];
}
//union of sets 
void onion(int s,int e,int set[]){
    int st=find(s,set);
    int ed=find(e,set);
    set[ed]=st;
}

//kruskal function
void kruskal_mst(Edge edset[],int e,int v){
    sort(edset,e);

    int set[v];
    for(int k=0;k<v;k++){
        set[k]=k;
    }
    int ct=0;
    for(int i=0;i<v;i++){
        for(int j=0;j<e;j++){
            if(find(edset[j].start,set)!=find(edset[j].end,set)){
                onion(edset[j].start,edset[j].end,set);
                cout<<edset[j].start<<"->"<<edset[j].end<<"  "<<edset[j].wt<<endl;
                ct++;
            }
            if(ct==v-1){
                break;
            }
        }
    }
}



//main function
int main(void){
    int v,e;
    cout<<"Enter the number of vertices: ";
    cin>>v;
    cout<<"Enter the number of edges: ";
    cin>>e;
    //int visit[v]={0,0,0,0,0};
    Edge edSet[e];
    for(int i=0;i<e;i++){
        cout<<"Enter the starting vertex: ";
        cin>>edSet[i].start;
        cout<<"Enter the ending vertex: ";
        cin>>edSet[i].end;
        cout<<"Enter the weight of the edge: ";
        cin>>edSet[i].wt;
    }

    sort(edSet,e);
    for(int i=0;i<e;i++){
        cout<<edSet[i].wt<<endl;
    }
    kruskal_mst(edSet,e,v);
    


    return 0;
}