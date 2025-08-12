#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

constexpr int MAX = static_cast<int>(1e6);

int gcd(int a, int b) {
    if(a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

std::vector<int> max_pf(MAX + 1, 0);
std::vector<std::vector<int>> pf(MAX + 1);
std::vector<std::vector<std::pair<int, int>>> prod(MAX + 1);

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> m(M + 1, 0);
    auto solve = [&](std::vector<int>& a) {
        int n = a.size();
        m.assign(M + 1, 0);

        for(int i = 0; i < n; i++) {
            for(auto [p, c] : prod[a[i]]) {
                m[p] += 1;
            }
        }
        
        for(int i = 0; i < n; i++) {
            for(auto [p, c] : prod[a[i]]) {
                m[p] -= 1;
            }

            int cnt = n - i - 1;

            for(auto [p, c] : prod[a[i]]) {
                if(c) {
                    cnt -= m[p]; 
                } else {
                    cnt += m[p];
                }
            }
            
            if(cnt > 0) {
                for(int j = i + 1; j < n; j++) {
                    if(gcd(a[i], a[j]) == 1) {
                        return std::pair<int, int>(i, j);
                    }
                }
            }
        }

        return std::pair<int, int>(-1, -1);
    };

    std::array<int, 4> ans = {};
    ans.fill(-1);

    auto [x1, y1] = solve(A);
    if(x1 == -1) {
        std::cout << 0 << '\n';
        return;
    }

    assert(gcd(A[x1], A[y1]) == 1);

    std::vector<int> a(N - 2);
    for(int i = 0, j = 0; i < N; i++) {
        if(i != x1 && i != y1) {
            a[j++] = A[i];
        }
    }

    auto [x2, y2] = solve(a);
    if(x2 != -1) {
        ans[0] = x1;
        ans[1] = y1;
        for(int i = 0; i < N; i++) {
            if(A[i] == a[x2] && i != x1 && i != y1) {
                ans[2] = i;
                break;
            } 
        } 
        for(int i = 0; i < N; i++) {
            if(A[i] == a[y2] && i != x1 && i != y1 && i != ans[2]) {
                ans[3] = i;
                break;
            }
        }
    } else {
        ans[0] = x1;
        ans[2] = y1;
        std::vector<int> x;
        std::vector<int> y;
        for(int i = 0; i < N; i++) {
            if(i != x1 && i != y1 && gcd(A[x1], A[i]) == 1) {
                x.push_back(i);
            }
            if(i != x1 && i != y1 && gcd(A[y1], A[i]) == 1) {
                y.push_back(i);
            }
        }
        if(x.empty() || y.empty()) {
            std::cout << 0 << '\n';
            return;
        }
        if(x[0] != y[0]) {
            ans[1] = x[0];
            ans[3] = y[0];
        } else {
            if(x.size() > 1) {
                ans[1] = x[1];
                ans[3] = y[0];
            } else if(y.size() > 1) {
                ans[1] = x[0];
                ans[3] = y[1];
            } else {
                std::cout << 0 << '\n';
                return;
            }
        }
    }
    for(int i = 0; i < 4; i++) {
        if(ans[i] == -1) {
            std::cout << 0 << '\n';
            return;
        }
    }

    for(int i = 0; i < 4; i++) {
        std::cout << ans[i] + 1 << " \n"[i == 3];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    for(int i = 2; i <= MAX; i++) {
        if(max_pf[i] == 0) {
            max_pf[i] = i;
            for(int j = i + i; j <= MAX; j += i) {
                max_pf[j] = std::max(max_pf[j], i);
            }
        }
    }

    for(int i = 2; i <= MAX; i++) {
        int x = i; 
        while(x > 1) {
            int f = max_pf[x];
            pf[i].push_back(f);
            while(x % f == 0) {
                x /= f;
            }
        }
        int size = pf[i].size();

        for(int j = 0; j < size; j++) {
            int sz = prod[i].size();
            for(int k = 0; k < sz; k++) {
                auto [p, c] = prod[i][k];
                prod[i].emplace_back(p * pf[i][j], c ^ 1);
            }
            prod[i].emplace_back(pf[i][j], 1);
        }
    }
    
    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
