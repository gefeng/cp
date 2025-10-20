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

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> seen(N + 1, 0);
    for(int i = 0; i < N; i++) {
        seen[A[i]] = 1;
    }

    int x = 0;
    for(int i = 1; i <= N; i++) {
        if(!seen[i]) {
            x = i;
            break;
        }
    }

    if(x == 0) {
        for(int i = 0; i < K; i++) {
            std::cout << A[i] << " \n"[i == K - 1];
        } 
        return;
    }

    std::vector<int> ans;
    ans.push_back(x);
    A.push_back(x);
    for(int i = 0; i < K - 1; i++) {
        for(int x = 1; x <= N; x++) {
            if(x != A.back() && x != A[A.size() - 2]) {
                A.push_back(x);
                ans.push_back(x);
                break;
            }
        } 
    }

    for(int i = 0; i < K; i++) {
        std::cout << ans[i] << " \n"[i == K - 1];
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
