#!/usr/bin/env python
import sys,os,commands,re
from CommonMethods import *
def main():
    castor = "/castor/cern.ch/cms/store/caf/user/uplegger/Workflows/Repro_2010June08/"
    sourceDirList = [castor+"v1",castor+"v2",castor+"v7",castor+"v8",castor+"v9"]
    destDirList   = ["v1","v2","v7","v8","v9"]
    path = "Repro_2010June08/"
    finalDir = path + "Results/"

    if not os.path.isdir(path):
        error = "WARNING: path directory doesn't exist! Creating it..."
        print error
        os.mkdir(path)

    if not os.path.isdir(finalDir):
        error = "WARNING: final dir directory doesn't exist! Creating it..."
        print error
        os.mkdir(finalDir)

    #for n in range(0,3):
    for n in range(0,len(sourceDirList)):
        sourceDir = sourceDirList[n] + '/'
        destDir   = path + destDirList[n] + '/'
        if not dirExists(sourceDir):
            continue
        fileList = ls(sourceDir)
        if not os.path.isdir(destDir):
            error = "WARNING: destination directory doesn't exist! Creating it..."
            print error
            os.mkdir(destDir)
        copiedFiles = cp(sourceDir,destDir,fileList,False,True)

        #if len(copiedFiles) != len(fileList):
        #    error = "ERROR: I couldn't copy all files"
        #    exit(error)

        for fileName in copiedFiles:
            #regExp = re.search('(\D+)(\d+)_(\d+)_(\d+).txt',fileName)
            regExp = re.search('(\D+)(\d+)_(\d+)_.txt',fileName)
            #if regExp:
                #print regExp.group(1) + regExp.group(2) + "_" + str(1) + "_" + regExp.group(3) + ".txt" 
                
            fullFileName = destDir + fileName
            print fullFileName
            runNumber = -1
            with open(fullFileName,'r') as file:
                allTxt = '' 
                for line in file:
                    if line.find("Runnumber") != -1:
                        tmpRun = int(line.split(' ')[1])
                        if runNumber != -1 and tmpRun != runNumber:
                            error = "This file (" + fileName + ") contains more than 1 run number!"
                            if regExp:
                                newFileName = regExp.group(1) + regExp.group(2) + "_" + str(runNumber) + "_" + regExp.group(3) + ".txt" 
                                with open(finalDir+newFileName,'w') as outFile:
                                    outFile.writelines(allTxt)
                                outFile.close()
                                allTxt = ''
                                #aCmd = "cp " + destDir + fileName + " " + finalDir + newFileName
                                #print aCmd
                                #output =  commands.getstatusoutput(aCmd)
                                #if output[0] != 0:
                                    #print output[1]
                            else:
                                print "WARNING: I can't match the regular espression for file: " + fileName
                        runNumber = int(line.split(' ')[1])
                    allTxt += line
            file.close()
            if regExp:
                newFileName = regExp.group(1) + regExp.group(2) + "_" + str(runNumber) + "_" + regExp.group(3) + ".txt" 
                with open(finalDir+newFileName,'w') as outFile:
                    outFile.writelines(allTxt)
                outFile.close()




        
if __name__ == "__main__":
    main()
