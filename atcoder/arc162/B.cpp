#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        A[i] -= 1;
    }

    auto ok = [](const std::vector<int>& A) {
        int n = A.size();
        for(int i = 0; i < n; i++) {
            if(A[i] != i) {
                return false;
            }
        }
        return true;
    };

    std::vector<std::pair<int, int>> ans;
    int p = 0;
    int v = 0;
    while(true) {
        if(ok(A)) {
            break;
        }

        int i = p;
        std::vector<int> nxt;
        while(i < N && A[i] != v) {
            i += 1;
        }

        if(i == p) {
            p += 1;
            v += 1;
            continue;
        }

        if(i == N - 1) {
            if(i == p + 1) {
                std::cout << "No" << '\n';
                return;
            }
    
            ans.emplace_back(i, N - 3);

            for(int j = 0; j < N - 3; j++) {
                nxt.emplace_back(A[j]);
            }

            nxt.emplace_back(A[i - 1]);
            nxt.emplace_back(A[i]);
            nxt.emplace_back(A[i - 2]);

            std::swap(nxt, A);
            nxt = std::vector<int>();

            i = N - 2;
        }

        ans.emplace_back(i + 1, p);

        for(int j = 0; j < p; j++) {
            nxt.push_back(A[j]);
        }

        nxt.push_back(A[i]);
        nxt.push_back(A[i + 1]);

        for(int j = p; j < N; j++) {
            if(j != i && j != i + 1) {
                nxt.push_back(A[j]);
            }
        }
        
        p += 1;
        v += 1;
        std::swap(nxt, A);
    }

    int sz = ans.size();
    std::cout << "Yes" << '\n' << sz << '\n';;
    
    for(int i = 0; i < sz; i++) {
        std::cout << ans[i].first << ' ' << ans[i].second << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
