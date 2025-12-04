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

    std::vector<int> ps;
    for(int i = 0; i * i <= N - 1 + N - 1; i++) {
        ps.push_back(i * i);
    }

    int now = N - 1;
    std::vector<int> ans(N, 0);

    while(now >= 0) {
        auto it = std::prev(std::upper_bound(ps.begin(), ps.end(), now + now));
        int t = *it;    

        int l = t - now;
        
        for(int i = l; i <= now; i++) {
            ans[i] = t - i;
        }
    
        now = l - 1;
    }
    
    for(int i = 0; i < N; i++) {
        std::cout << ans[i] << " \n"[i == N - 1];
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
