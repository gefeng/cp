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
    std::vector<int> B(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    auto check = [&]() {
        int p1 = -1;
        for(int i = 0; i < N; i++) {
            if(A[i] != B[i]) {
                p1 = i;
                break;
            }
        }

        if(p1 == -1) {
            return true;
        }

        int p2 = N;
        for(int i = p1 + 1, j = p1; i < N; i++, j++) {
            if(A[i] != B[j]) {
                p2 = i;
                break;
            }
        }

        if(A[p1] == B[p2 - 1]) {
            bool ok = true;
            for(int i = p2; i < N; i++) {
                if(A[i] != B[i]) {
                    ok = false;
                    break;
                }
            }
            if(ok) {
                return true;
            }
        }
        return false;
    };

    if(check()) {
        std::cout << "Yes" << '\n';
        return;
    }

    std::ranges::reverse(A);
    std::ranges::reverse(B);
    
    std::cout << (check() ? "Yes" : "No") << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
