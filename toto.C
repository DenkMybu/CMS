#define toto_cxx
#include "toto.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TPad.h>


void Selections(int,bool);
double Poisson(int, double);



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
	
	
	int nbinpt = 300;
	
	float minpt = 50, maxpt = 1550;
	
	int nbinias = 100;
	
	float minias = 0, maxias = 1.2;
	
	int nbinih = 100;
	
	float minih = 0, maxih = 8;
	
	
	TH1D* HSCP_multi = new TH1D("HSCP_multi", "# of HSCP candidates", 11, -0.5,10.5);
	TH1D* HSCP_pt = new TH1D("HSCP_pt", "pT",  100, minpt,maxpt);
	TH1D* HSCP_IH = new TH1D("HSCP_IH", " ( IH )",  nbinih ,0 , 80 );
	TH1D* HSCP_IAS = new TH1D("HSCP_IAS", " ( IAS ) ", nbinias , 0 , 1.2  );
	TH1D* HSCP_ETA = new TH1D("HSCP_ETA", "( ETA )", 100 , -8 , 8  );
	TH1D* HSCP_PT_LOW = new TH1D("HSCP_PT_LOW", " ( PT LOW ) " , nbinpt, 0 , 100 ) ;
	TH1D* HSCP_MUON = new TH1D("HSCP_MUON", " PT MUON " , 100, 0 , 200 ) ;
	TH1D* HSCP_PT_hscp0 = new TH1D("HSCP_PT_hscp0" , " PT pour HSCP =0 ", nbinpt , minpt , maxpt );
	TH1D* HSCP_PT_hscp1 = new TH1D("HSCP_PT_hscp1" , " PT pour HSCP != 0 ", nbinpt , minpt , maxpt );
	TH1D* HSCP_COUNT = new TH1D("HSCP_COUNT" , " #candidats passants " , 11 , -0.5 , 10.5 );
	
	
	
	TH1D* HSCP_IASMOVE = new TH1D("HSCP_IASMOVE", " ( IAS ) ", nbinias , minias , maxias  );
	TH1D* MASS_D = new TH1D("MASS_D" , " Masses des candidats dans la zone D " , 1000 , 0 , 2000);
	
	
	TH1D* AH = new TH1D("AH" , " #candidats A " , 1000 , 0.02, 0.4 );
	TH1D* BH = new TH1D("BH" , " #candidats B " , 1000 , 0.02 , 0.4 );
	TH1D* CH = new TH1D("CH" , " #candidats C " , 1000 , 0.02 , 0.4 );
	TH1D* DH = new TH1D("DH" , " #candidats D " , 1000 , 0.02 , 0.4 );
	
	
	TH1D* COUPURE_A_p = new TH1D("COUPURE_A_p" , " coupure zone A " , 100 ,0 , 2000 );
	TH1D* COUPURE_B_p = new TH1D("COUPURE_B_p" , " coupure zone B " , 100 ,0 , 2000 );
	TH1D* COUPURE_C_p = new TH1D("COUPURE_C_p" , " coupure zone C " , 100 ,0 , 2000 );
	TH1D* COUPURE_D_p = new TH1D("COUPURE_D_p" , " coupure zone D " , 100 ,0 , 2000 );
	
	
	
	TH1D* COUPURE_A_ih = new TH1D("COUPURE_A_ih" , " coupure zone A " , nbinih ,  minih , maxih );
	TH1D* COUPURE_B_ih = new TH1D("COUPURE_B_ih" , " coupure zone B " , nbinih ,  minih , maxih );
	TH1D* COUPURE_C_ih = new TH1D("COUPURE_C_ih" , " coupure zone C " , nbinih ,  minih , maxih );
	TH1D* COUPURE_D_ih = new TH1D("COUPURE_D_ih" , " coupure zone D " , nbinih ,  minih , maxih );
	

	TH1D* COUPURE_B_p_strict = new TH1D("COUPURE_B_p_strict" , " coupure zone B " , 100 ,0 , 2000 );
	
	

	TH1D* COUPURE_C_ih_strict = new TH1D("COUPURE_C_ih_strict" , " coupure zone C " , 100 ,  0 , 8 );
	
	
			
	TH2D* HSCP_PT_IH = new TH2D("HSCP_PT_IH", " PT ( IH )",  100 ,0 , 80 , 50, minpt , maxpt ); 
	TH2D* HSCP_PT_IAS = new TH2D("HSCP_PT_IAS", "PT ( IAS ) ", nbinias , minias , maxias , nbinpt, minpt , maxpt ); //Utiliser cet histo pour sortir l'autre histo avec les coupures changer le binding  **
	TH2D* HSCP_PT_ETA = new TH2D("HSCP_PT_ETA", "PT ( ETA )", 100 , -8 , 8 , 50 , minpt ,  maxpt ); //**
	TH2D* HSCP_PT_MUONINVERSEBETA = new TH2D("HSCP_PT_MUONINVERSEBETA", "PT ( MUONINVERSEBETA )", 100 ,-20, 20 , 50 , minpt , maxpt );
	TH2D* HSCP_PTT_PTM = new TH2D("HSCP_PTT_PTM", "PTTracks vs PTMuon", 200 , 0 , 1000 , 200 , 55 ,  1000 );

	
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
	HSCP_IASMOVE->Sumw2();
	MASS_D->Sumw2();
	
	
	AH->Sumw2();
	BH->Sumw2();
	CH->Sumw2();
	DH->Sumw2();
	
	
	COUPURE_B_p->Sumw2();
	COUPURE_B_p_strict->Sumw2();
	COUPURE_C_ih->Sumw2();
	COUPURE_C_ih_strict->Sumw2();
	COUPURE_A_p->Sumw2();
	COUPURE_D_p->Sumw2();

