#ifndef PhysicsList_h
#define PhysicsList_h 1

//#ifndef与#endif防止头文件的重复包含和编译

#include "G4VModularPhysicsList.hh"//一般用户自定义的PhysicsList类继承于此

//一般用户自定义的PhysicsList类继承于G4VModularPhysicsList
class PhysicsList : public G4VModularPhysicsList {
public:
    PhysicsList();//构造函数声明，将在对应源文件中定义
    virtual ~PhysicsList();//析构函数声明，将在对应源文件中定义
    virtual void SetCuts();//成员函数SetCuts()声明,将在对应源文件中定义
};

#endif //#ifndef与#endif防止头文件的重复包含和编译
