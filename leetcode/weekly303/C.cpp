#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

class FoodRatings {
public:
    unordered_map<string, pair<string, int>> m;
    unordered_map<string, map<int, set<string>>> im;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for(int i = 0; i < n; i++) {
            string s = foods[i];
            string t = cuisines[i];
            int r = ratings[i];
            
            m[s] = make_pair(t, r);
            im[t][r].insert(s);
        }
    }
    
    void changeRating(string food, int newRating) {
        string t = m[food].first;
        int r = m[food].second;
        
        im[t][r].erase(food);
        if(im[t][r].empty()) {
            im[t].erase(r);
        }

        m[food].second = newRating;
        im[t][newRating].insert(food);
    }
    
    string highestRated(string cuisine) {
        return *(im[cuisine].rbegin()->second.begin());
    }
};
