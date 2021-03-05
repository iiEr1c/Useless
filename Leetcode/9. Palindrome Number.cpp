class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        if(x == 0)
            return true;
        std::deque<int>d = {};
        while(x)
        {
            d.push_back(x % 10);
            x /= 10;
        }
        auto beg = d.cbegin();
        auto end = d.cend();
        --end;
        while(beg <= end)
        {
            if(*beg != *end)
                return false;
            ++beg;
            --end;
        }

        return true;
    }
};
