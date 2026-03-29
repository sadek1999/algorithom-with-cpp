#include <bits/stdc++.h>
using namespace std;
char grid[105][105];
bool vis[105][105];
int n, m;
vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}

void dfs(int x, int y)
{

    vis[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        int ci = x + d[i].first;
        int cj = y + d[i].second;
        if (valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] != '#')
        {  dfs(ci,cj);
        }
    }
}


int main()
{

    cin >> n >> m;

    pair<int, int> src = {-1, -1};
    pair<int, int> dis{-1, -1};
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

    if (src.first == -1 || dis.first == -1)
    {
        cout << "NO";
        return 0;
    }
    if (src == dis)
    {
        cout << "YES";
        return 0;
    }
  
    dfs(src.first,src.second);

    vis[dis.first][dis.second] ? cout << "YES" : cout << "NO";
    return 0;
}