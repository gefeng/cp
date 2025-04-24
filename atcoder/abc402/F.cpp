#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void dfs_1(int N, int M, std::vector<std::vector<int>>& A, std::vector<int64_t>& p_10, int r, int c, int64_t sum, std::vector<std::vector<int64_t>>& m_1) {
    int p = N * 2 - 2 - (r + c);
    sum += p_10[p] * A[r][c] % M;
    sum %= M;

    if(r + c == N - 1) {
        m_1[r - c + N].push_back(sum);
        return;
    }

    if(r + 1 >= 0 && r + 1 < N) {
        dfs_1(N, M, A, p_10, r + 1, c, sum, m_1);
    }

    if(c + 1 >= 0 && c + 1 < N) {
        dfs_1(N, M, A, p_10, r, c + 1, sum, m_1);
    }
}

void dfs_2(int N, int M, std::vector<std::vector<int>>& A, std::vector<int64_t>& p_10, int r, int c, int64_t sum, std::vector<std::vector<int64_t>>& m_2) {
    if(r + c == N - 1) {
        m_2[r - c + N].push_back(sum);
        return;
    }

    int p = N * 2 - 2 - (r + c);
    sum += p_10[p] * A[r][c] % M;
    sum %= M;

    if(r - 1 >= 0 && r - 1 < N) {
        dfs_2(N, M, A, p_10, r - 1, c, sum, m_2);
    }

    if(c - 1 >= 0 && c - 1 < N) {
        dfs_2(N, M, A, p_10, r, c - 1, sum, m_2);
    }
}

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> A(N, std::vector<int>(N, 0));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            std::cin >> A[i][j];
        }
    }

    std::vector<int64_t> p_10(N * 2, 1);
    for(int i = 1; i < N * 2; i++) {
        p_10[i] = p_10[i - 1] * 10 % M;
    }
    
    std::vector<std::vector<int64_t>> m_1(N * 2 + 1);
    std::vector<std::vector<int64_t>> m_2(N * 2 + 1);
    dfs_1(N, M, A, p_10, 0, 0, 0, m_1); 
    dfs_2(N, M, A, p_10, N - 1, N - 1, 0, m_2);

    for(auto& v : m_2) {
        std::sort(v.begin(), v.end());
    }
    
    int64_t ans = 0;
    for(int i = 0; i <= N * 2; i++) {
        for(int x : m_1[i]) {
            auto it = std::lower_bound(m_2[i].begin(), m_2[i].end(), M - x);
            if(it != m_2[i].begin()) {
                ans = std::max(ans, *std::prev(it) + x);
            }
            if(!m_2[i].empty()) {
                ans = std::max(ans, (x + m_2[i].back()) % M);
            }
        }
    }
    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
