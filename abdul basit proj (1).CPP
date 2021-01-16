/*name=Mohammad Abdul Basit
TOPIC=COMPUTER SCIENCE PROJECT
	EXAMINATION MANAGEMENT PACKAGE
*/
#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
int validdate(int,int,int);
int validmarks(double);
typedef char su[20];
typedef char a[4];
struct date
{
	int y,m,d;
};
class student		//class for students personal infromation
{
	private:
   	int admn_nmbr;
      int rollno;
      int clas;
      char section;
      char name[25];
      char sex;
      date dob;
      char mothername[25];
      char fathername[25];
      int phone;
      char streamcode[3];
      su sub[5];
   public:
    	void allotment();
   	void addition(int,int&);
      void display();
      int retadmnno(){return admn_nmbr;}
      int retrollno(){return rollno;}
      int retclass(){return clas;}
      char retsection(){return section;}
      char* retname(){return name;}
      char retsex(){return sex;}
      int retyear(){return dob.y;}
      int retday(){return dob.d;}
      int retmonth(){return dob.m;}
      char* retmothername(){return mothername;}
      char* retfathername(){return fathername;}
      int retphone(){return phone;}
      char* retstreamcode(){return streamcode;}
      char* retsub1(){return sub[0];}
      char* retsub2(){return sub[1];}
      char* retsub3(){return sub[2];}
      char* retsub4(){return sub[3];}
      char* retsub5(){return sub[4];}
      char* retsubi(i){return sub[i];}
      void ano(){cin>>admn_nmbr;}
      void roll(){cin>>rollno;}
      void classedit(){cin>>clas;}
      void sec(){cin>>section;}
      void nameedit(){gets(name);}
      void sexedit(){cin>>sex;sex=char(toupper(sex));}
      void year(){cin>>dob.y;}
      void month(){cin>>dob.m;}
      void day(){cin>>dob.d;}
      void mother(){gets(mothername);}
      void father(){gets(fathername);}
      void phoneedit(){cin>>phone;}
      void stream()
      {
      	cin>>streamcode;
         streamcode[0]=char(toupper(streamcode[0]));
         streamcode[1]=char(toupper(streamcode[1]));
         allotment();
      }
};

class result      // class for result of the student
{
	private:
   	int admn_no;
      int rollno;
      char name[25];
      struct
      {	char name[20];
         char grade[3];
         double marks;
      }subject[5];
      double avg,total;
      char division[20];
   public:
      result(){}
      result(int admn,int roll,char* na,char* sub1,char* sub2,char* sub3,char* sub4,char* sub5)
      {
      	admn_no=admn;
         rollno=roll;
         strcpy(name,na);
         strcpy(subject[0].name,sub1);
         strcpy(subject[1].name,sub2);
         strcpy(subject[2].name,sub3);
         strcpy(subject[3].name,sub4);
       	strcpy(subject[4].name,sub5);
         subject[0].marks=subject[1].marks=subject[2].marks=subject[3].marks=subject[4].marks=0;
         strcpy(subject[0].grade,"--");
         strcpy(subject[1].grade,"--");
         strcpy(subject[2].grade,"--");
         strcpy(subject[3].grade,"--");
         strcpy(subject[4].grade,"--");
         strcpy(division,"--");
         total=0,avg=0;
      }
      void entermarks(int i){cin>>subject[i].marks;}
   void calculategrade(int i)
	{
		if(subject[i].marks>=91&&subject[i].marks<=100)
   		strcpy(subject[i].grade,"A1");
   	if(subject[i].marks>=81&&subject[i].marks<91)
   		strcpy(subject[i].grade,"A2");
   	if(subject[i].marks>=71&&subject[i].marks<81)
   		strcpy(subject[i].grade,"B1");
   	if(subject[i].marks>=61&&subject[i].marks<71)
   		strcpy(subject[i].grade,"B2");
   	if(subject[i].marks>=51&&subject[i].marks<61)
   		strcpy(subject[i].grade,"C1");
   	if(subject[i].marks>=41&&subject[i].marks<51)
   		strcpy(subject[i].grade,"C2");
   	if(subject[i].marks>=31&&subject[i].marks<41)
   		strcpy(subject[i].grade,"D");
		if(subject[i].marks>=0&&subject[i].marks<31)
   		strcpy(subject[i].grade,"F");

	}
   void calcdiv()
   {
    	if(subject[1].marks>=33 && subject[2].marks>=33 && subject[3].marks>=33&&subject[4].marks>=33&&subject[0].marks>=33)
      {
      	if(total>=400)
         	strcpy(division,"I");
         if(total>=300 &&total<400)
         	strcpy(division,"II");
         if(total<300)
         	strcpy(division,"III");
      }
      if(subject[1].marks<=33 || subject[2].marks<=33 || subject[3].marks<=33||subject[4].marks<=33||subject[0].marks<=33)
      	strcpy(division,"CO");
   }

