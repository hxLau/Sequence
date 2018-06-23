#include<iostream>
#include"Sequence.h"
using namespace std;

int main()
{
    Sequence mySequence("/data/dna.txt");
    cout<<mySequence.length()<<endl;
    cout<<mySequence.numberOf('A')<<endl;
    cout<<mySequence.numberOf('G')<<" "<<mySequence.numberOf('C')<<" "<<mySequence.numberOf('T')<<endl;
    return 0;
}
