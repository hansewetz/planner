#include "ccgen/TranslationUnit.h"
#include <iostream>
using namespace std;
namespace ccgen{

// debug print operator
ostream&operator<<(ostream&os,TranslationUnit const&tu){
  os<<"name: "<<tu.name()<<", namespace: "<<tu.namespacestring();
  return os;
}
// ctor
TranslationUnit::TranslationUnit(std::string const&name):
    TranslationUnit(name,vector<string>{},vector<shared_ptr<Class>>{},vector<shared_ptr<Headerfile>>{}){
}
// ctor
TranslationUnit::TranslationUnit(std::string const&name,std::string const&nspace):
    TranslationUnit(name,vector<string>{nspace},vector<shared_ptr<Class>>{},vector<shared_ptr<Headerfile>>{}){
}
// ctor
TranslationUnit::TranslationUnit(string const&name,vector<string>const&namespaces,
                                 vector<shared_ptr<Class>>classes,
                                 vector<shared_ptr<Headerfile>>const&headerfiles):
  name_(name),namespaces_(namespaces),namespacestring_(createns(namespaces)),
  classes_(classes),headerfiles_(headerfiles){
}
// getters
string const&TranslationUnit::name()const noexcept{return name_;}
vector<string>const&TranslationUnit::namespaces()const noexcept{return namespaces_;}
vector<shared_ptr<Class>>const&TranslationUnit::classes()const noexcept{return classes_;}
string const&TranslationUnit::namespacestring()const{return namespacestring_;}
vector<shared_ptr<Headerfile>>const&TranslationUnit::headerfiles()const noexcept{return headerfiles_;}
bool TranslationUnit::hasnamespace()const{return namespaces_.size()>0;}

// add a class to tu
void TranslationUnit::add(shared_ptr<Class>cl){
  classes_.push_back(cl);
}
// add a headerfile to tu
void TranslationUnit::add(shared_ptr<Headerfile>h){
  headerfiles_.push_back(h);
}
// create a single namespace string
string TranslationUnit::createns(vector<string>const&namespaces){
  string ret;
  for(auto it=begin(namespaces);it!=end(namespaces);++it){
    ret+=*it;
    if(next(it)!=end(namespaces))ret+="::";
  }
  return ret;
}
}
