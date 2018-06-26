#include<iostream>
#include<time.h>
#include"Sequence.h"
using namespace std;

int main()
{
    clock_t start=clock();
    Sequence mySequence("/data/dna.txt");
    cout<<mySequence.length()<<endl;
    cout<<mySequence.numberOf('A')<<endl;
    cout<<mySequence.numberOf('G')<<" "<<mySequence.numberOf('C')<<" "<<mySequence.numberOf('T')<<endl;
    cout<<mySequence.longestConsecutive()<<endl;
    cout<<mySequence.longestConsecutive().length()<<endl;
    clock_t ends=clock();
    cout<<(double)(ends-start)/CLOCKS_PER_SEC<<endl;

    
    return 0;
}
