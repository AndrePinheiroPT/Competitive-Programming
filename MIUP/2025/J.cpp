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

struct State{ int x, y, d; };

void solve(){
    int H, W; cin >> H >> W;
    vector<string> g(H); f(i,0,H) cin >> g[i];

    pair<int,int> start{-1,-1}, goal{-1,-1};
    f(i,0,H) f(j,0,W) if(g[i][j]=='O') start={i,j}; else if(g[i][j]=='X') goal={i,j};
        

    vector<vector<bool>> valid(H, vector<bool>(W, false));
    f(i,0,H) f(j,0,W){
        bool ok = 1;
        f(di,-1,2) f(dj,-1,2){
            int ni=i+di, nj=j+dj;
            if(0 <= ni && ni < H && 0 <= nj && nj < W && g[ni][nj]!='#') continue;
            
            ok = false;
        }
        valid[i][j] = ok;
    }

    // Directions: 0=up,1=right,2=down,3=left
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = { 0, 1, 0,-1};

    vector<vector<array<bool,4>>> vis(H, vector<array<bool,4>>(W, {0,0,0,0}));
    struct Prev { int px, py, pd; char cmd; };
    vector<vector<array<Prev,4>>> prev(H, vector<array<Prev,4>>(W));

    f(i,0,H) f(j,0,W) f(d,0,4) prev[i][j][d] = Prev{-1,-1,-1,0};

    queue<State> q;
    vis[start.F][start.S][0] = true;
    prev[start.F][start.S][0] = Prev{-1,-1,-1,0};
    q.push(State{start.F, start.S, 0});

    bool found = false;
    State goalState{-1,-1,-1};

    while(!q.empty() && !found){
        State cur = q.front(); q.pop();
        int x = cur.x, y = cur.y, d = cur.d;

        // Check goal (any direction accepted)
        if(x == goal.F && y == goal.S){
            found = true;
            goalState = cur;
            break;
        }

        // Try L: rotate left (counterclockwise)
        int nd = (d+3)%4;
        if(!vis[x][y][nd]){
            vis[x][y][nd] = true;
            prev[x][y][nd] = Prev{x,y,d,'L'};
            q.push(State{x,y,nd});
        }

        // Try R: rotate right (clockwise)
        nd = (d+1)%4;
        if(!vis[x][y][nd]){
            vis[x][y][nd] = true;
            prev[x][y][nd] = Prev{x,y,d,'R'};
            q.push(State{x,y,nd});
        }

        // Try F: move forward one tile in dir d
        int nx = x + dx[d], ny = y + dy[d];
        if(0 <= nx && nx < H && 0 <= ny && ny < W && valid[nx][ny]){
            if(!vis[nx][ny][d]){
                vis[nx][ny][d] = true;
                prev[nx][ny][d] = Prev{x,y,d,'F'};
                q.push(State{nx,ny,d});
            }
        }
    }

    if(!found){
        cout << "IMPOSSIBLE" << '\n';
        return;
    }

    // Reconstruct path
    string ans;
    State cur = goalState;
    while(!(cur.x == start.F && cur.y == start.S && cur.d == 0)){
        Prev p = prev[cur.x][cur.y][cur.d];
        if(p.px == -1) break; 
        ans.pb(p.cmd);
        cur = State{p.px, p.py, p.pd};
    }
    reverse(all(ans));
    cout << ans << "\n";
}
        
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    //int t; cin>>t; while(t--)
    solve();
}