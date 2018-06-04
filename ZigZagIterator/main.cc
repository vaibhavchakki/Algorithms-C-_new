/*
 Given two 1d vectors, implement an iterator to return their elements alternately.

	Example:

	Input:
	v1 = [1,2]
	v2 = [3,4,5,6] 

	Output: [1,3,2,4,5,6]

	Explanation: By calling next repeatedly until hasNext returns false, 
				 the order of elements returned by next should be: [1,3,2,4,5,6].
	Follow up: What if you are given k 1d vectors? How well can your code be extended to such cases?

	Clarification for the follow up question:
	The "Zigzag" order is not clearly defined and is ambiguous for k > 2 cases. If "Zigzag" does not look right to you, replace "Zigzag" with "Cyclic". For example:

	Input:
	[1,2,3]
	[4,5,6,7]
	[8,9]

	Output: [1,4,8,2,5,9,3,6,7].
	
	https://leetcode.com/problems/zigzag-iterator/description/
	
	*/


class ZigzagIterator {
    vector<int> i;
    vector<int> imax;
    int curr;
    int k;
    vector<vector<int>> v;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        k = 2;
        i.assign({0, 0});
        imax.assign({v1.size(), v2.size()});
        curr = 0;
        v.assign({v1, v2});
    }

    int next() {
        bool exist = false;
        while (1) {
            int elem;
            if (i[curr] < imax[curr]) {
                elem = v[curr][i[curr]];
                i[curr]++;
                exist = true;
            }
            curr++;
            curr = curr % k;
            
            if (exist) {
                return elem;
            }
        }
    }

    bool hasNext() {
        return (i[0] < imax[0]) || (i[1] < imax[1]);
    }
};