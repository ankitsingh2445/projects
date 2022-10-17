


//include header files
#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<math.h>
#include<ctype.h>
#include<process.h>
#define go(r,c) gotoxy(c,r)
//shows the heading of the project
void showTitle();
//shows screen 1
void screen1();
//shows screen 1.1
void screen11();
//shows screen 1.2
void screen1_2();
// shows teacher's dashboard
void dashboard();
//shows teacher's details
void teacher();
//screen for uploading student's attendance
void uploadattendance1();
//screen for showing uploaded attendance
void viewattendance();
//shows student's details tothe teacher
void viewdetails();
//screen for uploading quiz
void uploadquizes();
//screen for uploading assignment
void uploadassignment();
//shows quiz responses
void quizresponse();
//shows assignment responses
void assignmentresponse();

//shows student's login or sigup screen
void studentLoginOrSignup();
//designs the border
void border();
//shows student's dashboard
void studentDashboard();
//shows student's details
void yourDetails();
void deatilchoice();
void showdeatils();

void yourDetail();
//shows student's attendance
void viewAttendance();
//shows uploaded quizzes
void quiz();
//shows uploaded assignments
void assignments();
//shows student's helpdesk
void helpdesk();
//shows basic calculator for students
void basicCalculator();
//void fact();
//void basic();
//void percentage();
//void sqrtroot();
//void cuberoot();
struct Attendance{
	char cho[11],choi;
};
int user;
typedef struct{
	char name[51],mobile[11],email[51],city[21],attendence[2];
}Student;
Student s;

typedef struct{
	char name[51],mobile[11],email[51],city[21],attendence[2];
}Studentt;
Studentt ss;
FILE *fp13;


struct SignUp{
	char name[51], password[21],pN[11],cho;
};

// for uploading assisgnment
typedef struct{
	int assno;
	char title[51];
	
}assignment;
assignment b;

FILE *fp3;//for uploading assisgnments
char con[1000],filename[100];//for uplaoding assisgments

//FOR uploading assisgnments submission
typedef struct{
	 char si[51];
	char assname[51];
	
}assignmentsolution;
assignmentsolution as;
FILE *fp8;//for submiting assisgnment solution

// for uploading attdence file

typedef struct{
	 char date[51];
	char liname[51];
	
}upattdence ;
upattdence ua;
FILE *fp9;
// vfor uploading quiz file
typedef struct{
	 int qno;
	char title[51];
	
}quizuploading;
quizuploading qz;
FILE *fp10;
// foe uploading quiz answer
typedef struct{
	 char qsi[51],quzname[51];
	char ans[51];
	
}quizanswer;
quizanswer qzs;
FILE *fp11;

/*struct Answers{
	char first,second;
};*/

