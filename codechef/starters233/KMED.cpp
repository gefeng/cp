#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, K;
    std::cin >> N >> K;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::ranges::sort(A);
    
    std::vector<int> ans;
    for(int i = 0; i < N; i++) {
        int l = (N - K) % 2 == 0 ? (N - K) / 2 - 1 : (N - K) / 2;
        int r = (N - K) / 2;
        
        if(i >= l && N - 1 - i >= r) {
            ans.push_back(A[i]);
        }
    }

    ans.erase(std::unique(ans.begin(), ans.end()), ans.end());

    int size = ans.size();
    for(int i = 0; i < size; i++) {
        std::cout << ans[i] << " \n"[i == size - 1];
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
