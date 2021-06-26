#include <iostream>
#include <vector>
#include <algorithm>
void populate(std::vector<unsigned int> &v)
{
	for(unsigned int i=1;i<v.size();i++)
	{
		if((i + 1) < v.size() && (v.at(i + 1) == 0 || v.at(i +1) > v.at(i) + 1))	v.at(i+1) = v.at(i) + 1;
		if( 2*i < v.size() && (v.at(2*i) == 0 || v.at(2*i) > v.at(i) + 1))		v.at(2*i) = v.at(i) + 1;
		if( 3*i < v.size() && (v.at(3*i) == 0 || v.at(3*i) > v.at(i) + 1))		v.at(3*i) = v.at(i) + 1;
	}
}
std::vector<unsigned int> minimize(std::vector<unsigned int> &v, unsigned int n)
{
	std::vector<unsigned int> sol;
	for(unsigned int i = n; i > 1 ;)
	{
		sol.push_back(i);
		if(v.at(i - 1) == v.at(i) - 1) i--;
		else if(i%2 == 0 && v.at(i/2) == v.at(i) -1) i /=2; 
		else if(i%3 == 0 && v.at(i/3) == v.at(i) -1) i /=3;
	}
	sol.push_back(1);
	std::reverse(sol.begin(),sol.end());
	return sol;
}

int main()
{
	unsigned int n;
	std::cin>>n;
	std::vector<unsigned int> v((n + 1),0), sol;
	v.at(1) = 1;
	populate(v);
	//for(unsigned int k =0;k<v.size();k++)	std::cout<<v.at(k)<<'\t';
	//std::cout<<'\n';
	sol = minimize(v,n);
	std::cout<<sol.size() -1<<'\n';
	for(unsigned int k =0;k<sol.size();k++)	std::cout<<sol.at(k)<<'\t';
	std::cout<<'\n';
	return 0;
}
