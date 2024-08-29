#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>
#include <map>

bool dfs(int64_t x, std::map<int64_t, int>& m) {
    if(m.find(x) != m.end()) {
        if(--m[x] == 0) {
            m.erase(x);
        }
        return true;
    }
    
    if(x == 1) {
        return false;
    }

    int64_t a = x / 2;
    int64_t b = (x + 1) / 2;
    
    if(!dfs(a, m)) {
        return false;
    }

    if(!dfs(b, m)) {
        return false;
    }

    return true;
}

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    if(N == 1) {
        std::cout << "YES" << '\n';
        return;
    }

    int64_t sum = 0;
    std::map<int64_t, int> m;
    for(int x : A) {
        sum += x;
        m[x] += 1;
    }
    

    std::cout << (dfs(sum, m) ? "YES" : "NO") << '\n';
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
