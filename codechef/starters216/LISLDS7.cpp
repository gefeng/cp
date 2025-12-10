#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>
#include <set>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int a = 0;
    int b = 0;
    for(int i = 0; i < N; i++) {
        if(A[i] == 1) {
            a += 1;
        } else {
            b += 1;
        }
    }

    int ans = 0;
    for(int i = 1; i <= N; i++) {
        if(A[i - 1] == 1) {
            a -= 1;
        } else {
            b -= 1;
        }

        int lis = 1 + b;
        int lds = 1 + b;
        lis += a / 2;
        lds += (a + 1) / 2;
        
        ans = std::max(ans, std::min(lis, lds));
        
        if(A[i - 1] == 1) {
            a += 1;
        } else {
            b += 1;
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
