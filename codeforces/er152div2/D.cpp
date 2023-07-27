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

    std::vector<int> painted(N, 0);
    std::vector<int> bal(N, 0);
    int ans = 0;
    for(int i = 0; i < N; i++) {
        if(A[i]) {
            int j = i;
            int cnt2 = 0;
            while(i < N && A[i]) {
                if(A[i] == 2) {
                    cnt2 += 1;
                }
                i += 1;
            }

            ans += 1;

            for(int k = j; k < i; k++) {
                painted[k] = 1;
            }

            if(cnt2) {
                if(j) {
                    painted[j - 1] = 1;
                }
                if(i < N) {
                    painted[i] = 1;
                }
            } else {
                if(j && !painted[j - 1]) {
                    painted[j - 1] = 1;
                } else if(i < N && !painted[i]) {
                    painted[i] = 1;
                }
            }
        } 
    }

    for(int i = 0; i < N; i++) {
        if(painted[i] == 0) {
            ans += 1;
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
