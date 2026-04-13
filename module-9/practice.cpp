#include <bits/stdc++.h>
using namespace std;

class Edg
{
public:
    int a, b, c;
    Edg(int a, int b, int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};
int n, e;
int dis[1005];
vector<Edg>Edge_list;

int main()
{
    cin >> n >> e;
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        Edge_list.push_back(Edg(a,b,c));

    }

    for (int i = 0; i < n; i++)
    {
        dis[i]= INT_MAX;
    }
    dis[0]=0;


for (int i = 0; i < n-1; i++)
{
    for (auto ed: Edge_list)
    {
        int a,b,c;
        a=ed.a;
        b=ed.b;
        c=ed.c;
        if(dis[a]!= INT_MAX && dis[a]+c < dis[b])
               dis[b] = dis[a] + c;
    }
    
}



for (int i = 0; i < n; i++)
{
    cout << i << "-> " << dis[i] << endl;
}


    // for (auto ed:Edge_list)
    // {
    //     cout << ed.a << " " << ed.b << " " << ed.c << endl;
    // }
    
    


    return 0;
}