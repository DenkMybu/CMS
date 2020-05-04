#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

double ran_expo(double lambda);

double generation();

int main(){

	double mmax=2000, mmin = 0 , mbin=1000,C = 3.197, K = 2.935; // REBIN dans l'autre pour les masses -> Rebin(10) //10
	
	bool k=1,j=1;
	
	int totalA = 0,totalB=0,totalC=0,totalD=0,totalD2=0,counta=5,countb;
	int totalD65=0,totalD70=0,totalD75=0,totalD80=0,totalD85=0;
	
	double sigma_D,sigma_D_real,DoD,E_A , E_B , E_C , E_D ; // 0.1 et 60
	double sizeonea = 0.012 , sizeoneb = ((1550 - 50 )/ 300) ;
	
	double Dth;
	
//*********************************************************** FIND IN FILE **************************************************************	
	
	
	
	
	TFile *myFile=new TFile("tuesday10.root"); //REPLACE BG3 par celui line 100 toto.C
	
	
	TH1D* hist_recupere=(TH1D*)gROOT->FindObject("HSCP_PT_IAS");
	
	TH1D* HIST_MASS_a=(TH1D*)gROOT->FindObject("COUPURE_A_p");
	TH1D* HIST_MASS_b=(TH1D*)gROOT->FindObject("COUPURE_B_ih");
	TH1D* HIST_MASS_c=(TH1D*)gROOT->FindObject("COUPURE_C_p");
	TH1D* HIST_MASS_d=(TH1D*)gROOT->FindObject("COUPURE_D_p");
	
	
	TH1D* HIST_MASS_a2 = (TH1D*)gROOT->FindObject("COUPURE_A_p"); //Pour avoir un nouveau graph qui somme plusieurs graphs
	TH1D* HIST_MASS_b2 = (TH1D*)gROOT->FindObject("COUPURE_B_ih");
	TH1D* HIST_MASS_c2 = (TH1D*)gROOT->FindObject("COUPURE_C_p");//ADD B_P Pour la somme des deux histos
	TH1D* HIST_MASS_d2 = (TH1D*)gROOT->FindObject("COUPURE_D_p");
	
	TH1D* HIST_MASS_a3 =(TH1D*)gROOT->FindObject("COUPURE_A_ih");
	TH1D* HIST_MASS_b3=(TH1D*)gROOT->FindObject("COUPURE_B_p");
	TH1D* HIST_MASS_c3=(TH1D*)gROOT->FindObject("COUPURE_C_ih");
	TH1D* HIST_MASS_d3=(TH1D*)gROOT->FindObject("COUPURE_D_ih");
	
	TH1D* MASS_D_toto=(TH1D*)gROOT->FindObject("MASS_D");
	
	
//****************************************************************************************************************************************


	TH2D* DOD_D = new TH2D("DOD as a function of D", "DOD(D) ", 1000 , 0 , 100000 , 100 , 0 , 2);
	
	
//*******************************************************OUPUT FILENAME ******************************************************************

	TString outputfilename="drawtuesday10.root"; //Screen bg 6 et bg 5 
	
	TFile* OutputHisto = new TFile(outputfilename,"RECREATE");
	
	
	
//*****************************************************************************************************************************************


	TH1D* HIST_MASS = new TH1D("HIST_MASS" , "MASS", mbin , mmin , mmax );
	
	TH1D* HIST_D_cut65 = new TH1D("HIST_D_cut65" , "D with cut 65", 100 , 0 , 1.2 );
	TH1D* HIST_D_cut70 = new TH1D("HIST_D_cut70" , "D with cut 70", 100 , 0 , 1.2 );
	TH1D* HIST_D_cut75 = new TH1D("HIST_D_cut75" , "D with cut 75", 100 , 0 , 1.2 );
	TH1D* HIST_D_cut80 = new TH1D("HIST_D_cut80" , "D with cut 80", 100 , 0 , 1.2 );
	TH1D* HIST_D_cut85 = new TH1D("HIST_D_cut85" , "D with cut 85", 100 , 0 , 1.2 );
	
	
	TH1D* PREDICT_D_REAL65 = new TH1D("Real D with cuts on IAS, PT = 65 " , "Predit D w/ IAS ", 100 , 0 , 1.2);
	TH1D* PREDICT_D_REAL70 = new TH1D("Real D with cuts on IAS, PT = 70" , "Predit D w/ IAS ", 100 , 0 , 1.2);
	TH1D* PREDICT_D_REAL75 = new TH1D("Real D with cuts on IAS, PT = 75" , "Predit D w/ IAS ", 100 , 0 , 1.2);
	TH1D* PREDICT_D_REAL80 = new TH1D("Real D with cuts on IAS, PT = 80" , "Predit D w/ IAS ", 100 , 0 , 1.2);
	TH1D* PREDICT_D_REAL85 = new TH1D("Real D with cuts on IAS, PT = 85" , "Predit D w/ IAS ", 100 , 0 , 1.2);
	
	TH1D* PREDICT_D_NUMBER65 = new TH1D("Number of candidates in D for PT = 65" , "Predit D w/ IAS ", 100 , 0 , 1.2);
	TH1D* PREDICT_D_NUMBER70 = new TH1D("Number of candidates in D for PT = 70" , "Predit D w/ IAS ", 100 , 0 , 1.2);
	TH1D* PREDICT_D_NUMBER75 = new TH1D("Number of candidates in D for PT = 75" , "Predit D w/ IAS ", 100 , 0 , 1.2);
	TH1D* PREDICT_D_NUMBER80 = new TH1D("Number of candidates in D for PT = 80" , "Predit D w/ IAS ", 100 , 0 , 1.2);
	TH1D* PREDICT_D_NUMBER85 = new TH1D("Number of candidates in D for PT = 85" , "Predit D w/ IAS ", 100 , 0 , 1.2);
	
	
//*************************** SUMW2 ************************************************
	
	HIST_MASS->Sumw2();
	HIST_D_cut65->Sumw2();//??
	HIST_D_cut70->Sumw2();
	HIST_D_cut75->Sumw2();
	HIST_D_cut80->Sumw2();
	HIST_D_cut85->Sumw2();
	MASS_D_toto->Sumw2();
	
	PREDICT_D_REAL65->Sumw2();
	PREDICT_D_REAL70->Sumw2();
	PREDICT_D_REAL75->Sumw2();
	PREDICT_D_REAL80->Sumw2();
	PREDICT_D_REAL85->Sumw2();
	
	//PREDICT_D_NUMBER65->Sumw2();
	//PREDICT_D_NUMBER70->Sumw2();
	//PREDICT_D_NUMBER75->Sumw2();
	//PREDICT_D_NUMBER80->Sumw2();
	//PREDICT_D_NUMBER85->Sumw2();
	
	
//*********************************************************************************	
	
	
	
	
//******************** RENORMALIZATION *****************************
	
	//HIST_MASS_b->Scale(1/HIST_MASS_b->Integral());
	//HIST_MASS_c->Scale(1/HIST_MASS_c->Integral());
	
//******************************************************************


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
	
	//double a= 0.096,b=65;
	// Changer les p pour multiples graphs, multigraph 
	
	for(int b=65;b<90;b+=5){
		cout << "PT cut = " << b << "\n";
		counta=0;
		for(double a=0.012;a<=0.3;a+=0.012) //Attention i++ / i--  calcul avec largeur des bins ***START 0.012, end 0.3 ?
		{
			totalA=0, totalB=0,totalC=0,totalD=0;
			
			/*if(b==65)
				totalD65=0;
				
			if(b==70)
				totalD70=0;
				
			if(b==75)
				totalD75=0;
				
			if(b==80)
				totalD80=0;
				
			if(b==85)
				totalD85=0;*/
				
			
			counta+=1;	
			for ( int u = 0 ; u<=(nbinx+1); u++){
	
				for (int i = 0 ; i<=(nbiny+1);i++){
			
					if ( ((u * sizeonea) <= a )  && ((( i*sizeoneb + 50 ) <= b))){ //
						totalA += hist_recupere->GetBinContent(u,i); //nombre d'évènements dans une boite pour le double for
				
					}
			
					if(((u*sizeonea) > a) && (((i*sizeoneb + 50 )<= b))){
						totalB += hist_recupere->GetBinContent(u,i);	
			
					}
			
					if(((u*sizeonea) <= a) && (((i*sizeoneb + 50) > b))){
						totalC += hist_recupere->GetBinContent(u,i);
					}
			
					if(((u*sizeonea) > a) && (((i*sizeoneb + 50 )> b))){
						totalD += hist_recupere->GetBinContent(u,i);
						totalD2 += hist_recupere->GetBinContent(u,i);
						
						if(b==65){
							totalD65+= hist_recupere->GetBinContent(u,i);
						}
							
						else if(b==70){
							totalD70+= hist_recupere->GetBinContent(u,i);
						}
							
						else if(b==75){
							totalD75+=hist_recupere->GetBinContent(u,i);
						}
						
						else if(b==80){
							totalD80+=hist_recupere->GetBinContent(u,i);
						}
						
						else if(b==85){
							totalD85+=hist_recupere->GetBinContent(u,i);
						}
						//cout << " IN FOR : a = " << (u*sizeonea) << " b = " << (i*sizeoneb +50 ) << "TotalD2 : " << totalD2 << "\n";
			
					}
			
				
				
				}
			
			}
	/*
	
	sigma_D=nD*sqrt(((E_A/nA)*(E_A/nA))+((E_B/nB)*(E_B/nB))+((E_C/nC)*(E_C/nC)));
		cout << " Error on D : " << sigma_D << "\n";
	
		sigma_D_divided = sigma_D / nD;
		cout << " Error on D o D : " << sigma_D_divided << "\n";
		
		Dpredit = (nC *1.* nB) / nA ;
		dod = 1.*Dpredit/nD ;
		
		cout << " # bin " << counta << " Center of bin :  "  << PREDICT_D->GetBinCenter(counta) << " a = " << a<< "\n";
	
		PREDICT_D->SetBinContent(counta,dod);
		
		PREDICT_D->SetBinError(counta,sigma_D_divided);
		cout << "D o D = " << dod << " # in D :" << nD << " # predicted : " << Dpredit << "\n";
	
	
	*/
			E_A = sqrt(totalA) ; 
			E_B = sqrt(totalB) ;
			E_C = sqrt(totalC) ;
			E_D = sqrt(totalD) ;
		
			sigma_D=totalD*sqrt(((E_A/totalA)*(E_A/totalA))+((E_B/totalB)*(E_B/totalB))+((E_C/totalC)*(E_C/totalC)));
			Dth = ((totalB *1.* totalC )/ totalA);
				
			//cout << " Total D 65 : " << totalD65 << " Total D 70 : " << totalD70 << " Total D 75 : " << totalD75 << " Total D 80 : " << totalD80 << " Total D 85 : " << totalD85 << endl;
			
			if(b==65){
				
				HIST_D_cut65->Fill(a,totalD);
				sigma_D_real = sigma_D / totalD;
				DoD = (1.*Dth / totalD );
				//cout << " Error on bars : " << sigma_D_real << "\n";
				DOD_D->Fill(totalD,DoD);
				PREDICT_D_REAL65->SetBinContent(counta,DoD);
				PREDICT_D_REAL65->SetBinError(counta,sigma_D_real);
				PREDICT_D_NUMBER65->SetBinContent(counta,totalD65);
			
			}
			if(b==70){
			
				HIST_D_cut70->Fill(a,totalD);
				sigma_D_real = sigma_D / totalD;
				DoD = (1.*Dth / totalD );
				//cout << " Error on bars : " << sigma_D_real << "\n";
				PREDICT_D_REAL70->SetBinContent(counta,DoD);
				PREDICT_D_REAL70->SetBinError(counta,sigma_D_real);
				PREDICT_D_NUMBER70->SetBinContent(counta,totalD70);
			
			}
			if(b==75){
				HIST_D_cut75->Fill(a,totalD);
				sigma_D_real = sigma_D / totalD;
				DoD = (1.*Dth / totalD );
				//cout << " Error on bars : " << sigma_D_real << "\n";
				PREDICT_D_REAL75->SetBinContent(counta,DoD);
				PREDICT_D_REAL75->SetBinError(counta,sigma_D_real);
				PREDICT_D_NUMBER75->SetBinContent(counta,totalD75);
			
			}
			if(b==80){
				HIST_D_cut80->Fill(a,totalD);
				sigma_D_real = sigma_D / totalD;
				DoD = (1.*Dth / totalD );
				cout << " Error on bars : " << sigma_D_real << "\n";
				PREDICT_D_REAL80->SetBinContent(counta,DoD);
				PREDICT_D_REAL80->SetBinError(counta,sigma_D_real);
				PREDICT_D_NUMBER80->SetBinContent(counta,totalD80);
			
			}
			if(b==85){
				HIST_D_cut85->Fill(a,totalD);
				sigma_D_real = sigma_D / totalD;
				DoD = (1.*Dth / totalD );
				//cout << " Error on bars : " << sigma_D_real << "\n";
				PREDICT_D_REAL85->SetBinContent(counta,DoD);
				PREDICT_D_REAL85->SetBinError(counta,sigma_D_real);
				PREDICT_D_NUMBER85->SetBinContent(counta,totalD85);
			
			}
			
			
			// remplir avec la möthode ABCD dans l'histogramme  et le superposer avec l'information sur les erreurs 
			//Dth = ((totalB *1.* totalC )/ totalA);
			//cout << "Dth : " << Dth <<"\n";
			

			
			cout << "a = " << a << "\n"<<endl;
			//cout << "Total D2 = " << totalD2 << "\n";
	

	
			//cout << "totalD2 in third for " << totalD2 << endl;
			cout << "A = " << totalA << " B = " << totalB << " C = " << totalC << " D = " << totalD <<" D predit : " << Dth << " Erreur sur D : " << sigma_D << "\n"<<endl;
	
			
		
		
			cout << "Total D 65 : " << totalD65 << " Total D 70 : " << totalD70 << " Total D 75 : " << totalD75 << " Total D 80 : " << totalD80 << " Total D 85 : " << totalD85 << "\n \n";
			totalD65=0,totalD70=0,totalD75=0,totalD80=0,totalD85=0;
		} // END for a
	} //END for b
	
	//cout << " Total D 65 : " << totalD65 << " Total D 70 : " << totalD70 << " Total D 75 : " << totalD75 << " Total D 80 : " << totalD80 << " Total D 85 : " << totalD85 << endl; 
	
	cout << "Total D2 = " << totalD2 << "\n"<<endl;
	int Sum = totalA + totalB + totalC + totalD;
	//cout<<" A = "<< totalA << " B = " << totalB <<" C = " << totalC << " D = "<< totalD <<"\n" << "Sum : " << Sum << " Total D2 = " << totalD2 << endl;
	
	
	
	
	int nentryA=0, nentryB=0, nentryC=0;
	
	double p,ih;
	double nentriesa = HIST_MASS_a->GetEntries();
	double nentriesb = HIST_MASS_b->GetEntries();
	double nentriesc = HIST_MASS_c->GetEntries();
	double nentriesd = HIST_MASS_d->GetEntries();
	double de = (nentriesb * 1.*nentriesc / nentriesa);
	double dd = (mmax - mmin) / mbin ; //Taile d'un bin * i + db pour aovirl em ilieu du bin i
	double db = dd/2 ; //Obtenir le milieu d'un bin
	
	cout << " N entries a : " << nentriesa << " N entries b : " << nentriesb << " N entries c : " << nentriesc << " N entries d : " << nentriesd <<" Estimated D on entries : " << de << "\n"<<endl;
	
	
	
	
//ATTENTION ici il faut la masse que dans D

	
	
//**************************************MASSES PREVISIONNELLES DANS D ************************************************************************ 
	
	int compteur0=0;
	int compteurx=0;
	for(int s = 0; s <= (nbinxb + 1) ; s++){ //p
		for(int k = 0; k<= (nbinxc + 1) ; k++ ){ //ih
			double m=0;
			double weight = (((HIST_MASS_b->GetBinContent(s))*1.*(HIST_MASS_c->GetBinContent(k)))/nentriesa) ;
			
			
			
			ih = HIST_MASS_b->GetBinCenter(s); // B_ih  enregistrer et regarder à l'oeil, sauver P et IH en plus de PT IAS ETA 
			
			p = HIST_MASS_c->GetBinCenter(k);// C_P
			
			//cout << "p = " << p << "ih = " << ih<< "\n"<<endl;
			
			if(ih > C ){
				m = sqrt(((p*p) * (ih - C ))/K);
				HIST_MASS->Fill(m,weight);
				//cout << "m = " << m << " with weight = " << weight<< "Cont S = " << (HIST_MASS_b->GetBinContent(s))<< "Cont K = " << (HIST_MASS_c->GetBinContent(k)) <<" nentriesa = " <<nentriesa << "\n";
				compteurx+=1;
			
			}
			
			else {
				//HIST_MASS->Fill(m);
				compteur0+=1;
			
			}
			
			
			//HIST_MASS->Fill(m);
			
		
		}
	}
	cout<<" Number of masses equal to 0 : " << compteur0<< " Number dif than 0 : " << compteurx << "\n";
	

//********************************************************************************************************************************************







	/*TCanvas *c1 = new TCanvas("c1","A Simple Graph Example",200,10,500,300);
	Double_t x[100], y[100];
	Int_t n = 20;
	for (Int_t i=0;i<n;i++) {
		x[i] = i*0.1;
		y[i] = 10*sin(x[i]+0.2);
   	}
	TGraph* gr = new TGraph(n,x,y);

	for(double IASF = 55 ; IASF < 90 ; IASF += 1){

	} 

	*/
   	


//********************************************* SETUP all graphs within canvas***************************************************
	
	
	HIST_D_cut65->SetLineColorAlpha(kBlue, 0.7); 
	HIST_D_cut65->SetLineStyle(1);
	HIST_D_cut65->SetLineWidth(2);
	
	
	HIST_D_cut70->SetLineColorAlpha(kGreen, 0.7);
	HIST_D_cut70->SetLineStyle(1);
	HIST_D_cut70->SetLineWidth(3);
	
	
	HIST_D_cut75->SetLineColorAlpha(kPink, 0.7);
	HIST_D_cut75->SetLineStyle(1);
	HIST_D_cut75->SetLineWidth(3);
	
	
	HIST_D_cut80->SetLineColorAlpha(kOrange, 0.7);
	HIST_D_cut80->SetLineStyle(1);
	HIST_D_cut80->SetLineWidth(2);
	
	
	HIST_D_cut85->SetLineColorAlpha(kBlack, 0.35);
	HIST_D_cut85->SetLineStyle(1);
	HIST_D_cut85->SetLineWidth(2);
	
	
	HIST_MASS_b3->SetLineColorAlpha(kBlue, 0.7);
	HIST_MASS_b3->SetLineStyle(1);
	HIST_MASS_b3->SetLineWidth(2);
	
	
	HIST_MASS_d2->SetLineColorAlpha(kRed, 0.7);
	HIST_MASS_d2->SetLineStyle(1);
	HIST_MASS_d2->SetLineWidth(2);
	
	MASS_D_toto->SetLineColorAlpha(kBlue, 0.7);
	MASS_D_toto->SetLineStyle(1); //sauvegarde
	MASS_D_toto->SetLineWidth(1);
	
	HIST_MASS->SetLineColorAlpha(2, 0.7);
	HIST_MASS->SetLineStyle(1);
	HIST_MASS->SetLineWidth(1); 
	
	PREDICT_D_REAL65->SetLineColorAlpha(4, 0.7);
	PREDICT_D_REAL65->SetLineStyle(1);
	PREDICT_D_REAL65->SetLineWidth(1);
	
	
	PREDICT_D_REAL70->SetLineColorAlpha(8, 0.7);
	PREDICT_D_REAL70->SetLineStyle(1);
	PREDICT_D_REAL70->SetLineWidth(1);
	
	PREDICT_D_REAL75->SetLineColorAlpha(6, 0.7);
	PREDICT_D_REAL75->SetLineStyle(1);
	PREDICT_D_REAL75->SetLineWidth(1);
	
	PREDICT_D_REAL80->SetLineColorAlpha(kOrange, 0.7);
	PREDICT_D_REAL80->SetLineStyle(1);
	PREDICT_D_REAL80->SetLineWidth(1);
	
	PREDICT_D_REAL85->SetLineColorAlpha(1, 0.4);
	PREDICT_D_REAL85->SetLineStyle(1);
	PREDICT_D_REAL85->SetLineWidth(1);


	DOD_D->SetLineColorAlpha(2, 0.7);
	DOD_D->SetLineStyle(1);
	DOD_D->SetLineWidth(3); 


//************************************c3->Modified() and c3->Update() or it doesnt work ? ************************

//************************************ Legend + all D with cuts  Canvas 8*************************************************
	
	
	
	TCanvas *c8 = new TCanvas("c8","c8",200,10,500,300);
	auto *mg = new TMultiGraph();
	TLegend* leg8 = new TLegend(0.7, 0.8, .5, .6);
	
	c8->cd();
	
	Double_t x[100], y[100], x_2 [100], y_2[100], x_3[100], y_3[100], x_4[100], y_4[100], x_5[100], y_5[100];
	Int_t n = 25;
	for (Int_t i=0;i<n;i++) {
     
		x[i] = i*0.012 + 0.006 ;
		y[i] = HIST_D_cut65->GetBinContent(i);
	}
	
	auto gr = new TGraph(n,x,y);
	mg->Add(gr);
	gr->SetLineColorAlpha(4, 0.7);
	leg8->AddEntry(HIST_D_cut65, "Cut Pt = 65", "l");
	//gr->Draw("AC*");

	
	for (Int_t i=0;i<n;i++) {
     
		x_2[i] = i*0.012 + 0.006 ;
		y_2[i] = HIST_D_cut70->GetBinContent(i);
	}
	
	auto gr2 = new TGraph(n,x_2,y_2);
	mg->Add(gr2);
	gr2->SetLineColorAlpha(8, 0.7);
	leg8->AddEntry(HIST_D_cut70, "Cut Pt = 70", "l");
	//gr2->Draw("AC* SAME");
	
	for (Int_t i=0;i<n;i++) {
     
		x_3[i] = i*0.012 + 0.006 ;
		y_3[i] = HIST_D_cut75->GetBinContent(i);
	}
	
	auto gr3 = new TGraph(n,x_3,y_3);
	mg->Add(gr3);
	gr3->SetLineColorAlpha(6, 0.7);
	leg8->AddEntry(HIST_D_cut75, "Cut Pt = 75", "l");
	//gr3->Draw("AC* SAME");
	
	for (Int_t i=0;i<n;i++) {
     
		x_4[i] = i*0.012 + 0.006 ;
		y_4[i] = HIST_D_cut80->GetBinContent(i);
	}
	
	auto gr4 = new TGraph(n,x_4,y_4);
	mg->Add(gr4);
	gr4->SetLineColorAlpha(kOrange, 0.7);
	leg8->AddEntry(HIST_D_cut80, "Cut Pt = 80", "l");
	//gr4->Draw("AC* SAME");
	
	for (Int_t i=0;i<n;i++) {
     
		x_5[i] = i*0.012 + 0.006 ;
		y_5[i] = HIST_D_cut85->GetBinContent(i);
	}
	

	auto gr5 = new TGraph(n,x_5,y_5);
	mg->Add(gr5);
	gr5->SetLineColorAlpha(1, 0.7);
	leg8->AddEntry(HIST_D_cut85, "Cut Pt = 85", "l");
	//gr5->Draw("AC* SAME");
	
	mg->SetTitle("D candidates for various PT/IAS ; IAS ; nb of candidates");
	mg->Draw("AC*"); 
	leg8->Draw();
	
	
//******************************************************************* Canvas 3 ********************************************************
	TCanvas* c3 = new TCanvas("Dth/Dreal for diff PT/IAS", "Cuts on D",500,500); // Creates canvas c3 that will merge all cuts
	TLegend* leg3 = new TLegend(0.7, 0.8, .5, .6); // Legends for canvas c3
	leg3->SetBorderSize(0); // Removes the border of legend
	c3->cd();
	
	HIST_D_cut65->Draw("hist");
	c3->Modified();
	c3->Update();
	leg3->AddEntry(HIST_D_cut65, "Cut Pt = 65", "l");
	

	HIST_D_cut70->Draw("hist SAME");
	c3->Modified();
	c3->Update();
	leg3->AddEntry(HIST_D_cut70, "Cut Pt = 70", "l");

	HIST_D_cut75->Draw("hist SAME");
	c3->Modified();
	c3->Update();
	leg3->AddEntry(HIST_D_cut75, "Cut Pt = 75", "l");

	HIST_D_cut80->Draw("hist SAME");
	c3->Modified();
	c3->Update();
	leg3->AddEntry(HIST_D_cut80, "Cut Pt = 80", "l");
	

	HIST_D_cut85->Draw("hist SAME");
	c3->Modified();
	c3->Update();
	leg3->AddEntry(HIST_D_cut85, "Cut Pt = 85", "l");
	
	
	leg3->Draw();
	//c3->SaveAs("CutsPTandD.pdf");
	
//************************************************ Canvas 2 B_P D_P *********************************************	
	TCanvas* c2 = new TCanvas("c2", "c2", 500,500);
	
	c2->cd();

	//HIST_MASS_d2->Draw();
	//HIST_MASS_b2->Draw("SAME");
	HIST_MASS_b3->Draw();
	HIST_MASS_d2->Draw("SAME");
	
//*************************************************************************************************************


	
//********************************************* Canvas 4 Real mass vs Predicted MAss *****************************

	TCanvas* c4 = new TCanvas("c4", "Real Masses vs Predicted Masses", 500,500);
	TLegend* leg4 = new TLegend(0.7, 0.8, .5, .6); // Legends for canvas c4
	
	c4->cd();
	
	HIST_MASS->Rebin(10);
	MASS_D_toto->Rebin(10);
	
	MASS_D_toto->Draw("hist"); //Real mass
	leg4->AddEntry(MASS_D_toto, "Real Masses", "l");
	
	HIST_MASS->Draw("hist SAME"); //Masses previsionnelles
	leg4->AddEntry(HIST_MASS, "Predicted Masses", "l");
	
	
	
	leg4->Draw();

//*************************************************************************************************************

//********************************************* Canvas 5 All the Dth/Dreel for different PTs and IAS *****************************

	TCanvas* c5 = new TCanvas("D_Cuts", "Cuts on D",500,500); // Creates canvas c3 that will merge all cuts
	TLegend* leg5 = new TLegend(0.7, 0.8, .5, .6); // Legends for canvas c3
	leg5->SetBorderSize(0); // Removes the border of legend
	c5->cd();
	
	PREDICT_D_REAL65->Draw();
	c5->Modified();
	c5->Update();
	leg5->AddEntry(PREDICT_D_REAL65, "Cut Pt = 65", "l");
	

	PREDICT_D_REAL70->Draw("SAME");
	c5->Modified();
	c5->Update();
	leg5->AddEntry(PREDICT_D_REAL70, "Cut Pt = 70", "l");

	PREDICT_D_REAL75->Draw("SAME");
	c5->Modified();
	c5->Update();
	leg5->AddEntry(PREDICT_D_REAL75, "Cut Pt = 75", "l");

	PREDICT_D_REAL80->Draw("SAME");
	c5->Modified();
	c5->Update();
	leg5->AddEntry(PREDICT_D_REAL80, "Cut Pt = 80", "l");
	
	PREDICT_D_REAL85->Draw("SAME");
	c5->Modified();
	c5->Update();
	leg5->AddEntry(PREDICT_D_REAL85, "Cut Pt = 85", "l");
	
	
	leg5->Draw();
	//c3->SaveAs("CutsPTandD.pdf"); //Saves file as PDF or ROOT or...



//*************************************************************************************************************
	
	
	
	
	TCanvas* c9 = new TCanvas("c9", "DoD as a fct of D", 500,500);
	TLegend* leg9 = new TLegend(0.7, 0.8, .5, .6); 
	
	c9->cd();
	
	
	DOD_D->Draw("C"); 
	leg9->AddEntry(DOD_D, "DoD as a function of D for PT = 65", "l");
	
	leg9->Draw();
	


//*********************************** Writing all histogramms**************************************************


	OutputHisto->cd();

	HIST_MASS->Write();
	MASS_D_toto->Write();
	HIST_D_cut65->Write();
	HIST_D_cut70->Write();
	HIST_D_cut75->Write();
	HIST_D_cut80->Write();
	HIST_D_cut85->Write();
	PREDICT_D_REAL65->Write();
	PREDICT_D_REAL70->Write();
	PREDICT_D_REAL75->Write();
	PREDICT_D_REAL80->Write();
	PREDICT_D_REAL85->Write();
	PREDICT_D_NUMBER65->Write();
	PREDICT_D_NUMBER70->Write();
	PREDICT_D_NUMBER75->Write();
	PREDICT_D_NUMBER80->Write();
	PREDICT_D_NUMBER85->Write();
	DOD_D->Write();
	//RANDOM_PT->Write();
	//RANDOM_IAS->Write();
	
	//OutputHisto->Close();
	

}
//*************************************************************************************************************









