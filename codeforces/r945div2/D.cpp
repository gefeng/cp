#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, K;
    std::cin >> N >> K;

    auto query = [](int l, int x) {
        std::cout << "? " << l + 1 << ' ' << x << std::endl;
        int q;
        std::cin >> q;
        return q - 1;
    };

    int max_v = 1;
    for(; max_v <= N; max_v++) {
        int res = query(0, max_v * N);
        if(res == N - 1) {
            break; 
        }
    }

    int ans = -1;
    for(int i = 1; i <= N / K; i++) {
        int m = i * max_v;
        int j = 0;
        int cnt_seg = 0;
        bool ok = true;
        while(j != N) {
            int res = query(j, m);
            if(res == N) {
                ok = false;
                break; 
            }
            if(++cnt_seg == K && res != N - 1) {
                ok = false;
                break;
            }
            j = res + 1;
        } 

        if(ok && cnt_seg == K) {
            ans = std::max(ans, m);
        }
    }

    std::cout << "! " << ans << std::endl;

    int verdict;
    std::cin >> verdict;
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
