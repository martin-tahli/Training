/*3. По зададено естествено число N, да се намерят всички двойки естествени числа М и К, за
които
М2+К2=N.*/

#include <stdio.h>
#include<math.h>

int main(){


int n;
	scanf("%d", &n);
	int i, j;

	for(i = 0; i < n; i++) {
		for(j = 0; j < i; j++) {
			if((i * 2 + j * 2) == n)
				printf("%d*2 + %d*2 = %d\n", i, j, n);
		}
	}

    for(i = 0; i < n; i++) {
        for(j = 0; j < i; j++) {
            if((pow(i,2) +pow( j,2)) == n)
				printf("%d*2 + %d*2 = %d\n", i, j, n);
        }
    }


return 0;
}
