#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

int query(std::vector<int>& a) {
    int k = a.size();
    std::cout << "? " << k << " ";
    for(int i = 0; i < k; i++) {
        std::cout << a[i] + 1 << ' ';
    }
    std::cout << std::endl;
    
    int Q;
    std::cin >> Q;
    return Q;
}

void run_case() {
    int N;
    std::cin >> N;

    int n = N * 2 + 1;
    int p1 = n - 1;
    int p2 = n - 1;
    int p3 = n - 1;

    int lo = 0;
    int hi = n - 2;
    while(lo <= hi) {
        int mid = (lo + hi) >> 1;
        
        std::vector<int> a;
        std::vector<int> b;
        for(int i = 0; i <= mid; i++) {
            a.push_back(i);
        }

        for(int i = mid + 1; i < n; i++) {
            b.push_back(i);
        }

        int x = query(a);
        int y = query(b);

        if(x == y) {
            if((a.size() - x) % 2 == 0) {
                lo = mid + 1; 
            } else {
                hi = mid - 1;
            }
        } else if(x > y) {
            p1 = mid;
            hi = mid - 1;
        } else {
            hi = mid - 1;
        }
    }

    lo = 0;
    hi = n - 2;
    while(lo <= hi) {
        int mid = (lo + hi) >> 1;
        
        std::vector<int> a;
        std::vector<int> b;
        for(int i = 0; i <= mid; i++) {
            a.push_back(i);
        }

        for(int i = mid + 1; i < n; i++) {
            b.push_back(i);
        }

        int x = query(a);
        int y = query(b);

        if(x == y) {
            if((a.size() - x) % 2 == 0) {
                lo = mid + 1; 
            } else {
                hi = mid - 1;
            }
        } else if(x > y) {
            lo = mid + 1;
        } else {
            p2 = mid;
            hi = mid - 1;
        }
    }
    
    lo = 0;
    hi = n - 2;
    while(lo <= hi) {
        int mid = (lo + hi) >> 1;
        
        std::vector<int> a;
        std::vector<int> b;
        for(int i = 0; i <= mid; i++) {
            a.push_back(i);
        }

        for(int i = mid + 1; i < n; i++) {
            b.push_back(i);
        }

        int x = query(a);
        int y = query(b);

        if(x == y) {
            if((a.size() - x) % 2 == 0) {
                lo = mid + 1; 
            } else {
                p3 = mid;
                hi = mid - 1;
            }
        } else {
            lo = mid + 1;
        }
    }

    std::cout << "! " << p1 + 1 << ' ' << p2 + 1 << ' ' << p3 + 1 << std::endl;
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
