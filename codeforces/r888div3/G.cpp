#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

struct dsu {
    int n;
    std::vector<int> p;
    std::vector<int> w;
    
    dsu(int n) : n(n) {
        p.resize(n, -1);
        w.resize(n, 1);
    }

    int find(int i) {
        if(p[i] < 0) {
            return i;
        }
        return p[i] = find(p[i]);
    }

    void unite(int i, int j) {
        int x = find(i);
        int y = find(j);
        
        if(x == y) {
            return;
        }

        if(w[x] >= w[y]) {
            p[y] = x;
            w[x] += w[y];
        } else {
            p[x] = y;
            w[y] += w[x];
        }
    }

    bool same(int i, int j) {
        return find(i) == find(j);
    }
};

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<std::pair<int, int>> E;
    for(int i = 0; i < M; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        E.emplace_back(U, V);
    }

    int Q;
    std::cin >> Q;
    std::vector<std::vector<int>> B(Q, std::vector<int>(4));
    for(int i = 0; i < Q; i++) {
        for(int j = 0; j < 3; j++) {
            std::cin >> B[i][j];
        }
        B[i][0] -= 1;
        B[i][1] -= 1;
        B[i][3] = i;
    } 

    std::sort(E.begin(), E.end(), [&](const auto& e1, const auto& e2) {
        return std::max(A[e1.first], A[e1.second]) < std::max(A[e2.first], A[e2.second]);
    });

    std::sort(B.begin(), B.end(), [&](const auto& q1, const auto& q2) {
        return A[q1[0]] + q1[2] < A[q2[0]] + q2[2];
    });

    std::vector<int> ans(Q, 0);
    dsu uf(N);
    int e = 0;
    for(auto& q : B) {
        int a = q[0];
        int b = q[1];
        
        while(e < M && std::max(A[E[e].first], A[E[e].second]) <= A[a] + q[2]) {
            uf.unite(E[e].first, E[e].second);
            e += 1;
        }

        ans[q[3]] = uf.same(a, b) ? 1 : 0;
    }

    for(int i = 0; i < Q; i++) {
        std::cout << (ans[i] ? "YES" : "NO") << '\n';
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
