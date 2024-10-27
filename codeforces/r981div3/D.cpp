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

    int ans = 0;
    int64_t sum = 0;
    std::vector<int> suffix(N, 0);
    std::vector<int> prefix(N, 0);
    std::map<int64_t, int> m;
    m[0] = N;
    for(int i = N - 1; i >= 0; i--) {
        sum += A[i];
        suffix[i] = i == N - 1 ? 0 : suffix[i + 1];
        if(m.find(sum) != m.end()) {
            int j = m[sum];
            suffix[i] = std::max(suffix[i], (j < N ? suffix[j] : 0) + 1);
        }
        m[sum] = i;
    }

    sum = 0;
    m.clear();
    m[0] = -1;
    for(int i = 0; i < N; i++) {
        sum += A[i];
        prefix[i] = i == 0 ? 0 : prefix[i - 1];
        if(m.find(sum) != m.end()) {
            int j = m[sum];
            prefix[i] = std::max(prefix[i], (j >= 0 ? prefix[j] : 0) + 1);
        }
        m[sum] = i;
        
        ans = std::max(ans, prefix[i] + (i + 1 < N ? suffix[i + 1] : 0));
        ans = std::max(ans, suffix[i] + (i - 1 >= 0 ? prefix[i - 1] : 0));
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
