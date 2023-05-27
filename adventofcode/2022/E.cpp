#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    std::vector<std::string> A = {"FHBVRQDP", "LDZQWV", "HLZQGRPC", "RDHFJVB", "ZWLC", "JRPNTGVM", "JRLVMBS", "DPJ", "DCNWV"};
    
    std::string S;
    while(std::getline(std::cin, S)) {
        std::vector<int> v;
        int n = S.size();
        for(int i = 0; i < S.size(); ) {
            if(S[i] >= '0' && S[i] <= '9') {
                int x = 0;
                while(i < n && S[i] >= '0' && S[i] <= '9') {
                    x = x * 10 + S[i] - '0';
                    i += 1; 
                }

                v.push_back(x);
            } else {
                i += 1;
            } 
        }

        int c = v[0];
        int f = v[1] - 1;
        int t = v[2] - 1;

        for(int i = 0; i < c; i++) {
            A[t].push_back(A[f].back());
            A[f].pop_back();
        }

        std::reverse(A[t].begin() + A[t].size() - c, A[t].end());
    }

    std::string ans = "";
    for(int i = 0; i < A.size(); i++) {
        ans.push_back(A[i].back());
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
