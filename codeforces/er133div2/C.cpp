#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

constexpr int64_t INF = static_cast<int64_t>(2e18);

void run_case() {
    int M;
    std::cin >> M;

    std::vector<std::vector<int64_t>> A(2, std::vector<int64_t>(M, 0));
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < M; j++) {
            std::cin >> A[i][j];
        }
    }

    auto solve1 = [&]() {
        int64_t res = INF;
        std::multiset<int64_t> ms1;
        std::multiset<int64_t> ms2;
        for(int i = 0; i < M; i++) {
            if(i != 0) {
                ms1.insert(A[0][i] - i);
            }
            ms2.insert(A[1][i] + i);
        }

        int64_t t = 0;
        for(int i = 0; i < M; i += 2) {
            if(i) {
                ms1.erase(ms1.find(A[0][i] - i));
                t = std::max(A[0][i], t) + 1;
            }
            int64_t max1 = ms1.empty() ? 0 : *ms1.rbegin();
            int64_t max2 = ms2.empty() ? 0 : *ms2.rbegin();
            int64_t st = t;
            st = std::max(st, max1 + i + 1);
            st = std::max(st, max2 + i - M * 2 + 2);

            res = std::min(res, (M - 1 - i) * 2 + 1 + st);
            
            if(i + 1 < M) {
                ms1.erase(ms1.find(A[0][i + 1] - i - 1));
                ms2.erase(ms2.find(A[1][i] + i));
                ms2.erase(ms2.find(A[1][i + 1] + i + 1));
                t = std::max(t, A[1][i]) + 1;
                t = std::max(t, A[1][i + 1]) + 1;
                t = std::max(t, A[0][i + 1]) + 1;
                if(i + 1 == M - 1) {
                    res = std::min(res, t);
                }
            }
        }
        return res;
    };

    auto solve2 = [&]() {
        int64_t res = INF;
        std::multiset<int64_t> ms1;
        std::multiset<int64_t> ms2;
        for(int i = 1; i < M; i++) {
            ms1.insert(A[0][i] + i);
            ms2.insert(A[1][i] - i);
        }

        int64_t t = 0;
        t = A[1][0] + 1;
        for(int i = 1; i < M; i += 2) {
            ms2.erase(ms2.find(A[1][i] - i));
            t = std::max(t, A[1][i]) + 1;
            
            int64_t max1 = ms1.empty() ? 0 : *ms1.rbegin();
            int64_t max2 = ms2.empty() ? 0 : *ms2.rbegin();
            int64_t st = t;
            st = std::max(st, max2 + i + 1);
            st = std::max(st, max1 + i - M * 2 + 2);

            res = std::min(res, (M - 1 - i) * 2 + 1 + st);
            
            if(i + 1 < M) {
                ms1.erase(ms1.find(A[0][i] + i));
                ms1.erase(ms1.find(A[0][i + 1] + i + 1));
                ms2.erase(ms2.find(A[1][i + 1] - i - 1));
                t = std::max(t, A[0][i]) + 1;
                t = std::max(t, A[0][i + 1]) + 1;
                t = std::max(t, A[1][i + 1]) + 1;
                if(i + 1 == M - 1) {
                    res = std::min(res, t);
                }
            }
        }
        return res;
    };

    int64_t ans = std::min(solve1(), solve2());
    
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
