#include<iostream>
#include<string>
#include<fstream>
#include<string.h>
#include<cstring>
#include<algorithm>
#include<vector>
#include<sstream>
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
/*
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
*/

int comlen(char* p,char* q)
{
    int i=0;
    while(*p&&(*p++==*q++)) ++i;
    return i;
}

int pstrcmp(const void* p1,const void* p2)
{
     return strcmp(*(char* const*)p1,*(char* const*)p2);
}

string Sequence::longestRepeated()
{
    int len=length();
    char* a=new char[len+1];
    char** c=new char*[len];
    char* p=(char*)all.data();
    for(int i=0;i<len;++i)
    {
        a[i]=p[i];
        c[i]=&a[i];
    }
    c[len]=0;
    qsort(c,len,sizeof(char*),pstrcmp);
    int maxi=0;
    int thislen=0;
    int maxlen=0;
    
    for(int i=0;i<len-1;++i)
    {
        thislen=comlen(c[i],c[i+1]);
        if(thislen>maxlen)
        {
           maxlen=thislen;
           maxi=i;
        }
    }
    string bb=c[maxi];
    string aaa=bb.substr(0,maxlen);
    return aaa;
}








  

