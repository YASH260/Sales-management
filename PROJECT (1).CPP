/*
------------------------------------------------------------
			PROJECT SALES MANAGEMENT
------------------------------------------------------------
   THIS PROJECT IS MADE BY -> a) ANKUR JAIN.
			      b) PAWAN ATTRI.
------------------------------------------------------------

  HEADER FILES.
------------------------------------------------------------
*/

 # include <fstream.h>
 # include <string.h>
 # include <stdlib.h>
 # include <stdio.h>
 # include <ctype.h>
 # include <conio.h>
 # include <iomanip.h>
 # include <dos.h>

 // CLASS LINE->DRAWING FUNCTIONS.
class LINE
{
	public:
	void HOR_LINE(int, int, int, char);
	void VER_LINE(int, int, int, char);
	void BOX(int,int,int,int,char);
	void CLEAR1();
	void CLEAR2();
};

//CLASS MENU-> MENU FUNCTIONS.
class MENU
{
	public:
       void M_MENU();
	private:
       void REP_MENU();
};

//CLASS ITEM ->DATA ABOUT ITEMS.
class ITEM
{
	public:
			void GETDATA();
			int RECORDNO(int);
			void MOD_RECORD();
			void SEARCH_RECORD();
			void DISP_IT_AVAIL();
			void DISP_IT_ORDER();
			void DISPLAY_RECORD(int);
			int FOUND_CODE(int);
			float ITEM_PRICE( int);
			char * ITEM_NAME( int);
			void MODI_STOCK(int, int);
			private:
			int LASTCODE();
			void MODI_RECORD(int);
			void ADD_RECORD();
			int I_CODE;
			char I_NAME[30];
			float I_RATE;
			int I_QTY;
	       };

// CLASS SALE -> DATA OF SALES MADE
class SALE {
		int CASHMEMO;
		int nitem;
		struct { int dd, mm, yy; } CASH_DATE;
		int ITEM_CODE[5];
		int ITEM_QTY[5];
		float TOT_AMT;
		   void GETSALE();
		   void ADD_RECORD_SALE();
		   int LASTMEMO();
		   void CAL_AMT();
		public:
		    int VALID_DATE(int,int,int);
		    void PREP_CASH();
		    void CASH_PRINT();
		    void DAILY_SALE();
		    void MONTH_SALE();
		    void YEAR_SALE();
		    void ITEM_SALE();
	    };

// THIS FUNCTION CONTROLS ALL THE FUNCTIONS IN THE MAIN MENU(M_MENU).
void MENU :: M_MENU()
{
	char ch ;
	LINE L;
	L.CLEAR1();
	while(1)
	{
		L.BOX(23,7,58,9,218);
		L.BOX(10,5,71,21,218);
		L.BOX(11,6,70,20,219);
		gotoxy(25,8);
		cout<<" A  S  K    P  V  T.    L  T  D.";
		gotoxy(27,11);
		cout<<"1:   ADD RECORD TO ITEM FILE";
		gotoxy(27,12);
		cout<<"2:   STOCK MODIFICATION ";
		gotoxy(27,13);
		cout<<"3:   CASHMEMO PREPRATION ";
		gotoxy(27,14);
		cout<<"4:   SEARCHING AN ITEM ";
		gotoxy(27,15);
		cout<<"5:   REPORT";
		gotoxy(27,17);
		cout<<"0:   EXIT";
		gotoxy(27,19);
		cout<<"ENTER YOUR CHOICE :";
		ch = getch();
		switch(ch)
		{
		  case 27 :
		  case '0': return;
		  case '1': ITEM I;
			    I.GETDATA();
			    break;
		  case '2': I.MOD_RECORD();
			    break;
		  case '3': SALE S;
			    S.PREP_CASH();
			    break;
		  case '4': I.SEARCH_RECORD();
			    break;
		  case '5': REP_MENU();
		}
		L.CLEAR1();
	  }
}

//FUNCTION TO CONTROL THE FUNCTIONS IN THE REPORT MENU(REP_MENU).
void MENU :: REP_MENU()
{
	char ch;
	LINE L;
	L.CLEAR2();
	while(1)
	{
		clrscr();
		L.BOX(30,6,51,8,218);
		L.BOX(10,3,73,20,218);
		L.BOX(9,2,74,22,219);
		gotoxy(31,7);
		cout <<"R E P O R T  M E N U";
		gotoxy(30,10);
		cout <<"1: CASH MEMO PRINTING";
		gotoxy(30,11);
		cout <<"2: DAILY SALE REPORT";
		gotoxy(30,12);
		cout <<"3: MONTHLY SALE REPORT";
		gotoxy(30,13);
		cout <<"4: YEARLY SALE REPORT";
		gotoxy(30,14);
		cout <<"5: ITEM-WISE SALE REPORT";
		gotoxy(30,15);
		cout <<"6: LIST OF ITEMS AVAILABLE";
		gotoxy(30,16);
		cout <<"7: ORDER LIST OF ITEMS WHOSE STOCK < 20";
		gotoxy(30,18);
		cout<<"0: EXIT";
		gotoxy(30,21);
		cout<<"ENTER YOUR CHOICE :";
		ch = getch();
		switch(ch)
		{
		   case 27 :
		   case '0': return;
		   case '1': SALE S;
			     S.CASH_PRINT();
			     break;
		   case '2': S.DAILY_SALE();
			     break;
		   case '3': S.MONTH_SALE();
			     break;
		   case '4': S.YEAR_SALE();
			     break;
		   case '5': S.ITEM_SALE();
			     break;
		   case '6': ITEM I;
			     I.DISP_IT_AVAIL();
			     break;
		   case '7': I.DISP_IT_ORDER();
		}
		L.CLEAR2();
	   }
}
//  FUNCTION TO DRAW HORRIZONTAL LINE.
void LINE :: HOR_LINE(int column1,int column2,int row,char c)
{
	for(column1; column1<=column2; column1++)
	{
		gotoxy(column1,row);
		cout<<c;
	}
}

