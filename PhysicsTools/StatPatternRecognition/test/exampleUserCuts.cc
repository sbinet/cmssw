//$Id: exampleUserCuts.cc,v 1.3 2007/07/24 23:05:12 narsky Exp $

#include "PhysicsTools/StatPatternRecognition/interface/SprExperiment.hh"
#include "PhysicsTools/StatPatternRecognition/interface/SprAbsFilter.hh"
#include "PhysicsTools/StatPatternRecognition/interface/SprPreFilter.hh"
#include "PhysicsTools/StatPatternRecognition/interface/SprSimpleReader.hh"
#include "PhysicsTools/StatPatternRecognition/interface/SprMyWriter.hh"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//
// Define user cuts and transformations here.
//

// Define a list of input classes.
// If accept all classes, return an empty vector.
vector<int> myClasses() {
  vector<int> classes(1);
  classes[0] = 1;
  return classes;
}

//
// The following two routines impose x0+x1>0 requirement.
//

// Define a list of variables used for user selection requirements.
vector<string> varsForCuts() {
  vector<string> vars(2);
  vars[0] = "x0";
  vars[1] = "x1";
  return vars;
}

// Define cuts for specified variables using the specified order of variables.
// Return true is the point passes the cuts, false otherwise.
bool myCuts(const vector<double>& v) {
  if( v[0]+v[1] > 0. ) return true;
  return false;
}

//
// The following 3 routines define transformation x1_plus_x2 = x0+x1
// The two variables, x0 and x1, are then replaced by x1_plus_x2
// in the input data.
//

// Define a list of variables for transformation.
vector<string> inputVars() {
  vector<string> vars(2);
  vars[0] = "x0";
  vars[1] = "x1";
  return vars;
}

vector<string> outputVars() {
  vector<string> vars(1);
  vars[0] = "x1_plus_x2";
  return vars;
}

// Define transformation.
void myTransform(const std::vector<double>& in,
		 std::vector<double>& out) {
  out.clear();
  out.resize(1);
  out[0] = in[0] + in[1];
}

//
// End of user definitions.
//


int main(int argc, char ** argv)
{
  // specify input file
  string trFile = "gauss2_uniform_2d_train.pat";

  //
  // Begin user-defined section.
  //
  // prepare pre-filter
  SprPreFilter pre;
  if( !pre.setSelection(varsForCuts,myCuts,myClasses) ) {
    cerr << "Unable to set pre-filter cuts." << endl;
    return 1;
  }
  if( !pre.setTransform(inputVars,outputVars,myTransform) ) {
    cerr << "Unable to set pre-filter transform." << endl;
    return 1;
  }
  //
  // End user-defined section.
  //

  // read training data from file applying pre-filter requirements
  SprSimpleReader reader(1,&pre);
  auto_ptr<SprAbsFilter> filter(reader.read(trFile.c_str()));
  if( filter.get() == 0 ) {
    cerr << "Unable to read data from file " << trFile.c_str() << endl;
    return 2;
  }

  // print summary
  vector<string> vars;
  filter->vars(vars);
  cout << "Read data from file " << trFile.c_str() 
       << " for variables";
  for( int i=0;i<vars.size();i++ ) 
    cout << " \"" << vars[i].c_str() << "\"";
  cout << endl;
  cout << "Total number of points read: " << filter->size() << endl;
  cout << "Points in class 0: " << filter->ptsInClass(0)
       << " 1: " << filter->ptsInClass(1) << endl;

  // set up an output writer
  auto_ptr<SprAbsWriter> tuple(new SprMyWriter("filtered"));
  string tupleFile = "filtered.root";
  if( !tuple->init(tupleFile.c_str()) ) {
    cerr << "Cannot open file " << tupleFile.c_str() << endl;
    return 3;
  }
  vector<string> axes;
  for( int i=0;i<vars.size();i++ ) axes.push_back(vars[i].c_str());
  tuple->setAxes(axes);

  // write filtered data
  vector<double> emp;
  for( int i=0;i<filter->size();i++ )
    tuple->write(1.,(*(filter.get()))[i],emp);

  // close writer
  if( !tuple->close() ) {
    cerr << "Unable to close file." << endl;
    return 4;
  }
  cout << "Output successfully closed." << endl;

  // exit
  return 0;
}
