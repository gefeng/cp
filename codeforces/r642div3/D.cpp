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
    int N;
    std::cin >> N;
    
    std::vector<int> ans(N, 0);

    std::map<int, std::set<int>> m;
    m[N].insert(0);
    
    for(int i = 1; i <= N; i++) {
        auto& [len, s] = *m.rbegin();
        int l = *s.begin();
        int r = l + len - 1;
    
        ans[(l + r) / 2] = i;

        int x = len % 2 == 0 ? len / 2 - 1 : len / 2;
        int y = len / 2;
        if(x) {
            m[x].insert(l);
        }
        if(y) {
            m[y].insert(l + x + 1);
        }

        s.erase(l);
        if(s.empty()) {
            m.erase(len);
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
