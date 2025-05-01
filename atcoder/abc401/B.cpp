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

    int ans = 0;
    int logged_in = 0;
    for(int i = 0; i < N; i++) {
        std::string S;
        std::cin >> S;

        if(S == "login") {
            logged_in = 1;
        } else if(S == "logout") {
            logged_in = 0;
        } else if(S == "public") {
        } else if(S == "private") {
            if(!logged_in) {
                ans += 1;
            }
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
