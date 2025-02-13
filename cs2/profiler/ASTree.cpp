/*
 *  ASTree.cpp
 *  Abstract Syntax Tree
 *
 *  Created by Jonathan Maletic
 *  Copyright 2016 Kent State University. All rights reserved.
 *
 *  Modified by:
 *
 */

#include "ASTree.hpp"


/////////////////////////////////////////////////////////////////////
// Copy constructor for srcML
//
srcML::srcML(const srcML& actual) {
    tree = new AST(*(actual.tree));
}

/////////////////////////////////////////////////////////////////////
// Constant time swap for srcML
//
void srcML::swap(srcML& b) {
    std::string t_header = header;
    header = b.header;
    b.header = t_header;
    
    AST *temp = tree;
    tree = b.tree;
    b.tree = temp;
}

/////////////////////////////////////////////////////////////////////
// Assignment for srcML
//
srcML& srcML::operator=(srcML rhs) {
    swap(rhs);
    return *this;
}

/////////////////////////////////////////////////////////////////////
// Reads in and constructs a srcML object.
//
std::istream& operator>>(std::istream& in, srcML& src){
    char ch;
    if (!in.eof()) in >> ch;
    src.header = readUntil(in, '>');
    if (!in.eof()) in >> ch;
    if (src.tree) delete src.tree;
    src.tree = new AST(category, readUntil(in, '>'));
    src.tree->read(in);
    return in;
}


/////////////////////////////////////////////////////////////////////
// Prints out a srcML object
//
std::ostream& operator<<(std::ostream& out, const srcML& src){
    src.tree->print(out);
    return out;
}




/////////////////////////////////////////////////////////////////////
//  Adds in the includes and profile variables
//
void srcML::mainHeader(std::vector<std::string>& profileNames) {
    tree->mainHeader(profileNames);
}

/////////////////////////////////////////////////////////////////////
//  Adds in the includes and profile variables
//
void srcML::fileHeader(const std::string& profileName) {
    tree->fileHeader(profileName);
}


/////////////////////////////////////////////////////////////////////
// Adds in the report to the main.
//
void srcML::mainReport(std::vector<std::string>& profileNames) {
        tree->mainReport(profileNames);
}

/////////////////////////////////////////////////////////////////////
//  Inserts a filename.count() into each function body.
//
void srcML::funcCount(const std::string& profilename) {
    tree->funcCount(profilename);
}

/////////////////////////////////////////////////////////////////////
// Inserts a filename.count() for each statement.
//
void srcML::lineCount(const std::string& profilename) {
    tree->lineCount(profilename);
}

    


/////////////////////////////////////////////////////////////////////
// Constructs a category, token, or whitespace node for the tree.
//
AST::AST(nodes t, const std::string& s) {
    nodeType = t;
    switch (nodeType) {
        case category:
            tag = s;
            break;
        case token:
            text = unEscape(s);
            break;
        case whitespace:
            text = s;
            break;
    }
}






/// Destructor for AST
///  Requires:  an AST object
///  Ensures:  all pointers and data are deleted
AST::~AST(){
  //  nodes clear;
  std::string erase;
  //nodeType = clear;
  tag = erase;
  closeTag = erase;
  text = erase;
  while(!child.empty()){
    delete child.front();
    child.pop_front();
  }     
}
/////////////////////////////////////////////////////////////////////
// Copy Constructor for AST
// Requires:  an AST object
// Ensures:  a copy
AST::AST(const AST& actual):AST() {
  AST result;
  result.nodeType = actual.nodeType;
  result.tag = actual.tag;
  result.closeTag = actual.closeTag;
  result.text = actual.text;
  std::list<AST*> temp;
  
  if(temp == actual.child)
    result.child = temp;
  else{
    temp = actual.child;
    while(!temp.empty()){
      result.child.push_front(new AST(*temp.front()));
      temp.pop_front();
    }
  }
  nodeType = result.nodeType;
  tag = result.tag;
  closeTag = result.closeTag;
  text = result.text;
  
  std::list<AST*> reverse;
  if(reverse == result.child)
    child = reverse;
  else{
    reverse = result.child;
    while(!reverse.empty()){
      child.push_front(new AST(*reverse.front()));
      reverse.pop_front();
    }
  }

}

