#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, Q;
    std::cin >> N >> Q;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        A[i]--;
    }

    std::vector<int> a(N);
    for(int i = 0; i < N; i++) {
        a[A[i]] = i;
    }

    int t = 0;
    for(int i = 0; i < Q; i++) {
        int T;
        std::cin >> T;
        
        if(T == 1) {
            int X, Y;
            std::cin >> X >> Y;
            X--;
            Y--;
            if(t) {
                std::swap(A[a[X]], A[a[Y]]);
                std::swap(a[X], a[Y]);
            } else {
                std::swap(a[A[X]], a[A[Y]]);
                std::swap(A[X], A[Y]);
            }
        } else {
            t ^= 1;
        }
    }

    std::vector<int> ans = t ? std::move(a) : std::move(A);
    
    for(int i = 0; i < N; i++) {
        std::cout << ans[i] + 1 << " \n"[i == N - 1];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
