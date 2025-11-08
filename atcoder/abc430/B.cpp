#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::string> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::set<std::vector<std::string>> s;
    for(int i = 0; i <= N - M; i++) {
        for(int j = 0; j <= N - M; j++) {
            std::vector<std::string> a(M);
            for(int r = 0; r < M; r++) {
                a[r] = A[i + r].substr(j, M);
            }
            s.insert(a);
        }
    }

    std::cout << s.size() << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
