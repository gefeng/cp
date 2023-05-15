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

    std::string S;
    std::cin >> S;

    int cnt = 0;
    for(char c : S) {
        if(c == 'T') {
            cnt += 1;
        }
    }

    bool win = true;
    if(cnt == N - cnt) {
        win = S.back() == 'A'; 
    } else {
        win = cnt > N - cnt;
    }

    std::cout << (win ? "T" : "A") << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
