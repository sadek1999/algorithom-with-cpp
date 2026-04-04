#include <bits/stdc++.h>
using namespace std;
// vector<vector<pair<int,int>>>adj_list;
vector<pair<int,int>>adj_list[1005];

int main()
{
    int n,e;
    cin >> n >> e;
    while (e--)
    {
         int a,b,c;
         cin >> a >> b >> c;
         adj_list[a].push_back({b,c});
         adj_list[b].push_back({a,c});

    }

    for (int i = 0; i < n; i++)
    { cout << i << "->";
        for(auto x : adj_list[i] ){
            cout << x.first << " " << x.second << ",";
        }
        cout << endl;
        
    }
    
    
    return 0;
}