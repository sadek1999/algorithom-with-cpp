#include <bits/stdc++.h>
using namespace std;

vector<int>adj_list[1005];
bool vis[1005];

void Dfs(int src){
    cout << src << " ";
    vis[src]= true;
    for (int child: adj_list[src])
    {
        if(!vis[child])
        Dfs(child);
    }
    
}

int main()
{
    int n,e;
    cin >> n >> e;
    while (e--)
    {
        int a,b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);

    }



    Dfs(0);
    
    
    return 0;
}