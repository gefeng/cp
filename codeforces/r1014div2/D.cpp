#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int INF = int(1e9);

void run_case() {
    int N;
    std::cin >> N;

    std::string S;
    std::cin >> S;

    std::vector<int> a(N, 0);
    for(int i = 0; i < N; i++) {
        if(S[i] == 'I') {
            a[i] = 1;
        } else if(S[i] == 'T') {
            a[i] = 2;
        }
    }
    
    std::vector<int> ans;
    
    while(ans.size() < 2 * N) {
        std::vector<int> na;
        int n = a.size();
        std::array<int, 3> freq = {};
        for(int i = 0; i < n; i++) {
            freq[a[i]] += 1; 
        }

        if(freq[0] == freq[1] && freq[0] == freq[2]) {
            break;
        }

        int min_1 = INF;
        int min_2 = INF;
        int x = -1;
        int y = -1;
        for(int i = 0; i < 3; i++) {
            if(freq[i] < min_1) {
                min_2 = min_1;
                min_1 = freq[i];
                y = x;
                x = i;
            } else if(freq[i] < min_2) {
                min_2 = freq[i];
                y = i;
            }
        }

        int p = -1;
        for(int i = 0; i < n - 1; i++) {
            if(a[i] != a[i + 1] && a[i] != x && a[i + 1] != x) {
                p = i; 
                break;
            }
        }

        if(p != -1) {
            ans.push_back(p);
            for(int i = 0; i <= p; i++) {
                na.push_back(a[i]);
            }
            na.push_back(x);
            for(int i = p + 1; i < n; i++) {
                na.push_back(a[i]);
            }
            std::swap(a, na);
            continue;
        }
    
        for(int i = 0; i < n - 1; i++) {
            if(a[i] != a[i + 1] && a[i] != y && a[i + 1] != y) {
                p = i; 
                break;
            }
        }

        if(p != -1) {
            ans.push_back(p);
            for(int i = 0; i <= p; i++) {
                na.push_back(a[i]);
            }
            na.push_back(y);
            for(int i = p + 1; i < n; i++) {
                na.push_back(a[i]);
            }
            std::swap(a, na);
            continue;
        }

        std::cout << -1 << '\n';
        return;
    }

    std::array<int, 3> freq = {};
    for(int x : a) {
        freq[x] += 1;
    }

    if(freq[0] != freq[1] || freq[0] != freq[2] || freq[1] != freq[2]) {
        std::cout << -1 << '\n';
        return;
    }

    int k = ans.size();
    std::cout << k << '\n';
    for(int i = 0; i < k; i++) {
        std::cout << ans[i] + 1 << '\n';
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
