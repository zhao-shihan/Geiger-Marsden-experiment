#ifndef PrimaryGeneratorAction_h
#define PrimaryGeneratorAction_h 1

//#ifndef与#endif防止头文件的重复包含和编译

#include "G4VUserPrimaryGeneratorAction.hh" //一般用户自定义的PrimaryGeneratorAction类继承于此
#include "G4ParticleGun.hh"//使用G4ParticleGun作为粒子源
#include "globals.hh" //包含Geant4中的全局变量等，除Actioninitializtion外均应包含

class G4ParticleGun;//使用G4ParticleGun作为粒子源
class G4Event;//成员函数中的参数中含有G4Event类，故提前声明
class G4Box;

//一般用户自定义的PrimaryGeneratorAction类需继承G4VUserPrimaryGeneratorAction
class PrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction {
public:
    PrimaryGeneratorAction();//构造函数声明，将在对应源文件中定义
    virtual ~PrimaryGeneratorAction();//析构函数声明，将在对应源文件中定义
    virtual void GeneratePrimaries(G4Event*);//成员函数声明，将在对应源文件中定义. 一般在此函数中指定粒子源的相关信息  
    const G4ParticleGun* GetParticleGun() const { return fParticleGun; }//用于访问私有变量 fParticleGun
private:
    G4ParticleGun* fParticleGun; // G4ParticleGun的指针fParticleGun
    G4Box* fEnvelopeBox;
};

#endif //#ifndef与#endif防止头文件的重复包含和编译
