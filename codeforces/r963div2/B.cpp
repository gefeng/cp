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
    
    bool good = true;
    for(int i = 0; i < N; i++) {
        if(A[i] % 2 != A[0] % 2) {
            good = false;
            break;
        }
    }

    if(good) {
        std::cout << 0 << '\n';
        return;
    }

    int cnt_eve = 0;
    for(int i = 0; i < N; i++) {
        if(A[i] % 2 == 0) {
            cnt_eve += 1;
        }
    }

    if(A.back() % 2 == 1) {
        std::cout << cnt_eve << '\n';
        return;
    }

    int64_t now = 0;
    int ans = cnt_eve;
    for(int i = N - 1; i >= 0; i--) {
        if(A[i] % 2 == 1) {
            now = A[i];
            for(int j = i - 1; j >= 0; j--) {
                now += A[j] % 2 == 0 ? A[j] : 0;
            }
            
            bool ok = true;
            for(int j = i + 1; j < N; j++) {
                if(A[j] % 2 == 0) {
                    if(now > A[j]) {
                        now += A[j];
                    } else {
                        ok = false;
                        break;
                    }
                }
            }
            
            if(!ok) {
                ans += 1;
            }
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
