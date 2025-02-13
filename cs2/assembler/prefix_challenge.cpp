// Infix to Postfix Program
// Michael Lovell
// cs23001
// 4/6/2016

#include<iostream>
#include"stack.hpp"
#include"string/string.hpp"
#include<fstream>
#include<vector>

// Postfix function
// Requires:  an output stream, input stream, and a stack object
// Ensures:  infix from input is converted to a postfix expresson and sent to output stream

void prefix(std::ostream&, std::istream&, stack<String>&);
String evaluate(String&, String&, String&, std::ostream&);
int j = 1;
int n = 0;

int main(int argc, char *argv[]){

   
  std::ifstream file(argv[1]);
  if(!file.is_open()){
    std::cout << "Unable to open file";
  }

  stack<String> infix;  

  //option 1 output to file
  if(argc == 3){
    std::ofstream out(argv[2]);
    prefix(out, file, infix);
  }

  //option 2 output to console
  else if (argc != 3)
    prefix(std::cout, file, infix);

   
  file.close();
}

// prefix()
// Requires:  an output steam, an input stream, and a stack
// Ensures:  infix read thru input stream is converted to prefix using stack and then sent to the output stream
void prefix(std::ostream& output, std::istream& file, stack<String>& infix){
  std::vector<String> preFixVector;
  String preFixString, temp, op, rhs, original, reset;
  String space(' ');
  j = 49;
  n = 1;
  while (!file.eof()){
    
    String result;
    file >> temp;
    if (temp != ";")
      original = original + temp + space;
    if ((temp != "(") && (temp != ")") && (temp != ";"))
      infix.push(temp);
    if (temp == ")"){
      rhs = infix.getTos();  infix.pop(); op = infix.getTos(); infix.pop(); result = op + space + infix.getTos() + space + rhs; infix.pop();
      infix.push(result);

    }
    if (temp == ";"){
      output << "Infix Expression:  " << original << std::endl << "Prefix Expression:  " << infix.getTos() << std::endl;
      original = reset; preFixString = infix.getTos(); preFixVector = preFixString.split(' '); String opo, lt, rt;
      stack<String> eval, temp;
      for (std::vector<String>::iterator i = preFixVector.begin(); i != preFixVector.end(); ++i){
	eval.push(*i);
       
      }
      int tempCount = 0; rt = eval.getTos();  eval.pop();  lt = eval.getTos();  eval.pop(); opo = eval.getTos();  eval.pop();  bool done = false;
      while (!done){

	if (eval.empty())
	  done = true;
	if (((opo == '+') || (opo == '-') || (opo == '*') || (opo == '/')) && ((lt != '+') && (lt != '-') && (lt != '*') && (lt != '/')) && ((rt != '+') && (rt != '-') && (rt != '*') && (rt != '/'))){
	  eval.push(evaluate(lt, opo, rt, output));
	  rt = eval.getTos();
	  eval.pop();
	  std::cout << eval.getTos();
	  if (eval.getTos() == 0)
	    done = true;
	  else 
	    eval.push(rt);
	  if (!temp.empty()){
	    for (int i = 0; i < tempCount; ++i){
	      eval.push(temp.getTos());
	      temp.pop();
	    }
	    tempCount = 0;
	  }
	  if (!done){
	    rt = eval.getTos();
	    eval.pop();
	    lt = eval.getTos();
	    eval.pop();
	    opo = eval.getTos();
	    eval.pop();
	  }

	}
	else {
	  temp.push(rt);
	  rt = reset;
	  rt = lt;
	  lt = opo;
	  opo = eval.getTos();
	  eval.pop();
	  ++tempCount;

	}
      }

      j = 49;
      n = 1;
    }
  }
}
String evaluate(String& x, String& y, String& u, std::ostream& output){
  String result;

  output << "   " << "LD" << " " << x  << std::endl;
    
  if (y == '+')
    output << "   " <<  "AD" << " " << u << std::endl;
  if (y == '-')
    output << "   " <<  "SB" << " " << u << std::endl;
  if (y == '*')
    output << "   " <<  "ML" << " " << u << std::endl;
  if (y ==  '/')
    output << "   " <<  "DV" << " " << u << std::endl;
  String v, temporary;
  int k = n;
  if(k < 10){
    char jToChar = j;
    v = jToChar;
  } else {
    int o = 0;
    while (k > 9){
      o = k % 10;
      char jToChar = o + 48;
      temporary = temporary + jToChar;
      k = k / 10;
    }
    int m = 0;
    for(int l = temporary.length(); l > 0; --l){
      v[m] = temporary[l];
      ++m;
      std::cout << "loop h";
    }
  }
  result = "TMP" + v;

  output << "   " << "ST" << " " << result << std::endl;
  ++j;
  ++n;
  return result;
}
