#ifndef RunAction_h
#define RunAction_h 1

//#ifndef与#endif防止头文件的重复包含和编译

#include "G4UserRunAction.hh" //一般用户自定义的RunAction类继承于此

//RunAction类的定义
class RunAction : public G4UserRunAction {
public:
    RunAction();//声明构造函数，将在对应源文件中定义
    virtual ~RunAction();//声明析构函数，将在对应源文件中定义
    virtual void BeginOfRunAction(const G4Run*);//声明每个Run开始时将被调用的函数：BeginOfRunAction(const G4Run*)
    virtual void   EndOfRunAction(const G4Run*);//声明每个Run结束时将被调用的函数：EndOfRunAction(const G4Run*)
};

#endif //#ifndef与#endif防止头文件的重复包含和编译
