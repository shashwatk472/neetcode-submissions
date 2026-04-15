/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> arr(1e6 + 1, 0);
        int n = intervals.size();
        for(int i = 0; i < n; i++)
        {
            arr[intervals[i].start]++;
            arr[intervals[i].end]--;
        }
        int ans = 0;
        for(int i = 0; i < arr.size(); i++)
        {   
            if(i != 0)
                arr[i] += arr[i-1];
            ans = max(ans, arr[i]);
        }

        return ans;
            
            

    }
};
