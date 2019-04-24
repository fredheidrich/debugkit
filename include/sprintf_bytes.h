// -*- C++ -*-
// ----------------------------------------------------------------------------
// See LICENSE for license information.
// ----------------------------------------------------------------------------
/// @file sprintf several bytes from a location in memory at a given length.
// ----------------------------------------------------------------------------

#ifndef sprintf_bytes_h
#define sprintf_bytes_h

// ----------------------------------------------------------------------------
// Apple
// ----------------------------------------------------------------------------
#if defined(__APPLE__)
#  include <cstdio>
#  include <cassert>
#  include <cmath> // ceil
// ----------------------------------------------------------------------------
// Others
// ----------------------------------------------------------------------------
#else
#  include <stdio.h>
#  include <assert.h>
#  include <math.h>
#endif

/// Copies a byte pointer to the start of the memory location and prints 
/// successive bytes using sprintf in groups of bytes. Displays each byte in
/// hexadecimal representation. The bytes will be copied into a buffer of max
/// buffer_size bytes.
///
/// @param buffer buffer to write string representation into
/// @param buffer_size length of representational buffer
/// @param start first byte to read from
/// @param length of bytes to read
// ----------------------------------------------------------------------------
template <int _GroupLength = 1>
void sprintf_bytes(
	char *buffer,
	size_t buffer_size,
	void const *start,
	size_t length
) {

	static_assert(_GroupLength > 0, "Byte group cannot be zero");

	char unsigned const *ptr = (char unsigned const *) start;
	int i, j;
	int cursor = 0;

	// Must have space enough for the input buffer to write
	assert(static_cast<int>(
		((16 + _GroupLength * 3 + 1) * ceil(length / _GroupLength)) + 1)
		< buffer_size
	);

 	for (i = 0; i < length && cursor < buffer_size; i += _GroupLength) {

  		sprintf(buffer + cursor, "%p  ", ptr + i);
		cursor += sizeof(void const *) + 5;

 		for (j = 0; j < _GroupLength && cursor < buffer_size; ++j) {
 			if (i + j < length) {
  				sprintf(buffer + cursor, "%.2x ", ptr[i + j]);
 			} else {
 				sprintf(buffer + cursor, "%s", " . ");
 			}
 			cursor += 3;
 		}
  		
  		sprintf(buffer + cursor, "%c", '\n');
  		cursor += 1;
  	}
	sprintf(buffer + cursor, "%c", '\0');
}


#endif // sprintf_bytes_h
