#include <stdio.h>

struct Question {
    char text[200];
    char options[4][50];
    int correct_option;
};

int main() {
    struct Question quiz[3] = {
        {
            "Which programming language is known as the mother of all languages?",
            {"1. Java", "2. Python", "3. C", "4. C++"},
            3
        },
        {
            "What is the size of an int data type in C (typically on 32/64 bit systems)?",
            {"1. 1 Byte", "2. 2 Bytes", "3. 4 Bytes", "4. 8 Bytes"},
            3
        },
        {
            "Which of the following is not a valid loop structure in C?",
            {"1. for", "2. while", "3. do-while", "4. foreach"},
            4
        }
    };

    int total_questions = 3;
    int score = 0;
    int user_answer;

    printf("======================================\n");
    printf("         WELCOME TO THE QUIZ          \n");
    printf("======================================\n\n");

    for (int i = 0; i < total_questions; i++) {
        printf("Question %d: %s\n", i + 1, quiz[i].text);
        
        for (int j = 0; j < 4; j++) {
            printf("%s\n", quiz[i].options[j]);
        }

        printf("Your answer (1-4): ");
        
        if (scanf("%d", &user_answer) != 1) {
            printf("\nInvalid input detected! Automatic 0 points for this question.\n");
            while (getchar() != '\n'); 
            printf("--------------------------------------\n\n");
            continue;
        }

        if (user_answer == quiz[i].correct_option) {
            printf("Correct Answer!\n\n");
            score++;
        } else {
            printf("Wrong! The correct answer was option %d.\n\n", quiz[i].correct_option);
        }
        printf("--------------------------------------\n\n");
    }

    printf("======================================\n");
    printf("             QUIZ OVER!               \n");
    printf("======================================\n");
    printf("Your Final Score: %d out of %d\n", score, total_questions);
    
    double percentage = ((double)score / total_questions) * 100;
    printf("Percentage: %.2f%%\n", percentage);

    return 0;
}