class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())
            return string{};
        sort(strs.begin(), strs.end());
        auto first_ele = *strs.cbegin();
        auto end_ele   = *(--strs.cend());
        auto minLen = min(first_ele.length(), end_ele.length());
        auto i = 0;
        auto beg1 = first_ele.cbegin();
        auto beg2 = end_ele.cbegin();
        while(i < minLen && *beg1 == *beg2)
        {
            ++i;
            ++beg1;
            ++beg2;
        }
        return first_ele.substr(0, i);
    }
};