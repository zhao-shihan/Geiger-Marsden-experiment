#ifndef B1SteppingAction_h
#define B1SteppingAction_h 1
//#ifndef与#endif防止头文件的重复包含和编译

#include "G4UserSteppingAction.hh" //一般用户自定义的SteppingAction类继承于此

class EventAction;//需要与EventAction进行连接，提前声明该类

//SteppingAction类的定义
class SteppingAction : public G4UserSteppingAction {
public:
    SteppingAction(EventAction* eventAction);//声明构造函数，将在对应源文件中定义
    virtual ~SteppingAction();//声明析构函数，将在对应源文件中定义
    virtual void UserSteppingAction(const G4Step*);//声明成员函数UserSteppingAction(const G4Step*). 在该成员函数中指定每一个Step中的操作
private:
    EventAction* fEventAction;//前文所述的EventAction
};

#endif //#ifndef与#endif防止头文件的重复包含和编译
