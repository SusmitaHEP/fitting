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
void PullSig1300()
{
    //gROOT->ProcessLine(".L tdrstyle.C");
    //gROOT->ProcessLine("setTDRStyle()");
  
  TFile* inputFile =new TFile("SkimFileMass_PrunedMass.root", "READ");
    //BKg Shapes:
  OtherTree=(TTree*)inputFile->Get("Other");
  ZJetsTree=(TTree*)inputFile->Get("ZJets");
  WJetsTree=(TTree*)inputFile->Get("WJets");
  SnglTTree=(TTree*)inputFile->Get("SnglT");
  TTBarTTree=(TTree*)inputFile->Get("TT");
  QCDTree=(TTree*)inputFile->Get("QCD");
  T5HH1300Tree=(TTree*)inputFile->Get("T5HH1300");
  T5HH1700Tree=(TTree*)inputFile->Get("T5HH1700");
  T5HH1100Tree=(TTree*)inputFile->Get("T5HH1100");
  T5HH1200Tree=(TTree*)inputFile->Get("T5HH1200");
  T5HH1400Tree=(TTree*)inputFile->Get("T5HH1400");
  T5HH1500Tree=(TTree*)inputFile->Get("T5HH1500");
  T5HH1600Tree=(TTree*)inputFile->Get("T5HH1600");
  T5HH1800Tree=(TTree*)inputFile->Get("T5HH1800");
  T5HH1900Tree=(TTree*)inputFile->Get("T5HH1900");
  T5HH2000Tree=(TTree*)inputFile->Get("T5HH2000");
  T5HH2100Tree=(TTree*)inputFile->Get("T5HH2100");
  T5HH1000Tree=(TTree*)inputFile->Get("T5HH1000");
 
  TH1D*PrunedMassZBkg=new TH1D("PrunedMassZBkg", "Pruned Mass [GeV]", 30,50.,200.);
  TH1D*PrunedMassWBkg=new TH1D("PrunedMassWBkg", "Pruned Mass [GeV]", 30,50.,200.);
  TH1D*PrunedMassTTBarBkg=new TH1D("PrunedMassTTBarBkg", "Pruned Mass [GeV]", 30,50.,200.);
  TH1D*PrunedMassQCDBkg=new TH1D("PrunedMassQCDBkg", "Pruned Mass [GeV]", 30,50.,200.);
  TH1D*PrunedMassT5HH1300Sig=new TH1D("PrunedMassT5HH1300Sig", "Pruned Mass [GeV]", 30,50.,200.);
  TH1D*PrunedMassT5HH1700Sig=new TH1D("PrunedMassT5HH1700Sig", "Pruned Mass [GeV]", 30,50.,200.);
  TH1D*PrunedMassT5HH1000Sig=new TH1D("PrunedMassT5HH1000Sig", "Pruned Mass [GeV]", 30,50.,200.);
  TH1D*PrunedMassT5HH1100Sig=new TH1D("PrunedMassT5HH1100Sig", "Pruned Mass [GeV]", 30,50.,200.);
  TH1D*PrunedMassT5HH1200Sig=new TH1D("PrunedMassT5HH1200Sig", "Pruned Mass [GeV]", 30,50.,200.);
  TH1D*PrunedMassT5HH1400Sig=new TH1D("PrunedMassT5HH1400Sig", "Pruned Mass [GeV]", 30,50.,200.);
  TH1D*PrunedMassT5HH1500Sig=new TH1D("PrunedMassT5HH1500Sig", "Pruned Mass [GeV]", 30,50.,200.);
  TH1D*PrunedMassT5HH1600Sig=new TH1D("PrunedMassT5HH1600Sig", "Pruned Mass [GeV]", 30,50.,200.);
  TH1D*PrunedMassT5HH1800Sig=new TH1D("PrunedMassT5HH1800Sig", "Pruned Mass [GeV]", 30,50.,200.);
  TH1D*PrunedMassT5HH1900Sig=new TH1D("PrunedMassT5HH1900Sig", "Pruned Mass [GeV]", 30,50.,200.);
  TH1D*PrunedMassT5HH2000Sig=new TH1D("PrunedMassT5HH2000Sig", "Pruned Mass [GeV]", 30,50.,200.);
  TH1D*PrunedMassT5HH2100Sig=new TH1D("PrunedMassT5HH2100Sig", "Pruned Mass [GeV]", 30,50.,200.);
  PrunedMassQCDBkg->Sumw2(kTRUE);
  PrunedMassWBkg->Sumw2(kTRUE);
  PrunedMassZBkg->Sumw2(kTRUE);
  PrunedMassTTBarBkg->Sumw2(kTRUE);
  PrunedMassT5HH1000Sig->Sumw2(kTRUE);
  PrunedMassT5HH1100Sig->Sumw2(kTRUE);
  PrunedMassT5HH1200Sig->Sumw2(kTRUE);
  PrunedMassT5HH1300Sig->Sumw2(kTRUE);
  PrunedMassT5HH1400Sig->Sumw2(kTRUE);
  PrunedMassT5HH1500Sig->Sumw2(kTRUE);
  PrunedMassT5HH1600Sig->Sumw2(kTRUE);
  PrunedMassT5HH1700Sig->Sumw2(kTRUE);
  PrunedMassT5HH1800Sig->Sumw2(kTRUE);
  PrunedMassT5HH1900Sig->Sumw2(kTRUE);
  PrunedMassT5HH2000Sig->Sumw2(kTRUE);
  PrunedMassT5HH2100Sig->Sumw2(kTRUE);
  
 ZJetsTree->Draw("PrunedMass1>>PrunedMassZBkg", "(MET>300 && HT>370 && JetPt1>200 && JetPt2>170 && PrunedMass1>40 && PrunedMass1<200 && PrunedMass2>70 && PrunedMass2<100)*Evtweight*(80/35.9)");
  WJetsTree->Draw("PrunedMass1>>PrunedMassWBkg", "(MET>300 && HT>370 && JetPt1>200 && JetPt2>170 && PrunedMass1>40 && PrunedMass1<200 && PrunedMass2>70 && PrunedMass2<100)*Evtweight*(80/35.9)");
  TTBarTTree->Draw("PrunedMass1>>PrunedMassTTBarBkg","(MET>300 && HT>370 && JetPt1>200 && JetPt2>170 && PrunedMass1>40 && PrunedMass1<200 && PrunedMass2>70 && PrunedMass2<100)*Evtweight*(80/35.9)");
  QCDTree->Draw("PrunedMass1>>PrunedMassQCDBkg", "(MET>300 && HT>370 && JetPt1>200 && JetPt2>170 && PrunedMass1>40 && PrunedMass1<200 && PrunedMass2>70 && PrunedMass2<100)*Evtweight*(80/35.9)");
  T5HH1300Tree->Draw("PrunedMass1>>PrunedMassT5HH1300Sig", "(MET>300 && HT>370 && JetPt1>200 && JetPt2>170 && PrunedMass1>40 && PrunedMass1<200 && PrunedMass2>70 && PrunedMass2<100)*Evtweight*(80/35.9)");
  T5HH1700Tree->Draw("PrunedMass1>>PrunedMassT5HH1700Sig", "(MET>300 && HT>370 && JetPt1>200 && JetPt2>170 && PrunedMass1>40 && PrunedMass1<200 && PrunedMass2>70 && PrunedMass2<100)*Evtweight*(80/35.9)");
  T5HH1000Tree->Draw("PrunedMass1>>PrunedMassT5HH1000Sig", "(MET>300 && HT>370 && JetPt1>200 && JetPt2>170 && PrunedMass1>40 && PrunedMass1<200 && PrunedMass2>70 && PrunedMass2<100)*Evtweight*(80/35.9)");
  T5HH1100Tree->Draw("PrunedMass1>>PrunedMassT5HH1100Sig", "(MET>300 && HT>370 && JetPt1>200 && JetPt2>170 && PrunedMass1>40 && PrunedMass1<200 && PrunedMass2>70 && PrunedMass2<100)*Evtweight*(80/35.9)");
  T5HH1200Tree->Draw("PrunedMass1>>PrunedMassT5HH1200Sig", "(MET>300 && HT>370 && JetPt1>200 && JetPt2>170 && PrunedMass1>40 && PrunedMass1<200 && PrunedMass2>70 && PrunedMass2<100)*Evtweight*(80/35.9)");
  T5HH1400Tree->Draw("PrunedMass1>>PrunedMassT5HH1400Sig", "(MET>300 && HT>370 && JetPt1>200 && JetPt2>170 && PrunedMass1>40 && PrunedMass1<200 && PrunedMass2>70 && PrunedMass2<100)*Evtweight*(80/35.9)");
  T5HH1500Tree->Draw("PrunedMass1>>PrunedMassT5HH1500Sig", "(MET>300 && HT>370 && JetPt1>200 && JetPt2>170 && PrunedMass1>40 && PrunedMass1<200 && PrunedMass2>70 && PrunedMass2<100)*Evtweight*(80/35.9)");
  T5HH1600Tree->Draw("PrunedMass1>>PrunedMassT5HH1600Sig", "(MET>300 && HT>370 && JetPt1>200 && JetPt2>170 && PrunedMass1>40 && PrunedMass1<200 && PrunedMass2>70 && PrunedMass2<100)*Evtweight*(80/35.9)");
  T5HH1800Tree->Draw("PrunedMass1>>PrunedMassT5HH1800Sig", "(MET>300 && HT>370 && JetPt1>200 && JetPt2>170 && PrunedMass1>40 && PrunedMass1<200 && PrunedMass2>70 && PrunedMass2<100)*Evtweight*(80/35.9)");
  T5HH1900Tree->Draw("PrunedMass1>>PrunedMassT5HH1900Sig", "(MET>300 && HT>370 && JetPt1>200 && JetPt2>170 && PrunedMass1>40 && PrunedMass1<200 && PrunedMass2>70 && PrunedMass2<100)*Evtweight*(80/35.9)");
  T5HH2000Tree->Draw("PrunedMass1>>PrunedMassT5HH2000Sig", "(MET>300 && HT>370 && JetPt1>200 && JetPt2>170 && PrunedMass1>40 && PrunedMass1<200 && PrunedMass2>70 && PrunedMass2<100)*Evtweight*(80/35.9)");
  T5HH2100Tree->Draw("PrunedMass1>>PrunedMassT5HH2100Sig", "(MET>300 && HT>370 && JetPt1>200 && JetPt2>170 && PrunedMass1>40 && PrunedMass1<200 && PrunedMass2>70 && PrunedMass2<100)*Evtweight*(80/35.9)");
  
  THStack*hstack=new THStack("hstack","");
  PrunedMassQCDBkg->SetFillColor(kMagenta+1);
  PrunedMassWBkg->SetFillColor(kBlue+1);
  PrunedMassZBkg->SetFillColor(kGreen+1);
  PrunedMassTTBarBkg->SetFillColor(kCyan+1);
  PrunedMassT5HH1300Sig->SetLineColor(kBlack+1);
  //PrunedMassT5HH1700Sig->SetLineColor(kYellow+1);
  
  TLegend *leg=new TLegend(0.5488722,0.6825806,0.914787,0.8748387,NULL,"brNDC");
  leg->AddEntry(PrunedMassQCDBkg, "QCD ","F");
  leg->AddEntry(PrunedMassTTBarBkg, "TTJets ","F");
  leg->AddEntry(PrunedMassWBkg, "W+Jets ","F");
  leg->AddEntry(PrunedMassZBkg, "Z+Jets ","F");
  leg->AddEntry(PrunedMassT5HH1300Sig, "T5ZZ1300 ","L");
  
  hstack->Add(PrunedMassQCDBkg);
  hstack->Add(PrunedMassTTBarBkg);
  hstack->Add(PrunedMassWBkg);
  hstack->Add(PrunedMassZBkg);
  TH1D*TotalBkg=(TH1D*)hstack->GetStack()->Last();
  
  RooRealVar jetMass("jetMass","Pruned Jet Mass [GeV]",50.,200.);
  jetMass.setRange("Signal",70., 100.);
  jetMass.setRange("Sideband1",50., 70.);
  jetMass.setRange("Sideband2",100., 200.);
  
  RooDataHist MC_bkg("MC_bkg","MC_bkg",jetMass,Import(*TotalBkg));
  RooDataHist MC_sig("MC_sig","MC_sig",jetMass,Import(*PrunedMassT5HH1300Sig));
  // RooRealVar a1("a1","a1",0.0,-100.,100.);
  // RooRealVar a2("a2","a2",0.0,-100.,100.);
  //  RooRealVar a3("a3","a3",0.0,-100.,100.);
  // RooRealVar a4("a4","a4",0.0,-100.,100.);
  
  RooRealVar a1("a1","a1",-1.037);
  RooRealVar a2("a2","a2",0.222);
  RooChebychev bkg("bkg", "", jetMass, RooArgList(a1,a2));
  RooFitResult *r =  bkg.fitTo(MC_bkg,Range("Sideband1,Sideband2"),Save());
  //integral of mass in signal region:
  // RooAbsReal*BkginSR=bkg.createIntegral(jetMass, NormSet(jetMass), Range("Signal"));
  
  /* RooRealVar mean("mean","mean",90.,50.,200.);
     RooRealVar sigma("sigma","sigma",5.,0.,50.);
     RooRealVar width("width","width",15.,0.,50.);*/
  RooRealVar mean("mean","mean",84.80);
  RooRealVar sigma("sigma","sigma",5.);
  RooRealVar width("width","width",8.8 );
  RooVoigtian voigt("voigt","voigt",jetMass,mean,width,sigma);
  //RooRealVar s1("s1","a1",0.,-50.,50.);
  
  RooRealVar s1("s1","s1",-0.411);
  RooChebychev cheby1sig("cheby1sig","Polynomial part", jetMass, RooArgList(s1));
  RooRealVar cheby1sigfrac("polyfrac","fraction of chebhchev",0.123);
   // RooRealVar cheby1sigfrac("polyfrac","fraction of chebhchev",0.5,0.,1.0);
  RooAddPdf sig ("sig","signal",RooArgList(cheby1sig,voigt),cheby1sigfrac);
  sig.fitTo(MC_sig);

  //integral of mass in signal region:
  RooPlot* frame = jetMass.frame();
  MC_bkg.plotOn(frame);
  bkg.plotOn(frame) ;
  bkg.paramOn(frame);
  MC_sig.plotOn(frame);
  sig.plotOn(frame,LineColor(kYellow));
  // sig.plotOn(frame,Components(voigt),LineColor(kRed));
  // sig.plotOn(frame,Components(cheby1sig),LineColor(kOrange));
  sig.paramOn(frame,LineColor(kBlue));

  new TCanvas("massfitting","massfitting",600,600) ;
  gPad->SetLeftMargin(0.15) ;
  hstack->Draw("hist");
  frame->GetYaxis()->SetTitle("Events");
  frame->GetXaxis()->SetTitle("LeadPrunedJetMass[GeV]");
  frame->GetYaxis()->SetRange(0,80);
  hstack->Draw("hist");
  frame->Draw("hist same");
  // PrunedMassT5HH1700Sig->Draw("hist same");
  // frame->SetMinimum(45000);
  //  frame->SetMaximum(70000);
  leg->Draw();
  MC_bkg.add(MC_sig);
  RooPlot *xframe = jetMass.frame();
  MC_bkg.plotOn(xframe) ; 

  RooRealVar nsig("nsig","number of signal events",300.,0.,10000.) ;
  RooRealVar nbkg("nbkg","number of background events",1000.,0.,10000.) ;
  RooExtendPdf esig("esig","extended signal p.d.f",sig,nsig) ;
  RooExtendPdf ebkg("ebkg","extended background p.d.f",bkg,nbkg) ;
  // Construct sum of two extended p.d.f. (no coefficients required)
  RooAddPdf  model("model","(g1+g2)+a",RooArgList(ebkg,esig)) ;
  RooFitResult* r1 = model.fitTo(MC_bkg,Extended(kTRUE),Save());
  model.plotOn(xframe,LineColor(kRed));
   
  model.plotOn(xframe,Components(ebkg),LineColor(kOrange),LineStyle(kDashed));
  model.paramOn(xframe,LineColor(kRed));
  // bkg.plotOn(xframe,LineColor(kOrange),LineStyle(kDashed));
  // bkg.paramOn(xframe);
  // sig.plotOn(xframe);
  // sig.paramOn(xframe);
  new TCanvas("c4","c4",600,600) ;
  hstack->Draw("hist");
  /*  leg1=new TLegend(0.5488722,0.6825806,0.914787,0.8748387,NULL,"brNDC");
      leg1->AddEntry(model, "Fit ","F");
      leg1->AddEntry(PrunedMassTTBarBkg, "TTJets ","F");*/
  xframe->GetXaxis()->SetTitle("LeadJetPrunedMass[GeV]");
  xframe->Draw("hist same");
  leg->Draw();
  RooMCStudy* mcs = new RooMCStudy(model,jetMass,Binned(kTRUE),Silence(),Extended(),FitOptions(Save(kTRUE),PrintEvalErrors(0)));
  mcs->generateAndFit(1000,0,kTRUE);
  RooDataSet* toySample = (RooDataSet*)mcs->genData(105);
  
  RooRealVar Mmean("Mmean","mean",90.,50.,200.);
  RooRealVar Msigma("Msigma","sigma",5.,0.,50.);
  RooRealVar Mwidth("Mwidth","width",15.,0.,50.);
  RooVoigtian Mvoigt("Mvoigt","voigt",jetMass,Mmean,Mwidth,Msigma);
  RooRealVar lambda("lambda", "slope", -0.1, -5., 0.);
  RooExponential expo("expo", "exponential PDF", jetMass, lambda);
  RooRealVar expofrac("expofrac","fraction of expo",0.5,0.,1.);
  
  RooAddPdf Mfinal ("Mfinal","signal",RooArgList(expo,Mvoigt),expofrac);
  RooPlot* frame0 = jetMass.frame();
 
  Mfinal.fitTo(*toySample);
 
  toySample->plotOn(frame0);
  Mfinal.plotOn(frame0);
  Mfinal.plotOn(frame0,Components(expo),LineColor(kRed),LineStyle(kDashed));
  // sig.plotOn(frame,Components(cheby1sig),LineColor(kOrange));
   Mfinal.paramOn(frame0,LineColor(kBlue));

   RooNLLVar nll("nll","nll",Mfinal,*toySample) ;
   RooPlot* frame5 = jetMass.frame();//Title("-log(L) scan vs m0, problematic regions masked"));
   nll.plotOn(frame5);//PrintEvalErrors(-1),ShiftToZero(),EvalErrorValue(nll.getVal()+10),LineColor(kRed));
  
  TH1* h_nsig = mcs->fitParDataSet().createHistogram("nsig") ;
  TH1* h_nbkg = mcs->fitParDataSet().createHistogram("nbkg") ;
  RooPlot* frame1  = mcs->plotParam(nsig) ;
  frame1->SetTitle("Distribution of fitted nsig values") ;
  RooPlot* frame2 = mcs->plotPull(nsig,FitGauss()) ;
  RooPlot* frame3  = mcs->plotParam(nbkg);
  frame3->SetTitle("Distribution of fitted nbkg values") ;
  RooPlot* frame4 = mcs->plotPull(nbkg,FitGauss()) ;
 

  TCanvas* c3 = new TCanvas("SignalPull","Pull distribution of nsig",1200,400);
  c3->Divide(3) ;
  c3->cd(1) ; gPad->SetLeftMargin(0.15) ; h_nsig->GetYaxis()->SetTitleOffset(1.6) ; h_nsig->Draw() ;
  c3->cd(2) ; gPad->SetLeftMargin(0.15) ; frame1->GetYaxis()->SetTitleOffset(1.4) ; frame1->Draw() ;
  c3->cd(3) ; gPad->SetLeftMargin(0.15) ; frame2->GetYaxis()->SetTitleOffset(1.4) ; frame2->Draw() ;
  
  TCanvas* c4 = new TCanvas("BkgPull","Pull distribution of nbkg",1200,400);
  c4->Divide(3) ;
  c4->cd(1) ; gPad->SetLeftMargin(0.15) ; h_nbkg->GetYaxis()->SetTitleOffset(1.6) ; h_nbkg->Draw() ;
  c4->cd(2) ; gPad->SetLeftMargin(0.15) ; frame3->GetYaxis()->SetTitleOffset(1.4) ; frame3->Draw() ;
  c4->cd(3) ; gPad->SetLeftMargin(0.15) ; frame4->GetYaxis()->SetTitleOffset(1.4) ; frame4->Draw() ;
  TCanvas* c6 = new TCanvas("ToySample Generation","ToySample Generation",1200,400);
  c6->Divide(1);
  c6->cd(1) ; gPad->SetLeftMargin(0.15) ; frame0->GetYaxis()->SetTitleOffset(1.4) ; frame0->Draw() ;

  

}
     
    
   
   
    

