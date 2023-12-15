#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

std::vector<std::string> A;

int hashify(std::string& s) {
    int h = 0;
    for(char c : s) {
        h += c;
        h *= 17;
        h %= 256;
    }
    return h;
}

void run_case1() {
    int n = A.size();
    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans += hashify(A[i]); 
    }

    std::cout << ans << '\n';
}

void run_case2() {
    std::vector<std::vector<std::pair<std::string, int>>> a(256);
    for(std::string& s : A) {
        int size = s.size();
        int p = 0;
        while(p < size && s[p] != '=' && s[p] != '-') {
            p += 1;
        }

        std::string label = s.substr(0, p);
        
        int h = hashify(label);
        std::vector<std::pair<std::string, int>>& box = a[h];

        if(s[p] == '=') {
            int focal = std::stoi(s.substr(p + 1, size - (p + 1)));
            bool found = false;
            for(auto& [l, f] : box) {
                if(l == label) {
                    f = focal; 
                    found = true;
                    break;
                }
            }

            if(!found) {
                box.emplace_back(label, focal);
            }
        } else {
            for(auto it = box.begin(); it != box.end(); it++) {
                if(it->first == label) {
                    box.erase(it);
                    break;
                }
            }
        }
    }

    int64_t ans = 0;
    for(int i = 0; i < 256; i++) {
        std::vector<std::pair<std::string, int>>& box = a[i];
        int size = box.size();
        
        for(int j = 0; j < size; j++) {
            ans += (int64_t)(i + 1) * (j + 1) * box[j].second;
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string S;
    while(std::getline(std::cin, S)) {
        int n = S.size();
        std::string s = "";
        for(int i = 0; i < n; i++) {
            while(i < n && S[i] != ',') {
                s.push_back(S[i++]);
            }

            A.push_back(s); 
            s = "";
        }
    }

    run_case1();
    run_case2();
}
