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

    int first_one = -1;
    int last_zero = -1;
    for(int i = 0; i < N; i++) {
        if(S[i] == '1') {
            first_one = first_one == -1 ? i : first_one;
        } else {
            last_zero = i;
        }
    }

    if(first_one != -1 && last_zero != -1 && first_one < last_zero) {
        std::string ans = S.substr(0, first_one) + S.substr(last_zero, N - last_zero);
        std::cout << ans << '\n';
    } else {
        std::cout << S << '\n';
    }
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
