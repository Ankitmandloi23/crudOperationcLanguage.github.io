#include<stdio.h>
#include<string.h>
void addStudent();
void editStudent();
void viewStudent();
void searchStudent();
void deleteStudent();
int numberOfStudentInList;
int rollNumber[100];
char name[100][22];
int main()
{
numberOfStudentInList=0;
int ch;
while(1)
{
printf("SELECT  A CHOICE===\n");
printf("1: For AddStudent\n");
printf("2: For EditStudent\n");
printf("3: For ViewStudent\n");
printf("4: For SearchStudent\n");
printf("5: For DeleteStudent\n");
printf("6: For Exit\n");
scanf("%d",&ch);
fflush(stdin);
if(ch<1 || ch>6)
{
printf("invalid Input ! Please select valid input(1-6)\n");
continue;
}
if(ch==1 && numberOfStudentInList==100)
{
printf("You can not add More then 100 Students\n");
continue;
}
if(ch>=2 && ch<=5 && numberOfStudentInList==0)
{
printf("You have not added a single student in list please Add!\n");
continue;
}
if(ch==1) addStudent();
if(ch==2) editStudent();
if(ch==3) viewStudent();
if(ch==4) searchStudent();
if(ch==5) deleteStudent();
if(ch==6) break;
}
return 0;
}
void addStudent()
{
int vRollNumber;
char vName[22];
char m,e;
printf("Student (ADD MODULE)\n");
printf("Enter Roll Number :");
scanf("%d",&vRollNumber);
fflush(stdin);
if(vRollNumber<=0)
{
printf("Invalid roll number\n");
return;
}
e=0;
while(e<numberOfStudentInList)
{
if(vRollNumber==rollNumber[e])
{
printf("That roll number is alrady alloted to %s\n",name[e]);
return;
}
e++;
}
printf("Enter a Name :");
fgets(vName,22,stdin);
fflush(stdin);
vName[strlen(vName)-1]='\0';
printf("SAVE : (Y/N) : ");
m=getchar();
fflush(stdin);
if(m!='Y' && m!='y')
{
printf("Student not added!!!\n");
return;
}
rollNumber[numberOfStudentInList]=vRollNumber;
strcpy(name[numberOfStudentInList],vName);
numberOfStudentInList++;
printf("STUDENT HAS BEEN ADDED SUCCESSFULLY! PRESS ENTER TO CONTNIUE>>>");
getchar();
fflush(stdin);
}





void editStudent()
{
int vRollNumber;
char vName[22];
int e,found;
char m;
printf("Student (EDIT MODULE)\n");
printf("Enter a Roll Number of the student EDIT :");
scanf("%d",&vRollNumber);
fflush(stdin);
if(vRollNumber<=0)
{
printf("Invalid roll Number\n");
return;
}
found=0;
e=0;
while(e<numberOfStudentInList)
{
if(vRollNumber==rollNumber[e])
{
found=1;
break;
}
e++;
}
if(found==0)
{
printf("Invalid roll Number\n");
return;
}
printf("NAME : %s\n",name[e]);
printf("EDIT (Y/N) :");
m=getchar();
fflush(stdin);
if(m!='Y' && m!='y')
{
printf("Student not Edited!!\n");
return;
}
printf("Enter new name :");
fgets(vName,22,stdin);
fflush(stdin);
vName[strlen(vName)-1]='\0';
printf("UPDATE (Y/N) :");
m=getchar();
if(m!='Y' && m!='y')
{
printf("Student not Edited!!\n");
return;
}
strcpy(name[e],vName);
printf("Student has been Updated !! PRESS enter to continue>>>");
getchar();
fflush(stdin);
}

void viewStudent()
{
int f;
printf("Student (LIST MODULE)\n");
f=0;
while(f<numberOfStudentInList)
{
printf("Roll Number : %d , Name : %s\n",rollNumber[f],name[f]);
f++;
}
printf("PRESS ENTER TO CONTINUE>>>>\n");
getchar();
fflush(stdin);
}


void searchStudent()
{

int e;
int found;
int vRollNumber;
printf("Student (SEARCH MODULE)\n");
printf("Enter Roll Number to SEARCH : ");
scanf("%d",&vRollNumber);
fflush(stdin);
if(vRollNumber<=0)
{
printf("Invalid roll Number\n");
return;
}
found=0;
e=0;
while(e<numberOfStudentInList)
{
if(vRollNumber==rollNumber[e])
{
found=1;
break;
}
e++;
}
if(found==0)
{
printf("Invalid rollNumber Not found in list!\n");
return;
}
printf("NAME : %s\n",name[e]);
printf("PRESS ENTER TO CONTINUE>>>>\n");
getchar();
fflush(stdin);
}



void deleteStudent()
{
int e,m;
int ep;
int found;
int vRollNumber;
printf("Student (DELETE MODULE)\n");
printf("Enter Roll Number to SEARCH : ");
scanf("%d",&vRollNumber);
fflush(stdin);
if(vRollNumber<=0)
{
printf("Invalid roll Number\n");
return;
}
found=0;
e=0;
while(e<numberOfStudentInList)
{
if(vRollNumber==rollNumber[e])
{
found=1;
break;
}
e++;
}
if(found==0)
{
printf("Invalid rollNumber Not found in list!\n");
return;
}
printf("NAME : %s\n",name[e]);
printf("DELETE (Y/N)");
m=getchar();
fflush(stdin);
getchar();
fflush(stdin);
if(m!='Y' && m!='y')
{
printf("Student not Deleted!!\n");
return;
}
ep=numberOfStudentInList-1;
while(e<=ep)
{
rollNumber[e]=rollNumber[e+1];
strcpy(name[e],name[e+1]);
e++;
}
numberOfStudentInList--;
printf("STUDENT HAS BEEN DELETED SUCCESSFULLY! PRESS ENTER TO CONTNIUE>>>");
getchar();
fflush(stdin);

}
