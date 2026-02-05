#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

int dfs(std::vector<int>& A, int l, int r) {
    if(l == r) {
        return 0;
    }

    int m = (l + r) / 2;
    // [l, m]   [m + 1, r]
    int cnt = 0;
    for(int i = l - 1; i < m; i++) {
        if(A[i] >= l && A[i] <= m) {
            cnt += 1;
        }
    }
    if(cnt == (r - l + 1) / 2) {
        int x = dfs(A, l, m);
        int y = dfs(A, m + 1, r);
        if(x == -1 || y == -1) {
            return -1;
        } else {
            return x + y;
        }
    } else if(cnt == 0) {
        for(int i = l - 1; i < m; i++) {
            std::swap(A[i], A[i + (r - l + 1) / 2]);
        }

        int x = dfs(A, l, m);
        int y = dfs(A, m + 1, r);
        if(x == -1 || y == -1) {
            return -1;
        } else {
            return x + y + 1;
        }
    } else {
        return -1;
    }
}

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::cout << dfs(A, 1, N) << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
