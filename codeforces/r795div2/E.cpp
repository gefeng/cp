#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>
#include <tuple>
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

struct E {
    int c;
    int p;
    int s;
    int idx;
    E(int _c, int _p, int _s, int _idx) : c(_c), p(_p), s(_s), idx(_idx) {}
};

void run_case() {
    int N;
    std::cin >> N;

    std::vector<E> events;
    std::vector<std::tuple<int, int, int>> A(N);
    for(int i = 0; i < N; i++) {
        int C, L, R;
        std::cin >> C >> L >> R;
        
        A[i] = {C, L, R + 1};
        events.emplace_back(C, L, 0, i);
        events.emplace_back(C, R + 1, 1, i);
    }

    std::ranges::sort(events, [](const auto& x, const auto& y) {
                if(x.p == y.p) {
                    return x.s < y.s;
                }
                return x.p < y.p;
            });

    int n = N << 1;
    std::vector<std::set<std::pair<int, int>>> m(2);
    dsu uf(N);
    for(int i = 0; i < n; ) {
        int j = i;
        while(i < n && events[j].p == events[i].p) {
            if(events[i].s == 1) {
                std::pair<int, int> key(events[i].p, events[i].idx);
                int c = events[i].c;
                if(m[c].find(key) != m[c].end()) {
                    m[c].erase(key);
                }
            } 
            i += 1;
        }

        std::array<int, 2> merge = {};
        for(int k = j; k < i; k++) {
            auto [c, p, s, idx] = events[k];
            if(s == 0) {
                m[c].emplace(std::get<2>(A[idx]), idx);
                merge[c ^ 1] = 1;
            }
        }

        for(int k = j; k < i; k++) {
            auto [c, p, s, idx] = events[k];
            if(s == 0) {
                if(!m[c ^ 1].empty()) {
                    uf.unite(m[c ^ 1].begin()->second, idx);
                }
            }
        }

        for(int k = 0; k < 2; k++) {
            if(merge[k]) {
                while(m[k].size() > 1) {
                    uf.unite(m[k].rbegin()->second, m[k].begin()->second);
                    m[k].erase(m[k].begin());
                }
            }
        }

    }

    std::cout << uf.groups().size() << '\n';
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