//***********************************************FUNCTION FOR RANDOMISATION ****************************************************** START


double generation(){

	double E_A ,E_B,E_C,E_D,sigma_D,sigma_D_divided,Dpredit,dod;

	double sizeonea = 0.012 , sizeoneb = ((1550 - 50 )/ 300) ;
	double weight,b=65;
	
	int nA =0,nB=0,nC=0,nD=0;
	int counta=5;
	
	
//*******************************************************DECLARING HISTOGRAMMS*******************************************************
	
	TH2D* RANDOM_PT_IAS = new TH2D("RANDOM_PT_IAS", "PT ( IAS ) ", 100 , 0 , 1.2 , 300, 50 , 1550 );
	
	
	TH1D* RANDOM_PT = new TH1D("Random pts" , "random PT", 100 , 50 , 1550 );
	TH1D* RANDOM_IAS = new TH1D("Random ias" , "Random IAS", 100 , 0 , 1.2);
	TH1D* PREDICT_D = new TH1D("Prediction for D with different cuts on IAS" , "Predit D w/ IAS ", 100 , 0 , 1.2);
	
	
//***********************************************************************************************************************************
	
	
	
//*****************************************************SUMW2*************************************************************************
	
	RANDOM_PT->Sumw2();
	RANDOM_IAS->Sumw2();
	PREDICT_D->Sumw2();
	
	
//***********************************************************************************************************************************
	//srand((unsigned)time(NULL));
	
	for(int i=0;i<1000000;i++){
		double j = ran_expo(0.01);
		//cout<< "Le "<<i<<"eme numero est : " <<  j << "\n";
		RANDOM_PT->Fill(j);
		
		double s = ran_expo(15) ; //n_expo(0.01)/1000);
		//cout << " s = " << s << endl;
		RANDOM_IAS->Fill(s);
		
	}
	

	
	RANDOM_PT->Write();
	RANDOM_IAS->Write();
	
	
	//for(int b=65;b<90;b+=5){
		//cout << " PT cut = " << b << "\n";
	
	for(double a=0.012;a<=0.3;a+=0.012) //Attention i++ / i--  calcul avec largeur des bins ***START 0.012, end 0.3 ?
	{	
		nA=0,nB=0,nC=0,nD=0;
		counta+= 1;		
	
		for ( int u = 0 ; u<=(100+1); u++){
	
			for (int i = 0 ; i<=(300+1);i++){
				//cout << " Bin " << u << " ias : " << RANDOM_IAS->GetBinCenter(u) << " Bin " << i << " pt : " << RANDOM_PT->GetBinCenter(i) << "\n"; // PROBLEME
			
				weight = ( RANDOM_PT->GetBinContent(i) *1. * RANDOM_IAS->GetBinContent(u)) / 30804 ;
			
				//cout << " Bin " << u << " ias : " << RANDOM_IAS->GetBinContent(u) << " Bin " << i << " pt : " << RANDOM_PT->GetBinContent(i) << "\n";
			
				//cout << "weight = " << weight << "\n";
			
				RANDOM_PT_IAS->Fill((RANDOM_IAS->GetBinCenter(u)),(RANDOM_PT->GetBinCenter(i)),weight);
			
				if ( ((u * sizeonea) <= a )  && ((( i*sizeoneb + 50 ) <= b))){ //
					nA += RANDOM_PT_IAS->GetBinContent(u,i); //nombre d'évènements dans une boite pour le double for
				
				}
			
				if(((u*sizeonea) > a) && (((i*sizeoneb +50 )<= b))){
					nB += RANDOM_PT_IAS->GetBinContent(u,i);
			
				}
			
				if(((u*sizeonea) <= a) && (((i*sizeoneb+50) > b))){
					nC += RANDOM_PT_IAS->GetBinContent(u,i);
				}
			
				if(((u*sizeonea) > a) && (((i*sizeoneb +50 )> b))){
					nD += RANDOM_PT_IAS->GetBinContent(u,i);
						//cout << " IN FOR : a = " << (u*sizeonea) << " b = " << (i*sizeoneb +50 ) << "TotalD2 : " << totalD2 << "\n";
			
				}
			}
		}
	
		E_A = sqrt(nA) ; 
		cout << " nA = " << nA << " sqrt(nA) = " << sqrt(nA) << "\n";
		E_B = sqrt(nB) ;
		E_C = sqrt(nC) ;
		E_D = sqrt(nD) ;
	
		sigma_D=nD*sqrt(((E_A/nA)*(E_A/nA))+((E_B/nB)*(E_B/nB))+((E_C/nC)*(E_C/nC)));
		cout << " Error on D : " << sigma_D << "\n";
	
		sigma_D_divided = sigma_D / nD;
		cout << " Error on D o D : " << sigma_D_divided << "\n";
		
		Dpredit = (nC *1.* nB) / nA ;
		dod = 1.*Dpredit/nD ;
		
		cout << " # bin " << counta << " Center of bin :  "  << PREDICT_D->GetBinCenter(counta) << " a = " << a<< "\n";
	
		PREDICT_D->SetBinContent(counta,dod);
		
		PREDICT_D->SetBinError(counta,sigma_D_divided);
		cout << "D o D = " << dod << " # in D :" << nD << " # predicted : " << Dpredit << "\n";
		
	}
	//}
	
	
	//int Dpredit = (nC *1.* nB) / nA ;
	//double dod = Dpredit/nD ;
	//cout << "Number of candidates in zone D : " << nD << " Number of candidates predicted : " << Dpredit <<  "\n";
	//cout << "D o D = " << dod << "\n";
	
	
	//RANDOM_PT_IAS->Write();
	
	
	TCanvas* c5 = new TCanvas("c5", "Random PTs", 500,500);
	c5->cd();
	RANDOM_PT->Draw("hist");
	
	TCanvas* c6 = new TCanvas("c6", "Random IAS", 500,500);
	RANDOM_IAS->Draw("hist");
	
	TCanvas* c7 = new TCanvas("c7", "Random PT_IAS", 500,500);
	RANDOM_PT_IAS->Draw("hist");
	
	TCanvas* c8 = new TCanvas("c8", "Prediction", 500,500);
	PREDICT_D->Draw();
	
	return 0;
}





//******************************************************************************************************************************

double ran_expo(double lambda){
    double u;
    u = rand() / (RAND_MAX + 1.0);
    return - log(1- u) / lambda;
}






