#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

constexpr int LOG = 30;
constexpr int MAX = int(1e5);

void run_case() {
    int N, Q;
    std::cin >> N >> Q;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<std::set<int>> prime_factors(MAX + 1);
    for(int i = 2; i <= MAX; i++) {
        if(prime_factors[i].empty()) {
            for(int j = i; j <= MAX; j += i) {
                prime_factors[j].insert(i);
            }
        }
    }

    std::vector<int> nxt(N, -1);
    
    std::set<int> s;
    int r = -1;
    for(int i = 0; i < N; i++) {
        if(i == 0 || nxt[i - 1] == i) {
            s = prime_factors[A[i]]; 
            r = i + 1;
            nxt[i] = r;
        } else {
            for(int x : prime_factors[A[i - 1]]) {
                s.erase(x);
            }
            nxt[i] = nxt[i - 1];
        }

        while(r < N) {
            bool end = false;
            for(int x : prime_factors[A[r]]) {
                if(s.find(x) != s.end()) {
                    nxt[i] = r;
                    end = true;
                    break;
                }
            }
            if(end) {
                break;
            }
            s.insert(prime_factors[A[r]].begin(), prime_factors[A[r]].end()); 
            r += 1;
        }

        if(r == N) {
            nxt[i] = r;
        }
    }

    std::vector<int> dp(N, 0);
    std::vector<std::vector<int>> jump(LOG, std::vector<int>(N, N));
    for(int i = N - 1; i >= 0; i--) {
        int r = nxt[i];
        if(r == N) {
            dp[i] = 1;
        } else {
            dp[i] = dp[r] + 1;
        }
    }

    
    for(int i = 0; i < N; i++) {
        jump[0][i] = nxt[i];
    }

    for(int i = 1; i < LOG; i++) {
        for(int j = 0; j < N; j++) {
            int p = jump[i - 1][j];
            if(p != N) {
                jump[i][j] = jump[i - 1][p];
            }
        }
    }

    for(int i = 0; i < Q; i++) {
        int L, R;
        std::cin >> L >> R;
        L -= 1;
        R -= 1;
        
        int p = L;
        while(true) {
            bool end = true;
            for(int j = LOG - 1; j >= 0; j--) {
                int np = jump[j][p];
                if(np <= R) {
                    p = np;
                    end = false;
                    break;
                }
            }
            if(end) {
                break;
            }
        }

        p = nxt[p];
        int res = dp[L] - (p == N ? 0 : dp[p]); 
        
        std::cout << res << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