//***************************************************OUT PUT FILENAME*******************************************************



	TString outputfilename="tuesday10.root";  // COEER line 16 drawhist.C
	TFile* OutputHisto = new TFile(outputfilename,"RECREATE");



//**************************************************************************************************************************
	// if (fChain == 0) return;
	Long64_t nentries = fChain->GetEntriesFast();
	Long64_t nbytes = 0, nb = 0;
	
	double IASF=0.096,PTF=65,A = 0,A2=0,B = 0,B2=0,C = 0,C2=0,D,D2 = 0, Ka =2.935, Ce = 3.197 ;
	
	double sigma_D,E_A , E_B , E_C , E_D ; // 0.1 et 60
	
	double B_strict =0,C_strict=0, MASS=0;
	
	double c_pt = 65,c_pt_strict = 65,c_ias=0.096,c_ias_strict = 0.096; 
	
	int test=0, count=0,counttot=0,compteur0=0,compteurx=0;
	
	for (Long64_t jentry=0; jentry<nentries;jentry++) { //boucle sur les entry
	
	
     		if(jentry%50000 == 0){
			cout<<"Still here ! " << "\n" << endl; //JUST FOR INFO
		}
		
		
		

     		Long64_t ientry = LoadTree(jentry);
     		if (ientry < 0) break;
     		nb = fChain->GetEntry(jentry);   nbytes += nb;
        	HSCP_multi->Fill(nhscp);
		count = 0; //Reset compteur 
		
     		for (int ihs=0; ihs<nhscp; ihs++) {
				
      			test=Selections(ihs,0);
      			if (test== 1){
				count+=1;
				// fin de boucle count 
	   			HSCP_MUON->Fill(muon_pt[hscp_track_idx[ihs]]);
	   			HSCP_PT_LOW->Fill(track_pt[hscp_track_idx[ihs]]);
           			HSCP_pt->Fill(track_pt[hscp_track_idx[ihs]]);
	      	
	   			HSCP_ETA->Fill(track_eta[hscp_track_idx[ihs]]);
	    			HSCP_PT_ETA->Fill(track_eta[hscp_track_idx[ihs]],track_pt[hscp_track_idx[ihs]]);
	      
	    			HSCP_PT_IH->Fill(track_ih_ampl[hscp_track_idx[ihs]],track_pt[hscp_track_idx[ihs]]);
	   			HSCP_IH->Fill(track_ih_ampl[hscp_track_idx[ihs]]);
	    		  
	    			HSCP_PT_IAS->Fill(track_ias_ampl[hscp_track_idx[ihs]],track_pt[hscp_track_idx[ihs]]);
	   			HSCP_IAS->Fill(track_ias_ampl[hscp_track_idx[ihs]]);
	      
	     			HSCP_PTT_PTM->Fill(muon_pt[hscp_track_idx[ihs]],track_pt[hscp_track_idx[ihs]]);
	     			HSCP_PT_MUONINVERSEBETA->Fill(muon_comb_inversebeta[hscp_track_idx[ihs]],track_pt[hscp_track_idx[ihs]]);
          
	      		
				
				//cout << "PT = " << track_pt[hscp_track_idx[ihs]] << " IAS = " << track_ias_ampl[hscp_track_idx[ihs]] << "\n" ;
			
				
			
				if ((track_pt[hscp_track_idx[ihs]]<=PTF) && (track_ias_ampl[hscp_track_idx[ihs]] <= IASF)){
					A+=1;
					//cout << "A = " << A << "\n";
					AH->Fill(track_ias_ampl[hscp_track_idx[ihs]]);
					COUPURE_A_p->Fill(track_p[hscp_track_idx[ihs]]);
					COUPURE_A_ih->Fill(track_ih_ampl[hscp_track_idx[ihs]]);
				}
		
				if ((track_pt[hscp_track_idx[ihs]]<=PTF) && (track_ias_ampl[hscp_track_idx[ihs]] > IASF)){ //IAS ?
					// FILL B 
					B+=1;
					//cout << "B = " << B << "\n";
					BH->Fill(track_ias_ampl[hscp_track_idx[ihs]]);
					COUPURE_B_p->Fill(track_p[hscp_track_idx[ihs]]);
					COUPURE_B_ih->Fill(track_ih_ampl[hscp_track_idx[ihs]]);
												 
				}
	
				if ((track_pt[hscp_track_idx[ihs]]>PTF) && (track_ias_ampl[hscp_track_idx[ihs]] <= IASF)){ // IAS ?
					// FILL C
					C+=1;
					//cout << "C = " << C << "\n";
					COUPURE_C_p->Fill(track_p[hscp_track_idx[ihs]]);
					COUPURE_C_ih->Fill(track_ih_ampl[hscp_track_idx[ihs]]);
					CH->Fill(track_ias_ampl[hscp_track_idx[ihs]]);
				
				}
		
				if ((track_pt[hscp_track_idx[ihs]]>PTF) && (track_ias_ampl[hscp_track_idx[ihs]] > IASF)){
					MASS = 0;
					D2 +=1;//D2 est D reel
					if(track_ih_ampl[hscp_track_idx[ihs]] > Ce){
						MASS=sqrt((track_p[hscp_track_idx[ihs]]*track_p[hscp_track_idx[ihs]]/Ka)*(track_ih_ampl[hscp_track_idx[ihs]]-Ce) ) ;
						MASS_D->Fill(MASS);
						compteurx+=1;
						cout << "Mass = " << MASS << "\n"; //si ça ne rentre pas dedans je mets 0
					}
					else {
						MASS_D->Fill(MASS);
						compteur0+=1;
											
					}// Initialiser la masse ä 0 avant 
					COUPURE_D_p->Fill(track_p[hscp_track_idx[ihs]]);
					COUPURE_D_ih->Fill(track_ih_ampl[hscp_track_idx[ihs]]);
					DH->Fill(track_ias_ampl[hscp_track_idx[ihs]]);
					
				}
			
	
					
			}
				
					
		}
			
		
		counttot += count; 
			
		HSCP_COUNT->Fill(count); 
			 

			

	
	}
		
	cout<<" Number of masses equal to 0 : " << compteur0<< " Number dif than 0 : " << compteurx << "\n";
	  
	for (int ihd=0; ihd<nhscp; ihd++) {
		if (ihd==0){
			if (hscp_track_idx[ihd]>=0){
				HSCP_PT_hscp0->Fill(track_pt[hscp_track_idx[ihd]]);
			}
		}
		
		if (ihd!=0){
			if (hscp_track_idx[ihd]>=0){
				HSCP_PT_hscp1->Fill(track_pt[hscp_track_idx[ihd]]);
			}
		}
		
	  }
	  
	  
	  
	// Calculs des valeurs des critères de coupures
	D=(C*B/A) ;
	//D_2=(H*A/E) ;
	//D_5=(H*B/F) ;
	//D_3=(A*G*F/(E*E));
	//D_4=(C*F/(E));
	
	
	
	
	
	E_A = sqrt(A) ; 
	E_B = sqrt(B) ;
	E_C = sqrt(C) ;
	E_D = sqrt(D) ;
	
	
	
	sigma_D=D*sqrt(((E_A/A)*(E_A/A))+((E_B/B)*(E_B/B))+((E_C/C)*(E_C/C)));
	
	
	
	
	
	
	
	cout<<" A = "<< A << " / Erreur sur A : " << E_A <<"\n" << endl;
	cout<<" B = "<< B << " / Erreur sur B : "<< E_B <<"\n" << endl;
	cout<<" C = "<< C << " / Erreur sur C : "<<E_C<<"\n" << endl;
	cout<<" D reel = "<< D2 <<"\n" << endl;
	cout<<" D estimated = "<< D << " / Erreur sur D : "<<sigma_D << "\n" << endl;
	  
	cout<<" Number that made it : "<< counttot << "\n" <<endl;

	Double_t Correlation_PTT_PTM = HSCP_PTT_PTM->GetCorrelationFactor();
	cout<<" Correlation PTT vs PTM : "<< Correlation_PTT_PTM << "\n" << endl;

	Double_t Correlation_PT_MUONINVERSEBETA = HSCP_PT_MUONINVERSEBETA->GetCorrelationFactor();
	cout<<" Correlation PT vs MUONINVERSEBETA : "<< Correlation_PT_MUONINVERSEBETA << "\n" << endl;

	Double_t Correlation_PT_ETA = HSCP_PT_ETA->GetCorrelationFactor();
	cout<<" Correlation PT vs ETA : "<< Correlation_PT_ETA << "\n" << endl;

	Double_t Correlation_PT_IAS = HSCP_PT_IAS->GetCorrelationFactor();
	cout<<" Correlation PT vs IAS : "<< Correlation_PT_IAS << "\n" << endl;

	Double_t Correlation_PT_IH = HSCP_PT_IH->GetCorrelationFactor();
	cout<<" Correlation PT vs IH : "<< Correlation_PT_IH << "\n" << endl;
	    
	  
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
	HSCP_IASMOVE->Write();
	MASS_D->Write();
	
	AH->Write();
	BH->Write();
	CH->Write();
	DH->Write();
	
	
	COUPURE_A_p->Write();
	COUPURE_B_p->Write();
	COUPURE_C_p->Write();
	COUPURE_D_p->Write();
	
	COUPURE_A_ih->Write();
	COUPURE_B_ih->Write();
	COUPURE_C_ih->Write();
	COUPURE_D_ih->Write();
	
	
	COUPURE_C_ih_strict->Write();

	COUPURE_B_p_strict->Write();




	OutputHisto->Close();
}



