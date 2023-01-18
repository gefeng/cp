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
    string S;
    cin >> S;

    vector<char> s;
    map<char, int> m;
    
    for(char c : S) {
        if(c == '(') {
            s.push_back(c);
        } else if(c == ')') {
            while(s.back() != '(') {
                char x = s.back();
                s.pop_back();

                if(--m[x] == 0) {
                    m.erase(x);
                }
            } 

            s.pop_back();
        } else {
            if(m.find(c) != m.end()) {
                cout << "No" << '\n';
                return;
            }

            m[c] += 1;

            s.push_back(c);
        }
    }

    cout << "Yes" << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
