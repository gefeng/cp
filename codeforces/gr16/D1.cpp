#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

struct fenwick_tree {
    int n;
    std::vector<int> ft;
    fenwick_tree(int _n) : n(_n + 1), ft(n, 0) {}
    
    void update(int i, int v) {
        for(++i; i < n; i += i & -i) {
            ft[i] += v;
        }
    }
    
    int query(int i) {
        int res = 0;
        for(++i; i > 0; i -= i & -i) {
            res += ft[i];
        }
        return res;
    }
};

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::pair<int, int>> A(M);
    for(int i = 0; i < M; i++) {
        std::cin >> A[i].first;
        A[i].second = i;
    }

    std::sort(A.begin(), A.end(), [](const auto& a, const auto& b) {
                if(a.first == b.first) {
                    return a.second > b.second;
                }
                return a.first < b.first;
            });

    std::vector<int> seat(M, 0);
    for(int i = 0; i < M; i++) {
        seat[A[i].second] = i;
    }

    fenwick_tree ft(M);

    int64_t ans = 0;
    for(int i = 0; i < M; i++) {
        int s = seat[i];
        ans += ft.query(s - 1);
        ft.update(s, 1);  
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
