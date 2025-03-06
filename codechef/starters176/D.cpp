#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

std::vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

void dfs(std::vector<std::vector<int>>& G, std::vector<int>& A, int v, int p, std::set<int>& s, int64_t& ans) {
    std::vector<int> removed;
    if(p != -1) {
        for(int x : s) {
            if(A[v] % x != 0) {
                removed.push_back(x); 
            }
        }
    }

    for(int x : removed) {
        s.erase(x);
    }

    for(int p : primes) {
        if(s.find(p) == s.end()) {
            ans += p;
            break;
        }
    }

    for(int nei : G[v]) {
        if(nei != p) {
            dfs(G, A, nei, v, s, ans);
        }
    }

    for(int x : removed) {
        s.insert(x);
    }
}

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<std::vector<int>> G(N);
    for(int i = 0; i < N - 1; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        G[U].push_back(V);
        G[V].push_back(U);
    }

    for(int i = 0; i < N; i++) {
        int64_t sum = 0;
        std::set<int> s;
        int x = A[i];
        for(int f = 2; f * f <= x; f++) {
            if(x % f == 0) {
                s.insert(f);
                while(x % f == 0) {
                    x /= f;
                }
            }
        }
        if(x > 1) {
            s.insert(x);
        }
        dfs(G, A, i, -1, s, sum);
        std::cout << sum << " \n"[i == N - 1];
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
