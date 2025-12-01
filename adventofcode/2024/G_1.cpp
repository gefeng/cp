#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

int64_t next_int(std::string& s, int& p) {
    int n = s.size();
    while(p < n && !std::isdigit(s[p])) {
        p += 1; 
    }
    if(p == n) {
        return -1;
    }

    int64_t x = 0;
    while(p < n && std::isdigit(s[p])) {
        x = x * 10 + s[p++] - '0';
    }

    return x;
}

bool dfs(std::vector<int64_t>& a, int i, int64_t x) {
    int n = a.size();
    if(i == n) {
        return a[0] == x; 
    }

    if(x <= a[0] / a[i]) {
        bool mul = dfs(a, i + 1, x * a[i]);
        if(mul) {
            return true;
        }
    }
    if(x + a[i] <= a[0]) {
        bool add = dfs(a, i + 1, x + a[i]);
        if(add) {
            return true;
        }
    }

    return false;
}

void run_case() {
    int64_t ans = 0;
    for(std::string S; std::getline(std::cin, S); ) {
        int p = 0;
        std::vector<int64_t> a;
        while(true) {
            int64_t x = next_int(S, p);
            if(x == -1) {
                break;
            }
            a.push_back(x);
        }

        if(dfs(a, 2, a[1])) {
            ans += a[0];
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
