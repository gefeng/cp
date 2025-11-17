#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>

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
    int64_t X, Y;
    std::cin >> N >> X >> Y;

    std::vector<std::tuple<char, int64_t, int64_t>> A(N);
    for(int i = 0; i < N; i++) {
        auto& [x, y, z] = A[i];
        std::cin >> x >> y >> z;
    }

    std::vector<std::array<int64_t, 4>> now;
    now.push_back({0, 0, X - 1, Y - 1});

    for(int i = 0; i < N; i++) {
        auto [c, a, b] = A[i];
        std::vector<std::array<int64_t, 4>> nxt;

        if(c == 'X') {
            for(auto& r : now) {
                if(r[2] < a) {
                    nxt.push_back({r[0], r[1] - b, r[2], r[3] - b});
                } else if(r[0] >= a) {
                    nxt.push_back({r[0], r[1] + b, r[2], r[3] + b});
                } else {
                    nxt.push_back({r[0], r[1] - b, a - 1, r[3] - b});
                    nxt.push_back({a, r[1] + b, r[2], r[3] + b});
                }
            }
        } else {
            for(auto& r : now) {
                if(r[3] < a) {
                    nxt.push_back({r[0] - b, r[1], r[2] - b, r[3]});
                } else if(r[1] >= a) {
                    nxt.push_back({r[0] + b, r[1], r[2] + b, r[3]});
                } else {
                    nxt.push_back({r[0] - b, r[1], r[2] - b, a - 1});
                    nxt.push_back({r[0] + b, a, r[2] + b, r[3]});
                }
            }
        }
        
        now = std::move(nxt);
    }

    auto intersect = [](int l1, int r1, int l2, int r2) {
        if(l1 > l2) {
            std::swap(l1, l2);
            std::swap(r1, r2);
        }
        return l2 <= r1;
    };

    auto connect = [&](int i, int j) {
        if(now[i][2] == now[j][0] - 1 || now[j][2] == now[i][0] - 1) {
            if(intersect(now[i][1], now[i][3], now[j][1], now[j][3])) {
                return true;
            }
        }
        if(now[i][1] == now[j][3] + 1 || now[i][3] == now[j][1] - 1) {
            if(intersect(now[i][0], now[i][2], now[j][0], now[j][2])) {
                return true;
            }
        }
        return false;
    };

    int size = now.size();
    dsu uf(size);
    for(int i = 0; i < size; i++) {
        for(int j = i + 1; j < size; j++) {
            if(connect(i, j)) {
                uf.unite(i, j);
            }
        }
    }

    std::vector<std::vector<int>> groups = uf.groups();
    size = groups.size();
    std::cout << size << '\n';
    
    std::vector<int64_t> cells;
    for(int i = 0; i < size; i++) {
        int64_t cnt = 0;
        for(int j : groups[i]) {
            cnt += (now[j][2] - now[j][0] + 1) * (now[j][3] - now[j][1] + 1);
        }
        cells.push_back(cnt);
    }

    std::ranges::sort(cells);

    for(int i = 0; i < size; i++) {
        std::cout << cells[i] << " \n"[i == size - 1];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
