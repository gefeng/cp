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

    std::map<int64_t, int> m;
    m[0] = -1;
    int64_t sum = 0;
    int64_t ans = 0;
    int max_p = -1;
    bool found = false;
    for(int i = 0; i < N; i++) {
        sum += A[i]; 
        
        if(m.find(sum) != m.end()) {
            int j = m[sum];
            max_p = std::max(max_p, j);
            ans += i - max_p - 1;
            found = true;
        } else { 
            ans += found ? i - max_p - 1 : i + 1; 
        }
    
        m[sum] = i;
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
