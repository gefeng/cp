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

    std::vector<std::string> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::set<std::string> unique;
    for(std::string& s : A) {
        unique.insert(s); 
    }

    for(std::string& s : A) {
        std::string t = s;
        std::reverse(t.begin(), t.end());
        
        if(s != t && unique.find(t) != unique.end() && unique.find(s) != unique.end()) {
            unique.erase(t); 
        }
    }

    std::cout << unique.size() << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
