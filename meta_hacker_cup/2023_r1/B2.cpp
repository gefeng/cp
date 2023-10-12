#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

/*void dfs(std::vector<int>& div, int sum, int prod, std::vector<int>& cand, std::vector<int>& ans) {
    int n = div.size();
    if(sum == 0 || prod == 1) {
        if(prod == 1 && (ans.empty() || sum + cand.size() < ans.size())) {
            ans = std::vector<int>(cand);
            for(int i = 0; i < sum; i++) {
                ans.push_back(1);
            }
        }
        return;
    }

    for(int i = 0; i < n; i++) {
        int d = div[i];
        if(d > sum) {
            break;
        }
    
        if(prod % d == 0) {
            cand.push_back(d);
            dfs(div, sum - d, prod / d, cand, ans);
            cand.pop_back();
        }
    }
}*/

std::map<int, std::vector<int>> m;

void dfs(int sum, int prod, int last, std::vector<int>& cur) {
    if(sum == 0) {
        if(m.find(prod) == m.end() || m[prod].size() > cur.size()) {
            m[prod] = cur;
        }
        return;
    }

    for(int i = last; i <= sum; i++) {
        cur.push_back(i);
        dfs(sum - i, prod * i, i, cur);
        cur.pop_back();
    }
}

void run_case(int T) {
    int P;
    std::cin >> P;

    std::vector<int> ans;
    if(m.find(P) != m.end()) {
        ans = m[P];
    }

    std::cout << "Case #" << T << ": ";
    if(ans.empty()) {
        std::cout << -1 << '\n';
    } else {
        int sz = ans.size();
        std::cout << sz << ' ';
        for(int i = 0; i < sz; i++) {
            std::cout << ans[i] << " \n"[i == sz - 1];
        }
    }
}

int main() {
    std::vector<int> cur;
    dfs(41, 1, 1, cur);
    
    int T;
    std::cin >> T;
    for(int t = 1; t <= T; t++) {
        run_case(t);
    }
}
