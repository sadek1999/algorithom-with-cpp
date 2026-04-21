#include <bits/stdc++.h>
using namespace std;
int n, e;
vector<vector<int>> adj_list;
vector<bool> vis;

void dfs(int src)
{
    vis[src] = true;
    for (int x : adj_list[src])
    {
        if (!vis[x])
        {
            vis[x] = true;
            dfs(x);
        }
    }
}

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    while (!q.empty())
    {
        int par = q.front();
        q.pop();
        for (int chil : adj_list[par])
        {
            if (!vis[chil])
            {
                vis[chil] = true;
                q.push(chil);
            }
        }
    }
}

int main()
{

    cin >> n >> e;
    adj_list.resize(n);
    vis.assign(n,false);
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    cout << "ok";
    

    return 0;
}