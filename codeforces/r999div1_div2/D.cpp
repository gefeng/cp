#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

bool dfs(std::multiset<int>& ms, int x) {
    if(x == 0) {
        return false;
    }
    auto it = ms.find(x);
    if(it != ms.end()) {
        ms.erase(it);
        return true;
    }

    return dfs(ms, x / 2) && dfs(ms, x / 2 + (x % 2 == 0 ? 0 : 1));
}

void run_case() {
    int N, M;
    std::cin >> N >> M;
    
    std::vector<int> A(N);
    std::vector<int> B(M);
    
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < M; i++) {
        std::cin >> B[i];
    }

    std::multiset<int> ms;
    for(int x : A) {
        ms.insert(x);
    }

    std::sort(B.begin(), B.end());

    for(int i = M - 1; i >= 0; i--) {
        int x = B[i];
        if(!dfs(ms, x)) {
            std::cout << "No" << '\n';
            return;
        }
    }

    std::cout << (ms.empty() ? "Yes" : "No") << '\n';
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
