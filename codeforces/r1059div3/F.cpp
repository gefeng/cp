#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int INF = static_cast<int>(2e9);

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::pair<int, int>> A(M);
    for(int i = 0; i < M; i++) {
        std::cin >> A[i].first >> A[i].second;
        A[i].first -= 1;
        A[i].second -= 1;
    }

    std::vector<int> ans(N, -1);
    for(int i = 0; i < N; i++) {
        int cnt = 0;
        for(auto [l, r] : A) {
            if(l <= i && r >= i) {
                cnt += 1;
            }
        } 

        if(cnt == M) {
            ans[i] = 0;
            for(int j = 0, k = 1; j < N; j++) {
                if(j != i) {
                    ans[j] = k++;
                }
            }
            for(int j = 0; j < N; j++) {
                std::cout << ans[j] << " \n"[j == N - 1];
            }
            return;
        }
    }

    for(int i = 0; i < N; i++) {
        int cnt = 0;
        for(auto [l, r] : A) {
            if(l <= i && r >= i) {
                cnt += 1;
            }
        } 

        if(cnt == 0) {
            ans[i] = 0;
            for(int j = 0, k = 1; j < N; j++) {
                if(j != i) {
                    ans[j] = k++;
                }
            }
            for(int j = 0; j < N; j++) {
                std::cout << ans[j] << " \n"[j == N - 1];
            }
            return;
        }
    }

    for(int i = 0; i < N; i++) {
        std::vector<std::pair<int, int>> a;
        for(auto [l, r] : A) {
            if(l <= i && r >= i) {
                a.emplace_back(l, r);
            }
        }

        int x = 0;
        int y = INF;
        for(auto [l, r] : a) {
            x = std::max(x, l);
            y = std::min(y, r);
        }

        if(y - x + 1 > 1) {
            ans[i] = 0;
            if(i - 1 >= x) {
                ans[i - 1] = 1;
            } else {
                ans[i + 1] = 1;
            }
            for(int j = 0, k = 2; j < N; j++) {
                if(ans[j] == -1) {
                    ans[j] = k++;
                }
            }
            for(int j = 0; j < N; j++) {
                std::cout << ans[j] << " \n"[j == N - 1];
            }
            return;
        }
    }

    ans[0] = 0;
    ans.back() = 1;
    for(int i = 0, j = 2; i < N; i++) {
        if(ans[i] == -1) {
            ans[i] = j++;
        }
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
