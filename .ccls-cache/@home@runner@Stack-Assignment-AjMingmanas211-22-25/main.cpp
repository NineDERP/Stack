#include <iostream>
using namespace std;
#include "stack.h"
#include <cstring>

int main(int argc, char *argv[]) {
  Stack s;
  int i,j, match,x;
  char c;
  match=-1;
  for(j=0;j<argc;j++){
   
    for(i=0;i<strlen(argv[j]);i++){
     switch(argv[j][i]){
      case '[' :
      case '{' :
      case '(' :
      s.push(argv[j][i]); match=1;
      break;
    //if it's open bracket [{ --> push
      case ']' :
         c=s.pop();
      if(c!='[') match=0;//not match
        if(c==0) match=3;
        break;
      case '}' :
         c=s.pop();
      if(c!='{') match=0;
      if(c==0) match=3;
        break;
       case ')' :
          c=s.pop();
      if(c!=')') match=0;
         if(c==0) match=3;
        break;
      default:break;
    //if it's close bracket ]} --> pop & check 
    }  
  } 
    while(s.check()==1){
      x=s.pop();
      if(x!=0) match = 2;
    }
    if(match==0) cout<<"Parentheses not match"<<endl;
    else if(match ==2) cout<<"Parentheses not match: too many open"<<endl;// too many open
    else if(match ==3) cout<<"Parentheses not match: too many close"<<endl; // too many close 
    else if (match==1) cout<<"Parentheses match"<<endl;
  }
  /*for(i=1;i<argc;i++){
    if(argv[i][0]=='x'){
      s.pop();
    }
    else s.push(atoi(argv[i]));
  }*/
  
  
  
 /*
  s.push(5);
  s.push(1);
  s.push(7);
  s.push(6);
  s.pop();//6
  s.pop();//7
  s.push(3);
  s.push(4);
 s.pop();//4
  s.pop();//3
  s.pop();//1
    s.pop();//5
    s.pop();
    s.pop();*/
}