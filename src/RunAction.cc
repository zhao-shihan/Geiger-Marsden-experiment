#include "RunAction.hh"//包含对应的头文件
#include "G4Run.hh"//包含Geant4中输出信息至程序外的G4cout与G4endl所对应的头文件

RunAction::RunAction() : G4UserRunAction() {}

RunAction::~RunAction() {}

void RunAction::BeginOfRunAction(const G4Run*) {}

void RunAction::EndOfRunAction(const G4Run* run) {
    G4int nofEvents = run->GetNumberOfEvent();//获取本次Run中模拟了多少个event
    if (nofEvents == 0) return;//如果模拟了0个，则返回

    G4cout
        << G4endl
        << " The run consists of " << nofEvents << " events"
        << G4endl
        << "------------------------------------------------------------"
        << G4endl;
    //将本次Run中模拟的event的数量输出至显示屏上
}
