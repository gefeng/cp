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

    std::vector<int> ans;
    if(N == 1) {
        for(int i = 0; i < K; i++) {
            std::cout << 1 << " \n"[i == K - 1];
        }
        return;
    }
    
    if(N % 2 == 0) {
        int mid = N / 2; 
        ans.push_back(mid);        
        for(int i = N; i > 0; i--) {
            int cnt = i == mid ? K - 1 : K;
            for(int j = 0; j < cnt; j++) {
                ans.push_back(i);
            }
        }
    } else {
        int mid = (N + 1) / 2;
        for(int i = 0; i < K; i++) {
            ans.push_back(mid);
        } 

        ans.push_back(mid - 1);
        
        for(int i = N; i > 0; i--) {
            if(i == mid) {
                continue;
            } 

            int cnt = i == mid - 1 ? K - 1 : K;
            for(int j = 0; j < cnt; j++) {
                ans.push_back(i);
            }
        }
    }

    for(int i = 0; i < N * K; i++) {
        std::cout << ans[i] << " \n"[i == N * K - 1];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
