/**
 * INCOMPLETE
 */

#include<iostream>
#include<vector>
std::vector<int> multiply(unsigned int n, std::vector<int> a, std::vector<int> b)
{
    	unsigned int size=a.size() > b.size()? a.size() : b.size();
    	std::vector<int> p(2*size - 1,0);
	for(unsigned int i=0;i<size; i++)
	{
		for(unsigned int j=0;j<size;j++)
		{
			p.at(i+j) += a.at(i) * b.at(j);
		}
	}
	return p;
}
std::vector<int> multiply_kartsuba(unsigned int n, std::vector<int> a, std::vector<int> b)
{
	std::vector<int> p(2 * n -1, 0);
	std::vector<int> d1(n/2 ), d0(n/2);
    	std::vector<int> e1(n/2), e0(n/2);
	d1.assign(a.begin(), a.begin() + n/2 );
    	d0.assign(a.begin() + n/2  , a.end());
    	e1.assign(b.begin(), b.begin() + n/2 );
    	e0.assign(b.begin() + n/2 , b.end());
	for(unsigned int i=0;i<d1.size();i++)
	{
		for(unsigned int j=0;j<e1.size();j++)
		{

		}
	}

	
		/*
		for(unsigned int i=0;i<d1.size();i++)
		{
			std::cout<<d1.at(i);//<<'\t'<<d0.at(i)<<'\t'<<e1.at(i)<<'\t'<<e0.at(i)<<'\n';
		}
		std::cout<<'\n';
		for(unsigned int i=0;i<d0.size();i++)
		{
			std::cout<<d0.at(i);//<<'\t'<<d0.at(i)<<'\t'<<e1.at(i)<<'\t'<<e0.at(i)<<'\n';
		}
		*/
	

	

	

    	return p;
}
int main()
{
    	unsigned int n;
    	std::cin>>n;
    	std::vector<int> a(n),b(n);
    	for(unsigned int i=0;i<n;i++)
    	{
        	std::cin>>a.at(i);
    	}
    	for(unsigned int j=0;j<n;j++)
    	{
        	std::cin>>b.at(j);
    	}
    	std::vector<int> p(2*n - 1);
    	p=multiply(n,a,b);
	for(unsigned int i=0; i< p.size(); i++)
	{
		std::cout<<p.at(i)<<'\t';
	}

return
    return 0;
}
