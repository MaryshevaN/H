#include <stdlib.h>
#include <stdio.h>
#define MAXLENGHT 256

int scan_bin_to_array(char*);
int bin_to_dec(char*);
void enter_binary_array(char**, int);
void print_bin_array(char**, int);
void print_dec_array(char*, int);


int main() {
	int n;
	printf("Enter num of binary array elements: ");
	scanf("%d", &n);
	getchar();

	
	char* array_dec = malloc(n*sizeof(int));
	
	char** array_bin = malloc(n*sizeof(char*));
	for (int i = 0; i < n; ++i) {
		array_bin[i] = malloc(MAXLENGHT*sizeof(char));
	}
	
	
	enter_binary_array(array_bin, n);
	
	
	for (int i = 0; i < n; ++i) {
		array_dec[i] = bin_to_dec(array_bin[i]);
	}
	
	
	print_bin_array(array_bin, n);
	print_dec_array(array_dec, n);
	return 0;
}


int scan_bin_to_array(char* bin) {
    int error = 0;
	char bin_symb;
	int pointer = 0;
	while ((bin_symb = getchar())!='\n')
		if ((bin_symb == '1')||(bin_symb == '0'))
			bin[pointer++] = bin_symb;
		else {
		    error = -1;
		}
	bin[pointer++] = '\0';
	if (error == -1) {
	    printf("You can use onle 1 or 0 in binary number! Try again...\n");
		return -1;
	}
	return 0;
}


int bin_to_dec(char* bin) {
	char bin_symb;
	int dec = 0;
	int pointer = 0;
	while ((bin_symb = bin[pointer++])!='\0')
		if ((bin_symb == '1')||(bin_symb == '0')) {
			dec*=2;
			dec+= bin_symb-'0';
		}
	return dec;
}


void enter_binary_array(char** array_bin, int n) {
	printf("Enter elements:\n");
	for (int i = 0; i < n; ++i) {
		printf(" [%d]: ", i+1);
		int error = scan_bin_to_array(array_bin[i]);
		while (error != 0) {
		    printf(" [%d]: ", i+1);
		    error = scan_bin_to_array(array_bin[i]);
		}
	}
}


void print_bin_array(char** array_bin, int n) {
	printf("\nBinary numbers array:\n");
	for (int i = 0; i < n; ++i) {
		printf(" [%d]: %s\n", i+1, array_bin[i]);
	}
}


void print_dec_array(char* array_dec, int n) {
	printf("\nDecimal numbers array:\n");
	for (int i = 0; i < n; ++i) {
		printf(" [%d]: %d\n", i+1, array_dec[i]);
	}
}
