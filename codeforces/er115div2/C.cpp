#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <numeric>
#include <map>

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int64_t sum = std::accumulate(A.begin(), A.end(), int64_t(0));

    if((sum * 2) % N != 0) {
        std::cout << 0 << '\n';
        return;
    }

    int t = sum * 2 / N;
    int64_t ans = 0;
    std::map<int, int> freq;
    for(int i = 0; i < N; i++) {
        int x = t - A[i];
        if(freq.find(x) != freq.end()) {
            ans += freq[x]; 
        }
        freq[A[i]] += 1;
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
