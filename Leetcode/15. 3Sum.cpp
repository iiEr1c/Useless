class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        auto size = nums.size();
        if(size < 3)
            return vector<vector<int>>{};
        std::sort(nums.begin(), nums.end());
        auto cbegin = nums.cbegin();
        auto begin = cbegin;
        auto end   = nums.cend();
        vector<vector<int>>ans = {};
        while(begin != end)
        {
            auto val_begin = *begin;
            if(val_begin > 0)
                return ans;
            if(begin > cbegin && *prev(begin, 1) == val_begin)
            {
                ++begin;
                continue;
            }
            auto left = next(begin, 1);
            auto right = prev(end, 1);
            while(left < right)
            {
                auto val_left = *left;
                auto val_right = *right;
                auto sum = val_begin + val_left + val_right;
                if(sum > 0)
                    --right;
                else if(sum < 0)
                    ++left;
                else
                {
                    ans.emplace_back(vector<int>{val_begin, val_left, val_right});
                    while(left != right && *left == *next(left, 1))
                        ++left;
                    while(left != right && *right == *prev(right, 1))
                        --right;
                    ++left;
                    --right;
                }
            }
            ++begin;
        }
        return ans;
    }
};
