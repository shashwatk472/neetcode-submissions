class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> v(127, 0);
        int ans = 0;
        int n = s.size();
        for(int i = 0, j = 0; i < n; i++)
        {
            if(v[s[i] - ' '] == 1)
            {
                while(i > j && s[i] != s[j])
                {
                    v[s[j] - ' ']--;
                    j++;
                }
                j++;
            }
            else
            {
                v[s[i] - ' ']++;
                ans = max(ans, i - j + 1);
                // cout << i << " " << j << " " << ans << endl;
            }

        }

        return ans;
    }
};
