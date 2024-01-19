#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

constexpr int MAX = 18;

void run_case() {
    int N;
    std::cin >> N;
    
    std::set<int64_t> s;
    std::vector<int64_t> rep;
    
    int64_t cur = 1;
    for(int i = 0; i < MAX; i++) {
        rep.push_back(cur);
        cur = cur * 10 + 1;
    }

    for(int64_t x : rep) {
        for(int64_t y : rep) {
            for(int64_t z : rep) {
                s.insert(x + y + z);
            }
        }
    }

    int cnt = 1;
    for(int64_t x : s) {
        if(cnt == N) {
            std::cout << x << '\n';
            return;
        } 
        cnt += 1;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
