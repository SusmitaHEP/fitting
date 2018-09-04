#ifndef __CINT__
#include "RooGlobalFunc.h"
#endif
#include "TFile.h"
#include "TROOT.h"
#include "TH1F.h"
#include "THStack.h"
#include "RooRealVar.h"
#include "RooDataHist.h"
#include "RooHistPdf.h"
#include "RooAddPdf.h"
#include "RooPlot.h"
#include "RooGaussian.h"
#include "RooBernstein.h"
#include "RooWorkspace.h"
#include "TLegend.h"
#include "TCanvas.h"
#include "RooDataSet.h"
#include "RooGaussian.h"
#include "RooLandau.h"
#include "RooFFTConvPdf.h"
// STL libraries
#include <iostream>
#include <cassert>

using namespace RooFit;
using namespace std;

//int main( int argc , char** argv ){
void fitSignalBkg(){
    //gROOT->ProcessLine(".L tdrstyle.C");
    //gROOT->ProcessLine("setTDRStyle()");
    
    TFile* inputFile =new TFile("SkimFileMass.root", "READ");
    //BKg Shapes:
    OtherTree=(TTree*)inputFile->Get("Other");
    ZJetsTree=(TTree*)inputFile->Get("ZJets");
    WJetsTree=(TTree*)inputFile->Get("WJets");
    SnglTTree=(TTree*)inputFile->Get("SnglT");
    TTBarTTree=(TTree*)inputFile->Get("TT");
    QCDTree=(TTree*)inputFile->Get("QCD");
    T5HH1300Tree=(TTree*)inputFile->Get("T5HH1300");
    T5HH1700Tree=(TTree*)inputFile->Get("T5HH1700");


    TH1D*PrunedMassZBkg=new TH1D("PrunedMassZBkg", "Pruned Mass [GeV]", 30,50,200);
    TH1D*PrunedMassWBkg=new TH1D("PrunedMassWBkg", "Pruned Mass [GeV]", 30,50,200);
    TH1D*PrunedMassTTBarBkg=new TH1D("PrunedMassTTBarBkg", "Pruned Mass [GeV]", 30,50,200);
    TH1D*PrunedMassQCDBkg=new TH1D("PrunedMassQCDBkg", "Pruned Mass [GeV]", 30,50,200);
    TH1D*PrunedMassT5HH1300Sig=new TH1D("PrunedMassT5HH1300Sig", "Pruned Mass [GeV]", 30,50,200);
    TH1D*PrunedMassT5HH1700Sig=new TH1D("PrunedMassT5HH1700Sig", "Pruned Mass [GeV]", 30,50,200);

    TH1D*METZBkg=new TH1D("METZBkg", "Pruned Mass [GeV]", 30,300,1500);
    TH1D*METWBkg=new TH1D("METWBkg", "Pruned Mass [GeV]", 30,300,1500);
    TH1D*METTTBarBkg=new TH1D("METTTBarBkg", "Pruned Mass [GeV]", 30,300,1500);
    TH1D*METQCDBkg=new TH1D("METQCDBkg", "Pruned Mass [GeV]", 30,300,1500);
    TH1D*METT5HH1300Sig=new TH1D("METT5HH1300Sig", "Pruned Mass [GeV]", 30,300,1500);
    TH1D*METT5HH1700Sig=new TH1D("METT5HH1700Sig", "Pruned Mass [GeV]", 30,300,1500);

    PrunedMassQCDBkg->Sumw2(kTRUE);
    PrunedMassWBkg->Sumw2(kTRUE);
    PrunedMassZBkg->Sumw2(kTRUE);
    PrunedMassTTBarBkg->Sumw2(kTRUE);
    PrunedMassT5HH1300Sig->Sumw2(kTRUE);
    PrunedMassT5HH1700Sig->Sumw2(kTRUE);
   
    ZJetsTree->Draw("PrunedMass1>>PrunedMassZBkg", "(MET>1000 && MET<1200 && HT>600 && JetPt1>400 && JetPt2>200 && PrunedMass1>70 && PrunedMass1<100 && PrunedMass2>70 && PrunedMass2<100)*Evtweight*(80/35.9)");
    WJetsTree->Draw("PrunedMass1>>PrunedMassWBkg", "(MET>1000 && MET<1200 && HT>600 && JetPt1>400 && JetPt2>200 && PrunedMass1>70 && PrunedMass1<100 && PrunedMass2>70 && PrunedMass2<100)*Evtweight*(80/35.9)");
    TTBarTTree->Draw("PrunedMass1>>PrunedMassTTBarBkg","(MET>1000 && MET<1200 && HT>600 && JetPt1>400 && JetPt2>200 && PrunedMass1>70 && PrunedMass1<100 && PrunedMass2>70 && PrunedMass2<100)*Evtweight*(80/35.9)");
    QCDTree->Draw("PrunedMass1>>PrunedMassQCDBkg", "(MET>1000 && MET<1200 && HT>600 && JetPt1>400 && JetPt2>200 && PrunedMass1>70 && PrunedMass1<100 && PrunedMass2>70 && PrunedMass2<100)*Evtweight*(80/35.9)");
    T5HH1300Tree->Draw("PrunedMass1>>PrunedMassT5HH1300Sig", "(MET>1000 && MET<1200 && HT>600 && JetPt1>400 && JetPt2>200 && PrunedMass1>70 && PrunedMass1<100 && PrunedMass2>70 && PrunedMass2<100)*Evtweight*(80/35.9)");
    T5HH1700Tree->Draw("PrunedMass1>>PrunedMassT5HH1700Sig", "(MET>1000 && MET<1200 && HT>600 && JetPt1>400 && JetPt2>200 && PrunedMass1>70 && PrunedMass1<100 && PrunedMass2>70 && PrunedMass2<100)*Evtweight*(80/35.9)");
    
    
    THStack*hstack=new THStack("hstack","");
    
     
    PrunedMassQCDBkg->SetFillColor(kMagenta+1);
    PrunedMassWBkg->SetFillColor(kBlue+1);
    PrunedMassZBkg->SetFillColor(kGreen+1);
    PrunedMassTTBarBkg->SetFillColor(kCyan+1);
    PrunedMassT5HH1300Sig->SetLineColor(kBlack+1);
    PrunedMassT5HH1700Sig->SetLineColor(kYellow+1);
    

    leg=new TLegend(0.5488722,0.6825806,0.914787,0.8748387,NULL,"brNDC");
    leg->AddEntry(PrunedMassQCDBkg, "QCD ","F");
    leg->AddEntry(PrunedMassTTBarBkg, "TTJets ","F");
    leg->AddEntry(PrunedMassWBkg, "W+Jets ","F");
    leg->AddEntry(PrunedMassZBkg, "Z+Jets ","F");
    leg->AddEntry(PrunedMassT5HH1300Sig, "T5ZZ1300 ","L");
    leg->AddEntry(PrunedMassT5HH1700Sig, "T5ZZ1700 ","L");    

    hstack->Add(PrunedMassQCDBkg);
    hstack->Add(PrunedMassTTBarBkg);
    hstack->Add(PrunedMassWBkg);
    hstack->Add(PrunedMassZBkg);
    TH1D*TotalBkg=(TH1D*)hstack->GetStack()->Last();
    
    //cout<<">>>>>>>>>>>>>>>>QCD>>>>>>>>>>>>>>>>"<<PrunedMassQCDBkg->Integral()<<endl;
    cout<<"Z+Jets==>"<<PrunedMassZBkg->Integral()<<endl;
    cout<<"W+tttJets==>"<<PrunedMassWBkg->Integral()+PrunedMassTTBarBkg->Integral()<<endl;
    //cout<<""<<PrunedMassZBkg->Integral()<<endl;
    //cout<<""<<PrunedMassT5HH1300Sig->Integral()<<endl;
    //cout<<""<<PrunedMassT5HH1700Sig->Integral()<<endl;
    
 /*   
    Int_t nbins = TotalBkg->GetSize();
    double_t bgerror1 = 0.; 
    for (Int_t i=1;i<nbins+1;i++) { 
    bgerror1 += TotalBkg->GetBinError(i);
      bgerror1 = TMath::Sqrt(bgerror1);
      cout<<"error in each bin******"<<bgerror1<<endl;
    }
    cout<<"MET>1200######"<<TotalBkg->Integral()<<endl;
    cout<<"Error################*********"<<bgerror1<<endl;

   
    
    TCanvas *c= new TCanvas("c","c",600,600) ;
    hstack->Draw("hist"); 
    PrunedMassT5HH1700Sig->Draw("hist same"); //PrunedMassT5HH1300Sig->Draw("hist same"); 
    leg->Draw();
    c->SaveAs("histo.png");

    ZJetsTree->Draw("MET>>METZBkg", "(MET>450 && MET<600 &&HT>600 && JetPt1>400 && JetPt2>200 && PrunedMass1>70 && PrunedMass1<100 && PrunedMass2>70 && PrunedMass2<100)*Evtweight*(80/35.9)");
    WJetsTree->Draw("MET>>METWBkg", "(MET>450 && MET<600 &&HT>600 && JetPt1>400 && JetPt2>200 && PrunedMass1>70 && PrunedMass1<100 && PrunedMass2>70 && PrunedMass2<100)*Evtweight*(80/35.9)");
    TTBarTTree->Draw("MET>>METTTBarBkg","(MET>450 && MET<600 &&HT>600 && JetPt1>400 && JetPt2>200 && PrunedMass1>70 && PrunedMass1<100 && PrunedMass2>70 && PrunedMass2<100)*Evtweight*(80/35.9)");
    QCDTree->Draw("MET>>METQCDBkg", "(MET>450 && MET<600 &&HT>600 && JetPt1>400 && JetPt2>200 && PrunedMass1>70 && PrunedMass1<100 && PrunedMass2>70 && PrunedMass2<100)*Evtweight*(80/35.9)");
    T5HH1300Tree->Draw("MET>>METT5HH1300Sig", "(MET>450 && MET<600 &&HT>600 && JetPt1>400 && JetPt2>200 && PrunedMass1>70 && PrunedMass1<100 && PrunedMass2>70 && PrunedMass2<100)*Evtweight*(80/35.9)");
    T5HH1700Tree->Draw("MET>>METT5HH1700Sig", "(MET>450 && MET<600 &&HT>600 && JetPt1>400 && JetPt2>200 && PrunedMass1>70 && PrunedMass1<100 && PrunedMass2>70 && PrunedMass2<100)*Evtweight*(80/35.9)");
   
    
    THStack*hstack2=new THStack("hstack2","");
    
     
    //METQCDBkg->SetFillColor(kMagenta+1);
    //METWBkg->SetFillColor(kBlue+1);
    METZBkg->SetFillColor(kGreen+1);
    //METTTBarBkg->SetFillColor(kCyan+1);
    //METT5HH1300Sig->SetLineColor(kBlack+1);
    //METT5HH1700Sig->SetLineColor(kBlack+1);
    

    leg=new TLegend(0.5488722,0.6825806,0.914787,0.8748387,NULL,"brNDC");
    leg->AddEntry(METQCDBkg, "QCD ","F");
    leg->AddEntry(METTTBarBkg, "TTJets ","F");
    leg->AddEntry(METWBkg, "W+Jets ","F");
    leg->AddEntry(METZBkg, "Z+Jets ","F");
    //leg->AddEntry(METT5HH1300Sig, "T5ZZ1300 ","L");
    leg->AddEntry(METT5HH1700Sig, "T5ZZ1700 ","L");    

    hstack2->Add(METQCDBkg);
    hstack2->Add(METTTBarBkg);
    hstack2->Add(METWBkg);
    hstack2->Add(METZBkg);
    TH1D*TotalBkgMETShapeB=(TH1D*)hstack2->GetStack()->Last();
    
    cout<<"Total Integral****************************************"<<TotalBkgMETShapeB->Integral()<<endl;

   
    RooRealVar jetMass("jetMass","Pruned Jet Mass [GeV]",30.,50.,200.);

    RooRealVar *METBins= new RooRealVar("METBins","MET [GeV]",30.,300.,1500.);
    jetMass.setRange("Signal",70., 100.);
    jetMass.setRange("Sideband1",50., 70.);
    jetMass.setRange("Sideband2",100., 200.);
    jetMass.setRange("Sideband3",100., 160.);
    

    METBins->setRange("METBin1", 300., 450.);
    METBins->setRange("METBin2", 450., 600.);
    METBins->setRange("METBin3", 600., 800.);
    METBins->setRange("METBin4", 800., 1000.);
    METBins->setRange("METBin5", 1000, 1200.);
    METBins->setRange("METBin6", 1200, 1500.);
        
    RooDataHist MC_bkg("MC_bkg","MC_bkg",jetMass,Import(*TotalBkg));
    
    RooRealVar a1("a1","a1",0.0,-100.0,100.0);
    RooRealVar a2("a2","a2",0.0,-100.0,100.0);
    //RooRealVar a3("a3","a3",0.0,-100.0,100.0);
    //RooRealVar a4("a4","a4",0.0,-100.0,100.0);
    
    RooChebychev poly("poly", "", jetMass, RooArgList(a1,a2));
    //RooExponential poly("poly", "", jetMass, a1);
    //RooPolynomial poly("poly", "", jetMass, RooArgList(a1,a2));
    
        
    //RooPlot* frame = jetMass.frame(Title("polynomial fit"));
    //poly.fitTo(MC_bkg);
    RooFitResult* r =  poly.fitTo(MC_bkg, Range("Sideband1,Sideband2"),Save());
    //integral of mass in signal region:
    RooAbsReal*BkginSR=poly.createIntegral(jetMass, NormSet(jetMass), Range("Signal"));
       
    RooPlot* frame = jetMass.frame(Title("polynomial fit"));
    
    MC_bkg.plotOn(frame);
    poly.plotOn(frame,VisualizeError(*r,RooArgSet(a1,a2),2),FillColor(kOrange));
    poly.plotOn(frame,VisualizeError(*r,1,kFALSE),DrawOption("L"),LineWidth(2),LineColor(kRed)) ;
  

    poly.plotOn(frame) ;
    poly.paramOn(frame);
    

new TCanvas("rf208_convolution2","rf208_convolution2",600,600) ;
    gPad->SetLeftMargin(0.15) ; frame->GetYaxis()->SetTitle("Events"); frame->GetXaxis()->SetTitle("pruned Mass"); hstack->Draw("hist"); 
    frame->Draw("hist same"); PrunedMassT5HH1700Sig->Draw("hist same"); leg->Draw();

    
    // Draw frame on canvas
    
     RooDataHist* MC_bkgMETShapeB = new RooDataHist("MC_bkgMETShapeB","MC_bkgMETShape",RooArgList(*METBins),TotalBkgMETShapeB);
     cout << "************************************ Bkg Integral********************************************************* "<< BkginSR->getVal()*TotalBkg->Integral() << endl ;
     RooRealVar alphaMET("alphaMET", "exponentialMET", 0, -1., 0.1);
     RooExponential expMETB("expMET", "", *METBins, alphaMET);
     RooFitResult*r3=expMETB.fitTo(*MC_bkgMETShapeB, Save());
     RooAbsReal*METBin1SRB=expMETB.createIntegral(*METBins, NormSet(*METBins), Range("METBin1"));
     RooAbsReal*METBin2SRB=expMETB.createIntegral(*METBins, NormSet(*METBins), Range("METBin2"));
     RooAbsReal*METBin3SRB=expMETB.createIntegral(*METBins, NormSet(*METBins), Range("METBin3"));
     RooAbsReal*METBin4SRB=expMETB.createIntegral(*METBins, NormSet(*METBins), Range("METBin4"));
     RooAbsReal*METBin5SRB=expMETB.createIntegral(*METBins, NormSet(*METBins), Range("METBin5"));
     RooAbsReal*METBin6SRB=expMETB.createIntegral(*METBins, NormSet(*METBins), Range("METBin6"));
     
     std::cout<<"MET Bin Fractions "<<METBin1SRB->getVal()<<", "<<METBin2SRB->getVal()<<", "<<METBin3SRB->getVal()<<", "<<METBin4SRB->getVal()<<", "<<METBin5SRB->getVal()<<", "<<METBin6SRB->getVal()<<std::endl;
     std::cout<<"MET Bin Bkg Predictions "<<METBin1SRB->getVal()*BkginSR->getVal()*TotalBkg->Integral() <<", "<<METBin2SRB->getVal()*BkginSR->getVal()*TotalBkg->Integral() <<", "<<METBin3SRB->getVal()*BkginSR->getVal()*TotalBkg->Integral() <<", "<<METBin4SRB->getVal()*BkginSR->getVal()*TotalBkg->Integral()<<METBin5SRB->getVal()*BkginSR->getVal()*TotalBkg->Integral() <<", "<<METBin6SRB->getVal()*BkginSR->getVal()*TotalBkg->Integral() <<std::endl;
     
    RooPlot* frame2 = METBins->frame(Title("polynomial fit"));

    MC_bkgMETShapeB->plotOn(frame2);
    expMETB.plotOn(frame2);
    expMETB.paramOn(frame2);

new TCanvas("rf208_convolution","rf208_convolution",600,600) ;
    gPad->SetLeftMargin(0.15) ; frame2->GetYaxis()->SetTitle("Events"); frame2->GetXaxis()->SetTitle("MET"); hstack2->Draw("hist"); 
    frame2->Draw("hist same"); METT5HH1700Sig->Draw("hist same"); leg->Draw();

*/  
}
