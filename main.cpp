#include<iostream>
#include<time.h>
#include<vector>
#include"Sequence.h"
using namespace std;

int main()
{
    clock_t start=clock();
    Sequence mySequence("/home/liu201730683185/github/Sequence/dna.txt");
    cout<<"序列长度为："<<mySequence.length()<<endl;
    cout<<"序列包括字符A的个数:"<<mySequence.numberOf('A')<<endl;
    cout<<"序列包括字符G的个数:"<<mySequence.numberOf('G')<<endl;
    cout<<"序列包括字符C的个数:"<<mySequence.numberOf('C')<<endl;
    cout<<"序列包括字符T的个数:"<<mySequence.numberOf('T')<<endl;
    cout<<"最长连续重复的序列是:"<<mySequence.longestConsecutive()<<endl;
    cout<<"重复的次数为："<<mySequence.longestConsecutive().length()<<endl;
    cout<<"最长重复子串为:"<<mySequence.longestRepeated()<<endl;
    clock_t ends=clock();
    cout<<(double)(ends-start)/CLOCKS_PER_SEC<<endl;

    
    return 0;
}
