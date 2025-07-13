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
    
    std::string ans = S;
    int x = 1;
    for(int k = 2; k <= N; k++) {
        std::string s = S.substr(k - 1, N - k + 1);
        std::string t = S.substr(0, k - 1);
        if((N - k + 1) % 2 == 1) {
            std::reverse(t.begin(), t.end());
        }
        s += t;

        if(s < ans) {
            ans = s;
            x = k;
        }
    }

    std::cout << ans << '\n' << x << '\n';;
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
