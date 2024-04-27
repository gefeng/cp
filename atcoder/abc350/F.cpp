#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

char do_flip(char c) {
    if(c >= 'a' && c <= 'z') {
        return c - 'a' + 'A';
    }
    return c - 'A' + 'a';
}

void dfs(std::string& S, std::vector<int>& match, int l, int r, int flip, std::string& ans) {
    if(l > r) {
        return;
    }
    if(l == r) {
        ans.push_back(flip ? do_flip(S[l]) : S[l]);
        return;
    }

    if(flip) {
        for(int i = r; i >= l; i--) {
            if(match[i] == -1) {
                ans.push_back(flip ? do_flip(S[i]) : S[i]);
            } else {
                dfs(S, match, match[i] + 1, i - 1, flip ^ 1, ans);
                i = match[i];
            }
        }
    } else {
        for(int i = l; i <= r; i++) {
            if(match[i] == -1) {
                ans.push_back(flip ? do_flip(S[i]) : S[i]);
            } else {
                dfs(S, match, i + 1, match[i] - 1, flip ^ 1, ans);
                i = match[i];
            }
        }
    }
}

void run_case() {
    std::string S;
    std::cin >> S;

    int n = S.size();
    std::vector<int> match(n, -1);
    std::vector<int> s; 
    for(int i = 0; i < n; i++) {
        if(S[i] == ')') {
            while(S[s.back()] != '(') {
                s.pop_back();
            }
            match[s.back()] = i;
            match[i] = s.back(); 
            s.pop_back();
        } else {
            s.push_back(i);
        }
    }

    std::string ans = "";
    dfs(S, match, 0, n - 1, 0, ans);
    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
