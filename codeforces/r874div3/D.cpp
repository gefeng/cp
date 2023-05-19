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
    
    int max_v = A[0] == N ? N - 1 : N;

    std::vector<int> ans(N);
    for(int i = 0; i < N; i++) {
        ans[i] = i + 1;
    }

    int p = 0;
    for(int i = 0; i < N; i++) {
        if(A[i] == max_v) {
            p = i;
            break;
        } 
    }

    if(p == N - 1) {
        std::vector<int> v(N);
        v[0] = max_v;
        for(int i = 1; i < N; i++) {
            v[i] = A[i - 1];
        }

        ans = std::max(ans, v);
    }


    for(int l = 0; l < p; l++) { 
        std::vector<int> v(N);
        int j = 0;
        for(int i = p; i < N; i++) {
            v[j++] = A[i]; 
        }

        for(int i = p - 1; i >= l; i--) {
            v[j++] = A[i]; 
        } 

        for(int i = 0; i < l; i++) {
            v[j++] = A[i];
        }

        ans = std::max(ans, v);
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
