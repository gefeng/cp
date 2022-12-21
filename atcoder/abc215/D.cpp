#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

using namespace std;

void run_case() {
    int N, M;
    cin >> N >> M;

    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    set<int> s;
    for(int i = 0; i < N; i++) {
        int x = A[i];
        for(int f = 2; f * f <= x; f++) {
            if(x % f == 0) {
                s.insert(f);
            }
            while(x % f == 0) {
                x /= f;
            }
        }
        if(x > 1) {
            s.insert(x);
        }
    }

    vector<int> ans;
    ans.push_back(1);
    for(int i = 2; i <= M; i++) {
        bool ok = true;
        int x = i;
        for(int f = 2; f * f <= x; f++) {
            if(x % f == 0) {
                if(s.find(f) != s.end()) {
                    ok = false;
                    break;
                }
            }
            while(x % f == 0) {
                x /= f;
            }
        }
        if(x > 1 && s.find(x) != s.end()) {
            ok = false; 
        }

        if(ok) {
            ans.push_back(i);
        }
    }

    int n = ans.size();
    cout << n << '\n';
    for(int x : ans) {
        cout << x << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
