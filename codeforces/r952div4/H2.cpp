#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>
#include <map>

constexpr std::array<int, 4> DR = {0, 1, 0, -1};
constexpr std::array<int, 4> DC = {1, 0, -1, 0};

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

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::string> G(N);
    for(int i = 0; i < N; i++) {
        std::cin >> G[i];
    }    

    dsu uf(N * M);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(G[i][j] == '#') {
                for(int d = 0; d < 4; d++) {
                    int ni = i + DR[d];
                    int nj = j + DC[d];
                    if(ni >= 0 && nj >= 0 && ni < N && nj < M && G[ni][nj] == '#') {
                        uf.unite(i * M + j, ni * M + nj);
                    }
                }
            }
        }
    }

    int ans = 0;
    std::vector<int> sum_r(N + 2, 0);
    std::vector<int> sum_c(M + 2, 0);
    std::vector<int> sum_dot(M, 0);
    std::vector<std::vector<int>> remove(N + 2, std::vector<int>(M + 2, 0));
    std::map<int, std::pair<int, int>> top_l;
    std::map<int, std::pair<int, int>> bot_r;
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < M; c++) {
            if(G[r][c] == '#') {
                int h = uf.find(r * M + c);
                if(top_l.find(h) == top_l.end()) {
                    top_l[h] = {r, c};
                } else {
                    auto& [x, y] = top_l[h];
                    x = std::min(x, r);
                    y = std::min(y, c);
                }

                if(bot_r.find(h) == bot_r.end()) {
                    bot_r[h] = {r, c};
                } else {
                    auto& [x, y] = bot_r[h];
                    x = std::max(x, r);
                    y = std::max(y, c);
                }
            }
        }
    }

    for(auto [h, p1] : top_l) {
        auto p2 = bot_r[h]; 
        int rl = std::max(0, p1.first - 1);
        int rr = std::min(N - 1, p2.first + 1);
        int cl = std::max(0, p1.second - 1);
        int cr = std::min(M - 1, p2.second + 1);
        int size = uf.size(h);

        sum_r[rl + 1] += size;
        sum_r[rr + 2] -= size;
        sum_c[cl + 1] += size;
        sum_c[cr + 2] -= size;

        remove[rl + 1][cl + 1] += size;
        remove[rl + 1][cr + 2] -= size;
        remove[rr + 2][cl + 1] -= size;
        remove[rr + 2][cr + 2] += size;
    }

    for(int r = 1; r <= N; r++) {
        sum_r[r] += sum_r[r - 1];
    }

    for(int c = 1; c <= M; c++) {
        sum_c[c] += sum_c[c - 1];
    }
    
    for(int r = 1; r <= N; r++) {
        for(int c = 1; c <= M; c++) {
            remove[r][c] += remove[r - 1][c] + remove[r][c - 1] - remove[r - 1][c - 1];
        }
    }

    for(int c = 0; c < M; c++) {
        for(int r = 0; r < N; r++) {
            if(G[r][c] == '.') {
                sum_dot[c] += 1;
            }
        }
    }

    for(int r = 0; r < N; r++) {
        int cnt = 0;
        for(int c = 0; c < M; c++) {
            if(G[r][c] == '.') {
                cnt += 1;
            }
        }

        for(int c = 0; c < M; c++) {
            ans = std::max(ans, sum_r[r + 1] + sum_c[c + 1] - remove[r + 1][c + 1] + cnt + sum_dot[c] - (G[r][c] == '.' ? 1 : 0));
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
