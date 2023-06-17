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
    std::vector<int> B(N);
    
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    std::vector<int> cnt_a(2 * N + 1, 0);
    std::vector<int> cnt_b(2 * N + 1, 0);
    
    for(int i = 0; i < N; ) {
        int j = i;
        while(i < N && A[i] == A[j]) {
            i += 1;
        }

        cnt_a[A[j]] = std::max(cnt_a[A[j]], i - j);
    }

    for(int i = 0; i < N; ) {
        int j = i;
        while(i < N && B[i] == B[j]) {
            i += 1;
        }

        cnt_b[B[j]] = std::max(cnt_b[B[j]], i - j);
    }

    int ans = 0;
    for(int i = 1; i <= 2 * N; i++) {
        ans = std::max(ans, cnt_a[i] + cnt_b[i]);
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
