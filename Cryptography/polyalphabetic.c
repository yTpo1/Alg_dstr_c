#include <stdio.h>
#define LEN 7
char word[LEN] = "trustme";

int poly_get_shift(char a)
{
	return a - 'a';
}

int get_char_val(char base, char cyph)
{
	/* ascii a = 97 z = 122 */
	int shift = 0;
	int rest = 0;
	shift = poly_get_shift(cyph);
	int new = base + shift;
	if (new > 122) {
		rest = new - 'z';
		new = 'a' + rest - 1;
	}
	return new;

	//int tbase = base - 97;
	//int tcyph = cyph - 97; 
	//int res = tbase + cyph;
	//if (res > 25)
	//	res = res - 25;
	//res = res + 97;
	//return res;
}

// TODO: if ascii value goes over z, then start over
void polyalpha_encr(char *s, int len)
{
	for (int i = 0, j = 0; i < len; i++, j++) {
		if (j == LEN)
			j = 0;
		//s[i] = s[i] + word[j];
		s[i] = get_char_val(s[i], word[j]);
	}
}

void polyalpha_decr(char *s, int len)
{
	for (int i = 0, j = 0; i < len; i++, j++) {
		if (j == LEN)
			j = 0;
		s[i] = s[i] - word[j];
	}
}
