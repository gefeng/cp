#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

using namespace std;

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
    int N, Q;
    cin >> N >> Q;

    vector<map<int, int>> groups(N);
    for(int i = 0; i < N; i++) {
        int C;
        cin >> C;

        groups[i][C] = 1;
    }

    dsu uf(N);    

    for(int i = 0; i < Q; i++) {
        int T, X, Y;
        cin >> T >> X >> Y;

        if(T == 1) {
            X -= 1;
            Y -= 1;

            if(uf.same(X, Y)) {
                continue;
            }

            int p1 = uf.find(X);
            int p2 = uf.find(Y);
            if(uf.size(p1) < uf.size(p2)) {
                for(auto [k, v] : groups[p1]) {
                    groups[p2][k] += v;
                }
            } else {
                for(auto [k, v] : groups[p2]) {
                    groups[p1][k] += v;
                }
            }
            uf.unite(X, Y);
        } else {
            X -= 1;
            
            cout << groups[uf.find(X)][Y] << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
