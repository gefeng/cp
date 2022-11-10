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
    string S;
    cin >> S;
    
    set<char> seen;
    int mask = 0;
    for(char c : S) {
        seen.insert(c);

        if(c >= 'a' && c <= 'z') {
            mask |= 1;
        } 
        if(c >= 'A' && c <= 'Z') {
            mask |= 2;
        }
    }

    if(mask == 3 && seen.size() == S.length()) {
        cout << "Yes" << '\n';
    } else {
        cout << "No" << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
