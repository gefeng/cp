#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector> 
#include <ranges>
#include <map>
#include <set>

bool dfs(int K, std::set<std::string>& seen, std::string& now) {
    if(now.size() == K) {
        if(seen.find(now) == seen.end()) {
            return true;
        }
        return false;
    }

    for(char c = '0'; c <= '1'; c++) {
        now.push_back(c);
        if(dfs(K, seen, now)) {
            return true;
        }
        now.pop_back();
    }

    return false;
}

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::string S;
    std::cin >> S;

    std::string rs(S);
    for(int i = 0; i < N; i++) {
        rs[i] = char(((rs[i] - '0') ^ 1) + '0');
    }

    int tot = N - K + 1;
    int k = 0;
    int cnt = 1;
    while(cnt <= tot) {
        cnt *= 2;
        k += 1;
    }

    if(K <= k) {
        std::set<std::string> seen;
        for(int i = 0; i <= N - K; i++) {
            seen.insert(rs.substr(i, K));
        }
        std::string now = "";
        if(!dfs(K, seen, now)) {
            std::cout << "NO" << '\n';
        } else {
            std::cout << "YES" << '\n' << now << '\n';
        }
    } else {
        std::set<std::string> seen;
        int one = 0;
        for(int l = 0, r = 0; r < N; r++) {
            one += rs[r] - '0';
            if(r - l + 1 > K - k) {
                one -= rs[l++] - '0';
            }
            if(r - l + 1 == K - k) {
                if(one == 0 && r + k < N) {
                    seen.insert(rs.substr(r + 1, k)); 
                } 
            }
        }
        std::string now = "";
        if(!dfs(k, seen, now)) {
            std::cout << "NO" << '\n';
        } else {
            std::cout << "YES" << '\n' << std::string(K - k, '0') + now << '\n';
        }
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
