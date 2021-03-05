class Solution {
public:
    /*
    string longestPalindrome(string s) {
        const int len = s.length();
        bool dp[len];
        std::string str = "";
        for(int right = 0; right < len; ++right)
            for(int left = 0; left <= right; ++left)
            {
                auto step = right - left;
                bool isEqual = s.at(left) == s.at(right);
                switch(step)
                {
                    case 0: dp[left] = true;
                        break;
                    case 1: dp[left] = isEqual ? true : false;
                        break;
                    default: dp[left] = dp[left + 1] && isEqual;
                        break;
                }
                if(dp[left] && step >= str.length())
                    str = s.substr(left, step + 1);
            }
        return str;
    }
    */
    string longestPalindrome(string s) {
        const int len = s.length();
        bool dp[len];
        std::string str = "";
        auto begin = s.cbegin();
        auto end = s.cend();
        auto right = begin;
        auto lastLen = 0;
        while(right != end)
        {
            auto left = begin;
            while(left <= right)
            {
                auto step = std::distance(left, right);
                auto idx = std::distance(begin, left);
                bool isEqual = (*left == *right);
                switch(step)
                {
                    case 0: dp[idx] = true;
                        break;
                    case 1: dp[idx] = isEqual ? true : false;
                        break;
                    default: dp[idx] = dp[idx + 1] && isEqual;
                        break;
                }
                if(dp[idx] && ++step >= lastLen)
                {
                    lastLen = step;
                    str = s.substr(idx, lastLen);
                }
                ++left;
            }
            ++right;
        }
        return str;
    }
};
