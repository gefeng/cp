#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void dfs(std::string& S, std::array<int, 26>& freq, std::vector<std::vector<int>>& pos, int cnt_odd, int p, std::string& ans) {
    if(cnt_odd == 2) {
        return;
    } 

    for(int i = 0; i < 26; i++) {
        if(freq[i] == 0) {
            continue;
        }
        
        auto it = std::lower_bound(pos[i].begin(), pos[i].end(), p);
        if(it == pos[i].end()) {
            continue;
        }
        
        int nxt = *it;
        int cnt = 0;
        int which = -1;
        for(int j = 0; j < 26; j++) {
            if(freq[j] && pos[j].back() > nxt) {
                cnt += 1; 
                which = j;
            }
        }

        if(cnt > 1) {
            freq[i] -= 1;
            if(freq[i] % 2 == 1) {
                cnt_odd += 1;
            } else {
                cnt_odd -= 1;
            }
            ans.push_back(char(i + 'a'));
            dfs(S, freq, pos, cnt_odd, nxt + 1, ans);
            return;
        }
        
        if((freq[i] % 2 == 0 && cnt_odd == 1) || (which != -1 && which != i && freq[i] % 2 == 0)) {
            freq[i] -= 1;
            cnt_odd += 1;
            ans.push_back(char(i + 'a'));
            dfs(S, freq, pos, cnt_odd, nxt + 1, ans);
            return;
        }
    }
}

void run_case() {
    int N;
    std::cin >> N;

    std::string S;
    std::cin >> S;

    std::array<int, 26> freq = {};
    std::vector<std::vector<int>> pos(26);
    for(int i = 0; i < N; i++) {
        freq[S[i] - 'a'] += 1;
        pos[S[i] - 'a'].push_back(i);
    }

    int cnt_odd = 0;
    int cnt_occ = 0;
    for(int i = 0; i < 26; i++) {
        cnt_odd += freq[i] % 2; 
        if(freq[i]) {
            cnt_occ += 1;
        }
    }

    if(cnt_occ == 1) {
        std::cout << -1 << '\n';
        return;
    }

    if(cnt_odd > 1) {
        std::cout << 0 << '\n';
        return;
    }

    std::string ans = "";
    dfs(S, freq, pos, cnt_odd, 0, ans);

    int size = ans.size();
    std::cout << size << '\n' << ans << '\n';
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
