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
    int64_t C;
    std::cin >> N >> C;

    std::vector<int64_t> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    
    int64_t sum = 0;
    for(int i = 1; i < N; i++) {
        sum += A[0] * A[i]; 
        if(sum > C) {
            break;
        }
    }
    if(sum <= C) {
        std::cout << 1 << '\n';
        return;
    }
    
    std::vector<int64_t> a(N - 1);
    for(int i = 1; i < N; i++) {
        a[i - 1] = A[i];
    }

    std::sort(a.begin(), a.end());
    
    sum = 0;
    for(int64_t x : A) {
        sum += x;
    }

    int ans = N;
    int64_t remove = 0;
    for(int i = 0; i < N - 1; i++) {
        remove += a[i]; 
        
        if((sum - remove) * remove <= C) {
            ans = N - (i + 1);
        } else {
            break;
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