//  FUNCTION TO DRAW VERTICAL LINE.
void LINE :: VER_LINE(int row1, int row2, int column, char c)
{
	for(row1; row1<=row2; row1++)
	{
		gotoxy(column,row1);
		cout<<c;
	}
}

// FUNCTION TO DRAW THE BOX.
void LINE :: BOX(int column1, int row1, int column2, int row2, char c)
{
	char ch = 218;
	char c1,c2,c3,c4;
	char l1=196 , l2=179;
	if(c==ch)
	{
		c1 = 218;  //Ú
		c2 = 191; //¿
		c3 = 192; //  À
		c4 = 217;  // Ù
		l1 = 196;  //Ä
		l2 = 179;  // ³
	}
	else
	{
		c1 = c;        // C1 IS CORNER 1
		c2 = c;        // CORNER 2
		c3 = c;
		c4 = c;
		l1 = c;       // L1 IS HORI_LINE CHARACTER
		l2 = c;
	}
	gotoxy(column1,row1);
	cout<<c1;
	gotoxy(column2,row1);
	cout<<c2;
	gotoxy(column1,row2);
	cout<<c3;
	gotoxy(column2,row2);
	cout<<c4;
	column1++;
	column2--;
	HOR_LINE(column1,column2,row1,l1);
	HOR_LINE(column1,column2,row2,l1);
	column1--;
	column2++;
	row1++;
	row2--;
	VER_LINE(row1,row2,column1,l2);
	VER_LINE(row1,row2,column2,l2);
}

// FUNCTIONS TO CLEAR THE SCREEN (CLEAR1->UPWARD);(CLEAR2->DOWNWORD).
void LINE :: CLEAR1()
{
	for(int i=25; i>=1; i--)
	{
		delay(20);  // 20 MILISECONDS
		gotoxy(1,i);
		clreol();
	}
}
void LINE :: CLEAR2()
{
	for(int i=1; i<=25; i++)
	{
		delay(20);
		gotoxy(1,i);
		clreol();
	}
}

float ITEM :: ITEM_PRICE( int icode)
{
	fstream file;
	file.open("ITEM.DAT", ios ::in | ios::binary);
	file.seekg(0, ios::beg);
	int found = 0;
	file.read((char*) this, sizeof(ITEM));
	while (( file) && (!found))
	{
	    if (I_CODE == icode)
	       found = 1;
	    else
	    file.read((char*) this, sizeof(ITEM));
	}
	file.close();
	return(I_RATE);
}
char * ITEM :: ITEM_NAME( int icode)
{
	fstream file;
	file.open("ITEM.DAT", ios ::in | ios::binary);
	file.seekg(0, ios::beg);
	int found = 0;
	file.read((char*) this, sizeof(ITEM));
	while (( file) && (!found))
	{
	    if (I_CODE == icode)
	       found = 1;
	    else
	    file.read((char*) this, sizeof(ITEM));
	}
	file.close();
	return(I_NAME);
}


// FUNCTION TO ADD THE GIVEN DATA IN THE ITEM FILE.
void ITEM :: ADD_RECORD()
{
	fstream file;
	file.open("ITEM.DAT", ios::app | ios::binary);
	file.write((char *) this, sizeof(ITEM));
	file.close();
}

void SALE::ADD_RECORD_SALE()
{
	fstream file;
	file.open("SALE.DAT", ios::app | ios::binary);
	file.write((char *) this, sizeof(SALE));
	file.close();
}

