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

    int ans = 0;
    for(int i = 0; i <= N - 3; i++) {
        std::string s = S.substr(i, 3);
        if("pie" == s || "map" == s) {
            ans += 1;
        }
    }

    for(int i = 0; i <= N - 5; i++) {
        std::string s = S.substr(i, 5);
        if("mapie" == s) {
            ans -= 1;
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
