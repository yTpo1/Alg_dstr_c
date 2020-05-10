static int SHIFT = 3;

char caesar_encrypt_char(char c)
{
	return (c + SHIFT);
}

char caesar_decrypt_char(char c)
{
	return (c - SHIFT);
}

void caesar_encrypt_str(char *s, int len)
{
	for (int i = 0; i < len; i++)
		s[i] = caesar_encrypt_char(s[i]);
}

void caesar_decrypt_str(char *s, int len)
{
	for (int i = 0; i < len; i++)
		s[i] = caesar_decrypt_char(s[i]);
}
