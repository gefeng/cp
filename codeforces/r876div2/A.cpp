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
    
    std::vector<int> a(N, 0);
    int cnt = 0;
    for(int i = 0; i < N; i++) {
        int need = (i + 1 + K - 1) / K;
        if(need > cnt) {
            a[i] = 1;
            cnt += 1;
        }
    }

    cnt = 0;
    for(int i = 0; i < N; i++) {
        int need = (i + 1 + K - 1) / K;

        if(a[N - 1 - i] == 1) {
            cnt += 1;
        }
        
        if(need > cnt) {
            if(a[N - 1 - i] == 0) {
                a[N - 1 - i] = 1;
                cnt += 1;
            } 
        }
    }

    int ans = 0;
    for(int i = 0; i < N; i++) { 
        ans += a[i];
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
