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

    bool same = true;
    for(int i = 1; i < N; i++) {
        if(A[i] != A[0]) {
            same = false;
            break;
        } 
    }

    if(same) {
        std::cout << 1 << '\n';
        return;
    }

    int ans = 1;
    for(int i = 0; i < N; i++) {
        int d = -1;
        while(i + 1 < N) {
            if(A[i + 1] == A[i]) {
                i += 1;
            } else {
               if(A[i + 1] > A[i]) {
                   if(d == -1) {
                       d = 0;
                   } else if(d == 1) {
                       i -= 1;
                       break;
                   }
                   i += 1;
               } else {
                   if(d == -1) {
                       d = 1;
                   } else if(d == 0) {
                       i -= 1;
                       break;
                   }
                   i += 1;
               } 
            }
        }
        ans += 1;
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