// FUNCTION TO ACCEPT THE DATA OF ITEM FILE
void ITEM:: GETDATA()
{
	clrscr();
	gotoxy(65,2);
	cout<<"<0>=EXIT";
	gotoxy(28,3);
	cout<<"ADDITION OF NEW ITEM ";
	gotoxy(5,5);
	cout<<"Item Code # ";
	I_CODE = LASTCODE()+1;
	gotoxy(17, 5);
	cout << I_CODE ;
	gotoxy(5,6);
	cout<<"~~~~~~~~~";
	gotoxy(5,7);
	cout<<"Item name # ";
	gotoxy(5,8);
	cout<<"~~~~~~~~~";
	gotoxy(5,9);
	cout<<"Item Rate # ";
	gotoxy(5,10);
	cout<<"~~~~~~~~~";
	gotoxy(5,11);
	cout<<"Quantity_in_Stock # ";
	gotoxy(5,12);
	cout<<"~~~~~~~~~~~~~~~~~";
	int valid ;
	do
	{
		valid = 1;
		gotoxy(5,25); clreol();
		cout<<"Enter the name of item ";
		gotoxy(20,7); clreol();
		gets(I_NAME);
		if(I_NAME[0]=='0')
			return;
		if(strlen(I_NAME) < 1 || strlen(I_NAME) > 30)
		{
			valid = 0;
			gotoxy(5,25); clreol();
			cout<<"\7Enter correctly (Range: 1..30)";
			getch();
		}
	} while(!valid);
	do
	{
		valid = 1;
		gotoxy(5,25);clreol();
		cout<<"Enter Rate of item ";
		gotoxy(20,9);
		clreol();
		cin >> I_RATE;
		if(I_RATE ==0.0)
			return;
		if (I_RATE <= 0 )
		{
			valid = 0;
			gotoxy(5,25); clreol();
			cout<<"\7Enter correctly";
			getch();
		}
	} while(!valid);
	do
		{
			valid = 1;
			gotoxy(5,25); clreol();
			cout<<"ENTER QUANTITY IN STOCK : ";
			gotoxy(30,11); clreol();
			cin >> I_QTY;
			if(I_QTY ==0)
				return;
			if( I_QTY < 0 )
			{
			    valid = 0;
			gotoxy(5,25); clreol();
			cout<<"\7Enter correctly";
			getch();
			}
	} while(!valid);
	char ch;
	do
	{
		gotoxy(5,24); clreol();
		cout<<"Do you want to save (y/n) ";
		ch = getche();
		ch = toupper(ch);
		if (ch == '0')
			return;
	} while( ch!='Y' && ch!='N');
	if(ch=='N')
		return;
	ADD_RECORD();
}

//FUNCTION TO MODIFY THE GIVEN DATA IN THE ITEM FILE.
void ITEM :: MODI_RECORD(int codeno)
{
	fstream file;
	file.open("ITEM.DAT", ios::out | ios::ate | ios::binary);
	int location;
	location = (codeno-1) * sizeof(ITEM);
	file.seekp(location);
	file.write((char *) this, sizeof(ITEM));
	file.close();
}

//FUNCTION TO RETURN THE LAST CASHMEMO NUMBER.
int SALE :: LASTMEMO()
{
	fstream file;
	file.open("SALE.DAT", ios::in | ios::binary);
	file.seekg(0,ios::beg);
	int count=0;
	while (file.read((char *) this, sizeof(SALE)))
		count = CASHMEMO;
	file.close();
	return count;
}
// FUNCTION TO RETURN THE LAST CODE
int ITEM :: LASTCODE()
{
	fstream file;
	file.open("ITEM.DAT", ios::in | ios::binary);
	file.seekg(0,ios::beg);
	int count=0;
	while (file.read((char *) this, sizeof(ITEM)))
		count = I_CODE;
	file.close();
	return count;
}
// FUNCTION TO PREPARE CASHMEMO
void SALE :: PREP_CASH()
{
	clrscr();
	gotoxy(65,2);
	cout<<"<0>=EXIT";
	gotoxy(28,3);
	cout<<"PREPARATION OF CASH MEMO ";
	gotoxy(5,5);
	cout<<"Cashmemo number # ";
	CASHMEMO = LASTMEMO()+1;
	gotoxy(23, 5);
	cout << CASHMEMO ;
	gotoxy(5,6);
	cout<<"~~~~~~~~~~~~~~~";
	gotoxy(5,7);
	cout<<"Cashmemo date";
	gotoxy(5,8);
	cout<<"~~~~~~~~~~~~~";
	gotoxy(5,9);
	cout<<"Day : ";
	gotoxy(5,10);
	cout<<"month : ";
	gotoxy(5,11);
	cout<<"Year : ";
	char tday[3],tmonth[3],tyear[5];
	int td;
	int valid;
	do
	{
		valid = 1;
		do
		{
			gotoxy(5,25); clreol();
			cout<<"ENTER DAY OF CASHMEMO";
			gotoxy(10,9); clreol();
			gets(tday);
			td = atoi(tday);
			CASH_DATE.dd = td;
			if(tday[0]=='0')
				return;
		} while(td==0);
		do
		{
			gotoxy(5,25); clreol();
			cout<<"ENTER MONTH OF JOINING";
			gotoxy(12,10); clreol();
			gets(tmonth);
			td = atoi(tmonth);
			CASH_DATE.mm = td;
			if(tmonth[0]=='0')
				return;
		} while(td == 0);
		do
		{
			gotoxy(5,25); clreol();
			cout<<"ENTER YEAR OF CASHMEMO";
			gotoxy(11,11); clreol();
			gets(tyear);
			td = atoi(tyear);
			CASH_DATE.yy = td;
			if(tyear[0]=='0')
			return;
		} while(td == 0);
		if(CASH_DATE.dd>31 || CASH_DATE.dd<1)
			valid = 0;
		else
		if(((CASH_DATE.yy%4)!=0 && CASH_DATE.mm==2 && CASH_DATE.dd>28) || ((CASH_DATE.yy%4)==0 && CASH_DATE.mm==2 && CASH_DATE.dd>29))
			valid = 0;
		else
		if((CASH_DATE.mm==4 || CASH_DATE.mm==6 || CASH_DATE.mm==9 || CASH_DATE.mm==11) && CASH_DATE.dd>30)
			valid = 0;
		else
		if(CASH_DATE.yy<1990 || CASH_DATE.yy>2020)
			valid = 0;
		else
		if(CASH_DATE.mm<1 || CASH_DATE.mm>12)
			valid = 0;
		if(!valid)
		{
			valid=0;
			gotoxy(5,25); clreol();
			cout<<"\7Enter correctly";
			getch();
			gotoxy(13,14); clreol();
			gotoxy(13,15); clreol();
		}
	} while(!valid);
	int i = 0;
	char ch;
	do
	{
		int valid = 1;
		do
		{
			gotoxy(5,25); clreol();
			cout<<"Enter the Item Code  : ";
			gotoxy(4,13); clreol();
			cout << " Item Code : ";
			cin >> ITEM_CODE[i];
		if(ITEM_CODE[i] ==0)
			return;
		if (ITEM_CODE[i] < 0 )
		{
			valid = 0;
			gotoxy(5,25);
			clreol();
			cout<<"\7Enter correctly (Range: 1..25)";
			getch();
		}
		} while(!valid);
	do
	{
		valid = 1;
		gotoxy(5,25); clreol();
		cout<<"Enter the QUANTITY SOLD ";
		gotoxy(4,14); clreol();
		cout << " Quantity Sold : ";
		cin >> ITEM_QTY[i];
		if(ITEM_QTY[i]  == 0)
			return;
		if ( ITEM_QTY[i] < 0 )
		  {
			valid = 0;
			gotoxy(5,25); clreol();
			cout<<"\7Enter correctly (Range: 1..30)";
			getch();
		}
	} while(!valid);
	i++;
	cout << " Wiish to enter more information (Y/N) : ";
	cin >> ch;
 } while ( toupper(ch) == 'Y');

       do
	 {
		gotoxy(5,24); clreol();
		cout<<"Do you want to save (y/n) ";
		ch = getche();
		ch = toupper(ch);
		if (ch == '0')
			return;
	} while( ch!='Y' && ch!='N');
	if(ch=='N')
		return;
	nitem = i;
	CAL_AMT();
	ADD_RECORD_SALE();
}

