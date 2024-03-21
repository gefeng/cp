#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

std::vector<int> manacher_odd(std::string s) {
    int n = s.size();
    s = "$" + s + "^";
    std::vector<int> p(n + 2);
    int l = 1, r = 1;
    for(int i = 1; i <= n; i++) {
        p[i] = std::max(0, std::min(r - i, p[l + (r - i)]));
        while(s[i - p[i]] == s[i + p[i]]) {
            p[i]++;
        }
        if(i + p[i] > r) {
            l = i - p[i], r = i + p[i];
        }
    }
    return p;
    //return std::vector<int>(begin(p) + 1, end(p) - 1);
}

std::vector<int> manacher(std::string s) {
    std::string t;
    for(auto c: s) {
        t += std::string("#") + c;
    }
    auto res = manacher_odd(t + "#");
    return std::vector<int>(begin(res) + 1, end(res) - 1);
}

void run_case() {
    int N, Q;
    std::cin >> N >> Q;

    std::string S;
    std::cin >> S;

    std::vector<std::vector<int>> eve(26, std::vector<int>(N + 1, 0));
    std::vector<std::vector<int>> odd(26, std::vector<int>(N + 1, 0));
    
    for(int i = 0; i < N; i++) {
        for(int c = 0; c < 26; c++) {
            if(c != S[i] - 'a') {
                eve[c][i + 1] = eve[c][i];
                odd[c][i + 1] = odd[c][i];
            } else {
                if(i % 2 == 0) {
                    eve[c][i + 1] = eve[c][i] + 1;
                    odd[c][i + 1] = odd[c][i];
                } else {
                    eve[c][i + 1] = eve[c][i];
                    odd[c][i + 1] = odd[c][i] + 1;
                }
            }
        }
    }

    std::vector<int> pal = manacher(S);

    for(int i = 0; i < Q; i++) {
        int L, R;
        std::cin >> L >> R;
        L -= 1;
        R -= 1;

        int64_t res = -1;
        for(int c = 0; c < 26; c++) {
            if(eve[c][R + 1] - eve[c][L] + odd[c][R + 1] - odd[c][L] == R - L + 1) {
                res = 0; 
                break;
            }
        } 

        if(R - L + 1 == 1) {
            res = 0;
        }

        if(res != -1) {
            std::cout << res << '\n';
            continue;
        }

        int c1 = S[L] - 'a';
        int c2 = S[L + 1] - 'a';
        int len = R - L + 1;
        if(L % 2 == 0) {
            int cnt_eve = eve[c1][R + 1] - eve[c1][L];
            int cnt_odd = odd[c2][R + 1] - odd[c2][L];
            if(cnt_eve == (len + 1) / 2 && cnt_odd == len / 2) {
                int last = len % 2 == 0 ? len : len - 1;
                res = (int64_t)(2 + last) * (last / 2) / 2;  
            } else {
                int p = (len * 2 + 1) / 2 + L * 2;
                int last = len;
                int d = len % 2 == 1 ? pal[p] / 2 * 2 - 1 : pal[p] / 2 * 2;
                if(d >= len) {
                    last -= 1; 
                }
                res = last < 2 ? 0 : (int64_t)(2 + last) * (last - 1) / 2;
            }
        } else {
            int cnt_eve = eve[c2][R + 1] - eve[c2][L];
            int cnt_odd = odd[c1][R + 1] - odd[c1][L];
            if(cnt_odd == (len + 1) / 2 && cnt_eve == len / 2) {
                int last = len % 2 == 0 ? len : len - 1;
                res = (int64_t)(2 + last) * (last / 2) / 2;  
            } else {
                int p = (len * 2 + 1) / 2 + L * 2;
                int last = len;
                int d = len % 2 == 1 ? pal[p] / 2 * 2 - 1 : pal[p] / 2 * 2;
                if(d >= len) {
                    last -= 1; 
                }
                res = last < 2 ? 0 : (int64_t)(2 + last) * (last - 1) / 2;
            }
        }

        std::cout << res << '\n';
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
