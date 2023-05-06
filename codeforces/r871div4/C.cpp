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

constexpr int INF = (int)2e9;

void run_case() {
    int N;
    std::cin >> N;

    std::map<std::string, std::set<int>> m;
    for(int i = 0; i < N; i++) {
        int M;
        std::cin >> M;

        std::string S;
        std::cin >> S;

        m[S].insert(M);
    }

    int ans = INF;
    if(m.find("11") != m.end()) {
        ans = std::min(ans, *m["11"].begin());
    }

    int min_1 = INF;
    int min_2 = INF;
    if(m.find("10") != m.end()) {
        min_1 = *m["10"].begin();
    }

    if(m.find("01") != m.end()) {
        min_2 = *m["01"].begin();
    }

    if(min_1 != INF && min_2 != INF) {
        ans = std::min(ans, min_1 + min_2);
    }

    std::cout << (ans == INF ? -1 : ans) << '\n';
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
