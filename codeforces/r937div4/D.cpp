#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

constexpr int MAX = (int)1e5;

std::vector<int> a;

void run_case() {
    int N;
    std::cin >> N;

    std::cout << (a[N] ? "Yes" : "No") << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    auto is_binary = [](int x) {
        while(x) {
            if(x % 10 > 1) {
                return false;
            }
            x /= 10;
        }
        return true;
    };
    
    std::queue<int> q;
    std::vector<int> base;
    for(int i = 1; i <= MAX; i++) {
        if(is_binary(i)) {
            q.push(i);
            base.push_back(i);
        }
    }

    a.resize(MAX + 1, 0);
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        
        a[cur] = 1;
        
        for(int x : base) {
            int64_t nxt = (int64_t)cur * x;
            if(nxt <= MAX && !a[nxt]) {
                a[nxt] = 1;
                q.push(nxt);
            }
        } 
    }

    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
