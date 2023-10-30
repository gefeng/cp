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

    if(N % 2 == 1) {
        std::cout << -1 << '\n';
        return;
    }

    int l = 0;
    int r = N - 1;
    int cnt = 0;
    std::vector<int> ans;
   
    std::string s = S;
    while(l < r) {
        if(s[l] != s[r]) {
            l += 1;
            r -= 1;
            continue;
        }

        if(cnt == 300) {
            std::cout << -1 << '\n';
            return;
        } 

        if(s[l] == '0') {
            std::string ns = s.substr(0, r + 1);
            ns.append("01");
            ns.append(s.substr(r + 1, s.size() - r - 1)); 

            ans.push_back(r);
            cnt += 1;
            
            r += 1;
            l += 1;
            std::swap(s, ns);
        } else {
            std::string ns = s.substr(0, l);
            ns.append("01");
            ns.append(s.substr(l, s.size() - l));

            ans.push_back(l - 1);
            cnt += 1;
            
            l += 1;
            r += 1;
            std::swap(s, ns);
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
    std::cin.tie(0);
    
    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
