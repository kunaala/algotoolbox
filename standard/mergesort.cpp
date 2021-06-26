#include <iostream>
#include <vector>
std::vector<int> sorter(std::vector<int> v)
{
	
	return v;	
}

int main()
{
	unsigned int n;
	std::cin>>n;
	std::vector<int> v(n);
	for(unsigned int i=0; i<n; i++)
	{
		std::cin>>v.at(i);
	}
	std::vector<int> s=sorter(v);
	for(unsigned int i=0; i<s.size(); i++)
	{
		std::cout<<s.at(i)<<'\t';
	}


	return 0;
}

