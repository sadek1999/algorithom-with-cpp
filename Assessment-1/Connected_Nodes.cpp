#include <bits/stdc++.h>
using namespace std;
vector<int>adj_lis[1005];

void connect ( int x){
    auto &a = adj_lis[x];
    if(a.empty()){
                cout << -1 << endl;
    }else{
sort(a.begin(),a.end(),greater<int>());
    for (int y : a)
    {
           cout << y << " ";
    }
    cout << endl;
    }

    
    
}

int main()
{
    int n ,e;
    cin >> n >> e;
    while (e--)
    {
       int a,b;
       cin >> a >> b;
       adj_lis[a].push_back(b);
       adj_lis[b].push_back(a);
    }
    
   int q;
   cin >> q;
   while (q--)
   {
          int p;
          cin >> p;
           connect(p);
          
   }
   
    
   

    return 0;
}