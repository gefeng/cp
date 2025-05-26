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

    std::sort(A.begin(), A.end());
    
    if(A[0] % 2 == A.back() % 2) {
        std::cout << 0 << '\n';
        return;
    }

    int ans = 0;
    int cnt = 1;
    for(int i = 1; i < N; i++) {
        if(A[i] % 2 == A[0] % 2) {
            cnt += 1;
        } else {
            break;
        }
    } 

    ans = cnt;
    cnt = 1;
    for(int i = N - 2; i >= 0; i--) {
        if(A[i] % 2 == A.back() % 2) {
            cnt += 1;
        } else {
            break;
        }
    }

    ans = std::min(ans, cnt);
    
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
