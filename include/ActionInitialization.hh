#ifndef ActionInitialization_h
#define ActionInitialization_h 1
//#ifndef与#endif防止头文件的重复包含和编译

#include "G4VUserActionInitialization.hh"
//一般用户自定义的DetectorConstruction类继承于此

//一般用户自定义的ActionInitialization继承于G4VUserActionInitialization
class ActionInitialization : public G4VUserActionInitialization {
public:
    ActionInitialization();//构造函数声明，将在对应源文件中定义
    virtual ~ActionInitialization();//析构函数声明，将在对应源文件中定义
    virtual void BuildForMaster() const;//成员函数声明，将在对应源文件中定义. master线程，不运算只控制
    virtual void Build() const;//成员函数声明，将在对应源文件中定义. worker线程，不控制只运算
};

#endif//#ifndef与#endif防止头文件的重复包含和编译
