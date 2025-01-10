#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm> 
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int A, B, K;
    std::cin >> A >> B >> K;
    
    int ca = A;
    int cb = B;

    if(K == A + B) {
        std::cout << "No" << '\n';
        return;
    }

    std::string x = "";
    std::string y = "";
    if(K == 0) {
        for(int i = 0; i < B; i++) {
            x.push_back('1');
        }
        for(int i = 0; i < A; i++) {
            x.push_back('0');
        }
        std::cout << "Yes" << '\n' << x << '\n' << x << '\n';
        return;
    }
    
    if(B == 1 || A == 0) {
        std::cout << "No" << '\n';
        return;
    }

    auto check = [&]() {
        int cnt_a = 0;
        int cnt_b = 0;
        for(int i = 0; i < ca + cb; i++) {
            cnt_a += x[i] - '0';
            cnt_b += y[i] - '0';
        }
        assert(cnt_a == cb && cnt_b == cb);

        int c = 0;
        int cnt_k = 0;
        for(int i = ca + cb - 1; i >= 0; i--) {
            int a = x[i] - '0';
            int b = y[i] - '0';
            a -= c;
            a += 2;
            a %= 2;

            if(a == b) {
                c = 0;
                continue;
            }
            cnt_k += 1;
            if(a < b) {
                c = 1;
            }
        }
        assert(cnt_k == K && c == 0);
    };

    x.push_back('1');
    y.push_back('1');
    B -= 1;
    
    if(K <= B) {
        y.push_back('0');
        for(int i = 0; i < K; i++) {
            x.push_back('1');
            y.push_back('1'); 
        }     
        x.push_back('0');
        A -= 1;
        B -= K;

        for(int i = 0; i < A; i++) {
            x.push_back('0');
            y.push_back('0');
        }
        for(int i = 0; i < B; i++) {
            x.push_back('1');
            y.push_back('1');
        }
    } else if(K <= A) {
        x.push_back('1');
        for(int i = 0; i < K; i++) {
            x.push_back('0');
            y.push_back('0');
        }
        y.push_back('1');
        A -= K;
        B -= 1;

        for(int i = 0; i < A; i++) {
            x.push_back('0');
            y.push_back('0');
        }
        for(int i = 0; i < B; i++) {
            x.push_back('1');
            y.push_back('1');
        }
    } else {
        x.push_back('1');
        y.push_back('0');
        
        A -= 1;
        B -= 1;
        int k = 0;
        while(k < K - 1 && A) {
            x.push_back('0'); 
            y.push_back('0');
            k += 1;
            A -= 1;
        }
        
        while(k < K - 1 && B) {
            x.push_back('1');
            y.push_back('1');
            k += 1;
            B -= 1;
        }
        
        if(k < K - 1) {
            std::cout << "No" << '\n';
            return;
        }

        x.push_back('0');
        y.push_back('1');

        for(int i = 0; i < A; i++) {
            x.push_back('0');
            y.push_back('0');
        }
        for(int i = 0; i < B; i++) {
            x.push_back('1');
            y.push_back('1');
        }
    }

    std::cout << "Yes" << '\n' << x << '\n' << y << '\n';
    check();
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