int toto::Selections(int i,bool k) {

	bool selec=1;
	if (k==1){
		if(hscp_track_idx[i]<0){ // 
			selec = 0; 
		}
		if(hscp_muon_idx[i]<0){ // Suppr si track only
			selec = 0; 
		}
		if(track_pt[hscp_track_idx[i]]<20){ // CHANGE TO 50 for tests
			selec = 0; 
		}
		if(muon_pt[hscp_track_idx[i]]<20){ //Suppr si track only, rajouter les sigmas et beta
			selec = 0; 
		}
	
		if( track_eta[hscp_track_idx[i]] >= 2.1 ) {
			selec = 0;
		}
		if( track_eta[hscp_track_idx[i]] <= -2.1) {
			selec = 0;
		}
		
		if(track_dz[hscp_track_idx[i]] >= 0.5){
			selec = 0;
		}
	
		if(track_dxy[hscp_track_idx[i]] >= 0.5){
			selec = 0;
		}
	
		if(track_pterr[hscp_track_idx[i]]/track_pt[hscp_track_idx[i]] >= 1){ // 1 a la place de 0.25
			selec = 0;
		}
		if(track_chi2[hscp_track_idx[i]] >= 5){
			selec = 0;
		}
	
		if(track_npixhits[hscp_track_idx[i]] <= 1){
			selec = 0;
		}
	
		if(track_nhits[hscp_track_idx[i]] <= 7){
			selec = 0;
		}
	
		if(track_validfraction[hscp_track_idx[i]] <= 0.8){
			selec = 0;
		}

		if(hscp_iso2_tk[i] >= 50){
			selec = 0;
		}
		
		
		if(track_p[hscp_track_idx[i]]>0){
			if((hscp_iso2_ecal[i]/track_p[hscp_track_idx[i]]) >= 0.3){
			selec = 0;
			}
	
		}
		
		else
			selec = 0;
		

	
	}
	else{
		if(hscp_track_idx[i]<0){ // 
			selec = 0; 
		}
		
		if(track_pt[hscp_track_idx[i]]<50){  // Coupure de preselection 50
			selec = 0; 
		}	
		
		if(track_eta[hscp_track_idx[i]] >= 2.1 ) {
			selec = 0;
		}
		if(track_eta[hscp_track_idx[i]] <= -2.1) {
			selec = 0;
		}
		
		if(track_dz[hscp_track_idx[i]] >= 0.5){
			selec = 0;
		}
	
		if(track_dxy[hscp_track_idx[i]] >= 0.5){
			selec = 0;
		}
	
		if(track_pterr[hscp_track_idx[i]]/track_pt[hscp_track_idx[i]] >= 1){ // 1 a la place de 0.25
			selec = 0;
		}
		if(track_chi2[hscp_track_idx[i]] >= 5){
			selec = 0;
		}
	
		if(track_npixhits[hscp_track_idx[i]] <= 1){
			selec = 0;
		}
	
		if(track_nhits[hscp_track_idx[i]] <= 7){
			selec = 0;
		}
	
		if(track_validfraction[hscp_track_idx[i]] <= 0.8){
			selec = 0;
		}

		if(hscp_iso2_tk[i] >= 50){
			selec = 0;
		}
		
		if(track_p[hscp_track_idx[i]]>0){
			if((hscp_iso2_ecal[i]/track_p[hscp_track_idx[i]]) >= 0.3){
			selec = 0;
			}
	
		}
		else
			selec = 0;
	
	}
	return selec;
}







