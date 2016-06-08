// This code implementation is the intellectual property of
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: Em5PhysicsList.hh,v 1.1.4.1 1999/12/07 20:47:08 gunter Exp $
// GEANT4 tag $Name: geant4-01-00 $
//

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

#ifndef Em5PhysicsList_h
#define Em5PhysicsList_h 1

#include "G4VUserPhysicsList.hh"
#include "globals.hh"

class Em5DetectorConstruction;
class Em5PhysicsListMessenger;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

class Em5PhysicsList: public G4VUserPhysicsList
{
  public:
    Em5PhysicsList( Em5DetectorConstruction*);
   ~Em5PhysicsList();

  protected:
    // Construct particle and physics
    void ConstructParticle();
    void ConstructProcess();
 
    void SetCuts();

  protected:
    // these methods Construct particles 
    void ConstructBosons();
    void ConstructLeptons();
    void ConstructMesons();
    void ConstructBarions();

  protected:
  // these methods Construct physics processes and register them
    void ConstructGeneral();
    void ConstructEM();
    
  public:

    void SetGammaCut(G4double);
    void SetElectronCut(G4double);
    void SetProtonCut(G4double);
    void SetCutsByEnergy(G4double);
    void GetRange(G4double);

    void SetMaxStep(G4double);

  private:

    G4double cutForGamma;
    G4double cutForElectron;
    G4double cutForProton;
    G4double currentDefaultCut;
    
    G4double MaxChargedStep;    

    Em5DetectorConstruction* pDet;
    Em5PhysicsListMessenger* physicsListMessenger;
};

#endif