void SALE :: CAL_AMT()
{
	ITEM I;
	float AMT=0.0;
	for(int i = 0; i < nitem; i++)
	{
		float PRICE = I.ITEM_PRICE(ITEM_CODE[i]);
		AMT += PRICE * ITEM_QTY[i];
	}
	TOT_AMT = AMT;
	for ( int j = 0; j < nitem; j++)
	{
	   if (ITEM_QTY[j])
		I.MODI_STOCK(ITEM_CODE[j], ITEM_QTY[j]);
	}
}
void ITEM :: MODI_STOCK( int code, int qty )
{

	int recno = RECORDNO(code);
	gotoxy(72,2);
	clrscr();
	fstream file;
	file.open("ITEM.DAT", ios::in | ios::binary);
	file.seekg(0,ios::beg);
	while(file.read((char *) this, sizeof(ITEM)))
	{
		if(I_CODE==code)
			break;
	}
	file.close();
	I_QTY = I_QTY - qty;
	MODI_RECORD(recno);
}
// FUNCTION TO SEARCH A PARTICULAR ITEM_RECORD
void ITEM::SEARCH_RECORD()
{
	clrscr();
	char ch,t1[10];
	float t2=0.0;
	int code, valid;
	gotoxy(72,2);
	cout<<"<0>=EXIT";
	gotoxy(5,5) ;
	cout<<"Enter code of the Item : ";
	gets(t1);
	t2 = atoi(t1);
	code = t2;
	if(code==0)
		return;
	clrscr();
	if(!FOUND_CODE(code))
	{
		gotoxy(5,5);
		cout<<"\7Record not found";
		getch();
		return;
	}
	DISPLAY_RECORD(code);
	gotoxy(5,25);
	cout<<"Press any key to continue...";
	getch();
}
// FUNCTION TO RETURN '0' IF THE GIVEN CODE IS NOT FOUND.
int ITEM :: FOUND_CODE(int code)
{
	fstream file;
	file.open("ITEM.DAT", ios::in | ios::binary);
	file.seekg(0,ios::beg);
	int found=0;
	while(file.read((char *) this, sizeof(ITEM)))
	{
		if(I_CODE==code)
		{
			found = 1;
			break;
		}
	}
	file.close();
	return found;
}

//FUNCTION TO RETURN RECORD NO. OF THE GIVEN CODE.
int ITEM :: RECORDNO(int code)
{
	fstream file;
	file.open("ITEM.DAT", ios::in | ios::binary);
	file.seekg(0,ios::beg);
	int codeno=0;
	while(file.read((char *) this, sizeof(ITEM)))
	{
		codeno++;
		if(I_CODE==code)
			break;
	}
	file.close();
	return (codeno);
}

