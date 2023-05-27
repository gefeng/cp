#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using LL = long long;

void run_case() {
    std::string S;
    
    std::vector<LL> v;
    LL sum = 0LL;
    while(std::getline(std::cin, S)) {
        if(S.empty()) {
            v.push_back(sum);
            sum = 0LL;
        } else {
            sum += stol(S);
        } 
    }

    v.push_back(sum);
    
    std::sort(v.begin(), v.end(), std::greater<LL>());
    
    LL ans = 0LL;
    for(int i = 0; i < 3; i++) {
        ans += v[i]; 
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
