// -*- C++ -*-
// ----------------------------------------------------------------------------
// See LICENSE for license information.
// ----------------------------------------------------------------------------
/// @file printf several bytes from a location in memory at a given length.
// ----------------------------------------------------------------------------

#ifndef printf_bytes_h
#define printf_bytes_h

// ----------------------------------------------------------------------------
// Apple
// ----------------------------------------------------------------------------
#if defined(__APPLE__)
#  include <cstdio>
// ----------------------------------------------------------------------------
// Others
// ----------------------------------------------------------------------------
#else
#  include <stdio.h>
#endif

/// Copies a byte pointer to the start of the memory location and prints 
/// successive bytes using printf in groups of bytes. Displays each byte in
/// hexadecimal representation
///
/// @param start fist byte to read from
/// @param length number of bytes to read from start
// ----------------------------------------------------------------------------
template <int _GroupLength = 1>
void printf_bytes(void const* start, size_t length) {

	static_assert(_GroupLength > 0, "Byte group cannot be zero");

	char unsigned const * ptr = (char unsigned const *) start;
	int i, j;
 	for (i = 0; i < length; i += _GroupLength) {

  		printf("%p  ", ptr + i);
 		
 		for (j = 0; j < _GroupLength; ++j) {
 			if (i + j < length) {
  				printf("%.2x ", ptr[i + j]);
 			} else {
 				printf(" . ");
 			}

 		}
  		
  		printf("\n");
  	}
}

#endif // printf_bytes_h
