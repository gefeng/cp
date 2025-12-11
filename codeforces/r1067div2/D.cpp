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

    std::string S, T;
    std::cin >> S >> T;

    std::vector<std::pair<int, int>> ans;
    for(int i = 0; i < N - 4; i++) {
        if(S[i] != T[i]) {
            int r = -1;
            for(int j = i + 1; j < N; j++) {
                if(S[j] == S[i]) {
                    r = j;
                    break;
                }
            }
            if(r == -1) {
                ans.emplace_back(i + 1, i + 2);
                S[i + 1] = S[i + 1] == '0' ? '1' : '0';
                S[i + 2] = S[i + 2] == '0' ? '1' : '0';
                r = i + 1;
            }
            ans.emplace_back(i, r);

            for(int j = i; j <= r; j++) {
                S[j] = S[j] == '0' ? '1' : '0';
            }
        } 
    }

    std::map<std::string, std::vector<std::pair<int, int>>> m;
    m["0000"] = {};
    m["1111"] = {{N - 4, N - 1}};
    m["1000"] = {{N - 4, N - 2}, {N - 3, N - 2}};
    m["0100"] = {{N - 3, N - 1}, {N - 2, N - 1}};
    m["0010"] = {{N - 4, N - 2}, {N - 4, N - 3}};
    m["0001"] = {{N - 3, N - 1}, {N - 3, N - 2}};
    
    m["1100"] = {{N - 4, N - 3}};
    m["0110"] = {{N - 3, N - 2}};
    m["0011"] = {{N - 2, N - 1}};

    m["1010"] = {{N - 3, N - 1}, {N - 2, N - 1}, {N - 4, N - 2}};
    m["0101"] = {{N - 4, N - 2}, {N - 4, N - 3}, {N - 3, N - 1}};
    m["1001"] = {{N - 4, N - 1}, {N - 3, N - 2}};

    m["1110"] = {{N - 4, N - 2}};
    m["0111"] = {{N - 3, N - 1}};
    m["1101"] = {{N - 4, N - 1}, {N - 4, N - 2}, {N - 4, N - 3}};
    m["1011"] = {{N - 4, N - 1}, {N - 3, N - 1}, {N - 2, N - 1}};

    std::string suf_s = S.substr(N - 4, 4);
    std::string suf_t = T.substr(N - 4, 4);
   
    std::vector<std::pair<int, int>> seq_s = m[suf_s];
    std::vector<std::pair<int, int>> seq_t = m[suf_t];

    for(int i = seq_s.size() - 1; i >= 0; i--) {
        ans.emplace_back(seq_s[i].first, seq_s[i].second);
    }
    

    for(int i = 0; i < seq_t.size(); i++) {
        ans.emplace_back(seq_t[i].first, seq_t[i].second);
    }

    int size = ans.size();
    assert(size <= N * 2);
    std::cout << size << '\n';
    for(int i = 0; i < size; i++) {
        std::cout << ans[i].first + 1 << ' ' << ans[i].second + 1 << '\n';
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
