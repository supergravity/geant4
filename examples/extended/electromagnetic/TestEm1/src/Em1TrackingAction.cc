
// This code implementation is the intellectual property of
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: Em1TrackingAction.cc,v 1.1.4.1 1999/12/07 20:46:56 gunter Exp $
// GEANT4 tag $Name: geant4-01-00 $
//
// 

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

#include "Em1TrackingAction.hh"
#include "Em1RunAction.hh"

#include "G4Track.hh"

#include "CLHEP/Hist/HBookFile.h"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

Em1TrackingAction::Em1TrackingAction(Em1RunAction* RunAct)
:runAction(RunAct)
{ }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

void Em1TrackingAction::PostUserTrackingAction(const G4Track* aTrack)
{
  //increase nb of processed tracks 
  //count nb of steps of this track
  
  G4int   nbSteps = aTrack->GetCurrentStepNumber();
  G4double Trleng = aTrack->GetTrackLength();
  
  if (aTrack->GetDefinition()->GetPDGCharge() == 0.)
       {runAction->CountTraks0(1); runAction->CountSteps0(nbSteps);}
  else {runAction->CountTraks1(1); runAction->CountSteps1(nbSteps);
        runAction->GetHisto(0)->accumulate(Trleng);
        runAction->GetHisto(1)->accumulate((float)nbSteps);
  }    
}

