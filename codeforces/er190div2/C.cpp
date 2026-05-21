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
    int64_t sum = 0;
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        sum += A[i];
    }

    if(sum < 3) {
        std::cout << 0 << '\n';
        return;
    }

    int64_t ans = 0;
    int unique = 0;
    for(int i = 0; i < N; i++) {
        if(A[i] == 1) {
            unique++;
        }
    }

    int cnt = 0;
    for(int i = 0; i < N; i++) {
        if(A[i] > 1) {
            int d = std::min(unique, (A[i] - 2) / 2);
            unique -= d;
            ans += A[i] + d;
            cnt++;
        }
    }

    if(unique && cnt == 1) {
        ans++;
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
