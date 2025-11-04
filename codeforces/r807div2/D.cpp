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
    
    if(S[0] != T[0] || S.back() != T.back()) {
        std::cout << -1 << '\n';
        return;
    }

    int64_t ans = 0; 
    std::vector<int> group_a;
    std::vector<int> group_b;
    for(int i = 0; i < N; ) {
        int j = i;
        while(i < N && S[i] == S[j]) {
            i += 1;
        }
        group_a.push_back(j);
    }

    for(int i = 0; i < N; ) {
        int j = i;
        while(i < N && T[i] == T[j]) {
            i += 1;
        }
        group_b.push_back(j);
    }

    if(group_a.size() != group_b.size()) {
        std::cout << -1 << '\n';
        return;
    }

    int size = group_a.size();
    for(int i = 0; i < size; i++) {
        ans += std::abs(group_a[i] - group_b[i]);
    }

    std::cout << ans << '\n';
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
