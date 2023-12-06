#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<std::string> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<std::vector<int64_t>> psum(N, std::vector<int64_t>(N + 1, 0));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            psum[i][j + 1] = psum[i][j] + (A[j][i] == 'o' ? 1 : 0);
        }
    }

    int64_t ans = 0;
    for(int i = 0; i < N; i++) {
        int64_t sum = 0;
        int64_t cnt = 0;
        for(int j = 0; j < N; j++) {
            sum += A[i][j] == 'o' ? 1 : 0;
        }
        
        for(int j = 0; j < N; j++) {
            if(A[i][j] == 'o') {
                ans += cnt * (psum[j][N] - psum[j][i + 1]);
                ans += cnt * psum[j][i];
                ans += (sum - 1 - cnt) * (psum[j][N] - psum[j][i + 1]);
                ans += (sum - 1 - cnt) * psum[j][i];
                cnt += 1;
            }
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
