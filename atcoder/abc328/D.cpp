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

    std::string s;
    int n = S.size();
    for(int i = 0; i < n; i++) {
        if(s.size() > 1 && s.back() == 'B' && s[s.size() - 2] == 'A' && S[i] == 'C') {
            s.pop_back();
            s.pop_back();
        } else {
            s.push_back(S[i]);
        }
    }

    std::cout << s << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
