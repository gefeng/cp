#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>
#include <set>

void dfs(std::vector<std::vector<int>>& G, std::vector<int>& A, int v, int p, std::vector<int>& parent, 
        std::vector<int>& cnt_black_c, std::vector<std::set<int>>& black_c, std::set<int>& white_p) {
    parent[v] = p;

    for(int nei : G[v]) {
        if(nei != p) {
            if(A[nei]) {
                cnt_black_c[v] += 1;
            }
            dfs(G, A, nei, v, parent, cnt_black_c, black_c, white_p);
        }
    }

    if(A[v]) {
        black_c[std::min(3, cnt_black_c[v])].insert(v);
    } else {
        if(cnt_black_c[v]) {
            white_p.insert(v);
        }
    }
}

void run_case() {
    int N, Q;
    std::cin >> N >> Q;
    
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

    std::vector<int> cnt_black_c(N, 0); // for each node count how many black children
    std::vector<std::set<int>> black_c(4); // store black node has 0/1/2/3+ black children
    std::set<int> white_p; 
    std::vector<int> parent(N, -1);
    dfs(G, A, 0, -1, parent, cnt_black_c, black_c, white_p);

    for(int i = 0; i < Q; i++) {
        int V;
        std::cin >> V;
        V -= 1;
        
        if(A[V]) {
            // black -> white
            if(V != 0) {
                int p = parent[V];
                cnt_black_c[p] -= 1;
                if(A[p]) {
                    black_c[std::min(3, cnt_black_c[p] + 1)].erase(p);
                    black_c[std::min(3, cnt_black_c[p])].insert(p);
                } else {
                    if(cnt_black_c[p] == 0) {
                        white_p.erase(p);
                    }
                }
            }

            black_c[std::min(3, cnt_black_c[V])].erase(V);
            if(cnt_black_c[V]) {
                white_p.insert(V);
            }
        } else {
            // white -> black
            if(V != 0) {
                int p = parent[V];
                cnt_black_c[p] += 1;
                if(A[p]) {
                    black_c[std::min(3, cnt_black_c[p] - 1)].erase(p);
                    black_c[std::min(3, cnt_black_c[p])].insert(p);
                } else {
                    white_p.insert(p);
                }
            }

            black_c[std::min(3, cnt_black_c[V])].insert(V);
            auto it = white_p.find(V);
            if(it != white_p.end()) {
                white_p.erase(it);
            }
        }

        A[V] ^= 1;

        bool has_black = false;
        for(int j = 0; j < 4; j++) {
            if(!black_c[j].empty()) {
                has_black = true;
                break;
            }
        }

        if(!has_black || !black_c[3].empty() || black_c[2].size() > 1) {
            std::cout << "No" << '\n';
            continue;
        } 

        if(black_c[2].size() == 1) {
            int v = *black_c[2].begin();

            if(v != 0 && A[parent[v]]) {
                std::cout << "No" << '\n';
                continue;
            }
        } 

        if(A[0] && !white_p.empty()) {
            std::cout << "No" << '\n'; 
            continue;
        }

        if(!A[0]) {
            if(white_p.size() > 1) {
                std::cout << "No" << '\n';
                continue;
            }
            if(white_p.size() == 1 && cnt_black_c[*white_p.begin()] > 1) {
                std::cout << "No" << '\n';
                continue;
            }
        }

        std::cout << "Yes" << '\n';
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