//Signup su;
char choice,first,second,at,operat,pass;
char ch[51],phoneNumber[11],userid[51],password[51];
int found =0,p,t;
int n, i ,fact = 1,total_marks,scored;
float percentage, num1, num2, result;
//char operator;
float num1, num2, result;
FILE *fp;
void main(){
    fp3=fopen("uploadingass","rb+"); //for uploading assisgnments
	if(fp3==NULL) fp3=fopen("uploadingass","wb+"); //for uploading assisgnments
	
	fp8=fopen("uploadiasssolution","rb+"); //for uploading assisgnments
	if(fp8==NULL) fp8=fopen("uploadiasssolution","wb+"); //for uploading assisgnments
	
	fp9=fopen("uploaattdencelist","rb+"); //for uploading assisgnments
	if(fp9==NULL) fp9=fopen("uploaattdencelist","wb+"); //for uploading assisgnments
	
	fp10=fopen("assignqz","rb+"); //for uploading assisgnments
	if(fp10==NULL) fp10=fopen("assignqz","wb+"); //for uploading assisgnments
	
	fp11=fopen("quizress","rb+"); //for uploading assisgnments
	if(fp11==NULL) fp11=fopen("quizress","wb+"); //for uploading assisgnments
	
	fp13=fopen("info","rb+"); //for uploading assisgnments
	if(fp13==NULL) fp13=fopen("info","wb+"); //for uploading assisgnments
	
	screen1();
}
void showTitle(){
	clrscr();
	border();
	go(5,30);
	textcolor(YELLOW+BLINK);
	cprintf("Paragon Educators");	//prints "Pragan Educators"
}
void screen1(){

	border();
	showTitle();
	go(12,30);
	textcolor(WHITE);
	cprintf("Version 1.0");
	//printf("Version 1.0");
	go(15,30);
	textcolor(YELLOW);
	cprintf("Developed by");
	//printf("Developed by");
	go(17,5);
	textcolor(WHITE);
	cprintf("Alok Pandey, Aman Verma , Ankit Singh, Aryan Shukla, Rashi Srivastava ");


	//prints "Alok Pandey, Aman Verma , Ankit Singh, Aryan Shukla, Rashi Srivastava"
	delay(2000);
	screen11();
}
void screen1_2(){
       //	int enteruser=0,enterpass=0;
	clrscr();
	border();
	showTitle();
	go(10,30);
	textcolor(WHITE);
	cprintf("Username        :");
	go(12,30);
	textcolor(WHITE);
	cprintf("Password        :");
	go(10,50);
	//scanf("%d",&enteruser);
	fflush(stdin);
	gets(userid);
	go(12,50);
	while(i<50){
		choice=getch();
		if(choice==13){
			break;
		}
		if(choice==8){
			if(i>0){
				i--;
				go(12,50);
				clreol();
				go(12,50);
				for(n=0;n<i;n++){
					putchar('*');
				}
			}
		}
		else{
			password[i]=choice;
			putchar('*');
			i++;
		}
	}
	password[i]='\0';

	//scanf("%d",&enterpass);
	/*if(2==enterpass||1==enteruser){
		user=enteruser;
		printf("Welcome to Teacher's dashboard");
		dashboard();
	} */
	if(strcmp(userid,"admin")==0 && strcmp(password,"12345")==0){
		printf("Welcome to Teacher's dashboard");
		dashboard();
	}
	else{   go(18,10);
		printf("Either password or username does not exist");
		system("pause");
		screen1_2();
		getch();
	}

}
void screen11(){
	char choice=0;
	clrscr();
	border();
	
	showTitle();
	go(10,30);
	textcolor(WHITE);
	cprintf("Teacher Login");
	go(12,30);
	textcolor(WHITE);
	cprintf("Student Login");
	go(14,30);
	textcolor(CYAN);
	cprintf("Enter choice (T/S) : ");fflush(stdin);scanf("%c%*c",&choice);
	
        switch(choice){
		 case 't':case 'T': screen1_2();break;
        	 case 's':case 'S': studentLoginOrSignup();break;
        	
        	
        }
	getch();
        
}
void dashboard(){
char choice=0;
clrscr();
border();
showTitle();


go(8,30);
textcolor(RED);
cprintf("Teacher's Dashboard");
go(8,50);
textcolor(RED);
cprintf("%d",user);
go(10,12);
textcolor(WHITE);
cprintf("(A) Your Details ");
go(10,50);
cprintf("(E) Upload Assignments");
go(12,12);
cprintf("(B) Update Student Attendance");
go(12,50);
cprintf("(F) Upload Quiz");
go(14,12);
cprintf("(C) View Student's Attendance");
go(14,50);
cprintf("(G) Quiz Response");
go(16,12);
cprintf("(D) View Student Details");
go(16,50);
cprintf("(H) Assignments Response");
go(20,20);
textcolor(CYAN);
cprintf("Enter Choice (A/B/C/D/E/F/G/H/R->Return)");
fflush(stdin);
scanf("%c%*c",&choice);

	switch(choice){
		 case 'a':case 'A': teacher();break;
	 case 'b':case 'B': uploadattendance1();break;
	 case 'c':case 'C': viewattendance();break;
	 case 'd':case 'D': viewdetails();break;
	 case 'e':case 'E': uploadquizes();break;
	 case 'f':case 'F': uploadassignment();break;
	 case 'g':case 'G': quizresponse();break;
	 case 'h':case 'H': assignmentresponse();break;
	 case 's':case 'S': screen11();break;
	 case 'q':case 'Q': exit(0);



	}
getch();
}
void teacher(){
	char choice=0;
	clrscr();
	border();
	showTitle();
	//clrscr();
	go(10,12);textcolor(WHITE);
	cprintf("Name");go(10,40);cprintf("ABCD");
	go(12,12);
	printf("Experience");go(12,40);cprintf("5 years");
	go(14,12);
	printf("Email");go(14,40);cprintf("abcd@gmail.com");
	
	go(16,12);
	printf("mobile");go(16,40);cprintf("1234567896");
	go(18,12);
	printf("city");go(18,40);cprintf("xyz");
	go(20,12);
	printf("Enter Choice R-->Return)");
	fflush(stdin);
	go(20,65);
	scanf("%c%*c",&choice);
	switch(choice){
		case 'r':case 'R': dashboard();
	}
   getch();
}
void uploadattendance1(){
	//char choice=0;
	clrscr();
	border();
	showTitle();
	go(10,30);
	textcolor(WHITE);
	cprintf("Upload Attendance \n ");
	go(12,30);cprintf(" Enter Date ");fflush(stdin);gets(ua.date);
	go(14,30);cprintf(" Enter File name ");fflush(stdin);gets(ua.liname);
	fseek(fp9,0,SEEK_END); //set the file pointer to end of the file
	fwrite(&ua,sizeof(ua),1,fp9); //write the record
	go(18,30);cprintf("uploading successfull...\n");
       go(20,30); system("pause");dashboard();
	
	
	
	
	
	getch();
}
void viewattendance(){
	FILE *fp4 ;
	char choice=0;
	clrscr();
	textcolor(YELLOW+BLINK);go(5,30);cprintf("Pragan Educators\n");
	textcolor(WHITE);
       //	border();
      //
      //	showTitle();
       //	go(,30);textcolor(WHITE);
       //	cprintf("View Attendance \n ");
	   go(7,10);
	rewind(fp9); //set file pointer to top of the file
	while(fread(&ua,sizeof(ua),1,fp9)){
	      printf(" %20s %20s \n",ua.date,ua.liname);
	    //  go(12,10);cprintf("%s",ua.date);
	     // go(12,30);cprintf("%s",ua.liname);
	}
     
	go(18,20);printf("enter file  name ");fflush(stdin);gets(filename);
    fp4 =fopen(filename,"r");
    while (fgets(con,1000, fp4)!=NULL)
    printf("%s\n",con);
    fclose(fp4);
    go(20,30);printf("Enter (E--> continue) (R-->Return) ");
	scanf("%c%*c",&choice);
	switch(choice){
		case 'r':case 'R': dashboard();break;
		case 'e':case 'E': viewattendance();break;
		case 'b':case 'B': studentDashboard();break;
	}
	getch();
}
void viewdetails(){
       	char choice=0;
	   int found=0;
	   char nbr[11];
	clrscr();
	border();
	showTitle();
       //	int found=0;
       //

	//char nbr[11];
	go(8,32);
	textcolor(BLUE);cprintf("Enter studentid ");go(8,50);fflush(stdin);scanf("%s",&nbr);
	rewind(fp13);
	while(fread(&ss,sizeof(ss),1,fp13)){
		if(strcmp(ss.mobile,nbr)==0){
			found=1;
			break;
		}
	}
	if(found==1){
	    
	    //cprintf("Your Detail");
	    go(12,30);
	  textcolor(WHITE);
	cprintf("Name      :");go(12,45);cprintf("%s",ss.name);
	go(14,30);
	textcolor(WHITE);
	cprintf("Mobile    :");go(14,45);cprintf("%s",ss.mobile);
	go(16,30);
	textcolor(WHITE);
	cprintf("Email id  :");go(16,45);cprintf("%s",ss.email);
	go(18,30);
	textcolor(WHITE);
	cprintf("City      :");go(18,45);cprintf("%s",ss.city);
		//printf("Record founds as %s %s %s %s\n",ss.name,ss.email,ss.mobile,ss.city);
	}
	else
		printf("Sorry! Record not found\n");
	go(20,20);cprintf("Return -->R");fflush(stdin);go(20,30);scanf("%s",&choice);
	switch(choice){
		case  'r' : case 'R' : dashboard();break;
	}

}
void uploadquizes(){
		char choice=0;
	clrscr();
	border();
	showTitle();
	go(12,20);textcolor(WHITE);
	cprintf("Upload Quiz Here \n");
	go(14,20);
	cprintf("Quiz No : ");go(14,55);scanf("%d",&qz.qno);
	go(16,20);cprintf("Title : ");go(16,55);fflush(stdin);gets(qz.title);
	fseek(fp10,0,SEEK_END); //set the file pointer to end of the file
	fwrite(&qz,sizeof(qz),1,fp10); //write the record
	go(20,20);
	cprintf(" Enter (E-->to continue ,R-->Return \n ");
	fflush(stdin);
	go(20,65);
scanf("%c%*c",&choice);
	switch(choice){
		case 'r':case 'R': dashboard();
		case 'e':case 'E': uploadquizes();
	}
     getch();
}
void uploadassignment(){
	char choice=0;
	clrscr();
	border();
	showTitle();
	go(12,20);textcolor(WHITE);
	cprintf("Upload Assignment Here \n");
	go(14,20);
	cprintf("assignment No : ");go(14,55);scanf("%d",&b.assno);
	go(16,20);cprintf("Title : ");go(16,55);fflush(stdin);gets(b.title);
	fseek(fp3,0,SEEK_END); //set the file pointer to end of the file
	fwrite(&b,sizeof(b),1,fp3); //write the record
	go(20,20);
	cprintf(" Enter (E-->to continue ,R-->Return \n ");
	fflush(stdin);
	go(20,65);
scanf("%c%*c",&choice);
	switch(choice){
		case 'r':case 'R': dashboard();
		case 'e':case 'E': uploadassignment();
	}
     getch();
}

