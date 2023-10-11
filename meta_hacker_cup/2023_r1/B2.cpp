#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

void dfs(std::vector<int>& div, int sum, int prod, std::vector<int>& cand, std::vector<int>& ans) {
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
}

void run_case(int T) {
    int P;
    std::cin >> P;

    std::vector<int> div;
    for(int i = 1; i * i <= P; i++) {
        if(P % i == 0) {
            if(i <= 41 && i != 1) {
                div.push_back(i);
            }
            if(P / i != i && P / i <= 41 && P / i != 1) {
                div.push_back(P / i);
            }
        }
    }

    std::sort(div.begin(), div.end());
    
    std::vector<int> cand;
    std::vector<int> ans;
    dfs(div, 41, P, cand, ans);

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
    int T;
    std::cin >> T;
    for(int t = 1; t <= T; t++) {
        run_case(t);
    }
}
