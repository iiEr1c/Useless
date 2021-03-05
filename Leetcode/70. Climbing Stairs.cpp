class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2)
            return n;
        int cur_sub_1 = 2;
        int cur_sub_2 = 1;
        int ret;
        for(int i = 3; i <= n; ++i)
        {
            ret = cur_sub_2 + cur_sub_1;
            cur_sub_2 = cur_sub_1;
            cur_sub_1 = ret;
        }
        return ret;
    }
};