void quizresponse(){
	FILE  *fp4;

	clrscr();
	//border();
	//showTitle();
	//go(16,20);textcolor(WHITE);
	rewind(fp11); //set file pointer to top of the file
	while(fread(&qzs,sizeof(qzs),1,fp11)){
		printf("%10s %25s %30s \n",qzs.qsi,qzs.quzname,qzs.ans);
	}
	go(12,30);cprintf("enter file name");fflush(stdin);gets(filename);
    fp4 =fopen(filename,"r");
    while (fgets(con,1000, fp4)!=NULL)
    printf("%s\n",con);
    fclose(fp4);
    go(18,20);
	cprintf("Enter (V--> view another submission) (R-->Return)\n ");
	fflush(stdin);
	go(18,65);

scanf("%c%*c",&choice);
	switch(choice){
		case 'r':case 'R': dashboard();
		case 'v':case 'V': quizresponse();
}
	getch();
}
void assignmentresponse(){
FILE *fp4;
	char choice=0;
	clrscr();
	//border();
	//showTitle();
     //go(2,30);cprintf("Paragan Educators\n");
  textcolor(WHITE);
    rewind(fp8); //set file pointer to top of the file
	while(fread(&as,sizeof(as),1,fp8)){
	       	printf("%10s %30s \n",as.si,as.assname);
	    //go(10,10); cprintf("%s",as.si);
	      //go(10,40);cprintf("%s",as.assname);
	}
     
	go(12,20);cprintf("enter assignment name ");fflush(stdin);gets(filename);
    fp4 =fopen(filename,"r");
    while (fgets(con,1000, fp4)!=NULL)
    printf("%s\n",con);
    fclose(fp4);
	//go(16,20);
	//printf(" View Another Submission \n");
	//go(18,20);
	//printf("Enter (V) \n");
	go(18,20);
	cprintf("Enter (V--> view another submission) (R-->Return)\n ");
	fflush(stdin);
	go(20,65);

scanf("%c%*c",&choice);
	switch(choice){
		case 'r':case 'R': dashboard();
		case 'v':case 'V': assignmentresponse();
	}
	getch();
}


