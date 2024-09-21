#include <bits/stdc++.h>
using namespace std;
int n, m;
char graph[100][100];
const int N = 1e5 + 5;
bool vis[100][100];
// vector<pair<int,int>> d = {{0,1},{0,-1},{-1,0},{1,0}};
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
bool valid(int x, int y){
    if(x>=0 && x<n && y>=0 && y<m && graph[x][y]=='.')
        return true;
    else
        return false;
}
void dfs(int si, int sj){
    // cout<<si<<" "<<sj<<endl;
    vis[sj][sj] = true;
    for(int i=0;i<4;i++){
        // int ci = si + d[i].first;
        // int cj = sj + d[i].second;
        int ci = si + dx[i];
        int cj = sj + dy[i];
        if(valid(ci,cj)==true && vis[ci][cj]==false){
            vis[ci][cj] = true;
            dfs(ci,cj);
        }
    }

}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> graph[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << graph[i][j];
        }
        cout<<endl;
    }
    // int si,sj;
    // cin>>si>>sj;
    memset(vis,false,sizeof(vis));
    //Check for the components
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(graph[i][j]=='.' && vis[i][j] == false){
                // vis[i][j]=true;
                dfs(i,j);
                cnt++;   
            }
        }
    }
    cout<<"Country - "<<cnt<<endl;
    // dfs(0,2);
    // cout<<vis[0][2]<<endl;
    return 0;
}