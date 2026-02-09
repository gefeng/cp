#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

void run_case() {
    int N;
    std::cin >> N;

    std::string S;
    std::cin >> S;

    int p = 0;
    while(p < N && S[p] == '0') {
        p += 1;
    }
    
    if(p == N) {
        std::cout << 0 << '\n';
        return;
    }

    int l = p;
    while(p < N && S[p] == '1') {
        p += 1;
    }
    
    if(p == N) {
        std::cout << S.substr(l, N - l) << '\n';
        return;
    }

    int r = p;
    while(p < N && S[p] == '0') {
        p += 1;
    }

    std::string a = S.substr(l, N - l);
    std::string b = "";
    if(r - l <= p - r) {
        b = S.substr(l, N - r);
    } else {
        std::set<int> s;
        int d = r - l - p + r;
        int shift = 0;
        for(int x = 0; x <= d; x++) {
            s.insert(x);
        }
        for(int i = p; i < N; i++) {
            if(S[i] == '1') {
                continue;
            }
            std::vector<int> bad;
            for(int x : s) {
                if(S[i - r + l + x] == '0') {
                    bad.push_back(x);
                }
            }
            if(bad.size() == s.size()) {
                continue;
            }
            for(int x : bad) {
                s.erase(x);
            }
        }

        assert(!s.empty());
        shift = *s.begin();
        b = S.substr(l + shift, N - r);
    }

    for(int i = 0, j = a.size() - b.size(); i < b.size(); i++, j++) {
        if(a[j] != b[i]) {
            a[j] = '1';
        }
    }
    
    std::cout << a << '\n';

    // 11111001000
    //      11111
    //
    // 1111100011100
    //      11110001
    //      1110001

    // 11111000110010111000 
    //      11100011
    //      1111000110
    //      1111100011
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