void border(){
	int i,j,k,l,m,n,a;
	clrscr();
	go(1,1);
	for(n=1;n<=78;n++){
		textcolor(CYAN);
		cprintf("%c",219);
	}
	go(1,70);
	for(n=1;n<=23;n++){
		textcolor(CYAN);
		cprintf("%c",219);
		printf("\n");
	}
	for(a=1;a<=78;a++){
		textcolor(CYAN);
		cprintf("%c",219);
	}
	go(1,78);
	for(i=1;i<24;i++){
		textcolor(CYAN);
		go(i,78);
		cprintf("%c",219);
	}
}
void studentLoginOrSignup(){
	struct SignUp su;
	FILE *fp=fopen("signup.bin","rb+");
	if(fp==NULL)
		fp = fopen("signup.bin","wb+");
	clrscr();
	border();
	go(5,32);
	textcolor(YELLOW+BLINK);
	cprintf("Paragon Educators");
	go(8,29);
	textcolor(BLUE);
	cprintf("Student Login Or Signup");
	go(12,38);
	printf("Login");
	go(14,38);
	printf("Signup");
	go(18,24);
	textcolor(GREEN);
	cprintf("Enter choice (L-->Login , S-->Signup)");
	fflush(stdin);
	go(18,65);
	choice=toupper(getchar());
	switch(choice){
		case 'L' : if(choice=='L'){
				clrscr();
				border();
				go(5,32);
				textcolor(YELLOW+BLINK);
				cprintf("Paragon Educators");
				go(8,31);
				textcolor(BLUE);
				cprintf("Student Login Screen");
				fflush(stdin);
				go(13,22);
				textcolor(WHITE);
				cprintf("Enter your User id: ");
				go(15,22);
				textcolor(WHITE);
				fflush(stdin);
				cprintf("Password");
				go(13,55);
				gets(phoneNumber);
				go(15,55);
				fflush(stdin);
				while(i<50){
					pass=getch();
					if(pass==13){
						break;
					}
					if(pass==8){
						if(i>0){
							i--;
							go(15,55);
							clreol();
							go(15,55);
							for(n=0;n<i;n++){
								putchar('*');
							}
						}
					}else{
						password[i]=pass;
						putchar('*');
						i++;
					}


				}
				password[i]='\0';
				while(fread(&su,sizeof(su),1,fp)){
					if(strcmp(su.pN,phoneNumber)){
						found=1;
						break;
					}
				}
				if(found==1){
					go(16,20);
					printf("Valid user");
					studentDashboard();
					
				}
				else{   go(20,20);
					printf("Record not found");
					go(22,20);
					system("pause");
					studentLoginOrSignup();
				}

				/*
				textcolor(WHITE);
				cprintf("Username");
				go(15,32);
				textcolor(WHITE);
				cprintf("Password");
				fflush(stdin);
				go(13,47);
				gets(ch);
				fflush(stdin);
				go(15,47);
				gets(ch);
				fflush(stdin);
				go(20,20);
				textcolor(GREEN);

				cprintf("Enter (Y-->Your Dashboard, R-->for Return)");
				fflush(stdin);
				go(20,65);
				choice=toupper(getchar());
				switch(choice){
					case 'Y' : if(choice=='Y'){
							clrscr();
							border();
							go(10,20);
							textcolor(GREEN);
							cprintf("Loading your Data, Wait For A While-->");
							delay(3000);
							fflush(stdin);
							clrscr();
							fflush(stdin);
							studentDashboard();
							getch();
							break;
						    }
					case 'R' : if(choice=='R'){
							exit(0);}*/
				  }

		case 'S' : if(choice=='S'){
				clrscr();
				border();
				gotoxy(32,5);
				textcolor(YELLOW+BLINK);
				cprintf("Paragon Educators");
				go(8,30);
				textcolor(BLUE);
				cprintf("Student Sign Up Screen");
				go(12,32);
				textcolor(WHITE);
				cprintf("Username: ");
				go(14,32);
				textcolor(WHITE);
				cprintf("Create Password: ");
				fflush(stdin);
				go(16,20);
				textcolor(WHITE);
				cprintf("Enter your user id :");
				fflush(stdin);
				go(12,55);
				gets(su.name);
				//fflush(stdin);
				go(14,55);
				fflush(stdin);
				gets(su.password);
				/*
				while(i<50){
				       su.cho=getch();
					if(su.cho==13){
						break;
					}
					if(su.cho==8){
						if(i>0){
							i--;
							go(14,55);
							clreol();
							go(12,35);
							for(n=0;n<i;n++){
								putchar('*');
							}
						}
					}
					else{
						password[i]=su.cho;
						putchar('*');
						i++;
					}
				}
				password[i]='\0';
				fflush(stdin);
				*/
				go(16,55);
				gets(su.pN);

				go(20,5);
				textcolor(GREEN);
				cprintf("Enter (Y--> for sucessful registration, R--> for return)");
				fflush(stdin);
				go(20,65);
				choice=toupper(getchar());
				switch(choice){
					case 'Y' : if(choice=='Y'){
							clrscr();
							border();
							fseek(fp,0,SEEK_END);
							fwrite(&su,sizeof(su),1,fp);
							fclose(fp);
							go(20,10);
							printf("your registration is sucessful");
							fflush(stdin);
							go(22,20);
							system("pause");
							choice=getch();
							studentLoginOrSignup();
							break;
							/*
							go(10,20);
							textcolor(GREEN);
							cprintf("Loading your Dashboard, Wait for a while-->");
							delay(3000);
							fflush(stdin);
							clrscr();
							fflush(stdin);
							clrscr();
							fflush(stdin);
							studentDashboard();
							getch();
							break;
							*/
						    }

					case 'R' : if(choice=='R'){
							exit(0);
						   }
				}
		}


	}
}
void studentDashboard(){
	fflush(stdin);
	border();
	fflush(stdin);
	go(5,32);
	textcolor(YELLOW+BLINK);
	cprintf("Paragon Educators");
	go(8,32);
	textcolor(GREEN);
	cprintf("Student Dashboard");
	fflush(stdin);
	textcolor(WHITE);
	go(12,10);
	textcolor(WHITE);
	cprintf("A : Yours Details ");
	go(14,10);
	textcolor(WHITE);
	cprintf("B : View Attendance ");
	go(16,10);
	textcolor(WHITE);
	cprintf("C : Quiz ");
	go(12,54);
	textcolor(WHITE);
	cprintf("D : Assignments ");
	go(14,54);
	textcolor(WHITE);
	cprintf("E : Helpdesk ");
	go(16,54);
	textcolor(WHITE);
	cprintf("F : Basic Calculator ");
	go(20,32);
	cprintf("Enter Choice : (A/B/C/D/E/F, r ->exit)");
	fflush(stdin);
	choice=toupper(getchar());
	switch(choice){
		case 'A' :  deatilchoice();
			   break;
		case 'B' : viewattendance();
			   break;
		case 'C' : quiz();
			   break;
		case 'D' : assignments();
			   break;
		case 'E' : helpdesk();
			   break;
		case 'F' : basicCalculator();
			   break;
		case 'T' : screen11(); break;
		case 'R' : exit(0);
			   system("pause");
			   break;
	}
	//getch();
}

