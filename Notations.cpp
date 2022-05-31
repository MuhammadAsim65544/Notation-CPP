#include <iostream>
#define MAX 20
#include<cmath>
#include <string.h>
using namespace std;
class myStack
{
	int stack[MAX], top,peak;
	public:
	    myStack(int t=-1):top(t){  }
	    void makeStackNUll()
		{
			top=-1;
		}
		char pop()
		{
			char val;
			if(top<0)
			{
				cout<<"Stack underflow.\n";
			}
			else 
			{
				val=stack[top];	
				top--;
				return val;
			}
		}
		void push(int data)
		{
			if(top>=MAX-1)
			{
				cout<<"OVer flow of stack.\n";
			}
			else
			{
				top++;
				stack[top] = data;
			}
		}
		int peek()
		{
			return stack[top];
		}
		bool isEmpty()
		{
			if(top==-1)
			return true;
			else 
			return false;
		}
};
class Notations
{
	myStack stak;
	string infix,postfix,prefix;
	char token;
	bool balance;
	public:
		Notations(string i="",string p="",bool b=true):infix(i),postfix(p),balance(b){	}
		void isBalanced(string);
		void set_infix();
		void evaluating_prefix(string);
		string infix_2_postfix(string infix)
		{
			int i,j=0;char temp;
			for(int i=0;i<infix.length();i++)
			{
				token=infix[i];
				if( token=='+'|| token=='-' || token=='*'|| token=='/' || token=='^')
				{
					while(prcd(stak.peek(), token) && !stak.isEmpty())
					{
						temp = stak.pop();
                		postfix.append(1, temp);
					}
					stak.push(token);
				}
				else if(token=='(')
				{
					stak.push(token);
				}
				else if(token==')')
				{
					while(stak.peek()!='(')
            		{
               			temp = stak.pop();
                		postfix.append(1, temp);
          			}
           			 stak.pop(); 
				}	
					
				else
				{
					 postfix.append(1, token);
				}
			}
			return postfix;
		}
		bool prcd(char op1, char op2)
		{
    		if((op1=='+') || (op1=='-') || (op1=='*') || (op1=='/')) //If Top of Stack contains Any Operator
    		{
        	if(((op1=='+') || (op1=='-')) && ((op2=='*') || (op2=='/'))) return false;
        		else return true; //if Q[i] < peeked i.e POP!
   			 }
    		else return false; 
		}
		void eval_postfix(string postfix)
		{
			stak.makeStackNUll();
			int i = 0;
    		char tempChar[MAX];
    		double doubleop1, doubleop2, value, tempval;
    		postfix.append(1, ')');
   			 for(int i = 0; postfix[i]!=')'; i++)
    		{
      		    token = postfix[i];
        		if((token=='+')||(token=='-')||(token=='*')||(token=='/')||(token=='^'))
        		{
            		doubleop2 = stak.pop();
            		doubleop1 = stak.pop();
            	
            //Calculating value now
            		if(token == '+') value = doubleop1 + doubleop2;
            		else if(token == '-') value = doubleop1 - doubleop2;
           			else if(token == '*') value = doubleop1 * doubleop2;
            		else if(token == '/') value = doubleop1 / doubleop2;
            		else if(token == '^') value = pow(doubleop1, doubleop2);
            		stak.push(value);
        		}
        		else
        		{
           		 //Converting to double value
            		tempChar[0] = token;
            		tempval = strtold(tempChar, NULL);
            		//Now Pushing into Stack
            		stak.push(tempval);
        	}
   		 }
    	value = stak.pop();
    	cout<<"\nPostfix Evaluated as: "<<value<<endl;
	}
	void infix_2_prefix(string infix)
	{
		string str="",pre_fix="",pof="";char temp; //pof is postfix
		for(int i=infix.length()-1;i>=0;i--)
		{
			temp=infix[i];
			if(temp=='(')
			temp=')';
			else if(temp==')')
			temp='(';
			str.append(1,temp);		
		}
			pof=infix_2_postfix(str);
			for(int i=pof.length()-1;i>=0;i--)
			{
				temp=pof[i];
				pre_fix.append(1,temp);
			}
			cout<<"Prefix expression is: "<<pre_fix<<endl;
	}
	void postfix_2_prefix(string postfix)
	{
		string prefx=""; char temp;
		for(int i=postfix.length()-1;i>=0;i--)
		{
			temp=postfix[i];
			prefx.append(1,temp);
		}
		cout<<"Prefix expression is: "<<prefx<<endl;
	}
};
int main()
{
	Notations p;
	string exp,postfix;
	int ch,check=0;
	do
	{
		cout<<"____________________________\n";
		cout<<"|                           |\n";
	    cout<<"|                           |\n";
		cout<<"|        MAIN MENU          |\n";
		cout<<"|0. isBalanced()            |\n";
		cout<<"|1. Infix To Postfix        |\n";	
		cout<<"|2. Evaluation Of Postfix   |\n";
		cout<<"|3. Infix To Prefix         |\n";
		cout<<"|4. Postfix To Infix        |\n";
		cout<<"|5. Evaluation Of Prefix    |\n";
		cout<<"|6. Exit                    |\n";
		cout<<"|___________________________|\n\n";
		cout<<"ENTER YOUR CHOICE: ";
		cin>>ch;
		switch(ch)
		{
			case 0:    
			    p.set_infix();
				break;
			case 1:
				cout<<"Enter infix expression: ";
		 		cin.ignore(10, '\n');
	       		getline(cin,exp); 		
				postfix=p.infix_2_postfix(exp);
				cout<<"Postfix expression is: "<<postfix<<endl;
				check++;
				break;
			case 2:
				cout<<"Enter Postfix expression: ";
		 		cin.ignore(10, '\n');
		 		getline(cin,exp);
				p.eval_postfix(exp);
				break;
			case 3:
				cout<<"Enter infix expression: ";		
		 		cin.ignore(10, '\n');
	       		getline(cin,exp); 
				p.infix_2_prefix(exp);
				break;
			case 4:
				cout<<"Enter Postfix expression: ";			
		 		cin.ignore(10, '\n');
	       		getline(cin,exp);
				  p.postfix_2_prefix(exp);
				break;
			case 5:
				cout<<"Enter Prefix expression: ";			
		 		cin.ignore(10, '\n');
	       		getline(cin,exp);
	       		p.evaluating_prefix(exp);
	       		break;
			case 6:
				exit(-1);
		}
	}while(1);
return 0;
}
void Notations::set_infix()
{
    do
    {   
        if(!balance) cout<<"\nNotation is NOT Balanced\nEnter Infix Notation Again!\n";
        else cout<<"\nEnter Infix Notation:\n";
        cin.ignore(10, '\n');
        getline(cin, infix);
        balance = true;
        isBalanced(infix);
    }
    while(!balance);
    
}
void Notations :: isBalanced(string infix)
{
    int i; bool balanced;
    stak.makeStackNUll();
    for(i = 0; (i < infix.length() && balanced); i++)
    {
        token = infix[i];
        if((token == '(')||(token == '{')||(token == '[')) stak.push(token);
        else if((token == ')')||(token == '}')||(token == ']'))
        {
            do
            {
                switch(stak.peek())
                {
                    case '(':
                        if(token!=')') balanced = false;
                        break;
                    case '{':
                        if(token!='}') balanced = false;
                        break;
                    case '[':
                        if(token!=']') balanced = false;
                        break;
                }
                if(!balanced) break;
                stak.pop();
                if(i<infix.length()) token  = infix[++i];

                if(stak.isEmpty()) break;
            } while ((token == ')')||(token == '}')||(token == ']'));
            if((token == '(')||(token == '{')||(token == '[')) stak.push(token);
            
        }
        else continue;
    }
    
}

void Notations ::evaluating_prefix(string prefix)
{
    int i = 0;
    char tempChar[MAX];
    double doubleop1, doubleop2, value, tempval;
    for(int i = prefix.length()-1; i>=0; i--)
    {
        token = prefix[i];
        if((token=='+')||(token=='-')||(token=='*')||(token=='/'))
        {
            doubleop2 = stak.pop();
            doubleop1 = stak.pop();
            if(token == '+') value = doubleop1 + doubleop2;
            else if(token == '-') value = doubleop1 - doubleop2;
            else if(token == '*') value = doubleop1 * doubleop2;
            else if(token == '/') value = doubleop1 / doubleop2;
            else if(token == '^') value = pow(doubleop1, doubleop2);

            stak.push(value);
        }
        else
        {
            //Converting to double value
            tempChar[0] = token;
            tempval = strtold(tempChar, NULL);
            //Now Pushing into Stack
            stak.push(tempval);
        }
    }
    value =stak.pop();
    cout<<"\nPrefix Evaluated as: "<<value<<endl; 
}
