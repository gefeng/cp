#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <tuple>
#include <queue>

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
    
    std::vector<std::tuple<int, int, int>> E;
    std::vector<std::vector<int>> A(N, std::vector<int>(N, 0));
    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            int W;
            std::cin >> W;
            E.emplace_back(W, i, j);
            A[i][j] = W;
            A[j][i] = W;
        }
    }

    std::ranges::sort(E);

    dsu uf(N);
    std::vector<std::vector<std::pair<int, int>>> G(N);
    for(auto [w, u, v] : E) {
        if(uf.same(u, v)) {
            continue;
        }
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
        uf.unite(u, v);
    }

    auto get_dist = [&](int s) {
        std::queue<int> q;
        std::vector<int> dist(N, 0);

        q.emplace(s);
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                int v = q.front();
                q.pop();
                for(auto [u, w] : G[v]) {
                    if(dist[u] == 0) {
                        dist[u] = dist[v] + w;
                        q.emplace(u);
                    }
                }
            }
        }
        return dist;
    };

    for(int i = 0; i < N; i++) {
        std::vector<int> dist = get_dist(i);
        for(int j = i + 1; j < N; j++) {
            if(dist[j] != A[i][j]) {
                std::cout << "No" << '\n';
                return;
            }
        }
    } 

    std::cout << "Yes" << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
