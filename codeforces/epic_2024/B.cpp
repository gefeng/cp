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

    std::map<int, int> m;
    int tot = 0;
    for(int i = 1; i < N; i++) {
        if(A[i] < A[i - 1]) {
            m[A[i - 1] - A[i]] += 1;
            A[i] = A[i - 1];
            tot += 1;
        }
    }

    int64_t ans = 0;
    int pre = 0;
    for(auto [d, f] : m) {
        ans += (int64_t)(d - pre) * (tot + 1);
        tot -= f;
        pre = d;
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
