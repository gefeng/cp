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

    std::string S;
    std::cin >> S;

    std::vector<int> zero(N + 1, 0);
    std::vector<int> one(N + 1, 0);
    for(int i = 0; i < N; i++) {
        zero[i + 1] = zero[i] + (S[i] == '0' ? 1 : 0);
        one[i + 1] = one[i] + (S[i] == '1' ? 1 : 0);
    }

    int ans = -1;
    for(int i = 0; i <= N; i++) {
        int l = i == 0 ? 0 : zero[i];
        int r = i == N ? 0 : one[N] - one[i];
        
        if(l >= (i + 1) / 2 && r >= (N - i + 1) / 2) {
            if(ans == -1) {
                ans = i;
            } else {
                if(N % 2 == 1) {
                    int d1 = std::min(std::abs(N / 2 - i), std::abs((N + 1) / 2 - i));
                    int d2 = std::min(std::abs(N / 2 - ans), std::abs((N + 1) / 2 - ans));
                    if(d1 < d2) {
                        ans = i;
                    }
                } else {
                    int d1 = std::abs((N + 1) / 2 - i); 
                    int d2 = std::abs((N + 1) / 2 - ans);
                    if(d1 < d2) {
                        ans = i;
                    }
                }
            }
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
