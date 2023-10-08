#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// User Struct
typedef struct user{
    char *name;
    char *surname;
    char *nickname;
    int age;
    struct user *next;
}User;

User *root;

void getNewUserInfo(void);
void addUser(char *name, char *surname, char *nickname, int age);
void printUserInfo(User *u);
int selectProcess(void);
//Main funtion
int main(){
    root = (User*)malloc(sizeof(User));
    root->next = NULL;
    
    printf("Welcome!\n");
    
    int process;
    process = selectProcess();
    if(process == 1){
        getNewUserInfo();
    }
    while(selectProcess() == 2){
        printf("Sign In function is not available now! Please select other options.\n");
        selectProcess();
    }
    while(selectProcess() != 1 || selectProcess() != 2){
        printf("Wrong selection!");
    }

}

//Add new user
void addUser(char *name, char *surname, char *nickname, int age){
    User *iter;
    iter = root;
    while(iter -> next != NULL){
        iter = iter -> next;
    }

    iter -> next = (User*)malloc(sizeof(User));
    iter = iter ->next;
    //set user
    iter -> name = name;
    iter -> surname = surname;
    iter -> nickname = nickname;
    iter -> age = age;

    //set next to null
    iter -> next = NULL;

    printUserInfo(iter);
}
void printUserInfo(User *u){

    
    printf("Name : %s\n, SurName : %s\n, NickName : %s\n, Age : %d\n", u -> name, u -> surname, u -> nickname, u -> age);
   
}

void getNewUserInfo(){
    char name[24], surname[24], nickname[24]; 
    int age;
    

    printf("Enter your name: ");
    scanf("%s",name);

    printf("Enter your surname: ");
    scanf("%s",surname);
    
    printf("Enter your nickname: ");
    scanf("%s",nickname);

    printf("Enter your age: ");
    scanf("%d",&age);

    
    if(age >= 18){
        addUser(name,surname,nickname,age);
    }
    else{
        printf("You are under 18. You can't sign up!");
    }


}

int selectProcess(){
    int process;
    printf("1-Sign-up\n2- Sign-in\nSelect process number: ");
    scanf("%d",&process);
    return process;
}
