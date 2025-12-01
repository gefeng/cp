#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>
#include <set>

bool is_digit(char c) {
    return c >= '0' && c <= '9';
}

int next_int(std::string& s, int& p) {
    int x = 0;
    int n = s.size();
    while(p < n && (!is_digit(s[p]))) {
        p += 1;
    }

    if(p == n) {
        return -1;
    }

    while(p < n && is_digit(s[p])) {
        x = x * 10 + s[p] - '0';
        p += 1;
    }

    return x;
}

void run_case() {
    int ans = 0;
    bool reading_rules = true;
    std::map<int, std::set<int>> m;

    for(std::string S; std::getline(std::cin, S); ) {
        if(S.empty()) {
            reading_rules = false;
            continue;
        }

        if(reading_rules) {
            int p = 0;
            int x = next_int(S, p);
            int y = next_int(S, p); 
            m[x].insert(y);
        } else {
            std::vector<int> a;
            int p = 0;
            while(true) {
                int x = next_int(S, p);
                if(x == -1) {
                    break;
                }
                a.push_back(x);
            }

            int n = a.size();
            bool good = true;
            for(int i = 0; i < n; i++) {
                if(m.find(a[i]) == m.end()) {
                    continue;
                }
                for(int j = 0; j < i; j++) {
                    if(m[a[i]].find(a[j]) != m[a[i]].end()) {
                        good = false;
                        break;
                    }
                }
            }

            if(good) {
                ans += a[n / 2]; 
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
