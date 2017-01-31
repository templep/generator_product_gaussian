#include <iostream>
#include <fstream>
#include "stdlib.h"
#include <cstdlib>
#include "stdio.h"

using namespace std;

/**
* a utility function to help user to call the program
* the program can be launch in iterative mode (with questions and answers) with only one argument -> the output file name
* the other mode is when the answers to every questions are given as parameters
*/
void help()
{
    cout << "This program generates a variant of computer vision programs." << endl;
    cout << "Computer vision programs come from OpenCV." << endl;
    cout << "The creation of the variant is done with interactions with users (asking questions)" << endl;
    cout << "All of values are initially set to default values identified on OpenCV website." << endl;
    cout << "Customization will be done by adding a random value drawn from the default value." << endl;
    cout << "This program takes as parameters the output file name of the product variant to be created" << endl;
    cout << "\t generator_product_gaussian_variation <filename>" << endl;
}

/**
* a function called (both in interactive and non-interactive modes) when no detection module should be used
* it will write into the output file all parameters related to detection with options to select detection module deactivated
* intput :
*   - fstream& f : a file stream representing the output file (avoid copy)
*/
void write_no_detection(fstream& f)
{
    f << "OpenCV.nb_frame=222"<< "\n";
    f << "Detect=0"<< "\n";
    f << "Detect.BackgroundSubtraction=0"<< "\n";
    f << "Detect.BackgroundSubtraction.MOG=0"<< "\n";
    f << "Detect.BackgroundSubtraction.MOG.nb_frame=200"<< "\n";
    f << "Detect.BackgroundSubtraction.MOG.nb_mixture=5"<< "\n";
    f << "Detect.BackgroundSubtraction.MOG.noiseRob=0.0"<< "\n";
    f << "Detect.BackgroundSubtraction.MOG.decisionThreshold=0.7"<< "\n";
    f << "Detect.BackgroundSubtraction.MOG2=0"<< "\n";
    f << "Detect.BackgroundSubtraction.MOG2.detectShadows=1"<< "\n";
    f << "Detect.BackgroundSubtraction.MOG2.nb_frame=500"<< "\n";
    f << "Detect.BackgroundSubtraction.MOG2.thresholdSquare=16.0"<< "\n";
    f << "Detect.BackgroundSubtraction.GMG=0"<< "\n";
    f << "Detect.BackgroundSubtraction.GMG.decisionThreshold=0.8"<< "\n";
    f << "Detect.BackgroundSubtraction.GMG.nb_frame=120"<< "\n";
    f << "Detect.BackgroundSubtraction.KNN=0"<< "\n";
    f << "Detect.BackgroundSubtraction.KNN.nb_frame=500"<< "\n";
    f << "Detect.BackgroundSubtraction.KNN.thresholdSquare=400.0"<< "\n";
    f << "Detect.BackgroundSubtraction.KNN.detectShadows=1"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD=0" << "\n";
    f << "Detect.BackgroundSubtraction.FGD.alpha1=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.deltish=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.n1cc=10"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.n2c=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.n2cc=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.is_obj_without_holes=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.lc=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.n1c=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.lcc=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.perform_morphing=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.minArea=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.alpha2=1"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.t=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.alpha3=0"<< "\n";
    f << "Detect.MorphologicalOperators=0"<< "\n";
    f << "Detect.MorphologicalOperators.Dilate=1"<< "\n";
    f << "Detect.MorphologicalOperators.Dilate.shape=rectangle"<< "\n";
    f << "Detect.MorphologicalOperators.Dilate.height=10"<< "\n";
    f << "Detect.MorphologicalOperators.Dilate.width=10"<< "\n";
    f << "Detect.MorphologicalOperators.Dilate.anchory=-1"<< "\n";
    f << "Detect.MorphologicalOperators.Dilate.anchorx=-1"<< "\n";
    f << "Detect.MorphologicalOperators.Erode=1"<< "\n";
    f << "Detect.MorphologicalOperators.Erode.shape=rectangle"<< "\n";
    f << "Detect.MorphologicalOperators.Erode.height=10"<< "\n";
    f << "Detect.MorphologicalOperators.Erode.width=10"<< "\n";
    f << "Detect.MorphologicalOperators.Erode.anchorx=-1"<< "\n";
    f << "Detect.MorphologicalOperators.Erode.anchory=-1"<< "\n";
    f << "Detect.ContoursRetrieval=0"<< "\n";
    f << "Detect.ContoursHierarchical.HCR=0"<< "\n";
    f << "Detect.ContoursHierarchical.HCR.External=0"<< "\n";
    f << "Detect.ContoursHierarchical.HCR.C_comp=0"<< "\n";
    f << "Detect.ContoursHierarchical.HCR.Tree=0"<< "\n";
    f << "Detect.ContoursHierarchical.NHCR=0"<< "\n";
    f << "Detect.ContoursHierarchical.NHCR.List=1"<< "\n";
    f << "Detect.ContoursHierarchical.None=0"<< "\n";
    f << "Detect.ContoursHierarchical.Approximate=0"<< "\n";
    f << "Detect.ContoursHierarchical.Approximate.K_Cos=0"<< "\n";
    f << "Detect.ContoursHierarchical.Approximate.Simple=1"<< "\n";
    f << "Detect.ContoursHierarchical.Approximate.L1=0"<< "\n";
    f << "Detect.ContoursHierarchical.offsetx=0"<< "\n";
    f << "Detect.ContoursHierarchical.offsety=0"<< "\n";
    f << "Detect.MerginBoundingBoxes=0"<< "\n";
    f << "Detect.MerginBoundingBoxes.scalingFactor=10"<< "\n";
    f << "Detect.MerginBoundingBoxes.nb_loop=-1"<< "\n";
    f << "Detect.MerginBoundingBoxes.maxDistance=10"<< "\n";
    f << "Detect.Filters=0"<< "\n";
    f << "Detect.Filters.FilterLenght=1"<< "\n";
    f << "Detect.Filters.FilterLenght.threshold=10"<< "\n";
    f << "Detect.Filters.FilterArea=1"<< "\n";
    f << "Detect.Filters.FilterArea.threshold=100"<< "\n";
    f << "Detect.OpticalFlow=0"<< "\n";
    f << "Detect.OpticalFlow.Dense=0"<< "\n";
    f << "Detect.OpticalFlow.Sparse=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.Farneback=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.SimpleFlow=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.DualTVL=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.Farneback.pyr_scale=0.5"<< "\n";
    f << "Detect.OpticalFlow.Dense.Farneback.levels=3"<< "\n";
    f << "Detect.OpticalFlow.Dense.Farneback.winSize=15"<< "\n";
    f << "Detect.OpticalFlow.Dense.Farneback.iterations=3"<< "\n";
    f << "Detect.OpticalFlow.Dense.Farneback.poly_n=5"<< "\n";
    f << "Detect.OpticalFlow.Dense.Farneback.poly_sigma=1.2"<< "\n";
    f << "Detect.OpticalFlow.Dense.Farneback.use_init_flow=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.Farneback.use_gaussian=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.Farneback.threshold=0.0001"<< "\n";
    f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK=0"<< "\n";
    f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.winSize=0"<< "\n";
    f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.maxLevel=0"<< "\n";
    f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.count=0"<< "\n";
    f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.epsilon=0"<< "\n";
    f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.use_initial_flow=0"<< "\n";
    f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.use_eigen_val=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.SimpleFlow.nb_layer=3"<< "\n";
    f << "Detect.OpticalFlow.Dense.SimpleFlow.averaging_block_size=2"<< "\n";
    f << "Detect.OpticalFlow.Dense.SimpleFlow.max_flow=4"<< "\n";
    f << "Detect.OpticalFlow.Dense.DualTVL.tau=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.DualTVL.lambda=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.DualTVL.theta=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.DualTVL.nscales=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.DualTVL.warps=1"<< "\n";
    f << "Detect.OpticalFlow.Dense.DualTVL.epsilon=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.DualTVL.iterations=0"<< "\n";
    f << "Detect.MotionHistory=0"<< "\n";
    f << "Detect.MotionHistory.mhi_duration=5"<< "\n";
    f << "Detect.MotionHistory.min_time_delta=0.05"<< "\n";
    f << "Detect.MotionHistory.max_time_delta=10"<<"\n";
    f << "Detect.MotionHistory.threshold=22"<<"\n";
    f << "Detect.BlockMatching=0" << "\n";
    f << "Detect.BlockMatching.min_disparity=0"<< "\n";
    f << "Detect.BlockMatching.num_disparities=16"<< "\n";
    f << "Detect.BlockMatching.block_size=3"<< "\n";
    f << "Detect.BlockMatching.p1=0"<< "\n";
    f << "Detect.BlockMatching.p2=0"<< "\n";
    f << "Detect.BlockMatching.disp12_max_diff=0"<< "\n";
    f << "Detect.BlockMatching.pre_filter_cap=0"<< "\n";
    f << "Detect.BlockMatching.uniqueness_ratio=0"<< "\n";
    f << "Detect.BlockMatching.speckle_window_size=0"<< "\n";
    f << "Detect.BlockMatching.speckle_range=0"<< "\n";
}

/**
* a function called in interactive mode to write the background subtraction module
* users have decided to use background subtraction as a detection module they also decided to give default values for each parameters
* parameters will be wrote for all the detection module (except for the common parts) : one activated, the others will not be
*
* input :
*   - fstream& f : a file stream representing the output file
*
* output :
*   - the background subtractor module should be written into the output file (assuming that the file has been closed to flush the buffer)
*/
void write_use_bgSub(fstream& f)
{
    f << "Detect.BackgroundSubtraction=1"<< "\n";

    ///which method to use ?
    cout << "Which method do you want to use ? (1 : MOG; 2 : MOG2; 3 : GMG; 4 : KNN; 5 : FGD (not implemented yet)" << endl;
    string choice;
    cin >> choice;
    while (choice != "1" && choice != "2" && choice != "3" && choice != "4")
    {
        cout << "Which method do you want to use ? (1 : MOG; 2 : MOG2; 3 : GMG; 4 : KNN; 5 : FGD (not implemented yet)" << endl;
        cin >> choice;
    }

    ///write parameters according to choices
    switch(atoi(choice.c_str()))
    {
        case 1 : // MOG
        {
            f << "Detect.BackgroundSubtraction.MOG=1"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG.nb_frame=200"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG.nb_mixture=5"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG.noiseRob=0.0"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG.decisionThreshold=0.7"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG2=0"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG2.detectShadows=1"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG2.nb_frame=500"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG2.thresholdSquare=16.0"<< "\n";
            f << "Detect.BackgroundSubtraction.GMG=0"<< "\n";
            f << "Detect.BackgroundSubtraction.GMG.decisionThreshold=0.8"<< "\n";
            f << "Detect.BackgroundSubtraction.GMG.nb_frame=120"<< "\n";
            f << "Detect.BackgroundSubtraction.KNN=0"<< "\n";
            f << "Detect.BackgroundSubtraction.KNN.nb_frame=500"<< "\n";
            f << "Detect.BackgroundSubtraction.KNN.thresholdSquare=400.0"<< "\n";
            f << "Detect.BackgroundSubtraction.KNN.detectShadows=1"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD=0" << "\n";
            f << "Detect.BackgroundSubtraction.FGD.alpha1=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.deltish=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.n1cc=10"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.n2c=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.n2cc=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.is_obj_without_holes=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.lc=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.n1c=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.lcc=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.perform_morphing=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.minArea=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.alpha2=1"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.t=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.alpha3=0"<< "\n";
            break;
        }
        case 2 : // MOG2
        {
            f << "Detect.BackgroundSubtraction.MOG=0"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG.nb_frame=200"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG.nb_mixture=5"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG.noiseRob=0.0"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG.decisionThreshold=0.7"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG2=1"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG2.detectShadows=1"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG2.nb_frame=500"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG2.thresholdSquare=16.0"<< "\n";
            f << "Detect.BackgroundSubtraction.GMG=0"<< "\n";
            f << "Detect.BackgroundSubtraction.GMG.decisionThreshold=0.8"<< "\n";
            f << "Detect.BackgroundSubtraction.GMG.nb_frame=120"<< "\n";
            f << "Detect.BackgroundSubtraction.KNN=0"<< "\n";
            f << "Detect.BackgroundSubtraction.KNN.nb_frame=500"<< "\n";
            f << "Detect.BackgroundSubtraction.KNN.thresholdSquare=400.0"<< "\n";
            f << "Detect.BackgroundSubtraction.KNN.detectShadows=1"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD=0" << "\n";
            f << "Detect.BackgroundSubtraction.FGD.alpha1=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.deltish=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.n1cc=10"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.n2c=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.n2cc=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.is_obj_without_holes=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.lc=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.n1c=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.lcc=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.perform_morphing=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.minArea=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.alpha2=1"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.t=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.alpha3=0"<< "\n";
            break;
        }
        case 3 : // GMG
        {
            f << "Detect.BackgroundSubtraction.MOG=0"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG.nb_frame=200"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG.nb_mixture=5"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG.noiseRob=0.0"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG.decisionThreshold=0.7"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG2=0"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG2.detectShadows=1"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG2.nb_frame=500"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG2.thresholdSquare=16.0"<< "\n";
            f << "Detect.BackgroundSubtraction.GMG=1"<< "\n";
            f << "Detect.BackgroundSubtraction.GMG.decisionThreshold=0.8"<< "\n";
            f << "Detect.BackgroundSubtraction.GMG.nb_frame=120"<< "\n";
            f << "Detect.BackgroundSubtraction.KNN=0"<< "\n";
            f << "Detect.BackgroundSubtraction.KNN.nb_frame=500"<< "\n";
            f << "Detect.BackgroundSubtraction.KNN.thresholdSquare=400.0"<< "\n";
            f << "Detect.BackgroundSubtraction.KNN.detectShadows=1"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD=0" << "\n";
            f << "Detect.BackgroundSubtraction.FGD.alpha1=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.deltish=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.n1cc=10"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.n2c=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.n2cc=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.is_obj_without_holes=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.lc=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.n1c=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.lcc=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.perform_morphing=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.minArea=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.alpha2=1"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.t=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.alpha3=0"<< "\n";
            break;
        }
        case 4 : // KNN
        {
            f << "Detect.BackgroundSubtraction.MOG=0"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG.nb_frame=200"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG.nb_mixture=5"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG.noiseRob=0.0"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG.decisionThreshold=0.7"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG2=0"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG2.detectShadows=1"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG2.nb_frame=500"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG2.thresholdSquare=16.0"<< "\n";
            f << "Detect.BackgroundSubtraction.GMG=0"<< "\n";
            f << "Detect.BackgroundSubtraction.GMG.decisionThreshold=0.8"<< "\n";
            f << "Detect.BackgroundSubtraction.GMG.nb_frame=120"<< "\n";
            f << "Detect.BackgroundSubtraction.KNN=1"<< "\n";
            f << "Detect.BackgroundSubtraction.KNN.nb_frame=500"<< "\n";
            f << "Detect.BackgroundSubtraction.KNN.thresholdSquare=400.0"<< "\n";
            f << "Detect.BackgroundSubtraction.KNN.detectShadows=1"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD=0" << "\n";
            f << "Detect.BackgroundSubtraction.FGD.alpha1=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.deltish=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.n1cc=10"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.n2c=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.n2cc=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.is_obj_without_holes=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.lc=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.n1c=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.lcc=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.perform_morphing=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.minArea=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.alpha2=1"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.t=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.alpha3=0"<< "\n";
            break;
        }
        default : cout << "Not implemented yet" << endl;
    }
    f << "Detect.OpticalFlow=0"<< "\n";
    f << "Detect.OpticalFlow.Dense=0"<< "\n";
    f << "Detect.OpticalFlow.Sparse=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.Farneback=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.SimpleFlow=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.DualTVL=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.Farneback.pyr_scale=0.5"<< "\n";
    f << "Detect.OpticalFlow.Dense.Farneback.levels=3"<< "\n";
    f << "Detect.OpticalFlow.Dense.Farneback.winSize=15"<< "\n";
    f << "Detect.OpticalFlow.Dense.Farneback.iterations=3"<< "\n";
    f << "Detect.OpticalFlow.Dense.Farneback.poly_n=5"<< "\n";
    f << "Detect.OpticalFlow.Dense.Farneback.poly_sigma=1.2"<< "\n";
    f << "Detect.OpticalFlow.Dense.Farneback.use_init_flow=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.Farneback.use_gaussian=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.Farneback.threshold=0.0001"<< "\n";
    f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK=0"<< "\n";
    f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.winSize=0"<< "\n";
    f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.maxLevel=0"<< "\n";
    f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.count=0"<< "\n";
    f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.epsilon=0"<< "\n";
    f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.use_initial_flow=0"<< "\n";
    f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.use_eigen_val=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.SimpleFlow.nb_layer=3"<< "\n";
    f << "Detect.OpticalFlow.Dense.SimpleFlow.averaging_block_size=2"<< "\n";
    f << "Detect.OpticalFlow.Dense.SimpleFlow.max_flow=4"<< "\n";
    f << "Detect.OpticalFlow.Dense.DualTVL.tau=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.DualTVL.lambda=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.DualTVL.theta=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.DualTVL.nscales=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.DualTVL.warps=1"<< "\n";
    f << "Detect.OpticalFlow.Dense.DualTVL.epsilon=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.DualTVL.iterations=0"<< "\n";
    f << "Detect.BlockMatching=0" << "\n";
    f << "Detect.BlockMatching.min_disparity=0"<< "\n";
    f << "Detect.BlockMatching.num_disparities=16"<< "\n";
    f << "Detect.BlockMatching.block_size=3"<< "\n";
    f << "Detect.BlockMatching.p1=0"<< "\n";
    f << "Detect.BlockMatching.p2=0"<< "\n";
    f << "Detect.BlockMatching.disp12_max_diff=0"<< "\n";
    f << "Detect.BlockMatching.pre_filter_cap=0"<< "\n";
    f << "Detect.BlockMatching.uniqueness_ratio=0"<< "\n";
    f << "Detect.BlockMatching.speckle_window_size=0"<< "\n";
    f << "Detect.BlockMatching.speckle_range=0"<< "\n";
    f << "Detect.MotionHistory=0"<< "\n";
    f << "Detect.MotionHistory.mhi_duration=5"<< "\n";
    f << "Detect.MotionHistory.min_time_delta=0.05"<< "\n";
    f << "Detect.MotionHistory.max_time_delta=10"<<"\n";
    f << "Detect.MotionHistory.threshold=22"<<"\n";
}

/**
* a function called in interactive mode to write the background subtraction module
* users have decided to use background subtraction as a detection module they also decided to give default values for each parameters
* parameters will be wrote for all the detection module (except for the common parts) : one activated, the others will not be
*
* input :
*   - fstream& f : a file stream representing the output file
*   - char** argv : the list of arguments given to the program when it has been called
*   - int idx : the index of the next argument to retrieve
*
* output :
*   - the background subtractor module should be written into the output file (assuming that the file has been closed to flush the buffer)
*   - int : the index of the next argument to retrieve
*/
int write_use_bgSub(fstream& f, char** argv, int idx)
{
    f << "Detect.BackgroundSubtraction=1"<< "\n";

    ///which method to use ?
    cout << "Which method do you want to use ? (1 : MOG; 2 : MOG2; 3 : GMG; 4 : KNN; 5 : FGD (not implemented yet)" << endl;
    string choice(argv[idx]);
    //cin >> choice;
    cout << choice << endl;
    idx++;

    while (choice != "1" && choice != "2" && choice != "3" && choice != "4")
    {
        cout << "Which method do you want to use ? (1 : MOG; 2 : MOG2; 3 : GMG; 4 : KNN; 5 : FGD (not implemented yet)" << endl;
        cin >> choice;
    }

    ///write parameters according to choices
    switch(atoi(choice.c_str()))
    {
        case 1 : // MOG
        {
            f << "Detect.BackgroundSubtraction.MOG=1"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG.nb_frame=200"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG.nb_mixture=5"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG.noiseRob=0.0"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG.decisionThreshold=0.7"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG2=0"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG2.detectShadows=1"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG2.nb_frame=500"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG2.thresholdSquare=16.0"<< "\n";
            f << "Detect.BackgroundSubtraction.GMG=0"<< "\n";
            f << "Detect.BackgroundSubtraction.GMG.decisionThreshold=0.8"<< "\n";
            f << "Detect.BackgroundSubtraction.GMG.nb_frame=120"<< "\n";
            f << "Detect.BackgroundSubtraction.KNN=0"<< "\n";
            f << "Detect.BackgroundSubtraction.KNN.nb_frame=500"<< "\n";
            f << "Detect.BackgroundSubtraction.KNN.thresholdSquare=400.0"<< "\n";
            f << "Detect.BackgroundSubtraction.KNN.detectShadows=1"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD=0" << "\n";
            f << "Detect.BackgroundSubtraction.FGD.alpha1=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.deltish=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.n1cc=10"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.n2c=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.n2cc=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.is_obj_without_holes=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.lc=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.n1c=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.lcc=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.perform_morphing=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.minArea=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.alpha2=1"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.t=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.alpha3=0"<< "\n";
            break;
        }
        case 2 : // MOG2
        {
            f << "Detect.BackgroundSubtraction.MOG=0"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG.nb_frame=200"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG.nb_mixture=5"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG.noiseRob=0.0"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG.decisionThreshold=0.7"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG2=1"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG2.detectShadows=1"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG2.nb_frame=500"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG2.thresholdSquare=16.0"<< "\n";
            f << "Detect.BackgroundSubtraction.GMG=0"<< "\n";
            f << "Detect.BackgroundSubtraction.GMG.decisionThreshold=0.8"<< "\n";
            f << "Detect.BackgroundSubtraction.GMG.nb_frame=120"<< "\n";
            f << "Detect.BackgroundSubtraction.KNN=0"<< "\n";
            f << "Detect.BackgroundSubtraction.KNN.nb_frame=500"<< "\n";
            f << "Detect.BackgroundSubtraction.KNN.thresholdSquare=400.0"<< "\n";
            f << "Detect.BackgroundSubtraction.KNN.detectShadows=1"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD=0" << "\n";
            f << "Detect.BackgroundSubtraction.FGD.alpha1=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.deltish=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.n1cc=10"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.n2c=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.n2cc=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.is_obj_without_holes=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.lc=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.n1c=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.lcc=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.perform_morphing=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.minArea=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.alpha2=1"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.t=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.alpha3=0"<< "\n";
            break;
        }
        case 3 : // GMG
        {
            f << "Detect.BackgroundSubtraction.MOG=0"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG.nb_frame=200"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG.nb_mixture=5"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG.noiseRob=0.0"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG.decisionThreshold=0.7"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG2=0"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG2.detectShadows=1"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG2.nb_frame=500"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG2.thresholdSquare=16.0"<< "\n";
            f << "Detect.BackgroundSubtraction.GMG=1"<< "\n";
            f << "Detect.BackgroundSubtraction.GMG.decisionThreshold=0.8"<< "\n";
            f << "Detect.BackgroundSubtraction.GMG.nb_frame=120"<< "\n";
            f << "Detect.BackgroundSubtraction.KNN=0"<< "\n";
            f << "Detect.BackgroundSubtraction.KNN.nb_frame=500"<< "\n";
            f << "Detect.BackgroundSubtraction.KNN.thresholdSquare=400.0"<< "\n";
            f << "Detect.BackgroundSubtraction.KNN.detectShadows=1"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD=0" << "\n";
            f << "Detect.BackgroundSubtraction.FGD.alpha1=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.deltish=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.n1cc=10"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.n2c=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.n2cc=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.is_obj_without_holes=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.lc=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.n1c=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.lcc=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.perform_morphing=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.minArea=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.alpha2=1"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.t=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.alpha3=0"<< "\n";
            break;
        }
        case 4 : // KNN
        {
            f << "Detect.BackgroundSubtraction.MOG=0"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG.nb_frame=200"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG.nb_mixture=5"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG.noiseRob=0.0"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG.decisionThreshold=0.7"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG2=0"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG2.detectShadows=1"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG2.nb_frame=500"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG2.thresholdSquare=16.0"<< "\n";
            f << "Detect.BackgroundSubtraction.GMG=0"<< "\n";
            f << "Detect.BackgroundSubtraction.GMG.decisionThreshold=0.8"<< "\n";
            f << "Detect.BackgroundSubtraction.GMG.nb_frame=120"<< "\n";
            f << "Detect.BackgroundSubtraction.KNN=1"<< "\n";
            f << "Detect.BackgroundSubtraction.KNN.nb_frame=500"<< "\n";
            f << "Detect.BackgroundSubtraction.KNN.thresholdSquare=400.0"<< "\n";
            f << "Detect.BackgroundSubtraction.KNN.detectShadows=1"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD=0" << "\n";
            f << "Detect.BackgroundSubtraction.FGD.alpha1=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.deltish=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.n1cc=10"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.n2c=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.n2cc=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.is_obj_without_holes=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.lc=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.n1c=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.lcc=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.perform_morphing=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.minArea=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.alpha2=1"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.t=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.alpha3=0"<< "\n";
            break;
        }
        default : cout << "Not implemented yet" << endl;
    }
    f << "Detect.OpticalFlow=0"<< "\n";
    f << "Detect.OpticalFlow.Dense=0"<< "\n";
    f << "Detect.OpticalFlow.Sparse=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.Farneback=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.SimpleFlow=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.DualTVL=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.Farneback.pyr_scale=0.5"<< "\n";
    f << "Detect.OpticalFlow.Dense.Farneback.levels=3"<< "\n";
    f << "Detect.OpticalFlow.Dense.Farneback.winSize=15"<< "\n";
    f << "Detect.OpticalFlow.Dense.Farneback.iterations=3"<< "\n";
    f << "Detect.OpticalFlow.Dense.Farneback.poly_n=5"<< "\n";
    f << "Detect.OpticalFlow.Dense.Farneback.poly_sigma=1.2"<< "\n";
    f << "Detect.OpticalFlow.Dense.Farneback.use_init_flow=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.Farneback.use_gaussian=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.Farneback.threshold=0.0001"<< "\n";
    f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK=0"<< "\n";
    f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.winSize=0"<< "\n";
    f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.maxLevel=0"<< "\n";
    f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.count=0"<< "\n";
    f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.epsilon=0"<< "\n";
    f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.use_initial_flow=0"<< "\n";
    f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.use_eigen_val=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.SimpleFlow.nb_layer=3"<< "\n";
    f << "Detect.OpticalFlow.Dense.SimpleFlow.averaging_block_size=2"<< "\n";
    f << "Detect.OpticalFlow.Dense.SimpleFlow.max_flow=4"<< "\n";
    f << "Detect.OpticalFlow.Dense.DualTVL.tau=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.DualTVL.lambda=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.DualTVL.theta=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.DualTVL.nscales=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.DualTVL.warps=1"<< "\n";
    f << "Detect.OpticalFlow.Dense.DualTVL.epsilon=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.DualTVL.iterations=0"<< "\n";
    f << "Detect.BlockMatching=0" << "\n";
    f << "Detect.BlockMatching.min_disparity=0"<< "\n";
    f << "Detect.BlockMatching.num_disparities=16"<< "\n";
    f << "Detect.BlockMatching.block_size=3"<< "\n";
    f << "Detect.BlockMatching.p1=0"<< "\n";
    f << "Detect.BlockMatching.p2=0"<< "\n";
    f << "Detect.BlockMatching.disp12_max_diff=0"<< "\n";
    f << "Detect.BlockMatching.pre_filter_cap=0"<< "\n";
    f << "Detect.BlockMatching.uniqueness_ratio=0"<< "\n";
    f << "Detect.BlockMatching.speckle_window_size=0"<< "\n";
    f << "Detect.BlockMatching.speckle_range=0"<< "\n";
    f << "Detect.MotionHistory=0"<< "\n";
    f << "Detect.MotionHistory.mhi_duration=5"<< "\n";
    f << "Detect.MotionHistory.min_time_delta=0.05"<< "\n";
    f << "Detect.MotionHistory.max_time_delta=10"<<"\n";
    f << "Detect.MotionHistory.threshold=22"<<"\n";

    return idx;
}

