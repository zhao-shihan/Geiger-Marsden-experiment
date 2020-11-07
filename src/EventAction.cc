#include "EventAction.hh"//包含对应的头文件
#include "G4Event.hh"//包含Geant4中输出信息至程序外的G4cout与G4endl所对应的头文件

int evtid; //声明外部变量，此变量为每个Event对应的序号，在main文件中定义

//EventAction类的构造函数
EventAction::EventAction() : G4UserEventAction(), fEdep(0.) {}

//EventAction类的析构函数
EventAction::~EventAction() {}

//成员函数AddEdep(double )的定义
void EventAction::AddEdep(double edep) {
    fEdep += edep;
    //从SteppingAction中获取每个Step沉积的能量，并累加至当前Event对应的fEdep
    //在后续介绍SteppingAction时说明
}

//成员函数BeginOfEventAction(const G4Event*)的定义
void EventAction::BeginOfEventAction(const G4Event*) {
    fEdep = 0;
    //在每个Event开始时把负责记录在每个Event中粒子沉积到材料中的能量的变量fEdep设为0
    //避免上一个Event的结果累加到下一个Event中
}

// 成员函数EndOfEventAction(const G4Event*)的定义
void EventAction::EndOfEventAction(const G4Event*) {
    G4cout
        << " This is " << evtid << " event "
        << G4endl
        << " Energy deposited in this event is " << fEdep << " MeV"
        << G4endl
        << "------------------------------------------------------------"
        << G4endl;
    //将每个Event的序号以及在该Event中粒子沉积到材料中的能量显示在屏幕上

    evtid++;//每模拟完成一个Event，将记录Event序号的变量evtid加1
}
