#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int A, B, C;
    std::cin >> A >> B >> C;

    int cur = 1;
    int cnt_c = 0;
    int d = 0;
    while(cur) {
        int nxt = 0;
        for(int i = 0; i < cur; i++) {
            if(A) {
                nxt += 2;
                A -= 1;
            } else if(B) {
                nxt += 1;
                B -= 1;
            } else {
                cnt_c += 1;
            }
        }

        std::swap(cur, nxt);

        d += 1;
    }

    std::cout << (cnt_c == C ? d - 1 : -1) << '\n';
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
