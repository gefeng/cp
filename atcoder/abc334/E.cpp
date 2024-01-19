#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

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

constexpr std::array<int, 4> DR = {0, 1, 0, -1};
constexpr std::array<int, 4> DC = {1, 0, -1, 0};
constexpr int64_t MOD = (int64_t)998244353;

int64_t q_pow(int64_t x, int64_t y) {
    int64_t res = 1;
    while(y) {
        if(y & 1) {
            res *= x;
            res %= MOD;
        }
        x *= x;
        x %= MOD;
        y >>= 1;
    }
    return res;
}

void run_case() {
    int H, W;
    std::cin >> H >> W;

    std::vector<std::string> G(H);
    for(int i = 0; i < H; i++) {
        std::cin >> G[i];
    }

    dsu uf(H * W);
    int tot_red = 0;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(G[i][j] == '.') {
                tot_red += 1;
            }
            for(int d = 0; d < 4; d++) {
                int ni = i + DR[d];
                int nj = j + DC[d];
                if(ni >= 0 && nj >= 0 && ni < H && nj < W && G[i][j] == G[ni][nj] && G[i][j] == '#') {
                    uf.unite(i * W + j, ni * W + nj);
                }
            }
        }
    }

    int tot_green = 0;
    std::set<int> g;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(G[i][j] == '#') {
                g.insert(uf.find(i * W + j));
            }
        }
    }
    tot_green = g.size();

    int64_t ans = 0;
    int64_t inv_tot_red = q_pow(tot_red, MOD - 2); 
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(G[i][j] == '.') {
                std::set<int> s;
                for(int d = 0; d < 4; d++) {
                    int ni = i + DR[d];
                    int nj = j + DC[d];
                    if(ni >= 0 && nj >= 0 && ni < H && nj < W && G[ni][nj] == '#') {
                        s.insert(uf.find(ni * W + nj));
                    }
                }
                int cnt = s.size();
                
                ans += inv_tot_red * (tot_green - cnt + 1) % MOD;
                ans %= MOD;
            }
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
