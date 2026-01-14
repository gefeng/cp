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
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<std::pair<int, int>> a;
    for(int i = 0; i < N - 1; i++) {
        a.emplace_back(i, i + 1);
    }

    std::ranges::sort(a, [&](const auto& x, const auto& y) {
                return std::abs(A[x.first] - A[x.second]) > std::abs(A[y.first] - A[y.second]);
            });

    dsu uf(N);
    std::vector<int64_t> ans(N, 0);
    int64_t sum = 0;
    for(int k = N - 1, i = 0; k >= 1; k--) {
        while(i < N - 1 && std::abs(A[a[i].first] - A[a[i].second]) >= k) {
            int p1 = uf.find(a[i].first);
            int p2 = uf.find(a[i].second);
            if(p1 != p2) {
                int64_t s1 = uf.size(p1);
                int64_t s2 = uf.size(p2);
                sum -= (s1 - 1) * s1 / 2 + (s2 - 1) * s2 / 2;
                uf.unite(a[i].first, a[i].second);
                int64_t s = uf.size(a[i].first);
                sum += (s - 1) * s / 2;
            }
            i += 1;
        }
        ans[k] = sum;
    }

    for(int k = 1; k < N; k++) {
        std::cout << ans[k] << " \n"[k == N - 1];
    }
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
