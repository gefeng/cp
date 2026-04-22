#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, P;
    std::cin >> N >> P;
    P--;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int ans = 0;
    if(P == 0) {
        ans = A[0]; 
        int now = A[0];
        for(int i = 1; i < N - 1; i++) {
            now ^= A[i];
            ans = std::min(ans, now);
        }
    } else if(P == N - 1) {
        ans = A[N - 1];
        int sum = 0;
        int now = 0;
        for(int i = 0; i < N; i++) {
            sum ^= A[i];
        }
        for(int i = 0; i < N - 1; i++) {
            now ^= A[i];
            ans = std::min(ans, now ^ sum);
        }
    } else {
        std::vector<int> a;
        int now = 0;
        for(int i = 0; i < N - 1; i++) {
            now ^= A[i];
            a.push_back(now);
        }
        std::ranges::sort(a);
        
        ans = A[P];
        for(int i = 1; i < a.size(); i++) {
            ans = std::min(ans, a[i] ^ a[i - 1]);
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
