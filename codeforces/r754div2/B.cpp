#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
void run_case() {
    int N;
    std::cin >> N;

    std::string S;
    std::cin >> S;
    
    std::string s(S);
    std::sort(s.begin(), s.end());

    std::vector<std::vector<int>> ans;
    std::vector<int> a;
    for(int i = 0; i < N; i++) {
        if(S[i] != s[i]) {
            a.push_back(i); 
        }   
    }
    if(!a.empty()) {
        ans.push_back(a);
    }

    int k = ans.size();
    std::cout << k << '\n';
    for(int i = 0; i < k; i++) {
        int m = ans[i].size();
        std::cout << m << ' ';
        for(int j = 0; j < m; j++) {
            std::cout << ans[i][j] + 1 << " \n"[j == m - 1];
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