      void changeinstream(char a[],int i)
      {
      	strcpy(subject[i].name,a);
         subject[i].marks=0;
         strcpy(subject[i].grade,"--");
         strcpy(division,"--");
      }
		int retadmnno(){return admn_no;}
   	int retrollno(){return rollno;}
   	char* retname(){return name;}
   	char* retsubname(int n){return subject[n].name;}
   	char* retsubgrade(int n){return subject[n].grade;}
   	double retsubmarks(int n){return subject[n].marks;}
      void editrollno(int r){rollno=r;}
      void editname(char a[]){strcpy(name,a);}
      void calctotal()
      {
      	total=0;
      	for(int x=0;x<5;x++)
      	{
         	total+=subject[x].marks;
         }
         avg=total/5.0;
      }
      double rettotal(){return total;}
      char* retdiv(){return division;}
      double retavg(){return avg;}

};
void sortonano()  //a function to sort student.dat on admission number
{
	fstream f("student.dat",ios::binary|ios::in|ios::out);
	f.seekg(0,ios::end);
	int size=sizeof(student),n=f.tellg()/size;
	student s1,s2;
	for (int k=1; k<n; k++)
	{
   	for (int x=0; x<n-k; x++)
		{
			f.seekg(x*size);
			f.read((char*)&s1,size);
			f.read((char*)&s2,size);
			if (s1.retadmnno()>s2.retadmnno())
			{
				f.seekp(x*size);
				f.write((char*)&s2,size);
				f.write((char*)&s1,size);
			}
      }
	}
}
int getlastadno()  // a function to get the admission of the last record
{
	sortonano();
   student a;
   int an, len=sizeof(student);
   ifstream fin("student.dat", ios::binary);
   if (fin==NULL)
   	an=0;
   else
   {
      fin.seekg(0, ios::end);
      int n=fin.tellg()/len;
      if (n==0)
         an=0;
      else
      {
         fin.seekg(len*(n-1), ios::beg);
         fin.read((char*)&a, sizeof(a));
         an=a.retadmnno();
      }
   }
   fin.close();
   return an;
}

