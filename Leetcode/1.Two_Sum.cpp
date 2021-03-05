class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int>m = {};
        const int size = nums.size();
        for(int i = 0; i < size; ++i)
        {
            const auto it = m.find(target - nums[i]);
            if(it != m.end())
                return {it->second, i};
            m.insert({nums[i], i});
        }
        return {};
    }
    /*
     * 1. 注意{}的使用: 初始化(在return语句中复制列表初始化std::initializer_list)
     * 2. unorder_map的使用
     *     2.1 添加元素 bool insert(std::pair<typename, typename>)
     *         或者 insert_or_assign insert->true, assign->false
     *     2.2 删除元素 int(long) erase(key), 返回值可能为0或1(不重复关键字))或大于1(重复关键字)
     *     2.3 访问元素 iterator<> find(key)/int count(key)
     *
     *     
     */
};
