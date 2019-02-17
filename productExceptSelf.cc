/* https://leetcode.com/problems/product-of-array-except-self */

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> temp = {1};
        for(int i=1;i<nums.size();i++){
            temp.push_back(temp.back()*nums[i-1]);
        }
        
        for (auto& t : temp) { cout << t << " ";}
        cout << endl;
        
        vector<int> temp2 = {1}; // create a new vector for answer
        
        for(int i=temp.size()-2;i>=0;i--){
            temp2.push_back(temp2.back()*nums[i+1]);
        }
        
        for(auto& t: temp2) { cout << t << " ";}  
        cout << endl;
        
        reverse(temp2.begin(),temp2.end());
        
        for(int i=0;i<temp.size();i++){
            temp[i] = temp[i]*temp2[i];
        }
        for (auto& t : temp) { cout << t << " ";}
        cout << endl;        
        
        return temp;
    }
};
