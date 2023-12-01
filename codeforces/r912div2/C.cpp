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

    int64_t sum = 0;
    std::vector<int64_t> res;
    for(int i = N - 1; i >= 0; i--) {
        if(sum < 0) {
            if(res.empty()) {
                res.push_back(A[i]);
            } else {
                res.back() += A[i];
            }
        } else {
            res.push_back(A[i]);
        }

        sum += A[i];
    }

    std::reverse(res.begin(), res.end());
    int size = res.size();
    int64_t ans = 0;
    for(int i = 0; i < size; i++) {
        ans += res[i] * (i + 1);
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
