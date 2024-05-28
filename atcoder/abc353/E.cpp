#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

struct node {
    std::vector<node*> c = std::vector<node*>(26, nullptr);
    int cnt = 0;
};

void run_case() {
    int N;
    std::cin >> N;

    std::vector<std::string> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    node* root = new node();

    int64_t ans = 0;
    for(auto& s : A) {
        int n = s.size();
        node* v = root;;
        
        int pre = 0;
        bool end = false;
        for(int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            if(v->c[c] == nullptr) {
                ans += (int64_t)i * pre;
                end = true;
                break;
            }

            v = v->c[c];
            int cnt = v->cnt;
            
            if(cnt < pre) {
                ans += (int64_t)i * (pre - cnt);
            }
            pre = cnt;
        }

        if(!end) {
            ans += (int64_t)pre * n;
        }

        v = root;
        for(int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            if(v->c[c] == nullptr) {
                v->c[c] = new node(); 
            }
            v = v->c[c];
            v->cnt += 1;
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
