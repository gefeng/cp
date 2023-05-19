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
    int N;
    std::cin >> N;

    std::string S;
    std::cin >> S;

    std::set<std::string> seen;
    int ans = 0;
    seen.insert(S.substr(0, 2));
    for(int i = 1; i < N; i++) {
        std::string s = S.substr(i, 2); 
        if(seen.find(s) == seen.end()) {
            ans += 1;
            seen.insert(s);
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
