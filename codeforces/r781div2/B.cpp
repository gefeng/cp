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

    std::sort(A.begin(), A.end());
    int cnt = 0;
    for(int i = 0; i < N; ) {
        int j = i; 
        while(i < N && A[i] == A[j]) {
            i += 1;
        }
        cnt = std::max(cnt, i - j);
    }

    int ans = 0;
    while(cnt < N) {
        ans += 1;
        int x = std::min(cnt, N - cnt);
        ans += x;
        cnt += x;
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
