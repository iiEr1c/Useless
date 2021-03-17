class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0)
            return vector<string>{};
        const array<string, 9>phone = {
            "", "abc","def",
            "ghi", "jkl", "mno",
            "pqrs", "tuv", "wxyz"
        };
        vector<string> ans = {};
        string tmp{};
        dfs(0, digits, tmp, phone, ans);
        return ans;
    }

    void dfs(int depth, const string& digits, string& tmp, const array<std::string, 9>& phone, vector<string>& ans)
    {
        if(depth == digits.size())
        {
            ans.push_back(tmp);
            return;
        }
        auto idx = static_cast<int>(digits.at(depth) - '0') - 1;
        for(const auto& i : phone[idx])
        {
            tmp.push_back(i);
            dfs(depth + 1, digits, tmp, phone, ans);
            tmp.pop_back();
        }
    }
};