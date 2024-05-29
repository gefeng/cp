#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::map<int, int> m;
    for(int i = 0; i < M; i++) {
        m[i ^ (M - i - 1)] += 1;
    }

    int64_t ans = 0;
    for(int i = 0; i < N; i++) {
        int x = i ^ (N - i - 1); 
        ans += m[x];
    }

    ans = (int64_t)N * M - ans;

    std::cout << ans << '\n';
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
