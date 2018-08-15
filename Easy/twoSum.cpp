#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
**/
vector<int> twoSum(vector<int>& nums, int target)
{
    int i;
    unordered_map<int, int> map;
    vector<int> ret;
    
    map[nums[0]] = 0;
    for (i = 1; i < nums.size(); i++)
    {
        if (map.find(target - nums[i]) != map.end())
        {
            ret.push_back(map.find(target - nums[i])->second);
            ret.push_back(i);
            break;
        }
        map[nums[i]] = i;
    }
    return ret;
}

