#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>
#include <deque>

void run_case() {
    int N, M;
    std::cin >> N >> M;

    int n = N * M;

    std::vector<int> A(N);
    std::vector<int> B(M);
    std::vector<int> in_a(n + 1, 0);    
    std::vector<int> in_b(n + 1, 0);
    bool ok = true;
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        if(in_a[A[i]]) {
            ok = false;
        }
        in_a[A[i]] = i + 1;
    }

    for(int i = 0; i < M; i++) {
        std::cin >> B[i];
        if(in_b[B[i]]) {
            ok = false;
        }
        in_b[B[i]] = i + 1;
    }

    if(!ok) {
        std::cout << "No" << '\n';
        return;
    }

    std::vector<std::vector<int>> ans(N, std::vector<int>(M, -1));
    
    std::vector<std::vector<std::pair<int, int>>> a(n + 1);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            a[std::min(A[i], B[j])].emplace_back(i + 1, j + 1);
        }
    }
    
    std::deque<std::pair<int, int>> cand;
    for(int v = n; v > 0; v--) {
        if(in_a[v] && in_b[v]) {
            if(ans[in_a[v] - 1][in_b[v] - 1] != -1) {
                std::cout << "No" << '\n';
                return;
            }
            ans[in_a[v] - 1][in_b[v] - 1] = v;
            for(auto [i, j] : a[v]) {
                if(ans[i - 1][j - 1] == -1) {
                    cand.emplace_back(i, j);
                }
            }
        } else if(in_a[v]) {
            bool found = false;
            for(auto [i, j] : a[v]) {
                if(!found && A[i - 1] == v && i == in_a[v] && ans[i - 1][j - 1] == -1) {
                    ans[i - 1][j - 1] = v;
                    found = true;
                } else {
                    if(ans[i - 1][j - 1] == -1) {
                        cand.emplace_back(i, j);
                    }
                }
            }
            if(!found) {
                std::cout << "No" << '\n';
                return;
            }
        } else if(in_b[v]) {
            bool found = false;
            for(auto [i, j] : a[v]) {
                if(!found && B[j - 1] == v && j == in_b[v] && ans[i - 1][j - 1] == -1) {
                    ans[i - 1][j - 1] = v;
                    found = true;
                } else {
                    if(ans[i - 1][j - 1] == -1) {
                        cand.emplace_back(i, j);
                    }
                }
            }
            if(!found) {
                std::cout << "No" << '\n';
                return;
            }
        } else {
            bool found = false;
            while(!cand.empty()) {
                auto [i, j] = cand.front();
                if(ans[i - 1][j - 1] != -1) {
                    cand.pop_front();
                } else {
                    ans[i - 1][j - 1] = v;
                    found = true;
                    cand.pop_front();
                    break;
                }
            }
            if(!found) {
                std::cout << "No" << '\n';
                return;
            }
            for(auto [i, j] : a[v]) {
                if(ans[i - 1][j - 1] == -1) {
                    cand.emplace_back(i, j);
                }
            }
        }
    }

    std::cout << "Yes" << '\n';
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            assert(ans[i][j] != -1);
            std::cout << ans[i][j] << " \n"[j == M - 1];
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
