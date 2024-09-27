#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N;
    std::cin >> N;

    auto query = [](std::string& s) {
        std::cout << "? " << s << std::endl;
        int Q;
        std::cin >> Q;
        assert(Q != -1);
        return Q;
    };

    std::string s = "";
    while(true) {
        s.push_back('0');
        int res = query(s);
            
        if(res == 1) {
            if(s.size() == N) {
                std::cout << "! " << s << std::endl;
                return;
            }
        } else {
            s.pop_back();
            s.push_back('1');
            res = query(s);
            if(res == 0) {
                s.pop_back();
                break;
            }
            if(s.size() == N) {
                std::cout << "! " << s << std::endl;
                return;
            }
        }
    }

    while(true) {
        s = "0" + s;
        int res = query(s);
    
        if(res == 1) {
            if(s.size() == N) {
                std::cout << "! " << s << std::endl;
                return;
            }
        } else {
            s = "1" + s.substr(1, s.size() - 1);
            if(s.size() == N) {
                std::cout << "! " << s << std::endl;
                return;
            }
        }
    }
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
