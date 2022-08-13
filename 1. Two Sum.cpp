1. Two Sum
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 
Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
 

Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.

更新了三种Two Sum解法
1、数组：O(nlogn)
2、哈希表: 理论O(n)，但数据量不大则不明显
3、二重循环：最省内存，效率最低
考虑了输入数据有重复的情况。
 
``` C++
class Solution {
public:
    /*Below is the 2 sum algorithm that is O(NlogN) + O(N)*/
    /*Alternative: hash从左往右扫描一遍，然后将数及坐标，存到map中。然后再扫描一遍即可。时间复杂度O(n)*/
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> numbersCopy;
        for(int i = 0; i < numbers.size(); i++) numbersCopy.push_back(numbers[i]);
        
        sort(numbersCopy.begin(), numbersCopy.end()); //O(NlogN)
        vector<int> returnNumbers = twoSumAlgorithm(numbersCopy, target);//O(N)
        
        vector<int> returnIndexes;
        for(int j = 0; j < returnNumbers.size(); j++)//2
            for(int i = 0; i < numbers.size(); i++)//O(N)
                if(numbers[i] == returnNumbers[j]) returnIndexes.push_back(i + 1);
                
        
        if(returnIndexes[0] > returnIndexes[1]){
            returnIndexes[0] = returnIndexes[0]^returnIndexes[1];
            returnIndexes[1] = returnIndexes[0]^returnIndexes[1];
            returnIndexes[0] = returnIndexes[0]^returnIndexes[1];
        }

        return returnIndexes;
    }
    
    /*Core algorithm is linear*/
    vector<int> twoSumAlgorithm(vector<int> &numbers, int target) {
        int len = numbers.size();
        vector<int> r;
        int i = 0; int j = len - 1;
        while(i < j){
            int x = numbers[i] + numbers[j];
            if(x == target){ 
                r.push_back(numbers[i]);
                r.push_back(numbers[j]);
                i++; j--;
            }else if(x > target) j--;
            else i++;
        }
        return r;
    }
    
    /*Exceed Time Limit*/
    /*
    vector<int> twoSum(vector<int> &numbers, int target) {
        int len = numbers.size();
        int index1 = 0;
        int index2 = 0;
        
        for(int i = 0; i < len; i++){
            for(int j = 0; j < len; j++){
                if(j==i) continue;
                if(numbers[i] + numbers[j] == target){
                    index1 = i+1;
                    index2 = j+1;
                }
            }
        }
        
        if(index1>index2){
            index1 = index1^index2;
            index2 = index1^index2;
            index1 = index1^index2;
        }
        
        vector<int> r;
        r.push_back(index1);
        r.push_back(index2);
        return r;
    }*/
};
```

