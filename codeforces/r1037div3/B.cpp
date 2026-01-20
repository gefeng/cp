#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int ans = 0;
    int now = 0;
    while(now < N) {
        if(A[now] == 1) {
            now += 1;
            continue;
        }

        if(now + K > N) {
            break; 
        }
        
        int p = -1;
        for(int i = 0; i < K; i++) {
            if(A[now + i] == 1) {
                p = now + i;
                break;
            }
        }

        if(p == -1) {
            ans += 1;
            now += K + 1;
        } else {
            now = p + 1; 
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
