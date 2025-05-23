#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int64_t N;
    std::cin >> N;

    auto query = [](std::string&& s, int64_t x) {
        int Q = 0;
        if(s == "add") {
            std::cout << s << ' ' << x << std::endl;
            std::cin >> Q;
        } else if(s == "mul") {
            std::cout << s << ' ' << x << std::endl;
            std::cin >> Q;
        } else if(s == "div") {
            std::cout << s << ' ' << x << std::endl;
            std::cin >> Q;
        } else {
            std::cout << s << std::endl;
            std::cin >> Q;
        }
        return Q;
    };

    for(int i = 0; i < 2; i++) {
        query("digit", 0);
    }

    query("add", -8);
    query("add", -4);
    query("add", -2);
    query("add", -1);
    query("add", N - 1);

    std::cout << "!" << std::endl;
    int Q;
    std::cin >> Q;
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