void student::addition(int an,int &z) //a function to add details of new student
{
   admn_nmbr=an;
   cout<<"Admission no.		:"<<admn_nmbr;
   cout<<"\nEnter roll number	:";cin>>rollno;
   cout<<"Enter class		:";cin>>clas;
   cout<<"Enter section		:";cin>>section;section=char(toupper(section));
   cout<<"Enter name		:";gets(name);
   cout<<"Male(M) or Female(F)	:";cin>>sex;sex=char(toupper(sex));
   cout<<"Date of birth DD/MM/YYYY:";cin>>dob.d;gotoxy(28,7);
   cout<<"/";cin>>dob.m;gotoxy(31,7);cout<<"/";cin>>dob.y;
  	z=validdate(dob.d,dob.m,dob.y);
   if(z==0)
   {
   	cout<<"Wrong date\n";
      cout<<"\n\nSTRIKE ANY KEY TO RETURN TO MAIN MENU";
   }
   else
   {
   	cout<<"Enter mother's name	:";gets(mothername);
   	cout<<"Enter father's name	:";gets(fathername);
   	cout<<"Enter phone number	:";cin>>phone;
   	cout<<"Enter stream code	:";cin>>streamcode;streamcode[0]=char(toupper(streamcode[0]));
      streamcode[1]=char(toupper(streamcode[1]));
   	allotment();
   }
}
void student::allotment()     // function to allot subject based on stream code
{
	if (strcmpi(streamcode,"SE")==0)
   {	strcpy(sub[0],"English");
   	strcpy(sub[1],"Mathematics") ;
      strcpy(sub[2],"Physics");
      strcpy(sub[3],"Chemistry");
      strcpy(sub[4],"Economics");
   }
   if (strcmpi(streamcode,"SC")==0)
   {	strcpy(sub[0],"English");
   	strcpy(sub[1],"Mathematics") ;
      strcpy(sub[2],"Physics");
      strcpy(sub[3],"Chemistry");
      strcpy(sub[4],"Computer Sc");
   }
   if (strcmpi(streamcode,"SB")==0)
   {	strcpy(sub[0],"English");
   	strcpy(sub[1],"Mathematics") ;
      strcpy(sub[2],"Physics");
      strcpy(sub[3],"Chemistry");
      strcpy(sub[4],"Biology");
   }
   if (strcmpi(streamcode,"CM")==0)
   {	strcpy(sub[0],"English");
   	strcpy(sub[1],"Mathematics") ;
      strcpy(sub[2],"Economics");
      strcpy(sub[3],"Accountancy");
      strcpy(sub[4],"Business St");
   }
   if (strcmpi(streamcode,"CI")==0)
   {	strcpy(sub[0],"English");
   	strcpy(sub[1],"Economics") ;
      strcpy(sub[2],"Accountancy");
      strcpy(sub[3],"Business St");
      strcpy(sub[4],"Info Prac");
   }
   if (strcmpi(streamcode,"HU")==0)
   {	strcpy(sub[0],"English");
   	strcpy(sub[1],"History") ;
      strcpy(sub[2],"Geography");
      strcpy(sub[3],"Economics");
      strcpy(sub[4],"Political Sc");
   }
}
void addfile()    //function to write in file
{
	clrscr();
   int admn=getlastadno();
   fstream fout("student.dat",ios::binary|ios::app);
   student a;int z;
   a.addition(admn+1,z);
   if(z==1)
   {
   	fstream fout1("result.dat",ios::binary|ios::app);
   	result b(a.retadmnno(),a.retrollno(),a.retname(),a.retsub1(),a.retsub2(),a.retsub3(),a.retsub4(),a.retsub5());
   	fout1.write((char*)&b,sizeof(b));
   	fout.write((char*)&a,sizeof(a));
      fout1.close();
      cout<<"All details entered";
      cout<<"\n\nSTRIKE ANY KEY TO RETURN TO MAIN MENU";
   }
   fout.close();
   getch();
}
void addresult()    //function to add marks of a student
{
	clrscr();
	int num;
	cout<<"enter admission number :";cin>>num;clrscr();
   fstream fin("result.dat",ios::binary|ios::in|ios::out);
   result a;
   int found=0;
   while(found==0&&fin.read((char*)&a,sizeof(a)))
   {

      if(a.retadmnno()==num)
      	found=1;
   }
   if(found==0)
   	{cout<<"No such admission number exists.";
      cout<<"\n\nSTRIKE ANY KEY TO RETURN TO MAIN MENU";}
   else
   {
   	int opt;
   	cout<<"			Name		:"<<a.retname();
      cout<<"\n			Roll No.	:"<<a.retrollno();
      cout<<"\n			Admission Number:"<<a.retadmnno();
      cout<<"\nIs this the correct file ?\n1.Yes\n2.No";cin>>opt;clrscr();
      if(opt==2)
      	cout<<"\n\nSTRIKE ANY KEY TO RETURN TO MAIN MENU";
      else
      {
      	int z=1;
      	for(int i=0;i<5&&z==1;i++)
         {  char z1[20];strcpy(z1,a.retsubname(i));
         	cout<<"Enter the marks for "<<z1<<"	:";a.entermarks(i);
            z=validmarks(a.retsubmarks(i));
         }
         if(z==0)
         {
         	cout<<"Mark Entered Is Wrong\n";
            cout<<"STRIKE ANY KEY TO GO BACK TO MAIN MENU";
         }
         else
         {
         	for(int i=0;i<5;i++)
         	{
   				a.calculategrade(i);
         	}clrscr();
         	a.calctotal();
         	a.calcdiv();
         	fin.seekg(-1*sizeof(a),ios::cur);
         	fin.write((char*)&a,sizeof(a));
      		cout<<"All marks entered";
         	cout<<"\n\nSTRIKE ANY KEY TO RETURN TO MAIN MENU";
      	}
      }
   }
   	fin.close();
   	getch();
}
void modification()   // function to modify details of an existing student
{
	clrscr();
	int number,found=0,found2=0;student a;result b;
	cout<<"Enter the admission number of the record to be edited	:";cin>>number;clrscr();
   fstream f("student.dat",ios::binary|ios::in|ios::out);
   fstream f2("result.dat",ios::binary|ios::in|ios::out);
   while(found==0&&!f.eof())
   {
   	f.read((char*)&a,sizeof(a));
      if(a.retadmnno()==number)
      	found=1;
   }
   while(found2==0&&!f2.eof())
   {
   	f2.read((char*)&b,sizeof(b));
      if(b.retadmnno()==number)
      	found2=1;
   }
   if(found==1&&found2==1)
   {
   	clrscr();
      cout<<"\t\t\tAdmission number		:"<<a.retadmnno();
   	cout<<"\n\t\t\tName				:"<<a.retname();
      cout<<"\n\t\t\tClass				:"<<a.retclass()<<"-"<<a.retsection();
      cout<<"\n\t\t\tRoll no.			:"<<a.retrollno();
      cout<<"\nIs this the correct record?\n1.Yes\n2.No";int w;cin>>w;
      if(w==1)
      {
      	int z;
      	clrscr();
      	int choice;
         cout<<"\t\t\t\tModify";
         cout<<"\n\t\t\t\t1.Roll Number";
      	cout<<"\n\t\t\t\t2.Class";
         cout<<"\n\t\t\t\t3.Section";
         cout<<"\n\t\t\t\t4.Name";
         cout<<"\n\t\t\t\t5.Sex";
         cout<<"\n\t\t\t\t6.Date OF Birth";
         cout<<"\n\t\t\t\t7.Mothers's Name";
         cout<<"\n\t\t\t\t8.Father's Name";
         cout<<"\n\t\t\t\t9.Phone Number";
         cout<<"\n\t\t\t\t10.Stream Code";
         for(int i=1;i<=5;i++)
         {
         	cout<<"\n\t\t\t\t"<<(10+i)<<".Marks obtained in "<<b.retsubname(i-1);
         }
         cout<<"\n\t\t\t\tEnter a choice[1-15]";
         cin>>choice;
         clrscr();
         if(choice==1)
         {
          cout<<"Existing Roll Number	:"<<a.retrollno();
          cout<<"\nEnter new roll number	:";a.roll();z=1;
          b.editrollno(a.retrollno());
			}
         if(choice==2)
         {
         	cout<<"Existing class	:"<<a.retclass();
            cout<<"\nEnter new class	:";a.classedit();z=1;
         }
         if(choice==3)
         {
          	cout<<"Existing Section	:"<<a.retsection();
            cout<<"\nEnter new section	:";a.sec();z=1;
         }
         if(choice==4)
         {
          	cout<<"Existing Name	:"<<a.retname();
            cout<<"\nEnter New Name	:";a.nameedit();z=1;
            b.editname(a.retname());
         }
         if(choice==5)
         {
         	cout<<"Existing sex	:"<<a.retsex();
            cout<<"\nEnter new sex	:";a.sexedit();z=1;
         }
         if(choice==6)
         {
         	cout<<"Existing date of birth	:"<<a.retday()<<"/"<<a.retmonth()<<"/"<<a.retyear();
            cout<<"\nEnter new date of birth:";a.day();gotoxy(27,2);
            cout<<"/";a.month();gotoxy(31,2);cout<<"/";a.year();
            z=validdate(a.retday(),a.retmonth(),a.retyear());
            if(z==0)
            {
            	cout<<"Wrong Date!!!";
					cout<<"\n\nSTRIKE ANY KEY TO RETURN TO MAIN MENU";
            }
         }
         if(choice==7)
         {
         	cout<<"Existing Mother's name	:"<<a.retmothername();
            cout<<"\nEnter new mother's name :";a.mother();
            z=1;
         }
         if(choice==8)
         {
         	cout<<"Existing Father's Nmae	:"<<a.retfathername();
            cout<<"\nEnter new father's name :";a.father();
            z=1;
         }
         if(choice==9)
         {
         	cout<<"Existing Phone Number :"<<a.retphone();
            cout<<"\nEnter new phone number	:";a.phoneedit();
            z=1;
         }
         if(choice==10)
         {
         	cout<<"Existing stream code	:"<<a.retstreamcode();
            cout<<"\nEnter new stream code	:";a.stream();
            for(int i=0;i<5;i++)
            {
            	b.changeinstream(a.retsubi(i),i);
            }
            b.calctotal();
            z=1;

         }
         if(choice==11)
         {
         	cout<<"Existing Marks in "<<b.retsubname(0)<<":"<<b.retsubmarks(0);
         	cout<<"\nEnter marks :";b.entermarks(0);
            z=validmarks(b.retsubmarks(0));
            if(z==1)
            {
         		b.calculategrade(0);
            	b.calctotal();
            	b.calcdiv();
            }
            else
            {
         		cout<<"Wrong Mark Is Inputted";
               cout<<"\n\nSTRIKE ANY KEY TO RETURN TO MAIN MENU";
            }
         }
         if(choice==12)
         {
         	cout<<"Existing Marks in "<<b.retsubname(1)<<":"<<b.retsubmarks(1);
         	cout<<"\nEnter marks :";b.entermarks(1);
         	z=validmarks(b.retsubmarks(1));
            if(z==1)
            {
            	b.calculategrade(1);
            	b.calctotal();
            	b.calcdiv();
            }
            else
            {
         		cout<<"Wrong Mark Is Inputted";
               cout<<"\n\nSTRIKE ANY KEY TO RETURN TO MAIN MENU";
            }
         }
         if(choice==13)
         {
         	cout<<"Existing Marks in "<<b.retsubname(2)<<":"<<b.retsubmarks(2);
         	cout<<"\nEnter marks :";b.entermarks(2);
            z=validmarks(b.retsubmarks(2));
            if(z==1)
            {
         		b.calculategrade(2);
            	b.calctotal();
            	b.calcdiv();
            }
            else
            {
         		cout<<"Wrong Mark Is Inputted";
               cout<<"\n\nSTRIKE ANY KEY TO RETURN TO MAIN MENU";
            }
         }
         if(choice==14)
         {
         	cout<<"Existing Marks in "<<b.retsubname(3)<<":"<<b.retsubmarks(3);
         	cout<<"\nEnter marks :";b.entermarks(3);
            z=validmarks(b.retsubmarks(3));
            if(z==1)
            {
         		b.calculategrade(3);
            	b.calctotal();
            	b.calcdiv();
            }
            else
            {
         		cout<<"Wrong Mark Is Inputted";
               cout<<"\n\nSTRIKE ANY KEY TO RETURN TO MAIN MENU";
            }
         }
         if(choice==15)
         {
         	cout<<"Existing Marks in "<<b.retsubname(4)<<":"<<b.retsubmarks(4);
         	cout<<"\nEnter marks :";b.entermarks(4);
            z=validmarks(b.retsubmarks(4));
            if(z==1)
            {
         		b.calculategrade(4);
            	b.calctotal();
            	b.calcdiv();
            }
            else
            {
         		cout<<"Wrong Mark Is Inputted";
               cout<<"\n\nSTRIKE ANY KEY TO RETURN TO MAIN MENU";
            }
         }
         if(z==1)
         {
         	cout<<"\nRecord Modified";
            cout<<"\n\n\nSTRIKE ANY KEY TO RETURN TO MAIN MENU";
         	f.seekg(-1*sizeof(a),ios::cur);
         	f2.seekg(-1*sizeof(b),ios::cur);
         	f.write((char*)&a,sizeof(a));
         	f2.write((char*)&b,sizeof(b));
         }
      }
      else
      	cout<<"\n\nSTRIKE ANY KEY TO RETURN TO MAIN MENU";
   }
   else
   	{
      	cout<<"\nNo Such Record Exists";
         cout<<"\n\nSTRIKE ANY KEY TO RETURN TO MAIN MENU";
      }
   getch();
   f.close();
   f2.close();
}
void deleterecord()  //function to delete a student record
{
	clrscr();
	int number;
   cout<<"Enter the admission number of record to be deleted	:";cin>>number;
   clrscr();
   student a;result b;
   fstream f("student.dat",ios::binary|ios::app|ios::in);
   fstream f2("result.dat",ios::binary|ios::app|ios::in);
   int found=0,found2=0;
   while(found==0&&!f.eof())
   {
   	f.read((char*)&a,sizeof(a));
      if(a.retadmnno()==number)
      	found=1;
   }
   while(found2==0&&!f2.eof())
   {
   	f2.read((char*)&b,sizeof(b));
      if(b.retadmnno()==number)
      	found2=1;
   }
   if (found==0&&found2==0)
     {
     		cout<<"No such record with the admission number exists.";
         cout<<"\n\nSTRIKE ANY KEY TO RETURN TO MAIN MENU";
         f.close();
         f2.close();
     }
   else
   	{

      	cout<<"\n\t\tThe name is 		:"<<a.retname();
         cout<<"\n\t\tThe roll no. is 	:"<<a.retrollno();
      	cout<<"\n\t\tthe class is		:"<<a.retclass()<<"-"<<a.retsection();
      	cout<<"\nIs this the correct record ? \n1.Yes \n2.No";int opt;cin>>opt;
         clrscr();
         if(opt==2)
         	cout<<"\n\nSTRIKE ANY KEY TO RETURN TO MAIN MENU";
         else
         {
           cout<<"Record Deleted";
           cout<<"\n\n\nSTRIKE A KEY TO RETURN TO MAIN MENU";
           fstream t1("temp1.dat",ios::binary|ios::app);
           f.seekg(0,ios::beg);
           while(f.read((char*)&a,sizeof(a)))
           {
           		if(a.retadmnno()!=number)
               	t1.write((char*)&a,sizeof(a));
           }
           f.close();
           t1.close();
           remove("student.dat");
           rename("temp1.dat","student.dat");
           fstream t2("temp2.dat",ios::binary|ios::app);
           f2.seekg(0,ios::beg);
           while(f2.read((char*)&b,sizeof(b)))
           {
           		if(b.retadmnno()!=number)
               	t2.write((char*)&b,sizeof(b));
           }
           f2.close();
           t2.close();
           remove("result.dat");
           rename("temp2.dat","result.dat");
         }
      }
      getch();
}
void studentdetails() // a function to display the personal details of student
{
	clrscr();
	int ano,found=0;student a;
   cout<<"Enter admission number	:";cin>>ano;clrscr();
   ifstream f("student.dat",ios::binary);
   while(f.read((char*)&a,sizeof(a)))
   {
   	if(a.retadmnno()==ano)
      	{found=1;break;}
      else
      	found=0;
   }
   if(found==0)
   {
   	cout<<"\nNo such record exists";
      cout<<"\n\nSTRIKE ANY KEY TO RETURN TO MAIN MENU";
   }
   else
   {

   	cout<<"\t\t\t\tSTUDENT DETAILS\n";
      for(int z=0;z<80;z++)
      	cout<<"-";
      cout<<"\nAdmission Number:"<<a.retadmnno();gotoxy(37,3);
      cout<<"Roll No. "<<a.retrollno();
      cout<<"\nName :"<<a.retname();gotoxy(37,4);
      cout<<"Class :"<<a.retclass()<<"-"<<a.retsection();
      cout<<"\nSex :"<<a.retsex();gotoxy(37,5);
      cout<<"DOB :"<<a.retday()<<"/"<<a.retmonth()<<"/"<<a.retyear();
      cout<<"\nFather's Name :"<<a.retfathername();
      cout<<"\nMother's Name :"<<a.retmothername();
      cout<<"\nPhone :"<<a.retphone();gotoxy(37,8);
      cout<<"Stream Code :"<<a.retstreamcode();
      cout<<"\n";
      for(int z=0;z<80;z++)
      	cout<<"-";
   }
   f.close();
   getch();
}
void studentresult() // a function to display report card of student
{
	clrscr();
	int ano,found=0,found1=0;student a;result b;
   cout<<"Enter admission number	:";cin>>ano;
   clrscr();
   ifstream f1("result.dat",ios::binary);
   ifstream f("student.dat",ios::binary);
   while(f.read((char*)&a,sizeof(a))&&found==0)
   {
   	if(a.retadmnno()==ano)
      	{found=1;break;}
      else
      	found=0;
   }
    while(f1.read((char*)&b,sizeof(b))&&found1==0)
   {
   	if(b.retadmnno()==ano)
      	{found1=1;break;}
      else
      	found1=0;
   }
   if(found1==0 && found==0)
   {
   	cout<<"\nNo such record exists";
      cout<<"\n\nSTRIKE ANY KEY TO RETURN TO MAIN MENU";
   }
   else
   {

   	cout<<"Admission No.: "<<b.retadmnno();
      gotoxy(43,1);
      cout<<"Roll: "<<b.retrollno();
      cout<<"\nName: "<<a.retname();gotoxy(43,2);
      cout<<"Class: "<<a.retclass()<<"-"<<a.retsection();
      cout<<"\nStream: ";
      if(strcmpi(a.retstreamcode(),"SB")==0)
      	cout<<"Science with Biology";
      if(strcmpi(a.retstreamcode(),"SC")==0)
      	cout<<"Science with Computers";
      if(strcmpi(a.retstreamcode(),"SE")==0)
      	cout<<"Science with Economic";
      if(strcmpi(a.retstreamcode(),"CM")==0)
      	cout<<"Commerce with Mathematics";
   	if(strcmpi(a.retstreamcode(),"CI")==0)
      	cout<<"Commerce with Informatics Practices";
      if(strcmpi(a.retstreamcode(),"HU")==0)
      	cout<<"Humanities\n";
      gotoxy(43,3);
      cout<<"DOB :"<<a.retday()<<"/"<<a.retmonth()<<"/"<<a.retyear();
      cout<<"\n";
      for(int z=0;z<80;z++)
      	cout<<"-";
      cout<<"\n";
      printf("%-20s%-10s%-15s%-10s\n","Subject","Max","Marks","Grade");
      for(int z=0;z<80;z++)
      	cout<<"-";
      cout<<"\n";
      for(int x=0;x<5;x++)
      {
      	printf("%-20s%-10s%-13.2f%-10s\n",b.retsubname(x),"100",b.retsubmarks(x),b.retsubgrade(x));
      }
      for(int z=0;z<80;z++)
      	cout<<"-";
      cout<<"\n";
      printf("%-20s%-10s%-13.2f%-10s\n","Total","100",b.retavg(),b.retdiv());
      for(int z=0;z<80;z++)
      	cout<<"-";
      cout<<"\nClass Teacher ";gotoxy(43,16);cout<<"Principal";
   }
   f1.close();
   f.close();
   getch();
}
void sortonstreamandname()  //a function to sort on stream and then name
{
	fstream f("student.dat",ios::binary|ios::in|ios::out);
	f.seekg(0,ios::end);
	int size=sizeof(student),n=f.tellg()/size;
	student s1,s2;
	for (int k=1; k<n; k++)
	{
   	for (int x=0; x<n-k; x++)
		{
			f.seekg(x*size);
			f.read((char*)&s1,size);
			f.read((char*)&s2,size);
			if (strcmpi(s1.retstreamcode(),s2.retstreamcode())>0)
			{
				f.seekp(x*size);
				f.write((char*)&s2,size);
				f.write((char*)&s1,size);
			}
      }
	}
   f.seekg(0,ios::beg);
	for (int k=1; k<n; k++)
	{
   	for (int x=0; x<n-k; x++)
		{
			f.seekg(x*size);
			f.read((char*)&s1,size);
			f.read((char*)&s2,size);
			if (strcmpi(s1.retname(),s2.retname())>0&&strcmpi(s1.retstreamcode(),s2.retstreamcode())==0)
			{
				f.seekp(x*size);
				f.write((char*)&s2,size);
				f.write((char*)&s1,size);
			}
      }
	}
   f.close();
}
void streamwisepersonalinformation() //a function to diaplay the personal
{                                    //details of students stream wise
												 //in table format
	clrscr();
	sortonstreamandname();
   int len=sizeof(student);
   ifstream fin("student.dat", ios::binary);
   fin.seekg(0, ios::end);
   int n=fin.tellg()/len;
   if (n==0)
   {
   	cout<<"No student information entered";
      cout<<"\n\nSTRIKE ANY KEY TO RETURN TO MAIN MENU";
   }
   fin.close();
   if(n!=0)
   {for(int z=0;z<132;z++)
      	cout<<"-";
   cout<<"\n";
   printf("%-4s%-1s%-25s%-1s%-4s%-1s%-6s%-1s%-3s%-1s%-10s%-1s%-25s%-1s%-25s%-1s%-10s%-1s%-8s%-1s\n","ADNO","|","           NAME","|","ROLL","|","CLASS","|","SEX","|","    DOB","|","          MOTHER NAME","|","       FATHER NAME","|","PHONE","|","STREAM CODE","|");
   for(int z=0;z<132;z++)
   		cout<<"-";
   cout<<"\n";
   fstream f("student.dat",ios::binary|ios::in);
   student a;
   while(f.read((char*)&a,sizeof(a)))
   {
   	printf("%-1s%-3d%-1s%-1s%-24s%-1s%-1s%-3d%-1s%-1s%-2d%-1s%-2c%-1s%-1s%-2c%-1s%-2d%-1s%-2d%-1s%-4d%-1s%-1s%-24s%-1s%-1s%-24s%-1s%-10d%-1s%-4s%-7s%-1s\n"," ",a.retadmnno(),"|"," ",a.retname(),"|"," ",a.retrollno(),"|"," ",a.retclass(),"-",a.retsection(),"|"," ",a.retsex(),"|",a.retday(),"/",a.retmonth(),"/",a.retyear(),"|"," ",a.retmothername(),"|"," ",a.retfathername(),"|",a.retphone(),"|","    ",a.retstreamcode(),"|");
   }
   for(int z=0;z<132;z++)
      	cout<<"-";
   cout<<"\n\n\n STRIKE ANY KEY TO GO BACK";
   f.close();}
   getch();
}
void sort2()//sort on division and then on admission number
{
	fstream f("result.dat",ios::binary|ios::in|ios::out);
	f.seekg(0,ios::end);
	int size=sizeof(result),n=f.tellg()/size;
	result s1,s2;
	for (int k=1; k<n; k++)
	{
   	for (int x=0; x<n-k; x++)
		{
			f.seekg(x*size);
			f.read((char*)&s1,size);
			f.read((char*)&s2,size);
			if (strcmpi(s1.retdiv(),s2.retdiv())<0)
			{
				f.seekp(x*size);
				f.write((char*)&s2,size);
				f.write((char*)&s1,size);
			}
		}
   }
   f.seekp(0,ios::beg);
   for (int k=1; k<n; k++)
	{
   	for (int x=0; x<n-k; x++)
		{
			f.seekg(x*size);
			f.read((char*)&s1,size);
			f.read((char*)&s2,size);
			if (s1.retadmnno()>s2.retadmnno()&&strcmpi(s1.retdiv(),s2.retdiv())==0)
			{
				f.seekp(x*size);
				f.write((char*)&s2,size);
				f.write((char*)&s1,size);
			}
		}
   }

f.close();
}
void resultstream()// function to show result of students stream wise
{                  // in a table format
	clrscr();
	sortonstreamandname();
   sort2();
	int len=sizeof(student);
   ifstream fin("student.dat", ios::binary);
   fin.seekg(0, ios::end);
   int n=fin.tellg()/len;
   if (n==0)
   {
   	cout<<"No student information entered";
      cout<<"\n\nSTRIKE ANY KEY TO RETURN TO MAIN MENU";
   }
   fin.close();
	a code[6]={"SB","SC","SE","CM","CI","HU"};
   student s;result r;
   for(int i=0;i<6;i++)
   {  fstream f2("result.dat",ios::binary|ios::out|ios::in);
   	fstream f("student.dat",ios::binary|ios::in);
      f.seekg(0,ios::beg);
   	fstream t("temp.dat",ios::binary|ios::app|ios::in);
   	while(f.read((char*)&s,sizeof(s)))
      {
      	if(strcmpi(s.retstreamcode(),code[i])==0)
         {
         	t.write((char*)&s,sizeof(s));
         }
      }
      f.seekg(0);
      f.close();
      t.seekg(0,ios::beg);
      if(t.read((char*)&s,sizeof(s)))
      {
      	t.seekg(0);
      	if(strcmpi(code[i],"SB")==0)
      		cout<<"\nScience with Biology\n";
      	if(strcmpi(code[i],"SC")==0)
      		cout<<"\nScience with Computers\n";
      	if(strcmpi(code[i],"SE")==0)
      		cout<<"\nScience with Economic\n";
      	if(strcmpi(code[i],"CM")==0)
      		cout<<"\nCommerce with Mathematics\n";
   		if(strcmpi(code[i],"CI")==0)
      		cout<<"\nCommerce with Informatics Practices\n";
      	if(strcmpi(code[i],"HU")==0)
      		cout<<"\nHumanities\n";
         for(int z=0;z<130;z++)
         	cout<<"-";
         cout<<"\n";
      	printf("%-3s%-1s%-25s%-1s%-4s%-1s%-12s%-1s%-2s%-1s%-12s%-1s%-2s%-1s%-12s%-1s%-2s%-1s%-12s%-1s%-2s%-1s%-12s%-1s%-2s%-1s%-6s%-1s%-4s%-1s%-3s%-1s\n","ANO","|","NAME","|","ROLL","|",s.retsub1(),"|","G1","|",s.retsub2(),"|","G2","|",s.retsub3(),"|","G3","|",s.retsub4(),"|","G4","|",s.retsub5(),"|","G5","|","TOTAL","|","AVG","|","DIV","|");
         for(int z=0;z<130;z++)
      		cout<<"-";
      	cout<<"\n";
         t.close();
      	while(f2.read((char*)&r,sizeof(r)))
      	{
         	fstream t("temp.dat",ios::binary|ios::in);
      		int found=0;
      		while(t.read((char*)&s,sizeof(s))&&found==0)
         	{

         		if(r.retadmnno()==s.retadmnno())
            		found=1;
         	}
         	if (found==1)
         		{
               	t.seekg(-sizeof(s),ios::cur);
               	printf("%-3d%-1s%-25s%-1s%-4d%-1s%-12.2f%-1s%-2s%-1s%-12.2f%-1s%-2s%-1s%-12.2f%-1s%-2s%-1s%-12.2f%-1s%-2s%-1s%-12.2f%-1s%-2s%-1s%-6.2f%-1s%-4.1f%-1s%-3s%-1s\n",r.retadmnno(),"|",r.retname(),"|",r.retrollno(),"|",r.retsubmarks(0),"|",r.retsubgrade(0),"|",r.retsubmarks(1),"|",r.retsubgrade(1),"|",r.retsubmarks(2),"|",r.retsubgrade(2),"|",r.retsubmarks(3),"|",r.retsubgrade(3),"|",r.retsubmarks(4),"|",r.retsubgrade(4),"|",r.rettotal(),"|",r.retavg(),"|",r.retdiv(),"|");
               }
            t.seekg(0);
            t.close();
         }
         f2.seekp(0);
          for(int z=0;z<130;z++)
      		cout<<"-";
      	cout<<"\n";


		}
      f2.close();
      t.close();
      remove("temp.dat");
   }

   getch();
}
int validdate(int dd,int mm,int yy) // a function to validate inputted date
{
    if(yy>=1900 && yy<=9999)
    {
        //check month
        if(mm>=1 && mm<=12)
        {
            //check days
            if((dd>=1 && dd<=31) && (mm==1 || mm==3 || mm==5 || mm==7 || mm==8 || mm==10 || mm==12))
                return 1;
            else if((dd>=1 && dd<=30) && (mm==4 || mm==6 || mm==9 || mm==11))
                return 1;
            else if((dd>=1 && dd<=28) && (mm==2))
                return 1;
            else if(dd==29 && mm==2 && (yy%400==0 ||(yy%4==0 && yy%100!=0)))
                return 1;
            else
                return 0;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}
int validmarks(double mark)// validate inputted marks
{
	if(mark>=0 &&mark<=100)
   	return 1;
   else
   	return 0;
}
void mainmenu()   // main menu
{
	clrscr();
	int choice;
   do{  clrscr();
        cout<<"\n\t\t\t\t*************";
        cout<<"\n\t\t\t\t* MAIN MENU *";
        cout<<"\n\t\t\t\t*************";
        cout<<"\n\n\n\t\t\t1.Enter a new students details";
        cout<<"\n\t\t\t2.Enter the marks obtained by a new student";
        cout<<"\n\t\t\t3.Modify the details for an exislting student";
        cout<<"\n\t\t\t4.Delete a students details";
        cout<<"\n\t\t\t5.Display the details of a particular student";
        cout<<"\n\t\t\t6.Display the mark sheet of a particular student";
        cout<<"\n\t\t\t7.Display the stream wise personal information of each student";
        cout<<"\n\t\t\t8.Display the stream wise result list of each student";
        cout<<"\n\t\t\t9.Exit";
        cout<<"\n\t\t\tEnter a choice[1-9]";
   	  cin>>choice;
        switch(choice)
        {
        	case 1:
         	addfile();
            break;
         case 2:
         	addresult();
            break;
         case 3:
         	modification();
            break;
         case 4:
         	deleterecord();
            break;
         case 5:
         	studentdetails();
            break;
         case 6:
         	studentresult();
            break;
         case 7:
         	streamwisepersonalinformation();
            break;
         case 8:
         	resultstream();
            break;
         case 9:
         	break;
         }
   }while(choice!=9);
}
void main()
{
	clrscr();
   mainmenu();

}














































































