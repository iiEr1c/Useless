class Solution {
public:
    bool isValid(string s) {
        stack<char>ss;
        for(const auto& i : s)
        {
            if(i == '(' || i == '[' || i == '{')
            {
                ss.push(i);
                continue;
            }
            if(ss.empty())
                return false;
            auto ch = ss.top();
            ss.pop();
            switch(i)
            {
                case ')':
                    if(ch == '(')
                        continue;
                    else
                        return false;
                    break;
                case ']':
                    if(ch == '[')
                        continue;
                    else
                        return false;
                    break;
                case '}':
                    if(ch == '{')
                        continue;
                    else
                        return false;
                    break;
            }
        }
        return ss.empty();
    }
};