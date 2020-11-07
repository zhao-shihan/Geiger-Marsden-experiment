#include "SteppingAction.hh"  
//包含对应的头文件
#include "G4Step.hh"  
//包含Geant4中输出信息至程序外的G4cout与G4endl所对应的头文件

#include "EventAction.hh"  
//包含EventAction的头文件

#include "G4Track.hh" 
//包含Geant4中Track的头文件，将在后续使用

#include "G4StepPoint.hh" 
//包含Geant4中处理每个相互作用点的头文件

extern int evtid; //声明外部变量，此变量为每个Event对应的序号，在main文件中定义

//SteppingAction类的构造函数
SteppingAction::SteppingAction(EventAction* eventAction) : G4UserSteppingAction(), fEventAction(eventAction) {}

//SteppingAction类的析构函数
SteppingAction::~SteppingAction() {}

//成员函数UserSteppingAction(const G4Step* )的定义，形参为当前Step的指针
void SteppingAction::UserSteppingAction(const G4Step* step) {
    auto track = step->GetTrack();//获取当前Step所在的Track的指针
    auto trackId = track->GetTrackID();//获取当前Step所在的Track的id
    auto parentId = track->GetParentID();
    //获取当前Step所在的Track的父track的id，如果其本身为初级track，则为0
    auto stepId = track->GetCurrentStepNumber();//获取当前Step的id
    auto particleId = track->GetParticleDefinition()->GetParticleName();//获取当前Step的粒子的名称	
    auto edep = (step->GetTotalEnergyDeposit());//获取在本Step中沉积的能量
    auto energy = (step->GetPreStepPoint()->GetKineticEnergy());//获取当前Step的粒子的动能

    G4cout << evtid << " " << parentId << " " << trackId << " " << stepId << " " << particleId << " " << edep << " " << energy << " " << G4endl;
    //将上述信息输出至显示屏中

    fEventAction->AddEdep(edep);
    //将本Step中沉积的能量传递至当前Step对应的Event中，在上一篇文章中说明
}
