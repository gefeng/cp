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

void run_case() {
    int Q;
    std::cin >> Q;
    
    std::set<int64_t> s;
    std::map<int64_t, int> m;
    for(int i = 0; i < Q; i++) {
        std::string T;
        int64_t X;
        std::cin >> T >> X;

        if(T == "+") {
            s.insert(X); 
        } else {
            int64_t c = 1;
            if(m.find(X) != m.end()) {
                c = m[X] + 1;
            }
            while(s.find(c * X) != s.end()) {
                c += 1;
            }
            m[X] = c - 1;

            std::cout << c * X << '\n';
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
