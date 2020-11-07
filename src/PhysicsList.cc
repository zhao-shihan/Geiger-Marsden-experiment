#include "PhysicsList.hh" //包含此源文件对应的头文件

#include "G4DecayPhysics.hh"
#include "G4EmStandardPhysics.hh"
#include "G4RadioactiveDecayPhysics.hh"
//包含将要指定的物理过程的头文件

PhysicsList::PhysicsList() : G4VModularPhysicsList() {
    SetVerboseLevel(1);
    RegisterPhysics(new G4EmStandardPhysics());
}

PhysicsList::~PhysicsList() {}

void PhysicsList::SetCuts() {
    G4VUserPhysicsList::SetCuts();
}
