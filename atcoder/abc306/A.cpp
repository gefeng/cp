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
    std::string S;
    std::cin >> N >> S;

    std::string ans;
    for(int i = 0; i < N; i++) {
        ans.push_back(S[i]);
        ans.push_back(S[i]);
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
