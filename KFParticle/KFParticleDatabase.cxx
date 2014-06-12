//----------------------------------------------------------------------------
// Implementation of the KFParticle class
// .
// @author  I.Kisel, I.Kulakov, M.Zyzak
// @version 1.0
// @since   20.08.13
// 
// 
//  -= Copyright &copy ALICE HLT and CBM L1 Groups =-
//____________________________________________________________________________

#include "KFParticleDatabase.h"

KFParticleDatabase* KFParticleDatabase::fDatabase = 0;

KFParticleDatabase::KFParticleDatabase()
{
  fMass[0] = 0.000510999;
  fMass[1] = 0.105658;
  fMass[2] = 0.13957;
  fMass[3] = 0.493667;
  fMass[4] = 0.9382723;

  fMassSecPDG[0] = 0.497614; //K0
  fMassSecPDG[1] = 1.115683; //Lambda
  fMassSecPDG[2] = 1.32171; //Xi  
  fMassSecPDG[3] = 0; //gamma
  
#ifdef PANDA_STT
  fMassSecPDGSigma[0]=2.2e-3; //K0 TODO tune
  fMassSecPDGSigma[1]=3.7e-3; //Lambda
  fMassSecPDGSigma[2]=2.e-3; //Xi TODO tune
#elif defined ALICE_ITS
  fMassSecPDGSigma[0]=17.7e-3;
  fMassSecPDGSigma[1]=5.9e-3;
  fMassSecPDGSigma[2]=7.3e-3;
#elif defined STAR_HFT
  fMassSecPDGSigma[0]=17.7e-3;
  fMassSecPDGSigma[1]=5.9e-3;
  fMassSecPDGSigma[2]=7.3e-3;
#else
  fMassSecPDGSigma[0]=4.9e-3; //TODO tune
  fMassSecPDGSigma[1]=2.5e-3;
  fMassSecPDGSigma[2]=2.5e-3; //TODO tune
#endif
  fMassSecPDGSigma[3]=6.0e-3; //TODO tune

  fMassPi0PDG = 0.13498;
  fMassPi0PDGSigma = 0.006;
  
  fDatabase = this;
}

KFParticleDatabase kfPartDatabase; //create instance