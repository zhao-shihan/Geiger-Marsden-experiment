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

//定义构造函数
ActionInitialization::ActionInitialization() : G4VUserActionInitialization() {}

//定义析构函数
ActionInitialization::~ActionInitialization() {}

//定义成员函数 BuildForMaster() const，定义master线程
void ActionInitialization::BuildForMaster() const {
    RunAction* runAction = new RunAction;
    //创建RunAction类
    SetUserAction(runAction);
    //指定其为Geant4程序的RunAction
    //由于master线程不运算，只需指定RunAction即可
}

//定义成员函数 Build() const，定义worker线程
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
