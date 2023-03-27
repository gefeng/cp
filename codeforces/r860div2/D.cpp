#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using LL = long long;

constexpr int INF = (int)2e9;

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> pos;
    std::vector<int> neg;
    int max_v = -INF;
    int min_v = INF;
    for(int i = 0; i < N; i++) {
        int X;
        std::cin >> X;

        if(X >= 0) {
            pos.push_back(X);
        } else {
            neg.push_back(X);
        }

        max_v = std::max(max_v, X);
        min_v = std::min(min_v, X);
    }

    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());

    std::vector<int> ans;
    LL t = max_v - min_v;
    LL sum = 0LL;
    int m = pos.size();
    int n = neg.size();
    int i = 0;
    int j = 0;
    bool ok = true;
    while(i < m || j < n) {
        if(i == m) {
            sum += neg[j];
            ans.push_back(neg[j++]);
            if(abs(sum) >= t) {
                ok = false; 
                break;
            }
        } else if(j == n) {
            sum += pos[i];
            ans.push_back(pos[i++]);
            if(abs(sum) >= t) {
                ok = false;
                break;
            }
        } else {
            if(abs(sum + pos[i]) < t) {
                sum += pos[i];
                ans.push_back(pos[i++]);
            } else if(abs(sum + neg[j]) < t) {
                sum += neg[j];
                ans.push_back(neg[j++]);
            } else {
                ok = false;
                break;
            }
        }
    }

    if(ok) {
        std::cout << "YES" << '\n';
        for(int i = 0; i < N; i++) {
            std::cout << ans[i] << " \n"[i == N - 1];
        }
        return;
    }

    reverse(pos.begin(), pos.end());
    reverse(neg.begin(), neg.end());
    i = 0;
    j = 0;
    sum = 0LL;
    ok = true;
    ans = std::vector<int>();
    while(i < m || j < n) {
        if(i == m) {
            sum += neg[j];
            ans.push_back(neg[j++]);
            if(abs(sum) >= t) {
                ok = false; 
                break;
            }
        } else if(j == n) {
            sum += pos[i];
            ans.push_back(pos[i++]);
            if(abs(sum) >= t) {
                ok = false;
                break;
            }
        } else {
            if(abs(sum + neg[j]) < t) {
                sum += neg[j];
                ans.push_back(neg[j++]);
            } else if(abs(sum + pos[i]) < t) {
                sum += pos[i];
                ans.push_back(pos[i++]);
            } else {
                ok = false;
                break;
            }
        }
    }

    if(ok) {
        std::cout << "YES" << '\n';
        for(int i = 0; i < N; i++) {
            std::cout << ans[i] << " \n"[i == N - 1];
        }
        return;
    }

    std::cout << "NO" << '\n';
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
