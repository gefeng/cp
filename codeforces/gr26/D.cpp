#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

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

    int64_t ans = 0;
    int n = S.size();
    
    int st = -1;
    for(int i = 0; i < n; i++) {
        if(S[i] != 'a') {
            st = i;
            break;
        }
    }

    if(st == -1) {
        std::cout << n - 1 << '\n';
        return;
    }

    std::vector<int> z = z_function(S.substr(st, n - st));

    std::vector<int> nxt(n, n);
    for(int i = n - 1; i >= 0; i--) {
        if(S[i] == 'a') {
            if(i + 1 < n) {
                nxt[i] = nxt[i + 1];
            }
        } else {
            nxt[i] = i;
        }
    } 

    std::string pattern = "";
    for(int i = st; i < n; i++) {
        pattern.push_back(S[i]);      
        int size = pattern.size();
        
        bool ok = true;
        int p = st + size;
        int min_group = st;
        int gap = 0;
        while(p < n) {
            if(S[p] != 'a') {
                if(!gap) {
                    min_group = 0;
                }
                if(n - p < size) {
                    ok = false;
                    break;
                }
                
                if(z[p - st] < size) {
                    ok = false;
                    break;
                }
                p += size; 
                gap = 0;
            } else {
                int np = nxt[p];
                if(np != n) {
                    min_group = std::min(min_group, np - p);
                }
                p = np;
                gap = 1;
            }
        }

        if(ok) {
            ans += min_group + 1;         
        }
    }

    std::cout << ans << '\n';
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
