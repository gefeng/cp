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

    std::vector<int> first(N + 1, -1);
    for(int i = 0; i < N; i++) {
        if(first[A[i]] == -1) {
            first[A[i]] = i;
        } 
    }

    int p = N - 1;
    while(p - 1 >= 0 && A[p - 1] <= A[p]) {
        p -= 1;
    }

    for(int i = p; i < N; i++) {
        if(first[A[i]] < p) {
            p = i + 1;
        }
    }

    std::vector<int> seen(N + 1, 0);
    for(int i = 0; i < p; i++) {
        seen[A[i]] = 1;
    }
    
    int ans = 0;
    for(int i = 1; i <= N; i++) {
        ans += seen[i];
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
