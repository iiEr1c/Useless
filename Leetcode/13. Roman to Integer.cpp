class Solution {
public:
    int romanToInt(string s) {
        auto sum = 0;
        auto pre = getVal(s.at(0));
        for(int i = 1; i < s.length(); ++i)
        {
            auto cur = getVal(s.at(i));
            sum = (pre < cur) ? (sum - pre) : (sum + pre);
            pre = cur;
        }
        sum += pre;
        return sum;
    }
    inline int getVal(char ch)
    {
        switch(ch)
        {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }
};
