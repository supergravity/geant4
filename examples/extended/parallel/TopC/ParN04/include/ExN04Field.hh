//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
// $Id: ExN04Field.hh 66587 2012-12-21 11:06:44Z ihrivnac $
//
/// \file parallel/ParN04/include/ExN04Field.hh
/// \brief Definition of the ExN04Field class
//

#ifndef ExN04Field_H
#define ExN04Field_H 1

#include "globals.hh"
#include "G4MagneticField.hh"

class ExN04Field : public G4MagneticField
{
  public:
    ExN04Field();
    ~ExN04Field();

    void GetFieldValue( const  double Point[3],
                               double *Bfield ) const;

  private:
    G4double Bz;
    G4double rmax_sq;
    G4double zmax;
};

#endif

