#include <iostream>
#include <vector>
#include <algorithm>
bool lazy(std::vector<int> v)
{
	unsigned int count =1, qualify = v.size() / 2;
	for(unsigned int k = 0; k < qualify ; k++)
	{

		for (unsigned int i= qualify;i< v.size(); i++)
		{
			if(v.at(i) == v.at(k) )
			{
				count++;
			}
		}
		if(count > qualify) return 1;			
	}
	return 0;
}
int partition(std::vector<int> v, unsigned int l, unsigned int r, unsigned int &count)
{
	unsigned int qualify = (r - l) / 2, mode =l;
	for(;mode <= r; mode++)
	{
		count = 1;
		for(unsigned int i = mode + 1; i<= r && mode<=r; i++)
		{
			if( v.at(i) == v.at(mode)) count++;
		}
		if(count > qualify)
		{
			//std::cout<<"l: "<<l<<'\t'<<"r :"<<r<<'\t'<<"count "<<count<<'\n';
			return mode;

		}
	}
	return -1; 

}
bool findelement_sorted(std::vector<int> v)
{
	if(v.size() < 2) return 1;
	std::sort(v.begin(), v.end());


	unsigned int count=1, qualify = v.size() / 2, key =0;
	//std::cout<<qualify<<'\n';
	for(unsigned int k = 1;k<v.size();k++)
	{
		if(v.at(key) == v.at(k))
		{
			count++;
			//std::cout<<"count: "<<count<<'\t'<<"k: "<<k<<'\n';
			if(count > qualify) return 1;
		}
		else 
		{
			key = k;
			count = 1;
		}
	}
	return 0;
}

bool findelement(std::vector<int> v)
{
	if(v.size() < 2)
	{
		//std::cout<<"only one element"<<'\n';
		return 1;
	}
	int m1, m2;
	unsigned int qualify = v.size() /2, count = 0, count1 = 0, count2 = 0 ;
	std::sort(v.begin(), v.end());
	m1= partition(v, 0, v.size() /2, count1);
	m2 = partition(v, v.size() /2 + 1 , v.size() - 1,count2);
	//std::cout<<"m1 :"<<m1<<'\t'<<"m2: "<<m2<<'\n';
	if(count1 > count2)
	{
		count = count1;
		for(unsigned int k=v.size() / 2;k<v.size() && m1 != -1; k++)
		{
			if(v.at(m1) == v.at(k) )  count++;
		}
		if(count > qualify) return 1;
		else
		{	
			count = count2;
			for(unsigned int k=0;k<=v.size() / 2  && m2 != -1; k++)
			{
				if(v.at(m2) == v.at(k) )  count++;
			}
			if(count > qualify) return 1;
			else return 0;
		}
		
	}
	else
	{
		count = count2;
		//std::cout<<count<<'\n';
		for(unsigned int k=0;k<=v.size() / 2  && m2 != -1; k++)
		{
			if(v.at(m2) == v.at(k) )  count++;
		}
		if(count > qualify) return 1;
		else
		{	
			count = count1;
			for(unsigned int k=v.size() /2 ;k<v.size() && m1 != -1; k++)
			{
				if(v.at(m1) == v.at(k) )  count++;
			}
			if(count > qualify) return 1;
			else return 0;
		}
	}
	//return lazy(v);

	
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
	bool status = findelement_sorted(v);
	std::cout<<status<<'\n';
	return 0;
}
