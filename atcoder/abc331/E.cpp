#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>
#include <set>

void run_case() {
    int N, M, L;
    std::cin >> N >> M >> L;

    std::vector<int> A(N);
    std::vector<int> B(M);
    std::map<std::pair<int, int>, std::set<int>> m;
    
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < M; i++) {
        std::cin >> B[i];
    }

    if(L == 0) {
        std::sort(A.begin(), A.end());
        std::sort(B.begin(), B.end());
        std::cout << A.back() + B.back() << '\n';
        return;
    }

    for(int i = 0; i < L; i++) {
        int X, Y;
        std::cin >> X >> Y;
        X -= 1;
        Y -= 1;
        m[{A[X], X}].insert(Y);
    }

    std::vector<std::pair<int, int>> a(N);
    for(int i = 0; i < N; i++) {
        a[i] = {A[i], i};
    }
    std::sort(a.begin(), a.end(), std::greater<std::pair<int, int>>());

    std::vector<int> ans(M, a[0].second);
    for(int i = 0; i < N; i++) {
        int v = a[i].first;
        int p = a[i].second;
        if(m.find({v, p}) != m.end()) {
            for(int j : m[{v, p}]) {
                if(ans[j] == p) {
                    ans[j] = i == N - 1 ? -1 : a[i + 1].second;
                }
            }
        }
    }

    int max_v = 0;
    for(int i = 0; i < M; i++) {
        if(ans[i] != -1) {
            max_v = std::max(max_v, B[i] + A[ans[i]]);
        }
    }

    std::cout << max_v << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
