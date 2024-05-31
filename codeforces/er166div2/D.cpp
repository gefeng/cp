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
    std::string S;
    std::cin >> S;

    int n = S.size();
    int sum = 0;
    int64_t ans = 0;
    std::map<int, int> m; 
    m[0] = 1;
    for(int i = 0; i < n; i++) {
        sum += S[i] == '(' ? 1 : -1;
        if(sum > 0 && m.find(sum) != m.end()) {
            ans += m[sum];
        }
        m[sum] += 1;
        
        int t = (sum - 1) / 2;
        while(!m.empty() && m.begin()->first <= t) {
            m.erase(m.begin());
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
