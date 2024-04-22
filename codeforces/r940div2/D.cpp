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

    std::vector<std::vector<int>> save_l(N, std::vector<int>(2, 0));
    std::vector<std::vector<int>> save_r(N, std::vector<int>(2, 0));
    std::vector<int> cnt(30, 0);
    int sum = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 29; j >= 0; j--) {
            if(A[i] & (1 << j)) {
                if(sum & (1 << j)) {
                    save_l[i][0] = cnt[j];
                    save_l[i][1] = i - cnt[j] + 1;
                } else {
                    save_l[i][1] = cnt[j];
                    save_l[i][0] = i - cnt[j] + 1;
                }
                break; 
            }
        }

        sum ^= A[i];
        for(int j = 0; j < 30; j++) {
            if(sum & (1 << j)) {
                cnt[j] += 1;
            }
        }
    }

    sum = 0;
    cnt.assign(30, 0);
    for(int i = N - 1; i >= 0; i--) {
        for(int j = 29; j >= 0; j--) {
            if(A[i] & (1 << j)) {
                if(sum & (1 << j)) {
                    save_r[i][0] = cnt[j];
                    save_r[i][1] = N - i - 1 - cnt[j] + 1;
                } else {
                    save_r[i][0] = N - i - 1 - cnt[j] + 1;
                    save_r[i][1] = cnt[j];
                }
                break; 
            }
        }
        
        sum ^= A[i];
        for(int j = 0; j < 30; j++) {
            if(sum & (1 << j)) {
                cnt[j] += 1;
            }
        }
    }

    int64_t ans = 0;
    for(int i = 0; i < N; i++) {
        ans += int64_t(save_l[i][0]) * int64_t(save_r[i][1]);
        ans += int64_t(save_l[i][1]) * int64_t(save_r[i][0]);
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
