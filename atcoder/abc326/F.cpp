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
    int N, X, Y;
    std::cin >> N >> X >> Y;

    std::vector<int> A;
    std::vector<int> B;
    for(int i = 0; i < N; i++) {
        int P;
        std::cin >> P;
        if(i % 2 == 0) {
            B.push_back(P);
        } else {
            A.push_back(P);
        }
    }

    auto solve = [](const std::vector<int>& a, int t) {
        int n = a.size();
        int m1 = n / 2;
        int m2 = (n + 1) / 2;
        std::map<int, int> seen;
        for(int i = 0; i < (1 << m1); i++) {
            int sum = 0;
            for(int j = 0; j < m1; j++) {
                if(i & (1 << j)) {
                    sum += a[j];
                } else {
                    sum -= a[j];
                } 
            } 
            seen[sum] = i;
        }

        for(int i = 0; i < (1 << m2); i++) {
            int sum = 0;
            for(int j = 0; j < m2; j++) {
                if(i & (1 << j)) {
                    sum += a[j + m1];
                } else {
                    sum -= a[j + m1];
                }
            }
            if(seen.find(t - sum) != seen.end()) {
                return ((int64_t)i << m1) | seen[t - sum];
            }
        }

        return (int64_t)-1;
    };

    int64_t x = solve(A, X);
    int64_t y = solve(B, Y);
    if(x == -1 || y == -1) {
        std::cout << "No" << '\n';
        return;
    }

    int dx = 0;
    int dy = 0;
    int n = A.size();
    int m = B.size();
    std::string ans = ""; 
    
    for(int i = 0, j = 0; i < n || j < m; ) {
        if(j < m) {
            int b = (y & ((int64_t)1 << j)) ? 1 : 0;
            if(b == 0) {
                ans.push_back(dx == 0 ? 'R' : 'L');
                dy = 1;
            } else {
                ans.push_back(dx == 0 ? 'L' : 'R');
                dy = 0;
            }
            j += 1;
        }

        if(i < n) {
            int b = (x & ((int64_t)1 << i)) ? 1 : 0;
            if(b == 0) {
                ans.push_back(dy == 0 ? 'L' : 'R');
                dx = 1;
            } else {
                ans.push_back(dy == 0 ? 'R' : 'L');
                dx = 0;
            }
            i += 1;
        }
    }

    std::cout << "Yes" << '\n' << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
