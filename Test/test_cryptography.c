#include "../lib_unittest/myunittest.h"
#include "../Cryptography/caesar.h"
#include "../Cryptography/polyalphabetic.h"

void test_caesar()
{
	char s[5] = "apple";
	assert_char_eq(caesar_encrypt_char('c'), 'f', "caesar");
	assert_char_eq(caesar_decrypt_char('f'), 'c', "caesar");
	caesar_encrypt_str(s, 5);
	assert_str_eq(s, "dssoh", "caesar");
	caesar_decrypt_str(s, 5);
	assert_str_eq(s, "apple", "caesar");
}

void test_polyalphabetic()
{
	char s[29] = "used in the fifteenth century";

	assert_int_eq(poly_get_shift('c'), 2, "poly");
	assert_int_eq(poly_get_shift('t'), 19, "poly");
	assert_int_eq(get_char_val('j', 'z'), 105, "poly");
	assert_int_eq(get_char_val('j', 't'), 99, "poly");
	assert_int_eq(get_char_val('m', 't'), 102, "poly");
	assert_int_eq(get_char_val('i', 'm'), 117, "poly");


	polyalpha_encr(s, 29);
	assert_str_eq(s, "okzw ca ybw abzgjyfoa wrsnmmr", "polyalpha");
	//polyalpha_decr(s, 29);
	//assert_str_eq(s, "used in the fifteenth century", "polyalpha");
}

void run_test_cryptography()
{
	test_caesar();
	test_polyalphabetic();
}
