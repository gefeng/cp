#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

constexpr int INF = int(2e9);

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    auto get_highest_bit = [&](int x) {
        int res = 0;
        while(x) {
            x /= 2;
            res += 1;
        }
        return res;
    };

    for(int i = 1; i < N - 1; i++) {
        int h_1 = get_highest_bit(A[i - 1]);
        int h_2 = get_highest_bit(A[i]);
        int h_3 = get_highest_bit(A[i + 1]);
        if(h_1 == h_2 && h_2 == h_3) {
            std::cout << 1 << '\n';
            return;
        }
    }

    int ans = INF;
    for(int i = 0; i < N; i++) {
        if(i < N - 1) {
            int l = 0;
            for(int j = i; j >= 0; j--) {
                l ^= A[j];
                int r = 0;
                for(int k = i + 1; k < N; k++) {
                    r ^= A[k]; 
                    if(r < l) {
                        ans = std::min(ans, i - j + k - i - 1);
                    }
                }
            }
        }
        if(i) {
            int r = 0;
            for(int j = i; j < N; j++) {
                r ^= A[j];
                int l = 0;
                for(int k = i - 1; k >= 0; k--) {
                    l ^= A[k];
                    if(r < l) {
                        ans = std::min(ans, i - 1 - k + j - i); 
                    }
                }
            }
        }
    }

    std::cout << (ans == INF ? -1 : ans) << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
