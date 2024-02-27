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

    std::array<int, 26> a = {};
    for(int i = 0; i < 26; i++) {
        a[i] = i;
    }

    int Q;
    std::cin >> Q;
    for(int i = 0; i < Q; i++) {
        char C, D;
        std::cin >> C >> D;

        for(int j = 0; j < 26; j++) {
            if(a[j] == C - 'a') {
                a[j] = D - 'a';
            }
        } 
    }

    for(int i = 0; i < N; i++) {
        S[i] = (char)(a[S[i] - 'a'] + 'a');
    }

    std::cout << S << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
