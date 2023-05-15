#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

struct fenwick_tree {
    int n;
    std::vector<int> ft;

    fenwick_tree(int _n) : n(_n + 1) {
        ft.resize(n, 0);
    }

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

    int query(int l, int r) {
        return query(r) - query(l - 1);
    }
};

    void run_case() {
    int N, K;
    std::cin >> N >> K;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> cnt_smaller(N, 0);
    std::vector<int> cnt_greater(N, 0);
    fenwick_tree ft(N + 1); 
    
    for(int i = N - 1; i >= 0; i--) {
        cnt_smaller[i] = ft.query(0, A[i]);
        cnt_greater[i] = ft.query(A[i] + 1, N);
        ft.update(A[i], 1);
    }

    auto print = [](std::vector<int>& A) {
        int n = A.size();
        for(int i = 0; i < n; i++) {
            std::cout << A[i] << " \n"[i == n - 1];
        }
    };

    for(int i = 0; i < N; i++) {
        int cnt = cnt_smaller[i];
        if(K - cnt > 0) {
            K -= cnt;
        } else {
            // find kth samller     
            std::vector<std::pair<int, int>> v;

            for(int j = i; j < N; j++) {
                if(A[j] < A[i]) {
                    v.emplace_back(A[j], j);
                }
            }
            
            std::sort(v.begin(), v.end());
            
            int p = v[K - 1].second;

            std::reverse(A.begin() + i, A.begin() + p + 1);

            print(A);

            return;
        }
    }

    if(K > N) {
        K -= N;
    } else {
        print(A);
        return;
    }

    for(int i = N - 1; i >= 0; i--) {
        int cnt = cnt_greater[i]; 
        if(K - cnt > 0) {
            K -= cnt;
        } else {
            // find kth greater
            std::vector<std::pair<int, int>> v;

            for(int j = i; j < N; j++) {
                if(A[j] > A[i]) {
                    v.emplace_back(A[j], j);
                }
            }

            std::sort(v.begin(), v.end());
            
            int p = v[K - 1].second;

            std::reverse(A.begin() + i, A.begin() + p + 1);

            print(A);

            return;
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
