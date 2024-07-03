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

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    auto get_score = [&](int st) {
        std::vector<int> a;
        std::set<int> s;
        if(st == 1) {
            s.insert(A[0]);
        }
        for(int i = st; i < N; i += 2) {
            if(i + 1 < N) {
                int x = A[i];
                int y = A[i + 1];
                int score = 0;
                
                if(x < y) {
                    s.insert(x);
                    if((int)s.size() == i + 1 && s.upper_bound(i + 1) == s.end()) {
                        score -= 1;
                    }
                    s.insert(y);
                } else {
                    s.insert(y);
                    if((int)s.size() == i + 1 && s.upper_bound(i + 1) == s.end()) {
                        score += 1;
                    }
                    s.insert(x);
                }

                a.push_back(score);
            }
        }

        return a;
    };

    auto sub_max = [](std::vector<int>& a) {
        int n = a.size();
        int sum = 0;
        int max_sum = 0;
        for(int i = 0; i < n; i++) {
            sum += a[i];
            max_sum = std::max(max_sum, sum); 
            sum = std::max(0, sum);
        }
        return max_sum;
    };

    std::vector<int> s1 = get_score(0);
    std::vector<int> s2 = get_score(1);

    int score = 0;
    std::set<int> s;
    for(int i = 0; i < N; i++) {
        s.insert(A[i]);
        
        if((int)s.size() == i + 1 && s.upper_bound(i + 1) == s.end()) {
            score += 1;
        }
    }

    score += std::max(sub_max(s1), sub_max(s2));
    std::cout << score << '\n';
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
