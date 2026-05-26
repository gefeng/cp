#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::map<int, int> m;
    for(int x : A) {
        m[x]++;
    }

    int64_t ans = 0;
    while(m.size() > 1) {
        auto [min_v, c1] = *m.begin();
        auto [max_v, c2] = *m.rbegin();
        
        if(max_v % 2 == 0) {
            if(min_v + 1 == max_v) {
                if(min_v == 1) {
                    ans += std::min(c1, c2);
                } else {
                    ans += c1;
                }
                break;
            }
            m[max_v / 2] += c2;
            ans += c2;
            m.erase(max_v);
        } else {
            m[(max_v + 1) / 2] += c2;
            ans += c2 * 2;
            m.erase(max_v);
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
