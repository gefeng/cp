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

    std::sort(A.begin(), A.end(), std::greater<int>());
    
    int ans = 0;
    for(int i = 0; i < N; i++) {
        if(K == 0) {
            break;
        }
        if(A[i] <= K) {
            K -= A[i]; 
        } else {
            ans = K;
            K = 0;
            break;
        }
    }

    ans += K;

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
