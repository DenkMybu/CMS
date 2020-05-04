#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <stdbool.h>
#include <vector>
#include <iostream>
#include <vector>
#include <math.h> 
#include <TRandom.h>


int main(){

	double a=0.096,b=65,mmax=2000, mmin = 0 ,C = 3.197, K = 2.935;
	int totalA = 0,totalB=0,totalC=0,totalD=0;
	double m,p,ih,weight,p_weight, exemple_P,exemple_IH,weight_poisson;
	
TString outputfilename="result.root" ;
TFile* OutputHisto = new TFile(outputfilename, "RECREATE");


TFile *myFile = new TFile("DONNEES_DY_10MARS.root");


TH1D* HIST_P=(TH1D*)gROOT->FindObject("COUPURE_G_p");
TH1D* HIST_IH=(TH1D*)gROOT->FindObject("COUPURE_F_ih");
TH1D* HIST_MASS_a=(TH1D*)gROOT->FindObject("COUPURE_A_p");
TH1D* HIST_MASS_e=(TH1D*)gROOT->FindObject("COUPURE_E_p");
TH1D* HIST_D_P=(TH1D*)gROOT->FindObject("COUPURE_D_p");
TH1D* HIST_D_IH=(TH1D*)gROOT->FindObject("COUPURE_D_ih");
TH1D* HIST_D_MASS=(TH1D*)gROOT->FindObject("MASS_D_loose");
/*
TH1D* HIST_P=(TH1D*)gROOT->FindObject("COUPURE_G_p_strict");
TH1D* HIST_IH=(TH1D*)gROOT->FindObject("COUPURE_F_ih_strict");
TH1D* HIST_MASS_a=(TH1D*)gROOT->FindObject("COUPURE_A_p_strict");
TH1D* HIST_MASS_e=(TH1D*)gROOT->FindObject("COUPURE_E_p_strict");
TH1D* HIST_D_P=(TH1D*)gROOT->FindObject("COUPURE_D_p_strict");
TH1D* HIST_D_IH=(TH1D*)gROOT->FindObject("COUPURE_D_ih_strict");
TH1D* HIST_D_MASS=(TH1D*)gROOT->FindObject("MASS_D");
HIST_D_MASS->Rebin(10);
*/

int nbinxa = HIST_MASS_a->GetNbinsX();
int nbinya = HIST_MASS_a->GetNbinsY();
int nbinx_p = HIST_P->GetNbinsX();
int nbinx_ih = HIST_IH->GetNbinsX();
int mbin = HIST_D_MASS->GetNbinsX();
int pentries = HIST_P->GetEntries();
int ihentries = HIST_IH->GetEntries();
int mentries = HIST_D_MASS->GetEntries();
cout << "pentries = " << pentries <<endl;
cout << " ihentries = " << ihentries << endl;
cout << " mentries = " << mentries << endl;


/*
TH1D* HIST_TEST= (TH1D*)HIST_P->Clone();
HIST_TEST->SetName("HISTOGRAME");
HIST_TEST->Reset();

TH1D* HIST_TEST= (TH1D*)HIST_P->Clone();
HIST_TEST->SetName("HISTOGRAME");
HIST_TEST->Reset();

TH1D* HIST_TEST= (TH1D*)HIST_P->Clone();
HIST_TEST->SetName("HISTOGRAME");
HIST_TEST->Reset();

TH1D* HIST_TEST= (TH1D*)HIST_P->Clone();
HIST_TEST->SetName("HISTOGRAME");
HIST_TEST->Reset();
*/

TH1D* HIST_MASS = new TH1D("HIST_MASS" , "MASS FROM POISSON with weight", mbin , mmin , mmax );
TH1D* HIST_MASS_F_G = new TH1D("HIST_MASS_F_G" , "MASS FROM F&G with weight", mbin , mmin , mmax );
TH1D* HIST_P_POISSON= new TH1D("HIST_P_POISSON" , " Histo random P" , nbinx_p , 0 ,2000 );
TH1D* HIST_IH_POISSON= new TH1D("HIST_IH_POISSON" , " Histo random IH" , nbinx_ih , 0 , 8 );

TH1D* HIST_P_POISSON_TOT= new TH1D("HIST_P_POISSON_TOT" , " Histo random P" , nbinx_p , 0 ,2000 );
TH1D* HIST_IH_POISSON_TOT= new TH1D("HIST_IH_POISSON_TOT" , " Histo random IH" , nbinx_ih , 0 , 8 );

TH1D* HIST_SIGNAL_PREDICT_MASS = new TH1D("HIST_SIGNAL_PREDICT_MASS" , " Rapport entre signal et prediction de la masse" , mbin , mmin ,mmax );
TH1D* HIST_SIGNAL_PREDICT_P = new TH1D("HIST_SIGNAL_PREDICT_P" , " Rapport entre signal et prediction de P" , nbinx_p , 0 ,2000 );
TH1D* HIST_SIGNAL_PREDICT_IH = new TH1D("HIST_SIGNAL_PREDICT_IH" , " Rapport entre signal et prediction de IH" , nbinx_ih , 0 , 8 );

TH1D* HIST_P_ENTRIES = new TH1D("HIST_P_ENTRIES" , " NOMBRE D'ENTREE P PSEUDO EXPERIENCE " , mbin ,0.9*pentries , 1.1*pentries );
TH1D* HIST_IH_ENTRIES = new TH1D("HIST_IH_ENTRIES", " NOMBRE D'ENTREE IH PSEUDO EXPERIENCE " , mbin , 0.9*ihentries , 1.1*ihentries );
TH1D* HIST_M_ENTRIES = new TH1D("HIST_MASS_ENTRIES" , " NOMBRE D'ENTREE MASS PSEUDO EXPERIENCE " , mbin , 0.9*mentries , 1.1*mentries );



HIST_SIGNAL_PREDICT_MASS->Sumw2();
HIST_SIGNAL_PREDICT_P->Sumw2();
HIST_SIGNAL_PREDICT_IH->Sumw2();
HIST_MASS->Sumw2();
HIST_P_POISSON->Sumw2();
HIST_IH_POISSON->Sumw2();
HIST_P_POISSON_TOT->Sumw2();
HIST_IH_POISSON_TOT->Sumw2();
HIST_D_P->Sumw2();
HIST_D_IH->Sumw2();
HIST_D_MASS->Sumw2();
HIST_P_ENTRIES->Sumw2();
HIST_IH_ENTRIES->Sumw2();
HIST_M_ENTRIES->Sumw2();
HIST_MASS_F_G->Sumw2();

	double nentriesa = HIST_MASS_a->GetEntries();
	double nentriese = HIST_MASS_e->GetEntries();
	Long64_t nentriesb = HIST_P_POISSON->GetEntries();
	Long64_t nentriesc = HIST_IH_POISSON->GetEntries();
//	nbinx_p = HIST_P_POISSON->GetNbinsX();
//	nbinx_ih = HIST_IH_POISSON->GetNbinsX();
	
vector <TH1D*> VECT_HIST_P ;
vector <TH1D*> VECT_HIST_IH ;
vector <TH1D*> VECT_HIST_MASS ;
TRandom *rand = new TRandom(0);
double val,val_p,calc,calc1,calc2 ;
for ( int i= 1; i<= 100 ; i++){					// Generation des 100 Pseudo-experience 
	
	
	TH1D* HIST_P_POISSON_ = new TH1D(Form("HIST_P_POISSON_%d",i),"HISTO RANDOM P ", nbinx_p , 0 , 2000 );
	TH1D* HIST_IH_POISSON_ = new TH1D(Form("HIST_IH_POISSON_%d",i),"HISTO RANDOM IH ", nbinx_ih , 0 , 8 );
	TH1D* HIST_MASS_ = new TH1D(Form("HIST_MASS_%d",i),"HISTO RANDOM MASS", mbin , mmin , mmax );
	for(int s = 1; s < (nbinx_p + 1) ; s++){ //p		// Création HISTOGRAMME DE P
			val_p = rand->Poisson(HIST_P->GetBinContent(s));
			weight_poisson= val_p ;
			val = rand->Poisson(HIST_P->GetBinCenter(s));
			HIST_P_POISSON_->Fill(HIST_P->GetBinCenter(s),weight_poisson) ;
	}
	for(int k = 1; k< (nbinx_ih + 1) ; k++ ){ //ih		// Création HISTOGRAMME DE IH
			weight = rand->Poisson(HIST_IH->GetBinContent(k)) ;
			HIST_IH_POISSON_->Fill(HIST_IH->GetBinCenter(k),weight);
	}
	for(int s = 1; s < (nbinx_p + 1) ; s++){ //p		// Recombination de HISTOGRAMME AFIN DE CREER L'HISTOGRAMME DE MASSE
		for(int k = 0; k<= (nbinx_ih + 1) ; k++ ){ //ih
			//weight = (((HIST_P_POISSON_->GetBinContent(s))*(HIST_IH_POISSON_->GetBinContent(k)))/(nentriesa/(nentriese*nentriese))) ; 	// ( Bin_p_i*Bin_ih_j )  / ( A / E*E )
			calc = ((HIST_P_POISSON_->GetBinContent(s)*HIST_IH_POISSON_->GetBinContent(k))/nentriese) ;
			calc1 = nentriesa/nentriese ;
			weight = calc*calc1 ;
			//cout << " BIn*Bin/E = " << weight << endl;
			//cout << " weight = " << weight << endl;
			p = HIST_P_POISSON_->GetBinCenter(s);
			ih = HIST_IH_POISSON_->GetBinCenter(k);
			m = sqrt(((p*p) * (ih - C ))/K);
			HIST_MASS->Fill(m,weight/100);
			HIST_MASS_->Fill(m,weight);
		}
	}
	for(int s = 1; s < (nbinx_p + 1) ; s++){ //p		// AJOUT DES HISTOGRAMMES RANDOM DANS UN HISTO TOTAL P
			p_weight = HIST_P_POISSON_->GetBinContent(s) ;
			pentries += p_weight ;
			HIST_P_POISSON_TOT->Fill(HIST_P_POISSON_->GetBinCenter(s),(p_weight/100)) ;
	}
	for(int k = 1; k< (nbinx_ih + 1) ; k++ ){ //ih		// AJOUT DES HISTOGRAMMES RANDOM DANS UN HISTO TOTAL IH
			weight = HIST_IH_POISSON_->GetBinContent(k) ;
			ihentries += weight ;
			HIST_IH_POISSON_TOT->Fill(HIST_IH_POISSON_->GetBinCenter(k),(weight/100));
	}
	HIST_P_ENTRIES->Fill(pentries);
	HIST_IH_ENTRIES->Fill(ihentries);
	VECT_HIST_P.push_back(HIST_P_POISSON_);
	VECT_HIST_IH.push_back(HIST_IH_POISSON_);
	VECT_HIST_MASS.push_back(HIST_MASS_);
//	HIST_P_POISSON_->Reset() ;				// REMISE A ZERO DES HISTO RANDOM P
//	HIST_IH_POISSON_->Reset() ;
	pentries = 0 ;
	ihentries= 0 ;
	mentries = 0 ;				// REMISE A ZERO DES HISTO RANDOM IH
	}
	for(int s = 1; s < (nbinx_p + 1) ; s++){ //p		// Recombination de HISTOGRAMME AFIN DE CREER L'HISTOGRAMME DE MASSE
		for(int k = 1; k< (nbinx_ih + 1) ; k++ ){ //ih
			weight = (((HIST_P->GetBinContent(s))*(HIST_IH->GetBinContent(k)))/nentriesa) ;
			p = HIST_P->GetBinCenter(s);
			ih = HIST_IH->GetBinCenter(k);
			//cout << "p = " << p << "ih = " << ih<< "\n"<<endl;
			m = sqrt(((p*p) * (ih - C ))/K);
			//cout<< " M = "<<m<<endl;
			HIST_MASS_F_G->Fill(m,weight/10);
		}
	}


			
			
TCanvas* T1 = new TCanvas("T1" , " Comparatif P " , 200 , 200 );	// CREATION DES CANVAS OU L'ON VA VISUALISER LES HISTO
TCanvas* T2 = new TCanvas("T2" , " Comparatif IH " , 200 , 200 );
TCanvas* T3 = new TCanvas("T3" , " Comparatif MASS " , 200 , 200 );
TCanvas* T4 = new TCanvas("T4" , " VECT P " , 200 , 200 );
TCanvas* T5 = new TCanvas("T5" , " VECT IH " , 200 , 200 );
TCanvas* T6 = new TCanvas("T6" , " VECT MASS " , 200 , 200 );




			// SCALING DES HISTOGRAMMES
HIST_IH_POISSON_TOT->Scale(1/HIST_IH_POISSON_TOT->Integral());
HIST_P_POISSON_TOT->Scale(1/HIST_P_POISSON_TOT->Integral());
//HIST_MASS->Scale(1/HIST_MASS->Integral());
HIST_D_P->Scale(1/HIST_D_P->Integral());
HIST_D_IH->Scale(1/HIST_D_IH->Integral());
//HIST_D_MASS->Scale(1/HIST_D_MASS->Integral());
HIST_P->Scale(1/HIST_P->Integral());
HIST_IH->Scale(1/HIST_IH->Integral());
HIST_SIGNAL_PREDICT_P->Divide(HIST_P_POISSON_TOT , HIST_D_P , 1 , 1 );

HIST_SIGNAL_PREDICT_MASS->Divide(HIST_MASS , HIST_D_MASS , 1 , 1 );

HIST_SIGNAL_PREDICT_IH->Divide(HIST_IH_POISSON_TOT , HIST_D_IH , 1 , 1 );

T1->cd();
HIST_D_P->Draw("HIST");
HIST_P_POISSON_TOT->SetLineColor(kRed);
HIST_P_POISSON_TOT->Draw("SAME HIST");
HIST_P->SetLineColor(kGreen);
HIST_P->Draw("SAME HIST");

T2->cd();
HIST_D_IH->Draw("HIST");
HIST_IH_POISSON_TOT->SetLineColor(kRed);
HIST_IH_POISSON_TOT->Draw("SAME HIST");
HIST_IH->SetLineColor(kGreen);
HIST_IH->Draw("SAME HIST");

T3->cd();
HIST_D_MASS->Draw("HIST");
HIST_MASS->SetLineColor(kRed);
HIST_MASS->Draw("SAME HIST");
HIST_MASS_F_G->SetLineColor(kGreen);
HIST_MASS_F_G->Draw("SAME HIST");

for (int v=0 ; v<10 ; v++){

T4->cd();
VECT_HIST_P[10*v]->Draw("HIST SAME");
T5->cd();
VECT_HIST_IH[10*v]->Draw("HIST SAME");
T6->cd();
VECT_HIST_MASS[10*v]->Draw("HIST SAME");


}
T1->SetName("Comparatif P");
T2->SetName("Comparatif IH");
T3->SetName("Comparatif MASS");
T4->SetName("Comparatif P VECT");
T5->SetName("Comparatif IH VECT ");
T6->SetName("Comparatif MASS VECT ");

OutputHisto->cd();
VECT_HIST_P[1]->Write();
VECT_HIST_P[1]->Write();

HIST_IH_POISSON_TOT->Write();
HIST_P_POISSON_TOT->Write();
HIST_MASS_F_G->Write();
VECT_HIST_MASS[1]->Write();
HIST_D_MASS->Write();
HIST_D_P->Write();
HIST_D_IH->Write();
HIST_P_ENTRIES->Write();
HIST_IH_ENTRIES->Write();
HIST_M_ENTRIES->Write();
HIST_SIGNAL_PREDICT_P->Write();
HIST_SIGNAL_PREDICT_MASS->Write();
HIST_SIGNAL_PREDICT_IH->Write();

HIST_P->Write();
HIST_IH->Write();

T1->Write();
T2->Write();
T3->Write();
T4->Write();
T5->Write();
T6->Write();
OutputHisto->Close();

}
