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

    std::vector<int> vis(N + 1, 0);
    for(int i = 1; i <= N / 2; i++) {
        if(vis[i]) {
            continue;
        }
        
        std::vector<int> a;
        for(int j = i; j <= N; j *= 2) {
            a.push_back(A[j - 1]);
            vis[j] = 1;
        }
        std::ranges::sort(a);
        
        for(int j = i, k = 0; j <= N; j *= 2, k++) {
            A[j - 1] = a[k];
        }
    }

    for(int i = 1; i < N; i++) {
        if(A[i] < A[i - 1]) {
            std::cout << "NO" << '\n';
            return;
        }
    }

    std::cout << "YES" << '\n';
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
