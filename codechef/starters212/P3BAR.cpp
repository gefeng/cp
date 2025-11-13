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
    std::vector<int> pos(N, 0);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        A[i] -= 1;
        pos[A[i]] = i;
    }

    std::vector<int> removed(N, 0);
    int ans = 0;
    for(int i = N - 1; i >= 0; i--) {
        int p = pos[i]; 
        int l = 0;
        int r = 0;
        for(int j = 0; j < p; j++) {
            if(!removed[A[j]]) {
                l += 1;
            }
        }

        for(int j = p + 1; j < N; j++) {
            if(!removed[A[j]]) {
                r += 1;
            }
        }
        
        removed[i] += 1;
        ans += std::min(l, r);
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