void deatilchoice(){
	char choice=0;
	clrscr();
	border();
	showTitle();
	go(10,12);	textcolor(WHITE);cprintf("(A) Show Deatil");
	go(12,12);cprintf("(B) fill Deatil");
	//go(14,12);cprintf("(C) Update Deatil");
	cprintf("Enter Choice : (A/B) r ->exit)");
	fflush(stdin);
	choice=toupper(getchar());
	switch(choice){
		case 'A' : showdeatils();
			        break;
		case 'B' : yourDetail();
			       break;
	
	
}			
   }
void showdeatils(){
	int found=0;
	char choice=0;
	clrscr();
	rewind(fp13);
	while(fread(&ss,sizeof(ss),1,fp13)){
		if(strcmp(ss.mobile,phoneNumber)==0){
			found=1;
			break;
		}
	}
	if(found==1){
	    go(8,32);
	    textcolor(BLUE);
	    cprintf("Your Detail");
	    go(12,30);
	  textcolor(WHITE);
	cprintf("Name      :");go(12,45);cprintf("%s",ss.name);
	go(14,30);
	textcolor(WHITE);
	cprintf("Mobile    :");go(14,45);cprintf("%s",ss.mobile);
	go(16,30);
	textcolor(WHITE);
	cprintf("Email id  :");go(16,45);cprintf("%s",ss.email);
	go(18,30);
	textcolor(WHITE);
	cprintf("City      :");go(18,45);cprintf("%s",ss.city);
		//printf("Record founds as %s %s %s %s\n",ss.name,ss.email,ss.mobile,ss.city);
	}
	else
		printf("Sorry! Record not found\n");
	go(20,20);cprintf("Return -->R");fflush(stdin);go(20,30);scanf("%s",&choice);
	switch(choice){
		case  'r' : case 'R' : studentDashboard();break;
	}
	getch();
}

void yourDetail(){
	//struct Student s;
	char choice=0;
	
	clrscr();
	border();
	go(5,32);
	textcolor(YELLOW+BLINK);
	cprintf("Paragon Educators");
	go(8,32);
	textcolor(BLUE);
	cprintf("Your Detail");
	go(12,30);
	textcolor(WHITE);
	cprintf("Name      :");
	go(14,30);
	textcolor(WHITE);
	cprintf("Mobile    :");
	go(16,30);
	textcolor(WHITE);
	cprintf("Email id  :");
	go(18,30);
	textcolor(WHITE);
	cprintf("City      :");
	fflush(stdin);
	go(12,45);
	scanf("%s",&ss.name);
	go(14,45);   fflush(stdin);
	scanf("%s",&ss.mobile);
	go(16,45);  fflush(stdin);
	scanf("%s",&ss.email);
	go(18,45);fflush(stdin);
	scanf("%s",&ss.city);
	go(20,20);

fseek(fp13,0,SEEK_END); //set the file pointer to end of the file
	fwrite(&ss,sizeof(ss),1,fp13); //write the record
	printf("Record Saved...\n");
	go(20,20);cprintf("Return -->R");fflush(stdin);go(20,30);scanf("%s",&choice);
	switch(choice){
		case  'r' : case 'R' : studentDashboard();break;
	}
	getch();
					
 
}
void viewAttendance(){
	//char choice=0;
	//struct attendance at;
	fp = fopen("students.bin","rb+");
	clrscr();
	border();
	go(5,32);
	textcolor(YELLOW+BLINK);
	cprintf("Paragon Educators");
	go(8,32);
	textcolor(BLUE);
	cprintf("View Attendance");
       while(fread(&s,sizeof(s),1,fp)){
	if(strcmp(s.mobile,phoneNumber)==0){
		found=1;
		break;
		}
	}
	if(found==1){
		go(12,20);
		textcolor(MAGENTA);
		printf("You were present!!");
		go(14,10);
		printf("Your Attendance is:");
		go(14,40);
		printf("%c",at);
	}
	else{
		go(12,20);
		textcolor(MAGENTA);
		printf("You were not present!!");
		go(14,20);
		printf("Ask your teacher to upload your attendance");
		getch();
		studentDashboard();
	}
	go(16,20);
	printf("Enter R-->return");
	fflush(stdin);
	go(16,65);
	fflush(stdin);
	scanf("%c",&choice);
	switch(choice){
		case 'r':case 'R': studentDashboard();
	}
	getch();
  }


