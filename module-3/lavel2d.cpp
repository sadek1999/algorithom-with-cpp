#include <bits/stdc++.h>
using namespace std;
int n, m;
char grid[105][105];
bool vis[105][105];
int level[105][105];
vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}

void bfs(int si , int sj){
    queue<pair<int,int>>q;
    q.push({si,sj});
    vis[si][sj]=true;
    level[si][sj]=0;
    // cout << "inside";

    while (!q.empty())
    {
        auto p= q.front();
        q.pop();
        int pi= p.first;
        int pj= p.second;
        // cout << pi << " " << pj << endl;
        for (int i = 0; i < 4; i++)
        {
            int ci = pi+ d[i].first;
            int cj = pj + d[i].second;
            if(valid(ci,cj) && !vis[ci][cj]){
                q.push({ci,cj});
                vis[ci][cj]= true;
                level[ci][cj]=level[pi][pj] + 1;
            }
        }
        
    }
    
    
}

int main()
{
cin >> n >> m;
for (int  i = 0; i < n; i++)
{
    for (int j = 0; j < m; j++)
    {
        cin >> grid[i][j];
    }
    
}

memset(vis,false,sizeof(vis));
int si,sj,di,dj;
cin >> si >> sj >> di >> dj;
// cout << si << sj;
bfs(si,sj);

cout << level[di][dj];

    return 0;
}