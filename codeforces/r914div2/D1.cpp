#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    std::vector<int> B(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    for(int i = 0; i < N; i++) {
        if(A[i] > B[i]) {
            std::cout << "No" << '\n';
            return;
        }
    }

    std::set<int> s(B.begin(), B.end());
    for(int x : s) {
        for(int i = 0; i < N; i++) {
            if(A[i] == x) {
                int l = i;
                int r = i;
                while(l - 1 >= 0 && A[l - 1] < x && B[l - 1] >= x) {
                    l -= 1;
                }
                while(r + 1 < N && A[r + 1] < x && B[r + 1] >= x) {
                    r += 1;
                }

                for(int j = l; j <= r; j++) {
                    A[j] = x;
                }
            }
        }
    }

    for(int i = 0; i < N; i++) {
        if(A[i] != B[i]) {
            std::cout << "No" << '\n';
            return;
        }
    }

    std::cout << "Yes" << '\n';
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
