#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using std::vector;
using std::set;
using std::endl;
using std::cout;
using std::sort;
void PrintVector(vector<set<int>> );
void SortVector(vector<set<int>>& my_sets);
int main()
{
    vector<set<int>> my_sets;
    set<int> a={1,4,3,5};
    set<int> b={17,1,6,5,23,49,101,0,10};
    set<int> c={54,1,2,11,15};
    my_sets.push_back(c);
    my_sets.push_back(b);
    my_sets.push_back(a);
    PrintVector(my_sets);
    SortVector(my_sets);
    cout<<endl;
    PrintVector(my_sets);
    return 0;
}

void PrintVector(vector<set<int>> my_sets)
{
    cout<<'{';
    for(vector<set<int>>::iterator it1=my_sets.begin();it1!=my_sets.end();++it1)
    {
        cout<<'{';
        for(set<int>::iterator it=(*it1).begin();it!=(*it1).end();++it)
        {
            cout<<*it;
            it++;
            if((it)!=(*it1).end())
            {
                cout<<',';
            }
            it--;
        }
        cout<<'}';
        it1++;
        if(it1!=my_sets.end())
        {
            cout<<',';
        }
        it1--;
    }
    cout<<'}'<<endl;
}

void SortVector(vector<set<int>>& my_sets)
{
    sort(my_sets.begin(),my_sets.end(),[](set<int> a, set<int> b){return(a.size()<b.size());});
}





