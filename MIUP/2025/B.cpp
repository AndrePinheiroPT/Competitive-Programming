
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
    std::vector<string> gr(5); f(i,0,5) cin >> gr[i];
    std::vector<vector<int>> s(5,vector<int>(5,0)); f(i,0,5) f(j,0,5) s[i][j] = (gr[i][j]=='X');

    auto BIT = [&](int r, int c){ return 1 << (r*5+c); };

    int init = 0;
    f(i,0,5) f(j,0,5) if(gr[i][j] == 'X') init |= BIT(i,j);

    auto toggle = [&](int &m, int r, int c) {
        if(0 <= r && r < 5 && 0 <= c && c < 5) m ^= BIT(r, c);
    };

    auto press = [&](int &m, int r, int c){
        toggle(m, r, c);
        toggle(m, r-1, c);
        toggle(m, r+1, c);
        toggle(m, r, c-1);
        toggle(m, r, c+1);
    };

    f(mask,0,1<<5){
        int board = init;
        int presses = 0;

        f(c,0,5) if(mask&(1<<c)){
            presses |= BIT(0, c);
            press(board,0,c);
        }

        f(r,1,5) f(c,0,5) {
            if(board & BIT(r-1, c)) {
                presses |= BIT(r, c);
                press(board, r, c);
            }
        }

        bool ok = true;
        f(c,0,5) if(board & BIT(4, c)) ok = false;

        if(ok){
            vector<int> ans;
            f(i,0,25) if(presses&(1<<i)) ans.pb(i);
            if(ans.size() <= 100){
                for(auto x:ans) cout << x << " ";
                cout << '\n';
                return;
            }
        }
    }

    cout << "Impossible" << '\n';    
}
        
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    //int t; cin>>t; while(t--)
    solve();
}