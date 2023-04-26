//11*) Разбийте число като сума от степени на двойката

#include <stdio.h>
#include <math.h>

int main() {
	int example = 65;
	int mask = 1;
	int i;

	for(i = 0; i < 32; i++) {
		if(example & mask) {
			int curr = pow(2, i);
			printf("%d ", curr);
		}
		mask = mask << 1;
	}

	return 0;
}
