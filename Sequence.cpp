#include<iostream>
#include<string>
#include<fstream>
#include<string.h>
#include<vector>
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
     string temp;
     string longstr;
     
     return longstr;
}













  
