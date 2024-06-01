#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

constexpr int MAX = (int)1e6;

std::vector<int> primes;

void eulerian_path(std::vector<std::set<int>>& g, int v, std::vector<int>& ans) {
    while(!g[v].empty()) {
        int u = *g[v].begin();
        g[v].erase(u);
        if(u != v) {
            g[u].erase(v);
        }
        eulerian_path(g, u, ans);
    }
    ans.push_back(v);
}

void run_case() {
    int N;
    std::cin >> N;
    
    int m = 1;
    while(true) {
        int cnt_e = m * (m + 1) / 2;
        if(m % 2 == 0) {
            cnt_e -= m / 2 - 1;
        }

        if(cnt_e >= N - 1) {
            break;
        }
    
        m += 1;
    }

    std::vector<std::set<int>> g(m);
    for(int i = 0; i < m; i++) {
        for(int j = i; j < m; j++) {
            if(m % 2 == 0 && i % 2 == 0 && i < m - 2 && i == j - 1) {
                continue; 
            }
            g[i].insert(j);
            if(i != j) {
                g[j].insert(i);
            }
        }
    }

    std::vector<int> ans;
    int st = m % 2 == 0 ? (m / 2 - 1) * 2 : 0;
    eulerian_path(g, st, ans);
    std::reverse(ans.begin(), ans.end());

    for(int i = 0; i < N; i++) {
        std::cout << primes[ans[i]] << " \n"[i == N - 1];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    std::vector<int> is_prime(MAX + 1, 1);
    for(int i = 2; i <= MAX; i++) {
        if(is_prime[i]) {
            primes.push_back(i);
            for(int j = i + i; j <= MAX; j += i) {
                is_prime[j] = 0;
            }
        }
    }
    
    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
