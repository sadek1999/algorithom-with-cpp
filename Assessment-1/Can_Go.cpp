#include <bits/stdc++.h>
using namespace std;
char grid[105][105];
bool vis[105][105];
int n, m;
vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

pair<int, int> src;
pair<int, int> dis;

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}
void bfs(pair<int,int> src)
{
    queue<pair<int ,int >> q ;
    q.push(src);
    vis[src.first][src.second]= true;
    while (!q.empty())
    {
         auto par = q.front();
         q.pop();
         int pi= par.first;
         int pj = par.second;
         for (int i = 0; i < 4; i++)
         {
            int ci = pi+d[i].first;
            int cj = pj +d[i].second;
            if(valid(ci,cj) && !vis[ci][cj] && grid[ci][cj] != '#'){
                q.push({ci,cj});
                vis[ci][cj] = true;
            }
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
            cin >> grid[i][j];
          
            if (grid[i][j] == 'A')
                src = {i, j};
            if (grid[i][j] == 'B')
                dis = {i, j};
        }
       
    }

    memset(vis, false, sizeof(vis));
    bfs(src);
    
    vis[dis.first][dis.second]? cout << "YES": cout << "NO";
    return 0;
}