#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

const int INF = 1e9;

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N * 3);
    for(int i = 0; i < N * 3; i++) {
        std::cin >> A[i];
    }

    std::vector<int> mid(N + 1, INF); 
    for(int i = 0; i < N * 3; i++) {
        if(mid[A[i]] == INF) {
            mid[A[i]] = -i - 1;
        } else if(mid[A[i]] < 0) {
            mid[A[i]] = i + 1;
        }
    }

    std::vector<std::pair<int, int>> v;
    for(int i = 1; i <= N; i++) {
        v.emplace_back(mid[i], i);
    }

    std::sort(v.begin(), v.end());
    
    for(int i = 0; i < N; i++) {
        std::cout << v[i].second << " \n"[i == N - 1];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
