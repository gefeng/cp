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
    std::string ans = "";
    int i = 0;
    while(S[i] != '|') {
        ans.push_back(S[i++]);
    }
    
    i += 1;
    while(S[i] != '|') {
        i += 1;
    }

    i += 1;
    while(i < n) {
        ans.push_back(S[i++]);
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
