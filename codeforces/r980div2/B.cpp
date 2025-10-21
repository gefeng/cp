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

    std::sort(A.begin(), A.end());

    auto strategy1 = [&]() {
        int64_t res = 0;
        int k = K;
        for(int i = 0; i < N; i++) {
            if(k == 0) {
                break;
            }

            int now = i == 0 ? A[i] : A[i] - A[i - 1];
            
            if(i) {
                res += 1;
            }

            if(now == 0) {
                continue;
            }

            int x = N - i;
            int t = std::min(now, k / x);
            k -= t * x;
            res += int64_t(t) * x;

            if(now - t > 0 || t == 0) {
                res += k;
                k = 0;
            }
        }
        return res; 
    };
    
    auto strategy2 = [&]() {
        int64_t res = 0;
        int k = K;
        for(int i = 0; i < N; i++) {
            if(k == 0) {
                break;
            }
            int d = std::min(k, A[i]);
            res += d;
            k -= d;
            if(A[i] == d && k) {
                res += 1; 
            }
        }
        return res;
    };
    

    std::cout << std::min(strategy1(), strategy2()) << '\n';
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
