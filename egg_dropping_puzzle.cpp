#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <unordered_set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <climits>
using namespace std;
typedef long long int ll;
#define EPS 1e-9
#define pb push_back
#define FOR(i, k, n) for (i = k; i < n; i++)
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define ln "\n"
bool isPrime(int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}
ll power(ll x, ll y, ll p)
{
    ll ans = 1;
    x = x % p;
    if (x == 0)
        return 0;
    while (y)
    {
        if (y & 1)
            ans = (ans * x) % p;
        y >>= 1;
        x = (x * x) % p;
    }
    return ans;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        int i, j;
        FOR(i, 0, n+1)
        {
            FOR(j, 0, k+1)
            {
                if (j == 0 || i == 0) //no of floors is 0 or no of eggs is 0
                {
                    dp[i][j] = 0;
                    continue;
                }
                if (i == 1)
                {
                    dp[i][j] = j;
                    continue;
                }
                if (j == 1)
                {
                    dp[i][j] = 1;
                    continue;
                }
                int f;
                int min = INT_MAX;
                FOR(f, 1, j + 1)
                {
                    int temp = 1 + max(dp[i - 1][f - 1], dp[i][j - f]);
                    if(temp<min)
                        min = temp;
                }
                dp[i][j]=min;
            }
        }
        cout << dp[n][k] << ln;
    }
    return 0;
}
// 2
// 2 10
// 3 5

// 4
// 3
