#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using LL = long long;

std::string add(std::string s, std::string t) {
    std::string ans = "";
    int n = s.size();
    int m = t.size();
    int c = 0;
    for(int i = n - 1, j = m - 1; i >= 0 || j >= 0; i--, j--) {
        int x = i < 0 ? 0 : s[i] - '0';
        int y = j < 0 ? 0 : t[j] - '0';
        int z = (x + y + c) % 10;
        c = (x + y + c) / 10;
        ans.push_back((char)(z + '0'));
    }

    if(c) {
        ans.push_back((char)(c + '0'));
    }

    std::reverse(ans.begin(), ans.end());

    return ans;
}

std::string mul(std::string s) {
    return add(s, s); 
}

void run_case() {
    std::string ans = "0";
    std::string base = "1";

    for(int i = 0; i < 64; i++) {
        int A;
        std::cin >> A;

        if(A == 1) {
            ans = add(ans, base); 
        }

        base = mul(base);
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
