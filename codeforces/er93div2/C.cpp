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

    std::map<int, int> m;
    m[1] = 1;
    
    int sum = 0;
    int64_t ans = 0;
    for(int i = 0; i < N; i++) {
        sum += S[i] - '0'; 
        
        int t = sum - i;
        
        ans += m.find(t) == m.end() ? 0 : m[t];
        
        m[sum - i] += 1;
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
