#include<iostream>
#include<vector>
double  fillingup(unsigned int total, std::vector<unsigned int> weights, std::vector<unsigned int> kcals)
{
    double totval=0;    
    unsigned int max = 1;
    unsigned int wcumula=0;
    for(unsigned int j=0;(wcumula != total && j<weights.size());j++)
    {
        if(weights.size() <= 1)
        {
            max =0;
        }
        else
        {
            for(unsigned int i=0; i<weights.size(); i++)
            {
 
                if(( (double)kcals.at(i) / weights.at(i)  ) > ( (double)kcals.at(max) / weights.at(max)))
                {
                    max=i;
                }
                
            }
        }

        if(weights.at(max) >= (total - wcumula))
        {
            // prop[max] = total - wcumula;
            totval +=  (total - wcumula) * ( (double)kcals.at(max) / weights.at(max));
            // std::cout<<"prop"<< prop[max]<<'\n';
            break; 
        }
        else 
        {
          
            // prop[max] = weights.at(max);
            wcumula  += weights.at(max);
            totval += weights.at(max) * ( (double)kcals.at(max) / weights.at(max));
            // std::cout<<"prop"<< prop[max]<<'\n';
            // weights.at(max) = 0;
            weights.at(max) = 2*kcals.at(max); // to nullify the imapact of this maxima  
        }
    
        
    } 
    return totval;   
    // for(int i=0;i<prop.size();i++)
    // {
    //     std::cout<<prop.at(i)<<'\t';
    // }  
    
}
int main()
{
    unsigned int n, size;
    std::cin>>n>>size;
    std::vector<unsigned int> weights(n), kcals(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> kcals[i] >> weights[i];
    }

    std::cout.precision(10);
    std::cout<<fillingup(size, weights, kcals);

    return 0;



}