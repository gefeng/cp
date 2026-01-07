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
    } void unite(int a, int b) {
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

void dfs(std::vector<std::vector<std::pair<int, int>>>& G, int v, int c, std::vector<int>& vis, std::string& ans) {
    vis[v] = 1;
    for(auto [u, e] : G[v]) {
        if(ans[e] == '#') {
            ans[e] = static_cast<char>((c ^ 1) + '0');
        }
        if(!vis[u]) {
            dfs(G, u, c ^ 1, vis, ans);
        }
    }
}

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<std::pair<int, int>>> G(N);
    std::vector<std::pair<int, int>> E;
    for(int i = 0; i < M; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        G[U].emplace_back(V, i);
        G[V].emplace_back(U, i);
        E.emplace_back(U, V);
    }

    if(M == N - 1) {
        std::cout << std::string(M, '0') << '\n';
        return;
    }

    int must_have = -1;
    while(true) {
        dsu uf(N);
        std::string ans(M, '0');
        std::vector<int> redu;
        if(must_have != -1) {
            uf.unite(E[must_have].first, E[must_have].second);
            redu.push_back(must_have);
        }

        for(int i = 0; i < M; i++) {
            if(i == must_have) {
                continue;
            }
            auto [u, v] = E[i];
            if(uf.same(u, v)) {
                ans[i] = '1';
                redu.push_back(i);
            } else {
                uf.unite(u, v);
            }
        }

        if(redu.size() == 3) {
            std::map<int, int> m;
            for(int e : redu) {
                m[E[e].first] += 1;
                m[E[e].second] += 1;
            }
            for(auto [_, f] : m) {
                if(f != 2) {
                    std::cout << ans << '\n';
                    return;
                }
            }

            for(int e : redu) {
                if(e != must_have) {
                    must_have = e;
                    break;
                }
            }
        } else {
            std::cout << ans << '\n';
            return;
        }
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
