#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int MAX = 10;

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
    
    std::vector<std::array<int, 3>> A(M);
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < 3; j++) {
            std::cin >> A[i][j];
        }
    }

    std::sort(A.begin(), A.end());

    std::vector<std::vector<std::vector<std::pair<int, int>>>> seg(MAX + 1, 
            std::vector<std::vector<std::pair<int, int>>>(MAX + 1));

    for(auto& a : A) {
        int st = ((a[0] - 1) % a[1]) + 1;
         
        std::vector<std::pair<int, int>>& s = seg[st][a[1]];
        
        if(!s.empty() && a[0] <= s.back().second) {
            s.back().second = std::max(s.back().second, a[0] + a[1] * a[2]);
        } else {
            s.emplace_back(a[0], a[0] + a[1] * a[2]);
        }
    }

    dsu uf(N + 1);    
    for(int i = 1; i <= MAX; i++) {
        for(int j = 1; j <= MAX; j++) {
            for(auto [l, r] : seg[i][j]) {
                for(int x = l; x <= r; x += j) {
                    uf.unite(l, x);
                }                
            }
        }
    }

    std::cout << uf.groups().size() - 1 << '\n';
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
