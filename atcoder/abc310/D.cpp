#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

int64_t dfs(int N, int T, std::vector<std::vector<int>>& A, int p, std::vector<int>& teams) {
    if(p == N) {
        return teams.size() == T ? 1 : 0;
    }

    int64_t res = 0;
    int sz = teams.size();
    for(int i = 0; i < sz; i++) {
        int t = teams[i];
        bool ok = true;
        for(int j = 0; j < N; j++) {
            if((t & (1 << j)) && !A[p][j]) {
                ok = false;
                break;
            }
        }

        if(ok) {
            teams[i] ^= 1 << p;
            res += dfs(N, T, A, p + 1, teams);
            teams[i] ^= 1 << p;
        }
    }
    
    if(sz < T) {
        teams.push_back(1 << p);
        res += dfs(N, T, A, p + 1, teams);
        teams.pop_back();
    }

    return res;
}

void run_case() {
    int N, T, M;
    std::cin >> N >> T >> M;

    std::vector<std::vector<int>> A(N, std::vector<int>(N, 1));
    for(int i = 0; i < M; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        A[U][V] = 0;
        A[V][U] = 0;
    }

    std::vector<int> teams;
    std::cout << dfs(N, T, A, 0, teams) << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
