#ifndef B1DetectorConstruction_h
#define B1DetectorConstruction_h 1

//#ifndef与#endif防止头文件的重复包含和编译

#include "G4VUserDetectorConstruction.hh" //一般用户自定义的DetectorConstruction类继承于此
#include "globals.hh"//包含Geant4中的全局变量等，除Actioninitializtion外均应包含

class G4VPhysicalVolume;//DetectorConstruction类中成员函数返回值中包括此类，故应提前声明

//一般用户自定义的DetectorConstruction继承于G4VUserDetectorConstruction
class DetectorConstruction : public G4VUserDetectorConstruction {
public:
    DetectorConstruction();//构造函数声明，将在对应源文件中定义
    virtual ~DetectorConstruction();//析构函数声明，将在对应源文件中定义
    virtual G4VPhysicalVolume* Construct();//成员函数Construct()声明，将在对应源文件中定义. 一般在此函数中指定材料的相关信息.
};

#endif//#ifndef与#endif防止头文件的重复包含和编译
