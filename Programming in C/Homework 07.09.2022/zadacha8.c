/*Да се напише програма, която реализира играта Бикове и Крави
1234
2156 → 2 крави
1256 → 2 бика
1247 → 2 бика 1 крава
*/


#include<stdio.h>

int main(){

int number,i,j,guess;

printf("Enter starting number 4 digits\n");
scanf("%d",&number);


	int numberArray[] = {
		number / 1000 % 10,
		number / 100 % 10,
		number / 10  % 10,
        number % 10
        };

	while(1) {
        printf("enter guess 4 digits \n");
		scanf("%d", &guess);
		if(guess == number)break;

		int arrGuess[] = {
		guess / 1000 % 10,
		guess / 100 % 10,
		guess / 10  % 10,
		guess % 10
		};

		int kravi = 0;
		int bikove = 0;
		int bikovePos[] = {0, 0, 0, 0};


		for(i = 0; i < 4; i++) {
        if(numberArray[i] == arrGuess[i]) {
		bikove++;
		bikovePos[i] = 1;
		}
		}

		for(i = 0; i < 4; i++) {
        for(j = 0; j < 4; j++) {

		if(numberArray[i] == arrGuess[j] && bikovePos[i] == 0)
		kravi++;
		}
		}

		printf("Kravi= %d\nbikove = %d\n\n", kravi, bikove);
	}
	printf("\n Winner winner chicken dinner!");

}
