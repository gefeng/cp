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
    
    for(char c = 'a'; c <= 'z'; c++) {
        bool ok = false;
        for(int i = 0; i < N; i++) {
            if(S[i] == c) {
                ok = true;
            }        
        }
        if(!ok) {
            std::cout << c << '\n';
            return;
        }
    }

    for(char a = 'a'; a <= 'z'; a++) {
        for(char b = 'a'; b <= 'z'; b++) {
            std::string s = "";
            s.push_back(a);
            s.push_back(b);
            if(S.find(s) == std::string::npos) {
                std::cout << s << '\n';
                return;
            }
        }
    }

    for(char a = 'a'; a <= 'z'; a++) {
        for(char b = 'a'; b <= 'z'; b++) {
            for(char c = 'a'; c <= 'z'; c++) {
                std::string s = "";
                s.push_back(a);
                s.push_back(b);
                s.push_back(c);
                if(S.find(s) == std::string::npos) {
                    std::cout << s << '\n';
                    return;
                }
            }
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
