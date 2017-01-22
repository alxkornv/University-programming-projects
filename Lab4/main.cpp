#include <iostream>
#include <list>
#include <set>
void listSetToList(const  std::list<std::set<int,std::greater<int>>> &src, std::list<int> &dst);
int main()
{
    std::set<int,std::greater<int>> a={3,2,1};
    std::set<int,std::greater<int>> b={4,5,3,6};
    std::set<int,std::greater<int>> c={2,0,5,6};
    std::set<int,std::greater<int>> d={30,13,31};
    std::list<std::set<int,std::greater<int>>> MyListSet;
    std::list<int> MyList;
    MyListSet.push_back(a);
    MyListSet.push_back(b);
    MyListSet.push_back(c);
    MyListSet.push_back(d);
    listSetToList(MyListSet,MyList);
    std::cout<<'{';
    for(std::list<int>::iterator it=MyList.begin();it!=MyList.end();++it)
    {
        std::cout<<*it;
        it++;
        if(it!=MyList.end())
        {
            std::cout<<", ";
        }
        it--;
    }
    std::cout<<'}';
    return 0;
}

void listSetToList(const  std::list<std::set<int,std::greater<int>>> &src, std::list<int> &dst)
{
    std::list<std::set<int,std::greater<int>>> TempSrc=src;
    std::list<std::set<int,std::greater<int>>>::iterator src_it;
    std::set<int>::iterator set_it;
    std::list<int>::iterator dst_it;
    TempSrc.sort([](std::set<int,std::greater<int>> a, std::set<int,std::greater<int>> b){return a.size()>b.size();});
    for(src_it=TempSrc.begin();src_it!=TempSrc.end();++src_it)
    {
        if(*((*src_it).begin())<=10)
        {
           for(set_it=(*src_it).begin();set_it!=(*src_it).end();++set_it)
           {
                dst.push_back(*set_it);
           }
        }

    }
}
