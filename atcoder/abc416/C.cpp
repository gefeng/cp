#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>

void dfs(int N, int K, std::vector<std::string>& A, int i, std::vector<int>& now, std::vector<std::string>& all) {
    if(now.size() == K) {
        std::vector<int> a(now);
        do {
            std::string s = "";
            for(int i : a) {
                s.append(A[i]);
            }
            all.push_back(s);
        } while(std::next_permutation(a.begin(), a.end()));
        return;
    }

    if(i == N) {
        return;
    }

    for(int c = 0; c + now.size() <= K; c++) {
        for(int j = 0; j < c; j++) {
            now.push_back(i);
        }
        dfs(N, K, A, i + 1, now, all);
        for(int j = 0; j < c; j++) {
            now.pop_back();
        }
    }
}

void run_case() {
    int N, K, X;
    std::cin >> N >> K >> X;

    std::vector<std::string> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<std::string> all;
    std::vector<int> now;
    dfs(N, K, A, 0, now, all);

    std::ranges::sort(all);
    std::cout << all[X - 1] << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
