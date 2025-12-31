#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

std::vector<int> prefix_function(std::string s) {
    int n = (int)s.length();
    std::vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

std::vector<int> z_function(std::string s) {
    int n = s.size();
    std::vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) {
            z[i] = std::min(r - i, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

void run_case() {
    std::string S;
    std::cin >> S;

    int n = S.size();
    std::vector<int> z = z_function(S);
    std::map<std::string, int> m;
    
    for(int i = 0; i < n; i++) {
        if(z[i] + i != n) {
            continue; 
        }
        
        std::string s = "";
        for(int j = z[i], k = 0; k < 10; k++, j++) {
            S.push_back(S[j]);
            s.push_back(S[j]);
            m[s] = std::max(m[s], z[i] + k + 1);
        }
        while(S.size() != n) {
            S.pop_back();
        }
    }
    
    int Q;
    std::cin >> Q;
    for(int _ = 0; _ < Q; _++) {
        std::string T;
        std::cin >> T;

        int size = T.size();
        std::vector<int> res(size, 0);

        S.append(T);
        
        std::string s = "";
        for(int i = 0; i < size; i++) {
            s.push_back(T[i]);
            if(m.find(s) != m.end()) {
                res[i] = m[s];
            }
            
            for(int j = 0; j < s.size(); j++) {
                bool good = true;
                for(int k = j, p = 0; k < s.size(); k++, p++) {
                    if(S[p] != s[k]) {
                        good = false;
                        break;
                    }
                }
                if(good) {
                    res[i] = std::max(res[i], static_cast<int>(s.size()) - j);
                }
            }
        }

        while(S.size() != n) {
            S.pop_back();
        }

        for(int i = 0; i < size; i++) {
            std::cout << res[i] << " \n"[i == size - 1];
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
