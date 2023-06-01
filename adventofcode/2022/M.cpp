#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

struct packet {
    int val;
    std::vector<packet*> list;

    packet(int _val) : val(_val) {}
    packet(std::vector<packet*> _list) : val(-1), list(_list) {}
};

packet* build(std::string& s, int& p) {
    if(s[p] == '[') {
        std::vector<packet*> list;     
        p += 1;
        while(s[p] != ']') {
            list.push_back(build(s, p));
            if(s[p] == ',') {
                p += 1;
            }
        }
        p += 1;
        return new packet(list);
    } else {
        int v = 0;
        while(s[p] != ',' && s[p] != ']') {
            v = v * 10 + s[p] - '0';
            p += 1;
        }
        return new packet(v);;
    }
}

int check_order(const packet* p1, const packet* p2) {
    if(p1->val != -1 && p2->val != -1) {
        if(p1->val < p2->val) {
            return 1;
        }
        if(p1->val > p2->val) {
            return 2;
        }
        return 0;
    } else if(p1->val == -1 && p2->val == -1) {
        int n = p1->list.size(); 
        int m = p2->list.size();

        for(int i = 0, j = 0; i < n || j < m; i++, j++) {
            if(i == n) {
                return 1;
            }
            if(j == m) {
                return 2;
            }

            int res = check_order(p1->list[i], p2->list[j]);
            if(res) {
                return res; 
            }
        }

        return 0;
    } else if(p1->val == -1) {
        std::vector<packet*> list;
        list.push_back(new packet(p2->val));
        return check_order(p1, new packet(list));
    } else {
        std::vector<packet*> list;
        list.push_back(new packet(p1->val));
        return check_order(new packet(list), p2);
    }
}

void run_case() {
    std::string S;
    packet* p1 = nullptr;
    packet* p2 = nullptr;

    int ans = 1;
    int i = 1;
    std::vector<packet*> all;
    while(std::getline(std::cin, S)) {
        if(S.empty()) {
            p1 = nullptr;
            p2 = nullptr;
            i += 1;
            continue;
        }

        if(p1 == nullptr) {
            int pos = 0;
            p1 = build(S, pos);
            all.push_back(p1);
        } else {
            int pos = 0;
            p2 = build(S, pos);
            all.push_back(p2);
        }

        /*if(p1 && p2) {
            if(check_order(p1, p2) == 1) {
                ans += i; 
            }
        }*/
    }

    p1 = new packet({new packet(2)});
    p2 = new packet({new packet(6)});
    packet* d1 = new packet({p1});
    packet* d2 = new packet({p2});
    
    all.push_back(d1);
    all.push_back(d2);

    auto cmp = [](packet* p1, packet* p2) {
        int res = check_order(p1, p2);
        return res == 1;
    };

    std::sort(all.begin(), all.end(), cmp);

    for(int i = 0; i < all.size(); i++) {
        if(all[i] == d1 || all[i] == d2) {
            ans *= i + 1;
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
