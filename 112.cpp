#include<iostream.h>
#include <windows.h> 
#include <conio.h> 

int clrscr() 
{ 

  HANDLE hndl = GetStdHandle(STD_OUTPUT_HANDLE); 
  CONSOLE_SCREEN_BUFFER_INFO csbi; 
  GetConsoleScreenBufferInfo(hndl, &csbi); 
  DWORD written; 
  DWORD N = csbi.dwSize.X * csbi.dwCursorPosition.Y + 
            csbi.dwCursorPosition.X + 1; 
  COORD curhome = {0,0}; 

  FillConsoleOutputCharacter(hndl, ' ', N, curhome, &written); 
  csbi.srWindow.Bottom -= csbi.srWindow.Top; 
  csbi.srWindow.Top = 0; 
  SetConsoleWindowInfo(hndl, TRUE, &csbi.srWindow); 
  SetConsoleCursorPosition(hndl, curhome); 

  return 0; 
} 






int main(){

	char input[20];
	char s,CurrentState;
	unsigned int i,oldi,j;


	do{
		cout<<"\t ---------------------------\n";
	    cout<<"\t|       词法分析程序        |\n";
	    cout<<"\t ---------------------------\n";
		cout<<"\t请输入：\n";
		cout<<"\t ";
		cin>>input;
        i=0,oldi=0,CurrentState='0';
		cout<<"\tclassno\t\tvalue\n";
		do{
		switch(CurrentState){
		case '0':
			switch(input[i]){
			case '0':
			case '1':
			case '2':
            case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':   CurrentState='1';
				        i++;
				        break;
			case '.':   CurrentState='3';
				        i++;
				        break;
               
			case '+':   if(i-oldi>0){
				            cout<<"\t"<<1<<"\t\t";
							for(j=oldi;j<i;j++)
								cout<<input[j];
							cout<<endl;}
							cout<<"\t"<<2<<endl;
							CurrentState='0';
							oldi=++i; break;  
			case '-':   if(i-oldi>0){
				            cout<<"\t"<<1<<"\t\t";
							for(j=oldi;j<i;j++)
								cout<<input[j];
							cout<<endl;}
							cout<<"\t"<<3<<endl;
							CurrentState='0';
							oldi=++i; break;  
			case '*':   if(i-oldi>0){
				            cout<<"\t"<<1<<"\t\t";
							for(j=oldi;j<i;j++)
								cout<<input[j];
							cout<<endl;}
							cout<<"\t"<<4<<endl;
							CurrentState='0';
							oldi=++i; break;  
			case '/':   if(i-oldi>0){
				            cout<<"\t"<<1<<"\t\t";
							for(j=oldi;j<i;j++)
								cout<<input[j];
							cout<<endl;}
							cout<<"\t"<<5<<endl;
							CurrentState='0';
							oldi=++i; break;  
			case '(':   if(i-oldi>0){
				            cout<<"\t"<<1<<"\t\t";
							for(j=oldi;j<i;j++)
								cout<<input[j];
							cout<<endl;}
							cout<<"\t"<<6<<endl;
							CurrentState='0';
							oldi=++i; break;  
            case ')':   if(i-oldi>0){
				            cout<<"\t"<<1<<"\t\t";
							for(j=oldi;j<i;j++)
								cout<<input[j];
							cout<<endl;}
							cout<<"\t"<<7<<endl;
							CurrentState='0';
							oldi=++i; break;  
				        
			default:    if(input[i]=='\0')
						{
							if(i-oldi>0){
				            cout<<"\t"<<1<<"\t\t";
							for(j=oldi;j<i;j++)
								cout<<input[j];
							cout<<endl;}
							cout<<endl<<"\t Finished!"<<endl;
							goto exit;
						}else{
							cout<<"\t ERROR!"<<endl; goto exit;
						}   break;
			}	
			
			break;
		case '1':
			switch(input[i]){
			case '0':
			case '1':
			case '2':
            case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':   CurrentState='1';
				        i++;
				        break;
            case 'E':   CurrentState='4';
				        i++;
				        break;
			case '.':   CurrentState='2';
				        i++;
				        break;
			case '+':   if(i-oldi>0){
				            cout<<"\t"<<1<<"\t\t";
							for(j=oldi;j<i;j++)
								cout<<input[j];
							cout<<endl;}
							cout<<"\t"<<2<<endl;
							CurrentState='0';
							oldi=++i; break;  
			case '-':   if(i-oldi>0){
				            cout<<"\t"<<1<<"\t\t";
							for(j=oldi;j<i;j++)
								cout<<input[j];
							cout<<endl;}
							cout<<"\t"<<3<<endl;
							CurrentState='0';
							oldi=++i; break;  
			case '*':   if(i-oldi>0){
				            cout<<"\t"<<1<<"\t\t";
							for(j=oldi;j<i;j++)
								cout<<input[j];
							cout<<endl;}
							cout<<"\t"<<4<<endl;
							CurrentState='0';
							oldi=++i; break;  
			case '/':   if(i-oldi>0){
				            cout<<"\t"<<1<<"\t\t";
							for(j=oldi;j<i;j++)
								cout<<input[j];
							cout<<endl;}
							cout<<"\t"<<5<<endl;
							CurrentState='0';
							oldi=++i; break;  
			case '(':   if(i-oldi>0){
				            cout<<"\t"<<1<<"\t\t";
							for(j=oldi;j<i;j++)
								cout<<input[j];
							cout<<endl;}
							cout<<"\t"<<6<<endl;
							CurrentState='0';
							oldi=++i; break;  
            case ')':   if(i-oldi>0){
				            cout<<"\t"<<1<<"\t\t";
							for(j=oldi;j<i;j++)
								cout<<input[j];
							cout<<endl;}
							cout<<"\t"<<7<<endl;
							CurrentState='0';
							oldi=++i; break;  
				        
			default:    if(input[i]=='\0')
						{
							if(i-oldi>0){
				            cout<<"\t"<<1<<"\t\t";
							for(j=oldi;j<i;j++)
								cout<<input[j];
							cout<<endl;}
							cout<<endl<<"\t Finished!"<<endl;
							goto exit;
						}else{
							cout<<"\t ERROR!"<<endl; goto exit;
						}   break;
			
			}
			
			break;
		case '2':
			switch(input[i]){
			case '0':
			case '1':
			case '2':
            case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':   CurrentState='1';
				        i++;
				        break;
            case 'E':   CurrentState='4';
				        i++;
				        break;					
		case '+':   if(i-oldi>0){
				            cout<<"\t"<<1<<"\t\t";
							for(j=oldi;j<i;j++)
								cout<<input[j];
							cout<<endl;}
							cout<<"\t"<<2<<endl;
							CurrentState='0';
							oldi=++i; break;  
			case '-':   if(i-oldi>0){
				            cout<<"\t"<<1<<"\t\t";
							for(j=oldi;j<i;j++)
								cout<<input[j];
							cout<<endl;}
							cout<<"\t"<<3<<endl;
							CurrentState='0';
							oldi=++i; break;  
			case '*':   if(i-oldi>0){
				            cout<<"\t"<<1<<"\t\t";
							for(j=oldi;j<i;j++)
								cout<<input[j];
							cout<<endl;}
							cout<<"\t"<<4<<endl;
							CurrentState='0';
							oldi=++i; break;  
			case '/':   if(i-oldi>0){
				            cout<<"\t"<<1<<"\t\t";
							for(j=oldi;j<i;j++)
								cout<<input[j];
							cout<<endl;}
							cout<<"\t"<<5<<endl;
							CurrentState='0';
							oldi=++i; break;  
			case '(':   if(i-oldi>0){
				            cout<<"\t"<<1<<"\t\t";
							for(j=oldi;j<i;j++)
								cout<<input[j];
							cout<<endl;}
							cout<<"\t"<<6<<endl;
							CurrentState='0';
							oldi=++i; break;  
            case ')':   if(i-oldi>0){
				            cout<<"\t"<<1<<"\t\t";
							for(j=oldi;j<i;j++)
								cout<<input[j];
							cout<<endl;}
							cout<<"\t"<<7<<endl;
							CurrentState='0';
							oldi=++i; break;  
				        
			default:    if(input[i]=='\0')
						{
							if(i-oldi>0){
				            cout<<"\t"<<1<<"\t\t";
							for(j=oldi;j<i;j++)
								cout<<input[j];
							cout<<endl;}
							cout<<endl<<"\t Finished!"<<endl;
							goto exit;
						}else{
							cout<<"\t ERROR!"<<endl; goto exit;
						}   break;
			
			}
		
			break;
		case '3':
			switch(input[i]){
			case '0':
			case '1':
			case '2':
            case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':   CurrentState='2';
				        i++;
				        break;
            			
		    case '+':   if(i-oldi>0){
				            cout<<"\t"<<1<<"\t\t";
							for(j=oldi;j<i;j++)
								cout<<input[j];
							cout<<endl;}
							cout<<"\t"<<2<<endl;
							CurrentState='0';
							oldi=++i; break;  
			case '-':   if(i-oldi>0){
				            cout<<"\t"<<1<<"\t\t";
							for(j=oldi;j<i;j++)
								cout<<input[j];
							cout<<endl;}
							cout<<"\t"<<3<<endl;
							CurrentState='0';
							oldi=++i; break;  
			case '*':   if(i-oldi>0){
				            cout<<"\t"<<1<<"\t\t";
							for(j=oldi;j<i;j++)
								cout<<input[j];
							cout<<endl;}
							cout<<"\t"<<4<<endl;
							CurrentState='0';
							oldi=++i; break;  
			case '/':   if(i-oldi>0){
				            cout<<"\t"<<1<<"\t\t";
							for(j=oldi;j<i;j++)
								cout<<input[j];
							cout<<endl;}
							cout<<"\t"<<5<<endl;
							CurrentState='0';
							oldi=++i; break;  
			case '(':   if(i-oldi>0){
				            cout<<"\t"<<1<<"\t\t";
							for(j=oldi;j<i;j++)
								cout<<input[j];
							cout<<endl;}
							cout<<"\t"<<6<<endl;
							CurrentState='0';
							oldi=++i; break;  
            case ')':   if(i-oldi>0){
				            cout<<"\t"<<1<<"\t\t";
							for(j=oldi;j<i;j++)
								cout<<input[j];
							cout<<endl;}
							cout<<"\t"<<7<<endl;
							CurrentState='0';
							oldi=++i; break;  
				        
			default:    if(input[i]=='\0')
						{
							cout<<"\t ERROR!"<<endl; goto exit;
						}   break;
			}		
			break;
		case '4':
			switch(input[i]){
			case '0':
			case '1':
			case '2':
            case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':   CurrentState='6';
				        i++;
				        break;
			case '+':   CurrentState='5'; i++;break;  
			case '-':   CurrentState='5'; i++;break;
            			
			case '*':   if(i-oldi>0){
				            cout<<"\t"<<1<<"\t\t";
							for(j=oldi;j<i;j++)
								cout<<input[j];
							cout<<endl;}
							cout<<"\t"<<4<<endl;
							CurrentState='0';
							oldi=++i; break;  
			case '/':   if(i-oldi>0){
				            cout<<"\t"<<1<<"\t\t";
							for(j=oldi;j<i;j++)
								cout<<input[j];
							cout<<endl;}
							cout<<"\t"<<5<<endl;
							CurrentState='0';
							oldi=++i; break;  
			case '(':   if(i-oldi>0){
				            cout<<"\t"<<1<<"\t\t";
							for(j=oldi;j<i;j++)
								cout<<input[j];
							cout<<endl;}
							cout<<"\t"<<6<<endl;
							CurrentState='0';
							oldi=++i; break;  
            case ')':   if(i-oldi>0){
				            cout<<"\t"<<1<<"\t\t";
							for(j=oldi;j<i;j++)
								cout<<input[j];
							cout<<endl;}
							cout<<"\t"<<7<<endl;
							CurrentState='0';
							oldi=++i; break;  
				        
			default:    if(input[i]=='\0')
						{
							cout<<"\t ERROR!"<<endl; goto exit;
						}   break;
			}	
			
			break;
		case '5':
			switch(input[i]){
			case '0':
			case '1':
			case '2':
            case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':   CurrentState='6';
				        i++;
				        break;
            			
			case '+':   if(i-oldi>0){
				            cout<<"\t"<<1<<"\t\t";
							for(j=oldi;j<i;j++)
								cout<<input[j];
							cout<<endl;}
							cout<<"\t"<<2<<endl;
							CurrentState='0';
							oldi=++i; break;  
			case '-':   if(i-oldi>0){
				            cout<<"\t"<<1<<"\t\t";
							for(j=oldi;j<i;j++)
								cout<<input[j];
							cout<<endl;}
							cout<<"\t"<<3<<endl;
							CurrentState='0';
							oldi=++i; break;  
			case '*':   if(i-oldi>0){
				            cout<<"\t"<<1<<"\t\t";
							for(j=oldi;j<i;j++)
								cout<<input[j];
							cout<<endl;}
							cout<<"\t"<<4<<endl;
							CurrentState='0';
							oldi=++i; break;  
			case '/':   if(i-oldi>0){
				            cout<<"\t"<<1<<"\t\t";
							for(j=oldi;j<i;j++)
								cout<<input[j];
							cout<<endl;}
							cout<<"\t"<<5<<endl;
							CurrentState='0';
							oldi=++i; break;  
			case '(':   if(i-oldi>0){
				            cout<<"\t"<<1<<"\t\t";
							for(j=oldi;j<i;j++)
								cout<<input[j];
							cout<<endl;}
							cout<<"\t"<<6<<endl;
							CurrentState='0';
							oldi=++i; break;  
            case ')':   if(i-oldi>0){
				            cout<<"\t"<<1<<"\t\t";
							for(j=oldi;j<i;j++)
								cout<<input[j];
							cout<<endl;}
							cout<<"\t"<<7<<endl;
							CurrentState='0';
							oldi=++i; break;  
				        
			default:    if(input[i]=='\0')
						{
							cout<<"\t ERROR!"<<endl; goto exit;
						}   break;
			}	
			
			break;
		case '6':
			switch(input[i]){
			case '0':
			case '1':
			case '2':
            case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':   CurrentState='6';
				        i++;
				        break;
            			
			case '+':   if(i-oldi>0){
				            cout<<"\t"<<1<<"\t\t";
							for(j=oldi;j<i;j++)
								cout<<input[j];
							cout<<endl;}
							cout<<"\t"<<2<<endl;
							CurrentState='0';
							oldi=++i; break;  
			case '-':   if(i-oldi>0){
				            cout<<"\t"<<1<<"\t\t";
							for(j=oldi;j<i;j++)
								cout<<input[j];
							cout<<endl;}
							cout<<"\t"<<3<<endl;
							CurrentState='0';
							oldi=++i; break;  
			case '*':   if(i-oldi>0){
				            cout<<"\t"<<1<<"\t\t";
							for(j=oldi;j<i;j++)
								cout<<input[j];
							cout<<endl;}
							cout<<"\t"<<4<<endl;
							CurrentState='0';
							oldi=++i; break;  
			case '/':   if(i-oldi>0){
				            cout<<"\t"<<1<<"\t\t";
							for(j=oldi;j<i;j++)
								cout<<input[j];
							cout<<endl;}
							cout<<"\t"<<5<<endl;
							CurrentState='0';
							oldi=++i; break;  
			case '(':   if(i-oldi>0){
				            cout<<"\t"<<1<<"\t\t";
							for(j=oldi;j<i;j++)
								cout<<input[j];
							cout<<endl;}
							cout<<"\t"<<6<<endl;
							CurrentState='0';
							oldi=++i; break;  
            case ')':   if(i-oldi>0){
				            cout<<"\t"<<1<<"\t\t";
							for(j=oldi;j<i;j++)
								cout<<input[j];
							cout<<endl;}
							cout<<"\t"<<7<<endl;
							CurrentState='0';
							oldi=++i; break;  
				        
			default:    if(input[i]=='\0')
						{
							if(i-oldi>0){
				            cout<<"\t"<<1<<"\t\t";
							for(j=oldi;j<i;j++)
								cout<<input[j];
							cout<<endl;}
							cout<<endl<<"\t Finished!"<<endl;
							goto exit;
						}else{
							cout<<"\t ERROR!"<<endl; goto exit;
						}   break;
			}		
			break;
			}
			}while(1);

exit:   cout<<"\n\t请输入e推出 任意键继续\n";
		cout<<"\t";
		cin>>s;
		if(s!='e')
			clrscr();

	}while(s!='e');
}

