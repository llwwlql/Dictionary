#include <stdio.h>

int main(int argc, char* argv[])
{
  int nBinary = 0;
  int nDigital = 1;
  int nTemp = 0;
  int nMark = 0;
  int nNumber = 0;
  int nNumberArrayOne[10000] = {0};
  int nNumberArrayTwo[10000] = {0};

  nNumberArrayOne[0] = 0;
  nNumberArrayTwo[0] = 1;
  scanf("%d", &nNumber);

  for (int i = 1; i < nNumber; i++)
  {
    if (nMark == 0)
    {
      for (int j = 0; j < nDigital; j++)
      {
        nTemp = nNumberArrayOne[j] + nNumberArrayTwo[j] + nBinary;
        nNumberArrayOne[j] = nTemp % 10;
        nBinary = nTemp / 10;
      }
      while(nBinary)
      {
        nDigital++;
        nNumberArrayOne[nDigital - 1] = nBinary % 10;
        nBinary = nBinary / 10; 
      }
      nMark = 1;
    }
    else
    {
      for (int j = 0; j < nDigital; j++)
      {
        nTemp = nNumberArrayOne[j] + nNumberArrayTwo[j] + nBinary;
        nNumberArrayTwo[j] = nTemp % 10;
        nBinary = nTemp / 10;
      }
      while(nBinary)
      {
        nDigital++;
        nNumberArrayTwo[nDigital - 1] = nBinary % 10;
        nBinary = nBinary / 10; 
      }
      nMark = 0;
    }
  }
 
  if (nMark == 0)
  {
    for (int k = nDigital - 1; k >= 0; k--)
    {
      printf("%d", nNumberArrayTwo[k]);
    }
    puts("");
  }
  else
  {
    for (int k = nDigital - 1; k >= 0; k--)
    {
      printf("%d", nNumberArrayOne[k]);
    }
    puts("");
  }
 
  return 0;
}
