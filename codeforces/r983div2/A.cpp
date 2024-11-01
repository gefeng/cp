#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<int> A(N * 2);
    int cnt = 0;
    for(int i = 0; i < N * 2; i++) {
        std::cin >> A[i];
        if(A[i]) {
            cnt += 1;
        }
    }
    
    int min_on = cnt % 2;
    int max_on = std::min(cnt, N * 2 - cnt);
    
    std::cout << min_on << ' ' << max_on << '\n';
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
