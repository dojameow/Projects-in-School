#include<stdio.h>
#include<conio.h>
#include<process.h>

void AddRecord();
void SeeRecord();

int main(){
int choice,exit=0;
while(exit!=1){
system("cls");
printf("1. Add Record\n");
printf("2. See Record\n");
printf("0. Exit\n");
printf("Enter your choice: ");
scanf("%d",&choice);

switch(choice){
case 1: AddRecord();break;
case 2: SeeRecord();break;
case 0: exit=1;break;
default: printf("\nInvalid Input!");
}
}
}

void AddRecord(){
    system("cls");
    char studentnum[15],firstname[20],lastname[20];
    char gender;
    FILE *fp;
    fp=fopen("LIM.txt","a");
    printf("\nEnter Student Number: ");
    scanf("%s",&studentnum);
    printf("\nEnter First Name: ");
    scanf("%s",&firstname);
    printf("\nEnter Last Name: ");
    scanf("%s",&lastname);
    printf("\nEnter Gender (F or M): ");
    scanf("%c",&gender);
    scanf("%c",&gender);

    fprintf(fp,"%s\n%s %s\n%c\n",studentnum,firstname,lastname,gender);
    printf("\nRecord Successfully Added!");
    fclose(fp);
    system("pause");
}

void SeeRecord(){
    system("cls");
    FILE *fp;
    fp=fopen("LIM.txt","r");
    char i;
    i=fgetc(fp);
    while(i!=EOF){
        printf("%c",i);
        i=fgetc(fp);
    }
    fclose(fp);
    system("pause");
}



