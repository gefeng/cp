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

    int ans = -1;
    for(int i = 0; i <= N; i++) {
        int cnt = 0;
        for(int j = N - 1; j >= 0; j--) {
            if(A[j] > i) {
                cnt += 1;
            } 
        }

        if(cnt == i) {
            ans = cnt;
            break;
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
