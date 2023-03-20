#ifndef L&S_H_INCLUDED
#define L&S_H_INCLUDED
#include<iostream>
#include "mystring.h"
#include <iostream>
#include<string.h>
#include <mysql.h>
#include <sstream>
//#include "c.h"

struct Sign_Up{
    char usn[30]{NULL};
    char em[30]{NULL};
    char pwn[30]{NULL};
    char ad[30]{NULL};
    char np[11]{NULL};
    bool chackE=false,chackNP=false,chackPhone;
}SU;
struct Login{


    char us[30]{NULL};
    char pw[30]{NULL};
    char wo[50]{NULL};
}Lo;

/*
void Connect(){


    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES * res;


    int qstate;

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "localhost", "root", "", "rsms", 0, NULL, 0);

    if(conn)
    {
        std::stringstream ss;
        ss << " INSERT INTO employees (Name, Email, Password , Number_phone,Address) values ('" << SU.usn<<"','"
        << SU.em<<" ','" <<SU.pwn<<" ','" <<SU.np <<" ','" <<SU.ad<<"');";
        string query = ss.str ();
        const char * q = query.c_str();
        qstate = mysql_query(conn, q);
    }
    }
*/
void sgin_up(){
    start:
    system("cls");

        if(SU.chackE==true||SU.chackNP==true){
            cout<<"\t\t sign up\nusername:";
            show(SU.usn);
            cout<<endl;
            }
        else{
            cout<<"\t\t sign up\nusername:";
            gets(SU.usn);
        }

        if (SU.chackNP==true){
            cout<<"email:";show(SU.em);cout<<endl;
            cout<<"password:";show(SU.pwn);cout<<endl;
            cout<<"address:";show(SU.ad);cout<<endl;
        }

        else {
            cout<<"email:";gets(SU.em);
            if (countchar(SU.em,'@')==0 || countchar(SU.em,'@')>1){
            cout<<"your email invalid should have one @ only\n";
            system("pause");
            SU.chackE=true;
            goto start;
                }
                else SU.chackE=false;
            if (countchar(SU.em,'.')==0){
            cout<<"your email  invalid should have at least one comma .\n";
            system("pause");
            SU.chackE=true;
            goto start;
        }
                else SU.chackE=false;

                cout<<"password:";gets(SU.pwn);
                cout<<"address:";gets(SU.ad);
                }

	cout<<"phone:";gets(SU.np);
	for(int i=0,c=0;i<11;i++){
        SU.chackPhone=(SU.np[i]<='9'&&SU.np[i]>='0');
        if(SU.np[i]==0)c++;
        if(SU.chackPhone&&c<9) SU.chackPhone=true;
        else SU.chackPhone=false;
        }

	if(!(SU.chackPhone)){
        cout<<"enter is invalid should be 11 number and should be least 10 number at zero";
        SU.chackNP=true;
        system("pause");
        goto start;
	}
        else SU.chackNP=false;
	null(Lo.wo);
	 C_SU();
    }

    void login(){
u:
	cout<<"\t\t Login    (if you don't have account enter 0)\n";  show(Lo.wo);

	cout<<"\nusername:";  gets(Lo.us);


	if(Lo.us[0]=='0'||Lo.us[1]=='0'){
        sgin_up();
    system("pause");
        goto u;
	}

	if(chackS(SU.usn,Lo.us)!=0){
            system("cls");
            strcpy(Lo.wo,"worng username plase enter true username");
            goto u;
        }
	null(Lo.wo);





pa:
    system("cls");
	cout<<"username:";show(Lo.us);cout<<endl;show(Lo.wo);cout<<endl;
	cout<<"password:";gets(Lo.pw);

	if(chackS(Lo.pw,SU.pwn)!=0)
        {
        strcpy(Lo.wo,"worng password");
        goto pa;
        }

	system("cls");
	}


#endif // L&S_H_INCLUDED
