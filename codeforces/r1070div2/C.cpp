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

    std::vector<int> eve;
    std::vector<int> odd;
    for(int x : A) {
        if(x % 2 == 0) {
            eve.push_back(x);
        } else {
            odd.push_back(x);
        }
    }

    std::ranges::sort(eve, std::greater<int>());
    std::ranges::sort(odd, std::greater<int>());

    int n = eve.size();
    int m = odd.size();
    if(m == 0) {
        for(int k = 1; k <= N; k++) {
            std::cout << 0 << " \n"[k == N];
        }
        return;
    }

    std::vector<int64_t> psum(n + 1, 0);
    for(int i = 0; i < n; i++) {
        psum[i + 1] = psum[i] + eve[i];
    }

    for(int k = 1; k <= N; k++) {
        int64_t sum = 0;
        if(k == 1) {
            sum = odd[0]; 
        } else {
            int cnt_eve = std::min(n, k - 1);
            if(cnt_eve == k - 1) {
                sum = odd[0] + psum[cnt_eve];
            } else {
                int extra = k - 1 - cnt_eve;
                if(extra % 2 == 0) {
                    sum = odd[0] + psum[cnt_eve];
                } else {
                    if(cnt_eve && m - 1 > extra) {
                        cnt_eve -= 1;
                        sum = odd[0] + psum[cnt_eve];
                    }
                }
            }
        }

        std::cout << sum << " \n"[k == N];
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
