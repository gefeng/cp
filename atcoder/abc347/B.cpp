#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

void run_case() {
    std::string S;
    std::cin >> S;

    std::set<std::string> s;
    int n = S.size();
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            s.insert(S.substr(i, j - i + 1));
        }
    }

    std::cout << s.size() << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
