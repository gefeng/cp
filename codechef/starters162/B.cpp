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
    
    std::string S;
    std::cin >> S;

    int cnt_a = 0;
    int cnt_b = 0;
    for(int i = 0; i < N; i++) {
        if(S[i] == 'A') {
            if(cnt_b != 0) {
                cnt_b -= 1;
            }
            cnt_a += 1;
        } else {
            if(cnt_a != 0) {
                cnt_a -= 1;
            }
            cnt_b += 1;
        }
    }

    std::cout << cnt_a + cnt_b << '\n';
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