void quiz(){
	FILE *fp4;
	clrscr();
	//border();
	//go(5,32);
	//textcolor(YELLOW+BLINK);
	//cprintf("Paragon Educators");
	//go(8,38);
	//textcolor(BLUE);
	//cprintf("QUIZ");
	//go(12,10);
	textcolor(WHITE);
	//printf("Your Quiz Appears Here!!! " );
	rewind(fp10); //set file pointer to top of the file
	while(fread(&qz,sizeof(qz),1,fp10)){
		printf("%10d %30s \n",qz.qno,qz.title);
	}
	go(8,10);
	cprintf("To view quiz Enter quiz name ");
	fflush(stdin);gets(filename);
    fp4 =fopen(filename,"r");
    while (fgets(con,1000, fp4)!=NULL)
    printf("%s\n",con);
    fclose(fp4);
    
	go(12,30);cprintf("Attempt quiz : ");
	go(13,20);cprintf("enter your id : ");fflush(stdin);gets(qzs.qsi);
	go(14,20);cprintf("enter quiz name : ");fflush(stdin);gets(qzs.quzname);
	go(15,20);cprintf("enter question number with answer : ");fflush(stdin);gets(qzs.ans);
	fseek(fp11,0,SEEK_END); //set the file pointer to end of the file
	fwrite(&qzs,sizeof(qzs),1,fp11); //write the record
	go(20,20);cprintf("submisson sucessful...\n");system("pause");studentDashboard();
	


}
void assignments(){
	 FILE *fp4 ;
	clrscr();
	//border();
	
	//textcolor(YELLOW+BLINK);
	//cprintf("Paragon Edcators");
	//go(8,32);
	textcolor(WHITE);
	//cprintf("Assignments");
		   
       //	FILE *fp4;
       //	clrscr();
	//p4 =fopen(filename,"r");
	rewind(fp3); //set file pointer to top of the file
	while(fread(&b,sizeof(b),1,fp3)){
		printf("%10d %30s \n",b.assno,b.title);
	}
	
     go(16,20);cprintf("enter assignment name");fflush(stdin);gets(filename);
    fp4 =fopen(filename,"r");
    while (fgets(con,1000, fp4)!=NULL)
    printf("%s\n",con);
    fclose(fp4);
    
    //submitting assignment;
    printf(" For submiting assisgnment enter ->s, Return-> r  "); fflush(stdin);
scanf("%c%*c",&choice);
switch(choice){
 case 's':case 'S': printf("enter your id : ");fflush(stdin);gets(as.si);
	                printf("enter file name : ");fflush(stdin);gets(as.assname);
	                fseek(fp8,0,SEEK_END); //set the file pointer to end of the file
	                fwrite(&as,sizeof(as),1,fp8); //write the record
			printf("submisson sucessful...\n");system("pause");studentDashboard();break;
	                
case 'r' :case 'R' : studentDashboard();
    
	}
    
    getch();

}
void helpdesk(){
	border();
	go(5,32);
	textcolor(YELLOW+BLINK);
	cprintf("Paragon Educators");
	go(8,36);
	textcolor(BLUE);
	cprintf("Helpdesk");
	go(10,32);
	textcolor(GREEN);
	cprintf("Choose Your Topic");
	go(12,10);
	printf("topic 1: C Programming");
	go(14,10);
	printf("topic 3: Microsoft Word");
	go(16,10);
	printf("topic 5: Check Your Answer ");
	go(12,50);
	printf("topic 2: C++ Programming ");
	go(14,50);
	printf("topic 4:Test Your Knowledge");
	go(16,50);
	printf("topic 6: Contact Us");
	go(20,12);
	textcolor(RED);
	cprintf("Enter Topic Number in integer or r for return : ");
	fflush(stdin);
	go(20,65);
	choice=getchar();
	switch(choice){
		case '1': if(choice=='1'){
				clrscr();
				border();
				go(5,32);
				textcolor(YELLOW+BLINK);
				cprintf("Paragon Educators");
				go(8,36);
				textcolor(BLUE);
				cprintf("Helpdesk");
				go(10,10);
				textcolor(GREEN);
				cprintf("Topic: C progamming :-" );
//				go(18,32);
//				printf("Test your knowledge");
//				go(20,32);
//				printf("Enter t fot test or r for return");
//				fflush(stdin);
//				go(20,65);
//				choice=toupper(getchar());
//				if(choice=='T'){
//					clrscr();
//					go(5,32);
//					textcolor(RED);
//					cprintf("Paper is not uploaded yet");
//					delay(3000);
//					helpdesk();
//					getch();
//				}
//				if(choice=='R'){
//					studentDashboard();
//					getch();
//				}
				go(12,22);
				printf("A brief history of C evolved from a language\n");
				go(13,22);
				printf("called B, written by Ken Thompson at Bell Labs\n");
				go(14,22);
				printf("in 1970. Ken used B to write one of the first\n");
				go(15,22);
				printf("implementations of UNIX. B in turn was\n");
				go(16,22);
				printf("a descendant of the language BCPL (developed\n");
				go(17,22);
				printf("at Cambridge (UK) in 1967), with most of its\n");
				go(18,22);
				printf("instructions removed.So many instructions were\n");
				go(19,22);
				printf("removed in going from BCPL to B, that Dennis\n");
				go(20,22);
				printf("Ritchie of Bell Labs put some back in (in 1972),\n ");
				go(21,22);
				printf("and called the language C.\n");
				go(22,20);
				textcolor(GREEN);
				cprintf("press r--> for return");
				go(22,60);
				choice=tolower(getch());
				if(choice=='r'){
					helpdesk();
					getch();
					}
			       //	The famous book The
//				printf		C Programming Language was written by 
//				printf		Kernighan and Ritchie in 1978, and was the 
//				printf		definitive reference book on C for almost a 
//						
//				printf		decade.	The original C was still too limiting
//				printf			,and not standardized, and so in 1983 an ANSI
//				printf		committee was established to formalise the 
//						
//				printf		language definition. It has taken until now 
//				printf		(ten years later) for the ANSI ( American 
//						
//				printf		National StandardInstitute) standard to become
//			printf		well accepted and almost universally supported
//				printf		 by compilers") 
							
							
							
//							Structure of a program
//							 Every C program consists of one or more modules called functions.
//							One of these functions is called main. The program begins by executing main
//							function and access other functions, if any. Functions are written after or before
//							main function separately. A function has
//							 (1) heading consists of name with list of
//							arguments ( optional ) enclosed in parenthesis, 
//							(2) argument declaration (if any) and
//							(3) compound statement enclosed in two braces { } such that each statement ends
//							with a semicolon. Comments, which are not executable statement, of necessary can
//							be placed in between /* and */.")

				break;
			   }
		case '2' : if(choice=='2'){
						clrscr();
						border();
						go(5,32);
						textcolor(YELLOW+BLINK);
						cprintf("Paragon Educators");
						go(8,36);
						textcolor(BLUE);
						cprintf("Helpdesk");
						go(10,10);
						textcolor(GREEN);
						cprintf("Topic: C++ progamming :-" );
						go(12,22);
						printf("C++, pronounced C plus plus, is a");
						go(13,22);
						printf("programming language that was built off the C");
						go(14,22);printf("language. The syntax of C++ is nearly");
						go(15,22);printf("identical to C, but it has object-oriented"); 
						go(16,22);printf("features, which allow the programmer tocreate");
						go(17,22);printf("objects within the code. This makes"); 
						go(18,22);printf("programming easier, more efficient, and some");
						go(19,22);printf("would even say, more fun. Because of the ");
						go(20,22);printf("power and flexibility of the language, most");
						go(21,22);printf("software programs today are written in C++.");
						go(23,22);
						textcolor(GREEN);
						printf("press r--> for return");
						go(23,60);
						fflush(stdin);
						choice=tolower(getch());
						if(choice=='r'){
							helpdesk();
							getch();
							}
//C++ is an Object Oriented Programming language but is not purely Object Oriented. Its features like Friend and Virtual, violate some of the very important OOPS features, rendering this language unworthy of being called completely Object Oriented. Its a middle level language.
//
//Benefits of C++ over C Language
//The major difference being OOPS concept, C++ is an object oriented language whereas C is a procedural language. Apart form this there are many other features of C++ which gives this language an upper hand on C laguage.")
//				clrscr();
//				go(5,32);
//				textcolor(RED);
//				cprintf("topic Not Decided Yet");
//				delay(2000);
//				studentDashboard();
//				getch();
						break;

			    }
		case '3' : if(choice=='3'){
						clrscr();
						border();
						go(5,32);
						textcolor(YELLOW+BLINK);
						cprintf("Paragon Educators");
						go(8,36);
						textcolor(BLUE);
						cprintf("Helpdesk");
						go(10,10);
						textcolor(GREEN);
						cprintf("Topic: Microsoft Word :-" );
						go(12,22);
						printf("Microsoft Word is a widely used");
						go(13,22); 
						printf("commercial word processor designed by Microsoft.");
						 go(14,22);
						printf("It is a paid software that helps in preparing");
						go(15,22);
						printf("editing, storing and printing documents quickly");
						go(16,22);		 
						printf("and with accuracy.MS Word is a part of the Microsoft");
						go(17,22);
						printf("Office suite, a productivity software and can also");
						go(18,22);
						printf("be purchased as a stand-alone product. It was");
						go(19,22);
						printf("initially launched in 1983 and has been revised");
						go(20,22);
						printf("numerous times since then. MS Word is available on");
						go(21,22);
						printf("both Windows and Macintosh operating systems.");
						go(22,20);
						textcolor(GREEN);
						cprintf("press r--> for return");
						fflush(stdin);
						go(22,60);
						choice=tolower(getch());
						if(choice=='r'){
							helpdesk();
							getch();
						}
								
								
							
						
				break;
			   }
		case '4' : if(choice=='4'){     //struct Answers ans;
						/*FILE *fp =fopen("answers.bin","rb+");
						if(fp==NULL)
						fp=fopen("answers.bin","wb+");
						*/
						clrscr();
						border();
						go(5,32);
						textcolor(YELLOW+BLINK);
						cprintf("Paragon Educators");
						go(8,36);
						textcolor(BLUE);
						cprintf("Helpdesk");
						go(10,10);
						textcolor(GREEN);
						cprintf("Test Your Knowledge :-" );
						go(12,10);
						printf("1.MS Word, MS Excel, and MS PowerPoint are the part of");
						go(14,10);printf("a- Microsoft Office Suite");
						go(14,40);printf("b- Microsoft Windows");
						go(15,10);printf("c- Mac OS X");
						go(15,40);printf("d- None of these");

						go(17,10);
						printf("2. Who invented C Language.?");
						go(18,10);
						printf("a- Charles Babbage");
						go(18,40);printf("b- Grahambel");
						go(19,10);printf("c- Dennis Ritchie");
						go(19,40);printf("d- Steve Jobs");
						
						
						
						go(20,10);
						printf("Answers the options here:");
						go(21,14);
						printf("1 :");
						go(21,55);
						printf("2 :");
						go(21,18);
						first=tolower(getche());
						go(21,59);
						second=tolower(getche());
					       /*	fseek(fp,0,SEEK_END);
						fwrite(&ans,sixeof(ans),1,fp);
						fclose(fp);*/
						getch();
						go(22,10);
						printf("Your response has been Submitted");
						helpdesk();
						getch();
						break;
			    }
		case '5' : if(choice=='5'){
						//FILE *fp=fopen("answers.bin","rb+");

						clrscr();
						border();
						go(5,32);
						textcolor(YELLOW+BLINK);
						cprintf("Paragon Educators");
						go(8,36);
						textcolor(BLUE);
						cprintf("Helpdesk");
						go(10,10);
						textcolor(GREEN);
						cprintf("Check your Answers :-" );
						go(12,14);
						if(strcmp(first,'b')==0){
							go(13,14);
							printf("Your answer is correct");
						}
						else{
							go(13,14);
							printf("Answer should be <b> Microsoft Windows");
						}
						if(strcmp(second,'c')==0){
							go(15,14);
							printf("Your answer is correct");	
						}
						else{
							go(15,14);
							printf("Answer should be <c> Dennies Ritchie");
						}
						getch();
						go(20,8);
						//fclose(fp);
						printf("Press r--> for return and e--> for exit");
						go(20,60);
						choice=tolower(getchar());
						switch(choice){
							case 'r' : if(choice=='r'){
											helpdesk();
											getch();
											break;
										}
										
							case 'e' : if(choice=='e'){
											exit(0);
											break;
							}
											
						}
						break;
			    }
		case '6' : if(choice=='6'){
						clrscr();
						border();
						go(5,32);
						textcolor(YELLOW+BLINK);
						cprintf("Paragon Educators");
						go(8,36);
						textcolor(BLUE);
						cprintf("Helpdesk");
						go(12,14);
						textcolor(GREEN);
						cprintf("Contact Us:-");
						go(16,14);
						textcolor(WHITE);
						cprintf("Mail id:-");
						go(18,14);
						textcolor(WHITE);
						cprintf("Phone no:-");
						go(16,40);
						textcolor(RED);
						cprintf("contacttechophile@gmail.com");
						go(18,40);
						textcolor(RED);
						cprintf("120-XXXX-XXX");
						system("pause");
						helpdesk();
						getch();
						break;
			    	}
		case 'r' : studentDashboard();
			   getch();
			   break;



	}

}
void basicCalculator(){
	clrscr();
	border();
	go(5,32);
	textcolor(YELLOW+BLINK);
	cprintf("Paragon Educators");
	go(8,32);
	textcolor(BLUE);
	cprintf("Basic Calculator");
//	go(12,20);
//	printf("A:");
//	go(14,20);
//	printf("B:");
//	go(16,20);
//	printf("C:");
//	char choice;
	go(10,12);
	printf("A. To calculate the Factorial\n");
	go(11,12);printf("B. To perform Basic CalculationS i.e, +,-,*,/ /n\n");
	go(12,12);printf("C. To calculate the Percentage\n");
	go(13,12);printf("D. To calculate the Square Root\n");
	go(14,12);printf("E. To calculate the Cube Root\n");
	go(15,12);printf("Enter choice(A/B/C/D/E): ");
	fflush(stdin);
	go(15,60);
	choice=toupper(getchar());
	switch(choice){
		case 'A' : if(choice=='A'){
				  		clrscr();
						border();
						go(5,32);
						textcolor(YELLOW+BLINK);
						cprintf("Paragon Educators");
						go(8,32);
						textcolor(BLUE);
						cprintf("Basic Calculator");
//						int n, i;
//				    	int fact = 1;
						go(10,12);
						printf("Enter an integer: ");
						fflush(stdin);
						go(10,40);
						scanf("%d", &n);
				
				
						if (n < 0)
						printf("Error! Factorial of a negative number doesn't exist.");
						else {
							for (i = 1; i <= n; i++) {
							fact *= i;
							}
						}
						go(12,12);
						printf("Factorial of %d is %d", n, fact);
					       //	}
						go(18,20);
						system("pause");
						basicCalculator();
						getch();
						break;
					}
		case 'B' : if(choice=='B'){
						clrscr();
						border();
						go(5,32);
						textcolor(YELLOW+BLINK);
						cprintf("Paragon Educators");
						go(8,32);
						textcolor(BLUE);
						cprintf("Basic Calculator");
//						char operator;
//					    float num1, num2, result;
					 	go(10,12);
					    printf("Simulation of a Simple Calculator");
//					    printf("*********************************\n");
						go(12,12);
					    printf("Enter two numbers ");
					    go(12,40);
					    scanf("%f %f", &num1, &num2);
					    fflush(stdin);
					    go(14,12);
					    printf("Enter the operator [+,-,*,/] \n");
					    fflush(stdin);
					    go(14,55);
					    scanf("%s", &operat);
					    switch(operat)
					    {
					    case '+': result = num1 + num2;
					        break;
					    case '-': result = num1 - num2;
					        break;
					    case '*': result = num1 * num2;
					        break;
					    case '/': result = num1 / num2;
					        break;
					    default : printf("Error in operationn");
					        break;
					    }
					    go(16,20);
					    printf("\n %5.2f %c %5.2f = %5.2f\n", num1, operat, num2, result);
					    go(18,20);
					    system("pause");
						basicCalculator();
						getch();
						break;
									
					}
					
		case 'C' : if(choice=='C'){
//				float percentage;
//				int total_marks,scored;
						clrscr();
						border();
						go(5,32);
						textcolor(YELLOW+BLINK);
						cprintf("Paragon Educators");
						go(8,32);
						textcolor(BLUE);
						cprintf("Basic Calculator");
						go(12,10);
						printf("Enter total marks and scored marks");
						go(12,50);
						scanf("%d%d",&total_marks,&scored);
						percentage = (float)scored / total_marks * 100.0;
						go(14,20);
						printf("Percentage = %.2f%%", percentage);
						go(18,20);
						system("pause");
						basicCalculator();
						getch();
						break;


}
			
		case 'D' : if(choice=='D'){
						clrscr();
						border();
						go(5,32);
						textcolor(YELLOW+BLINK);
						cprintf("Paragon Educators");
						go(8,32);
						textcolor(BLUE);
						cprintf("Basic Calculator");
						go(12,10);
						printf("Enter a number: ");
						go(12,40);
						scanf("%d",&p);
						go(14,10);
						printf("Square root of %d is %.2f\n",p,sqrt(p));
						go(18,20);
						system("pause");
						basicCalculator();
						getch();
						break;
					}
			
		case 'E' : if(choice=='E'){
						clrscr();
						border();
						go(5,32);
						textcolor(YELLOW+BLINK);
						cprintf("Paragon Educators");
						go(8,32);
						textcolor(BLUE);
						cprintf("Basic Calculator");
						go(12,10);
						printf("Enter a number: ");
						go(12,30);
						scanf("%d",&t);
						go(14,10);
						printf("Cube root of %d is %.2f\n",t,pow(t,1.0/3));
						go(18,20);
						system("pause");
						basicCalculator();
						getch();
						break;
						}
		default:
			printf("Please,Enter the correct choice!");
	}
			go(20,20);
			printf("Enter R -> Return ");
			fflush(stdin);
			go(50,20);
			choice=toupper(getchar());
			switch(choice){
				case 'R' : if(choice=='R'){
						studentDashboard();
						getch();
						break;
					    }
	}
}



