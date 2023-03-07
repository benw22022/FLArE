#ifndef FLAREDETECTORCONSTRUCTION_HH
#define FLAREDETECTORCONSTRUCTION_HH

#include <G4VUserDetectorConstruction.hh>
#include <G4String.hh>

//class G4GlobalMagFieldMessenger;
class G4LogicalVolume;
class FLArEDetectorConstructionMessenger;
class DetectorConstructionMaterial;

/**
 *
 * Obligatory class responsible for geometry - volumes, materials, fields, etc.
 *
 */

class FLArEDetectorConstruction : public G4VUserDetectorConstruction {
  public:
    // Main method that has to be override in all detectors
    FLArEDetectorConstruction();
    ~FLArEDetectorConstruction();
    G4VPhysicalVolume* Construct() override;

    void ConstructSDandField() override;
    void SetDetMaterial(G4String detMaterial);
    void SetGeomOption(G4String detGeomOption);
    void saveGDML(G4bool i) { m_saveGdml = i; };
    void UpdateGeometry();

  private:
    void DefineMaterial();

    G4LogicalVolume* worldLog;
    G4LogicalVolume* lArBoxLog;
    G4LogicalVolume* hadCatcherLogical;
    G4LogicalVolume* HadCalXCellLogical;
    G4LogicalVolume* HadCalYCellLogical;
    G4LogicalVolume* muonFinderLogical;
    G4LogicalVolume* MuonFinderXCellLogical;
    G4LogicalVolume* MuonFinderYCellLogical;
    G4LogicalVolume* HadAbsorLayersLogical;
    G4LogicalVolume* MuonFinderAbsorLayersLogical;
    G4LogicalVolume* crygapLogical;
    G4LogicalVolume* TPCModuleLogical;
    G4String fDetMaterialName;
    G4String fDetGeomOption;
    G4bool m_saveGdml;

    DetectorConstructionMaterial* LArBoxMaterials;
    FLArEDetectorConstructionMessenger* messenger;

    //static G4ThreadLocal G4GlobalMagFieldMessenger* fMagFieldMessenger; // magnetic field messenger
};

#endif
