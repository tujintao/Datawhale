class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, int> hash;
        int res = 0;
        int t = n;
        while (1) {
            if (hash.count(t) == 1) return false;
            else
                hash[t] = 1;
            if (t == 1) return true;
            while(t) {
                int digit = t % 10;
                res += digit * digit;
                t /= 10;
            }
            t = res;
            res = 0;
        }   
        return false;
    }
};