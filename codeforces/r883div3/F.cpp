#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> cnt(10, 0);
    for(int x : A) {
        cnt[x] += 1;
    }

    auto query = [](int have, std::vector<int>& remove) {
        int n = remove.size();
        std::string q = "- " + std::to_string(n);
    
        for(int i = 0; i < n; i++) {
            q.push_back(' ');
            q.append(std::to_string(remove[i] + 1));
        }

        std::cout << q << std::endl;

        std::vector<int> res(have - n);
        for(int i = 0; i < have - n; i++) {
            std::cin >> res[i];
        }

        return res;
    };

    auto count_types = [](std::vector<int>& cnt) {
        int res = 0;
        for(int i = 1; i < 10; i++) {
            if(cnt[i]) {
                res += 1;
            }
        }
        return res;
    };

    int to = 0;
    while(count_types(cnt) > 1) {
        int sz = A.size();
        std::vector<int> remove;

        A = query(sz, remove);
        
        std::vector<int> ncnt(10, 0);
        for(int x : A) {
            ncnt[x] += 1;
        }

        bool same = true;
        for(int i = 1; i < 10; i++) {
            if(cnt[i] != ncnt[i]) {
                same = false;
                break;
            }
        }

        if(same) {
            continue;
        }

        for(int i = 0; i < sz; i++) {
            if(ncnt[A[i]] <= cnt[A[i]]) {
                remove.push_back(i);
            } else {
                to = A[i];
            }
        }

        A = query(sz, remove);
        cnt = std::vector<int>(10, 0);
        for(int i = 0; i < A.size(); i++) {
            cnt[A[i]] += 1;
            if(A[i] != to) {
                std::cout << "! " << i + 1 << std::endl;
                return;
            }
        }
    }

    if(A.size() == 1) {
        std::cout << "! " + std::to_string(1) << std::endl;
        return;
    }

    to = 0;
    for(int i = 0; i < 10; i++) {
        if(cnt[i]) {
            to = i;
            break;
        } 
    }

    while(true) {
        int sz = A.size();
        std::vector<int> remove;
        
        A = query(sz, remove);

        for(int i = 0; i < A.size(); i++) {
            if(A[i] != to) {
                std::cout << "! " + std::to_string(i + 1) << std::endl;
                return;
            } 
        }
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
