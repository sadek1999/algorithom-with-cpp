#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[1005];

void connected(int src, int dis)
{
    if (src == dis)
    {
        cout << "YES" << endl;
    }
    else
    {
        auto &d = adj_list[src];
        auto x = find(d.begin(), d.end(), dis);
        if (x != d.end())
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
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
    }

    int q;
    cin >> q;
    while (q--)
    {
        int src, dis;
        cin >> src >> dis;
        connected(src, dis);
    }

    return 0;
}