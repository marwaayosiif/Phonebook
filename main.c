#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include "PhoneBook.h"

struct person
{
    char name[35];
    char phoneNumber[20];
    char mail[100];

};

int main()
{
    system("cls");
    printf("PHONE BOOK\n\n");
    printf("1. Add Contact\n");
    printf("2. Delete Contact\n");
    printf("3. Search Contact By Name\n");
    printf("4. Search Contact By Phone Number\n");
    printf("5. Edit Contact\n");
    printf("6. Show All Contacts\n");
    printf("7. Exit\n\n");
    printf("Enter Your Choice:");
    int option;
    scanf("%d",&option);

    switch(option)
    {
    case 1:
        add_contact();
        break;
    case 2:
        delete_contact();
        break;
    case 3:
        search_contact_name();
        break;
    case 4:
        search_contact_number();
        break;
    case 5:
        modify_contact();
        break;
    case 6:
        show_all_Contacts();
        break;
    case 7:
        exit(0);
    default:
        main();
    }

}

void show_all_Contacts(){

    FILE *fp;
    fp=fopen("PhoneBook.txt","r");
    system("cls");
    printf("SHOW ALL CONTACT\n\n");
    int i =1 ;
    struct person p;
    while(fscanf(fp,"%s %s %s",&p.name,&p.phoneNumber,&p.mail)!=EOF)
    {

            printf("Contact %d\n" ,i);
            printf("\nName: %s",&p.name);
            printf("\nPhone Number: %s",&p.phoneNumber);
            printf("\nEmail: %s\n\n",&p.mail);
            i++;

    }
    fclose(fp);
    printf("\nPRESS ANY KEY TO CONTINUE");
    getch();
    main();
}

void modify_contact(){

    FILE *fp,*fp1;
    fp=fopen("PhoneBook.txt","r+");
    fp1=fopen("temp.txt","w");
    system("cls");
    printf("Modify Contact\n\n");
    printf("Enter Name to be modified: ");
    char name[20];
    scanf("%s",name);
    struct person p;
    struct person p1;
    while(fscanf(fp,"%s %s %s",&p.name,&p.phoneNumber,&p.mail)!=EOF)
    {
        if(strcmp(name,&p.name)==0)
        {
            printf("\nEnter Name: ");
            scanf("%s",&p1.name);
            printf("\nEnter Phone: ");
            scanf("%s",&p1.phoneNumber);
            printf("\nEnter Email: ");
            scanf("%s",&p1.mail);
            fprintf(fp1,"%s %s %s\n",&p1.name,&p1.phoneNumber,&p1.mail);
            continue;
        }
        fprintf(fp1,"%s %s %s\n",&p.name,&p.phoneNumber,&p.mail);
    }
    fclose(fp);
    fclose(fp1);
    fp=fopen("PhoneBook.txt","w");
    fp1=fopen("temp.txt","r");
    while(fscanf(fp1,"%s %s %s",&p.name,&p.phoneNumber,&p.mail)!=EOF)
    {
        fprintf(fp,"%s %s %s\n",&p.name,&p.phoneNumber,&p.mail);


    }
    /*printf("\nEnter Name: ");
    scanf("%s",&p1.name);
    printf("\nEnter Phone: ");
    scanf("%s",&p1.phoneNumber);
    printf("\nEnter Email: ");
    scanf("%s",&p1.mail);
    fprintf(fp,"%s %s %s\n",&p1.name,&p1.phoneNumber,&p1.mail);*/
    fclose(fp);
    fclose(fp1);
    remove("temp.txt");
    printf("\nPRESS ANY KEY TO CONTINUE");
    getch();
    main();
}

void search_contact_name(){

    FILE *fp;
    fp=fopen("PhoneBook.txt","r");
    system("cls");
    printf("SEARCH CONTACT By Name\n\n");
    printf("Enter Name: ");
    char name[20];
    scanf("%s",name);
    struct person p;
    while(fscanf(fp,"%s %s %s",&p.name,&p.phoneNumber,&p.mail)!=EOF)
    {
        if(strcmp(name,&p.name)==0)
        {
            printf("\nName: %s\n",&p.name);
            printf("\nPhone Number: %s\n",&p.phoneNumber);
            printf("\nEmail: %s\n",&p.mail);
        }
    }
    fclose(fp);
    printf("\nPRESS ANY KEY TO CONTINUE");
    getch();
    main();
}

void search_contact_number(){

    FILE *fp;
    fp=fopen("PhoneBook.txt","r");
    system("cls");
    printf("SEARCH CONTACT By Number\n\n");
    printf("Enter Phone Number: ");
    char PhoneNumber[20];
    scanf("%s",PhoneNumber);
    struct person p;
    while(fscanf(fp,"%s %s %s",&p.name,&p.phoneNumber,&p.mail)!=EOF)
    {
        if(strcmp(PhoneNumber,&p.phoneNumber)==0)
        {
            printf("\nName: %s\n",&p.name);
            printf("\nPhone Number: %s\n",&p.phoneNumber);
            printf("\nEmail: %s\n",&p.mail);
        }
    }
    fclose(fp);
    printf("\nPRESS ANY KEY TO CONTINUE");
    getch();
    main();
}

void delete_contact(){
    FILE *fp,*fp1;
    fp=fopen("PhoneBook.txt","r+");
    fp1=fopen("temp.txt","w");
    system("cls");
    printf("DELETE CONTACT\n\n");
    printf("Enter Name: ");
    char name[20];
    scanf("%s",name);
    struct person p;
    while(fscanf(fp,"%s %s %s",&p.name,&p.phoneNumber,&p.mail)!=EOF)
    {
        if(strcmp(name,&p.name)==0)
        {
            continue;
        }
        fprintf(fp1,"%s %s %s\n",&p.name,&p.phoneNumber,&p.mail);
    }
    fclose(fp);
    fclose(fp1);
    fp=fopen("PhoneBook.txt","w");
    fp1=fopen("temp.txt","r");
    while(fscanf(fp1,"%s %s %s",&p.name,&p.phoneNumber,&p.mail)!=EOF)
    {

        fprintf(fp,"%s %s %s\n",&p.name,&p.phoneNumber,&p.mail);
    }
    fclose(fp);
    fclose(fp1);
    remove("temp.txt");
    printf("\nPRESS ANY KEY TO CONTINUE");
    getch();
    main();
}

void add_contact(){
    struct person p;
    FILE *fp;
    fp=fopen("PhoneBook.txt","ab+");
    system("cls");
    printf("ADD CONTACT\n\n");
    printf("\nName:");
    scanf("%s",&p.name);
    printf("\nPhone Number:");
    scanf("%s",&p.phoneNumber);
    printf("\nEmail:");
    scanf("%s",&p.mail);
    fprintf(fp,"%s %s %s\n",&p.name,&p.phoneNumber,&p.mail);
    fclose(fp);
    printf("\nPRESS ANY KEY TO CONTINUE");
    getch();
    main();
}






