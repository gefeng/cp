#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int A, B, C, D;
    std::cin >> A >> B >> C >> D;

    std::string S;
    std::cin >> S;

    int n = S.size();
    
    std::string s = "";
    for(int i = 0; i < n; ) {
        int j = i;
        while(i < n && S[i] == S[j]) {
            i += 1;
        }
        
        int len = i - j;
        if(j == 0 || i == n) {
            if(S[j] == 'A') {
                A -= len - 1;
                if(A < 0) {
                    std::cout << "No" << '\n';
                    return;
                }
                s.push_back('A');
            } else {
                B -= len - 1;
                if(B < 0) {
                    std::cout << "No" << '\n';
                    return;
                }
                s.push_back('B');
            }
        } else {
            if(len > 2) {
                if(S[j] == 'A') {
                    A -= len - 2;
                    if(A < 0) {
                        std::cout << "No" << '\n';
                        return;
                    }
                    s.append("AA");
                } else {
                    B -= len - 2;
                    if(B < 0) {
                        std::cout << "No" << '\n';
                        return;
                    }
                    s.append("BB");
                }
            } else {
                for(int _ = 0; _ < len; _++) {
                    s.push_back(S[j]);
                }
            }
        }
    }

    n = s.size();
    std::vector<int> seg_ab;
    std::vector<int> seg_ba;
    for(int i = 0; i < n; i++) {
        int j = i;
        while(i + 1 < n && s[i + 1] != s[i]) {
            i += 1;
        }
        
        int len = i - j + 1;
        if(s[j] != s[i]) {
            int need = len / 2;
            if(s[j] == 'A') {
                seg_ab.push_back(need);
            } else {
                seg_ba.push_back(need);
            }
        }
    }
    
    std::ranges::sort(seg_ab);
    std::ranges::sort(seg_ba);

    for(int c : seg_ab) {
        if(C >= c) {
            C -= c;
            continue;
        }
        c -= C;
        C = 0;
        if(A == 0 || B == 0) {
            std::cout << "No" << '\n';
            return;
        }
        A -= 1;
        B -= 1;
        c -= 1;
        if(c == 0) {
            continue;
        }
        int d = std::min(c, D);
        D -= d;
        c -= d;
        if(c == 0) {
            continue; 
        }
        if(A < c || B < c) {
            std::cout << "No" << '\n';
            return;
        }
        A -= c;
        B -= c;
    }

    for(int c : seg_ba) {
        if(D >= c) {
            D -= c;
            continue;
        }
        c -= D;
        D = 0;
        if(A == 0 || B == 0) {
            std::cout << "No" << '\n';
            return;
        }
        A -= 1;
        B -= 1;
        c -= 1;
        if(c == 0) {
            continue;
        }
        int d = std::min(c, C);
        C -= d;
        c -= d;
        if(c == 0) {
            continue; 
        }
        if(A < c || B < c) {
            std::cout << "No" << '\n';
            return;
        }
        A -= c;
        B -= c;
    }

    //std::cout << A << ' ' << B << ' ' << C << ' ' << D << '\n';

    for(int i = 0; i < n; i++) {
        int j = i;
        while(i + 1 < n && s[i + 1] != s[i]) {
            i += 1;
        }
        
        int len = i - j + 1;
        if(s[i] == s[j]) {
            int need = len / 2;
            int d = std::min(C, need);
            C -= d;
            need -= d;
            if(need) {
                d = std::min(D, need);
                D -= d;
                need -= d;
                if(need) {
                    if(A < need || B < need) {
                        std::cout << "No" << '\n';
                        return;
                    }
                    A -= need;
                    B -= need;
                }
            }
            if(s[j] == 'A') {
                A -= 1;
                if(A < 0) {
                    std::cout << "No" << '\n';
                    return;
                } 
            } else {
                B -= 1;
                if(B < 0) {
                    std::cout << "No" << '\n';
                    return;
                }
            }
        }
    }
    
    std::cout << (A == 0 && B == 0 && C == 0 && D == 0 ? "Yes" : "No") << '\n';
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
