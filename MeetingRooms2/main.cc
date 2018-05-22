/**
	Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.

	Example 1:

	Input: [[0, 30],[5, 10],[15, 20]]
	Output: 2
	Example 2:

	Input: [[7,10],[2,4]]
	Output: 
	
	https://leetcode.com/problems/meeting-rooms-ii/description/

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
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<vector<Interval>> schedule;
        
        sort(intervals.begin(), intervals.end(), [](const Interval& l, const Interval& r) {return l.start < r.start;});
        
        for (auto &i : intervals) {
            if (schedule.size() > 0) {
                bool scheduled = false;
                for (auto &s: schedule) {
                    Interval j = s.back();
                    if (j.end <= i.start) {
                        scheduled = true;
                        s.push_back(i);
                        break;
                    }
                }
                
                if (!scheduled) {
                    schedule.push_back({i});
                }
                
            }
            else {
                schedule.push_back({i});
            }
        }
        
        return schedule.size();
    }
};