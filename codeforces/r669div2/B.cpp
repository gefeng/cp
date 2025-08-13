#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>

int gcd(int a, int b) {
    if(a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::ranges::sort(A, std::greater<int>());
    std::vector<int> ans(N, 0);
    std::vector<int> vis(N, 0);
    ans[0] = A[0];
    vis[0] = 1;

    int g = ans[0];
    for(int i = 1; i < N; i++) {
        int max_g = 0;
        int p = -1;
        for(int j = 0; j < N; j++) {
            if(!vis[j]) {
                int x = gcd(g, A[j]);
                if(x > max_g) {
                    max_g = x;
                    p = j;
                } else if(x == max_g) {
                    if(p == -1 || A[j] > A[p]) {
                        p = j;
                    }
                }
            }
        }
        ans[i] = A[p];
        vis[p] = 1;
        g = max_g;
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
