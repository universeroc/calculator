// lexical.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "lexical.h"

int _tmain(int argc, _TCHAR* argv[])
{
  Lexical lexical;
  std::cout<< lexical.usage();
  std::cin >> lexical;
  lexical.Analysis();
  std::cout<< lexical;

	return 0;
}

