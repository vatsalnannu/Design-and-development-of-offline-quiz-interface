#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include<ctype.h>
#include<dos.h>
#include<windows.h>
#include<conio.h>
FILE* fp1;
int total;
char ch;
char name[20];
int count1=0;
int change=1;
int random[10];
FILE *fp;
int choose_answer2(int q){
    printf("\nChoose your answer\n");
	char u_ans;
	char ch=_getch();
	u_ans = toupper(ch);
	char answer[10] = {'A','A','A','A','A','A','A','A','A','A'};
	int i;
	int total = 0;
	for(i=0;i<10;i++)
	{

		if(i==(q-1))
		{
			if(answer[i]==u_ans)
				{
				    printf("\nYou Choose %c\n",u_ans);
					printf("Correct answer. \n \n Press enter for next question.");
					total += 4;
					if(change>=3){

					}
					else
                    change++;
				}
			else if(answer[i]!=u_ans)
			{
			    printf("\nYou Choose %c\n",u_ans);
				printf("Wrong Answer. \n \n Press enter for next question.");
				total -= 1;
				if(change==1)
                {

                }

                else{
                        change--;
                }

			}
		}
	}
	return total;
}

void again() //function to ask to play again
{
    printf("Do you want to play again Y or N\n");
    char aga;
     aga=_getch();
    char l = toupper(aga);
    if(l=='Y')
    {
        menu();
        fp1 = fopen("F:/UPES/MINOR PROJECT/Files/scoreboard.txt","a");
        fprintf(fp1,"%s",name);
        fclose(fp1);
    }
    else if(l=='N')
    {
        exit(0);
    }
    else
    {
        printf("Invaild option\n");
        again();
    }
}
void timer() //timer to attempt the question.
{
    int x;
    printf("\nTime left : ");

    for(x=10;x>0;x--)
    {
        if(_kbhit())
        {
            ch=_getch();
            break;
        }
        else if(x==1)
        {
            printf("%d \nTime is up \n ",x);
            total=total-1;
            break;
        }
        else
        {
            printf("%d ",x);
            Sleep(1000);
        }
    }

}
//Function for giving instruction
void instruction(){
	printf("\n\nHere are some instructions about quiz, please read them carefully :\n\n1. The quiz consist 10 question. \n2. Each of 4 marks. \n3. Negative marking is there i.e. for every wrong answer 1 mark will be deducted. \n4. There are four level you can choose any one of them. \n \n ");
    printf("Press < M > to go to Main Menu");
    _getch();
    system("cls");
    menu();
}
int choose_answer(int q){
    printf("\nChoose your answer\n");
	char u_ans;
	char array[256];
	FILE *fp;
	timer();
	u_ans = toupper(ch);
	char answer[10] = {'A','A','A','A','A','A','A','A','A','A'};
	int i;
	total = 0;
	for(i=0;i<10;i++)
	{

		if(i==(q-1))
		{
			if(answer[i]==u_ans)
				{
				    printf("\nYou Choose %c\n",u_ans);
					printf("Correct answer. \n ");
					total += 4;
				}
			else
			{
			    printf("\nYou Choose %c\n",u_ans);
				printf("Wrong Answer. \n ");
				total -= 1;
			}
		}
	}
	fp = fopen("F:/UPES/MINOR PROJECT/Files/Rea1.txt","r");
		 int a=0;
		 while (fgets(array, sizeof(array), fp)) {
                a++;
      if(q==(a-1))
       {
            printf("%s",array);
       }
	}
	printf("press enter for next question.\n");
	return total;
}
int randomNumber(int random[])
{
	int random1;
	int p;
	int i,j;
	srand(time(0));
	for(i = 0; i < 10; i++) {
	     do {
	        p = 1;
	        random1 = rand() % 10 + 1;
	        for (j = 0; j < i && p == 1; j++) {
	           if (random[j] == random1) {
	              p = 0;
	           }
	        }
	     } while (p != 1);
	     random[i] = random1;
	}
	return random;
}
//Function for opening quiz
void level1(){
	FILE* fp;
    int ques;
    char array[256];
	int i,count=0;
	int q,h,random_q[4],j,val,a,k;
	randomNumber(random);
i = 0;
j = 0;
for( k=0;k<10;k++)
{
	printf("%d.",k+1);
    fp = fopen("F:/UPES/MINOR PROJECT/Files/level1.txt","r");
    for( a=1;a<=10;a++)
    {
    i=0;
    int ques=random[k];
    if(random[k]==a)
    {
        a=(a*5)+1;
        while (fgets(array, sizeof(array), fp)) {
        i++;
        if(i == a || i==a+1 || i==a+2 || i==a+3 || i==a+4)
        {
            printf("%s",array);
        }
    }
    count = count + choose_answer(ques);
    _getch();
    system("cls");
    }
    }
}
printf("Your final score is : %d\n",count);
fp1 = fopen("F:/UPES/MINOR PROJECT/Files/scoreboard.txt","a");
fprintf(fp1,"\n%d ",total);
fclose(fp);
}
void level2(){
	FILE* fp;
    int ques;
    char array[256];
	int i,count=0;
	int q,h,random_q[4],j,val,a,k;
	randomNumber(random);
i = 0;
j = 0;
for( k=0;k<10;k++)
{
	printf("%d.",k+1);
    fp = fopen("F:/UPES/MINOR PROJECT/Files/level2.txt","r");
    for( a=1;a<=10;a++)
    {
    i=0;

    int ques=random[k];
    if(random[k]==a)
    {
        a=(a*5)+1;
        while (fgets(array, sizeof(array), fp)) {
        i++;
        if(i == a || i==a+1 || i==a+2 || i==a+3 || i==a+4)
        {
            printf("%s",array);
        }
    }
    count = count + choose_answer(ques);
    _getch();
    system("cls");

    }

    }

}
printf("Your final score is : %d\n",count);
fp1 = fopen("F:/UPES/MINOR PROJECT/Files/scoreboard.txt","a");
fprintf(fp1,"\n%d ",total);
fclose(fp);
}
void level3(){
	FILE* fp;
    int ques;
    char array[256];
	int i,count=0;
	int q,h,random_q[4],j,val,a,k;
	randomNumber(random);
i = 0;
j = 0;
for( k=0;k<10;k++)
{
	printf("%d.",k+1);
    fp = fopen("F:/UPES/MINOR PROJECT/Files/level3.txt","r");
    for( a=1;a<=10;a++)
    {
    i=0;

    int ques=random[k];
    if(random[k]==a)
    {
        a=(a*5)+1;
        while (fgets(array, sizeof(array), fp)) {
        i++;
        if(i == a || i==a+1 || i==a+2 || i==a+3 || i==a+4)
        {
            printf("%s",array);
        }
    }
    count = count + choose_answer(ques);
    _getch();
    system("cls");

    }

    }

}
printf("Your final score is : %d\n",count);
fp1 = fopen("F:/UPES/MINOR PROJECT/Files/scoreboard.txt","a");
fprintf(fp1,"Score = %d",count);
fclose(fp1);
fclose(fp);
}
void mixQues()
{
     int ques;
    char array[256];
	int i,count=0;
	int q,h,random_q[4],j,val,a,k;
	randomNumber(random);
	i=0;
	j=0;
for( k=0;k<10;k++)
{
	printf("%d.",k+1);
	if(change==1)
    {
        fp = fopen("F:/UPES/MINOR PROJECT/Files/level1.txt","r");
        for( a=1;a<=10;a++)
        {
            i=0;
            int ques=random[k];
            if(random[k]==a)
            {
                a=(a*5)+1;
                while (fgets(array, sizeof(array), fp)) {
                i++;
                if(i == a || i==a+1 || i==a+2 || i==a+3 || i==a+4)
                {
                    printf("%s",array);
                }
            }
            count = count + choose_answer2(ques);
            _getch();
            system("cls");
            }
        }
}
	else if(change==2)
    {
        fp = fopen("F:/UPES/MINOR PROJECT/Files/level2.txt","r");
        for( a=1;a<=10;a++)
        {
            i=0;
            int ques=random[k];
            if(random[k]==a)
            {
                a=(a*5)+1;
                while (fgets(array, sizeof(array), fp)) {
                i++;
                if(i == a || i==a+1 || i==a+2 || i==a+3 || i==a+4)
                {
                    printf("%s",array);
                }
            }
            count = count + choose_answer2(ques);
            _getch();
            system("cls");
            }
        }
}
	else if(change==3)
    {
        fp = fopen("F:/UPES/MINOR PROJECT/Files/level3.txt","r");
        for( a=1;a<=10;a++)
        {
            i=0;
            int ques=random[k];
            if(random[k]==a)
            {
                a=(a*5)+1;
                while (fgets(array, sizeof(array), fp)) {
                i++;
                if(i == a || i==a+1 || i==a+2 || i==a+3 || i==a+4)
                {
                    printf("%s",array);
                }
            }
            count = count + choose_answer2(ques);
            _getch();
            system("cls");
            }
        }
}
}
printf("Your final score is : %d",count);
fclose(fp);
}




