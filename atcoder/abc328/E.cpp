#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t INF = (int64_t)1e18;

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
    int64_t K;
    std::cin >> N >> M >> K;
    
    std::vector<std::vector<int64_t>> E(M, std::vector<int64_t>(3, 0));
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < 3; j++) {
            std::cin >> E[i][j];
        }
    }

    int max_v = 1 << M;
    int64_t ans = INF;
    for(int i = 0; i < max_v; i++) {
        if(__builtin_popcount(i) == N - 1) {
            dsu uf(N);
            int64_t sum = 0;
            bool ok = true;
            for(int j = 0; j < M; j++) {
                if(i & (1 << j)) {
                    int u = E[j][0] - 1;
                    int v = E[j][1] - 1;
                    int64_t w = E[j][2];
                    if(uf.same(u, v)) {
                        ok = false;
                        break;
                    }
                    sum += w;
                    sum %= K;
                    uf.unite(u, v);
                }
            }

            if(ok) {
                ans = std::min(ans, sum);
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
