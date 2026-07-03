#include <iostream>

using namespace	std;
class Solution
{
  public:
	bool isVogal(char s)
	{
		string vogals = "aeiouAEIOU";
		for (int i = 0; i < vogals.size(); i++)
		{
			if (vogals[i] == s)
				return (true);
		}
		return (false);
	}
	string reverseVowels(string s)
	{
		string result;
		int i = 0;
		int j = s.size() - 1;
		while(i < s.size())
		{
			if (isVogal(s[i]))
			{
				while (!isVogal(s[j]))
					j--;
                
				if (isVogal(s[j]))
				{
                    result += s[j];
                    s[j] = s[i];
                    j--;
				}
			}
            else
                result += s[i];
            i++;
		}
		return (result);
	}
};

int	main(void)
{
	Solution str;
	std::cout << str.reverseVowels("IceCreAm") << std::endl;
	return (0);
}