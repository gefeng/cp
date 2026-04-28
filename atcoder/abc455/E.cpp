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
    int N;
    std::cin >> N;

    std::string S;
    std::cin >> S;

    std::array<int, 3> freq{};
    std::map<int, int> m1;
    std::map<int, int> m2;
    std::map<int, int> m3;
    std::map<std::pair<int, int>, int> m4;
    int64_t ans = static_cast<int64_t>(N) * (N + 1) / 2;
    m1[0] = 1;
    m2[0] = 1;
    m3[0] = 1;
    m4[{0, 0}] = 1;
    for(int i = 0; i < N; i++) {
        freq[S[i] - 'A']++;

        int x = freq[0] - freq[1];
        int ab = 0;
        if(m1.find(x) != m1.end()) {
            ab += m1[x];
        }
        m1[x]++;
        
        x = freq[0] - freq[2];
        int ac = 0;
        if(m2.find(x) != m2.end()) {
            ac += m2[x];
        }
        m2[x]++;

        x = freq[1] - freq[2];
        int bc = 0;
        if(m3.find(x) != m3.end()) {
            bc += m3[x];
        }
        m3[x]++;
        
        std::pair<int, int> k{freq[0] - freq[1], freq[0] - freq[2]};
        int abc = 0;
        if(m4.find(k) != m4.end()) {
            abc += m4[k];
        }
        m4[k]++;

        ans -= ab;
        ans -= bc;
        ans -= ac;
        ans += abc * 2;
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
