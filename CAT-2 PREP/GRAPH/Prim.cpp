#include<iostream>
using namespace std;
#define INF 9999

void prim(int graph[4][4],int V){
    bool visited[V];

    //Intially no vertex is visited
    for(int i=0;i<V;i++){
        visited[i]=false;
    }

    visited[0]=true;

    int totalWeight=0;

    for(int count=0;count< V-1;count++){
        int minWeight=INF;
        int u=-1;
        int v=-1;

        //find smallest edge connecting
        //visited vertex to unvistied vertex
        for(int i=0;i<V;i++){
            if(visited[i]){
                for(int j=0;j<V;j++){
                    if(!visited[j] && graph[i][j] != 0 && graph[i][j]<minWeight){
                        minWeight=graph[i][j];
                        u=i;
                        v=j;
                    }
                }
            }
        }
        cout<<u<<" - "<<v<<" = "<<minWeight<<endl;
        totalWeight+=minWeight;

        visited[v]=true;
    }
    cout<<"Total Weight= "<<totalWeight<<endl;
}


int main(){
    int V=4;
    int graph[4][4]={
        {0,10,6,5},
        {10,0,0,15},
        {6,0,0,4},
        {5,15,4,0}
    };
    prim(graph,V);
    return 0;
}