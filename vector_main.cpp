#include "vector_impl.h"

int main()
{
    int n=0;
    std::cin>>n;
    Vector vec(n);
    for(int i=0; i<n; ++i)
    {
        int k=0;
        std::cin>>k;
        vec.insert(i,k) ;
    }
    std::cout<<"Part 1 vector"<<std::endl;
    for(int i=0; i<vec.get_size(); ++i)
    {
        std::cout<<vec.at(i)<<" ";
    }
    std::cout<<std::endl;
    //std::cout<<"Part 1.2"<<std::endl;
    std::cout<<std::endl;
    std::cout<<"Is empty - "<<vec.isEmpty()<<std::endl;
    std::cout<<"Front - "<<vec.front()<<"\tback - "<<vec.back()<<std::endl;
    vec.insert(2,10);
    vec.erase(3);
    std::cout<<"Part 2 insert (2,10), erase (3)"<<std::endl;
    for(int i=0; i<vec.get_size(); ++i)
    {
        std::cout<<vec.at(i)<<" ";
    }
    std::cout<<std::endl;
    std::cout<<"get capacity - "<<vec.get_cap()<<std::endl;
    vec.resize(2);
    vec.reserve(15);
    vec.push_back(2);
    vec.push_back(7);
    std::cout<<"resize(2)  reserve(15) pushback(2)(7)"<<std::endl;
    for(int i=0; i<vec.get_size(); ++i)
    {
        std::cout<<vec.at(i)<<" ";
    }
    std::cout<<std::endl;
    vec.pop_back();
    vec.shrink_to_fit();
    std::cout<<"Part 3 popback,shrink"<<std::endl;
    for(int i=0; i<vec.get_size(); ++i)
    {
        std::cout<<vec.at(i)<<" ";
    }
    std::cout<<std::endl;
    std::cout<<"Size - "<<vec.get_size()<<"\tCap - "<<vec.get_cap()<<std::endl;
    return 0;
}