/////////////////////////////////////////////////////////////////////
// Constant time swap for AST
//
void AST::swap(AST& b) {
  nodes tempNode;
  //  if(nodeType != b.nodeType){
  tempNode = b.nodeType;
  b.nodeType = nodeType;
  nodeType = tempNode;
  //}

  std::string tempTag, tempCloseTag, tempText;
  //if(tag != b.tag){
  tempTag = b.tag;
  b.tag = tag;
  tag = tempTag;
  //}

  //if(closeTag != b.closeTag){
  tempCloseTag = b.closeTag;
  b.closeTag = closeTag;
  closeTag = tempCloseTag;
  //}

  //if(text != b.text){
  tempText = b.text;
  b.text = text;
  text = tempText;
  //}

  //if ((!child.empty()) || (!b.child.empty())){
  std::list<AST*> tempChild;
  if(b.child.empty())
    tempChild = b.child;
  else{

  while(!b.child.empty()){
    tempChild.push_front(b.child.front());
    delete b.child.front();
    b.child.pop_front();
  }
  }
  if(child.empty())
    b.child = child;
  else{
   while(!child.empty()){
    b.child.push_front(child.front());
    delete child.front();
    child.pop_front();
   }
  }
  if(tempChild.empty())
    child = tempChild;
  else{
   while(!tempChild.empty()){
     child.push_front(tempChild.front());
     delete tempChild.front();
     tempChild.pop_front();
   }
  }
}
//}
/////////////////////////////////////////////////////////////////////
// Assignment for AST
//
AST& AST::operator=(AST rhs) {
    swap(rhs);
    return *this;
}




/////////////////////////////////////////////////////////////////////
// Returns a pointer to child[i] where (child[i]->tag == tagName)
//
// IMPORTANT for part 3
AST* AST::getChild(std::string tagName) {
    std::list<AST*>::iterator ptr = child.begin();
    while (((*ptr)->tag != tagName) && (ptr != child.end())) {
         ++ptr;
    }
    return *ptr;
}



/////////////////////////////////////////////////////////////////////
// Returns the full name of a <name> node.
//
// IMPORTANT for part 3
//
std::string AST::getName() const {
    std::string result;
    if (child.front()->tag != "name") {
        result = child.front()->text;   //A simple name (e.g., main)
    } else {                            //A complex name (e.g., stack::push).
        result = child.front()->child.front()->text;
        result += "::";
        result += child.back()->child.front()->text;
    }
    return result;
}




/////////////////////////////////////////////////////////////////////
//  Adds in the includes and profile variables in a main file.
//
void AST::mainHeader(std::vector<std::string>& profileNames) {
  // insert using list insert functions traversing the tree  
for(std::vector<std::string>::iterator i = profileNames.begin(); i != profileNames.end(); ++i){
  std::string dash_i = *i;
  std::replace(dash_i.begin(), dash_i.end(),'.', '_');
  std::string foo = "profile " + dash_i + "(\"" + *i + "\");\n";
  AST* temp = new AST(token,"#include \"profile.hpp\"\n");
    AST* temp2 = new AST(token,foo);
    std::list<AST*>::iterator j = child.begin();
    ++j;
    ++j;
    child.insert(j,temp);
    child.insert(j,temp2);
  }
    //NEED TO IMPLEMENT
    //Skip down a couple lines.
    //For each file profile name, add a new node with a profile 
    // declaration.
    //Also, add in the profile declaration for functions and the
    //include for profile.hpp
}


/////////////////////////////////////////////////////////////////////
//  Adds in the includes and profile variables for non-main files
//
void AST::fileHeader(const std::string& profileName) {
  std::string dash_i = profileName;
  std::replace(dash_i.begin(), dash_i.end(),'.', '_');
  
  std::string foo = "extern profile " + dash_i + ";\n";
  AST* temp = new AST(token,"#include \"profile.hpp\"\n");
  AST* temp2 = new AST(token,foo);
  std::list<AST*>::iterator i = child.begin();
  ++i;
  ++i;
  child.insert(i,temp);
  
  child.insert(i,temp2);
    //NEED TO IMPLEMENT
    //Skip down a couple lines.
    //For each file profile name, add a new node with a profile 
    // extern declaration.
    //Also, add in the extern declaration for functions and the
    //include for profile.hpp
    

}