//FUNCTION TO DISPLAY THE LIST OF THE ITEMS AVAILABLE.
void ITEM :: DISP_IT_AVAIL()
{
	clrscr();
	int row=6,found=0,flag=0;
	char ch;
	gotoxy(19,2);
	cout<<"LIST OF ITEMS";
	gotoxy(19,3);
	cout<<"~~~~~~~~~~~~~";
	gotoxy(1,4);
	cout<<"CODE           NAME           RATE           QUANTITY ";
	gotoxy(1,5);
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	fstream file;
	file.open("ITEM.DAT", ios::in | ios::binary);
	file.seekg(0,ios::beg);
	while (file.read((char *) this, sizeof(ITEM)))
	{
		flag = 0;
		delay(20);
		found = 1;
		gotoxy(2,row);
		cout<< I_CODE;
		gotoxy(16,row);
		cout<< I_NAME;
		gotoxy(32,row);
		cout<<I_RATE;
		gotoxy(47,row);
		cout << I_QTY;
		if (row > 23)
		{
			flag = 1;
			row = 6;
			gotoxy(1,25);
			cout<<"Press any key to continue or Press <ESC> to exit";
			ch = getch();
			if(ch==27)
				break;
			clrscr();
			gotoxy(19,2);
			cout<<"LIST OF ITEMS";
			gotoxy(19,3);
			cout<<"~~~~~~~~~~~~~";
			gotoxy(1,4);
			cout<<"CODE           NAME           RATE           QUANTITY ";
			gotoxy(1,5);
			cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		}
		else
			row++;
	}
	if(!found)
	{
		gotoxy(5,10);
		cout<<"\7Records not found";
	}
	if(!flag)
	{
		gotoxy(1,25);
		cout<<"Press any key to continue...";
		getche();
	}
	file.close();
}
// FUNCTION TO DISPLAY LIST OF ITEMS WHOSE QUANTITY <20
void ITEM :: DISP_IT_ORDER()
{
	clrscr();
	int row=6,found=0,flag=0;
	char ch;
	gotoxy(7,2);
	cout<<"LIST OF ITEMS WHOSE QUANTITY IN STOCK < 20";
	gotoxy(7,3);
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	gotoxy(1,4);
	cout<<"CODE            NAME            RATE            QTY";
	gotoxy(1,5);
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	fstream file;
	file.open("ITEM.DAT", ios::in | ios::binary);
	file.seekg(0,ios::beg);
	while (file.read((char*)this,sizeof(ITEM)))
	{
	     if (I_QTY < 20)
	     {
		flag = 0;
		delay(20);
		found = 1;
		gotoxy(2,row);
		cout<< I_CODE;
		gotoxy(16,row);
		cout<< I_NAME;
		gotoxy(33,row);
		cout<<I_RATE;
		gotoxy(49,row);
		cout << I_QTY;
		if (row > 23)
		{
			flag = 1;
			row = 6;
			gotoxy(1,25);
			cout<<"Press any key to continue or Press <ESC> to exit";
			ch = getch();
			if(ch==(char)27)
			 break;
			clrscr();
			gotoxy(7,2);
			cout<<"LIST OF ITEMS WHOSE QUANTITY IN STOCK < 20";
			gotoxy(7,3);
			cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
			gotoxy(1,4);
			cout<<"CODE            NAME            RATE            QTY";
			gotoxy(1,5);
			cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		}
		else
			row++;
	}
     }
	if(!found)
	{
		gotoxy(5,10);
		cout<<"\7Records not found";
	}
	if(!flag)
	{
		gotoxy(1,25);
		cout<<"Press any key to continue...";
		getche();
	}
	file.close();
}

