# FLArE
Simulation code for R&D of the FLArE detector
![nutau evt display](./flare_nutau_evd.jpg)

## To compile the code
* Create a new directory to contain the executables (assume the path is /path/to/build)
* Assume the path to the source code is /path/to/source
* To compile, you need to go to the build directory `cd /path/to/build`
* And then `cmake /path/to/source`
* Finally `make`

Things get complicated with importing GENIE results to the Geant4 Application. What we're doing now is to link to GENIE libraries so we can have a dictionary for the ROOT file format, read in the TTree record and then loop over the particles in the event record and for those with status code == 1 (those particles coming out of the nucleus) and call Geant4's PrimaryVertex. Not only GENIE libraries, there are a bunch of another packages needed in order to link GENIE libraries. 
* Geant4 v4_10_6_p01c
* ROOT v6_22_06a
* GENIE v3_00_06k
* log4cpp v1_1_3c
* gsl v2_6a
* libxml2 v2_9_10a
* pythia6 v6_4_28r

## Macro command
### Geometry
|Command |Description | Default |
|:--|:--|:--|
|/det/saveGdml          | option for saving detector geometry in a GDML file, run before `/run/initialize`     |`false`|
|/det/addFLArE          | option for adding the FLArE detector, run before `/run/initialize`                   |`true`|
|/det/addFLArEPos       | position of the FLArE detector, run before `/run/initialize`                         |`0 0 4300 mm`|
|/det/material          | option for detector material, choose `LAr` or `LKr`, run before `/run/initialize`    |`LAr`|
|/det/module            | option for tpc module option, choose `single` or `3x7`, run before `/run/initialize` |`single`|
|/det/field             | option for setting the magnetic field value in FLArE HadCather and Muon Finder       |`1 T`|
|/det/addFORMOSA        | option for adding the FORMOSA detector, run before `/run/initialize`                 |`true`|
|/det/addFORMOSAPos     | position of the FORMOSA detector, run before `/run/initialize`                       |`0 0 13870 mm`|
|/det/addFASERnu2       | option for adding the FASERnu2 detector, run before `/run/initialize`                |`true`|
|/det/addFASERnu2Pos    | position of the FASERnu2 detector, run before `/run/initialize`                      |`0 0 22123 mm`|
|/det/addFASER2         | option for adding the FASER2 detector, run before `/run/initialize`                  |`true`|
|/det/addFASER2Pos      | position of the FASER2 detector, run before `/run/initialize`                        |`0 0 43036 mm`|
|/det/magnetGeom        | option for FASER2 magnet geometry, choose `SAMURAI` or `CrystalPulling`              |`SAMURAI`|
|/det/magnetField       | option for setting the FASER2 magnetic field value                                   |`1 T`|
|/det/magnetWinX        | option for SAMURAI magnet window size along X axis                                   |`3.0 m`|
|/det/magnetWinY        | option for SAMURAI magnet window size along Y axis                                   |`1.0 m`|
|/det/magnetWinZ        | option for SAMURAI magnet window size along Z size                                   |`4.0 m`|
|/det/yokeThickX        | option for SAMURAI yoke thickness along X axis                                       |`1.5 m`|
|/det/yokeThickY        | option for SAMURAI yoke thickness along Y axis                                       |`2.0 m`|
|/det/magnetNumber      | option for number of CrystalPulling magnets                                          |`3`|
|/det/magnetInnerR      | option for CrystalPulling magnet inner radius                                        |`0.8 m`|
|/det/magnetOuterR      | option for CrystalPulling magnet outer radius                                        |`1.2 m`|
|/det/magnetLengthZ     | option for CrystalPulling magnet size along Z axis                                   |`1.25 m`|
|/det/magnetGap         | option for gap length (along Z) between CrystalPullin magnets                        |`0.5 m`|
|/det/trackingNumber    | option for number of FASER2 tracking stations in each assembly                       |`6`|
|/det/trackingNBarsX    | option for number of vertical scintillator bars (segmentation along X axis)          |`7`|  
|/det/trackingNBarsY    | option for number of horizontal scintillator bars (segmentation along Y axis)        |`3`|
|/det/trackingScinThick | option for scintillator bar thickness (along Z) in tracking layers                   |`1.0 cm`|
|/det/trackingGap       | option for gap length (along Z) between tracking stations, and gap to magnet         |` 0.5 m`|
### Event generators
|Command |Description |
|:--|:--|
|/genie/useGenie     | option for PrimaryGeneratorMessenger, set `true` to read neutrino interactions from GENIE|
|/genie/genieInput   | if `useGenie is true`, give which `.ghep.root` file to read GENIE events|
|/genie/genieIStart  | if `useGenie is true`, give the start position of the file to read GENIE events|
### Analysis
|Command |Description |
|:--|:--|
|/histo/fileName     | option for AnalysisManagerMessenger, set name of the file saving all analysis variables|
|/histo/saveHit      | if `true` save information for all hits, `false` in default to save space|
|/histo/save3DEvd    | if `true` save 3D spatial distribution of energy deposition, `false` in default|
|/histo/save2DEvd    | if `true` save 2D spatial distribution of energy deposition, `false` in default|
|/histo/circleFit    | if `true` run circle fitting and save information in output, `false` in default to save space|
|/histo/addDiffusion | if `toy` diffuse energy, if `single` diffuse single electron, `false` in default without diffusion|

## Run simulation of leptons
There are six `.mac` macros in `macros` directory: LAr_e-.mac, LAr_mu-.mac, LAr_tau-.mac, LKr_e-.mac, LKr_mu-.mac, LKr_tau-.mac.
As denoted by the name, they're used to simulate e-/mu-/tau- leptons in a LAr or LKr detector. To run a simulation, just do `./FLArE macros/LAr_e-.mac`.
If you want to modify the lepton energy you intend to simulate, modify the parameters inside the mac scripts.

## How to save an event display with high resolution using the DAWN Event Display
There is [this tutorial](https://conferences.fnal.gov/g4tutorial/g4cd/Documentation/Visualization/G4DAWNTutorial/G4DAWNTutorial.html) for use at the October 2003 Fermilab Geant4 Tutorial.
* Add `/vis/open DAWNFILE` to the mac file, after running a pass of simulation you'll find a ".prim" files suitable for viewing in DAWN.
* Run `~/dune_data/app/dawn_3_91a/dawn -d filename.prim`, and it will generate a high resolution picture with the format of EPS.


## Submit grid jobs on DUNEGPVMs

## Some initial results

[cern indico 1](https://indico.cern.ch/event/1095064/contributions/4621162/attachments/2349156/4006611/20211118%40FLArEDetectorSimulation.pdf)
 
[cern indico 2](https://indico.cern.ch/event/1250086/#3-status-update-on-flare-simul)
