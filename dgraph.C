void dgraph(){

   TCanvas *c = new TCanvas("c","Graph2DErrors example",0,0,600,600);
   Double_t P = 6.;

   Double_t *m=0, *t=0, *mean=0;
   Double_t *em=0, *et=0, *emean=0;
   m = new Double_t[np];
   t = new Double_t[np];
   mean = new Double_t[np];
   em = new Double_t[np];
   et = new Double_t[np];
   emean = new Double_t[np];

  m[6]={300,450,600,800,1000,1200};
  t[6]={0.3,0.3,0.3,0.8,0.8,0.8};
  mean[6]={0.45,0.47,0.344,0.338,0.46,0.21};

  em[6]={15,15,15,15,15,15,50,50};
  t[6]={0.3,0.3,0.3,0.2,0.2,0.2};
  emean[6]={0.02,0.03,0.04,0.10,0.26,0.93};






TGraph2DErrors *dte = new TGraph2DErrors(6, m, t, mean, em, et, emean);
   dte->SetTitle("TGraph2D with error bars: option \"ERR\"");
   dte->SetFillColor(29);
   dte->SetMarkerSize(0.8);
   dte->SetMarkerStyle(20);
   dte->SetMarkerColor(kRed);
   dte->SetLineColor(kBlue-3);
   dte->SetLineWidth(2);
   dte->Draw("err p0");
   gPad->SetLogy(1);
   return c;





}

