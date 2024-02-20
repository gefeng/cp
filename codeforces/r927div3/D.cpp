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

    std::string T;
    std::cin >> T;

    std::vector<std::string> A(N * 2);
    for(int i = 0; i < N * 2; i++) {
        std::cin >> A[i];
    }

    std::map<char, std::vector<char>> m;
    for(int i = 0; i < N * 2; i++) {
        m[A[i][1]].push_back(A[i][0]);
    }

    for(auto& [_, v] : m) {
        std::sort(v.begin(), v.end());
    }

    std::vector<std::string> ans;
    for(auto& [c, v] : m) {
        if(c != T[0]) {
            while(v.size() > 1) {
                std::string s = "";
                std::string t = "";
                t.push_back(v.back());
                t.push_back(c);
                v.pop_back(); 
                s.push_back(v.back());
                s.push_back(c);
                v.pop_back();
                ans.push_back(s + " " + t);
            } 
        }
    }

    std::vector<char>& trump = m[T[0]];

    for(auto& [c, v] : m) {
        if(c != T[0]) {
            while(!v.empty()) {
                if(trump.empty()) {
                    std::cout << "IMPOSSIBLE" << '\n';
                    return;
                }

                std::string s = "";
                std::string t = "";
                s.push_back(v.back());
                s.push_back(c);
                v.pop_back();

                t.push_back(trump.back());
                t.push_back(T[0]);
                trump.pop_back();
                ans.push_back(s + " " + t);
            }
        }
    }

    while(trump.size() > 1) {
        std::string s = "";
        std::string t = "";
        t.push_back(trump.back());
        t.push_back(T[0]);
        trump.pop_back(); 
        s.push_back(trump.back());
        s.push_back(T[0]);
        trump.pop_back();
        ans.push_back(s + " " + t);
    }

    if(ans.size() != N) {
        std::cout << "IMPOSSIBLE" << '\n';
        return;
    }

    for(int i = 0; i < N; i++) {
        std::cout << ans[i] << '\n'; 
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
