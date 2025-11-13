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
    int n,m,c; cin >> n >> m >> c;
    std::vector<int> a(n,0); f(i,0,n) cin >> a[i];

    vector<pair<int,int>> edgs;
    f(i,0,m){
        int x,y; cin >> x >> y;
        edgs.pb({x-1,y-1});
    }

    ll s = 0; f(i,0,n) s+=a[i];
    s = sqrt(s)+5;

    std::vector<vector<int>> dp(n+1,vector<int>(s+1,-inf));
    dp[0][0] = 0;

    

    f(t,1,s+1){
        for(auto &[x,y]:edgs){
            if(dp[x][t-1]!=-inf) if(dp[x][t-1]+a[y]+c*(t-1)*(t-1)-c*t*t > dp[y][t]){
                dp[y][t]=dp[x][t-1]+a[y]+c*(t-1)*(t-1)-c*t*t ;
            }
        }
    }

    int ans = -inf; f(i,1,s+1) ans=max(ans,dp[0][i]);
    cout << ans << '\n';
}
        
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("time.in", "r", stdin);
    freopen("time.out", "w", stdout);
    //int t; cin>>t; while(t--)
    solve();
}