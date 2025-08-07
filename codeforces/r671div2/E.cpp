#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>

int gcd(int a, int b) {
    if(a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<int> div;
    std::vector<int> pf;
    div.push_back(N);
    for(int f = 2; f * f <= N; f++) {
        if(N % f == 0) {
            div.push_back(f);
            if(N / f != f) {
                div.push_back(N / f);
            }
        }
    }

    {
        int x = N;
        for(int f = 2; f * f <= x; f++) {
            if(x % f == 0) {
                pf.push_back(f);
                while(x % f == 0) {
                    x /= f;
                }
            } 
        }
        if(x > 1) {
            pf.push_back(x);
        }
    }

    std::ranges::sort(div);
    std::ranges::sort(pf);

    int n = div.size();
    int m = pf.size();
    std::vector<int> picked(n, 0);
    std::vector<int> last;
    std::vector<int> ans;
    int cnt = 0;

    for(int i = 0; i < m; i++) {
        int x = pf[i] * pf[(i + 1) % m];
        for(int j = 0; j < n; j++) {
            if(div[j] == pf[i]) {
                picked[j] = 1;
            }
            if(div[j] == x && !picked[j]) {
                last.push_back(div[j]);
                picked[j] = 1;
            }
        } 
        if(last.size() != i + 1) {
            int x = pf[i] * pf[(i + 1) % m];
            for(int j = 0; j < n; j++) {
                if(div[j] % x == 0 && !picked[j]) {
                    last.push_back(div[j]);
                    picked[j] = 1;
                    break;
                }
            } 
        }
    }

    if(last.size() == m) {
        for(int i = 0; i < m; i++) {
            ans.push_back(pf[i]);
            for(int k = 0; k < n; k++) {
                if(!picked[k] && div[k] % pf[i] == 0) {
                    picked[k] = 1;
                    ans.push_back(div[k]);
                }
            }
            ans.push_back(last[i]);
        } 
    } else {
        cnt = m - last.size();
        for(int i = 0, j = 0; i < m; i++) {
            ans.push_back(pf[i]);
            for(int k = 0; k < n; k++) {
                if(!picked[k] && div[k] % pf[i] == 0) {
                    picked[k] = 1;
                    ans.push_back(div[k]);
                }
            }
            if(j < last.size()) {
                ans.push_back(last[j++]);
            }
        } 
    }

    int size = ans.size();
    for(int i = 0; i < size; i++) {
        std::cout << ans[i] << " \n"[i == size - 1];
    }
    std::cout << cnt << '\n';
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
