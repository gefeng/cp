#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

using namespace std;

void run_case() {
    int N;
    cin >> N;
    
    string S;
    cin >> S;

    map<string, int> m;
    for(int i = 0; i < N - 1; i++) {
        string t = "";
        t.push_back(S[i]);
        t.push_back(S[i + 1]);
        
        if(m.find(t) != m.end()) {
            if(m[t] < i - 1) {
                cout << "Yes" << '\n';
                return;
            }
        } else {
            m[t] = i;
        }
    }

    cout << "No" << '\n';
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
