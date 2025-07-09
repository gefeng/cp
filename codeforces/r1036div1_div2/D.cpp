#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    if(K == 1) {
        std::cout << "Yes" << '\n';
        return;
    }

    auto is_pal = [](std::vector<int>& a) {
        int l = 0;
        int r = a.size() - 1;
        while(l < r) {
            if(a[l] != a[r]) {
                return false;
            }
            l += 1;
            r -= 1;
        }
        return true;
    };

    std::vector<int> a(A);
    std::ranges::sort(a);

    if(a[K - 1] == a[K - 2]) {
        std::vector<int> b;
        for(int i = 0; i < N; i++) {
            if(A[i] <= a[K - 1]) {
                b.push_back(A[i]);
            }
        }

        int l = 0;
        int r = b.size() - 1;
        int v = a[K - 1];
        int cnt = b.size() - (K - 1);
        while(l < r) {
            if(b[l] != b[r]) {
                if((b[l] != v && b[r] != v) || cnt == 0) {
                    std::cout << "No" << '\n';
                    return;
                }
                if(b[l] == v) {
                    l += 1;
                } else {
                    r -= 1;
                }
                cnt -= 1;
            } else {
                l += 1;
                r -= 1;
            }
        }
        std::cout << "Yes" << '\n';
    } else {
        std::vector<int> b;
        for(int i = 0; i < N; i++) {
            if(A[i] < a[K - 1]) {
                b.push_back(A[i]);
            }
        }
        std::cout << (is_pal(b) ? "Yes" : "No") << '\n';
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
