#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

/*
 * if x < y < z then min(x ^ y, y ^ z) < x ^ z
 * x = xxx1xxx0x0
 * z = xxx1xxx1xx
 *            k
 *
 * x ^ z >= 2^k
 *
 * for y 
 * if kth bit is 0 -> x ^ y < x ^ z
 * if kth bit is 1 -> y ^ z < x ^ z 
 * thus min(x ^ y, y ^ z) < x ^ z
 * so minimum pair can only exist among adjacent elements where elements are in non-descending order
 */

void run_case() {
    int Q;
    std::cin >> Q;
    
    std::map<int, int> m1;
    std::map<int, int> m2;
    for(int i = 0; i < Q; i++) { 
        int T;
        std::cin >> T;

        if(T == 1) {
            int X;
            std::cin >> X;

            if(m1.find(X) != m1.end()) {
                m2[0] += 1;
            } else {
                auto it = m1.upper_bound(X);
                if(it != m1.end() && it != m1.begin()) {
                    int a = it->first;
                    it--;
                    a = a ^ it->first;

                    if(--m2[a] == 0) {
                        m2.erase(a);
                    }
                }

                it = m1.upper_bound(X);
                if(it != m1.end()) {
                    m2[it->first ^ X] += 1;
                }
                if(it != m1.begin()) {
                    it--;
                    m2[it->first ^ X] += 1;
                }
            }

            m1[X] += 1;
        } else if(T == 2) {
            int X;
            std::cin >> X;

            if(--m1[X] == 0) {
                m1.erase(X);
                
                auto it = m1.upper_bound(X);
                if(it != m1.end() && it != m1.begin()) {
                    int a = it->first;
                    it--;
                    a = a ^ it->first;

                    m2[a] += 1;
                }

                it = m1.upper_bound(X);
                if(it != m1.end()) {
                    int a = it->first ^ X;
                    if(--m2[a] == 0) {
                        m2.erase(a);
                    }
                }

                if(it != m1.begin()) {
                    it--;
                    int a = it->first ^ X;
                    if(--m2[a] == 0) {
                        m2.erase(a);
                    }
                }
            } else {
                if(--m2[0] == 0) {
                    m2.erase(0);
                }
            }
        } else {
            std::cout << m2.begin()->first << '\n';
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
