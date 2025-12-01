#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

void run_case() {
    std::vector<int> lhs;
    std::vector<int> rhs;
    for(std::string S; std::getline(std::cin, S); ) {
        int x = 0;
        int p = 0;
        while(S[p] >= '0' && S[p] <= '9') {
            x = x * 10 + S[p] - '0';
            p += 1;
        }
        lhs.push_back(x);

        while(S[p] == ' ') {
            p += 1;
        }
        
        x = 0;
        while(p < S.size() && S[p] >= '0' && S[p] <= '9') {
            x = x * 10 + S[p] - '0';
            p += 1;
        }
        rhs.push_back(x);
    }

    std::map<int, int> freq;
    for(int x : rhs) {
        freq[x] += 1;
    } 

    int64_t sum = 0;
    for(int x : lhs) {
        if(freq.find(x) != freq.end()) {
            sum += x * freq[x];
        }
    }
    std::cout << sum << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
