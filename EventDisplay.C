// Code used to explore ONE TTree produced from the binary file
// this code takes the events which are defined as signal from the root ttree and it investigates them. 


#include <TROOT.h>
#include <TH2D.h>
#include <TH1D.h>
#include <TMath.h>
#include <TRandom.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <TFile.h>
#include <cmath>
#include <chrono>


using namespace std::chrono;
using namespace std;



double ConvertToPhot(double Neg_Amplitude, double dt){
  double const R(50.), gain(1e7), e_ch(1.6e-19), qe(0.25), col_eff(0.8);//gain = 1e7 for 1650V (Hamamtsu R6427)
  return Neg_Amplitude * (-dt) /(R* gain *e_ch*qe*col_eff);
}



void PlotMultiWF(std::vector<TH1*> hist ,const char * file_name){

  TCanvas *c1 = new TCanvas("c1","sub data",200,10,700,500);


  string first = std::string(file_name)+std::string("(");
  string last =std::string(file_name) +std::string(")");
  string mid = std::string(file_name);



  for (int i(0); i < hist.size(); i++){
    //char first = file_name.c_str+"(";
    //char last = file_name.c_str+")";
    if (i==0) {
      hist[i]->Draw();
      c1->Print(first.c_str(),"pdf0");
    }else if (i == hist.size() -1 ){
      hist[i]->Draw();
      c1->Print(last.c_str(),"pdf2");
    }else{
      hist[i]->Draw();
      c1->Print(file_name,"pdf1");
    }
  }
}

//------------------
//main
//------------------

void EventDisplay(const string file_name = "/home/amarinei/Year1_PhD/TPC/ELPaper2/results/C4500_LSF2450_ThGUp2150_ThGDnGND_PMesh0_TPC1650_p2_0/WF_output_50_4.0RMS.root", string type = "Signal",int evt = 0){

  gROOT->SetBatch();
  gROOT->SetStyle("Plain");
  //  bool SaveWFPlot = true; 

  std::vector<double> key_idx;
  std::vector<double> key_Intg;
  std::vector<double> key_min_a;

  std::vector<TString> path_store;

  //enter the name of the file you want to investigate
  // TFile * file_store = TFile::Open("/srv/beegfs/scratch/users/a/amarinei/Swan_TTrees/Configuration_P25/Batch_2/NegScan/WFSumInvestigationC4500_LSF2450_ThGUp2150_ThGDnGND_PMesh0_TPC1650_p2_0/WF_output_5000_4.0RMS.root");
  TFile * file_store = TFile::Open(file_name.c_str()); 
       
  auto tree = file_store->Get<TTree>("T");
  TH1D *h1 =  new TH1D("h1","", 100000, -20,80);
  double dt = 1e-9;

  std::vector<double> *wf = new std::vector<double>;
  std::vector<double> *rms = new std::vector<double>;
  int Signal(0), Empty(0);
  std::vector<int> Signal_idx;
  std::vector<int> Empty_idx;
  double intg_a(0);
  std::vector<int> *min_cts_a = new std::vector<int>;
  TString NSigmas_st = "4.0";
  double NSigmas = 4.0;
  // Double_t dt, t0(-20);
  int trig_idx, nentries;

  tree->SetBranchAddress("WF", &wf);
  tree->SetBranchAddress("RMS", &rms);
  tree->SetBranchAddress("Signal", &Signal);
  tree->SetBranchAddress("Empty", &Empty);
  tree->SetBranchAddress("min_counts_inDrift", &min_cts_a);
  // tree->SetBranchAddress("t0", &tree);
  tree->SetBranchAddress("trig_idx", &trig_idx);
  tree->SetBranchAddress("nentries", &nentries);


  tree->GetEntry(evt);
  
  evt = Signal;
  if (type == "Empty")  {
    evt = Empty;
    cout << " Empty event " << evt << endl;
  } 
  else {
    evt = Signal;
  } 

  tree->GetEntry(evt);

  for (int j(0); j < wf->size(); j++){
    h1->SetBinContent(j+1, wf->at(j));
  }  

  
  TCanvas *wtf = new TCanvas("wf", "waveform", 0, 0, 800, 600);
  h1->SetTitle(Form("Evt %d | %.02f * rms | intg_a = %f , min cts = %zu",evt, NSigmas, intg_a, min_cts_a->size())); 
  h1->GetYaxis()->SetTitleOffset(1.1);
  h1->Draw();

  if ( type == "Signal" )      wtf->SaveAs(Form("Pdfs/Signal/evt_%d.pdf", Signal));
  if ( type == "Empty" )      wtf->SaveAs(Form("Pdfs/Empty/evt_%d.pdf", Empty));
  // wtf->SaveAs("test.pdf");      
          

}

