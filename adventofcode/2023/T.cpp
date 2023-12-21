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
#include <queue>

std::vector<std::vector<std::string>> A;
std::map<std::string, std::map<std::string, int>> B;
std::map<std::string, int> C;

std::vector<std::vector<int>> save(4);

constexpr int REP = 50000;
void run_case1() {
    std::map<std::string, std::vector<std::string>> g;
    for(auto& step : A) {
        int n = step.size();
        for(int i = 1; i < n; i++) {
            g[step[0]].push_back(step[i]);
        }
    }

    int64_t cnt_lo = 0;
    int64_t cnt_hi = 0;
    for(int i = 0; i < REP; i++) {
        std::queue<std::pair<std::string, int>> q;
        q.emplace("broadcaster", 0);

        cnt_lo += 1;
       
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                auto [source, pulse] = q.front();
                q.pop();
                if(pulse == 0) {
                    cnt_lo += g[source].size();
                } else {
                    cnt_hi += g[source].size();
                }

                for(std::string& nei : g[source]) {
                    if(C.find(nei) != C.end()) {
                        if(pulse == 0) {
                            C[nei] ^= 1;  
                            q.emplace(nei, C[nei] ? 1 : 0);
                        }
                    } else if(B.find(nei) != B.end()) {
                        B[nei][source] = pulse;
                        int hi = 0;
                        for(auto& [_, r] : B[nei]) {
                            if(r) {
                                hi += 1;
                            }
                        }

                        int send = hi == B[nei].size() ? 0 : 1;
                        q.emplace(nei, send);

                        if(send == 1) {
                            if(nei == "ks") {
                                save[0].push_back(i + 1);
                            } else if(nei == "pm") {
                                save[1].push_back(i + 1);
                            } else if(nei == "dl") {
                                save[2].push_back(i + 1);
                            } else if(nei == "vk") {
                                save[3].push_back(i + 1);
                            }
                        }
                        
                    }
                }
            }
        }
    }
    
    std::cout << cnt_hi * cnt_lo << '\n';
}

int64_t gcd(int64_t a, int64_t b) {
    if(a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

int64_t lcm(int64_t a, int64_t b) {
    return a * b / gcd(a, b);
}

void run_case2() {
    int64_t ans = save[0].front();
    for(int i = 1; i < 4; i++) {
        ans = lcm(ans, save[i].front());
    }
    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    std::string S;
    std::vector<std::string> input;
    while(std::getline(std::cin, S)) {
        input.push_back(S);

        int i = 0;
        std::string from = "";
        std::vector<std::string> to;
        while(S[i] != ' ') {
            from.push_back(S[i++]); 
        } 


        if(from[0] == '&') {
            std::string id = from.substr(1, from.size() - 1);  
            if(B.find(id) == B.end()) {
                B[id] = {};
            }
        }

        if(from[0] == '%') {
            std::string id = from.substr(1, from.size() - 1);
            C[id] = 0;
        }
    }

    for(std::string& s : input) {
        int n = s.size(); 
        int i = 0;
        std::string from = "";
        if(s[i] == '&' || s[i] == '%') {
            i += 1;
        }

        A.emplace_back();
        while(s[i] != ' ') {
            from.push_back(s[i++]); 
        } 

        A.back().push_back(from);

        i += 4;
        while(i < n) {
            if(s[i] == ' ' || s[i] == ',') {
                i += 1;
                continue;
            }

            std::string t = "";
            while(i < n && s[i] != ',') {
                t.push_back(s[i++]);
            }
            A.back().push_back(t);

            if(B.find(t) != B.end()) {
                B[t][from] = 0;
            }
        }
    }
    
    run_case1();
    run_case2();
}
