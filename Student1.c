#include<stdio.h>
#include<stdlib.h>
#include <string.h>
void adminPanel() {
    int choice;
    printf("\t\tAdmin Panel\n\n");
    printf("1. Add Employee\n");
    printf("2. Delete Employee\n");
    printf("3. Modify Employee\n");
    printf("4. Show All Employee\n");
    printf("5. Search Employee\n");
    printf("6. Logout\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            addEmployee();
            break;
        case 2:
            deleteEmployee();
            break;
        case 3:
            modifyEmployee();
            break;
        case 4:
            showStudent();
            break;
        case 5:
            searchStudent();
            break;
        case 6:
            printf("Logging out...\n");
            exit(0);
        default:
printf("Invalid choice. Please try again.\n");
            adminPanel();
    }
}

void login() {
    char username[20];
    char password[20];
    printf("\t\tLogin\n\n");
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", ok);

    if (strcmp(username, "admin") == 0 && strcmp(password, "password") == 0) {
        printf("Login successful!\n");
        adminPanel();
    } else {
        printf("Invalid username or password. Please try again.\n");
        login();
    }
}

int main() {
    login();
    return 0;
}

void addStudent();
void showStudent();
void searchStudent();
int autoid();
void deleteStudent();
void modifyStudent();
void showRecycle();
void recoverRecycle();
struct student
{
    int stud_id;
    char stud_name[30];
    char stud_clas[15];
    char stud_city[15];
    char stud_pno[15];
};

void addStudent()
{
    struct student s;
    FILE *fp;
    system("cls");
    printf("\t\tAdd Employee Module..\n\n");
    s.stud_id = autoid();
    printf("Enter Employee ID -- %d\n",s.stud_id);
    fflush(stdin);
    printf("Enter Employee Name -- ");
    scanf("%[^\n]s",&s.stud_name);
    fflush(stdin);
    printf("Enter Employee Class -- ");
    scanf("%[^\n]s",&s.stud_clas);
    fflush(stdin);
    printf("Enter Employee City -- ");
    scanf("%[^\n]s",&s.stud_city);
    fflush(stdin);
    printf("Enter Employee Phone Number -- ");
    scanf("%[^\n]s",&s.stud_pno);
    fflush(stdin);
    fp = fopen("student.txt","a+");
    fwrite(&s,sizeof(s),1,fp);
    printf("\n\nData Successfully Inserted");
    fclose(fp);
}
void showStudent()
{
    struct student s;
    FILE *fp;
    system("cls");
    printf("\t\tShow Employee Module..\n\n");
    if (!(fp = fopen("student.txt","r"))){
        printf("\n\nFile Not Exists..\n\n");
        return;
    }
    while (fread(&s,sizeof(s),1,fp)){

        printf("%d\t",s.stud_id);
        printf("%s\t",s.stud_name);
        printf("%s\t",s.stud_clas);
        printf("%s\t",s.stud_city);
        printf("%s\n\n",s.stud_pno);
    }
    printf("\n\n");
    fclose(fp);
}
void searchStudent()
{
    struct student s;
    int id,counter = 0;
    FILE *fp;
    system("cls");
    printf("\t\tSearch Employee Module..\n\n");
    if (!(fp = fopen("student.txt","r"))){
        printf("\n\nFile Not Exists..\n\n");
        return;
    }
    printf("Enter Employee ID -- ");
    scanf("%d",&id);
    while (fread(&s,sizeof(s),1,fp)){
        if ( s.stud_id == id){
            printf("%d\t",s.stud_id);
            printf("%s\t",s.stud_name);
            printf("%s\t",s.stud_clas);
            printf("%s\t",s.stud_city);
            printf("%s\n\n",s.stud_pno);
            counter = 1;
            //break;
        }
    }
    if ( counter == 0)
        printf("Data Not Found...");
    printf("\n\n");
    fclose(fp);
}

