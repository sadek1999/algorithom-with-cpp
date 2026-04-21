#include <bits/stdc++.h>
using namespace std;
int n ,e;
vector<vector<pair<int,int>>>adj_list;
vector<int>dis;


void dij(int src){
     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
     pq.push({0,src});
     dis[0]= 0;
     while (!pq.empty())
     {
         auto par = pq.top();
         pq.pop();
         int par_node= par.second;
         int par_dis= par.first;

         for (auto chil: adj_list[par_node])
         {
            int chil_node = chil.first;
            int chil_dis = chil.second;
            if(dis[par_node] + chil_dis < dis[chil_node]){
                dis[chil_node] = dis[par_node] + chil_dis;
                pq.push({dis[chil_node],chil_node});
            }
         }
         
     }
     
}


int main()
{
    cin >> n >> e;
    adj_list.resize(n);
    dis.resize(n);

   
    while (e--)
    {
        int a,b,c;
        cin >> a >> b >> c;
        adj_list[a].push_back({b,c});
        adj_list[b].push_back({a,c});


    }

    for (int  i = 0; i < n; i++)
    {
        dis[i] = INT_MAX;
    }
   


    dij(0);

    for (int i = 0; i < n; i++)
    {
        cout << i << "->" << dis[i] << endl ;
    }
    

    // for (int i = 0; i < n; i++) {
    //     cout  << i << "->  ";
    //     for (auto x : adj_list[i]) {
    //         cout << " " << x.first << "  " << x.second ;
    //     }
    //     cout << endl;
    // }
    
    
    
    

    
    return 0;
}