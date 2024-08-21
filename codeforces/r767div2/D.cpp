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

    std::vector<std::string> A(N);
    std::map<std::string, int> m;
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        m[A[i]] += 1;
    }

    auto is_pal = [](std::string& s) {
        for(int l = 0, r = s.size() - 1; l < r; l += 1, r -= 1) {
            if(s[l] != s[r]) {
                return false;
            }
        }
        return true;
    };

    for(int i = 0; i < N; i++) {
        if(is_pal(A[i])) {
            std::cout << "YES" << '\n';
            return;
        }
    }

    for(int i = 0; i < N; i++) {
        if(--m[A[i]] == 0) {
            m.erase(A[i]);
        }
        
        std::string s = A[i];
        std::reverse(s.begin(), s.end());
        
        if(m.find(s) != m.end()) {
            std::cout << "YES" << '\n';
            return;
        }

        if(A[i].size() == 2) { 
            for(char c = 'a'; c <= 'z'; c++) {
                std::string t(1, c);
                t.append(s);
                if(m.find(t) != m.end()) {
                    std::cout << "YES" << '\n';
                    return;
                }
            }
        } else {
            s = s.substr(1, 2);
            if(m.find(s) != m.end()) {
                std::cout << "YES" << '\n';
                return;
            }
        }
    }

    std::cout << "NO" << '\n';
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
