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

    int64_t ans = 0;
    std::map<int64_t, int64_t> m;

    for(int i = 0; i < N; i++) {
        int64_t x = A[i] - i;
        if(m.find(x) != m.end()) {
            int64_t sum = m[x] + A[i];
            m[x] = sum;
            ans = std::max(ans, sum);
        } else {
            m[x] = A[i];
            ans = std::max(ans, int64_t(A[i]));
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
