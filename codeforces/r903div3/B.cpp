#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    std::array<int64_t, 3> A;
    for(int i = 0; i < 3; i++) {
        std::cin >> A[i];
    }

    int64_t sum = A[0] + A[1] + A[2];
    
    bool ans = false;
    for(int i = 0; i <= 3; i++) {
        int tot = i + 3;
        if(sum % tot != 0) {
            continue;
        } 

        int64_t t = sum / tot;
        int cnt = i;
        bool ok = true;
        for(int j = 0; j < 3; j++) {
            int64_t x = A[j];
            while(x > t && cnt) {
                x -= t;
                cnt -= 1; 
            }

            if(x < t || x > t) {
                ok = false;
                break;
            }
        }

        if(ok) {
            ans = true;
            break;
        }
    }

    std::cout << (ans ? "Yes" : "No") << '\n';
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
