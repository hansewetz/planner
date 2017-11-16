#ifndef __SIG_GUARD_H__
#define __SIG_GUARD_H__
#include "throw.h"
#include <csignal>
#include <stack>
#include <utility>
namespace utils{

// a class acting as a signal handler guard
// (use it when you want to handle a set of signals within a code block)
// (when exiting the code block the original signal handler will be set again in the destructor of this class)
// (the class follow the RAII idiom)
// 
// example:
//        auto fsig=[](int sig){BOOST_LOG_TRIVIAL(warning)<<"cannot interupt ongoing operation";};
//        sigguard<SIGINT,SIGHUP,SIGTERM>sig(fsig);
//
template<int...SIGS>
class sigguard{
public:
  // ctor
  sigguard(sighandler_t fsig):fsig_(fsig){
    setsigs(std::integer_sequence<int,SIGS...>());
  }
  // dtor
  ~sigguard(){
    while(!oldhandlers_.empty()){
      auto p=oldhandlers_.top();
      oldhandlers_.pop();
      signal(p.first,p.second);
    }
  }
  private:
    // setup all new signal handlers
    template<int...sigs>
    void setsigs(std::integer_sequence<int,sigs...>){
      using xxx=int[];
      (void)xxx{(1,setsig(sigs),0)...};
    }
    // set a single signal handler and save the old one so it can be set in the dtor
    void setsig(int sig){
      auto oldhandler=signal(sig,fsig_);
      if(oldhandler==SIG_ERR){
        THROW_RUNTIME("could not set signal handler: "<<strsignal(sig););
      }
      oldhandlers_.push(std::make_pair(sig,oldhandler));
    }
    // old signal handlers - reset in dtor
    std::stack<std::pair<int,sighandler_t>>oldhandlers_;

    // signal handler function
    sighandler_t fsig_;
};
}
#endif
