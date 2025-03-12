#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <tuple>

void run_case() {
    int N;
    std::cin >> N;

    std::string S, T;
    std::cin >> S >> T;
    
    std::vector<std::tuple<int, int, int>> ans;
    for(int i = 0; i < N; i++) {
        if(S[i] == T[i]) {
            continue;
        }
        if(i == N - 1 || S[i + 1] == T[i + 1]) {
            ans.emplace_back(1, i, i);
        } else {
            if(S[i] == S[i + 1]) {
                ans.emplace_back(1, i, i + 1);
            } else {
                ans.emplace_back(2, i, i + 1);
            }
            i += 1;
        }
    }

    int k = ans.size();
    std::cout << k << '\n';
    for(auto [t, l, r] : ans) {
        std::cout << t << ' ' << l + 1 << ' ' << r + 1 << '\n'; 
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
