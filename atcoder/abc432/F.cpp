#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <numeric>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int sum = std::accumulate(A.begin(), A.end(), 0);
    if(sum % N != 0) {
        std::cout << -1 << '\n';
        return;
    }

    int t = sum / N;
    for(int i = 0; i < N; i++) {
        A[i] -= t;
    }

    std::vector<int> dp(1 << N, -1);
    std::vector<int> pre(1 << N, -1);
    dp[0] = 0;
    for(int i = 0; i < (1 << N); i++) {
        int s = 0;
        for(int j = 0; j < N; j++) {
            if(i & (1 << j)) {
                s += A[j];
            }
        }

        for(int j = 0; j < N; j++) {
            if(i & (1 << j)) {
                continue;
            }
            int nxt = A[j] + s == 0 ? dp[i] + 1 : dp[i];
            int m = i | (1 << j);
            
            if(nxt > dp[m]) {
                dp[m] = nxt;
                pre[m] = i;
            }
        } 
    }

    sum = 0;
    int now = (1 << N) - 1;
    std::vector<std::vector<int>> groups;
    std::vector<int> g;
    while(now != 0) {
        int nxt = pre[now];
        int i = now ^ nxt;
        for(int j = 0; j < N; j++) {
            if(i & (1 << j)) {
                g.push_back(j);
                sum -= A[j];
                break;
            }
        }
        if(sum == 0) {
            groups.push_back(g);
            g.clear();
        }
        now = nxt;
    }

    std::vector<std::tuple<int, int, int>> seq;
    for(auto& g : groups) {
        int size = g.size();
        if(size == 1) {
            continue;
        }
        int p = -1;
        for(int i = 0; i < size; i++) {
            if(A[g[i]] < 0) {
                p = i;
                break;
            }
        }

        for(int i = 0; i < size; i++) {
            if(A[g[i]] > 0) {
                seq.emplace_back(g[i] + 1, g[p] + 1, A[g[i]]);
            }
        }
        
        for(int i = 0; i < size; i++) {
            if(A[g[i]] < 0 && i != p) {
                seq.emplace_back(g[p] + 1, g[i] + 1, -A[g[i]]);
            }
        }
    }

    int q = seq.size();
    std::cout << q << '\n';
    for(auto [x, y, z] : seq) {
        std::cout << x << ' ' << y << ' ' << z << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
