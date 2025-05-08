#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <tuple>
    
int dfs(std::vector<std::tuple<int, int, int>>& A, std::vector<std::vector<int>>& G, int v, int p, int min_c, int64_t& ans) {
    auto [c, x, y] = A[v]; 
    min_c = std::min(min_c, c);

    int one = 0;
    int zero = 0;
    for(int nei : G[v]) {
        if(nei != p) {
            int unsolved = dfs(A, G, nei, v, min_c, ans);
            if(unsolved < 0) {
                zero += -unsolved;
            } else if(unsolved > 0) {
                one += unsolved;
            }
        }
    }

    if(x != y) {
        if(x == 0) {
            zero += 1;
        } else {
            one += 1;
        }
    }

    int d = std::min(zero, one); 
    ans += int64_t(d) * 2 * min_c;
    
    zero -= d;
    one -= d;
    
    if(zero) {
        return -zero;
    } else {
        return one;
    }
}

void run_case() {
    int N;
    std::cin >> N;

    std::vector<std::tuple<int, int, int>> A(N);
    for(int i = 0; i < N; i++) {
        auto& [C, X, Y] = A[i];
        std::cin >> C >> X >> Y;
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

    int64_t ans = 0;
    if(dfs(A, G, 0, -1, int(2e9), ans) == 0) {
        std::cout << ans << '\n';
        return;
    }

    std::cout << -1 << '\n'; 
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
