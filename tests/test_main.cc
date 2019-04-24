
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "printf_bytes.h"
#include "sprintf_bytes.h"


TEST_CASE("printf_bytes") {
	
	char const buf[6] = "ABCDE";

	printf_bytes(buf, 5);
	printf_bytes<8>(buf, 5);
	printf_bytes<8>(buf, 16); // possible to print outside

	// printf_bytes<0>(buf, 5); // will not compile

}

TEST_CASE("sprintf_bytes") {

	char const buf[6] = "ABCDE";
	char buffer[128] = {0};

	sprintf_bytes<8>(buffer, 128, buf, 6);
	printf("%s", buffer);

}