#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> A(N);
    std::vector<int> psum(N + 1, 0);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        psum[i + 1] = psum[i] + (A[i] == 0 ? 1 : 0);
    }

    std::vector<int> dp(M + 1, 0);
    std::vector<int> diff(M + 1, 0); 
    for(int i = 0; i < N; i++) {
        int points = psum[i + 1];

        if(A[i] < 0) {
            int l = -A[i];
            int r = points;
            if(l <= r) {
                diff[l] += 1;
                if(r + 1 <= M) {
                    diff[r + 1] -= 1; 
                }
            } 
        }
        if(A[i] > 0) {
            int l = 0;
            int r = points - A[i];
            if(l <= r) {
                diff[l] += 1;
                if(r + 1 <= M) {
                    diff[r + 1] -= 1; 
                }
            }
        }
       
        if(A[i] == 0 || i == N - 1) {
            std::vector<int> ndp(M + 1, 0);
            int sum = 0;
            for(int j = 0; j <= M; j++) {
                sum += diff[j];
                dp[j] += sum;
                if(j) {
                    ndp[j] = std::max(dp[j - 1], dp[j]);
                } else {
                    ndp[j] = dp[j];
                }
            }  
            std::swap(dp, ndp);
            diff.assign(M + 1, 0);
        }
    }
    
    int ans = 0;
    for(int i = 0; i <= M; i++) {
        ans = std::max(ans, dp[i]);
    }
    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
