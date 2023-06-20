#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

void run_case() {
    int X;
    std::cin >> X;

    auto query = [](int x, int sign) {
        std::string s = "";
        if(sign == 1) {
            s.append("+ ");
        } else {
            s.append("- ");
        }

        s.append(std::to_string(x));

        std::cout << s << std::endl;
        
        int res;
        std::cin >> res;

        return res;
    };

    auto output_ans = [](int x) {
        std::cout << "! " + std::to_string(x) << std::endl;
    };

    int ans = 1;
    std::map<int, int> m;
    m[X] = 1;
    for(int i = 2; i <= 1000; i++) {
        int res = query(1, 1);
        if(res == X) {
            output_ans(ans);
            return;
        }

        m[res] = i;
        ans += 1;
    } 

    int cnt = 1;
    while(true) {
        int res = query(1000, 1);
        cnt += 1;
        
        if(m.find(res) != m.end()) {
            ans = cnt * 1000 - m[res];
            break;
        }
    }
    
    output_ans(ans);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
