#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int64_t> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::sort(A.begin(), A.end());

    int lo = 1;
    int hi = N;
    int ans = 0;
    while(lo <= hi) {
        int mid = (lo + hi) >> 1;

        std::vector<int64_t> a;
        std::vector<int64_t> b;
        
        int h = 0;
        for(int i = 0; i < N; i++) {
            if(A[i] % K == 0) {
                a.push_back(A[i]);
            } else {
                if(A[i] >= mid) {
                    h += 1;
                } else if(A[i] * K >= mid) {
                    b.push_back(A[i]);
                }
            }
        }

        int n = a.size();
        for(int i = 0; i < n; i++) {
            while(!b.empty() && a[i] % K == 0 && a[i] / K >= mid) {
                b.pop_back();
                a[i] /= K;
                h += 1;
            }
        }

        for(int i = 0; i < n; i++) {
            while(!b.empty() && a[i] % K == 0 && a[i] < mid) {
                b.pop_back();
                a[i] /= K;
                h += 1;
            }
        }

        std::vector<std::pair<int, int>> c;
        for(int i = 0; i < n; i++) {
            if(a[i] % K == 0) {
                int x = a[i];
                c.emplace_back(a[i], 0);
                while(x % K == 0) {
                    c.back().second += 1;
                    x /= K;
                }
            } else {
                if(a[i] >= mid) {
                    h += 1;
                }
            }
        }

        std::sort(c.begin(), c.end(), [](const auto& a, const auto& b) {
                    return a.second > b.second;
                });

        for(auto& [v, f] : c) {
            while(!b.empty() && f) {
                v /= K;
                f -= 1;
                h += 1;
                b.pop_back();
            }
        }

        for(auto [v, _] : c) {
            if(v >= mid) {
                h += 1;
            }
        }

        if(h >= mid) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
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
