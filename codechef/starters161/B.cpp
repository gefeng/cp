#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int INF = int(2e9);

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int ans = 0;
    for(int i = 0; i < N; ) {
        if(A[i] == 3) {
            int j = i;
            while(i < N && A[i] == 3) {
                i += 1;
            }
            
            if(j && i < N && i - j == 1 && A[j - 1] == 2 && A[i] == 2) {
                ans += 1;
            } else {
                if((j && A[j - 1] == 1) || (i < N && A[i] == 1)) {
                    ans += i - j - 1 + 3;
                } else {
                    ans += (i - j) * 3;
                }
            }
        } else {
            ans += A[i];
            i += 1;
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
