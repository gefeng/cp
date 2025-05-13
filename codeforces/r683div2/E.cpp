#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

int dfs(std::vector<int>& a) {
    if(a.size() < 4) {
        return 0;
    }

    std::vector<int> s_0;
    std::vector<int> s_1;
    
    int hb = 0;
    for(int x : a) {
        for(int i = 30; i >= 0; i--) {
            if(x & (1 << i)) {
                hb = std::max(hb, i);
                break;
            }
        }     
    }

    for(int x : a) {
        if(x & (1 << hb)) {
            s_0.push_back(x);
        } else {
            s_1.push_back(x);
        }
    }

    int n = s_0.size();
    int m = s_1.size();

    for(int& x : s_0) {
        x ^= 1 << hb;
    }

    if(m == 0) {
        return dfs(s_0);
    }
    
    return std::min(dfs(s_0) + m - 1, dfs(s_1) + n - 1);
}

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::cout << dfs(A) << '\n'; 
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
