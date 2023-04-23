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

    int max_l = 0;
    int cnt = 0;
    for(int i = 0; i < N; i++) {
        if(S[i] == 'o') {
            cnt += 1;
        } else {
            max_l = std::max(max_l, cnt);
            cnt = 0;
        }
    }

    max_l = std::max(max_l, cnt);

    if(max_l == 0 || max_l == N) {
        std::cout << -1 << '\n';
    } else {
        std::cout << max_l << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
