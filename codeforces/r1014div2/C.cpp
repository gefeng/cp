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

    std::sort(A.begin(), A.end());

    std::vector<int> eve;
    std::vector<int> odd;
    for(int i = 0; i < N; i++) {
        if(A[i] % 2 == 0) {
            eve.push_back(A[i]);
        } else {
            odd.push_back(A[i]);
        }
    }

    if(eve.empty() || odd.empty()) {
        std::cout << A.back() << '\n';
        return;
    }

    int n = eve.size();
    int m = odd.size();
    int64_t sum_eve = std::accumulate(eve.begin(), eve.end(), int64_t(0));
    int64_t sum_odd = std::accumulate(odd.begin(), odd.end(), int64_t(0));
    int64_t ans = 0;
    
    ans = eve.back() + sum_eve - eve.back() + sum_odd - m + 1;
    
    sum_eve += sum_odd - odd.back() - (m - 1);
    ans = std::max(ans, sum_eve);
    
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
