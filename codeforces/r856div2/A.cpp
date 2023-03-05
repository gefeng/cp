#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

using namespace std;

bool is_ok(string& s, vector<string>& A) {
    for(int l = 0, r = s.size() - 1; l < r; l += 1, r -= 1) {
        if(s[l] != s[r]) {
            return false;
        }
    }

    map<string, int> m;
    for(string& t : A) {
        m[t] += 1;
    } 

    for(int i = 1; i < s.size(); i++) {
        string prefix = s.substr(0, i);
        if(m.find(prefix) == m.end()) {
            return false;
        }
        if(--m[prefix] == 0) {
            m.erase(prefix);
        }

        string suffix = s.substr(s.size() - i, i);
        if(m.find(suffix) == m.end()) {
            return false;
        }
        if(--m[suffix] == 0) {
            m.erase(suffix);
        }
    }

    return true;
}

void run_case() {
    int N;
    cin >> N;

    string x = "";
    string y = "";
    vector<string> A(2 * N - 2);
    for(int i = 0; i < 2 * N - 2; i++) {
        cin >> A[i];
        if(A[i].size() == N - 1) {
            if(x.empty()) {
                x = A[i];
            } else {
                y = A[i];
            }
        }
    }

    string s = x;
    s.append(y.substr(y.size() - 1, 1));
    string t = y;
    t.append(x.substr(x.size() - 1, 1));
    if(is_ok(s, A) || is_ok(t, A)) {
        cout << "YES" << '\n';
        return;
    }

    cout << "NO" << '\n';    
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
