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

    int winner = 0;
    int max_v = 0;
    for(int i = 0; i < N; i++) {
        int A, B;
        std::cin >> A >> B;

        if(A <= 10) {
            if(B > max_v) {
                winner = i + 1;
                max_v = B;
            }
        }
    }

    std::cout << winner << '\n';
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
