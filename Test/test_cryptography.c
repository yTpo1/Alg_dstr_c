#include "../lib_unittest/myunittest.h"
#include "../Cryptography/caesar.h"
#include "../Cryptography/polyalphabetic.h"

void test_caesar()
{
	char s[5] = "apple";
	assert_char_eq(caesar_encrypt_char('c'), 'f', "caesar");
	assert_char_eq(caesar_decrypt_char('f'), 'c', "caesar");
	caesar_encrypt_str(s, 5);
	assert_str_equal(s, "dssoh", "caesar");
	caesar_decrypt_str(s, 5);
	assert_str_equal(s, "apple", "caesar");
}

void test_polyalphabetic()
{
	char s[29] = "used in the fifteenth century";

	test_intequal(poly_get_shift('c'), 2, "poly");
	test_intequal(poly_get_shift('t'), 19, "poly");
	test_intequal(get_char_val('j', 'z'), 105, "poly");
	test_intequal(get_char_val('j', 't'), 99, "poly");
	test_intequal(get_char_val('m', 't'), 102, "poly");
	test_intequal(get_char_val('i', 'm'), 117, "poly");


	polyalpha_encr(s, 29);
	assert_str_equal(s, "okzw ca ybw abzgjyfoa wrsnmmr", "polyalpha");
	//polyalpha_decr(s, 29);
	//assert_str_equal(s, "used in the fifteenth century", "polyalpha");
}

void run_test_cryptography()
{
	test_caesar();
	test_polyalphabetic();
}
