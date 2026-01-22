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

    bool sorted = true;
    for(int i = 1; i < N; i++) {
        if(A[i] < A[i - 1]) {
            sorted = false;
        }
    }
    if(sorted) {
        std::cout << 0 << '\n';
        return;
    }

    int ans = N + 1;
    for(int i = 0; i < N; i++) {
        std::vector<int> a(A);
        std::ranges::sort(a.begin(), a.begin() + i + 1);
        
        sorted = true;
        for(int j = 1; j < N; j++) {
            if(a[j] < a[j - 1]) {
                sorted = false;
                break;
            }
        }
        if(sorted) {
            ans = std::min(ans, A[i]);
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
