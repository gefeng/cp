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

    std::vector<int> ans(N, 0);
    if(K % 2 == 1) {
        for(int i = 0; i < N - 1; i++) {
            ans[i] = N;
        }
        ans[N - 1] = N - 1;
    } else {
        if(N == 2) {
            ans[0] = 2;
            ans[1] = 1;
        } else {
            for(int i = 0; i < N; i++) {
                if(i != N - 2) {
                    ans[i] = N - 1; 
                } else {
                    ans[i] = N;
                }
            }
        }
    }

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
