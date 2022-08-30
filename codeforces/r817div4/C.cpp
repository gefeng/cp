#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <vector>
#include <unordered_set>

using namespace std;

void run_case() {
    int N;
    cin >> N;

    vector<unordered_set<string>> A(3, unordered_set<string>());
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < N; j++) {
            string S;
            cin >> S;
            A[i].insert(S);
        }
    }

    array<int, 3> ans{0};
    for(int i = 0; i < 3; i++) {
        for(string s : A[i]) {
            int cnt = 1;
            for(int j = 0; j < 3; j++) {
                if(i != j && A[j].find(s) != A[j].end()) {
                    cnt++;
                }
            }

            if(cnt == 1) {
                ans[i] += 3;
            }
            if(cnt == 2) {
                ans[i] += 1;    
            }
        }
    }

    cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    while(T--) {
        run_case();
    }
}
