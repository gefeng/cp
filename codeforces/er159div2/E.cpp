#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

struct node {
    std::array<node*, 26> a = {nullptr};
    int cnt = 0;
};

void insert(node* root, std::string& s) {
    int n = s.size();
    node* p = root;
    p->cnt += 1;
    for(int i = 0; i < n; i++) {
        int c = s[i] - 'a';
        if(p->a[c] == nullptr) {
            p->a[c] = new node();
        }
        p = p->a[c];
        p->cnt += 1;
    }
}

int64_t query1(node* root, std::string& s) {
    int n = s.size();
    node* p = root;
    int64_t res = 0;
    for(int i = n - 1; i >= 0; i--) {
        int c = s[i] - 'a';
        int64_t d = 0;
        if(p->a[c] != nullptr) {
            d = p->cnt - p->a[c]->cnt;
            res += d * (i + 1);
            p = p->a[c];
        } else {
            d = p->cnt;
            res += d * (i + 1);
            break;
        }
    }
    return res;
}

int64_t query2(node* root, std::string& s) {
    int n = s.size();
    node* p = root;
    int64_t res = 0;
    for(int i = 0; i < n; i++) {
        int c = s[i] - 'a'; 
        int64_t d = 0;
        if(p->a[c] != nullptr) {
            d = p->cnt - p->a[c]->cnt;
            res += d * (n - i);
            p = p->a[c];
        } else {
            d = p->cnt;
            res += d * (n - i);
            break;
        }
    } 
    return res;
}

void remove(node* root) {
    for(int i = 0; i < 26; i++) {
        if(root->a[i] != nullptr) {
            remove(root->a[i]); 
        }
    }
    delete root;
}

void run_case() {
    int N;
    std::cin >> N;

    std::vector<std::string> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int64_t ans = 0;
    node* root = new node();
    for(int i = 0; i < N; i++) {
        insert(root, A[i]);    
    }

    for(int i = 0; i < N; i++) {
        ans += query1(root, A[i]);
    } 

    remove(root);

    root = new node();
    for(int i = 0; i < N; i++) {
        std::reverse(A[i].begin(), A[i].end());
        insert(root, A[i]);
    } 

    for(int i = 0; i < N; i++) {
        std::reverse(A[i].begin(), A[i].end());
        ans += query2(root, A[i]);
    } 

    remove(root);

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
