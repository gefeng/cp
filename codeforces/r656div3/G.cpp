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
    std::vector<int> B(N);
    std::vector<int> freq(N, 0);
    std::vector<int> col1(N, -1);
    std::vector<int> col2(N, -1);
    dsu uf(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        A[i] -= 1;
        freq[A[i]] += 1;
        if(col1[A[i]] == -1) {
            col1[A[i]] = i;
        } else {
            col2[A[i]] = i;
        }
    }

    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
        B[i] -= 1;
        freq[B[i]] += 1;
        if(col1[B[i]] == -1) {
            col1[B[i]] = i;
        } else {
            col2[B[i]] = i;
        }
        uf.unite(A[i], B[i]);
    }

    for(int i = 0; i < N; i++) {
        if(freq[i] != 2) {
            std::cout << -1 << '\n';
            return;
        }
    }

    std::vector<int> color(N, -1);
    for(int i = 0; i < N; i++) {
        if(A[i] == B[i]) {
            continue;
        }
        int x = A[i];
        int c = i;
        while(color[c] == -1) {
            if(A[c] == x) {
                color[c] = 0;
                x = B[c];
                c = col1[x] == c ? col2[x] : col1[x];
            } else {
                color[c] = 1; 
                x = A[c];
                c = col1[x] == c ? col2[x] : col1[x];
            }
        }
    }

    int ans = 0;
    std::vector<int> pos;
    std::vector<int> cnt(N, 0);
    for(int i = 0; i < N; i++) {
        if(A[i] == B[i]) {
            continue;
        }
        int p = uf.find(A[i]);
        cnt[p] += color[i]; 
    }

    for(int i = 0; i < N; i++) {
        if(color[i] == -1) {
            continue;
        }
        int p = uf.find(A[i]);
        int s = uf.size(A[i]);
        if(cnt[p] < s - cnt[p]) {
            if(color[i] == 1) {
                pos.push_back(i);
            } 
        } else {
            if(color[i] == 0) {
                pos.push_back(i);
            }
        }
    }

    ans = pos.size();
    std::cout << ans << '\n';
    for(int i = 0; i < ans; i++) {
        std::cout << pos[i] + 1 << " \n"[i == ans - 1];
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
