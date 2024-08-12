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
    
    std::vector<std::string> A(N);
    int m = 0;
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        m = std::max(m, int(A[i].size()));
    }

    std::vector<std::string> ans;
    for(int c = 0; c < m; c++) {
        std::string s = "";
        for(int r = N - 1; r >= 0; r--) {
            if(c >= A[r].size()) {
                s.push_back('*'); 
            } else {
                s.push_back(A[r][c]);
            }
        }

        while(!s.empty() && s.back() == '*') {
            s.pop_back();
        }
    
        ans.push_back(s);
    } 

    for(int i = 0; i < m; i++) {
        std::cout << ans[i] << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
