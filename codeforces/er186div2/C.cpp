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
    std::vector<int> B(N);
    std::vector<int> C(N);
    
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> C[i];
    }

    int64_t ans = 0;
    int64_t cnt = 0;
    for(int x = 0; x < N; x++) {
        bool ok = true;
        for(int i = 0; i < N; i++) {
            int j = (i + x) % N;
            if(B[i] >= C[j]) {
                ok = false;
                break;
            }
        } 
        if(ok) {
            cnt += 1;
        }
    }

    for(int x = 0; x < N; x++) {
        bool ok = true;
        for(int i = 0; i < N; i++) {
            int j = (i + x) % N;
            if(A[i] >= B[j]) {
                ok = false;
                break;
            }
        } 
        if(ok) {
            ans += cnt * N;
        }
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
