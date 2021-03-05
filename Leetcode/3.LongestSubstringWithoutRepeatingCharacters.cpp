class Solution {
public:
    /*
    int lengthOfLongestSubstring(string s) {
        int end = s.length();
        std::unordered_map<char, int>m = {};
        auto start = 0;
        auto i = 0;
        auto maxLen = 0;
        while(i < end)
        {
            auto ch = s.at(i);
            auto it = m.find(ch);
            if(it == m.end())
                maxLen = max(maxLen, i - start + 1);
            else
            {
                auto new_start = it->second;
                while(start <= new_start)
                    m.erase(s.at(start++));
            }

            m.insert({ch, i});
            ++i;
        }
        return maxLen;
    }
    */

    /*
    int lengthOfLongestSubstring(string s) {
        std::unordered_map<char, string::const_iterator>m;
        auto beg = s.cbegin();
        auto end = s.cend();
        auto start = beg;
        auto maxLen = 0;
        while(beg != end)
        {
            auto ch = *beg;
            while(m.find(ch) != m.cend())
            {
                m.erase(*start);
                ++start;
            }
            maxLen = max(maxLen, static_cast<int>(beg - start) + 1);
            m.emplace(ch, beg);
            ++beg;
        }
        return maxLen;
    }
    */
    /*
    int lengthOfLongestSubstring(string s) {
        std::unordered_set<char>m;
        auto beg = s.cbegin();
        auto end = s.cend();
        auto start = beg;
        auto maxLen = 0;
        while(beg != end)
        {
            auto ch = *beg;
            while(m.find(ch) != m.cend())
            {
                m.erase(*start);
                ++start;
            }
            maxLen = max(maxLen, static_cast<int>(beg - start) + 1);
            m.insert(ch);
            ++beg;
        }
        return maxLen;
    }
    */
    int lengthOfLongestSubstring(string s) {
        bool isExisted[128] = {false};
        auto beg = s.cbegin();
        auto end = s.cend();
        auto last = beg;
        auto maxLen = 0;
        while(beg != end)
        {
            auto idx1 = static_cast<int>(*beg);
            while(isExisted[idx1])
            {
                auto idx2 = static_cast<int>(*last);
                isExisted[idx2] = false;
                ++last;
            }
            maxLen = max(maxLen, static_cast<int>(beg - last) + 1);
            isExisted[idx1] = true;
            ++beg;
        }
        return maxLen;
    }
    /*
    int lengthOfLongestSubstring(string s) {
        //bool isExisted[128] = {false};
        bitset<128>isExisted(0);
        auto beg = s.cbegin();
        auto end = s.cend();
        auto start = beg;
        auto maxLen = 0;
        while(beg != end)
        {
            auto idx1 = static_cast<int>(*beg);
            while(isExisted.test(idx1))
            {
                auto idx2 = static_cast<int>(*start);
                isExisted.reset(idx2);
                ++start;
            }
            maxLen = max(maxLen, static_cast<int>(beg - start) + 1);
            isExisted.set(idx1);
            ++beg;
        }
        return maxLen;
    }
    */
};
