#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t INF = (int64_t)5e18;

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
    int N, X, Y, Z;
    std::cin >> N >> X >> Y >> Z;

    std::vector<int64_t> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<std::array<int64_t, 4>> a(N);
    for(int i = 0; i < N; i++) {
        a[i][0] = A[i] <= X ? X - A[i] : ((A[i] + X - 1) / X * X) - A[i];
        a[i][1] = A[i] <= Y ? Y - A[i] : ((A[i] + Y - 1) / Y * Y) - A[i];
        a[i][2] = A[i] <= Z ? Z - A[i] : ((A[i] + Z - 1) / Z * Z) - A[i];
        a[i][3] = i;
    } 

    std::vector<std::array<int64_t, 4>> cand;
    std::sort(a.begin(), a.end(), [](const auto& a, const auto& b) {
                return a[0] < b[0];
            });

    for(int i = 0; i < std::min(3, N); i++) {
        cand.push_back(a[i]);
    } 

    
    std::sort(a.begin(), a.end(), [](const auto& a, const auto& b) {
                return a[1] < b[1];
            });

    for(int i = 0; i < std::min(3, N); i++) {
        cand.push_back(a[i]);
    }

    std::sort(a.begin(), a.end(), [](const auto& a, const auto& b) {
                return a[2] < b[2];
            });

    for(int i = 0; i < std::min(3, N); i++) {
        cand.push_back(a[i]);
    }

    int64_t lcmxyz = lcm(lcm(X, Y), Z);
    int64_t lcmxy = lcm(X, Y);
    int64_t lcmxz = lcm(X, Z);
    int64_t lcmyz = lcm(Y, Z);
    int64_t ans = INF;
    int sz = cand.size();
    for(int i = 0; i < N; i++) {
        if(A[i] <= lcmxyz) {
            ans = std::min(ans, lcmxyz - A[i]);
        } else {
            ans = std::min(ans, ((A[i] + lcmxyz - 1) / lcmxyz * lcmxyz) - A[i]);
        }
    }

    for(int i = 0; i < N; i++) {
        int64_t d = A[i] <= lcmxy ? lcmxy - A[i] : ((A[i] + lcmxy - 1) / lcmxy * lcmxy) - A[i];
        for(int j = 0; j < sz; j++) {
            if(cand[j][3] != i) {
                ans = std::min(ans, d + cand[j][2]);
            }
        }
    }
    for(int i = 0; i < N; i++) {
        int64_t d = A[i] <= lcmxz ? lcmxz - A[i] : ((A[i] + lcmxz - 1) / lcmxz * lcmxz) - A[i];
        for(int j = 0; j < sz; j++) {
            if(cand[j][3] != i) {
                ans = std::min(ans, d + cand[j][1]);
            }
        }
    }
    for(int i = 0; i < N; i++) {
        int64_t d = A[i] <= lcmyz ? lcmyz - A[i] : ((A[i] + lcmyz - 1) / lcmyz * lcmyz) - A[i];
        for(int j = 0; j < sz; j++) {
            if(cand[j][3] != i) {
                ans = std::min(ans, d + cand[j][0]);
            }
        }
    }


    for(int i = 0; i < sz; i++) {
        for(int j = 0; j < sz; j++) {
            for(int k = 0; k < sz; k++) {
                if(cand[i][3] != cand[j][3] && cand[i][3] != cand[k][3] && cand[j][3] != cand[k][3]) {
                    ans = std::min(ans, cand[i][0] + cand[j][1] + cand[k][2]);
                }
            }
        }
    }
    
    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
