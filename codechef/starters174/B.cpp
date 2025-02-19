#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <unordered_map>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int64_t> A(N);
    std::unordered_map<int64_t, int> m;
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        m[A[i]] += 1;
    }

    std::sort(A.begin(), A.end());
    
    int64_t ans = 0;
    for(int64_t x = 1; x <= N; x++) {
        int64_t len = 0;
        for(int64_t y = x; y <= N * 2; y += x) {
            if(m.find(y) != m.end()) {
                len += m[y];
            }
        }
        if(len) {
            ans = std::max(ans, len + x);
        }
    }

    for(int i = 0; i < N; ) {
        int j = i;
        while(i < N && A[i] == A[j]) {
            i += 1;
        }
        ans = std::max(ans, i - j + A[j]);
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
