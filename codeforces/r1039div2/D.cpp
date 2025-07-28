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
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    
    std::vector<int> lds;
    std::vector<int> prefix(N, 0);
    for(int i = 0; i < N; i++) {
        if(lds.empty() || A[i] < lds.back()) {
            lds.push_back(A[i]);
        } else {
            lds.pop_back();
            lds.push_back(A[i]);
        }
        prefix[i] = lds.size();
    }

    int64_t sum = std::accumulate(prefix.begin(), prefix.end(), static_cast<int64_t>(0));

    int64_t ans = sum;
    for(int i = 1; i < N; i++) {
        sum -= 1;
        if(A[i - 1] > A[i]) {
            sum -= N - i;
        }
        ans += sum;
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
