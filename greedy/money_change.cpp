#include<iostream>
using std::cin;
using std::cout;
int main()
{
    unsigned int m;
    cin>>m;
    unsigned int n, r;
    n = m/10;
    r = m % 10;
    n += r / 5;
    r %= 5;
    n += r;
    cout<<n<<'\n';


    return 0;
}
