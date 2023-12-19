#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>
#include <map>

constexpr int NO_MATCH = 9999; 

std::map<std::string, std::vector<std::pair<int, std::pair<int, std::string>>>> M;
std::vector<std::array<int, 4>> A;

bool is_digit(char c) {
    return c >= '0' && c <= '9';
}

bool is_overlap(int l1, int r1, int l2, int r2) {
    return !(r1 < l2 || l1 > r2);
}

void dfs(std::array<std::pair<int, int>, 4> range, std::string s, std::vector<std::array<std::pair<int, int>, 4>>& res) {
    if(s == "A") {
        res.push_back(range);
        return; 
    } else if(s == "R") {
        return;
    }

    std::vector<std::pair<int, std::pair<int, std::string>>>& e = M[s];
    for(auto [i, p] : e) {
        if(i != NO_MATCH) {
            int l1 = range[i].first;
            int r1 = range[i].second;
            int l2 = 0;
            int r2 = 0;
            if(p.first < 0) {
                l2 = 1;
                r2 = std::abs(p.first) - 1;
            } else {
                l2 = p.first + 1;
                r2 = 4000;
            }
            if(is_overlap(l1, r1, l2, r2)) {
                int cl = std::max(l1, l2);
                int cr = std::min(r1, r2);
                range[i].first = cl;
                range[i].second = cr;
                dfs(range, p.second, res);
                range[i].first = l1;
                range[i].second = r1;
            }

            if(p.first < 0) {
                l2 = std::abs(p.first);
                r2 = 4000;
            } else {
                l2 = 1;
                r2 = p.first;
            }

            if(is_overlap(l1, r1, l2, r2)) {
                int cl = std::max(l1, l2);
                int cr = std::min(r1, r2);
                range[i].first = cl;
                range[i].second = cr;
            } else {
                break;
            }
        } else {
            dfs(range, p.second, res);
        }
    }
}

void run_case1() {
    int64_t ans = 0;
    for(std::array<int, 4>& a : A) {
        std::string s = "in";

        while(s != "A" && s != "R") {
            std::vector<std::pair<int, std::pair<int, std::string>>>& e = M[s];
            for(auto [i, p] : e) {
                if(i != NO_MATCH) {
                    if((p.first < 0 && a[i] < std::abs(p.first)) || (p.first > 0 && a[i] > p.first)) {
                        s = p.second; 
                        break;
                    }
                } else {
                    s = p.second;
                    break;
                }
            }
        }

        if(s == "A") {
            for(int i = 0; i < 4; i++) {
                ans += a[i];
            }
        }
    }

    std::cout << ans << '\n';
}

void run_case2() {
    int64_t ans = 0;
    std::array<std::pair<int, int>, 4> range = {std::make_pair<int, int>(1, 4000), std::make_pair<int, int>(1, 4000), 
        std::make_pair<int, int>(1, 4000), std::make_pair<int, int>(1, 4000)};

    std::vector<std::array<std::pair<int, int>, 4>> res;
    dfs(range, "in", res);
    
    for(auto& r : res) {
        int64_t cnt = 1;
        for(int i = 0; i < 4; i++) {
            cnt *= r[i].second - r[i].first + 1;
        }
        ans += cnt;
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string S;
    while(std::getline(std::cin, S)) {
        int n = S.size();
        if(S.empty()) {
            continue;
        }

        int i = 0;
        if(S[0] == '{') {
            i += 1;
            std::array<int, 4> v;
            for(int j = 0; j < 4; j++) {
                int x = 0;
                while(i < n && S[i] != ',') {
                    if(is_digit(S[i])) {
                        x = x * 10 + S[i] - '0';
                    }
                    i += 1;
                }
                v[j] = x;
                if(S[i] == ',') {
                    i += 1;
                }
            }
            A.push_back(v);
        } else {
            std::string id = "";
            while(S[i] != '{') {
                id.push_back(S[i++]); 
            }
            i += 1;

            while(i < n && S[i] != '}') {
                std::string s;
                while(S[i] != ',' && S[i] != '}') {
                    s.push_back(S[i++]);
                }

                if(s.find('<') != std::string::npos || s.find('>') != std::string::npos) {
                    char c = s[0];
                    int p = 2;
                    int x = 0;
                    std::string to = "";
                    while(p < s.size() && s[p] != ':') {
                        x = x * 10 + s[p] - '0'; 
                        p += 1;
                    }
                    
                    x *= s[1] == '<' ? -1 : 1;

                    p += 1;
                    while(p < s.size()) {
                        to.push_back(s[p++]);
                    }
                    
                    int part = 0;
                    if(c == 'x') {
                        part = 0; 
                    } else if(c == 'm') {
                        part = 1;
                    } else if(c == 'a') {
                        part = 2;
                    } else {
                        part = 3;
                    }

                    M[id].push_back({part, {x, to}});
                } else {
                    M[id].push_back({NO_MATCH, {-1, s}});
                }
                if(S[i] == ',') {
                    i += 1;
                }
            }
        }
    }
    
    run_case1();
    run_case2();
}
