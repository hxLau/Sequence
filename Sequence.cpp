#include<iostream>
#include<string>
#include<fstream>
#include<string.h>
#include"Sequence.h"
using namespace std;

Sequence::Sequence(string filename)
{
    char* fi=(char*)filename.data();
    ifstream input(fi);
    string line;
    int alength;

    getline(input,line);
    alength=line.length();
    line.erase(alength-1,1);
    all=line;

    while(getline(input,line))
    {  
        alength=line.length();
        line.erase(alength-1,1);
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
     
}

string Sequence::longestRepeated()
{
     string temp;
     string longstr;
     
     return longstr;
}













  
