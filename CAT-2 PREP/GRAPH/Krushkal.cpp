#include<iostream>
#include<algorithm>

using namespace std;

struct Edge{
    int u;
    int v;
    int weight;
};
int parent[100];

int find(int x){
    if(parent[x]==x){
        return x;
    }

    return parent[x]=find(parent[x]);
}

void unionSet(int u,int v){
    u=find(u);
    v=find(v);

    parent[v]=u;
}

void krushkal(Edge edges[],int V,int E){
    //step-1 sort
    sort(edges,edges+E,[](Edge a,Edge b){
        return a.weight<b.weight;
    });

    for(int i=0;i<V;i++){
        parent[i]=i;
    }

    int totalWeight=0;
    int edgeCount=0;

    for(int i=0;i<E;i++){
        int u=edges[i].u;
        int v=edges[i].v;

        if(find(u)!=find(v)){
            cout<<u<<" - "<<v<<" = "<<edges[i].weight<<endl;
            totalWeight+=edges[i].weight;
            edgeCount++;
            unionSet(u,v);
        }

        if(edgeCount==V-1){
            break;
        }
    }

    cout<<"Total Weight="<<totalWeight;
}

int main(){
    int V=4;
    int E=5;
    Edge edges[]={
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    krushkal(edges,V,E);
    return 0;
}