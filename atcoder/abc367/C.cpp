#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void dfs(int N, int K, std::vector<int>& A, std::vector<int>& seq, int i, int sum) {
    if(i == N) {
        if(sum % K == 0) {
            for(int j = 0; j < N; j++) {
                std::cout << seq[j] << " \n"[j == N - 1];
            }
        }
        return;
    }

    for(int x = 1; x <= A[i]; x++) {
        seq.push_back(x);
        dfs(N, K, A, seq, i + 1, sum + x);
        seq.pop_back();
    }
}

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> seq;
    dfs(N, K, A, seq, 0, 0);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
