#include <bits/stdc++.h>
using namespace std;
 int n ,e;
class Edg{
    public:
    int a, b,c;
    Edg(int a, int b, int c){
        this->a=a;
        this->b=b;
        this->c=c;
    }
};
vector<Edg>edge_list;
vector<int>dis;


void bellmen_flor(int src){
    dis[src]=0;
    for (int i = 0; i < n-1; i++)
    {
        for (auto ed: edge_list)
        {
            int a = ed.a;
            int b= ed.b;
            int c=ed.c;

            if( dis[a]!= INT_MAX && dis[a] + c < dis[b]){
                dis[b]= dis[a]+c;
            }
        }
        
    }
    
}

int main()
{
   
    cin >> n >> e;
    
    dis.resize(n);
    while (e--)
    {
        int a,b,c;
        cin >> a >> b>> c;
        edge_list.push_back({Edg(a,b,c)});
    }

    for (int i = 0; i < n; i++)
    {
        dis[i]=INT_MAX;
    }
bellmen_flor(0);
    
    cout << "ok";
    
    
    return 0;
}