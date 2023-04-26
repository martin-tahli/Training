//	Напишете програма PrintPatterns, която отпечата следните текстови графики
//	на екрана. Пирамида ,обърната пирамида и ромб


#include <stdio.h>



int main() {



   int i, j, space, k = 0;;

   for (i = 6; i >= 1; --i) {
      for (space = 0; space < 6 - i; ++space)
         printf("  ");
      for (j = i; j <= 2 * i - 1; ++j)
         printf("# ");
      for (j = 0; j < i - 1; ++j)
         printf("# ");
      printf("\n");
   }


   for (i = 1; i <= 6; ++i, k = 0) {
      for (space = 1; space <= 6 - i; ++space) {
         printf("  ");
      }
      while (k != 2 * i - 1) {
         printf("# ");
         ++k;
      }
      printf("\n");
   }


 for (i = 1; i <= 6; ++i, k = 0) {
      for (space = 1; space <= 6 - i; ++space) {
         printf("  ");
      }
      while (k != 2 * i - 1) {
         printf("# ");
         ++k;
      }
      printf("\n");
   }
for (i = 6; i >= 1; --i) {
      for (space = 0; space < 6 - i; ++space)
         printf("  ");
      for (j = i; j <= 2 * i - 1; ++j)
         printf("# ");
      for (j = 0; j < i - 1; ++j)
         printf("# ");
      printf("\n");
   }



   return 0;
}
