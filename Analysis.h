//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Feb 28 13:17:19 2018 by ROOT version 5.34/36
// from TTree tree/all observables, signal
// found on file: SkimFileMass.root
//////////////////////////////////////////////////////////

#ifndef Analysis_h
#define Analysis_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include <vector>
#include <vector>
#include <vector>
#include <vector>
#include <vector>

// Fixed size dimensions of array or collections stored in the TTree if any.

class Analysis {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Double_t        JetPt1;
   Double_t        JetPt2;
   Double_t        PrunedMass1;
   Double_t        PrunedMass2;
   Double_t        Jet1_tau2overtau1;
   Double_t        Jet2_tau2overtau2;
   Double_t        Evtweight;

   // List of branches
   TBranch        *b_JetPt1;   //!
   TBranch        *b_JetPt;   //!
   TBranch        *b_PrunedMass1;   //!
   TBranch        *b_PrunedMass;   //!
   TBranch        *b_Jet1_tau2overtau1;   //!
   TBranch        *b_Jet2_tau2overtau1;   //!
   TBranch        *b_Evtweight;   //!

   Analysis(TTree *tree=0);
   virtual ~Analysis();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef Analysis_cxx
Analysis::Analysis(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("SkimFileMass.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("SkimFileMass.root");
      }
      f->GetObject("tree",tree);

   }
   Init(tree);
}

Analysis::~Analysis()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t Analysis::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t Analysis::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void Analysis::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   
   fChain->SetBranchAddress("JetPt1", &JetPt1, &b_JetPt1);
   fChain->SetBranchAddress("JetPt2", &JetPt2, &b_JetPt);
   fChain->SetBranchAddress("PrunedMass1", &PrunedMass1, &b_PrunedMass1);
   fChain->SetBranchAddress("PrunedMass2", &PrunedMass2, &b_PrunedMass);
   fChain->SetBranchAddress("Jet1_tau2overtau1", &Jet1_tau2overtau1, &b_Jet1_tau2overtau1);
   fChain->SetBranchAddress("Jet2_tau2overtau2", &Jet2_tau2overtau2, &b_Jet2_tau2overtau1);
   fChain->SetBranchAddress("Evtweight", &Evtweight, &b_Evtweight);
   Notify();
}

Bool_t Analysis::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void Analysis::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t Analysis::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef Analysis_cxx
