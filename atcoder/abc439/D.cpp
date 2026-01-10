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
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int64_t ans = 0;
    std::map<int, int> m1;
    std::map<int, int> m2;
    for(int i = 0; i < N; i++) {
        if(A[i] % 5 == 0) {
            int x = A[i] / 5;
            int64_t c1 = 0;
            int64_t c2 = 0;
            if(m1.find(x) != m1.end()) {
                c1 += m1[x];
            }
            if(m2.find(x) != m2.end()) {
                c2 += m2[x];
            }
            ans += c1 * c2;
        }
        if(A[i] % 3 == 0) {
            m1[A[i] / 3] += 1;
        }
        if(A[i] % 7 == 0) {
            m2[A[i] / 7] += 1;
        }
    }

    m1.clear();
    m2.clear();
    for(int i = N - 1; i >= 0; i--) {
        if(A[i] % 5 == 0) {
            int x = A[i] / 5;
            int64_t c1 = 0;
            int64_t c2 = 0;
            if(m1.find(x) != m1.end()) {
                c1 += m1[x];
            }
            if(m2.find(x) != m2.end()) {
                c2 += m2[x];
            }
            ans += c1 * c2;
        }
        if(A[i] % 3 == 0) {
            m1[A[i] / 3] += 1;
        }
        if(A[i] % 7 == 0) {
            m2[A[i] / 7] += 1;
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
