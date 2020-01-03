/* February 2019
runtime: 4ms [99th]
memory: 1.6Mb [the best?]
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res = {0};
        unordered_map<int,int> hash_map;
        int remainder=0;
        for(int index=0; index < nums.size(); index++){
            remainder = target - nums[index];
            if(hash_map.find(remainder) == hash_map.end())
                hash_map[nums[index]] = index;
            else{
                res = {hash_map[remainder], index};
            }
        }
        return res;
    }
};