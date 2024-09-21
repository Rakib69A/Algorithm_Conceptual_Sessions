#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int parent[N];
int sz[N];
void dsu_initialize(int n){
    for(int i=1;i<=n;i++){
        parent[i] = -1;
        sz[i] = 1;
    }
}
int dsu_find(int node){
    if(parent[node] == -1)
        return node;
    int leader = dsu_find(parent[node]);
    parent[node] = leader;
    return leader;
}
void union_by_sz(int node1, int node2){
    int leaderA = dsu_find(node1);
    int leaderB = dsu_find(node2);
    if(leaderA == leaderB) return;
    if(sz[leaderA] > sz[leaderB]){
        parent[leaderB] = leaderA;
        sz[leaderA] += sz[leaderB];
    }
    else{
        parent[leaderA] = leaderB;
        sz[leaderB] += sz[leaderA];
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    dsu_initialize(n);
    while(m--){
        int a,b;
        cin>>a>>b;
        union_by_sz(a,b);
    }
    // for(int i=1;i<=n;i++){
    //     cout<<i<<" "<<parent[i]<<endl;
    // }
    vector<int> leaders;
    for(int i=1;i<=n;i++){
        if(parent[i] == -1){
            leaders.push_back(i);
        }
    }
    cout<<leaders.size()-1<<endl;
    for(int i=1;i<leaders.size();i++){
        cout<<leaders[i-1]<<" "<<leaders[i]<<endl;
    }
    return 0;
}