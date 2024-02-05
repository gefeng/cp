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

    std::string ans = "";
    int i = S.size() - 1;
    while(S[i] != '.') {
        ans.push_back(S[i--]);
    }

    std::reverse(ans.begin(), ans.end());

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
