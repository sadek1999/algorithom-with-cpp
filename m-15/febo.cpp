#include <bits/stdc++.h>
using namespace std;
int dp[10005];

int fibo(int n)
{

    if (n < 2)
        return n;
    if (dp[n] != -1)
        return dp[n];
    dp[n] = fibo(n - 1) + fibo(n - 2);
    return dp[n];
}
int main()
{
    int n;
    cin >> n;
    memset(dp, -1, sizeof(dp));

    cout << fibo(n);

    return 0;
}