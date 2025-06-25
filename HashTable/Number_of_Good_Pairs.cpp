/*  Brute force approch
    TC O(n^2)
    SC O(1)
*/
class Solution
{
public:
    int numIdenticalPairs(vector<int> &nums)
    {
        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (nums[i] == nums[j])
                {
                    count++;
                }
            }
        }

        return count;
    }
};

/*  HashTable and freq note approach
    TC O(n)
    SC O(1)
*/
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> freq;

        for (int num : nums) {
            freq[num]++;
        }
        int totalCount = 0;
        for (auto& p : freq) {
            int i = p.second;
            totalCount += (i * (i - 1)) / 2;
        }

        return totalCount;
    }
};