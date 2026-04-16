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
    int Q;
    std::cin >> Q;
    
    std::map<int, int> m;
    int ans = 0;
    for(int i = 0; i < Q; i++) {
        int T, H;
        std::cin >> T >> H;
        
        if(T == 1) {
            m[H]++;
            ans++;
        } else {
            while(!m.empty() && m.begin()->first <= H) {
                ans -= m.begin()->second;
                m.erase(m.begin());
            }
        }
        std::cout << ans << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
