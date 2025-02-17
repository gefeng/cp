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

    std::set<std::pair<int, int>> s;
    int ans = 0;
    for(int i = 0; i < M; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        if(U > V) {
            std::swap(U, V);
        }
        
        if(s.find({U, V}) != s.end() || U == V) {
            ans += 1;
        }
        s.emplace(U, V);
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
