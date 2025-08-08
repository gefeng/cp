#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

std::set<int> dfs(std::vector<std::vector<int>>& G, std::vector<int>& A, std::vector<int>& B, int v, int p, int64_t& sum) {
    std::set<int> s;
    bool add = false;
    int first = 0;
    int second = 0;
    for(int nei : G[v]) {
        if(nei != p) {
            std::set<int> x = dfs(G, A, B, nei, v, sum);
            if(s.size() < x.size()) {
                std::swap(s, x);
            }
            for(int c : x) {
                if(s.find(c) != s.end()) {
                    if(first == 0) {
                        first = c;
                    } else if(second == 0 && c != first) {
                        second = c;
                    }
                }
            }
            for(int c : x) {
                s.insert(c);
            }
            if(B[v]) {
                if((first && !second && first != B[v]) || (first && second)) {
                    add = true;
                } 
            } else {
                if(first && second) {
                    add = true;
                }
            }
        }
    }

    if(add) {
        sum += A[v];
    }

    B[v] = B[v] ? B[v] : first;

    if(B[v] != 0) {
        s.insert(B[v]);
    }

    return s;
}

void paint(std::vector<std::vector<int>>& G, std::vector<int>& B, int v, int p) {
    if(B[v] == 0) {
        B[v] = p == -1 ? 1 : B[p];
    }

    for(int nei : G[v]) {
        if(nei != p) {
            paint(G, B, nei, v);
        }
    }
}

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> A(N); 
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> B(N);
    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
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

    int64_t sum = 0;
    dfs(G, A, B, 0, -1, sum);

    paint(G, B, 0, -1);
    std::cout << sum << '\n';
    for(int i = 0; i < N; i++) {
        std::cout << B[i] << " \n"[i == N - 1];
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
