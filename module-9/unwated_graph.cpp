#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>adj_list;
bool vis[105];


void dfs(int src){
    vis[src] = true;
    for (int child:adj_list[src] )
    {
       if(!vis[child])
              dfs(child);
    }
    
}


void bfs(int src){
    queue<int>q;
    q.push(src);
    vis[src] = true;
    while (!q.empty())
    {
         int parent= q.front();
         q.pop();
       for (int chil:adj_list[parent])
       {
            if(!vis[chil]){
                q.push(chil);
                vis[chil]=true;
            }
       }
       
    }
    
}


int main()
{
    int n ,e;
    cin >> n >> e;
    adj_list.resize(n+1);
    
  while (e--)
  {
   int a, b;
   cin >> a>> b;
   adj_list[a].push_back(b);
   adj_list[b].push_back(a);
   
  }
  
    
memset(vis,false,sizeof(vis));

// for (int i; i < n ; i++)
// {
//    for (int x:adj_list[i])
//    {
//         cout << x << " ";
//    }
//    cout << endl;
   
// }



    return 0;
}