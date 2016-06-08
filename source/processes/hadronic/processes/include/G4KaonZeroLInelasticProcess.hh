// This code implementation is the intellectual property of
// the RD44 GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4KaonZeroLInelasticProcess.hh,v 2.0 1998/07/02 16:36:27 gunter Exp $
// GEANT4 tag $Name: geant4-00 $
//
 // G4 Process: KaonZeroL Inelastic Process
 // J.L. Chuma, TRIUMF, 11-Feb-1997
 // Last modified: 03-Apr-1997

#ifndef G4KaonZeroLInelasticProcess_h
#define G4KaonZeroLInelasticProcess_h 1

//#include "G4HadronicInelasticProcess.hh"
#include "G4HadronInelasticProcess.hh"
 
// class G4KaonZeroLInelasticProcess : public G4HadronicInelasticProcess
 class G4KaonZeroLInelasticProcess : public G4HadronInelasticProcess
 {
 public:
    
    G4KaonZeroLInelasticProcess(
     const G4String& processName = "KaonZeroLInelastic" ) :
      //      G4HadronicInelasticProcess( processName, G4KaonZeroLong::KaonZeroLong() )
      G4HadronInelasticProcess( processName, G4KaonZeroLong::KaonZeroLong() )
    { }
    
    ~G4KaonZeroLInelasticProcess()
    { }
    
 };
 
#endif