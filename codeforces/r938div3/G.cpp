#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>
#include <map>

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> G(N, std::vector<int>(M, 0));
    std::map<int, std::set<int>> m;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            std::cin >> G[i][j];
        }
    }

    auto get_divisors = [](int v) {
        std::set<int> s;
        for(int f = 1; f * f <= v; f++) {
            if(v % f == 0) {
                s.insert(f);
                s.insert(v / f);
            }
        }
        return s;
    };

    std::vector<int> candidate;
    std::set<int> s1 = get_divisors(G[0][0]);
    std::set<int> s2 = get_divisors(G[N - 1][M - 1]);
    for(int div : s1) {
        if(s2.find(div) != s2.end()) {
            candidate.push_back(div);
        }
    }

    int ans = 0;
    std::vector<std::vector<int>> dp(N, std::vector<int>(M, 0)); 
    for(int div : candidate) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                dp[i][j] = 0;
            }
        }

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(i == 0 && j == 0) {
                    dp[i][j] = 1;
                }

                if(i - 1 >= 0) {
                    dp[i][j] = dp[i][j] || (dp[i - 1][j] && (G[i][j] % div == 0));
                }

                if(j - 1 >= 0) {
                    dp[i][j] = dp[i][j] || (dp[i][j - 1] && (G[i][j] % div == 0));
                }
            }
        }

        if(dp[N - 1][M - 1]) {
            ans = std::max(ans, div);
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