/**
* a function called in interactive mode to write the optical flow module
* users have decided to use optical flow as a detection module they also decided to give default values for each parameters
* parameters will be wrote for all the detection module (except for the common parts) : one activated, the others will not be
*
* input :
*   - fstream& f : a file stream representing the output file
*
* output :
*   - the optical flow module should be written into the output file (assuming that the file has been closed to flush the buffer)
*/
void write_use_optFlow(fstream& f)
{
    f << "Detect.BackgroundSubtraction=0"<< "\n";
    f << "Detect.BackgroundSubtraction.MOG=0"<< "\n";
    f << "Detect.BackgroundSubtraction.MOG.nb_frame=200"<< "\n";
    f << "Detect.BackgroundSubtraction.MOG.nb_mixture=5"<< "\n";
    f << "Detect.BackgroundSubtraction.MOG.noiseRob=0.0"<< "\n";
    f << "Detect.BackgroundSubtraction.MOG.decisionThreshold=0.7"<< "\n";
    f << "Detect.BackgroundSubtraction.MOG2=0"<< "\n";
    f << "Detect.BackgroundSubtraction.MOG2.detectShadows=1"<< "\n";
    f << "Detect.BackgroundSubtraction.MOG2.nb_frame=500"<< "\n";
    f << "Detect.BackgroundSubtraction.MOG2.thresholdSquare=16.0"<< "\n";
    f << "Detect.BackgroundSubtraction.GMG=0"<< "\n";
    f << "Detect.BackgroundSubtraction.GMG.decisionThreshold=0.8"<< "\n";
    f << "Detect.BackgroundSubtraction.GMG.nb_frame=120"<< "\n";
    f << "Detect.BackgroundSubtraction.KNN=0"<< "\n";
    f << "Detect.BackgroundSubtraction.KNN.nb_frame=500"<< "\n";
    f << "Detect.BackgroundSubtraction.KNN.thresholdSquare=400.0"<< "\n";
    f << "Detect.BackgroundSubtraction.KNN.detectShadows=1"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD=0" << "\n";
    f << "Detect.BackgroundSubtraction.FGD.alpha1=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.deltish=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.n1cc=10"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.n2c=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.n2cc=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.is_obj_without_holes=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.lc=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.n1c=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.lcc=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.perform_morphing=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.minArea=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.alpha2=1"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.t=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.alpha3=0"<< "\n";

    ///which method to use ?
    cout << "Which method do you want to use ? (1 : Farneback; 2 : Simple Flow; 3 : DuaTVL1" << endl;
    string choice;
    cin >> choice;
    while (choice != "1" && choice != "2" && choice != "3" && choice != "4")
    {
        cout << "Which method do you want to use ? (1 : Farneback; 2 : Simple Flow; 3 : DuaTVL1" << endl;
        cin >> choice;
    }

    ///write parameters according to choices
    switch(atoi(choice.c_str()))
    {
        case 1 : //use Farneback
        {
            f << "Detect.OpticalFlow=1"<< "\n";
            f << "Detect.OpticalFlow.Dense=1"<< "\n";
            f << "Detect.OpticalFlow.Sparse=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback=1"<< "\n";
            f << "Detect.OpticalFlow.Dense.SimpleFlow=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.pyr_scale=0.5"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.levels=3"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.winSize=15"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.iterations=3"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.poly_n=5"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.poly_sigma=1.2"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.use_init_flow=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.use_gaussian=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.threshold=0.0001"<< "\n";
            f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK=0"<< "\n";
            f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.winSize=0"<< "\n";
            f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.maxLevel=0"<< "\n";
            f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.count=0"<< "\n";
            f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.epsilon=0"<< "\n";
            f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.use_initial_flow=0"<< "\n";
            f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.use_eigen_val=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.SimpleFlow.nb_layer=3"<< "\n";
            f << "Detect.OpticalFlow.Dense.SimpleFlow.averaging_block_size=2"<< "\n";
            f << "Detect.OpticalFlow.Dense.SimpleFlow.max_flow=4"<< "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL.tau=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL.lambda=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL.theta=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL.nscales=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL.warps=1"<< "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL.epsilon=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL.iterations=0"<< "\n";
            break;
        }

        case 2 : // use Simple Flow
        {
                        f << "Detect.OpticalFlow=1"<< "\n";
            f << "Detect.OpticalFlow.Dense=1"<< "\n";
            f << "Detect.OpticalFlow.Sparse=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.SimpleFlow=1"<< "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.pyr_scale=0.5"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.levels=3"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.winSize=15"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.iterations=3"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.poly_n=5"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.poly_sigma=1.2"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.use_init_flow=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.use_gaussian=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.threshold=0.0001"<< "\n";
            f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK=0"<< "\n";
            f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.winSize=0"<< "\n";
            f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.maxLevel=0"<< "\n";
            f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.count=0"<< "\n";
            f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.epsilon=0"<< "\n";
            f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.use_initial_flow=0"<< "\n";
            f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.use_eigen_val=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.SimpleFlow.nb_layer=3"<< "\n";
            f << "Detect.OpticalFlow.Dense.SimpleFlow.averaging_block_size=2"<< "\n";
            f << "Detect.OpticalFlow.Dense.SimpleFlow.max_flow=4"<< "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL.tau=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL.lambda=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL.theta=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL.nscales=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL.warps=1"<< "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL.epsilon=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL.iterations=0"<< "\n";
            break;
        }
        case 3 : // use Dual TVL 1
        {
            f << "Detect.OpticalFlow=1"<< "\n";
            f << "Detect.OpticalFlow.Dense=1"<< "\n";
            f << "Detect.OpticalFlow.Sparse=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.SimpleFlow=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL=1"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.pyr_scale=0.5"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.levels=3"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.winSize=15"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.iterations=3"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.poly_n=5"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.poly_sigma=1.2"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.use_init_flow=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.use_gaussian=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.threshold=0.0001"<< "\n";
            f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK=0"<< "\n";
            f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.winSize=0"<< "\n";
            f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.maxLevel=0"<< "\n";
            f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.count=0"<< "\n";
            f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.epsilon=0"<< "\n";
            f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.use_initial_flow=0"<< "\n";
            f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.use_eigen_val=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.SimpleFlow.nb_layer=3"<< "\n";
            f << "Detect.OpticalFlow.Dense.SimpleFlow.averaging_block_size=2"<< "\n";
            f << "Detect.OpticalFlow.Dense.SimpleFlow.max_flow=4"<< "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL.tau=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL.lambda=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL.theta=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL.nscales=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL.warps=1"<< "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL.epsilon=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL.iterations=0"<< "\n";
            break;
        }
    }
    f << "Detect.BlockMatching=0" << "\n";
    f << "Detect.BlockMatching.min_disparity=0"<< "\n";
    f << "Detect.BlockMatching.num_disparities=16"<< "\n";
    f << "Detect.BlockMatching.block_size=3"<< "\n";
    f << "Detect.BlockMatching.p1=0"<< "\n";
    f << "Detect.BlockMatching.p2=0"<< "\n";
    f << "Detect.BlockMatching.disp12_max_diff=0"<< "\n";
    f << "Detect.BlockMatching.pre_filter_cap=0"<< "\n";
    f << "Detect.BlockMatching.uniqueness_ratio=0"<< "\n";
    f << "Detect.BlockMatching.speckle_window_size=0"<< "\n";
    f << "Detect.BlockMatching.speckle_range=0"<< "\n";
    f << "Detect.MotionHistory=0"<< "\n";
    f << "Detect.MotionHistory.mhi_duration=5"<< "\n";
    f << "Detect.MotionHistory.min_time_delta=0.05"<< "\n";
    f << "Detect.MotionHistory.max_time_delta=10"<<"\n";
    f << "Detect.MotionHistory.threshold=22"<<"\n";
}

/**
* a function called in interactive mode to write the optical flow module
* users have decided to use optical flow as a detection module they also decided to give default values for each parameters
* parameters will be wrote for all the detection module (except for the common parts) : one activated, the others will not be
*
* input :
*   - fstream& f : a file stream representing the output file
*   - char** argv : the list of arguments given to the program when has been called
*   - int idx : the index of the next argument to retrieve
*
* output :
*   - the optical flow module should be written into the output file (assuming that the file has been closed to flush the buffer)
*   - int : the index of the next argument to retrieve
*/
int write_use_optFlow(fstream& f,char** argv, int idx)
{
    f << "Detect.BackgroundSubtraction=0"<< "\n";
    f << "Detect.BackgroundSubtraction.MOG=0"<< "\n";
    f << "Detect.BackgroundSubtraction.MOG.nb_frame=200"<< "\n";
    f << "Detect.BackgroundSubtraction.MOG.nb_mixture=5"<< "\n";
    f << "Detect.BackgroundSubtraction.MOG.noiseRob=0.0"<< "\n";
    f << "Detect.BackgroundSubtraction.MOG.decisionThreshold=0.7"<< "\n";
    f << "Detect.BackgroundSubtraction.MOG2=0"<< "\n";
    f << "Detect.BackgroundSubtraction.MOG2.detectShadows=1"<< "\n";
    f << "Detect.BackgroundSubtraction.MOG2.nb_frame=500"<< "\n";
    f << "Detect.BackgroundSubtraction.MOG2.thresholdSquare=16.0"<< "\n";
    f << "Detect.BackgroundSubtraction.GMG=0"<< "\n";
    f << "Detect.BackgroundSubtraction.GMG.decisionThreshold=0.8"<< "\n";
    f << "Detect.BackgroundSubtraction.GMG.nb_frame=120"<< "\n";
    f << "Detect.BackgroundSubtraction.KNN=0"<< "\n";
    f << "Detect.BackgroundSubtraction.KNN.nb_frame=500"<< "\n";
    f << "Detect.BackgroundSubtraction.KNN.thresholdSquare=400.0"<< "\n";
    f << "Detect.BackgroundSubtraction.KNN.detectShadows=1"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD=0" << "\n";
    f << "Detect.BackgroundSubtraction.FGD.alpha1=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.deltish=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.n1cc=10"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.n2c=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.n2cc=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.is_obj_without_holes=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.lc=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.n1c=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.lcc=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.perform_morphing=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.minArea=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.alpha2=1"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.t=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.alpha3=0"<< "\n";

    ///which method to use ?
    cout << "Which method do you want to use ? (1 : Farneback; 2 : Simple Flow; 3 : DuaTVL1" << endl;
    string choice(argv[idx]);
    //cin >> choice;
    cout << choice << endl;
    idx++;

    while (choice != "1" && choice != "2" && choice != "3" && choice != "4")
    {
        cout << "Which method do you want to use ? (1 : Farneback; 2 : Simple Flow; 3 : DuaTVL1" << endl;
        cin >> choice;
    }

    ///write parameters according to choices
    switch(atoi(choice.c_str()))
    {
        case 1 : //use Farneback
        {
            f << "Detect.OpticalFlow=1"<< "\n";
            f << "Detect.OpticalFlow.Dense=1"<< "\n";
            f << "Detect.OpticalFlow.Sparse=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback=1"<< "\n";
            f << "Detect.OpticalFlow.Dense.SimpleFlow=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.pyr_scale=0.5"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.levels=3"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.winSize=15"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.iterations=3"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.poly_n=5"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.poly_sigma=1.2"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.use_init_flow=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.use_gaussian=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.threshold=0.0001"<< "\n";
            f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK=0"<< "\n";
            f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.winSize=0"<< "\n";
            f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.maxLevel=0"<< "\n";
            f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.count=0"<< "\n";
            f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.epsilon=0"<< "\n";
            f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.use_initial_flow=0"<< "\n";
            f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.use_eigen_val=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.SimpleFlow.nb_layer=3"<< "\n";
            f << "Detect.OpticalFlow.Dense.SimpleFlow.averaging_block_size=2"<< "\n";
            f << "Detect.OpticalFlow.Dense.SimpleFlow.max_flow=4"<< "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL.tau=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL.lambda=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL.theta=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL.nscales=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL.warps=1"<< "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL.epsilon=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL.iterations=0"<< "\n";
            break;
        }

        case 2 : // use Simple Flow
        {
                        f << "Detect.OpticalFlow=1"<< "\n";
            f << "Detect.OpticalFlow.Dense=1"<< "\n";
            f << "Detect.OpticalFlow.Sparse=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.SimpleFlow=1"<< "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.pyr_scale=0.5"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.levels=3"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.winSize=15"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.iterations=3"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.poly_n=5"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.poly_sigma=1.2"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.use_init_flow=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.use_gaussian=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.threshold=0.0001"<< "\n";
            f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK=0"<< "\n";
            f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.winSize=0"<< "\n";
            f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.maxLevel=0"<< "\n";
            f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.count=0"<< "\n";
            f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.epsilon=0"<< "\n";
            f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.use_initial_flow=0"<< "\n";
            f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.use_eigen_val=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.SimpleFlow.nb_layer=3"<< "\n";
            f << "Detect.OpticalFlow.Dense.SimpleFlow.averaging_block_size=2"<< "\n";
            f << "Detect.OpticalFlow.Dense.SimpleFlow.max_flow=4"<< "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL.tau=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL.lambda=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL.theta=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL.nscales=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL.warps=1"<< "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL.epsilon=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL.iterations=0"<< "\n";
            break;
        }
        case 3 : // use Dual TVL 1
        {
            f << "Detect.OpticalFlow=1"<< "\n";
            f << "Detect.OpticalFlow.Dense=1"<< "\n";
            f << "Detect.OpticalFlow.Sparse=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.SimpleFlow=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL=1"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.pyr_scale=0.5"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.levels=3"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.winSize=15"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.iterations=3"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.poly_n=5"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.poly_sigma=1.2"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.use_init_flow=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.use_gaussian=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.threshold=0.0001"<< "\n";
            f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK=0"<< "\n";
            f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.winSize=0"<< "\n";
            f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.maxLevel=0"<< "\n";
            f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.count=0"<< "\n";
            f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.epsilon=0"<< "\n";
            f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.use_initial_flow=0"<< "\n";
            f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.use_eigen_val=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.SimpleFlow.nb_layer=3"<< "\n";
            f << "Detect.OpticalFlow.Dense.SimpleFlow.averaging_block_size=2"<< "\n";
            f << "Detect.OpticalFlow.Dense.SimpleFlow.max_flow=4"<< "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL.tau=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL.lambda=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL.theta=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL.nscales=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL.warps=1"<< "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL.epsilon=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL.iterations=0"<< "\n";
            break;
        }
    }
    f << "Detect.BlockMatching=0" << "\n";
    f << "Detect.BlockMatching.min_disparity=0"<< "\n";
    f << "Detect.BlockMatching.num_disparities=16"<< "\n";
    f << "Detect.BlockMatching.block_size=3"<< "\n";
    f << "Detect.BlockMatching.p1=0"<< "\n";
    f << "Detect.BlockMatching.p2=0"<< "\n";
    f << "Detect.BlockMatching.disp12_max_diff=0"<< "\n";
    f << "Detect.BlockMatching.pre_filter_cap=0"<< "\n";
    f << "Detect.BlockMatching.uniqueness_ratio=0"<< "\n";
    f << "Detect.BlockMatching.speckle_window_size=0"<< "\n";
    f << "Detect.BlockMatching.speckle_range=0"<< "\n";
    f << "Detect.MotionHistory=0"<< "\n";
    f << "Detect.MotionHistory.mhi_duration=5"<< "\n";
    f << "Detect.MotionHistory.min_time_delta=0.05"<< "\n";
    f << "Detect.MotionHistory.max_time_delta=10"<<"\n";
    f << "Detect.MotionHistory.threshold=22"<<"\n";

    return idx;
}

/**
* a function called to write the Block Matching module
* this function is used in both modes
* users have decided to use block matching as a detection module they also decided to give default values for each parameters
* parameters will be wrote for all the detection module (except for the common parts) : one activated, the others will not be
*
* input :
*   - fstream& f : a file stream representing the output file
*
* output :
*   - the Block Matching module should be written in the output file (assuming that the file has been closed to flush the buffer)
*/
void write_use_BM(fstream& f)
{
    f << "Detect.BackgroundSubtraction=0"<< "\n";
    f << "Detect.BackgroundSubtraction.MOG=0"<< "\n";
    f << "Detect.BackgroundSubtraction.MOG.nb_frame=200"<< "\n";
    f << "Detect.BackgroundSubtraction.MOG.nb_mixture=5"<< "\n";
    f << "Detect.BackgroundSubtraction.MOG.noiseRob=0.0"<< "\n";
    f << "Detect.BackgroundSubtraction.MOG.decisionThreshold=0.7"<< "\n";
    f << "Detect.BackgroundSubtraction.MOG2=0"<< "\n";
    f << "Detect.BackgroundSubtraction.MOG2.detectShadows=1"<< "\n";
    f << "Detect.BackgroundSubtraction.MOG2.nb_frame=500"<< "\n";
    f << "Detect.BackgroundSubtraction.MOG2.thresholdSquare=16.0"<< "\n";
    f << "Detect.BackgroundSubtraction.GMG=0"<< "\n";
    f << "Detect.BackgroundSubtraction.GMG.decisionThreshold=0.8"<< "\n";
    f << "Detect.BackgroundSubtraction.GMG.nb_frame=120"<< "\n";
    f << "Detect.BackgroundSubtraction.KNN=0"<< "\n";
    f << "Detect.BackgroundSubtraction.KNN.nb_frame=500"<< "\n";
    f << "Detect.BackgroundSubtraction.KNN.thresholdSquare=400.0"<< "\n";
    f << "Detect.BackgroundSubtraction.KNN.detectShadows=1"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD=0" << "\n";
    f << "Detect.BackgroundSubtraction.FGD.alpha1=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.deltish=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.n1cc=10"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.n2c=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.n2cc=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.is_obj_without_holes=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.lc=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.n1c=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.lcc=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.perform_morphing=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.minArea=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.alpha2=1"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.t=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.alpha3=0"<< "\n";

    f << "Detect.OpticalFlow=0"<< "\n";
    f << "Detect.OpticalFlow.Dense=0"<< "\n";
    f << "Detect.OpticalFlow.Sparse=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.Farneback=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.SimpleFlow=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.DualTVL=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.Farneback.pyr_scale=0.5"<< "\n";
    f << "Detect.OpticalFlow.Dense.Farneback.levels=3"<< "\n";
    f << "Detect.OpticalFlow.Dense.Farneback.winSize=15"<< "\n";
    f << "Detect.OpticalFlow.Dense.Farneback.iterations=3"<< "\n";
    f << "Detect.OpticalFlow.Dense.Farneback.poly_n=5"<< "\n";
    f << "Detect.OpticalFlow.Dense.Farneback.poly_sigma=1.2"<< "\n";
    f << "Detect.OpticalFlow.Dense.Farneback.use_init_flow=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.Farneback.use_gaussian=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.Farneback.threshold=0.0001"<< "\n";
    f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK=0"<< "\n";
    f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.winSize=0"<< "\n";
    f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.maxLevel=0"<< "\n";
    f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.count=0"<< "\n";
    f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.epsilon=0"<< "\n";
    f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.use_initial_flow=0"<< "\n";
    f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.use_eigen_val=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.SimpleFlow.nb_layer=3"<< "\n";
    f << "Detect.OpticalFlow.Dense.SimpleFlow.averaging_block_size=2"<< "\n";
    f << "Detect.OpticalFlow.Dense.SimpleFlow.max_flow=4"<< "\n";
    f << "Detect.OpticalFlow.Dense.DualTVL.tau=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.DualTVL.lambda=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.DualTVL.theta=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.DualTVL.nscales=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.DualTVL.warps=1"<< "\n";
    f << "Detect.OpticalFlow.Dense.DualTVL.epsilon=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.DualTVL.iterations=0"<< "\n";

    f << "Detect.BlockMatching=1" << "\n";
    f << "Detect.BlockMatching.min_disparity=0"<< "\n";
    f << "Detect.BlockMatching.num_disparities=16"<< "\n";
    f << "Detect.BlockMatching.block_size=3"<< "\n";
    f << "Detect.BlockMatching.p1=0"<< "\n";
    f << "Detect.BlockMatching.p2=0"<< "\n";
    f << "Detect.BlockMatching.disp12_max_diff=0"<< "\n";
    f << "Detect.BlockMatching.pre_filter_cap=0"<< "\n";
    f << "Detect.BlockMatching.uniqueness_ratio=0"<< "\n";
    f << "Detect.BlockMatching.speckle_window_size=0"<< "\n";
    f << "Detect.BlockMatching.speckle_range=0"<< "\n";

    f << "Detect.MotionHistory=0"<< "\n";
    f << "Detect.MotionHistory.mhi_duration=5"<< "\n";
    f << "Detect.MotionHistory.min_time_delta=0.05"<< "\n";
    f << "Detect.MotionHistory.max_time_delta=10"<<"\n";
    f << "Detect.MotionHistory.threshold=22"<<"\n";

}

/**
* a function called in interactive mode to write the motion history module
* this function is used in both modes
* users have decided to use motion history as a detection module they also decided to give default values for each parameters
* parameters will be wrote for all the detection module (except for the common parts) : one activated, the others will not be
*
* input :
*   - fstream& f : a file stream representing the output file
*
* output :
*   - the Motion History module should be written in the output file (assuming the file has been closed to flush its buffer)
*/
void write_use_MH(fstream& f)
{
    f << "Detect.BackgroundSubtraction=0"<< "\n";
    f << "Detect.BackgroundSubtraction.MOG=0"<< "\n";
    f << "Detect.BackgroundSubtraction.MOG.nb_frame=200"<< "\n";
    f << "Detect.BackgroundSubtraction.MOG.nb_mixture=5"<< "\n";
    f << "Detect.BackgroundSubtraction.MOG.noiseRob=0.0"<< "\n";
    f << "Detect.BackgroundSubtraction.MOG.decisionThreshold=0.7"<< "\n";
    f << "Detect.BackgroundSubtraction.MOG2=0"<< "\n";
    f << "Detect.BackgroundSubtraction.MOG2.detectShadows=1"<< "\n";
    f << "Detect.BackgroundSubtraction.MOG2.nb_frame=500"<< "\n";
    f << "Detect.BackgroundSubtraction.MOG2.thresholdSquare=16.0"<< "\n";
    f << "Detect.BackgroundSubtraction.GMG=0"<< "\n";
    f << "Detect.BackgroundSubtraction.GMG.decisionThreshold=0.8"<< "\n";
    f << "Detect.BackgroundSubtraction.GMG.nb_frame=120"<< "\n";
    f << "Detect.BackgroundSubtraction.KNN=0"<< "\n";
    f << "Detect.BackgroundSubtraction.KNN.nb_frame=500"<< "\n";
    f << "Detect.BackgroundSubtraction.KNN.thresholdSquare=400.0"<< "\n";
    f << "Detect.BackgroundSubtraction.KNN.detectShadows=1"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD=0" << "\n";
    f << "Detect.BackgroundSubtraction.FGD.alpha1=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.deltish=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.n1cc=10"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.n2c=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.n2cc=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.is_obj_without_holes=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.lc=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.n1c=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.lcc=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.perform_morphing=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.minArea=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.alpha2=1"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.t=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.alpha3=0"<< "\n";

    f << "Detect.OpticalFlow=0"<< "\n";
    f << "Detect.OpticalFlow.Dense=0"<< "\n";
    f << "Detect.OpticalFlow.Sparse=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.Farneback=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.SimpleFlow=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.DualTVL=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.Farneback.pyr_scale=0.5"<< "\n";
    f << "Detect.OpticalFlow.Dense.Farneback.levels=3"<< "\n";
    f << "Detect.OpticalFlow.Dense.Farneback.winSize=15"<< "\n";
    f << "Detect.OpticalFlow.Dense.Farneback.iterations=3"<< "\n";
    f << "Detect.OpticalFlow.Dense.Farneback.poly_n=5"<< "\n";
    f << "Detect.OpticalFlow.Dense.Farneback.poly_sigma=1.2"<< "\n";
    f << "Detect.OpticalFlow.Dense.Farneback.use_init_flow=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.Farneback.use_gaussian=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.Farneback.threshold=0.0001"<< "\n";
    f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK=0"<< "\n";
    f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.winSize=0"<< "\n";
    f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.maxLevel=0"<< "\n";
    f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.count=0"<< "\n";
    f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.epsilon=0"<< "\n";
    f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.use_initial_flow=0"<< "\n";
    f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.use_eigen_val=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.SimpleFlow.nb_layer=3"<< "\n";
    f << "Detect.OpticalFlow.Dense.SimpleFlow.averaging_block_size=2"<< "\n";
    f << "Detect.OpticalFlow.Dense.SimpleFlow.max_flow=4"<< "\n";
    f << "Detect.OpticalFlow.Dense.DualTVL.tau=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.DualTVL.lambda=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.DualTVL.theta=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.DualTVL.nscales=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.DualTVL.warps=1"<< "\n";
    f << "Detect.OpticalFlow.Dense.DualTVL.epsilon=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.DualTVL.iterations=0"<< "\n";

    f << "Detect.BlockMatching=0" << "\n";
    f << "Detect.BlockMatching.min_disparity=0"<< "\n";
    f << "Detect.BlockMatching.num_disparities=16"<< "\n";
    f << "Detect.BlockMatching.block_size=3"<< "\n";
    f << "Detect.BlockMatching.p1=0"<< "\n";
    f << "Detect.BlockMatching.p2=0"<< "\n";
    f << "Detect.BlockMatching.disp12_max_diff=0"<< "\n";
    f << "Detect.BlockMatching.pre_filter_cap=0"<< "\n";
    f << "Detect.BlockMatching.uniqueness_ratio=0"<< "\n";
    f << "Detect.BlockMatching.speckle_window_size=0"<< "\n";
    f << "Detect.BlockMatching.speckle_range=0"<< "\n";

    f << "Detect.MotionHistory=1"<< "\n";
    f << "Detect.MotionHistory.mhi_duration=5"<< "\n";
    f << "Detect.MotionHistory.min_time_delta=0.05"<< "\n";
    f << "Detect.MotionHistory.max_time_delta=10"<<"\n";
    f << "Detect.MotionHistory.threshold=22"<<"\n";
}

/**
* a function called in interactive mode which will write common part of the detection module
* users has decided to use detection module and have chosen which one, call the function according to choices
* this function will write default values for the given choice -> other choices in the module will be deactivated
* input :
*   - fstream& f : a file stream representing the output file (avoid copy)
*   - int choice : the choice made regarding the method to be used
*
* output :
*   - something is written in the output file
*   - methods of the detection module that are not used are deactivated
*/
void write_detect_default(fstream& f, int choice)
{
    f << "OpenCV.nb_frame=222"<< "\n";
    f << "Detect=1"<< "\n";
    switch(choice)
    {
        case 1 : //use background subtraction
        {
            write_use_bgSub(f);
            break;
        }
        case 2 : //use Optical Flow
        {
            write_use_optFlow(f);
            break;
        }
        case 3 : //use BM
        {
            write_use_BM(f);
            break;
        }
        case 4:  //use Motion History
        {
            write_use_MH(f);
            break;
        }
    }

    f << "Detect.MorphologicalOperators=1"<< "\n";
    f << "Detect.MorphologicalOperators.Dilate=1"<< "\n";
    f << "Detect.MorphologicalOperators.Dilate.shape=rectangle"<< "\n";
    f << "Detect.MorphologicalOperators.Dilate.height=10"<< "\n";
    f << "Detect.MorphologicalOperators.Dilate.width=10"<< "\n";
    f << "Detect.MorphologicalOperators.Dilate.anchory=-1"<< "\n";
    f << "Detect.MorphologicalOperators.Dilate.anchorx=-1"<< "\n";
    f << "Detect.MorphologicalOperators.Erode=1"<< "\n";
    f << "Detect.MorphologicalOperators.Erode.shape=rectangle"<< "\n";
    f << "Detect.MorphologicalOperators.Erode.height=10"<< "\n";
    f << "Detect.MorphologicalOperators.Erode.width=10"<< "\n";
    f << "Detect.MorphologicalOperators.Erode.anchorx=-1"<< "\n";
    f << "Detect.MorphologicalOperators.Erode.anchory=-1"<< "\n";
    f << "Detect.ContoursRetrieval=1"<< "\n";
    f << "Detect.ContoursHierarchical.HCR=0"<< "\n";
    f << "Detect.ContoursHierarchical.HCR.External=0"<< "\n";
    f << "Detect.ContoursHierarchical.HCR.C_comp=0"<< "\n";
    f << "Detect.ContoursHierarchical.HCR.Tree=0"<< "\n";
    f << "Detect.ContoursHierarchical.NHCR=1"<< "\n";
    f << "Detect.ContoursHierarchical.NHCR.List=1"<< "\n";
    f << "Detect.ContoursHierarchical.None=0"<< "\n";
    f << "Detect.ContoursHierarchical.Approximate=1"<< "\n";
    f << "Detect.ContoursHierarchical.Approximate.K_Cos=0"<< "\n";
    f << "Detect.ContoursHierarchical.Approximate.Simple=1"<< "\n";
    f << "Detect.ContoursHierarchical.Approximate.L1=0"<< "\n";
    f << "Detect.ContoursHierarchical.offsetx=0"<< "\n";
    f << "Detect.ContoursHierarchical.offsety=0"<< "\n";
    f << "Detect.MerginBoundingBoxes=1"<< "\n";
    f << "Detect.MerginBoundingBoxes.scalingFactor=10"<< "\n";
    f << "Detect.MerginBoundingBoxes.nb_loop=-1"<< "\n";
    f << "Detect.MerginBoundingBoxes.maxDistance=10"<< "\n";
    f << "Detect.Filters=1"<< "\n";
    f << "Detect.Filters.FilterLenght=1"<< "\n";
    f << "Detect.Filters.FilterLenght.threshold=10"<< "\n";
    f << "Detect.Filters.FilterArea=1"<< "\n";
    f << "Detect.Filters.FilterArea.threshold=100"<< "\n";
}

/**
* a function which will write common part of the detection module
* users has decided to use detection module and have chosen which one, call the function according to choices
* this function will write default values for the given choice -> other choices in the module will be deactivated
* input :
*   - fstream& f : a file stream representing the output file (avoid copy)
*   - int choice : the choice made regarding the method to be used
*
* output :
*   - something is written in the output file
*   - methods of the detection module that are not used are deactivated
*/
int write_detect_default(fstream& f, int choice, char** argv, int idx)
{
    f << "OpenCV.nb_frame=222"<< "\n";
    f << "Detect=1"<< "\n";
    switch(choice)
    {
        case 1 : //use background subtraction
        {
            idx = write_use_bgSub(f, argv, idx);
            break;
        }
        case 2 : //use Optical Flow
        {
            idx = write_use_optFlow(f, argv, idx);
            break;
        }
        case 3 : //use BM
        {
            write_use_BM(f);
            break;
        }
        case 4:  //use Motion History
        {
            write_use_MH(f);
            break;
        }
    }

    f << "Detect.MorphologicalOperators=1"<< "\n";
    f << "Detect.MorphologicalOperators.Dilate=1"<< "\n";
    f << "Detect.MorphologicalOperators.Dilate.shape=rectangle"<< "\n";
    f << "Detect.MorphologicalOperators.Dilate.height=10"<< "\n";
    f << "Detect.MorphologicalOperators.Dilate.width=10"<< "\n";
    f << "Detect.MorphologicalOperators.Dilate.anchory=-1"<< "\n";
    f << "Detect.MorphologicalOperators.Dilate.anchorx=-1"<< "\n";
    f << "Detect.MorphologicalOperators.Erode=1"<< "\n";
    f << "Detect.MorphologicalOperators.Erode.shape=rectangle"<< "\n";
    f << "Detect.MorphologicalOperators.Erode.height=10"<< "\n";
    f << "Detect.MorphologicalOperators.Erode.width=10"<< "\n";
    f << "Detect.MorphologicalOperators.Erode.anchorx=-1"<< "\n";
    f << "Detect.MorphologicalOperators.Erode.anchory=-1"<< "\n";
    f << "Detect.ContoursRetrieval=1"<< "\n";
    f << "Detect.ContoursHierarchical.HCR=0"<< "\n";
    f << "Detect.ContoursHierarchical.HCR.External=0"<< "\n";
    f << "Detect.ContoursHierarchical.HCR.C_comp=0"<< "\n";
    f << "Detect.ContoursHierarchical.HCR.Tree=0"<< "\n";
    f << "Detect.ContoursHierarchical.NHCR=1"<< "\n";
    f << "Detect.ContoursHierarchical.NHCR.List=1"<< "\n";
    f << "Detect.ContoursHierarchical.None=0"<< "\n";
    f << "Detect.ContoursHierarchical.Approximate=1"<< "\n";
    f << "Detect.ContoursHierarchical.Approximate.K_Cos=0"<< "\n";
    f << "Detect.ContoursHierarchical.Approximate.Simple=1"<< "\n";
    f << "Detect.ContoursHierarchical.Approximate.L1=0"<< "\n";
    f << "Detect.ContoursHierarchical.offsetx=0"<< "\n";
    f << "Detect.ContoursHierarchical.offsety=0"<< "\n";
    f << "Detect.MerginBoundingBoxes=1"<< "\n";
    f << "Detect.MerginBoundingBoxes.scalingFactor=10"<< "\n";
    f << "Detect.MerginBoundingBoxes.nb_loop=-1"<< "\n";
    f << "Detect.MerginBoundingBoxes.maxDistance=10"<< "\n";
    f << "Detect.Filters=1"<< "\n";
    f << "Detect.Filters.FilterLenght=1"<< "\n";
    f << "Detect.Filters.FilterLenght.threshold=10"<< "\n";
    f << "Detect.Filters.FilterArea=1"<< "\n";
    f << "Detect.Filters.FilterArea.threshold=100"<< "\n";

    return idx;
}

