#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

int64_t gcd(int64_t a, int64_t b) {
    if(a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

int64_t lcm(int64_t a, int64_t b) {
    return a * b / gcd(a, b);
}

void run_case() {
    int N, X, Y;
    std::cin >> N >> X >> Y;
    
    std::vector<int> A(N - 1);
    std::vector<int> B(N - 1);
    for(int i = 0; i < N - 1; i++) {
        std::cin >> A[i] >> B[i];
    }

    int Q;
    std::cin >> Q;
    std::vector<int> C(Q);
    for(int i = 0; i < Q; i++) {
        std::cin >> C[i];
    }

    int g = 1;
    for(int i = 0; i < N - 1; i++) {
        g = lcm(g, A[i]);
    }

    std::vector<int64_t> save(g, 0);
    for(int i = 0; i < g; i++) {
        int64_t t = i;
        for(int j = 0; j < N - 1; j++) {
            if(t % A[j] == 0) {
                t += B[j];
            } else {
                t += (A[j] - (t % A[j])) + B[j];
            }
        }
        save[i] = t - i;
    }

    for(int i = 0; i < Q; i++) {
        int64_t res = C[i];
        int st = (C[i] + X) % g;
        int64_t t = save[st];
        res = res + X + t + Y;
        std::cout << res << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
