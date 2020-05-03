#include <stdio.h>

char encrypt_c(char c){
	return (c + 3);
}

char decrypt_c(char c){
	return (c - 3);
}

int main(int argc, char **argv){
	char *mess = NULL;
	size_t len = 0;
	int n = 0;
	int opt = 0;

	printf("Enter your message: ");
	n = getline(&mess, &len, stdin);
	printf("0 to encrypt\n1 to decrtypt\n");	
	opt = getchar();
	if(opt == '0' || opt == '1')
		opt = opt - '0';
	else{
		printf("Sorry. Only 0 and 1 are valid options");
		return 0;
	}

	for(int i = 0; i<n; i++){
		if(opt)
			printf("%c",decrypt_c(mess[i])); 
		else
			printf("%c",encrypt_c(mess[i])); 
	}
	printf("\n");

	return 0;
}
