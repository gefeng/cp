#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, R;
    std::cin >> N >> R;
    
    std::vector<int> A(N);
    int sum = 0;
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        sum += A[i];
    }

    int ans = 0;
    for(int i = 0; i < N; i++) {
        int r = A[i] / 2;
        A[i] %= 2;
        R -= r;
        sum -= 2 * r;
        ans += 2 * r;
    }

    if(sum <= R) {
        ans += sum;
    } else {
        sum -= R;
        ans += R - sum;
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