//FUNCTION  FOR  CASHMEMO PRINTING.
void SALE :: CASH_PRINT()
{
	clrscr();
	int cno;
	float PRICE = 0.0;
	char cname[40];
	cout << " Enter the cashmemo number : ";
	cin >> cno;
	cout << " Enter the company name : ";
	gets(cname);
	clrscr();
	int row=13 ,found=0;
	char ch;
	gotoxy(24,2);
	cout<<"CASHMEMO";
	gotoxy(24,3);
	cout<<"~~~~~~~~";
	gotoxy(22,4);
	cout <<"ASK PVT. LTD.";
	gotoxy(22,5);
	cout <<"-------------";
	fstream file;
	file.open("SALE.DAT", ios::in | ios::binary);
	file.seekg(0,ios::beg);
	file.read((char *) this, sizeof(SALE));
	while ((file ) && (!found))
	{
	   if ( CASHMEMO == cno )
	      found = 1;
	   else
	   file.read((char *) this, sizeof(SALE));
	}
	file.close();
	if (!found )
	   {
	       gotoxy(10,10);
	       cout << " Record not found ";
	       return;
	   }
	gotoxy(1,7);
	cout<<"NO. :";
	gotoxy(7,7);
	cout << cno;
	gotoxy(31,7);
	cout << " Date : ";
	gotoxy(39, 7);
	cout << CASH_DATE.dd << "/" << CASH_DATE.mm << "/"
	     << CASH_DATE.yy ;
	 gotoxy(1,9);
	 cout << "M/s : ";
	 gotoxy(7, 9);
	 cout << cname;
	 gotoxy(1,10);
	 cout <<"_________________________________________________";
	 gotoxy(1,11);
	 cout <<"     QTY    |      PARTICULARS      |   AMOUNT    ";
	 gotoxy(1,12);
	 cout <<"-------------------------------------------------";
	 for (int i = 0; i < nitem; i++)
	 {
		 gotoxy(6,row);
		 cout <<ITEM_QTY[i];
		 gotoxy(13,row);
		 cout <<"|";
		 ITEM I;
		 char *NAME = I.ITEM_NAME(ITEM_CODE[i]);
		 gotoxy(21,row);
		 cout <<NAME;
		 gotoxy(37,row);
		 cout <<"|";
		 gotoxy(42,row);
		 PRICE = I.ITEM_PRICE(ITEM_CODE[i]);
		 cout <<PRICE;
		 row++;
		 gotoxy(1,row);
		 cout <<"-------------------------------------------------";
		 row++;
	 }
		 gotoxy(32,row);
		 cout <<"(TOTAL)";
		 gotoxy(40,row);
		 cout <<"=";
		 gotoxy(42,row);
		 cout <<TOT_AMT;
		 cout << endl;
		 cout <<"-------------------------------------------------";
	 getch();
}

