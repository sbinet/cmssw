#include "RecoBTag/Analysis/interface/TrackCountingTagPlotter.h"

TrackCountingTagPlotter::TrackCountingTagPlotter(const TString & tagName,
	const EtaPtBin & etaPtBin, const edm::ParameterSet& pSet, bool update) :
	BaseTagInfoPlotter(tagName, etaPtBin)
{

  nBinEffPur_  = pSet.getParameter<int>("nBinEffPur");
  startEffPur_ = pSet.getParameter<double>("startEffPur");
  endEffPur_   = pSet.getParameter<double>("endEffPur");

  finalized = false;
  if (update){
  TString dir= "TrackCounting"+theExtensionString;
  gFile->cd();
  gFile->cd(dir);
  }

  trkNbr3D = new FlavourHistograms<int>
	("selTrksNbr_3D" + theExtensionString, "Number of selected tracks for 3D IPS" + theExtensionString, 31, -0.5, 30.5,
	false, true, true, "b", update);

  trkNbr2D = new FlavourHistograms<int>
	("selTrksNbr_2D" + theExtensionString, "Number of selected tracks for 2D IPS" + theExtensionString, 31, -0.5, 30.5,
	false, true, true, "b", update);

  lowerIPSBound = -35.0;
  upperIPSBound = +35.0;

  tkcntHistosSig3D[4] = new FlavourHistograms<double>
       ("ips_3D" + theExtensionString, "3D Significance of impact parameter",
	50, lowerIPSBound, upperIPSBound, false, true, true, "b", update) ;

  tkcntHistosSig3D[0] = new FlavourHistograms<double>
       ("ips1_3D" + theExtensionString, "3D Significance of impact parameter 1st trk",
	50, lowerIPSBound, upperIPSBound, false, true, true, "b", update) ;

  tkcntHistosSig3D[1] = new FlavourHistograms<double>
       ("ips2_3D" + theExtensionString, "3D Significance of impact parameter 2nd trk",
	50, lowerIPSBound, upperIPSBound, false, true, true, "b", update) ;

  tkcntHistosSig3D[2] = new FlavourHistograms<double>
       ("ips3_3D" + theExtensionString, "3D Significance of impact parameter 3rd trk",
	50, lowerIPSBound, upperIPSBound, false, true, true, "b", update) ;

  tkcntHistosSig3D[3] = new FlavourHistograms<double>
       ("ips4_3D" + theExtensionString, "3D Significance of impact parameter 4th trk",
	50, lowerIPSBound, upperIPSBound, false, true, true, "b", update) ;

  tkcntHistosSig2D[4] = new FlavourHistograms<double>
       ("ips_2D" + theExtensionString, "2D Significance of impact parameter",
	50, lowerIPSBound, upperIPSBound, false, true, true, "b", update) ;

  tkcntHistosSig2D[0] = new FlavourHistograms<double>
       ("ips1_2D" + theExtensionString, "2D Significance of impact parameter 1st trk",
	50, lowerIPSBound, upperIPSBound, false, true, true, "b", update) ;

  tkcntHistosSig2D[1] = new FlavourHistograms<double>
       ("ips2_2D" + theExtensionString, "2D Significance of impact parameter 2nd trk",
	50, lowerIPSBound, upperIPSBound, false, true, true, "b", update) ;

  tkcntHistosSig2D[2] = new FlavourHistograms<double>
       ("ips3_2D" + theExtensionString, "2D Significance of impact parameter 3rd trk",
	50, lowerIPSBound, upperIPSBound, false, true, true, "b", update) ;

  tkcntHistosSig2D[3] = new FlavourHistograms<double>
       ("ips4" + theExtensionString, "2D Significance of impact parameter 4th trk",
	50, lowerIPSBound, upperIPSBound, false, true, true, "b", update) ;

}


TrackCountingTagPlotter::~TrackCountingTagPlotter ()
{

  delete trkNbr3D;
  delete trkNbr2D;

  for(int n=0; n <= 4; n++) {
    delete tkcntHistosSig2D[n];
    delete tkcntHistosSig3D[n];
  }
  if (finalized) {
    for(int n=0; n < 4; n++) delete effPurFromHistos[n];
  }
}


