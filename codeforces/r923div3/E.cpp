#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    // a0 a1 a2 a3 a4 a5 a6
    // ai + k should diff by 1
    int N, K;
    std::cin >> N >> K;
    
    std::vector<int> ans(N, -1);
    int l = 1;
    int r = N;
    for(int i = 0, t = 0; i < N; i++, t ^= 1) {
        if(i + K >= N || l > r) {
            break;
        }
        if(t == 0) {
            for(int j = i; j < N; j += K) {
                ans[j] = l++;
                if(l > r) {
                    break;
                }
            }
        } else {
            for(int j = i; j < N; j += K) {
                ans[j] = r--;
                if(l > r) {
                    break;
                }
            }
        }
    }

    for(int i = 0; i < N; i++) {
        if(ans[i] == -1) {
            ans[i] = l++;
        }
    } 

    /*int max_s = 0;
    int min_s = 1e9;
    for(int i = 0; i <= N - K; i++) {
        int sum = 0;
        for(int j = 0; j < K; j++) {
            sum += ans[j + i]; 
        }
        max_s = std::max(max_s, sum);
        min_s = std::min(min_s, sum);
    }

    std::cout << max_s - min_s << '\n';*/

    for(int i = 0; i < N; i++) {
        std::cout << ans[i] << " \n"[i == N - 1];
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
