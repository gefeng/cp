#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

using LL = long long;

void run_case() {
    int N;
    std::cin >> N;

    int r = 0;
    int c = 0;
    int cnt = 0;
    std::vector<int> save(2000, 0);
    for(int i = 0, j = 1, k = 1; i < 2000; i++, k += j, j++) {
        cnt += j;
        save[i] = k;
        if(cnt >= N) {
            r = i;
            c = N - k;
            break;
        }
    }

    LL ans = 0LL;
    for(int i = r, j = 1; i >= 0; i--) {
        int ed = std::min(c, i);

        int st = std::max(0, ed - j + 1);
        int x = save[i] + st;
        int z = ed - st + 1;
        int z1 = z - 1;

        //std::cout << z << '\n';

        ans += (1LL * x * x * z) + 2LL * x * (1LL + z1) * z1 / 2LL + 1LL * z1 * (z1 + 1LL) * (2LL * z1 + 1LL) / 6LL;

        if(ed != i) {
            j += 1; 
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
