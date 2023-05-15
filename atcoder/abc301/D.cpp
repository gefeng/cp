#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using LL = long long;

LL dfs(LL N, std::string& S, int p, LL cur) {
    int sz = S.size();
    if(p == sz) {
        return cur;
    }

    char c = S[p];
    if(c == '?') {
        if((cur | (1LL << (sz - 1 - p))) <= N) {
            LL x = cur | (1LL << (sz - 1 - p));

            for(int i = p + 1; i < sz; i++) {
                if(S[i] == '1') {
                    x |= 1LL << (sz - 1 - i);
                }
            }

            if(x <= N) {
                return dfs(N, S, p + 1, cur | (1LL << (sz - 1 - p))); 
            } else {
                return dfs(N, S, p + 1, cur);
            }
        } else {
            return dfs(N, S, p + 1, cur);
        }
    } else if(c == '1') {
        if((cur | (1LL << (sz - 1 - p))) <= N) {
            return dfs(N, S, p + 1, cur | (1LL << (sz - 1 - p))); 
        } 
        return -1LL;
    } else {
        return dfs(N, S, p + 1, cur);
    }
}

void run_case() {
    std::string S;
    std::cin >> S;

    LL N;
    std::cin >> N;

    LL res = dfs(N, S, 0, 0LL);
    
    std::cout << res << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