// FUNCTION TO DISPLAY MONTHLY SALE
void SALE :: MONTH_SALE()
{
	clrscr();
	int M;
	int row=6,found=0,flag=0;
	char ch;
	cout <<"ENTER THE MONTH : ";
	cin >>M;
	clrscr();
	gotoxy(13,2);
	cout<<"MONTHLY  SALE  REPORT";
	gotoxy(13,3);
	cout<<"~~~~~~~~~~~~~~~~~~~~~";
	gotoxy(1,4);
	cout<<"DATE              YEAR              SALE  ";
	gotoxy(1,5);
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	fstream file;
	file.open("SALE.DAT", ios::in | ios::binary);
	file.seekg(0,ios::beg);
	while (file.read((char *) this, sizeof(SALE)))
	{
	if(CASH_DATE.mm==M)
	  {
		flag = 0;
		found = 1;
		gotoxy(2,row);
		cout<< CASH_DATE.dd;
		gotoxy(19,row);
		cout<<CASH_DATE.yy;
		gotoxy(37,row);
		cout<<TOT_AMT;
		if (row > 23)
		{
			flag = 1;
			row = 6;
			gotoxy(1,25);
			cout<<"Press any key to continue or Press <ESC> to exit";
			ch = getch();
			if (ch == (char) 27)
			  break;
			  clrscr();
			gotoxy(13,2);
			cout<<"MONTHLY  SALE  REPORT";
			gotoxy(13,3);
			cout<<"~~~~~~~~~~~~~~~~~~~~~";
			gotoxy(1,4);
			cout<<"DATE              YEAR              SALE  ";
			gotoxy(1,5);
			cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		   }
		 else
			row++;
	   }
	}

	if(!found)
	{
		gotoxy(5,10);
		cout<<"\7Records not found";
	}
	if(!flag)
	{
		gotoxy(1,25);
		cout<<"Press any key to continue...";
		getche();
	}
	file.close();
}
//FUNCTION TO PRINT YEARLY SALE
void SALE :: YEAR_SALE()
{
	clrscr();
	int row=6,found=0,flag=0;
	char ch;
	int Y;
	cout <<"ENTER THE YEAR : ";
	cin >>Y;
	clrscr();
	gotoxy(13,2);
	cout<<"YEARLY  SALE  REPORT";
	gotoxy(13,3);
	cout<<"~~~~~~~~~~~~~~~~~~~~";
	gotoxy(1,4);
	cout<<"DATE              MONTH              SALE  ";
	gotoxy(1,5);
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	fstream file;
	file.open("SALE.DAT", ios::in | ios::binary);
	file.seekg(0,ios::beg);
	while (file.read((char *) this, sizeof(SALE)))
	{
	if (CASH_DATE.yy==Y)
	{
		flag = 0;
		delay(20);
		found = 1;
		gotoxy(2,row);
		cout<< CASH_DATE.dd;
		gotoxy(21,row);
		cout<<CASH_DATE.mm;
		gotoxy(38,row);
		cout<<TOT_AMT;
		if (row > 23)
		{
			flag = 1;
			row = 6;
			gotoxy(1,25);
			cout<<"Press any key to continue or Press <ESC> to exit";
			ch = getch();
			if(ch==(char)27)
				break;
			clrscr();
			gotoxy(13,2);
			cout<<"YEARLY  SALE  REPORT";
			gotoxy(13,3);
			cout<<"~~~~~~~~~~~~~~~~~~~~";
			gotoxy(1,4);
			cout<<"DATE              MONTH              SALE  ";
			gotoxy(1,5);
			cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		}
		else
			row++;
	}
      }
	if(!found)
	{
		gotoxy(5,10);
		cout<<"\7Records not found";
	}
	if(!flag)
	{
		gotoxy(1,25);
		cout<<"Press any key to continue...";
		getche();
	}
	file.close();
}
//FUNCTION TO PRINT DAILY SALE
void SALE :: DAILY_SALE()
{
	clrscr();
	int row=6,found=0,flag=0;
	char ch;
	int D,M,Y;
	cout <<"ENTER THE DATE : ";
	cin >>D;
	cout <<"ENTER THE MONTH : ";
	cin >>M;
	cout <<"ENTER THE YEAR : ";
	cin >>Y;
	clrscr();
	gotoxy(18,2);
	cout<<"DAILY SALE REPORT";
	gotoxy(18,3);
	cout<<"~~~~~~~~~~~~~~~~~~~";
	gotoxy(1,4);
	cout<<"DATE           MONTH           YEAR           SALE  ";
	gotoxy(1,5);
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	fstream file;
	file.open("SALE.DAT", ios::in | ios::binary);
	file.seekg(0,ios::beg);
	file.read((char *) this, sizeof(SALE));
	while ( file )
	{
	if ((CASH_DATE.dd==D)&&(CASH_DATE.mm==M)&&(CASH_DATE.yy==Y))
	{
		flag = 0;
		delay(20);
		found = 1;
		gotoxy(2,row);
		cout<< CASH_DATE.dd;
		gotoxy(18,row);
		cout<<CASH_DATE.mm;
		gotoxy(32,row);
		cout<<CASH_DATE.yy;
		gotoxy(47,row);
		cout<<TOT_AMT;
		if (row > 23)
		{
			flag = 1;
			row = 6;
			gotoxy(1,25);
			cout<<"Press any key to continue or Press <ESC> to exit";
			ch = getch();
			if(ch== (char)27)
			      break;
			clrscr();
			gotoxy(18,2);
			cout<<"DAILY SALE REPORT";
			gotoxy(18,3);
			cout<<"~~~~~~~~~~~~~~~~~~~";
			gotoxy(1,4);
			cout<<"DATE           MONTH           YEAR           SALE  ";
			gotoxy(1,5);
			cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		}
		else
			row++;
	 }
	file.read((char *) this, sizeof(SALE));
	}

	if(!found)
	{
		gotoxy(5,10);
		cout<<"\7Records not found";
	}
	if(!flag)
	{
		gotoxy(1,25);
		cout<<"Press any key to continue...";
		getche();
	}
	file.close();
}
//FUNCTION TO DISPLAY ITEM_WISE SALE REPORT
void SALE :: ITEM_SALE()
{
	clrscr();
	int row=6,found=0,flag=0;
	char ch;
	int icode;
	cout <<"ENTER THE ITEM CODE NO. : ";
	cin >>icode;
	clrscr();
	gotoxy(15,2);
	cout<<"ITEM  WISE  SALE  REPORT";
	gotoxy(15,3);
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~";
	gotoxy(1,4);
	cout<<" DATE              QUANTITY-SOLD              AMOUNT ";
	gotoxy(1,5);
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	fstream file;
	file.open("SALE.DAT", ios::in | ios::binary);
	file.seekg(0,ios::beg);
	while (file.read((char *) this, sizeof(SALE)))
	{
	    for ( int i = 0; i < nitem; i++)
	    {
	    if (ITEM_CODE[i] == icode)
	      {
		flag = 0;
		delay(20);
		found = 1;
		gotoxy(1,row);
		cout<< CASH_DATE.dd << "/" << CASH_DATE.mm << "/"
		     << CASH_DATE.yy;
		gotoxy(22,row);
		cout << ITEM_QTY[i];
		gotoxy(48,row);
		ITEM I;
		float PRICE = I.ITEM_PRICE(ITEM_CODE[i]);
		TOT_AMT = PRICE * ITEM_QTY[i];
		cout<<TOT_AMT;
		if (row > 23)
		{
			flag = 1;
			row = 6;
			gotoxy(1,25);
			cout<<"Press any key to continue or Press <ESC> to exit";
			ch = getch();
			if(ch==(char)27)
			     break;
			gotoxy(15,2);
			cout<<"ITEM  WISE  SALE  REPORT";
			gotoxy(15,3);
			cout<<"~~~~~~~~~~~~~~~~~~~~~~~~";
			gotoxy(1,4);
			cout<<" DATE              QUANTITY-SOLD              AMOUNT ";
			gotoxy(1,5);
			cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		    }
		else
			row++;
	      }
	  }
      }
	if(!found)
	{
		gotoxy(5,10);
		cout<<"\7Records not found";
	}
	if(!flag)
	{
		gotoxy(1,25);
		cout<<"Press any key to continue...";
		getche();
	}
	file.close();
}

