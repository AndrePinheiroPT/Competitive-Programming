#include <bits/stdc++.h>

using namespace std;

#ifdef local
    #include "debug.hpp"
    #define pr(...) debug(#__VA_ARGS__, __VA_ARGS__)
    #define prs(...) debug_nameless(__VA_ARGS__)
#else
    #define pr(...) 0
    #define prs(...) 0
#endif

typedef long double ld;
typedef int64_t ll;
typedef uint64_t ull;

#define pb push_back
#define F first
#define S second

#define all(x) x.begin(),x.end()
#define f(i,a,b) for (int i=a; i<b; ++i)
#define rev(i,a,b) for (int i=a; i>b; --i)

const ll N = 1e5+5;
const ll INF = LLONG_MAX/4;
const int inf = INT_MAX;
const ll mod = 1e9+7;


void solve(){
    ll n, k; cin >> n >> k;
    std::vector<char> a(n); f(i,0,n) cin >> a[i];

    vector<vector<vector<ll>>> dp(3,vector<vector<ll>>(n+1,vector<ll>(k+1,0)));

    f(i,1,n+1){
        dp[0][i][0] = dp[0][i-1][0]+(a[i-1]=='S');
        dp[1][i][0] = dp[1][i-1][0]+(a[i-1]=='H');
        dp[2][i][0] = dp[2][i-1][0]+(a[i-1]=='P');
    }

    f(i,1,n+1){
        f(j,1,k+1){
            dp[0][i][j] = (a[i-1]=='S')+max(dp[1][i-1][j-1],max(dp[2][i-1][j-1],dp[0][i-1][j]));
            dp[1][i][j] = (a[i-1]=='H')+max(dp[0][i-1][j-1],max(dp[2][i-1][j-1],dp[1][i-1][j]));
            dp[2][i][j] = (a[i-1]=='P')+max(dp[1][i-1][j-1],max(dp[0][i-1][j-1],dp[2][i-1][j]));
        }
    }

    ll ans = 0; f(i,0,k+1) f(j,0,3) ans = max(ans, dp[j][n][i]);
    cout << ans << '\n';
}
        
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
    //int t; cin>>t; while(t--)
    solve();
}