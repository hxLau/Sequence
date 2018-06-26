#include<iostream>
#include<string>
#include<fstream>
#include<string.h>
#include<vector>
#include<algorithm>
#include"Sequence.h"
using namespace std;

Sequence::Sequence(string filename)
{
    char* fi=(char*)filename.data();
    ifstream input(fi);
    string line;
    
    getline(input,line);
    all=line;

    while(getline(input,line))
    {  
        all+=line;
    }

    ilength=all.length();
}

int Sequence::length()
{
    return ilength;
}

int Sequence::numberOf(char base)
{
    int count=0;
    char *p=(char*)all.data();
    char *start=p;
    char *findout=strchr(start,base);
    
    while(findout)
    {
        count++;
        start=findout+1;
        findout=strchr(start,base);
    }
    return count;
}

string Sequence::longestConsecutive()
{
    char *before=(char*)all.data();
    char *p=(char*)all.data();
    char t;
    int max=1;
    int count=1;
    while(*++before)
    {
        if(*before==*p)
        {
            count++;
            if(count>max)
            {
                max=count;
                t=p[0];
            }
        }
        else
        {
            p=before;
            count=1;
        }
    }
    
    char *ptr=new char[max];
    for(int i=0;i<max;i++)
    {
        ptr[i]=t;
    }
    string longest=ptr;
    delete []ptr;
    int len=longest.length();
    longest.erase(max,len-max);
    return longest;
}

string Sequence::longestRepeated()
{
     vector<string> behindstr;
     for(int i=0;i<length();i++)
     {
          behindstr.push_back(all.substr(length()-i-1,i+1));
     }
     sort(behindstr.begin(),behindstr.end());
     int max=0;
     string longstr;
     for(int i=0;i<behindstr.size()-1;i++)
     {
          string str1=behindstr[i];
          string str2=behindstr[i+1];
          int templen=0;
          for(int j=0;j<min(str1.length(),str2.length());j++)
          {
               if(str1[j]!=str2[j])
               { 
                   templen=0;
                   break;
               }
               else templen++;
               if(max<templen)
               {
                   max=templen;
                   longstr=str2.substr(0,max);
               }
          }
     }
     return longstr;
}













  

