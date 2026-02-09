#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void setColor(int c)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void header(const char *title)
{
    system("cls");
    setColor(11);
    printf("====================================\n");
    printf(" %s\n", title);
    printf("====================================\n");
    setColor(7);
}

int main()
{
    int choice;
    int guessScore = 0, rpsScore = 0, mathScore = 0;

    srand(time(0));

    do
    {
        header("MINI GAME CONSOLE");
        printf("1. Guess the Number\n");
        printf("2. Rock Paper Scissors\n");
        printf("3. Math Challenge\n");
        printf("4. Score Summary\n");
        printf("0. Exit\n\n");
        printf("Select Option: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            int hidden, guess, attempts = 0;

            header("GUESS THE NUMBER");
            printf("Set secret number (1 - 100): ");
            scanf("%d", &hidden);

            system("cls");

            while (1)
            {
                printf("ENTER THE HIDDEN NUMBER : ");
                scanf("%d", &guess);
                attempts++;

                if (guess < hidden)
                {
                    setColor(12);
                    printf("THE NUMBER U ENTER IS TOO LOW\n");
                }
                else if (guess > hidden)
                {
                    setColor(12);
                    printf("THE NUMBER U ENTER IS TOO HIGH\n");
                }
                else
                {
                    setColor(10);
                    printf("Correct in %d attempts\n", attempts);

                    if (attempts >= 1 && attempts <= 3)
                        guessScore += 15;
                    else if (attempts >= 4 && attempts <= 6)
                        guessScore += 10;
                    else if (attempts >= 7 && attempts <= 10)
                        guessScore += 5;
                    else
                        guessScore += 2;
                    break;
                }
                setColor(7);
            }
            system("pause");
            break;
        }

        case 2:
        {
            int user, comp, again = 1;

            while (again)
            {
                header("ROCK PAPER SCISSORS");

                do
                {
                    printf("1. Rock\n2. Paper\n3. Scissors\n\nChoose: ");
                    scanf("%d", &user);
                } while (user < 1 || user > 3);

                comp = rand() % 3 + 1;

                if (user == comp)
                {
                    setColor(14);
                    printf("Draw\n");
                }
                else if ((user == 1 && comp == 3) ||
                         (user == 2 && comp == 1) ||
                         (user == 3 && comp == 2))
                {
                    setColor(10);
                    printf("CONGRATULATIONS YOU WIN\n");
                    rpsScore += 5;
                }
                else
                {
                    setColor(12);
                    printf("BETTER LUCK NEXT TIME\n");
                }

                setColor(7);
                printf("\nPlay Again? (1=Yes 0=No): ");
                scanf("%d", &again);
            }
            break;
        }

        case 3:
        {
            int round = 1;

            while (round)
            {
                int correct = 0, streak = 0;

                header("MATH CHALLENGE");

                for (int i = 1; i <= 5; i++)
                {
                    int a = rand() % 10 + 1;
                    int b = rand() % 10 + 1;
                    int ans, result;
                    int op = rand() % 2;

                    printf("Q%d: ", i);

                    if (op == 0)
                    {
                        printf("%d + %d = ", a, b);
                        result = a + b;
                    }
                    else
                    {
                        printf("%d - %d = ", a, b);
                        result = a - b;
                    }

                    scanf("%d", &ans);

                    if (ans == result)
                    {
                        setColor(10);
                        printf("Correct\n");
                        correct++;
                        streak++;
                        mathScore += 5;

                        if (streak >= 3)
                            mathScore += 2;
                    }
                    else
                    {
                        setColor(12);
                        printf("POOR WRONG  (ANSWER : %d)\n", result);
                        streak = 0;
                    }
                    setColor(7);
                }

                header("ROUND RESULT");
                printf("TOTAL SCORE IS : %d / 5\n", correct);

                if (correct == 5)
                {
                    setColor(10);
                    printf("EXCELLENT PERFORMANCE PERFECT ROUND \n");
                    mathScore += 5;
                }
                else if (correct >= 3)
                {
                    setColor(14);
                    printf("GOOD PERFORMANCE\n");
                }
                else
                {
                    setColor(12);
                    printf("POOR PERFORMANCE TRY AGAIN\n");
                }

                setColor(7);
                printf("\nNext Round? (1=Yes 0=Menu): ");
                scanf("%d", &round);
            }
            break;
        }

        case 4:
            header("SCORE SUMMARY");
            printf("Guess Game Score : %d\n", guessScore);
            printf("RPS Score        : %d\n", rpsScore);
            printf("Math Score       : %d\n", mathScore);
            printf("------------------------------\n");
            printf("Total Score      : %d\n", guessScore + rpsScore + mathScore);
            system("pause");
            break;

        case 0:
            header("EXITING");
            printf("THANK YOU FOR PLAYING\n");
            break;

        default:
            printf("INVALID CHOICE PLEASE CHOOSE AGAIN ....\n");
            system("pause");
        }

    } while (choice != 0);

    return 0;
}
