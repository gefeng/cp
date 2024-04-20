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
    std::array<int, 26> freq{};
    for(int i = 0; i < n; i++) {
        freq[S[i] - 'a'] += 1;
    }

    bool good = true;
    for(int i = 1; i <= n; i++) {
        int cnt = 0;
        for(int j = 0; j < 26; j++) {
            if(freq[j] == i) {
                cnt += 1;
            }
        }

        if(cnt != 0 && cnt != 2) {
            good = false;
            break;
        }
    }

    std::cout << (good ? "Yes" : "No") << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
