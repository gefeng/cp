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

    for(char c1 = 'a'; c1 <= 'z'; c1++) {
        for(char c2 = 'a'; c2 <= 'z'; c2++) {
            for(char c3 = 'a'; c3 <= 'z'; c3++) {
                if(c1 - 'a' + 1 + c2 - 'a' + 1 + c3 - 'a' + 1 == N) {
                    std::string ans = "";
                    ans.push_back(c1);
                    ans.push_back(c2);
                    ans.push_back(c3);
                    std::cout << ans << '\n';
                    return;
                }
            }
        }
    }
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
