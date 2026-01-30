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

    std::string t = "abacaba";

    int cnt = 0;
    for(int i = 0; i <= N - 7; i++) {
        std::string s = S.substr(i, 7);
        if(s == t) {
            cnt += 1;
        }
    }

    if(cnt > 1) {
        std::cout << "No" << '\n';
        return;
    }

    if(cnt == 1) {
        for(int i = 0; i < N; i++) {
            if(S[i] == '?') {
                S[i] = 'd';
            }
        }
        std::cout << "Yes" << '\n';
        std::cout << S << '\n';
        return;
    }

    for(int i = 0; i <= N - 7; i++) {
        bool good = true;
        for(int j = 0; j < 7; j++) {
            if(S[i + j] != t[j] && S[i + j] != '?') {
                good = false; 
                break;
            }
        }

        if(!good) {
            continue;
        }

        if(i + 10 < N) {
            std::string s = S.substr(i + 7, 4); 
            if(s == "caba") {
                good = false;
            }
        }

        if(i - 4 >= 0) {
            std::string s = S.substr(i - 4, 4);
            if(s == "abac") {
                good = false;
            }
        }

        if(i + 12 < N) {
            std::string s = S.substr(i + 7, 6);
            if(s == "bacaba") {
                good = false;
            }
        }
        
        if(i - 6 >= 0) {
            std::string s = S.substr(i - 6, 6);
            if(s == "abacab") {
                good = false;
            }
        }

        if(!good) {
            continue;
        }

        for(int j = 0; j < 7; j++) {
            if(S[i + j] == '?') {
                S[i + j] = t[j];
            }
        }

        for(int j = 0; j < N; j++) {
            if(S[j] == '?') {
                S[j] = 'd';
            }
        }

        std::cout << "Yes" << '\n';
        std::cout << S << '\n';
        return;
    }

    std::cout << "No" << '\n';
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
