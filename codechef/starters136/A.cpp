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

    std::string S;
    std::cin >> S;

    int64_t ans = (int64_t)(N + 1) * N / 2;
    
    std::map<int, int> m;
    m[0] = 1;
    int sum = 0;
    for(int i = 0; i < N; i++) {
        if(S[i] == '1') {
            sum += 1;
        } else {
            sum -= 1;
        }

        if(m.find(sum) != m.end()) {
            ans += m[sum];
        }
        
        m[sum] += 1;
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
