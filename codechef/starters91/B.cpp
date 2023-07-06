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

    std::string ans = "";
    if(N <= 15) {
        ans.append("Lower ");
        if(N <= 10) {
            ans.append("Double");
        } else {
            ans.append("Single");
        }
    } else {
        ans.append("Upper ");
        if(N <= 25) {
            ans.append("Double");
        } else {
            ans.append("Single");
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
