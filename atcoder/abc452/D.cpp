#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    std::string S, T;
    std::cin >> S >> T;

    std::vector<std::vector<int>> pos(26);
    int n = S.size();
    int m = T.size();

    for(int i = 0; i < n; i++) {
        pos[S[i] - 'a'].push_back(i);
    }

    int64_t ans = 0;
    for(int i = 0; i < n; i++) {
        if(i + 1 < m) {
            ans += i + 1;
            continue;
        }

        int now = i;
        int j = m - 1;
        bool ok = true;
        while(j >= 0) {
            int t = T[j] - 'a';
            auto it = std::upper_bound(pos[t].begin(), pos[t].end(), now);
            if(it == pos[t].begin()) {
                ok = false;
                break;
            }
            it--;
            now = *it - 1;
            j--;
        }
        
        if(!ok) {
            ans += i + 1;
        } else {
            ans += i - now - 1;
        }
    }
    
    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
