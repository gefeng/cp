#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

void run_case() {
    int N, T;
    std::cin >> N >> T;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::map<int, int> m;
    for(int i = 0; i < N; i++) {
        if(m.find(A[i]) == m.end()) {
            if(T >= A[i] && m.find(T - A[i]) != m.end()) {
                m[A[i]] = 1;
            } else {
                m[A[i]] = 0;        
            }
        }
    }

    int cnt = 0;
    std::vector<int> ans(N);
    for(int i = 0; i < N; i++) {
        if(A[i] * 2 == T) {
            cnt += 1;
        } else {
            ans[i] = m[A[i]];
        }
    }

    cnt /= 2;
    for(int i = 0; i < N; i++) {
        if(A[i] * 2 == T && cnt) {
            ans[i] = 1;
            cnt -= 1;
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
