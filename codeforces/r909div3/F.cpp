#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>

void run_case() {
    int N, Q;
    std::cin >> N >> Q;

    std::vector<int> A(Q);
    for(int i = 0; i < Q; i++) {
        std::cin >> A[i];
    }

    std::vector<std::vector<int>> g(N, std::vector<int>(N, 0));
    std::map<int, std::vector<int>> q;
    for(int i = 0; i < N - 1; i++) {
        std::cout << i + 1 << ' ' << i + 2 << '\n';
        g[i][i + 1] = 1;
        g[i + 1][i] = 1;
    }

    int d1 = N - 1;
    int d2 = N - 1;
    int u = N - 1;
    int v = N - 2;
    for(int i = 0; i < Q; i++) {
        if(A[i] == d1 || A[i] == d2) {
            std::cout << -1 << ' ' << -1 << ' ' << -1 << '\n';
            continue;
        }

        int nv = A[i] - 1;
        std::cout << u + 1 << ' ' << v + 1 << ' ' << nv + 1 << '\n';
        v = nv;

        d1 = A[i];
        d2 = d1 == N - 1 ? N - 1 : N - v - 1;
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
