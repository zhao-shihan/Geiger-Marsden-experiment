#include "PrimaryGeneratorAction.hh" //包含该源文件对应的头文件
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
//包含Geant4粒子数据库
#include "G4SystemOfUnits.hh"//包含Geant4单位制
#include "Randomize.hh"//包含Geant4随机数产生器

PrimaryGeneratorAction::PrimaryGeneratorAction() : G4VUserPrimaryGeneratorAction(), fParticleGun(0) {
    G4int n_particle = 1;
    fParticleGun = new G4ParticleGun(n_particle);

    G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
    G4String particleName;
    G4ParticleDefinition* particle = particleTable->FindParticle(particleName = "alpha");
    fParticleGun->SetParticleDefinition(particle);

    G4double a = 0.0;
    G4double b = 0.0;
    G4double c = 1.0;
    fParticleGun->SetParticleMomentumDirection(G4ThreeVector(a, b, c));
    fParticleGun->SetParticleEnergy(200 * keV);
}

PrimaryGeneratorAction::~PrimaryGeneratorAction() {
    delete fParticleGun;
}

void PrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent) {
    G4double gunSizeXY = 1. * mm;
    G4double gunPosition = -1 * m;
    G4double x0 = gunSizeXY * (G4UniformRand() - 0.5);
    G4double y0 = gunSizeXY * (G4UniformRand() - 0.5);
    G4double z0 = gunPosition;

    fParticleGun->SetParticlePosition(G4ThreeVector(x0, y0, z0));
    fParticleGun->GeneratePrimaryVertex(anEvent);
}
