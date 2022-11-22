#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>

using namespace std;
using LL = long long;

void run_case() {
    int H, W, N;
    cin >> H >> W >> N;

    int S_X, S_Y, G_X, G_Y;
    cin >> S_X >> S_Y >> G_X >> G_Y;
    S_X -= 1;
    S_Y -= 1;
    G_X -= 1;
    G_Y -= 1;

    map<int, set<int>> r_m;
    map<int, set<int>> c_m;
    for(int i = 0; i < N; i++) {
        int X, Y;
        cin >> X >> Y;
        X -= 1;
        Y -= 1;
        
        r_m[X].insert(Y);
        c_m[Y].insert(X);
    }

    queue<pair<int, int>> q;
    set<LL> vis;
    
    q.emplace(S_X, S_Y);
    vis.insert(1LL * S_X * W + S_Y);

    int ans = 0;
    while(!q.empty()) {
        int sz = q.size(); 
        while(sz--) {
            pair<int, int> cur = q.front();
            q.pop();

            int r = cur.first;
            int c = cur.second;
            
            if(r == G_X && c == G_Y) {
                cout << ans << '\n';
                return;
            }

            for(int i = 0; i < 4; i++) {
                int nr = r;
                int nc = c;
                if(i == 0) {  // down
                    nr = H - 1;
                    if(c_m.find(c) != c_m.end()) {
                        set<int>& s = c_m[c]; 
                        auto it = s.upper_bound(r);
                        if(it != s.end()) {
                            nr = (*it) - 1;
                        }
                    }
                    if(nr == H - 1) {
                        continue;
                    }
                } else if(i == 1) { // right
                    nc = W - 1;
                    if(r_m.find(r) != r_m.end()) {
                        set<int>& s = r_m[r];
                        auto it = s.upper_bound(c);
                        if(it != s.end()) {
                            nc = (*it) - 1;
                        }
                    }
                    if(nc == W - 1) {
                        continue;
                    }
                } else if(i == 2) { // up
                    nr = 0;
                    if(c_m.find(c) != c_m.end()) {
                        set<int>& s = c_m[c];
                        auto it = s.upper_bound(r);
                        if(it != s.begin()) {
                            it--;
                            nr = (*it) + 1;
                        }
                    }
                    if(nr == 0) {
                        continue;
                    }
                } else if(i == 3) { // left
                    nc = 0;
                    if(r_m.find(r) != r_m.end()) {
                        set<int>& s = r_m[r];
                        auto it = s.upper_bound(c);
                        if(it != s.begin()) {
                            it--;
                            nc = (*it) + 1;
                        }
                    }
                    if(nc == 0) {
                        continue;
                    }
                }

                LL h = 1LL * nr * W + nc;
                if(vis.find(h) == vis.end()) {
                    vis.insert(h);
                    q.emplace(nr, nc);
                }
            } 
        }
        ans += 1;
    }

    cout << -1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
