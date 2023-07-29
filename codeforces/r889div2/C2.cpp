#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int INF = 1e9;

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int64_t> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    bool inc = true;
    int64_t min_v = A[0];
    int64_t max_v = A[0];
    for(int i = 1; i < N; i++) {
        if(A[i] < A[i - 1]) {
            inc = false;
        }

        min_v = std::min(min_v, A[i]);
        max_v = std::max(max_v, A[i]);
    }

    if(inc) {
        std::cout << 0 << '\n';
        return;
    }

    std::vector<std::pair<int, int>> ans;
    for(int i = 0; i < N; i++) {
        std::vector<int64_t> a(A);
        std::vector<std::pair<int, int>> cand;
        
        if(a[i] == 0) {
            continue;
        }
        
        if(a[i] > 0) {
            while(a[i] < abs(min_v)) {
                a[i] += a[i];
                cand.emplace_back(i, i);
            }

            for(int j = 0; j < N; j++) {
                if(a[j] < 0) {
                    a[j] += a[i];
                    cand.emplace_back(j, i);
                }
                if(j) {
                    a[j] += a[j - 1];
                    cand.emplace_back(j, j - 1);
                }
            }
        } else {
            while(abs(a[i]) < abs(max_v)) {
                a[i] += a[i];
                cand.emplace_back(i, i);
            }

            for(int j = N - 1; j >= 0; j--) {
                if(a[j] > 0) {
                    a[j] += a[i];
                    cand.emplace_back(j, i);
                }
                if(j < N - 1) {
                    a[j] += a[j + 1];
                    cand.emplace_back(j, j + 1);
                }
            }
        }

        if(ans.empty() || ans.size() > cand.size()) {
            std::swap(ans, cand);
        }
    } 

    int sz = ans.size();
    std::cout << sz << '\n';

    for(int i = 0; i < sz; i++) {
        std::cout << ans[i].first + 1 << ' ' << ans[i].second + 1 << '\n';
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
