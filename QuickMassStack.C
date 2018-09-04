#ifndef __CINT__
#include "RooGlobalFunc.h"
#endif
#include "RooRealVar.h"
#include "RooDataSet.h"
#include "RooDataHist.h"
#include "RooGaussian.h"
#include "TCanvas.h"
#include "RooPlot.h"
#include "TAxis.h"
#include "TFile.h"
#include "TTree.h"
#include "TLegend.h"
#include "RooFit.h"
using namespace RooFit ;
using namespace std ;
void QuickMassStack(){
//gROOT->ProcessLine(".L tdrstyle.C");
//setTDRStyle();
TFile*finQCD=new TFile("Histograms.root", "READ");
TCanvas* can=new TCanvas("c1","",800,800); can->Divide(1,2);


const float xpad[2] = {0.f,1.f};																						//
const float ypad[4] = {0.,0.2351916,0.2351916,0.98};


 RooRealVar mJ("mJ","mJ",0,300) ;
TH1F*tagSRQCD=(TH1F*)finQCD->Get("h_LeadJetprunedMass_QCD_ZZM31TLM");
TH1F*tagSRZ=(TH1F*)finQCD->Get("h_LeadJetprunedMass_ZJets_ZZM31TLM");
TH1F*tagSRW=(TH1F*)finQCD->Get("h_LeadJetprunedMass_WJets_ZZM31TLM");
TH1F*tagSRT=(TH1F*)finQCD->Get("h_LeadJetprunedMass_TTJets_ZZM31TLM");

	THStack*hstack=new THStack("hstack","");


		tagSRQCD->SetFillColor(kGray);
		tagSRW->SetFillColor(kBlue);
		tagSRZ->SetFillColor(kGreen+1);
		tagSRT->SetFillColor(kCyan);
    leg=new TLegend(0.5488722,0.6825806,0.914787,0.8748387,NULL,"brNDC");
    leg->AddEntry(tagSRQCD, "QCD ","F");
    leg->AddEntry(tagSRT, "TTJets ","F");
    leg->AddEntry(tagSRW, "W+Jets ","F");
    leg->AddEntry(tagSRZ, "Z+Jets ","F");

hstack->Add(tagSRQCD);
hstack->Add(tagSRW);
hstack->Add(tagSRT);
hstack->Add(tagSRZ);
TH1D*TotalBkg=(TH1D*)hstack->GetStack()->Last();


//    TotalBkg->Fit("pol3");
    RooDataHist dhTotal("dhTotal","dhTotal",mJ,Import(*TotalBkg)) ;
    

    //TotalBkg->SumW2Error(kTRUE);
    TotalBkg->Draw("esame");

    RooRealVar meanG("meanG","meanG",80,75,85);  																//
    RooRealVar sigmaG("sigmaG","sigmaG",55,50,70);  
	
    //RooRealVar alpha("alpha", "exponential", 0, -10, 10);
    //RooRealVar mean("mean", "landau", 0, 50, 100);

//    RooPolynomial poly("poly", "", mJ, RooArgList(poly_c1, poly_c2, poly_c3));
    RooDataHist dhTotal("dhTotal","dhTotal",mJ,Import(*TotalBkg)) ;
  //  RooLandau* lau=new RooLandau("lau", "", mJ, mean, alpha);
   RooGaussian poisson("poisson", "",mJ, meanG, sigmaG );

    poisson.fitTo(dhTotal);
  //  lau->fitTo(dhTotal);
   
   
   // TCanvas*c1=new TCanvas("c1", "", 800, 800);

        can->cd(1);																											//
	gPad->SetPad(xpad[0],ypad[2],xpad[1],ypad[3]);
	
	RooPlot* frame = mJ.frame(Title("Imported TH1 with poisson error bars")) ;
	frame->GetYaxis()->SetTitleOffset(1.0);	
	
	double chi2_ndf =  frame->chiSquare("Fit","Data");																	//
	cout<<"/////////////////////////chi square ///////////////////////////////////////="<<chi2_ndf<<endl;
	
	dhTotal.plotOn(frame, DataError(RooAbsData::SumW2)) ;
        poisson.plotOn(frame);																								//
	poisson.paramOn(frame);
	hstack->Draw("hist");	
	frame->Draw("same");
	leg->Draw();																										//
																														//
	can->cd(2);																											//
	gPad->SetPad(xpad[0],ypad[0],xpad[1],ypad[2]);																		//
	RooPlot* z1frame = mJ.frame(Title("Pull"));																			//
	RooHist* hpull1 = frame->pullHist();	
	
	double chi2_ndf =  frame->chiSquare("Fit","Data");																	//
	cout<<"/////////////////////////chi square ///////////////////////////////////////="<<chi2_ndf<<endl;
	
	z1frame->GetYaxis()->SetTitleOffset(0.19); z1frame->GetYaxis()->SetTitleSize(0.16); 								//
	z1frame->GetYaxis()->SetTitle("Pull(#sigma)"); 
																							//
	z1frame->addPlotable(hpull1,"P");
	z1frame->Draw();
	
      //  can->Print("IntegratedMETBins.pdf");
  //  return;
    
    
}
