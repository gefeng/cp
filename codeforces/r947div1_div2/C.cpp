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

    int ans = 0;
    for(int i = 1; i < N; i++) {
        ans = std::max(ans, std::min(A[i - 1], A[i])); 
    }

    for(int i = 2; i < N; i++) {
        std::array<int, 3> a = {A[i - 2], A[i - 1], A[i]};
        std::sort(a.begin(), a.end());
        ans = std::max(ans, a[1]);
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
