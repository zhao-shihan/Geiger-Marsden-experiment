#include "PrimaryGeneratorAction.hh" //包含该源文件对应的头文件
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
//包含Geant4粒子数据库
#include "G4SystemOfUnits.hh"//包含Geant4单位制
#include "Randomize.hh"//包含Geant4随机数产生器

//定义PrimaryGeneratorAction构造函数
PrimaryGeneratorAction::PrimaryGeneratorAction() : G4VUserPrimaryGeneratorAction(), fParticleGun(0) {
    G4int n_particle = 1;
    fParticleGun = new G4ParticleGun(n_particle);
    //在Geant4中一般用G4ParticleGun来创建粒子
    //n_particle=1 表示在一个event中产生1个粒子，可修改为其他数字以产生不同数量的粒子

    G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
    //创建粒子数据库G4ParticleTable对象以从中查找对应粒子
    G4String particleName;
    G4ParticleDefinition* particle = particleTable->FindParticle(particleName = "alpha");
    //从创建的G4ParticleTable中查找名为"alpha"的粒子
    fParticleGun->SetParticleDefinition(particle);
    //指定G4ParticleGun将要产生的粒子为刚刚查找到的alpha粒子

    G4double a = 0.0;
    G4double b = 0.0;
    G4double c = 1.0;
    fParticleGun->SetParticleMomentumDirection(G4ThreeVector(a, b, c));
    //按照此方法确定的动量分配方式为：
    //x方向：分配|a|/sqrt(a^2+b^2+c^2)的动量
    //y方向：分配|b|/sqrt(a^2+b^2+c^2)的动量
    //z方向：分配|c|/sqrt(a^2+b^2+c^2)的动量
    //如果a/b/c为负数，则表示与对应坐标轴正方向相反
    //e.g.a=0,b=0,c=1表示粒子仅在z轴方向有速度，粒子源沿着z轴方向发射。
    //也可以采用随机分布的方法确定动量方向，与确定位置类似

    fParticleGun->SetParticleEnergy(200 * keV);
    //将alpha粒子的能量设置为200keV
}

//定义析构函数，删除私有变量fParticleGun
PrimaryGeneratorAction::~PrimaryGeneratorAction() {
    delete fParticleGun;
}

//定义成员函数GeneratePrimaries(G4Event* )
//该成员函数将在每个event开始时被调用一次
void PrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent) {
    G4double gunSizeXY = 1. * mm;
    G4double gunPosition = -1 * m;
    G4double x0 = gunSizeXY * (G4UniformRand() - 0.5);
    G4double y0 = gunSizeXY * (G4UniformRand() - 0.5);
    G4double z0 = gunPosition;
    //与x0的确定方法相同
    fParticleGun->SetParticlePosition(G4ThreeVector(x0, y0, z0));
    //使用刚才产生的三个位置坐标来指定本次event中的粒子源位置

    fParticleGun->GeneratePrimaryVertex(anEvent);
    //通过PrimaryGeneratorAction所继承的G4VUserPrimaryGeneratorAction类的成员函数
    //GeneratePrimaryVertex(G4Event* )，根据上述程序设置的信息
    //来指定本次Run中每个event开始时的粒子的产生信息
}
