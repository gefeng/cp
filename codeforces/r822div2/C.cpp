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

    std::string S;
    std::cin >> S;

    std::vector<int> removed(N + 1, 0);
    int k = 1;
    int64_t ans = 0;
    while(k <= N) {
        for(int i = k; i <= N; i += k) {
            if(removed[i]) {
                continue;
            }
            if(S[i - 1] == '0') {
                ans += k; 
                removed[i] = 1;
            } else { 
                break;
            }
        }
        k += 1;
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
