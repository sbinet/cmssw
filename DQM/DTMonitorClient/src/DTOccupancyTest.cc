

/*
 *  See header file for a description of this class.
 *
 *  $Date: 2008/06/05 12:50:59 $
 *  $Revision: 1.5 $
 *  \author G. Cerminara - University and INFN Torino
 */


#include <DQM/DTMonitorClient/src/DTOccupancyTest.h>
#include <DQM/DTMonitorClient/src/DTOccupancyClusterBuilder.h>

#include "FWCore/ServiceRegistry/interface/Service.h"
#include <FWCore/Framework/interface/LuminosityBlock.h>
#include <FWCore/Framework/interface/EventSetup.h>
#include "Geometry/Records/interface/MuonGeometryRecord.h"
#include "Geometry/DTGeometry/interface/DTGeometry.h"
#include "DQMServices/Core/interface/DQMStore.h"
#include "DQMServices/Core/interface/MonitorElement.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"

#include "TMath.h"

using namespace edm;
using namespace std;




DTOccupancyTest::DTOccupancyTest(const edm::ParameterSet& ps){
  LogVerbatim ("DTOccupancyTest") << "[DTOccupancyTest]: Constructor";

  // Get the DQM service
  dbe = Service<DQMStore>().operator->();

  lsCounter = 0;

  writeRootFile  = ps.getUntrackedParameter<bool>("writeRootFile", false);
  if(writeRootFile) {
    rootFile = new TFile("DTOccupancyTest.root","RECREATE");
    ntuple = new TNtuple("OccupancyNtuple", "OccupancyNtuple", "ls:wh:st:se:lay1MeanCell:lay1RMS:lay2MeanCell:lay2RMS:lay3MeanCell:lay3RMS:lay4MeanCell:lay4RMS:lay5MeanCell:lay5RMS:lay6MeanCell:lay6RMS:lay7MeanCell:lay7RMS:lay8MeanCell:lay8RMS:lay9MeanCell:lay9RMS:lay10MeanCell:lay10RMS:lay11MeanCell:lay11RMS:lay12MeanCell:lay12RMS");
  }

}




DTOccupancyTest::~DTOccupancyTest(){
  LogVerbatim ("DTOccupancyTest") << " destructor called" << endl;


}




void DTOccupancyTest::beginJob(const EventSetup& context){
  LogVerbatim ("DTOccupancyTest") << "[DTOccupancyTest]: BeginJob";

  // Event counter
  nevents = 0;

  // Get the geometry
  context.get<MuonGeometryRecord>().get(muonGeom);

  // Book the histos
  for(int wh = -2; wh <= 2; ++wh) { // loop over wheels
    bookHistos(wh, string("Occupancies"), "OccupancySummary");
  }

  dbe->setCurrentFolder("DT/01-Digi/");
  summaryHisto = dbe->book2D("OccupancySummary","Occupancy Summary",12,1,13,5,-2,3);
  summaryHisto->setAxisTitle("sector",1);
  summaryHisto->setAxisTitle("wheel",2);

}




void DTOccupancyTest::beginLuminosityBlock(LuminosityBlock const& lumiSeg, EventSetup const& context) {
  LogVerbatim ("DTOccupancyTest") <<"[DTOccupancyTest]: Begin of LS transition";
}




void DTOccupancyTest::analyze(const Event& e, const EventSetup& context) {
  nevents++;
  LogVerbatim ("DTOccupancyTest") << "[DTOccupancyTest]: "<<nevents<<" events";


}




void DTOccupancyTest::endLuminosityBlock(LuminosityBlock const& lumiSeg, EventSetup const& context) {
  LogVerbatim ("DTOccupancyTest")
    <<"[DTOccupancyTest]: End of LS transition, performing the DQM client operation";
  lsCounter++;



  // Reset the global summary
  summaryHisto->Reset();


  // Get all the DT chambers
  vector<DTChamber*> chambers = muonGeom->chambers();

  for(vector<DTChamber*>::const_iterator chamber = chambers.begin();
      chamber != chambers.end(); ++chamber) {  // Loop over all chambers
    DTChamberId chId = (*chamber)->id();

    MonitorElement * chamberOccupancyHisto = dbe->get(getMEName("OccupancyAllHits_perCh", chId));	

    // Run the tests on the plot for the various granularities
    if(chamberOccupancyHisto != 0) {
      // Get the 2D histo
      TH2F* histo = chamberOccupancyHisto->getTH2F();
      int result = runOccupancyTest(histo, chId);
      int sector = chId.sector();

      if(sector == 13) {
	sector = 4;
	float resultSect4 = wheelHistos[chId.wheel()]->getBinContent(sector, chId.station());
	if(resultSect4 > result) {
	  result = (int)resultSect4;
	}
      } else if(sector == 14) {
	sector = 10;
	float resultSect10 = wheelHistos[chId.wheel()]->getBinContent(sector, chId.station());
	if(resultSect10 > result) {
	  result = (int)resultSect10;
	}
      }
      wheelHistos[chId.wheel()]->setBinContent(sector, chId.station(),result);
      if(result > summaryHisto->getBinContent(sector, chId.wheel()+3)) {
	summaryHisto->setBinContent(sector, chId.wheel()+3, result);
      }
    } else {
      LogVerbatim ("DTOccupancyTest") << "[DTOccupancyTest] ME: "
				      << getMEName("OccupancyAllHits_perCh", chId) << " not found!" << endl;
    }

  }

  // Fill the global summary
  // Check for entire sectors off and report them on the global summary
  //FIXME: TODO

  if(writeRootFile) ntuple->AutoSave("SaveSelf");

}


