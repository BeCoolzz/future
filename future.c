#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

struct DOB
{
    int yy;
    int mm;
    int dd;
};
struct player
{
    char name[20];
    char address[20];
    char aim[20];
    int intelligence;
    struct DOB date;
    int lck;
};

void ask(struct player *p);
int age(int yr);
int randno();
void futureintro(int);
void future1(int ran, int age);
void future2(int age);
void guess(int num);
int luck();
//int futurequetion();
int gender;

int main()
{
    

    struct player P, P2;
    char C;
    int a;
    FILE *fp;
start:
    fp = fopen("future.txt", "w+");
    if(fp == NULL)
    {
        printf("Couldn't open file or the file doesn't exist\n");
        exit(0);
    }
    else
    {
        ask(&P);
        a = age(P.date.yy);
        fwrite(&P, sizeof(struct player), 1, fp);
        printf("Data written successfully\n");
        rewind(fp);
        //printf("%d\n", a);
    
        gender:
            printf("------Chose your gender------\n\n\t-Male (Press M)\n\t-Female (Press F)\n\t-Other (Press O)\n");
            scanf(" %c", &C);

            // Choose gender and work accordingly
            switch (C)
            {
                case 'm':
                case 'M':
                    gender = 0;
                    printf("Hello! Mr.%s\n", (P.name));
                    futureintro(randno());
                    printf("\n");
                    future1(randno(), a);
                    sleep(5);
                    future2(a);
                    
                    
                    break;
                
                case 'f':
                case 'F':
                    gender = 1;
                    printf("Hello! Ms.%s\n", (P.name));
                    futureintro(randno());
                    printf("\n");
                    future1(randno(), a);
                    sleep(5);
                    future2(a);
                    break;

                case 'o':
                case 'O':
                    gender = 1;
                    printf("Hello! Mr.%s\n", (P.name));
                    futureintro(randno());
                    printf("\n");
                    future1(randno(), a);
                    sleep(5);
                    future2(a);
                    printf("bye\n");
                    break;

                default:
                    goto gender;
            }
    }
    fread(&P2, sizeof(struct player), 1, fp);
    printf("Name: %s\nAddress: %s\nAim: %s\nIntelligence: %d\nDOB: %d-%d-%d\nLuck: %d%%\n", P2.name, P2.address, P2.aim, P2.intelligence, P2.date.yy, P2.date.mm, P2.date.dd, P2.lck);
    fclose(fp); 
    return 0;
}

// Get personal information from the user
void ask(struct player *p)
{
    printf("Enter your name: ");
    scanf("%s", p -> name);
    printf("Enter your address: ");
    scanf("%s", p->address);
    printf("Your AIM?? ");
    scanf("%s", p->aim);
    printf("In the scale of (1 - 10) how would you specify your intelligence: ");
    scanf("%d", &(p->intelligence));
    printf("Enter your DOB in yy-mm-dd format: ");
    scanf("%d %d %d", &(p -> date.yy), &(p->date.mm), &(p->date.dd));
    (p->lck) = luck();
}
// Returns random number between 0 - 9
int randno()
{
    time_t t;
    t = time(NULL);
    t = t % 10;
    return t;
}

int luck()
{
    time_t t;
    t = time(NULL);
    t = t % 100;
    return t;
}

// Calculate age of person
int age(int yr)
{
    int y;
    if(yr<2010)
    {
        y = 2020 - yr;
    }
    else
    {
        y = 2076 - yr;
    }
    return y;
}

// Stylis intro at the execution of the program
void futureintro(int num)
{
    char intro[35] = "***** LOADING-YOUR-FUTURE *****";
    for(int i = 0; i < strlen(intro); i++)
    {
        printf("%c", intro[i]);
        usleep(350000);
        fflush(stdout);
    }
    printf("\n");  
}

// The first vawishyamani
void future1(int ran, int age)
{
    if(ran == 0)
    {
        printf("Your are likely to get diarrhea this week\n---> Be Safe <---\n");
    }
    if(ran == 1)
    {
        printf("You may get spanked by a girl this month\n---> Stay away from GIRLS <---\n");
    }
    if(ran == 2)
    {
        printf("You might get tea spilled on you\n---> Sorry TEA Lover <---\n");
    }
    if(ran == 3)
    {
        printf("You will have just your usual boring life until next month\n---> Dont lose HOPE <---\n");
    }
    if(ran == 4)
    {
        printf("The Toilet water and Toilet paper will run out when you are all alone\n---> Always carry a tissue paper with you <---\n");
    }
    if(ran == 5)
    {
        printf("You are likely to get water inside your nose while drinking\n---> Use Straw && dont put it inside your nose <---\n");
    }
    if(ran == 6)
    {
        printf("You may suffer from constipation if you dont control your diet\n---> Ohh! Now we know why you take your time in restroom <---\n");
    }
    if(ran == 7)
    {
        if(gender == 0) {
            printf("Lucky YOU! There is high chance a beautiful lady kisses you\n---> Here hits reality its a dream!! <---\n");
        } else
        {
            printf("Lucky YOU! There is high chance a handsome boy kisses you\n---> Here hits reality its a dream!! <---\n");
        }
        
    }
    if(ran == 8)
    {
        if(gender == 0) {
            printf("Your PANT may get torn right at the centr\n---> Dont forget your undies <---\n");
        } else {
            printf("You might slip due to banana pill\n---> Walk Carefully <---\n");
        }
    }
    if(ran == 9 && age < 25)
    {
        if(gender == 0){
            printf("Your thing might not work for few days in next few weeks\n---> Say NO to P*RN <---\n");
        } else
        {
            printf("You might suffer from headache\n---> Drink Hot Water <---");
        }
        

    }
}

void future2(int age)
{
    int count = 0, used[10], n;
    while(age < 60 && count < 10)
    {
        printf("\nBy the age of %d, ", age);
        for(int i = 0; i<10; i++)
        {
            n = randno();
            if (n != used[i])
            {
                used[i] = n;
                //guess(n); 
            }   
        }
        guess(n);
        sleep(3);
        age += randno();
        count++;
    }
}

void guess(int num)
{
    switch (num)
    {
    case 0:
        printf("You will have completed your formal eduction\n");
        break;
    case 1:
        printf("You will be married %d times\n", (randno())/2);
        break;
    case 2:
        printf("You will have %d children\n", randno());
        break;
    case 3:
        printf("You will be bald\n");
        break;
    case 4:
        printf("You will be fat as PIG\n");
        break;
    case 5:
        printf("You will be renowned person in NEPAL\n");
        break;
    case 6:
        printf("There is a high chance you will have your well established company\n");
        break;
    case 7:
        printf("You will start to seek a new way life\n");
        break;
    case 8:
        printf("You will have travelled different cuntries\n");
        break;
    case 9:
        if(gender == 0) {
            printf("You will have outcomed your fear of ladies\n");
        } else
        {
            printf("You will have outcomed your fear of failure\n");
        }
        break;
    }
}

void menu()
{
    int choice;
    printf("**** MENU ****\n1. Know Your Future\n2. See Previous Results\n3. Exit the Program");
    switch (choice)
    {
    case 1:
        
        break;
    case 2:
        break;
    default:
        break;
    }
}

// Questions related to course
//int futurequetion()