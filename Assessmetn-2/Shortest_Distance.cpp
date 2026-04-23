#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e15;

int main()
{

    int n, e;
    cin >> n >> e;

    long long adj_mat[n + 1][n + 1];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                adj_mat[i][j] = 0;
            else
                adj_mat[i][j] = INF;
        }
    }

    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        if (c < adj_mat[a][b])
        {
            adj_mat[a][b] = c;
        }
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (adj_mat[i][k] < INF && adj_mat[k][j] < INF)
                {
                    if (adj_mat[i][k] + adj_mat[k][j] < adj_mat[i][j])
                    {
                        adj_mat[i][j] = adj_mat[i][k] + adj_mat[k][j];
                    }
                }
            }
        }
    }

    int q;
    cin >> q;
    while (q--)
    {
        int src, dst;
        cin >> src >> dst;

        if (adj_mat[src][dst] >=INF)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << adj_mat[src][dst] << endl;
        }
    }

    return 0;
}