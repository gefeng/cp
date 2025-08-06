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

    auto is_power_of_two = [](int x) {
        while(x != 1) {
            if(x % 2) {
                return false;
            }
            x /= 2;
        }
        return true;
    };

    if(is_power_of_two(N)) {
        std::cout << -1 << '\n';
        return;
    }

    int ans = 0;
    for(int i = 1; i <= N; i++) {
        if(is_power_of_two(i)) {
            ans += S[i - 1] == '0' ? 1 : 0;
        } else {
            for(int j = 0; j < 30; j++) {
                if(i & (1 << j)) {
                    continue;
                }
                if((i | (1 << j)) > N) {
                    ans += S[i - 1] == '1' ? 1 : 0; 
                }
                break;
            }
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
