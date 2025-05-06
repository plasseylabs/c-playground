#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "lib.h"

char roman_digits(int n) {
	switch (n) {
	case 1:
		return 'I';
	case 5:
		return 'V';
	case 10:
		return 'X';
	case 50:
		return 'L';
	case 100:
		return 'C';
	case 500:
		return 'D';
	case 1000:
		return 'M';
	default:
		return '\0';
	}
}

char *intToRoman(int num) {
	char roman[20] = {0};
	int i = 0;
	while (num >= 1000) {
		roman[i++] = 'M';
		num -= 1000;
	}
	if (num >= 900) {
		roman[i++] = 'C';
		roman[i++] = 'M';
		num -= 900;
	}
	if (num >= 500) {
		roman[i++] = 'D';
		num -= 500;
	}
	if (num >= 400) {
		roman[i++] = 'C';
		roman[i++] = 'D';
		num -= 400;
	}
	while (num >= 100) {
		roman[i++] = 'C';
		num -= 100;
	}
	if (num >= 90) {
		roman[i++] = 'X';
		roman[i++] = 'C';
		num -= 90;
	}
	if (num >= 50) {
		roman[i++] = 'L';
		num -= 50;
	}
	if (num >= 40) {
		roman[i++] = 'X';
		roman[i++] = 'L';
		num -= 40;
	}
	while (num >= 10) {
		roman[i++] = 'X';
		num -= 10;
	}
	if (num >= 9) {
		roman[i++] = 'I';
		roman[i++] = 'X';
		num -= 9;
	}
	if (num >= 5) {
		roman[i++] = 'V';
		num -= 5;
	}
	if (num >= 4) {
		roman[i++] = 'I';
		roman[i++] = 'V';
		num -= 4;
	}
	while (num) {
		roman[i++] = 'I';
		num -= 1;
	}

	char *result = (char *)malloc((strlen(roman) + 1) * sizeof(char *));
	strcpy(result, roman);
	return result;
}
