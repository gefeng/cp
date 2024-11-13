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

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    } 

    std::vector<int> lis;
    int ans = 0;
    for(int i = 0; i < N; i++) {
        if(lis.empty() || A[i] >= lis.back()) {
            lis.push_back(A[i]);
        } else {
            auto it = std::upper_bound(lis.begin(), lis.end(), A[i]);
            *it = A[i];
        }
        
        ans = lis.size() + ((i + 1) - lis.size()) * 2;
        
        std::cout << ans << " \n"[i == N - 1];
    }
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
