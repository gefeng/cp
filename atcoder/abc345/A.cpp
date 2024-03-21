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

    if(S[0] == '<' && S.back() == '>') {
        int n = S.size();
        int cnt = 0;
        for(int i = 1; i < n - 1; i++) { 
            if(S[i] == '=') {
                cnt += 1;
            }
        }

        if(cnt && cnt == n - 2) {
            std::cout << "Yes" << '\n';
            return;
        }
    }

    std::cout << "No" << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
