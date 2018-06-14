/*
	In a row of seats, 1 represents a person sitting in that seat, and 0 represents that the seat is empty. 

	There is at least one empty seat, and at least one person sitting.

	Alex wants to sit in the seat such that the distance between him and the closest person to him is maximized. 

	Return that maximum distance to closest person.

	Example 1:

	Input: [1,0,0,0,1,0,1]
	Output: 2
	Explanation: 
	If Alex sits in the second open seat (seats[2]), then the closest person has distance 2.
	If Alex sits in any other open seat, the closest person has distance 1.
	Thus, the maximum distance to the closest person is 2.
	Example 2:

	Input: [1,0,0,0]
	Output: 3
	Explanation: 
	If Alex sits in the last seat, the closest person is 3 seats away.
	This is the maximum distance possible, so the answer is 3.
	
	https://leetcode.com/problems/maximize-distance-to-closest-person/description/
	
	*/

class Solution {
public:
    
    void print(vector<int>& dist) {
        for (int i = 0; i < dist.size(); i++) {
            cout << dist[i] << " ";
        }
        cout << endl;
    }
    
    /*int maxDistToClosest(vector<int>& seats) {
        int maxDist = 0;
        
        vector<int> dist(seats.size(), INT_MAX);
        
        int start = 0;
        int validstart = 0;
        for (int i = 0; i < seats.size(); i++) {
            if (seats[i]) {
                dist[i] = 0;
                start = i;
                validstart = 1;
            }
            else {
                dist[i] = validstart ? min(dist[i], (i - start)) : dist[i];
            }
        }
        
        //print(dist);
        
        int end = seats.size() - 1;
        int validend = 0;
        for (int i = seats.size() - 1; i >= 0; i--) {
            if (seats[i]) {
                dist[i] = 0;
                end = i;
                validend = 1;
            }
            else {
                dist[i] = validend ? min(dist[i], (end - i)) : dist[i];
            }
        }
        
        //print(dist);
        
        for (int i = 0; i < dist.size(); i++) {
            maxDist = max(maxDist, dist[i]);
        }
        
        return maxDist;
    }*/
    
    int maxDistToClosest(vector<int>& seats) {
        int maxDist = 0;
        int dist     = 0;
        int lastSeat = -1;
        
        for (int i = 0; i < seats.size(); i++) {
            if (seats[i]) {
                int t = (lastSeat > -1) ? (i - lastSeat) / 2 : dist;
                maxDist = max(maxDist, t);
                dist = 0;
                lastSeat = i;
            }
            else {
                dist++;
            }
        }
        
        return max(maxDist, dist);
        
    }
};