void DTOccupancyTest::endJob(){

  LogVerbatim ("DTOccupancyTest") << "[DTOccupancyTest] endjob called!";
  if(writeRootFile) {
    rootFile->cd();
    ntuple->Write();
    rootFile->Close();
  }
}


  
// --------------------------------------------------
void DTOccupancyTest::bookHistos(const int wheelId, string folder, string histoTag) {
  // Set the current folder
  stringstream wheel; wheel << wheelId;	
  dbe->setCurrentFolder("DT/01-Digi/");

  // build the histo name
  string histoName = histoTag + "_W" + wheel.str(); 
  
  
  LogVerbatim ("DTOccupancyTest") <<"[DTOccupancyTest]: booking wheel histo:"<< endl
				  <<"              folder "<< "DT/01-Digi/Wheel"
    + wheel.str() + "/" + folder << endl
				  <<"              histoTag "<<histoTag << endl
				  <<"              histoName "<<histoName<<endl;
  
  string histoTitle = "Occupancy summary WHEEL: "+wheel.str();
  wheelHistos[wheelId] = dbe->book2D(histoName,histoTitle,12,1,13,4,1,5);
  wheelHistos[wheelId]->setBinLabel(1,"MB1",2);
  wheelHistos[wheelId]->setBinLabel(2,"MB2",2);
  wheelHistos[wheelId]->setBinLabel(3,"MB3",2);
  wheelHistos[wheelId]->setBinLabel(4,"MB4",2);
  wheelHistos[wheelId]->setAxisTitle("sector",1);
}



string DTOccupancyTest::getMEName(string histoTag, const DTChamberId& chId) {

  stringstream wheel; wheel << chId.wheel();
  stringstream station; station << chId.station();
  stringstream sector; sector << chId.sector();


  string folderRoot = "DT/01-Digi/Wheel" + wheel.str() +
    "/Station" + station.str() +
    "/Sector" + sector.str() + "/";

  string folder = "Occupancies/";
  
  // build the histo name
  string histoName = histoTag 
    + "_W" + wheel.str() 
    + "_St" + station.str() 
    + "_Sec" + sector.str();

  string histoname = folderRoot + histoName;

  return histoname;
}




