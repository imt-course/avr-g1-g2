
long long int power (int num, unsigned int pow) {
	int i;
	long long int result = 1;
	if (num == 0) {
		result = 0;
	}
	else if (num != 1) {
		for (i=0; i<pow; i++) {
			result *= num;
		}
	}
	return result;
}
