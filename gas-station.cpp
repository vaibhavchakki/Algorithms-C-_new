//https://leetcode.com/problems/gas-station/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//        cout<<gas.size()<<endl;
        if(gas.size() == 0 || gas.size() != cost.size())
            return -1;
        int i,j;
        for(i = 0; i < gas.size(); i++)
        {
            if(gas[i] >= cost[i])
            {
                int res = gas[i];
                for(j = i+1; j < gas.size(); j++)
                {
                    res = res - cost[j-1];
                    if(res < 0)
                        break;
                    else
                        res += gas[j];
                    //cout<<res<<' ';
                }
                if(res >= 0)
                    for(j = 0; j <= i; j++)
                    {
                        if(j == 0)
                            res = res - cost[cost.size()-1];
                        else
                            res = res - cost[j-1];
                        if(res < 0)
                            break;
                        else if(i!=j)
                            res +=gas[j];
                        //cout<<res<<' ';
                    }
                //cout<<endl;
                if(res >= 0)
                    return i;
            }
        }
        return -1;
    }
};

/*Runtime: 8 ms, faster than 93.30% of C++ online submissions for Gas Station.
Memory Usage: 9 MB, less than 68.97% of C++ online submissions for Gas Station.
This will take O(n) Time and O(1) Space Complexity.
Approach
We check form last station
if res >=0 then we check upto last
else our station becomes 2nd last
continue the above steps upto n times
if we get res >= 0 then return i
else -1*/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int i = gas.size()-1, j = 0;
        int res = gas[i] - cost[i];//checking from last index
        
        while(i > j)
        {
            if(res > -1)//check upto the station i
            {
                res += gas[j] - cost[j];
                j++;
            }
            else //previous station
            {
                i--;
                res += gas[i] - cost[i];
            }
        }
        return res >= 0 ? i : -1;
    }
};

/*Runtime: 8 ms, faster than 93.30% of C++ online submissions for Gas Station.
Memory Usage: 9.2 MB, less than 9.69% of C++ online submissions for Gas Station.
This code will take O(n) Time and O(1) Space Complexity
Approach
If the sum of gas and cost >=0 there exits a ans
the index is min ( sum (value >= 0))+1
else return -1*/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int res = 0, subres = INT_MAX, index;
        for(int i = 0; i < gas.size(); i++)
        {
            res +=gas[i] - cost[i];//add
            if(res < subres) //small res
            {
                subres = res;
                index = i + 1;
            }
        }
        return res >= 0 ? (index % gas.size()) : -1; //when index > gas.size() that time index%gas.size()
    }
};
