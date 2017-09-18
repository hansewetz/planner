#pragma once
#include <memory>
#include <string>
#include <vector>
#include <iosfwd>
namespace ccgen{

// forward decl
class Class;
class Headerfile;

// class representing a 'type' for code generation
class TranslationUnit{
public:
  // debug print operator
  friend std::ostream&operator<<(std::ostream&os,TranslationUnit const&tu);

  // ctors,assign,dtor
  TranslationUnit(std::string const&name);
  TranslationUnit(std::string const&name,std::string const&nspace);
  TranslationUnit(std::string const&name,std::vector<std::string>const&namespaces,
                  std::vector<std::shared_ptr<Class>>classes,
                  std::vector<std::shared_ptr<Headerfile>>const&headerfiles);
  TranslationUnit(TranslationUnit const&)=default;
  TranslationUnit(TranslationUnit&&)=default;
  TranslationUnit&operator=(TranslationUnit const&)=default;
  TranslationUnit&operator=(TranslationUnit&&)=default;
  ~TranslationUnit()=default;

  // getters
  std::string const&name()const noexcept;
  std::vector<std::string>const&namespaces()const noexcept;
  std::vector<std::shared_ptr<Class>>const&classes()const noexcept;
  std::string const&namespacestring()const;
  std::vector<std::shared_ptr<Headerfile>>const&headerfiles()const noexcept;
  bool hasnamespace()const;

  // modifyers
  void add(std::shared_ptr<Class>cl);
  void add(std::shared_ptr<Headerfile>h);
private:
  // helper functions
  static std::string createns(std::vector<std::string>const&namespaces);

  // private attributes
  std::string const name_;
  std::vector<std::string>const namespaces_;
  std::string const namespacestring_;
  std::vector<std::shared_ptr<Class>>classes_;
  std::vector<std::shared_ptr<Headerfile>>headerfiles_;
};
}