/////////////////////////////////////////////////////////////////////
// Adds in the report to the main.
// Assumes only one return at end of main body.
//
void AST::mainReport(std::vector<std::string>& profileNames) {
  std::string first = "std::cout << ",second = " << std::endl;\n";  
for(std::vector<std::string>::iterator i = profileNames.begin(); i != profileNames.end(); ++i){
    std::string dash_i = *i;
    std::replace(dash_i.begin(), dash_i.end(),'.', '_');
    for(std::list<AST*>::iterator j = child.begin(); j != child.end(); ++j){
      if((*j)->tag == "function"){
	std::string funcName;
	std::list<AST*>::iterator k = (*j)->child.begin();
	++k;
	++k;
        funcName = (*k)->getName();
	if(funcName == "main"){
	  std::string funcInsert = first + dash_i + second;
	  AST* temp = new AST(token,funcInsert);
	  k = (*j)->child.end();
	  --k;
	  std::list<AST*>::iterator l = (*k)->child.end();
	  --l;
	  --l;
	  --l;
	  //std::list<AST*>::iterator m = (*l)->child.begin();
	  child.insert(l,temp);
	}
      }
    }
 }
    //NEED TO IMPLEMENT
    
    //Find the function with name main and then start from the end.
    //Find the main - function with name of "main"
    //Then start from the end() of this function and iterate
    // backwards until you find a return stmt.   You'll want
    // to insert the report statements before this return.
    
    
}


/////////////////////////////////////////////////////////////////////
// Adds in a line to count the number of times each function is executed.
//  Assumes no nested functions.
//
void AST::funcCount(const std::string& profileName) {
  std::string dash_i = profileName;
  std::replace(dash_i.begin(), dash_i.end(),'.', '_');
  std::string funcInsert;
  std::string originalFuncInsert = dash_i + ".count(_LINE_, ";  
for(std::list<AST*>::iterator i = child.begin(); i != child.end(); ++i){
     
    if((*i)->tag == "function"){
      std::string funcName;
      std::list<AST*>::iterator j = (*i)->child.begin();
      ++j;
      ++j;
	funcName = (*j)->getName();
      AST* k = (*i)->getChild("block");
      std::list<AST*>::iterator l = k->child.begin();
      funcInsert = originalFuncInsert + "\"" + funcName + "\");";
      AST* temp = new AST(token,funcInsert);
      ++l;  
      child.insert(l,temp);  
      
    }
  }
 
    //NEED TO IMPLEMENT
    
    // for all children
    //     if child is a function, constructor, destructor
    //        Find the function name
    //        Find block and insert line as first line in block
    //

}

/////////////////////////////////////////////////////////////////////
// Adds in a line to count the number of times each statement is executed.
//   No breaks, returns, throw etc.
//   Assumes all construts (for, while, if) have { }.
//
void AST::lineCount(const std::string& profileName) {
  std::string dash_i = profileName;
  std::replace(dash_i.begin(), dash_i.end(),'.', '_');
  std::string funcInsert;
  std::string originalFuncInsert = dash_i + ".count(_LINE_);";

  for(std::list<AST*>::iterator i = child.begin(); i != child.end(); ++i){
    //    bool found;
    std::string a = (*i)->tag;
    if((*i)->nodeType == category){
      if((a == "expr_stmt") || (a == "if") || (a == "while") || (a == "for") || (a == "switch")){//"block")){
      std::list<AST*>::iterator j = i;
      ++j;
      AST* temp = new AST(token,originalFuncInsert);
      child.insert((j),temp);
      
    } 
    for(std::list<AST*>::iterator k = (*i)->child.begin(); k != (*i)->child.end(); ++k)
	(*k)->lineCount(profileName);
 }  
    
  }
    //NEED TO IMPLEMENT
    
    // Recursively check for expr_stmt and call
    
    
}


