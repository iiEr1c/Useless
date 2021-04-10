class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string str;
        vector<string>result;
        dfs(n, n, str, result);
        return result;
    }
    void dfs(int left, int right, string& str, vector<string>& result)
    {
        if(left == 0 && right == 0)
        {
            result.push_back(str);
            return;
        }
        if(left > 0)
        {
            str.push_back('(');
            dfs(left - 1, right, str, result);
            str.pop_back();
        }
        if(right > left)
        {
            str.push_back(')');
            dfs(left, right - 1, str, result);
            str.pop_back();
        }
    }
    /*
    vector<string> generateParenthesis(int n) {
        string str;
        vector<string>result;
        dfs(n << 1, str, result);
        return result;
    }

    void dfs(const int maxDepth, string& str, vector<string>& result)
    {
        if(str.size() == maxDepth)
        {
            if(valid(str))
                result.push_back(str);
            return;
        }
        str.push_back('(');
        dfs(maxDepth, str, result);
        str.pop_back();
        str.push_back(')');
        dfs(maxDepth, str, result);
        str.pop_back();
    }

    bool valid(const string& str)
    {
        int balance = 0;
        for(const auto& i : str)
        {
            balance = i == '(' ? balance + 1 : balance - 1;
            if(balance < 0)
                return false;
        }
        return balance == 0;
    }
    */
};