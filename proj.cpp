//**************************HEADER FILES INCLUDED****************************//
//#include<fstream.h>
#include<conio.h>
#include<dos.h>
#include<math.h>
#include<iomanip.h>
#include<process.h>
#include<stdio.h>
#include<string.h>
#include<graphics.h>
void welcome();
int cost[50];
int code;
char name[50];
int q[50];
int f=0;
char comp[50][50];
char item[50][50];
void clear()
{
for(int i=0;i<=f;i++)
{
cost[i]=0;
q[i]=0;
strcpy(comp[i],"");
strcpy(item[i],"");
 }
f=0;code=0;strcpy(name,"");
}
//***********************CLASS FOR CONSUMER  INFORMATION*************************//
class consumer
{
long int cno;
char cname[50];
char address[50];
char email[100];
char phoneno[50];
public:
//**************************CONSTRUCTER****************************//
consumer()
{
cno=0;
strcpy(cname,NULL);
strcpy(address,NULL);
strcpy(phoneno,NULL);
strcpy(email,NULL);
}
//**************************function to purchase**********************//
void submenu(int sr=1)
{
cleardevice();
consumer c;
 int er=0;
settextstyle(3,0,1);
ifstream in("file.txt",ios::in|ios::binary);
if(sr==1)
{
outtextxy(100,106," Enter the customer code to be searched  ");
 gotoxy(67,8);
int ay;cin>>ay; code=ay;
for(;!in.eof();)
{
in.read((char*)&c,sizeof(c));
if(c.cno==ay)
er=1;
}
}
if(er==1||sr==0)
{
t: char a; char d;
cleardevice();
settextstyle(7,0,4);
outtextxy(50,50,"  ******** ROSHNI KENDRA ********");
outtextxy(50,90,"  ****** LIST OF COMPANYS ******");
settextstyle(3,0,1);
outtextxy(100,200," 1. Bajaj  ");
outtextxy(100,232," 2. Usha");
outtextxy(100,264," 3. Orient");
outtextxy(100,296," 4. Indo ");
outtextxy(100,328," 5. Guru  ");
outtextxy(50,430,"Enter the company code whose product you want to purchase");
a=getch();
char k;int qe=0;
cleardevice();
if(a=='1')
{
BAJAJ b;b.buy();
outtextxy(70,70,"ENTER y IF YOU WANT TO PURCHASE AGAIN OTHERWISE  n");
k=getch();
if(k=='y')
goto t;
else
qe=1;
}
else if(a=='2')
{
USHA u;
u.buy();
outtextxy(70,70,"ENTER y IF YOU WANT TO PURCHASE AGAIN OTHERWISE  n");
k=getch();
if(k=='y')
goto t;
else
qe=1;
}
else if(a=='3')
{
ORIENT o;
o.buy();
outtextxy(70,70,"ENTER y IF YOU WANT TO PURCHASE AGAIN OTHERWISE  n");
k=getch();
if(k=='y')
goto t;
else
qe=1;
}
else if(a=='4')
{
INDO i;
i.buy();
outtextxy(70,70,"ENTER y IF YOU WANT TO PURCHASE AGAIN OTHERWISE  n");
k=getch();
if(k=='y')
goto t;
else
qe=1;
}
else if(a=='5')
{
GURU g;
g.buy();
outtextxy(70,70,"ENTER y IF YOU WANT TO PURCHASE AGAIN OTHERWISE  n");
k=getch();
if(k=='y')
goto t;
else
qe=1;}
else
{
outtextxy(70,70,"wrong choice!!");
getch();
c.mainmenu();}
if(qe==1)
{
cleardevice();
outtextxy(70,70,"\n Do you want to see the bill(y/n)  ");
d=getch();
//**************************MODULE FOR BILL****************************//
if(d=='y')
{
 cleardevice();
int t=0;
long grand=0;
setlinestyle(1,0,1);
line(21,98,600,98);
line(21,94,600,94);
line(21,140,600,140);
line(21,136,600,136);
line(21,180,600,180);
line(21,184,600,184);
line(119,140,119,370);
line(115,140,115,370);
line(200,140,200,370);
line(204,140,204,370);
line(340,140,340,370);
line(336,140,336,370);
line(420,140,420,370);
line(416,140,416,370);
line(520,140,520,370);
line(524,140,524,370);
line(21,370,600,370);
line(21,374,600,374);
line(410,374,410,404);
line(406,374,406,408);
line(410,404,600,404);
line(406,408,600,408);
setlinestyle(0,0,1);
setcolor(3);
rectangle(21,15,600,450);
rectangle(16,11,604,454);
setfillstyle(6,3);
floodfill(18,13,3);
settextstyle(7,0,4);
outtextxy(20,20,"  ******** ROSHNI KENDRA ********");
outtextxy(20,55,"  ********    SALE BILL     ********");
settextstyle(3,0,1);
outtextxy(30,105,"Customer Code:");
gotoxy(25,8); cout<<code;
outtextxy(290,105,"Customer Name:");
ifstream in("file.txt",ios::in|ios::binary);
for(;!in.eof();)
{
in.read((char*)&c,sizeof(c));
if(c.cno==code)
 strcpy(name,c.cname); } in.close();
gotoxy(57,8); puts(name);
outtextxy(30,150,"Serial No.");
outtextxy(123,150,"Company");
outtextxy(260,150,"Item");
outtextxy(350,150,"Cost");
outtextxy(430,150,"Quantity");
outtextxy(550,150,"Total");
for(int i=0;i<f;i++)
{
t=cost[i]*q[i];
gotoxy(8,2*i+13);
cout<<i+1;
gotoxy(19,2*i+13);
cout<<comp[i];
gotoxy(27,2*i+13);
cout<<item[i];
gotoxy(45,2*i+13);
cout<<cost[i];
gotoxy(57,2*i+13);
cout<<q[i];
gotoxy(69,2*i+13);
cout<<t;
grand+=t;
t=0;
}
gotoxy(69,25);
outtextxy(420,378,"Grand Total = ");
cout<<grand;
settextstyle(0,0,0);
outtextxy(30,390,"NOTICE :");
outtextxy(30,410,"Goods once sold will not be replaced.");
outtextxy(30,430,"For any complaint or information log on to Roshnikendra.in");
getch();
a=0;sr=1;clear();
}
}
}
else
{
cleardevice();
outtextxy(50,100,"RECORD DOES NOT EXIST");
outtextxy(50,140,"Enter 1 if you want to add new coustmer information");
outtextxy(50,180,"Enter 2 if you want to return to Main Menu");
char q;
q=getch();
if(q=='1')
{
c.add(0);
cleardevice();
goto t;
}
else
 {
cleardevice();
c.mainmenu();}
}
}
//**************************function to enter values******************//
void get()
{
cleardevice();
 settextstyle(7,0,4);
outtextxy(50,50,"  ******** ROSHNI KENDRA ********");
outtextxy(50,90,"***** CUSTOMER INFORMATION*****");
settextstyle(3,0,1);
outtextxy(100,200," Enter the Customer code");
outtextxy(100,232," Enter the Customer name");
outtextxy(100,264," Enter the Customer address");
outtextxy(100,296," Enter the Customer phoneno.");
outtextxy(100,328," Enter the Customer Email Id.");
gotoxy(55,14);
cin>>cno;
gotoxy(55,16);
gets(cname);
gotoxy(55,18);
gets(address);
gotoxy(55,20);
gets(phoneno);
gotoxy(55,22);
gets(email);
outtextxy(50,400,"Please press any key to proceed.....");
getch();
}

//**********************function for output**********************//
void show()
{
cleardevice();
 settextstyle(7,0,4);
outtextxy(50,50,"  ******** ROSHNI KENDRA ********");
outtextxy(50,90,"***** CUSTOMER INFORMATION*****");
settextstyle(3,0,1);
outtextxy(100,200," Customer code");
outtextxy(100,232," Customer name");
outtextxy(100,264," Customer address");
outtextxy(100,296," Customer phoneno.");
outtextxy(100,328," Customer Email Id.");
gotoxy(55,14);
cout<<cno;
gotoxy(55,16);
puts(cname);
gotoxy(55,18);
puts(address);
gotoxy(55,20);
puts(phoneno);
gotoxy(55,22);
puts(email);
outtextxy(50,400,"Please press any key to proceed.....");
getch();
}
 /////////////////////function to add a record/////////////////////
 void add(int rf=1)
 {
cleardevice();
settextstyle(3,0,1);
 char ab;
 consumer c;
if(rf==1)
{
outtextxy(100,100,"Enter 1 if you want to add product ");
outtextxy(100,140,"Enter 2 if you want to add coustmer code");
ab=getch();
}
 char a;
if(ab=='2'||rf==0)
{
ofstream out("file.txt",ios::app|ios::binary);
c.get();
out.write((char*)&c,sizeof(c));
out.close();
cleardevice();
outtextxy(100,100,"YOUR RECORD HAS BEEN SAVED");
getch();
}
if(ab=='1')
c.addproduct();
}
//**************************FUNCTION TO ADD PRODUCT****************************//
void addproduct()
{
char a;
g:
cleardevice();
settextstyle(7,0,4);
outtextxy(50,50,"  ******** ROSHNI KENDRA ********");
outtextxy(50,90,"  ****** LIST OF COMPANYS ******");
settextstyle(3,0,1);
outtextxy(100,200," 1. Bajaj  ");
outtextxy(100,232," 2. Usha");
outtextxy(100,264," 3. Orient");
outtextxy(100,296," 4. Indo ");
outtextxy(100,328," 5. Guru  ");
outtextxy(50,430,"Enter the company code whose stock you want to add  ");
a=getch();
 consumer c;
cleardevice();
if(a=='1')
{
BAJAJ b;
ofstream out("bajaj.txt",ios::app|ios::binary);
cleardevice();
products();
ifstream in("bajaj.txt",ios::in|ios::binary);
ofstream out1("tem.txt",ios::out|ios::binary);
in.read((char*)&b,sizeof(b));
b.input();
out1.write((char*)&b,sizeof(b));
in.close();out.close();out1.close();
remove("bajaj.txt");
rename("tem.txt","bajaj.txt");}
if(a=='2')
{USHA u;
ofstream out("usha.txt",ios::app|ios::binary);
cleardevice();products();
ifstream in("usha.txt",ios::in|ios::binary);
ofstream out1("tem.txt",ios::out|ios::binary);
in.read((char*)&u,sizeof(u));
u.input();
out1.write((char*)&u,sizeof(u));
in.close();out.close();out1.close();
remove("usha.txt");
rename("tem.txt","usha.txt");
}
if(a=='3')
{
ORIENT o;
ofstream out("orient.txt",ios::app|ios::binary);
cleardevice();products();
ifstream in("orient.txt",ios::in|ios::binary);
ofstream out1("tem.txt",ios::out|ios::binary);
in.read((char*)&o,sizeof(o));
o.input();
out1.write((char*)&o,sizeof(o));
in.close();out.close();out1.close();
remove("orient.txt");
rename("tem.txt","orient.txt");
}
if(a=='4')
{
INDO i;
ofstream out("indo.txt",ios::app|ios::binary);
cleardevice();
products();
ifstream in("indo.txt",ios::in|ios::binary);
ofstream out1("tem.txt",ios::out|ios::binary);
in.read((char*)&i,sizeof(i));
i.input();
out1.write((char*)&i,sizeof(i));
in.close();out.close();out1.close();
remove("indo.txt");
rename("tem.txt","indo.txt");
}
if(a=='5')
{
GURU g;
ofstream out("guru.txt",ios::app|ios::binary);
cleardevice();
products();
ifstream in("guru.txt",ios::in|ios::binary);
ofstream out1("tem.txt",ios::out|ios::binary);
in.read((char*)&g,sizeof(g));
g.input();
out1.write((char*)&g,sizeof(g));
in.close();out.close();out1.close();
remove("guru.txt");
rename("tem.txt","guru.txt");
}
char b;
cleardevice();
settextstyle(3,0,1);
outtextxy(100,100,"IF YOU WANT ADD RECORD OF ANY OTHER COMPANY PRESS 1");
outtextxy(200,140,"OR");
outtextxy(100,190,"YOU WANT TO RETURN TO MAIN MENU PRESS 2");
b=getch();
  if(b=='1')
  goto g;
  else
  c.mainmenu();
 }
 //**************************FUNCTION TO SEARCH A RECORD****************************//
 void search()
  {
  cleardevice();
  consumer c;
settextstyle(3,0,1);
  ifstream in("file.txt",ios::in|ios::binary);
  outtextxy(100,106," Enter the customer code to be searched  ");
  gotoxy(67,8);
  int a,f=0;
  cin>>a;
  for(;!in.eof();)
  {
  in.read((char*)&c,sizeof(c));
  if(c.cno==a)
  {
  f=1;
  c.show();
  }
  }
  char b;
  cleardevice();
  if(f!=1)
outtextxy(100,140," Entered customer code not found!!!!!");
outtextxy(100,190," Do you want to search again (y/n)");
  b=getch();
  if(b=='y')
  c.search();
  in.close();
cleardevice();
  }
 //***********************FUNCTION TO SHOW ALL THE RECORDS**************************//
void showall()
   {
   cleardevice();
  consumer c;
  ifstream in("file.txt",ios::in|ios::binary);
  for(;!in.eof();)
  {
  in.read((char*)&c,sizeof(c));
  c.show();
  }
  in.close();
 }

