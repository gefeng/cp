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

    int64_t ans = 0;
    
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            int64_t max_v = i * j;
            std::set<int> slots;
            for(int k = 1; k <= N; k++) {
                if(i != k) {
                    slots.insert(k);
                }
            }
            
            bool ok = true;
            int64_t sum = 0;
            for(int k = N; k >= 1; k--) {
                if(k == j) {
                    continue;
                }
                auto it = slots.upper_bound(max_v / k);
                if(it == slots.begin()) {
                    ok = false;
                    break;
                }

                it--;
                sum += *it * k; 
                slots.erase(it);
            }

            if(ok) {
                ans = std::max(ans, sum);
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
