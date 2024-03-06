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

    std::array<int, 5> coins = {1, 3, 6, 10, 15};
    std::array<int, 24> best = {0, 1, 2, 1, 2, 3, 1, 2, 3, 2, 1, 2, 2, 2, 3, 1, 2, 3, 2, 3, 2, 2, 3, 3};
    //23 = 10 * 2 + 3
    //24 = 15 + 9
    //25 = 15 + 10
    //26 = 15 + 10 + 1
    //27 = 15 + 6 + 6
    //28 = 15 + 10 + 3
    //29 = 15 + 14 


    int ans = N;
    int m = best.size();

    if(N < m) {
        ans = best[N];
    } else {
        for(int i = 0; i < m; i++) {
            int y = N - i;
            if(y % 15 == 0) {
                ans = std::min(ans, y / 15 + best[i]);
            }
        }
    }

    /*3 * 6 + 98 - 18 = 80

    75 + 98 - 75 = 23
    5 * 15 + 10 * 2 + 3

    2 * 1
    1 * 3
    4 * 6 
    2 * 10 */

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
