#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int X;
    std::cin >> X;

    std::vector<int> a;
    int sum = 0;
    for(int i = 1; sum < X; ) {
        sum += i;
        a.push_back(i++);
    }

    int ans = a.size() + sum - X;

    for(int i : a) {
        if(i != 1 && sum - i >= X) {
            ans = std::min(ans, sum - i - X + static_cast<int>(a.size()));
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
