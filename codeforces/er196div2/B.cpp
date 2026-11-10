#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::ranges::sort(A);
    
    if(A[0] == 1) {
        std::cout << 0 << '\n';
        return;
    }
    
    int ans = N;
    for(int i = 0; i < N; ) {
        int j = i;
        while(i < N && A[i] == A[j]) {
            i++;
        }

        int cnt = i - j;
        for(int k = i; k < N; k++) {
            if(A[k] % A[j] == 0) {
                cnt++;
            }
        }
        ans = std::min(ans, N - cnt);
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
