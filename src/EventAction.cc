#include "EventAction.hh"//包含对应的头文件
#include "G4Event.hh"//包含Geant4中输出信息至程序外的G4cout与G4endl所对应的头文件

int evtid; //声明外部变量，此变量为每个Event对应的序号，在main文件中定义

EventAction::EventAction() : G4UserEventAction() {}

EventAction::~EventAction() {}

void EventAction::BeginOfEventAction(const G4Event*) {}

void EventAction::EndOfEventAction(const G4Event*) {
    G4cout
        << " This is " << evtid << " event "
        << G4endl
        << "------------------------------------------------------------"
        << G4endl;
    evtid++;//每模拟完成一个Event，将记录Event序号的变量evtid加1
}
