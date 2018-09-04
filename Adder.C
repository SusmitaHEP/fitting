void Adder(){

    TFile* inputFile =new TFile("Histograms.root", "READ");
TH1D*METpassBkg=new TH1D("METpassBkg", "1 parton matched [GeV]", 30,0,300);
    TH1D*METfailBkg=new TH1D("METfailBkg", "more than 1 parton matched [GeV]", 30,0,300);

h_LeadJetprunedMass_QCD_ZZ=(TH1F*)inputFile->Get("h_LeadJetprunedMass_QCD_ZZ");
h_LeadJetprunedMass_TTJets_ZZ=(TH1F*)inputFile->Get("h_LeadJetprunedMass_TTJets_ZZ");
h_LeadJetprunedMass_WJets_ZZ=(TH1F*)inputFile->Get("h_LeadJetprunedMass_WJets_ZZ");
h_LeadJetprunedMass_ZJets_ZZ=(TH1F*)inputFile->Get("h_LeadJetprunedMass_ZJets_ZZ");


h_subLeadJetprunedMass_QCD_ZZ=(TH1F*)inputFile->Get("h_subLeadJetprunedMass_QCD_ZZ");
h_subLeadJetprunedMass_TTJets_ZZ=(TH1F*)inputFile->Get("h_subLeadJetprunedMass_TTJets_ZZ");
h_subLeadJetprunedMass_WJets_ZZ=(TH1F*)inputFile->Get("h_subLeadJetprunedMass_WJets_ZZ");
h_subLeadJetprunedMass_ZJets_ZZ=(TH1F*)inputFile->Get("h_subLeadJetprunedMass_ZJets_ZZ");

THStack*hstack=new THStack("hstack","");
    
    
   h_LeadJetprunedMass_QCD_ZZ ->SetFillColor(kGray);
    h_LeadJetprunedMass_TTJets_ZZ->SetFillColor(kBlue);
    h_LeadJetprunedMass_WJets_ZZ->SetFillColor(kGreen+1);
    h_LeadJetprunedMass_ZJets_ZZ->SetFillColor(kCyan);
    
    leg=new TLegend(0.5488722,0.6825806,0.914787,0.8748387,NULL,"brNDC");
leg->AddEntry(h_LeadJetprunedMass_QCD_ZZ, "QCD ","F");
    leg->AddEntry(h_LeadJetprunedMass_TTJets_ZZ, "TTJets ","F");
      leg->AddEntry(h_LeadJetprunedMass_WJets_ZZ, "W+Jets ","F");
            leg->AddEntry(h_LeadJetprunedMass_ZJets_ZZ, "Z+Jets ","F");
               
                   hstack->Add(h_LeadJetprunedMass_QCD_ZZ);
                      hstack->Add(h_LeadJetprunedMass_TTJets_ZZ);
                          hstack->Add(h_LeadJetprunedMass_WJets_ZZ);
                            hstack->Add(h_LeadJetprunedMass_ZJets_ZZ);
                                  TH1D*TotalBkg=(TH1D*)hstack->GetStack()->Last();
                                     hstack->Draw("hist");
                                            leg->Draw();
                                            

}
