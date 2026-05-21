#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int INF = static_cast<int>(2e9) + 10;

template<class T, T (*op)(T, T)>
struct sparse_table {
    const int LOG = 20;

    int n;
    std::vector<std::vector<T>> st;
    std::vector<int> log;

    sparse_table(int n) : n(n) {
        st = std::vector<std::vector<T>>(n, std::vector<T>(LOG, 0));

        log = std::vector<int>(n + 1, 0);
        for(int i = 2, k = 0; i <= n; i++) {
            if(k + 1 < LOG && (1 << (k + 1)) < i) {
                k += 1; 
            } 
            log[i] = k;
        }
    }
    
    sparse_table(std::vector<T>& a) : sparse_table(a.size()) {
        for(int i = 0; i < n; i++) {
            st[i][0] = a[i];
        }
    
        for(int k = 1; k < LOG; k++) {
            for(int i = 0; i + (1 << k) - 1 < n; i++) {
                st[i][k] = op(st[i][k - 1], st[i + (1 << (k - 1))][k - 1]);
            }
        }
    }

    T get(int l, int r) {
        int k = log[r - l + 1];
        return op(st[l][k], st[r - (1 << k) + 1][k]);
    }
};

int op(int a, int b) {
    return std::min(a, b);
}

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<std::pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first;
    }

    for(int i = 0; i < N; i++) {
        std::cin >> A[i].second;
    }

    int M;
    std::cin >> M;
    std::vector<int> TP(M, 0);
    std::vector<int> TC(M, 0);
    std::vector<int> D(M, 0);

    for(int i = 0; i < M; i++) {
        std::cin >> TP[i];
    }

    for(int i = 0; i < M; i++) {
        std::cin >> TC[i];
    }

    for(int i = 0; i < M; i++) {
        std::cin >> D[i];
    }

    std::vector<int> prefix(N + 1, INF);
    std::vector<int> suffix(N + 1, INF);
    std::vector<int> sum(N, 0);
    std::vector<int> ans(M, INF);

    {
        std::ranges::sort(A);

        for(int i = 0; i < N; i++) {
            prefix[i + 1] = std::min(prefix[i], A[i].second);
            suffix[i + 1] = std::min(suffix[i], A[N - 1 - i].second);
            sum[i] = A[i].first + A[i].second;
        }

        sparse_table<int, op> st(sum);
        
        for(int i = 0; i < M; i++) {
            int j = std::lower_bound(A.begin(), A.end(), TP[i], [&](const auto& x, int y) {
                        return x.first < y;
                    }) - A.begin();

            if(j) {
                ans[i] = std::min(ans[i], prefix[j] < TC[i] ? 0 : std::min(prefix[j], TC[i] + D[i]));
            }

            int k = std::lower_bound(A.begin(), A.end(), TP[i] + D[i], [&](const auto& x, int y) {
                        return x.first < y;
                    }) - A.begin();

            if(k < N) {
                ans[i] = std::min(ans[i], (suffix[N - k] < TC[i] ? 0 : std::min(suffix[N - k], TC[i] + D[i])) + TP[i] + D[i]);
            }

            if(j < k) {
                ans[i] = std::min(ans[i], st.get(j, k - 1)); 
            }
        }
    }

    {
        std::ranges::sort(A, [](const auto& x, const auto& y) {
                    return x.second < y.second;
                });

        for(int i = 0; i < N; i++) {
            prefix[i + 1] = std::min(prefix[i], A[i].first);
            suffix[i + 1] = std::min(suffix[i], A[N - 1 - i].first);
            sum[i] = A[i].first + A[i].second;
        }

        sparse_table<int, op> st(sum);
        for(int i = 0; i < M; i++) {
            int j = std::lower_bound(A.begin(), A.end(), TC[i], [&](const auto& x, int y) {
                        return x.second < y;
                    }) - A.begin();

            if(j) {
                ans[i] = std::min(ans[i], prefix[j] < TP[i] ? 0 : std::min(prefix[j], TP[i] + D[i]));
            }

            int k = std::lower_bound(A.begin(), A.end(), TC[i] + D[i], [&](const auto& x, int y) {
                        return x.second < y;
                    }) - A.begin();

            if(k < N) {
                ans[i] = std::min(ans[i], (suffix[N - k] < TP[i] ? 0 : std::min(suffix[N - k], TP[i] + D[i])) + TC[i] + D[i]);
            }


            if(j < k) {
                ans[i] = std::min(ans[i], st.get(j, k - 1)); 
            }
        }
    }

    for(int i = 0; i < M; i++) {
        std::cout << ans[i] << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
