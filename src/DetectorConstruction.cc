#include "DetectorConstruction.hh"//包含该源文件对应的头文件

#include "G4NistManager.hh"//包含在材料种类定义时所使用的数据库
#include "G4Box.hh"//包含在实体定义时所使用的形状：长方体
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"//包含逻辑几何体，物理几何体(G4PVPlacement类)

#include "G4SystemOfUnits.hh"//包含物理单位制

DetectorConstruction::DetectorConstruction() : G4VUserDetectorConstruction() {}

DetectorConstruction::~DetectorConstruction() {}

G4VPhysicalVolume* DetectorConstruction::Construct() {
    G4NistManager* nist = G4NistManager::Instance();
    G4double density = 1e-14 * g / cm2;
    G4Material* world_mat = nist->BuildMaterialWithNewDensity("Void", "G4_AIR", density);
    G4Material* env_mat = nist->FindOrBuildMaterial("G4_Au");

    bool checkOverlaps = true;
    //指定world的长宽高
    G4double world_x = 0.5 * m;
    G4double world_y = 0.5 * m;
    G4double world_z = 1.0 * m;
    //指定env的长宽高
    G4double env_x = world_x;
    G4double env_y = world_y;
    G4double env_z = 1 * nm;

    G4Box* solidWorld = new G4Box(
        "World",
        world_x,
        world_y,
        world_z
    );
    G4Box* solidEnv = new G4Box(
        "Env",
        env_x,
        env_y,
        env_z
    );
    G4LogicalVolume* logicWorld = new G4LogicalVolume(
        solidWorld,
        world_mat,
        "World"
    );
    G4LogicalVolume* logicEnv = new G4LogicalVolume(
        solidEnv,
        env_mat,
        "Env"
    );
    G4VPhysicalVolume* physWorld = new G4PVPlacement(
        0,
        G4ThreeVector(),
        logicWorld,
        "World",
        0,
        false,
        0,
        checkOverlaps
    );
    G4VPhysicalVolume* physEnv = new G4PVPlacement(
        0,
        G4ThreeVector(),
        logicEnv,
        "Env",
        logicWorld,
        false,
        0,
        checkOverlaps
    );

    return physWorld;
}
