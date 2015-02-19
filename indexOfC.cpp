#include "indexOfC.h"

long IndexOfC( long searchVal, long arrayInt[], unsigned count )
{
	for(unsigned i = 0; i != count; ++i) {
		if( arrayInt[i] == searchVal )
			return i;
	}
  return -1;
}
