#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

int main(){

	double a=0.096,b=65,mmax=3000, mmin = 0 , mbin=300,C = 3.197, K = 2.935;
	bool k=1,j=1;
	int totalA = 0,totalB=0,totalC=0,totalD=0;

	TString outputfilename="bg3.root";
	TFile* OutputHisto = new TFile(outputfilename,"RECREATE");




	TFile *myFile=new TFile("bg.root");
	TH1D* hist_recupere=(TH1D*)gROOT->FindObject("HSCP_PT_IAS");
	TH1D* HIST_MASS_a=(TH1D*)gROOT->FindObject("COUPURE_A_p");
	TH1D* HIST_MASS_b=(TH1D*)gROOT->FindObject("COUPURE_F_p");
	TH1D* HIST_MASS_c=(TH1D*)gROOT->FindObject("COUPURE_G_ih");

	TH1D* HIST_MASS = new TH1D("HIST_MASS" , "MASS w/o weight", mbin , mmin , mmax );


	HIST_MASS->Sumw2();


	//HIST_MASS_b->Scale(1/HIST_MASS_b->Integral());
	//HIST_MASS_c->Scale(1/HIST_MASS_c->Integral());


	int nbinx = hist_recupere->GetNbinsX();
	int nbiny = hist_recupere->GetNbinsY();

	int nbinxa = HIST_MASS_a->GetNbinsX();
	int nbinya = HIST_MASS_a->GetNbinsY();

	int nbinxb = HIST_MASS_b->GetNbinsX();
	int nbinyb = HIST_MASS_b->GetNbinsY();

	int nbinxc =  HIST_MASS_c->GetNbinsX();
	int nbinyc =  HIST_MASS_c->GetNbinsY();


	//  ias : 100, 0, 1.2
	// pt : 55 1550

	double sizeonea = 0.012 , sizeoneb = ((1550 - 55 )/ 299) ;

	for ( int u = 0 ; u<=(nbinx+1); u++){

		for (int i = 0 ; i<=(nbiny+1);i++){

			if ( ((u * sizeonea) <= a )  && ((( i*sizeoneb + 55 ) <= b))){
				totalA += hist_recupere->GetBinContent(u,i); //nombre d'évènements dans une boite pour le double for

			}

			else if(((u*sizeonea) > a) && (((i*sizeoneb +55 )<= b))){
				totalB += hist_recupere->GetBinContent(u,i);

			}

			else if(((u*sizeonea) <= a) && (((i*sizeoneb+55) > b))){
				totalC += hist_recupere->GetBinContent(u,i);
			}

			else if(((u*sizeonea) > a) && (((i*sizeoneb +55 )> b))){
				totalD += hist_recupere->GetBinContent(u,i);

			}

		}
	}

	int Sum = totalA + totalB + totalC + totalD;
	cout<<" A = "<< totalA << " B = " << totalB <<" C = " << totalC << " D = "<< totalD <<"\n" << "Sum : " << Sum << endl;


	double m,p,ih;

	int nentryA=0, nentryB=0, nentryC=0;

	Long64_t nentriesa = HIST_MASS_a->GetEntries();
	Long64_t nentriesb = HIST_MASS_b->GetEntries();
	Long64_t nentriesc = HIST_MASS_c->GetEntries();

	cout << " N entries a : " << nentriesa << " N entries b : " << nentriesb << " N entries c : " << nentriesc << "\n"<<endl;

	double dd = (mmax - mmin) / mbin ;
	double db = dd/2 ;
	for(int s = 0; s <= (nbinxb + 1) ; s++){ //p
		for(int k = 0; k<= (nbinxc + 1) ; k++ ){ //ih
			double weight = (((HIST_MASS_b->GetBinContent(s))*(HIST_MASS_c->GetBinContent(k)))/nentriesa) ;

			p = HIST_MASS_b->GetBinCenter(s);
			ih = HIST_MASS_c->GetBinCenter(k);
			//cout << "p = " << p << "ih = " << ih<< "\n"<<endl;
			m = sqrt(((p*p) * (ih - C ))/K);

			//HIST_MASS->Fill(m);
			HIST_MASS->Fill(m,weight);

		}
	}



//premier bin rempi doit etre
//link betwwen bins, valeur xmin xmax?

OutputHisto->cd();

HIST_MASS->Write();

OutputHisto->Close();


}
