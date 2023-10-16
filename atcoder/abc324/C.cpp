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
    
    std::string T;
    std::cin >> T;

    int n = T.size();

    std::vector<int> ans;
    for(int i = 0; i < N; i++) {
        std::string S;
        std::cin >> S;

        int m = S.size();

        if(S == T) {
            ans.push_back(i);
            continue;
        }

        if(n == m) {
            int cnt = 0;
            for(int j = 0; j < n; j++) {
                if(S[j] != T[j]) {
                    cnt += 1;
                }
            }

            if(cnt == 1) {
                ans.push_back(i);
            }
            continue;
        }

        if(n == m + 1) {
            int skip = 1;
            bool ok = true;
            for(int k = 0, j = 0; k < m && j < n; j++) {
                if(S[k] != T[j]) {
                    if(skip == 0) {
                        ok = false; 
                        break;
                    }
                    skip -= 1;
                } else {
                    k += 1;
                } 
            }

            if(ok) {
                ans.push_back(i);
            }
            continue;
        }

        if(n + 1 == m) {
            int skip = 1;
            bool ok = true;
            for(int k = 0, j = 0; k < m && j < n; k++) {
                if(S[k] != T[j]) {
                    if(skip == 0) {
                        ok = false; 
                        break;
                    }
                    skip -= 1;
                } else {
                    j += 1;
                } 
            }

            if(ok) {
                ans.push_back(i);
            }
        }
    }

    int size = ans.size();
    std::cout << size << '\n';
    for(int i = 0; i < size; i++) {
        std::cout << ans[i] + 1 << " \n"[i == size - 1];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
