void newgraph(){

   TCanvas *c = new TCanvas("c","Graph2DErrors example",0,0,600,600);
  // Double_t P = 6.;

Double_t  m[12]={375,375,525,525,700,700,900,900,1100,1100,1350,1350};
Double_t  mean[12]={0.45,0.45,0.47,0.47,0.44,0.44,0.38,0.38,0.46,0.46,0.21,0.21};

Double_t  em[12]={1,1,1,1,1,1,1,1,1,1,1,1};
Double_t  emean[12]={0.02,0.02,0.03,0.03,0.04,0.04,0.10,0.10,0.27,0.27,0.94,0.94};






TGraphErrors *gr = new TGraphErrors(12, m, mean, em, emean);
 gr->SetTitle("TGraphErrors Example");
   gr->SetMarkerColor(4);
   gr->SetMarkerStyle(21);
   gr->Draw("ALP");
   c->Update();




}
