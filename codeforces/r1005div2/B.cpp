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
    std::vector<int> freq(N + 1, 0);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        freq[A[i]] += 1;
    }

    int ans = 0;
    int x = -1;
    int y = -1;
    for(int l = 0, r = 0; r < N; r++) {
        if(freq[A[r]] == 1) {
            if(r - l + 1 > ans) {
                ans = r - l + 1;
                x = l;
                y = r;
            }
        } else {
            l = r + 1;
        }
    }

    if(ans == 0) {
        std::cout << 0 << '\n';
        return;
    }
    
    std::cout << x + 1 << ' ' << y + 1 << '\n';
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
