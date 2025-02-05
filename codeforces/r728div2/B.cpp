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

    std::vector<int> pos(N + N + 1, 0);
    int ans = 0;
    for(int i = 0; i < N; i++) {
        int j = i + 1;
        int l = (j + 1 + A[i] - 1) / A[i];
        int r = (j + j - 1) / A[i];
        for(int v = l; v <= r; v++) {
            if(pos[v] != 0 && int64_t(A[i]) * v == pos[v] + j) {
                ans += 1;
            }
        }

        pos[A[i]] = i + 1;
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
