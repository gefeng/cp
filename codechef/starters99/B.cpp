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

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int64_t ans = (int64_t)1e18;
    for(int a = 0; a < 3; a++) {
        for(int b = 0; b < 3; b++) {
            for(int c = 0; c < 3; c++) {
                if((a + b + c) % 3 == 0) {
                    std::array<int, 3> t = {a, b, c};
                    int64_t sum = 0;
                    for(int i = 0; i < 3; i++) {
                        for(int j = i; j < N; j += 3) {
                            sum += (t[i] - (A[j] % 3) + 3) % 3;
                        }
                    } 

                    ans = std::min(ans, sum);
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
