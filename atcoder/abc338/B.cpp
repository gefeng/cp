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

    std::array<int, 26> cnt = {};
    for(char c : S) {
        cnt[c - 'a'] += 1;
    }

    int max_f = 0;
    int ans = 0;
    for(int i = 0; i < 26; i++) {
        if(cnt[i] > max_f) {
            max_f = cnt[i];
            ans = i;
        }
    }

    std::cout << (char)(ans + 'a') << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
