#include <iostream>
#include <vector>
using namespace std;

void sortColors(vector<int> &nums)
{
    int start = 0;
    int middle = 0;
    int end = nums.size() - 1;

    while (middle <= end)
    {
        if (nums[middle] == 0)
        {
            swap(nums[start], nums[middle]);
            start++;
            middle++;
        }
        else if (nums[middle] == 1)
        {
            middle++;
        }
        else if (nums[middle] == 2)
        {
            swap(nums[middle], nums[end]);
            end--;
        }
    }
    //print array
    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;
}

int main()
{
    cout << "Sort Colors" << endl;
    vector<int> nums = {2, 0, 1, 2, 0, 1};
    sortColors(nums);
    return 0;
}