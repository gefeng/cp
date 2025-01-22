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

void run_case() {
    int N, M_1, M_2;
    std::cin >> N >> M_1 >> M_2;

    std::set<std::pair<int, int>> s_1;
    std::set<std::pair<int, int>> s_2;
    dsu uf_1(N);
    dsu uf_2(N);
    for(int i = 0; i < M_1; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        if(U > V) {
            std::swap(U, V);
        }
        s_1.emplace(U, V);
    }

    for(int i = 0; i < M_2; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        if(U > V) {
            std::swap(U, V);
        }
        s_2.emplace(U, V);
        uf_2.unite(U, V);
    }

    int ans = 0;
    for(auto [u, v] : s_1) {
        if(uf_2.same(u, v)) {
            uf_1.unite(u, v);
        } else {
            ans += 1;
        }
    } 

    for(auto [u, v] : s_2) {
        if(!uf_1.same(u, v)) {
            uf_1.unite(u, v);
            ans += 1;
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
