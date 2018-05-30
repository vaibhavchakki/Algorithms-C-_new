/**

	Given a collection of intervals, merge all overlapping intervals.

	Example 1:

	Input: [[1,3],[2,6],[8,10],[15,18]]
	Output: [[1,6],[8,10],[15,18]]
	Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
	Example 2:

	Input: [[1,4],[4,5]]
	Output: [[1,5]]
	Explanation: Intervals [1,4] and [4,5] are considerred overlapping
	
	https://leetcode.com/problems/merge-intervals/description/

 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> result;
        
        if (intervals.size() < 2) {
            return intervals;
        }
        
        sort(intervals.begin(), intervals.end(), [](const Interval& l, const Interval& r) {return l.start < r.start;});
        
        for (int i = 0; i < intervals.size(); i++) {
            int merged = false;
            for (int j = 0; j < result.size(); j++) {
                if (result[j].end >= intervals[i].start) {
                    result[j].end = max(intervals[i].end, result[j].end);
                    merged = true;
                    break;
                }
            }
            
            if (merged == false) {
                result.push_back(intervals[i]);
            }
        }
        
        return result;
    }
};