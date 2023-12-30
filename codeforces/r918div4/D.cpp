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
    std::cin >> N;

    std::string S;
    std::cin >> S;

    auto is_vowel = [](char c) {
        return c == 'a' || c == 'e';
    };

    std::vector<std::string> a;
    for(int i = N - 1; i >= 0; i--) {
        if(!is_vowel(S[i])) {
            a.push_back(S.substr(i - 2, 3));
            i -= 2;
        } else {
            a.push_back(S.substr(i - 1, 2));
            i -= 1;
        }
    }

    std::string ans = "";
    for(int i = a.size() - 1; i >= 0; i--) {
        ans.append(a[i]);
        if(i > 0) {
            ans.push_back('.');
        }

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
