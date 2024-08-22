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

    int n = N * M;
    std::vector<std::pair<int, int>> A(n);
    for(int i = 0; i < n; i++) {
        std::cin >> A[i].first;
        A[i].second = i;
    }

    std::sort(A.begin(), A.end());

    std::vector<int> seat(n, 0);
    for(int i = 0; i < n; ) {
        int j = i;
        while(i < n && A[i].first == A[j].first) {
            i += 1;
        }
         
        for(int k = j; k < i; ) {
            int r = std::min(k + M - (k % M) - 1, i - 1);
            
            for(int s = k, p = r; s <= r; s++, p--) {
                seat[A[p].second] = s; 
            }
            k = r + 1;
        } 
    }

    std::vector<fenwick_tree> ft(N, fenwick_tree(M));
    int64_t ans = 0;
    for(int i = 0; i < n; i++) {
        int s = seat[i];
        int r = s / M;
        int c = s % M;
         
        ans += ft[r].query(c - 1);
        ft[r].update(c, 1);
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