// Function to choose level
void level(name){
	int choose;
	printf("Please select level (Choose 1,2 or 3) \n 1. Basic \n 2. Intermediate \n 3. Hard \n 4. Mix Level \n");
	choose=_getch();

	again:  //for goto function

		if(choose == '1')
		{
			printf("You choose Basic level \n \n");
			printf("Press any key to go to your quiz \n");
			_getch();
			system("cls");
			level1();
		}
		else
		{
		if(choose == '2'){
		printf("You choose Inermediate level \n \n");
		printf("Press any key to go to your quiz \n");
		_getch();
		system("cls");
		level2();
		}
		else
		{
		if(choose=='3'){
			printf("You choose Hard level \n \n");
			printf("Press any key to go to your quiz \n");
			_getch();
			system("cls");
			level3();
		}
		else
		{
		if(choose=='4'){
			printf("You choose Mix level \n \n");
			printf("Press any key to go to your quiz \n");
			_getch();
			system("cls");
			mixQues();
		}

		else
		{
		printf("Invalid choice. Please select level agaain\n 1. Basic \n 2. Intermediate \n 3. Hard \n \n");

		goto again;
	}
	}
	}
	}

}
void enter_name()
{
	printf("Enter your name : \n");
	gets(name);
	system("cls");
	fp1 = fopen("F:/UPES/MINOR PROJECT/Files/scoreboard.txt","a");
	fprintf(fp1,"%s",name);
    fclose(fp1);
}
//Function of welcome page
void welcome(){
	printf("***************************************************************************************\n");
	printf("***************************************************************************************\n");
	printf("**                                                                                   **\n");
	printf("**                                                                                   **\n");
	printf("**                                                                                   **\n");
	printf("**                                                                                   **\n");
	printf("**                                Welcome                                            ** \n");
	printf("**                          This is BD Quizzor                                       ** \n");
	printf("**                                                                                   **\n");
	printf("**                                                                                   **\n");
	printf("**                                                                                   ** \n");
	printf("**                                                                                   ** \n");
    printf("***************************************************************************************\n");
    printf("***************************************************************************************\n");
}
void toppers(){
   FILE *fp;
char c;
fp=fopen("F:/UPES/MINOR PROJECT/Files/scoreboard.txt","r");
while((c=fgetc(fp))!=EOF){
printf("%c",c);
}
fclose(fp);
   printf("\nPress < M > to go to Main Menu");
    _getch();
    system("cls");
    menu();
}
void menu(){
    if(count1==0)
    {
            printf("Welcome to the Game %s \n Nice to see you !! \n \n",name);
            count1++;
    }
    printf("\t\t\tMain Menu\t\t\t");
    printf("\nPress < S > to Start Game");
    printf("\nPress < R > for Rules");
    printf("\nPress < T > for Top Scorers");
    printf("\nPress < E > to Exit Game");
    char z;
    z=_getch();
    char letter = toupper(z);
    if(letter=='S'){
        system("cls");
        level(name);
    }
    else if(letter=='R'){
        system("cls");
        instruction();
    }
    else if(letter=='T'){
        system("cls");
        toppers();
    }
    else{
        exit(0);
    }
}
int main(int argc, char *argv[]) {
    system("COLOR B0");
    welcome();
	printf("Press any key to continue");
	_getch();
	system("cls");
	enter_name();
	menu();
	again();
	return 0;

}
