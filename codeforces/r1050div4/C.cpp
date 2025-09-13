#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first >> A[i].second;;
    }

    int t = 0;
    int p = 0;
    int ans = 0;
    for(int i = 0; i < N; i++) {
        auto [nt, np] = A[i]; 
        int d = nt - t; 

        ans += d;
        if((d % 2 == 1 && p == np) || (d % 2 == 0 && p != np)) {
            ans -= 1;
        }
        
        t = nt;
        p = np;
    }

    ans += M - A.back().first;

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
