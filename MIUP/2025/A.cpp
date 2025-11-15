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
    ll n,k; cin >> n >> k;
    std::map<ll, vector<ll>> gr;
    std::map<ll, ll> indeg;

    f(i,0,n){
        ll x,y; cin >> x >> y;
        string m; cin >> m;
        gr[x].pb(y);
        indeg[y]++;
    }

    std::map<ll, ll> rank;
    auto dfs = [&](auto &dfs, ll x) -> void {
        for(auto y:gr[x]){
            dfs(dfs, y);
            rank[x]=max(rank[x],rank[y]+1);
        }
    };

    std::vector<pair<ll,ll>> ans;
    for(auto &[u,_]:gr){
        if(indeg[u]==0){
            dfs(dfs,u);
            ans.pb({-rank[u],u});
        }
    }

    sort(all(ans));
    f(i,0,min((ll)ans.size(),k)) cout << ans[i].S << '\n';
}
        
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    //int t; cin>>t; while(t--)
    solve();
}