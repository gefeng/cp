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

    std::vector<std::vector<int>> pos(N + 1);
    for(int i = 0; i < N; i++) {
        pos[A[i]].push_back(i);
    }
    
    int64_t ans = 0;
    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            int64_t l = std::lower_bound(pos[A[j]].begin(), pos[A[j]].end(), i) - pos[A[j]].begin();
            int64_t r = pos[A[i]].end() - std::upper_bound(pos[A[i]].begin(), pos[A[i]].end(), j);
            
            ans += l * r;
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
