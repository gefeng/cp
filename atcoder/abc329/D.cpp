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
    int N, M;
    std::cin >> N >> M;

    std::vector<int> votes(N + 1, 0);
    std::map<int, std::set<int>> m;
    for(int i = 0; i < M; i++) {
        int X;
        std::cin >> X;

        int pre = votes[X];
        votes[X] += 1;
        int cur = votes[X];

        if(pre != 0) {
            m[pre].erase(X);
            if(m[pre].empty()) {
                m.erase(pre);
            }
        }

        m[cur].insert(X);

        std::cout << *m.rbegin()->second.begin() << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
