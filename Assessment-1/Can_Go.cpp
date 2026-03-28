#include <bits/stdc++.h>
using namespace std;
char grid[105][105];
pair<int, int> src;
pair<int, int> dis;

int main()
{
    int n, m;
    cin >> n >> m;
    // cout << n << m ;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            // cout << grid [i][j] << " ";
            if (grid[i][j] == 'A')
                src = {i, j};
            if (grid[i][j] == 'B')
                dis = {i, j};
        }
        // cout << endl;
    }
  cout << "src = " << src.first << " " << src.second ;
  cout << "dis = " << dis.first << " " << dis.second ;
    return 0;
}