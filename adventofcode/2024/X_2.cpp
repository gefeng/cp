#include <iostream>
#include <utility> 
#include <cassert> 
#include <algorithm> 
#include <cmath>
#include <array>
#include <string> 
#include <vector>
#include <queue> 
#include <map> 
#include <set>

inline bool is_letter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

std::string to_binary(int64_t x) {
    std::string s = "";
    for(int i = 45; i >= 0; i--) {
        if(x & (int64_t(1) << i)) {
            s.push_back('1');
        } else {
            s.push_back('0');
        }
    }
    return s;
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

int get_diff(std::string& s, std::string& t) {
    int n = s.size();
    int cnt = 0;
    for(int i = 0; i < 46; i++) {
        if(s[i] != t[i]) {
            cnt += 1;
        }
    }
    return cnt;
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
            if(a[0] > a[2]) {
                std::swap(a[0], a[2]);
            }
            A.push_back(a);
        } else {
            int p = 0;
            std::string s = next_word(S, p);
            int val = S.back() - '0';
            m[s] = val;
        }
    }

    int n = A.size();
    std::sort(A.begin(), A.end());

    auto solve = [&]() {
        std::set<std::string> nodes;
        std::map<std::string, std::set<std::string>> g;
        std::map<std::string, std::set<std::string>> rg;
        std::map<std::string, std::string> gate;
        std::map<std::string, int> indegree;

        for(auto& a : A) {
            std::string v_1 = a[0];
            std::string v_2 = a[2];
            std::string v_3 = a[3];
            std::string op = a[1];
            g[v_1].insert(v_3);
            g[v_2].insert(v_3);
            rg[v_3].insert(v_1);
            rg[v_3].insert(v_2);
            indegree[v_3] += 2;
            gate[v_3] = op; 
            nodes.insert(v_1);
            nodes.insert(v_2);
            nodes.insert(v_3);
        }
        
        std::queue<std::string> q;
        for(const std::string& v : nodes) {
            if(indegree.find(v) == indegree.end()) {
                q.push(v);
            }
        }

        int cnt = 0;
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                std::string v = q.front();
                q.pop();

                cnt += 1;
                
                for(const std::string& nei : g[v]) {
                    if(--indegree[nei] == 0) {
                        std::string& op = gate[nei];
                        int x = m[*rg[nei].begin()];
                        int y = m[*rg[nei].rbegin()];
                        if(op == "AND") {
                            m[nei] = x & y;    
                        } else if(op == "OR") {
                            m[nei] = x | y;
                        } else if(op == "XOR") {
                            m[nei] = x ^ y;
                        }
                        q.push(nei);
                    }
                }
            }
        }

        if(cnt != nodes.size()) {
            return -1;
        }

        // auto bfs = [&](std::string st) {
        //     std::queue<std::string> q;
        //     q.push(st);
        //     while(!q.empty()) {
        //         int size = q.size();
        //         while(size--) {
        //             std::string now = q.front();
        //             q.pop();
        //
        //             // if(now[0] != 'x' && now[0] != 'y') {
        //             //     std::cout << '\"' << now << '\"' << ',';
        //             // }
        //
        //             if(gate.find(now) == gate.end()) {
        //                 std::cout << now << ' ';
        //             } else {
        //                 std::cout << now << "[" << gate[now] << "]" << ' ';
        //             }
        //
        //             // std::cout << now << "[" << m[now] << "]" << ' ';
        //             for(std::string nei : rg[now]) {
        //                 q.push(nei);
        //             }
        //         }
        //         std::cout << '\n';
        //     } 
        //     std::cout << '\n';
        // };
        //
        // for(std::string s : nodes) {
        //     if(s[0] == 'z') {
        //         bfs(s);
        //     }
        // }

        int64_t res = 0;
        int64_t x = 0;
        int64_t y = 0;
        for(auto [s, v] : m) {
            if(s[0] == 'z') {
                if(v == 1) {
                    res |= int64_t(1) << stoi(s.substr(1, 2));
                }
            }
            if(s[0] == 'x') {
                if(v == 1) {
                    x |= int64_t(1) << stoi(s.substr(1, 2));
                }
            }
            if(s[0] == 'y') {
                if(v == 1) {
                    y |= int64_t(1) << stoi(s.substr(1, 2));
                }
            }
        }
        //std::cout << x + y << ' ' << res << '\n';
        // std::cout << to_binary(x) << '\n';
        // std::cout << to_binary(y) << '\n';
        std::string st = to_binary(x + y);
        std::string sr = to_binary(res);
        std::cout << res << '\n';
        int d = get_diff(st, sr);
        //std::cout << cnt_0 << ' ' << cnt_1 << '\n';
        std::cout << st << '\n' << sr << '\n';
        std::cout << d << '\n';
        return d;
    };

    auto to_node = [](int x) {
        std::string res = "x";
        if(x < 10) {
            res.push_back('0');
            res.push_back(char(x + '0'));
        } else {
            res.append(std::to_string(x));
        }
        return res;
    };
    
    auto get_pos = [&](std::string s) {
        for(int i = 0; i < n; i++) {
            if(A[i][3] == s) {
                return i;
            }
        } 
        return -1;
    };

    int p_1 = get_pos("kfp");
    int p_2 = get_pos("hbs");
    int p_3 = get_pos("z27");
    int p_4 = get_pos("jcp");
    int p_5 = get_pos("dhq");
    int p_6 = get_pos("z18");
    int p_7 = get_pos("z22");
    int p_8 = get_pos("pdg");

    std::swap(A[p_1][3], A[p_2][3]);        
    std::swap(A[p_3][3], A[p_4][3]);
    std::swap(A[p_5][3], A[p_6][3]);
    std::swap(A[p_7][3], A[p_8][3]);

    solve();
    //std::swap(A[get_pos("dhq")][3], A[get_pos("bqp")][3]);
    //std::swap(A[get_pos("z18")][3], A[get_pos("pdg")][3]);

    // for(int i = 0; i < n; i++) {
    //     if(i == p_1 || i == p_2 || i == p_3 || i == p_4 || i == p_5 || i == p_6) {
    //         continue;
    //     }
    //     for(int j = 0; j < n; j++) {
    //         if(i == j || j == p_1 || j == p_2 || j == p_3 || j == p_4 || j == p_5 || j == p_6) {
    //             continue;
    //         }
    //         
    //         std::swap(A[i][3], A[j][3]);
    //         int d = solve();
    //         if(d == 0) {
    //             std::cout << A[i][3] << ' ' << A[j][3] << '\n';
    //         }
    //         std::swap(A[i][3], A[j][3]);
    //     }
    // }
    
    std::vector<std::string> ans = {"kfp", "hbs", "z27", "jcp", "dhq", "z18", "z22", "pdg"};
    std::sort(ans.begin(), ans.end());

    for(auto s : ans) {
        std::cout << s << ',';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
