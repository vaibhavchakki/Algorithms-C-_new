/* https://leetcode.com/problems/reorganize-string */

class Solution {
public:
    string reorganizeString(string S) {
        
        map<char, int> strMap;
        for (auto &s: S) {strMap[s]++;}
        
        auto cmp = [] (const pair<char, int>& lhs, const pair<char, int>& rhs) 
        {
            return (lhs.second < rhs.second);
        };
        priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(cmp)> pq(cmp);
        
        for(auto& m: strMap) {
            pq.push(make_pair(m.first, m.second));
        }
        
        string res ="";
        char prev = ' ';
        
        while (!pq.empty()) {
            auto top = pq.top(); pq.pop();
            if (top.first != prev) {
                res.push_back(top.first);
                top.second--;
                prev = top.first;
                if (top.second > 0) {
                    pq.push(top);
                }
            }
            else {
                if (pq.empty()) {return string(""); }
                auto next_top = pq.top(); pq.pop();
                pq.push(top);
                res.push_back(next_top.first);
                next_top.second--;
                prev = next_top.first;
                if (next_top.second) { pq.push(next_top); }
            }
        }
        
        return res;
    }
};
