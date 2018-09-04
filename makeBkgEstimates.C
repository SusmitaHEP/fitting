#include "TFile.h"
#include "TROOT.h"
#include "TH1F.h"
#include "TCanvas.h"
// STL libraries
#include <iostream>
#include <cassert>
using namespace std;

void makeBkgEstimates(){
    TFile* inputFile =new TFile("SkimFileMass.root", "READ");
    TFile* outputFile =new TFile("BkgEstimates.root", "RECREATE");
    
    OtherTree=(TTree*)inputFile->Get("Other");
    ZJetsTree=(TTree*)inputFile->Get("ZJets");
    WJetsTree=(TTree*)inputFile->Get("WJets");
    SnglTTree=(TTree*)inputFile->Get("SnglT");
    TTBarTTree=(TTree*)inputFile->Get("TT");
    QCDTree=(TTree*)inputFile->Get("QCD");
    T5HH750Tree=(TTree*)inputFile->Get("T5HH750");
    T5HH1000Tree=(TTree*)inputFile->Get("T5HH1000");
    T5HH1100Tree=(TTree*)inputFile->Get("T5HH1100");
    T5HH1200Tree=(TTree*)inputFile->Get("T5HH1200");
    T5HH1300Tree=(TTree*)inputFile->Get("T5HH1300");
    T5HH1400Tree=(TTree*)inputFile->Get("T5HH1400");
    T5HH1500Tree=(TTree*)inputFile->Get("T5HH1500");
    T5HH1600Tree=(TTree*)inputFile->Get("T5HH1600");
    T5HH1700Tree=(TTree*)inputFile->Get("T5HH1700");
    T5HH1800Tree=(TTree*)inputFile->Get("T5HH1800");
    T5HH1900Tree=(TTree*)inputFile->Get("T5HH1900");
    T5HH2000Tree=(TTree*)inputFile->Get("T5HH2000");
    T5HH2100Tree=(TTree*)inputFile->Get("T5HH2100");

    TH1D*LeadJetMassOther=new TH1D("LeadJetMassOther", "Pruned Mass [GeV]", 150,50,200);
    TH1D*LeadJetMassZJets=new TH1D("LeadJetMassZJets", "Pruned Mass [GeV]", 150,50,200);
    TH1D*LeadJetMassWJets=new TH1D("LeadJetMassWJets", "Pruned Mass [GeV]", 150,50,200);
    TH1D*LeadJetMassSnglT=new TH1D("LeadJetMassSnglT", "Pruned Mass [GeV]", 150,50,200);
    TH1D*LeadJetMassTT=new TH1D("LeadJetMassTT", "Pruned Mass [GeV]", 150,50,200);
    TH1D*LeadJetMassQCD=new TH1D("LeadJetMassQCD", "Pruned Mass [GeV]", 150,50,200);
    TH1D*LeadJetMassdata=new TH1D("LeadJetMassdata", "Pruned Mass [GeV]", 150,50,200);
    TH1D*LeadJetMassT5HH750=new TH1D("LeadJetMassT5HH750", "Pruned Mass [GeV]", 150,50,200);
    TH1D*LeadJetMassT5HH1000=new TH1D("LeadJetMassT5HH1000", "Pruned Mass [GeV]", 150,50,200);
    TH1D*LeadJetMassT5HH1100=new TH1D("LeadJetMassT5HH1100", "Pruned Mass [GeV]", 150,50,200);
    TH1D*LeadJetMassT5HH1200=new TH1D("LeadJetMassT5HH1200", "Pruned Mass [GeV]", 150,50,200);
    TH1D*LeadJetMassT5HH1300=new TH1D("LeadJetMassT5HH1300", "Pruned Mass [GeV]", 150,50,200);
    TH1D*LeadJetMassT5HH1400=new TH1D("LeadJetMassT5HH1400", "Pruned Mass [GeV]", 150,50,200);
    TH1D*LeadJetMassT5HH1500=new TH1D("LeadJetMassT5HH1500", "Pruned Mass [GeV]", 150,50,200);
    TH1D*LeadJetMassT5HH1600=new TH1D("LeadJetMassT5HH1600", "Pruned Mass [GeV]", 150,50,200);
    TH1D*LeadJetMassT5HH1700=new TH1D("LeadJetMassT5HH1700", "Pruned Mass [GeV]", 150,50,200);
    TH1D*LeadJetMassT5HH1800=new TH1D("LeadJetMassT5HH1800", "Pruned Mass [GeV]", 150,50,200);
    TH1D*LeadJetMassT5HH1900=new TH1D("LeadJetMassT5HH1900", "Pruned Mass [GeV]", 150,50,200);
    TH1D*LeadJetMassT5HH2000=new TH1D("LeadJetMassT5HH2000", "Pruned Mass [GeV]", 150,50,200);
    TH1D*LeadJetMassT5HH2100=new TH1D("LeadJetMassT5HH2100", "Pruned Mass [GeV]", 150,50,200);
    
    
    TH1D*METBinsOther=new TH1D("METBinsOther", "MET [GeV]", 100.,0.,2000.);
    TH1D*METBinsZJets=new TH1D("METBinsZJets", "MET [GeV]", 100.,0.,2000.);
    TH1D*METBinsWJets=new TH1D("METBinsWJets", "MET [GeV]", 100.,0.,2000.);
    TH1D*METBinsSnglT=new TH1D("METBinsSnglT", "MET [GeV]", 100.,0.,2000.);
    TH1D*METBinsTT=new TH1D("METBinsTT", "MET [GeV]", 100.,0.,2000.);
    TH1D*METBinsQCD=new TH1D("METBinsQCD", "MET [GeV]", 100.,0.,2000.);
    TH1D*METBinsdata=new TH1D("METBinsdata", "MET [GeV]", 100.,0.,2000.);
    TH1D*METT5HH750=new TH1D("METT5HH750", "MET [GeV]", 100.,0.,2000.);
    TH1D*METT5HH1000=new TH1D("METT5HH1000", "MET [GeV]", 100.,0.,2000.);
    TH1D*METT5HH1100=new TH1D("METT5HH1100", "MET [GeV]", 100.,0.,2000.);
    TH1D*METT5HH1200=new TH1D("METT5HH1200", "MET [GeV]", 100.,0.,2000.);
    TH1D*METT5HH1300=new TH1D("METT5HH1300", "MET [GeV]", 100.,0.,2000.);
    TH1D*METT5HH1400=new TH1D("METT5HH1400", "MET [GeV]", 100.,0.,2000.);
    TH1D*METT5HH1500=new TH1D("METT5HH1500", "MET [GeV]", 100.,0.,2000.);
    TH1D*METT5HH1600=new TH1D("METT5HH1600", "MET [GeV]", 100.,0.,2000.);
    TH1D*METT5HH1700=new TH1D("METT5HH1700", "MET [GeV]", 100.,0.,2000.);
    TH1D*METT5HH1800=new TH1D("METT5HH1800", "MET [GeV]", 100.,0.,2000.);
    TH1D*METT5HH1900=new TH1D("METT5HH1900", "MET [GeV]", 100.,0.,2000.);
    TH1D*METT5HH2000=new TH1D("METT5HH2000", "MET [GeV]", 100.,0.,2000.);
    TH1D*METT5HH2100=new TH1D("METT5HH2100", "MET [GeV]", 100.,0.,2000.);
    
    
    LeadJetMassOther->Sumw2(kTRUE);
    LeadJetMassZJets->Sumw2(kTRUE);
    LeadJetMassWJets->Sumw2(kTRUE);
    LeadJetMassSnglT->Sumw2(kTRUE);
    LeadJetMassTT->Sumw2(kTRUE);
    LeadJetMassQCD->Sumw2(kTRUE);
    LeadJetMassdata->Sumw2(kTRUE);
    LeadJetMassT5HH750->Sumw2(kTRUE);
    LeadJetMassT5HH1000->Sumw2(kTRUE);
    LeadJetMassT5HH1100->Sumw2(kTRUE);
    LeadJetMassT5HH1200->Sumw2(kTRUE);
    LeadJetMassT5HH1300->Sumw2(kTRUE);
    LeadJetMassT5HH1400->Sumw2(kTRUE);
    LeadJetMassT5HH1500->Sumw2(kTRUE);
    LeadJetMassT5HH1600->Sumw2(kTRUE);
    LeadJetMassT5HH1700->Sumw2(kTRUE);
    LeadJetMassT5HH1800->Sumw2(kTRUE);
    LeadJetMassT5HH1900->Sumw2(kTRUE);
    LeadJetMassT5HH2000->Sumw2(kTRUE);
    LeadJetMassT5HH2100->Sumw2(kTRUE);
    
    OtherTree->Draw("PrunedMass1>>LeadJetMassOther", "(HT>1000 && JetPt1>600 && JetPt2>400 && MET>300 && PrunedMass2>75 && PrunedMass2<95)*Evtweight*(80/35.9)");
    ZJetsTree->Draw("PrunedMass1>>LeadJetMassZJets", "(HT>1000 && JetPt1>600 && JetPt2>400 && MET>300 && PrunedMass2>75 && PrunedMass2<95)*Evtweight*(80/35.9)");
    WJetsTree->Draw("PrunedMass1>>LeadJetMassWJets", "(HT>1000 && JetPt1>600 && JetPt2>400 && MET>300 && PrunedMass2>75 && PrunedMass2<95)*Evtweight*(80/35.9)");
    SnglTTree->Draw("PrunedMass1>>LeadJetMassSnglT", "(HT>1000 && JetPt1>600 && JetPt2>400 && MET>300 && PrunedMass2>75 && PrunedMass2<95)*Evtweight*(80/35.9)");
    TTBarTTree->Draw("PrunedMass1>>LeadJetMassTT", "(HT>1000 && JetPt1>600 && JetPt2>400 && MET>300 && PrunedMass2>75 && PrunedMass2<95)*Evtweight*(80/35.9)");
    QCDTree->Draw("PrunedMass1>>LeadJetMassQCD", "(HT>1000 && JetPt1>600 && JetPt2>400 && MET>300 && PrunedMass2>75 && PrunedMass2<95)*Evtweight*(80/35.9)");
    T5HH750Tree->Draw("PrunedMass1>>LeadJetMassT5HH750", "(HT>1000 && JetPt1>600 && JetPt2>400 && MET>300 && PrunedMass2>75 && PrunedMass2<95)*Evtweight*(80/35.9)");
    T5HH1000Tree->Draw("PrunedMass1>>LeadJetMassT5HH1000", "(HT>1000 && JetPt1>600 && JetPt2>400 && MET>300 && PrunedMass2>75 && PrunedMass2<95)*Evtweight*(80/35.9)");
    T5HH1100Tree->Draw("PrunedMass1>>LeadJetMassT5HH1100", "(HT>1000 && JetPt1>600 && JetPt2>400 && MET>300 && PrunedMass2>75 && PrunedMass2<95)*Evtweight*(80/35.9)");
    T5HH1200Tree->Draw("PrunedMass1>>LeadJetMassT5HH1200", "(HT>1000 && JetPt1>600 && JetPt2>400 && MET>300 && PrunedMass2>75 && PrunedMass2<95)*Evtweight*(80/35.9)");
    T5HH1300Tree->Draw("PrunedMass1>>LeadJetMassT5HH1300", "(HT>1000 && JetPt1>600 && JetPt2>400 && MET>300 && PrunedMass2>75 && PrunedMass2<95)*Evtweight*(80/35.9)");
    T5HH1400Tree->Draw("PrunedMass1>>LeadJetMassT5HH1400", "(HT>1000 && JetPt1>600 && JetPt2>400 && MET>300 && PrunedMass2>75 && PrunedMass2<95)*Evtweight*(80/35.9)");
    T5HH1500Tree->Draw("PrunedMass1>>LeadJetMassT5HH1500", "(HT>1000 && JetPt1>600 && JetPt2>400 && MET>300 && PrunedMass2>75 && PrunedMass2<95)*Evtweight*(80/35.9)");
    T5HH1600Tree->Draw("PrunedMass1>>LeadJetMassT5HH1600", "(HT>1000 && JetPt1>600 && JetPt2>400 && MET>300 && PrunedMass2>75 && PrunedMass2<95)*Evtweight*(80/35.9)");
    T5HH1700Tree->Draw("PrunedMass1>>LeadJetMassT5HH1700", "(HT>1000 && JetPt1>600 && JetPt2>400 && MET>300 && PrunedMass2>75 && PrunedMass2<95)*Evtweight*(80/35.9)");
    T5HH1800Tree->Draw("PrunedMass1>>LeadJetMassT5HH1800", "(HT>1000 && JetPt1>600 && JetPt2>400 && MET>300 && PrunedMass2>75 && PrunedMass2<95)*Evtweight*(80/35.9)");
    T5HH1900Tree->Draw("PrunedMass1>>LeadJetMassT5HH1900", "(HT>1000 && JetPt1>600 && JetPt2>400 && MET>300 && PrunedMass2>75 && PrunedMass2<95)*Evtweight*(80/35.9)");
    T5HH2000Tree->Draw("PrunedMass1>>LeadJetMassT5HH2000", "(HT>1000 && JetPt1>600 && JetPt2>400 && MET>300 && PrunedMass2>75 && PrunedMass2<95)*Evtweight*(80/35.9)");
    T5HH2100Tree->Draw("PrunedMass1>>LeadJetMassT5HH2100", "(HT>1000 && JetPt1>600 && JetPt2>400 && MET>300 && PrunedMass2>75 && PrunedMass2<95)*Evtweight*(80/35.9)");

        
    OtherTree->Draw("MET>>METBinsOther", "(HT>1000 && JetPt1>600 && JetPt2>400 && MET>300 && PrunedMass1>75 && PrunedMass1<95 && PrunedMass2>75 && PrunedMass2<95)*Evtweight*(80/35.9)");
    ZJetsTree->Draw("MET>>METBinsZJets", "(HT>1000 && JetPt1>600 && JetPt2>400 && MET>300 && PrunedMass1>75 && PrunedMass1<95 && PrunedMass2>75 && PrunedMass2<95)*Evtweight*(80/35.9)");
    WJetsTree->Draw("MET>>METBinsWJets", "(HT>1000 && JetPt1>600 && JetPt2>400 && MET>300 && PrunedMass1>75 && PrunedMass1<95 && PrunedMass2>75 && PrunedMass2<95)*Evtweight*(80/35.9)");
    SnglTTree->Draw("MET>>METBinsSnglT", "(HT>1000 && JetPt1>600 && JetPt2>400 && MET>300 && PrunedMass1>75 && PrunedMass1<95 && PrunedMass2>75 && PrunedMass2<95)*Evtweight*(80/35.9)");
    TTBarTTree->Draw("MET>>METBinsTT", "(HT>1000 && JetPt1>600 && JetPt2>400 && MET>300 && PrunedMass1>75 && PrunedMass1<95 && PrunedMass2>75 && PrunedMass2<95)*Evtweight*(80/35.9)");
    QCDTree->Draw("MET>>METBinsQCD", "(HT>1000 && JetPt1>600 && JetPt2>400 && MET>300 && PrunedMass1>75 && PrunedMass1<95 && PrunedMass2>75 && PrunedMass2<95)*Evtweight*(80/35.9)");
    T5HH750Tree->Draw("MET>>METT5HH750", "(HT>1000 && JetPt1>600 && JetPt2>400 && MET>300 && PrunedMass1>75 && PrunedMass1<95 && PrunedMass2>75 && PrunedMass2<95)*Evtweight*(80/35.9)");
    T5HH1000Tree->Draw("MET>>METT5HH1000", "(HT>1000 && JetPt1>600 && JetPt2>400 && MET>300 && PrunedMass1>75 && PrunedMass1<95 && PrunedMass2>75 && PrunedMass2<95)*Evtweight*(80/35.9)");
    T5HH1100Tree->Draw("MET>>METT5HH1100", "(HT>1000 && JetPt1>600 && JetPt2>400 && MET>300 && PrunedMass1>75 && PrunedMass1<95 && PrunedMass2>75 && PrunedMass2<95)*Evtweight*(80/35.9)");
    T5HH1200Tree->Draw("MET>>METT5HH1200", "(HT>1000 && JetPt1>600 && JetPt2>400 && MET>300 && PrunedMass1>75 && PrunedMass1<95 && PrunedMass2>75 && PrunedMass2<95)*Evtweight*(80/35.9)");
    T5HH1300Tree->Draw("MET>>METT5HH1300", "(HT>1000 && JetPt1>600 && JetPt2>400 && MET>300 && PrunedMass1>75 && PrunedMass1<95 && PrunedMass2>75 && PrunedMass2<95)*Evtweight*(80/35.9)");
    T5HH1400Tree->Draw("MET>>METT5HH1400", "(HT>1000 && JetPt1>600 && JetPt2>400 && MET>300 && PrunedMass1>75 && PrunedMass1<95 && PrunedMass2>75 && PrunedMass2<95)*Evtweight*(80/35.9)");
    T5HH1500Tree->Draw("MET>>METT5HH1500", "(HT>1000 && JetPt1>600 && JetPt2>400 && MET>300 && PrunedMass1>75 && PrunedMass1<95 && PrunedMass2>75 && PrunedMass2<95)*Evtweight*(80/35.9)");
    T5HH1600Tree->Draw("MET>>METT5HH1600", "(HT>1000 && JetPt1>600 && JetPt2>400 && MET>300 && PrunedMass1>75 && PrunedMass1<95 && PrunedMass2>75 && PrunedMass2<95)*Evtweight*(80/35.9)");
    T5HH1700Tree->Draw("MET>>METT5HH1700", "(HT>1000 && JetPt1>600 && JetPt2>400 && MET>300 && PrunedMass1>75 && PrunedMass1<95 && PrunedMass2>75 && PrunedMass2<95)*Evtweight*(80/35.9)");
    T5HH1800Tree->Draw("MET>>METT5HH1800", "(HT>1000 && JetPt1>600 && JetPt2>400 && MET>300 && PrunedMass1>75 && PrunedMass1<95 && PrunedMass2>75 && PrunedMass2<95)*Evtweight*(80/35.9)");
    T5HH1900Tree->Draw("MET>>METT5HH1900", "(HT>1000 && JetPt1>600 && JetPt2>400 && MET>300 && PrunedMass1>75 && PrunedMass1<95 && PrunedMass2>75 && PrunedMass2<95)*Evtweight*(80/35.9)");
    T5HH2000Tree->Draw("MET>>METT5HH2000", "(HT>1000 && JetPt1>600 && JetPt2>400 && MET>300 && PrunedMass1>75 && PrunedMass1<95 && PrunedMass2>75 && PrunedMass2<95)*Evtweight*(80/35.9)");
    T5HH2100Tree->Draw("MET>>METT5HH2100", "(HT>1000 && JetPt1>600 && JetPt2>400 && MET>300 && PrunedMass1>75 && PrunedMass1<95 && PrunedMass2>75 && PrunedMass2<95)*Evtweight*(80/35.9)");
   
    
    outputFile->Write();
  
}
