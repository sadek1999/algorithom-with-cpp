#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[1005];
bool vis[1005];
int parent[1005];
int level[1005];

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    level[src] = 0;

    while (!q.empty())
    {
        int par = q.front();
        q.pop();

        for (int chil : adj_list[par])
        {
            if (!vis[chil])
            {
                q.push(chil);
                vis[chil] = true;
                level[chil]= level[par]+1;
                parent[chil] = par;
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    memset(level, -1, sizeof(level));
    memset(vis, false, sizeof(vis));
    memset(parent, -1, sizeof(parent));

    int src, dis;
    cin >> src >> dis;
    bfs(src);

  int node = dis;
  vector<int> x;
  while (node != -1)
  {
    x.push_back(node);
    node = parent[node];
  }

reverse(x.begin(),x.end());

for(auto a: x){
    cout << a << " ";
}
  
    

    return 0;
}