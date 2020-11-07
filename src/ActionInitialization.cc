#include "ActionInitialization.hh" 
//包含该源文件对应的头文件
#include "PrimaryGeneratorAction.hh" 
//包含粒子源头文件，将在此指定
#include "RunAction.hh" 
//包含RunAction头文件，将在此指定
#include "EventAction.hh"
//包含EventAction头文件，将在此指定
#include "SteppingAction.hh"
//包含SteppingAction头文件，将在此指定

ActionInitialization::ActionInitialization() : G4VUserActionInitialization() {}

ActionInitialization::~ActionInitialization() {}

void ActionInitialization::BuildForMaster() const {
    RunAction* runAction = new RunAction;
    //创建RunAction类
    SetUserAction(runAction);
    //指定其为Geant4程序的RunAction
    //由于master线程不运算，只需指定RunAction
}

void ActionInitialization::Build() const {
    SetUserAction(new PrimaryGeneratorAction);//指定其为Geant4程序的粒子源

    RunAction* runAction = new RunAction();
    SetUserAction(runAction);
    //指定其为Geant4程序的RunAction

    EventAction* eventAction = new EventAction();
    SetUserAction(eventAction);
    //指定其为Geant4程序的EventAction

    SteppingAction* steppingAction = new SteppingAction(eventAction);
    SetUserAction(steppingAction);
    //指定其为Geant4程序的SteppingAction
    //由于worker线程需要运算，需要指定所有运算相关的程序内容
}