/////////////////////////////////////////////////////////////////////
// Read in and construct AST
// REQUIRES: '>' was previous charater read 
//           && this == new AST(category, "TagName")
//
//
std::istream& AST::read(std::istream& in) {
    AST *subtree;
    std::string temp, Lws, Rws;
    char ch;
    if (!in.eof()) in.get(ch);
    while (!in.eof()) {
        if (ch == '<') {                      //Found a tag
            temp = readUntil(in, '>');
            if (temp[0] == '/') {
                closeTag = temp;
                break;                        //Found close tag, stop recursion
            }
            subtree = new AST(category, temp);               //New subtree
            subtree->read(in);                               //Read it in
            in.get(ch);
            child.push_back(subtree);                        //Add it to child
        } else {                                             //Found a token
            temp = std::string(1, ch) + readUntil(in, '<');  //Read it in.
            std::vector<std::string> tokenList = tokenize(temp);
            for (std::vector<std::string>::const_iterator i=tokenList.begin();
                 i != tokenList.end(); ++i) {
                if (isspace((*i)[0])) {
                    subtree = new AST(whitespace, *i);
                } else {
                    subtree = new AST(token, *i);
                }
                child.push_back(subtree);
            }
            ch = '<';
        }
    }
    return in;
}


/////////////////////////////////////////////////////////////////////
// Print an AST 
// REQUIRES: indent >= 0
//
std::ostream& AST::print(std::ostream& out) const {
    for (std::list<AST*>::const_iterator i = child.begin();
         i != child.end(); ++i) {
        switch ((*i)->nodeType) {
            case category:
                (*i)->print(out);
                break;
            case token:
                out << (*i)->text;
                break;
            case whitespace:
                out << (*i)->text;
                break;
        }
    }
    return out;
}

    
    
    

/////////////////////////////////////////////////////////////////////
// Utilities
//

// IMPORTANT for part 3
bool isStopTag(std::string tag) {
    if (tag == "decl_stmt"            ) return true;
    if (tag == "argument_list"        ) return true;
    if (tag == "init"                 ) return true;
    if (tag == "condition"            ) return true;
    if (tag == "cpp:include"          ) return true;
    if (tag == "macro"                ) return true;
    if (tag == "comment type\"block\"") return true;
    if (tag == "comment type\"line\"" ) return true;
    return false;
}

//For reading

/////////////////////////////////////////////////////////////////////
// Reads until a key is encountered.  Does not include ch.
// REQUIRES: in.open()
// ENSURES: RetVal[i] != key for all i.
//
std::string readUntil(std::istream& in, char key) {
    std::string result;
    char ch;
    in.get(ch);
    while (!in.eof() && (ch != key)) {
        result += ch;
        in.get(ch);
    }
    return result;
}

/////////////////////////////////////////////////////////////////////
// Converts escaped XML charaters back to charater form
// REQUIRES: s == "&lt;"
// ENSURES:  RetVal == "<"
//
std::string unEscape(std::string s) {
    std::size_t pos = 0;
    while ((pos = s.find("&gt;"))  != s.npos) { s.replace(pos, 4, ">");}
    while ((pos = s.find("&lt;"))  != s.npos) { s.replace(pos, 4, "<");}
    while ((pos = s.find("&amp;")) != s.npos) { s.replace(pos, 5, "&");}
    return s;
}


/////////////////////////////////////////////////////////////////////
// Given: s == "   a + c  "
// RetVal == {"   ", "a", " ", "+", "c", " "}  
//
std::vector<std::string> tokenize(const std::string& s) {
    std::vector<std::string> result;
    std::string temp = "";
    unsigned i = 0;
    while (i < s.length()) {
        while (isspace(s[i]) && (i < s.length())) {
            temp.push_back(s[i]);
            ++i;
        }
        if (temp != "") {
            result.push_back(temp);
            temp = "";
        }
        while (!isspace(s[i]) && (i < s.length())) {
            temp.push_back(s[i]);
            ++i;
        }
        if (temp != "") {
            result.push_back(temp);
            temp = "";
        }
    }
    return result;
}
    

