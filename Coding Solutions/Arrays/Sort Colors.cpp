class Solution {
public:
    void sortColors(vector<int>& nums) {
        //Dutch National Flag Algorithm
        int n = nums.size();
        int low = 0, mid = 0, high = n - 1;

        while (!(mid > high))
        {
            if (nums[mid] == 0)
            {
                swap(nums[mid], nums[low]);
                mid++;
                low++;
            }
            else if (nums[mid] == 1)
            {
                mid++;
            }
            else
            {
                swap(nums[high], nums[mid]);
                high--;
            }
        }
    }
};