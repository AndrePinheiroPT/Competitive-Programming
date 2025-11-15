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
const ll mod = 998244353;


void solve(){
    ll w,h; cin >> w >> h;
    ll n; cin >> n;
    std::vector<pair<ll,ll>> a;
    f(i,0,n){
        ll x,y; cin >> x >> y;
        a.pb({x,y});
    }

    std::vector<vector<ll>> dp(w+1,vector<ll>(h+1,INF));
    dp[0][0]=0;
    f(i,1,w+1) dp[i][0]=0;
    f(i,1,h+1) dp[0][i]=0;

    f(i,1,w+1){
        f(j,1,h+1){
            bool ok = 0;
            for(auto &[x,y]:a){
                if(i-x>=0 && j-y>=0){
                    ok=1;
                    dp[i][j]=min(dp[i][j],min(dp[i-x][j]+dp[x][j-y], dp[i][j-y]+dp[i-x][y]));
                }
            }
            if(!ok) dp[i][j] = i*j;
        }
    }

    cout << dp[w][h] << '\n';
}
        
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    solve();
}