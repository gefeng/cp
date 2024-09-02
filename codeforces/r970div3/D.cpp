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
        A[i] -= 1;
    }

    std::string S;
    std::cin >> S;

    std::vector<int> vis(N, 0);
    std::vector<int> ans(N, 0);
    for(int i = 0; i < N; i++) {
        if(vis[i]) {
            continue;
        } 

        int now = i;
        int cnt = 0;
        std::vector<int> all;
        while(!vis[now]) {
            if(S[now] == '0') {
                cnt += 1; 
            }
            all.push_back(now);
            vis[now] = 1;
            now = A[now];
        }

        for(int x : all) {
            ans[x] = cnt;
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
