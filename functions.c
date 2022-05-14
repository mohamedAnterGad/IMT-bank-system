#include "functions.h"

typedef struct client{
    char FullName[MAX_SIZE_NAME];
    char Address[MAX_SIZE];
    char NationalID[MAX_SIZE];
	char guardian_id[MAX_SIZE];
    int Age;
    int CountID;
	char password[MAX_SIZE];
	

}Client;

void gotoxy(int x, int y){
    COORD c = { x, y };  
    SetConsoleCursorPosition(  GetStdHandle(STD_OUTPUT_HANDLE) , c);
}

void welcome_screen(void){
	
    system("cls");
    //SetConsoleCursorPosition(38,2);
    //clrscr();
    
    gotoxy(40, 2);
    printf("... Welcome in Our Bank System ...");
    
    gotoxy(45, 3);
    printf("\n  \t\t\t\t\t\t 1. Admin Window \n \t\t\t\t\t\t 2. User Window");    


	char option;
    printf("\n \n Choose Window : ");
    option = getch();
    printf("%c \n",option);
    switch(option)
    {
        case '1':
            Admin();
            //system("cls");
           
			
            break;
        case '2':
            User();
            break;
    }
	
	
}

void Admin(){
	char username[20]; 
    char password[20]; 
	
    system("cls");
    printf("\n");
    gotoxy(44, 3);
    printf("~~ Welcome in Admin Window ~~");
    gotoxy(44, 4);
    printf("-----------------------------");
	
	   //system("cls");
            gotoxy(44, 7);
            printf(".Enter your username:\t"); 
            scanf("%s",&username); 
            
            gotoxy(44, 9);
            printf(".Enter your password:\t"); 
            scanf("%s",&password); // the same as password (without &) 
			
			//printf("*username = %c",*username);
			//printf("&username = %x",&username);
			//printf("username = %x",username);
            LoginAdmin(username, password);
			
			// choose feature if successful login
			//to be edited (check for sucessful login)
			int choice = choose_features_admin();
			switch (choice){
				case 1 :
					//create_new_account();
					break ;
	
	}
}

void User(){
    //system("cls");
    printf("\nWelcome in User Window\n");
}

                    // LOGIN Function //
void LoginAdmin(char* username, char* password){ 

    if(strcmp(username,"Heba")==0) //check name if right 
    { 
        // check password
        if(strcmp(password,"123")==0)
        { 
	//return 1 //valid
        printf("\nWelcome.Login Success!"); 
        }
        else{ 
		//return 0 // not valid
        printf("\nwrong password");
        } 
    }
    // If name wasn't right
    else
    { 
		//return 0 //not valid
        printf("\nUser doesn't exist"); 
    }
    
} 


                // Generate Password //
void Generate_Pass(int N){
    
    // int pass = rand();
    // printf("PassWord: %d",pass);
    // return pass;
     int i = 0;
  
    int randomizer = 0;
  
    // Seed the random-number generator
    // with current time so that the
    // numbers will be different every time
    srand((unsigned int)(time(NULL)));
  
    // Array of numbers
    char numbers[] = "0123456789";
    // Array of small alphabets
    char letter[] = "abcdefghijklmnoqprstuvwyzx";
    // Array of capital alphabets
    char LETTER[] = "ABCDEFGHIJKLMNOQPRSTUYWVZX";
    // Array of all the special symbols
    char symbols[] = "!@#$^&*?";
  
    // Stores the random password
    char password[N];
  
    // To select the randomizer
    // inside the loop
    randomizer = rand() % 4;
  
    // Iterate over the range [0, N]
    for (i = 0; i < N; i++) {
  
        if (randomizer == 1) {
            password[i] = numbers[rand() % 10];
            randomizer = rand() % 4;
            printf("%c", password[i]);
        }
        else if (randomizer == 2) {
            password[i] = symbols[rand() % 8];
            randomizer = rand() % 4;
            printf("%c", password[i]);
        }
        else if (randomizer == 3) {
            password[i] = LETTER[rand() % 26];
            randomizer = rand() % 4;
            printf("%c", password[i]);
        }
        else {
            password[i] = letter[rand() % 26];
            randomizer = rand() % 4;
            printf("%c", password[i]);
        }
    }
    //printf(password);
}


int Create_BankID(int bank_id){
    //printf("%c",bank_id);
    return bank_id++;
}

int Calc_Age(int birth_year){
    int current_year = 2022;
    int age = current_year - birth_year;
    return age;
}

int Check_Age(int age){
	/*
	INPUT : age
	OUTPUT : 0 : not valid age 
			 1 : valid age
			 
	FUNCITON : check if age < or equal 21
	*/
    if (age <= 21)
    {
		return 0;
    }
    else{
		return 1;
    }
}

char* input_guardian_id(void){
	/*
	INPUT : void
	OUTPUT : the guardian ID as a string
	FUNCITON : takes the guardian ID as input from the user
	*/
	static char guardian_id[MAX_SIZE];
	 printf("\nYou must have a guardian...");
     printf("\nPlease enter your guardian ID : ");
     scanf("%s",guardian_id);
	 return guardian_id;
}


int choose_features_admin(void){
	/*
	INPUT : void
	OUTPUT : 1 : create new account 
			 2 : open existing account
			 3 : exit the  system
			 else : to be handeled when calling the function (wrong input)
			 
	FUNCITON : to know whcich function the admin want to choose
	
	*/
	
	printf("choose the function: \n");
	printf("1. create new account\n");
	printf("2. open existing account\n");
	printf("3. exit the  system\n");
	int x = 0;
	printf("enter a number ");
	scanf("%d",&x);
	return x;
}

int check_valid_id(char* id){ 
	/* the input is a pointer to the string
		the output is 0 if id is not valid
		thr output is 1 if id is valid
	*/
	int flag2 = 0;
	int is_valid = 0;
	
	/* ******************************
	 **check the length of the id: ** 
	 ******************************** */
	int length = strlen(id);
	if ( length != 14){
		return 0;
	}
	/* **********************************
	 **check if all chars are integer: ** 
	 ************************************ */
	// get the size of the id
	for (int i=0;i<length; i++){
		char ch = id[i];
		if(!isdigit(ch)){
			return 0;
		}
	}
	
	//if you made it here then the id is valid
	return 1;
}
