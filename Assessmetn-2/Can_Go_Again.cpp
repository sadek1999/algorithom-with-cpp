#include <bits/stdc++.h>
using namespace std;
int n, e;

class Egd
{
public:
    int a, b;
    long long c;
    Egd(int a, int b, long long c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};
vector<Egd> ege_list;
vector<long long> dis;

void bellmen_ford(int src)
{
    dis[src] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (auto ed : ege_list)
        {
            int a = ed.a;
            int b = ed.b;
            long long c = ed.c;
            if (dis[a] != INT_MAX && dis[a] + c < dis[b])
            {
                
                dis[b] = dis[a] + c;
               
            }
        }
    }
}

int main()
{
    cin >> n >> e;
    dis.assign(n + 1, INT_MAX);
    while (e--)
    {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        ege_list.push_back({Egd(a, b, c)});
    }
    int src, t;
    cin >> src >> t;
    bellmen_ford(src);

    bool cycle = false;
    for (auto ed : ege_list)
    {
        int a = ed.a;
        int b = ed.b;
        long long c = ed.c;
        if (dis[a] != INT_MAX && dis[a] + c < dis[b])
        {
            cycle = true;
        }
    }

    if (cycle)
    {
        cout << "Negative Cycle Detected";
    }
    else
    {
        while (t--)
        {
            int x;
            cin >> x;
            dis[x] == INT_MAX ? cout << "Not Possible" << endl : cout << dis[x] << endl;
        }
    }

    return 0;
}