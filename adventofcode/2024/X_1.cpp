#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

inline bool is_letter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

std::string next_word(std::string& s, int& p) {
    int n = s.size();
    while(p < n && !is_letter(s[p])) {
        p += 1;
    }
    
    std::string res = "";
    while(p < n && is_letter(s[p])) {
        res.push_back(s[p++]);
    }
    return res;
}

void run_case() {
    bool reading_gate = false;

    std::map<std::string, int> m;
    std::vector<std::vector<std::string>> A;
 
    for(std::string S; std::getline(std::cin, S); ) {
        if(S.empty()) {
            reading_gate = true;
            continue;
        }

        if(reading_gate) {
            int p = 0;
            std::vector<std::string> a;
            while(true) {
                std::string s = next_word(S, p);
                if(s.empty()) {
                    break;
                }
                a.push_back(s);
            }
            A.push_back(a);
        } else {
            int p = 0;
            std::string s = next_word(S, p);
            int val = S.back() - '0';
            m[s] = val;
        }
    }

    while(true) {
        bool end = true;
        for(auto& a : A) {
            std::string v_1 = a[0];
            std::string v_2 = a[2];
            std::string v_3 = a[3];
            std::string op = a[1];
          
            if(m.find(v_1) != m.end() && m.find(v_2) != m.end() && m.find(v_3) == m.end()) {
                int x = m[v_1];
                int y = m[v_2];
                if(op == "AND") {
                    m[v_3] = x & y;
                } else if(op == "OR") {
                    m[v_3] = x | y;
                } else if(op == "XOR") {
                    m[v_3] = x ^ y;
                }
                end = false;
            }
        } 

        if(end) {
            break;
        }
    }

    int64_t res = 0;
    for(auto [s, v] : m) {
        if(s[0] == 'z') {
            if(v == 1) {
                res |= int64_t(1) << stoi(s.substr(1, 2));
            }
        }
    }
    std::cout << res << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
