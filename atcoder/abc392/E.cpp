#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

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

    std::vector<std::pair<int, int>> E(M);
    for(int i = 0; i < M; i++) {
        std::cin >> E[i].first >> E[i].second;
        E[i].first -= 1;
        E[i].second -= 1;
    }

    dsu uf(N);
    std::vector<std::tuple<int, int, int>> rem;
    for(int i = 0; i < M; i++) {
        auto [u, v] = E[i];
        if(uf.same(u, v)) {
            rem.emplace_back(u, v, i);
        } else {
            uf.unite(u, v);
        }
    }

    if(uf.size(0) == N) {
        std::cout << 0 << '\n';
        return;
    }
    
    std::map<int, std::vector<std::tuple<int, int, int>>> m;
    for(auto [u, v, i] : rem) {
        int p = uf.find(u); 
        m[p].emplace_back(u, v, i);
    }

    int head = m.begin()->first;
    std::vector<std::tuple<int, int, int>> edges = m[head];
    
    m.erase(head);
    
    std::vector<std::tuple<int, int, int>> ans;
    for(auto& [v, e] : m) {
        auto [x, y, i] = edges.back();
        edges.pop_back();
        
        ans.emplace_back(i, y, v);
        uf.unite(head, v);
        
        for(auto t : e) {
            edges.push_back(t);
        }

        head = uf.find(head);
    }

    for(int i = 0; i < N; i++) {
        if(uf.same(head, i)) {
            continue;
        }
        
        auto [x, y, idx] = edges.back();
        edges.pop_back();

        ans.emplace_back(idx, y, i);
        uf.unite(head, i);
    
        head = uf.find(head);
    }

    int size = ans.size();
    std::cout << size << '\n';
    for(int i = 0; i < size; i++) {
        auto [idx, x, y] = ans[i];
        std::cout << idx + 1 << ' ' << x + 1 << ' ' << y + 1 << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
