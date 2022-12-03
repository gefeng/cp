#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int N;
    cin >> N;

    string S;
    cin >> S;

    vector<int> l(N + 1, -1);
    vector<int> r(N + 1, -1);
    
    for(int i = 1; i <= N; i++) {
        if(S[i - 1] == 'L') {
            if(l[i - 1] != -1) {
                int pre = l[i - 1];
                r[pre] = i;
                l[i] = pre;
            }
            l[i - 1] = i;
            r[i] = i - 1;
        } else {
            if(r[i - 1] != -1) {
                int nxt = r[i - 1];
                l[nxt] = i;
                r[i] = nxt;
            }
            r[i - 1] = i;
            l[i] = i - 1;
        }
    }

    vector<int> ans_1;
    vector<int> ans_2;
    for(int i = 0; i != -1; i = l[i]) {
        ans_1.push_back(i);
    } 

    for(int i = 0; i != -1; i = r[i]) {
        ans_2.push_back(i);
    }
    
    reverse(ans_1.begin(), ans_1.end());
    
    for(int i = 0; i < ans_1.size(); i++) {
        cout << ans_1[i] << ' ';
    }

    for(int i = 1; i < ans_2.size(); i++) {
        cout << ans_2[i] << ' '; 
    }

    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
