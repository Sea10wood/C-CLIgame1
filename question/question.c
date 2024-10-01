#include <stdio.h>
#include "./question.h"

int show_question(const char* prompt, const char* choices[], int num_choices) {
    printf("%s\n", prompt);
    for (int i = 0; i < num_choices; i++) {
        printf("%d. %s\n", i + 1, choices[i]);
    }

    int selection;
    while (1) {
        printf("番号を入力してください: ");
        if (scanf("%d", &selection) == 1 && selection >= 1 && selection <= num_choices) {
            return selection;  
        } else {
            printf("無効な番号です。再入力してください。\n");
        }
    }
}
