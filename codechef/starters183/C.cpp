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
        A[i] -= 1;
    }

    int ans = 0;
    int cnt = 0;
    for(int i = 0; i < N; i++) {
        if(i == A[i]) {
            cnt += 1;
        }
    }

    if(cnt == 0) {
        std::cout << 0 << '\n';
        return;
    }

    ans = (cnt + 1) / 2;
    
    if(N % 2 == 1 && A[N / 2] == N / 2) {
        if(cnt == 1) {
            int min_v = N;
            for(int i = 0; i < N / 2; i++) {
                min_v = std::min(min_v, A[i]);
            }
            std::cout << (min_v > N / 2 ? 0 : 1) << '\n';
            return;
        }

        cnt = 0;
        for(int i = 0; i < N / 2; i++) {
            if(A[i] < N / 2) {
                cnt += 1;     
            }
        }

        ans = std::min(ans, cnt);
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
