# CMSSW_PITHYA8_standalone
Documentation about how to use standalone Pythia8 through CMSSW to test pythia (.dat) files.

## Requirements:

* Should be able to `cmsrel` a CMSSW folder. Used `CMSSW_17_0_0_pre1`.
* Used sample Pythia card from the repo [here](https://github.com/fermilab-hep-ai/simulation/blob/main/processes/upsilon_to_leptons/upsilon_to_leptons_pythia_card.dat).
* Found the cms config file with Pythia commands in McM requests website. Then, copied, pastied, and edited as needed.

## Steps to Follow:
1. git clone this repo.

2.
  ```bash
  cmsenv #activate cmsenv
  scram tool info pythia8 # Check that variable $PYTHA8_BASE is there. If not:
  export PYTHIA8_BASE=/cvmfs/cms.cern.ch/el8_amd64_gcc13/external/pythia8/317-28f2335c1fd0cf5ad4dd66647fac0416
  cd CMSSW_PYTHIA8_standalone/ 
  g++ testCard.cc -o testCard \
      -I$PYTHIA8_BASE/include \
      -L$PYTHIA8_BASE/lib \
      -lpythia8 \
      -Wl,-rpath,$PYTHIA8_BASE/lib \
      && echo "Compiled OK"
  ```
3. If no errors, an executable `testCard` file should have been generated. Test run:
`./testCard testCard.dat > out.log` generates output to `out.log`. Check that there are no errors. 
