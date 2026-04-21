class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> m;
        set<vector<int>> s;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++)
            m[nums[i]] = i;
        for(int i = 0 ; i < n - 1; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                int x = nums[i] + nums[j];
                if(m.count(-x) > 0 && m[-x] > j)
                    s.insert({nums[i], nums[j], -x});
            }
        }

        return vector<vector<int>> (s.begin(), s.end());
    }
};
