#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

int next_int(std::string& s, int& p) {
    int n = s.size();
    if(p >= n) {
        return -1;
    }

    int x = 0;
    while(p < n && s[p] == ' ') {
        p += 1;
    }
    
    while(p < n && s[p] >= '0' && s[p] <= '9') {
        x = x * 10 + s[p] - '0';
        p += 1;
    }
    
    return x;
}

bool is_safe(std::vector<int>& a) {
    bool inc = true;
    bool dec = true;
    bool gap = true;
    
    for(int i = 1; i < a.size(); i++) {
        if(a[i] <= a[i - 1]) {
            inc = false;
        }
        if(a[i] >= a[i - 1]) {
            dec = false;
        }

        int d = std::abs(a[i] - a[i - 1]);
        if(d < 1 || d > 3) {
            gap = false;
        }
    }

    return (inc || dec) && gap;
}

void run_case() {
    int ans = 0;
    for(std::string S; std::getline(std::cin, S); ) {
        int p = 0;
        std::vector<int> a;
        while(true) {
            int x = next_int(S, p);
            if(x == -1) {
                break;
            }
            a.push_back(x);
        }

        if(is_safe(a)) {
            ans += 1;
        } else {
            for(int i = 0; i < a.size(); i++) {
                std::vector<int> b;
                for(int j = 0; j < a.size(); j++) {
                    if(i != j) {
                        b.push_back(a[j]);
                    }
                }
                if(is_safe(b)) {
                    ans += 1;
                    break;
                } 
            }
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
