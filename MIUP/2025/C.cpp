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
    ll c,m,s; cin >> c >> m >> s;
    std::vector<vector<ll>> cand(c,vector<ll>(s,0));
    std::vector<vector<ll>> party(m,vector<ll>(s,0));

    f(i,0,c) f(j,0,s) cin >> cand[i][j];
    f(i,0,m) f(j,0,s) cin >> party[i][j];


    std::map<ll,vector<ll>> rank;
    f(z,0,m){
        vector<ll> rec(c+1,1);
        cand.pb(party[z]);
        f(i,0,m){
            std::vector<pair<ll,ll>> ds;
            f(j,0,c+1){
                ll dist = 0; f(k,0,s) dist+=(cand[j][k]-party[i][k])*(cand[j][k]-party[i][k]);
                ds.pb({dist,j});
            } 

            sort(all(ds));
            if(ds[0].F==ds[1].F) continue;
            else rec[ds[0].S]++; 
        }
        cand.pop_back();

        bool ok=1; f(i,0,c) if(rec[c]<=rec[i]) ok=0;
        if(ok) rank[rec[c]].pb(z);
    }

    if(rank.empty()) cout << "Not My Time" << '\n';
    else{
        auto &[u,v] = *rank.rbegin();
        sort(all(v));

        cout << u << '\n';
        set<vector<ll>> allPrefs; for(auto x:v) allPrefs.insert(party[x]);
        for(auto pr:allPrefs) f(i,0,pr.size()) cout << pr[i] << (i!=pr.size()-1?' ':'\n');
      
    }
}
        
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    //int t; cin>>t; while(t--)
    solve();
}