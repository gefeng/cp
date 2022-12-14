#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

struct dsu {
public:
    dsu() : _n(0) {}
    explicit dsu(int n) : _n(n), _parent_or_size(n, -1) {}

    int find(int a) {
        assert(a >= 0 && a < _n);
        if(_parent_or_size[a] < 0) return a;
        return find(_parent_or_size[a]); 
    }

    void unite(int a, int b) {
        assert(a >= 0 && a < _n);
        assert(b >= 0 && b < _n);
        int x = find(a), y = find(b);
        if(x == y) return;
        if(-_parent_or_size[x] < -_parent_or_size[y]) std::swap(x, y);
        _parent_or_size[x] += _parent_or_size[y];
        _parent_or_size[y] = x;
    }

    bool same(int a, int b) {
        assert(a >= 0 && a < _n);
        assert(b >= 0 && b < _n);
        return find(a) == find(b);
    }

    int size(int a) {
        assert(a >= 0 && a < _n);
        return -_parent_or_size[find(a)];
    }

    std::vector<std::vector<int>> groups() {
        std::vector<std::vector<int>> res(_n);
        std::vector<int> group_size(_n, 0);
        for(int i = 0; i < _n; i++) {
            group_size[find(i)]++;
        }
        for(int i = 0; i < _n; i++) {
            res[i].reserve(group_size[i]);
        }
        for(int i = 0; i < _n; i++) {
            res[find(i)].push_back(i);
        }
        // erase-remove idiom: remove all empty vector in linear time
        res.erase(
            std::remove_if(res.begin(), res.end(), 
                           [](const std::vector<int>& v) { return v.empty(); }), 
            res.end());
        return res;
    }

private:
    int _n;
    // if root then -1 * component_size
    // else parent
    std::vector<int> _parent_or_size;
};

const array<int, 4> DR{0, 1, 0, -1};
const array<int, 4> DC{1, 0, -1, 0};

int dfs(vector<string>& G, vector<vector<bool>>& vis, int M, int r, int c) {
    vis[r][c] = true;
    int cnt = 1;
    if(r == 0) {
        if(G[r + 1][c] == 'B' && !vis[r + 1][c]) {
            cnt += dfs(G, vis, M, r + 1, c);
        } else if(c + 1 < M && G[r][c + 1] == 'B') {
            cnt += dfs(G, vis, M, r, c + 1);
        }
    } else {
        if(G[r - 1][c] == 'B' && !vis[r - 1][c]) {
            cnt += dfs(G, vis, M, r - 1, c);
        } else if(c + 1 < M && G[r][c + 1] == 'B') {
            cnt += dfs(G, vis, M, r, c + 1);
        }
    }
    return cnt;
}

void run_case() {
    int M;
    cin >> M;
    
    vector<string> g(2);
    for(int i = 0; i < 2; i++) {
        cin >> g[i];
    }

    auto encode = [&](int r, int c) {
        return r * M + c;
    };

    dsu uf(2 * M);
    int tot = 0;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < M; j++) {
            if(g[i][j] == 'W') continue;
            tot += 1;
            for(int d = 0; d < 4; d++) {
                int ni = i + DR[d];
                int nj = j + DC[d];
                if(ni >= 0 && nj >= 0 && ni < 2 && nj < M && g[ni][nj] == 'B') {
                    uf.unite(encode(i, j), encode(ni, nj)); 
                }
            }
        }
    }

    
    for(int i = 0; i < M; i++) {
        if(g[0][i] == 'B' || g[1][i] == 'B') {
            int cnt = 0;
            if(g[0][i] == 'B') {
                vector<vector<bool>> vis(2, vector<bool>(M, false));
                cnt = dfs(g, vis, M, 0, i); 
                if(cnt == tot) {
                    cout << "Yes" << '\n';
                    return;
                }
            } 

            if(g[1][i] == 'B') {
                vector<vector<bool>> vis(2, vector<bool>(M, false));
                cnt = dfs(g, vis, M, 1, i); 
                if(cnt == tot) {
                    cout << "Yes" << '\n';
                    return;
                }
            } 

            break;
        }
    }

    cout << "No" << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    while(T--) {
        run_case();
    }
}