double toto::Poisson( int k, double mean ) { 

  double p = std::exp(-mean);
  
  double f = 1;
  
  for ( int i=0 ; i<k ; i++ ) {
  	f *= mean/(i+1);
  }
       
  return p*f;
  
}



//Ouvrir l'hist PT IAS, le récup ds une fonction -> ouvre le fichier root, récupère l'histogramme, boucle sur les bins , pour chaque point du binding, GetEntries(binx,biny) 

/*Pour la distribution en masse

int nbinx = HIST_MASS->GetNBinsX();

int nbiny = HIST_MASS->GetNBinsY();

HIST_MASS  

for ( i = 0; i<= nbinx + ; i++){		SUR TOUS LES BINS
	for(j=0; j<= nbiny+;j++){
		
	
	}
}
IH = K * (m² / p² ) + C   -> m =  + ou - sqrt((p² * IH - C)/K) Attention pour tout ce qui est neg ? K = Ka , C = Ce

Pour tous ceux qui passent dans D, ils ont un p et un IH; calculer leur masse, fill un histogramme


if ((track_pt[hscp_track_idx[ihs]]>PTF) && (track_ias_ampl[hscp_track_idx[ihs]] > IASF)){
			 	
				DH->Fill(track_ias_ampl[hscp_track_idx[ihs]]);
				
				D2 +=1;
			}

m = sqrt((track_p[ihs]² * track_ih[ihs] -C )/ K)

 


Ensuite pour le poids : cb d'evenements dans un bin ? GetBinContent / totBinContent   (qu'on calcule en utilisant le tot, ou boucle for et additionner tous les bin)
multiplier les fractions 














RENOTMALIZATION HIST 2D ANTOINE


nombre de bins sur éta -> nombre de bins en y sur éta / PT 

ensuite, remplir les "bins" (faux bins) avec des coefficients 



double rapport = GetBinContent(flat) / GetBinContent(pentu), on multiplie le tout par ce ratio et walla













*/
