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

    for(int i = 0; i < N; i++) {
        std::vector<int> freq(200, 0);
        int max_f = 0;
        for(int j = i; j < N; j++) {
            freq[A[j]] += 1;
            int most = 0;
            if(freq[A[j]] > max_f) {
                max_f = freq[A[j]];
                most = A[j]; 
            } 

            if(most == K) {
                std::cout << "YES" << '\n';
                return;
            }
        }
    }

    std::cout << "NO" << '\n';
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
