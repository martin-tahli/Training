/*8*) Намерете позицията на най-старшия бит, който е със
стойност 1 в дадено число.*/


#include <stdio.h>

int main() {
	int example = 16;
	int i;
	int mask = 1;
	int lastPosition = -1;

	for(i = 1; i <= 32; i++) {
		if(example & mask) {
			lastPosition = i;
		}
		mask = mask << 1;
	}

	printf("%d", lastPosition);

	return 0;
}
