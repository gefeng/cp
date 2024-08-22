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
    
    std::array<std::string, 2> A;
    for(int i = 0; i < 2; i++) {
        std::cin >> A[i]; 
    }

    int ans = 0;
    std::array<int, 2> seen = {};
    for(int i = 0; i < N; i++) {
        int c1 = A[0][i] - '0';
        int c2 = A[1][i] - '0';
        seen[c1] = 1;
        seen[c2] = 1;
        
        int mex = 0;
        for(int j = 0; j < 2; j++) {
            if(seen[j]) {
                mex += 1;
            } else {
                break;
            }
        }

        if(mex == 2) {
            if(c1 == 1 && c2 == 1) {
                ans += 1;
            } else {
                ans += 2;
            }
            seen.fill(0);
            mex = 0;
        } else {
            ans += mex;
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
