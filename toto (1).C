#define toto_cxx
#include "toto.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <stdbool.h>


void toto::Loop()
{
//   In a ROOT session, you can do:
//      root> .L toto.C
//      root> toto t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch


double ptf,IASf,A = 0,B = 0,C = 0,D = 0,E=0,F=0,G=0,H=0;		// Compteur de coupure
double A_strict=0, B_strict=0, C_strict=0,D_strict=0,E_strict=0,F_strict=0,G_strict=0,H_strict=0 ;
// Premier critere de selection 		double c_pt = 65  , c_ias = 0.05 , c_beta=1.05;	
// Premier critere de selection 		double c_pt_strict = 65 , c_ias_strict = 0.1 , c_beta_strict=1.15;	
double c_pt = 55  , c_ias = 0.025 , c_beta=1.03;	
double c_pt_strict = 65 , c_ias_strict = 0.05 , c_beta_strict=1.05;				// Critère de coupure
double D_1,D_2,D_3,D_4,D_5;
double MASS=0;
double MASS_2=0; 
double D_1_strict,D_2_strict,D_3_strict,D_4_strict,D_5_strict;
double sigma_D_1, sigma_D_2, sigma_D_3, sigma_D_4 , sigma_D_5 ;
double sigma_D_1_strict, sigma_D_2_strict, sigma_D_3_strict, sigma_D_4_strict , sigma_D_5_strict ;
double E_A , E_B , E_C , E_D , E_E , E_F , E_G , E_H ; 
double E_A_strict , E_B_strict , E_C_strict , E_D_strict , E_E_strict , E_F_strict , E_G_strict , E_H_strict ; 
TString outputfilename="bg.root";
TFile* OutputHisto = new TFile(outputfilename,"RECREATE");

int nbin_p=100 ;
int nbin_ih=100 ;
int nbin_eta=100 ;


TH1D* HSCP_multi = new TH1D("HSCP_multi", "# of HSCP candidates", 11, -0.5,10.5);
TH1D* HSCP_pt = new TH1D("HSCP_pt", "pT",  nbin_p, 55.,1550);
TH1D* HSCP_IH = new TH1D("HSCP_IH", " ( IH )",  nbin_ih , 0 , 8 );
TH1D* HSCP_IAS = new TH1D("HSCP_IAS", " ( IAS ) ", nbin_ih , 0 , 1.2  );
TH1D* HSCP_ETA = new TH1D("HSCP_ETA", "( ETA )", nbin_eta , -8 , 8  );
TH1D* HSCP_PT_LOW = new TH1D("HSCP_PT_LOW", " ( PT LOW ) " , nbin_p , 0 , 100 ) ;
TH1D* HSCP_MUON = new TH1D("HSCP_MUON", " PT MUON " , 100, 0 , 200 ) ;
TH1D* HSCP_PT_hscp0 = new TH1D("HSCP_PT_hscp0" , " PT pour HSCP =0 ", nbin_p , 55 , 1550 );
TH1D* HSCP_PT_hscp1 = new TH1D("HSCP_PT_hscp1" , " PT pour HSCP != 0 ", nbin_p , 55 , 1550 );
TH1D* HSCP_COUNT = new TH1D("HSCP_COUNT" , " # candidat passant les cuts " , 11 , -0.5 , 10.5 );


TH1D* MASS_A_loose = new TH1D("MASS_A_loose" , " Masses des candidats dans la zone A " , 200 , 0 , 2000);
TH1D* MASS_B_loose = new TH1D("MASS_B_loose" , " Masses des candidats dans la zone B " , 200 , 0 , 2000);
TH1D* MASS_C_loose = new TH1D("MASS_C_loose" , " Masses des candidats dans la zone C " , 200 , 0 , 2000);
TH1D* MASS_D_loose = new TH1D("MASS_D_loose" , " Masses des candidats dans la zone D " , 200 , 0 , 2000);
TH1D* MASS_E_loose = new TH1D("MASS_E_loose" , " Masses des candidats dans la zone E " , 200 , 0 , 2000);
TH1D* MASS_F_loose = new TH1D("MASS_F_loose" , " Masses des candidats dans la zone F " , 200 , 0 , 2000);
TH1D* MASS_G_loose = new TH1D("MASS_G_loose" , " Masses des candidats dans la zone G " , 200 , 0 , 2000);
TH1D* MASS_H_loose = new TH1D("MASS_H_loose" , " Masses des candidats dans la zone H " , 200 , 0 , 2000);


TH1D* MASS_A = new TH1D("MASS_A" , " Masses des candidats dans la zone A " , 200 , 0 , 2000);
TH1D* MASS_B = new TH1D("MASS_B" , " Masses des candidats dans la zone B " , 200 , 0 , 2000);
TH1D* MASS_C = new TH1D("MASS_C" , " Masses des candidats dans la zone C " , 200 , 0 , 2000);
TH1D* MASS_D = new TH1D("MASS_D" , " Masses des candidats dans la zone D " , 200 , 0 , 2000);
TH1D* MASS_E = new TH1D("MASS_E" , " Masses des candidats dans la zone E " , 200 , 0 , 2000);
TH1D* MASS_F = new TH1D("MASS_F" , " Masses des candidats dans la zone F " , 200 , 0 , 2000);
TH1D* MASS_G = new TH1D("MASS_G" , " Masses des candidats dans la zone G " , 200 , 0 , 2000);
TH1D* MASS_H = new TH1D("MASS_H" , " Masses des candidats dans la zone H " , 200 , 0 , 2000);


TH2D* HSCP_PT_IH = new TH2D("HSCP_PT_IH", " PT ( IH )",  nbin_ih ,0 , 8 , 50, 55 , 1550 );
TH2D* HSCP_PT_IAS = new TH2D("HSCP_PT_IAS", "PT ( IAS ) ", nbin_ih , 0 , 1.2 ,nbin_p, 50 , 2000 );
TH2D* HSCP_PT_ETA = new TH2D("HSCP_PT_ETA", "PT ( ETA )", nbin_eta , -8 , 8 , nbin_p , 50 ,  2000 );
TH2D* HSCP_PT_MUONINVERSEBETA = new TH2D("HSCP_PT_MUONINVERSEBETA", "PT ( MUONINVERSEBETA )", 100 ,-1, 3 ,nbin_p , 50 , 2000 );
TH2D* HSCP_PTT_PTM = new TH2D("HSCP_PTT_PTM", "PTTracks vs PTMuon", nbin_p , 0 , 1000 , nbin_p , 0 ,  1000 );
TH2D* HSCP_DZONE_PT_IAS = new TH2D("HSCP_DZONE_PT_IAS" , " Pt vs IAS dans la zone de coupure D ", nbin_p , 0 , 2000 , nbin_ih , 0 , 1.2 );
TH2D* DZONE_PT_ETA = new TH2D("DZONE_PT_ETA" , " PT ( ETA ) en zone D ", nbin_p , 0 , 2000 , nbin_eta , -8 , 8 ); 
TH2D* DZONE_PT_ETA_loose = new TH2D("DZONE_PT_ETA_loose" , " PT ( ETA ) en zone D loose ", nbin_p , 0 , 2000 , nbin_eta  , -8 , 8 );
TH2D* MASS_P = new TH2D(" MASS_P " , " Masse ( Impulsion ) " , nbin_p , 0 , 2000 , 200 , 0 , 2000 );
TH2D* BETA_ETA  = new TH2D(" BETA_ETA " , " Inverse beta ( eta  ) " , nbin_eta , -2.1 , 2.1 , nbin_eta , 1 , 5 );
TH2D* PT_ETA_A = new TH2D(" PT_ETA_A " , " PT ( ETA ) A " , nbin_eta , -2.1 , 2.1 , nbin_p , 0 , 2000 ) ;
TH2D* PT_ETA_D = new TH2D(" PT_ETA_D " , " PT ( ETA ) D " , nbin_eta , -2.1 , 2.1 , nbin_p , 0 , 2000 ) ;
TH2D* PT_ETA_E = new TH2D(" PT_ETA_D " , " PT ( ETA ) E " , nbin_eta , -2.1 , 2.1 , nbin_p , 0 , 2000 ) ;
TH2D* PT_ETA_D_CORR = new TH2D(" PT_ETA_D_CORR " , " PT ( ETA ) D CORR " , nbin_eta , -2.1 , 2.1 , nbin_p , 0 , 2000 ) ;


TH1D* COUPURE_A_p = new TH1D("COUPURE_A_p" , " coupure zone A " , nbin_p ,0 , 2000 );
TH1D* COUPURE_B_p = new TH1D("COUPURE_B_p" , " coupure zone B " , nbin_p ,0 , 2000 );
TH1D* COUPURE_C_p = new TH1D("COUPURE_C_p" , " coupure zone C " , nbin_p ,0 , 2000 );
TH1D* COUPURE_D_p = new TH1D("COUPURE_D_p" , " coupure zone D " , nbin_p ,0 , 2000 );
TH1D* COUPURE_E_p = new TH1D("COUPURE_E_p" , " coupure zone E " , nbin_p ,0 , 2000 );
TH1D* COUPURE_F_p = new TH1D("COUPURE_F_p" , " coupure zone F " , nbin_p ,0 , 2000 );
TH1D* COUPURE_G_p = new TH1D("COUPURE_G_p" , " coupure zone G " , nbin_p ,0 , 2000 );
TH1D* COUPURE_H_p = new TH1D("COUPURE_H_p" , " coupure zone H " , nbin_p ,0 , 2000 );

TH1D* COUPURE_A_ih = new TH1D("COUPURE_A_ih" , " coupure zone A " , nbin_ih ,  0 , 8 );
TH1D* COUPURE_B_ih = new TH1D("COUPURE_B_ih" , " coupure zone B " , nbin_ih ,  0 , 8 );
TH1D* COUPURE_C_ih = new TH1D("COUPURE_C_ih" , " coupure zone C " , nbin_ih ,  0 , 8 );
TH1D* COUPURE_D_ih = new TH1D("COUPURE_D_ih" , " coupure zone D " , nbin_ih ,  0 , 8 );
TH1D* COUPURE_E_ih = new TH1D("COUPURE_E_ih" , " coupure zone E " , nbin_ih ,  0 , 8 );
TH1D* COUPURE_F_ih = new TH1D("COUPURE_F_ih" , " coupure zone F " , nbin_ih ,  0 , 8 );
TH1D* COUPURE_G_ih = new TH1D("COUPURE_G_ih" , " coupure zone G " , nbin_ih ,  0 , 8 );
TH1D* COUPURE_H_ih = new TH1D("COUPURE_H_ih" , " coupure zone H " , nbin_ih ,  0 , 8 );

TH1D* COUPURE_A_eta = new TH1D("COUPURE_A_eta" , " coupure zone A " , nbin_eta , -2.1 ,2.1 );
TH1D* COUPURE_B_eta = new TH1D("COUPURE_B_eta" , " coupure zone B " , nbin_eta , -2.1 ,2.1 );
TH1D* COUPURE_C_eta = new TH1D("COUPURE_C_eta" , " coupure zone C " , nbin_eta , -2.1 ,2.1 );
TH1D* COUPURE_D_eta = new TH1D("COUPURE_D_eta" , " coupure zone D " , nbin_eta , -2.1 ,2.1 );
TH1D* COUPURE_E_eta = new TH1D("COUPURE_E_eta" , " coupure zone E " , nbin_eta , -2.1 ,2.1 );
TH1D* COUPURE_F_eta = new TH1D("COUPURE_F_eta" , " coupure zone F " , nbin_eta , -2.1 ,2.1 );
TH1D* COUPURE_G_eta = new TH1D("COUPURE_G_eta" , " coupure zone G " , nbin_eta , -2.1 ,2.1 );
TH1D* COUPURE_H_eta = new TH1D("COUPURE_H_eta" , " coupure zone H " , nbin_eta , -2.1 ,2.1 );

TH1D* COUPURE_A_p_strict = new TH1D("COUPURE_A_p_strict" , " coupure zone A " , nbin_p ,0 , 2000 );
TH1D* COUPURE_B_p_strict = new TH1D("COUPURE_B_p_strict" , " coupure zone B " , nbin_p ,0 , 2000 );
TH1D* COUPURE_C_p_strict = new TH1D("COUPURE_C_p_strict" , " coupure zone C " , nbin_p ,0 , 2000 );
TH1D* COUPURE_D_p_strict = new TH1D("COUPURE_D_p_strict" , " coupure zone D " , nbin_p ,0 , 2000 );
TH1D* COUPURE_E_p_strict = new TH1D("COUPURE_E_p_strict" , " coupure zone E " , nbin_p ,0 , 2000 );
TH1D* COUPURE_F_p_strict = new TH1D("COUPURE_F_p_strict" , " coupure zone F " , nbin_p ,0 , 2000 );
TH1D* COUPURE_G_p_strict = new TH1D("COUPURE_G_p_strict" , " coupure zone G " , nbin_p ,0 , 2000 );
TH1D* COUPURE_H_p_strict = new TH1D("COUPURE_H_p_strict" , " coupure zone H " , nbin_p ,0 , 2000 );

TH1D* COUPURE_A_ih_strict = new TH1D("COUPURE_A_ih_strict" , " coupure zone A " , nbin_ih ,  0 , 8 );
TH1D* COUPURE_B_ih_strict = new TH1D("COUPURE_B_ih_strict" , " coupure zone B " , nbin_ih ,  0 , 8 );
TH1D* COUPURE_C_ih_strict = new TH1D("COUPURE_C_ih_strict" , " coupure zone C " , nbin_ih ,  0 , 8 );
TH1D* COUPURE_D_ih_strict = new TH1D("COUPURE_D_ih_strict" , " coupure zone D " , nbin_ih ,  0 , 8 );
TH1D* COUPURE_E_ih_strict = new TH1D("COUPURE_E_ih_strict" , " coupure zone E " , nbin_ih ,  0 , 8 );
TH1D* COUPURE_F_ih_strict = new TH1D("COUPURE_F_ih_strict" , " coupure zone F " , nbin_ih ,  0 , 8 );
TH1D* COUPURE_G_ih_strict = new TH1D("COUPURE_G_ih_strict" , " coupure zone G " , nbin_ih ,  0 , 8 );
TH1D* COUPURE_H_ih_strict = new TH1D("COUPURE_H_ih_strict" , " coupure zone H " , nbin_ih ,  0 , 8 );

TH1D* COUPURE_A_eta_strict = new TH1D("COUPURE_A_eta_strict" , " coupure zone A " , nbin_eta , -2.1 ,2.1 );
TH1D* COUPURE_B_eta_strict = new TH1D("COUPURE_B_eta_strict" , " coupure zone B " , nbin_eta , -2.1 ,2.1 );
TH1D* COUPURE_C_eta_strict = new TH1D("COUPURE_C_eta_strict" , " coupure zone C " , nbin_eta , -2.1 ,2.1 );
TH1D* COUPURE_D_eta_strict = new TH1D("COUPURE_D_eta_strict" , " coupure zone D " , nbin_eta , -2.1 ,2.1 );
TH1D* COUPURE_E_eta_strict = new TH1D("COUPURE_E_eta_strict" , " coupure zone E " , nbin_eta , -2.1 ,2.1 );
TH1D* COUPURE_F_eta_strict = new TH1D("COUPURE_F_eta_strict" , " coupure zone F " , nbin_eta , -2.1 ,2.1 );
TH1D* COUPURE_G_eta_strict = new TH1D("COUPURE_G_eta_strict" , " coupure zone G " , nbin_eta , -2.1 ,2.1 );
TH1D* COUPURE_H_eta_strict = new TH1D("COUPURE_H_eta_strict" , " coupure zone H " , nbin_eta , -2.1 ,2.1 );

COUPURE_B_p->Sumw2();
COUPURE_B_p_strict->Sumw2();
COUPURE_C_ih->Sumw2();
COUPURE_C_ih_strict->Sumw2();
MASS_D->Sumw2();
MASS_D_loose->Sumw2();
HSCP_DZONE_PT_IAS->Sumw2();
HSCP_MUON->Sumw2();
HSCP_multi->Sumw2();
HSCP_pt->Sumw2();
HSCP_PT_ETA->Sumw2();
HSCP_PT_IH->Sumw2();
HSCP_PT_IAS->Sumw2();
HSCP_PT_MUONINVERSEBETA->Sumw2();
HSCP_IH->Sumw2();
HSCP_IAS->Sumw2();
HSCP_ETA->Sumw2();
HSCP_PT_LOW->Sumw2();
HSCP_PTT_PTM->Sumw2();
HSCP_PT_hscp0->Sumw2();
HSCP_PT_hscp1->Sumw2();
DZONE_PT_ETA->Sumw2();
DZONE_PT_ETA_loose->Sumw2();


// if (fChain == 0) return;
Long64_t nentries = fChain->GetEntriesFast();
Long64_t nbytes = 0, nb = 0;
int compteur=0 ;

for (Long64_t jentry=0; jentry<nentries;jentry++) {
	HSCP_COUNT->Fill(compteur);
	//compteur = 0 ;
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
            HSCP_multi->Fill(nhscp);
      int test ;
      bool choix=1 ; 						// 1=TRACKER+TOF analyse, 0=Tracker only 
      
      for (int ihs=0; ihs<nhscp; ihs++) {
      test = selection(ihs,choix) ;
              if (test==1){
	      compteur+=1;
	      HSCP_MUON->Fill(muon_pt[hscp_track_idx[ihs]]);
	      HSCP_PT_LOW->Fill(track_pt[hscp_track_idx[ihs]]);
              HSCP_pt->Fill(track_pt[hscp_track_idx[ihs]]);
	      
	      HSCP_ETA->Fill(track_eta[hscp_track_idx[ihs]]);
	      HSCP_PT_ETA->Fill(track_eta[hscp_track_idx[ihs]],track_pt[hscp_track_idx[ihs]]);
	      
	      HSCP_PT_IH->Fill(track_ih_ampl_corr[hscp_track_idx[ihs]],track_pt[hscp_track_idx[ihs]]);
	      HSCP_IH->Fill(track_ih_ampl_corr[hscp_track_idx[ihs]]);
	      
	      HSCP_PT_IAS->Fill(track_ias_ampl[hscp_track_idx[ihs]],track_pt[hscp_track_idx[ihs]]);
	      HSCP_IAS->Fill(track_ias_ampl[hscp_track_idx[ihs]]);
	      
	      HSCP_PTT_PTM->Fill(muon_pt[hscp_track_idx[ihs]],track_pt[hscp_track_idx[ihs]]);
	      HSCP_PT_MUONINVERSEBETA->Fill(muon_comb_inversebeta[hscp_track_idx[ihs]],track_pt[hscp_track_idx[ihs]]);
	      
	      BETA_ETA->Fill(track_eta[hscp_track_idx[ihs]] , muon_comb_inversebeta[hscp_track_idx[ihs]] ) ;
	      
	      
	if ((track_pt[hscp_track_idx[ihs]]<c_pt_strict) && (track_ias_ampl[hscp_track_idx[ihs]] < c_ias_strict) && ( muon_comb_inversebeta[hscp_track_idx[ihs]] > c_beta_strict)) {		
		A_strict+=1;
		COUPURE_A_p_strict->Fill(track_p[hscp_track_idx[ihs]]);
		COUPURE_A_ih_strict->Fill(track_ih_ampl_corr[hscp_track_idx[ihs]]);
		COUPURE_A_eta_strict->Fill(track_eta[hscp_track_idx[ihs]]);
		MASS=sqrt((track_p[hscp_track_idx[ihs]]*track_p[hscp_track_idx[ihs]]/2.935)*(track_ih_ampl_corr[hscp_track_idx[ihs]]-3.197) ) ;
		MASS_A->Fill(MASS) ;
		MASS_P->Fill(MASS, track_pt[hscp_track_idx[ihs]] ) ;
		
	}
		
	
	if ((track_pt[hscp_track_idx[ihs]]<c_pt_strict) && (track_ias_ampl[hscp_track_idx[ihs]] >= c_ias_strict) && ( muon_comb_inversebeta[hscp_track_idx[ihs]] > c_beta_strict )){ //IAS ?
		B_strict+=1;
		COUPURE_B_p_strict->Fill(track_p[hscp_track_idx[ihs]]);
		COUPURE_B_ih_strict->Fill(track_ih_ampl_corr[hscp_track_idx[ihs]]);
		COUPURE_B_eta_strict->Fill(track_eta[hscp_track_idx[ihs]]);
		MASS=sqrt((track_p[hscp_track_idx[ihs]]*track_p[hscp_track_idx[ihs]]/2.935)*(track_ih_ampl_corr[hscp_track_idx[ihs]]-3.197) ) ;
		MASS_B->Fill(MASS) ;
		MASS_P->Fill(MASS, track_pt[hscp_track_idx[ihs]] ) ;
	
	}
	
	if ((track_pt[hscp_track_idx[ihs]]>=c_pt_strict) && (track_ias_ampl[hscp_track_idx[ihs]] < c_ias_strict) && (muon_comb_inversebeta[hscp_track_idx[ihs]] > c_beta_strict )){ // IAS ?
		C_strict+=1;
		COUPURE_C_p_strict->Fill(track_p[hscp_track_idx[ihs]]);
		COUPURE_C_ih_strict->Fill(track_ih_ampl_corr[hscp_track_idx[ihs]]);
		COUPURE_C_eta_strict->Fill(track_eta[hscp_track_idx[ihs]]);
		MASS=sqrt((track_p[hscp_track_idx[ihs]]*track_p[hscp_track_idx[ihs]]/2.935)*(track_ih_ampl_corr[hscp_track_idx[ihs]]-3.197) ) ;
		MASS_C->Fill(MASS) ;
		MASS_P->Fill(MASS, track_pt[hscp_track_idx[ihs]] ) ;
	
	}
	if ((track_pt[hscp_track_idx[ihs]]>=c_pt_strict) && (track_ias_ampl[hscp_track_idx[ihs]] >= c_ias_strict) && (muon_comb_inversebeta[hscp_track_idx[ihs]] > c_beta_strict )){ // IAS ?
		D_strict+=1;
		MASS=sqrt((track_p[hscp_track_idx[ihs]]*track_p[hscp_track_idx[ihs]]/2.935)*(track_ih_ampl_corr[hscp_track_idx[ihs]]-3.197) ) ;
		COUPURE_D_p_strict->Fill(track_p[hscp_track_idx[ihs]]);
		COUPURE_D_ih_strict->Fill(track_ih_ampl_corr[hscp_track_idx[ihs]]);
		COUPURE_D_eta_strict->Fill(track_eta[hscp_track_idx[ihs]]);
		HSCP_DZONE_PT_IAS->Fill(track_pt[hscp_track_idx[ihs]] , track_ias_ampl[hscp_track_idx[ihs]]);
		MASS_D->Fill(MASS);
		MASS_P->Fill(MASS, track_pt[hscp_track_idx[ihs]] ) ;
		DZONE_PT_ETA->Fill(track_pt[hscp_track_idx[ihs]] , track_eta[hscp_track_idx[ihs]]);

	
	}
		if ((track_pt[hscp_track_idx[ihs]]<c_pt_strict) && (track_ias_ampl[hscp_track_idx[ihs]] < c_ias_strict) && ( muon_comb_inversebeta[hscp_track_idx[ihs]] <= c_beta_strict)) {		
		E_strict+=1;
		COUPURE_E_p_strict->Fill(track_p[hscp_track_idx[ihs]]);
		COUPURE_E_ih_strict->Fill(track_ih_ampl_corr[hscp_track_idx[ihs]]);
		COUPURE_E_eta_strict->Fill(track_eta[hscp_track_idx[ihs]]);
		MASS=sqrt((track_p[hscp_track_idx[ihs]]*track_p[hscp_track_idx[ihs]]/2.935)*(track_ih_ampl_corr[hscp_track_idx[ihs]]-3.197) ) ;
		MASS_E->Fill(MASS) ;
		MASS_P->Fill(MASS, track_pt[hscp_track_idx[ihs]] ) ;
		
	}
		
	
	if ((track_pt[hscp_track_idx[ihs]]<c_pt_strict) && (track_ias_ampl[hscp_track_idx[ihs]] >= c_ias_strict) && ( muon_comb_inversebeta[hscp_track_idx[ihs]] <= c_beta_strict )){ //IAS ?
		F_strict+=1;
		COUPURE_F_p_strict->Fill(track_p[hscp_track_idx[ihs]]);
		COUPURE_F_ih_strict->Fill(track_ih_ampl_corr[hscp_track_idx[ihs]]);
		COUPURE_F_eta_strict->Fill(track_eta[hscp_track_idx[ihs]]);
		MASS=sqrt((track_p[hscp_track_idx[ihs]]*track_p[hscp_track_idx[ihs]]/2.935)*(track_ih_ampl_corr[hscp_track_idx[ihs]]-3.197) ) ;
		MASS_F->Fill(MASS) ;
		MASS_P->Fill(MASS, track_pt[hscp_track_idx[ihs]] ) ;
	
	}
	
	if ((track_pt[hscp_track_idx[ihs]]>=c_pt_strict) && (track_ias_ampl[hscp_track_idx[ihs]] < c_ias_strict) && (muon_comb_inversebeta[hscp_track_idx[ihs]] <= c_beta_strict )){ // IAS ?
		G_strict+=1;
		COUPURE_G_p_strict->Fill(track_p[hscp_track_idx[ihs]]);
		COUPURE_G_ih_strict->Fill(track_ih_ampl_corr[hscp_track_idx[ihs]]);
		COUPURE_G_eta_strict->Fill(track_eta[hscp_track_idx[ihs]]);
		MASS=sqrt((track_p[hscp_track_idx[ihs]]*track_p[hscp_track_idx[ihs]]/2.935)*(track_ih_ampl_corr[hscp_track_idx[ihs]]-3.197) ) ;
		MASS_G->Fill(MASS) ;
		MASS_P->Fill(MASS, track_pt[hscp_track_idx[ihs]] ) ;
	
	}
	if ((track_pt[hscp_track_idx[ihs]]>=c_pt_strict) && (track_ias_ampl[hscp_track_idx[ihs]] >= c_ias_strict) && (muon_comb_inversebeta[hscp_track_idx[ihs]] <= c_beta_strict )){ 
		H_strict+=1;
		COUPURE_H_p_strict->Fill(track_p[hscp_track_idx[ihs]]);
		COUPURE_H_ih_strict->Fill(track_ih_ampl_corr[hscp_track_idx[ihs]]);
		COUPURE_H_eta_strict->Fill(track_eta[hscp_track_idx[ihs]]);
		MASS=sqrt((track_p[hscp_track_idx[ihs]]*track_p[hscp_track_idx[ihs]]/2.935)*(track_ih_ampl_corr[hscp_track_idx[ihs]]-3.197) ) ;
		MASS_H->Fill(MASS) ;
		MASS_P->Fill(MASS, track_pt[hscp_track_idx[ihs]] ) ;
	
	}
	      
	if ((track_pt[hscp_track_idx[ihs]]<c_pt) && (track_ias_ampl[hscp_track_idx[ihs]] < c_ias) && ( muon_comb_inversebeta[hscp_track_idx[ihs]] > c_beta)) {	
		A+=1;
		COUPURE_A_p->Fill(track_p[hscp_track_idx[ihs]]);
		COUPURE_A_ih->Fill(track_ih_ampl_corr[hscp_track_idx[ihs]]);
		COUPURE_A_eta->Fill(track_eta[hscp_track_idx[ihs]]);
		MASS=sqrt((track_p[hscp_track_idx[ihs]]*track_p[hscp_track_idx[ihs]]/2.935)*(track_ih_ampl_corr[hscp_track_idx[ihs]]-3.197) ) ;
		MASS_A_loose->Fill(MASS) ;
		MASS_P->Fill(MASS, track_pt[hscp_track_idx[ihs]] ) ;
		PT_ETA_A->Fill(track_eta[hscp_track_idx[ihs]],track_pt[hscp_track_idx[ihs]]);
		
	}
		
	
	if ((track_pt[hscp_track_idx[ihs]]<c_pt) && (track_ias_ampl[hscp_track_idx[ihs]] >= c_ias) && ( muon_comb_inversebeta[hscp_track_idx[ihs]] > c_beta )){ //IAS ?
		B+=1;
		COUPURE_B_p->Fill(track_p[hscp_track_idx[ihs]]);
		COUPURE_B_ih->Fill(track_ih_ampl_corr[hscp_track_idx[ihs]]);
		COUPURE_B_eta->Fill(track_eta[hscp_track_idx[ihs]]);
		MASS=sqrt((track_p[hscp_track_idx[ihs]]*track_p[hscp_track_idx[ihs]]/2.935)*(track_ih_ampl_corr[hscp_track_idx[ihs]]-3.197) ) ;
		MASS_B_loose->Fill(MASS) ;
		MASS_P->Fill(MASS, track_pt[hscp_track_idx[ihs]] ) ;
	
	}
	
	if ((track_pt[hscp_track_idx[ihs]]>=c_pt) && (track_ias_ampl[hscp_track_idx[ihs]] < c_ias) && (muon_comb_inversebeta[hscp_track_idx[ihs]] > c_beta )){ // IAS ?
		C+=1;
		COUPURE_C_p->Fill(track_p[hscp_track_idx[ihs]]);
		COUPURE_C_ih->Fill(track_ih_ampl_corr[hscp_track_idx[ihs]]);
		COUPURE_C_eta->Fill(track_eta[hscp_track_idx[ihs]]);
		MASS=sqrt((track_p[hscp_track_idx[ihs]]*track_p[hscp_track_idx[ihs]]/2.935)*(track_ih_ampl_corr[hscp_track_idx[ihs]]-3.197) ) ;
		MASS_C_loose->Fill(MASS) ;
		MASS_P->Fill(MASS, track_pt[hscp_track_idx[ihs]] ) ;
		PT_ETA_D->Fill(track_eta[hscp_track_idx[ihs]],track_pt[hscp_track_idx[ihs]]);
	
	}
	if ((track_pt[hscp_track_idx[ihs]]>=c_pt) && (track_ias_ampl[hscp_track_idx[ihs]] >= c_ias) && (muon_comb_inversebeta[hscp_track_idx[ihs]] > c_beta )){ // IAS ?
		D+=1;
		COUPURE_D_p->Fill(track_p[hscp_track_idx[ihs]]);
		COUPURE_D_ih->Fill(track_ih_ampl_corr[hscp_track_idx[ihs]]);
		COUPURE_D_eta->Fill(track_eta[hscp_track_idx[ihs]]);
		MASS_2=sqrt((track_p[hscp_track_idx[ihs]]*track_p[hscp_track_idx[ihs]]/2.935)*(track_ih_ampl_corr[hscp_track_idx[ihs]]-3.197) ) ;
		MASS_D_loose->Fill(MASS_2);
		DZONE_PT_ETA_loose->Fill(track_pt[hscp_track_idx[ihs]] , track_eta[hscp_track_idx[ihs]]);
		//cout << " P = " << track_p[hscp_track_idx[ihs]] << endl ;
		//cout << " IH = " << track_ih_ampl_corr[hscp_track_idx[ihs]] << endl;
		//cout << " MASS = " << MASS_2 <<endl;
		MASS_P->Fill(MASS_2, track_pt[hscp_track_idx[ihs]] ) ;
	
	}
		if ((track_pt[hscp_track_idx[ihs]]<c_pt) && (track_ias_ampl[hscp_track_idx[ihs]] < c_ias) && ( muon_comb_inversebeta[hscp_track_idx[ihs]] <= c_beta)) {	
		E+=1;
		COUPURE_E_p->Fill(track_p[hscp_track_idx[ihs]]);
		COUPURE_E_ih->Fill(track_ih_ampl_corr[hscp_track_idx[ihs]]);
		COUPURE_E_eta->Fill(track_eta[hscp_track_idx[ihs]]);
		PT_ETA_E->Fill(track_eta[hscp_track_idx[ihs]],track_pt[hscp_track_idx[ihs]]);
		MASS=sqrt((track_p[hscp_track_idx[ihs]]*track_p[hscp_track_idx[ihs]]/2.935)*(track_ih_ampl_corr[hscp_track_idx[ihs]]-3.197) ) ;
		MASS_E_loose->Fill(MASS) ;
		MASS_P->Fill(MASS, track_pt[hscp_track_idx[ihs]] ) ;
		
	}
		
	
	if ((track_pt[hscp_track_idx[ihs]]<c_pt) && (track_ias_ampl[hscp_track_idx[ihs]] >= c_ias) && ( muon_comb_inversebeta[hscp_track_idx[ihs]] <= c_beta )){ //IAS ?
		
		F+=1;
		COUPURE_F_p->Fill(track_p[hscp_track_idx[ihs]]);
		COUPURE_F_ih->Fill(track_ih_ampl_corr[hscp_track_idx[ihs]]);
		COUPURE_F_eta->Fill(track_eta[hscp_track_idx[ihs]]);
		MASS=sqrt((track_p[hscp_track_idx[ihs]]*track_p[hscp_track_idx[ihs]]/2.935)*(track_ih_ampl_corr[hscp_track_idx[ihs]]-3.197) ) ;
		MASS_F_loose->Fill(MASS) ;
		MASS_P->Fill(MASS, track_pt[hscp_track_idx[ihs]] ) ;
	
	}
	
	if ((track_pt[hscp_track_idx[ihs]]>=c_pt) && (track_ias_ampl[hscp_track_idx[ihs]] < c_ias) && (muon_comb_inversebeta[hscp_track_idx[ihs]] <= c_beta )){ // IAS ?
		
		
		G+=1;
		COUPURE_G_p->Fill(track_p[hscp_track_idx[ihs]]);
		COUPURE_G_ih->Fill(track_ih_ampl_corr[hscp_track_idx[ihs]]);
		COUPURE_G_eta->Fill(track_eta[hscp_track_idx[ihs]]);
		MASS=sqrt((track_p[hscp_track_idx[ihs]]*track_p[hscp_track_idx[ihs]]/2.935)*(track_ih_ampl_corr[hscp_track_idx[ihs]]-3.197) ) ;
		MASS_G_loose->Fill(MASS) ;
		MASS_P->Fill(MASS, track_pt[hscp_track_idx[ihs]] ) ;
	
	}
	if ((track_pt[hscp_track_idx[ihs]]>=c_pt) && (track_ias_ampl[hscp_track_idx[ihs]] >= c_ias) && (muon_comb_inversebeta[hscp_track_idx[ihs]] <= c_beta )){ // IAS ?
		
		
		H+=1;
		COUPURE_H_p->Fill(track_p[hscp_track_idx[ihs]]);
		COUPURE_H_ih->Fill(track_ih_ampl_corr[hscp_track_idx[ihs]]);
		COUPURE_H_eta->Fill(track_eta[hscp_track_idx[ihs]]);
		MASS=sqrt((track_p[hscp_track_idx[ihs]]*track_p[hscp_track_idx[ihs]]/2.935)*(track_ih_ampl_corr[hscp_track_idx[ihs]]-3.197) ) ;
		MASS_H->Fill(MASS) ;
		MASS_H_loose->Fill(MASS) ;
		MASS_P->Fill(MASS, track_pt[hscp_track_idx[ihs]] ) ;
	
	}
          }
	  }
	  }
for (int ihd=0; ihd<nhscp; ihd++) {
	if (ihd==0){
		if (hscp_track_idx[ihd]>=0) {
			HSCP_PT_hscp0->Fill(track_pt[hscp_track_idx[ihd]]);
			   		    }
		   }
		if (ihd!=0){
		          if (hscp_track_idx[ihd]>=0) {
				HSCP_PT_hscp1->Fill(track_pt[hscp_track_idx[ihd]]);
							}
		}
}


	  
TH1D* HIST_ETA_A = (TH1D*)COUPURE_A_eta->Clone();
TH1D* HIST_ETA_B = (TH1D*)COUPURE_B_eta->Clone();
TH1D* HIST_ETA_C = (TH1D*)COUPURE_C_eta->Clone();
TH1D* HIST_ETA_D = (TH1D*)COUPURE_D_eta->Clone();
TH1D* HIST_ETA_E = (TH1D*)COUPURE_E_eta->Clone();
TH1D* HIST_ETA_F = (TH1D*)COUPURE_F_eta->Clone();
TH1D* HIST_ETA_G = (TH1D*)COUPURE_G_eta->Clone();
TH1D* HIST_ETA_H = (TH1D*)COUPURE_H_eta->Clone();

HIST_ETA_A->Scale(1/HIST_ETA_A->Integral()) ;
HIST_ETA_B->Scale(1/HIST_ETA_B->Integral()) ;
HIST_ETA_C->Scale(1/HIST_ETA_C->Integral()) ;
HIST_ETA_D->Scale(1/HIST_ETA_D->Integral()) ;
HIST_ETA_E->Scale(1/HIST_ETA_E->Integral()) ;
HIST_ETA_F->Scale(1/HIST_ETA_F->Integral()) ;
HIST_ETA_G->Scale(1/HIST_ETA_G->Integral()) ;
HIST_ETA_H->Scale(1/HIST_ETA_H->Integral()) ;
COUPURE_E_eta->Scale(1/COUPURE_E_eta->Integral());
COUPURE_D_eta->Scale(1/COUPURE_D_eta->Integral());

double weight ;
for ( int j = 1 ; j<= nbin_eta ; j++) {
	weight = ( COUPURE_E_eta->GetBinContent(j)/COUPURE_D_eta->GetBinContent(j))*PT_ETA_D->GetBinContent(j) ;
	PT_ETA_D_CORR->Fill(PT_ETA_D->GetBinCenter(j), weight );
}
TH1D* PT_D_CORR_PROJ = PT_ETA_D_CORR->ProjectionX();

TCanvas* TAB_ETA = new TCanvas("TAB_ETA" , " Superposition ETA " , nbin_eta , nbin_eta );
TAB_ETA->cd();
HIST_ETA_A->Draw("HIST");
HIST_ETA_B->Draw("HIST SAME");
HIST_ETA_C->Draw("HIST SAME");
HIST_ETA_D->Draw("HIST SAME");
HIST_ETA_E->Draw("HIST SAME");
HIST_ETA_F->Draw("HIST SAME");
HIST_ETA_G->Draw("HIST SAME");
HIST_ETA_H->Draw("HIST SAME");

// Calculs des valeurs des critères de coupures
D_1=(C*B/A) ;
D_2=(H*A/E) ;
D_5=(H*B/F) ;
D_3=(A*G*F/(E*E));
D_4=(C*F/(E));

D_1_strict=(C_strict*B_strict/A_strict) ;
D_2_strict=(H_strict*A_strict/E_strict) ;
D_5_strict=(H_strict*B_strict/F_strict) ;
D_3_strict=(A_strict*G_strict*F_strict/(E_strict*E_strict));
D_4_strict=(C_strict*F_strict/(E_strict));

E_A = sqrt(A) ; 
E_B = sqrt(B) ;
E_C = sqrt(C) ;
E_D = sqrt(D) ;
E_E = sqrt(E) ;
E_F = sqrt(F) ;
E_G = sqrt(G) ;
E_H = sqrt(H) ;

E_A_strict = sqrt(A_strict) ; 
E_B_strict = sqrt(B_strict) ;
E_C_strict = sqrt(C_strict) ;
E_D_strict = sqrt(D_strict) ;
E_E_strict = sqrt(E_strict) ;
E_F_strict = sqrt(F_strict) ;
E_G_strict = sqrt(G_strict) ;
E_H_strict = sqrt(H_strict) ;


	  
sigma_D_1=D_1*sqrt((E_A/A)*(E_A/A)+(E_B/B)*(E_B/B)+(E_C/C)*(E_C/C));
sigma_D_2=D_2*sqrt((E_A/A)*(E_A/A)+(E_H/H)*(E_H/H)+(E_E/E)*(E_E/E));
sigma_D_3=D_3*sqrt((E_A/A)*(E_A/A)+(E_G/G)*(E_G/G)+(E_F/F)*(E_F/F)+2*(E_E/E)) ;
sigma_D_4=D_4*sqrt((E_C/C)*(E_C/C)+(E_F/F)*(E_F/F)+(E_E/E)*(E_E/E)) ;
sigma_D_5=D_5*sqrt((E_H/H)*(E_H/H)+(E_B/B)*(E_B/B)+(E_F/F)*(E_F/F)) ;

sigma_D_1_strict=D_1_strict*sqrt((E_A_strict/A_strict)*(E_A_strict/A_strict)+(E_B_strict/B_strict)*(E_B_strict/B_strict)+(E_C_strict/C_strict)*(E_C_strict/C_strict));
sigma_D_2_strict=D_2_strict*sqrt((E_A_strict/A_strict)*(E_A_strict/A_strict)+(E_H_strict/H_strict)*(E_H_strict/H_strict)+(E_E_strict/E_strict)*(E_E_strict/E_strict));
sigma_D_3_strict=D_3_strict*sqrt((E_A_strict/A_strict)*(E_A_strict/A_strict)+(E_G_strict/G_strict)*(E_G_strict/G_strict)+(E_F_strict/F_strict)*(E_F_strict/F_strict)+2*(E_E_strict/E_strict)) ;
sigma_D_4_strict=D_4_strict*sqrt((E_C_strict/C_strict)*(E_C_strict/C_strict)+(E_F_strict/F_strict)*(E_F_strict/F_strict)+(E_E_strict/E_strict)*(E_E_strict/E_strict)) ;
sigma_D_5_strict=D_5_strict*sqrt((E_H_strict/H_strict)*(E_H_strict/H_strict)+(E_B_strict/B_strict)*(E_B_strict/B_strict)+(E_F_strict/F_strict)*(E_F_strict/F)) ;

Double_t Correlation_PTT_PTM=HSCP_PTT_PTM->GetCorrelationFactor();
cout<<" Correlation PTT vs PTM = "<< Correlation_PTT_PTM << " " <<endl ;
Double_t Correlation_PT_MUONINVERSEBETA=HSCP_PT_MUONINVERSEBETA->GetCorrelationFactor();
cout<<" Correlation PT vs Muon Inverse Beta " << Correlation_PT_MUONINVERSEBETA << " " << endl;
Double_t Correlation_PT_IAS=HSCP_PT_IAS->GetCorrelationFactor();
cout<<" Correlation PT vs IAS " << Correlation_PT_IAS << " " <<endl;
Double_t Correlation_PT_IH=HSCP_PT_IH->GetCorrelationFactor();
cout<<" Correlation PT vs IH " << Correlation_PT_IH << " " << endl;
Double_t Correlation_PT_ETA=HSCP_PT_ETA->GetCorrelationFactor();
cout<<" Correlation PT ve ETA " << Correlation_PT_ETA << " " << endl;

OutputHisto->cd();
HSCP_COUNT->Write();
HSCP_multi->Write();
HSCP_pt->Write();
HSCP_PT_ETA->Write();
HSCP_PT_IH->Write();
HSCP_PT_IAS->Write();
HSCP_PT_MUONINVERSEBETA->Write();
HSCP_PT_LOW->Write();
HSCP_IH->Write();
HSCP_IAS->Write();
HSCP_ETA->Write();
HSCP_PTT_PTM->Write();
HSCP_MUON->Write();
HSCP_PT_hscp0->Write();
HSCP_PT_hscp0->Write();
TAB_ETA->Write();


COUPURE_A_p->Write();
COUPURE_B_p->Write();
COUPURE_C_p->Write();
COUPURE_D_p->Write();
COUPURE_E_p->Write();
COUPURE_F_p->Write();
COUPURE_G_p->Write();
COUPURE_H_p->Write();

COUPURE_A_ih->Write();
COUPURE_B_ih->Write();
COUPURE_C_ih->Write();
COUPURE_D_ih->Write();
COUPURE_E_ih->Write();
COUPURE_F_ih->Write();
COUPURE_G_ih->Write();
COUPURE_H_ih->Write();

COUPURE_A_eta->Write();
COUPURE_B_eta->Write();
COUPURE_C_eta->Write();
COUPURE_D_eta->Write();
COUPURE_E_eta->Write();
COUPURE_F_eta->Write();
COUPURE_G_eta->Write();
COUPURE_H_eta->Write();

COUPURE_A_p_strict->Write();
COUPURE_B_p_strict->Write();
COUPURE_C_p_strict->Write();
COUPURE_D_p_strict->Write();
COUPURE_E_p_strict->Write();
COUPURE_F_p_strict->Write();
COUPURE_G_p_strict->Write();
COUPURE_H_p_strict->Write();

COUPURE_A_ih_strict->Write();
COUPURE_B_ih_strict->Write();
COUPURE_C_ih_strict->Write();
COUPURE_D_ih_strict->Write();
COUPURE_E_ih_strict->Write();
COUPURE_F_ih_strict->Write();
COUPURE_G_ih_strict->Write();
COUPURE_H_ih_strict->Write();

COUPURE_A_eta_strict->Write();
COUPURE_B_eta_strict->Write();
COUPURE_C_eta_strict->Write();
COUPURE_D_eta_strict->Write();
COUPURE_E_eta_strict->Write();
COUPURE_F_eta_strict->Write();
COUPURE_G_eta_strict->Write();
COUPURE_H_eta_strict->Write();

MASS_A->Write();
MASS_B->Write();
MASS_C->Write();
MASS_D->Write();
MASS_E->Write();
MASS_F->Write();
MASS_G->Write();
MASS_H->Write();

MASS_A_loose->Write();
MASS_B_loose->Write();
MASS_C_loose->Write();
MASS_D_loose->Write();
MASS_E_loose->Write();
MASS_F_loose->Write();
MASS_G_loose->Write();
MASS_H_loose->Write();

HSCP_DZONE_PT_IAS->Write();
MASS_D->Write();
MASS_D_loose->Write();
DZONE_PT_ETA->Write();
DZONE_PT_ETA_loose->Write();
BETA_ETA->Write ();
MASS_P->Write();
PT_ETA_A->Write();
PT_ETA_E->Write();
PT_ETA_D->Write();
PT_ETA_D_CORR->Write();
PT_D_CORR_PROJ->Write();

//  		************************************* AFFICHAGE ******************************************************
cout<<"   "<<"c_pt"<<" "<<"c_ias"<<" "<<"c_beta"<< endl;
cout<<"E ="<<" 0  "<<" "<<"  0  "<<" "<<"  0   "<< endl;
cout<<"G ="<<" 1  "<<" "<<"  0  "<<" "<<"  0   "<< endl;
cout<<"F ="<<" 0  "<<" "<<"  1  "<<" "<<"  0   "<< endl;
cout<<"H ="<<" 1  "<<" "<<"  1  "<<" "<<"  0   "<< endl;
cout<<"A ="<<" 0  "<<" "<<"  0  "<<" "<<"  1   "<< endl;
cout<<"C ="<<" 1  "<<" "<<"  0  "<<" "<<"  1   "<< endl;
cout<<"B ="<<" 0  "<<" "<<"  1  "<<" "<<"  1   "<< endl;
cout<<"D ="<<" 1  "<<" "<<"  1  "<<" "<<"  1   "<< endl;

cout<<"D_1= " << " C*B / A " << endl ;
cout<<"D_2= " << " H*B / F " << endl ;
cout<<"D_5= " << " H*C / G " << endl ;
cout<<"D_3= " << " A*G*F / E*E "<<endl ;
cout<<"D_4= " << " E*C*B / G*A "<<endl ;

cout << "Nombre candidats = " << compteur << " " << endl; 
cout << " E = " << E << " // " << 100*E/compteur << "% "<<endl;
cout << " G = " << G << " // " << 100*G/compteur << "% "<<endl;
cout << " F = " << F << " // " << 100*F/compteur << "% "<<endl;
cout << " H = " << H << " // " << 100*H/compteur << "% "<<endl;
cout << " A = " << A << " // " << 100*A/compteur << "% "<<endl;
cout << " C = " << C << " // " << 100*C/compteur << "% "<<endl;
cout << " B = " << B << " // " << 100*B/compteur << "% "<<endl;
cout << " D = " << D << " // " << 100*D/compteur << "% "<<endl;
cout << " " << endl;
cout << " E_strict = " << E_strict << " // " << 100*E_strict/compteur << "% "<<endl;
cout << " G_strict = " << G_strict << " // " << 100*G_strict/compteur << "% "<<endl;
cout << " F_strict = " << F_strict << " // " << 100*F_strict/compteur << "% "<<endl;
cout << " H_strict = " << H_strict << " // " << 100*H_strict/compteur << "% "<<endl;
cout << " A_strict = " << A_strict << " // " << 100*A_strict/compteur << "% "<<endl;
cout << " C_strict = " << C_strict << " // " << 100*C_strict/compteur << "% "<<endl;
cout << " B_strict = " << B_strict << " // " << 100*B_strict/compteur << "% "<<endl;
cout << " D_strict = " << D_strict << " // " << 100*D_strict/compteur << "% "<<endl;
cout << " " << endl;
cout << " Estimateur de D " << endl;
cout << " D_1 = " << D_1 << " +- " << sigma_D_1 << " " << endl;
cout << " D_2 = " << D_2 << " +- " << sigma_D_2 << " " << endl;
cout << " D_5 = " << D_5 << " +- " << sigma_D_3 << " " << endl;
cout << " D_3 = " << D_3 << " +- " << sigma_D_4 << " " << endl;
cout << " D_4 = " << D_4 << " +- " << sigma_D_5 << " " << endl;
cout << " " << endl;
cout << " D_1_strict = " << D_1_strict << " +- " << sigma_D_1_strict << " " << endl;
cout << " D_2_strict = " << D_2_strict << " +- " << sigma_D_2_strict << " " << endl;
cout << " D_5_strict = " << D_5_strict << " +- " << sigma_D_3_strict << " " << endl;
cout << " D_3_strict = " << D_3_strict << " +- " << sigma_D_4_strict << " " << endl;
cout << " D_4_strict = " << D_4_strict << " +- " << sigma_D_5_strict << " " << endl;

OutputHisto->Close();
}

