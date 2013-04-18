#!/usr/bin/env python
from optparse import OptionParser, OptionGroup

## set up the option parser
parser = OptionParser(usage="usage: %prog [options] ARGs", description="This is a script to submit a set of jobs to set up the datacard structure for direct mA-tanb limit calculation to lxb (lxq). ARGs corresponds to the mass directories or to the parent directories.")
parser.add_option("--name", dest="name", default="submit", type="string",
                  help="Set the name of the submission. All scripts concerned with the submission will be located in a directory with that name in your working directory. [Default: \"submit\"]")
parser.add_option("--lxq", dest="lxq", default=False, action="store_true",
                  help="Specify this option when running on lxq instead of lxb. [Default: False]")

## check number of arguments; in case print usage
(options, args) = parser.parse_args()
if len(args) < 1 :
    parser.print_usage()
    exit(1)

import os
import sys
import glob

import logging
log = logging.getLogger("xsec2tanb")
logging.basicConfig(stream=sys.stderr, level=logging.INFO)

from HiggsAnalysis.HiggsToTauTau.utils import contained
from HiggsAnalysis.HiggsToTauTau.utils import is_number
from HiggsAnalysis.HiggsToTauTau.utils import get_mass

name = options.name
dirglob = args
## prepare log file directory
os.system("mkdir -p log")

## tamplate for the submission script
script_template = '''
#!/usr/bin/bash

cd {working_dir}
eval `scram runtime -sh`

echo "Running submit.py:"
echo "in directory {directory}"

$CMSSW_BASE/src/HiggsAnalysis/HiggsToTauTau/scripts/submit.py --tanb+ --setup {directory}
'''

lxq_fragment = '''
#!/usr/bin/bash
#$ -l h_cpu=1:00:00
export SCRAM_ARCH=$scram_arch
ini cmssw_cvmfs
ini autoproxy
'''

if options.lxq :
    script_template = script_template.replace('#!/usr/bin/bash', lxq_fragment)
    
def submit(name, key, masses) :
    '''
    prepare the submission script
    '''
    submit_name = '%s_submit.sh' % name
    with open(submit_name, 'w') as submit_script:
        if options.lxq :
            submit_script.write('export scram_arch=$SCRAM_ARCH\n')
            submit_script.write('export cmssw_base=$CMSSW_BASE\n')
        if not os.path.exists(name):
            os.system("mkdir -p %s" % name)
        ##print masses
        for i, mass in enumerate(masses[key]):
            dir=key+'/'+mass
            if not is_number(dir[dir.rstrip('/').rfind('/')+1:]) :
                continue
            ## do not submit jobs on old LSF output
            if 'LSFJOB' in dir:
                continue
            log.info(" Generating submision script for %s", dir)
            script_file_name = '%s/%s_%i.sh' % (name, name, i)
            with open(script_file_name, 'w') as script:
                script.write(script_template.format(
                    working_dir = os.getcwd(),
                    directory = dir
                    ))
            os.system('chmod a+x %s' % script_file_name)
            if options.lxq :
                submit_script.write('qsub -l site=hh -j y -o /dev/null -l h_vmem=4000M -v scram_arch -v cmssw_base %s\n' % script_file_name)
            else :
                os.system('touch {PWD}/log/{LOG}'.format(
                    PWD=os.getcwd(), LOG=script_file_name[script_file_name.rfind('/')+1:].replace('.sh', '.log')))
                submit_script.write('bsub -q 8nh -oo {PWD}/log/{LOG} {PWD}/{FILE}\n'.format(
                    LOG=script_file_name[script_file_name.rfind('/')+1:].replace('.sh', '.log'), PWD=os.getcwd(), FILE=script_file_name))
    os.system('chmod a+x %s' % submit_name)

def directories(args) :
    ## prepare structure of parent directories
    dirs = []
    for dir in args :
        if is_number(get_mass(dir)) or get_mass(dir) == "common" :
            dir = dir[:dir.rstrip('/').rfind('/')]
        if not dir in dirs :
            dirs.append(dir)
    ## prepare mapping of masses per parent directory
    masses = {}
    for dir in dirs :
        buffer = []
        for path in args :
            if dir+'/' in path :
                if is_number(get_mass(path)) :
                    mass = get_mass(path)
                    if not contained(mass, buffer) :
                        buffer.append(mass)
        masses[dir] = list(buffer)
    return (dirs, masses)

dirs = directories(args)[0]
masses = directories(args)[1]
for dir in dirs :
    ana = dir[:dir.rfind('/')]
    limit = dir[len(ana)+1:]
    jobname = ana[ana.rfind('/')+1:]+'-'+limit+'-'+options.name
    ## create submission scripts
    submit(jobname, dir, masses)
    ## execute
    os.system("./{JOBNAME}_submit.sh".format(JOBNAME=jobname))
    ## shelve
    os.system("mv {JOBNAME}_submit.sh {JOBNAME}".format(JOBNAME=jobname))


