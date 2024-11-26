#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

int gcd(int a, int b) {
    if(a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    auto is_bad = [&](int i, int j) {
        return gcd(A[i], A[j]) == 1;
    };

    std::vector<int> ans;
    std::set<std::pair<int, int>> s;
    std::set<int> waiting;
    for(int i = 0; i < N; i++) {
        waiting.insert(i);
    }

    for(int i = 0; i < N; i++) {
        int j = (i + 1) % N;
        if(is_bad(i, j)) {
            s.emplace(i, j);
        }
    }
    
    if(s.empty()) {
        std::cout << 0 << '\n';
        return;
    }

    std::pair<int, int> now = {-1, -1};
    while(!s.empty()) {
        auto it = s.lower_bound(now);
        if(it == s.end()) {
            it = s.begin();
        }
        auto [x, y] = *it;

        auto it_1 = waiting.lower_bound(y); 
        int nxt = std::next(it_1) == waiting.end() ? *waiting.begin() : *std::next(it_1);
        int pre = it_1 == waiting.begin() ? *waiting.rbegin() : *std::prev(it_1);

        s.erase({x, y});
        waiting.erase(y);
        ans.push_back(y);

        if(x == y) {
            break;
        }
        
        if(!s.empty() && s.find({y, nxt}) != s.end()) {
            s.erase({y, nxt});
        }

        if((s.empty() || s.find({pre, nxt}) == s.end()) && is_bad(pre, nxt)) {
            s.emplace(pre, nxt);
        }

        now = {y + 1, -1};
    }

    int n = ans.size();
    std::cout << n << " \n"[n == 0];
    for(int i = 0; i < n; i++) {
        std::cout << ans[i] + 1 << " \n"[i == n - 1];
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
