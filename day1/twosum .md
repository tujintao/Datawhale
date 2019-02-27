### 思路 

由题目知道a + b = target有唯一解

​	1.稍作形变a = target - b 我们通过hashmap保存所有的num 一边遍历一边插入则遍历到a的时候一定可以得到b

空间复杂度 : `O(n)`

时间复杂度: `O(n)` hashmap的插入删除都是`O(1)`总共进行 n 次

```c++
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            int t = target - nums[i];
            if (m.count(t)) {
                res.push_back(m[t]);
                res.push_back(i);
                break;
            }
            m[nums[i]] = i;
        }
        return res;
    }
};
```

