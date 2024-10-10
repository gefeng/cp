#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

constexpr int MAX = int(1e5);

std::vector<int> dp(MAX + 1, -1);
std::vector<std::vector<int>> divisors(MAX + 1);

int dfs(int x) {
    if(divisors[x].empty()) {
        return 0; 
    }

    if(dp[x] != -1) {
        return dp[x];
    }

    std::set<int> s;
    for(int d : divisors[x]) {
        s.insert(dfs(d));
    }

    int mex = 0;
    while(s.find(mex) != s.end()) {
        mex += 1;
    }
    
    return dp[x] = mex;
}

void run_case() {
    int N;
    std::cin >> N;

    for(int i = 1; i <= MAX; i++) {
        for(int f = 1; f * f <= i; f++) {
            if(i % f == 0) {
                if(f != i) {
                    divisors[i].push_back(f);
                } 
                if(i / f != f && i / f != i) {
                    divisors[i].push_back(i / f);
                }
            }
        }
    }

    for(int i = 1; i <= MAX; i++) {
        dfs(i);
    }

    int sum = 0;
    for(int i = 0; i < N; i++) {
        int X;
        std::cin >> X;
        sum ^= dp[X];
    }

    std::cout << (sum == 0 ? "Bruno" : "Anna") << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
