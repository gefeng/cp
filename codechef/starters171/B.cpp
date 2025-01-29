#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int INF = int(2e9);

void run_case() {
    int N, P;
    std::cin >> N >> P;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        if(A[i] == 0) {
            A[i] = INF;
        }
    }

    std::vector<int> nxt(N, -1);
    std::vector<int> pre(N, -1);
    std::vector<int> ans(N, INF);
    std::vector<int> stk;

    for(int i = 0; i < N; i++) {
        while(!stk.empty() && A[stk.back()] <= A[i]) {
            stk.pop_back();
        }

        if(!stk.empty()) {
            pre[i] = stk.back();
        }

        stk.push_back(i);
    } 

    stk.clear();
    
    for(int i = N - 1; i >= 0; i--) {
        while(!stk.empty() && A[stk.back()] <= A[i]) {
            stk.pop_back();
        }

        if(!stk.empty()) {
            nxt[i] = stk.back();
        }
        
        stk.push_back(i);
    }

    for(int i = 0; i < N; i++) {
        int j = pre[i];
        if(j == -1) {
            continue; 
        }

        if(A[j] == INF) {
            ans[i] = std::min(ans[i], (A[i] + P - 1) / P);
        } else {
            ans[i] = std::min(ans[i], ans[j]);
        }
    }

    for(int i = N - 1; i >= 0; i--) {
        int j = nxt[i];
        if(j == -1) {
            continue;
        }

        if(A[j] == INF) {
            ans[i] = std::min(ans[i], (A[i] + P - 1) / P);
        } else {
            ans[i] = std::min(ans[i], ans[j]);
        }
    }

    for(int i = 0; i < N; i++) {
        ans[i] = ans[i] == INF ? 0 : ans[i];
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