// Run a test on the occupancy of the chamber
// Return values:
// 0 -> all ok
// 1 -> # consecutive dead channels > N
// 2 -> dead layer
// 3 -> dead SL
// 4 -> dead chamber
int DTOccupancyTest::runOccupancyTest(TH2F *histo, const DTChamberId& chId) {
  int nBinsX = histo->GetNbinsX();

  // Reset the error flags
  bool failSL = false;
  bool failLayer = false;
  bool failCells = false;

  // Check that the chamber has digis
  if(histo->Integral() == 0) {
    return 4;
  }

  cout << "--- Occupancy test for chamber: " << chId << endl;
  // set the # of SLs
  int nSL = 3;
  if(chId.station() == 4) nSL = 2;

  // 
  float values[28];
  if(writeRootFile) {
    values[0] = lsCounter;
    values[1] = chId.wheel(); 
    values[2] = chId.station();
    values[3] = chId.sector();
  }

  // Compute the average occupancy per layer and its RMS
  // we also look of the layer with the smallest RMS in order to find a reference value
  // for the cell occupancy 
  double totalChamberOccupp = 0;
  double squaredLayerOccupSum = 0;

  map<DTLayerId, pair<double, double> > averageCellOccupAndRMS;
  map<DTLayerId, double> layerOccupancyMap;

  int index = 3;
  for(int slay = 1; slay <= 3; ++slay) { // loop over SLs
    // Skip layer 2 on MB4
    if(chId.station() == 4 && slay == 2) {
      if(writeRootFile) {
	values[12] = -1;
	values[13] = -1; 
	values[14] = -1;
	values[15] = -1;
	values[16] = -1;
	values[17] = -1; 
	values[18] = -1;
	values[19] = -1;
      }
      index = 19;
      continue;
    }
    // check the SL occupancy
    int binYlow = ((slay-1)*4)+1;
    int binYhigh = binYlow+3;
    double slInteg = histo->Integral(1,nBinsX,binYlow,binYhigh);
    if(slInteg == 0) {
      return 3;
    }

    for(int lay = 1; lay <= 4; ++lay) { // loop over layers
      DTLayerId layID(chId,slay,lay);

      int binY = binYlow+(lay-1);
      
      double layerInteg = histo->Integral(1,nBinsX,binY,binY);
      squaredLayerOccupSum += layerInteg*layerInteg;
      totalChamberOccupp+= layerInteg;

      layerOccupancyMap[layID] = layerInteg;

      // We look for the distribution of hits within the layer
      int nWires = muonGeom->layer(layID)->specificTopology().channels();
      int firstWire = muonGeom->layer(layID)->specificTopology().firstChannel();
      double layerSquaredSum = 0;
      // reset the alert bit in the plot (used by render plugins)
      histo->SetBinContent(nBinsX+1,binY,0.);

      for(int cell = firstWire; cell != (nWires+firstWire); ++cell) { // loop over cells
	double cellOccup = histo->GetBinContent(cell,binY);
	layerSquaredSum+=cellOccup*cellOccup;
      }
      


      // compute the average cell occpuancy and RMS
      double averageCellOccup = layerInteg/nWires;
      double averageSquaredCellOccup = layerSquaredSum/nWires;
      double rmsCellOccup = sqrt(averageSquaredCellOccup - averageCellOccup*averageCellOccup);
      averageCellOccupAndRMS[layID] = make_pair(averageCellOccup, rmsCellOccup);
      cout << "  " << layID
				  << " average cell occ.: " << averageCellOccup
				  << " RMS: " << rmsCellOccup << endl;
      if(writeRootFile) {
	index++;
	values[index] = averageCellOccup;
	index++;
	values[index] = rmsCellOccup;
      }
    }
  }
  

  if(writeRootFile) ntuple->Fill(values);

  double averageLayerOcc = totalChamberOccupp/(nSL*4);
  double averageSquaredLayeroccup = squaredLayerOccupSum/(nSL*4);
  double layerOccupRMS = sqrt(averageSquaredLayeroccup - averageLayerOcc*averageLayerOcc);

  double minCellRMS = 99999999;
  double referenceCellOccup = -1;

  DTOccupancyClusterBuilder builder;

  // find the cell reference value
  for(map<DTLayerId, pair<double, double> >::const_iterator layAndValues = averageCellOccupAndRMS.begin();
      layAndValues != averageCellOccupAndRMS.end(); layAndValues++) {
    DTLayerId lid = (*layAndValues).first;

    double rms = (*layAndValues).second.second;
    double lOcc = layerOccupancyMap[lid]; // FIXME: useless
    double avCellOcc = (*layAndValues).second.first;
    cout << "   " << lid << " tot. occ: " << lOcc
				<< " average cell occ: " << avCellOcc
				<< " RMS: " << rms << endl;
    DTOccupancyPoint point(avCellOcc, rms, lid);
    builder.addPoint(point);

  }

  builder.buildClusters();
  referenceCellOccup = builder.getBestCluster().averageMean();
  minCellRMS = builder.getBestCluster().averageRMS();
  double safeFactor = 3.;
//   if(minCellRMS > referenceCellOccup) safeFactor = 5;

  cout << " Reference cell occup.: " << referenceCellOccup
       << " RMS: " << minCellRMS << endl;
  
  // Set a warning for particularly high RMS: noise can "mask" dead channels
//   bool rmsWarning = false;
//   if(layerOccupRMS > averageLayerOcc) {
//     cout << " Warning RMS is too big: monitoring all layers" << endl;
//     rmsWarning = true;
//   }  

  int nFailingSLs = 0;

  // Check the layer occupancy
  for(int slay = 1; slay <= 3; ++slay) { // loop over SLs
    // Skip layer 2 on MB4
    if(chId.station() == 4 && slay == 2) continue;

    int binYlow = ((slay-1)*4)+1;
//     int binYhigh = binYlow+3;


    int nFailingLayers = 0;

    for(int lay = 1; lay <= 4; ++lay) { // loop over layers
      DTLayerId layID(chId,slay,lay);
      int nWires = muonGeom->layer(layID)->specificTopology().channels();
      int firstWire = muonGeom->layer(layID)->specificTopology().firstChannel();
      int binY = binYlow+(lay-1);

      double layerInteg = histo->Integral(1,nBinsX,binY,binY);
      cout << "     layer: " << layID << " integral: " << layerInteg << endl;


      // if RMS is big check all layers
      bool alreadyMonitored = false;

      if(monitoredLayers.find(layID) != monitoredLayers.end()) alreadyMonitored = true;

      
//       double avCellOccInLayer = averageCellOccupAndRMS[layID].first;
//       double cellOccupRMS =  averageCellOccupAndRMS[layID].second;
//       if(monitoredLayers.find(layID) != monitoredLayers.end() ||
// 	 layerInteg == 0 ||
// 	 layerInteg < (averageLayerOcc - 3*layerOccupRMS) ||
// 	 cellOccupRMS > avCellOccInLayer ||
// 	 avCellOccInLayer < referenceCellOccup/3.) { // check the layer

	if(alreadyMonitored || builder.isProblematic(layID)) { // check the layer

	  // Add it to the list of of monitored layers
	  if(monitoredLayers.find(layID) == monitoredLayers.end()) monitoredLayers.insert(layID);

	if(layerInteg != 0) { // check # of dead cells
	  int totalDeadCells = 0;
	  int nDeadCellsInARow = 1;
	  int nDeadCellsInARowMax = 0;
	  int nCellsZeroCount = 0;
	  bool previousIsDead = false;

	  int interDeadCells = 0;
	  for(int cell = firstWire; cell != (nWires+firstWire); ++cell) { // loop over cells
	    double cellOccup = histo->GetBinContent(cell,binY);
	    cout << "        cell occup: " << cellOccup;
	    if(cellOccup == 0 || cellOccup < (referenceCellOccup-safeFactor*sqrt(referenceCellOccup))) {
	      if(cellOccup == 0) nCellsZeroCount++;
	      totalDeadCells++;
	      if(previousIsDead) nDeadCellsInARow++;
	      previousIsDead = true;
	      interDeadCells = 0;
	      cout << " below referece" << endl;
	    } else {
	      previousIsDead = false;
	      interDeadCells++;

	      // 3 cells not dead between a group of dead cells don't break the count
	      if(interDeadCells > 3) {
		if(nDeadCellsInARow > nDeadCellsInARowMax) nDeadCellsInARowMax = nDeadCellsInARow;
		nDeadCellsInARow = 1; 
	      }
	      cout << endl;
	    }
	  }
	  if(nDeadCellsInARow > nDeadCellsInARowMax) nDeadCellsInARowMax = nDeadCellsInARow;
	  cout << "       # wires: " << nWires
	       << " # cells 0 count: " << nCellsZeroCount
	       << " # dead cells in a row: " << nDeadCellsInARowMax
	       << " total # of dead cells: " << totalDeadCells;
	  

	  // Count dead cells
// 	  if(TMath::Erf(referenceCellOccup/sqrt(referenceCellOccup)) > 2./3. &&
// 	     nDeadCellsInARowMax >  nWires/3.
// 	     && nDeadCellsInARowMax <  2*nWires/3.) {
// 	    cout << " -> fail cells!" << endl;

// 	    failCells = true;
// 	    histo->SetBinContent(nBinsX+1,binY,-1.);
// 	  } else
	  if((TMath::Erfc(referenceCellOccup/sqrt(referenceCellOccup)) < 10./(double)nWires &&
	      nDeadCellsInARowMax>= 10.) ||
	     (TMath::Erfc(referenceCellOccup/sqrt(referenceCellOccup)) < 0.5 &&
	      totalDeadCells > nWires/2.)) {
	    cout << " -> fail layer!" << endl;
	    nFailingLayers++;
	    failLayer = true;
	    histo->SetBinContent(nBinsX+1,binY,-1.);
	  }  else if(referenceCellOccup > 10 &&
		     nCellsZeroCount > nWires/3. &&
		     (double)nCellsZeroCount/(double)nWires >
		     2.*TMath::Erfc(referenceCellOccup/sqrt(referenceCellOccup))) {
	      cout << " -> would fail cells!" << endl;
	      cout << "  # of cells with 0 count: " << nCellsZeroCount
		   << " # wires: " << nWires
		   << "  erfc: " <<   TMath::Erfc(referenceCellOccup/sqrt(referenceCellOccup)) << endl;
// 	      failCells = true;
// 	      histo->SetBinContent(nBinsX+1,binY,-1.);
	  } else {
	    cout << endl;
	  }

	} else { // all layer is dead
	  cout << "     fail layer: no entries" << endl;
	  failLayer = true;
	}
	// If monitored only because of RMS warning remove the layer from the list of monitored
// 	if(rmsWarning && !failLayer && !failCells && !alreadyMonitored){
// // 	  monitoredLayers.erase(layID);
// 	}
      }
    }
    // Check if the whole layer is off
    if( nFailingLayers == 4) {
      nFailingSLs++;
      failSL = true;
    }
  }

  // All the chamber is off
  if(nFailingSLs == nSL) return 4;


  // FIXME add check on cells
  if(failSL) return 3;
  if(failLayer) return 2;
  if(failCells) return 1;

  return 0;
}