int autoid()
{
    struct student s;
    int id,counter = 0;
    FILE *fp;
    system("cls");
    if (!(fp = fopen("student.txt","r"))){
        counter = 101;
    }
    else{
        while (fread(&s,sizeof(s),1,fp)){
            if ( s.stud_id > counter)
                counter = s.stud_id;
        }
        counter++;
    }
    fclose(fp);
    return counter;
}
/*Delete Module start */
void deleteStudent()
{
    char c;
    struct student s;
    int id,counter = 0;
    FILE *fp,*fp1,*fp2;
    system("cls");
    printf("\t\tDelete Employee Module..\n\n");
    if (!(fp = fopen("student.txt","r"))){
        printf("\n\nFile Not Exists..\n\n");
        return;
    }
    printf("Enter Employee ID for Delete Record -- ");
    scanf("%d",&id);
    printf("\n\nEmployee Details are -- \n\n");
    fp1 = fopen("student_temp.txt","a+");
    while (fread(&s,sizeof(s),1,fp)){
        if ( s.stud_id == id){
            printf("Employee ID -- %d\n\n",s.stud_id);
            printf("Employee Name -- %s\n\n",s.stud_name);
            printf("Employee Class -- %s\n\n",s.stud_clas);
            printf("Employee City -- %s\n\n",s.stud_city);
            printf("Employee Phone No -- %s\n\n",s.stud_pno);
            counter = 1;
            printf("Do you want to Delete Record.. Press 1 else any key..");
            c = getch();
            if ( c == '1'){
                printf("\n\n1. Permanent Delete\t2. Temparory Delete\n\n");
                c = getch();
                if (c == '1'){
                    printf("\n\nData Successfully Deleted..\n\n");
                }
                else{
                    fp2=fopen("student_recycle.txt","a+");
                        fwrite(&s,sizeof(s),1,fp2);
                    fclose(fp2);
                    printf("\n\nData Successfully Deleted..\n\n");
                }
            }
            else{
                fwrite(&s,sizeof(s),1,fp1);
            }
        }
        else{
            fwrite(&s,sizeof(s),1,fp1);
        }
    }
    if ( counter == 0)
        printf("Data Not Found...");
    printf("\n\n");
    fclose(fp1);
    fclose(fp);
    remove("student.txt");
    rename("student_temp.txt","student.txt");
}
/*Delete Module End*/
/*Show Recycle start*/

void showRecycle()
{
    struct student s;
    FILE *fp;
    system("cls");
    printf("\t\tShow Recycle Bin Module..\n\n");
    if (!(fp = fopen("student_recycle.txt","r"))){
        printf("\n\nFile Not Exists..\n\n");
        return;
    }
    while (fread(&s,sizeof(s),1,fp)){

        printf("%d\t",s.stud_id);
        printf("%s\t",s.stud_name);
        printf("%s\t",s.stud_clas);
        printf("%s\t",s.stud_city);
        printf("%s\n\n",s.stud_pno);
    }
    printf("\n\n");
    fclose(fp);
}

/*Show Recycle End*/
/*Recover Recycle start*/

void recoverRecycle()
{
    struct student s;
    FILE *fp, *fp1, *fp2;
    int data,count = 0, count1 = 0;
    char c;
    system("cls");
    printf("\t\tRecover Recycle Bin Module..\n\n");
    if (!(fp = fopen("student_recycle.txt","r"))){
        printf("\n\nFile Not Exists..\n\n");
        return;
    }
    while (fread(&s,sizeof(s),1,fp)){
        printf("%d\t",s.stud_id);
        printf("%s\t",s.stud_name);
        printf("%s\t",s.stud_clas);
        printf("%s\t",s.stud_city);
        printf("%s\n\n",s.stud_pno);
    }
    fclose(fp);
    printf("\n\nRecover Data..\n\n");
    printf("1. All Records\t2. One By One\n\n");
    c = getch();
    if ( c == '1'){
            printf("Are you Sure you want to recover..Press 1 else any key..");
            c = getch();
            if ( c == '1'){
                fp = fopen("student_recycle.txt","r");
                fp1 = fopen("student.txt","a+");
                while (fread(&s,sizeof(s),1,fp)){
                    fwrite(&s,sizeof(s),1,fp1);
                }
                printf("\n\nData Recover Successful..\n\n");
                fclose(fp1);
                fclose(fp);
                remove("student_recycle.txt");
            }else{
                printf("\n\nRecovery Cancel..\n\n");
            }
    }
    else if ( c == '2'){
        printf("\n\nEnter Student ID for Recover -- ");
        scanf("%d",&data);
        printf("Are you Sure you want to recover..Press 1 else any key..");
            c = getch();
            if ( c == '1'){
                fp = fopen("student_recycle.txt","r");
                fp1 = fopen("student.txt","a+");
                fp2 = fopen("student_rtmp.txt","a+");
                while (fread(&s,sizeof(s),1,fp)){
                    if ( s.stud_id == data){
                        fwrite(&s,sizeof(s),1,fp1);
                        count++;
                    }
                    else{
                        fwrite(&s,sizeof(s),1,fp2);
                    }
                    count1++;
                }
                if ( count !=0)
                    printf("\n\nData Recover Successful..\n\n");
                else
                    printf("\n\nNo Data Found\n\n");
                fclose(fp2);
                fclose(fp1);
                fclose(fp);
                remove("student_recycle.txt");
                rename("student_rtmp.txt","student_recycle.txt");
            }else{
                printf("\n\nRecovery Cancel..\n\n");
            }
    }
    if (count1 == 1 && count !=0)
        remove("student_recycle.txt");
    printf("\n\n");
}

