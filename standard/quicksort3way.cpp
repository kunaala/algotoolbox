#include<iostream>
#include<vector>
#include<cstdlib>
std::vector<int>& swapper(std::vector<int> &v, unsigned int id1, unsigned int id2)
{
	int temp;
	temp=v.at(id1);
	v.at(id1) = v.at(id2);
	v.at(id2) = temp;
	return v;
}
std::pair<unsigned int, unsigned int> partition(std::vector<int> &v, unsigned int l, int r)
{
	unsigned int pivot = l;// + (rand() % (r - l) );
	//std::cout<<"pivot: "<<pivot<<'\n';
	std::pair<unsigned int , unsigned int> p;
	unsigned int j=l, k=l;
	for(unsigned int i=l+1;i<=r;i++)
	{
		if(v.at(i) < v.at(l)) 
		{
			j++;k++;
			v = swapper(v, i, k);
			v = swapper(v,k,j);
		}
		else if ( v.at(i) == v.at(l))
		{
			k++;
			v = swapper(v, i, k);
		}

	}
	/*
    	for(unsigned int i=0; i<v.size();i++)
    	{
        	std::cout<<v.at(i)<<'\t';
	}
	
	std::cout<<"before swapping"<<'\n';
	v = swapper(v,j,l);
    	for(unsigned int i=0; i<v.size();i++)
    	{
        	std::cout<<v.at(i)<<'\t';
	}
	std::cout<<"after swapping"<<'\n';
	*/
	v = swapper(v, j, l);
	p.first = j;
	p.second = k;
	return p;
	
}
std::vector<int> sorter(std::vector<int> &v, unsigned int l, int r)
{   
	std::pair<unsigned int , unsigned int> p;
	unsigned int m1,m2;
	//std::cout<<"l: "<<l<<'\t'<<"r: "<<r<<'\n';	
	while(l < r && r > 0 )
	{
		//std::cout<<"l: "<<l<<'\t'<<"r: "<<r<<'\n';	
		
		p=partition(v, l, r);
		m1=p.first;
		m2=p.second;
		//std::cout<<"l: "<<l<<'\t'<<"r: "<<r<<'\t'<<"m1: "<<m1<<'\t'<<"m2: "<<m2<<'\n';
		if( (m1-l) <= (r-m2) )
		{
			//std::cout<<"recursion"<<'\n';
			sorter(v, l, m1-1);
			l = m2 + 1;
		}
		else 
		{
			sorter(v, m2+1, r);
			r = m1 - 1;
		}
		/*
		std::cout<<"sorter printing: "<<'\n';
		for(unsigned int i=0; i<v.size();i++)
    		{
        		std::cout<<v.at(i)<<'\t';
    		}
		std::cout<<'\n';
		*/
	}
	return v;
	
}
int main()
{
    	//std::cout<<"enter size of the list"<<'\n';
    	unsigned int n;
    	std::cin>>n;
    	//std::cout<<"Enter its elements"<<'\n';
    	std::vector<int> v(n);
    	for(unsigned int i=0; i<n;i++)
    	{
        	std::cin>>v.at(i);
    	}
    	v=sorter(v,0,n-1);
	for(unsigned int i=0; i<v.size();i++)
    	{
		std::cout<<v.at(i)<<'\t';
	}
	std::cout<<'\n';
	return 0;

}
