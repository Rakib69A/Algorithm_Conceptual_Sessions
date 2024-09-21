#include <bits/stdc++.h>
using namespace std;
const int N = 1000;
bool vis[N][N];
int dis[N][N];
pair<int, int> parent[N][N];
int n, m;
char grid[N][N];
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}
void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    dis[si][sj] = 0;
    while ((!q.empty()))
    {
        pair<int, int> par = q.front();
        q.pop();
        int a = par.first;
        int b = par.second;
        for (int i = 0; i < 4; i++)
        {
            int ci = a + d[i].first;
            int cj = b + d[i].second;
            if (valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] != '#')
            {
                vis[ci][cj] = true;
                q.push({ci, cj});
                dis[ci][cj] = dis[a][b] + 1;
                parent[ci][cj] = {a, b};
            }
        }
    }
}
int main()
{
    int si, sj;
    int di, dj;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'A')
            {
                si = i;
                sj = j;
            }
            else if (grid[i][j] == 'B')
            {
                di = i;
                dj = j;
            }
        }
    }
    memset(vis, false, sizeof(vis));
    memset(dis, -1, sizeof(dis));
    memset(parent, -1, sizeof(parent));
    bfs(si, sj);
    if (vis[di][dj])
    {
        cout << "YES" << endl;
        cout << dis[di][dj] << endl;
        pair<int, int> x = {di, dj};
        vector<pair<int, int>> path;
        while (!(x.first == si && x.second == sj))
        {
            path.push_back(x);
            x = parent[x.first][x.second];
        }
        path.push_back({si,sj});
        reverse(path.begin(), path.end());
        for(int i=1;i<path.size();i++){

            if(path[i-1].first == path[i].first){
                // L/R
                if(path[i-1].second < path[i].second){
                    cout<<"R";
                }else{
                    cout<<"L";
                }
            }else{
               // U/D
               if(path[i-1].first < path[i].first){
                    cout<<"D";
               }else{
                cout<<"U";
               }
            }

            // int a = path[i].first - path[i-1].first;
            // int b = path[i].second - path[i-1].second;
            // // if(a == 0 && b == -1) cout<<"L";
            // else if(a == 0 && b == 1) cout<<"R";
            // else if(a==-1 && b==0) cout<<"U";
            // else cout<<"D";
        }
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}