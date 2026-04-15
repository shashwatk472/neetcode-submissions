class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2)
        return n;
        int p1 = 1, p2 = 2;
        for(int i = 3; i <= n; i++)
        {
            int t = p2;
            p2 += p1;
            p1 = t;
        }

        return p2;
    }
};
