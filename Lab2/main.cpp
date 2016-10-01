#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
using std::cout;
using std::cin;
using std::endl;
using std::string;
void lab2_12(string ,std::vector<std::pair<int,int>> &);
void lab2_7(string ,int);
int main()
{
    std::vector<std::pair<int,int>> vec;

    string str="999 999h lkj 12 j";
    //cout<<"Enter string"<<endl;
    //std::getline(cin,str);

    lab2_12(str,vec);
    std::sort(vec.begin(),vec.end(),[](std::pair<int,int> p1, std::pair<int,int> p2){return p1.first<p2.first;});
    int num=vec.at(0).first;
    lab2_7(str,num);
    return 0;
}

void lab2_12(string str,std::vector<std::pair<int,int>> &vec)
{
    int num=0;
    bool flag=false;
    size_t ptr=0;
    string s1="";

    std::vector<std::pair<int,int>>::iterator it;
    for(size_t i=0;i<str.size();i++)
    {
        if(isdigit(str[i])!=0)
        {
            s1=str.substr(i);
            num=stoi(s1,&ptr,10);
            for(size_t j=0;j<vec.size();j++)
            {
                if(vec.at(j).first==num)
                {
                    vec.at(j).second++;
                    flag=true;
                    break;
                }
            }

            if(!flag || vec.size()==0)
            {
                vec.push_back(std::make_pair(num,1));

            }
            i+=ptr;
            ptr=0;
            flag=false;

        }
    }

    //cout<<str<<endl;
    if(vec.size()!=0)
    {
    string temp_st="";
    for(size_t i=0;i<str.size();i++)
    {
        if(isdigit(str[i])!=0)
        {
            s1=str.substr(i);
            num=stoi(s1);
            temp_st=std::to_string(num);
            it=std::find_if(vec.begin(),vec.end(),[num](std::pair<int,int> &elem){return elem.first==num;});
            if(it->second>1)
            {
                num++;
                s1=std::to_string(num);
                str.replace(str.begin()+i,str.begin()+i+temp_st.size(),s1);
                cout<<str<<endl;
                i+=s1.size()-1;

            }
            else
            {
                i+=temp_st.size()-1;
            }
        }
    }

    }
    cout<<endl;

     cout<<str<<endl;

}

void lab2_7(string str, int num)
{
    string s1="";
    string s2="";
    int temp;
    s2=std::to_string(num);
    for(size_t i=0;i<str.size();i++)
    {
        if(isdigit(str[i])!=0)
        {
          s1=str.substr(i);
          temp=stoi(s1);
          s1=std::to_string(temp);
          str.replace(str.begin()+i,str.begin()+i+s1.size(),s2);
          i+=s2.size()-1;
        }
    }
    cout<<str<<endl;
}
