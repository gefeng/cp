#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    std::string S;
    std::cin >> S;

    int n = S.size();
    std::array<int, 26> cnt = {};
    for(int i = 0; i < n; i++) {
        cnt[S[i] - 'a'] += 1;
    }

    int c = 0;
    for(int i = 0; i < 26; i++) {
        if(cnt[i] == 1) {
            c = i;
            break;
        }
    }

    for(int i = 0; i < n; i++) {
        if(S[i] - 'a' == c) {
            std::cout << i + 1 << '\n';
            return;
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
