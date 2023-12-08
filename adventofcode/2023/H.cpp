#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>

constexpr int MAX = (int)1e6;

std::string T;
std::map<std::string, std::pair<std::string, std::string>> G;

int64_t gcd(int64_t a, int64_t b) {
    if(a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

int64_t lcm(int64_t a, int64_t b) {
    return a * b / gcd(a, b);
}

void run_case1() {
    int ans = 0;
    int n = T.size();
    std::string cur = "AAA";
    std::string t = "ZZZ";

    int i = 0;
    while(cur != t) {
        if(T[i] == 'L') {
            cur = G[cur].first;
        } else {
            cur = G[cur].second;
        }
        i = (i + 1) % n;
        ans += 1;
    }

    std::cout << ans << '\n';
}

void run_case2() {
    int64_t ans = 0;
    int n = T.size();
    std::vector<std::string> st;
    
    for(auto [s, _] : G) {
        if(s.back() == 'A') {
            st.push_back(s);
        }
    }

    int size = st.size();
    std::vector<std::vector<int>> res(size);
    std::vector<int64_t> cycle;

    for(int j = 0; j < size; j++) {
        int i = 0;
        int cnt = 0;
        std::queue<std::string> q;
        q.push(st[j]);

        while(cnt < MAX) {
            std::string cur = q.front();
            q.pop();
            
            if(cur.back() == 'Z') {
                res[j].push_back(cnt);
            }

            if(T[i] == 'L') {
                std::string nxt = G[cur].first;
                q.push(nxt);
            } else {
                std::string nxt = G[cur].second;
                q.push(nxt);
            }

            i = (i + 1) % n;
            cnt += 1;
        }

        cycle.push_back(res[j][1] - res[j][0]); 
    }

    ans = cycle[0];
    for(int i = 1; i < size; i++) {
        ans = lcm(ans, cycle[i]); 
    } 

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::getline(std::cin, T);

    std::string S;
    std::getline(std::cin, S);

    while(std::getline(std::cin, S)) {
        std::string cur = S.substr(0, 3);
        std::string nxt_l = S.substr(7, 3);
        std::string nxt_r = S.substr(12, 3);
        G[cur] = {nxt_l, nxt_r};
    }

    //run_case1();
    run_case2();
}
