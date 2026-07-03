#include <iostream>
using namespace	std;
#include <vector>

class Solution
{
  public:
	vector<int> productExceptSelf(vector<int> &nums)
	{
        int n = nums.size();
        vector<int>answer(n, 1);
        int left = 1;

		for (int i = 0; i < nums.size(); i++)
        {
            answer[i] = left;
            left *= nums[i];
        }
        int right = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            answer[i] *= right;
            right *= nums[i];
        }
        return answer;
        
    }
};

	int main()
	{
		Solution sol;
		vector<int> vec = {1, 2, 3, 4};
        vector<int> res;
		res = sol.productExceptSelf(vec);
        for (size_t i = 0; i < res.size(); i++)
        {
            std::cout << res[i] << std::endl;
        }
        
		return (1);
	}