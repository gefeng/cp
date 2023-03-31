#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

using LL = long long;

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::map<int, std::vector<int>> odd_m;
    std::map<int, std::vector<int>> eve_m;

    for(int i = 0; i < N; i++) {
        if(i % 2 == 0) {
            eve_m[A[i]].push_back(i);
        } else {
            odd_m[A[i]].push_back(i);
        }
    }

    LL ans = 0LL;
    for(int i = 0; i < N; i++) {
        int r = std::min(K - 1, std::max(2 * N - 1 - 2 * i - K, 0));
        int l = std::max(2, 2 * (K / 2 - i));
        //std::cout << i << ' ' << l << ' ' << r << '\n';
        
        std::vector<int>& pos = i % 2 == 0 ? eve_m[A[i]] : odd_m[A[i]];

        auto it_r = upper_bound(pos.begin(), pos.end(), i + r);
        auto it_l = upper_bound(pos.begin(), pos.end(), i + l - 1);

        int tot = r / 2 - (l - 1) / 2;
        int same = it_r - it_l;
        //std::cout << i << ' ' << tot << ' ' << same << '\n'; 
        ans += tot - same;
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
