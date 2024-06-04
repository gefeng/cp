#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int DEPTH = 30;

struct node {
    std::array<node*, 2> c;
    int ref_cnt;
    node() : c({nullptr, nullptr}), ref_cnt(0) {} 
    ~node() {
        delete c[0];
        delete c[1];
        c[0] = nullptr;
        c[1] = nullptr;
    }
};

void insert(node* root, int x) {
    node* cur = root;
    for(int i = DEPTH - 1; i >= 0; i--) {
        int b = (x & (1 << i)) ? 1 : 0; 
        if(cur->c[b] == nullptr) {
            cur->c[b] = new node(); 
        }
        cur = cur->c[b];
        cur->ref_cnt += 1;
    }
}

void remove(node* root, int x) {
    node* par = nullptr;
    node* cur = root;
    for(int i = DEPTH - 1; i >= 0; i--) {
        int b = (x & (1 << i)) ? 1 : 0;
        par = cur;
        cur = cur->c[b];
        if(--cur->ref_cnt == 0) {
            if(par->c[0] == cur) {
                par->c[0] = nullptr;
            } else {
                par->c[1] = nullptr;
            }
            delete cur;             
            break;
        }
    }
}

int query(node* root, int x) {
    node* cur = root;
    int max_v = 0;
    for(int i = DEPTH - 1; i >= 0; i--) {
        int b = (x & (1 << i)) ? 1 : 0;
        if(cur->c[b ^ 1] != nullptr) {
            cur = cur->c[b ^ 1];
            max_v |= 1 << i;
        } else if(cur->c[b] != nullptr) {
            cur = cur->c[b];
        } else {
            break;
        }
    }
    return max_v;
}

void dfs(std::vector<std::vector<std::pair<int, int>>>& G, int v, int p, int xor_sum, int depth, std::vector<int>& dp, std::vector<int>& parity) {
    dp[v] = xor_sum;
    parity[v] = depth % 2;
    for(auto [u, w] : G[v]) {
        if(u != p) {
            dfs(G, u, v, xor_sum ^ w, depth + 1, dp, parity);
        }
    }
}

void run_case() {
    int N, M;
    std::cin >> N >> M;
    
    std::vector<std::vector<std::pair<int, int>>> G(N);
    for(int i = 0; i < N - 1; i++) {
        int U, V, W;
        std::cin >> U >> V >> W;
        U -= 1;
        V -= 1;
        G[U].emplace_back(V, W);
        G[V].emplace_back(U, W);
    }

    std::vector<int> dp(N, 0);
    std::vector<int> parity(N, 0);
    dfs(G, 0, -1, 0, 0, dp, parity);

    node* r_eve = new node();
    node* r_odd = new node();
    for(int i = 0; i < N; i++) {
        if(parity[i]) {
            insert(r_odd, dp[i]);
        } else {
            insert(r_eve, dp[i]);
        }
    }
    
    int acc = 0;
    for(int i = 0; i < M; i++) {
        char T;
        std::cin >> T;
        
        if(T == '^') {
            int X;
            std::cin >> X;
            acc ^= X;
        } else {
            int V, X;
            std::cin >> V >> X;
            V -= 1;
            
            if(parity[V]) {
                remove(r_odd, dp[V]);
                int q1 = query(r_odd, X ^ dp[V]);
                int q2 = query(r_eve, X ^ acc ^ dp[V]);
                insert(r_odd, dp[V]);
                std::cout << std::max(q1, q2) << ' ';
            } else {
                remove(r_eve, dp[V]);
                int q1 = query(r_odd, X ^ acc ^ dp[V]);
                int q2 = query(r_eve, X ^ dp[V]);
                insert(r_eve, dp[V]);
                std::cout << std::max(q1, q2) << ' ';
            }
        }
    }
    std::cout << std::endl;
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
