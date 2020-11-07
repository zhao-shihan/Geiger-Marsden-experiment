#ifndef EventAction_h
#define EventAction_h 1

//#ifndef与#endif防止头文件的重复包含和编译

#include "G4UserEventAction.hh" //一般用户自定义的EventAction类继承于此

//EventAction类的定义
class EventAction : public G4UserEventAction {
public:
    EventAction();//声明构造函数，将在对应源文件中定义
    virtual ~EventAction();//声明析构函数，将在对应源文件中定义
    virtual void BeginOfEventAction(const G4Event* event);//声明每个Event开始时将被调用的函数：BeginOfEventAction(const G4Event*)
    virtual void EndOfEventAction(const G4Event* event);//声明每个Event结束时将被调用的函数：EndOfEventAction(const G4Event*)
};

#endif
//#ifndef与#endif防止头文件的重复包含和编译
