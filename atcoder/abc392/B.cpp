#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::set<int> s;
    for(int i = 0; i < M; i++) {
        int X;
        std::cin >> X;
        s.insert(X);
    }
    
    std::vector<int> ans;
    for(int i = 1; i <= N; i++) {
        if(s.find(i) == s.end()) {
            ans.push_back(i);
        }
    }

    int size = ans.size();
    std::cout << size << '\n';
    for(int i = 0; i < size; i++) {
        std::cout << ans[i] << " \n"[i == size - 1];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
