#!/usr/bin/env python

""" This is script runs all the macros in the local Macros dir
"""

def arguments(comp, resType = "Z", firstFile = "0", secondFile = "1") :
    if( comp == "Pt" ) :
        name = "pt"
    elif( comp == "Eta" ) :
        name = "eta"
    elif( comp == "PhiPlus" ) :
        name = "phi"
    else :
        print "Error"
        return ""
    return "\"hRecBestResVSMu_MassVS"+comp+"\", \""+firstFile+"_MuScleFit.root\", \""+secondFile+"_MuScleFit.root\", \"Resonance mass vs "+name+"\", \""+resType+"\", 4, 4, 2, \"filegraph_"+name+".root\""

import os

from ROOT import gROOT

firstFile = "\"0\""
secondFile = "\"1\""
resonanceType = "Z"

macrosDir = os.popen("echo $CMSSW_BASE", "r").read().strip()
macrosDir += "/src/MuonAnalysis/MomentumScaleCalibration/test/Macros/"

print macrosDir+"Run.C"

# Mass vs pt, eta, phi
# --------------------
gROOT.ProcessLine(".L "+macrosDir+"fit2DProj.C+");
fileNum1 = firstFile.strip("\"")
fileNum2 = secondFile.strip("\"")
gROOT.ProcessLine( "macroPlot("+arguments("Pt", resonanceType, fileNum1, fileNum2)+")" )
gROOT.ProcessLine( "macroPlot("+arguments("Eta", resonanceType, fileNum1, fileNum2)+")" )
gROOT.ProcessLine( "macroPlot("+arguments("PhiPlus", resonanceType, fileNum1, fileNum2)+")" )

# Resolution
# ----------
gROOT.ProcessLine(".x "+macrosDir+"ResolDraw.cc+("+firstFile+")")
gROOT.ProcessLine(".x "+macrosDir+"ResolDraw.cc+("+secondFile+")")
gROOT.ProcessLine(".x "+macrosDir+"ResolCompare.cc("+firstFile+", "+secondFile+")")
# os.system("root -l "+macrosDir+"ResolCompare.cc")

# Pt reco vs Pt gen
gROOT.ProcessLine(".x "+macrosDir+"CompareRecoGenPt.C("+firstFile+", "+secondFile+")")

# Mass vs mass probability
gROOT.ProcessLine(".x "+macrosDir+"Plot_mass.C+("+firstFile+", "+secondFile+")")
os.system("root -l "+macrosDir+"ShowMassComparison.C")