void toto::Bruitdefond(int i){
	double ptf,IASf,A = 0,B = 0,C = 0,D = 0;
	
	
	double *pointeur = NULL; //pb pour l'incrémentation
	//A = Poisson(10, essayer avec des valeurs aléatoires en utilisant un rand()%100 par ex
	
	
	//for (i...)
	
	
	if ((track_pt[hscp_track_idx[i]]<65) && (track_ias_ampl[hscp_track_idx[i]] < 0.2)){
		// FILL A
		A+=1;
		
	}
		
	
	if ((track_pt[hscp_track_idx[i]]<65) && (track_ias_ampl[hscp_track_idx[i]] > 0.2)){ //IAS ?
		// FILL B
		B+=1;
	
	}
	
	if ((track_pt[hscp_track_idx[i]]>65) && (track_ias_ampl[hscp_track_idx[i]] < 0.2)){ // IAS ?
		
		// FILL C
		C+=1;
	
	}
	
	/*if ((track_pt[hscp_track_idx[i]]>65) && (track_ias_ampl[hscp_track_idx[i]] > 0.2)){
		
		// FILL D
		D+=1; D = (C * B / A);
	
	}*/
	
}



int toto::selection(int i,bool a)
{
int COMPT=0;
bool SELEC=1 ;
if ( a==1 ) {
	if (hscp_track_idx[i]<0){
	  	SELEC=0; 
	  }
	  if (hscp_muon_idx[i]<0){
	  	SELEC=0;
	  }
	  if (track_pt[hscp_track_idx[i]]<50){
	  	SELEC=0;
	  }
	  if (muon_pt[hscp_track_idx[i]]<50){
	  	SELEC=0;
	  }
	  if (track_eta[hscp_track_idx[i]] > 2.1){
	  	SELEC=0;
	  }
	  if (track_eta[hscp_track_idx[i]] < -2.1){
	  	SELEC=0;
	  }
	  if (track_dz[hscp_track_idx[i]]>0.5){
	  	SELEC=0;
	  }
	  if (track_dxy[hscp_track_idx[i]]>0.5){
	  	SELEC=0;
	  }
	  if (track_chi2[hscp_track_idx[i]]>5){
	  	SELEC=0;
	  }
	  if (track_npixhits[hscp_track_idx[i]]<1){
	  	SELEC=0;
	  }
	  if (track_nhits[hscp_track_idx[i]]<7){
	  	SELEC=0;
	  }
	  if (track_validfraction[hscp_track_idx[i]]<0.8){
	  	SELEC=0;
	  }
	  if((track_pterr[hscp_track_idx[i]]/track_pt[hscp_track_idx[i]])>1){
	  	SELEC=0;
	  }
	 /* if (ndedxhits<5){
	 	SELEC=0;
	  }
	  if (dedx_isstrip[hscp_track_idx[i]]<1){
	  	SELEC=0;
	  }
	  if (hscp_iso2_tk[hscp_track_idx[i]]>50){
	  	SELEC=0;
	   } */ 
	 if ((hscp_iso2_ecal[hscp_track_idx[i]]/track_p[hscp_track_idx[i]])>0.3){
	 	SELEC=0;
	 }
	 if ( muon_comb_inversebeta[hscp_track_idx[i]] < 1   ) {
	 	SELEC=0;
	 }
	 if ( muon_comb_inversebetaerr[hscp_track_idx[i]] >0.15   ) {
	 	SELEC=0;
	 }
	 if (  muon_comb_tofndof[hscp_track_idx[i]]< 7  ) {
	 	SELEC=0;
	 }
}
if ( a==0){
	  if (hscp_track_idx[i]<0){
	  	SELEC=0; 
	  }
	  if (track_pt[hscp_track_idx[i]]<50){
	  	SELEC=0;
	  }
	  if (track_eta[hscp_track_idx[i]] > 2.1){
	  	SELEC=0;
	  }
	  if (track_eta[hscp_track_idx[i]] < -2.1){
	  	SELEC=0;
	  }
	  if (track_dz[hscp_track_idx[i]]>0.5){
	  	SELEC=0;
	  }
	  if (track_dxy[hscp_track_idx[i]]>0.5){
	  	SELEC=0;
	  }
	  if (track_chi2[hscp_track_idx[i]]>5){
	  	SELEC=0;
	  }
	  if (track_npixhits[hscp_track_idx[i]]<1){
	  	SELEC=0;
	  }
	  if (track_nhits[hscp_track_idx[i]]<7){
	  	SELEC=0;
	  }
	  if (track_validfraction[hscp_track_idx[i]]<0.8){
	  	SELEC=0;
	  }
	  if((track_pterr[hscp_track_idx[i]]/track_pt[hscp_track_idx[i]])>1){
	  	SELEC=0;
	  }
	  if ((hscp_iso2_ecal[hscp_track_idx[i]]/track_p[hscp_track_idx[i]])>0.3){
	 	SELEC=0;
	 }

}        
return SELEC ;
}
