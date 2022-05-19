#pragma once
#include <exception>
using namespace std;

class RationalException : public exception
{
public:
	RationalException(const char* const msg) : exception(msg) {};
};

