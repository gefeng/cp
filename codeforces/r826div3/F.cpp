#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>
#include <tuple>

constexpr int INF = static_cast<int>(2e9) + 10;

void run_case() {
    int N;
    std::cin >> N;

    std::vector<std::tuple<int, int, int, int>> A(N);
    for(int i = 0; i < N; i++) {
        int L, R, C;
        std::cin >> L >> R >> C;
        A[i] = {L, R, C, i};
    }

    std::ranges::sort(A);
    
    std::vector<int> ans(N, INF);
    std::pair<int, int> max1{-1, -1};
    std::pair<int, int> max2{-1, -1};
    for(int i = 0; i < N; ) {
        int j = i;
        std::set<int> s;
        while(i < N && std::get<0>(A[j]) == std::get<0>(A[i])) {
            s.insert(std::get<2>(A[i]));
            i += 1;
        }
        
        if(s.size() > 1) {
            for(int k = j; k < i; k++) {
                ans[std::get<3>(A[k])] = 0;
            }
        } else {
            for(int k = j; k < i; k++) {
                auto [l, r, c, idx] = A[k];
                if(max1.second != -1 && max1.second != c) {
                    ans[idx] = max1.first >= l ? 0 : l - max1.first;
                } else if(max2.second != -1 && max2.second != c) {
                    ans[idx] = max2.first >= l ? 0 : l - max2.first;
                }
            }
        }

        for(int k = j; k < i; k++) {
            auto [l, r, c, idx] = A[k];
            if(r > max1.first) {
                if(c != max1.second) {
                    max2 = max1;
                }
                max1 = {r, c};
            } else if(r > max2.first) {
                if(c != max1.second) {
                    max2 = {r, c};
                }
            }
        }
        assert(max1.second != max2.second);
    }

    std::pair<int, int> min1{INF, -1};
    std::pair<int, int> min2{INF, -1};
    for(int i = N - 1; i >= 0; ) {
        int j = i;
        std::set<int> s;
        while(i >= 0 && std::get<0>(A[j]) == std::get<0>(A[i])) {
            s.insert(std::get<2>(A[i]));
            i -= 1;
        }
        
        if(s.size() > 1) {
            for(int k = j; k > i; k--) {
                ans[std::get<3>(A[k])] = 0;
            }
        } else {
            for(int k = j; k > i; k--) {
                auto [l, r, c, idx] = A[k];
                if(min1.second != -1 && min1.second != c) {
                    ans[idx] = std::min(ans[idx], min1.first <= r ? 0 : min1.first - r);
                } else if(min2.second != -1 && min2.second != c) {
                    ans[idx] = std::min(ans[idx], min2.first <= r ? 0 : min2.first - r);
                }
            }
        }

        for(int k = j; k > i; k--) {
            auto [l, r, c, idx] = A[k];
            if(l < min1.first) {
                if(c != min1.second) {
                    min2 = min1;
                }
                min1 = {l, c};
            } else if(l < min2.first) {
                if(c != min1.second) {
                    min2 = {l, c};
                }
            }
        }
        assert(min1.second != min2.second);
    }

    for(int i = 0; i < N; i++) {
        std::cout << ans[i] << " \n"[i == N - 1];
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
