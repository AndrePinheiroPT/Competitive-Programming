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
    ll n; cin >> n;
    std::vector<ll> a(n,0); f(i,0,n) cin >> a[i];

    std::vector<vector<ll>> gr(n);
    f(i,0,n-1){
        ll x,y; cin >> x >> y;
        x--,y--;
        gr[x].pb(y);
        gr[y].pb(x);
    }

    f(i,0,n){
        std::vector<ll> v; for(auto x:gr[i]) if(a[i]>a[x]) v.pb(a[x]+1);

        ll m = v.size();    
        ll w = a[i];
        std::vector<ll> dp(w+1,0); dp[0]=1;

        f(j,1,m+1) rev(k,w,v[j-1]-1) dp[k] = dp[k-v[j-1]] | dp[k];

        if(!dp[w]){
            cout << "no" << '\n';
            return;
        }
    }

    cout << "yes" << '\n';
    
}
        
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    //int t; cin>>t; while(t--)
    solve();
}