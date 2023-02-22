#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>
#include <queue>

using namespace std;

const array<int, 4> DR{0, 1, 0, -1};
const array<int, 4> DC{1, 0, -1, 0};

void run_case() {
    int H, W;
    cin >> H >> W;

    vector<string> G(H);
    for(int i = 0; i < H; i++) {
        cin >> G[i];
    }

    int sr = 0;
    int sc = 0;
    int tr = 0;
    int tc = 0;
    vector<set<pair<int, int>>> t(26);
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(G[i][j] == 'S') {
                sr = i;
                sc = j;
            }
            if(G[i][j] == 'G') {
                tr = i;
                tc = j;
            }
            if(G[i][j] >= 'a' && G[i][j] <= 'z') {
                int c = G[i][j] - 'a';
                t[c].emplace(i, j);
            }
        }
    }

    queue<pair<int, int>> q;
    vector<vector<bool>> vis(H, vector<bool>(W, false));

    q.emplace(sr, sc);
    vis[sr][sc] = true;
    int d = 0;

    while(!q.empty()) {
        int sz = q.size();
        while(sz--) {
            pair<int, int> cur = q.front();
            q.pop();

            int r = cur.first;
            int c = cur.second;

            if(r == tr && c == tc) {
                cout << d << '\n';
                return;
            }

            for(int i = 0; i < 4; i++) {
                int nr = r + DR[i];
                int nc = c + DC[i];
                if(nr >= 0 && nc >= 0 && nr < H && nc < W && G[nr][nc] != '#' && !vis[nr][nc]) {
                    vis[nr][nc] = true; 
                    q.emplace(nr, nc);
                }
            }

            if(G[r][c] >= 'a' && G[r][c] <= 'z') {
                vector<pair<int, int>> teleported;
                set<pair<int, int>>& s = t[G[r][c] - 'a'];
                for(auto& p : s) { 
                    int nr = p.first;
                    int nc = p.second;
                    if(!vis[nr][nc]) {
                        vis[nr][nc] = true;
                        q.emplace(nr, nc);
                    }
                    teleported.emplace_back(nr, nc);
                }

                for(auto& p : teleported) {
                    s.erase(p);
                }
            }
        }
        
        d += 1;
    }

    cout << -1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
