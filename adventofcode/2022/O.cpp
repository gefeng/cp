#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

using LL = long long;

constexpr LL Y = 2000000LL;
constexpr int MAX = (int)4e6;

void run_case() {
    auto is_digit = [](char c) {
        return c >= '0' && c <= '9';
    };

    std::string S;
    std::cin >> S;

    std::vector<std::vector<std::pair<LL, LL>>> range_x(MAX + 1);
    
    std::set<std::pair<LL, LL>> beacon;
    std::set<std::pair<LL, LL>> sensor;

    while(std::getline(std::cin, S)) {
        int n = S.size();
        std::vector<LL> pos;
        for(int i = 0; i < n; ) {
            if(is_digit(S[i])) {
                LL x = 0LL;
                int j = i;
                while(i < n && is_digit(S[i])) {
                    x = x * 10LL + S[i] - '0';
                    i += 1;
                }
                
                LL sign = j > 0 && S[j - 1] == '-' ? -1LL : 1LL;
                pos.push_back(x * sign);
            } else {
                i += 1;
            }
        }

        LL d = abs(pos[0] - pos[2]) + abs(pos[1] - pos[3]);
        for(int y = 0; y <= MAX; y++) {
            LL to_y = abs(pos[1] - y); 
            if(to_y <= d) {
                range_x[y].emplace_back(pos[0] - (d - to_y), pos[0] + (d - to_y)); 
            }
        }

        sensor.emplace(pos[0], pos[1]);
        beacon.emplace(pos[2], pos[3]);

        /*if(pos[3] == Y) {
            beacon.insert(pos[2]);
        }*/
    }


    for(int i = 0; i <= MAX; i++) {
        std::vector<std::pair<LL, LL>>& v = range_x[i];
    
        std::sort(v.begin(), v.end());

        std::vector<std::pair<LL, LL>> merge;
        for(auto p : v) {
            //std::cout << p.first << ' ' << p.second << '\n';
            if(!merge.empty() && merge.back().second + 1 >= p.first) {
                merge.back().second = std::max(merge.back().second, p.second);
            } else {
                merge.push_back(p);
                /*if(merge.empty()) {
                    merge.push_back(p);
                } else {
                    LL x = p.first - 1LL;
                    LL y = i; 
                    if(x >= 0 && x <= MAX && y >= 0 && y <= MAX && 
                            sensor.find({x, y}) == sensor.end() && beacon.find({x, y}) == beacon.end()) {
                        std::cout << x * MAX + y << '\n';
                    }   
                }*/
            }
        }

        if(merge.size() > 1) {
            LL x = merge[1].first - 1;
            LL y = i;
            std::cout << x * MAX + y << '\n';
            
        }
    }


    /*LL ans = 0LL;
    for(auto p : merge) {
        ans += p.second - p.first + 1LL;
        
        for(LL x : beacon) {
            if(x >= p.first && x <= p.second) {
                ans -= 1LL;
            } 
        }
    }

    std::cout << ans << '\n';*/
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