void TrackCountingTagPlotter::analyzeTag (const reco::BaseTagInfo * baseTagInfo,
	const int & jetFlavour)
{

  const reco::TrackCountingTagInfo * tagInfo = 
	dynamic_cast<const reco::TrackCountingTagInfo *>(baseTagInfo);

  if (!tagInfo) {
    throw cms::Exception("Configuration")
      << "BTagPerformanceAnalyzer: Extended TagInfo not of type TrackCountingTagInfo. " << endl;
  }

  trkNbr3D->fill(jetFlavour, tagInfo->selectedTracks(0));
  trkNbr2D->fill(jetFlavour, tagInfo->selectedTracks(1));

  for(int n=0; n < tagInfo->selectedTracks(1) && n < 4; n++)
    tkcntHistosSig2D[n]->fill(jetFlavour, tagInfo->significance(n,1));
  for(int n=tagInfo->selectedTracks(1); n < 4; n++)
    tkcntHistosSig2D[n]->fill(jetFlavour, lowerIPSBound-1.0);

  for(int n=0; n < tagInfo->selectedTracks(0) && n < 4; n++)
    tkcntHistosSig3D[n]->fill(jetFlavour, tagInfo->significance(n,0));
  for(int n=tagInfo->selectedTracks(0); n < 4; n++)
    tkcntHistosSig3D[n]->fill(jetFlavour, lowerIPSBound-1.0);

  for(int n=0; n < tagInfo->selectedTracks(1); n++)
    tkcntHistosSig2D[4]->fill(jetFlavour, tagInfo->significance(n,1));
  for(int n=0; n < tagInfo->selectedTracks(0); n++)
    tkcntHistosSig3D[4]->fill(jetFlavour, tagInfo->significance(n,0));
}

void TrackCountingTagPlotter::finalize ()
{
  //
  // final processing:
  // produce the misid. vs. eff histograms
  //
  effPurFromHistos[0] = new EffPurFromHistos (tkcntHistosSig3D[1],
		nBinEffPur_, startEffPur_,
		endEffPur_);
  effPurFromHistos[1] = new EffPurFromHistos (tkcntHistosSig3D[2],
		nBinEffPur_, startEffPur_,
		endEffPur_);
  effPurFromHistos[2] = new EffPurFromHistos (tkcntHistosSig2D[1],
		nBinEffPur_, startEffPur_,
		endEffPur_);
  effPurFromHistos[3] = new EffPurFromHistos (tkcntHistosSig2D[2],
		nBinEffPur_, startEffPur_,
		endEffPur_);
  for(int n=0; n < 4; n++) effPurFromHistos[n]->compute();
  finalized = true;
}

void TrackCountingTagPlotter::psPlot(const TString & name)
{
  TString cName = "TrackCountingPlots"+ theExtensionString;
  setTDRStyle()->cd();
  TCanvas canvas(cName, "TrackCountingPlots"+ theExtensionString, 600, 900);
  canvas.UseCurrentStyle();
  canvas.Divide(2,3);
  canvas.Print(name + cName + ".ps[");

  canvas.cd(1);
  trkNbr3D->plot();
  canvas.cd(2);
  tkcntHistosSig3D[4]->plot();
  for(int n=0; n < 4; n++) {
    canvas.cd(3+n);
    tkcntHistosSig3D[n]->plot();
  }

  canvas.Print(name + cName + ".ps");
  canvas.Clear();
  canvas.Divide(2,3);

  canvas.cd(1);
  trkNbr2D->plot();
  canvas.cd(2);
  tkcntHistosSig2D[4]->plot();
  for(int n=0; n < 4; n++) {
    canvas.cd(3+n);
    tkcntHistosSig2D[n]->plot();
  }

  if (finalized) {
    for(int n=0; n < 2; n++) {
      canvas.Print(name + cName + ".ps");
      canvas.Clear();
      canvas.Divide(2,3);
      canvas.cd(1);
      effPurFromHistos[0+n]->discriminatorNoCutEffic()->plot();
      canvas.cd(2);
      effPurFromHistos[0+n]->discriminatorCutEfficScan()->plot();
      canvas.cd(3);
      effPurFromHistos[0+n]->plot();
      canvas.cd(4);
      effPurFromHistos[1+n]->discriminatorNoCutEffic()->plot();
      canvas.cd(5);
      effPurFromHistos[1+n]->discriminatorCutEfficScan()->plot();
      canvas.cd(6);
      effPurFromHistos[1+n]->plot();
    }
  }

  canvas.Print(name + cName + ".ps");
  canvas.Print(name + cName + ".ps]");
}

void TrackCountingTagPlotter::write(const bool allHisto)
{
  TString dir= "TrackCounting"+theExtensionString;
  gFile->cd();
  gFile->mkdir(dir);
  gFile->cd(dir);
  trkNbr2D->write(allHisto);
  trkNbr3D->write(allHisto);
  for(int n=0; n <= 4; n++) {
    tkcntHistosSig2D[n]->write(allHisto);
    tkcntHistosSig3D[n]->write(allHisto);
  }
  if (finalized) {
    for(int n=0; n < 4; n++) effPurFromHistos[n]->write(allHisto);
  }
  gFile->cd();
}

void TrackCountingTagPlotter::epsPlot(const TString & name)
{
  trkNbr2D->epsPlot(name);
  trkNbr3D->epsPlot(name);
  for(int n=0; n <= 4; n++) {
    tkcntHistosSig2D[n]->epsPlot(name);
    tkcntHistosSig3D[n]->epsPlot(name);
  }
  if (finalized) {
    for(int n=0; n < 4; n++) effPurFromHistos[n]->epsPlot(name);
  }
}
