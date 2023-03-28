#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

using LL = long long;

void run_case() {
    std::string S;
    std::cin >> S;

    std::map<int, int> m;
    
    LL ans = 0LL;
    int mask = 0;
    m[0] += 1;
    for(char c : S) {
        mask ^= 1 << (c - '0');
        
        ans += m[mask];    
        m[mask] += 1;
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
