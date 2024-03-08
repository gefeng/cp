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

void run_case() {
    int N;
    std::cin >> N;

    if(N == 1) {
        std::cout << 1 << '\n';
        return;
    }

    if(N == 3) {
        std::cout << "169" << '\n' << "196" << '\n' << "961" << '\n';
        return;
    }

    if(N == 5) {
        std::cout << "16384" << '\n' << "31684" << '\n' << "36481" << '\n' << "38416" << '\n'<< "43681" << '\n';
        return;
    }

    std::string s = "196";
    std::string t = "";
    while(s.size() < N) {
        s.push_back('0');
    }
    std::cout << s << '\n';

    for(int i = 0; i < N / 2; i++) {
        s = "";
        t = "";
        s.push_back('1');
        t.push_back('9');
        for(int j = 0; j < i; j++) {
            s.push_back('0');
            t.push_back('0');
        }
        s.push_back('6');
        t.push_back('6');
        for(int j = 0; j < i; j++) {
            s.push_back('0');
            t.push_back('0');
        }
        s.push_back('9');
        t.push_back('1');
        for(int j = 0; j < i && s.size() < N; j++) {
            s.push_back('0');
            t.push_back('0');
        }

        while(s.size() < N) {
            s.push_back('0');
            t.push_back('0');
        }
        std::cout << s << '\n' << t << '\n';
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
