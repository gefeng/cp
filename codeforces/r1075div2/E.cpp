#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>

void run_case() {
    int N;
    std::cin >> N;
    
    std::string S;
    std::cin >> S;

    int zero = std::ranges::count(S, '0');
    int one = N - zero;
    if(zero == N) {
        std::cout << -1 << '\n';
        return;
    }

    int ans = -1; // minimum operations to make "1"

    if(N == 1) {
        ans = 0;
    } else if(one >= zero) {
        ans = 1;
    } else if(zero - one == 1) {
        ans = 2;
    } else {
        std::array<int, 2> c{};
        for(int i = 0; i < N; i++) {
            c[S[i] - '0'] += 1;
            if(c[1] > c[0]) {
                ans = 2;
                break;
            }
        }

        c.fill(0);
        for(int i = N - 1; i >= 0; i--) {
            c[S[i] - '0'] += 1;
            if(c[1] > c[0]) {
                ans = 2;
                break;
            }
        }
        
        if(ans == -1) {
            c.fill(0);
            int min_v = 0;
            for(int i = 0; i < N; i++) {
                c[S[i] - '0'] += 1;
                if(c[1] - c[0] - min_v >= 2 || c[0] == c[1]) {
                    ans = 3;
                    break;
                }
                min_v = std::min(min_v, c[1] - c[0]);
            }

            c.fill(0);
            min_v = 0;
            for(int i = N - 1; i >= 0; i--) {
                c[S[i] - '0'] += 1;
                if(c[1] - c[0] - min_v >= 2 || c[0] == c[1]) {
                    ans = 3;
                    break;
                }
                min_v = std::min(min_v, c[1] - c[0]);
            }
        }
        
        if(ans == -1) {
            ans = 4;
        }
    }
    
    std::cout << N + ans - 1 << '\n';
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
