#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::map<int, int> m;
    for(int x : A) {
        m[x] += 1;
    }

    std::vector<int> ans;
    while(!m.empty()) {
        std::vector<int> take;
        
        int mex = 0;
        for(auto [k, v] : m) {
            if(k != mex) {
                break;
            } 

            take.push_back(k);
            mex += 1;
        }

        if(take.empty()) {
            int x = m.begin()->first;
            ans.push_back(0); 

            if(--m[x] == 0) {
                m.erase(x);
            }
        } else {
            ans.push_back(mex);
            for(int x : take) {
                if(--m[x] == 0) {
                    m.erase(x);
                }
            }
        }
    }

    int sz = ans.size();
    std::cout << sz << '\n';
    for(int i = 0; i < sz; i++) {
        std::cout << ans[i] << " \n"[i == sz - 1];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
