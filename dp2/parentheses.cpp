#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>
void printfn(std::vector<std::vector<int>> sol)
{
	for(unsigned int i=0;i<sol.size();i++)
	{
		for(unsigned int j=0;j<sol[i].size();j++)	std::cout<<(sol.at(i)).at(j)<<'\t';
		std::cout<<'\n';
	}
}
long long int ops(long long int a, char op, long long int b)
{
	if(op == '+')		return a + b;
	else if (op == '-')	return a - b;
	else if (op == '*')	return a * b;
	return 0;
}
std::pair<long long int, long long int> minmax(unsigned int i, unsigned int j, std::vector<long long int> sym, std::vector<std::vector< long long int>> &maxmat, std::vector<std::vector<long long int>> &minmat)
{
	std::pair<long long int, long long int> p;
	p.first =  std::numeric_limits<long long int>::max();
	p.second = std::numeric_limits<long long int>::min();
	//std::cout<<p.first<<":"<<p.second<<"hai"<<'\n';
	long long int a,b,c,d;
	for(unsigned int k=i;k<j;k++)
	{
		a = ops( (maxmat.at(i)).at(k), sym.at(k), (maxmat.at(k + 1)).at(j));
		b = ops( (maxmat.at(i)).at(k), sym.at(k), (minmat.at(k + 1)).at(j));
		c = ops( (minmat.at(i)).at(k), sym.at(k), (maxmat.at(k + 1)).at(j));
		d = ops( (minmat.at(i)).at(k), sym.at(k), (minmat.at(k + 1)).at(j));
	
		p.first = std::min({p.first, a,b,c,d});
		p.second = std::max({p.second, a,b,c,d});
	}
	return p;

}
long long int maximize(std::string str)
{
	std::vector<long long int> d,sym;
	for(unsigned int i =0;i<str.size();i+=2)	d.push_back(str.at(i) - 48);		
	for(unsigned int i =1;i<(str.size() - 1);i+=2)	sym.push_back(str.at(i));
	//for(unsigned int i =0;i<sym.size();i++)	std::cout<<sym.at(i)<<'\t';
	//std::cout<<'\n';
	std::vector<long long int> vr(d.size(), 0);
	std::vector<std::vector<long long int>> max(d.size(), vr),min(d.size(), vr);
	for(unsigned int i =0; i< d.size(); i++)
	{
		(max.at(i)).at(i) = d.at(i);
		(min.at(i)).at(i) = d.at(i);
	}
	std::pair<long long int, long long int> p;
	for(unsigned int k=1; k<d.size();k++)
	{
		for(unsigned int i=0; i<(d.size() - k); i++)
		{
			unsigned int j = i + k;
			p = minmax(i,j,sym, min, max);
			(min.at(i)).at(j)= p.first;
			(max.at(i)).at(j)= p.second;

		}
	}
	//printfn(max);
	//printfn(min);
	return (max.at(0)).at(d.size() -1);
}
int main()
{
	std::string str;
	std::cin>>str;
	std::cout<<maximize(str)<<'\n';
	return 0;
}
