#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>

void run_case() {
    int N;
    std::cin >> N;

    std::string S, T;
    std::cin >> S >> T;

    std::vector<int> ans;
    for(int i = N - 1; i >= 0; i--) {
        if(S[i] != T[i]) {
            if(S[0] != S[i]) {
                ans.push_back(1);
                S[0] = S[i];
            }
            ans.push_back(i + 1);
            for(int j = 0; j < i + 1; j++) {
                S[j] = static_cast<char>(((S[j] - '0') ^ 1) + '0');
            }
            std::ranges::reverse(S.begin(), S.begin() + i + 1);
        } 
    }

    assert(S == T);

    int size = ans.size();
    std::cout << size << " \n"[size == 0];
    for(int i = 0; i < size; i++) {
        std::cout << ans[i] << " \n"[i == size - 1];
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
