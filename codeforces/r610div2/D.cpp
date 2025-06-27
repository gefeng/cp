#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int MAX = 300;

void run_case() {
    auto query = [](const std::string& s) {
        std::cout << s << std::endl;
        int Q;
        std::cin >> Q;
        return Q;
    };

    std::string a(MAX, 'a');
    std::string b(MAX, 'b');
    int x = query(a);
    if(x == 0) {
        return;
    }

    int y = query(b);
    if(y == 0) {
        return;
    }

    int cnt_a = y - (x + y - 300);
    int cnt_b = x - (x + y - 300);

    if(cnt_a == 0) {
        std::string s(cnt_b, 'b');
        query(s);
        return;
    }

    if(cnt_b == 0) {
        std::string s(cnt_a, 'a');
        query(s);
        return;
    }

    int len = cnt_a + cnt_b;

    std::string s(len, 'a');
    int res = cnt_b;
    
    for(int i = 0; i < len - 1; i++) {
        s[i] = 'b';
        int ed = query(s);
        if(ed == 0) {
            return;
        }
        if(ed > res) {
            s[i] = 'a';    
        } else {
            res = ed;
        }
    }

    if(res) {
        s.back() = 'b';
    }

    query(s);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