/*recover Recycle End*/
/*Modify Module start*/

void modifyStudent()
{
    struct student s,s1;
    FILE *fp, *fp1;
    int count = 0, data;
    char name[30],clas[15],city[15],pno[15];
    char c;
    system("cls");
    printf("\t\tModify Employee Module..\n\n");
    if (!(fp = fopen("student.txt","r"))){
        printf("\n\nFile Not Exists for Modify..\n\n");
        return;
    }
    while (fread(&s,sizeof(s),1,fp)){
        printf("%d\t",s.stud_id);
        printf("%s\t",s.stud_name);
        printf("%s\t",s.stud_clas);
        printf("%s\t",s.stud_city);
        printf("%s\n\n",s.stud_pno);
    }
    fclose(fp);
    printf("\n\nModify Records..\n\n");
    printf("Enter Student Id you want to modify -- ");
    scanf("%d",&data);
    printf("1. All Records\t2. Modify Name\n\n");
    printf("3. Modify Class\t4. Modify City\n\n");
    printf("5. Modify Phone No\t");
    c = getch();
    if ( c == '1'){
        fp = fopen("student.txt","r");
        fp1 = fopen("student_tmp.txt","a+");
        while(fread(&s,sizeof(s),1,fp)){
            if (s.stud_id == data){
                s1.stud_id = s.stud_id;
                printf("Student ID -- %d\n\n",s1.stud_id);
                fflush(stdin);
                printf("Enter Student Name -- ");
                scanf("%[^\n]s",&s1.stud_name);
                fflush(stdin);
                printf("Enter Student Class -- ");
                scanf("%[^\n]s",&s1.stud_clas);
                fflush(stdin);
                printf("Enter Student City -- ");
                scanf("%[^\n]s",&s1.stud_city);
                fflush(stdin);
                printf("Enter Student Phone Number -- ");
                scanf("%[^\n]s",&s1.stud_pno);
                fflush(stdin);
                printf("\n\nAre you sure you want to update record, Press 1 else any key...");
                c = getch();
                if ( c == '1'){
                    fwrite(&s1,sizeof(s1),1,fp1);
                    printf("\n\nRecord Updated Successfully..\n\n");
                }
                else{
                    fwrite(&s,sizeof(s),1,fp1);
                    printf("\n\nRecord Update Operation Cancel..\n\n");
                }
            }
            else{
                fwrite(&s,sizeof(s),1,fp1);
            }
        }
        fclose(fp1);
        fclose(fp);
        remove("student.txt");
        rename("student_tmp.txt","student.txt");
    }
    else if ( c == '2'){
        fp = fopen("student.txt","r");
        fp1 = fopen("student_tmp.txt","a+");
        while(fread(&s,sizeof(s),1,fp)){
            if (s.stud_id == data){
                s1 = s;
                printf("Student ID -- %d\n\n",s1.stud_id);
                fflush(stdin);
                printf("Enter Student Name -- ");
                scanf("%[^\n]s",&s1.stud_name);
                fflush(stdin);
                printf("\n\nAre you sure you want to update Name, Press 1 else any key...");
                c = getch();
                if ( c == '1'){
                    fwrite(&s1,sizeof(s1),1,fp1);
                    printf("\n\nRecord Updated Successfully..\n\n");
                }
                else{
                    fwrite(&s,sizeof(s),1,fp1);
                    printf("\n\nRecord Update Operation Cancel..\n\n");
                }
            }
            else{
                fwrite(&s,sizeof(s),1,fp1);
            }
        }
        fclose(fp1);
        fclose(fp);
        remove("student.txt");
        rename("student_tmp.txt","student.txt");
    }
    else if ( c == '3'){
        fp = fopen("student.txt","r");
        fp1 = fopen("student_tmp.txt","a+");
        while(fread(&s,sizeof(s),1,fp)){
            if (s.stud_id == data){
                s1 = s;
                printf("Student ID -- %d\n\n",s1.stud_id);
                fflush(stdin);
                printf("Enter Student Class -- ");
                scanf("%[^\n]s",&s1.stud_clas);
                fflush(stdin);
                printf("\n\nAre you sure you want to update Class, Press 1 else any key...");
                c = getch();
                if ( c == '1'){
                    fwrite(&s1,sizeof(s1),1,fp1);
                    printf("\n\nRecord Updated Successfully..\n\n");
                }
                else{
                    fwrite(&s,sizeof(s),1,fp1);
                    printf("\n\nRecord Update Operation Cancel..\n\n");
                }
            }
            else{
                fwrite(&s,sizeof(s),1,fp1);
            }
        }
        fclose(fp1);
        fclose(fp);
        remove("student.txt");
        rename("student_tmp.txt","student.txt");
    }
    else if ( c == '4'){
        fp = fopen("student.txt","r");
        fp1 = fopen("student_tmp.txt","a+");
        while(fread(&s,sizeof(s),1,fp)){
            if (s.stud_id == data){
                s1 = s;
                printf("Student ID -- %d\n\n",s1.stud_id);
                fflush(stdin);
                printf("Enter Student City -- ");
                scanf("%[^\n]s",&s1.stud_city);
                fflush(stdin);
                printf("\n\nAre you sure you want to update City, Press 1 else any key...");
                c = getch();
                if ( c == '1'){
                    fwrite(&s1,sizeof(s1),1,fp1);
                    printf("\n\nRecord Updated Successfully..\n\n");
                }
                else{
                    fwrite(&s,sizeof(s),1,fp1);
                    printf("\n\nRecord Update Operation Cancel..\n\n");
                }
            }
            else{
                fwrite(&s,sizeof(s),1,fp1);
            }
        }
        fclose(fp1);
        fclose(fp);
        remove("student.txt");
        rename("student_tmp.txt","student.txt");
    }
    else if ( c == '5'){
        fp = fopen("student.txt","r");
        fp1 = fopen("student_tmp.txt","a+");
        while(fread(&s,sizeof(s),1,fp)){
            if (s.stud_id == data){
                s1 = s;
                printf("Student ID -- %d\n\n",s1.stud_id);
                fflush(stdin);
                printf("Enter Student Phone No -- ");
                scanf("%[^\n]s",&s1.stud_pno);
                fflush(stdin);
                printf("\n\nAre you sure you want to update Phone Number, Press 1 else any key...");
                c = getch();
                if ( c == '1'){
                    fwrite(&s1,sizeof(s1),1,fp1);
                    printf("\n\nRecord Updated Successfully..\n\n");
                }
                else{
                    fwrite(&s,sizeof(s),1,fp1);
                    printf("\n\nRecord Update Operation Cancel..\n\n");
                }
            }
            else{
                fwrite(&s,sizeof(s),1,fp1);
            }
        }
        fclose(fp1);
        fclose(fp);
        remove("student.txt");
        rename("student_tmp.txt","student.txt");
    }
    printf("\n\n");
}
/*Modify module End*/
