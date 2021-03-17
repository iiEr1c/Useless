class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        const auto size = nums.size();
        sort(nums.begin(), nums.end());
        auto t = nums.begin();
        nums.insert(t, *t + 1);        // add dummy node
        auto begin = ++nums.cbegin();
        auto end = nums.cend();
        auto best = 1e7;
        for(; begin != end; ++begin)
        {
            if(*prev(begin, 1) == *begin)
                continue;
            auto left = next(begin, 1);
            auto right = prev(end, 1);
            while(left < right)
            {
                auto sum = *begin + *left + *right;
                if(sum == target)
                    return target;
                best = abs(sum - target) < abs(best - target) ? sum : best;
                /*
                if(sum < target)
                {
                    auto val = *left++;
                    while(left < right && *left == val)
                        ++left;
                }

                if(sum > target)
                {
                    auto val = *right--;
                    while(left < right && *right == val)
                        --right;
                }
                */
                if(sum < target)
                    left = std::find_if_not(left, right, [val = *left](const int &t){
                        return val == t;
                    });
                if(sum > target)        // std::vector<int>::reverse_iterator比较麻烦
                {
                    auto val = *right--;
                    while(left < right && *right == val)
                        --right;
                }
            }
        }
        nums.erase(nums.begin());
        return best;
    }
};