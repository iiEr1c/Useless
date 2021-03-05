class Solution {
public:
    int maxArea(vector<int>& height) {
        auto beg = height.cbegin();
        auto end = height.cend();
        int size = height.size();
        --size;
        --end;
        int maxCap = 0;
        while(beg != end)
        {
            maxCap = max(min(*beg, *end) * size, maxCap);
            if(*beg < *end)
                ++beg;
            else
                --end;
            --size;
        }
        return maxCap;
    }
};
