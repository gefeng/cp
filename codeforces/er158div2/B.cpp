#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>
#include <map>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int64_t ans = 0;
    int min_v = (int)2e9;
    for(int i = 0; i < N; i++) {
        int j = i;
        while(i + 1 < N && A[i + 1] <= A[i]) {
            i += 1;
        }

        int64_t cnt = A[j] - (min_v == (int)2e9 ? 0 : min_v);
        ans += cnt;
        
        min_v = A[i];
    }

    std::cout << std::max(0LL, ans - 1) << '\n';
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
