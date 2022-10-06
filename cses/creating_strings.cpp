#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>

using namespace std;

void dfs(string& S, int can, string& cur, set<string>& ans) {
    int n = S.length();

    if(can == 0) {
        ans.insert(cur);
        return;
    }
    
    for(int i = 0; i < n; i++) {
        if(can & (1 << i)) {
            cur.push_back(S[i]);
            dfs(S, can ^ (1 << i), cur, ans);
            cur.pop_back();
        }
    }
}

void run_case() {
    string S;
    cin >> S;

    int n = S.length();
    set<string> ans;
    
    sort(S.begin(), S.end());

    string cur = "";
    dfs(S, (1 << n) - 1, cur, ans); 

    int tot = ans.size();
    cout << tot << '\n';
    for(string s : ans) {
        cout << s << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
