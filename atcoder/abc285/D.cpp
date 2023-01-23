#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;

void run_case() {
    int N;
    cin >> N;
    
    map<string, vector<string>> G;
    map<string, int> deg;
    set<string> all;

    for(int i = 0; i < N; i++) {
        string S, T;
        cin >> S >> T;

        G[S].push_back(T);
        deg[T] += 1;

        all.insert(S);
        all.insert(T);
    }

    queue<string> q;
    for(const string& s : all) {
        if(deg.find(s) == deg.end()) {
            q.push(s);
        }
    } 

    int cnt = 0;
    while(!q.empty()) {
        string cur = q.front();
        q.pop();
        
        cnt += 1;

        for(string& nei : G[cur]) {
            if(--deg[nei] == 0) {
                q.push(nei);
                deg.erase(nei);
            }
        }
    }

    cout << (all.size() == cnt ? "Yes" : "No") << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
