#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <numeric>

void run_case() {
    int N;
    int64_t K;
    std::cin >> N >> K;

    std::vector<int64_t> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int64_t sum = std::accumulate(A.begin(), A.end(), int64_t(0));
    int64_t max_v = *std::max_element(A.begin(), A.end());

    int64_t ans = 0;
    for(int64_t size = N; size >= 1; size--) {
        int64_t rem = (size - (sum % size)) % size;
        int64_t cnt = std::max(max_v, (sum + rem) / size);
        if(cnt <= (K + sum) / size) {
            ans = size;
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
