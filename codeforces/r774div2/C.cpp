#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>
#include <set>

void run_case() {
    int64_t N;
    std::cin >> N;
    
    std::vector<int64_t> fact;
    int64_t f = 1;
    int64_t x = 1;
    while(f <= N) {
        fact.push_back(f);
        f *= ++x;
    }

    int n = fact.size();
    int ans = __builtin_popcountll(N);
    for(int i = 0; i < (1 << n); i++) {
        int64_t sum = 0;
        int cnt = 0;
        for(int j = 0; j < n; j++) {
            if(i & (int64_t(1) << j)) {
                sum += fact[j];
                cnt += 1;
            }
        }
        if(sum <= N) {
            cnt += __builtin_popcountll(N - sum); 
            ans = std::min(ans, cnt);
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
