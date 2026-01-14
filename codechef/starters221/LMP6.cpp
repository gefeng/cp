#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

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
    int64_t N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> A(N, std::vector<int>(M, 0));
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            std::cin >> A[i][j];
        }
    }

    bool sorted = true;
    for(int i = 0, x = 1; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(A[i][j] != x++) {
                sorted = false;
            }
        }
    }

    if(sorted) {
        std::cout << N * M + 1 << '\n';
        return;
    }

    auto check = [&](int t) {
        int n = M * N;
        dsu uf(n);
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if((i + 1) * (j + 1) >= t) {
                    uf.unite(i * M + j, 0);
                }
                if((i + 1) * (M - j) >= t) {
                    uf.unite(i * M + j, M - 1);
                }
                if((N - i) * (j + 1) >= t) {
                    uf.unite(i * M + j, (N - 1) * M);
                }
                if((N - i) * (M - j) >= t) {
                    uf.unite(i * M + j, (N - 1) * M + M - 1);
                }
            }
        }

        bool ok = true;
        std::vector<std::vector<int>> groups = uf.groups();
        for(auto& g : groups) {
            int size = g.size();
            std::vector<int> values(size);
            for(int i = 0; i < size; i++) {
                values[i] = A[g[i] / M][g[i] % M];
            }
            std::ranges::sort(values);

            for(int i = 0; i < size; i++) {
                int p = g[i];
                if(p + 1 != values[i]) {
                    ok = false;
                }
            }
        }
        return ok;
    };

    int lo = 2;
    int hi = N * M;
    int ans = 0;
    while(lo <= hi) {
        int mid = (lo + hi) >> 1;
        
        if(check(mid)) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
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
