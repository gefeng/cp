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

    std::vector<int> ans;
    ans.push_back(1);
    
    std::vector<int> seen(N * 2 + 1, 0);
    seen[1] = 1;
    for(int i = 1, now = 2; i < N; i++) {
        while(seen[now]) {
            now++;
        }
        ans.push_back(now);
        seen[now] = 1;
        if(ans[i - 1] + now <= N * 2) {
            seen[ans[i - 1] + now] = 1;
        }
    }

    for(int i = 0; i < N; i++) {
        std::cout << ans[i] << " \n"[i == N - 1];
    }
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
