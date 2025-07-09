#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>

void dfs(std::vector<int>& A, int l, int r) {
    if(l == r) {
        return;
    }

    int mid = (r + l) >> 1;
    dfs(A, l, mid);
    dfs(A, mid + 1, r);

    if(A[l] > A[mid + 1]) {
        for(int i = l, j = mid + 1; i <= mid; i++, j++) {
            std::swap(A[i], A[j]);
        }
    }
}

void run_case() {
    int N;
    std::cin >> N;

    int n = 1 << N;
    std::vector<int> A(n);
    for(int i = 0; i < n; i++) {
        std::cin >> A[i];
    }

    dfs(A, 0, n - 1);

    for(int i = 0; i < n; i++) {
        std::cout << A[i] << " \n"[i == n - 1];
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
