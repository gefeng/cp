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
    int N;
    cin >> N;

    vector<int> A(N, 0);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    string S;
    cin >> S;

    for(int i = 1; i <= 50; i++) {
        bool ok = true;
        set<int> s;
        for(int j = 0; j < N; j++) {
            if(A[j] == i) {
                s.insert(S[j]); 
            }
        }
        ok = s.empty() || s.size() == 1;

        if(!ok) {
            cout << "NO" << '\n';
            return;
        }
    }

    cout << "YES" << '\n';
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
