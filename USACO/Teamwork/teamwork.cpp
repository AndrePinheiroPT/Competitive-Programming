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
    ll n,k; cin >> n >> k;
    std::vector<ll> a(n+1,0); f(i,1,n+1) cin >> a[i];

    std::vector<ll> dp(n+1,0);
    f(i,1,n+1){
        ll mx = a[i], c=1;
        dp[i] = mx;
        rev(j,i-1,max((ll)(-1),i-k-1)){
            dp[i] = max(dp[i], dp[j]+c*mx);
            mx = max(mx, a[j]); c++;
        }
    }

    pr(dp);
    cout << dp[n] << '\n';

}
        
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("teamwork.in", "r", stdin);
    freopen("teamwork.out", "w", stdout);
    //int t; cin>>t; while(t--)
    solve();
}