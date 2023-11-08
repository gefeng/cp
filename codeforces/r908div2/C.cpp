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

    std::vector<int> vis(N, 0);
    int p = N - 1;
    while(K) {
        if(A[p] > N) {
            std::cout << "No" << '\n';
            return;
        } 

        if(vis[p]) {
            std::cout << "Yes" << '\n';
            return;
        }

        vis[p] = 1;
        p = (p - A[p] + N) % N;
        K -= 1;
    }
    
    std::cout << "Yes" << '\n';
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
