/* 1)
- Brute Force Solution
time Complexity = O(nlogn) ->> Sort function take O(nlogn) and for loop take between O(1 to n)
Space Complexity - O(1) -> Constant Space
*/

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int i = 0;
        for (i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] == nums[i + 1]) // -> if(nums[i]^nums[i+1] == 0)
            {
                break;
            }
        }
        return nums[i];
    }
};

/* 2)
- Bool Method
time Complexity = O(n)
Space Complexity - O(n) -> Because it is creating an extra arr.
*/
// choose Between 2.1 / 2.2

// 2.1 ->
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        vector<bool> hash(nums.size(), false);

        for (int i = 0; i < nums.size(); i++)
        {
            if (hash[nums[i]])
            {
                return nums[i];
            }
            else
            {
                hash[nums[i]] = true;
            }
        }
        return -1;
    }
};

// 2.2 ->
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        vector<int> arr(nums.size(), 0);
        int i = 0;

        // storing 0->1 at position accoring to nums, if any no. came twice then there stores 1->2.
        for (i = 0; i < nums.size(); i++)
        {
            arr[nums[i]]++;
        }

        for (i = 0; i < arr.size(); i++)
        {
            if (arr[i] > 1) //  element occur more than once in nums
            {
                break;
            }
        }

        return i;
    }
};

/* 3)
- Binary Search Method
time Complexity = O(n^2)
Space Complexity - O(1) -> Constant Space
*/

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int low = 1, high = nums.size() - 1, cnt;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            cnt = 0;
            // cnt number less than equal to mid
            for (int n : nums)
            {
                if (n <= mid)
                    ++cnt;
            }
            // binary search on left
            if (cnt <= mid)
                low = mid + 1;
            else
                // binary search on right
                high = mid - 1;
        }
        return low;
    }
};


/* 4)
- Hash Map
time Complexity = O(n)
Space Complexity - O(n) 
*/
class Solution{
    public:  int findDuplicate_set(int[] nums) {
        Set<int> set = new HashSet<>();
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            if (!set.add(nums[i])) {
                return nums[i];
            }
        }

        return len;
    }
};
