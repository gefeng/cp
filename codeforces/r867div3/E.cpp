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

    if(N & 1) {
        std::cout << -1 << '\n';
        return;
    }
    
    std::array<std::vector<int>, 26> cnt;
    for(int i = 0; i < N / 2; i++) {
        if(S[i] == S[N - i - 1]) {
            cnt[S[i] - 'a'].push_back(i);
        } 
    }

    int ans = 0;
    while(true) {
        int max1 = 0;
        int max2 = 0;
        int c1 = 0;
        int c2 = 0;
        for(int i = 0; i < 26; i++) {
            if(cnt[i].size() > max1) {
                max2 = max1;
                max1 = cnt[i].size();
                c2 = c1;
                c1 = i;
            } else if(cnt[i].size() > max2) {
                max2 = cnt[i].size();
                c2 = i;
            }
        }

        if(max2 == 0) {
            break;
        }

        int p1 = cnt[c1].back();
        int p2 = cnt[c2].back();
        cnt[c1].pop_back();
        cnt[c2].pop_back();
        std::swap(S[p1], S[p2]);
        ans += 1;
    }
    /*for(int i = 0; i < 26; i++) {
        while(true) {
            if(cnt[i].empty()) {
                break;
            }
            int p1 = cnt[i].back();
            int p2 = -1;
            for(int j = 0; j < 26; j++) {
                if(i != j && cnt[j].size()) {
                    p2 = cnt[j].back();
                    cnt[j].pop_back();
                    cnt[i].pop_back();
                    std::swap(S[p1], S[p2]);
                    ans += 1;
                    break;
                }
            }
            if(p2 == -1) {
                break;
            }
        }
    }*/

    int c = -1;
    int left = 0;
    for(int i = 0; i < 26; i++) {
        if(cnt[i].size()) {
            c = i; 
            left = cnt[i].size();
        }
    }

    if(c != -1) {
        for(int i = 0; i < N / 2 && left; i++) {
            if(S[i] - 'a' != c && S[N - i - 1] - 'a' != c) {
                left -= 1;
                ans += 1;
            }
        }

        if(left != 0) {
            std::cout << -1 << '\n';
            return;
        }
    }

    std::cout << ans << '\n';
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
