/* https://leetcode.com/problems/top-k-frequent-words/ */

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> res;
               
        auto comp = [](const pair<int, string>& lhs, const pair<int, string>& rhs) {
            if (lhs.first == rhs.first) {
                return (lhs.second > rhs.second);
            }
            else {
                return (lhs.first < rhs.first);
            }
        };
        
        map<string, int> countWords;
        for (auto& s: words) {
            countWords[s]++;
        }
        
        k = (countWords.size() < k) ? countWords.size() : k;
        
        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(comp)> pq(comp);
        
        for (auto& m: countWords) {
            pq.push(make_pair(m.second, m.first));
        }
        
        for(int i = 0; i < k; i++) {
            auto r = pq.top(); pq.pop();
            res.push_back(r.second);
        }

        return res;
    }
};
