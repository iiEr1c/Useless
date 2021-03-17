class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        const auto size = nums.size();
        if(size < 4)
            return vector<vector<int>>{};
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans{};
        auto begin = nums.cbegin();
        auto _begin = begin;
        auto end   = nums.cend();
        for(; begin != prev(end, 3); ++begin)
        {  
            if(begin > _begin && *begin == *prev(begin, 1))
                continue;
            if(*begin + *next(begin, 1) + *next(begin, 2) + *next(begin, 3) > target)
                break;
            if(*begin + *prev(end, 1) + *prev(end, 2) + *prev(end, 3) < target)
                continue;
            auto beg = next(begin, 1);
            auto _beg = beg;
            for(; beg != prev(end, 2); ++beg)
            {
                if(beg > _beg && *beg == *prev(beg, 1))
                    continue;
                if(*begin + *beg + *next(beg, 1) + *next(beg, 2) > target)
                    break;
                if(*begin + *beg + *prev(end, 1) + *prev(end, 2) < target)
                    continue;
                auto left = next(beg, 1);
                auto right = prev(end, 1);
                while(left < right)
                {
                    auto sum = *begin + *beg + *left + *right;
                    if(sum == target)
                    {
                        ans.push_back({*begin, *beg, *left, *right});
                        auto val = *left++;
                        while(left < right && *left == val)
                            ++left;
                        val = *right--;
                        while(left < right && *right == val)
                            --right;
                    }
                    else if(sum < target)
                    {
                        auto val = *left++;
                        while(left < right && *left == val)
                            ++left;
                    }
                    else
                    {
                        auto val = *right--;
                        while(left < right && *right == val)
                            --right;
                    }
                }
            }
        }

        return ans;      
    }
};