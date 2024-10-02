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
    int N, Q;
    std::cin >> N >> Q;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::map<int64_t, int64_t> m;
    for(int i = 0; i < N; i++) {
        int64_t cnt = int64_t(i) * (N - i) + N - i - 1;
        m[cnt] += 1;
        
        if(i + 1 < N) {
            cnt = int64_t(i + 1) * (N - i - 1);
            m[cnt] += A[i + 1] - A[i] - 1;
        }
    }

    for(int i = 0; i < Q; i++) {
        int64_t K;
        std::cin >> K;
       
        std::cout << m[K] << " \n"[i == Q - 1];
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
