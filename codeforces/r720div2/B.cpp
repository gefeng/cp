#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

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

    std::vector<std::array<int, 4>> ans;
    for(int i = 1; i < N; i++) {
        if(gcd(A[i], A[i - 1]) != 1) {
            if(A[i] > A[i - 1]) {
                ans.push_back({i, i + 1, A[i - 1], A[i - 1] + 1});
                A[i] = A[i - 1] + 1;
            } else {
                if(i - 1 == 0) {
                    ans.push_back({i, i + 1, A[i], A[i] + 1});
                    A[i - 1] = A[i];
                    A[i] += 1;
                } else {
                    int x = A[i] + 1;
                    while(gcd(A[i - 2], x) != 1 || gcd(x, A[i]) != 1) {
                        x += 1;
                    }
                    ans.push_back({i, i + 1, x, A[i]});
                    A[i - 1] = x;
                }
            }
        }
    }

    int k = ans.size();
    std::cout << k << '\n';
    for(int i = 0; i < k; i++) {
        for(int j = 0; j < 4; j++) {
            std::cout << ans[i][j] << " \n"[j == 3];
        }
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
