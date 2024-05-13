#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

struct two_sat {
    int n;
    std::vector<std::vector<int>> adj, adj_t;
    std::vector<bool> used;
    std::vector<int> order, comp;
    std::vector<bool> assignment;

    two_sat(int n) : n(n) {
        adj.resize(n);
        adj_t.resize(n);
    }

    void dfs1(int v) {
        used[v] = true;
        for (int u : adj[v]) {
            if (!used[u])
                dfs1(u);
        }
        order.push_back(v);
    }

    void dfs2(int v, int cl) {
        comp[v] = cl;
        for (int u : adj_t[v]) {
            if (comp[u] == -1)
                dfs2(u, cl);
        }
    }

    bool solve_2SAT() {
        order.clear();
        used.assign(n, false);
        for (int i = 0; i < n; ++i) {
            if (!used[i])
                dfs1(i);
        }

        comp.assign(n, -1);
        for (int i = 0, j = 0; i < n; ++i) {
            int v = order[n - i - 1];
            if (comp[v] == -1)
                dfs2(v, j++);
        }

        assignment.assign(n / 2, false);
        for (int i = 0; i < n; i += 2) {
            if (comp[i] == comp[i + 1])
                return false;
            assignment[i / 2] = comp[i] > comp[i + 1];
        }
        return true;
    }

    void add_disjunction(int a, bool na, int b, bool nb) {
        // na and nb signify whether a and b are to be negated 
        a = 2*a ^ na;
        b = 2*b ^ nb;
        int neg_a = a ^ 1;
        int neg_b = b ^ 1;
        adj[neg_a].push_back(b);
        adj[neg_b].push_back(a);
        adj_t[b].push_back(neg_a);
        adj_t[a].push_back(neg_b);
    }
};

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<std::vector<int>> A(3, std::vector<int>(N));
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < N; j++) {
            std::cin >> A[i][j];
        }
    }

    two_sat ts(N * 2);
    for(int c = 0; c < N; c++) {
        ts.add_disjunction(std::abs(A[0][c]) - 1, A[0][c] < 0, std::abs(A[1][c]) - 1, A[1][c] < 0);
        ts.add_disjunction(std::abs(A[0][c]) - 1, A[0][c] < 0, std::abs(A[2][c]) - 1, A[2][c] < 0);
        ts.add_disjunction(std::abs(A[1][c]) - 1, A[1][c] < 0, std::abs(A[2][c]) - 1, A[2][c] < 0);
    }

    std::cout << (ts.solve_2SAT() ? "Yes" : "No") << '\n';
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
