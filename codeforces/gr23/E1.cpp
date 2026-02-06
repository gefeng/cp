#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <numeric>

void run_case() {
    int N;
    std::cin >> N;

    auto query = [](std::vector<int>& a) {
        int size = a.size();
        std::cout << "? " << size << ' ';
        for(int i = 0; i < size; i++) {
            std::cout << a[i] << ' ';
        }
        std::cout << std::endl;
        
        std::string Q;
        std::cin >> Q;
        return Q == "YES" ? 1 : 0;
    };

    auto guess = [](int x) {
        std::cout << "! " << x << std::endl;
        std::string Q;
        std::cin >> Q;
        return Q == ":)" ? 1 : 0;
    };

    std::vector<int> now(N, 0);
    std::iota(now.begin(), now.end(), 1);

    while(now.size() > 3) {
        int n = now.size();
        int m1 = n / 4;
        int m2 = n / 4 * 2;
        int m3 = n / 4 * 3;

        std::vector<int> a;
        std::vector<int> b;
        for(int i = 0; i < m2; i++) {
            a.push_back(now[i]);
        }
        for(int i = 0; i < m1; i++) {
            b.push_back(now[i]);
        }
        for(int i = m2; i < m3; i++) {
            b.push_back(now[i]);
        }
        
        int q1 = query(a);
        int q2 = query(b);
        std::vector<int> nxt;
        if(q1 && q2) {
            for(int i = 0; i < m3; i++) {
                nxt.push_back(now[i]);
            }
        } else if(!q1 && !q2) {
            for(int i = m1; i < n; i++) {
                nxt.push_back(now[i]);
            }
        } else if(q1 && !q2) {
            for(int i = 0; i < m2; i++) {
                nxt.push_back(now[i]);
            }
            for(int i = m3; i < n; i++) {
                nxt.push_back(now[i]);
            }
        } else {
            for(int i = 0; i < m1; i++) {
                nxt.push_back(now[i]);
            }
            for(int i = m2; i < n; i++) {
                nxt.push_back(now[i]);
            }
        }

        now = std::move(nxt);
    }

    if(now.size() == 1) {
        guess(now[0]);
        return;
    }
    if(now.size() == 2) {
        if(!guess(now[0])) {
            guess(now[1]);
        }
        return;
    }

    {
        std::vector<int> a{now[0]};
        int q = query(a);
        if(!q) {
            q = query(a);
            if(q) {
                if(!guess(now[0])) {
                    a[0] = now[1];
                    q = query(a);
                    if(q) {
                        guess(now[1]);
                    } else {
                        guess(now[2]);
                    }
                }
            } else {
                if(!guess(now[1])) {
                    guess(now[2]);
                }
            }
        } else {
            a[0] = now[1];
            q = query(a);
            if(q) {
                if(!guess(now[0])) {
                    guess(now[1]); 
                }
            } else {
                if(!guess(now[0])) {
                    guess(now[2]);
                }
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
