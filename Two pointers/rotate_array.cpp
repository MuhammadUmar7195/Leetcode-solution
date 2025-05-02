#include <iostream>
#include <vector>
using namespace std;

void reverse(vector<int> &nums, int start, int end)
{
    while (start < end)
    {
        swap(nums[start++], nums[end--]);
    }
}
void rotate(vector<int> &nums, int k)
{
    int n = nums.size();
    // Take mod of size k for rotation
    k = k % n;

    // Step 1 reverse the full array
    reverse(nums, 0, n - 1);
    // Step 2 reverse the k elements
    reverse(nums, 0, k - 1);
    // step 3 reverse the remaining elements
    reverse(nums, k, n - 1);

    for(int i = 0; i<n; i++){
        cout << nums[i] << " ";
    }
}

int main()
{
    cout << "Rotate Array" << endl;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    rotate(nums, k);
    cout << endl;
    return 0;
}