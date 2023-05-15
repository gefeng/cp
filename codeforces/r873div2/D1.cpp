#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

using LL = long long;

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    LL ans = 0LL;
    for(int i = 1; i < N; i++) {
        ans += (1LL + i) * i / 2;
    }
    
    for(int i = 1; i < N; i++) {
        int k = i - 1;
        while(k >= 0 && A[k] > A[i]) {
            k -= 1;
        } 

        if(k < 0) {
            continue; 
        }

        int l = k - 1;
        int r = i + 1;
        while(l >= 0 && A[l] < A[i]) {
            l -= 1;
        }
        
        while(r < N && A[r] > A[i]) {
            r += 1;
        }

        ans -= 1LL * (k - l) * (r - i);
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
