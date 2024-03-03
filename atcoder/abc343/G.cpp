#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int INF = (int)2e9;

std::vector<int> z_function(std::string s) {
    int n = s.size();
    std::vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) {
            z[i] = std::min(r - i, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<std::string> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    // best[i][j] shortest length adding to s[i] if creating a new string t that
    // both s[i] and s[j] are substring of t.
    // 1. if s[j] is a substring of s[i] then adding 0.
    // 2. find length l of the longest prefix of s[j] is also a suffix of s[i] then adding size(s[j]) - l
    std::vector<std::vector<int>> best(N, std::vector<int>(N, INF));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(i == j) {
                continue;
            }

            if(A[i].find(A[j]) != std::string::npos) {
                best[i][j] = 0;
                continue;
            }

            std::string s = A[j] + A[i]; 
            std::vector<int> z =  z_function(s);
            int n = A[i].size();
            int m = A[j].size();
            int len = m;
            for(int i = m; i < m + n; i++) {
                if(z[i] == m + n - i) {
                    len = m - std::min(z[i], m);
                    break;
                }
            }

            best[i][j] = len;
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(i == j) {
                continue;
            }
        }
    }

    std::vector<std::vector<int>> dp(1 << N, std::vector<int>(N, INF));
    for(int i = 0; i < N; i++) {
        dp[1 << i][i] = A[i].size();
    }

    for(int i = 1; i < (1 << N); i++) {
        for(int j = 0; j < N; j++) {
            if(dp[i][j] != INF) {
                for(int k = 0; k < N; k++) {
                    if(i & (1 << k)) {
                        continue;
                    }

                    if(best[j][k]) {
                        dp[i | (1 << k)][k] = std::min(dp[i | (1 << k)][k], dp[i][j] + best[j][k]);
                    } else {
                        dp[i | (1 << k)][j] = std::min(dp[i | (1 << k)][j], dp[i][j]);
                    }
                }
            }
        }
    }

    int ans = INF;
    for(int i = 0; i < N; i++) {
        ans = std::min(ans, dp[(1 << N) - 1][i]);
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