//FUNCTION TO DISPLAY THE RECORD OF ITEMS.
void ITEM :: DISPLAY_RECORD(int code)
{
	fstream file;
	file.open("ITEM.DAT", ios::in | ios::binary);
	file.seekg(0,ios::beg);
	while(file.read((char *) this, sizeof(ITEM)))
	{
		if(I_CODE==code)
		{
			gotoxy(5,5);
			cout<<" Code # " <<I_CODE;
			gotoxy(5,6);
			cout<<"~~~~~~~~~~~~~";
			gotoxy(5,7);
			cout<<"Name         : " <<I_NAME;
			gotoxy(5,8);
			cout<<"RATE      : " <<I_RATE;
			gotoxy(5,9);
			cout<<"Quantity    : " <<I_QTY;
		}
	}
	file.close();
}


//FUNCTION TO GIVE DATA FOR THE MODIFICATION OF THE ITEM RECORD
void ITEM :: MOD_RECORD()
{
	clrscr();
	char ch,t1[10];
	float t2=0.0;
	int code, valid;
	gotoxy(72,2);
	cout<<"<0>=EXIT";
	gotoxy(5,5) ;
	cout<<"Enter code of the Item ";
	gets(t1);
	t2 = atoi(t1);
	code = t2;
	if(code==0)
		return;
	clrscr();
	if(!FOUND_CODE(code))
	{
		gotoxy(5,5);
		cout<<"\7Record not found";
		getch();
		return;
	}
	int recno = RECORDNO(code);
	gotoxy(72,2);
	cout<<"<0>=EXIT";
	gotoxy(22,3);
	cout<<"MODIFICATION OF ITEM RECORD";
	DISPLAY_RECORD(code);
	do
	{
		gotoxy(5,24); clreol();
		cout<<"Do you want to modify this record (y/n) ";
		ch = getche();
		ch = toupper(ch);
		if (ch == '0')
			return;
	} while(ch!='Y' && ch!='N');
	if (ch=='N')
		return;
	clrscr();
	fstream file;
	file.open("ITEM.DAT", ios::in | ios::binary);
	file.seekg(0,ios::beg);
	while(file.read((char *) this, sizeof(ITEM)))
	{
		if(I_CODE==code)
			break;
	}
	file.close();
	gotoxy(5,5);
	cout<<"ITEM CODE # " <<code;
	gotoxy(5,6);
	cout<<"~~~~~~~~~~~~~";
	gotoxy(5,7);
	cout<<"NAME  : ";
	gotoxy(5,8);
	cout<<"RATE  : ";
	gotoxy(5,9) ;
	cout<<"QUANTITY_IN_STOCK : ";
	do
	{
		valid = 1;
		gotoxy(5,25); clreol();
		cout<<"Enter the name of Item or <ENTER> FOR NO CHANGE";
		gotoxy(20,7); clreol();
		gets(I_NAME);
		strupr(I_NAME);
		if(I_NAME[0]=='0')
			return;
		if(strlen(I_NAME)>30)
		{
			valid = 0;
			gotoxy(5,25); clreol();
			cout<<"\7Enter correctly (Range: 1..30)";
			getch();
		}
	} while(!valid);
	if(strlen(I_NAME)=='0')
	{
		gotoxy(20,7);
		cout<<I_NAME;
	}
	do
	{
		valid = 1;
		gotoxy(5,25); clreol();
		cout <<"Enter Rate of Item or <ENTER> FOR NO CHANGE";
		gotoxy(20,8); clreol();
		cin >>I_RATE;
		if(I_RATE ==0)
			return;
		if(I_RATE < 0)
		{
			valid = 0;
			gotoxy(5,25); clreol();
			cout<<"\7Enter correctly ";
			getch();
		}
	} while(!valid);
	if(I_RATE == 0)
	{
		gotoxy(20,8);
		cout<<I_RATE;
	}
	do
	{
		valid = 1;
		gotoxy(5,25); clreol();
		cout<<"Enter Quantity of Item or <ENTER> FOR NO CHANGE";
		gotoxy(25,9); clreol();
		cin >>I_QTY;
		if(I_QTY==0)
			return;
		if(I_QTY <0)
		{
			valid = 0;
			gotoxy(5,25); clreol();
			cout<<"\7Enter correctly";
			getch();
		}
	} while(!valid);
	if(I_QTY==0)
	{
		gotoxy(25,9);
		cout<<I_QTY;
	}
	do
	{
		gotoxy(5,18); clreol();
		cout<<"Do you want to save (y/n) ";
		ch = getche();
		ch = toupper(ch);
		if(ch=='0')
			return;
	} while(ch!='Y' && ch!='N');
	if(ch=='N')
		return;
	MODI_RECORD(recno);
	gotoxy(5,23);
	cout<<"\7Record Modified";
	gotoxy(5,25);
	cout<<"Press any key to continue...";
}

// THIS FUNCTION RETURN 0 IF THE GIVEN DATE IS INVALID
int SALE :: VALID_DATE(int d1, int m1, int y1)
{
	int valid=1;
	if(d1>31 || d1<1)
		valid = 0;
	else
	if(((y1%4)!=0 && m1==2 && d1>28) || ((y1%4)==0 && m1==2 && d1>29))
		valid = 0;
	else
	if((m1==4 || m1==6 || m1==9 || m1==11) && d1>30)
		valid = 0;
	return valid;
}

//  MAIN  FUNCTION
void main()
{
	MENU menu;
	menu.M_MENU();

}
