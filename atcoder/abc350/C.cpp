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
    std::vector<int> pos(N, 0);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        A[i] -= 1;
        pos[A[i]] = i;
    }

    std::vector<std::pair<int, int>> ans;
    for(int i = 0; i < N; i++) {
        if(A[i] == i) {
            continue;
        }

        int p = pos[i];
        ans.emplace_back(i, p);
        
        std::swap(A[i], A[p]);
        pos[i] = i;
        pos[A[p]] = p;
    }

    int size = ans.size();
    std::cout << size << '\n';
    for(int i = 0; i < size; i++) {
        std::cout << ans[i].first + 1 << ' ' << ans[i].second + 1 << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
