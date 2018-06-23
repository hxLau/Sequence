#ifndef SEQUENCE_H
#define SEQUENCE_H
#include<string.h>
using namespace std;

class Sequence
{
  public:
    Sequence(string);
    int length();
    int numberOf(char base);
    string longestConsecutive();
    string longestRepeated();
  private:
    int ilength;
    string all;
};
#endif