 //***********************FUNCTION TO DELETE A RECORD**************************//
void del()
{
cleardevice();
settextstyle(3,0,1);
consumer c;
ifstream in("file.txt",ios::in|ios::binary);
ofstream out("temp.txt",ios::out|ios::binary);
outtextxy(100,106," Enter the Customer code to be deleted ");
gotoxy(67,8);
int a,f=0;char b;
cin>>a;
for(;!in.eof();)
{
in.read((char*)&c,sizeof(c));
if(c.cno==a)
{
f=1;break;
}
}
if(f==1)
{
c.show();
outtextxy(50,430," Do you want to delete this record (y,n) ");
b=getch();
if(b=='y')
{
for(;!in.eof();)
{
in.read((char*)&c,sizeof(c));
if(c.cno!=a)
out.write((char*)&c,sizeof(c));
}
in.close();
out.close();
remove("file.txt");
rename("temp.txt","file.txt"); cleardevice();
outtextxy(100,100,"YOUR RECORD HAS BEEN DELETED");
}
}
else
outtextxy(100,140,"RECORD NOT FOUND"); getch();
}
//***********************FUNCTION TO MODIFY  A RECORD**************************//
 void modify()
  {
cleardevice();
  consumer c;
settextstyle(3,0,1);
  ifstream in("file.txt",ios::in|ios::binary);
  ofstream out("temp.txt",ios::out|ios::binary);
outtextxy(100,106," Enter the Customer code to be modified ");
gotoxy(67,8);
  int a;char b;int tt=0;
  cin>>a;
  for(;!in.eof();)
  {
  in.read((char*)&c,sizeof(c));
  if(c.cno==a)
  {
tt=1;
break;
  }
}
  if(tt==1)
  {
   c.show();
outtextxy(50,430," Do you want to modify this record (y,n) ");
  b=getch();
  if(b=='y')
  {
  for(;!in.eof();)
  {
  in.read((char*)&c,sizeof(c));
  if(c.cno!=a)
  out.write((char*)&c,sizeof(c));
  }
  cleardevice();
  outtextxy(100,100," Enter the new information ");
  c.get();
  out.write((char*)&c,sizeof(c));
  in.close();
  out.close();
  remove("file.txt");
  rename("temp.txt","file.txt");cleardevice();
  outtextxy(100,100,"YOUR RECORD HAS BEEN MODIFIED"); getch();
  }
}
  else
  {
 cleardevice();
  outtextxy(100,100,"RECORD DOES NOT EXIST");  getch();
 }
  }
//***********************FUNCTION FOR MAIN MENU**************************//
void mainmenu()
{
char a;
l:
 cleardevice();
consumer c;
setcolor(GREEN);
setfillstyle(11,LIGHTBLUE);
bar3d(0,20, 600,450, 25, 1);
settextstyle(7,0,5);
outtextxy(10, 19,"******ROSHNI KENDRA******");
outtextxy(10,66,"******* MAIN MENU  *******");
settextstyle(3,0, 3); setcolor(7);
outtextxy(15,129,"#1. Purchase items  ");
outtextxy(15,159,"#2. Add a record   ");
outtextxy(15,189,"#3. Show a record   ");
outtextxy(15,219,"#4. Delete a record  ");
outtextxy(15,249,"#5. Modify a record  ");
outtextxy(15,279,"#6. Show all the record  ");
outtextxy(15,309,"#7. Stock ");
outtextxy(15,339,"#8. Exit ");
settextstyle(1,0, 4);
outtextxy(15,389,"Enter your choice(1-8)...  ");
  a=getch();
cleardevice();
 if(a=='1')
{
c.submenu();
last();
}
else if(a=='2')
{
c.add();
last();
}
else if(a=='3')
{
c.search();
last();
}
else if(a=='4')
{
c.del();
 last();
}
else if(a=='5')
{
c.modify();
last();
}
else if(a=='6')
{
c.showall();
last();
}
else if(a=='7')
{
stock();
last();
}
else if(a=='8')
exit(0);
 else
{
settextstyle(3,0,3);
outtextxy(400,389," Wrong choice!!!!!  ");
  }
goto l;
  }
};
 //********************FUNCTION TO PRINT PRICE OF PRODUCTS**********************//
 void print()
{
cleardevice();
setfillstyle(0,0);
 setcolor(GREEN);
settextstyle(8,0,2);
bar3d(15,70,270,200,10,10);
bar3d(200,250,500,380,10,10);
bar3d(310,70,620,200,10,10);
outtextxy(15,75," APPLIANCES  PRICE ");
outtextxy(315,75,"LIGHTING PRODUCTS PRICE");
outtextxy(204,250,"WIRING PRODUCTS  PRICE ");
settextstyle(3,0,1);
 setcolor(WHITE);
outtextxy(15,100," 1. Cooler         2700");
outtextxy(15,125," 2. Induction       1600");
outtextxy(15,150," 3. Geyser         5800");
outtextxy(15,175," 4. Fans           1070");
outtextxy(325,100," 5. Bulbs                  200");
outtextxy(325,125," 6. Mercury                50");
outtextxy(325,150," 7. Surface Lights         450");
outtextxy(325,175," 8. Concealed Lights       650");
outtextxy(200,275,"  9. Wires                  500");
outtextxy(200,300," 10. Bulb Holders            20 ");
outtextxy(200,325," 11. Switches               30");
outtextxy(200,350," 12. Sockets                25 ");
}
//********************FUNCTION TO SHOW ALL THE PRODUCTS***********************//
void products()
{
cleardevice();
 setfillstyle(0,0);
setcolor(GREEN);
 settextstyle(8,0,2);
bar3d(15,70,200,200,10,10);
bar3d(200,250,420,380,10,10);
bar3d(320,70,580,200,10,10);
outtextxy(15,75,"  APPLIANCES ");
outtextxy(325,75," LIGHTING PRODUCTS ");
outtextxy(200,250," WIRING PRODUCTS ");
settextstyle(3,0,1);
 setcolor(WHITE);
outtextxy(15,100," 1. Cooler");
outtextxy(15,125," 2. Induction");
outtextxy(15,150," 3. Geyser");
outtextxy(15,175," 4. Fans");
outtextxy(325,100," 5. Bulbs");
outtextxy(325,125," 6. Mercury");
outtextxy(325,150," 7. Surface Lights");
outtextxy(325,175," 8. Concealed Lights");
outtextxy(200,275,"  9. Wires");
outtextxy(200,300," 10. Bulb Holders ");
outtextxy(200,325," 11. Switches");
outtextxy(200,350," 12. Sockets ");
getch();
}
//***********************CLASS FOR COMPANY**************************//
class BAJAJ
{
int a,b,cooler,induction,geyser,fan,bulb,concealed;
int surface,mercury,wire,holder,switchs,socket;
public:
//***********************CLASS CONSTRUCTOR**************************//
BAJAJ()
{
cooler=0,induction=0,geyser=0,fan=0,bulb=0,concealed=0;
surface=0,mercury=0,wire=0,holder=0,switchs=0,socket=0;
}
//***********************FUNCTION FOR PRODUCT INPUT**************************//
void input()
{
settextstyle(3,0,1);
outtextxy(20,378,"Enter the product code to change the quantity ");
gotoxy(65,25);
cin>>a; b=0;
cout<<"\n\t\t\t\t\t\t";
outtextxy(20,410,"Enter the quantity");
cin>>b;
switch(a)
{
case 1:
cooler+=b;
b=0;
break;
case 2:
induction+=b;
b=0;
break;
case 3:
geyser+=b;
b=0;
break;
case 4:
fan+=b;
b=0;
break;
case 5:
bulb+=b;
b=0;
break;
case 6:
mercury+=b;
b=0;
break;
case 7:
surface+=b;
b=0;
break;
case 8:
concealed+=b;
b=0;
break;
case 9:
wire+=b;
b=0;
break;
case 10:
holder+=b;
b=0;
break;
case 11:
switchs+=b;
b=0;
break;
case 12:
socket+=b;
b=0;
break;
default:
outtextxy(50,400,"Wrong Choice");
}
cleardevice();
}

//***********************FUNCTION FOR ITEM PURCHASE**************************//
void purchase()
{
outtextxy(20,378,"Enter the product code you want to purchase");
gotoxy(65,25);
a=0;
cin>>a;
b=0;
cout<<"\n\t\t\t\t\t\t";
outtextxy(20,410,"Enter the quantity  ");
cin>>b;
q[f]=b;
 strcpy(comp[f],"Bajaj");
switch(a)
{
case 1:
cooler-=b;
strcpy(item[f],"Cooler");
cost[f]=2700;
break;
case 2:
induction-=b;
strcpy(item[f],"Induction");
cost[f]=1600;
break;
case 3:
geyser-=b;
strcpy(item[f],"Geyser");
cost[f]=5800;
break;
case 4:
fan-=b;
strcpy(item[f],"Fan");
cost[f]=1070;
break;
case 5:
bulb-=b;
strcpy(item[f],"Bulb");
cost[f]=200;
break;
case 6:
mercury-=b;
strcpy(item[f],"Mercury");
cost[f]=50;
break;
case 7:
surface-=b;
strcpy(item[f],"Surface Light");
cost[f]=450;
break;
case 8:
concealed-=b;
strcpy(item[f],"Concealed Light");
cost[f]=650;
break;
case 9:
wire-=b;
strcpy(item[f],"Wire");
cost[f]=500;
break;
case 10:
holder-=b;
strcpy(item[f],"Holder");
cost[f]=20;
break;
case 11:
switchs-=b;
strcpy(item[f],"Switch");
cost[f]=30;
break;
case 12:
socket-=b;
strcpy(item[f],"Socket");
cost[f]=25;
break;
}
b=0;
cleardevice();
}
//***********************FUNCTION TO DISPLAY STOCK**************************//
void display()
{
cleardevice();
setcolor(GREEN);
 setfillstyle(0,0);
  settextstyle(8,0,2);
bar3d(15,70,205,230,10,10);
bar3d(200,250,430,420,10,10);
bar3d(325,70,575,230,10,10);
outtextxy(15,75,"  APPLIANCES ");
outtextxy(325,75," LIGHTING PRODUCTS ");
outtextxy(200,250," WIRING PRODUCTS ");
settextstyle(3,0,1);
setcolor(WHITE);
outtextxy(15,106," 1. Cooler");
gotoxy(23,8);
cout<<cooler;
outtextxy(15,137," 2. Induction");
gotoxy(23,10);
cout<<induction;
outtextxy(15,169," 3. Geyser");
gotoxy(23,12);
cout<<geyser;
outtextxy(15,200," 4. Fans");
 gotoxy(23,14);
cout<<fan;
outtextxy(325,106," 5. Bulbs");
gotoxy(69,8);
cout<<bulb;
outtextxy(325,137," 6. Mercury");
gotoxy(69,10);
cout<<mercury;
outtextxy(325,169," 7. Surface Lights");
gotoxy(69,12);
cout<<surface;
outtextxy(325,200," 8. Concealed Lights");
gotoxy(69,14);
cout<<concealed;
outtextxy(200,281,"  9. Wires");
gotoxy(51,19);
cout<<wire;
outtextxy(200,312," 10. Bulb Holders ");
gotoxy(51,21);
cout<<holder;
outtextxy(200,344," 11. Switches");
gotoxy(51,23);
cout<<switchs;
outtextxy(200,376," 12. Sockets ");
gotoxy(51,25);
cout<<socket;
}
//***********************FUNCTION TO UPDATE STOCK**************************//
void buy()
{
BAJAJ d;
ofstream out("bajaj.txt",ios::app|ios::binary);
cleardevice();
print();
ifstream in("bajaj.txt",ios::in|ios::binary);
ofstream out1("tem.txt",ios::out|ios::binary);
in.read((char*)&d,sizeof(d));
d.purchase();
out1.write((char*)&d,sizeof(d));
in.close();
out.close();
out1.close();
remove("bajaj.txt");
rename("tem.txt","bajaj.txt");
f++;
}
};
//***********************CLASS FOR COMPANY**************************//
class USHA
{
int a,b,cooler,induction,geyser,fan,bulb,concealed;
int surface,mercury,wire,holder,switchs,socket;
public:
//***********************CLASS CONSTRUCTOR**************************//
USHA ()
{
cooler=0,induction=0,geyser=0,fan=0,bulb=0,concealed=0;
surface=0,mercury=0,wire=0,holder=0,switchs=0,socket=0;
}
//***********************FUNCTION FOR PRODUCT INPUT**************************//
void input()
{
settextstyle(3,0,1);
outtextxy(20,378,"Enter the product code to change the quantity ");
gotoxy(65,25);
cin>>a; b=0;
cout<<"\n\t\t\t\t\t\t";
outtextxy(20,410,"Enter the quantity");
cin>>b;
switch(a)
{
case 1:
cooler+=b;
b=0;
break;
case 2:
induction+=b;
b=0;
break;
case 3:
geyser+=b;
b=0;
break;
case 4:
fan+=b;
b=0;
break;
case 5:
bulb+=b;
b=0;
break;
case 6:
mercury+=b;
b=0;
break;
case 7:
surface+=b;
b=0;
break;
case 8:
concealed+=b;
b=0;
break;
case 9:
wire+=b;
b=0;
break;
case 10:
holder+=b;
b=0;
break;
case 11:
switchs+=b;
b=0;
break;
case 12:
socket+=b;
b=0;
break;
default:
outtextxy(50,400,"Wrong Choice");
}
cleardevice();
}

//***********************FUNCTION FOR ITEM PURCHASE**************************//
void purchase()
{
outtextxy(20,378,"Enter the product code you want to purchase");
gotoxy(65,25);
a=0;
cin>>a;
b=0;
cout<<"\n\t\t\t\t\t\t";
outtextxy(20,410,"Enter the quantity  ");
cin>>b;
q[f]=b;
 strcpy(comp[f]," Usha");
switch(a)
{
case 1:
cooler-=b;
strcpy(item[f],"Cooler");
cost[f]=2700;
break;
case 2:
induction-=b;
strcpy(item[f],"Induction");
cost[f]=1600;
break;
case 3:
geyser-=b;
strcpy(item[f],"Geyser");
cost[f]=5800;
break;
case 4:
fan-=b;
strcpy(item[f],"Fan");
cost[f]=1070;
break;
case 5:
bulb-=b;
strcpy(item[f],"Bulb");
cost[f]=200;
break;
case 6:
mercury-=b;
strcpy(item[f],"Mercury");
cost[f]=50;
break;
case 7:
surface-=b;
strcpy(item[f],"Surface Light");
cost[f]=450;
break;
case 8:
concealed-=b;
strcpy(item[f],"Concealed Light");
cost[f]=650;
break;
case 9:
wire-=b;
strcpy(item[f],"Wire");
cost[f]=500;
break;
case 10:
holder-=b;
strcpy(item[f],"Holder");
cost[f]=20;
break;
case 11:
switchs-=b;
strcpy(item[f],"Switch");
cost[f]=30;
break;
case 12:
socket-=b;
strcpy(item[f],"Socket");
cost[f]=25;
break;
}
b=0;
cleardevice();
}
//***********************FUNCTION TO DISPLAY STOCK**************************//
void display()
{
cleardevice();
setcolor(GREEN);
 setfillstyle(0,0);
  settextstyle(8,0,2);
bar3d(15,70,205,230,10,10);
bar3d(200,250,430,420,10,10);
bar3d(325,70,575,230,10,10);
outtextxy(15,75,"  APPLIANCES ");
outtextxy(325,75," LIGHTING PRODUCTS ");
outtextxy(200,250," WIRING PRODUCTS ");
settextstyle(3,0,1);
setcolor(WHITE);
outtextxy(15,106," 1. Cooler");
gotoxy(23,8);
cout<<cooler;
outtextxy(15,137," 2. Induction");
gotoxy(23,10);
cout<<induction;
outtextxy(15,169," 3. Geyser");
gotoxy(23,12);
cout<<geyser;
outtextxy(15,200," 4. Fans");
 gotoxy(23,14);
cout<<fan;
outtextxy(325,106," 5. Bulbs");
gotoxy(69,8);
cout<<bulb;
outtextxy(325,137," 6. Mercury");
gotoxy(69,10);
cout<<mercury;
outtextxy(325,169," 7. Surface Lights");
gotoxy(69,12);
cout<<surface;
outtextxy(325,200," 8. Concealed Lights");
gotoxy(69,14);
cout<<concealed;
outtextxy(200,281,"  9. Wires");
gotoxy(51,19);
cout<<wire;
outtextxy(200,312," 10. Bulb Holders ");
gotoxy(51,21);
cout<<holder;
outtextxy(200,344," 11. Switches");
gotoxy(51,23);
cout<<switchs;
outtextxy(200,376," 12. Sockets ");
gotoxy(51,25);
cout<<socket;
}
//***********************FUNCTION TO UPDATE STOCK**************************//
void buy()
{
cleardevice();
USHA u;
char k;
ofstream out("usha.txt",ios::app|ios::binary);
cleardevice();
print();
ifstream in("usha.txt",ios::in|ios::binary);
ofstream out1("tem.txt",ios::out|ios::binary);
in.read((char*)&u,sizeof(u));
u.purchase();
out1.write((char*)&u,sizeof(u));
in.close();
out.close();
out1.close();
remove("usha.txt");
rename("tem.txt","usha.txt");f++;
}
};
//***********************CLASS FOR COMPANY**************************//
class ORIENT
{
int a,b,cooler,induction,geyser,fan,bulb,concealed;
int surface,mercury,wire,holder,switchs,socket;
public:
//***********************CLASS CONSTRUCTOR**************************//
ORIENT()
{
cooler=0,induction=0,geyser=0,fan=0,bulb=0,concealed=0;
surface=0,mercury=0,wire=0,holder=0,switchs=0,socket=0;
}
//***********************FUNCTION FOR PRODUCT INPUT**************************//
void input()
{
settextstyle(3,0,1);
outtextxy(20,378,"Enter the product code to change the quantity ");
gotoxy(65,25);
cin>>a; b=0;
cout<<"\n\t\t\t\t\t\t";
outtextxy(20,410,"Enter the quantity");
cin>>b;
switch(a)
{
case 1:
cooler+=b;
b=0;
break;
case 2:
induction+=b;
b=0;
break;
case 3:
geyser+=b;
b=0;
break;
case 4:
fan+=b;
b=0;
break;
case 5:
bulb+=b;
b=0;
break;
case 6:
mercury+=b;
b=0;
break;
case 7:
surface+=b;
b=0;
break;
case 8:
concealed+=b;
b=0;
break;
case 9:
wire+=b;
b=0;
break;
case 10:
holder+=b;
b=0;
break;
case 11:
switchs+=b;
b=0;
break;
case 12:
socket+=b;
b=0;
break;
default:
outtextxy(50,400,"Wrong Choice");
}
cleardevice();
}

//***********************FUNCTION FOR ITEM PURCHASE**************************//
void purchase()
{
outtextxy(20,378,"Enter the product code you want to purchase");
gotoxy(65,25);
a=0;
cin>>a;
b=0;
cout<<"\n\t\t\t\t\t\t";
outtextxy(20,410,"Enter the quantity  ");
cin>>b;
q[f]=b;
 strcpy(comp[f]," Orient");
switch(a)
{
case 1:
cooler-=b;
strcpy(item[f],"Cooler");
cost[f]=2700;
break;
case 2:
induction-=b;
strcpy(item[f],"Induction");
cost[f]=1600;
break;
case 3:
geyser-=b;
strcpy(item[f],"Geyser");
cost[f]=5800;
break;
case 4:
fan-=b;
strcpy(item[f],"Fan");
cost[f]=1070;
break;
case 5:
bulb-=b;
strcpy(item[f],"Bulb");
cost[f]=200;
break;
case 6:
mercury-=b;
strcpy(item[f],"Mercury");
cost[f]=50;
break;
case 7:
surface-=b;
strcpy(item[f],"Surface Light");
cost[f]=450;
break;
case 8:
concealed-=b;
strcpy(item[f],"Concealed Light");
cost[f]=650;
break;
case 9:
wire-=b;
strcpy(item[f],"Wire");
cost[f]=500;
break;
case 10:
holder-=b;
strcpy(item[f],"Holder");
cost[f]=20;
break;
case 11:
switchs-=b;
strcpy(item[f],"Switch");
cost[f]=30;
break;
case 12:
socket-=b;
strcpy(item[f],"Socket");
cost[f]=25;
break;
}
b=0;
cleardevice();
}
//***********************FUNCTION TO DISPLAY STOCK**************************//
void display()
{
cleardevice();
setcolor(GREEN);
 setfillstyle(0,0);
  settextstyle(8,0,2);
bar3d(15,70,205,230,10,10);
bar3d(200,250,430,420,10,10);
bar3d(325,70,575,230,10,10);
outtextxy(15,75,"  APPLIANCES ");
outtextxy(325,75," LIGHTING PRODUCTS ");
outtextxy(200,250," WIRING PRODUCTS ");
settextstyle(3,0,1);
setcolor(WHITE);
outtextxy(15,106," 1. Cooler");
gotoxy(23,8);
cout<<cooler;
outtextxy(15,137," 2. Induction");
gotoxy(23,10);
cout<<induction;
outtextxy(15,169," 3. Geyser");
gotoxy(23,12);
cout<<geyser;
outtextxy(15,200," 4. Fans");
 gotoxy(23,14);
cout<<fan;
outtextxy(325,106," 5. Bulbs");
gotoxy(69,8);
cout<<bulb;
outtextxy(325,137," 6. Mercury");
gotoxy(69,10);
cout<<mercury;
outtextxy(325,169," 7. Surface Lights");
gotoxy(69,12);
cout<<surface;
outtextxy(325,200," 8. Concealed Lights");
gotoxy(69,14);
cout<<concealed;
outtextxy(200,281,"  9. Wires");
gotoxy(51,19);
cout<<wire;
outtextxy(200,312," 10. Bulb Holders ");
gotoxy(51,21);
cout<<holder;
outtextxy(200,344," 11. Switches");
gotoxy(51,23);
cout<<switchs;
outtextxy(200,376," 12. Sockets ");
gotoxy(51,25);
cout<<socket;
}
//***********************FUNCTION TO UPDATE STOCK**************************//
void buy()
{
cleardevice();
ORIENT o;
char k;
ofstream out("orient.txt",ios::app|ios::binary);
cleardevice();
print();
ifstream in("orient.txt",ios::in|ios::binary);
ofstream out1("tem.txt",ios::out|ios::binary);
in.read((char*)&o,sizeof(o));
o.purchase();
out1.write((char*)&o,sizeof(o));
in.close();
out.close();
out1.close();
remove("orient.txt");
rename("tem.txt","orient.txt");
f++;
}
};
//***********************CLASS FOR COMPANY**************************//
class INDO
{
int a,b,cooler,induction,geyser,fan,bulb,concealed;
int surface,mercury,wire,holder,switchs,socket;
public:
//***********************CLASS CONSTRUCTOR**************************//
INDO()
{
cooler=0,induction=0,geyser=0,fan=0,bulb=0,concealed=0;
surface=0,mercury=0,wire=0,holder=0,switchs=0,socket=0;
}
//***********************FUNCTION FOR PRODUCT INPUT**************************//
void input()
{
settextstyle(3,0,1);
outtextxy(20,378,"Enter the product code to change the quantity ");
gotoxy(65,25);
cin>>a; b=0;
cout<<"\n\t\t\t\t\t\t";
outtextxy(20,410,"Enter the quantity");
cin>>b;
switch(a)
{
case 1:
cooler+=b;
b=0;
break;
case 2:
induction+=b;
b=0;
break;
case 3:
geyser+=b;
b=0;
break;
case 4:
fan+=b;
b=0;
break;
case 5:
bulb+=b;
b=0;
break;
case 6:
mercury+=b;
b=0;
break;
case 7:
surface+=b;
b=0;
break;
case 8:
concealed+=b;
b=0;
break;
case 9:
wire+=b;
b=0;
break;
case 10:
holder+=b;
b=0;
break;
case 11:
switchs+=b;
b=0;
break;
case 12:
socket+=b;
b=0;
break;
default:
outtextxy(50,400,"Wrong Choice");
}
cleardevice();
}
//***********************FUNCTION FOR ITEM PURCHASE**************************//
void purchase()
{
outtextxy(20,378,"Enter the product code you want to purchase");
gotoxy(65,25);
a=0;
cin>>a;
b=0;
cout<<"\n\t\t\t\t\t\t";
outtextxy(20,410,"Enter the quantity  ");
cin>>b;
q[f]=b;
 strcpy(comp[f]," Indo");
switch(a)
{
case 1:
cooler-=b;
strcpy(item[f],"Cooler");
cost[f]=2700;
break;
case 2:
induction-=b;
strcpy(item[f],"Induction");
cost[f]=1600;
break;
case 3:
geyser-=b;
strcpy(item[f],"Geyser");
cost[f]=5800;
break;
case 4:
fan-=b;
strcpy(item[f],"Fan");
cost[f]=1070;
break;
case 5:
bulb-=b;
strcpy(item[f],"Bulb");
cost[f]=200;
break;
case 6:
mercury-=b;
strcpy(item[f],"Mercury");
cost[f]=50;
break;
case 7:
surface-=b;
strcpy(item[f],"Surface Light");
cost[f]=450;
break;
case 8:
concealed-=b;
strcpy(item[f],"Concealed Light");
cost[f]=650;
break;
case 9:
wire-=b;
strcpy(item[f],"Wire");
cost[f]=500;
break;
case 10:
holder-=b;
strcpy(item[f],"Holder");
cost[f]=20;
break;
case 11:
switchs-=b;
strcpy(item[f],"Switch");
cost[f]=30;
break;
case 12:
socket-=b;
strcpy(item[f],"Socket");
cost[f]=25;
break;
}
b=0;
cleardevice();
}
//***********************FUNCTION TO DISPLAY STOCK**************************//
void display()
{
cleardevice();
setcolor(GREEN);
 setfillstyle(0,0);
  settextstyle(8,0,2);
bar3d(15,70,205,230,10,10);
bar3d(200,250,430,420,10,10);
bar3d(325,70,575,230,10,10);
outtextxy(15,75,"  APPLIANCES ");
outtextxy(325,75," LIGHTING PRODUCTS ");
outtextxy(200,250," WIRING PRODUCTS ");
settextstyle(3,0,1);
setcolor(WHITE);
outtextxy(15,106," 1. Cooler");
gotoxy(23,8);
cout<<cooler;
outtextxy(15,137," 2. Induction");
gotoxy(23,10);
cout<<induction;
outtextxy(15,169," 3. Geyser");
gotoxy(23,12);
cout<<geyser;
outtextxy(15,200," 4. Fans");
 gotoxy(23,14);
cout<<fan;
outtextxy(325,106," 5. Bulbs");
gotoxy(69,8);
cout<<bulb;
outtextxy(325,137," 6. Mercury");
gotoxy(69,10);
cout<<mercury;
outtextxy(325,169," 7. Surface Lights");
gotoxy(69,12);
cout<<surface;
outtextxy(325,200," 8. Concealed Lights");
gotoxy(69,14);
cout<<concealed;
outtextxy(200,281,"  9. Wires");
gotoxy(51,19);
cout<<wire;
outtextxy(200,312," 10. Bulb Holders ");
gotoxy(51,21);
cout<<holder;
outtextxy(200,344," 11. Switches");
gotoxy(51,23);
cout<<switchs;
outtextxy(200,376," 12. Sockets ");
gotoxy(51,25);
cout<<socket;
}
//***********************FUNCTION TO UPDATE STOCK**************************//
void buy()
{
cleardevice();
INDO i;
ofstream out("indo.txt",ios::app|ios::binary);
cleardevice();print();
ifstream in("indo.txt",ios::in|ios::binary);
ofstream out1("tem.txt",ios::out|ios::binary);
in.read((char*)&i,sizeof(i));
i.purchase();
out1.write((char*)&i,sizeof(i));
in.close();out.close();out1.close();
remove("indo.txt");
rename("tem.txt","indo.txt");
f++;
}
};
//***********************CLASS FOR COMPANY**************************//
class GURU
{
int a,b,cooler,induction,geyser,fan,bulb,concealed;
int surface,mercury,wire,holder,switchs,socket;
public:
//***********************CLASS CONSTRUCTOR**************************//
GURU()
{
cooler=0,induction=0,geyser=0,fan=0,bulb=0,concealed=0;
surface=0,mercury=0,wire=0,holder=0,switchs=0,socket=0;
}
//***********************FUNCTION FOR PRODUCT INPUT**************************//
void input()
{
settextstyle(3,0,1);
outtextxy(20,378,"Enter the product code to change the quantity ");
gotoxy(65,25);
cin>>a; b=0;
cout<<"\n\t\t\t\t\t\t";
outtextxy(20,410,"Enter the quantity");
cin>>b;
switch(a)
{
case 1:
cooler+=b;
b=0;
break;
case 2:
induction+=b;
b=0;
break;
case 3:
geyser+=b;
b=0;
break;
case 4:
fan+=b;
b=0;
break;
case 5:
bulb+=b;
b=0;
break;
case 6:
mercury+=b;
b=0;
break;
case 7:
surface+=b;
b=0;
break;
case 8:
concealed+=b;
b=0;
break;
case 9:
wire+=b;
b=0;
break;
case 10:
holder+=b;
b=0;
break;
case 11:
switchs+=b;
b=0;
break;
case 12:
socket+=b;
b=0;
break;
default:
outtextxy(50,400,"Wrong Choice");
}
cleardevice();
}

//***********************FUNCTION FOR ITEM PURCHASE**************************//
void purchase()
{
outtextxy(20,378,"Enter the product code you want to purchase");
gotoxy(65,25);
a=0;
cin>>a;
b=0;
cout<<"\n\t\t\t\t\t\t";
outtextxy(20,410,"Enter the quantity  ");
cin>>b;
q[f]=b;
 strcpy(comp[f]," Guru");
switch(a)
{
case 1:
cooler-=b;
strcpy(item[f],"Cooler");
cost[f]=2700;
break;
case 2:
induction-=b;
strcpy(item[f],"Induction");
cost[f]=1600;
break;
case 3:
geyser-=b;
strcpy(item[f],"Geyser");
cost[f]=5800;
break;
case 4:
fan-=b;
strcpy(item[f],"Fan");
cost[f]=1070;
break;
case 5:
bulb-=b;
strcpy(item[f],"Bulb");
cost[f]=200;
break;
case 6:
mercury-=b;
strcpy(item[f],"Mercury");
cost[f]=50;
break;
case 7:
surface-=b;
strcpy(item[f],"Surface Light");
cost[f]=450;
break;
case 8:
concealed-=b;
strcpy(item[f],"Concealed Light");
cost[f]=650;
break;
case 9:
wire-=b;
strcpy(item[f],"Wire");
cost[f]=500;
break;
case 10:
holder-=b;
strcpy(item[f],"Holder");
cost[f]=20;
break;
case 11:
switchs-=b;
strcpy(item[f],"Switch");
cost[f]=30;
break;
case 12:
socket-=b;
strcpy(item[f],"Socket");
cost[f]=25;
break;
}
b=0;
cleardevice();
}
//***********************FUNCTION TO DISPLAY STOCK**************************//
void display()
{
cleardevice();
setcolor(GREEN);
 setfillstyle(0,0);
  settextstyle(8,0,2);
bar3d(15,70,205,230,10,10);
bar3d(200,250,430,420,10,10);
bar3d(325,70,575,230,10,10);
outtextxy(15,75,"  APPLIANCES ");
outtextxy(325,75," LIGHTING PRODUCTS ");
outtextxy(200,250," WIRING PRODUCTS ");
settextstyle(3,0,1);
setcolor(WHITE);
outtextxy(15,106," 1. Cooler");
gotoxy(23,8);
cout<<cooler;
outtextxy(15,137," 2. Induction");
gotoxy(23,10);
cout<<induction;
outtextxy(15,169," 3. Geyser");
gotoxy(23,12);
cout<<geyser;
outtextxy(15,200," 4. Fans");
 gotoxy(23,14);
cout<<fan;
outtextxy(325,106," 5. Bulbs");
gotoxy(69,8);
cout<<bulb;
outtextxy(325,137," 6. Mercury");
gotoxy(69,10);
cout<<mercury;
outtextxy(325,169," 7. Surface Lights");
gotoxy(69,12);
cout<<surface;
outtextxy(325,200," 8. Concealed Lights");
gotoxy(69,14);
cout<<concealed;
outtextxy(200,281,"  9. Wires");
gotoxy(51,19);
cout<<wire;
outtextxy(200,312," 10. Bulb Holders ");
gotoxy(51,21);
cout<<holder;
outtextxy(200,344," 11. Switches");
gotoxy(51,23);
cout<<switchs;
outtextxy(200,376," 12. Sockets ");
gotoxy(51,25);
cout<<socket;
}
//***********************FUNCTION TO UPDATE STOCK**************************//
void buy()
{
cleardevice();
GURU g;
ofstream out("guru.txt",ios::app|ios::binary);
cleardevice();
print();
ifstream in("guru.txt",ios::in|ios::binary);
ofstream out1("tem.txt",ios::out|ios::binary);
in.read((char*)&g,sizeof(g));
g.purchase();
out1.write((char*)&g,sizeof(g));
in.close();
out.close();
out1.close();
remove("guru.txt");
rename("tem.txt","guru.txt");
f++;
}
};
//***********************FUNCTION TO VIEW STOCK**************************//
void stock()
{
char a;
g:
cleardevice();
settextstyle(7,0,4);
outtextxy(50,50,"  ******** ROSHNI KENDRA ********");
outtextxy(50,90,"  ****** LIST OF COMPANYS ******");
settextstyle(3,0,1);
outtextxy(100,200," 1. Bajaj  ");
outtextxy(100,232," 2. Usha");
outtextxy(100,264," 3. Orient");
outtextxy(100,296," 4. Indo ");
outtextxy(100,328," 5. Guru  ");
outtextxy(50,430,"Enter the company code whose stock you want to view ");
a=getch();
consumer c;
cleardevice();
if(a=='1')
{
BAJAJ b;
ifstream in("bajaj.txt",ios::in|ios::binary);
in.read((char*)&b,sizeof(b));
b.display();
getch();
in.close();
}
if(a=='2')
{
USHA u;
ifstream in("usha.txt",ios::in|ios::binary);
in.read((char*)&u,sizeof(u));
u.display();
getch();
in.close();
}
if(a=='3')
{
ORIENT o;
ifstream in("orient.txt",ios::in|ios::binary);
in.read((char*)&o,sizeof(o));
o.display();
getch();
in.close();
}
if(a=='4')
{
INDO i;
ifstream in("indo.txt",ios::in|ios::binary);
in.read((char*)&i,sizeof(i));
i.display();
getch();
 in.close();
}
if(a=='5')
{
GURU g;
ifstream in("guru.txt",ios::in|ios::binary);
in.read((char*)&g,sizeof(g));
g.display();
getch();
in.close();
}
char b;
cleardevice();
 settextstyle(3,0,1);
outtextxy(50,100,"TO VIEW THE RECORD OF ANY OTHER COMPANY PRESS 1");
outtextxy(100,140,"OR");
outtextxy(50,180,"TO RETURN TO MAIN MENU PRESS 2");
b=getch();
if(b=='1')
goto g;
else
c.mainmenu();
}
//***********************FUNCTION TO GIVE OPTION **************************//
void last()
{
cleardevice();
 settextstyle(3,0,1);
setcolor(LIGHTBLUE);
outtextxy(50,100,"To return to Main Menu press 1");
outtextxy(50,140,"To exit press 2");
 consumer c;
char a;
  a=getch();
  if(a=='1')
  c.mainmenu();
  else
  exit(0);
}
//***********************FUNCTION FOR PASSWORD**************************//
void password()
{
cleardevice();
int k=0;
password:
cleardevice();
setcolor(RED);
settextstyle(0,0,0);
rectangle(200,150,360,260);
line(210,150,210,100);
line(230,150,230,100);
line(350,150,350,100);
line(330,150,330,100);
ellipse(280,100,0,180,50,30);
ellipse(280,100,0,180,70,50);
line(270,230,290,230);
line(270,230,275,215);
line(290,230,285,215);
ellipse(280,206,300,240,10,10);
setcolor(15);
rectangle(210,300,350,320);
settextstyle(0,0,1);
outtextxy(225,308,"ENTER PASSWORD");
char pass[50]="";
for(int i=0;i<8;i++)
{
pass[i]=getch();
if(i==0)
{setcolor(0);
outtextxy(225,308,"ENTER PASSWORD");
}
setcolor(15);
outtextxy(240+i*8,308,"*");
}
if(strcmpi(pass,"password")==0)
{
cleardevice();
setcolor(GREEN);
rectangle(200,150,360,260);
line(210,150,210,100);
line(230,150,230,100);
line(350,130,350,100);
line(330,130,330,100);
line(330,130,350,130);
ellipse(280,100,0,180,50,30);
ellipse(280,100,0,180,70,50);
line(270,230,290,230);
line(270,230,275,215);
line(290,230,285,215);
ellipse(280,206,300,240,10,10);
settextstyle(3,0,1);
setcolor(15);
outtextxy(190,330,"CORRECT PASSWORD!!!");
outtextxy(190,380,"Press Enter To Proceed . . .");
settextstyle(0,0,0);
getch();
welcome();
}
else
{
setcolor(RED);
settextstyle(3,0,1);
outtextxy(215,350,"WRONG PASSWORD ! ! !");
outtextxy(215,400,"Press Enter To Proceed . . .");
getch();
if(k==1)
{
setcolor(0);
settextstyle(3,0,1);
outtextxy(215,350,"WRONG PASSWORD ! ! !");
outtextxy(215,400,"Press Enter To Proceed . . .");
setcolor(RED);
settextstyle(3,0,1);
outtextxy(215,350,"WARNING ! ! ! LAST CHANCE");
getch();
k++;
goto password;
}
k++;
if(k<3)
{
goto password;
}
else
{
setcolor(0);
 settextstyle(3,0,1);
outtextxy(215,350,"WRONG PASSWORD ! ! !");
outtextxy(215,400,"Press Enter To Proceed . . .");
setcolor(RED);
outtextxy(205,350,"Maximum no of attempts achievied");
outtextxy(205,400,"Exiting . . .");
delay(1000);
exit(0);
}
}
getch();
}
//***********************FUNCTION FOR WELCOME SCREEN**************************//
void welcome()
{
cleardevice();
float x=1,y=0.0,j=.5,count=.1;
settextstyle(1,0,9);
for(int k=0;k<=4;k++)
{
for(float i=90;i<270;i+=10)
{
y=cos(((i*22/7)/180))/j;
if(y>0)
y=-y;
setcolor(14);
outtextxy(0,y*100+200,"W");
outtextxy(90,350-(y*100+200),"E");
outtextxy(180,y*100+200,"L");
outtextxy(270,350-(y*100+200),"C");
outtextxy(360,y*100+200,"O");
outtextxy(450,350-(y*100+200),"M");
outtextxy(540,y*100+200,"E");
delay(40);
setcolor(0);
outtextxy(0,y*100+200,"W");
outtextxy(90,350-(y*100+200),"E");
outtextxy(180,y*100+200,"L");
outtextxy(270,350-(y*100+200),"C");
outtextxy(360,y*100+200,"O");
outtextxy(450,350-(y*100+200),"M");
outtextxy(540,y*100+200,"E");
 }
j+=count;
count+=.1;
}
setcolor(14);
outtextxy(0,y*100+200,"W");
outtextxy(90,y*100+200,"E");
outtextxy(180,y*100+200,"L");
outtextxy(270,y*100+200,"C");
outtextxy(360,y*100+200,"O");
outtextxy(450,y*100+200,"M");
outtextxy(540,y*100+200,"E");
delay(1000);
cleardevice();
setcolor(15);
setbkcolor(1);
settextstyle(7,0,2);
outtextxy(130,100,"BUSINESS MANAGEMENT PROJECT");
outtextxy(270,130,"BY");
outtextxy(130,160,"DEV RASTOGI & & RISHABH KEDIA");
int i;
for(i=0;i<430;i++)
{line(110+i,80,111+i,80);
line(110+i,211,111+i,211);
line(106+i,76,115+i,76);
line(106+i,215,115+i,215);
 delay(5);
 }
for(i=0;i<130;i++)
{
line(106,76+i,106,85+i);
line(545,76+i,545,85+i);
line(110,80+i,110,81+i);
line(541,80+i,541,81+i);
 delay(5);
 }
outtextxy(130,300,"        UNDER GUIDANCE OF:"    );
outtextxy(130,390,"    THE PILLARS PUBLIC SCHOOL");
for(i=0;i<430;i++)
{
line(110+i,280,111+i,280);
line(110+i,431,111+i,431);
line(106+i,276,115+i,276);
line(106+i,435,115+i,435);
delay(5);
 }
for(i=0;i<150;i++)
{
line(106,276+i,106,285+i);
line(545,276+i,545,285+i);
line(110,280+i,110,281+i);
line(541,280+i,541,281+i);
 delay(5);
 }
outtextxy(130,330,"       MR. AMIT SRIVASTAVA"    );
for(i=0;i<270;i++)
{
line(190+i,355,191+i,355);
line(190+i,357,191+i,357);
delay(15);
}
outtextxy(130,360,"(RESPECTED COMPUTER TEACHER)");
delay(300);
for(i=0;i<=700;i++)
{
rectangle(319-i,199-i,319+i,199+i);
delay(5);
}
delay(10);
cleardevice();
setbkcolor(0);
setcolor(3);
for(j=0;j<5;j++)
{
for( i=0;i<200;i+=1)
 {
cleardevice();
circle(319,199,i);
outtextxy(250,400,"LOADING . . .");
delay(1);
}
}
setcolor(0);
consumer c;
c.mainmenu();
}

//*********************** VOID MAIN **************************//
void main()
{
int gdriver = DETECT;
int gmode;
initgraph(&gdriver, &gmode, "C:\\TC\\BGI");
password();
closegraph();
}

