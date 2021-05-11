#include <iostream>
#include <vector>
std::vector<int> sorter(std::vector<int> v)
{
	unsigned int min, idx=0;
	int temp;
	for(;idx != v.size(); idx++)
	{
		min=idx;
		for(unsigned int i=idx; i< v.size(); i++)
		{
			if(v.at(i) < v.at(min)) min=i;
		}
		//std::cout<<"min: "<<v.at(min)<<'\n';
		if(min > idx )
		{	
			temp = v.at(min);
			v.at(min)=v.at(idx);
			v.at(idx) = temp;
			//std::cout<<"swapped: "<<v.at(idx)<<'\t'<<"with: "<<v.at(min)<<'\n';
		//for(unsigned int i=0; i<v.size(); i++)
		//{
		//	std::cout<<v.at(i)<<'\t';
		//}
		//std::cout<<'\n';
		}
	}	
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