/**
* a function called in interactive mode to write the background subtraction module
* users have decided to use background subtraction as a detection module they also decided to give random values for each parameters
* parameters will be wrote for all the detection module (except for the common parts) : one activated, the others will not be
* random values are an approximation of a Gaussian distribution based on the use of uniformly distributed values
*
* input :
*   - fstream& f : a file stream representing the output file
*/
void write_use_bgSub_rand(fstream& f)
{
    f << "Detect.BackgroundSubtraction=1"<< "\n";

    ///which method to use ?
    cout << "Which method do you want to use ? (1 : MOG; 2 : MOG2; 3 : GMG; 4 : KNN; 5 : FGD (not implemented yet)" << endl;
    string choice;
    cin >> choice;
    while (choice != "1" && choice != "2" && choice != "3" && choice != "4")
    {
        cout << "Which method do you want to use ? (1 : MOG; 2 : MOG2; 3 : GMG; 4 : KNN; 5 : FGD (not implemented yet)" << endl;
        cin >> choice;
    }

    ///write parameters corresponding to choices
    switch(atoi(choice.c_str()))
    {
        case 1 : // use MOG
        {
            //int res_frame = rand() % 500;
            int res_frame = (((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX)+ ((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX) ) * 125; //between 0 and 500 -> mean around 250
            int res_mixt = (((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX)+ ((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX) ) * 2.5 + 2; //between 2 and 12 -> mean around 7
            double res_robust = (((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX)+ ((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX) ) /4; // between 0 and 1 -> mean around 0.5
            double res_thresh = (((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX)+ ((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX) ) /4; // between 0 and 1 -> mean around 0.5
            f << "Detect.BackgroundSubtraction.MOG=1"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG.nb_frame=" << res_frame << "\n";
            f << "Detect.BackgroundSubtraction.MOG.nb_mixture=" << res_mixt << "\n";
            f << "Detect.BackgroundSubtraction.MOG.noiseRob=" << res_robust << "\n";
            f << "Detect.BackgroundSubtraction.MOG.decisionThreshold=" << res_thresh << "\n";
            f << "Detect.BackgroundSubtraction.MOG2=0"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG2.detectShadows=1"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG2.nb_frame=500"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG2.thresholdSquare=16.0"<< "\n";
            f << "Detect.BackgroundSubtraction.GMG=0"<< "\n";
            f << "Detect.BackgroundSubtraction.GMG.decisionThreshold=0.8"<< "\n";
            f << "Detect.BackgroundSubtraction.GMG.nb_frame=120"<< "\n";
            f << "Detect.BackgroundSubtraction.KNN=0"<< "\n";
            f << "Detect.BackgroundSubtraction.KNN.nb_frame=500"<< "\n";
            f << "Detect.BackgroundSubtraction.KNN.thresholdSquare=400.0"<< "\n";
            f << "Detect.BackgroundSubtraction.KNN.detectShadows=1"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD=0" << "\n";
            f << "Detect.BackgroundSubtraction.FGD.alpha1=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.deltish=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.n1cc=10"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.n2c=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.n2cc=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.is_obj_without_holes=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.lc=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.n1c=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.lcc=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.perform_morphing=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.minArea=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.alpha2=1"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.t=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.alpha3=0"<< "\n";
            break;
        }
        case 2 : // use MOG2
        {
            int res_frame = (((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX)+ ((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX) ) * 125; // between 0 and 500 -> mean around 250
            double res_thresh = (((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX)+ ((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX) ) * 25; //between 0 and 100 -> mean around 50
            f << "Detect.BackgroundSubtraction.MOG=0"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG.nb_frame=200"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG.nb_mixture=5"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG.noiseRob=0.0"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG.decisionThreshold=0.7"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG2=1"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG2.detectShadows=1"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG2.nb_frame=" << res_frame << "\n";
            f << "Detect.BackgroundSubtraction.MOG2.thresholdSquare=" << res_thresh << "\n";
            f << "Detect.BackgroundSubtraction.GMG=0"<< "\n";
            f << "Detect.BackgroundSubtraction.GMG.decisionThreshold=0.8"<< "\n";
            f << "Detect.BackgroundSubtraction.GMG.nb_frame=120"<< "\n";
            f << "Detect.BackgroundSubtraction.KNN=0"<< "\n";
            f << "Detect.BackgroundSubtraction.KNN.nb_frame=500"<< "\n";
            f << "Detect.BackgroundSubtraction.KNN.thresholdSquare=400.0"<< "\n";
            f << "Detect.BackgroundSubtraction.KNN.detectShadows=1"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD=0" << "\n";
            f << "Detect.BackgroundSubtraction.FGD.alpha1=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.deltish=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.n1cc=10"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.n2c=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.n2cc=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.is_obj_without_holes=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.lc=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.n1c=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.lcc=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.perform_morphing=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.minArea=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.alpha2=1"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.t=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.alpha3=0"<< "\n";
            break;
        }
        case 3 : // use GMG
        {
            int res_frame = (((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX)+ ((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX) ) * 125; // between 0 and 500 -> mean around 250
            double res_thresh = (((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX)+ ((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX) ) /4; // between 0 and 1 -> mean around 0.5
            f << "Detect.BackgroundSubtraction.MOG=0"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG.nb_frame=200"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG.nb_mixture=5"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG.noiseRob=0.0"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG.decisionThreshold=0.7"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG2=0"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG2.detectShadows=1"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG2.nb_frame=500"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG2.thresholdSquare=16.0"<< "\n";
            f << "Detect.BackgroundSubtraction.GMG=1"<< "\n";
            f << "Detect.BackgroundSubtraction.GMG.decisionThreshold=" << res_thresh << "\n";
            f << "Detect.BackgroundSubtraction.GMG.nb_frame=" << res_frame << "\n";
            f << "Detect.BackgroundSubtraction.KNN=0"<< "\n";
            f << "Detect.BackgroundSubtraction.KNN.nb_frame=500"<< "\n";
            f << "Detect.BackgroundSubtraction.KNN.thresholdSquare=400.0"<< "\n";
            f << "Detect.BackgroundSubtraction.KNN.detectShadows=1"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD=0" << "\n";
            f << "Detect.BackgroundSubtraction.FGD.alpha1=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.deltish=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.n1cc=10"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.n2c=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.n2cc=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.is_obj_without_holes=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.lc=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.n1c=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.lcc=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.perform_morphing=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.minArea=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.alpha2=1"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.t=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.alpha3=0"<< "\n";
            break;
        }
        case 4 : // use KNN
        {
            int res_frame = (((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX)+ ((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX) ) * 125; // between 0 and 500 -> mean around 250
            double res_thresh = (((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX)+ ((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX) ) * 25; //between 0 and 100 and then squared -> mean around 50 and then 2500
            res_thresh *= res_thresh;
            f << "Detect.BackgroundSubtraction.MOG=0"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG.nb_frame=200"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG.nb_mixture=5"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG.noiseRob=0.0"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG.decisionThreshold=0.7"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG2=0"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG2.detectShadows=1"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG2.nb_frame=500"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG2.thresholdSquare=16.0"<< "\n";
            f << "Detect.BackgroundSubtraction.GMG=0"<< "\n";
            f << "Detect.BackgroundSubtraction.GMG.decisionThreshold=0.8"<< "\n";
            f << "Detect.BackgroundSubtraction.GMG.nb_frame=120"<< "\n";
            f << "Detect.BackgroundSubtraction.KNN=1"<< "\n";
            f << "Detect.BackgroundSubtraction.KNN.nb_frame=" << res_frame << "\n";
            f << "Detect.BackgroundSubtraction.KNN.thresholdSquare=" << "res_thresh"<< "\n";
            f << "Detect.BackgroundSubtraction.KNN.detectShadows=1"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD=0" << "\n";
            f << "Detect.BackgroundSubtraction.FGD.alpha1=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.deltish=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.n1cc=10"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.n2c=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.n2cc=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.is_obj_without_holes=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.lc=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.n1c=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.lcc=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.perform_morphing=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.minArea=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.alpha2=1"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.t=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.alpha3=0"<< "\n";
            break;
        }
        default : cout << "Not implemented yet" << endl;
    }
    f << "Detect.OpticalFlow=0"<< "\n";
    f << "Detect.OpticalFlow.Dense=0"<< "\n";
    f << "Detect.OpticalFlow.Sparse=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.Farneback=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.SimpleFlow=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.DualTVL=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.Farneback.pyr_scale=0.5"<< "\n";
    f << "Detect.OpticalFlow.Dense.Farneback.levels=3"<< "\n";
    f << "Detect.OpticalFlow.Dense.Farneback.winSize=15"<< "\n";
    f << "Detect.OpticalFlow.Dense.Farneback.iterations=3"<< "\n";
    f << "Detect.OpticalFlow.Dense.Farneback.poly_n=5"<< "\n";
    f << "Detect.OpticalFlow.Dense.Farneback.poly_sigma=1.2"<< "\n";
    f << "Detect.OpticalFlow.Dense.Farneback.use_init_flow=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.Farneback.use_gaussian=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.Farneback.threshold=0.0001"<< "\n";
    f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK=0"<< "\n";
    f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.winSize=0"<< "\n";
    f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.maxLevel=0"<< "\n";
    f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.count=0"<< "\n";
    f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.epsilon=0"<< "\n";
    f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.use_initial_flow=0"<< "\n";
    f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.use_eigen_val=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.SimpleFlow.nb_layer=3"<< "\n";
    f << "Detect.OpticalFlow.Dense.SimpleFlow.averaging_block_size=2"<< "\n";
    f << "Detect.OpticalFlow.Dense.SimpleFlow.max_flow=4"<< "\n";
    f << "Detect.OpticalFlow.Dense.DualTVL.tau=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.DualTVL.lambda=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.DualTVL.theta=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.DualTVL.nscales=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.DualTVL.warps=1"<< "\n";
    f << "Detect.OpticalFlow.Dense.DualTVL.epsilon=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.DualTVL.iterations=0"<< "\n";
    f << "Detect.BlockMatching=0" << "\n";
    f << "Detect.BlockMatching.min_disparity=0"<< "\n";
    f << "Detect.BlockMatching.num_disparities=16"<< "\n";
    f << "Detect.BlockMatching.block_size=3"<< "\n";
    f << "Detect.BlockMatching.p1=0"<< "\n";
    f << "Detect.BlockMatching.p2=0"<< "\n";
    f << "Detect.BlockMatching.disp12_max_diff=0"<< "\n";
    f << "Detect.BlockMatching.pre_filter_cap=0"<< "\n";
    f << "Detect.BlockMatching.uniqueness_ratio=0"<< "\n";
    f << "Detect.BlockMatching.speckle_window_size=0"<< "\n";
    f << "Detect.BlockMatching.speckle_range=0"<< "\n";
    f << "Detect.MotionHistory=0"<< "\n";
    f << "Detect.MotionHistory.mhi_duration=5"<< "\n";
    f << "Detect.MotionHistory.min_time_delta=0.05"<< "\n";
    f << "Detect.MotionHistory.max_time_delta=10"<<"\n";
    f << "Detect.MotionHistory.threshold=22"<<"\n";
}

/**
* a function called to write the background subtraction module
* users have decided to use background subtraction as a detection module they also decided to give random values for each parameters
* parameters will be wrote for all the detection module (except for the common parts) : one activated, the others will not be
* random values are an approximation of a Gaussian distribution based on the use of uniformly distributed values
*
* input :
*   - fstream& f : a file stream representing the output file
*   - char** argv : the list of arguments given when the program was called
*   - int idx : current index of the argument to use
* output :
*   - detect module should be written in the output file (except for the common part and assuming that a close operator has been performed to flush the buffer)
*   - int : the new current index of the argument to use
*/
int write_use_bgSub_rand(fstream& f, char** argv, int idx)
{
    f << "Detect.BackgroundSubtraction=1"<< "\n";

    ///which method to use ?
    cout << "Which method do you want to use ? (1 : MOG; 2 : MOG2; 3 : GMG; 4 : KNN; 5 : FGD (not implemented yet)" << endl;
    string choice(argv[idx]);
    cout << choice << endl;
    //cin >> choice;
    idx++;

    while (choice != "1" && choice != "2" && choice != "3" && choice != "4")
    {
        cout << "Which method do you want to use ? (1 : MOG; 2 : MOG2; 3 : GMG; 4 : KNN; 5 : FGD (not implemented yet)" << endl;
        cin >> choice;
    }

    ///write corresponding choices
    switch(atoi(choice.c_str()))
    {
        case 1 : // use MOG
        {
            int res_frame = (((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX)+ ((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX) ) * 125; // between 0 and 500 -> mean around 250
            int res_mixt = (((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX)+ ((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX) ) * 2.5 + 2; // between 2 and 12 -> mean around 7
            double res_robust = (((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX)+ ((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX) ) /4; // between 0 and 1 -> mean around 0.5
            double res_thresh = (((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX)+ ((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX) ) /4; // between 0 and 1 -> mean around 0.5
            f << "Detect.BackgroundSubtraction.MOG=1"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG.nb_frame=" << res_frame << "\n";
            f << "Detect.BackgroundSubtraction.MOG.nb_mixture=" << res_mixt << "\n";
            f << "Detect.BackgroundSubtraction.MOG.noiseRob=" << res_robust << "\n";
            f << "Detect.BackgroundSubtraction.MOG.decisionThreshold=" << res_thresh << "\n";
            f << "Detect.BackgroundSubtraction.MOG2=0"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG2.detectShadows=1"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG2.nb_frame=500"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG2.thresholdSquare=16.0"<< "\n";
            f << "Detect.BackgroundSubtraction.GMG=0"<< "\n";
            f << "Detect.BackgroundSubtraction.GMG.decisionThreshold=0.8"<< "\n";
            f << "Detect.BackgroundSubtraction.GMG.nb_frame=120"<< "\n";
            f << "Detect.BackgroundSubtraction.KNN=0"<< "\n";
            f << "Detect.BackgroundSubtraction.KNN.nb_frame=500"<< "\n";
            f << "Detect.BackgroundSubtraction.KNN.thresholdSquare=400.0"<< "\n";
            f << "Detect.BackgroundSubtraction.KNN.detectShadows=1"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD=0" << "\n";
            f << "Detect.BackgroundSubtraction.FGD.alpha1=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.deltish=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.n1cc=10"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.n2c=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.n2cc=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.is_obj_without_holes=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.lc=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.n1c=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.lcc=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.perform_morphing=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.minArea=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.alpha2=1"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.t=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.alpha3=0"<< "\n";
            break;
        }
        case 2 : // use MOG2
        {
            int res_frame = (((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX)+ ((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX) ) * 125; // between 0 and 500 -> mean around 250
            double res_thresh = (((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX)+ ((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX) ) * 25; // between 0 and 100 -> mean around 50
            f << "Detect.BackgroundSubtraction.MOG=0"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG.nb_frame=200"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG.nb_mixture=5"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG.noiseRob=0.0"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG.decisionThreshold=0.7"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG2=1"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG2.detectShadows=1"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG2.nb_frame=" << res_frame << "\n";
            f << "Detect.BackgroundSubtraction.MOG2.thresholdSquare=" << res_thresh << "\n";
            f << "Detect.BackgroundSubtraction.GMG=0"<< "\n";
            f << "Detect.BackgroundSubtraction.GMG.decisionThreshold=0.8"<< "\n";
            f << "Detect.BackgroundSubtraction.GMG.nb_frame=120"<< "\n";
            f << "Detect.BackgroundSubtraction.KNN=0"<< "\n";
            f << "Detect.BackgroundSubtraction.KNN.nb_frame=500"<< "\n";
            f << "Detect.BackgroundSubtraction.KNN.thresholdSquare=400.0"<< "\n";
            f << "Detect.BackgroundSubtraction.KNN.detectShadows=1"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD=0" << "\n";
            f << "Detect.BackgroundSubtraction.FGD.alpha1=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.deltish=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.n1cc=10"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.n2c=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.n2cc=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.is_obj_without_holes=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.lc=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.n1c=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.lcc=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.perform_morphing=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.minArea=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.alpha2=1"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.t=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.alpha3=0"<< "\n";
            break;
        }
        case 3 : // use GMG
        {
            int res_frame = (((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX)+ ((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX) ) * 125; // between 0 and 500 -> mean around 250
            double res_thresh = (((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX)+ ((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX) ) /4; // between 0 and 1 -> mean around 0.5
            f << "Detect.BackgroundSubtraction.MOG=0"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG.nb_frame=200"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG.nb_mixture=5"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG.noiseRob=0.0"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG.decisionThreshold=0.7"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG2=0"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG2.detectShadows=1"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG2.nb_frame=500"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG2.thresholdSquare=16.0"<< "\n";
            f << "Detect.BackgroundSubtraction.GMG=1"<< "\n";
            f << "Detect.BackgroundSubtraction.GMG.decisionThreshold=" << res_thresh << "\n";
            f << "Detect.BackgroundSubtraction.GMG.nb_frame=" << res_frame << "\n";
            f << "Detect.BackgroundSubtraction.KNN=0"<< "\n";
            f << "Detect.BackgroundSubtraction.KNN.nb_frame=500"<< "\n";
            f << "Detect.BackgroundSubtraction.KNN.thresholdSquare=400.0"<< "\n";
            f << "Detect.BackgroundSubtraction.KNN.detectShadows=1"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD=0" << "\n";
            f << "Detect.BackgroundSubtraction.FGD.alpha1=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.deltish=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.n1cc=10"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.n2c=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.n2cc=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.is_obj_without_holes=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.lc=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.n1c=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.lcc=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.perform_morphing=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.minArea=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.alpha2=1"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.t=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.alpha3=0"<< "\n";
            break;
        }
        case 4 : // use KNN
        {
            int res_frame = (((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX)+ ((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX) ) * 125; // between 0 and 500 -> mean around 250
            double res_thresh = (((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX)+ ((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX) ) * 25; // between 0 and 100 and then squared -> mean around 50 and then 2500
            res_thresh *= res_thresh;
            f << "Detect.BackgroundSubtraction.MOG=0"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG.nb_frame=200"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG.nb_mixture=5"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG.noiseRob=0.0"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG.decisionThreshold=0.7"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG2=0"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG2.detectShadows=1"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG2.nb_frame=500"<< "\n";
            f << "Detect.BackgroundSubtraction.MOG2.thresholdSquare=16.0"<< "\n";
            f << "Detect.BackgroundSubtraction.GMG=0"<< "\n";
            f << "Detect.BackgroundSubtraction.GMG.decisionThreshold=0.8"<< "\n";
            f << "Detect.BackgroundSubtraction.GMG.nb_frame=120"<< "\n";
            f << "Detect.BackgroundSubtraction.KNN=1"<< "\n";
            f << "Detect.BackgroundSubtraction.KNN.nb_frame=" << res_frame << "\n";
            f << "Detect.BackgroundSubtraction.KNN.thresholdSquare=" << "res_thresh"<< "\n";
            f << "Detect.BackgroundSubtraction.KNN.detectShadows=1"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD=0" << "\n";
            f << "Detect.BackgroundSubtraction.FGD.alpha1=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.deltish=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.n1cc=10"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.n2c=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.n2cc=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.is_obj_without_holes=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.lc=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.n1c=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.lcc=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.perform_morphing=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.minArea=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.alpha2=1"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.t=0"<< "\n";
            f << "Detect.BackgroundSubtraction.FGD.alpha3=0"<< "\n";
            break;
        }
        default : cout << "Not implemented yet" << endl;
    }
    f << "Detect.OpticalFlow=0"<< "\n";
    f << "Detect.OpticalFlow.Dense=0"<< "\n";
    f << "Detect.OpticalFlow.Sparse=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.Farneback=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.SimpleFlow=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.DualTVL=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.Farneback.pyr_scale=0.5"<< "\n";
    f << "Detect.OpticalFlow.Dense.Farneback.levels=3"<< "\n";
    f << "Detect.OpticalFlow.Dense.Farneback.winSize=15"<< "\n";
    f << "Detect.OpticalFlow.Dense.Farneback.iterations=3"<< "\n";
    f << "Detect.OpticalFlow.Dense.Farneback.poly_n=5"<< "\n";
    f << "Detect.OpticalFlow.Dense.Farneback.poly_sigma=1.2"<< "\n";
    f << "Detect.OpticalFlow.Dense.Farneback.use_init_flow=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.Farneback.use_gaussian=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.Farneback.threshold=0.0001"<< "\n";
    f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK=0"<< "\n";
    f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.winSize=0"<< "\n";
    f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.maxLevel=0"<< "\n";
    f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.count=0"<< "\n";
    f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.epsilon=0"<< "\n";
    f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.use_initial_flow=0"<< "\n";
    f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.use_eigen_val=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.SimpleFlow.nb_layer=3"<< "\n";
    f << "Detect.OpticalFlow.Dense.SimpleFlow.averaging_block_size=2"<< "\n";
    f << "Detect.OpticalFlow.Dense.SimpleFlow.max_flow=4"<< "\n";
    f << "Detect.OpticalFlow.Dense.DualTVL.tau=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.DualTVL.lambda=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.DualTVL.theta=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.DualTVL.nscales=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.DualTVL.warps=1"<< "\n";
    f << "Detect.OpticalFlow.Dense.DualTVL.epsilon=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.DualTVL.iterations=0"<< "\n";
    f << "Detect.BlockMatching=0" << "\n";
    f << "Detect.BlockMatching.min_disparity=0"<< "\n";
    f << "Detect.BlockMatching.num_disparities=16"<< "\n";
    f << "Detect.BlockMatching.block_size=3"<< "\n";
    f << "Detect.BlockMatching.p1=0"<< "\n";
    f << "Detect.BlockMatching.p2=0"<< "\n";
    f << "Detect.BlockMatching.disp12_max_diff=0"<< "\n";
    f << "Detect.BlockMatching.pre_filter_cap=0"<< "\n";
    f << "Detect.BlockMatching.uniqueness_ratio=0"<< "\n";
    f << "Detect.BlockMatching.speckle_window_size=0"<< "\n";
    f << "Detect.BlockMatching.speckle_range=0"<< "\n";
    f << "Detect.MotionHistory=0"<< "\n";
    f << "Detect.MotionHistory.mhi_duration=5"<< "\n";
    f << "Detect.MotionHistory.min_time_delta=0.05"<< "\n";
    f << "Detect.MotionHistory.max_time_delta=10"<<"\n";
    f << "Detect.MotionHistory.threshold=22"<<"\n";

    return idx;
}

/**
* a function called in interactive mode to write the optical flow module
* users have decided to use optical flow as a detection module they also decided to give random values for each parameters
* parameters will be wrote for all the detection module (except for the common parts) : one activated, the others will not be
* random values are an approximation of a Gaussian distribution based on the use of uniformly distributed values
*
* input :
*   - fstream& f : a file stream representing the output file
*/
void write_use_optFlow_rand(fstream& f)
{
    f << "Detect.BackgroundSubtraction=0"<< "\n";
    f << "Detect.BackgroundSubtraction.MOG=0"<< "\n";
    f << "Detect.BackgroundSubtraction.MOG.nb_frame=200"<< "\n";
    f << "Detect.BackgroundSubtraction.MOG.nb_mixture=5"<< "\n";
    f << "Detect.BackgroundSubtraction.MOG.noiseRob=0.0"<< "\n";
    f << "Detect.BackgroundSubtraction.MOG.decisionThreshold=0.7"<< "\n";
    f << "Detect.BackgroundSubtraction.MOG2=0"<< "\n";
    f << "Detect.BackgroundSubtraction.MOG2.detectShadows=1"<< "\n";
    f << "Detect.BackgroundSubtraction.MOG2.nb_frame=500"<< "\n";
    f << "Detect.BackgroundSubtraction.MOG2.thresholdSquare=16.0"<< "\n";
    f << "Detect.BackgroundSubtraction.GMG=0"<< "\n";
    f << "Detect.BackgroundSubtraction.GMG.decisionThreshold=0.8"<< "\n";
    f << "Detect.BackgroundSubtraction.GMG.nb_frame=120"<< "\n";
    f << "Detect.BackgroundSubtraction.KNN=0"<< "\n";
    f << "Detect.BackgroundSubtraction.KNN.nb_frame=500"<< "\n";
    f << "Detect.BackgroundSubtraction.KNN.thresholdSquare=400.0"<< "\n";
    f << "Detect.BackgroundSubtraction.KNN.detectShadows=1"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD=0" << "\n";
    f << "Detect.BackgroundSubtraction.FGD.alpha1=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.deltish=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.n1cc=10"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.n2c=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.n2cc=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.is_obj_without_holes=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.lc=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.n1c=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.lcc=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.perform_morphing=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.minArea=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.alpha2=1"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.t=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.alpha3=0"<< "\n";

    ///which method to use ?
    cout << "Which method do you want to use ? (1 : Farneback; 2 : Simple Flow; 3 : DuaTVL1" << endl;
    string choice;
    cin >> choice;
    while (choice != "1" && choice != "2" && choice != "3" && choice != "4")
    {
        cout << "Which method do you want to use ? (1 : Farneback; 2 : Simple Flow; 3 : DuaTVL1" << endl;
        cin >> choice;
    }

    ///write parameters according to choices
    switch(atoi(choice.c_str()))
    {
        case 1 : //use Farneback
        {
            double res_pyr_scale = (((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX)+ ((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX) ) /4; // between 0 and 1 -> mean around 0.5
            int res_lvl = (((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX)+ ((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX) ) * 2.5 + 1; // between 1 and 11 -> mean around 6
            int res_size = (((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX)+ ((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX) ) * 7.5; // between 0 and 30 -> mean around 15
            if(res_size %2 == 0) {res_size += 1;} // res_size has to be odd
            int res_iter = (((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX)+ ((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX) ) * 2.5; // between 0 and 10 -> mean around 5
            int res_n = (((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX)+ ((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX) ) * 3.75 + 3; // between 3 and 18 -> mean around 10.5
            if(res_n %2 == 0) {res_n += 1;} // res_n has to be odd
            double res_sigma = (((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX)+ ((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX) ) /4 + 1; // between 1 and 2 -> mean around 1.5
            f << "Detect.OpticalFlow=1"<< "\n";
            f << "Detect.OpticalFlow.Dense=1"<< "\n";
            f << "Detect.OpticalFlow.Sparse=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback=1"<< "\n";
            f << "Detect.OpticalFlow.Dense.SimpleFlow=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.pyr_scale=" << res_pyr_scale << "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.levels=" << res_lvl << "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.winSize=" << res_size << "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.iterations=" << res_iter << "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.poly_n=" << res_n << "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.poly_sigma=" << res_sigma << "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.use_init_flow=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.use_gaussian=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.threshold=0.0001"<< "\n";
            f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK=0"<< "\n";
            f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.winSize=0"<< "\n";
            f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.maxLevel=0"<< "\n";
            f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.count=0"<< "\n";
            f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.epsilon=0"<< "\n";
            f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.use_initial_flow=0"<< "\n";
            f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.use_eigen_val=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.SimpleFlow.nb_layer=3"<< "\n";
            f << "Detect.OpticalFlow.Dense.SimpleFlow.averaging_block_size=2"<< "\n";
            f << "Detect.OpticalFlow.Dense.SimpleFlow.max_flow=4"<< "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL.tau=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL.lambda=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL.theta=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL.nscales=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL.warps=1"<< "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL.epsilon=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL.iterations=0"<< "\n";
            break;
        }

        case 2 : // use Simple Flow
        {
            int res_layer = (((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX)+ ((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX) ) * 1.75 + 1; // between 1 and 8 -> mean around 4.5
            int res_block_size = (((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX)+ ((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX) ) * 2.5 + 1; // between 1 and 11 -> mean around 6
            int res_flow = (((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX)+ ((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX) ) * 2.5 + 1; // between 1 and 11 -> mean around 6
            f << "Detect.OpticalFlow=1"<< "\n";
            f << "Detect.OpticalFlow.Dense=1"<< "\n";
            f << "Detect.OpticalFlow.Sparse=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.SimpleFlow=1"<< "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.pyr_scale=0.5"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.levels=3"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.winSize=15"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.iterations=3"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.poly_n=5"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.poly_sigma=1.2"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.use_init_flow=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.use_gaussian=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.threshold=0.0001"<< "\n";
            f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK=0"<< "\n";
            f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.winSize=0"<< "\n";
            f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.maxLevel=0"<< "\n";
            f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.count=0"<< "\n";
            f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.epsilon=0"<< "\n";
            f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.use_initial_flow=0"<< "\n";
            f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.use_eigen_val=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.SimpleFlow.nb_layer=" << res_layer << "\n";
            f << "Detect.OpticalFlow.Dense.SimpleFlow.averaging_block_size=" << res_block_size << "\n";
            f << "Detect.OpticalFlow.Dense.SimpleFlow.max_flow=" << res_flow << "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL.tau=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL.lambda=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL.theta=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL.nscales=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL.warps=1"<< "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL.epsilon=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL.iterations=0"<< "\n";
            break;
        }
        case 3 : // use Dual TVL 1
        {
            double res_lambda = (((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX)+ ((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX) ) /4; // between 0 and 1 -> mean around 0.5
            int res_n = (((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX)+ ((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX) ) * 2.5 + 1; // between 1 and 11 -> mean around 6
            f << "Detect.OpticalFlow=1"<< "\n";
            f << "Detect.OpticalFlow.Dense=1"<< "\n";
            f << "Detect.OpticalFlow.Sparse=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.SimpleFlow=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL=1"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.pyr_scale=0.5"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.levels=3"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.winSize=15"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.iterations=3"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.poly_n=5"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.poly_sigma=1.2"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.use_init_flow=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.use_gaussian=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.threshold=0.0001"<< "\n";
            f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK=0"<< "\n";
            f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.winSize=0"<< "\n";
            f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.maxLevel=0"<< "\n";
            f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.count=0"<< "\n";
            f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.epsilon=0"<< "\n";
            f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.use_initial_flow=0"<< "\n";
            f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.use_eigen_val=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.SimpleFlow.nb_layer=3"<< "\n";
            f << "Detect.OpticalFlow.Dense.SimpleFlow.averaging_block_size=2"<< "\n";
            f << "Detect.OpticalFlow.Dense.SimpleFlow.max_flow=4"<< "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL.tau=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL.lambda=" << res_lambda << "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL.theta=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL.nscales=" << res_n<< "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL.warps=1"<< "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL.epsilon=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL.iterations=0"<< "\n";
            break;
        }
    }
    f << "Detect.BlockMatching=0" << "\n";
    f << "Detect.BlockMatching.min_disparity=0"<< "\n";
    f << "Detect.BlockMatching.num_disparities=16"<< "\n";
    f << "Detect.BlockMatching.block_size=3"<< "\n";
    f << "Detect.BlockMatching.p1=0"<< "\n";
    f << "Detect.BlockMatching.p2=0"<< "\n";
    f << "Detect.BlockMatching.disp12_max_diff=0"<< "\n";
    f << "Detect.BlockMatching.pre_filter_cap=0"<< "\n";
    f << "Detect.BlockMatching.uniqueness_ratio=0"<< "\n";
    f << "Detect.BlockMatching.speckle_window_size=0"<< "\n";
    f << "Detect.BlockMatching.speckle_range=0"<< "\n";
    f << "Detect.MotionHistory=0"<< "\n";
    f << "Detect.MotionHistory.mhi_duration=5"<< "\n";
    f << "Detect.MotionHistory.min_time_delta=0.05"<< "\n";
    f << "Detect.MotionHistory.max_time_delta=10"<<"\n";
    f << "Detect.MotionHistory.threshold=22"<<"\n";
}

/**
* a function called to write the optical flow module
* users have decided to use optical flow as a detection module they also decided to give random values for each parameters
* parameters will be wrote for all the detection module (except for the common parts) : one activated, the others will not be
* random values are an approximation of a Gaussian distribution based on the use of uniformly distributed values
*
* input :
*   - fstream& f : a file stream representing the output file
*   - char** argv : the list of arguments given when the program was called
*   - int idx: the current index to retrieve argument value
* output :
*   - modules written in output file
*   - int : the new value of the index to retrieve argument values
*/

int write_use_optFlow_rand(fstream& f, char** argv, int idx)
{
    f << "Detect.BackgroundSubtraction=0"<< "\n";
    f << "Detect.BackgroundSubtraction.MOG=0"<< "\n";
    f << "Detect.BackgroundSubtraction.MOG.nb_frame=200"<< "\n";
    f << "Detect.BackgroundSubtraction.MOG.nb_mixture=5"<< "\n";
    f << "Detect.BackgroundSubtraction.MOG.noiseRob=0.0"<< "\n";
    f << "Detect.BackgroundSubtraction.MOG.decisionThreshold=0.7"<< "\n";
    f << "Detect.BackgroundSubtraction.MOG2=0"<< "\n";
    f << "Detect.BackgroundSubtraction.MOG2.detectShadows=1"<< "\n";
    f << "Detect.BackgroundSubtraction.MOG2.nb_frame=500"<< "\n";
    f << "Detect.BackgroundSubtraction.MOG2.thresholdSquare=16.0"<< "\n";
    f << "Detect.BackgroundSubtraction.GMG=0"<< "\n";
    f << "Detect.BackgroundSubtraction.GMG.decisionThreshold=0.8"<< "\n";
    f << "Detect.BackgroundSubtraction.GMG.nb_frame=120"<< "\n";
    f << "Detect.BackgroundSubtraction.KNN=0"<< "\n";
    f << "Detect.BackgroundSubtraction.KNN.nb_frame=500"<< "\n";
    f << "Detect.BackgroundSubtraction.KNN.thresholdSquare=400.0"<< "\n";
    f << "Detect.BackgroundSubtraction.KNN.detectShadows=1"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD=0" << "\n";
    f << "Detect.BackgroundSubtraction.FGD.alpha1=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.deltish=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.n1cc=10"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.n2c=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.n2cc=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.is_obj_without_holes=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.lc=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.n1c=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.lcc=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.perform_morphing=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.minArea=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.alpha2=1"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.t=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.alpha3=0"<< "\n";

    /// which method to use ?
    cout << "Which method do you want to use ? (1 : Farneback; 2 : Simple Flow; 3 : DuaTVL1" << endl;
    string choice(argv[idx]);
    //cin >> choice;
    cout << choice << endl;
    idx++;

    while (choice != "1" && choice != "2" && choice != "3" && choice != "4")
    {
        cout << "Which method do you want to use ? (1 : Farneback; 2 : Simple Flow; 3 : DuaTVL1" << endl;
        cin >> choice;
    }

    ///write module according to choices
    switch(atoi(choice.c_str()))
    {
        case 1 : //use Farneback
        {
            double res_pyr_scale = (((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX)+ ((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX) ) /4; // between 0 and 1 -> mean around 0.5
            int res_lvl = (((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX)+ ((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX) ) * 2.5 + 1; // between 1 and 11 -> mean around 6
            int res_size = (((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX)+ ((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX) ) * 7.5; // between 0 and 30 -> mean around 15
            if(res_size %2 == 0) {res_size += 1;} // res_size has to be odd
            int res_iter = (((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX)+ ((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX) ) * 2.5; // between 0 and 10 -> mean around 5
            int res_n = (((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX)+ ((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX) ) * 3.75 + 3; // between 3 and 18 -> mean around 10.5
            if(res_n %2 == 0) {res_n += 1;} // res_n hasz to be odd
            double res_sigma = (((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX)+ ((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX) ) /4 + 1; // between 1 and 2 -> mean around 1.5
            f << "Detect.OpticalFlow=1"<< "\n";
            f << "Detect.OpticalFlow.Dense=1"<< "\n";
            f << "Detect.OpticalFlow.Sparse=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback=1"<< "\n";
            f << "Detect.OpticalFlow.Dense.SimpleFlow=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.pyr_scale=" << res_pyr_scale << "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.levels=" << res_lvl << "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.winSize=" << res_size << "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.iterations=" << res_iter << "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.poly_n=" << res_n << "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.poly_sigma=" << res_sigma << "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.use_init_flow=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.use_gaussian=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.threshold=0.0001"<< "\n";
            f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK=0"<< "\n";
            f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.winSize=0"<< "\n";
            f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.maxLevel=0"<< "\n";
            f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.count=0"<< "\n";
            f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.epsilon=0"<< "\n";
            f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.use_initial_flow=0"<< "\n";
            f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.use_eigen_val=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.SimpleFlow.nb_layer=3"<< "\n";
            f << "Detect.OpticalFlow.Dense.SimpleFlow.averaging_block_size=2"<< "\n";
            f << "Detect.OpticalFlow.Dense.SimpleFlow.max_flow=4"<< "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL.tau=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL.lambda=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL.theta=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL.nscales=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL.warps=1"<< "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL.epsilon=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL.iterations=0"<< "\n";
            break;
        }

        case 2 : // use Simple Flow
        {
            int res_layer = (((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX)+ ((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX) ) * 1.75 + 1; // between 1 and 8 -> mean around 4.5
            int res_block_size = (((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX)+ ((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX) ) * 2.5 + 1; // between 1 and 11 -> mean around 6
            int res_flow = (((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX)+ ((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX) ) * 2.5 + 1; // between 1 and 11 -> mean around 6
            f << "Detect.OpticalFlow=1"<< "\n";
            f << "Detect.OpticalFlow.Dense=1"<< "\n";
            f << "Detect.OpticalFlow.Sparse=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.SimpleFlow=1"<< "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.pyr_scale=0.5"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.levels=3"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.winSize=15"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.iterations=3"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.poly_n=5"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.poly_sigma=1.2"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.use_init_flow=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.use_gaussian=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.threshold=0.0001"<< "\n";
            f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK=0"<< "\n";
            f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.winSize=0"<< "\n";
            f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.maxLevel=0"<< "\n";
            f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.count=0"<< "\n";
            f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.epsilon=0"<< "\n";
            f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.use_initial_flow=0"<< "\n";
            f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.use_eigen_val=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.SimpleFlow.nb_layer=" << res_layer << "\n";
            f << "Detect.OpticalFlow.Dense.SimpleFlow.averaging_block_size=" << res_block_size << "\n";
            f << "Detect.OpticalFlow.Dense.SimpleFlow.max_flow=" << res_flow << "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL.tau=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL.lambda=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL.theta=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL.nscales=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL.warps=1"<< "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL.epsilon=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL.iterations=0"<< "\n";
            break;
        }
        case 3 : // use Dual TVL 1
        {
            double res_lambda = (((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX)+ ((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX) ) /4; // between 0 and 1 -> mean around 0.5
            int res_n = (((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX)+ ((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX) ) * 2.5 + 1; // between 1 and 11 -> mean around 6
            f << "Detect.OpticalFlow=1"<< "\n";
            f << "Detect.OpticalFlow.Dense=1"<< "\n";
            f << "Detect.OpticalFlow.Sparse=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.SimpleFlow=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL=1"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.pyr_scale=0.5"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.levels=3"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.winSize=15"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.iterations=3"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.poly_n=5"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.poly_sigma=1.2"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.use_init_flow=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.use_gaussian=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.Farneback.threshold=0.0001"<< "\n";
            f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK=0"<< "\n";
            f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.winSize=0"<< "\n";
            f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.maxLevel=0"<< "\n";
            f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.count=0"<< "\n";
            f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.epsilon=0"<< "\n";
            f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.use_initial_flow=0"<< "\n";
            f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.use_eigen_val=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.SimpleFlow.nb_layer=3"<< "\n";
            f << "Detect.OpticalFlow.Dense.SimpleFlow.averaging_block_size=2"<< "\n";
            f << "Detect.OpticalFlow.Dense.SimpleFlow.max_flow=4"<< "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL.tau=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL.lambda=" << res_lambda << "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL.theta=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL.nscales=" << res_n<< "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL.warps=1"<< "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL.epsilon=0"<< "\n";
            f << "Detect.OpticalFlow.Dense.DualTVL.iterations=0"<< "\n";
            break;
        }
    }
    f << "Detect.BlockMatching=0" << "\n";
    f << "Detect.BlockMatching.min_disparity=0"<< "\n";
    f << "Detect.BlockMatching.num_disparities=16"<< "\n";
    f << "Detect.BlockMatching.block_size=3"<< "\n";
    f << "Detect.BlockMatching.p1=0"<< "\n";
    f << "Detect.BlockMatching.p2=0"<< "\n";
    f << "Detect.BlockMatching.disp12_max_diff=0"<< "\n";
    f << "Detect.BlockMatching.pre_filter_cap=0"<< "\n";
    f << "Detect.BlockMatching.uniqueness_ratio=0"<< "\n";
    f << "Detect.BlockMatching.speckle_window_size=0"<< "\n";
    f << "Detect.BlockMatching.speckle_range=0"<< "\n";
    f << "Detect.MotionHistory=0"<< "\n";
    f << "Detect.MotionHistory.mhi_duration=5"<< "\n";
    f << "Detect.MotionHistory.min_time_delta=0.05"<< "\n";
    f << "Detect.MotionHistory.max_time_delta=10"<<"\n";
    f << "Detect.MotionHistory.threshold=22"<<"\n";

    return idx;
}

/**
* a function called to write the Block Matching module
* this function is used in both modes
* users have decided to use block matching as a detection module they also decided to give random values for each parameters
* parameters will be wrote for all the detection module (except for the common parts) : one activated, the others will not be
* random values are an approximation of a Gaussian distribution based on the use of uniformly distributed values
*
* input :
*   - fstream& f : a file stream representing the output file
*/
void write_use_BM_rand(fstream& f)
{
    f << "Detect.BackgroundSubtraction=0"<< "\n";
    f << "Detect.BackgroundSubtraction.MOG=0"<< "\n";
    f << "Detect.BackgroundSubtraction.MOG.nb_frame=200"<< "\n";
    f << "Detect.BackgroundSubtraction.MOG.nb_mixture=5"<< "\n";
    f << "Detect.BackgroundSubtraction.MOG.noiseRob=0.0"<< "\n";
    f << "Detect.BackgroundSubtraction.MOG.decisionThreshold=0.7"<< "\n";
    f << "Detect.BackgroundSubtraction.MOG2=0"<< "\n";
    f << "Detect.BackgroundSubtraction.MOG2.detectShadows=1"<< "\n";
    f << "Detect.BackgroundSubtraction.MOG2.nb_frame=500"<< "\n";
    f << "Detect.BackgroundSubtraction.MOG2.thresholdSquare=16.0"<< "\n";
    f << "Detect.BackgroundSubtraction.GMG=0"<< "\n";
    f << "Detect.BackgroundSubtraction.GMG.decisionThreshold=0.8"<< "\n";
    f << "Detect.BackgroundSubtraction.GMG.nb_frame=120"<< "\n";
    f << "Detect.BackgroundSubtraction.KNN=0"<< "\n";
    f << "Detect.BackgroundSubtraction.KNN.nb_frame=500"<< "\n";
    f << "Detect.BackgroundSubtraction.KNN.thresholdSquare=400.0"<< "\n";
    f << "Detect.BackgroundSubtraction.KNN.detectShadows=1"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD=0" << "\n";
    f << "Detect.BackgroundSubtraction.FGD.alpha1=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.deltish=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.n1cc=10"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.n2c=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.n2cc=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.is_obj_without_holes=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.lc=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.n1c=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.lcc=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.perform_morphing=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.minArea=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.alpha2=1"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.t=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.alpha3=0"<< "\n";
    f << "Detect.OpticalFlow=0"<< "\n";
    f << "Detect.OpticalFlow.Dense=0"<< "\n";
    f << "Detect.OpticalFlow.Sparse=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.Farneback=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.SimpleFlow=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.DualTVL=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.Farneback.pyr_scale=0.5"<< "\n";
    f << "Detect.OpticalFlow.Dense.Farneback.levels=3"<< "\n";
    f << "Detect.OpticalFlow.Dense.Farneback.winSize=15"<< "\n";
    f << "Detect.OpticalFlow.Dense.Farneback.iterations=3"<< "\n";
    f << "Detect.OpticalFlow.Dense.Farneback.poly_n=5"<< "\n";
    f << "Detect.OpticalFlow.Dense.Farneback.poly_sigma=1.2"<< "\n";
    f << "Detect.OpticalFlow.Dense.Farneback.use_init_flow=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.Farneback.use_gaussian=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.Farneback.threshold=0.0001"<< "\n";
    f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK=0"<< "\n";
    f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.winSize=0"<< "\n";
    f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.maxLevel=0"<< "\n";
    f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.count=0"<< "\n";
    f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.epsilon=0"<< "\n";
    f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.use_initial_flow=0"<< "\n";
    f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.use_eigen_val=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.SimpleFlow.nb_layer=3"<< "\n";
    f << "Detect.OpticalFlow.Dense.SimpleFlow.averaging_block_size=2"<< "\n";
    f << "Detect.OpticalFlow.Dense.SimpleFlow.max_flow=4"<< "\n";
    f << "Detect.OpticalFlow.Dense.DualTVL.tau=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.DualTVL.lambda=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.DualTVL.theta=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.DualTVL.nscales=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.DualTVL.warps=1"<< "\n";
    f << "Detect.OpticalFlow.Dense.DualTVL.epsilon=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.DualTVL.iterations=0"<< "\n";

    int res_block = (((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX)+ ((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX) ) /4 * 11 + 3; // between 3 and 14 -> mean around 8.5
    if(res_block % 2 == 0) {res_block += 1;} // res_block has to be odd
    f << "Detect.BlockMatching=1" << "\n";
    f << "Detect.BlockMatching.min_disparity=0"<< "\n";
    f << "Detect.BlockMatching.num_disparities=16" << "\n";
    f << "Detect.BlockMatching.block_size="<< res_block << "\n";
    f << "Detect.BlockMatching.p1=0"<< "\n";
    f << "Detect.BlockMatching.p2=0"<< "\n";
    f << "Detect.BlockMatching.disp12_max_diff=0"<< "\n";
    f << "Detect.BlockMatching.pre_filter_cap=0"<< "\n";
    f << "Detect.BlockMatching.uniqueness_ratio=0"<< "\n";
    f << "Detect.BlockMatching.speckle_window_size=0"<< "\n";
    f << "Detect.BlockMatching.speckle_range=0"<< "\n";

    f << "Detect.MotionHistory=0"<< "\n";
    f << "Detect.MotionHistory.mhi_duration=5"<< "\n";
    f << "Detect.MotionHistory.min_time_delta=0.05"<< "\n";
    f << "Detect.MotionHistory.max_time_delta=10"<<"\n";
    f << "Detect.MotionHistory.threshold=22"<<"\n";
}

/**
* a function called in interactive mode to write the motion history module
* this function is used in both modes
* users have decided to use motion history as a detection module they also decided to give random values for each parameters
* parameters will be wrote for all the detection module (except for the common parts) : one activated, the others will not be
* random values are an approximation of a Gaussian distribution based on the use of uniformly distributed values
*
* input :
*   - fstream& f : a file stream representing the output file
*/
void write_use_MH_rand(fstream& f)
{
    f << "Detect.BackgroundSubtraction=0"<< "\n";
    f << "Detect.BackgroundSubtraction.MOG=0"<< "\n";
    f << "Detect.BackgroundSubtraction.MOG.nb_frame=200"<< "\n";
    f << "Detect.BackgroundSubtraction.MOG.nb_mixture=5"<< "\n";
    f << "Detect.BackgroundSubtraction.MOG.noiseRob=0.0"<< "\n";
    f << "Detect.BackgroundSubtraction.MOG.decisionThreshold=0.7"<< "\n";
    f << "Detect.BackgroundSubtraction.MOG2=0"<< "\n";
    f << "Detect.BackgroundSubtraction.MOG2.detectShadows=1"<< "\n";
    f << "Detect.BackgroundSubtraction.MOG2.nb_frame=500"<< "\n";
    f << "Detect.BackgroundSubtraction.MOG2.thresholdSquare=16.0"<< "\n";
    f << "Detect.BackgroundSubtraction.GMG=0"<< "\n";
    f << "Detect.BackgroundSubtraction.GMG.decisionThreshold=0.8"<< "\n";
    f << "Detect.BackgroundSubtraction.GMG.nb_frame=120"<< "\n";
    f << "Detect.BackgroundSubtraction.KNN=0"<< "\n";
    f << "Detect.BackgroundSubtraction.KNN.nb_frame=500"<< "\n";
    f << "Detect.BackgroundSubtraction.KNN.thresholdSquare=400.0"<< "\n";
    f << "Detect.BackgroundSubtraction.KNN.detectShadows=1"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD=0" << "\n";
    f << "Detect.BackgroundSubtraction.FGD.alpha1=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.deltish=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.n1cc=10"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.n2c=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.n2cc=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.is_obj_without_holes=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.lc=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.n1c=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.lcc=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.perform_morphing=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.minArea=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.alpha2=1"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.t=0"<< "\n";
    f << "Detect.BackgroundSubtraction.FGD.alpha3=0"<< "\n";
    f << "Detect.OpticalFlow=0"<< "\n";
    f << "Detect.OpticalFlow.Dense=0"<< "\n";
    f << "Detect.OpticalFlow.Sparse=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.Farneback=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.SimpleFlow=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.DualTVL=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.Farneback.pyr_scale=0.5"<< "\n";
    f << "Detect.OpticalFlow.Dense.Farneback.levels=3"<< "\n";
    f << "Detect.OpticalFlow.Dense.Farneback.winSize=15"<< "\n";
    f << "Detect.OpticalFlow.Dense.Farneback.iterations=3"<< "\n";
    f << "Detect.OpticalFlow.Dense.Farneback.poly_n=5"<< "\n";
    f << "Detect.OpticalFlow.Dense.Farneback.poly_sigma=1.2"<< "\n";
    f << "Detect.OpticalFlow.Dense.Farneback.use_init_flow=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.Farneback.use_gaussian=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.Farneback.threshold=0.0001"<< "\n";
    f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK=0"<< "\n";
    f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.winSize=0"<< "\n";
    f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.maxLevel=0"<< "\n";
    f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.count=0"<< "\n";
    f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.epsilon=0"<< "\n";
    f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.use_initial_flow=0"<< "\n";
    f << "Detect.OpticalFlow.Sparse.OpticalFlowPyrLK.use_eigen_val=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.SimpleFlow.nb_layer=3"<< "\n";
    f << "Detect.OpticalFlow.Dense.SimpleFlow.averaging_block_size=2"<< "\n";
    f << "Detect.OpticalFlow.Dense.SimpleFlow.max_flow=4"<< "\n";
    f << "Detect.OpticalFlow.Dense.DualTVL.tau=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.DualTVL.lambda=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.DualTVL.theta=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.DualTVL.nscales=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.DualTVL.warps=1"<< "\n";
    f << "Detect.OpticalFlow.Dense.DualTVL.epsilon=0"<< "\n";
    f << "Detect.OpticalFlow.Dense.DualTVL.iterations=0"<< "\n";
    f << "Detect.BlockMatching=0" << "\n";
    f << "Detect.BlockMatching.min_disparity=0"<< "\n";
    f << "Detect.BlockMatching.num_disparities=16"<< "\n";
    f << "Detect.BlockMatching.block_size=3"<< "\n";
    f << "Detect.BlockMatching.p1=0"<< "\n";
    f << "Detect.BlockMatching.p2=0"<< "\n";
    f << "Detect.BlockMatching.disp12_max_diff=0"<< "\n";
    f << "Detect.BlockMatching.pre_filter_cap=0"<< "\n";
    f << "Detect.BlockMatching.uniqueness_ratio=0"<< "\n";
    f << "Detect.BlockMatching.speckle_window_size=0"<< "\n";
    f << "Detect.BlockMatching.speckle_range=0"<< "\n";

    int res_duration = (((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX)+ ((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX) ) * 25; // between 0 and 100 -> mean around 50
    double res_min = (((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX)+ ((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX) ) /4; // between 0 and 1 -> mean around 0.5
    double res_max = (((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX)+ ((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX) ) * 25; // between 0 and 1 -> mean around 0.5
    int res_thresh = (((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX)+ ((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX) ) /4 * 255 + 1; // between 1 and 256 -> mean around 128
    f << "Detect.MotionHistory=1"<< "\n";
    f << "Detect.MotionHistory.mhi_duration=" << res_duration << "\n";
    f << "Detect.MotionHistory.min_time_delta=" << res_min << "\n";
    f << "Detect.MotionHistory.max_time_delta=" << res_max <<"\n";
    f << "Detect.MotionHistory.threshold=" << res_thresh<<"\n";
}

/**
* a function called in interactive mode which will write common part of the detection module
* users has decided to use detection module and have chosen which one, call the function according to choices
* this function will write randomly generated values for the given choice -> other choices in the module will be deactivated
* the random generation is an approximation of Gaussian distribution by using uniformly distributed values (call several time rand() on the range [0;1] then divide by the number of rand() call (upper bound)
* input :
*   - fstream& f : a file stream representing the output file (avoid copy)
*   - int choice : the choice made regarding the method to be used
*
* output :
*   - something is written in the output file
*   - methods of the detection module that are not used are deactivated
*/
void write_detect_rand(fstream& f, int choice)
{
    f << "OpenCV.nb_frame=222"<< "\n";
    f << "Detect=1"<< "\n";

    switch(choice)
    {
        case 1 : //use background subtraction
        {
            write_use_bgSub_rand(f);
            break;
        }
        case 2 : //use Optical Flow
        {
            write_use_optFlow_rand(f);
            break;
        }
        case 3 : //use BM
        {
            write_use_BM_rand(f);
            break;
        }
        case 4:  //use Motion History
        {
            write_use_MH_rand(f);
            break;
        }
    }

    int res = (((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX)+ ((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX) ) * 5 + 10; //between 10 and 30 -> mean around 20
    int res_scal_fact = (((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX)+ ((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX) ) * 7.5 + 10; // between 10 and 40 -> mean around 25
    int res_loop = (((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX)+ ((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX) ) * 5 - 1; // between -1 and 19 -> mean around 9
    int res_dist = (((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX)+ ((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX) ) /4 * 10 + 10; // between 10 and 20 -> mean around 15
    f << "Detect.MorphologicalOperators=1"<< "\n";
    f << "Detect.MorphologicalOperators.Dilate=1"<< "\n";
    f << "Detect.MorphologicalOperators.Dilate.shape=rectangle"<< "\n";
    f << "Detect.MorphologicalOperators.Dilate.height=" << res << "\n";
    f << "Detect.MorphologicalOperators.Dilate.width=" << res << "\n";
    f << "Detect.MorphologicalOperators.Dilate.anchory=-1"<< "\n";
    f << "Detect.MorphologicalOperators.Dilate.anchorx=-1"<< "\n";
    f << "Detect.MorphologicalOperators.Erode=1"<< "\n";
    f << "Detect.MorphologicalOperators.Erode.shape=rectangle"<< "\n";
    f << "Detect.MorphologicalOperators.Erode.height=" << res << "\n";
    f << "Detect.MorphologicalOperators.Erode.width=" << res << "\n";
    f << "Detect.MorphologicalOperators.Erode.anchorx=-1"<< "\n";
    f << "Detect.MorphologicalOperators.Erode.anchory=-1"<< "\n";
    f << "Detect.ContoursRetrieval=1"<< "\n";
    f << "Detect.ContoursHierarchical.HCR=0"<< "\n";
    f << "Detect.ContoursHierarchical.HCR.External=0"<< "\n";
    f << "Detect.ContoursHierarchical.HCR.C_comp=0"<< "\n";
    f << "Detect.ContoursHierarchical.HCR.Tree=0"<< "\n";
    f << "Detect.ContoursHierarchical.NHCR=1"<< "\n";
    f << "Detect.ContoursHierarchical.NHCR.List=1"<< "\n";
    f << "Detect.ContoursHierarchical.None=0"<< "\n";
    f << "Detect.ContoursHierarchical.Approximate=1"<< "\n";
    f << "Detect.ContoursHierarchical.Approximate.K_Cos=0"<< "\n";
    f << "Detect.ContoursHierarchical.Approximate.Simple=1"<< "\n";
    f << "Detect.ContoursHierarchical.Approximate.L1=0"<< "\n";
    f << "Detect.ContoursHierarchical.offsetx=0"<< "\n";
    f << "Detect.ContoursHierarchical.offsety=0"<< "\n";
    f << "Detect.MerginBoundingBoxes=1"<< "\n";
    f << "Detect.MerginBoundingBoxes.scalingFactor=" << res_scal_fact << "\n";
    f << "Detect.MerginBoundingBoxes.nb_loop=" << res_loop << "\n";
    f << "Detect.MerginBoundingBoxes.maxDistance=" << res_dist << "\n";
    f << "Detect.Filters=1"<< "\n";
    f << "Detect.Filters.FilterLenght=1"<< "\n";
    f << "Detect.Filters.FilterLenght.threshold=10"<< "\n";
    f << "Detect.Filters.FilterArea=1"<< "\n";
    f << "Detect.Filters.FilterArea.threshold=100"<< "\n";
}

/**
* a function which will write common part of the detection module
* users has decided to use detection module and have chosen which one, call the function according to choices
* this function will write randomly generated values for the given choice -> other choices in the module will be deactivated
* the random generation is an approximation of Gaussian distribution by using uniformly distributed values (call several time rand() on the range [0;1] then divide by the number of rand() call (upper bound)
* input :
*   - fstream& f : a file stream representing the output file (avoid copy)
*   - int choice : the choice made regarding the method to be used
*   - char** argv : the array of arguments given to the main function while called
*   - int idx : the current index to use to retrieve/fetch the right argument
*
* output :
*   - something is written in the output file
*   - methods of the detection module that are not used are deactivated
*/
int write_detect_rand(fstream& f, int choice, char** argv, int idx)
{
    f << "OpenCV.nb_frame=222"<< "\n";
    f << "Detect=1"<< "\n";

    switch(choice)
    {
        case 1 : //use background subtraction
        {
            idx = write_use_bgSub_rand(f, argv, idx);
            break;
        }
        case 2 : //use Optical Flow
        {
            idx = write_use_optFlow_rand(f, argv, idx);
            break;
        }
        case 3 : //use BM
        {
            write_use_BM_rand(f);
            break;
        }
        case 4:  //use Motion History
        {
            write_use_MH_rand(f);
            break;
        }
    }

    int res = (((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX)+ ((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX) ) * 5 + 10; //between 10 and 30 -> mean around 20
    int res_scal_fact = (((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX)+ ((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX) ) * 7.5 + 10; // between 10 and 40 -> mean around 25
    int res_loop = (((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX)+ ((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX) ) * 5 - 1; // between -1 and 19 -> mean around 9
    int res_dist = (((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX)+ ((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX) ) /4 * 10 + 10; // between 10 and 20 -> mean around 15
    f << "Detect.MorphologicalOperators=1"<< "\n";
    f << "Detect.MorphologicalOperators.Dilate=1"<< "\n";
    f << "Detect.MorphologicalOperators.Dilate.shape=rectangle"<< "\n";
    f << "Detect.MorphologicalOperators.Dilate.height=" << res << "\n";
    f << "Detect.MorphologicalOperators.Dilate.width=" << res << "\n";
    f << "Detect.MorphologicalOperators.Dilate.anchory=-1"<< "\n";
    f << "Detect.MorphologicalOperators.Dilate.anchorx=-1"<< "\n";
    f << "Detect.MorphologicalOperators.Erode=1"<< "\n";
    f << "Detect.MorphologicalOperators.Erode.shape=rectangle"<< "\n";
    f << "Detect.MorphologicalOperators.Erode.height=" << res << "\n";
    f << "Detect.MorphologicalOperators.Erode.width=" << res << "\n";
    f << "Detect.MorphologicalOperators.Erode.anchorx=-1"<< "\n";
    f << "Detect.MorphologicalOperators.Erode.anchory=-1"<< "\n";
    f << "Detect.ContoursRetrieval=1"<< "\n";
    f << "Detect.ContoursHierarchical.HCR=0"<< "\n";
    f << "Detect.ContoursHierarchical.HCR.External=0"<< "\n";
    f << "Detect.ContoursHierarchical.HCR.C_comp=0"<< "\n";
    f << "Detect.ContoursHierarchical.HCR.Tree=0"<< "\n";
    f << "Detect.ContoursHierarchical.NHCR=1"<< "\n";
    f << "Detect.ContoursHierarchical.NHCR.List=1"<< "\n";
    f << "Detect.ContoursHierarchical.None=0"<< "\n";
    f << "Detect.ContoursHierarchical.Approximate=1"<< "\n";
    f << "Detect.ContoursHierarchical.Approximate.K_Cos=0"<< "\n";
    f << "Detect.ContoursHierarchical.Approximate.Simple=1"<< "\n";
    f << "Detect.ContoursHierarchical.Approximate.L1=0"<< "\n";
    f << "Detect.ContoursHierarchical.offsetx=0"<< "\n";
    f << "Detect.ContoursHierarchical.offsety=0"<< "\n";
    f << "Detect.MerginBoundingBoxes=1"<< "\n";
    f << "Detect.MerginBoundingBoxes.scalingFactor=" << res_scal_fact << "\n";
    f << "Detect.MerginBoundingBoxes.nb_loop=" << res_loop << "\n";
    f << "Detect.MerginBoundingBoxes.maxDistance=" << res_dist << "\n";
    f << "Detect.Filters=1"<< "\n";
    f << "Detect.Filters.FilterLenght=1"<< "\n";
    f << "Detect.Filters.FilterLenght.threshold=10"<< "\n";
    f << "Detect.Filters.FilterArea=1"<< "\n";
    f << "Detect.Filters.FilterArea.threshold=100"<< "\n";

    return idx;
}

/**
* a function which asks user to choose if they want to use a detection module and its configuration
* this function is used only in interactive mode
* It writes (by delegation) directly choices into the output file
*/
void module_detection_creation(fstream& f)
{
    ///want to use a detection module ?
    cout << "Do you want to use a module to detect what is moving inside frames ? (y or n)" << endl;
    string choice;
    cin >> choice;

    ///if yes
    if(choice == "y")
    {
        ///choose the method to use
        cout << "What method do you want to use ? (1: Background Subtraction; 2: Optical Flow; 3: BlockMatching; 4: Motion History)" << endl;
        getline(cin,choice);
        while(choice != "1" && choice != "2" && choice != "3" && choice != "4" && choice != "5")
        {
            cout << "What method do you want to use ? (1: Background Subtraction; 2: Optical Flow; 3: BlockMatching; 4: Motion History)" << endl;
            getline(cin,choice);
        }

        ///use defaults values ?
        string def;
        cout << "Do you want to use default values ? (y or n)" << endl;
        getline(cin,def);
        if (def == "y") ///if yes
        {
            write_detect_default(f,atoi(choice.c_str()));
        }
        else ///if no
        {
            write_detect_rand(f,atoi(choice.c_str()));
        }
    }
    else ///if no detection module
    {
        write_no_detection(f);
    }
}

/**
* a function which uses parameters to continue the execution of the program (without interactions with users)
* this function is used only if more than argument is given
* It writes (by delegation) directly choices into the output file
*/
int module_detection_creation(fstream& f, char** argv, int& idx)
{
    ///want to use detection module ? -> use argv[idx]
    cout << "Do you want to use a module to detect what is moving inside frames ? (y or n)" << endl;
    string choice(argv[idx]);
    cout << choice << endl;
    idx++;

    ///if yes
    if(choice == "y")
    {

        /// choose the method to use -> use argv[idx]
        cout << "What method do you want to use ? (1: Background Subtraction; 2: Optical Flow; 3: BlockMatching; 4: Motion History)" << endl;
        //getline(cin,choice);
        choice = argv[idx];
        cout << choice << endl;
        idx++;
        while(choice != "1" && choice != "2" && choice != "3" && choice != "4" && choice != "5")
        {
            cout << "What method do you want to use ? (1: Background Subtraction; 2: Optical Flow; 3: BlockMatching; 4: Motion History)" << endl;
            getline(cin,choice);
        }

        ///use default values ? -> use argv[idx]
        cout << "Do you want to use default values ? (y or n)" << endl;
        string def(argv[idx]);
        cout << def << endl;
        idx++;
        /*cout << "Do you want to use default values ? (y or n)" << endl;
        getline(cin,def);*/
        if (def == "y") ///if yes
        {
            idx = write_detect_default(f,atoi(choice.c_str()), argv, idx);
        }
        else ///if no
        {
            idx = write_detect_rand(f,atoi(choice.c_str()), argv, idx);
        }
    }
    else ///if no detection module
    {
        write_no_detection(f);
    }
    return idx;
}

/**
* a function called in interactive mode to write the color space to use
* this function should not be called if feature matching (recognition module) is planned to be used -> features should not be reasoning over color space
* 9 different color spaces are provided by OpenCV
* only one can be activated at a time
*
* input :
*   - fstream& f : a file stream representing the output file
*
* output :
*   - the color space parameters is written in the output file
*/
void write_use_color_space(fstream& f)
{
    f << "Recognition.ColorSpace=1"<< "\n";

    ///which color space to use ?
    cout << "Which color space do you want to use ? (1: RGB; 2: grayscale; 3: YCrCb; 4 : YUV; 5: XYZ; 6: HSV; 7: HLS; 8: La*b*; 9: Luv)" << "\n";
    string res;
    cin >> res;
    while (res != "1" && res != "2" && res != "3" && res != "4" && res != "5" && res != "6" && res != "7" && res != "8" && res !="9")
    {
        cout << "Which color space do you want to use ? (1: RGB; 2: grayscale; 3: YCrCb; 4 : YUV; 5: XYZ; 6: HSV; 7: HLS; 8: La*b*; 9: Luv)" << "\n";
        cin >> res;
    }

    ///write color space parameters according to choices
    switch(atoi(res.c_str()))
    {
        case 1 : // RGB
        {
            f << "Recognition.ColorSpace.rgb=1"<< "\n";
            f << "Recognition.ColorSpace.gray=0"<< "\n";
            f << "Recognition.ColorSpace.yCrCb=0"<< "\n";
            f << "Recognition.ColorSpace.YUV=0"<< "\n";
            f << "Recognition.ColorSpace.XYZ=0"<< "\n";
            f << "Recognition.ColorSpace.HSV=0"<< "\n";
            f << "Recognition.ColorSpace.HLS=0"<< "\n";
            f << "Recognition.ColorSpace.Lab=0"<< "\n";
            f << "Recognition.ColorSpace.Luv=0"<< "\n";
            break;
        }
        case 2: // grayscale
        {
            f << "Recognition.ColorSpace.rgb=0"<< "\n";
            f << "Recognition.ColorSpace.gray=1"<< "\n";
            f << "Recognition.ColorSpace.yCrCb=0"<< "\n";
            f << "Recognition.ColorSpace.YUV=0"<< "\n";
            f << "Recognition.ColorSpace.XYZ=0"<< "\n";
            f << "Recognition.ColorSpace.HSV=0"<< "\n";
            f << "Recognition.ColorSpace.HLS=0"<< "\n";
            f << "Recognition.ColorSpace.Lab=0"<< "\n";
            f << "Recognition.ColorSpace.Luv=0"<< "\n";
            break;
        }
        case 3 : // YCrCb
        {
            f << "Recognition.ColorSpace.rgb=0"<< "\n";
            f << "Recognition.ColorSpace.gray=0"<< "\n";
            f << "Recognition.ColorSpace.yCrCb=1"<< "\n";
            f << "Recognition.ColorSpace.YUV=0"<< "\n";
            f << "Recognition.ColorSpace.XYZ=0"<< "\n";
            f << "Recognition.ColorSpace.HSV=0"<< "\n";
            f << "Recognition.ColorSpace.HLS=0"<< "\n";
            f << "Recognition.ColorSpace.Lab=0"<< "\n";
            f << "Recognition.ColorSpace.Luv=0"<< "\n";
            break;
        }
        case 4 : // YUV
        {
            f << "Recognition.ColorSpace.rgb=0"<< "\n";
            f << "Recognition.ColorSpace.gray=0"<< "\n";
            f << "Recognition.ColorSpace.yCrCb=0"<< "\n";
            f << "Recognition.ColorSpace.YUV=1"<< "\n";
            f << "Recognition.ColorSpace.XYZ=0"<< "\n";
            f << "Recognition.ColorSpace.HSV=0"<< "\n";
            f << "Recognition.ColorSpace.HLS=0"<< "\n";
            f << "Recognition.ColorSpace.Lab=0"<< "\n";
            f << "Recognition.ColorSpace.Luv=0"<< "\n";
            break;
        }
        case 5 : // XYZ
        {
            f << "Recognition.ColorSpace.rgb=0"<< "\n";
            f << "Recognition.ColorSpace.gray=0"<< "\n";
            f << "Recognition.ColorSpace.yCrCb=0"<< "\n";
            f << "Recognition.ColorSpace.YUV=0"<< "\n";
            f << "Recognition.ColorSpace.XYZ=1"<< "\n";
            f << "Recognition.ColorSpace.HSV=0"<< "\n";
            f << "Recognition.ColorSpace.HLS=0"<< "\n";
            f << "Recognition.ColorSpace.Lab=0"<< "\n";
            f << "Recognition.ColorSpace.Luv=0"<< "\n";
            break;
        }
        case 6 : // HSV
        {
            f << "Recognition.ColorSpace.rgb=0"<< "\n";
            f << "Recognition.ColorSpace.gray=0"<< "\n";
            f << "Recognition.ColorSpace.yCrCb=0"<< "\n";
            f << "Recognition.ColorSpace.YUV=0"<< "\n";
            f << "Recognition.ColorSpace.XYZ=0"<< "\n";
            f << "Recognition.ColorSpace.HSV=1"<< "\n";
            f << "Recognition.ColorSpace.HLS=0"<< "\n";
            f << "Recognition.ColorSpace.Lab=0"<< "\n";
            f << "Recognition.ColorSpace.Luv=0"<< "\n";
            break;
        }
        case 7 : // HLS
        {
            f << "Recognition.ColorSpace.rgb=0"<< "\n";
            f << "Recognition.ColorSpace.gray=0"<< "\n";
            f << "Recognition.ColorSpace.yCrCb=0"<< "\n";
            f << "Recognition.ColorSpace.YUV=0"<< "\n";
            f << "Recognition.ColorSpace.XYZ=0"<< "\n";
            f << "Recognition.ColorSpace.HSV=0"<< "\n";
            f << "Recognition.ColorSpace.HLS=1"<< "\n";
            f << "Recognition.ColorSpace.Lab=0"<< "\n";
            f << "Recognition.ColorSpace.Luv=0"<< "\n";
            break;
        }
        case 8 : // La*b*
        {
            f << "Recognition.ColorSpace.rgb=0"<< "\n";
            f << "Recognition.ColorSpace.gray=0"<< "\n";
            f << "Recognition.ColorSpace.yCrCb=0"<< "\n";
            f << "Recognition.ColorSpace.YUV=0"<< "\n";
            f << "Recognition.ColorSpace.XYZ=0"<< "\n";
            f << "Recognition.ColorSpace.HSV=0"<< "\n";
            f << "Recognition.ColorSpace.HLS=0"<< "\n";
            f << "Recognition.ColorSpace.Lab=1"<< "\n";
            f << "Recognition.ColorSpace.Luv=0"<< "\n";
            break;
        }
        case 9 : // Luv
        {
            f << "Recognition.ColorSpace.rgb=0"<< "\n";
            f << "Recognition.ColorSpace.gray=0"<< "\n";
            f << "Recognition.ColorSpace.yCrCb=0"<< "\n";
            f << "Recognition.ColorSpace.YUV=0"<< "\n";
            f << "Recognition.ColorSpace.XYZ=0"<< "\n";
            f << "Recognition.ColorSpace.HSV=0"<< "\n";
            f << "Recognition.ColorSpace.HLS=0"<< "\n";
            f << "Recognition.ColorSpace.Lab=0"<< "\n";
            f << "Recognition.ColorSpace.Luv=1"<< "\n";
            break;
        }
    }
}

/**
* a function called to write the color space to use
* this function should not be called if feature matching (recognition module) is planned to be used -> features should not be reasoning over color space
* 9 different color spaces are provided by OpenCV
* only one can be activated at a time
*
* input :
*   - fstream& f : a file stream representing the output file
*   - char** argv : the list of arguments given when the program was called
*   - int idx : the index of the next argument to use
*
* output :
*   - the color space parameters is written in the output file
*   - int : the index of the next argument to use
*/
int write_use_color_space(fstream& f, char** argv, int idx)
{
    f << "Recognition.ColorSpace=1"<< "\n";

    ///which color space to use ?
    cout << "Which color space do you want to use ? (1: RGB; 2: grayscale; 3: YCrCb; 4 : YUV; 5: XYZ; 6: HSV; 7: HLS; 8: La*b*; 9: Luv)" << "\n";
    string res(argv[idx]);
    //cin >> res;
    cout << res << endl;
    idx ++;

    while (res != "1" && res != "2" && res != "3" && res != "4" && res != "5" && res != "6" && res != "7" && res != "8" && res !="9")
    {
        cout << "Which color space do you want to use ? (1: RGB; 2: grayscale; 3: YCrCb; 4 : YUV; 5: XYZ; 6: HSV; 7: HLS; 8: La*b*; 9: Luv)" << "\n";
        cin >> res;
    }

    ///write color space parameters according to choices
    switch(atoi(res.c_str()))
    {
        case 1 : // RGB
        {
            f << "Recognition.ColorSpace.rgb=1"<< "\n";
            f << "Recognition.ColorSpace.gray=0"<< "\n";
            f << "Recognition.ColorSpace.yCrCb=0"<< "\n";
            f << "Recognition.ColorSpace.YUV=0"<< "\n";
            f << "Recognition.ColorSpace.XYZ=0"<< "\n";
            f << "Recognition.ColorSpace.HSV=0"<< "\n";
            f << "Recognition.ColorSpace.HLS=0"<< "\n";
            f << "Recognition.ColorSpace.Lab=0"<< "\n";
            f << "Recognition.ColorSpace.Luv=0"<< "\n";
            break;
        }
        case 2: // Grayscale
        {
            f << "Recognition.ColorSpace.rgb=0"<< "\n";
            f << "Recognition.ColorSpace.gray=1"<< "\n";
            f << "Recognition.ColorSpace.yCrCb=0"<< "\n";
            f << "Recognition.ColorSpace.YUV=0"<< "\n";
            f << "Recognition.ColorSpace.XYZ=0"<< "\n";
            f << "Recognition.ColorSpace.HSV=0"<< "\n";
            f << "Recognition.ColorSpace.HLS=0"<< "\n";
            f << "Recognition.ColorSpace.Lab=0"<< "\n";
            f << "Recognition.ColorSpace.Luv=0"<< "\n";
            break;
        }
        case 3 : // YCrCb
        {
            f << "Recognition.ColorSpace.rgb=0"<< "\n";
            f << "Recognition.ColorSpace.gray=0"<< "\n";
            f << "Recognition.ColorSpace.yCrCb=1"<< "\n";
            f << "Recognition.ColorSpace.YUV=0"<< "\n";
            f << "Recognition.ColorSpace.XYZ=0"<< "\n";
            f << "Recognition.ColorSpace.HSV=0"<< "\n";
            f << "Recognition.ColorSpace.HLS=0"<< "\n";
            f << "Recognition.ColorSpace.Lab=0"<< "\n";
            f << "Recognition.ColorSpace.Luv=0"<< "\n";
            break;
        }
        case 4 : // YUV
        {
            f << "Recognition.ColorSpace.rgb=0"<< "\n";
            f << "Recognition.ColorSpace.gray=0"<< "\n";
            f << "Recognition.ColorSpace.yCrCb=0"<< "\n";
            f << "Recognition.ColorSpace.YUV=1"<< "\n";
            f << "Recognition.ColorSpace.XYZ=0"<< "\n";
            f << "Recognition.ColorSpace.HSV=0"<< "\n";
            f << "Recognition.ColorSpace.HLS=0"<< "\n";
            f << "Recognition.ColorSpace.Lab=0"<< "\n";
            f << "Recognition.ColorSpace.Luv=0"<< "\n";
            break;
        }
        case 5 : // XYZ
        {
            f << "Recognition.ColorSpace.rgb=0"<< "\n";
            f << "Recognition.ColorSpace.gray=0"<< "\n";
            f << "Recognition.ColorSpace.yCrCb=0"<< "\n";
            f << "Recognition.ColorSpace.YUV=0"<< "\n";
            f << "Recognition.ColorSpace.XYZ=1"<< "\n";
            f << "Recognition.ColorSpace.HSV=0"<< "\n";
            f << "Recognition.ColorSpace.HLS=0"<< "\n";
            f << "Recognition.ColorSpace.Lab=0"<< "\n";
            f << "Recognition.ColorSpace.Luv=0"<< "\n";
            break;
        }
        case 6 : // HSV
        {
            f << "Recognition.ColorSpace.rgb=0"<< "\n";
            f << "Recognition.ColorSpace.gray=0"<< "\n";
            f << "Recognition.ColorSpace.yCrCb=0"<< "\n";
            f << "Recognition.ColorSpace.YUV=0"<< "\n";
            f << "Recognition.ColorSpace.XYZ=0"<< "\n";
            f << "Recognition.ColorSpace.HSV=1"<< "\n";
            f << "Recognition.ColorSpace.HLS=0"<< "\n";
            f << "Recognition.ColorSpace.Lab=0"<< "\n";
            f << "Recognition.ColorSpace.Luv=0"<< "\n";
            break;
        }
        case 7 : // HLS
        {
            f << "Recognition.ColorSpace.rgb=0"<< "\n";
            f << "Recognition.ColorSpace.gray=0"<< "\n";
            f << "Recognition.ColorSpace.yCrCb=0"<< "\n";
            f << "Recognition.ColorSpace.YUV=0"<< "\n";
            f << "Recognition.ColorSpace.XYZ=0"<< "\n";
            f << "Recognition.ColorSpace.HSV=0"<< "\n";
            f << "Recognition.ColorSpace.HLS=1"<< "\n";
            f << "Recognition.ColorSpace.Lab=0"<< "\n";
            f << "Recognition.ColorSpace.Luv=0"<< "\n";
            break;
        }
        case 8 : // La*b*
        {
            f << "Recognition.ColorSpace.rgb=0"<< "\n";
            f << "Recognition.ColorSpace.gray=0"<< "\n";
            f << "Recognition.ColorSpace.yCrCb=0"<< "\n";
            f << "Recognition.ColorSpace.YUV=0"<< "\n";
            f << "Recognition.ColorSpace.XYZ=0"<< "\n";
            f << "Recognition.ColorSpace.HSV=0"<< "\n";
            f << "Recognition.ColorSpace.HLS=0"<< "\n";
            f << "Recognition.ColorSpace.Lab=1"<< "\n";
            f << "Recognition.ColorSpace.Luv=0"<< "\n";
            break;
        }
        case 9 : // Luv
        {
            f << "Recognition.ColorSpace.rgb=0"<< "\n";
            f << "Recognition.ColorSpace.gray=0"<< "\n";
            f << "Recognition.ColorSpace.yCrCb=0"<< "\n";
            f << "Recognition.ColorSpace.YUV=0"<< "\n";
            f << "Recognition.ColorSpace.XYZ=0"<< "\n";
            f << "Recognition.ColorSpace.HSV=0"<< "\n";
            f << "Recognition.ColorSpace.HLS=0"<< "\n";
            f << "Recognition.ColorSpace.Lab=0"<< "\n";
            f << "Recognition.ColorSpace.Luv=1"<< "\n";
            break;
        }
    }

    return idx;
}

/**
* a function called to write the color space parameters when none are used
* 9 different color spaces are provided by OpenCV
* none should be activated after calling this function
*
* input :
*   - fstream& f : a file stream representing the output file
*
* output :
*   - the color space parameters are written in the output file (none are activated)
*/
void write_not_use_color_space(fstream& f)
{
    f << "Recognition.ColorSpace=1"<< "\n";
    f << "Recognition.ColorSpace.rgb=1"<< "\n";
    f << "Recognition.ColorSpace.gray=0"<< "\n";
    f << "Recognition.ColorSpace.yCrCb=0"<< "\n";
    f << "Recognition.ColorSpace.YUV=0"<< "\n";
    f << "Recognition.ColorSpace.XYZ=0"<< "\n";
    f << "Recognition.ColorSpace.HSV=0"<< "\n";
    f << "Recognition.ColorSpace.HLS=0"<< "\n";
    f << "Recognition.ColorSpace.Lab=0"<< "\n";
    f << "Recognition.ColorSpace.Luv=0"<< "\n";
}

/**
* a function called in interactive mode to write the template matching module
* users have decided to use template matching as a recognition module they also decided to give default values for each parameters
* parameters will be wrote for all the recognition module (except for the common parts) : one activated, the others will not be
*
* input :
*   - fstream& f : a file stream representing the output file
*
* output :
*   - recognition module should be written in the output file (assumed that it has been closed to flush the buffer)
*/
void write_use_template_matching(fstream& f)
{
    f << "Recognition.TemplateMatching=1"<< "\n";
    f << "Recognition.TemplateMatching.TemplateMatching=1"<< "\n";
    f << "Recognition.TemplateMatching.HistogramMatching=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching=0"<< "\n";
    f << "Recognition.TemplateMatching.DistanceMatching=0"<<"\n";
    f << "Recognition.Pyramidal=0"<< "\n";
    f << "Recognition.Pyramidal.BMPyramidal=0"<< "\n";
    f << "Recognition.Pyramidal.CascadeClassifier=0"<< "\n";

    ///which distance to use ?
    cout << "Which distance method do you want to use ? (1 : tm_coeff; 2 : tm_coeff_normalized; 3 : tm_sqdiff; 4 : tm_sqdiff_normalized; 5 : tm_ccorr ; 6 : tm_corr_normalized)" << "\n";
    string c;
    cin >> c;
    while( c != "1" && c != "2" && c != "3" && c != "4" && c != "5" && c != "6")
    {
        cout << "Which distance method do you want to use ? (1 : tm_coeff; 2 : tm_coeff_normalized; 3 : tm_sqdiff; 4 : tm_sqdiff_normalized; 5 : tm_ccorr ; 6 : tm_corr_normalized)" << "\n";
        cin >> c;
    }

    //write parameters according to choices
    switch (atoi(c.c_str()))
    {
        case 1 :
        {
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccoeff=1"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccoeff_morned=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_sqdiff=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_sqdiff_normed=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccorr=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccorr_normed=0"<< "\n";
            break;
        }
        case 2 :
        {
           f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccoeff=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccoeff_morned=1"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_sqdiff=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_sqdiff_normed=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccorr=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccorr_normed=0"<< "\n";
            break;
        }
        case 3 :
        {
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccoeff=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccoeff_morned=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_sqdiff=1"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_sqdiff_normed=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccorr=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccorr_normed=0"<< "\n";
            break;
        }
        case 4 :
        {
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccoeff=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccoeff_norned=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_sqdiff=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_sqdiff_normed=1"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccorr=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccorr_normed=0"<< "\n";
            break;
        }
        case 5 :
        {
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccoeff=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccoeff_morned=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_sqdiff=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_sqdiff_normed=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccorr=1"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccorr_normed=0"<< "\n";
            break;
        }
        case 6 :
        {
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccoeff=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccoeff_morned=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_sqdiff=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_sqdiff_normed=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccorr=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccorr_normed=1"<< "\n";
            break;
        }
    }

    f << "Recognition.TemplateMatching.TemplateMatching.nb_layers=0" << "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.size_factor=2" << "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.match_proba=0.8" << "\n";

    ///color space ? And which one ?
    cout << "Do you want to use a particular color space ? (y or n)" <<"\n";
    cin >> c;
    if (c == "y")
    {
        write_use_color_space(f);
    }
    else
    {
        write_not_use_color_space(f);
    }

    f << "Recognition.TemplateMatching.DistanceMatching.Absolute_diff=0" << "\n";
    f << "Recognition.TemplateMatching.DistanceMatching.MSE=0" << "\n";
    f << "Recognition.TemplateMatching.DistanceMatching.MAE=0" << "\n";
    f << "Recognition.TemplateMatching.DistanceMatching.max_distance=1200" << "\n";

    f << "Recognition.TemplateMatching.FeatureMatching.Sift=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Surf=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Brief=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Brisk=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Freak=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Sift.nfeatures=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Sift.n_octave_layers=3"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Sift.contrast_threshold=0.04"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Sift.edge_threshold=10"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Sift.sigma=1.6"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Surf.hessian_threshold=400.0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Surf.n_octaves=4"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Surf.n_octave_layers=2"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Surf.extended=1"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Surf.upright=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Brief.bytes=32"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Brief.use_orientation=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.nfeatures=500"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.scale_factor=1.2"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.nlevels=8"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.edge_threshold=31"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.first_level=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.wta_k=2"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.score_type=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.patch_size=31"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.fast_threshold=20"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Brisk.thresh=30"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Brisk.octaves=3"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Brisk.pattern_scale=1.0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Freak.orientation_normalized=1"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Freak.scale_normalized=1"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Freak.pattern_scale=22.0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Freak.n_octaves=4"<< "\n";

    f << "Recognition.TemplateMatching.HistogramMatching.numberOfBins=50"<< "\n";
    f << "Recognition.TemplateMatching.HistogramMatching.Threshold=0.8" << "\n";

    f << "Recognition.DistanceMeasure=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance=0"<< "\n";
    f << "Recognition.DistanceMeasure.PixelWiseDistance=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.Correl=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.ChiSquare=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.ChiSquareAlt=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.Intersection=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.KLDivergence=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.Hellinger=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.Bhattacharyya=0"<< "\n";
}

/**
* a function called to write the template matching module
* users have decided to use template matching as a recognition module they also decided to give default values for each parameters
* parameters will be written for all the recognition module (except for the common parts) : one activated, the others will not be
* randoms values are an approximation of a Gaussian distribution based on the use of uniformly distributed values
*
* input :
*   - fstream& f : a file stream representing the output file
*   - char** argv : the list of arguments given when the program was called
*   - int idx : the index of the next argument to retrieve
*
* output :
*   - recognition module should be written in the output file (assumed that it has been closed to flush the buffer)
*   - int: the index of the next argument to retrieve
*/
int write_use_template_matching(fstream& f, char** argv, int idx)
{
    f << "Recognition.TemplateMatching=1"<< "\n";
    f << "Recognition.TemplateMatching.TemplateMatching=1"<< "\n";
    f << "Recognition.TemplateMatching.HistogramMatching=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching=0"<< "\n";
    f << "Recognition.TemplateMatching.DistanceMatching=0"<<"\n";
    f << "Recognition.Pyramidal=0"<< "\n";
    f << "Recognition.Pyramidal.BMPyramidal=0"<< "\n";
    f << "Recognition.Pyramidal.CascadeClassifier=0"<< "\n";

    ///which distance to use ?
    cout << "Which distance method do you want to use ? (1 : tm_coeff; 2 : tm_coeff_normalized; 3 : tm_sqdiff; 4 : tm_sqdiff_normalized; 5 : tm_ccorr ; 6 : tm_corr_normalized)" << "\n";
    string c(argv[idx]);
    //cin >> c;
    cout << c << endl;
    idx++;

    while( c != "1" && c != "2" && c != "3" && c != "4" && c != "5" && c != "6")
    {
        cout << "Which distance method do you want to use ? (1 : tm_coeff; 2 : tm_coeff_normalized; 3 : tm_sqdiff; 4 : tm_sqdiff_normalized; 5 : tm_ccorr ; 6 : tm_corr_normalized)" << "\n";
        cin >> c;
    }

    ///write parameters according to choices
    switch (atoi(c.c_str()))
    {
        case 1 :
        {
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccoeff=1"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccoeff_morned=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_sqdiff=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_sqdiff_normed=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccorr=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccorr_normed=0"<< "\n";
            break;
        }
        case 2 :
        {
           f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccoeff=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccoeff_morned=1"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_sqdiff=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_sqdiff_normed=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccorr=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccorr_normed=0"<< "\n";
            break;
        }
        case 3 :
        {
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccoeff=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccoeff_morned=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_sqdiff=1"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_sqdiff_normed=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccorr=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccorr_normed=0"<< "\n";
            break;
        }
        case 4 :
        {
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccoeff=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccoeff_norned=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_sqdiff=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_sqdiff_normed=1"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccorr=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccorr_normed=0"<< "\n";
            break;
        }
        case 5 :
        {
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccoeff=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccoeff_morned=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_sqdiff=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_sqdiff_normed=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccorr=1"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccorr_normed=0"<< "\n";
            break;
        }
        case 6 :
        {
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccoeff=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccoeff_morned=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_sqdiff=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_sqdiff_normed=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccorr=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccorr_normed=1"<< "\n";
            break;
        }
    }

    f << "Recognition.TemplateMatching.TemplateMatching.nb_layers=0" << "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.size_factor=2" << "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.match_proba=0.8" << "\n";

    /// color space ? Which one ?
    cout << "Do you want to use a particular color space ? (y or n)" <<"\n";
    //cin >> c;
    c= argv[idx];
    cout << c << endl;
    idx++;

    if (c == "y")
    {
        idx = write_use_color_space(f,argv,idx);
    }
    else
    {
        write_not_use_color_space(f);
    }

    f << "Recognition.TemplateMatching.DistanceMatching.Absolute_diff=0" << "\n";
    f << "Recognition.TemplateMatching.DistanceMatching.MSE=0" << "\n";
    f << "Recognition.TemplateMatching.DistanceMatching.MAE=0" << "\n";
    f << "Recognition.TemplateMatching.DistanceMatching.max_distance=1200" << "\n";

    f << "Recognition.TemplateMatching.FeatureMatching.Sift=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Surf=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Brief=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Brisk=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Freak=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Sift.nfeatures=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Sift.n_octave_layers=3"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Sift.contrast_threshold=0.04"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Sift.edge_threshold=10"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Sift.sigma=1.6"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Surf.hessian_threshold=400.0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Surf.n_octaves=4"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Surf.n_octave_layers=2"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Surf.extended=1"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Surf.upright=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Brief.bytes=32"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Brief.use_orientation=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.nfeatures=500"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.scale_factor=1.2"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.nlevels=8"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.edge_threshold=31"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.first_level=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.wta_k=2"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.score_type=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.patch_size=31"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.fast_threshold=20"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Brisk.thresh=30"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Brisk.octaves=3"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Brisk.pattern_scale=1.0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Freak.orientation_normalized=1"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Freak.scale_normalized=1"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Freak.pattern_scale=22.0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Freak.n_octaves=4"<< "\n";

    f << "Recognition.TemplateMatching.HistogramMatching.numberOfBins=50"<< "\n";
    f << "Recognition.TemplateMatching.HistogramMatching.Threshold=0.8" << "\n";

    f << "Recognition.DistanceMeasure=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance=0"<< "\n";
    f << "Recognition.DistanceMeasure.PixelWiseDistance=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.Correl=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.ChiSquare=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.ChiSquareAlt=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.Intersection=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.KLDivergence=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.Hellinger=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.Bhattacharyya=0"<< "\n";

    return idx;
}

/**
* a function called to write the feature matching module
* users have decided to use feature matching as a recognition module they also decided to give defaut values for each parameters
* parameters will be written for all the recognition module (except for the common parts) : one activated, the others will not be
*
* the feature matching should not take care of the color space thus we do not ask for changing color space of images
*
* input :
*   - fstream& f : a file stream representing the output file
*
* output :
*   - recognition module should be written in the output file (assumed that it has been closed to flush the buffer)
*/
void write_use_feature_matching(fstream& f)
{

    f << "Recognition.TemplateMatching=1"<< "\n";
    f << "Recognition.TemplateMatching.TemplateMatching=0"<< "\n";
    f << "Recognition.TemplateMatching.HistogramMatching=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching=1"<< "\n";
    f << "Recognition.TemplateMatching.DistanceMatching=0"<< "\n";
    f << "Recognition.Pyramidal=0"<< "\n";
    f << "Recognition.Pyramidal.BMPyramidal=0"<< "\n";
    f << "Recognition.Pyramidal.CascadeClassifier=0"<< "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccoeff=0"<< "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccoeff_morned=0"<< "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_sqdiff=0"<< "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_sqdiff_normed=0"<< "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccorr=0"<< "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccorr_normed=0"<< "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.nb_layers=0" << "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.size_factor=2" << "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.match_proba=0.8" << "\n";
    f << "Recognition.TemplateMatching.DistanceMatching.Absolute_diff=0" << "\n";
    f << "Recognition.TemplateMatching.DistanceMatching.MSE=0" << "\n";
    f << "Recognition.TemplateMatching.DistanceMatching.MAE=0" << "\n";
    f << "Recognition.TemplateMatching.DistanceMatching.max_distance=1200" << "\n";

    write_not_use_color_space(f);

    ///which descriptor technique to use ?
    cout << "Which feature descriptors do you want to use ? (1: SIFT; 2: SURF; 3: BRIEF; 4: ORB; 5: BRISK; 6: FREAK)" << "\n";
    string c;
    cin >> c;

    while(c != "1" && c != "2" && c != "3" && c != "4" && c != "5" && c != "6")
    {
        cout << "Which feature descriptors do you want to use ? (1: SIFT; 2: SURF; 3: BRIEF; 4: ORB; 5: BRISK; 6: FREAK)" << "\n";
        cin >> c;
    }

    ///write parameters according to choices
    switch(atoi(c.c_str()))
    {
        case 1 : // SIFT
        {
            f << "Recognition.TemplateMatching.FeatureMatching.Sift=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brief=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.nfeatures=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.n_octave_layers=3"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.contrast_threshold=0.04"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.edge_threshold=10"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.sigma=1.6"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.hessian_threshold=400.0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.n_octaves=4"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.n_octave_layers=2"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.extended=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.upright=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brief.bytes=32"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brief.use_orientation=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.nfeatures=500"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.scale_factor=1.2"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.nlevels=8"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.edge_threshold=31"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.first_level=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.wta_k=2"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.score_type=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.patch_size=31"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.fast_threshold=20"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk.thresh=30"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk.octaves=3"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk.pattern_scale=1.0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.orientation_normalized=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.scale_normalized=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.pattern_scale=22.0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.n_octaves=4"<< "\n";
            break;
        }

        case 2 : // SURF
        {
            f << "Recognition.TemplateMatching.FeatureMatching.Sift=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brief=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.nfeatures=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.n_octave_layers=3"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.contrast_threshold=0.04"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.edge_threshold=10"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.sigma=1.6"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.hessian_threshold=400.0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.n_octaves=4"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.n_octave_layers=2"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.extended=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.upright=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brief.bytes=32"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brief.use_orientation=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.nfeatures=500"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.scale_factor=1.2"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.nlevels=8"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.edge_threshold=31"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.first_level=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.wta_k=2"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.score_type=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.patch_size=31"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.fast_threshold=20"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk.thresh=30"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk.octaves=3"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk.pattern_scale=1.0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.orientation_normalized=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.scale_normalized=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.pattern_scale=22.0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.n_octaves=4"<< "\n";
            break;
        }

        case 3 : // BRIEF
        {
            f << "Recognition.TemplateMatching.FeatureMatching.Sift=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brief=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.nfeatures=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.n_octave_layers=3"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.contrast_threshold=0.04"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.edge_threshold=10"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.sigma=1.6"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.hessian_threshold=400.0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.n_octaves=4"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.n_octave_layers=2"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.extended=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.upright=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brief.bytes=32"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brief.use_orientation=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.nfeatures=500"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.scale_factor=1.2"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.nlevels=8"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.edge_threshold=31"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.first_level=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.wta_k=2"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.score_type=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.patch_size=31"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.fast_threshold=20"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk.thresh=30"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk.octaves=3"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk.pattern_scale=1.0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.orientation_normalized=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.scale_normalized=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.pattern_scale=22.0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.n_octaves=4"<< "\n";
            break;
        }

        case 4 : // ORB
        {
            f << "Recognition.TemplateMatching.FeatureMatching.Sift=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brief=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.nfeatures=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.n_octave_layers=3"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.contrast_threshold=0.04"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.edge_threshold=10"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.sigma=1.6"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.hessian_threshold=400.0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.n_octaves=4"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.n_octave_layers=2"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.extended=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.upright=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brief.bytes=32"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brief.use_orientation=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.nfeatures=500"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.scale_factor=1.2"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.nlevels=8"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.edge_threshold=31"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.first_level=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.wta_k=2"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.score_type=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.patch_size=31"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.fast_threshold=20"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk.thresh=30"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk.octaves=3"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk.pattern_scale=1.0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.orientation_normalized=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.scale_normalized=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.pattern_scale=22.0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.n_octaves=4"<< "\n";
            break;
        }

        case 5 : // BRISK
        {
            f << "Recognition.TemplateMatching.FeatureMatching.Sift=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brief=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.nfeatures=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.n_octave_layers=3"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.contrast_threshold=0.04"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.edge_threshold=10"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.sigma=1.6"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.hessian_threshold=400.0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.n_octaves=4"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.n_octave_layers=2"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.extended=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.upright=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brief.bytes=32"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brief.use_orientation=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.nfeatures=500"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.scale_factor=1.2"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.nlevels=8"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.edge_threshold=31"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.first_level=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.wta_k=2"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.score_type=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.patch_size=31"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.fast_threshold=20"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk.thresh=30"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk.octaves=3"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk.pattern_scale=1.0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.orientation_normalized=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.scale_normalized=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.pattern_scale=22.0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.n_octaves=4"<< "\n";
            break;
        }

        case 6 : // FREAK
        {
            f << "Recognition.TemplateMatching.FeatureMatching.Sift=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brief=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.nfeatures=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.n_octave_layers=3"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.contrast_threshold=0.04"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.edge_threshold=10"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.sigma=1.6"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.hessian_threshold=400.0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.n_octaves=4"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.n_octave_layers=2"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.extended=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.upright=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brief.bytes=32"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brief.use_orientation=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.nfeatures=500"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.scale_factor=1.2"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.nlevels=8"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.edge_threshold=31"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.first_level=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.wta_k=2"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.score_type=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.patch_size=31"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.fast_threshold=20"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk.thresh=30"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk.octaves=3"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk.pattern_scale=1.0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.orientation_normalized=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.scale_normalized=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.pattern_scale=22.0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.n_octaves=4"<< "\n";
            break;
        }
    }
    f << "Recognition.TemplateMatching.HistogramMatching.numberOfBins=50"<< "\n";
    f << "Recognition.TemplateMatching.HistogramMatching.Threshold=0.8" << "\n";

    f << "Recognition.DistanceMeasure=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance=0"<< "\n";
    f << "Recognition.DistanceMeasure.PixelWiseDistance=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.Correl=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.ChiSquare=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.ChiSquareAlt=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.Intersection=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.KLDivergence=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.Hellinger=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.Bhattacharyya=0"<< "\n";
}

/**
* a function called to write the feature matching module
* users have decided to use feature matching as a recognition module they also decided to give defaut values for each parameters
* parameters will be written for all the recognition module (except for the common parts) : one activated, the others will not be
*
* the feature matching should not take care of the color space thus we do not ask for changing color space of images
*
* input :
*   - fstream& f : a file stream representing the output file
*   - char** argv : the list of arguments given to the program when it has been called
*   - int idx : the next index of argument to retrieve
*
* output :
*   - recognition module should be written in the output file (assumed that it has been closed to flush the buffer)
*   - int : the next index of argument to retrieve
*/
int write_use_feature_matching(fstream& f, char** argv, int idx)
{

    f << "Recognition.TemplateMatching=1"<< "\n";
    f << "Recognition.TemplateMatching.TemplateMatching=0"<< "\n";
    f << "Recognition.TemplateMatching.HistogramMatching=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching=1"<< "\n";
    f << "Recognition.TemplateMatching.DistanceMatching=0"<< "\n";
    f << "Recognition.Pyramidal=0"<< "\n";
    f << "Recognition.Pyramidal.BMPyramidal=0"<< "\n";
    f << "Recognition.Pyramidal.CascadeClassifier=0"<< "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccoeff=0"<< "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccoeff_morned=0"<< "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_sqdiff=0"<< "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_sqdiff_normed=0"<< "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccorr=0"<< "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccorr_normed=0"<< "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.nb_layers=0" << "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.size_factor=2" << "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.match_proba=0.8" << "\n";
    f << "Recognition.TemplateMatching.DistanceMatching.Absolute_diff=0" << "\n";
    f << "Recognition.TemplateMatching.DistanceMatching.MSE=0" << "\n";
    f << "Recognition.TemplateMatching.DistanceMatching.MAE=0" << "\n";
    f << "Recognition.TemplateMatching.DistanceMatching.max_distance=1200" << "\n";

    write_not_use_color_space(f);

    ///which descriptor technique to use ?
    cout << "Which feature descriptors do you want to use ? (1: SIFT; 2: SURF; 3: BRIEF; 4: ORB; 5: BRISK; 6: FREAK)" << "\n";
    string c(argv[idx]);
    cout << c << endl;
    //cin >> c;
    idx++;

    while(c != "1" && c != "2" && c != "3" && c != "4" && c != "5" && c != "6")
    {
        cout << "Which feature descriptors do you want to use ? (1: SIFT; 2: SURF; 3: BRIEF; 4: ORB; 5: BRISK; 6: FREAK)" << "\n";
        cin >> c;
    }

    ///write parameters according to choices
    switch(atoi(c.c_str()))
    {
        case 1 : // SIFT
        {
            f << "Recognition.TemplateMatching.FeatureMatching.Sift=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brief=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.nfeatures=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.n_octave_layers=3"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.contrast_threshold=0.04"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.edge_threshold=10"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.sigma=1.6"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.hessian_threshold=400.0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.n_octaves=4"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.n_octave_layers=2"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.extended=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.upright=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brief.bytes=32"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brief.use_orientation=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.nfeatures=500"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.scale_factor=1.2"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.nlevels=8"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.edge_threshold=31"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.first_level=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.wta_k=2"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.score_type=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.patch_size=31"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.fast_threshold=20"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk.thresh=30"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk.octaves=3"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk.pattern_scale=1.0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.orientation_normalized=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.scale_normalized=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.pattern_scale=22.0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.n_octaves=4"<< "\n";
            break;
        }

        case 2 : // SURF
        {
            f << "Recognition.TemplateMatching.FeatureMatching.Sift=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brief=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.nfeatures=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.n_octave_layers=3"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.contrast_threshold=0.04"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.edge_threshold=10"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.sigma=1.6"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.hessian_threshold=400.0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.n_octaves=4"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.n_octave_layers=2"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.extended=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.upright=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brief.bytes=32"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brief.use_orientation=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.nfeatures=500"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.scale_factor=1.2"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.nlevels=8"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.edge_threshold=31"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.first_level=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.wta_k=2"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.score_type=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.patch_size=31"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.fast_threshold=20"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk.thresh=30"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk.octaves=3"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk.pattern_scale=1.0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.orientation_normalized=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.scale_normalized=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.pattern_scale=22.0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.n_octaves=4"<< "\n";
            break;
        }

        case 3 : // BRIEF
        {
            f << "Recognition.TemplateMatching.FeatureMatching.Sift=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brief=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.nfeatures=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.n_octave_layers=3"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.contrast_threshold=0.04"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.edge_threshold=10"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.sigma=1.6"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.hessian_threshold=400.0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.n_octaves=4"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.n_octave_layers=2"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.extended=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.upright=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brief.bytes=32"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brief.use_orientation=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.nfeatures=500"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.scale_factor=1.2"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.nlevels=8"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.edge_threshold=31"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.first_level=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.wta_k=2"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.score_type=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.patch_size=31"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.fast_threshold=20"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk.thresh=30"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk.octaves=3"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk.pattern_scale=1.0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.orientation_normalized=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.scale_normalized=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.pattern_scale=22.0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.n_octaves=4"<< "\n";
            break;
        }

        case 4 : // ORB
        {
            f << "Recognition.TemplateMatching.FeatureMatching.Sift=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brief=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.nfeatures=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.n_octave_layers=3"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.contrast_threshold=0.04"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.edge_threshold=10"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.sigma=1.6"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.hessian_threshold=400.0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.n_octaves=4"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.n_octave_layers=2"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.extended=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.upright=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brief.bytes=32"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brief.use_orientation=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.nfeatures=500"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.scale_factor=1.2"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.nlevels=8"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.edge_threshold=31"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.first_level=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.wta_k=2"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.score_type=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.patch_size=31"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.fast_threshold=20"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk.thresh=30"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk.octaves=3"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk.pattern_scale=1.0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.orientation_normalized=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.scale_normalized=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.pattern_scale=22.0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.n_octaves=4"<< "\n";
            break;
        }

        case 5 : // BRISK
        {
            f << "Recognition.TemplateMatching.FeatureMatching.Sift=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brief=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.nfeatures=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.n_octave_layers=3"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.contrast_threshold=0.04"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.edge_threshold=10"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.sigma=1.6"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.hessian_threshold=400.0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.n_octaves=4"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.n_octave_layers=2"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.extended=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.upright=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brief.bytes=32"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brief.use_orientation=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.nfeatures=500"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.scale_factor=1.2"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.nlevels=8"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.edge_threshold=31"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.first_level=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.wta_k=2"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.score_type=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.patch_size=31"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.fast_threshold=20"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk.thresh=30"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk.octaves=3"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk.pattern_scale=1.0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.orientation_normalized=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.scale_normalized=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.pattern_scale=22.0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.n_octaves=4"<< "\n";
            break;
        }

        case 6 : // FREAK
        {
            f << "Recognition.TemplateMatching.FeatureMatching.Sift=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brief=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.nfeatures=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.n_octave_layers=3"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.contrast_threshold=0.04"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.edge_threshold=10"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.sigma=1.6"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.hessian_threshold=400.0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.n_octaves=4"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.n_octave_layers=2"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.extended=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.upright=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brief.bytes=32"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brief.use_orientation=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.nfeatures=500"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.scale_factor=1.2"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.nlevels=8"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.edge_threshold=31"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.first_level=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.wta_k=2"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.score_type=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.patch_size=31"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.fast_threshold=20"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk.thresh=30"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk.octaves=3"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk.pattern_scale=1.0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.orientation_normalized=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.scale_normalized=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.pattern_scale=22.0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.n_octaves=4"<< "\n";
            break;
        }
    }
    f << "Recognition.TemplateMatching.HistogramMatching.numberOfBins=50"<< "\n";
    f << "Recognition.TemplateMatching.HistogramMatching.Threshold=0.8" << "\n";

    f << "Recognition.DistanceMeasure=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance=0"<< "\n";
    f << "Recognition.DistanceMeasure.PixelWiseDistance=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.Correl=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.ChiSquare=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.ChiSquareAlt=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.Intersection=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.KLDivergence=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.Hellinger=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.Bhattacharyya=0"<< "\n";

    return idx;
}

/**
* a function called to write the histogram matching module
* users have decided to use histogram matching as a recognition module they also decided to give defaut values for each parameters
* parameters will be written for all the recognition module (except for the common parts) : one activated, the others will not be
*
* Histogram are really dependent of the color space
*
* input :
*   - fstream& f : a file stream representing the output file
*
* output :
*   - recognition module should be written in the output file (assumed that it has been closed to flush the buffer)
*/
void write_use_histogram_matching(fstream& f)
{
    f << "Recognition.TemplateMatching=1"<< "\n";
    f << "Recognition.TemplateMatching.TemplateMatching=0"<< "\n";
    f << "Recognition.TemplateMatching.HistogramMatching=1"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching=0"<< "\n";
    f << "Recognition.TemplateMatching.DistanceMatching=0"<< "\n";
    f << "Recognition.Pyramidal=0"<< "\n";
    f << "Recognition.Pyramidal.BMPyramidal=0"<< "\n";
    f << "Recognition.Pyramidal.CascadeClassifier=0"<< "\n";

    f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccoeff=0"<< "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccoeff_morned=0"<< "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_sqdiff=0"<< "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_sqdiff_normed=0"<< "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccorr=0"<< "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccorr_normed=0"<< "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.nb_layers=0" << "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.size_factor=2" << "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.match_proba=0.8" << "\n";
    f << "Recognition.TemplateMatching.DistanceMatching.Absolute_diff=0" << "\n";
    f << "Recognition.TemplateMatching.DistanceMatching.MSE=0" << "\n";
    f << "Recognition.TemplateMatching.DistanceMatching.MAE=0" << "\n";
    f << "Recognition.TemplateMatching.DistanceMatching.max_distance=1200" << "\n";

    ///use specific color space ? Which one ?
    cout << "Do you want to use a particular color space ? (y or n)" <<"\n";
    string c;
    cin >> c;
    if (c == "y")
    {
        write_use_color_space(f);
    }
    else
    {
        write_not_use_color_space(f);
    }
    f << "Recognition.TemplateMatching.FeatureMatching.Sift=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Surf=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Brief=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Brisk=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Freak=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Sift.nfeatures=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Sift.n_octave_layers=3"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Sift.contrast_threshold=0.04"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Sift.edge_threshold=10"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Sift.sigma=1.6"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Surf.hessian_threshold=400.0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Surf.n_octaves=4"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Surf.n_octave_layers=2"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Surf.extended=1"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Surf.upright=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Brief.bytes=32"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Brief.use_orientation=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.nfeatures=500"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.scale_factor=1.2"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.nlevels=8"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.edge_threshold=31"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.first_level=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.wta_k=2"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.score_type=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.patch_size=31"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.fast_threshold=20"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Brisk.thresh=30"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Brisk.octaves=3"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Brisk.pattern_scale=1.0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Freak.orientation_normalized=1"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Freak.scale_normalized=1"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Freak.pattern_scale=22.0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Freak.n_octaves=4"<< "\n";

    f << "Recognition.TemplateMatching.HistogramMatching.numberOfBins=50"<< "\n";
    f << "Recognition.TemplateMatching.HistogramMatching.Threshold=0.8" << "\n";

    f << "Recognition.DistanceMeasure=1"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance=1"<< "\n";
    f << "Recognition.DistanceMeasure.PixelWiseDistance=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.Correl=1"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.ChiSquare=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.ChiSquareAlt=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.Intersection=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.KLDivergence=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.Hellinger=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.Bhattacharyya=0"<< "\n";

}

/**
* a function called to write the histogram matching module
* users have decided to use histogram matching as a recognition module they also decided to give defaut values for each parameters
* parameters will be written for all the recognition module (except for the common parts) : one activated, the others will not be
*
* the histogram matching is really dependent on the color space that is used
*
* input :
*   - fstream& f : a file stream representing the output file
*   - char** argv : the list of arguments given to the program when it was called
*   - int idx : the index of the next argument to retrieve
*
* output :
*   - recognition module should be written in the output file (assumed that it has been closed to flush the buffer)
*   - int : the index of the next argument to retrieve
*/
int write_use_histogram_matching(fstream& f, char** argv, int idx)
{
    f << "Recognition.TemplateMatching=1"<< "\n";
    f << "Recognition.TemplateMatching.TemplateMatching=0"<< "\n";
    f << "Recognition.TemplateMatching.HistogramMatching=1"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching=0"<< "\n";
    f << "Recognition.TemplateMatching.DistanceMatching=0"<< "\n";
    f << "Recognition.Pyramidal=0"<< "\n";
    f << "Recognition.Pyramidal.BMPyramidal=0"<< "\n";
    f << "Recognition.Pyramidal.CascadeClassifier=0"<< "\n";

    f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccoeff=0"<< "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccoeff_morned=0"<< "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_sqdiff=0"<< "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_sqdiff_normed=0"<< "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccorr=0"<< "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccorr_normed=0"<< "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.nb_layers=0" << "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.size_factor=2" << "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.match_proba=0.8" << "\n";
    f << "Recognition.TemplateMatching.DistanceMatching.Absolute_diff=0" << "\n";
    f << "Recognition.TemplateMatching.DistanceMatching.MSE=0" << "\n";
    f << "Recognition.TemplateMatching.DistanceMatching.MAE=0" << "\n";
    f << "Recognition.TemplateMatching.DistanceMatching.max_distance=1200" << "\n";

    ///use specific color space ? Which one ?
    cout << "Do you want to use a particular color space ? (y or n)" <<"\n";
    string c(argv[idx]);
    //cin >> c;
    cout << c << endl;
    idx++;

    if (c == "y")
    {
        idx = write_use_color_space(f,argv,idx);
    }
    else
    {
        write_not_use_color_space(f);
    }
    f << "Recognition.TemplateMatching.FeatureMatching.Sift=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Surf=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Brief=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Brisk=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Freak=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Sift.nfeatures=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Sift.n_octave_layers=3"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Sift.contrast_threshold=0.04"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Sift.edge_threshold=10"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Sift.sigma=1.6"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Surf.hessian_threshold=400.0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Surf.n_octaves=4"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Surf.n_octave_layers=2"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Surf.extended=1"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Surf.upright=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Brief.bytes=32"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Brief.use_orientation=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.nfeatures=500"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.scale_factor=1.2"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.nlevels=8"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.edge_threshold=31"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.first_level=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.wta_k=2"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.score_type=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.patch_size=31"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.fast_threshold=20"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Brisk.thresh=30"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Brisk.octaves=3"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Brisk.pattern_scale=1.0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Freak.orientation_normalized=1"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Freak.scale_normalized=1"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Freak.pattern_scale=22.0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Freak.n_octaves=4"<< "\n";

    f << "Recognition.TemplateMatching.HistogramMatching.numberOfBins=50"<< "\n";
    f << "Recognition.TemplateMatching.HistogramMatching.Threshold=0.8" << "\n";

    f << "Recognition.DistanceMeasure=1"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance=1"<< "\n";
    f << "Recognition.DistanceMeasure.PixelWiseDistance=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.Correl=1"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.ChiSquare=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.ChiSquareAlt=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.Intersection=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.KLDivergence=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.Hellinger=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.Bhattacharyya=0"<< "\n";

    return idx;
}

/**
* a function called to write the distance matching module
* users have decided to use distance matching as a recognition module they also decided to give defaut values for each parameters
* parameters will be written for all the recognition module (except for the common parts) : one activated, the others will not be
*
* the distance computation is really dependent on the color space that is used
*
* input :
*   - fstream& f : a file stream representing the output file
*
* output :
*   - recognition module should be written in the output file (assumed that it has been closed to flush the buffer)
*/
void write_use_distance_matching(fstream& f)
{
    f << "Recognition.TemplateMatching=1"<< "\n";
    f << "Recognition.TemplateMatching.TemplateMatching=0"<< "\n";
    f << "Recognition.TemplateMatching.HistogramMatching=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching=0"<< "\n";
    f << "Recognition.TemplateMatching.DistanceMatching=1"<< "\n";
    f << "Recognition.Pyramidal=0"<< "\n";
    f << "Recognition.Pyramidal.BMPyramidal=0"<< "\n";
    f << "Recognition.Pyramidal.CascadeClassifier=0"<< "\n";

    f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccoeff=0"<< "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccoeff_morned=0"<< "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_sqdiff=0"<< "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_sqdiff_normed=0"<< "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccorr=0"<< "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccorr_normed=0"<< "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.nb_layers=0" << "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.size_factor=2" << "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.match_proba=0.8" << "\n";
    f << "Recognition.TemplateMatching.DistanceMatching.Absolute_diff=0" << "\n";
    f << "Recognition.TemplateMatching.DistanceMatching.MSE=1" << "\n";
    f << "Recognition.TemplateMatching.DistanceMatching.MAE=0" << "\n";
    f << "Recognition.TemplateMatching.DistanceMatching.max_distance=1200" << "\n";

    ///use a particular color space ? Which one ?
    cout << "Do you want to use a particular color space ? (y or n)" <<"\n";
    string c;
    cin >> c;
    if (c == "y")
    {
        write_use_color_space(f);
    }
    else
    {
        write_not_use_color_space(f);
    }
    f << "Recognition.TemplateMatching.FeatureMatching.Sift=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Surf=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Brief=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Brisk=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Freak=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Sift.nfeatures=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Sift.n_octave_layers=3"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Sift.contrast_threshold=0.04"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Sift.edge_threshold=10"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Sift.sigma=1.6"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Surf.hessian_threshold=400.0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Surf.n_octaves=4"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Surf.n_octave_layers=2"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Surf.extended=1"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Surf.upright=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Brief.bytes=32"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Brief.use_orientation=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.nfeatures=500"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.scale_factor=1.2"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.nlevels=8"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.edge_threshold=31"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.first_level=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.wta_k=2"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.score_type=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.patch_size=31"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.fast_threshold=20"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Brisk.thresh=30"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Brisk.octaves=3"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Brisk.pattern_scale=1.0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Freak.orientation_normalized=1"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Freak.scale_normalized=1"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Freak.pattern_scale=22.0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Freak.n_octaves=4"<< "\n";

    f << "Recognition.TemplateMatching.HistogramMatching.numberOfBins=50"<< "\n";
    f << "Recognition.TemplateMatching.HistogramMatching.Threshold=0.8" << "\n";

    f << "Recognition.DistanceMeasure=1"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance=0"<< "\n";
    f << "Recognition.DistanceMeasure.PixelWiseDistance=1"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.Correl=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.ChiSquare=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.ChiSquareAlt=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.Intersection=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.KLDivergence=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.Hellinger=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.Bhattacharyya=0"<< "\n";
}

/**
* a function called to write the distance matching module
* users have decided to use distance matching as a recognition module they also decided to give defaut values for each parameters
* parameters will be written for all the recognition module (except for the common parts) : one activated, the others will not be
*
* the distance measure is really dependent of the color space which is used
*
* input :
*   - fstream& f : a file stream representing the output file
*   - char** argv : the list of arguments that has been given to the program when it was called
*   - int idx : the index of the next argument to retrieve
*
* output :
*   - recognition module should be written in the output file (assumed that it has been closed to flush the buffer)
*   - int : the index of the next argument to retrieve
*/
int write_use_distance_matching(fstream& f, char** argv, int idx)
{
    f << "Recognition.TemplateMatching=1"<< "\n";
    f << "Recognition.TemplateMatching.TemplateMatching=0"<< "\n";
    f << "Recognition.TemplateMatching.HistogramMatching=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching=0"<< "\n";
    f << "Recognition.TemplateMatching.DistanceMatching=1"<< "\n";
    f << "Recognition.Pyramidal=0"<< "\n";
    f << "Recognition.Pyramidal.BMPyramidal=0"<< "\n";
    f << "Recognition.Pyramidal.CascadeClassifier=0"<< "\n";

    f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccoeff=0"<< "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccoeff_morned=0"<< "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_sqdiff=0"<< "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_sqdiff_normed=0"<< "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccorr=0"<< "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccorr_normed=0"<< "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.nb_layers=0" << "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.size_factor=2" << "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.match_proba=0.8" << "\n";
    f << "Recognition.TemplateMatching.DistanceMatching.Absolute_diff=0" << "\n";
    f << "Recognition.TemplateMatching.DistanceMatching.MSE=1" << "\n";
    f << "Recognition.TemplateMatching.DistanceMatching.MAE=0" << "\n";
    f << "Recognition.TemplateMatching.DistanceMatching.max_distance=1200" << "\n";

    ///use a particular color space ? Which one ?
    cout << "Do you want to use a particular color space ? (y or n)" <<"\n";
    string c(argv[idx]);
    //cin >> c;
    cout << c << endl;
    idx++;

    if (c == "y")
    {
        idx = write_use_color_space(f,argv,idx);
    }
    else
    {
        write_not_use_color_space(f);
    }
    f << "Recognition.TemplateMatching.FeatureMatching.Sift=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Surf=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Brief=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Brisk=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Freak=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Sift.nfeatures=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Sift.n_octave_layers=3"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Sift.contrast_threshold=0.04"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Sift.edge_threshold=10"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Sift.sigma=1.6"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Surf.hessian_threshold=400.0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Surf.n_octaves=4"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Surf.n_octave_layers=2"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Surf.extended=1"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Surf.upright=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Brief.bytes=32"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Brief.use_orientation=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.nfeatures=500"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.scale_factor=1.2"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.nlevels=8"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.edge_threshold=31"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.first_level=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.wta_k=2"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.score_type=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.patch_size=31"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.fast_threshold=20"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Brisk.thresh=30"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Brisk.octaves=3"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Brisk.pattern_scale=1.0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Freak.orientation_normalized=1"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Freak.scale_normalized=1"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Freak.pattern_scale=22.0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Freak.n_octaves=4"<< "\n";

    f << "Recognition.TemplateMatching.HistogramMatching.numberOfBins=50"<< "\n";
    f << "Recognition.TemplateMatching.HistogramMatching.Threshold=0.8" << "\n";

    f << "Recognition.DistanceMeasure=1"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance=0"<< "\n";
    f << "Recognition.DistanceMeasure.PixelWiseDistance=1"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.Correl=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.ChiSquare=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.ChiSquareAlt=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.Intersection=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.KLDivergence=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.Hellinger=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.Bhattacharyya=0"<< "\n";

    return idx;
}

/**
* a function called in interactive mode which will write common part of the recognition module
* users has chosen which recognition method to use, call the function according to choices
* this function will write default values for the given choice -> other choices in the module will be deactivated
* input :
*   - fstream& f : a file stream representing the output file (avoid copy)
*   - int choice : the choice made regarding the method to be used
*
* output :
*   - something is written in the output file
*   - methods of the recognition module that are not used are deactivated
*/
void write_recognition_default(fstream& f, int choice)
{
    f << "Recognition=1"<< "\n";
    switch (choice)
    {
        case 1 : //use template matching
        {
            write_use_template_matching(f);
            break;
        }
        case 2 : //use feature matching
        {
            write_use_feature_matching(f);
        }

        case 3 : // use histogram matching
        {
            write_use_histogram_matching(f);
            break;
        }

        case 4 : //use distance matching
        {
            write_use_distance_matching(f);
            break;
        }

        case 5 : // use Pyramidal
        {
            f << "Recognition.TemplateMatching=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching=0"<< "\n";
            f << "Recognition.TemplateMatching.HistogramMatching=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching=0"<< "\n";
            f << "Recognition.TemplateMatching.DistanceMatching=0"<< "\n";
            f << "Recognition.Pyramidal=1"<< "\n";
            f << "Recognition.Pyramidal.BMPyramidal=0"<< "\n";
            f << "Recognition.Pyramidal.CascadeClassifier=0"<< "\n";
            break;
        }
    }
}

/**
* a function which will write common part of the recognition module
* users has chosen which recognition method to use, call the function according to choices
* this function will write default values for the given choice -> other choices in the module will be deactivated
* input :
*   - fstream& f : a file stream representing the output file (avoid copy)
*   - int choice : the choice made regarding the method to be used
*   - char** argv : the list of arguments given to the program when it has been called
*   - int idx : the index of the next argument to retrieve
*
* output :
*   - something is written in the output file
*   - methods of the recognition module that are not used are deactivated
*   - int : the index of the next argument to retrieve
*/
int write_recognition_default(fstream& f, int choice, char** argv, int idx)
{
    f << "Recognition=1"<< "\n";
    switch (choice)
    {
        case 1 : //use template matching
        {
            idx = write_use_template_matching(f,argv,idx);
            break;
        }
        case 2 : //use feature matching
        {
            idx = write_use_feature_matching(f,argv,idx);
            break;
        }

        case 3 : // use histogram matching
        {
            idx = write_use_histogram_matching(f, argv, idx);
            break;
        }

        case 4 : //use distance matching
        {
            idx = write_use_distance_matching(f, argv, idx);
            break;
        }

        case 5 : // use Pyramidal
        {
            f << "Recognition.TemplateMatching=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching=0"<< "\n";
            f << "Recognition.TemplateMatching.HistogramMatching=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching=0"<< "\n";
            f << "Recognition.TemplateMatching.DistanceMatching=0"<< "\n";
            f << "Recognition.Pyramidal=1"<< "\n";
            f << "Recognition.Pyramidal.BMPyramidal=0"<< "\n";
            f << "Recognition.Pyramidal.CascadeClassifier=0"<< "\n";
            break;
        }
    }
    return idx;
}

/**
* a function called in interactive mode to write the template matching module
* users have decided to use template matching as a recognition module they also decided to give random values for each parameters
* parameters will be wrote for all the recognition module (except for the common parts) : one activated, the others will not be
* random values are generated following an approximation of a Gaussian distribution which uses uniformly distributed values
*
* input :
*   - fstream& f : a file stream representing the output file
*
* output :
*   - recognition module should be written in the output file (assumed that it has been closed to flush the buffer)
*/
void write_use_template_matching_rand(fstream& f)
{
    f << "Recognition.TemplateMatching=1"<< "\n";
    f << "Recognition.TemplateMatching.TemplateMatching=1"<< "\n";
    f << "Recognition.TemplateMatching.HistogramMatching=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching=0"<< "\n";
    f << "Recognition.TemplateMatching.DistanceMatching=0"<<"\n";
    f << "Recognition.Pyramidal=0"<< "\n";
    f << "Recognition.Pyramidal.BMPyramidal=0"<< "\n";
    f << "Recognition.Pyramidal.CascadeClassifier=0"<< "\n";

    ///which distance to use ?
    cout << "Which distance method do you want to use ? (1 : tm_coeff; 2 : tm_coeff_normalized; 3 : tm_sqdiff; 4 : tm_sqdiff_normalized; 5 : tm_ccorr ; 6 : tm_corr_normalized)" << "\n";
    string c;
    cin >> c;
    while( c != "1" && c != "2" && c != "3" && c != "4" && c != "5" && c != "6")
    {
        cout << "Which distance method do you want to use ? (1 : tm_coeff; 2 : tm_coeff_normalized; 3 : tm_sqdiff; 4 : tm_sqdiff_normalized; 5 : tm_ccorr ; 6 : tm_corr_normalized)" << "\n";
        cin >> c;
    }

    ///write parameters according to choices
    switch (atoi(c.c_str()))
    {
        case 1 :
        {
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccoeff=1"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccoeff_morned=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_sqdiff=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_sqdiff_normed=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccorr=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccorr_normed=0"<< "\n";
            break;
        }
        case 2 :
        {
           f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccoeff=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccoeff_morned=1"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_sqdiff=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_sqdiff_normed=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccorr=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccorr_normed=0"<< "\n";
            break;
        }
        case 3 :
        {
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccoeff=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccoeff_morned=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_sqdiff=1"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_sqdiff_normed=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccorr=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccorr_normed=0"<< "\n";
            break;
        }
        case 4 :
        {
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccoeff=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccoeff_norned=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_sqdiff=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_sqdiff_normed=1"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccorr=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccorr_normed=0"<< "\n";
            break;
        }
        case 5 :
        {
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccoeff=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccoeff_morned=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_sqdiff=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_sqdiff_normed=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccorr=1"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccorr_normed=0"<< "\n";
            break;
        }
        case 6 :
        {
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccoeff=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccoeff_morned=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_sqdiff=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_sqdiff_normed=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccorr=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccorr_normed=1"<< "\n";
            break;
        }
    }

    f << "Recognition.TemplateMatching.TemplateMatching.nb_layers=0" << "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.size_factor=" << (((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX)+ ((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX) ) /4 * 10 + 2 << "\n"; // between 2 and 12 -> mean around 7
    f << "Recognition.TemplateMatching.TemplateMatching.match_proba=" << (((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX)+ ((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX) ) /4 << "\n"; // between 0 and 1 -> mean around 0.5

    ///use a particular color space ? Which one ?
    cout << "Do you want to use a particular color space ? (y or n)" <<"\n";
    cin >> c;
    if (c == "y")
    {
        write_use_color_space(f);
    }
    else
    {
        write_not_use_color_space(f);
    }

    f << "Recognition.TemplateMatching.DistanceMatching.Absolute_diff=0" << "\n";
    f << "Recognition.TemplateMatching.DistanceMatching.MSE=0" << "\n";
    f << "Recognition.TemplateMatching.DistanceMatching.MAE=0" << "\n";
    f << "Recognition.TemplateMatching.DistanceMatching.max_distance=1200" << "\n";

    f << "Recognition.TemplateMatching.FeatureMatching.Sift=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Surf=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Brief=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Brisk=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Freak=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Sift.nfeatures=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Sift.n_octave_layers=3"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Sift.contrast_threshold=0.04"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Sift.edge_threshold=10"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Sift.sigma=1.6"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Surf.hessian_threshold=400.0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Surf.n_octaves=4"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Surf.n_octave_layers=2"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Surf.extended=1"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Surf.upright=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Brief.bytes=32"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Brief.use_orientation=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.nfeatures=500"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.scale_factor=1.2"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.nlevels=8"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.edge_threshold=31"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.first_level=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.wta_k=2"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.score_type=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.patch_size=31"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.fast_threshold=20"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Brisk.thresh=30"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Brisk.octaves=3"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Brisk.pattern_scale=1.0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Freak.orientation_normalized=1"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Freak.scale_normalized=1"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Freak.pattern_scale=22.0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Freak.n_octaves=4"<< "\n";

    f << "Recognition.TemplateMatching.HistogramMatching.numberOfBins=50"<< "\n";
    f << "Recognition.TemplateMatching.HistogramMatching.Threshold=0.8" << "\n";

    f << "Recognition.DistanceMeasure=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance=0"<< "\n";
    f << "Recognition.DistanceMeasure.PixelWiseDistance=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.Correl=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.ChiSquare=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.ChiSquareAlt=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.Intersection=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.KLDivergence=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.Hellinger=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.Bhattacharyya=0"<< "\n";
}

/**
* a function called in interactive mode to write the template matching module
* users have decided to use template matching as a recognition module they also decided to give random values for each parameters
* parameters will be wrote for all the recognition module (except for the common parts) : one activated, the others will not be
* random values are generated following an approximation of a Gaussian distribution which uses uniformly distributed values
*
* input :
*   - fstream& f : a file stream representing the output file
*   - char** argv : the list of argument given to the program when it has been called
*   - int idx : the index of the next argument to retrieve
*
* output :
*   - recognition module should be written in the output file (assumed that it has been closed to flush the buffer)
*   - int : the index of the next argument to retrieve
*/
int write_use_template_matching_rand(fstream& f, char** argv, int idx)
{
    f << "Recognition.TemplateMatching=1"<< "\n";
    f << "Recognition.TemplateMatching.TemplateMatching=1"<< "\n";
    f << "Recognition.TemplateMatching.HistogramMatching=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching=0"<< "\n";
    f << "Recognition.TemplateMatching.DistanceMatching=0"<<"\n";
    f << "Recognition.Pyramidal=0"<< "\n";
    f << "Recognition.Pyramidal.BMPyramidal=0"<< "\n";
    f << "Recognition.Pyramidal.CascadeClassifier=0"<< "\n";

    ///which distance to use ?
    cout << "Which distance method do you want to use ? (1 : tm_coeff; 2 : tm_coeff_normalized; 3 : tm_sqdiff; 4 : tm_sqdiff_normalized; 5 : tm_ccorr ; 6 : tm_corr_normalized)" << "\n";
    string c(argv[idx]);
    //cin >> c;
    cout << c << endl;
    idx++;

    while( c != "1" && c != "2" && c != "3" && c != "4" && c != "5" && c != "6")
    {
        cout << "Which distance method do you want to use ? (1 : tm_coeff; 2 : tm_coeff_normalized; 3 : tm_sqdiff; 4 : tm_sqdiff_normalized; 5 : tm_ccorr ; 6 : tm_corr_normalized)" << "\n";
        cout << "Last index -> " << idx-1 << endl;
        cout << "Last argument -> " << argv[idx-1] << endl;

        for (int i=1; i<= idx; i++)
        {
            cout << argv[i] << "\t";
        }
        cout << endl;

        cin >> c;
    }
    ///write parameters according to choices
    switch (atoi(c.c_str()))
    {
        case 1 :
        {
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccoeff=1"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccoeff_morned=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_sqdiff=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_sqdiff_normed=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccorr=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccorr_normed=0"<< "\n";
            break;
        }
        case 2 :
        {
           f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccoeff=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccoeff_morned=1"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_sqdiff=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_sqdiff_normed=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccorr=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccorr_normed=0"<< "\n";
            break;
        }
        case 3 :
        {
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccoeff=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccoeff_morned=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_sqdiff=1"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_sqdiff_normed=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccorr=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccorr_normed=0"<< "\n";
            break;
        }
        case 4 :
        {
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccoeff=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccoeff_norned=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_sqdiff=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_sqdiff_normed=1"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccorr=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccorr_normed=0"<< "\n";
            break;
        }
        case 5 :
        {
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccoeff=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccoeff_morned=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_sqdiff=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_sqdiff_normed=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccorr=1"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccorr_normed=0"<< "\n";
            break;
        }
        case 6 :
        {
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccoeff=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccoeff_morned=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_sqdiff=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_sqdiff_normed=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccorr=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccorr_normed=1"<< "\n";
            break;
        }
    }

    f << "Recognition.TemplateMatching.TemplateMatching.nb_layers=0" << "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.size_factor=" << (((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX)+ ((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX) ) /4 * 10 + 2 << "\n"; // between 2 and 12 -> mean around 7
    f << "Recognition.TemplateMatching.TemplateMatching.match_proba=" << (((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX)+ ((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX) ) /4 << "\n"; // between 0 and 1 -> mean around 0.5

    /// use a particular color space ? Which one ?
    cout << "Do you want to use a particular color space ? (y or n)" <<"\n";
    //cin >> c;
    c= argv[idx];
    cout << c << endl;
    idx++;

    if (c == "y")
    {
        idx = write_use_color_space(f,argv,idx);
    }
    else
    {
        write_not_use_color_space(f);
    }

    f << "Recognition.TemplateMatching.DistanceMatching.Absolute_diff=0" << "\n";
    f << "Recognition.TemplateMatching.DistanceMatching.MSE=0" << "\n";
    f << "Recognition.TemplateMatching.DistanceMatching.MAE=0" << "\n";
    f << "Recognition.TemplateMatching.DistanceMatching.max_distance=1200" << "\n";

    f << "Recognition.TemplateMatching.FeatureMatching.Sift=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Surf=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Brief=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Brisk=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Freak=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Sift.nfeatures=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Sift.n_octave_layers=3"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Sift.contrast_threshold=0.04"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Sift.edge_threshold=10"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Sift.sigma=1.6"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Surf.hessian_threshold=400.0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Surf.n_octaves=4"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Surf.n_octave_layers=2"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Surf.extended=1"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Surf.upright=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Brief.bytes=32"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Brief.use_orientation=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.nfeatures=500"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.scale_factor=1.2"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.nlevels=8"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.edge_threshold=31"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.first_level=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.wta_k=2"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.score_type=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.patch_size=31"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.fast_threshold=20"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Brisk.thresh=30"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Brisk.octaves=3"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Brisk.pattern_scale=1.0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Freak.orientation_normalized=1"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Freak.scale_normalized=1"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Freak.pattern_scale=22.0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Freak.n_octaves=4"<< "\n";

    f << "Recognition.TemplateMatching.HistogramMatching.numberOfBins=50"<< "\n";
    f << "Recognition.TemplateMatching.HistogramMatching.Threshold=0.8" << "\n";

    f << "Recognition.DistanceMeasure=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance=0"<< "\n";
    f << "Recognition.DistanceMeasure.PixelWiseDistance=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.Correl=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.ChiSquare=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.ChiSquareAlt=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.Intersection=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.KLDivergence=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.Hellinger=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.Bhattacharyya=0"<< "\n";

    return idx;
}

/**
* a function called to write the feature matching module
* users have decided to use feature matching as a recognition module they also decided to give random values for each parameters
* parameters will be written for all the recognition module (except for the common parts) : one activated, the others will not be
*
* the feature matching should not take care of the color space thus we do not ask for changing color space of images
* random values are generated following an approximation of a Gaussian distribution using uniformly distributed values
*
* input :
*   - fstream& f : a file stream representing the output file
*
* output :
*   - recognition module should be written in the output file (assumed that it has been closed to flush the buffer)
*/
void write_use_feature_matching_rand(fstream& f)
{
    f << "Recognition.TemplateMatching=1"<< "\n";
    f << "Recognition.TemplateMatching.TemplateMatching=0"<< "\n";
    f << "Recognition.TemplateMatching.HistogramMatching=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching=1"<< "\n";
    f << "Recognition.TemplateMatching.DistanceMatching=0"<< "\n";
    f << "Recognition.Pyramidal=0"<< "\n";
    f << "Recognition.Pyramidal.BMPyramidal=0"<< "\n";
    f << "Recognition.Pyramidal.CascadeClassifier=0"<< "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccoeff=0"<< "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccoeff_morned=0"<< "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_sqdiff=0"<< "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_sqdiff_normed=0"<< "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccorr=0"<< "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccorr_normed=0"<< "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.nb_layers=0" << "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.size_factor=2" << "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.match_proba=0.8" << "\n";
    f << "Recognition.TemplateMatching.DistanceMatching.Absolute_diff=0" << "\n";
    f << "Recognition.TemplateMatching.DistanceMatching.MSE=0" << "\n";
    f << "Recognition.TemplateMatching.DistanceMatching.MAE=0" << "\n";
    f << "Recognition.TemplateMatching.DistanceMatching.max_distance=1200" << "\n";

    write_not_use_color_space(f);

    ///which descriptor technique to use ?
    cout << "Which feature descriptors do you want to use ? (1: SIFT; 2: SURF; 3: BRIEF; 4: ORB; 5: BRISK; 6: FREAK)" << "\n";
    string c;
    cin >> c;

    while(c != "1" && c != "2" && c != "3" && c != "4" && c != "5" && c != "6")
    {
        cout << "Which feature descriptors do you want to use ? (1: SIFT; 2: SURF; 3: BRIEF; 4: ORB; 5: BRISK; 6: FREAK)" << "\n";
        cin >> c;
    }

    switch(atoi(c.c_str()))
    {
        case 1 : // SIFT
        {
            f << "Recognition.TemplateMatching.FeatureMatching.Sift=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brief=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.nfeatures=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.n_octave_layers=3" << "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.contrast_threshold=" << (((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX)+ ((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX) ) /4<< "\n"; // between 0 and 1 -> mean around 0.5
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.edge_threshold=" << (((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX)+ ((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX) ) * 5 << "\n"; // between 0 and 20 -> mean around 10
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.sigma=1.6"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.hessian_threshold=400.0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.n_octaves=4"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.n_octave_layers=2"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.extended=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.upright=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brief.bytes=32"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brief.use_orientation=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.nfeatures=500"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.scale_factor=1.2"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.nlevels=8"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.edge_threshold=31"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.first_level=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.wta_k=2"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.score_type=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.patch_size=31"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.fast_threshold=20"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk.thresh=30"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk.octaves=3"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk.pattern_scale=1.0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.orientation_normalized=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.scale_normalized=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.pattern_scale=22.0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.n_octaves=4"<< "\n";
            break;
        }

        case 2 : // SURF
        {
            f << "Recognition.TemplateMatching.FeatureMatching.Sift=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brief=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.nfeatures=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.n_octave_layers=3"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.contrast_threshold=0.04"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.edge_threshold=10"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.sigma=1.6"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.hessian_threshold=" << ((((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX)+ ((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX) ) /4 * 400) << "\n"; // between 0 and 400 -> mean around 200
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.n_octaves=4"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.n_octave_layers=2"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.extended=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.upright=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brief.bytes=32"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brief.use_orientation=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.nfeatures=500"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.scale_factor=1.2"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.nlevels=8"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.edge_threshold=31"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.first_level=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.wta_k=2"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.score_type=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.patch_size=31"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.fast_threshold=20"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk.thresh=30"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk.octaves=3"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk.pattern_scale=1.0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.orientation_normalized=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.scale_normalized=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.pattern_scale=22.0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.n_octaves=4"<< "\n";
            break;
        }

        case 3 : // BRIEF
        {
            f << "Recognition.TemplateMatching.FeatureMatching.Sift=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brief=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.nfeatures=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.n_octave_layers=3"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.contrast_threshold=0.04"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.edge_threshold=10"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.sigma=1.6"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.hessian_threshold=400.0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.n_octaves=4"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.n_octave_layers=2"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.extended=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.upright=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brief.bytes=32"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brief.use_orientation=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.nfeatures=500"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.scale_factor=1.2"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.nlevels=8"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.edge_threshold=31"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.first_level=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.wta_k=2"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.score_type=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.patch_size=31"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.fast_threshold=20"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk.thresh=30"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk.octaves=3"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk.pattern_scale=1.0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.orientation_normalized=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.scale_normalized=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.pattern_scale=22.0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.n_octaves=4"<< "\n";
            break;
        }

        case 4 : // ORB
        {
            f << "Recognition.TemplateMatching.FeatureMatching.Sift=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brief=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.nfeatures=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.n_octave_layers=3"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.contrast_threshold=0.04"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.edge_threshold=10"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.sigma=1.6"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.hessian_threshold=400.0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.n_octaves=4"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.n_octave_layers=2"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.extended=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.upright=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brief.bytes=32"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brief.use_orientation=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.nfeatures=" << (((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX)+ ((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX) ) * 125 << "\n"; // between 0 and 500 -> mean around 250
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.scale_factor=" << ( (((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX)+ ((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX) )  / 4) +1 << "\n"; // between 1 and 2 -> mean around 1.5
            cout << "HEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEY" << endl <<( (((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX)+ ((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX) )  / 4) +1 << endl;
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.nlevels=8"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.edge_threshold=31"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.first_level=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.wta_k=" << (((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX)+ ((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX) ) /2 + 2<< "\n"; // between 2 and 4 -> mean around 3
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.score_type=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.patch_size=31"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.fast_threshold=20"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk.thresh=30"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk.octaves=3"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk.pattern_scale=1.0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.orientation_normalized=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.scale_normalized=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.pattern_scale=22.0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.n_octaves=4"<< "\n";
            break;
        }

        case 5 : // BRISK
        {
            f << "Recognition.TemplateMatching.FeatureMatching.Sift=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brief=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.nfeatures=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.n_octave_layers=3"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.contrast_threshold=0.04"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.edge_threshold=10"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.sigma=1.6"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.hessian_threshold=400.0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.n_octaves=4"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.n_octave_layers=2"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.extended=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.upright=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brief.bytes=32"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brief.use_orientation=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.nfeatures=500"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.scale_factor=1.2"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.nlevels=8"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.edge_threshold=31"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.first_level=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.wta_k=2"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.score_type=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.patch_size=31"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.fast_threshold=20"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk.thresh=30"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk.octaves=3"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk.pattern_scale=1.0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.orientation_normalized=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.scale_normalized=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.pattern_scale=22.0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.n_octaves=4"<< "\n";
            break;
        }

        case 6 : // FREAK
        {
            f << "Recognition.TemplateMatching.FeatureMatching.Sift=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brief=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.nfeatures=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.n_octave_layers=3"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.contrast_threshold=0.04"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.edge_threshold=10"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.sigma=1.6"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.hessian_threshold=400.0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.n_octaves=4"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.n_octave_layers=2"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.extended=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.upright=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brief.bytes=32"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brief.use_orientation=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.nfeatures=500"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.scale_factor=1.2"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.nlevels=8"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.edge_threshold=31"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.first_level=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.wta_k=2"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.score_type=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.patch_size=31"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.fast_threshold=20"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk.thresh=30"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk.octaves=3"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk.pattern_scale=1.0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.orientation_normalized=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.scale_normalized=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.pattern_scale=22.0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.n_octaves=4"<< "\n";
            break;
        }
    }
    f << "Recognition.TemplateMatching.HistogramMatching.numberOfBins=50"<< "\n";
    f << "Recognition.TemplateMatching.HistogramMatching.Threshold=0.8" << "\n";

    f << "Recognition.DistanceMeasure=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance=0"<< "\n";
    f << "Recognition.DistanceMeasure.PixelWiseDistance=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.Correl=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.ChiSquare=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.ChiSquareAlt=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.Intersection=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.KLDivergence=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.Hellinger=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.Bhattacharyya=0"<< "\n";
}

/**
* a function called to write the feature matching module
* users have decided to use feature matching as a recognition module they also decided to give random values for each parameters
* parameters will be written for all the recognition module (except for the common parts) : one activated, the others will not be
*
* the feature matching should not take care of the color space thus we do not ask for changing color space of images
* random values are generated following an approximation of a Gaussian distribution using uniformly distributed values
*
* input :
*   - fstream& f : a file stream representing the output file
*   - char** argv : the list of arguments that have been given to the program when it has been call
*   - int idx : the index of the next argument to retrieve
*
* output :
*   - recognition module should be written in the output file (assumed that it has been closed to flush the buffer)
*   - int : the index of the next argument to retrieve
*/
int write_use_feature_matching_rand(fstream& f, char** argv, int idx)
{
    f << "Recognition.TemplateMatching=1"<< "\n";
    f << "Recognition.TemplateMatching.TemplateMatching=0"<< "\n";
    f << "Recognition.TemplateMatching.HistogramMatching=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching=1"<< "\n";
    f << "Recognition.TemplateMatching.DistanceMatching=0"<< "\n";
    f << "Recognition.Pyramidal=0"<< "\n";
    f << "Recognition.Pyramidal.BMPyramidal=0"<< "\n";
    f << "Recognition.Pyramidal.CascadeClassifier=0"<< "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccoeff=0"<< "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccoeff_morned=0"<< "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_sqdiff=0"<< "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_sqdiff_normed=0"<< "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccorr=0"<< "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccorr_normed=0"<< "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.nb_layers=0" << "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.size_factor=2" << "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.match_proba=0.8" << "\n";
    f << "Recognition.TemplateMatching.DistanceMatching.Absolute_diff=0" << "\n";
    f << "Recognition.TemplateMatching.DistanceMatching.MSE=0" << "\n";
    f << "Recognition.TemplateMatching.DistanceMatching.MAE=0" << "\n";
    f << "Recognition.TemplateMatching.DistanceMatching.max_distance=1200" << "\n";

    write_not_use_color_space(f);

    ///which descriptor technique to use ?
    cout << "Which feature descriptors do you want to use ? (1: SIFT; 2: SURF; 3: BRIEF; 4: ORB; 5: BRISK; 6: FREAK)" << "\n";
    string c(argv[idx]);
    //cin >> c;
    cout << c << endl;
    idx++;

    while(c != "1" && c != "2" && c != "3" && c != "4" && c != "5" && c != "6")
    {
        cout << "Which feature descriptors do you want to use ? (1: SIFT; 2: SURF; 3: BRIEF; 4: ORB; 5: BRISK; 6: FREAK)" << "\n";
        cin >> c;
    }

    ///write parameters according to choices
    switch(atoi(c.c_str()))
    {
        case 1 :
        {
            f << "Recognition.TemplateMatching.FeatureMatching.Sift=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brief=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.nfeatures=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.n_octave_layers=3" << "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.contrast_threshold=" << (((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX)+ ((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX) ) /4<< "\n"; // between 0 and 1 -> mean around 0.5
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.edge_threshold=" << (((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX)+ ((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX) ) * 5 << "\n"; // between 0 and 20 -> mean around 10
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.sigma=1.6"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.hessian_threshold=400.0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.n_octaves=4"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.n_octave_layers=2"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.extended=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.upright=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brief.bytes=32"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brief.use_orientation=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.nfeatures=500"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.scale_factor=1.2"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.nlevels=8"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.edge_threshold=31"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.first_level=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.wta_k=2"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.score_type=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.patch_size=31"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.fast_threshold=20"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk.thresh=30"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk.octaves=3"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk.pattern_scale=1.0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.orientation_normalized=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.scale_normalized=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.pattern_scale=22.0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.n_octaves=4"<< "\n";
            break;
        }

        case 2 : // SURF
        {
            f << "Recognition.TemplateMatching.FeatureMatching.Sift=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brief=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.nfeatures=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.n_octave_layers=3"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.contrast_threshold=0.04"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.edge_threshold=10"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.sigma=1.6"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.hessian_threshold=" << (((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX)+ ((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX) ) * 50 + 300 << "\n"; //between 300 and 500 -> mean around 400
            // << (rand() % 200 + (-100) ) + 400 << "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.n_octaves=4"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.n_octave_layers=2"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.extended=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.upright=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brief.bytes=32"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brief.use_orientation=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.nfeatures=500"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.scale_factor=1.2"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.nlevels=8"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.edge_threshold=31"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.first_level=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.wta_k=2"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.score_type=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.patch_size=31"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.fast_threshold=20"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk.thresh=30"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk.octaves=3"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk.pattern_scale=1.0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.orientation_normalized=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.scale_normalized=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.pattern_scale=22.0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.n_octaves=4"<< "\n";
            break;
        }

        case 3 : // BRIEF
        {
            f << "Recognition.TemplateMatching.FeatureMatching.Sift=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brief=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.nfeatures=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.n_octave_layers=3"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.contrast_threshold=0.04"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.edge_threshold=10"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.sigma=1.6"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.hessian_threshold=400.0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.n_octaves=4"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.n_octave_layers=2"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.extended=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.upright=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brief.bytes=32"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brief.use_orientation=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.nfeatures=500"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.scale_factor=1.2"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.nlevels=8"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.edge_threshold=31"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.first_level=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.wta_k=2"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.score_type=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.patch_size=31"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.fast_threshold=20"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk.thresh=30"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk.octaves=3"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk.pattern_scale=1.0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.orientation_normalized=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.scale_normalized=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.pattern_scale=22.0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.n_octaves=4"<< "\n";
            break;
        }

        case 4 : //ORB
        {
            f << "Recognition.TemplateMatching.FeatureMatching.Sift=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brief=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.nfeatures=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.n_octave_layers=3"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.contrast_threshold=0.04"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.edge_threshold=10"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.sigma=1.6"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.hessian_threshold=400.0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.n_octaves=4"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.n_octave_layers=2"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.extended=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.upright=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brief.bytes=32"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brief.use_orientation=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.nfeatures=" << (((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX)+ ((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX) ) * 50 + 400 << "\n"; // between 400 and 600 -> mean around 500
            //(rand() % 200 + (-100)) + 500 << "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.scale_factor=" << (((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX)+ ((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX) ) / 4 +1 << "\n"; //between 1 and  2 -> mean around 1.5
            cout << "HEEEEEEEEEEEY" << endl << (double) rand() << " "<< ((double) rand() / RAND_MAX) <<" " << (double) rand() << " "<< ((double) rand() / RAND_MAX) <<" "<< (double) rand() << " "<< ((double) rand() / RAND_MAX) <<" "<< (double) rand() << " "<< ((double) rand() / RAND_MAX) << endl;
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.nlevels=8"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.edge_threshold=31"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.first_level=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.wta_k=" << (((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX)+ ((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX) ) / 2 + 2 << "\n"; // between 2 and 4 -> mean around 3
            //rand() % 3 + (-2) + 3<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.score_type=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.patch_size=31"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.fast_threshold=20"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk.thresh=30"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk.octaves=3"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk.pattern_scale=1.0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.orientation_normalized=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.scale_normalized=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.pattern_scale=22.0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.n_octaves=4"<< "\n";
            break;
        }

        case 5 : // BRISK
        {
            f << "Recognition.TemplateMatching.FeatureMatching.Sift=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brief=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.nfeatures=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.n_octave_layers=3"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.contrast_threshold=0.04"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.edge_threshold=10"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.sigma=1.6"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.hessian_threshold=400.0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.n_octaves=4"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.n_octave_layers=2"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.extended=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.upright=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brief.bytes=32"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brief.use_orientation=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.nfeatures=500"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.scale_factor=1.2"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.nlevels=8"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.edge_threshold=31"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.first_level=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.wta_k=2"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.score_type=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.patch_size=31"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.fast_threshold=20"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk.thresh=30"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk.octaves=3"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk.pattern_scale=1.0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.orientation_normalized=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.scale_normalized=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.pattern_scale=22.0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.n_octaves=4"<< "\n";
            break;
        }

        case 6 : // FREAK
        {
            f << "Recognition.TemplateMatching.FeatureMatching.Sift=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brief=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.nfeatures=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.n_octave_layers=3"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.contrast_threshold=0.04"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.edge_threshold=10"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Sift.sigma=1.6"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.hessian_threshold=400.0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.n_octaves=4"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.n_octave_layers=2"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.extended=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Surf.upright=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brief.bytes=32"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brief.use_orientation=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.nfeatures=500"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.scale_factor=1.2"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.nlevels=8"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.edge_threshold=31"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.first_level=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.wta_k=2"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.score_type=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.patch_size=31"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.ORB.fast_threshold=20"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk.thresh=30"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk.octaves=3"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Brisk.pattern_scale=1.0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.orientation_normalized=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.scale_normalized=1"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.pattern_scale=22.0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching.Freak.n_octaves=4"<< "\n";
            break;
        }
    }
    f << "Recognition.TemplateMatching.HistogramMatching.numberOfBins=50"<< "\n";
    f << "Recognition.TemplateMatching.HistogramMatching.Threshold=0.8" << "\n";

    f << "Recognition.DistanceMeasure=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance=0"<< "\n";
    f << "Recognition.DistanceMeasure.PixelWiseDistance=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.Correl=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.ChiSquare=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.ChiSquareAlt=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.Intersection=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.KLDivergence=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.Hellinger=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.Bhattacharyya=0"<< "\n";

    return idx++;
}

/**
* a function called to write the histogram matching module
* users have decided to use histogram matching as a recognition module they also decided to give random values for each parameters
* parameters will be written for all the recognition module (except for the common parts) : one activated, the others will not be
*
* Histogram are really dependent of the color space
* random values are generated following an approximation of a Gaussian distribution using uniformly distributed values
*
* input :
*   - fstream& f : a file stream representing the output file
*
* output :
*   - recognition module should be written in the output file (assumed that it has been closed to flush the buffer)
*/
void write_use_histogram_matching_rand(fstream& f)
{
    f << "Recognition.TemplateMatching=1"<< "\n";
    f << "Recognition.TemplateMatching.TemplateMatching=0"<< "\n";
    f << "Recognition.TemplateMatching.HistogramMatching=1"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching=0"<< "\n";
    f << "Recognition.TemplateMatching.DistanceMatching=0"<< "\n";
    f << "Recognition.Pyramidal=0"<< "\n";
    f << "Recognition.Pyramidal.BMPyramidal=0"<< "\n";
    f << "Recognition.Pyramidal.CascadeClassifier=0"<< "\n";

    f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccoeff=0"<< "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccoeff_morned=0"<< "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_sqdiff=0"<< "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_sqdiff_normed=0"<< "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccorr=0"<< "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccorr_normed=0"<< "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.nb_layers=0" << "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.size_factor=2" << "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.match_proba=0.8" << "\n";
    f << "Recognition.TemplateMatching.DistanceMatching.Absolute_diff=0" << "\n";
    f << "Recognition.TemplateMatching.DistanceMatching.MSE=0" << "\n";
    f << "Recognition.TemplateMatching.DistanceMatching.MAE=0" << "\n";
    f << "Recognition.TemplateMatching.DistanceMatching.max_distance=1200" << "\n";

    ///use a particular color space ? Which one ?
    cout << "Do you want to use a particular color space ? (y or n)" <<"\n";
    string c;
    cin >> c;
    if (c == "y")
    {
        write_use_color_space(f);
    }
    else
    {
        write_not_use_color_space(f);
    }
    f << "Recognition.TemplateMatching.FeatureMatching.Sift=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Surf=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Brief=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Brisk=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Freak=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Sift.nfeatures=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Sift.n_octave_layers=3"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Sift.contrast_threshold=0.04"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Sift.edge_threshold=10"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Sift.sigma=1.6"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Surf.hessian_threshold=400.0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Surf.n_octaves=4"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Surf.n_octave_layers=2"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Surf.extended=1"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Surf.upright=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Brief.bytes=32"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Brief.use_orientation=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.nfeatures=500"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.scale_factor=1.2"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.nlevels=8"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.edge_threshold=31"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.first_level=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.wta_k=2"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.score_type=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.patch_size=31"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.fast_threshold=20"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Brisk.thresh=30"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Brisk.octaves=3"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Brisk.pattern_scale=1.0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Freak.orientation_normalized=1"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Freak.scale_normalized=1"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Freak.pattern_scale=22.0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Freak.n_octaves=4"<< "\n";

    f << "Recognition.TemplateMatching.HistogramMatching.numberOfBins=" << (((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX)+ ((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX) ) / 4 * 255 + 1 << "\n"; // between 1 and 256 -> mean around 128
    f << "Recognition.TemplateMatching.HistogramMatching.Threshold=" << (((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX)+ ((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX) ) / 4 << "\n"; // between 0 and 1 -> mean around 0.5

    f << "Recognition.DistanceMeasure=1"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance=1"<< "\n";
    f << "Recognition.DistanceMeasure.PixelWiseDistance=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.Correl=1"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.ChiSquare=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.ChiSquareAlt=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.Intersection=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.KLDivergence=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.Hellinger=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.Bhattacharyya=0"<< "\n";

}

/**
* a function called to write the histogram matching module
* users have decided to use histogram matching as a recognition module they also decided to give random values for each parameters
* parameters will be written for all the recognition module (except for the common parts) : one activated, the others will not be
*
* the histogram matching is really dependent on the color space that is used
* random values are generated following an approximation of a Gaussian distribution using uniformly distributed values
*
* input :
*   - fstream& f : a file stream representing the output file
*   - char** argv : the list of arguments given to the program when it was called
*   - int idx : the index of the next argument to retrieve
*
* output :
*   - recognition module should be written in the output file (assumed that it has been closed to flush the buffer)
*   - int : the index of the next argument to retrieve
*/
int write_use_histogram_matching_rand(fstream& f, char** argv, int idx)
{
    f << "Recognition.TemplateMatching=1"<< "\n";
    f << "Recognition.TemplateMatching.TemplateMatching=0"<< "\n";
    f << "Recognition.TemplateMatching.HistogramMatching=1"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching=0"<< "\n";
    f << "Recognition.TemplateMatching.DistanceMatching=0"<< "\n";
    f << "Recognition.Pyramidal=0"<< "\n";
    f << "Recognition.Pyramidal.BMPyramidal=0"<< "\n";
    f << "Recognition.Pyramidal.CascadeClassifier=0"<< "\n";

    f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccoeff=0"<< "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccoeff_morned=0"<< "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_sqdiff=0"<< "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_sqdiff_normed=0"<< "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccorr=0"<< "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccorr_normed=0"<< "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.nb_layers=0" << "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.size_factor=2" << "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.match_proba=0.8" << "\n";
    f << "Recognition.TemplateMatching.DistanceMatching.Absolute_diff=0" << "\n";
    f << "Recognition.TemplateMatching.DistanceMatching.MSE=0" << "\n";
    f << "Recognition.TemplateMatching.DistanceMatching.MAE=0" << "\n";
    f << "Recognition.TemplateMatching.DistanceMatching.max_distance=1200" << "\n";

    ///use a particular color space ? Which one ?
    cout << "Do you want to use a particular color space ? (y or n)" <<"\n";
    string c(argv[idx]);
    //cin >> c;
    cout << c << endl;
    idx++;

    if (c == "y")
    {
        idx = write_use_color_space(f,argv,idx);
    }
    else
    {
        write_not_use_color_space(f);
    }
    f << "Recognition.TemplateMatching.FeatureMatching.Sift=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Surf=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Brief=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Brisk=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Freak=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Sift.nfeatures=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Sift.n_octave_layers=3"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Sift.contrast_threshold=0.04"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Sift.edge_threshold=10"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Sift.sigma=1.6"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Surf.hessian_threshold=400.0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Surf.n_octaves=4"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Surf.n_octave_layers=2"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Surf.extended=1"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Surf.upright=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Brief.bytes=32"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Brief.use_orientation=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.nfeatures=500"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.scale_factor=1.2"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.nlevels=8"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.edge_threshold=31"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.first_level=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.wta_k=2"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.score_type=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.patch_size=31"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.fast_threshold=20"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Brisk.thresh=30"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Brisk.octaves=3"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Brisk.pattern_scale=1.0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Freak.orientation_normalized=1"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Freak.scale_normalized=1"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Freak.pattern_scale=22.0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Freak.n_octaves=4"<< "\n";

    f << "Recognition.TemplateMatching.HistogramMatching.numberOfBins=" << (((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX)+ ((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX) ) / 4 * 255 + 1 << "\n"; // between 1 and 256 -> mean around 128
    f << "Recognition.TemplateMatching.HistogramMatching.Threshold=" << (((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX)+ ((double) rand() / RAND_MAX) + ((double) rand() / RAND_MAX) ) / 4 << "\n"; // between 0 and 1 -> mean around 0.5

    f << "Recognition.DistanceMeasure=1"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance=1"<< "\n";
    f << "Recognition.DistanceMeasure.PixelWiseDistance=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.Correl=1"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.ChiSquare=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.ChiSquareAlt=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.Intersection=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.KLDivergence=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.Hellinger=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.Bhattacharyya=0"<< "\n";

    return idx;
}

/**
* a function called to write the distance matching module
* users have decided to use distance matching as a recognition module they also decided to give random values for each parameters
* parameters will be written for all the recognition module (except for the common parts) : one activated, the others will not be
*
* the distance computation is really dependent on the color space that is used
* random values are generated following an approximation of a Gaussian distribution using uniformly distributed values
*
* input :
*   - fstream& f : a file stream representing the output file
*
* output :
*   - recognition module should be written in the output file (assumed that it has been closed to flush the buffer)
*/
void write_use_distance_matching_rand(fstream& f)
{
    f << "Recognition.TemplateMatching=1"<< "\n";
    f << "Recognition.TemplateMatching.TemplateMatching=0"<< "\n";
    f << "Recognition.TemplateMatching.HistogramMatching=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching=0"<< "\n";
    f << "Recognition.TemplateMatching.DistanceMatching=1"<< "\n";
    f << "Recognition.Pyramidal=0"<< "\n";
    f << "Recognition.Pyramidal.BMPyramidal=0"<< "\n";
    f << "Recognition.Pyramidal.CascadeClassifier=0"<< "\n";

    f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccoeff=0"<< "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccoeff_morned=0"<< "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_sqdiff=0"<< "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_sqdiff_normed=0"<< "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccorr=0"<< "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccorr_normed=0"<< "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.nb_layers=0" << "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.size_factor=2" << "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.match_proba=0.8" << "\n";
    f << "Recognition.TemplateMatching.DistanceMatching.Absolute_diff=0" << "\n";
    f << "Recognition.TemplateMatching.DistanceMatching.MSE=1" << "\n";
    f << "Recognition.TemplateMatching.DistanceMatching.MAE=0" << "\n";
    f << "Recognition.TemplateMatching.DistanceMatching.max_distance=1200" << "\n";

    ///use a particular color space ? Which one ?
    cout << "Do you want to use a particular color space ? (y or n)" <<"\n";
    string c;
    cin >> c;
    if (c == "y")
    {
        write_use_color_space(f);
    }
    else
    {
        write_not_use_color_space(f);
    }
    f << "Recognition.TemplateMatching.FeatureMatching.Sift=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Surf=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Brief=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Brisk=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Freak=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Sift.nfeatures=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Sift.n_octave_layers=3"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Sift.contrast_threshold=0.04"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Sift.edge_threshold=10"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Sift.sigma=1.6"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Surf.hessian_threshold=400.0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Surf.n_octaves=4"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Surf.n_octave_layers=2"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Surf.extended=1"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Surf.upright=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Brief.bytes=32"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Brief.use_orientation=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.nfeatures=500"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.scale_factor=1.2"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.nlevels=8"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.edge_threshold=31"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.first_level=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.wta_k=2"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.score_type=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.patch_size=31"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.fast_threshold=20"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Brisk.thresh=30"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Brisk.octaves=3"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Brisk.pattern_scale=1.0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Freak.orientation_normalized=1"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Freak.scale_normalized=1"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Freak.pattern_scale=22.0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Freak.n_octaves=4"<< "\n";

    f << "Recognition.TemplateMatching.HistogramMatching.numberOfBins=50"<< "\n";
    f << "Recognition.TemplateMatching.HistogramMatching.Threshold=0.8" << "\n";

    f << "Recognition.DistanceMeasure=1"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance=0"<< "\n";
    f << "Recognition.DistanceMeasure.PixelWiseDistance=1"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.Correl=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.ChiSquare=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.ChiSquareAlt=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.Intersection=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.KLDivergence=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.Hellinger=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.Bhattacharyya=0"<< "\n";
}

/**
* a function called to write the distance matching module
* users have decided to use distance matching as a recognition module they also decided to give random values for each parameters
* parameters will be written for all the recognition module (except for the common parts) : one activated, the others will not be
*
* the distance measure is really dependent of the color space which is used
* random values are generated following an approximation of a Gaussian distribution using uniformly distributed values
*
* input :
*   - fstream& f : a file stream representing the output file
*   - char** argv : the list of arguments that has been given to the program when it was called
*   - int idx : the index of the next argument to retrieve
*
* output :
*   - recognition module should be written in the output file (assumed that it has been closed to flush the buffer)
*   - int : the index of the next argument to retrieve
*/
int write_use_distance_matching_rand(fstream& f, char** argv, int idx)
{
    f << "Recognition.TemplateMatching=1"<< "\n";
    f << "Recognition.TemplateMatching.TemplateMatching=0"<< "\n";
    f << "Recognition.TemplateMatching.HistogramMatching=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching=0"<< "\n";
    f << "Recognition.TemplateMatching.DistanceMatching=1"<< "\n";
    f << "Recognition.Pyramidal=0"<< "\n";
    f << "Recognition.Pyramidal.BMPyramidal=0"<< "\n";
    f << "Recognition.Pyramidal.CascadeClassifier=0"<< "\n";

    f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccoeff=0"<< "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccoeff_morned=0"<< "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_sqdiff=0"<< "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_sqdiff_normed=0"<< "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccorr=0"<< "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.cv_tm_ccorr_normed=0"<< "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.nb_layers=0" << "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.size_factor=2" << "\n";
    f << "Recognition.TemplateMatching.TemplateMatching.match_proba=0.8" << "\n";
    f << "Recognition.TemplateMatching.DistanceMatching.Absolute_diff=0" << "\n";
    f << "Recognition.TemplateMatching.DistanceMatching.MSE=1" << "\n";
    f << "Recognition.TemplateMatching.DistanceMatching.MAE=0" << "\n";
    f << "Recognition.TemplateMatching.DistanceMatching.max_distance=1200" << "\n";

    /// use a specific color space ? Which one ?
    cout << "Do you want to use a particular color space ? (y or n)" <<"\n";
    string c(argv[idx]);
    //cin >> c;
    cout << c << endl;
    idx++;

    if (c == "y")
    {
        idx = write_use_color_space(f,argv,idx);
    }
    else
    {
        write_not_use_color_space(f);
    }
    f << "Recognition.TemplateMatching.FeatureMatching.Sift=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Surf=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Brief=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Brisk=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Freak=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Sift.nfeatures=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Sift.n_octave_layers=3"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Sift.contrast_threshold=0.04"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Sift.edge_threshold=10"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Sift.sigma=1.6"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Surf.hessian_threshold=400.0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Surf.n_octaves=4"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Surf.n_octave_layers=2"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Surf.extended=1"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Surf.upright=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Brief.bytes=32"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Brief.use_orientation=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.nfeatures=500"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.scale_factor=1.2"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.nlevels=8"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.edge_threshold=31"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.first_level=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.wta_k=2"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.score_type=0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.patch_size=31"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.ORB.fast_threshold=20"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Brisk.thresh=30"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Brisk.octaves=3"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Brisk.pattern_scale=1.0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Freak.orientation_normalized=1"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Freak.scale_normalized=1"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Freak.pattern_scale=22.0"<< "\n";
    f << "Recognition.TemplateMatching.FeatureMatching.Freak.n_octaves=4"<< "\n";

    f << "Recognition.TemplateMatching.HistogramMatching.numberOfBins=50"<< "\n";
    f << "Recognition.TemplateMatching.HistogramMatching.Threshold=0.8" << "\n";

    f << "Recognition.DistanceMeasure=1"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance=0"<< "\n";
    f << "Recognition.DistanceMeasure.PixelWiseDistance=1"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.Correl=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.ChiSquare=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.ChiSquareAlt=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.Intersection=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.KLDivergence=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.Hellinger=0"<< "\n";
    f << "Recognition.DistanceMeasure.HistogramDistance.Bhattacharyya=0"<< "\n";

    return idx;
}

/**
* a function called in interactive mode which will write common part of the recognition module
* users has chosen which recognition method to use, call the function according to choices
* this function will write random values for the given choice -> other choices in the module will be deactivated
*
* random values are generated following an approximation of a Gaussian law using uniformly distributed values
*
* input :
*   - fstream& f : a file stream representing the output file (avoid copy)
*   - int choice : the choice made regarding the method to be used
*
* output :
*   - something is written in the output file
*   - methods of the recognition module that are not used are deactivated
*/
void write_recognition_rand(fstream& f, int choice)
{
    f << "Recognition=1"<< "\n";
    switch (choice)
    {
        case 1 : //use template matching
        {
            write_use_template_matching_rand(f);
            break;
        }
        case 2 : //use feature matching
        {
            write_use_feature_matching_rand(f);
            break;
        }

        case 3 : // use histogram matching
        {
            write_use_histogram_matching_rand(f);
            break;
        }

        case 4 : //use distance matching
        {
            write_use_distance_matching_rand(f);
            break;
        }

        case 5 : // use Pyramidal
        {
            f << "Recognition.TemplateMatching=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching=0"<< "\n";
            f << "Recognition.TemplateMatching.HistogramMatching=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching=0"<< "\n";
            f << "Recognition.TemplateMatching.DistanceMatching=0"<< "\n";
            f << "Recognition.Pyramidal=1"<< "\n";
            f << "Recognition.Pyramidal.BMPyramidal=0"<< "\n";
            f << "Recognition.Pyramidal.CascadeClassifier=0"<< "\n";
            break;
        }
    }
}

/**
* a function which will write common part of the recognition module
* users has chosen which recognition method to use, call the function according to choices
* this function will write random values for the given choice -> other choices in the module will be deactivated
*
* random values are generated following an approximation of a Gaussian distribution using uniformly distributed values
*
* input :
*   - fstream& f : a file stream representing the output file (avoid copy)
*   - int choice : the choice made regarding the method to be used
*   - char** argv : the list of arguments given to the program when it has been called
*   - int idx : the index of the next argument to retrieve
*
* output :
*   - something is written in the output file
*   - methods of the recognition module that are not used are deactivated
*   - int : the index of the next argument to retrieve
*/
int write_recognition_rand(fstream& f, int choice, char** argv, int idx)
{
    f << "Recognition=1"<< "\n";
    switch (choice)
    {
        case 1 : //use template matching
        {
            idx = write_use_template_matching_rand(f, argv, idx);
            break;
        }
        case 2 : //use feature matching
        {
            idx = write_use_feature_matching_rand(f, argv, idx);
            break;
        }

        case 3 : // use histogram matching
        {
            idx = write_use_histogram_matching_rand(f, argv, idx);
            break;
        }

        case 4 : //use distance matching
        {
            idx = write_use_distance_matching_rand(f, argv, idx);
            break;
        }

        case 5 : // use Pyramidal
        {
            f << "Recognition.TemplateMatching=0"<< "\n";
            f << "Recognition.TemplateMatching.TemplateMatching=0"<< "\n";
            f << "Recognition.TemplateMatching.HistogramMatching=0"<< "\n";
            f << "Recognition.TemplateMatching.FeatureMatching=0"<< "\n";
            f << "Recognition.TemplateMatching.DistanceMatching=0"<< "\n";
            f << "Recognition.Pyramidal=1"<< "\n";
            f << "Recognition.Pyramidal.BMPyramidal=0"<< "\n";
            f << "Recognition.Pyramidal.CascadeClassifier=0"<< "\n";
            break;
        }
    }

    return idx;
}

/**
* a function which asks user to choose what recognition technique they want to use and its configuration
* this function is used only in interactive mode
* It writes (by delegation) directly choices into the output file
*/
void module_recognition_creation(fstream& f)
{
    ///what recognition method to use ?
    string choice;
    cout << "What method do you want to use to recognize objects? (1: Template Matching; 2: Feature Matching; 3: Histogram Matching; 4: Distance Matching)" << endl;
    cin >> choice;
    while(choice != "1" && choice != "2" && choice != "3" && choice != "4")
    {
        cout << "What method do you want to use ? (1: Template Matching; 2: Feature Matching; 3: Histogram Matching; 4: Distance Matching)" << endl;
        cin >> choice;
    }

    ///use default values ?
    string def;
    cout << "Do you want to use default values ? (y or n)" << endl;
    cin >> def;
    if (def == "y")
    {
        write_recognition_default(f,atoi(choice.c_str()));
    }
    else
    {
        write_recognition_rand(f,atoi(choice.c_str()));
    }
}

/**
* a function which asks user to choose what recognition technique they want to use and its configuration
* this function is used only in interactive mode
* It writes (by delegation) directly choices into the output file
*
* input :
*   - fstream& f : a file stream representing the output file
*   - char** argv : the list of arguments given to the program when it has been call
*   - int idx : the index of the next argument to retrieve
*
* output :
*   -int : the index of the next argument to retrieve
*/
int module_recognition_creation(fstream& f, char** argv, int idx)
{
    /*///@DEBUG
    cout << "beginning recognition creation " << idx << endl;*/

    ///what recognition technique to use ?
    cout << "What method do you want to use to recognize objects? (1: Template Matching; 2: Feature Matching; 3: Histogram Matching; 4: Distance Matching)" << endl;
    string choice(argv[idx]);
    cout << choice << endl;
    idx++;

    while(choice != "1" && choice != "2" && choice != "3" && choice != "4")
    {
        cout << "What method do you want to use ? (1: Template Matching; 2: Feature Matching; 3: Histogram Matching; 4: Distance Matching)" << endl;
        cin >> choice;
    }

    ///use default values ?
    cout << "Do you want to use default values ? (y or n)" << endl;
    string def(argv[idx]);
    cout << def << endl;
    idx++;

    if (def == "y")
    {
        idx = write_recognition_default(f,atoi(choice.c_str()),argv,idx);
    }
    else
    {
        idx = write_recognition_rand(f,atoi(choice.c_str()),argv,idx);
    }

    return idx;
}

/**
* a function called (both in interactive and non-interactive modes) when no tracking module should be used
* it will write into the output file all parameters related to tracking with options to select tracking module deactivated
* intput :
*   - fstream& f : a file stream representing the output file (avoid copy)
*/
void write_no_tracking(fstream& f)
{
    f << "Tracking=0"<< "\n";
    f << "Tracking.Trackers=0"<< "\n";
    f << "Tracking.Trackers.Boosting=0"<< "\n";
    f << "Tracking.Trackers.MIL=0"<< "\n";
    f << "Tracking.CamShift=0"<< "\n";
}

/**
* a function called in interactive mode which will write common part of the tracking module
* users has decided to use tracking module and have chosen which one, call the function according to choices
* this function will write default values for the given choice -> other choices in the module will be deactivated
* input :
*   - fstream& f : a file stream representing the output file (avoid copy)
*   - int choice : the choice made regarding the method to be used
*
* output :
*   - something is written in the output file
*   - methods of the tracking module that are not used are deactivated
*/
void write_tracking_default(fstream& f, int choice)
{
    f << "Tracking=1"<< "\n";
    if(choice == 1)
    {
        ///use trackers ?
        cout << "Do you want to use tracking technique based on Boosting ? (y or n)" << endl;
        string c;
        cin >> c;
        if(c == "y")
        {
            f << "Tracking.Trackers=1"<< "\n";
            f << "Tracking.Trackers.Boosting=1"<< "\n";
            f << "Tracking.Trackers.MIL=0"<< "\n";
            f << "Tracking.CamShift=0"<< "\n";
        }
        else ///else use MIL
        {
            f << "Tracking.Trackers=1"<< "\n";
            f << "Tracking.Trackers.Boosting=0"<< "\n";
            f << "Tracking.Trackers.MIL=1"<< "\n";
            f << "Tracking.CamShift=0"<< "\n";
        }

    }
    else /// else no trackers but CamShift
    {
        f << "Tracking.Trackers=0"<< "\n";
        f << "Tracking.Trackers.Boosting=0"<< "\n";
        f << "Tracking.Trackers.MIL=0"<< "\n";
        f << "Tracking.CamShift=1"<< "\n";
    }

}

/**
* a function which will write common part of the tracking module
* users has decided to use tracking module and have chosen which one, call the function according to choices
* this function will write default values for the given choice -> other choices in the module will be deactivated
* input :
*   - fstream& f : a file stream representing the output file (avoid copy)
*   - int choice : the choice made regarding the method to be used
*
* output :
*   - something is written in the output file
*   - methods of the tracking module that are not used are deactivated
*/
int write_tracking_default(fstream& f, int choice, char** argv, int idx)
{
    f << "Tracking=1"<< "\n";
    ///use tracker based technique ?
    if(choice == 1)
    {
        ///use boosting
        cout << "Do you want to use tracking technique based on Boosting ? (y or n)" << endl;
        string c(argv[idx]);
        //cin >> c;
        cout << c << endl;
        idx++;

        if(c == "y") // boosting
        {
            f << "Tracking.Trackers=1"<< "\n";
            f << "Tracking.Trackers.Boosting=1"<< "\n";
            f << "Tracking.Trackers.MIL=0"<< "\n";
            f << "Tracking.CamShift=0"<< "\n";
        }
        else // MIL
        {
            f << "Tracking.Trackers=1"<< "\n";
            f << "Tracking.Trackers.Boosting=0"<< "\n";
            f << "Tracking.Trackers.MIL=1"<< "\n";
            f << "Tracking.CamShift=0"<< "\n";
        }

    }
    else // CamShift
    {
        f << "Tracking.Trackers=0"<< "\n";
        f << "Tracking.Trackers.Boosting=0"<< "\n";
        f << "Tracking.Trackers.MIL=0"<< "\n";
        f << "Tracking.CamShift=1"<< "\n";
    }

    return idx;
}

/**
* a function called in interactive mode which will write common part of the tracking module
* users has decided to use tracking module and have chosen which one, call the function according to choices
* this function will write randomly generated values for the given choice -> other choices in the module will be deactivated
* the random generation is an approximation of Gaussian distribution by using uniformly distributed values (call several time rand() on the range [0;1] then divide by the number of rand() call (upper bound)
* input :
*   - fstream& f : a file stream representing the output file (avoid copy)
*   - int choice : the choice made regarding the method to be used
*
* output :
*   - something is written in the output file
*   - methods of the tracking module that are not used are deactivated
*/
void write_tracking_rand(fstream& f, int choice)
{
    f << "Tracking=1"<< "\n";
    //use trackers ?
    if(choice == 1)
    {
        ///use boosting ?
        cout << "Do you want to use tracking technique based on Boosting ? (y or n)" << endl;
        string c;
        cin >> c;
        if(c == "y") //boosting
        {
            f << "Tracking.Trackers=1"<< "\n";
            f << "Tracking.Trackers.Boosting=1"<< "\n";
            f << "Tracking.Trackers.MIL=0"<< "\n";
            f << "Tracking.CamShift=0"<< "\n";
        }
        else // MIL
        {
            f << "Tracking.Trackers=1"<< "\n";
            f << "Tracking.Trackers.Boosting=0"<< "\n";
            f << "Tracking.Trackers.MIL=1"<< "\n";
            f << "Tracking.CamShift=0"<< "\n";
        }

    }
    else // CamShift
    {
        f << "Tracking.Trackers=0"<< "\n";
        f << "Tracking.Trackers.Boosting=0"<< "\n";
        f << "Tracking.Trackers.MIL=0"<< "\n";
        f << "Tracking.CamShift=1"<< "\n";
    }
}

/**
* a function which will write common part of the tracking module
* users has decided to use tracking module and have chosen which one, call the function according to choices
* this function will write randomly generated values for the given choice -> other choices in the module will be deactivated
* the random generation is an approximation of Gaussian distribution by using uniformly distributed values (call several time rand() on the range [0;1] then divide by the number of rand() call (upper bound)
* input :
*   - fstream& f : a file stream representing the output file (avoid copy)
*   - int choice : the choice made regarding the method to be used
*   - char** argv : the array of arguments given to the main function while called
*   - int idx : the current index to use to retrieve/fetch the right argument
*
* output :
*   - something is written in the output file
*   - methods of the tracking module that are not used are deactivated
*/
int write_tracking_rand(fstream& f, int choice, char** argv, int idx)
{
    f << "Tracking=1"<< "\n";
    ///use trackers ?
    if(choice == 1)
    {
        ///use boosting ?
        cout << "Do you want to use tracking technique based on Boosting ? (y or n)" << endl;
        string c(argv[idx]);
        //cin >> c;
        cout << c << endl;
        idx++;

        if(c == "y") //boosting
        {
            f << "Tracking.Trackers=1"<< "\n";
            f << "Tracking.Trackers.Boosting=1"<< "\n";
            f << "Tracking.Trackers.MIL=0"<< "\n";
            f << "Tracking.CamShift=0"<< "\n";
        }
        else // MIL
        {
            f << "Tracking.Trackers=1"<< "\n";
            f << "Tracking.Trackers.Boosting=0"<< "\n";
            f << "Tracking.Trackers.MIL=1"<< "\n";
            f << "Tracking.CamShift=0"<< "\n";
        }

    }
    else  // CamShift
    {
        f << "Tracking.Trackers=0"<< "\n";
        f << "Tracking.Trackers.Boosting=0"<< "\n";
        f << "Tracking.Trackers.MIL=0"<< "\n";
        f << "Tracking.CamShift=1"<< "\n";
    }

    return idx;
}

/**
* a function which asks user to choose if they want to use a tracking module and its configuration
* this function is used only in interactive mode
* It writes (by delegation) directly choices into the output file
*/
void module_tracking_creation(fstream& f)
{
    ///use tracking ?
    cout << "Do you want to use a module to track objcets once recognized ? (y or n)" << endl;
    string choice;
    cin >> choice;
    if(choice == "y")
    {

        ///which technique?
        cout << "What method do you want to use ? (1: Track; 2: CamShift)" << endl;
        cin >> choice;
        while(choice != "1" && choice != "2")
        {
            cout << "What method do you want to use ? (1: Track; 2: CamShift)" << endl;
            cin >> choice;
        }
        string def;

        /// use default values ?
        cout << "Do you want to use default values ? (y or n)" << endl;
        cin >> def;
        if (def == "y")
        {
            write_tracking_default(f,atoi(choice.c_str()));
        }
        else
        {
            write_tracking_rand(f,atoi(choice.c_str()));
        }
    }
    else
    {
        write_no_tracking(f);
    }
}

/**
* a function which uses parameters to continue the execution of the program (without interactions with users)
* this function is used only if more than argument is given
* It writes (by delegation) directly choices into the output file
*/
int module_tracking_creation(fstream& f,char** argv, int idx)
{
    ///use tracking ?
    cout << "Do you want to use a module to track objcets once recognized ? (y or n)" << endl;
    string choice(argv[idx]);
    //cin >> choice;
    cout << choice << endl;
    idx++;

    if(choice == "y")
    {

        ///which technique ?
        cout << "What method do you want to use ? (1: Track; 2: CamShift)" << endl;
        //cin >> choice;
        choice = argv[idx];
        cout << choice;
        idx++;

        while(choice != "1" && choice != "2")
        {
            cout << "What method do you want to use ? (1: Track; 2: CamShift)" << endl;
            cin >> choice;
        }
        string def(argv[idx]);

        ///use default values ?
        cout << "Do you want to use default values ? (y or n)" << endl;
        //cin >> def;
        cout << def << endl;
        idx++;

        if (def == "y")
        {
            idx = write_tracking_default(f,atoi(choice.c_str()), argv, idx);
        }
        else
        {
            idx = write_tracking_rand(f,atoi(choice.c_str()), argv, idx);
        }
    }
    else
    {
        write_no_tracking(f);
    }

    return idx;
}


/**
* the main function of the program;
* it will decide on which mode to launch computations
* input :
*   - argc : the number of arguments
*   - argv : the value of arguments
*
* among the different running modes, there is also the possibility to use defaults values
* but also randomly generated values.
* Random values are generated as an approximation of a Gaussian law out of uniformly distributed values
*/
int main(int argc, char** argv)
{
    cout <<"TIME : " <<  time(0) << endl;
    srand(time(NULL));
    //not enough number of argument
    if(argc <= 1)
    {
        help();
        return 1;
    }

    if(argc == 2) //iteractive mode (questions and answers by user)
    {
        //argument is the filename of the product file
        const string filename = argv[1];


        ///@DEBUG : display the file name on screen
        cout << "OUTPUT NAME : " << argv[1] <<endl;

        //open the output file
        fstream file(filename.c_str(), fstream::out );

        ///write the different modules
        module_detection_creation(file);
        module_recognition_creation(file);
        module_tracking_creation(file);
        file.close();
    }

    else //eveything is given
    {
        ///@DEBUG : display the number of given arguments on screen
        cout << argc << endl;

        //the index of the current argument to use
        int idx =1;

        //argument is the filename of the product file
        const string filename = argv[idx];

        ///@DEBUG : display the file name on screen
        cout << "OUTPUT NAME : " << argv[idx] <<endl;

        //open the output file
        fstream file(filename.c_str(), fstream::out );

        //increase index to the next argument to use
        idx++;

        //call function with argv and idx to know which value
        ///write the different modules
        idx = module_detection_creation(file,argv,idx);
        ///@DEBUG : be sure that detection module has been written
        cout << "after module detection : " << idx << endl;
        idx = module_recognition_creation(file,argv,idx);
        ///@DEBUG : be sure that recognition module has been written
        cout << "after module recognition : " << idx << endl;
        idx = module_tracking_creation(file,argv,idx);

        /// @DEBUG : assert all the command line has been processed
        if(idx == argc)
        {
            cout << "cool" << endl;
        }
        else
        {
            cout << "wrong number of argument ?" << endl;
        }
    }

    return 0;
}
