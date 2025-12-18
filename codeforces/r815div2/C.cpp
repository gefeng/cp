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

    std::vector<std::string> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int ans = 0;
    int zero = 0;
    int adj = 0;
    std::vector<std::string> a(A);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(A[i][j] == '1') {
                ans += 1;
            } else {
                zero = 1;
            }
            if(i < N - 1 && j < M - 1) {
                int cnt = 0;
                for(int r = 0; r < 2; r++) {
                    for(int c = 0; c < 2; c++) {
                        if(A[i + r][j + c] == '0') {
                            cnt += 1;
                        }
                    }
                }
                if(cnt > 1) {
                    adj = 1;
                }
            }
        }
    }

    if(zero) {
        ans -= adj ? 0 : 1;
    } else {
        ans -= 2;
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
