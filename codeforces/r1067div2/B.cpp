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

    std::vector<int> A(N * 2);
    for(int i = 0; i < N * 2; i++) {
        std::cin >> A[i];
    }

    int d0 = 0;
    int d1 = 0;
    int d2 = 0;
    int ans = 0;
    std::vector<int> freq(N * 2 + 1, 0);
    for(int i = 0; i < N * 2; i++) {
        freq[A[i]] += 1;
    }

    for(int i = 1; i <= N * 2; i++) {
        if(freq[i] == 0) {
            continue;
        }
        if(freq[i] % 2 == 0) {
            if((freq[i] / 2) % 2 == 1) {
                d0 += 1;
            } else {
                d2 += 1;
            }
        } else {
            d1 += 1;
        }
    }

    ans = d2 * 2 + d0 * 2 + d1;
    if(d2 % 2 == 1 && d1 == 0) {
        ans -= 2;
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
