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
    
    std::vector<int> ans(N + 1, 0);
    std::vector<std::vector<int>> a(20);
    
    int hb = 0;
    for(int i = 1; i <= N; i *= 2, hb++) {
        for(int x = i; x <= std::min(N, i * 2 - 1); x++) {
            a[hb].push_back(x);
        }
    }

    hb--;
    int now = N * 2;
    ans[N] = 1;
    a[hb].pop_back();
    
    for(int b = hb; b >= 0; b--) {
        for(int x : a[b]) {
            ans[x] = 0;
            now ^= x;
        }

        if((now & (1 << b)) || b == 0) {
            continue;
        }

        int y = a[b - 1].back(); 
        a[b - 1].pop_back();
        ans[y] = 1;
        now ^= y * 2;
    }

    {
        int xor_s = 0;
        int or_s = 0;
        for(int i = 1; i <= N; i++) {
            xor_s ^= ans[i] ? i * 2 : i;
            or_s |= i;
        }
        assert(xor_s == now && xor_s >= 2 * or_s);
    }

    for(int i = 1; i <= N; i++) {
        std::cout << ans[i] << " \n"[i == N];
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
