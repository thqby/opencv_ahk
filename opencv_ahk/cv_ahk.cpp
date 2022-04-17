#include "pch.h"
#include "cv_mat.h"
#include "cv_func.h"
#include "util.h"
#include "cv_class.h"
#include <ahkapi.h>
#include "cvobj.h"
#include "Vector.h"
#include "TextDraw.h"

IAhkApi* g_ahkapi = nullptr;
ExprTokenType g_invalid[1] = {};
ExprTokenType* g_invalidparam[1] = { g_invalid };

FuncEntry CV_Funcs[] = {
BIFn(CamShift, 3, 3, CV_FUNC),
BIFn(Canny, 4, 6, CV_FUNC),
BIFn(GaussianBlur, 4, 6, CV_FUNC),
BIFn(HoughCircles, 5, 9, CV_FUNC),
BIFn(HoughLines, 5, 9, CV_FUNC),
BIFn(HoughLinesP, 5, 7, CV_FUNC),
BIFn(HoughLinesPointSet, 10, 10, CV_FUNC),
BIFn(HoughLinesWithAccumulator, 5, 9, CV_FUNC),
BIFn(HuMoments, 2, 2, CV_FUNC),
BIFn(LUT, 3, 3, CV_FUNC),
BIFn(Laplacian, 3, 7, CV_FUNC),
BIFn(Mahalanobis, 3, 3, CV_FUNC),
BIFn(PCABackProject, 4, 4, CV_FUNC),
BIFn(PCACompute, 3, 5, CV_FUNC),
BIFn(PCAProject, 4, 4, CV_FUNC),
BIFn(PSNR, 2, 3, CV_FUNC),
BIFn(RQDecomp3x3, 3, 6, CV_FUNC),
BIFn(Rodrigues, 2, 3, CV_FUNC),
BIFn(SVBackSubst, 5, 5, CV_FUNC),
BIFn(SVDecomp, 4, 5, CV_FUNC),
BIFn(Scharr, 5, 8, CV_FUNC),
BIFn(Sobel, 5, 9, CV_FUNC),
BIFn(absdiff, 3, 3, CV_FUNC),
BIFn(accumulate, 2, 3, CV_FUNC),
BIFn(accumulateProduct, 3, 4, CV_FUNC),
BIFn(accumulateSquare, 2, 3, CV_FUNC),
BIFn(accumulateWeighted, 3, 4, CV_FUNC),
BIFn(adaptiveThreshold, 7, 7, CV_FUNC),
BIFn(add, 3, 5, CV_FUNC),
BIFn(addText, 4, 9, CV_FUNC),
BIFn(addWeighted, 6, 7, CV_FUNC),
BIFn(applyColorMap, 3, 3, CV_FUNC),
BIFn(approxPolyDP, 4, 4, CV_FUNC),
BIFn(arcLength, 2, 2, CV_FUNC),
BIFn(arrowedLine, 4, 8, CV_FUNC),
BIFn(batchDistance, 5, 10, CV_FUNC),
BIFn(bilateralFilter, 5, 6, CV_FUNC),
BIFn(bitwise_and, 3, 4, CV_FUNC),
BIFn(bitwise_not, 2, 3, CV_FUNC),
BIFn(bitwise_or, 3, 4, CV_FUNC),
BIFn(bitwise_xor, 3, 4, CV_FUNC),
BIFn(blendLinear, 5, 5, CV_FUNC),
BIFn(blur, 3, 5, CV_FUNC),
BIFn(borderInterpolate, 3, 3, CV_FUNC),
BIFn(boundingRect, 1, 1, CV_FUNC),
BIFn(boxFilter, 4, 7, CV_FUNC),
BIFn(boxPoints, 2, 2, CV_FUNC),
BIFn(buildOpticalFlowPyramid, 4, 8, CV_FUNC),
BIFn(calcBackProject, 6, 6, CV_FUNC),
BIFn(calcCovarMatrix, 4, 5, CV_FUNC),
BIFn(calcHist, 6, 7, CV_FUNC),
BIFn(calcOpticalFlowFarneback, 10, 10, CV_FUNC),
BIFn(calcOpticalFlowPyrLK, 6, 11, CV_FUNC),
BIFn(calibrateCamera, 7, 12, CV_FUNC),
BIFn(calibrateCameraRO, 9, 15, CV_FUNC),
BIFn(calibrateHandEye, 6, 7, CV_FUNC),
BIFn(calibrateRobotWorldHandEye, 8, 9, CV_FUNC),
BIFn(calibrationMatrixValues, 9, 9, CV_FUNC),
BIFn(cartToPolar, 4, 5, CV_FUNC),
BIFn(checkChessboard, 2, 2, CV_FUNC),
BIFn(checkHardwareSupport, 1, 1, CV_FUNC),
BIFn(checkRange, 1, 5, CV_FUNC),
BIFn(circle, 4, 7, CV_FUNC),
BIFn(clipLine, 3, 3, CV_FUNC),
BIFn(colorChange, 3, 6, CV_FUNC),
BIFn(compare, 4, 4, CV_FUNC),
BIFn(compareHist, 3, 3, CV_FUNC),
BIFn(completeSymm, 1, 2, CV_FUNC),
BIFn(composeRT, 6, 14, CV_FUNC),
BIFn(computeCorrespondEpilines, 4, 4, CV_FUNC),
BIFn(computeECC, 2, 3, CV_FUNC),
BIFn(connectedComponents, 2, 5, CV_FUNC),
BIFn(connectedComponentsWithStats, 4, 7, CV_FUNC),
BIFn(contourArea, 1, 2, CV_FUNC),
BIFn(convertFp16, 2, 2, CV_FUNC),
BIFn(convertMaps, 5, 6, CV_FUNC),
BIFn(convertPointsFromHomogeneous, 2, 2, CV_FUNC),
BIFn(convertPointsToHomogeneous, 2, 2, CV_FUNC),
BIFn(convertScaleAbs, 2, 4, CV_FUNC),
BIFn(convexHull, 2, 4, CV_FUNC),
BIFn(convexityDefects, 3, 3, CV_FUNC),
BIFn(copyMakeBorder, 7, 8, CV_FUNC),
BIFn(copyTo, 3, 3, CV_FUNC),
BIFn(cornerEigenValsAndVecs, 4, 5, CV_FUNC),
BIFn(cornerHarris, 5, 6, CV_FUNC),
BIFn(cornerMinEigenVal, 3, 5, CV_FUNC),
BIFn(cornerSubPix, 5, 5, CV_FUNC),
BIFn(correctMatches, 5, 5, CV_FUNC),
BIFn(countNonZero, 1, 1, CV_FUNC),
BIFn(createAlignMTB, 0, 3, CV_FUNC),
BIFn(createBackgroundSubtractorKNN, 0, 3, CV_FUNC),
BIFn(createBackgroundSubtractorMOG2, 0, 3, CV_FUNC),
BIFn(createCLAHE, 0, 2, CV_FUNC),
BIFn(createCalibrateDebevec, 0, 3, CV_FUNC),
BIFn(createCalibrateRobertson, 0, 2, CV_FUNC),
BIFn(createGeneralizedHoughBallard, 0, 0, CV_FUNC),
BIFn(createGeneralizedHoughGuil, 0, 0, CV_FUNC),
BIFn(createHanningWindow, 3, 3, CV_FUNC),
BIFn(createLineSegmentDetector, 0, 8, CV_FUNC),
BIFn(createMergeDebevec, 0, 0, CV_FUNC),
BIFn(createMergeMertens, 0, 3, CV_FUNC),
BIFn(createMergeRobertson, 0, 0, CV_FUNC),
BIFn(createTonemap, 0, 1, CV_FUNC),
BIFn(createTonemapDrago, 0, 3, CV_FUNC),
BIFn(createTonemapMantiuk, 0, 3, CV_FUNC),
BIFn(createTonemapReinhard, 0, 4, CV_FUNC),
BIFn(createTrackbar, 3, 4, CV_FUNC),
BIFn(cubeRoot, 1, 1, CV_FUNC),
BIFn(cvtColor, 3, 4, CV_FUNC),
BIFn(cvtColorTwoPlane, 4, 4, CV_FUNC),
BIFn(dct, 2, 3, CV_FUNC),
BIFn(decolor, 3, 3, CV_FUNC),
BIFn(decomposeEssentialMat, 4, 4, CV_FUNC),
BIFn(decomposeHomographyMat, 5, 5, CV_FUNC),
BIFn(decomposeProjectionMatrix, 4, 8, CV_FUNC),
BIFn(demosaicing, 3, 4, CV_FUNC),
BIFn(denoise_TVL1, 2, 4, CV_FUNC),
BIFn(destroyAllWindows, 0, 0, CV_FUNC),
BIFn(destroyWindow, 1, 1, CV_FUNC),
BIFn(detailEnhance, 2, 4, CV_FUNC),
BIFn(determinant, 1, 1, CV_FUNC),
BIFn(dft, 2, 4, CV_FUNC),
BIFn(dilate, 3, 7, CV_FUNC),
BIFn(displayOverlay, 2, 3, CV_FUNC),
BIFn(displayStatusBar, 2, 3, CV_FUNC),
BIFn(distanceTransform, 4, 6, CV_FUNC),
BIFn(divSpectrums, 4, 5, CV_FUNC),
BIFn(divide, 3, 5, CV_FUNC),
BIFn(drawChessboardCorners, 4, 4, CV_FUNC),
BIFn(drawContours, 4, 9, CV_FUNC),
BIFn(drawFrameAxes, 6, 7, CV_FUNC),
BIFn(drawKeypoints, 3, 5, CV_FUNC),
BIFn(drawMarker, 3, 7, CV_FUNC),
BIFn(drawMatches, 6, 11, CV_FUNC),
BIFn(drawMatches2, 6, 10, CV_FUNC),
BIFn(edgePreservingFilter, 2, 5, CV_FUNC),
BIFn(eigen, 2, 3, CV_FUNC),
BIFn(eigenNonSymmetric, 3, 3, CV_FUNC),
BIFn(ellipse, 3, 10, CV_FUNC),
BIFn(ellipse2Poly, 7, 7, CV_FUNC),
BIFn(empty_array_desc, 0, 0, CV_FUNC),
BIFn(empty_gopaque_desc, 0, 0, CV_FUNC),
BIFn(empty_scalar_desc, 0, 0, CV_FUNC),
BIFn(equalizeHist, 2, 2, CV_FUNC),
BIFn(erode, 3, 7, CV_FUNC),
BIFn(estimateAffine2D, 2, 8, CV_FUNC),
BIFn(estimateAffine3D, 2, 6, CV_FUNC),
BIFn(estimateAffinePartial2D, 2, 8, CV_FUNC),
BIFn(estimateChessboardSharpness, 3, 6, CV_FUNC),
BIFn(estimateTranslation3D, 4, 6, CV_FUNC),
BIFn(exp, 2, 2, CV_FUNC),
BIFn(extractChannel, 3, 3, CV_FUNC),
BIFn(fastAtan2, 2, 2, CV_FUNC),
BIFn(fastNlMeansDenoising, 2, 6, CV_FUNC),
BIFn(fastNlMeansDenoisingColored, 2, 6, CV_FUNC),
BIFn(fastNlMeansDenoisingColoredMulti, 4, 8, CV_FUNC),
BIFn(fastNlMeansDenoisingMulti, 4, 8, CV_FUNC),
BIFn(fillConvexPoly, 3, 5, CV_FUNC),
BIFn(fillPoly, 3, 6, CV_FUNC),
BIFn(filter2D, 4, 7, CV_FUNC),
BIFn(filterHomographyDecompByVisibleRefpoints, 5, 6, CV_FUNC),
BIFn(filterSpeckles, 4, 5, CV_FUNC),
BIFn(find4QuadCornerSubpix, 3, 3, CV_FUNC),
BIFn(findChessboardCorners, 3, 4, CV_FUNC),
BIFn(findChessboardCornersSB, 3, 5, CV_FUNC),
BIFn(findCirclesGrid, 3, 6, CV_FUNC),
BIFn(findContours, 4, 6, CV_FUNC),
BIFn(findEssentialMat, 2, 10, CV_FUNC),
BIFn(findFundamentalMat, 2, 7, CV_FUNC),
BIFn(findHomography, 2, 7, CV_FUNC),
BIFn(findNonZero, 2, 2, CV_FUNC),
BIFn(findTransformECC, 3, 7, CV_FUNC),
BIFn(fitEllipse, 1, 1, CV_FUNC),
BIFn(fitEllipseAMS, 1, 1, CV_FUNC),
BIFn(fitEllipseDirect, 1, 1, CV_FUNC),
BIFn(fitLine, 6, 6, CV_FUNC),
BIFn(flip, 3, 3, CV_FUNC),
BIFn(floodFill, 4, 8, CV_FUNC),
BIFn(gemm, 6, 7, CV_FUNC),
BIFn(getAffineTransform, 2, 2, CV_FUNC2),
BIFn(getBuildInformation, 0, 0, CV_FUNC2),
BIFn(getCPUFeaturesLine, 0, 0, CV_FUNC2),
BIFn(getCPUTickCount, 0, 0, CV_FUNC2),
BIFn(getDefaultNewCameraMatrix, 1, 3, CV_FUNC2),
BIFn(getDerivKernels, 5, 7, CV_FUNC2),
BIFn(getFontScaleFromHeight, 2, 3, CV_FUNC2),
BIFn(getGaborKernel, 5, 7, CV_FUNC2),
BIFn(getGaussianKernel, 2, 3, CV_FUNC2),
BIFn(getHardwareFeatureName, 1, 1, CV_FUNC2),
BIFn(getLogLevel, 0, 0, CV_FUNC2),
BIFn(getNumThreads, 0, 0, CV_FUNC2),
BIFn(getNumberOfCPUs, 0, 0, CV_FUNC2),
BIFn(getOptimalDFTSize, 1, 1, CV_FUNC2),
BIFn(getOptimalNewCameraMatrix, 4, 7, CV_FUNC2),
BIFn(getPerspectiveTransform, 2, 3, CV_FUNC2),
BIFn(getRectSubPix, 4, 5, CV_FUNC2),
BIFn(getRotationMatrix2D, 3, 3, CV_FUNC2),
BIFn(getStructuringElement, 2, 3, CV_FUNC2),
BIFn(getTextSize, 5, 5, CV_FUNC2),
BIFn(getThreadNum, 0, 0, CV_FUNC2),
BIFn(getTickCount, 0, 0, CV_FUNC2),
BIFn(getTickFrequency, 0, 0, CV_FUNC2),
BIFn(getTrackbarPos, 2, 2, CV_FUNC2),
BIFn(getValidDisparityROI, 5, 5, CV_FUNC2),
BIFn(getVersionMajor, 0, 0, CV_FUNC2),
BIFn(getVersionMinor, 0, 0, CV_FUNC2),
BIFn(getVersionRevision, 0, 0, CV_FUNC2),
BIFn(getVersionString, 0, 0, CV_FUNC2),
BIFn(getWindowImageRect, 1, 1, CV_FUNC2),
BIFn(getWindowProperty, 2, 2, CV_FUNC2),
BIFn(goodFeaturesToTrack, 5, 11, CV_FUNC2),
BIFn(grabCut, 6, 7, CV_FUNC2),
BIFn(groupRectangles, 3, 4, CV_FUNC2),
BIFn(haveImageReader, 1, 1, CV_FUNC2),
BIFn(haveImageWriter, 1, 1, CV_FUNC2),
BIFn(haveOpenVX, 0, 0, CV_FUNC2),
BIFn(hconcat, 2, 2, CV_FUNC2),
BIFn(idct, 2, 3, CV_FUNC2),
BIFn(idft, 2, 4, CV_FUNC2),
BIFn(illuminationChange, 3, 5, CV_FUNC2),
BIFn(imcount, 1, 2, CV_FUNC2),
BIFn(imdecode, 2, 2, CV_FUNC2),
BIFn(imencode, 3, 4, CV_FUNC2),
BIFn(imread, 1, 2, CV_FUNC2),
BIFn(imreadmulti, 2, 5, CV_FUNC2),
BIFn(imshow, 2, 2, CV_FUNC2),
BIFn(imwrite, 2, 3, CV_FUNC2),
BIFn(imwritemulti, 2, 3, CV_FUNC2),
BIFn(inRange, 4, 4, CV_FUNC2),
BIFn(initCameraMatrix2D, 3, 4, CV_FUNC2),
BIFn(initInverseRectificationMap, 8, 8, CV_FUNC2),
BIFn(initUndistortRectifyMap, 8, 8, CV_FUNC2),
BIFn(inpaint, 5, 5, CV_FUNC2),
BIFn(insertChannel, 3, 3, CV_FUNC2),
BIFn(integral, 2, 6, CV_FUNC2),
BIFn(intersectConvexConvex, 3, 4, CV_FUNC2),
BIFn(invert, 2, 3, CV_FUNC2),
BIFn(invertAffineTransform, 2, 2, CV_FUNC2),
BIFn(isContourConvex, 1, 1, CV_FUNC2),
BIFn(kmeans, 6, 7, CV_FUNC2),
BIFn(line, 4, 7, CV_FUNC2),
BIFn(linearPolar, 5, 5, CV_FUNC2),
BIFn(log, 2, 2, CV_FUNC2),
BIFn(logPolar, 5, 5, CV_FUNC2),
BIFn(magnitude, 3, 3, CV_FUNC2),
BIFn(matMulDeriv, 4, 4, CV_FUNC2),
BIFn(matchShapes, 4, 4, CV_FUNC2),
BIFn(matchTemplate, 4, 5, CV_FUNC2),
BIFn(max, 3, 3, CV_FUNC2),
BIFn(mean, 1, 2, CV_FUNC2),
BIFn(meanShift, 3, 3, CV_FUNC2),
BIFn(meanStdDev, 3, 4, CV_FUNC2),
BIFn(medianBlur, 3, 3, CV_FUNC2),
BIFn(merge, 2, 2, CV_FUNC2),
BIFn(min, 3, 3, CV_FUNC2),
BIFn(minAreaRect, 1, 1, CV_FUNC2),
BIFn(minEnclosingCircle, 3, 3, CV_FUNC2),
BIFn(minEnclosingTriangle, 2, 2, CV_FUNC2),
BIFn(minMaxLoc, 2, 6, CV_FUNC2),
BIFn(mixChannels, 3, 3, CV_FUNC2),
BIFn(moments, 1, 2, CV_FUNC2),
BIFn(morphologyEx, 4, 8, CV_FUNC2),
BIFn(moveWindow, 3, 3, CV_FUNC2),
BIFn(mulSpectrums, 4, 5, CV_FUNC2),
BIFn(mulTransposed, 3, 6, CV_FUNC2),
BIFn(multiply, 3, 5, CV_FUNC2),
BIFn(namedWindow, 1, 2, CV_FUNC2),
BIFn(norm, 1, 4, CV_FUNC2),
BIFn(normalize, 2, 7, CV_FUNC2),
BIFn(patchNaNs, 1, 2, CV_FUNC2),
BIFn(pencilSketch, 3, 6, CV_FUNC2),
BIFn(perspectiveTransform, 3, 3, CV_FUNC2),
BIFn(phase, 3, 4, CV_FUNC2),
BIFn(phaseCorrelate, 2, 4, CV_FUNC2),
BIFn(pointPolygonTest, 3, 3, CV_FUNC2),
BIFn(polarToCart, 4, 5, CV_FUNC2),
BIFn(pollKey, 0, 0, CV_FUNC2),
BIFn(polylines, 4, 7, CV_FUNC2),
BIFn(pow, 3, 3, CV_FUNC2),
BIFn(preCornerDetect, 3, 4, CV_FUNC2),
BIFn(projectPoints, 6, 8, CV_FUNC2),
BIFn(putText, 6, 9, CV_FUNC2),
BIFn(pyrDown, 2, 4, CV_FUNC2),
BIFn(pyrMeanShiftFiltering, 4, 6, CV_FUNC2),
BIFn(pyrUp, 2, 4, CV_FUNC2),
BIFn(randShuffle, 1, 3, CV_FUNC2),
BIFn(randn, 3, 3, CV_FUNC2),
BIFn(randu, 3, 3, CV_FUNC2),
BIFn(readOpticalFlow, 1, 1, CV_FUNC2),
BIFn(recoverPose, 5, 13, CV_FUNC2),
BIFn(rectangle, 3, 7, CV_FUNC2),
BIFn(rectify3Collinear, 25, 25, CV_FUNC2),
BIFn(reduce, 4, 5, CV_FUNC2),
BIFn(reduceArgMax, 3, 4, CV_FUNC2),
BIFn(reduceArgMin, 3, 4, CV_FUNC2),
BIFn(remap, 5, 7, CV_FUNC2),
BIFn(repeat, 4, 4, CV_FUNC2),
BIFn(reprojectImageTo3D, 3, 5, CV_FUNC2),
BIFn(resize, 3, 6, CV_FUNC2),
BIFn(resizeWindow, 2, 3, CV_FUNC2),
BIFn(rotate, 3, 3, CV_FUNC2),
BIFn(rotatedRectangleIntersection, 3, 3, CV_FUNC2),
BIFn(sampsonDistance, 3, 3, CV_FUNC2),
BIFn(scaleAdd, 4, 4, CV_FUNC2),
BIFn(seamlessClone, 6, 6, CV_FUNC2),
BIFn(selectROI, 1, 4, CV_FUNC2),
BIFn(selectROIs, 3, 5, CV_FUNC2),
BIFn(sepFilter2D, 5, 8, CV_FUNC2),
BIFn(setIdentity, 1, 2, CV_FUNC2),
BIFn(setLogLevel, 1, 1, CV_FUNC2),
BIFn(setNumThreads, 1, 1, CV_FUNC2),
BIFn(setMouseCallback, 2, 2, CV_FUNC2),
BIFn(setRNGSeed, 1, 1, CV_FUNC2),
BIFn(setTrackbarMax, 3, 3, CV_FUNC2),
BIFn(setTrackbarMin, 3, 3, CV_FUNC2),
BIFn(setTrackbarPos, 3, 3, CV_FUNC2),
BIFn(setUseOpenVX, 1, 1, CV_FUNC2),
BIFn(setUseOptimized, 1, 1, CV_FUNC2),
BIFn(setWindowProperty, 3, 3, CV_FUNC2),
BIFn(setWindowTitle, 2, 2, CV_FUNC2),
BIFn(solve, 3, 4, CV_FUNC2),
BIFn(solveCubic, 2, 2, CV_FUNC2),
BIFn(solveLP, 3, 3, CV_FUNC2),
BIFn(solveP3P, 7, 7, CV_FUNC2),
BIFn(solvePnP, 6, 8, CV_FUNC2),
BIFn(solvePnPGeneric, 6, 11, CV_FUNC2),
BIFn(solvePnPRansac, 6, 12, CV_FUNC2),
BIFn(solvePnPRefineLM, 6, 7, CV_FUNC2),
BIFn(solvePnPRefineVVS, 6, 8, CV_FUNC2),
BIFn(solvePoly, 2, 3, CV_FUNC2),
BIFn(sort, 3, 3, CV_FUNC2),
BIFn(sortIdx, 3, 3, CV_FUNC2),
BIFn(spatialGradient, 3, 5, CV_FUNC2),
BIFn(split, 2, 2, CV_FUNC2),
BIFn(sqrBoxFilter, 4, 7, CV_FUNC2),
BIFn(sqrt, 2, 2, CV_FUNC2),
BIFn(startWindowThread, 0, 0, CV_FUNC2),
BIFn(stereoCalibrate, 12, 15, CV_FUNC2),
BIFn(stereoRectify, 12, 17, CV_FUNC2),
BIFn(stereoRectifyUncalibrated, 6, 7, CV_FUNC2),
BIFn(stylization, 2, 4, CV_FUNC2),
BIFn(subtract, 3, 5, CV_FUNC2),
BIFn(sum, 1, 1, CV_FUNC2),
BIFn(textureFlattening, 3, 6, CV_FUNC2),
BIFn(threshold, 5, 5, CV_FUNC2),
BIFn(trace, 1, 1, CV_FUNC2),
BIFn(transform, 3, 3, CV_FUNC2),
BIFn(transpose, 2, 2, CV_FUNC2),
BIFn(triangulatePoints, 5, 5, CV_FUNC2),
BIFn(undistort, 4, 5, CV_FUNC2),
BIFn(undistortPoints, 4, 7, CV_FUNC2),
BIFn(useOpenVX, 0, 0, CV_FUNC2),
BIFn(useOptimized, 0, 0, CV_FUNC2),
BIFn(validateDisparity, 4, 5, CV_FUNC2),
BIFn(vconcat, 2, 2, CV_FUNC2),
BIFn(waitKey, 0, 1, CV_FUNC2),
BIFn(waitKeyEx, 0, 1, CV_FUNC2),
BIFn(warpAffine, 4, 7, CV_FUNC2),
BIFn(warpPerspective, 4, 7, CV_FUNC2),
BIFn(warpPolar, 6, 6, CV_FUNC2),
BIFn(watershed, 2, 2, CV_FUNC2),
BIFn(wrapperEMD, 3, 6, CV_FUNC2),
BIFn(writeOpticalFlow, 2, 2, CV_FUNC2),
};


FuncEntry CV_CUDA_Funcs[] = {
BIFn(createContinuous, 4, 4, CV_CUDA_FUNC),
BIFn(ensureSizeIsEnough, 4, 4, CV_CUDA_FUNC),
BIFn(getCudaEnabledDeviceCount, 0, 0, CV_CUDA_FUNC),
BIFn(getDevice, 0, 0, CV_CUDA_FUNC),
BIFn(printCudaDeviceInfo, 1, 1, CV_CUDA_FUNC),
BIFn(printShortCudaDeviceInfo, 1, 1, CV_CUDA_FUNC),
BIFn(registerPageLocked, 1, 1, CV_CUDA_FUNC),
BIFn(resetDevice, 0, 0, CV_CUDA_FUNC),
BIFn(setBufferPoolConfig, 3, 3, CV_CUDA_FUNC),
BIFn(setBufferPoolUsage, 1, 1, CV_CUDA_FUNC),
BIFn(setDevice, 1, 1, CV_CUDA_FUNC),
BIFn(unregisterPageLocked, 1, 1, CV_CUDA_FUNC),
};


FuncEntry CV_DETAIL_Funcs[] = {
BIFn(calibrateRotatingCamera, 2, 2, CV_DETAIL_FUNC),
BIFn(computeImageFeatures, 3, 4, CV_DETAIL_FUNC),
BIFn(computeImageFeatures2, 3, 4, CV_DETAIL_FUNC),
BIFn(createLaplacePyr, 3, 3, CV_DETAIL_FUNC),
BIFn(createLaplacePyrGpu, 3, 3, CV_DETAIL_FUNC),
BIFn(createWeightMap, 3, 3, CV_DETAIL_FUNC),
BIFn(focalsFromHomography, 5, 5, CV_DETAIL_FUNC),
BIFn(leaveBiggestComponent, 3, 3, CV_DETAIL_FUNC),
BIFn(matchesGraphAsString, 3, 3, CV_DETAIL_FUNC),
BIFn(normalizeUsingWeightMap, 2, 2, CV_DETAIL_FUNC),
BIFn(overlapRoi, 5, 5, CV_DETAIL_FUNC),
BIFn(restoreImageFromLaplacePyr, 1, 1, CV_DETAIL_FUNC),
BIFn(restoreImageFromLaplacePyrGpu, 1, 1, CV_DETAIL_FUNC),
BIFn(resultRoi, 2, 2, CV_DETAIL_FUNC),
BIFn(resultRoiIntersection, 2, 2, CV_DETAIL_FUNC),
BIFn(resultTl, 1, 1, CV_DETAIL_FUNC),
BIFn(selectRandomSubset, 3, 3, CV_DETAIL_FUNC),
BIFn(stitchingLogLevel, 0, 0, CV_DETAIL_FUNC),
BIFn(waveCorrect, 2, 2, CV_DETAIL_FUNC),
};


FuncEntry CV_DNN_Funcs[] = {
BIFn(NMSBoxes, 5, 7, CV_DNN_FUNC),
BIFn(NMSBoxesRotated, 5, 7, CV_DNN_FUNC),
BIFn(blobFromImage, 1, 7, CV_DNN_FUNC),
BIFn(blobFromImages, 1, 7, CV_DNN_FUNC),
BIFn(getAvailableTargets, 1, 1, CV_DNN_FUNC),
BIFn(imagesFromBlob, 2, 2, CV_DNN_FUNC),
BIFn(readNet, 1, 3, CV_DNN_FUNC),
BIFn(readNetFromCaffe, 1, 2, CV_DNN_FUNC),
BIFn(readNetFromDarknet, 1, 2, CV_DNN_FUNC),
BIFn(readNetFromModelOptimizer, 2, 2, CV_DNN_FUNC),
BIFn(readNetFromONNX, 1, 1, CV_DNN_FUNC),
BIFn(readNetFromTensorflow, 1, 2, CV_DNN_FUNC),
BIFn(readNetFromTorch, 1, 3, CV_DNN_FUNC),
BIFn(readTensorFromONNX, 1, 1, CV_DNN_FUNC),
BIFn(readTorchBlob, 1, 2, CV_DNN_FUNC),
BIFn(shrinkCaffeModel, 2, 3, CV_DNN_FUNC),
BIFn(softNMSBoxes, 6, 9, CV_DNN_FUNC),
BIFn(writeTextGraph, 2, 2, CV_DNN_FUNC),
};


FuncEntry CV_FISHEYE_Funcs[] = {
BIFn(calibrate, 7, 9, CV_FISHEYE_FUNC),
BIFn(distortPoints, 4, 5, CV_FISHEYE_FUNC),
BIFn(estimateNewCameraMatrixForUndistortRectify, 5, 8, CV_FISHEYE_FUNC),
BIFi(initUndistortRectifyMap, 8, 8, CV_FISHEYE_FUNC, FID_fisheye_initUndistortRectifyMap),
BIFi(projectPoints, 6, 8, CV_FISHEYE_FUNC, FID_fisheye_projectPoints),
BIFi(stereoCalibrate, 10, 12, CV_FISHEYE_FUNC, FID_fisheye_stereoCalibrate),
BIFi(stereoRectify, 13, 16, CV_FISHEYE_FUNC, FID_fisheye_stereoRectify),
BIFn(undistortImage, 4, 6, CV_FISHEYE_FUNC),
BIFi(undistortPoints, 4, 6, CV_FISHEYE_FUNC, FID_undistortPoints),
};


FuncEntry CV_GAPI_Funcs[] = {
BIFn(BGR2RGB, 1, 1, CV_GAPI_FUNC),
BIFn(RGB2Gray, 1, 1, CV_GAPI_FUNC),
BIFi(add, 2, 3, CV_GAPI_FUNC, FID_gapi_add),
BIFn(addC, 2, 3, CV_GAPI_FUNC),
BIFi(boundingRect, 1, 1, CV_GAPI_FUNC, FID_gapi_boundingRect),
BIFn(copy, 1, 1, CV_GAPI_FUNC),
//BIFn(goodFeaturesToTrack, 4, 8, CV_GAPI_FUNC),
//BIFn(kmeans, 5, 6, CV_GAPI_FUNC),
BIFi(mean, 1, 1, CV_GAPI_FUNC, FID_gapi_mean),
BIFi(medianBlur, 2, 2, CV_GAPI_FUNC, FID_gapi_medianBlur),
//BIFn(parseSSD, 2, 5, CV_GAPI_FUNC),
//BIFn(parseYolo, 2, 5, CV_GAPI_FUNC),
BIFi(resize, 2, 5, CV_GAPI_FUNC,FID_gapi_resize),
BIFn(split3, 1, 1, CV_GAPI_FUNC),
BIFi(threshold, 3, 3, CV_GAPI_FUNC, FID_gapi_threshold),
};


FuncEntry CV_GAPI_CORE_CPU_Funcs[] = {
BIFn(kernels, 0, 0, CV_GAPI_CORE_CPU_FUNC),
};


FuncEntry CV_GAPI_CORE_FLUID_Funcs[] = {
BIFi(kernels, 0, 0, CV_GAPI_CORE_FLUID_FUNC, FID_fluid_kernels),
};


FuncEntry CV_GAPI_CORE_OCL_Funcs[] = {
BIFi(kernels, 0, 0, CV_GAPI_CORE_OCL_FUNC, FID_ocl_kernels),
};


FuncEntry CV_GAPI_IE_Funcs[] = {
BIFn(params, 3, 4, CV_GAPI_IE_FUNC),
};


FuncEntry CV_GAPI_RENDER_OCV_Funcs[] = {
BIFi(kernels, 0, 0, CV_GAPI_RENDER_OCV_FUNC, FID_ocv_kernels),
};


FuncEntry CV_GAPI_STREAMING_Funcs[] = {
BIFn(size, 1, 1, CV_GAPI_STREAMING_FUNC),
};

/*
FuncEntry CV_GAPI_WIP_Funcs[] = {
BIFn(make_capture_src, 1, 1, CV_GAPI_WIP_FUNC),
};


FuncEntry CV_GAPI_WIP_DRAW_Funcs[] = {
BIFn(render, 2, 4, CV_GAPI_WIP_DRAW_FUNC),
BIFn(render3ch, 2, 2, CV_GAPI_WIP_DRAW_FUNC),
BIFn(renderNV12, 3, 3, CV_GAPI_WIP_DRAW_FUNC),
};
*/

FuncEntry CV_IPP_Funcs[] = {
BIFn(getIppVersion, 0, 0, CV_IPP_FUNC),
BIFn(setUseIPP, 1, 1, CV_IPP_FUNC),
BIFn(setUseIPP_NotExact, 1, 1, CV_IPP_FUNC),
BIFn(useIPP, 0, 0, CV_IPP_FUNC),
BIFn(useIPP_NotExact, 0, 0, CV_IPP_FUNC),
};


FuncEntry CV_OCL_Funcs[] = {
BIFn(finish, 0, 0, CV_OCL_FUNC),
BIFn(haveAmdBlas, 0, 0, CV_OCL_FUNC),
BIFn(haveAmdFft, 0, 0, CV_OCL_FUNC),
BIFn(haveOpenCL, 0, 0, CV_OCL_FUNC),
BIFn(setUseOpenCL, 1, 1, CV_OCL_FUNC),
BIFn(useOpenCL, 0, 0, CV_OCL_FUNC),
};


FuncEntry CV_PARALLEL_Funcs[] = {
BIFn(setParallelForBackend, 1, 2, CV_PARALLEL_FUNC),
};


FuncEntry CV_SAMPLES_Funcs[] = {
BIFn(addSamplesDataSearchPath, 1, 1, CV_SAMPLES_FUNC),
BIFn(addSamplesDataSearchSubDirectory, 1, 1, CV_SAMPLES_FUNC),
BIFn(findFile, 1, 3, CV_SAMPLES_FUNC),
BIFn(findFileOrKeep, 1, 2, CV_SAMPLES_FUNC),
};


FuncEntry CV_UTILS_Funcs[] = {
BIFn(dumpBool, 1, 1, CV_UTILS_FUNC),
BIFn(dumpCString, 1, 1, CV_UTILS_FUNC),
BIFn(dumpDouble, 1, 1, CV_UTILS_FUNC),
BIFn(dumpFloat, 1, 1, CV_UTILS_FUNC),
BIFn(dumpInputArray, 1, 1, CV_UTILS_FUNC),
BIFn(dumpInputArrayOfArrays, 1, 1, CV_UTILS_FUNC),
BIFn(dumpInputOutputArray, 1, 1, CV_UTILS_FUNC),
BIFn(dumpInputOutputArrayOfArrays, 1, 1, CV_UTILS_FUNC),
BIFn(dumpInt, 1, 1, CV_UTILS_FUNC),
BIFn(dumpRange, 1, 1, CV_UTILS_FUNC),
BIFn(dumpRect, 1, 1, CV_UTILS_FUNC),
BIFn(dumpRotatedRect, 1, 1, CV_UTILS_FUNC),
BIFn(dumpSizeT, 1, 1, CV_UTILS_FUNC),
BIFn(dumpString, 1, 1, CV_UTILS_FUNC),
BIFn(dumpTermCriteria, 1, 1, CV_UTILS_FUNC),
BIFn(dumpVectorOfDouble, 1, 1, CV_UTILS_FUNC),
BIFn(dumpVectorOfInt, 1, 1, CV_UTILS_FUNC),
BIFn(dumpVectorOfRect, 1, 1, CV_UTILS_FUNC),
BIFn(generateVectorOfInt, 2, 2, CV_UTILS_FUNC),
BIFn(generateVectorOfMat, 5, 5, CV_UTILS_FUNC),
BIFn(generateVectorOfRect, 2, 2, CV_UTILS_FUNC),
BIFn(testAsyncArray, 1, 1, CV_UTILS_FUNC),
BIFn(testAsyncException, 0, 0, CV_UTILS_FUNC),
BIFn(testOverloadResolution, 1, 2, CV_UTILS_FUNC),
BIFn(testOverwriteNativeMethod, 1, 1, CV_UTILS_FUNC),
BIFn(testRaiseGeneralException, 0, 0, CV_UTILS_FUNC),
BIFn(testReservedKeywordConversion, 1, 3, CV_UTILS_FUNC),
BIFn(testRotatedRect, 5, 5, CV_UTILS_FUNC),
BIFn(testRotatedRectVector, 5, 5, CV_UTILS_FUNC),
};


FuncEntry CV_UTILS_FS_Funcs[] = {
BIFn(getCacheDirectoryForDownloads, 0, 0, CV_UTILS_FS_FUNC),
};


FuncEntry CV_VIDEOIO_REGISTRY_Funcs[] = {
BIFn(getBackendName, 1, 1, CV_VIDEOIO_REGISTRY_FUNC),
BIFn(getBackends, 0, 0, CV_VIDEOIO_REGISTRY_FUNC),
BIFn(getCameraBackendPluginVersion, 3, 3, CV_VIDEOIO_REGISTRY_FUNC),
BIFn(getCameraBackends, 0, 0, CV_VIDEOIO_REGISTRY_FUNC),
BIFn(getStreamBackendPluginVersion, 3, 3, CV_VIDEOIO_REGISTRY_FUNC),
BIFn(getStreamBackends, 0, 0, CV_VIDEOIO_REGISTRY_FUNC),
BIFn(getWriterBackendPluginVersion, 3, 3, CV_VIDEOIO_REGISTRY_FUNC),
BIFn(getWriterBackends, 0, 0, CV_VIDEOIO_REGISTRY_FUNC),
BIFn(hasBackend, 1, 1, CV_VIDEOIO_REGISTRY_FUNC),
BIFn(isBackendBuiltIn, 1, 1, CV_VIDEOIO_REGISTRY_FUNC),
};





extern "C" __declspec(dllexport) void* opencv_init(IAhkApi* api) {
#define ADDCLASS(cls, ...) o.SetValue(g_ahkapi->Class_New(_T(#cls), sizeof(cls), cls::sMember, cls::sMemberCount, cls::sPrototype, __VA_ARGS__));\
	g_ahkapi->Object_SetProp(_cv, _T(#cls), o, true), o.object->Release();\
	cls::sPrototype->OnDispose = []() { cls::sPrototype = nullptr; };
	
#define ADDCLASS2(name, cls, ...) o.SetValue(g_ahkapi->Class_New(_T(name), sizeof(cls), cls::sMember, cls::sMemberCount, cls::sPrototype, __VA_ARGS__));\
	g_ahkapi->Object_SetProp(_cv, _T(name), o, true), o.object->Release();\
	cls::sPrototype->OnDispose = []() { cls::sPrototype = nullptr; };

	if (g_ahkapi = api) {
		ExprTokenType param, * params[] = { &param };
		param.SetValue(_T("cv"));
		Object* _cv = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Module, params, 1);
		ExprTokenType o{};

		// init classes
		{
			Object* t = g_ahkapi->Class_New(_T("Vector"), sizeof(VectorBase), nullptr, 0, VectorBase::sPrototype);
			ADDCLASS2("Vector_double", Vector<double>, VectorBase::sPrototype);
			ADDCLASS2("Vector_float", Vector<float>, VectorBase::sPrototype);
			ADDCLASS2("Vector_int", Vector<int>, VectorBase::sPrototype);
			ADDCLASS2("Vector_Mat", Vector<cv::Mat>, VectorBase::sPrototype);
			ADDCLASS2("Vector_Point", Vector<cv::Point>, VectorBase::sPrototype);
			ADDCLASS2("Vector_Point2f", Vector<cv::Point2f>, VectorBase::sPrototype);
			ADDCLASS2("Vector_Rect", Vector<cv::Rect>, VectorBase::sPrototype);
			ADDCLASS2("Vector_Rect2d", Vector<cv::Rect2d>, VectorBase::sPrototype);
			ADDCLASS2("Vector_RotatedRect", Vector<cv::RotatedRect>, VectorBase::sPrototype);
			ADDCLASS2("Vector_Size", Vector<cv::Size>, VectorBase::sPrototype);
			ADDCLASS2("Vector_uchar", Vector<uchar>, VectorBase::sPrototype);
			ADDCLASS2("Vector_UMat", Vector<cv::UMat>, VectorBase::sPrototype);
			ADDCLASS2("Vector_Vec2b", Vector<cv::Vec2b>, VectorBase::sPrototype);
			ADDCLASS2("Vector_Vec2d", Vector<cv::Vec2d>, VectorBase::sPrototype);
			ADDCLASS2("Vector_Vec2f", Vector<cv::Vec2f>, VectorBase::sPrototype);
			ADDCLASS2("Vector_Vec2i", Vector<cv::Vec2i>, VectorBase::sPrototype);
			ADDCLASS2("Vector_Vec2s", Vector<cv::Vec2s>, VectorBase::sPrototype);
			ADDCLASS2("Vector_Vec2w", Vector<cv::Vec2w>, VectorBase::sPrototype);
			ADDCLASS2("Vector_Vec3b", Vector<cv::Vec3b>, VectorBase::sPrototype);
			ADDCLASS2("Vector_Vec3d", Vector<cv::Vec3d>, VectorBase::sPrototype);
			ADDCLASS2("Vector_Vec3f", Vector<cv::Vec3f>, VectorBase::sPrototype);
			ADDCLASS2("Vector_Vec3i", Vector<cv::Vec3i>, VectorBase::sPrototype);
			ADDCLASS2("Vector_Vec3s", Vector<cv::Vec3s>, VectorBase::sPrototype);
			ADDCLASS2("Vector_Vec3w", Vector<cv::Vec3w>, VectorBase::sPrototype);
			ADDCLASS2("Vector_Vec4b", Vector<cv::Vec4b>, VectorBase::sPrototype);
			ADDCLASS2("Vector_Vec4d", Vector<cv::Vec4d>, VectorBase::sPrototype);
			ADDCLASS2("Vector_Vec4f", Vector<cv::Vec4f>, VectorBase::sPrototype);
			ADDCLASS2("Vector_Vec4i", Vector<cv::Vec4i>, VectorBase::sPrototype);
			ADDCLASS2("Vector_Vec4s", Vector<cv::Vec4s>, VectorBase::sPrototype);
			ADDCLASS2("Vector_Vec4w", Vector<cv::Vec4w>, VectorBase::sPrototype);
			ADDCLASS2("Vector_Vec6d", Vector<cv::Vec6d>, VectorBase::sPrototype);
			ADDCLASS2("Vector_Vec6f", Vector<cv::Vec6f>, VectorBase::sPrototype);
			ADDCLASS2("Vector_Vec6i", Vector<cv::Vec6i>, VectorBase::sPrototype);
			ADDCLASS2("Vector_Vec8i", Vector<cv::Vec8i>, VectorBase::sPrototype);
			ADDCLASS2("Vector_Vector_int", Vector<std::vector<int>>, VectorBase::sPrototype);
			ADDCLASS2("Vector_Vector_Point", Vector<std::vector<cv::Point>>, VectorBase::sPrototype);
			ADDCLASS2("Vector_Vector_Point2f", Vector<std::vector<cv::Point2f>>, VectorBase::sPrototype);
			t->Release();

			ADDCLASS(TextDraw);
			ADDCLASS(Mat);
			ADDCLASS(UMat);
			ADDCLASS(Algorithm);
			ADDCLASS(Feature2D, Algorithm::sPrototype);
			ADDCLASS(AKAZE, Feature2D::sPrototype);
			ADDCLASS(AffineFeature, Feature2D::sPrototype);
			ADDCLASS(AgastFeatureDetector, Feature2D::sPrototype);
			ADDCLASS(AlignExposures, Algorithm::sPrototype);
			ADDCLASS(AlignMTB, AlignExposures::sPrototype);
			ADDCLASS(AsyncArray);
			ADDCLASS(DescriptorMatcher, Algorithm::sPrototype);
			ADDCLASS(BFMatcher, DescriptorMatcher::sPrototype);
			ADDCLASS(BOWImgDescriptorExtractor);
			ADDCLASS(BOWTrainer);
			ADDCLASS(BOWKMeansTrainer, BOWTrainer::sPrototype);
			ADDCLASS(BRISK, Feature2D::sPrototype);
			ADDCLASS(BackgroundSubtractor, Algorithm::sPrototype);
			ADDCLASS(BackgroundSubtractorKNN, BackgroundSubtractor::sPrototype);
			ADDCLASS(BackgroundSubtractorMOG2, BackgroundSubtractor::sPrototype);
			ADDCLASS(BaseCascadeClassifier, Algorithm::sPrototype);
			ADDCLASS(CLAHE, Algorithm::sPrototype);
			ADDCLASS(CalibrateCRF, Algorithm::sPrototype);
			ADDCLASS(CalibrateDebevec, CalibrateCRF::sPrototype);
			ADDCLASS(CalibrateRobertson, CalibrateCRF::sPrototype);
			ADDCLASS(CascadeClassifier);
			ADDCLASS(DenseOpticalFlow, Algorithm::sPrototype);
			ADDCLASS(DISOpticalFlow, DenseOpticalFlow::sPrototype);
			ADDCLASS(DMatch);
			ADDCLASS(FaceDetectorYN);
			ADDCLASS(FaceRecognizerSF);
			ADDCLASS(FarnebackOpticalFlow, DenseOpticalFlow::sPrototype);
			ADDCLASS(FastFeatureDetector, Feature2D::sPrototype);
			ADDCLASS(FileNode);
			ADDCLASS(FileStorage);
			ADDCLASS(FlannBasedMatcher, DescriptorMatcher::sPrototype);
			ADDCLASS(GFTTDetector, Feature2D::sPrototype);
			ADDCLASS(GFrame);
			ADDCLASS(GMat);
			ADDCLASS(GScalar);
			ADDCLASS(GStreamingCompiled);
			ADDCLASS(GeneralizedHough, Algorithm::sPrototype);
			ADDCLASS(GeneralizedHoughBallard, GeneralizedHough::sPrototype);
			ADDCLASS(GeneralizedHoughGuil, GeneralizedHough::sPrototype);
			ADDCLASS(KAZE, Feature2D::sPrototype);
			ADDCLASS(KalmanFilter);
			ADDCLASS(KeyPoint);
			ADDCLASS(LineSegmentDetector, Algorithm::sPrototype);
			ADDCLASS(MSER, Feature2D::sPrototype);
			ADDCLASS(MergeExposures, Algorithm::sPrototype);
			ADDCLASS(MergeDebevec, MergeExposures::sPrototype);
			ADDCLASS(MergeMertens, MergeExposures::sPrototype);
			ADDCLASS(MergeRobertson, MergeExposures::sPrototype);
			ADDCLASS(Moments);
			ADDCLASS(ORB, Feature2D::sPrototype);
			ADDCLASS(PyRotationWarper);
			ADDCLASS(QRCodeDetector);
			ADDCLASS(QRCodeEncoder);
			ADDCLASS(SIFT, Feature2D::sPrototype);
			ADDCLASS(SimpleBlobDetector, Feature2D::sPrototype);
			ADDCLASS(SparseOpticalFlow, Algorithm::sPrototype);
			ADDCLASS(SparsePyrLKOpticalFlow, SparseOpticalFlow::sPrototype);
			ADDCLASS(StereoMatcher, Algorithm::sPrototype);
			ADDCLASS(StereoBM, StereoMatcher::sPrototype);
			ADDCLASS(StereoSGBM, StereoMatcher::sPrototype);
			ADDCLASS(Stitcher);
			ADDCLASS(Subdiv2D);
			ADDCLASS(TickMeter);
			ADDCLASS(Tonemap, Algorithm::sPrototype);
			ADDCLASS(TonemapDrago, Tonemap::sPrototype);
			ADDCLASS(TonemapMantiuk, Tonemap::sPrototype);
			ADDCLASS(TonemapReinhard, Tonemap::sPrototype);
			ADDCLASS(Tracker);
			ADDCLASS(TrackerDaSiamRPN, Tracker::sPrototype);
			ADDCLASS(TrackerGOTURN, Tracker::sPrototype);
			ADDCLASS(TrackerMIL, Tracker::sPrototype);
			ADDCLASS(VariationalRefinement, DenseOpticalFlow::sPrototype);
			ADDCLASS(VideoCapture);
			ADDCLASS(VideoWriter);
			ADDCLASS(WarperCreator);
			ADDCLASS(cuda_BufferPool);
			ADDCLASS(cuda_DeviceInfo);
			ADDCLASS(cuda_Event);
			ADDCLASS(cuda_GpuMat);
			ADDCLASS(cuda_GpuMat_Allocator);
			ADDCLASS(cuda_GpuMatND);
			ADDCLASS(cuda_HostMem);
			ADDCLASS(cuda_Stream);
			ADDCLASS(cuda_TargetArchs);
			ADDCLASS(detail_Estimator);
			ADDCLASS(detail_AffineBasedEstimator, detail_Estimator::sPrototype);
			ADDCLASS(detail_FeaturesMatcher);
			ADDCLASS(detail_BestOf2NearestMatcher, detail_FeaturesMatcher::sPrototype);
			ADDCLASS(detail_AffineBestOf2NearestMatcher, detail_BestOf2NearestMatcher::sPrototype);
			ADDCLASS(detail_BestOf2NearestRangeMatcher, detail_BestOf2NearestMatcher::sPrototype);
			ADDCLASS(detail_Blender);
			ADDCLASS(detail_ExposureCompensator);
			ADDCLASS(detail_BlocksCompensator, detail_ExposureCompensator::sPrototype);
			ADDCLASS(detail_BlocksChannelsCompensator, detail_BlocksCompensator::sPrototype);
			ADDCLASS(detail_BlocksGainCompensator, detail_BlocksCompensator::sPrototype);
			ADDCLASS(detail_BundleAdjusterBase, detail_Estimator::sPrototype);
			ADDCLASS(detail_BundleAdjusterAffine, detail_BundleAdjusterBase::sPrototype);
			ADDCLASS(detail_BundleAdjusterAffinePartial, detail_BundleAdjusterBase::sPrototype);
			ADDCLASS(detail_BundleAdjusterRay, detail_BundleAdjusterBase::sPrototype);
			ADDCLASS(detail_BundleAdjusterReproj, detail_BundleAdjusterBase::sPrototype);
			ADDCLASS(detail_ChannelsCompensator, detail_ExposureCompensator::sPrototype);
			ADDCLASS(detail_SeamFinder);
			ADDCLASS(detail_DpSeamFinder, detail_SeamFinder::sPrototype);
			ADDCLASS(detail_FeatherBlender, detail_Blender::sPrototype);
			ADDCLASS(detail_GainCompensator, detail_ExposureCompensator::sPrototype);
			ADDCLASS(detail_GraphCutSeamFinder, detail_SeamFinder::sPrototype);
			ADDCLASS(detail_HomographyBasedEstimator, detail_Estimator::sPrototype);
			ADDCLASS(detail_MultiBandBlender, detail_Blender::sPrototype);
			ADDCLASS(detail_NoBundleAdjuster, detail_BundleAdjusterBase::sPrototype);
			ADDCLASS(detail_NoExposureCompensator, detail_ExposureCompensator::sPrototype);
			ADDCLASS(detail_NoSeamFinder, detail_SeamFinder::sPrototype);
			ADDCLASS(detail_PairwiseSeamFinder, detail_SeamFinder::sPrototype);
			ADDCLASS(detail_Timelapser);
			ADDCLASS(detail_TimelapserCrop, detail_Timelapser::sPrototype);
			ADDCLASS(detail_VoronoiSeamFinder, detail_PairwiseSeamFinder::sPrototype);
			ADDCLASS(dnn_Model);
			ADDCLASS(dnn_ClassificationModel, dnn_Model::sPrototype);
			ADDCLASS(dnn_DetectionModel, dnn_Model::sPrototype);
			ADDCLASS(dnn_KeypointsModel, dnn_Model::sPrototype);
			ADDCLASS(dnn_Layer, Algorithm::sPrototype);
			ADDCLASS(dnn_Net);
			ADDCLASS(dnn_SegmentationModel, dnn_Model::sPrototype);
			ADDCLASS(dnn_TextDetectionModel, dnn_Model::sPrototype);
			ADDCLASS(dnn_TextDetectionModel_DB, dnn_TextDetectionModel::sPrototype);
			ADDCLASS(dnn_TextDetectionModel_EAST, dnn_TextDetectionModel::sPrototype);
			ADDCLASS(dnn_TextRecognitionModel, dnn_Model::sPrototype);
			ADDCLASS(flann_Index);
			ADDCLASS(gapi_GKernelPackage);
			ADDCLASS(gapi_ie_PyParams);
			ADDCLASS(ml_StatModel, Algorithm::sPrototype);
			ADDCLASS(ml_ANN_MLP, ml_StatModel::sPrototype);
			ADDCLASS(ml_DTrees, ml_StatModel::sPrototype);
			ADDCLASS(ml_Boost, ml_DTrees::sPrototype);
			ADDCLASS(ml_EM, ml_StatModel::sPrototype);
			ADDCLASS(ml_KNearest, ml_StatModel::sPrototype);
			ADDCLASS(ml_LogisticRegression, ml_StatModel::sPrototype);
			ADDCLASS(ml_NormalBayesClassifier, ml_StatModel::sPrototype);
			ADDCLASS(ml_ParamGrid);
			ADDCLASS(ml_RTrees, ml_DTrees::sPrototype);
			ADDCLASS(ml_SVM, ml_StatModel::sPrototype);
			ADDCLASS(ml_SVMSGD, ml_StatModel::sPrototype);
			ADDCLASS(ml_TrainData);
			ADDCLASS(ocl_Device);
			ADDCLASS(ocl_OpenCLExecutionContext);
			ADDCLASS(segmentation_IntelligentScissorsMB);
			ADDCLASS(CirclesGridFinderParameters);
			ADDCLASS(GArrayDesc);
			ADDCLASS(GMatDesc);
			ADDCLASS(GOpaqueDesc);
			ADDCLASS(GScalarDesc);
			ADDCLASS(HOGDescriptor);
			ADDCLASS(QRCodeEncoder_Params);
			ADDCLASS(SimpleBlobDetector_Params);
			ADDCLASS(TrackerDaSiamRPN_Params);
			ADDCLASS(TrackerGOTURN_Params);
			ADDCLASS(TrackerMIL_Params);
			ADDCLASS(UsacParams);
			ADDCLASS(detail_CameraParams);
			ADDCLASS(detail_ImageFeatures);
			ADDCLASS(detail_MatchesInfo);
			ADDCLASS(detail_ProjectorBase);
			ADDCLASS(detail_SphericalProjector);
			ADDCLASS(dnn_DictValue);
			ADDCLASS(gapi_GNetPackage);
			ADDCLASS(gapi_GNetParam);
			ADDCLASS(gapi_streaming_queue_capacity);
			ADDCLASS(gapi_wip_draw_Circle);
			ADDCLASS(gapi_wip_draw_Image);
			ADDCLASS(gapi_wip_draw_Line);
			ADDCLASS(gapi_wip_draw_Mosaic);
			ADDCLASS(gapi_wip_draw_Poly);
			ADDCLASS(gapi_wip_draw_Rect);
			ADDCLASS(gapi_wip_draw_Text);

			ADDCLASS(RNG);
			ADDCLASS(GOpaque_Size);
			ADDCLASS(GOpaque_Rect);
		};
		


		// init funcs
		for (auto it : CV_Funcs) {
			o.object = g_ahkapi->Func_New(it);
			g_ahkapi->Object_SetProp(_cv, (LPTSTR)it.mName, o, true);
			o.object->Release();
		}

		{
			Object* mmm;
#define ADDFUNCS(func, name) o.SetValue(g_ahkapi->Object_New());\
			mmm = (Object*)o.object;\
			g_ahkapi->Object_SetProp(_cv, _T(name), o, true);\
			mmm->Release();\
			for (auto it : CV_##func) {\
				o.object = g_ahkapi->Func_New(it);\
				g_ahkapi->Object_SetProp(mmm, (LPTSTR)it.mName, o, true);\
				o.object->Release();\
			}
			ADDFUNCS(CUDA_Funcs, "cuda");
			ADDFUNCS(DETAIL_Funcs, "detail");
			ADDFUNCS(DNN_Funcs, "dnn");
			ADDFUNCS(FISHEYE_Funcs, "fisheye");
			ADDFUNCS(GAPI_Funcs, "gapi");
			ADDFUNCS(GAPI_CORE_CPU_Funcs, "gapi_core_cpu");
			ADDFUNCS(GAPI_CORE_FLUID_Funcs, "gapi_core_fluid");
			ADDFUNCS(GAPI_CORE_OCL_Funcs, "gapi_core_ocl");
			ADDFUNCS(GAPI_IE_Funcs, "gapi_ie");
			ADDFUNCS(GAPI_RENDER_OCV_Funcs, "gapi_render_ocv");
			ADDFUNCS(GAPI_STREAMING_Funcs, "gapi_streaming");
			//ADDFUNCS(GAPI_WIP_Funcs, "gapi_wip");
			//ADDFUNCS(GAPI_WIP_DRAW_Funcs, "gapi_wip_draw");
			ADDFUNCS(IPP_Funcs, "ipp");
			ADDFUNCS(OCL_Funcs, "ocl");
			ADDFUNCS(PARALLEL_Funcs, "parallel");
			ADDFUNCS(SAMPLES_Funcs, "samples");
			ADDFUNCS(UTILS_Funcs, "utils");
			ADDFUNCS(UTILS_FS_Funcs, "utils_fs");
			ADDFUNCS(VIDEOIO_REGISTRY_Funcs, "videoio_registry");

		}

		// init enums
		{
			Object* objs[10] = { _cv };
	#define SETOWNPROP(obj, name, val) g_ahkapi->Object_SetProp(obj, _T(#name), ExprTokenType{ (__int64)(int)val }, true)
	#define SETOWNPROP1(obj, name) g_ahkapi->Object_SetProp(obj, _T(#name), ExprTokenType{ (__int64)name }, true)
	#define SETOWNPROP2(obj, name, val) g_ahkapi->Object_SetProp(obj, _T(#name), ExprTokenType{ val }, true), val->Release()

			objs[1] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[0], constants, objs[1]), objs[0] = objs[1];

			SETOWNPROP1(objs[1], CV_8U);
			SETOWNPROP1(objs[1], CV_8S);
			SETOWNPROP1(objs[1], CV_16U);
			SETOWNPROP1(objs[1], CV_16S);
			SETOWNPROP1(objs[1], CV_32S);
			SETOWNPROP1(objs[1], CV_32F);
			SETOWNPROP1(objs[1], CV_64F);
			SETOWNPROP1(objs[1], CV_16F);
			SETOWNPROP1(objs[1], CV_8UC1);
			SETOWNPROP1(objs[1], CV_8UC2);
			SETOWNPROP1(objs[1], CV_8UC3);
			SETOWNPROP1(objs[1], CV_8UC4);
			SETOWNPROP1(objs[1], CV_8SC1);
			SETOWNPROP1(objs[1], CV_8SC2);
			SETOWNPROP1(objs[1], CV_8SC3);
			SETOWNPROP1(objs[1], CV_8SC4);
			SETOWNPROP1(objs[1], CV_16UC1);
			SETOWNPROP1(objs[1], CV_16UC2);
			SETOWNPROP1(objs[1], CV_16UC3);
			SETOWNPROP1(objs[1], CV_16UC4);
			SETOWNPROP1(objs[1], CV_16SC1);
			SETOWNPROP1(objs[1], CV_16SC2);
			SETOWNPROP1(objs[1], CV_16SC3);
			SETOWNPROP1(objs[1], CV_16SC4);
			SETOWNPROP1(objs[1], CV_32SC1);
			SETOWNPROP1(objs[1], CV_32SC2);
			SETOWNPROP1(objs[1], CV_32SC3);
			SETOWNPROP1(objs[1], CV_32SC4);
			SETOWNPROP1(objs[1], CV_32FC1);
			SETOWNPROP1(objs[1], CV_32FC2);
			SETOWNPROP1(objs[1], CV_32FC3);
			SETOWNPROP1(objs[1], CV_32FC4);
			SETOWNPROP1(objs[1], CV_64FC1);
			SETOWNPROP1(objs[1], CV_64FC2);
			SETOWNPROP1(objs[1], CV_64FC3);
			SETOWNPROP1(objs[1], CV_64FC4);
			SETOWNPROP1(objs[1], CV_16FC1);
			SETOWNPROP1(objs[1], CV_16FC2);
			SETOWNPROP1(objs[1], CV_16FC3);
			SETOWNPROP1(objs[1], CV_16FC4);
			SETOWNPROP1(objs[1], CV_HAL_CMP_EQ);
			SETOWNPROP1(objs[1], CV_HAL_CMP_GT);
			SETOWNPROP1(objs[1], CV_HAL_CMP_GE);
			SETOWNPROP1(objs[1], CV_HAL_CMP_LT);
			SETOWNPROP1(objs[1], CV_HAL_CMP_LE);
			SETOWNPROP1(objs[1], CV_HAL_CMP_NE);
			SETOWNPROP1(objs[1], CV_HAL_BORDER_CONSTANT);
			SETOWNPROP1(objs[1], CV_HAL_BORDER_REPLICATE);
			SETOWNPROP1(objs[1], CV_HAL_BORDER_REFLECT);
			SETOWNPROP1(objs[1], CV_HAL_BORDER_WRAP);
			SETOWNPROP1(objs[1], CV_HAL_BORDER_REFLECT_101);
			SETOWNPROP1(objs[1], CV_HAL_BORDER_TRANSPARENT);
			SETOWNPROP1(objs[1], CV_HAL_BORDER_ISOLATED);
			SETOWNPROP1(objs[1], CV_HAL_DFT_INVERSE);
			SETOWNPROP1(objs[1], CV_HAL_DFT_SCALE);
			SETOWNPROP1(objs[1], CV_HAL_DFT_ROWS);
			SETOWNPROP1(objs[1], CV_HAL_DFT_COMPLEX_OUTPUT);
			SETOWNPROP1(objs[1], CV_HAL_DFT_REAL_OUTPUT);
			SETOWNPROP1(objs[1], CV_HAL_DFT_TWO_STAGE);
			SETOWNPROP1(objs[1], CV_HAL_DFT_STAGE_COLS);
			SETOWNPROP1(objs[1], CV_HAL_DFT_IS_CONTINUOUS);
			SETOWNPROP1(objs[1], CV_HAL_DFT_IS_INPLACE);
			SETOWNPROP1(objs[1], CV_HAL_SVD_NO_UV);
			SETOWNPROP1(objs[1], CV_HAL_SVD_SHORT_UV);
			SETOWNPROP1(objs[1], CV_HAL_SVD_MODIFY_A);
			SETOWNPROP1(objs[1], CV_HAL_SVD_FULL_UV);
			SETOWNPROP1(objs[1], CV_HAL_GEMM_1_T);
			SETOWNPROP1(objs[1], CV_HAL_GEMM_2_T);
			SETOWNPROP1(objs[1], CV_HAL_GEMM_3_T);

			SETOWNPROP(objs[1], ACCESS_FAST, cv::ACCESS_FAST);
			SETOWNPROP(objs[1], ACCESS_MASK, cv::ACCESS_MASK);
			SETOWNPROP(objs[1], ACCESS_READ, cv::ACCESS_READ);
			SETOWNPROP(objs[1], ACCESS_RW, cv::ACCESS_RW);
			SETOWNPROP(objs[1], ACCESS_WRITE, cv::ACCESS_WRITE);
			SETOWNPROP(objs[1], ADAPTIVE_THRESH_GAUSSIAN_C, cv::ADAPTIVE_THRESH_GAUSSIAN_C);
			SETOWNPROP(objs[1], ADAPTIVE_THRESH_MEAN_C, cv::ADAPTIVE_THRESH_MEAN_C);
			objs[2] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[1], AKAZE, objs[2]);
			SETOWNPROP(objs[2], DESCRIPTOR_KAZE, cv::AKAZE::DESCRIPTOR_KAZE);
			SETOWNPROP(objs[2], DESCRIPTOR_KAZE_UPRIGHT, cv::AKAZE::DESCRIPTOR_KAZE_UPRIGHT);
			SETOWNPROP(objs[2], DESCRIPTOR_MLDB, cv::AKAZE::DESCRIPTOR_MLDB);
			SETOWNPROP(objs[2], DESCRIPTOR_MLDB_UPRIGHT, cv::AKAZE::DESCRIPTOR_MLDB_UPRIGHT);
			objs[2] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[1], AgastFeatureDetector, objs[2]);
			SETOWNPROP(objs[2], AGAST_5_8, cv::AgastFeatureDetector::AGAST_5_8);
			SETOWNPROP(objs[2], AGAST_7_12d, cv::AgastFeatureDetector::AGAST_7_12d);
			SETOWNPROP(objs[2], AGAST_7_12s, cv::AgastFeatureDetector::AGAST_7_12s);
			SETOWNPROP(objs[2], NONMAX_SUPPRESSION, cv::AgastFeatureDetector::NONMAX_SUPPRESSION);
			SETOWNPROP(objs[2], OAST_9_16, cv::AgastFeatureDetector::OAST_9_16);
			SETOWNPROP(objs[2], THRESHOLD, cv::AgastFeatureDetector::THRESHOLD);
			SETOWNPROP(objs[1], BORDER_CONSTANT, cv::BORDER_CONSTANT);
			SETOWNPROP(objs[1], BORDER_DEFAULT, cv::BORDER_DEFAULT);
			SETOWNPROP(objs[1], BORDER_ISOLATED, cv::BORDER_ISOLATED);
			SETOWNPROP(objs[1], BORDER_REFLECT, cv::BORDER_REFLECT);
			SETOWNPROP(objs[1], BORDER_REFLECT101, cv::BORDER_REFLECT101);
			SETOWNPROP(objs[1], BORDER_REFLECT_101, cv::BORDER_REFLECT_101);
			SETOWNPROP(objs[1], BORDER_REPLICATE, cv::BORDER_REPLICATE);
			SETOWNPROP(objs[1], BORDER_TRANSPARENT, cv::BORDER_TRANSPARENT);
			SETOWNPROP(objs[1], BORDER_WRAP, cv::BORDER_WRAP);
			SETOWNPROP(objs[1], CALIB_CB_ACCURACY, cv::CALIB_CB_ACCURACY);
			SETOWNPROP(objs[1], CALIB_CB_ADAPTIVE_THRESH, cv::CALIB_CB_ADAPTIVE_THRESH);
			SETOWNPROP(objs[1], CALIB_CB_ASYMMETRIC_GRID, cv::CALIB_CB_ASYMMETRIC_GRID);
			SETOWNPROP(objs[1], CALIB_CB_CLUSTERING, cv::CALIB_CB_CLUSTERING);
			SETOWNPROP(objs[1], CALIB_CB_EXHAUSTIVE, cv::CALIB_CB_EXHAUSTIVE);
			SETOWNPROP(objs[1], CALIB_CB_FAST_CHECK, cv::CALIB_CB_FAST_CHECK);
			SETOWNPROP(objs[1], CALIB_CB_FILTER_QUADS, cv::CALIB_CB_FILTER_QUADS);
			SETOWNPROP(objs[1], CALIB_CB_LARGER, cv::CALIB_CB_LARGER);
			SETOWNPROP(objs[1], CALIB_CB_MARKER, cv::CALIB_CB_MARKER);
			SETOWNPROP(objs[1], CALIB_CB_NORMALIZE_IMAGE, cv::CALIB_CB_NORMALIZE_IMAGE);
			SETOWNPROP(objs[1], CALIB_CB_SYMMETRIC_GRID, cv::CALIB_CB_SYMMETRIC_GRID);
			SETOWNPROP(objs[1], CALIB_FIX_ASPECT_RATIO, cv::CALIB_FIX_ASPECT_RATIO);
			SETOWNPROP(objs[1], CALIB_FIX_FOCAL_LENGTH, cv::CALIB_FIX_FOCAL_LENGTH);
			SETOWNPROP(objs[1], CALIB_FIX_INTRINSIC, cv::CALIB_FIX_INTRINSIC);
			SETOWNPROP(objs[1], CALIB_FIX_K1, cv::CALIB_FIX_K1);
			SETOWNPROP(objs[1], CALIB_FIX_K2, cv::CALIB_FIX_K2);
			SETOWNPROP(objs[1], CALIB_FIX_K3, cv::CALIB_FIX_K3);
			SETOWNPROP(objs[1], CALIB_FIX_K4, cv::CALIB_FIX_K4);
			SETOWNPROP(objs[1], CALIB_FIX_K5, cv::CALIB_FIX_K5);
			SETOWNPROP(objs[1], CALIB_FIX_K6, cv::CALIB_FIX_K6);
			SETOWNPROP(objs[1], CALIB_FIX_PRINCIPAL_POINT, cv::CALIB_FIX_PRINCIPAL_POINT);
			SETOWNPROP(objs[1], CALIB_FIX_S1_S2_S3_S4, cv::CALIB_FIX_S1_S2_S3_S4);
			SETOWNPROP(objs[1], CALIB_FIX_TANGENT_DIST, cv::CALIB_FIX_TANGENT_DIST);
			SETOWNPROP(objs[1], CALIB_FIX_TAUX_TAUY, cv::CALIB_FIX_TAUX_TAUY);
			SETOWNPROP(objs[1], CALIB_HAND_EYE_ANDREFF, cv::CALIB_HAND_EYE_ANDREFF);
			SETOWNPROP(objs[1], CALIB_HAND_EYE_DANIILIDIS, cv::CALIB_HAND_EYE_DANIILIDIS);
			SETOWNPROP(objs[1], CALIB_HAND_EYE_HORAUD, cv::CALIB_HAND_EYE_HORAUD);
			SETOWNPROP(objs[1], CALIB_HAND_EYE_PARK, cv::CALIB_HAND_EYE_PARK);
			SETOWNPROP(objs[1], CALIB_HAND_EYE_TSAI, cv::CALIB_HAND_EYE_TSAI);
			SETOWNPROP(objs[1], CALIB_NINTRINSIC, cv::CALIB_NINTRINSIC);
			SETOWNPROP(objs[1], CALIB_RATIONAL_MODEL, cv::CALIB_RATIONAL_MODEL);
			SETOWNPROP(objs[1], CALIB_ROBOT_WORLD_HAND_EYE_LI, cv::CALIB_ROBOT_WORLD_HAND_EYE_LI);
			SETOWNPROP(objs[1], CALIB_ROBOT_WORLD_HAND_EYE_SHAH, cv::CALIB_ROBOT_WORLD_HAND_EYE_SHAH);
			SETOWNPROP(objs[1], CALIB_SAME_FOCAL_LENGTH, cv::CALIB_SAME_FOCAL_LENGTH);
			SETOWNPROP(objs[1], CALIB_THIN_PRISM_MODEL, cv::CALIB_THIN_PRISM_MODEL);
			SETOWNPROP(objs[1], CALIB_TILTED_MODEL, cv::CALIB_TILTED_MODEL);
			SETOWNPROP(objs[1], CALIB_USE_EXTRINSIC_GUESS, cv::CALIB_USE_EXTRINSIC_GUESS);
			SETOWNPROP(objs[1], CALIB_USE_INTRINSIC_GUESS, cv::CALIB_USE_INTRINSIC_GUESS);
			SETOWNPROP(objs[1], CALIB_USE_LU, cv::CALIB_USE_LU);
			SETOWNPROP(objs[1], CALIB_USE_QR, cv::CALIB_USE_QR);
			SETOWNPROP(objs[1], CALIB_ZERO_DISPARITY, cv::CALIB_ZERO_DISPARITY);
			SETOWNPROP(objs[1], CALIB_ZERO_TANGENT_DIST, cv::CALIB_ZERO_TANGENT_DIST);
			SETOWNPROP(objs[1], CAP_ANDROID, cv::CAP_ANDROID);
			SETOWNPROP(objs[1], CAP_ANY, cv::CAP_ANY);
			SETOWNPROP(objs[1], CAP_ARAVIS, cv::CAP_ARAVIS);
			SETOWNPROP(objs[1], CAP_AVFOUNDATION, cv::CAP_AVFOUNDATION);
			SETOWNPROP(objs[1], CAP_CMU1394, cv::CAP_CMU1394);
			SETOWNPROP(objs[1], CAP_DC1394, cv::CAP_DC1394);
			SETOWNPROP(objs[1], CAP_DSHOW, cv::CAP_DSHOW);
			SETOWNPROP(objs[1], CAP_FFMPEG, cv::CAP_FFMPEG);
			SETOWNPROP(objs[1], CAP_FIREWARE, cv::CAP_FIREWARE);
			SETOWNPROP(objs[1], CAP_FIREWIRE, cv::CAP_FIREWIRE);
			SETOWNPROP(objs[1], CAP_GIGANETIX, cv::CAP_GIGANETIX);
			SETOWNPROP(objs[1], CAP_GPHOTO2, cv::CAP_GPHOTO2);
			SETOWNPROP(objs[1], CAP_GSTREAMER, cv::CAP_GSTREAMER);
			SETOWNPROP(objs[1], CAP_IEEE1394, cv::CAP_IEEE1394);
			SETOWNPROP(objs[1], CAP_IMAGES, cv::CAP_IMAGES);
			SETOWNPROP(objs[1], CAP_INTELPERC, cv::CAP_INTELPERC);
			SETOWNPROP(objs[1], CAP_INTELPERC_DEPTH_GENERATOR, cv::CAP_INTELPERC_DEPTH_GENERATOR);
			SETOWNPROP(objs[1], CAP_INTELPERC_DEPTH_MAP, cv::CAP_INTELPERC_DEPTH_MAP);
			SETOWNPROP(objs[1], CAP_INTELPERC_GENERATORS_MASK, cv::CAP_INTELPERC_GENERATORS_MASK);
			SETOWNPROP(objs[1], CAP_INTELPERC_IMAGE, cv::CAP_INTELPERC_IMAGE);
			SETOWNPROP(objs[1], CAP_INTELPERC_IMAGE_GENERATOR, cv::CAP_INTELPERC_IMAGE_GENERATOR);
			SETOWNPROP(objs[1], CAP_INTELPERC_IR_GENERATOR, cv::CAP_INTELPERC_IR_GENERATOR);
			SETOWNPROP(objs[1], CAP_INTELPERC_IR_MAP, cv::CAP_INTELPERC_IR_MAP);
			SETOWNPROP(objs[1], CAP_INTELPERC_UVDEPTH_MAP, cv::CAP_INTELPERC_UVDEPTH_MAP);
			SETOWNPROP(objs[1], CAP_INTEL_MFX, cv::CAP_INTEL_MFX);
			SETOWNPROP(objs[1], CAP_MSMF, cv::CAP_MSMF);
			SETOWNPROP(objs[1], CAP_OPENCV_MJPEG, cv::CAP_OPENCV_MJPEG);
			SETOWNPROP(objs[1], CAP_OPENNI, cv::CAP_OPENNI);
			SETOWNPROP(objs[1], CAP_OPENNI2, cv::CAP_OPENNI2);
			SETOWNPROP(objs[1], CAP_OPENNI2_ASTRA, cv::CAP_OPENNI2_ASTRA);
			SETOWNPROP(objs[1], CAP_OPENNI2_ASUS, cv::CAP_OPENNI2_ASUS);
			SETOWNPROP(objs[1], CAP_OPENNI_ASUS, cv::CAP_OPENNI_ASUS);
			SETOWNPROP(objs[1], CAP_OPENNI_BGR_IMAGE, cv::CAP_OPENNI_BGR_IMAGE);
			SETOWNPROP(objs[1], CAP_OPENNI_DEPTH_GENERATOR, cv::CAP_OPENNI_DEPTH_GENERATOR);
			SETOWNPROP(objs[1], CAP_OPENNI_DEPTH_GENERATOR_BASELINE, cv::CAP_OPENNI_DEPTH_GENERATOR_BASELINE);
			SETOWNPROP(objs[1], CAP_OPENNI_DEPTH_GENERATOR_FOCAL_LENGTH, cv::CAP_OPENNI_DEPTH_GENERATOR_FOCAL_LENGTH);
			SETOWNPROP(objs[1], CAP_OPENNI_DEPTH_GENERATOR_PRESENT, cv::CAP_OPENNI_DEPTH_GENERATOR_PRESENT);
			SETOWNPROP(objs[1], CAP_OPENNI_DEPTH_GENERATOR_REGISTRATION, cv::CAP_OPENNI_DEPTH_GENERATOR_REGISTRATION);
			SETOWNPROP(objs[1], CAP_OPENNI_DEPTH_GENERATOR_REGISTRATION_ON, cv::CAP_OPENNI_DEPTH_GENERATOR_REGISTRATION_ON);
			SETOWNPROP(objs[1], CAP_OPENNI_DEPTH_MAP, cv::CAP_OPENNI_DEPTH_MAP);
			SETOWNPROP(objs[1], CAP_OPENNI_DISPARITY_MAP, cv::CAP_OPENNI_DISPARITY_MAP);
			SETOWNPROP(objs[1], CAP_OPENNI_DISPARITY_MAP_32F, cv::CAP_OPENNI_DISPARITY_MAP_32F);
			SETOWNPROP(objs[1], CAP_OPENNI_GENERATORS_MASK, cv::CAP_OPENNI_GENERATORS_MASK);
			SETOWNPROP(objs[1], CAP_OPENNI_GRAY_IMAGE, cv::CAP_OPENNI_GRAY_IMAGE);
			SETOWNPROP(objs[1], CAP_OPENNI_IMAGE_GENERATOR, cv::CAP_OPENNI_IMAGE_GENERATOR);
			SETOWNPROP(objs[1], CAP_OPENNI_IMAGE_GENERATOR_OUTPUT_MODE, cv::CAP_OPENNI_IMAGE_GENERATOR_OUTPUT_MODE);
			SETOWNPROP(objs[1], CAP_OPENNI_IMAGE_GENERATOR_PRESENT, cv::CAP_OPENNI_IMAGE_GENERATOR_PRESENT);
			SETOWNPROP(objs[1], CAP_OPENNI_IR_GENERATOR, cv::CAP_OPENNI_IR_GENERATOR);
			SETOWNPROP(objs[1], CAP_OPENNI_IR_GENERATOR_PRESENT, cv::CAP_OPENNI_IR_GENERATOR_PRESENT);
			SETOWNPROP(objs[1], CAP_OPENNI_IR_IMAGE, cv::CAP_OPENNI_IR_IMAGE);
			SETOWNPROP(objs[1], CAP_OPENNI_POINT_CLOUD_MAP, cv::CAP_OPENNI_POINT_CLOUD_MAP);
			SETOWNPROP(objs[1], CAP_OPENNI_QVGA_30HZ, cv::CAP_OPENNI_QVGA_30HZ);
			SETOWNPROP(objs[1], CAP_OPENNI_QVGA_60HZ, cv::CAP_OPENNI_QVGA_60HZ);
			SETOWNPROP(objs[1], CAP_OPENNI_SXGA_15HZ, cv::CAP_OPENNI_SXGA_15HZ);
			SETOWNPROP(objs[1], CAP_OPENNI_SXGA_30HZ, cv::CAP_OPENNI_SXGA_30HZ);
			SETOWNPROP(objs[1], CAP_OPENNI_VALID_DEPTH_MASK, cv::CAP_OPENNI_VALID_DEPTH_MASK);
			SETOWNPROP(objs[1], CAP_OPENNI_VGA_30HZ, cv::CAP_OPENNI_VGA_30HZ);
			SETOWNPROP(objs[1], CAP_PROP_APERTURE, cv::CAP_PROP_APERTURE);
			SETOWNPROP(objs[1], CAP_PROP_ARAVIS_AUTOTRIGGER, cv::CAP_PROP_ARAVIS_AUTOTRIGGER);
			SETOWNPROP(objs[1], CAP_PROP_AUDIO_BASE_INDEX, cv::CAP_PROP_AUDIO_BASE_INDEX);
			SETOWNPROP(objs[1], CAP_PROP_AUDIO_DATA_DEPTH, cv::CAP_PROP_AUDIO_DATA_DEPTH);
			SETOWNPROP(objs[1], CAP_PROP_AUDIO_POS, cv::CAP_PROP_AUDIO_POS);
			SETOWNPROP(objs[1], CAP_PROP_AUDIO_SAMPLES_PER_SECOND, cv::CAP_PROP_AUDIO_SAMPLES_PER_SECOND);
			SETOWNPROP(objs[1], CAP_PROP_AUDIO_SHIFT_NSEC, cv::CAP_PROP_AUDIO_SHIFT_NSEC);
			SETOWNPROP(objs[1], CAP_PROP_AUDIO_STREAM, cv::CAP_PROP_AUDIO_STREAM);
			SETOWNPROP(objs[1], CAP_PROP_AUDIO_SYNCHRONIZE, cv::CAP_PROP_AUDIO_SYNCHRONIZE);
			SETOWNPROP(objs[1], CAP_PROP_AUDIO_TOTAL_CHANNELS, cv::CAP_PROP_AUDIO_TOTAL_CHANNELS);
			SETOWNPROP(objs[1], CAP_PROP_AUDIO_TOTAL_STREAMS, cv::CAP_PROP_AUDIO_TOTAL_STREAMS);
			SETOWNPROP(objs[1], CAP_PROP_AUTOFOCUS, cv::CAP_PROP_AUTOFOCUS);
			SETOWNPROP(objs[1], CAP_PROP_AUTO_EXPOSURE, cv::CAP_PROP_AUTO_EXPOSURE);
			SETOWNPROP(objs[1], CAP_PROP_AUTO_WB, cv::CAP_PROP_AUTO_WB);
			SETOWNPROP(objs[1], CAP_PROP_BACKEND, cv::CAP_PROP_BACKEND);
			SETOWNPROP(objs[1], CAP_PROP_BACKLIGHT, cv::CAP_PROP_BACKLIGHT);
			SETOWNPROP(objs[1], CAP_PROP_BITRATE, cv::CAP_PROP_BITRATE);
			SETOWNPROP(objs[1], CAP_PROP_BRIGHTNESS, cv::CAP_PROP_BRIGHTNESS);
			SETOWNPROP(objs[1], CAP_PROP_BUFFERSIZE, cv::CAP_PROP_BUFFERSIZE);
			SETOWNPROP(objs[1], CAP_PROP_CHANNEL, cv::CAP_PROP_CHANNEL);
			SETOWNPROP(objs[1], CAP_PROP_CODEC_EXTRADATA_INDEX, cv::CAP_PROP_CODEC_EXTRADATA_INDEX);
			SETOWNPROP(objs[1], CAP_PROP_CODEC_PIXEL_FORMAT, cv::CAP_PROP_CODEC_PIXEL_FORMAT);
			SETOWNPROP(objs[1], CAP_PROP_CONTRAST, cv::CAP_PROP_CONTRAST);
			SETOWNPROP(objs[1], CAP_PROP_CONVERT_RGB, cv::CAP_PROP_CONVERT_RGB);
			SETOWNPROP(objs[1], CAP_PROP_DC1394_MAX, cv::CAP_PROP_DC1394_MAX);
			SETOWNPROP(objs[1], CAP_PROP_DC1394_MODE_AUTO, cv::CAP_PROP_DC1394_MODE_AUTO);
			SETOWNPROP(objs[1], CAP_PROP_DC1394_MODE_MANUAL, cv::CAP_PROP_DC1394_MODE_MANUAL);
			SETOWNPROP(objs[1], CAP_PROP_DC1394_MODE_ONE_PUSH_AUTO, cv::CAP_PROP_DC1394_MODE_ONE_PUSH_AUTO);
			SETOWNPROP(objs[1], CAP_PROP_DC1394_OFF, cv::CAP_PROP_DC1394_OFF);
			SETOWNPROP(objs[1], CAP_PROP_EXPOSURE, cv::CAP_PROP_EXPOSURE);
			SETOWNPROP(objs[1], CAP_PROP_EXPOSUREPROGRAM, cv::CAP_PROP_EXPOSUREPROGRAM);
			SETOWNPROP(objs[1], CAP_PROP_FOCUS, cv::CAP_PROP_FOCUS);
			SETOWNPROP(objs[1], CAP_PROP_FORMAT, cv::CAP_PROP_FORMAT);
			SETOWNPROP(objs[1], CAP_PROP_FOURCC, cv::CAP_PROP_FOURCC);
			SETOWNPROP(objs[1], CAP_PROP_FPS, cv::CAP_PROP_FPS);
			SETOWNPROP(objs[1], CAP_PROP_FRAME_COUNT, cv::CAP_PROP_FRAME_COUNT);
			SETOWNPROP(objs[1], CAP_PROP_FRAME_HEIGHT, cv::CAP_PROP_FRAME_HEIGHT);
			SETOWNPROP(objs[1], CAP_PROP_FRAME_WIDTH, cv::CAP_PROP_FRAME_WIDTH);
			SETOWNPROP(objs[1], CAP_PROP_GAIN, cv::CAP_PROP_GAIN);
			SETOWNPROP(objs[1], CAP_PROP_GAMMA, cv::CAP_PROP_GAMMA);
			SETOWNPROP(objs[1], CAP_PROP_GIGA_FRAME_HEIGH_MAX, cv::CAP_PROP_GIGA_FRAME_HEIGH_MAX);
			SETOWNPROP(objs[1], CAP_PROP_GIGA_FRAME_OFFSET_X, cv::CAP_PROP_GIGA_FRAME_OFFSET_X);
			SETOWNPROP(objs[1], CAP_PROP_GIGA_FRAME_OFFSET_Y, cv::CAP_PROP_GIGA_FRAME_OFFSET_Y);
			SETOWNPROP(objs[1], CAP_PROP_GIGA_FRAME_SENS_HEIGH, cv::CAP_PROP_GIGA_FRAME_SENS_HEIGH);
			SETOWNPROP(objs[1], CAP_PROP_GIGA_FRAME_SENS_WIDTH, cv::CAP_PROP_GIGA_FRAME_SENS_WIDTH);
			SETOWNPROP(objs[1], CAP_PROP_GIGA_FRAME_WIDTH_MAX, cv::CAP_PROP_GIGA_FRAME_WIDTH_MAX);
			SETOWNPROP(objs[1], CAP_PROP_GPHOTO2_COLLECT_MSGS, cv::CAP_PROP_GPHOTO2_COLLECT_MSGS);
			SETOWNPROP(objs[1], CAP_PROP_GPHOTO2_FLUSH_MSGS, cv::CAP_PROP_GPHOTO2_FLUSH_MSGS);
			SETOWNPROP(objs[1], CAP_PROP_GPHOTO2_PREVIEW, cv::CAP_PROP_GPHOTO2_PREVIEW);
			SETOWNPROP(objs[1], CAP_PROP_GPHOTO2_RELOAD_CONFIG, cv::CAP_PROP_GPHOTO2_RELOAD_CONFIG);
			SETOWNPROP(objs[1], CAP_PROP_GPHOTO2_RELOAD_ON_CHANGE, cv::CAP_PROP_GPHOTO2_RELOAD_ON_CHANGE);
			SETOWNPROP(objs[1], CAP_PROP_GPHOTO2_WIDGET_ENUMERATE, cv::CAP_PROP_GPHOTO2_WIDGET_ENUMERATE);
			SETOWNPROP(objs[1], CAP_PROP_GSTREAMER_QUEUE_LENGTH, cv::CAP_PROP_GSTREAMER_QUEUE_LENGTH);
			SETOWNPROP(objs[1], CAP_PROP_GUID, cv::CAP_PROP_GUID);
			SETOWNPROP(objs[1], CAP_PROP_HUE, cv::CAP_PROP_HUE);
			SETOWNPROP(objs[1], CAP_PROP_HW_ACCELERATION, cv::CAP_PROP_HW_ACCELERATION);
			SETOWNPROP(objs[1], CAP_PROP_HW_ACCELERATION_USE_OPENCL, cv::CAP_PROP_HW_ACCELERATION_USE_OPENCL);
			SETOWNPROP(objs[1], CAP_PROP_HW_DEVICE, cv::CAP_PROP_HW_DEVICE);
			SETOWNPROP(objs[1], CAP_PROP_IMAGES_BASE, cv::CAP_PROP_IMAGES_BASE);
			SETOWNPROP(objs[1], CAP_PROP_IMAGES_LAST, cv::CAP_PROP_IMAGES_LAST);
			SETOWNPROP(objs[1], CAP_PROP_INTELPERC_DEPTH_CONFIDENCE_THRESHOLD, cv::CAP_PROP_INTELPERC_DEPTH_CONFIDENCE_THRESHOLD);
			SETOWNPROP(objs[1], CAP_PROP_INTELPERC_DEPTH_FOCAL_LENGTH_HORZ, cv::CAP_PROP_INTELPERC_DEPTH_FOCAL_LENGTH_HORZ);
			SETOWNPROP(objs[1], CAP_PROP_INTELPERC_DEPTH_FOCAL_LENGTH_VERT, cv::CAP_PROP_INTELPERC_DEPTH_FOCAL_LENGTH_VERT);
			SETOWNPROP(objs[1], CAP_PROP_INTELPERC_DEPTH_LOW_CONFIDENCE_VALUE, cv::CAP_PROP_INTELPERC_DEPTH_LOW_CONFIDENCE_VALUE);
			SETOWNPROP(objs[1], CAP_PROP_INTELPERC_DEPTH_SATURATION_VALUE, cv::CAP_PROP_INTELPERC_DEPTH_SATURATION_VALUE);
			SETOWNPROP(objs[1], CAP_PROP_INTELPERC_PROFILE_COUNT, cv::CAP_PROP_INTELPERC_PROFILE_COUNT);
			SETOWNPROP(objs[1], CAP_PROP_INTELPERC_PROFILE_IDX, cv::CAP_PROP_INTELPERC_PROFILE_IDX);
			SETOWNPROP(objs[1], CAP_PROP_IOS_DEVICE_EXPOSURE, cv::CAP_PROP_IOS_DEVICE_EXPOSURE);
			SETOWNPROP(objs[1], CAP_PROP_IOS_DEVICE_FLASH, cv::CAP_PROP_IOS_DEVICE_FLASH);
			SETOWNPROP(objs[1], CAP_PROP_IOS_DEVICE_FOCUS, cv::CAP_PROP_IOS_DEVICE_FOCUS);
			SETOWNPROP(objs[1], CAP_PROP_IOS_DEVICE_TORCH, cv::CAP_PROP_IOS_DEVICE_TORCH);
			SETOWNPROP(objs[1], CAP_PROP_IOS_DEVICE_WHITEBALANCE, cv::CAP_PROP_IOS_DEVICE_WHITEBALANCE);
			SETOWNPROP(objs[1], CAP_PROP_IRIS, cv::CAP_PROP_IRIS);
			SETOWNPROP(objs[1], CAP_PROP_ISO_SPEED, cv::CAP_PROP_ISO_SPEED);
			SETOWNPROP(objs[1], CAP_PROP_LRF_HAS_KEY_FRAME, cv::CAP_PROP_LRF_HAS_KEY_FRAME);
			SETOWNPROP(objs[1], CAP_PROP_MODE, cv::CAP_PROP_MODE);
			SETOWNPROP(objs[1], CAP_PROP_MONOCHROME, cv::CAP_PROP_MONOCHROME);
			SETOWNPROP(objs[1], CAP_PROP_OPENNI2_MIRROR, cv::CAP_PROP_OPENNI2_MIRROR);
			SETOWNPROP(objs[1], CAP_PROP_OPENNI2_SYNC, cv::CAP_PROP_OPENNI2_SYNC);
			SETOWNPROP(objs[1], CAP_PROP_OPENNI_APPROX_FRAME_SYNC, cv::CAP_PROP_OPENNI_APPROX_FRAME_SYNC);
			SETOWNPROP(objs[1], CAP_PROP_OPENNI_BASELINE, cv::CAP_PROP_OPENNI_BASELINE);
			SETOWNPROP(objs[1], CAP_PROP_OPENNI_CIRCLE_BUFFER, cv::CAP_PROP_OPENNI_CIRCLE_BUFFER);
			SETOWNPROP(objs[1], CAP_PROP_OPENNI_FOCAL_LENGTH, cv::CAP_PROP_OPENNI_FOCAL_LENGTH);
			SETOWNPROP(objs[1], CAP_PROP_OPENNI_FRAME_MAX_DEPTH, cv::CAP_PROP_OPENNI_FRAME_MAX_DEPTH);
			SETOWNPROP(objs[1], CAP_PROP_OPENNI_GENERATOR_PRESENT, cv::CAP_PROP_OPENNI_GENERATOR_PRESENT);
			SETOWNPROP(objs[1], CAP_PROP_OPENNI_MAX_BUFFER_SIZE, cv::CAP_PROP_OPENNI_MAX_BUFFER_SIZE);
			SETOWNPROP(objs[1], CAP_PROP_OPENNI_MAX_TIME_DURATION, cv::CAP_PROP_OPENNI_MAX_TIME_DURATION);
			SETOWNPROP(objs[1], CAP_PROP_OPENNI_OUTPUT_MODE, cv::CAP_PROP_OPENNI_OUTPUT_MODE);
			SETOWNPROP(objs[1], CAP_PROP_OPENNI_REGISTRATION, cv::CAP_PROP_OPENNI_REGISTRATION);
			SETOWNPROP(objs[1], CAP_PROP_OPENNI_REGISTRATION_ON, cv::CAP_PROP_OPENNI_REGISTRATION_ON);
			SETOWNPROP(objs[1], CAP_PROP_OPEN_TIMEOUT_MSEC, cv::CAP_PROP_OPEN_TIMEOUT_MSEC);
			SETOWNPROP(objs[1], CAP_PROP_ORIENTATION_AUTO, cv::CAP_PROP_ORIENTATION_AUTO);
			SETOWNPROP(objs[1], CAP_PROP_ORIENTATION_META, cv::CAP_PROP_ORIENTATION_META);
			SETOWNPROP(objs[1], CAP_PROP_PAN, cv::CAP_PROP_PAN);
			SETOWNPROP(objs[1], CAP_PROP_POS_AVI_RATIO, cv::CAP_PROP_POS_AVI_RATIO);
			SETOWNPROP(objs[1], CAP_PROP_POS_FRAMES, cv::CAP_PROP_POS_FRAMES);
			SETOWNPROP(objs[1], CAP_PROP_POS_MSEC, cv::CAP_PROP_POS_MSEC);
			SETOWNPROP(objs[1], CAP_PROP_PVAPI_BINNINGX, cv::CAP_PROP_PVAPI_BINNINGX);
			SETOWNPROP(objs[1], CAP_PROP_PVAPI_BINNINGY, cv::CAP_PROP_PVAPI_BINNINGY);
			SETOWNPROP(objs[1], CAP_PROP_PVAPI_DECIMATIONHORIZONTAL, cv::CAP_PROP_PVAPI_DECIMATIONHORIZONTAL);
			SETOWNPROP(objs[1], CAP_PROP_PVAPI_DECIMATIONVERTICAL, cv::CAP_PROP_PVAPI_DECIMATIONVERTICAL);
			SETOWNPROP(objs[1], CAP_PROP_PVAPI_FRAMESTARTTRIGGERMODE, cv::CAP_PROP_PVAPI_FRAMESTARTTRIGGERMODE);
			SETOWNPROP(objs[1], CAP_PROP_PVAPI_MULTICASTIP, cv::CAP_PROP_PVAPI_MULTICASTIP);
			SETOWNPROP(objs[1], CAP_PROP_PVAPI_PIXELFORMAT, cv::CAP_PROP_PVAPI_PIXELFORMAT);
			SETOWNPROP(objs[1], CAP_PROP_READ_TIMEOUT_MSEC, cv::CAP_PROP_READ_TIMEOUT_MSEC);
			SETOWNPROP(objs[1], CAP_PROP_RECTIFICATION, cv::CAP_PROP_RECTIFICATION);
			SETOWNPROP(objs[1], CAP_PROP_ROLL, cv::CAP_PROP_ROLL);
			SETOWNPROP(objs[1], CAP_PROP_SAR_DEN, cv::CAP_PROP_SAR_DEN);
			SETOWNPROP(objs[1], CAP_PROP_SAR_NUM, cv::CAP_PROP_SAR_NUM);
			SETOWNPROP(objs[1], CAP_PROP_SATURATION, cv::CAP_PROP_SATURATION);
			SETOWNPROP(objs[1], CAP_PROP_SETTINGS, cv::CAP_PROP_SETTINGS);
			SETOWNPROP(objs[1], CAP_PROP_SHARPNESS, cv::CAP_PROP_SHARPNESS);
			SETOWNPROP(objs[1], CAP_PROP_SPEED, cv::CAP_PROP_SPEED);
			SETOWNPROP(objs[1], CAP_PROP_STREAM_OPEN_TIME_USEC, cv::CAP_PROP_STREAM_OPEN_TIME_USEC);
			SETOWNPROP(objs[1], CAP_PROP_TEMPERATURE, cv::CAP_PROP_TEMPERATURE);
			SETOWNPROP(objs[1], CAP_PROP_TILT, cv::CAP_PROP_TILT);
			SETOWNPROP(objs[1], CAP_PROP_TRIGGER, cv::CAP_PROP_TRIGGER);
			SETOWNPROP(objs[1], CAP_PROP_TRIGGER_DELAY, cv::CAP_PROP_TRIGGER_DELAY);
			SETOWNPROP(objs[1], CAP_PROP_VIDEO_STREAM, cv::CAP_PROP_VIDEO_STREAM);
			SETOWNPROP(objs[1], CAP_PROP_VIDEO_TOTAL_CHANNELS, cv::CAP_PROP_VIDEO_TOTAL_CHANNELS);
			SETOWNPROP(objs[1], CAP_PROP_VIEWFINDER, cv::CAP_PROP_VIEWFINDER);
			SETOWNPROP(objs[1], CAP_PROP_WB_TEMPERATURE, cv::CAP_PROP_WB_TEMPERATURE);
			SETOWNPROP(objs[1], CAP_PROP_WHITE_BALANCE_BLUE_U, cv::CAP_PROP_WHITE_BALANCE_BLUE_U);
			SETOWNPROP(objs[1], CAP_PROP_WHITE_BALANCE_RED_V, cv::CAP_PROP_WHITE_BALANCE_RED_V);
			SETOWNPROP(objs[1], CAP_PROP_XI_ACQ_BUFFER_SIZE, cv::CAP_PROP_XI_ACQ_BUFFER_SIZE);
			SETOWNPROP(objs[1], CAP_PROP_XI_ACQ_BUFFER_SIZE_UNIT, cv::CAP_PROP_XI_ACQ_BUFFER_SIZE_UNIT);
			SETOWNPROP(objs[1], CAP_PROP_XI_ACQ_FRAME_BURST_COUNT, cv::CAP_PROP_XI_ACQ_FRAME_BURST_COUNT);
			SETOWNPROP(objs[1], CAP_PROP_XI_ACQ_TIMING_MODE, cv::CAP_PROP_XI_ACQ_TIMING_MODE);
			SETOWNPROP(objs[1], CAP_PROP_XI_ACQ_TRANSPORT_BUFFER_COMMIT, cv::CAP_PROP_XI_ACQ_TRANSPORT_BUFFER_COMMIT);
			SETOWNPROP(objs[1], CAP_PROP_XI_ACQ_TRANSPORT_BUFFER_SIZE, cv::CAP_PROP_XI_ACQ_TRANSPORT_BUFFER_SIZE);
			SETOWNPROP(objs[1], CAP_PROP_XI_AEAG, cv::CAP_PROP_XI_AEAG);
			SETOWNPROP(objs[1], CAP_PROP_XI_AEAG_LEVEL, cv::CAP_PROP_XI_AEAG_LEVEL);
			SETOWNPROP(objs[1], CAP_PROP_XI_AEAG_ROI_HEIGHT, cv::CAP_PROP_XI_AEAG_ROI_HEIGHT);
			SETOWNPROP(objs[1], CAP_PROP_XI_AEAG_ROI_OFFSET_X, cv::CAP_PROP_XI_AEAG_ROI_OFFSET_X);
			SETOWNPROP(objs[1], CAP_PROP_XI_AEAG_ROI_OFFSET_Y, cv::CAP_PROP_XI_AEAG_ROI_OFFSET_Y);
			SETOWNPROP(objs[1], CAP_PROP_XI_AEAG_ROI_WIDTH, cv::CAP_PROP_XI_AEAG_ROI_WIDTH);
			SETOWNPROP(objs[1], CAP_PROP_XI_AE_MAX_LIMIT, cv::CAP_PROP_XI_AE_MAX_LIMIT);
			SETOWNPROP(objs[1], CAP_PROP_XI_AG_MAX_LIMIT, cv::CAP_PROP_XI_AG_MAX_LIMIT);
			SETOWNPROP(objs[1], CAP_PROP_XI_APPLY_CMS, cv::CAP_PROP_XI_APPLY_CMS);
			SETOWNPROP(objs[1], CAP_PROP_XI_AUTO_BANDWIDTH_CALCULATION, cv::CAP_PROP_XI_AUTO_BANDWIDTH_CALCULATION);
			SETOWNPROP(objs[1], CAP_PROP_XI_AUTO_WB, cv::CAP_PROP_XI_AUTO_WB);
			SETOWNPROP(objs[1], CAP_PROP_XI_AVAILABLE_BANDWIDTH, cv::CAP_PROP_XI_AVAILABLE_BANDWIDTH);
			SETOWNPROP(objs[1], CAP_PROP_XI_BINNING_HORIZONTAL, cv::CAP_PROP_XI_BINNING_HORIZONTAL);
			SETOWNPROP(objs[1], CAP_PROP_XI_BINNING_PATTERN, cv::CAP_PROP_XI_BINNING_PATTERN);
			SETOWNPROP(objs[1], CAP_PROP_XI_BINNING_SELECTOR, cv::CAP_PROP_XI_BINNING_SELECTOR);
			SETOWNPROP(objs[1], CAP_PROP_XI_BINNING_VERTICAL, cv::CAP_PROP_XI_BINNING_VERTICAL);
			SETOWNPROP(objs[1], CAP_PROP_XI_BPC, cv::CAP_PROP_XI_BPC);
			SETOWNPROP(objs[1], CAP_PROP_XI_BUFFERS_QUEUE_SIZE, cv::CAP_PROP_XI_BUFFERS_QUEUE_SIZE);
			SETOWNPROP(objs[1], CAP_PROP_XI_BUFFER_POLICY, cv::CAP_PROP_XI_BUFFER_POLICY);
			SETOWNPROP(objs[1], CAP_PROP_XI_CC_MATRIX_00, cv::CAP_PROP_XI_CC_MATRIX_00);
			SETOWNPROP(objs[1], CAP_PROP_XI_CC_MATRIX_01, cv::CAP_PROP_XI_CC_MATRIX_01);
			SETOWNPROP(objs[1], CAP_PROP_XI_CC_MATRIX_02, cv::CAP_PROP_XI_CC_MATRIX_02);
			SETOWNPROP(objs[1], CAP_PROP_XI_CC_MATRIX_03, cv::CAP_PROP_XI_CC_MATRIX_03);
			SETOWNPROP(objs[1], CAP_PROP_XI_CC_MATRIX_10, cv::CAP_PROP_XI_CC_MATRIX_10);
			SETOWNPROP(objs[1], CAP_PROP_XI_CC_MATRIX_11, cv::CAP_PROP_XI_CC_MATRIX_11);
			SETOWNPROP(objs[1], CAP_PROP_XI_CC_MATRIX_12, cv::CAP_PROP_XI_CC_MATRIX_12);
			SETOWNPROP(objs[1], CAP_PROP_XI_CC_MATRIX_13, cv::CAP_PROP_XI_CC_MATRIX_13);
			SETOWNPROP(objs[1], CAP_PROP_XI_CC_MATRIX_20, cv::CAP_PROP_XI_CC_MATRIX_20);
			SETOWNPROP(objs[1], CAP_PROP_XI_CC_MATRIX_21, cv::CAP_PROP_XI_CC_MATRIX_21);
			SETOWNPROP(objs[1], CAP_PROP_XI_CC_MATRIX_22, cv::CAP_PROP_XI_CC_MATRIX_22);
			SETOWNPROP(objs[1], CAP_PROP_XI_CC_MATRIX_23, cv::CAP_PROP_XI_CC_MATRIX_23);
			SETOWNPROP(objs[1], CAP_PROP_XI_CC_MATRIX_30, cv::CAP_PROP_XI_CC_MATRIX_30);
			SETOWNPROP(objs[1], CAP_PROP_XI_CC_MATRIX_31, cv::CAP_PROP_XI_CC_MATRIX_31);
			SETOWNPROP(objs[1], CAP_PROP_XI_CC_MATRIX_32, cv::CAP_PROP_XI_CC_MATRIX_32);
			SETOWNPROP(objs[1], CAP_PROP_XI_CC_MATRIX_33, cv::CAP_PROP_XI_CC_MATRIX_33);
			SETOWNPROP(objs[1], CAP_PROP_XI_CHIP_TEMP, cv::CAP_PROP_XI_CHIP_TEMP);
			SETOWNPROP(objs[1], CAP_PROP_XI_CMS, cv::CAP_PROP_XI_CMS);
			SETOWNPROP(objs[1], CAP_PROP_XI_COLOR_FILTER_ARRAY, cv::CAP_PROP_XI_COLOR_FILTER_ARRAY);
			SETOWNPROP(objs[1], CAP_PROP_XI_COLUMN_FPN_CORRECTION, cv::CAP_PROP_XI_COLUMN_FPN_CORRECTION);
			SETOWNPROP(objs[1], CAP_PROP_XI_COOLING, cv::CAP_PROP_XI_COOLING);
			SETOWNPROP(objs[1], CAP_PROP_XI_COUNTER_SELECTOR, cv::CAP_PROP_XI_COUNTER_SELECTOR);
			SETOWNPROP(objs[1], CAP_PROP_XI_COUNTER_VALUE, cv::CAP_PROP_XI_COUNTER_VALUE);
			SETOWNPROP(objs[1], CAP_PROP_XI_DATA_FORMAT, cv::CAP_PROP_XI_DATA_FORMAT);
			SETOWNPROP(objs[1], CAP_PROP_XI_DEBOUNCE_EN, cv::CAP_PROP_XI_DEBOUNCE_EN);
			SETOWNPROP(objs[1], CAP_PROP_XI_DEBOUNCE_POL, cv::CAP_PROP_XI_DEBOUNCE_POL);
			SETOWNPROP(objs[1], CAP_PROP_XI_DEBOUNCE_T0, cv::CAP_PROP_XI_DEBOUNCE_T0);
			SETOWNPROP(objs[1], CAP_PROP_XI_DEBOUNCE_T1, cv::CAP_PROP_XI_DEBOUNCE_T1);
			SETOWNPROP(objs[1], CAP_PROP_XI_DEBUG_LEVEL, cv::CAP_PROP_XI_DEBUG_LEVEL);
			SETOWNPROP(objs[1], CAP_PROP_XI_DECIMATION_HORIZONTAL, cv::CAP_PROP_XI_DECIMATION_HORIZONTAL);
			SETOWNPROP(objs[1], CAP_PROP_XI_DECIMATION_PATTERN, cv::CAP_PROP_XI_DECIMATION_PATTERN);
			SETOWNPROP(objs[1], CAP_PROP_XI_DECIMATION_SELECTOR, cv::CAP_PROP_XI_DECIMATION_SELECTOR);
			SETOWNPROP(objs[1], CAP_PROP_XI_DECIMATION_VERTICAL, cv::CAP_PROP_XI_DECIMATION_VERTICAL);
			SETOWNPROP(objs[1], CAP_PROP_XI_DEFAULT_CC_MATRIX, cv::CAP_PROP_XI_DEFAULT_CC_MATRIX);
			SETOWNPROP(objs[1], CAP_PROP_XI_DEVICE_MODEL_ID, cv::CAP_PROP_XI_DEVICE_MODEL_ID);
			SETOWNPROP(objs[1], CAP_PROP_XI_DEVICE_RESET, cv::CAP_PROP_XI_DEVICE_RESET);
			SETOWNPROP(objs[1], CAP_PROP_XI_DEVICE_SN, cv::CAP_PROP_XI_DEVICE_SN);
			SETOWNPROP(objs[1], CAP_PROP_XI_DOWNSAMPLING, cv::CAP_PROP_XI_DOWNSAMPLING);
			SETOWNPROP(objs[1], CAP_PROP_XI_DOWNSAMPLING_TYPE, cv::CAP_PROP_XI_DOWNSAMPLING_TYPE);
			SETOWNPROP(objs[1], CAP_PROP_XI_EXPOSURE, cv::CAP_PROP_XI_EXPOSURE);
			SETOWNPROP(objs[1], CAP_PROP_XI_EXPOSURE_BURST_COUNT, cv::CAP_PROP_XI_EXPOSURE_BURST_COUNT);
			SETOWNPROP(objs[1], CAP_PROP_XI_EXP_PRIORITY, cv::CAP_PROP_XI_EXP_PRIORITY);
			SETOWNPROP(objs[1], CAP_PROP_XI_FFS_ACCESS_KEY, cv::CAP_PROP_XI_FFS_ACCESS_KEY);
			SETOWNPROP(objs[1], CAP_PROP_XI_FFS_FILE_ID, cv::CAP_PROP_XI_FFS_FILE_ID);
			SETOWNPROP(objs[1], CAP_PROP_XI_FFS_FILE_SIZE, cv::CAP_PROP_XI_FFS_FILE_SIZE);
			SETOWNPROP(objs[1], CAP_PROP_XI_FRAMERATE, cv::CAP_PROP_XI_FRAMERATE);
			SETOWNPROP(objs[1], CAP_PROP_XI_FREE_FFS_SIZE, cv::CAP_PROP_XI_FREE_FFS_SIZE);
			SETOWNPROP(objs[1], CAP_PROP_XI_GAIN, cv::CAP_PROP_XI_GAIN);
			SETOWNPROP(objs[1], CAP_PROP_XI_GAIN_SELECTOR, cv::CAP_PROP_XI_GAIN_SELECTOR);
			SETOWNPROP(objs[1], CAP_PROP_XI_GAMMAC, cv::CAP_PROP_XI_GAMMAC);
			SETOWNPROP(objs[1], CAP_PROP_XI_GAMMAY, cv::CAP_PROP_XI_GAMMAY);
			SETOWNPROP(objs[1], CAP_PROP_XI_GPI_LEVEL, cv::CAP_PROP_XI_GPI_LEVEL);
			SETOWNPROP(objs[1], CAP_PROP_XI_GPI_MODE, cv::CAP_PROP_XI_GPI_MODE);
			SETOWNPROP(objs[1], CAP_PROP_XI_GPI_SELECTOR, cv::CAP_PROP_XI_GPI_SELECTOR);
			SETOWNPROP(objs[1], CAP_PROP_XI_GPO_MODE, cv::CAP_PROP_XI_GPO_MODE);
			SETOWNPROP(objs[1], CAP_PROP_XI_GPO_SELECTOR, cv::CAP_PROP_XI_GPO_SELECTOR);
			SETOWNPROP(objs[1], CAP_PROP_XI_HDR, cv::CAP_PROP_XI_HDR);
			SETOWNPROP(objs[1], CAP_PROP_XI_HDR_KNEEPOINT_COUNT, cv::CAP_PROP_XI_HDR_KNEEPOINT_COUNT);
			SETOWNPROP(objs[1], CAP_PROP_XI_HDR_T1, cv::CAP_PROP_XI_HDR_T1);
			SETOWNPROP(objs[1], CAP_PROP_XI_HDR_T2, cv::CAP_PROP_XI_HDR_T2);
			SETOWNPROP(objs[1], CAP_PROP_XI_HEIGHT, cv::CAP_PROP_XI_HEIGHT);
			SETOWNPROP(objs[1], CAP_PROP_XI_HOUS_BACK_SIDE_TEMP, cv::CAP_PROP_XI_HOUS_BACK_SIDE_TEMP);
			SETOWNPROP(objs[1], CAP_PROP_XI_HOUS_TEMP, cv::CAP_PROP_XI_HOUS_TEMP);
			SETOWNPROP(objs[1], CAP_PROP_XI_HW_REVISION, cv::CAP_PROP_XI_HW_REVISION);
			SETOWNPROP(objs[1], CAP_PROP_XI_IMAGE_BLACK_LEVEL, cv::CAP_PROP_XI_IMAGE_BLACK_LEVEL);
			SETOWNPROP(objs[1], CAP_PROP_XI_IMAGE_DATA_BIT_DEPTH, cv::CAP_PROP_XI_IMAGE_DATA_BIT_DEPTH);
			SETOWNPROP(objs[1], CAP_PROP_XI_IMAGE_DATA_FORMAT, cv::CAP_PROP_XI_IMAGE_DATA_FORMAT);
			SETOWNPROP(objs[1], CAP_PROP_XI_IMAGE_DATA_FORMAT_RGB32_ALPHA, cv::CAP_PROP_XI_IMAGE_DATA_FORMAT_RGB32_ALPHA);
			SETOWNPROP(objs[1], CAP_PROP_XI_IMAGE_IS_COLOR, cv::CAP_PROP_XI_IMAGE_IS_COLOR);
			SETOWNPROP(objs[1], CAP_PROP_XI_IMAGE_PAYLOAD_SIZE, cv::CAP_PROP_XI_IMAGE_PAYLOAD_SIZE);
			SETOWNPROP(objs[1], CAP_PROP_XI_IS_COOLED, cv::CAP_PROP_XI_IS_COOLED);
			SETOWNPROP(objs[1], CAP_PROP_XI_IS_DEVICE_EXIST, cv::CAP_PROP_XI_IS_DEVICE_EXIST);
			SETOWNPROP(objs[1], CAP_PROP_XI_KNEEPOINT1, cv::CAP_PROP_XI_KNEEPOINT1);
			SETOWNPROP(objs[1], CAP_PROP_XI_KNEEPOINT2, cv::CAP_PROP_XI_KNEEPOINT2);
			SETOWNPROP(objs[1], CAP_PROP_XI_LED_MODE, cv::CAP_PROP_XI_LED_MODE);
			SETOWNPROP(objs[1], CAP_PROP_XI_LED_SELECTOR, cv::CAP_PROP_XI_LED_SELECTOR);
			SETOWNPROP(objs[1], CAP_PROP_XI_LENS_APERTURE_VALUE, cv::CAP_PROP_XI_LENS_APERTURE_VALUE);
			SETOWNPROP(objs[1], CAP_PROP_XI_LENS_FEATURE, cv::CAP_PROP_XI_LENS_FEATURE);
			SETOWNPROP(objs[1], CAP_PROP_XI_LENS_FEATURE_SELECTOR, cv::CAP_PROP_XI_LENS_FEATURE_SELECTOR);
			SETOWNPROP(objs[1], CAP_PROP_XI_LENS_FOCAL_LENGTH, cv::CAP_PROP_XI_LENS_FOCAL_LENGTH);
			SETOWNPROP(objs[1], CAP_PROP_XI_LENS_FOCUS_DISTANCE, cv::CAP_PROP_XI_LENS_FOCUS_DISTANCE);
			SETOWNPROP(objs[1], CAP_PROP_XI_LENS_FOCUS_MOVE, cv::CAP_PROP_XI_LENS_FOCUS_MOVE);
			SETOWNPROP(objs[1], CAP_PROP_XI_LENS_FOCUS_MOVEMENT_VALUE, cv::CAP_PROP_XI_LENS_FOCUS_MOVEMENT_VALUE);
			SETOWNPROP(objs[1], CAP_PROP_XI_LENS_MODE, cv::CAP_PROP_XI_LENS_MODE);
			SETOWNPROP(objs[1], CAP_PROP_XI_LIMIT_BANDWIDTH, cv::CAP_PROP_XI_LIMIT_BANDWIDTH);
			SETOWNPROP(objs[1], CAP_PROP_XI_LUT_EN, cv::CAP_PROP_XI_LUT_EN);
			SETOWNPROP(objs[1], CAP_PROP_XI_LUT_INDEX, cv::CAP_PROP_XI_LUT_INDEX);
			SETOWNPROP(objs[1], CAP_PROP_XI_LUT_VALUE, cv::CAP_PROP_XI_LUT_VALUE);
			SETOWNPROP(objs[1], CAP_PROP_XI_MANUAL_WB, cv::CAP_PROP_XI_MANUAL_WB);
			SETOWNPROP(objs[1], CAP_PROP_XI_OFFSET_X, cv::CAP_PROP_XI_OFFSET_X);
			SETOWNPROP(objs[1], CAP_PROP_XI_OFFSET_Y, cv::CAP_PROP_XI_OFFSET_Y);
			SETOWNPROP(objs[1], CAP_PROP_XI_OUTPUT_DATA_BIT_DEPTH, cv::CAP_PROP_XI_OUTPUT_DATA_BIT_DEPTH);
			SETOWNPROP(objs[1], CAP_PROP_XI_OUTPUT_DATA_PACKING, cv::CAP_PROP_XI_OUTPUT_DATA_PACKING);
			SETOWNPROP(objs[1], CAP_PROP_XI_OUTPUT_DATA_PACKING_TYPE, cv::CAP_PROP_XI_OUTPUT_DATA_PACKING_TYPE);
			SETOWNPROP(objs[1], CAP_PROP_XI_RECENT_FRAME, cv::CAP_PROP_XI_RECENT_FRAME);
			SETOWNPROP(objs[1], CAP_PROP_XI_REGION_MODE, cv::CAP_PROP_XI_REGION_MODE);
			SETOWNPROP(objs[1], CAP_PROP_XI_REGION_SELECTOR, cv::CAP_PROP_XI_REGION_SELECTOR);
			SETOWNPROP(objs[1], CAP_PROP_XI_ROW_FPN_CORRECTION, cv::CAP_PROP_XI_ROW_FPN_CORRECTION);
			SETOWNPROP(objs[1], CAP_PROP_XI_SENSOR_BOARD_TEMP, cv::CAP_PROP_XI_SENSOR_BOARD_TEMP);
			SETOWNPROP(objs[1], CAP_PROP_XI_SENSOR_CLOCK_FREQ_HZ, cv::CAP_PROP_XI_SENSOR_CLOCK_FREQ_HZ);
			SETOWNPROP(objs[1], CAP_PROP_XI_SENSOR_CLOCK_FREQ_INDEX, cv::CAP_PROP_XI_SENSOR_CLOCK_FREQ_INDEX);
			SETOWNPROP(objs[1], CAP_PROP_XI_SENSOR_DATA_BIT_DEPTH, cv::CAP_PROP_XI_SENSOR_DATA_BIT_DEPTH);
			SETOWNPROP(objs[1], CAP_PROP_XI_SENSOR_FEATURE_SELECTOR, cv::CAP_PROP_XI_SENSOR_FEATURE_SELECTOR);
			SETOWNPROP(objs[1], CAP_PROP_XI_SENSOR_FEATURE_VALUE, cv::CAP_PROP_XI_SENSOR_FEATURE_VALUE);
			SETOWNPROP(objs[1], CAP_PROP_XI_SENSOR_MODE, cv::CAP_PROP_XI_SENSOR_MODE);
			SETOWNPROP(objs[1], CAP_PROP_XI_SENSOR_OUTPUT_CHANNEL_COUNT, cv::CAP_PROP_XI_SENSOR_OUTPUT_CHANNEL_COUNT);
			SETOWNPROP(objs[1], CAP_PROP_XI_SENSOR_TAPS, cv::CAP_PROP_XI_SENSOR_TAPS);
			SETOWNPROP(objs[1], CAP_PROP_XI_SHARPNESS, cv::CAP_PROP_XI_SHARPNESS);
			SETOWNPROP(objs[1], CAP_PROP_XI_SHUTTER_TYPE, cv::CAP_PROP_XI_SHUTTER_TYPE);
			SETOWNPROP(objs[1], CAP_PROP_XI_TARGET_TEMP, cv::CAP_PROP_XI_TARGET_TEMP);
			SETOWNPROP(objs[1], CAP_PROP_XI_TEST_PATTERN, cv::CAP_PROP_XI_TEST_PATTERN);
			SETOWNPROP(objs[1], CAP_PROP_XI_TEST_PATTERN_GENERATOR_SELECTOR, cv::CAP_PROP_XI_TEST_PATTERN_GENERATOR_SELECTOR);
			SETOWNPROP(objs[1], CAP_PROP_XI_TIMEOUT, cv::CAP_PROP_XI_TIMEOUT);
			SETOWNPROP(objs[1], CAP_PROP_XI_TRANSPORT_PIXEL_FORMAT, cv::CAP_PROP_XI_TRANSPORT_PIXEL_FORMAT);
			SETOWNPROP(objs[1], CAP_PROP_XI_TRG_DELAY, cv::CAP_PROP_XI_TRG_DELAY);
			SETOWNPROP(objs[1], CAP_PROP_XI_TRG_SELECTOR, cv::CAP_PROP_XI_TRG_SELECTOR);
			SETOWNPROP(objs[1], CAP_PROP_XI_TRG_SOFTWARE, cv::CAP_PROP_XI_TRG_SOFTWARE);
			SETOWNPROP(objs[1], CAP_PROP_XI_TRG_SOURCE, cv::CAP_PROP_XI_TRG_SOURCE);
			SETOWNPROP(objs[1], CAP_PROP_XI_TS_RST_MODE, cv::CAP_PROP_XI_TS_RST_MODE);
			SETOWNPROP(objs[1], CAP_PROP_XI_TS_RST_SOURCE, cv::CAP_PROP_XI_TS_RST_SOURCE);
			SETOWNPROP(objs[1], CAP_PROP_XI_USED_FFS_SIZE, cv::CAP_PROP_XI_USED_FFS_SIZE);
			SETOWNPROP(objs[1], CAP_PROP_XI_WB_KB, cv::CAP_PROP_XI_WB_KB);
			SETOWNPROP(objs[1], CAP_PROP_XI_WB_KG, cv::CAP_PROP_XI_WB_KG);
			SETOWNPROP(objs[1], CAP_PROP_XI_WB_KR, cv::CAP_PROP_XI_WB_KR);
			SETOWNPROP(objs[1], CAP_PROP_XI_WIDTH, cv::CAP_PROP_XI_WIDTH);
			SETOWNPROP(objs[1], CAP_PROP_ZOOM, cv::CAP_PROP_ZOOM);
			SETOWNPROP(objs[1], CAP_PVAPI, cv::CAP_PVAPI);
			SETOWNPROP(objs[1], CAP_PVAPI_DECIMATION_2OUTOF16, cv::CAP_PVAPI_DECIMATION_2OUTOF16);
			SETOWNPROP(objs[1], CAP_PVAPI_DECIMATION_2OUTOF4, cv::CAP_PVAPI_DECIMATION_2OUTOF4);
			SETOWNPROP(objs[1], CAP_PVAPI_DECIMATION_2OUTOF8, cv::CAP_PVAPI_DECIMATION_2OUTOF8);
			SETOWNPROP(objs[1], CAP_PVAPI_DECIMATION_OFF, cv::CAP_PVAPI_DECIMATION_OFF);
			SETOWNPROP(objs[1], CAP_PVAPI_FSTRIGMODE_FIXEDRATE, cv::CAP_PVAPI_FSTRIGMODE_FIXEDRATE);
			SETOWNPROP(objs[1], CAP_PVAPI_FSTRIGMODE_FREERUN, cv::CAP_PVAPI_FSTRIGMODE_FREERUN);
			SETOWNPROP(objs[1], CAP_PVAPI_FSTRIGMODE_SOFTWARE, cv::CAP_PVAPI_FSTRIGMODE_SOFTWARE);
			SETOWNPROP(objs[1], CAP_PVAPI_FSTRIGMODE_SYNCIN1, cv::CAP_PVAPI_FSTRIGMODE_SYNCIN1);
			SETOWNPROP(objs[1], CAP_PVAPI_FSTRIGMODE_SYNCIN2, cv::CAP_PVAPI_FSTRIGMODE_SYNCIN2);
			SETOWNPROP(objs[1], CAP_PVAPI_PIXELFORMAT_BAYER16, cv::CAP_PVAPI_PIXELFORMAT_BAYER16);
			SETOWNPROP(objs[1], CAP_PVAPI_PIXELFORMAT_BAYER8, cv::CAP_PVAPI_PIXELFORMAT_BAYER8);
			SETOWNPROP(objs[1], CAP_PVAPI_PIXELFORMAT_BGR24, cv::CAP_PVAPI_PIXELFORMAT_BGR24);
			SETOWNPROP(objs[1], CAP_PVAPI_PIXELFORMAT_BGRA32, cv::CAP_PVAPI_PIXELFORMAT_BGRA32);
			SETOWNPROP(objs[1], CAP_PVAPI_PIXELFORMAT_MONO16, cv::CAP_PVAPI_PIXELFORMAT_MONO16);
			SETOWNPROP(objs[1], CAP_PVAPI_PIXELFORMAT_MONO8, cv::CAP_PVAPI_PIXELFORMAT_MONO8);
			SETOWNPROP(objs[1], CAP_PVAPI_PIXELFORMAT_RGB24, cv::CAP_PVAPI_PIXELFORMAT_RGB24);
			SETOWNPROP(objs[1], CAP_PVAPI_PIXELFORMAT_RGBA32, cv::CAP_PVAPI_PIXELFORMAT_RGBA32);
			SETOWNPROP(objs[1], CAP_QT, cv::CAP_QT);
			SETOWNPROP(objs[1], CAP_REALSENSE, cv::CAP_REALSENSE);
			SETOWNPROP(objs[1], CAP_UEYE, cv::CAP_UEYE);
			SETOWNPROP(objs[1], CAP_UNICAP, cv::CAP_UNICAP);
			SETOWNPROP(objs[1], CAP_V4L, cv::CAP_V4L);
			SETOWNPROP(objs[1], CAP_V4L2, cv::CAP_V4L2);
			SETOWNPROP(objs[1], CAP_VFW, cv::CAP_VFW);
			SETOWNPROP(objs[1], CAP_WINRT, cv::CAP_WINRT);
			SETOWNPROP(objs[1], CAP_XIAPI, cv::CAP_XIAPI);
			SETOWNPROP(objs[1], CAP_XINE, cv::CAP_XINE);
			SETOWNPROP(objs[1], CASCADE_DO_CANNY_PRUNING, cv::CASCADE_DO_CANNY_PRUNING);
			SETOWNPROP(objs[1], CASCADE_DO_ROUGH_SEARCH, cv::CASCADE_DO_ROUGH_SEARCH);
			SETOWNPROP(objs[1], CASCADE_FIND_BIGGEST_OBJECT, cv::CASCADE_FIND_BIGGEST_OBJECT);
			SETOWNPROP(objs[1], CASCADE_SCALE_IMAGE, cv::CASCADE_SCALE_IMAGE);
			SETOWNPROP(objs[1], CCL_BBDT, cv::CCL_BBDT);
			SETOWNPROP(objs[1], CCL_BOLELLI, cv::CCL_BOLELLI);
			SETOWNPROP(objs[1], CCL_DEFAULT, cv::CCL_DEFAULT);
			SETOWNPROP(objs[1], CCL_GRANA, cv::CCL_GRANA);
			SETOWNPROP(objs[1], CCL_SAUF, cv::CCL_SAUF);
			SETOWNPROP(objs[1], CCL_SPAGHETTI, cv::CCL_SPAGHETTI);
			SETOWNPROP(objs[1], CCL_WU, cv::CCL_WU);
			SETOWNPROP(objs[1], CC_STAT_AREA, cv::CC_STAT_AREA);
			SETOWNPROP(objs[1], CC_STAT_HEIGHT, cv::CC_STAT_HEIGHT);
			SETOWNPROP(objs[1], CC_STAT_LEFT, cv::CC_STAT_LEFT);
			SETOWNPROP(objs[1], CC_STAT_MAX, cv::CC_STAT_MAX);
			SETOWNPROP(objs[1], CC_STAT_TOP, cv::CC_STAT_TOP);
			SETOWNPROP(objs[1], CC_STAT_WIDTH, cv::CC_STAT_WIDTH);
			SETOWNPROP(objs[1], CHAIN_APPROX_NONE, cv::CHAIN_APPROX_NONE);
			SETOWNPROP(objs[1], CHAIN_APPROX_SIMPLE, cv::CHAIN_APPROX_SIMPLE);
			SETOWNPROP(objs[1], CHAIN_APPROX_TC89_KCOS, cv::CHAIN_APPROX_TC89_KCOS);
			SETOWNPROP(objs[1], CHAIN_APPROX_TC89_L1, cv::CHAIN_APPROX_TC89_L1);
			SETOWNPROP(objs[1], CMP_EQ, cv::CMP_EQ);
			SETOWNPROP(objs[1], CMP_GE, cv::CMP_GE);
			SETOWNPROP(objs[1], CMP_GT, cv::CMP_GT);
			SETOWNPROP(objs[1], CMP_LE, cv::CMP_LE);
			SETOWNPROP(objs[1], CMP_LT, cv::CMP_LT);
			SETOWNPROP(objs[1], CMP_NE, cv::CMP_NE);
			SETOWNPROP(objs[1], COLORMAP_AUTUMN, cv::COLORMAP_AUTUMN);
			SETOWNPROP(objs[1], COLORMAP_BONE, cv::COLORMAP_BONE);
			SETOWNPROP(objs[1], COLORMAP_CIVIDIS, cv::COLORMAP_CIVIDIS);
			SETOWNPROP(objs[1], COLORMAP_COOL, cv::COLORMAP_COOL);
			SETOWNPROP(objs[1], COLORMAP_DEEPGREEN, cv::COLORMAP_DEEPGREEN);
			SETOWNPROP(objs[1], COLORMAP_HOT, cv::COLORMAP_HOT);
			SETOWNPROP(objs[1], COLORMAP_HSV, cv::COLORMAP_HSV);
			SETOWNPROP(objs[1], COLORMAP_INFERNO, cv::COLORMAP_INFERNO);
			SETOWNPROP(objs[1], COLORMAP_JET, cv::COLORMAP_JET);
			SETOWNPROP(objs[1], COLORMAP_MAGMA, cv::COLORMAP_MAGMA);
			SETOWNPROP(objs[1], COLORMAP_OCEAN, cv::COLORMAP_OCEAN);
			SETOWNPROP(objs[1], COLORMAP_PARULA, cv::COLORMAP_PARULA);
			SETOWNPROP(objs[1], COLORMAP_PINK, cv::COLORMAP_PINK);
			SETOWNPROP(objs[1], COLORMAP_PLASMA, cv::COLORMAP_PLASMA);
			SETOWNPROP(objs[1], COLORMAP_RAINBOW, cv::COLORMAP_RAINBOW);
			SETOWNPROP(objs[1], COLORMAP_SPRING, cv::COLORMAP_SPRING);
			SETOWNPROP(objs[1], COLORMAP_SUMMER, cv::COLORMAP_SUMMER);
			SETOWNPROP(objs[1], COLORMAP_TURBO, cv::COLORMAP_TURBO);
			SETOWNPROP(objs[1], COLORMAP_TWILIGHT, cv::COLORMAP_TWILIGHT);
			SETOWNPROP(objs[1], COLORMAP_TWILIGHT_SHIFTED, cv::COLORMAP_TWILIGHT_SHIFTED);
			SETOWNPROP(objs[1], COLORMAP_VIRIDIS, cv::COLORMAP_VIRIDIS);
			SETOWNPROP(objs[1], COLORMAP_WINTER, cv::COLORMAP_WINTER);
			SETOWNPROP(objs[1], COLOR_BGR2BGR555, cv::COLOR_BGR2BGR555);
			SETOWNPROP(objs[1], COLOR_BGR2BGR565, cv::COLOR_BGR2BGR565);
			SETOWNPROP(objs[1], COLOR_BGR2BGRA, cv::COLOR_BGR2BGRA);
			SETOWNPROP(objs[1], COLOR_BGR2GRAY, cv::COLOR_BGR2GRAY);
			SETOWNPROP(objs[1], COLOR_BGR2HLS, cv::COLOR_BGR2HLS);
			SETOWNPROP(objs[1], COLOR_BGR2HLS_FULL, cv::COLOR_BGR2HLS_FULL);
			SETOWNPROP(objs[1], COLOR_BGR2HSV, cv::COLOR_BGR2HSV);
			SETOWNPROP(objs[1], COLOR_BGR2HSV_FULL, cv::COLOR_BGR2HSV_FULL);
			SETOWNPROP(objs[1], COLOR_BGR2Lab, cv::COLOR_BGR2Lab);
			SETOWNPROP(objs[1], COLOR_BGR2Luv, cv::COLOR_BGR2Luv);
			SETOWNPROP(objs[1], COLOR_BGR2RGB, cv::COLOR_BGR2RGB);
			SETOWNPROP(objs[1], COLOR_BGR2RGBA, cv::COLOR_BGR2RGBA);
			SETOWNPROP(objs[1], COLOR_BGR2XYZ, cv::COLOR_BGR2XYZ);
			SETOWNPROP(objs[1], COLOR_BGR2YCrCb, cv::COLOR_BGR2YCrCb);
			SETOWNPROP(objs[1], COLOR_BGR2YUV, cv::COLOR_BGR2YUV);
			SETOWNPROP(objs[1], COLOR_BGR2YUV_I420, cv::COLOR_BGR2YUV_I420);
			SETOWNPROP(objs[1], COLOR_BGR2YUV_IYUV, cv::COLOR_BGR2YUV_IYUV);
			SETOWNPROP(objs[1], COLOR_BGR2YUV_YV12, cv::COLOR_BGR2YUV_YV12);
			SETOWNPROP(objs[1], COLOR_BGR5552BGR, cv::COLOR_BGR5552BGR);
			SETOWNPROP(objs[1], COLOR_BGR5552BGRA, cv::COLOR_BGR5552BGRA);
			SETOWNPROP(objs[1], COLOR_BGR5552GRAY, cv::COLOR_BGR5552GRAY);
			SETOWNPROP(objs[1], COLOR_BGR5552RGB, cv::COLOR_BGR5552RGB);
			SETOWNPROP(objs[1], COLOR_BGR5552RGBA, cv::COLOR_BGR5552RGBA);
			SETOWNPROP(objs[1], COLOR_BGR5652BGR, cv::COLOR_BGR5652BGR);
			SETOWNPROP(objs[1], COLOR_BGR5652BGRA, cv::COLOR_BGR5652BGRA);
			SETOWNPROP(objs[1], COLOR_BGR5652GRAY, cv::COLOR_BGR5652GRAY);
			SETOWNPROP(objs[1], COLOR_BGR5652RGB, cv::COLOR_BGR5652RGB);
			SETOWNPROP(objs[1], COLOR_BGR5652RGBA, cv::COLOR_BGR5652RGBA);
			SETOWNPROP(objs[1], COLOR_BGRA2BGR, cv::COLOR_BGRA2BGR);
			SETOWNPROP(objs[1], COLOR_BGRA2BGR555, cv::COLOR_BGRA2BGR555);
			SETOWNPROP(objs[1], COLOR_BGRA2BGR565, cv::COLOR_BGRA2BGR565);
			SETOWNPROP(objs[1], COLOR_BGRA2GRAY, cv::COLOR_BGRA2GRAY);
			SETOWNPROP(objs[1], COLOR_BGRA2RGB, cv::COLOR_BGRA2RGB);
			SETOWNPROP(objs[1], COLOR_BGRA2RGBA, cv::COLOR_BGRA2RGBA);
			SETOWNPROP(objs[1], COLOR_BGRA2YUV_I420, cv::COLOR_BGRA2YUV_I420);
			SETOWNPROP(objs[1], COLOR_BGRA2YUV_IYUV, cv::COLOR_BGRA2YUV_IYUV);
			SETOWNPROP(objs[1], COLOR_BGRA2YUV_YV12, cv::COLOR_BGRA2YUV_YV12);
			SETOWNPROP(objs[1], COLOR_BayerBG2BGR, cv::COLOR_BayerBG2BGR);
			SETOWNPROP(objs[1], COLOR_BayerBG2BGRA, cv::COLOR_BayerBG2BGRA);
			SETOWNPROP(objs[1], COLOR_BayerBG2BGR_EA, cv::COLOR_BayerBG2BGR_EA);
			SETOWNPROP(objs[1], COLOR_BayerBG2BGR_VNG, cv::COLOR_BayerBG2BGR_VNG);
			SETOWNPROP(objs[1], COLOR_BayerBG2GRAY, cv::COLOR_BayerBG2GRAY);
			SETOWNPROP(objs[1], COLOR_BayerBG2RGB, cv::COLOR_BayerBG2RGB);
			SETOWNPROP(objs[1], COLOR_BayerBG2RGBA, cv::COLOR_BayerBG2RGBA);
			SETOWNPROP(objs[1], COLOR_BayerBG2RGB_EA, cv::COLOR_BayerBG2RGB_EA);
			SETOWNPROP(objs[1], COLOR_BayerBG2RGB_VNG, cv::COLOR_BayerBG2RGB_VNG);
			SETOWNPROP(objs[1], COLOR_BayerBGGR2BGR, cv::COLOR_BayerBGGR2BGR);
			SETOWNPROP(objs[1], COLOR_BayerBGGR2BGRA, cv::COLOR_BayerBGGR2BGRA);
			SETOWNPROP(objs[1], COLOR_BayerBGGR2BGR_EA, cv::COLOR_BayerBGGR2BGR_EA);
			SETOWNPROP(objs[1], COLOR_BayerBGGR2BGR_VNG, cv::COLOR_BayerBGGR2BGR_VNG);
			SETOWNPROP(objs[1], COLOR_BayerBGGR2GRAY, cv::COLOR_BayerBGGR2GRAY);
			SETOWNPROP(objs[1], COLOR_BayerBGGR2RGB, cv::COLOR_BayerBGGR2RGB);
			SETOWNPROP(objs[1], COLOR_BayerBGGR2RGBA, cv::COLOR_BayerBGGR2RGBA);
			SETOWNPROP(objs[1], COLOR_BayerBGGR2RGB_EA, cv::COLOR_BayerBGGR2RGB_EA);
			SETOWNPROP(objs[1], COLOR_BayerBGGR2RGB_VNG, cv::COLOR_BayerBGGR2RGB_VNG);
			SETOWNPROP(objs[1], COLOR_BayerGB2BGR, cv::COLOR_BayerGB2BGR);
			SETOWNPROP(objs[1], COLOR_BayerGB2BGRA, cv::COLOR_BayerGB2BGRA);
			SETOWNPROP(objs[1], COLOR_BayerGB2BGR_EA, cv::COLOR_BayerGB2BGR_EA);
			SETOWNPROP(objs[1], COLOR_BayerGB2BGR_VNG, cv::COLOR_BayerGB2BGR_VNG);
			SETOWNPROP(objs[1], COLOR_BayerGB2GRAY, cv::COLOR_BayerGB2GRAY);
			SETOWNPROP(objs[1], COLOR_BayerGB2RGB, cv::COLOR_BayerGB2RGB);
			SETOWNPROP(objs[1], COLOR_BayerGB2RGBA, cv::COLOR_BayerGB2RGBA);
			SETOWNPROP(objs[1], COLOR_BayerGB2RGB_EA, cv::COLOR_BayerGB2RGB_EA);
			SETOWNPROP(objs[1], COLOR_BayerGB2RGB_VNG, cv::COLOR_BayerGB2RGB_VNG);
			SETOWNPROP(objs[1], COLOR_BayerGBRG2BGR, cv::COLOR_BayerGBRG2BGR);
			SETOWNPROP(objs[1], COLOR_BayerGBRG2BGRA, cv::COLOR_BayerGBRG2BGRA);
			SETOWNPROP(objs[1], COLOR_BayerGBRG2BGR_EA, cv::COLOR_BayerGBRG2BGR_EA);
			SETOWNPROP(objs[1], COLOR_BayerGBRG2BGR_VNG, cv::COLOR_BayerGBRG2BGR_VNG);
			SETOWNPROP(objs[1], COLOR_BayerGBRG2GRAY, cv::COLOR_BayerGBRG2GRAY);
			SETOWNPROP(objs[1], COLOR_BayerGBRG2RGB, cv::COLOR_BayerGBRG2RGB);
			SETOWNPROP(objs[1], COLOR_BayerGBRG2RGBA, cv::COLOR_BayerGBRG2RGBA);
			SETOWNPROP(objs[1], COLOR_BayerGBRG2RGB_EA, cv::COLOR_BayerGBRG2RGB_EA);
			SETOWNPROP(objs[1], COLOR_BayerGBRG2RGB_VNG, cv::COLOR_BayerGBRG2RGB_VNG);
			SETOWNPROP(objs[1], COLOR_BayerGR2BGR, cv::COLOR_BayerGR2BGR);
			SETOWNPROP(objs[1], COLOR_BayerGR2BGRA, cv::COLOR_BayerGR2BGRA);
			SETOWNPROP(objs[1], COLOR_BayerGR2BGR_EA, cv::COLOR_BayerGR2BGR_EA);
			SETOWNPROP(objs[1], COLOR_BayerGR2BGR_VNG, cv::COLOR_BayerGR2BGR_VNG);
			SETOWNPROP(objs[1], COLOR_BayerGR2GRAY, cv::COLOR_BayerGR2GRAY);
			SETOWNPROP(objs[1], COLOR_BayerGR2RGB, cv::COLOR_BayerGR2RGB);
			SETOWNPROP(objs[1], COLOR_BayerGR2RGBA, cv::COLOR_BayerGR2RGBA);
			SETOWNPROP(objs[1], COLOR_BayerGR2RGB_EA, cv::COLOR_BayerGR2RGB_EA);
			SETOWNPROP(objs[1], COLOR_BayerGR2RGB_VNG, cv::COLOR_BayerGR2RGB_VNG);
			SETOWNPROP(objs[1], COLOR_BayerGRBG2BGR, cv::COLOR_BayerGRBG2BGR);
			SETOWNPROP(objs[1], COLOR_BayerGRBG2BGRA, cv::COLOR_BayerGRBG2BGRA);
			SETOWNPROP(objs[1], COLOR_BayerGRBG2BGR_EA, cv::COLOR_BayerGRBG2BGR_EA);
			SETOWNPROP(objs[1], COLOR_BayerGRBG2BGR_VNG, cv::COLOR_BayerGRBG2BGR_VNG);
			SETOWNPROP(objs[1], COLOR_BayerGRBG2GRAY, cv::COLOR_BayerGRBG2GRAY);
			SETOWNPROP(objs[1], COLOR_BayerGRBG2RGB, cv::COLOR_BayerGRBG2RGB);
			SETOWNPROP(objs[1], COLOR_BayerGRBG2RGBA, cv::COLOR_BayerGRBG2RGBA);
			SETOWNPROP(objs[1], COLOR_BayerGRBG2RGB_EA, cv::COLOR_BayerGRBG2RGB_EA);
			SETOWNPROP(objs[1], COLOR_BayerGRBG2RGB_VNG, cv::COLOR_BayerGRBG2RGB_VNG);
			SETOWNPROP(objs[1], COLOR_BayerRG2BGR, cv::COLOR_BayerRG2BGR);
			SETOWNPROP(objs[1], COLOR_BayerRG2BGRA, cv::COLOR_BayerRG2BGRA);
			SETOWNPROP(objs[1], COLOR_BayerRG2BGR_EA, cv::COLOR_BayerRG2BGR_EA);
			SETOWNPROP(objs[1], COLOR_BayerRG2BGR_VNG, cv::COLOR_BayerRG2BGR_VNG);
			SETOWNPROP(objs[1], COLOR_BayerRG2GRAY, cv::COLOR_BayerRG2GRAY);
			SETOWNPROP(objs[1], COLOR_BayerRG2RGB, cv::COLOR_BayerRG2RGB);
			SETOWNPROP(objs[1], COLOR_BayerRG2RGBA, cv::COLOR_BayerRG2RGBA);
			SETOWNPROP(objs[1], COLOR_BayerRG2RGB_EA, cv::COLOR_BayerRG2RGB_EA);
			SETOWNPROP(objs[1], COLOR_BayerRG2RGB_VNG, cv::COLOR_BayerRG2RGB_VNG);
			SETOWNPROP(objs[1], COLOR_BayerRGGB2BGR, cv::COLOR_BayerRGGB2BGR);
			SETOWNPROP(objs[1], COLOR_BayerRGGB2BGRA, cv::COLOR_BayerRGGB2BGRA);
			SETOWNPROP(objs[1], COLOR_BayerRGGB2BGR_EA, cv::COLOR_BayerRGGB2BGR_EA);
			SETOWNPROP(objs[1], COLOR_BayerRGGB2BGR_VNG, cv::COLOR_BayerRGGB2BGR_VNG);
			SETOWNPROP(objs[1], COLOR_BayerRGGB2GRAY, cv::COLOR_BayerRGGB2GRAY);
			SETOWNPROP(objs[1], COLOR_BayerRGGB2RGB, cv::COLOR_BayerRGGB2RGB);
			SETOWNPROP(objs[1], COLOR_BayerRGGB2RGBA, cv::COLOR_BayerRGGB2RGBA);
			SETOWNPROP(objs[1], COLOR_BayerRGGB2RGB_EA, cv::COLOR_BayerRGGB2RGB_EA);
			SETOWNPROP(objs[1], COLOR_BayerRGGB2RGB_VNG, cv::COLOR_BayerRGGB2RGB_VNG);
			SETOWNPROP(objs[1], COLOR_COLORCVT_MAX, cv::COLOR_COLORCVT_MAX);
			SETOWNPROP(objs[1], COLOR_GRAY2BGR, cv::COLOR_GRAY2BGR);
			SETOWNPROP(objs[1], COLOR_GRAY2BGR555, cv::COLOR_GRAY2BGR555);
			SETOWNPROP(objs[1], COLOR_GRAY2BGR565, cv::COLOR_GRAY2BGR565);
			SETOWNPROP(objs[1], COLOR_GRAY2BGRA, cv::COLOR_GRAY2BGRA);
			SETOWNPROP(objs[1], COLOR_GRAY2RGB, cv::COLOR_GRAY2RGB);
			SETOWNPROP(objs[1], COLOR_GRAY2RGBA, cv::COLOR_GRAY2RGBA);
			SETOWNPROP(objs[1], COLOR_HLS2BGR, cv::COLOR_HLS2BGR);
			SETOWNPROP(objs[1], COLOR_HLS2BGR_FULL, cv::COLOR_HLS2BGR_FULL);
			SETOWNPROP(objs[1], COLOR_HLS2RGB, cv::COLOR_HLS2RGB);
			SETOWNPROP(objs[1], COLOR_HLS2RGB_FULL, cv::COLOR_HLS2RGB_FULL);
			SETOWNPROP(objs[1], COLOR_HSV2BGR, cv::COLOR_HSV2BGR);
			SETOWNPROP(objs[1], COLOR_HSV2BGR_FULL, cv::COLOR_HSV2BGR_FULL);
			SETOWNPROP(objs[1], COLOR_HSV2RGB, cv::COLOR_HSV2RGB);
			SETOWNPROP(objs[1], COLOR_HSV2RGB_FULL, cv::COLOR_HSV2RGB_FULL);
			SETOWNPROP(objs[1], COLOR_LBGR2Lab, cv::COLOR_LBGR2Lab);
			SETOWNPROP(objs[1], COLOR_LBGR2Luv, cv::COLOR_LBGR2Luv);
			SETOWNPROP(objs[1], COLOR_LRGB2Lab, cv::COLOR_LRGB2Lab);
			SETOWNPROP(objs[1], COLOR_LRGB2Luv, cv::COLOR_LRGB2Luv);
			SETOWNPROP(objs[1], COLOR_Lab2BGR, cv::COLOR_Lab2BGR);
			SETOWNPROP(objs[1], COLOR_Lab2LBGR, cv::COLOR_Lab2LBGR);
			SETOWNPROP(objs[1], COLOR_Lab2LRGB, cv::COLOR_Lab2LRGB);
			SETOWNPROP(objs[1], COLOR_Lab2RGB, cv::COLOR_Lab2RGB);
			SETOWNPROP(objs[1], COLOR_Luv2BGR, cv::COLOR_Luv2BGR);
			SETOWNPROP(objs[1], COLOR_Luv2LBGR, cv::COLOR_Luv2LBGR);
			SETOWNPROP(objs[1], COLOR_Luv2LRGB, cv::COLOR_Luv2LRGB);
			SETOWNPROP(objs[1], COLOR_Luv2RGB, cv::COLOR_Luv2RGB);
			SETOWNPROP(objs[1], COLOR_RGB2BGR, cv::COLOR_RGB2BGR);
			SETOWNPROP(objs[1], COLOR_RGB2BGR555, cv::COLOR_RGB2BGR555);
			SETOWNPROP(objs[1], COLOR_RGB2BGR565, cv::COLOR_RGB2BGR565);
			SETOWNPROP(objs[1], COLOR_RGB2BGRA, cv::COLOR_RGB2BGRA);
			SETOWNPROP(objs[1], COLOR_RGB2GRAY, cv::COLOR_RGB2GRAY);
			SETOWNPROP(objs[1], COLOR_RGB2HLS, cv::COLOR_RGB2HLS);
			SETOWNPROP(objs[1], COLOR_RGB2HLS_FULL, cv::COLOR_RGB2HLS_FULL);
			SETOWNPROP(objs[1], COLOR_RGB2HSV, cv::COLOR_RGB2HSV);
			SETOWNPROP(objs[1], COLOR_RGB2HSV_FULL, cv::COLOR_RGB2HSV_FULL);
			SETOWNPROP(objs[1], COLOR_RGB2Lab, cv::COLOR_RGB2Lab);
			SETOWNPROP(objs[1], COLOR_RGB2Luv, cv::COLOR_RGB2Luv);
			SETOWNPROP(objs[1], COLOR_RGB2RGBA, cv::COLOR_RGB2RGBA);
			SETOWNPROP(objs[1], COLOR_RGB2XYZ, cv::COLOR_RGB2XYZ);
			SETOWNPROP(objs[1], COLOR_RGB2YCrCb, cv::COLOR_RGB2YCrCb);
			SETOWNPROP(objs[1], COLOR_RGB2YUV, cv::COLOR_RGB2YUV);
			SETOWNPROP(objs[1], COLOR_RGB2YUV_I420, cv::COLOR_RGB2YUV_I420);
			SETOWNPROP(objs[1], COLOR_RGB2YUV_IYUV, cv::COLOR_RGB2YUV_IYUV);
			SETOWNPROP(objs[1], COLOR_RGB2YUV_YV12, cv::COLOR_RGB2YUV_YV12);
			SETOWNPROP(objs[1], COLOR_RGBA2BGR, cv::COLOR_RGBA2BGR);
			SETOWNPROP(objs[1], COLOR_RGBA2BGR555, cv::COLOR_RGBA2BGR555);
			SETOWNPROP(objs[1], COLOR_RGBA2BGR565, cv::COLOR_RGBA2BGR565);
			SETOWNPROP(objs[1], COLOR_RGBA2BGRA, cv::COLOR_RGBA2BGRA);
			SETOWNPROP(objs[1], COLOR_RGBA2GRAY, cv::COLOR_RGBA2GRAY);
			SETOWNPROP(objs[1], COLOR_RGBA2RGB, cv::COLOR_RGBA2RGB);
			SETOWNPROP(objs[1], COLOR_RGBA2YUV_I420, cv::COLOR_RGBA2YUV_I420);
			SETOWNPROP(objs[1], COLOR_RGBA2YUV_IYUV, cv::COLOR_RGBA2YUV_IYUV);
			SETOWNPROP(objs[1], COLOR_RGBA2YUV_YV12, cv::COLOR_RGBA2YUV_YV12);
			SETOWNPROP(objs[1], COLOR_RGBA2mRGBA, cv::COLOR_RGBA2mRGBA);
			SETOWNPROP(objs[1], COLOR_XYZ2BGR, cv::COLOR_XYZ2BGR);
			SETOWNPROP(objs[1], COLOR_XYZ2RGB, cv::COLOR_XYZ2RGB);
			SETOWNPROP(objs[1], COLOR_YCrCb2BGR, cv::COLOR_YCrCb2BGR);
			SETOWNPROP(objs[1], COLOR_YCrCb2RGB, cv::COLOR_YCrCb2RGB);
			SETOWNPROP(objs[1], COLOR_YUV2BGR, cv::COLOR_YUV2BGR);
			SETOWNPROP(objs[1], COLOR_YUV2BGRA_I420, cv::COLOR_YUV2BGRA_I420);
			SETOWNPROP(objs[1], COLOR_YUV2BGRA_IYUV, cv::COLOR_YUV2BGRA_IYUV);
			SETOWNPROP(objs[1], COLOR_YUV2BGRA_NV12, cv::COLOR_YUV2BGRA_NV12);
			SETOWNPROP(objs[1], COLOR_YUV2BGRA_NV21, cv::COLOR_YUV2BGRA_NV21);
			SETOWNPROP(objs[1], COLOR_YUV2BGRA_UYNV, cv::COLOR_YUV2BGRA_UYNV);
			SETOWNPROP(objs[1], COLOR_YUV2BGRA_UYVY, cv::COLOR_YUV2BGRA_UYVY);
			SETOWNPROP(objs[1], COLOR_YUV2BGRA_Y422, cv::COLOR_YUV2BGRA_Y422);
			SETOWNPROP(objs[1], COLOR_YUV2BGRA_YUNV, cv::COLOR_YUV2BGRA_YUNV);
			SETOWNPROP(objs[1], COLOR_YUV2BGRA_YUY2, cv::COLOR_YUV2BGRA_YUY2);
			SETOWNPROP(objs[1], COLOR_YUV2BGRA_YUYV, cv::COLOR_YUV2BGRA_YUYV);
			SETOWNPROP(objs[1], COLOR_YUV2BGRA_YV12, cv::COLOR_YUV2BGRA_YV12);
			SETOWNPROP(objs[1], COLOR_YUV2BGRA_YVYU, cv::COLOR_YUV2BGRA_YVYU);
			SETOWNPROP(objs[1], COLOR_YUV2BGR_I420, cv::COLOR_YUV2BGR_I420);
			SETOWNPROP(objs[1], COLOR_YUV2BGR_IYUV, cv::COLOR_YUV2BGR_IYUV);
			SETOWNPROP(objs[1], COLOR_YUV2BGR_NV12, cv::COLOR_YUV2BGR_NV12);
			SETOWNPROP(objs[1], COLOR_YUV2BGR_NV21, cv::COLOR_YUV2BGR_NV21);
			SETOWNPROP(objs[1], COLOR_YUV2BGR_UYNV, cv::COLOR_YUV2BGR_UYNV);
			SETOWNPROP(objs[1], COLOR_YUV2BGR_UYVY, cv::COLOR_YUV2BGR_UYVY);
			SETOWNPROP(objs[1], COLOR_YUV2BGR_Y422, cv::COLOR_YUV2BGR_Y422);
			SETOWNPROP(objs[1], COLOR_YUV2BGR_YUNV, cv::COLOR_YUV2BGR_YUNV);
			SETOWNPROP(objs[1], COLOR_YUV2BGR_YUY2, cv::COLOR_YUV2BGR_YUY2);
			SETOWNPROP(objs[1], COLOR_YUV2BGR_YUYV, cv::COLOR_YUV2BGR_YUYV);
			SETOWNPROP(objs[1], COLOR_YUV2BGR_YV12, cv::COLOR_YUV2BGR_YV12);
			SETOWNPROP(objs[1], COLOR_YUV2BGR_YVYU, cv::COLOR_YUV2BGR_YVYU);
			SETOWNPROP(objs[1], COLOR_YUV2GRAY_420, cv::COLOR_YUV2GRAY_420);
			SETOWNPROP(objs[1], COLOR_YUV2GRAY_I420, cv::COLOR_YUV2GRAY_I420);
			SETOWNPROP(objs[1], COLOR_YUV2GRAY_IYUV, cv::COLOR_YUV2GRAY_IYUV);
			SETOWNPROP(objs[1], COLOR_YUV2GRAY_NV12, cv::COLOR_YUV2GRAY_NV12);
			SETOWNPROP(objs[1], COLOR_YUV2GRAY_NV21, cv::COLOR_YUV2GRAY_NV21);
			SETOWNPROP(objs[1], COLOR_YUV2GRAY_UYNV, cv::COLOR_YUV2GRAY_UYNV);
			SETOWNPROP(objs[1], COLOR_YUV2GRAY_UYVY, cv::COLOR_YUV2GRAY_UYVY);
			SETOWNPROP(objs[1], COLOR_YUV2GRAY_Y422, cv::COLOR_YUV2GRAY_Y422);
			SETOWNPROP(objs[1], COLOR_YUV2GRAY_YUNV, cv::COLOR_YUV2GRAY_YUNV);
			SETOWNPROP(objs[1], COLOR_YUV2GRAY_YUY2, cv::COLOR_YUV2GRAY_YUY2);
			SETOWNPROP(objs[1], COLOR_YUV2GRAY_YUYV, cv::COLOR_YUV2GRAY_YUYV);
			SETOWNPROP(objs[1], COLOR_YUV2GRAY_YV12, cv::COLOR_YUV2GRAY_YV12);
			SETOWNPROP(objs[1], COLOR_YUV2GRAY_YVYU, cv::COLOR_YUV2GRAY_YVYU);
			SETOWNPROP(objs[1], COLOR_YUV2RGB, cv::COLOR_YUV2RGB);
			SETOWNPROP(objs[1], COLOR_YUV2RGBA_I420, cv::COLOR_YUV2RGBA_I420);
			SETOWNPROP(objs[1], COLOR_YUV2RGBA_IYUV, cv::COLOR_YUV2RGBA_IYUV);
			SETOWNPROP(objs[1], COLOR_YUV2RGBA_NV12, cv::COLOR_YUV2RGBA_NV12);
			SETOWNPROP(objs[1], COLOR_YUV2RGBA_NV21, cv::COLOR_YUV2RGBA_NV21);
			SETOWNPROP(objs[1], COLOR_YUV2RGBA_UYNV, cv::COLOR_YUV2RGBA_UYNV);
			SETOWNPROP(objs[1], COLOR_YUV2RGBA_UYVY, cv::COLOR_YUV2RGBA_UYVY);
			SETOWNPROP(objs[1], COLOR_YUV2RGBA_Y422, cv::COLOR_YUV2RGBA_Y422);
			SETOWNPROP(objs[1], COLOR_YUV2RGBA_YUNV, cv::COLOR_YUV2RGBA_YUNV);
			SETOWNPROP(objs[1], COLOR_YUV2RGBA_YUY2, cv::COLOR_YUV2RGBA_YUY2);
			SETOWNPROP(objs[1], COLOR_YUV2RGBA_YUYV, cv::COLOR_YUV2RGBA_YUYV);
			SETOWNPROP(objs[1], COLOR_YUV2RGBA_YV12, cv::COLOR_YUV2RGBA_YV12);
			SETOWNPROP(objs[1], COLOR_YUV2RGBA_YVYU, cv::COLOR_YUV2RGBA_YVYU);
			SETOWNPROP(objs[1], COLOR_YUV2RGB_I420, cv::COLOR_YUV2RGB_I420);
			SETOWNPROP(objs[1], COLOR_YUV2RGB_IYUV, cv::COLOR_YUV2RGB_IYUV);
			SETOWNPROP(objs[1], COLOR_YUV2RGB_NV12, cv::COLOR_YUV2RGB_NV12);
			SETOWNPROP(objs[1], COLOR_YUV2RGB_NV21, cv::COLOR_YUV2RGB_NV21);
			SETOWNPROP(objs[1], COLOR_YUV2RGB_UYNV, cv::COLOR_YUV2RGB_UYNV);
			SETOWNPROP(objs[1], COLOR_YUV2RGB_UYVY, cv::COLOR_YUV2RGB_UYVY);
			SETOWNPROP(objs[1], COLOR_YUV2RGB_Y422, cv::COLOR_YUV2RGB_Y422);
			SETOWNPROP(objs[1], COLOR_YUV2RGB_YUNV, cv::COLOR_YUV2RGB_YUNV);
			SETOWNPROP(objs[1], COLOR_YUV2RGB_YUY2, cv::COLOR_YUV2RGB_YUY2);
			SETOWNPROP(objs[1], COLOR_YUV2RGB_YUYV, cv::COLOR_YUV2RGB_YUYV);
			SETOWNPROP(objs[1], COLOR_YUV2RGB_YV12, cv::COLOR_YUV2RGB_YV12);
			SETOWNPROP(objs[1], COLOR_YUV2RGB_YVYU, cv::COLOR_YUV2RGB_YVYU);
			SETOWNPROP(objs[1], COLOR_YUV420p2BGR, cv::COLOR_YUV420p2BGR);
			SETOWNPROP(objs[1], COLOR_YUV420p2BGRA, cv::COLOR_YUV420p2BGRA);
			SETOWNPROP(objs[1], COLOR_YUV420p2GRAY, cv::COLOR_YUV420p2GRAY);
			SETOWNPROP(objs[1], COLOR_YUV420p2RGB, cv::COLOR_YUV420p2RGB);
			SETOWNPROP(objs[1], COLOR_YUV420p2RGBA, cv::COLOR_YUV420p2RGBA);
			SETOWNPROP(objs[1], COLOR_YUV420sp2BGR, cv::COLOR_YUV420sp2BGR);
			SETOWNPROP(objs[1], COLOR_YUV420sp2BGRA, cv::COLOR_YUV420sp2BGRA);
			SETOWNPROP(objs[1], COLOR_YUV420sp2GRAY, cv::COLOR_YUV420sp2GRAY);
			SETOWNPROP(objs[1], COLOR_YUV420sp2RGB, cv::COLOR_YUV420sp2RGB);
			SETOWNPROP(objs[1], COLOR_YUV420sp2RGBA, cv::COLOR_YUV420sp2RGBA);
			SETOWNPROP(objs[1], COLOR_mRGBA2RGBA, cv::COLOR_mRGBA2RGBA);
			SETOWNPROP(objs[1], CONTOURS_MATCH_I1, cv::CONTOURS_MATCH_I1);
			SETOWNPROP(objs[1], CONTOURS_MATCH_I2, cv::CONTOURS_MATCH_I2);
			SETOWNPROP(objs[1], CONTOURS_MATCH_I3, cv::CONTOURS_MATCH_I3);
			SETOWNPROP(objs[1], COVAR_COLS, cv::COVAR_COLS);
			SETOWNPROP(objs[1], COVAR_NORMAL, cv::COVAR_NORMAL);
			SETOWNPROP(objs[1], COVAR_ROWS, cv::COVAR_ROWS);
			SETOWNPROP(objs[1], COVAR_SCALE, cv::COVAR_SCALE);
			SETOWNPROP(objs[1], COVAR_SCRAMBLED, cv::COVAR_SCRAMBLED);
			SETOWNPROP(objs[1], COVAR_USE_AVG, cv::COVAR_USE_AVG);
			objs[2] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[1], CirclesGridFinderParameters, objs[2]);
			SETOWNPROP(objs[2], ASYMMETRIC_GRID, cv::CirclesGridFinderParameters::ASYMMETRIC_GRID);
			SETOWNPROP(objs[2], SYMMETRIC_GRID, cv::CirclesGridFinderParameters::SYMMETRIC_GRID);
			SETOWNPROP(objs[1], DCT_INVERSE, cv::DCT_INVERSE);
			SETOWNPROP(objs[1], DCT_ROWS, cv::DCT_ROWS);
			SETOWNPROP(objs[1], DECOMP_CHOLESKY, cv::DECOMP_CHOLESKY);
			SETOWNPROP(objs[1], DECOMP_EIG, cv::DECOMP_EIG);
			SETOWNPROP(objs[1], DECOMP_LU, cv::DECOMP_LU);
			SETOWNPROP(objs[1], DECOMP_NORMAL, cv::DECOMP_NORMAL);
			SETOWNPROP(objs[1], DECOMP_QR, cv::DECOMP_QR);
			SETOWNPROP(objs[1], DECOMP_SVD, cv::DECOMP_SVD);
			SETOWNPROP(objs[1], DFT_COMPLEX_INPUT, cv::DFT_COMPLEX_INPUT);
			SETOWNPROP(objs[1], DFT_COMPLEX_OUTPUT, cv::DFT_COMPLEX_OUTPUT);
			SETOWNPROP(objs[1], DFT_INVERSE, cv::DFT_INVERSE);
			SETOWNPROP(objs[1], DFT_REAL_OUTPUT, cv::DFT_REAL_OUTPUT);
			SETOWNPROP(objs[1], DFT_ROWS, cv::DFT_ROWS);
			SETOWNPROP(objs[1], DFT_SCALE, cv::DFT_SCALE);
			objs[2] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[1], DISOpticalFlow, objs[2]);
			SETOWNPROP(objs[2], PRESET_FAST, cv::DISOpticalFlow::PRESET_FAST);
			SETOWNPROP(objs[2], PRESET_MEDIUM, cv::DISOpticalFlow::PRESET_MEDIUM);
			SETOWNPROP(objs[2], PRESET_ULTRAFAST, cv::DISOpticalFlow::PRESET_ULTRAFAST);
			SETOWNPROP(objs[1], DIST_C, cv::DIST_C);
			SETOWNPROP(objs[1], DIST_FAIR, cv::DIST_FAIR);
			SETOWNPROP(objs[1], DIST_HUBER, cv::DIST_HUBER);
			SETOWNPROP(objs[1], DIST_L1, cv::DIST_L1);
			SETOWNPROP(objs[1], DIST_L12, cv::DIST_L12);
			SETOWNPROP(objs[1], DIST_L2, cv::DIST_L2);
			SETOWNPROP(objs[1], DIST_LABEL_CCOMP, cv::DIST_LABEL_CCOMP);
			SETOWNPROP(objs[1], DIST_LABEL_PIXEL, cv::DIST_LABEL_PIXEL);
			SETOWNPROP(objs[1], DIST_MASK_3, cv::DIST_MASK_3);
			SETOWNPROP(objs[1], DIST_MASK_5, cv::DIST_MASK_5);
			SETOWNPROP(objs[1], DIST_MASK_PRECISE, cv::DIST_MASK_PRECISE);
			SETOWNPROP(objs[1], DIST_USER, cv::DIST_USER);
			SETOWNPROP(objs[1], DIST_WELSCH, cv::DIST_WELSCH);
			objs[2] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[1], DescriptorMatcher, objs[2]);
			SETOWNPROP(objs[2], BRUTEFORCE, cv::DescriptorMatcher::BRUTEFORCE);
			SETOWNPROP(objs[2], BRUTEFORCE_HAMMING, cv::DescriptorMatcher::BRUTEFORCE_HAMMING);
			SETOWNPROP(objs[2], BRUTEFORCE_HAMMINGLUT, cv::DescriptorMatcher::BRUTEFORCE_HAMMINGLUT);
			SETOWNPROP(objs[2], BRUTEFORCE_L1, cv::DescriptorMatcher::BRUTEFORCE_L1);
			SETOWNPROP(objs[2], BRUTEFORCE_SL2, cv::DescriptorMatcher::BRUTEFORCE_SL2);
			SETOWNPROP(objs[2], FLANNBASED, cv::DescriptorMatcher::FLANNBASED);
			objs[2] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[1], DrawMatchesFlags, objs[2]);
			SETOWNPROP(objs[2], DEFAULT, cv::DrawMatchesFlags::DEFAULT);
			SETOWNPROP(objs[2], DRAW_OVER_OUTIMG, cv::DrawMatchesFlags::DRAW_OVER_OUTIMG);
			SETOWNPROP(objs[2], DRAW_RICH_KEYPOINTS, cv::DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
			SETOWNPROP(objs[2], NOT_DRAW_SINGLE_POINTS, cv::DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS);
			SETOWNPROP(objs[1], EVENT_FLAG_ALTKEY, cv::EVENT_FLAG_ALTKEY);
			SETOWNPROP(objs[1], EVENT_FLAG_CTRLKEY, cv::EVENT_FLAG_CTRLKEY);
			SETOWNPROP(objs[1], EVENT_FLAG_LBUTTON, cv::EVENT_FLAG_LBUTTON);
			SETOWNPROP(objs[1], EVENT_FLAG_MBUTTON, cv::EVENT_FLAG_MBUTTON);
			SETOWNPROP(objs[1], EVENT_FLAG_RBUTTON, cv::EVENT_FLAG_RBUTTON);
			SETOWNPROP(objs[1], EVENT_FLAG_SHIFTKEY, cv::EVENT_FLAG_SHIFTKEY);
			SETOWNPROP(objs[1], EVENT_LBUTTONDBLCLK, cv::EVENT_LBUTTONDBLCLK);
			SETOWNPROP(objs[1], EVENT_LBUTTONDOWN, cv::EVENT_LBUTTONDOWN);
			SETOWNPROP(objs[1], EVENT_LBUTTONUP, cv::EVENT_LBUTTONUP);
			SETOWNPROP(objs[1], EVENT_MBUTTONDBLCLK, cv::EVENT_MBUTTONDBLCLK);
			SETOWNPROP(objs[1], EVENT_MBUTTONDOWN, cv::EVENT_MBUTTONDOWN);
			SETOWNPROP(objs[1], EVENT_MBUTTONUP, cv::EVENT_MBUTTONUP);
			SETOWNPROP(objs[1], EVENT_MOUSEHWHEEL, cv::EVENT_MOUSEHWHEEL);
			SETOWNPROP(objs[1], EVENT_MOUSEMOVE, cv::EVENT_MOUSEMOVE);
			SETOWNPROP(objs[1], EVENT_MOUSEWHEEL, cv::EVENT_MOUSEWHEEL);
			SETOWNPROP(objs[1], EVENT_RBUTTONDBLCLK, cv::EVENT_RBUTTONDBLCLK);
			SETOWNPROP(objs[1], EVENT_RBUTTONDOWN, cv::EVENT_RBUTTONDOWN);
			SETOWNPROP(objs[1], EVENT_RBUTTONUP, cv::EVENT_RBUTTONUP);
			objs[2] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[1], Error, objs[2]);
			SETOWNPROP(objs[2], BadAlign, cv::Error::BadAlign);
			SETOWNPROP(objs[2], BadAlphaChannel, cv::Error::BadAlphaChannel);
			SETOWNPROP(objs[2], BadCOI, cv::Error::BadCOI);
			SETOWNPROP(objs[2], BadCallBack, cv::Error::BadCallBack);
			SETOWNPROP(objs[2], BadDataPtr, cv::Error::BadDataPtr);
			SETOWNPROP(objs[2], BadDepth, cv::Error::BadDepth);
			SETOWNPROP(objs[2], BadImageSize, cv::Error::BadImageSize);
			SETOWNPROP(objs[2], BadModelOrChSeq, cv::Error::BadModelOrChSeq);
			SETOWNPROP(objs[2], BadNumChannel1U, cv::Error::BadNumChannel1U);
			SETOWNPROP(objs[2], BadNumChannels, cv::Error::BadNumChannels);
			SETOWNPROP(objs[2], BadOffset, cv::Error::BadOffset);
			SETOWNPROP(objs[2], BadOrder, cv::Error::BadOrder);
			SETOWNPROP(objs[2], BadOrigin, cv::Error::BadOrigin);
			SETOWNPROP(objs[2], BadROISize, cv::Error::BadROISize);
			SETOWNPROP(objs[2], BadStep, cv::Error::BadStep);
			SETOWNPROP(objs[2], BadTileSize, cv::Error::BadTileSize);
			SETOWNPROP(objs[2], GpuApiCallError, cv::Error::GpuApiCallError);
			SETOWNPROP(objs[2], GpuNotSupported, cv::Error::GpuNotSupported);
			SETOWNPROP(objs[2], HeaderIsNull, cv::Error::HeaderIsNull);
			SETOWNPROP(objs[2], MaskIsTiled, cv::Error::MaskIsTiled);
			SETOWNPROP(objs[2], OpenCLApiCallError, cv::Error::OpenCLApiCallError);
			SETOWNPROP(objs[2], OpenCLDoubleNotSupported, cv::Error::OpenCLDoubleNotSupported);
			SETOWNPROP(objs[2], OpenCLInitError, cv::Error::OpenCLInitError);
			SETOWNPROP(objs[2], OpenCLNoAMDBlasFft, cv::Error::OpenCLNoAMDBlasFft);
			SETOWNPROP(objs[2], OpenGlApiCallError, cv::Error::OpenGlApiCallError);
			SETOWNPROP(objs[2], OpenGlNotSupported, cv::Error::OpenGlNotSupported);
			SETOWNPROP(objs[2], StsAssert, cv::Error::StsAssert);
			SETOWNPROP(objs[2], StsAutoTrace, cv::Error::StsAutoTrace);
			SETOWNPROP(objs[2], StsBackTrace, cv::Error::StsBackTrace);
			SETOWNPROP(objs[2], StsBadArg, cv::Error::StsBadArg);
			SETOWNPROP(objs[2], StsBadFlag, cv::Error::StsBadFlag);
			SETOWNPROP(objs[2], StsBadFunc, cv::Error::StsBadFunc);
			SETOWNPROP(objs[2], StsBadMask, cv::Error::StsBadMask);
			SETOWNPROP(objs[2], StsBadMemBlock, cv::Error::StsBadMemBlock);
			SETOWNPROP(objs[2], StsBadPoint, cv::Error::StsBadPoint);
			SETOWNPROP(objs[2], StsBadSize, cv::Error::StsBadSize);
			SETOWNPROP(objs[2], StsDivByZero, cv::Error::StsDivByZero);
			SETOWNPROP(objs[2], StsError, cv::Error::StsError);
			SETOWNPROP(objs[2], StsFilterOffsetErr, cv::Error::StsFilterOffsetErr);
			SETOWNPROP(objs[2], StsFilterStructContentErr, cv::Error::StsFilterStructContentErr);
			SETOWNPROP(objs[2], StsInplaceNotSupported, cv::Error::StsInplaceNotSupported);
			SETOWNPROP(objs[2], StsInternal, cv::Error::StsInternal);
			SETOWNPROP(objs[2], StsKernelStructContentErr, cv::Error::StsKernelStructContentErr);
			SETOWNPROP(objs[2], StsNoConv, cv::Error::StsNoConv);
			SETOWNPROP(objs[2], StsNoMem, cv::Error::StsNoMem);
			SETOWNPROP(objs[2], StsNotImplemented, cv::Error::StsNotImplemented);
			SETOWNPROP(objs[2], StsNullPtr, cv::Error::StsNullPtr);
			SETOWNPROP(objs[2], StsObjectNotFound, cv::Error::StsObjectNotFound);
			SETOWNPROP(objs[2], StsOk, cv::Error::StsOk);
			SETOWNPROP(objs[2], StsOutOfRange, cv::Error::StsOutOfRange);
			SETOWNPROP(objs[2], StsParseError, cv::Error::StsParseError);
			SETOWNPROP(objs[2], StsUnmatchedFormats, cv::Error::StsUnmatchedFormats);
			SETOWNPROP(objs[2], StsUnmatchedSizes, cv::Error::StsUnmatchedSizes);
			SETOWNPROP(objs[2], StsUnsupportedFormat, cv::Error::StsUnsupportedFormat);
			SETOWNPROP(objs[2], StsVecLengthErr, cv::Error::StsVecLengthErr);
			SETOWNPROP(objs[1], FILLED, cv::FILLED);
			SETOWNPROP(objs[1], FILTER_SCHARR, cv::FILTER_SCHARR);
			SETOWNPROP(objs[1], FLOODFILL_FIXED_RANGE, cv::FLOODFILL_FIXED_RANGE);
			SETOWNPROP(objs[1], FLOODFILL_MASK_ONLY, cv::FLOODFILL_MASK_ONLY);
			SETOWNPROP(objs[1], FM_7POINT, cv::FM_7POINT);
			SETOWNPROP(objs[1], FM_8POINT, cv::FM_8POINT);
			SETOWNPROP(objs[1], FM_LMEDS, cv::FM_LMEDS);
			SETOWNPROP(objs[1], FM_RANSAC, cv::FM_RANSAC);
			SETOWNPROP(objs[1], FONT_HERSHEY_COMPLEX, cv::FONT_HERSHEY_COMPLEX);
			SETOWNPROP(objs[1], FONT_HERSHEY_COMPLEX_SMALL, cv::FONT_HERSHEY_COMPLEX_SMALL);
			SETOWNPROP(objs[1], FONT_HERSHEY_DUPLEX, cv::FONT_HERSHEY_DUPLEX);
			SETOWNPROP(objs[1], FONT_HERSHEY_PLAIN, cv::FONT_HERSHEY_PLAIN);
			SETOWNPROP(objs[1], FONT_HERSHEY_SCRIPT_COMPLEX, cv::FONT_HERSHEY_SCRIPT_COMPLEX);
			SETOWNPROP(objs[1], FONT_HERSHEY_SCRIPT_SIMPLEX, cv::FONT_HERSHEY_SCRIPT_SIMPLEX);
			SETOWNPROP(objs[1], FONT_HERSHEY_SIMPLEX, cv::FONT_HERSHEY_SIMPLEX);
			SETOWNPROP(objs[1], FONT_HERSHEY_TRIPLEX, cv::FONT_HERSHEY_TRIPLEX);
			SETOWNPROP(objs[1], FONT_ITALIC, cv::FONT_ITALIC);
			objs[2] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[1], FaceRecognizerSF, objs[2]);
			SETOWNPROP(objs[2], FR_COSINE, cv::FaceRecognizerSF::FR_COSINE);
			SETOWNPROP(objs[2], FR_NORM_L2, cv::FaceRecognizerSF::FR_NORM_L2);
			objs[2] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[1], FastFeatureDetector, objs[2]);
			SETOWNPROP(objs[2], FAST_N, cv::FastFeatureDetector::FAST_N);
			SETOWNPROP(objs[2], NONMAX_SUPPRESSION, cv::FastFeatureDetector::NONMAX_SUPPRESSION);
			SETOWNPROP(objs[2], THRESHOLD, cv::FastFeatureDetector::THRESHOLD);
			SETOWNPROP(objs[2], TYPE_5_8, cv::FastFeatureDetector::TYPE_5_8);
			SETOWNPROP(objs[2], TYPE_7_12, cv::FastFeatureDetector::TYPE_7_12);
			SETOWNPROP(objs[2], TYPE_9_16, cv::FastFeatureDetector::TYPE_9_16);
			objs[2] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[1], FileNode, objs[2]);
			SETOWNPROP(objs[2], EMPTY, cv::FileNode::EMPTY);
			SETOWNPROP(objs[2], FLOAT, cv::FileNode::FLOAT);
			SETOWNPROP(objs[2], FLOW, cv::FileNode::FLOW);
			SETOWNPROP(objs[2], INT, cv::FileNode::INT);
			SETOWNPROP(objs[2], MAP, cv::FileNode::MAP);
			SETOWNPROP(objs[2], NAMED, cv::FileNode::NAMED);
			SETOWNPROP(objs[2], NONE, cv::FileNode::NONE);
			SETOWNPROP(objs[2], REAL, cv::FileNode::REAL);
			SETOWNPROP(objs[2], SEQ, cv::FileNode::SEQ);
			SETOWNPROP(objs[2], STR, cv::FileNode::STR);
			SETOWNPROP(objs[2], STRING, cv::FileNode::STRING);
			SETOWNPROP(objs[2], TYPE_MASK, cv::FileNode::TYPE_MASK);
			SETOWNPROP(objs[2], UNIFORM, cv::FileNode::UNIFORM);
			objs[2] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[1], FileStorage, objs[2]);
			SETOWNPROP(objs[2], APPEND, cv::FileStorage::APPEND);
			SETOWNPROP(objs[2], BASE64, cv::FileStorage::BASE64);
			SETOWNPROP(objs[2], FORMAT_AUTO, cv::FileStorage::FORMAT_AUTO);
			SETOWNPROP(objs[2], FORMAT_JSON, cv::FileStorage::FORMAT_JSON);
			SETOWNPROP(objs[2], FORMAT_MASK, cv::FileStorage::FORMAT_MASK);
			SETOWNPROP(objs[2], FORMAT_XML, cv::FileStorage::FORMAT_XML);
			SETOWNPROP(objs[2], FORMAT_YAML, cv::FileStorage::FORMAT_YAML);
			SETOWNPROP(objs[2], INSIDE_MAP, cv::FileStorage::INSIDE_MAP);
			SETOWNPROP(objs[2], MEMORY, cv::FileStorage::MEMORY);
			SETOWNPROP(objs[2], NAME_EXPECTED, cv::FileStorage::NAME_EXPECTED);
			SETOWNPROP(objs[2], READ, cv::FileStorage::READ);
			SETOWNPROP(objs[2], UNDEFINED, cv::FileStorage::UNDEFINED);
			SETOWNPROP(objs[2], VALUE_EXPECTED, cv::FileStorage::VALUE_EXPECTED);
			SETOWNPROP(objs[2], WRITE, cv::FileStorage::WRITE);
			SETOWNPROP(objs[2], WRITE_BASE64, cv::FileStorage::WRITE_BASE64);
			objs[2] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[1], Formatter, objs[2]);
			SETOWNPROP(objs[2], FMT_C, cv::Formatter::FMT_C);
			SETOWNPROP(objs[2], FMT_CSV, cv::Formatter::FMT_CSV);
			SETOWNPROP(objs[2], FMT_DEFAULT, cv::Formatter::FMT_DEFAULT);
			SETOWNPROP(objs[2], FMT_MATLAB, cv::Formatter::FMT_MATLAB);
			SETOWNPROP(objs[2], FMT_NUMPY, cv::Formatter::FMT_NUMPY);
			SETOWNPROP(objs[2], FMT_PYTHON, cv::Formatter::FMT_PYTHON);
			SETOWNPROP(objs[1], GC_BGD, cv::GC_BGD);
			SETOWNPROP(objs[1], GC_EVAL, cv::GC_EVAL);
			SETOWNPROP(objs[1], GC_EVAL_FREEZE_MODEL, cv::GC_EVAL_FREEZE_MODEL);
			SETOWNPROP(objs[1], GC_FGD, cv::GC_FGD);
			SETOWNPROP(objs[1], GC_INIT_WITH_MASK, cv::GC_INIT_WITH_MASK);
			SETOWNPROP(objs[1], GC_INIT_WITH_RECT, cv::GC_INIT_WITH_RECT);
			SETOWNPROP(objs[1], GC_PR_BGD, cv::GC_PR_BGD);
			SETOWNPROP(objs[1], GC_PR_FGD, cv::GC_PR_FGD);
			SETOWNPROP(objs[1], GEMM_1_T, cv::GEMM_1_T);
			SETOWNPROP(objs[1], GEMM_2_T, cv::GEMM_2_T);
			SETOWNPROP(objs[1], GEMM_3_T, cv::GEMM_3_T);
			objs[2] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[1], GFluidKernel, objs[2]);
			objs[3] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[2], Kind, objs[3]);
			SETOWNPROP(objs[3], Filter, cv::GFluidKernel::Kind::Filter);
			SETOWNPROP(objs[3], Resize, cv::GFluidKernel::Kind::Resize);
			SETOWNPROP(objs[3], YUV420toRGB, cv::GFluidKernel::Kind::YUV420toRGB);
			objs[2] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[1], GShape, objs[2]);
			SETOWNPROP(objs[2], GARRAY, cv::GShape::GARRAY);
			SETOWNPROP(objs[2], GFRAME, cv::GShape::GFRAME);
			SETOWNPROP(objs[2], GMAT, cv::GShape::GMAT);
			SETOWNPROP(objs[2], GOPAQUE, cv::GShape::GOPAQUE);
			SETOWNPROP(objs[2], GSCALAR, cv::GShape::GSCALAR);
			SETOWNPROP(objs[1], HISTCMP_BHATTACHARYYA, cv::HISTCMP_BHATTACHARYYA);
			SETOWNPROP(objs[1], HISTCMP_CHISQR, cv::HISTCMP_CHISQR);
			SETOWNPROP(objs[1], HISTCMP_CHISQR_ALT, cv::HISTCMP_CHISQR_ALT);
			SETOWNPROP(objs[1], HISTCMP_CORREL, cv::HISTCMP_CORREL);
			SETOWNPROP(objs[1], HISTCMP_HELLINGER, cv::HISTCMP_HELLINGER);
			SETOWNPROP(objs[1], HISTCMP_INTERSECT, cv::HISTCMP_INTERSECT);
			SETOWNPROP(objs[1], HISTCMP_KL_DIV, cv::HISTCMP_KL_DIV);
			objs[2] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[1], HOGDescriptor, objs[2]);
			SETOWNPROP(objs[2], DEFAULT_NLEVELS, cv::HOGDescriptor::DEFAULT_NLEVELS);
			SETOWNPROP(objs[2], DESCR_FORMAT_COL_BY_COL, cv::HOGDescriptor::DESCR_FORMAT_COL_BY_COL);
			SETOWNPROP(objs[2], DESCR_FORMAT_ROW_BY_ROW, cv::HOGDescriptor::DESCR_FORMAT_ROW_BY_ROW);
			SETOWNPROP(objs[2], L2Hys, cv::HOGDescriptor::L2Hys);
			SETOWNPROP(objs[1], HOUGH_GRADIENT, cv::HOUGH_GRADIENT);
			SETOWNPROP(objs[1], HOUGH_GRADIENT_ALT, cv::HOUGH_GRADIENT_ALT);
			SETOWNPROP(objs[1], HOUGH_MULTI_SCALE, cv::HOUGH_MULTI_SCALE);
			SETOWNPROP(objs[1], HOUGH_PROBABILISTIC, cv::HOUGH_PROBABILISTIC);
			SETOWNPROP(objs[1], HOUGH_STANDARD, cv::HOUGH_STANDARD);
			SETOWNPROP(objs[1], IMREAD_ANYCOLOR, cv::IMREAD_ANYCOLOR);
			SETOWNPROP(objs[1], IMREAD_ANYDEPTH, cv::IMREAD_ANYDEPTH);
			SETOWNPROP(objs[1], IMREAD_COLOR, cv::IMREAD_COLOR);
			SETOWNPROP(objs[1], IMREAD_GRAYSCALE, cv::IMREAD_GRAYSCALE);
			SETOWNPROP(objs[1], IMREAD_IGNORE_ORIENTATION, cv::IMREAD_IGNORE_ORIENTATION);
			SETOWNPROP(objs[1], IMREAD_LOAD_GDAL, cv::IMREAD_LOAD_GDAL);
			SETOWNPROP(objs[1], IMREAD_REDUCED_COLOR_2, cv::IMREAD_REDUCED_COLOR_2);
			SETOWNPROP(objs[1], IMREAD_REDUCED_COLOR_4, cv::IMREAD_REDUCED_COLOR_4);
			SETOWNPROP(objs[1], IMREAD_REDUCED_COLOR_8, cv::IMREAD_REDUCED_COLOR_8);
			SETOWNPROP(objs[1], IMREAD_REDUCED_GRAYSCALE_2, cv::IMREAD_REDUCED_GRAYSCALE_2);
			SETOWNPROP(objs[1], IMREAD_REDUCED_GRAYSCALE_4, cv::IMREAD_REDUCED_GRAYSCALE_4);
			SETOWNPROP(objs[1], IMREAD_REDUCED_GRAYSCALE_8, cv::IMREAD_REDUCED_GRAYSCALE_8);
			SETOWNPROP(objs[1], IMREAD_UNCHANGED, cv::IMREAD_UNCHANGED);
			SETOWNPROP(objs[1], IMWRITE_EXR_COMPRESSION, cv::IMWRITE_EXR_COMPRESSION);
			SETOWNPROP(objs[1], IMWRITE_EXR_COMPRESSION_B44, cv::IMWRITE_EXR_COMPRESSION_B44);
			SETOWNPROP(objs[1], IMWRITE_EXR_COMPRESSION_B44A, cv::IMWRITE_EXR_COMPRESSION_B44A);
			SETOWNPROP(objs[1], IMWRITE_EXR_COMPRESSION_DWAA, cv::IMWRITE_EXR_COMPRESSION_DWAA);
			SETOWNPROP(objs[1], IMWRITE_EXR_COMPRESSION_DWAB, cv::IMWRITE_EXR_COMPRESSION_DWAB);
			SETOWNPROP(objs[1], IMWRITE_EXR_COMPRESSION_NO, cv::IMWRITE_EXR_COMPRESSION_NO);
			SETOWNPROP(objs[1], IMWRITE_EXR_COMPRESSION_PIZ, cv::IMWRITE_EXR_COMPRESSION_PIZ);
			SETOWNPROP(objs[1], IMWRITE_EXR_COMPRESSION_PXR24, cv::IMWRITE_EXR_COMPRESSION_PXR24);
			SETOWNPROP(objs[1], IMWRITE_EXR_COMPRESSION_RLE, cv::IMWRITE_EXR_COMPRESSION_RLE);
			SETOWNPROP(objs[1], IMWRITE_EXR_COMPRESSION_ZIP, cv::IMWRITE_EXR_COMPRESSION_ZIP);
			SETOWNPROP(objs[1], IMWRITE_EXR_COMPRESSION_ZIPS, cv::IMWRITE_EXR_COMPRESSION_ZIPS);
			SETOWNPROP(objs[1], IMWRITE_EXR_TYPE, cv::IMWRITE_EXR_TYPE);
			SETOWNPROP(objs[1], IMWRITE_EXR_TYPE_FLOAT, cv::IMWRITE_EXR_TYPE_FLOAT);
			SETOWNPROP(objs[1], IMWRITE_EXR_TYPE_HALF, cv::IMWRITE_EXR_TYPE_HALF);
			SETOWNPROP(objs[1], IMWRITE_JPEG2000_COMPRESSION_X1000, cv::IMWRITE_JPEG2000_COMPRESSION_X1000);
			SETOWNPROP(objs[1], IMWRITE_JPEG_CHROMA_QUALITY, cv::IMWRITE_JPEG_CHROMA_QUALITY);
			SETOWNPROP(objs[1], IMWRITE_JPEG_LUMA_QUALITY, cv::IMWRITE_JPEG_LUMA_QUALITY);
			SETOWNPROP(objs[1], IMWRITE_JPEG_OPTIMIZE, cv::IMWRITE_JPEG_OPTIMIZE);
			SETOWNPROP(objs[1], IMWRITE_JPEG_PROGRESSIVE, cv::IMWRITE_JPEG_PROGRESSIVE);
			SETOWNPROP(objs[1], IMWRITE_JPEG_QUALITY, cv::IMWRITE_JPEG_QUALITY);
			SETOWNPROP(objs[1], IMWRITE_JPEG_RST_INTERVAL, cv::IMWRITE_JPEG_RST_INTERVAL);
			SETOWNPROP(objs[1], IMWRITE_PAM_FORMAT_BLACKANDWHITE, cv::IMWRITE_PAM_FORMAT_BLACKANDWHITE);
			SETOWNPROP(objs[1], IMWRITE_PAM_FORMAT_GRAYSCALE, cv::IMWRITE_PAM_FORMAT_GRAYSCALE);
			SETOWNPROP(objs[1], IMWRITE_PAM_FORMAT_GRAYSCALE_ALPHA, cv::IMWRITE_PAM_FORMAT_GRAYSCALE_ALPHA);
			SETOWNPROP(objs[1], IMWRITE_PAM_FORMAT_NULL, cv::IMWRITE_PAM_FORMAT_NULL);
			SETOWNPROP(objs[1], IMWRITE_PAM_FORMAT_RGB, cv::IMWRITE_PAM_FORMAT_RGB);
			SETOWNPROP(objs[1], IMWRITE_PAM_FORMAT_RGB_ALPHA, cv::IMWRITE_PAM_FORMAT_RGB_ALPHA);
			SETOWNPROP(objs[1], IMWRITE_PAM_TUPLETYPE, cv::IMWRITE_PAM_TUPLETYPE);
			SETOWNPROP(objs[1], IMWRITE_PNG_BILEVEL, cv::IMWRITE_PNG_BILEVEL);
			SETOWNPROP(objs[1], IMWRITE_PNG_COMPRESSION, cv::IMWRITE_PNG_COMPRESSION);
			SETOWNPROP(objs[1], IMWRITE_PNG_STRATEGY, cv::IMWRITE_PNG_STRATEGY);
			SETOWNPROP(objs[1], IMWRITE_PNG_STRATEGY_DEFAULT, cv::IMWRITE_PNG_STRATEGY_DEFAULT);
			SETOWNPROP(objs[1], IMWRITE_PNG_STRATEGY_FILTERED, cv::IMWRITE_PNG_STRATEGY_FILTERED);
			SETOWNPROP(objs[1], IMWRITE_PNG_STRATEGY_FIXED, cv::IMWRITE_PNG_STRATEGY_FIXED);
			SETOWNPROP(objs[1], IMWRITE_PNG_STRATEGY_HUFFMAN_ONLY, cv::IMWRITE_PNG_STRATEGY_HUFFMAN_ONLY);
			SETOWNPROP(objs[1], IMWRITE_PNG_STRATEGY_RLE, cv::IMWRITE_PNG_STRATEGY_RLE);
			SETOWNPROP(objs[1], IMWRITE_PXM_BINARY, cv::IMWRITE_PXM_BINARY);
			SETOWNPROP(objs[1], IMWRITE_TIFF_COMPRESSION, cv::IMWRITE_TIFF_COMPRESSION);
			SETOWNPROP(objs[1], IMWRITE_TIFF_RESUNIT, cv::IMWRITE_TIFF_RESUNIT);
			SETOWNPROP(objs[1], IMWRITE_TIFF_XDPI, cv::IMWRITE_TIFF_XDPI);
			SETOWNPROP(objs[1], IMWRITE_TIFF_YDPI, cv::IMWRITE_TIFF_YDPI);
			SETOWNPROP(objs[1], IMWRITE_WEBP_QUALITY, cv::IMWRITE_WEBP_QUALITY);
			SETOWNPROP(objs[1], INPAINT_NS, cv::INPAINT_NS);
			SETOWNPROP(objs[1], INPAINT_TELEA, cv::INPAINT_TELEA);
			SETOWNPROP(objs[1], INTERSECT_FULL, cv::INTERSECT_FULL);
			SETOWNPROP(objs[1], INTERSECT_NONE, cv::INTERSECT_NONE);
			SETOWNPROP(objs[1], INTERSECT_PARTIAL, cv::INTERSECT_PARTIAL);
			SETOWNPROP(objs[1], INTER_AREA, cv::INTER_AREA);
			SETOWNPROP(objs[1], INTER_BITS, cv::INTER_BITS);
			SETOWNPROP(objs[1], INTER_BITS2, cv::INTER_BITS2);
			SETOWNPROP(objs[1], INTER_CUBIC, cv::INTER_CUBIC);
			SETOWNPROP(objs[1], INTER_LANCZOS4, cv::INTER_LANCZOS4);
			SETOWNPROP(objs[1], INTER_LINEAR, cv::INTER_LINEAR);
			SETOWNPROP(objs[1], INTER_LINEAR_EXACT, cv::INTER_LINEAR_EXACT);
			SETOWNPROP(objs[1], INTER_MAX, cv::INTER_MAX);
			SETOWNPROP(objs[1], INTER_NEAREST, cv::INTER_NEAREST);
			SETOWNPROP(objs[1], INTER_NEAREST_EXACT, cv::INTER_NEAREST_EXACT);
			SETOWNPROP(objs[1], INTER_TAB_SIZE, cv::INTER_TAB_SIZE);
			SETOWNPROP(objs[1], INTER_TAB_SIZE2, cv::INTER_TAB_SIZE2);
			objs[2] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[1], KAZE, objs[2]);
			SETOWNPROP(objs[2], DIFF_CHARBONNIER, cv::KAZE::DIFF_CHARBONNIER);
			SETOWNPROP(objs[2], DIFF_PM_G1, cv::KAZE::DIFF_PM_G1);
			SETOWNPROP(objs[2], DIFF_PM_G2, cv::KAZE::DIFF_PM_G2);
			SETOWNPROP(objs[2], DIFF_WEICKERT, cv::KAZE::DIFF_WEICKERT);
			SETOWNPROP(objs[1], KMEANS_PP_CENTERS, cv::KMEANS_PP_CENTERS);
			SETOWNPROP(objs[1], KMEANS_RANDOM_CENTERS, cv::KMEANS_RANDOM_CENTERS);
			SETOWNPROP(objs[1], KMEANS_USE_INITIAL_LABELS, cv::KMEANS_USE_INITIAL_LABELS);
			SETOWNPROP(objs[1], LDR_SIZE, cv::LDR_SIZE);
			SETOWNPROP(objs[1], LINE_4, cv::LINE_4);
			SETOWNPROP(objs[1], LINE_8, cv::LINE_8);
			SETOWNPROP(objs[1], LINE_AA, cv::LINE_AA);
			SETOWNPROP(objs[1], LMEDS, cv::LMEDS);
			SETOWNPROP(objs[1], LOCAL_OPTIM_GC, cv::LOCAL_OPTIM_GC);
			SETOWNPROP(objs[1], LOCAL_OPTIM_INNER_AND_ITER_LO, cv::LOCAL_OPTIM_INNER_AND_ITER_LO);
			SETOWNPROP(objs[1], LOCAL_OPTIM_INNER_LO, cv::LOCAL_OPTIM_INNER_LO);
			SETOWNPROP(objs[1], LOCAL_OPTIM_NULL, cv::LOCAL_OPTIM_NULL);
			SETOWNPROP(objs[1], LOCAL_OPTIM_SIGMA, cv::LOCAL_OPTIM_SIGMA);
			SETOWNPROP(objs[1], LSD_REFINE_ADV, cv::LSD_REFINE_ADV);
			SETOWNPROP(objs[1], LSD_REFINE_NONE, cv::LSD_REFINE_NONE);
			SETOWNPROP(objs[1], LSD_REFINE_STD, cv::LSD_REFINE_STD);
			SETOWNPROP(objs[1], MARKER_CROSS, cv::MARKER_CROSS);
			SETOWNPROP(objs[1], MARKER_DIAMOND, cv::MARKER_DIAMOND);
			SETOWNPROP(objs[1], MARKER_SQUARE, cv::MARKER_SQUARE);
			SETOWNPROP(objs[1], MARKER_STAR, cv::MARKER_STAR);
			SETOWNPROP(objs[1], MARKER_TILTED_CROSS, cv::MARKER_TILTED_CROSS);
			SETOWNPROP(objs[1], MARKER_TRIANGLE_DOWN, cv::MARKER_TRIANGLE_DOWN);
			SETOWNPROP(objs[1], MARKER_TRIANGLE_UP, cv::MARKER_TRIANGLE_UP);
			SETOWNPROP(objs[1], MIXED_CLONE, cv::MIXED_CLONE);
			SETOWNPROP(objs[1], MONOCHROME_TRANSFER, cv::MONOCHROME_TRANSFER);
			SETOWNPROP(objs[1], MORPH_BLACKHAT, cv::MORPH_BLACKHAT);
			SETOWNPROP(objs[1], MORPH_CLOSE, cv::MORPH_CLOSE);
			SETOWNPROP(objs[1], MORPH_CROSS, cv::MORPH_CROSS);
			SETOWNPROP(objs[1], MORPH_DILATE, cv::MORPH_DILATE);
			SETOWNPROP(objs[1], MORPH_ELLIPSE, cv::MORPH_ELLIPSE);
			SETOWNPROP(objs[1], MORPH_ERODE, cv::MORPH_ERODE);
			SETOWNPROP(objs[1], MORPH_GRADIENT, cv::MORPH_GRADIENT);
			SETOWNPROP(objs[1], MORPH_HITMISS, cv::MORPH_HITMISS);
			SETOWNPROP(objs[1], MORPH_OPEN, cv::MORPH_OPEN);
			SETOWNPROP(objs[1], MORPH_RECT, cv::MORPH_RECT);
			SETOWNPROP(objs[1], MORPH_TOPHAT, cv::MORPH_TOPHAT);
			SETOWNPROP(objs[1], MOTION_AFFINE, cv::MOTION_AFFINE);
			SETOWNPROP(objs[1], MOTION_EUCLIDEAN, cv::MOTION_EUCLIDEAN);
			SETOWNPROP(objs[1], MOTION_HOMOGRAPHY, cv::MOTION_HOMOGRAPHY);
			SETOWNPROP(objs[1], MOTION_TRANSLATION, cv::MOTION_TRANSLATION);
			objs[2] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[1], Mat, objs[2]);
			SETOWNPROP(objs[2], AUTO_STEP, cv::Mat::AUTO_STEP);
			SETOWNPROP(objs[2], CONTINUOUS_FLAG, cv::Mat::CONTINUOUS_FLAG);
			SETOWNPROP(objs[2], DEPTH_MASK, cv::Mat::DEPTH_MASK);
			SETOWNPROP(objs[2], MAGIC_MASK, cv::Mat::MAGIC_MASK);
			SETOWNPROP(objs[2], MAGIC_VAL, cv::Mat::MAGIC_VAL);
			SETOWNPROP(objs[2], SUBMATRIX_FLAG, cv::Mat::SUBMATRIX_FLAG);
			SETOWNPROP(objs[2], TYPE_MASK, cv::Mat::TYPE_MASK);
			objs[2] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[1], MediaFormat, objs[2]);
			SETOWNPROP(objs[2], BGR, cv::MediaFormat::BGR);
			SETOWNPROP(objs[2], NV12, cv::MediaFormat::NV12);
			objs[2] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[1], MediaFrame, objs[2]);
			objs[3] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[2], Access, objs[3]);
			SETOWNPROP(objs[3], R, cv::MediaFrame::Access::R);
			SETOWNPROP(objs[3], W, cv::MediaFrame::Access::W);
			SETOWNPROP(objs[1], NEIGH_FLANN_KNN, cv::NEIGH_FLANN_KNN);
			SETOWNPROP(objs[1], NEIGH_FLANN_RADIUS, cv::NEIGH_FLANN_RADIUS);
			SETOWNPROP(objs[1], NEIGH_GRID, cv::NEIGH_GRID);
			SETOWNPROP(objs[1], NORMAL_CLONE, cv::NORMAL_CLONE);
			SETOWNPROP(objs[1], NORMCONV_FILTER, cv::NORMCONV_FILTER);
			SETOWNPROP(objs[1], NORM_HAMMING, cv::NORM_HAMMING);
			SETOWNPROP(objs[1], NORM_HAMMING2, cv::NORM_HAMMING2);
			SETOWNPROP(objs[1], NORM_INF, cv::NORM_INF);
			SETOWNPROP(objs[1], NORM_L1, cv::NORM_L1);
			SETOWNPROP(objs[1], NORM_L2, cv::NORM_L2);
			SETOWNPROP(objs[1], NORM_L2SQR, cv::NORM_L2SQR);
			SETOWNPROP(objs[1], NORM_MINMAX, cv::NORM_MINMAX);
			SETOWNPROP(objs[1], NORM_RELATIVE, cv::NORM_RELATIVE);
			SETOWNPROP(objs[1], NORM_TYPE_MASK, cv::NORM_TYPE_MASK);
			SETOWNPROP(objs[1], OPTFLOW_FARNEBACK_GAUSSIAN, cv::OPTFLOW_FARNEBACK_GAUSSIAN);
			SETOWNPROP(objs[1], OPTFLOW_LK_GET_MIN_EIGENVALS, cv::OPTFLOW_LK_GET_MIN_EIGENVALS);
			SETOWNPROP(objs[1], OPTFLOW_USE_INITIAL_FLOW, cv::OPTFLOW_USE_INITIAL_FLOW);
			objs[2] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[1], ORB, objs[2]);
			SETOWNPROP(objs[2], FAST_SCORE, cv::ORB::FAST_SCORE);
			SETOWNPROP(objs[2], HARRIS_SCORE, cv::ORB::HARRIS_SCORE);
			objs[2] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[1], PCA, objs[2]);
			SETOWNPROP(objs[2], DATA_AS_COL, cv::PCA::DATA_AS_COL);
			SETOWNPROP(objs[2], DATA_AS_ROW, cv::PCA::DATA_AS_ROW);
			SETOWNPROP(objs[2], USE_AVG, cv::PCA::USE_AVG);
			SETOWNPROP(objs[1], PROJ_SPHERICAL_EQRECT, cv::PROJ_SPHERICAL_EQRECT);
			SETOWNPROP(objs[1], PROJ_SPHERICAL_ORTHO, cv::PROJ_SPHERICAL_ORTHO);
			objs[2] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[1], Param, objs[2]);
			SETOWNPROP(objs[2], ALGORITHM, cv::Param::ALGORITHM);
			SETOWNPROP(objs[2], BOOLEAN, cv::Param::BOOLEAN);
			SETOWNPROP(objs[2], FLOAT, cv::Param::FLOAT);
			SETOWNPROP(objs[2], INT, cv::Param::INT);
			SETOWNPROP(objs[2], MAT, cv::Param::MAT);
			SETOWNPROP(objs[2], MAT_VECTOR, cv::Param::MAT_VECTOR);
			SETOWNPROP(objs[2], REAL, cv::Param::REAL);
			SETOWNPROP(objs[2], SCALAR, cv::Param::SCALAR);
			SETOWNPROP(objs[2], STRING, cv::Param::STRING);
			SETOWNPROP(objs[2], UCHAR, cv::Param::UCHAR);
			SETOWNPROP(objs[2], UINT64, cv::Param::UINT64);
			SETOWNPROP(objs[2], UNSIGNED_INT, cv::Param::UNSIGNED_INT);
			objs[2] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[1], QRCodeEncoder, objs[2]);
			SETOWNPROP(objs[2], CORRECT_LEVEL_H, cv::QRCodeEncoder::CORRECT_LEVEL_H);
			SETOWNPROP(objs[2], CORRECT_LEVEL_L, cv::QRCodeEncoder::CORRECT_LEVEL_L);
			SETOWNPROP(objs[2], CORRECT_LEVEL_M, cv::QRCodeEncoder::CORRECT_LEVEL_M);
			SETOWNPROP(objs[2], CORRECT_LEVEL_Q, cv::QRCodeEncoder::CORRECT_LEVEL_Q);
			SETOWNPROP(objs[2], ECI_UTF8, cv::QRCodeEncoder::ECI_UTF8);
			SETOWNPROP(objs[2], MODE_ALPHANUMERIC, cv::QRCodeEncoder::MODE_ALPHANUMERIC);
			SETOWNPROP(objs[2], MODE_AUTO, cv::QRCodeEncoder::MODE_AUTO);
			SETOWNPROP(objs[2], MODE_BYTE, cv::QRCodeEncoder::MODE_BYTE);
			SETOWNPROP(objs[2], MODE_ECI, cv::QRCodeEncoder::MODE_ECI);
			SETOWNPROP(objs[2], MODE_KANJI, cv::QRCodeEncoder::MODE_KANJI);
			SETOWNPROP(objs[2], MODE_NUMERIC, cv::QRCodeEncoder::MODE_NUMERIC);
			SETOWNPROP(objs[2], MODE_STRUCTURED_APPEND, cv::QRCodeEncoder::MODE_STRUCTURED_APPEND);
			SETOWNPROP(objs[1], QT_CHECKBOX, cv::QT_CHECKBOX);
			SETOWNPROP(objs[1], QT_FONT_BLACK, cv::QT_FONT_BLACK);
			SETOWNPROP(objs[1], QT_FONT_BOLD, cv::QT_FONT_BOLD);
			SETOWNPROP(objs[1], QT_FONT_DEMIBOLD, cv::QT_FONT_DEMIBOLD);
			SETOWNPROP(objs[1], QT_FONT_LIGHT, cv::QT_FONT_LIGHT);
			SETOWNPROP(objs[1], QT_FONT_NORMAL, cv::QT_FONT_NORMAL);
			SETOWNPROP(objs[1], QT_NEW_BUTTONBAR, cv::QT_NEW_BUTTONBAR);
			SETOWNPROP(objs[1], QT_PUSH_BUTTON, cv::QT_PUSH_BUTTON);
			SETOWNPROP(objs[1], QT_RADIOBOX, cv::QT_RADIOBOX);
			SETOWNPROP(objs[1], QT_STYLE_ITALIC, cv::QT_STYLE_ITALIC);
			SETOWNPROP(objs[1], QT_STYLE_NORMAL, cv::QT_STYLE_NORMAL);
			SETOWNPROP(objs[1], QT_STYLE_OBLIQUE, cv::QT_STYLE_OBLIQUE);
			SETOWNPROP(objs[1], QUAT_ASSUME_NOT_UNIT, cv::QUAT_ASSUME_NOT_UNIT);
			SETOWNPROP(objs[1], QUAT_ASSUME_UNIT, cv::QUAT_ASSUME_UNIT);
			objs[2] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[1], QuatEnum, objs[2]);
			SETOWNPROP(objs[2], EULER_ANGLES_MAX_VALUE, cv::QuatEnum::EULER_ANGLES_MAX_VALUE);
			SETOWNPROP(objs[2], EXT_XYX, cv::QuatEnum::EXT_XYX);
			SETOWNPROP(objs[2], EXT_XYZ, cv::QuatEnum::EXT_XYZ);
			SETOWNPROP(objs[2], EXT_XZX, cv::QuatEnum::EXT_XZX);
			SETOWNPROP(objs[2], EXT_XZY, cv::QuatEnum::EXT_XZY);
			SETOWNPROP(objs[2], EXT_YXY, cv::QuatEnum::EXT_YXY);
			SETOWNPROP(objs[2], EXT_YXZ, cv::QuatEnum::EXT_YXZ);
			SETOWNPROP(objs[2], EXT_YZX, cv::QuatEnum::EXT_YZX);
			SETOWNPROP(objs[2], EXT_YZY, cv::QuatEnum::EXT_YZY);
			SETOWNPROP(objs[2], EXT_ZXY, cv::QuatEnum::EXT_ZXY);
			SETOWNPROP(objs[2], EXT_ZXZ, cv::QuatEnum::EXT_ZXZ);
			SETOWNPROP(objs[2], EXT_ZYX, cv::QuatEnum::EXT_ZYX);
			SETOWNPROP(objs[2], EXT_ZYZ, cv::QuatEnum::EXT_ZYZ);
			SETOWNPROP(objs[2], INT_XYX, cv::QuatEnum::INT_XYX);
			SETOWNPROP(objs[2], INT_XYZ, cv::QuatEnum::INT_XYZ);
			SETOWNPROP(objs[2], INT_XZX, cv::QuatEnum::INT_XZX);
			SETOWNPROP(objs[2], INT_XZY, cv::QuatEnum::INT_XZY);
			SETOWNPROP(objs[2], INT_YXY, cv::QuatEnum::INT_YXY);
			SETOWNPROP(objs[2], INT_YXZ, cv::QuatEnum::INT_YXZ);
			SETOWNPROP(objs[2], INT_YZX, cv::QuatEnum::INT_YZX);
			SETOWNPROP(objs[2], INT_YZY, cv::QuatEnum::INT_YZY);
			SETOWNPROP(objs[2], INT_ZXY, cv::QuatEnum::INT_ZXY);
			SETOWNPROP(objs[2], INT_ZXZ, cv::QuatEnum::INT_ZXZ);
			SETOWNPROP(objs[2], INT_ZYX, cv::QuatEnum::INT_ZYX);
			SETOWNPROP(objs[2], INT_ZYZ, cv::QuatEnum::INT_ZYZ);
			SETOWNPROP(objs[1], RANSAC, cv::RANSAC);
			SETOWNPROP(objs[1], RECURS_FILTER, cv::RECURS_FILTER);
			SETOWNPROP(objs[1], REDUCE_AVG, cv::REDUCE_AVG);
			SETOWNPROP(objs[1], REDUCE_MAX, cv::REDUCE_MAX);
			SETOWNPROP(objs[1], REDUCE_MIN, cv::REDUCE_MIN);
			SETOWNPROP(objs[1], REDUCE_SUM, cv::REDUCE_SUM);
			SETOWNPROP(objs[1], RETR_CCOMP, cv::RETR_CCOMP);
			SETOWNPROP(objs[1], RETR_EXTERNAL, cv::RETR_EXTERNAL);
			SETOWNPROP(objs[1], RETR_FLOODFILL, cv::RETR_FLOODFILL);
			SETOWNPROP(objs[1], RETR_LIST, cv::RETR_LIST);
			SETOWNPROP(objs[1], RETR_TREE, cv::RETR_TREE);
			SETOWNPROP(objs[1], RHO, cv::RHO);
			objs[2] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[1], RMat, objs[2]);
			objs[3] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[2], Access, objs[3]);
			SETOWNPROP(objs[3], R, cv::RMat::Access::R);
			SETOWNPROP(objs[3], W, cv::RMat::Access::W);
			objs[2] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[1], RNG, objs[2]);
			SETOWNPROP(objs[2], NORMAL, cv::RNG::NORMAL);
			SETOWNPROP(objs[2], UNIFORM, cv::RNG::UNIFORM);
			SETOWNPROP(objs[1], ROTATE_180, cv::ROTATE_180);
			SETOWNPROP(objs[1], ROTATE_90_CLOCKWISE, cv::ROTATE_90_CLOCKWISE);
			SETOWNPROP(objs[1], ROTATE_90_COUNTERCLOCKWISE, cv::ROTATE_90_COUNTERCLOCKWISE);
			SETOWNPROP(objs[1], SAMPLING_NAPSAC, cv::SAMPLING_NAPSAC);
			SETOWNPROP(objs[1], SAMPLING_PROGRESSIVE_NAPSAC, cv::SAMPLING_PROGRESSIVE_NAPSAC);
			SETOWNPROP(objs[1], SAMPLING_PROSAC, cv::SAMPLING_PROSAC);
			SETOWNPROP(objs[1], SAMPLING_UNIFORM, cv::SAMPLING_UNIFORM);
			SETOWNPROP(objs[1], SCORE_METHOD_LMEDS, cv::SCORE_METHOD_LMEDS);
			SETOWNPROP(objs[1], SCORE_METHOD_MAGSAC, cv::SCORE_METHOD_MAGSAC);
			SETOWNPROP(objs[1], SCORE_METHOD_MSAC, cv::SCORE_METHOD_MSAC);
			SETOWNPROP(objs[1], SCORE_METHOD_RANSAC, cv::SCORE_METHOD_RANSAC);
			SETOWNPROP(objs[1], SOLVELP_MULTI, cv::SOLVELP_MULTI);
			SETOWNPROP(objs[1], SOLVELP_SINGLE, cv::SOLVELP_SINGLE);
			SETOWNPROP(objs[1], SOLVELP_UNBOUNDED, cv::SOLVELP_UNBOUNDED);
			SETOWNPROP(objs[1], SOLVELP_UNFEASIBLE, cv::SOLVELP_UNFEASIBLE);
			SETOWNPROP(objs[1], SOLVEPNP_AP3P, cv::SOLVEPNP_AP3P);
			SETOWNPROP(objs[1], SOLVEPNP_DLS, cv::SOLVEPNP_DLS);
			SETOWNPROP(objs[1], SOLVEPNP_EPNP, cv::SOLVEPNP_EPNP);
			SETOWNPROP(objs[1], SOLVEPNP_IPPE, cv::SOLVEPNP_IPPE);
			SETOWNPROP(objs[1], SOLVEPNP_IPPE_SQUARE, cv::SOLVEPNP_IPPE_SQUARE);
			SETOWNPROP(objs[1], SOLVEPNP_ITERATIVE, cv::SOLVEPNP_ITERATIVE);
			SETOWNPROP(objs[1], SOLVEPNP_MAX_COUNT, cv::SOLVEPNP_MAX_COUNT);
			SETOWNPROP(objs[1], SOLVEPNP_P3P, cv::SOLVEPNP_P3P);
			SETOWNPROP(objs[1], SOLVEPNP_SQPNP, cv::SOLVEPNP_SQPNP);
			SETOWNPROP(objs[1], SOLVEPNP_UPNP, cv::SOLVEPNP_UPNP);
			SETOWNPROP(objs[1], SORT_ASCENDING, cv::SORT_ASCENDING);
			SETOWNPROP(objs[1], SORT_DESCENDING, cv::SORT_DESCENDING);
			SETOWNPROP(objs[1], SORT_EVERY_COLUMN, cv::SORT_EVERY_COLUMN);
			SETOWNPROP(objs[1], SORT_EVERY_ROW, cv::SORT_EVERY_ROW);
			objs[2] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[1], SVD, objs[2]);
			SETOWNPROP(objs[2], FULL_UV, cv::SVD::FULL_UV);
			SETOWNPROP(objs[2], MODIFY_A, cv::SVD::MODIFY_A);
			SETOWNPROP(objs[2], NO_UV, cv::SVD::NO_UV);
			objs[2] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[1], SparseMat, objs[2]);
			SETOWNPROP(objs[2], HASH_BIT, cv::SparseMat::HASH_BIT);
			SETOWNPROP(objs[2], HASH_SCALE, cv::SparseMat::HASH_SCALE);
			SETOWNPROP(objs[2], MAGIC_VAL, cv::SparseMat::MAGIC_VAL);
			SETOWNPROP(objs[2], MAX_DIM, cv::SparseMat::MAX_DIM);
			objs[2] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[1], StereoBM, objs[2]);
			SETOWNPROP(objs[2], PREFILTER_NORMALIZED_RESPONSE, cv::StereoBM::PREFILTER_NORMALIZED_RESPONSE);
			SETOWNPROP(objs[2], PREFILTER_XSOBEL, cv::StereoBM::PREFILTER_XSOBEL);
			objs[2] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[1], StereoMatcher, objs[2]);
			SETOWNPROP(objs[2], DISP_SCALE, cv::StereoMatcher::DISP_SCALE);
			SETOWNPROP(objs[2], DISP_SHIFT, cv::StereoMatcher::DISP_SHIFT);
			objs[2] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[1], StereoSGBM, objs[2]);
			SETOWNPROP(objs[2], MODE_HH, cv::StereoSGBM::MODE_HH);
			SETOWNPROP(objs[2], MODE_HH4, cv::StereoSGBM::MODE_HH4);
			SETOWNPROP(objs[2], MODE_SGBM, cv::StereoSGBM::MODE_SGBM);
			SETOWNPROP(objs[2], MODE_SGBM_3WAY, cv::StereoSGBM::MODE_SGBM_3WAY);
			objs[2] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[1], Stitcher, objs[2]);
			SETOWNPROP(objs[2], ERR_CAMERA_PARAMS_ADJUST_FAIL, cv::Stitcher::ERR_CAMERA_PARAMS_ADJUST_FAIL);
			SETOWNPROP(objs[2], ERR_HOMOGRAPHY_EST_FAIL, cv::Stitcher::ERR_HOMOGRAPHY_EST_FAIL);
			SETOWNPROP(objs[2], ERR_NEED_MORE_IMGS, cv::Stitcher::ERR_NEED_MORE_IMGS);
			SETOWNPROP(objs[2], OK, cv::Stitcher::OK);
			SETOWNPROP(objs[2], PANORAMA, cv::Stitcher::PANORAMA);
			SETOWNPROP(objs[2], SCANS, cv::Stitcher::SCANS);
			objs[2] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[1], Subdiv2D, objs[2]);
			SETOWNPROP(objs[2], NEXT_AROUND_DST, cv::Subdiv2D::NEXT_AROUND_DST);
			SETOWNPROP(objs[2], NEXT_AROUND_LEFT, cv::Subdiv2D::NEXT_AROUND_LEFT);
			SETOWNPROP(objs[2], NEXT_AROUND_ORG, cv::Subdiv2D::NEXT_AROUND_ORG);
			SETOWNPROP(objs[2], NEXT_AROUND_RIGHT, cv::Subdiv2D::NEXT_AROUND_RIGHT);
			SETOWNPROP(objs[2], PREV_AROUND_DST, cv::Subdiv2D::PREV_AROUND_DST);
			SETOWNPROP(objs[2], PREV_AROUND_LEFT, cv::Subdiv2D::PREV_AROUND_LEFT);
			SETOWNPROP(objs[2], PREV_AROUND_ORG, cv::Subdiv2D::PREV_AROUND_ORG);
			SETOWNPROP(objs[2], PREV_AROUND_RIGHT, cv::Subdiv2D::PREV_AROUND_RIGHT);
			SETOWNPROP(objs[2], PTLOC_ERROR, cv::Subdiv2D::PTLOC_ERROR);
			SETOWNPROP(objs[2], PTLOC_INSIDE, cv::Subdiv2D::PTLOC_INSIDE);
			SETOWNPROP(objs[2], PTLOC_ON_EDGE, cv::Subdiv2D::PTLOC_ON_EDGE);
			SETOWNPROP(objs[2], PTLOC_OUTSIDE_RECT, cv::Subdiv2D::PTLOC_OUTSIDE_RECT);
			SETOWNPROP(objs[2], PTLOC_VERTEX, cv::Subdiv2D::PTLOC_VERTEX);
			SETOWNPROP(objs[1], THRESH_BINARY, cv::THRESH_BINARY);
			SETOWNPROP(objs[1], THRESH_BINARY_INV, cv::THRESH_BINARY_INV);
			SETOWNPROP(objs[1], THRESH_MASK, cv::THRESH_MASK);
			SETOWNPROP(objs[1], THRESH_OTSU, cv::THRESH_OTSU);
			SETOWNPROP(objs[1], THRESH_TOZERO, cv::THRESH_TOZERO);
			SETOWNPROP(objs[1], THRESH_TOZERO_INV, cv::THRESH_TOZERO_INV);
			SETOWNPROP(objs[1], THRESH_TRIANGLE, cv::THRESH_TRIANGLE);
			SETOWNPROP(objs[1], THRESH_TRUNC, cv::THRESH_TRUNC);
			SETOWNPROP(objs[1], TM_CCOEFF, cv::TM_CCOEFF);
			SETOWNPROP(objs[1], TM_CCOEFF_NORMED, cv::TM_CCOEFF_NORMED);
			SETOWNPROP(objs[1], TM_CCORR, cv::TM_CCORR);
			SETOWNPROP(objs[1], TM_CCORR_NORMED, cv::TM_CCORR_NORMED);
			SETOWNPROP(objs[1], TM_SQDIFF, cv::TM_SQDIFF);
			SETOWNPROP(objs[1], TM_SQDIFF_NORMED, cv::TM_SQDIFF_NORMED);
			objs[2] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[1], TermCriteria, objs[2]);
			SETOWNPROP(objs[2], COUNT, cv::TermCriteria::COUNT);
			SETOWNPROP(objs[2], EPS, cv::TermCriteria::EPS);
			SETOWNPROP(objs[2], MAX_ITER, cv::TermCriteria::MAX_ITER);
			objs[2] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[1], UMat, objs[2]);
			SETOWNPROP(objs[2], AUTO_STEP, cv::UMat::AUTO_STEP);
			SETOWNPROP(objs[2], CONTINUOUS_FLAG, cv::UMat::CONTINUOUS_FLAG);
			SETOWNPROP(objs[2], DEPTH_MASK, cv::UMat::DEPTH_MASK);
			SETOWNPROP(objs[2], MAGIC_MASK, cv::UMat::MAGIC_MASK);
			SETOWNPROP(objs[2], MAGIC_VAL, cv::UMat::MAGIC_VAL);
			SETOWNPROP(objs[2], SUBMATRIX_FLAG, cv::UMat::SUBMATRIX_FLAG);
			SETOWNPROP(objs[2], TYPE_MASK, cv::UMat::TYPE_MASK);
			objs[2] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[1], UMatData, objs[2]);
			SETOWNPROP(objs[2], ASYNC_CLEANUP, cv::UMatData::ASYNC_CLEANUP);
			SETOWNPROP(objs[2], COPY_ON_MAP, cv::UMatData::COPY_ON_MAP);
			SETOWNPROP(objs[2], DEVICE_COPY_OBSOLETE, cv::UMatData::DEVICE_COPY_OBSOLETE);
			SETOWNPROP(objs[2], DEVICE_MEM_MAPPED, cv::UMatData::DEVICE_MEM_MAPPED);
			SETOWNPROP(objs[2], HOST_COPY_OBSOLETE, cv::UMatData::HOST_COPY_OBSOLETE);
			SETOWNPROP(objs[2], TEMP_COPIED_UMAT, cv::UMatData::TEMP_COPIED_UMAT);
			SETOWNPROP(objs[2], TEMP_UMAT, cv::UMatData::TEMP_UMAT);
			SETOWNPROP(objs[2], USER_ALLOCATED, cv::UMatData::USER_ALLOCATED);
			SETOWNPROP(objs[1], USAC_ACCURATE, cv::USAC_ACCURATE);
			SETOWNPROP(objs[1], USAC_DEFAULT, cv::USAC_DEFAULT);
			SETOWNPROP(objs[1], USAC_FAST, cv::USAC_FAST);
			SETOWNPROP(objs[1], USAC_FM_8PTS, cv::USAC_FM_8PTS);
			SETOWNPROP(objs[1], USAC_MAGSAC, cv::USAC_MAGSAC);
			SETOWNPROP(objs[1], USAC_PARALLEL, cv::USAC_PARALLEL);
			SETOWNPROP(objs[1], USAC_PROSAC, cv::USAC_PROSAC);
			SETOWNPROP(objs[1], USAGE_ALLOCATE_DEVICE_MEMORY, cv::USAGE_ALLOCATE_DEVICE_MEMORY);
			SETOWNPROP(objs[1], USAGE_ALLOCATE_HOST_MEMORY, cv::USAGE_ALLOCATE_HOST_MEMORY);
			SETOWNPROP(objs[1], USAGE_ALLOCATE_SHARED_MEMORY, cv::USAGE_ALLOCATE_SHARED_MEMORY);
			SETOWNPROP(objs[1], USAGE_DEFAULT, cv::USAGE_DEFAULT);
			SETOWNPROP(objs[1], VIDEOWRITER_PROP_DEPTH, cv::VIDEOWRITER_PROP_DEPTH);
			SETOWNPROP(objs[1], VIDEOWRITER_PROP_FRAMEBYTES, cv::VIDEOWRITER_PROP_FRAMEBYTES);
			SETOWNPROP(objs[1], VIDEOWRITER_PROP_HW_ACCELERATION, cv::VIDEOWRITER_PROP_HW_ACCELERATION);
			SETOWNPROP(objs[1], VIDEOWRITER_PROP_HW_ACCELERATION_USE_OPENCL, cv::VIDEOWRITER_PROP_HW_ACCELERATION_USE_OPENCL);
			SETOWNPROP(objs[1], VIDEOWRITER_PROP_HW_DEVICE, cv::VIDEOWRITER_PROP_HW_DEVICE);
			SETOWNPROP(objs[1], VIDEOWRITER_PROP_IS_COLOR, cv::VIDEOWRITER_PROP_IS_COLOR);
			SETOWNPROP(objs[1], VIDEOWRITER_PROP_NSTRIPES, cv::VIDEOWRITER_PROP_NSTRIPES);
			SETOWNPROP(objs[1], VIDEOWRITER_PROP_QUALITY, cv::VIDEOWRITER_PROP_QUALITY);
			SETOWNPROP(objs[1], VIDEO_ACCELERATION_ANY, cv::VIDEO_ACCELERATION_ANY);
			SETOWNPROP(objs[1], VIDEO_ACCELERATION_D3D11, cv::VIDEO_ACCELERATION_D3D11);
			SETOWNPROP(objs[1], VIDEO_ACCELERATION_MFX, cv::VIDEO_ACCELERATION_MFX);
			SETOWNPROP(objs[1], VIDEO_ACCELERATION_NONE, cv::VIDEO_ACCELERATION_NONE);
			SETOWNPROP(objs[1], VIDEO_ACCELERATION_VAAPI, cv::VIDEO_ACCELERATION_VAAPI);
			SETOWNPROP(objs[1], WARP_FILL_OUTLIERS, cv::WARP_FILL_OUTLIERS);
			SETOWNPROP(objs[1], WARP_INVERSE_MAP, cv::WARP_INVERSE_MAP);
			SETOWNPROP(objs[1], WARP_POLAR_LINEAR, cv::WARP_POLAR_LINEAR);
			SETOWNPROP(objs[1], WARP_POLAR_LOG, cv::WARP_POLAR_LOG);
			SETOWNPROP(objs[1], WINDOW_AUTOSIZE, cv::WINDOW_AUTOSIZE);
			SETOWNPROP(objs[1], WINDOW_FREERATIO, cv::WINDOW_FREERATIO);
			SETOWNPROP(objs[1], WINDOW_FULLSCREEN, cv::WINDOW_FULLSCREEN);
			SETOWNPROP(objs[1], WINDOW_GUI_EXPANDED, cv::WINDOW_GUI_EXPANDED);
			SETOWNPROP(objs[1], WINDOW_GUI_NORMAL, cv::WINDOW_GUI_NORMAL);
			SETOWNPROP(objs[1], WINDOW_KEEPRATIO, cv::WINDOW_KEEPRATIO);
			SETOWNPROP(objs[1], WINDOW_NORMAL, cv::WINDOW_NORMAL);
			SETOWNPROP(objs[1], WINDOW_OPENGL, cv::WINDOW_OPENGL);
			SETOWNPROP(objs[1], WND_PROP_ASPECT_RATIO, cv::WND_PROP_ASPECT_RATIO);
			SETOWNPROP(objs[1], WND_PROP_AUTOSIZE, cv::WND_PROP_AUTOSIZE);
			SETOWNPROP(objs[1], WND_PROP_FULLSCREEN, cv::WND_PROP_FULLSCREEN);
			SETOWNPROP(objs[1], WND_PROP_OPENGL, cv::WND_PROP_OPENGL);
			SETOWNPROP(objs[1], WND_PROP_TOPMOST, cv::WND_PROP_TOPMOST);
			SETOWNPROP(objs[1], WND_PROP_VISIBLE, cv::WND_PROP_VISIBLE);
			SETOWNPROP(objs[1], WND_PROP_VSYNC, cv::WND_PROP_VSYNC);
			objs[2] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[1], _InputArray, objs[2]);
			SETOWNPROP(objs[2], CUDA_GPU_MAT, cv::_InputArray::CUDA_GPU_MAT);
			SETOWNPROP(objs[2], CUDA_HOST_MEM, cv::_InputArray::CUDA_HOST_MEM);
			SETOWNPROP(objs[2], EXPR, cv::_InputArray::EXPR);
			SETOWNPROP(objs[2], FIXED_SIZE, cv::_InputArray::FIXED_SIZE);
			SETOWNPROP(objs[2], FIXED_TYPE, cv::_InputArray::FIXED_TYPE);
			SETOWNPROP(objs[2], KIND_MASK, cv::_InputArray::KIND_MASK);
			SETOWNPROP(objs[2], KIND_SHIFT, cv::_InputArray::KIND_SHIFT);
			SETOWNPROP(objs[2], MAT, cv::_InputArray::MAT);
			SETOWNPROP(objs[2], MATX, cv::_InputArray::MATX);
			SETOWNPROP(objs[2], NONE, cv::_InputArray::NONE);
			SETOWNPROP(objs[2], OPENGL_BUFFER, cv::_InputArray::OPENGL_BUFFER);
			SETOWNPROP(objs[2], STD_ARRAY, cv::_InputArray::STD_ARRAY);
			SETOWNPROP(objs[2], STD_ARRAY_MAT, cv::_InputArray::STD_ARRAY_MAT);
			SETOWNPROP(objs[2], STD_BOOL_VECTOR, cv::_InputArray::STD_BOOL_VECTOR);
			SETOWNPROP(objs[2], STD_VECTOR, cv::_InputArray::STD_VECTOR);
			SETOWNPROP(objs[2], STD_VECTOR_CUDA_GPU_MAT, cv::_InputArray::STD_VECTOR_CUDA_GPU_MAT);
			SETOWNPROP(objs[2], STD_VECTOR_MAT, cv::_InputArray::STD_VECTOR_MAT);
			SETOWNPROP(objs[2], STD_VECTOR_UMAT, cv::_InputArray::STD_VECTOR_UMAT);
			SETOWNPROP(objs[2], STD_VECTOR_VECTOR, cv::_InputArray::STD_VECTOR_VECTOR);
			SETOWNPROP(objs[2], UMAT, cv::_InputArray::UMAT);
			objs[2] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[1], _OutputArray, objs[2]);
			SETOWNPROP(objs[2], DEPTH_MASK_16F, cv::_OutputArray::DEPTH_MASK_16F);
			SETOWNPROP(objs[2], DEPTH_MASK_16S, cv::_OutputArray::DEPTH_MASK_16S);
			SETOWNPROP(objs[2], DEPTH_MASK_16U, cv::_OutputArray::DEPTH_MASK_16U);
			SETOWNPROP(objs[2], DEPTH_MASK_32F, cv::_OutputArray::DEPTH_MASK_32F);
			SETOWNPROP(objs[2], DEPTH_MASK_32S, cv::_OutputArray::DEPTH_MASK_32S);
			SETOWNPROP(objs[2], DEPTH_MASK_64F, cv::_OutputArray::DEPTH_MASK_64F);
			SETOWNPROP(objs[2], DEPTH_MASK_8S, cv::_OutputArray::DEPTH_MASK_8S);
			SETOWNPROP(objs[2], DEPTH_MASK_8U, cv::_OutputArray::DEPTH_MASK_8U);
			SETOWNPROP(objs[2], DEPTH_MASK_ALL, cv::_OutputArray::DEPTH_MASK_ALL);
			SETOWNPROP(objs[2], DEPTH_MASK_ALL_16F, cv::_OutputArray::DEPTH_MASK_ALL_16F);
			SETOWNPROP(objs[2], DEPTH_MASK_ALL_BUT_8S, cv::_OutputArray::DEPTH_MASK_ALL_BUT_8S);
			SETOWNPROP(objs[2], DEPTH_MASK_FLT, cv::_OutputArray::DEPTH_MASK_FLT);
			SETOWNPROP(objs[1], __UMAT_USAGE_FLAGS_32BIT, cv::__UMAT_USAGE_FLAGS_32BIT);
			objs[2] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[1], cuda, objs[2]);
			SETOWNPROP(objs[2], DYNAMIC_PARALLELISM, cv::cuda::DYNAMIC_PARALLELISM);
			objs[3] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[2], DeviceInfo, objs[3]);
			SETOWNPROP(objs[3], ComputeModeDefault, cv::cuda::DeviceInfo::ComputeModeDefault);
			SETOWNPROP(objs[3], ComputeModeExclusive, cv::cuda::DeviceInfo::ComputeModeExclusive);
			SETOWNPROP(objs[3], ComputeModeExclusiveProcess, cv::cuda::DeviceInfo::ComputeModeExclusiveProcess);
			SETOWNPROP(objs[3], ComputeModeProhibited, cv::cuda::DeviceInfo::ComputeModeProhibited);
			objs[3] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[2], Event, objs[3]);
			SETOWNPROP(objs[3], BLOCKING_SYNC, cv::cuda::Event::BLOCKING_SYNC);
			SETOWNPROP(objs[3], DEFAULT, cv::cuda::Event::DEFAULT);
			SETOWNPROP(objs[3], DISABLE_TIMING, cv::cuda::Event::DISABLE_TIMING);
			SETOWNPROP(objs[3], INTERPROCESS, cv::cuda::Event::INTERPROCESS);
			SETOWNPROP(objs[2], FEATURE_SET_COMPUTE_10, cv::cuda::FEATURE_SET_COMPUTE_10);
			SETOWNPROP(objs[2], FEATURE_SET_COMPUTE_11, cv::cuda::FEATURE_SET_COMPUTE_11);
			SETOWNPROP(objs[2], FEATURE_SET_COMPUTE_12, cv::cuda::FEATURE_SET_COMPUTE_12);
			SETOWNPROP(objs[2], FEATURE_SET_COMPUTE_13, cv::cuda::FEATURE_SET_COMPUTE_13);
			SETOWNPROP(objs[2], FEATURE_SET_COMPUTE_20, cv::cuda::FEATURE_SET_COMPUTE_20);
			SETOWNPROP(objs[2], FEATURE_SET_COMPUTE_21, cv::cuda::FEATURE_SET_COMPUTE_21);
			SETOWNPROP(objs[2], FEATURE_SET_COMPUTE_30, cv::cuda::FEATURE_SET_COMPUTE_30);
			SETOWNPROP(objs[2], FEATURE_SET_COMPUTE_32, cv::cuda::FEATURE_SET_COMPUTE_32);
			SETOWNPROP(objs[2], FEATURE_SET_COMPUTE_35, cv::cuda::FEATURE_SET_COMPUTE_35);
			SETOWNPROP(objs[2], FEATURE_SET_COMPUTE_50, cv::cuda::FEATURE_SET_COMPUTE_50);
			SETOWNPROP(objs[2], GLOBAL_ATOMICS, cv::cuda::GLOBAL_ATOMICS);
			objs[3] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[2], HostMem, objs[3]);
			SETOWNPROP(objs[3], PAGE_LOCKED, cv::cuda::HostMem::PAGE_LOCKED);
			SETOWNPROP(objs[3], SHARED, cv::cuda::HostMem::SHARED);
			SETOWNPROP(objs[3], WRITE_COMBINED, cv::cuda::HostMem::WRITE_COMBINED);
			SETOWNPROP(objs[2], NATIVE_DOUBLE, cv::cuda::NATIVE_DOUBLE);
			SETOWNPROP(objs[2], SHARED_ATOMICS, cv::cuda::SHARED_ATOMICS);
			SETOWNPROP(objs[2], WARP_SHUFFLE_FUNCTIONS, cv::cuda::WARP_SHUFFLE_FUNCTIONS);
			objs[2] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[1], detail, objs[2]);
			objs[3] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[2], ArgKind, objs[3]);
			SETOWNPROP(objs[3], GARRAY, cv::detail::ArgKind::GARRAY);
			SETOWNPROP(objs[3], GFRAME, cv::detail::ArgKind::GFRAME);
			SETOWNPROP(objs[3], GMAT, cv::detail::ArgKind::GMAT);
			SETOWNPROP(objs[3], GMATP, cv::detail::ArgKind::GMATP);
			SETOWNPROP(objs[3], GOBJREF, cv::detail::ArgKind::GOBJREF);
			SETOWNPROP(objs[3], GOPAQUE, cv::detail::ArgKind::GOPAQUE);
			SETOWNPROP(objs[3], GSCALAR, cv::detail::ArgKind::GSCALAR);
			SETOWNPROP(objs[3], OPAQUE, cv::detail::ArgKind::OPAQUE_VAL);
			SETOWNPROP(objs[3], OPAQUE_VAL, cv::detail::ArgKind::OPAQUE_VAL);
			objs[3] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[2], Blender, objs[3]);
			SETOWNPROP(objs[3], FEATHER, cv::detail::Blender::FEATHER);
			SETOWNPROP(objs[3], MULTI_BAND, cv::detail::Blender::MULTI_BAND);
			SETOWNPROP(objs[3], NO, cv::detail::Blender::NO);
			objs[3] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[2], DpSeamFinder, objs[3]);
			SETOWNPROP(objs[3], COLOR, cv::detail::DpSeamFinder::COLOR);
			SETOWNPROP(objs[3], COLOR_GRAD, cv::detail::DpSeamFinder::COLOR_GRAD);
			objs[3] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[2], ExposureCompensator, objs[3]);
			SETOWNPROP(objs[3], CHANNELS, cv::detail::ExposureCompensator::CHANNELS);
			SETOWNPROP(objs[3], CHANNELS_BLOCKS, cv::detail::ExposureCompensator::CHANNELS_BLOCKS);
			SETOWNPROP(objs[3], GAIN, cv::detail::ExposureCompensator::GAIN);
			SETOWNPROP(objs[3], GAIN_BLOCKS, cv::detail::ExposureCompensator::GAIN_BLOCKS);
			SETOWNPROP(objs[3], NO, cv::detail::ExposureCompensator::NO);
			objs[3] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[2], GraphCutSeamFinderBase, objs[3]);
			SETOWNPROP(objs[3], COST_COLOR, cv::detail::GraphCutSeamFinderBase::COST_COLOR);
			SETOWNPROP(objs[3], COST_COLOR_GRAD, cv::detail::GraphCutSeamFinderBase::COST_COLOR_GRAD);
			objs[3] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[2], OpaqueKind, objs[3]);
			SETOWNPROP(objs[3], CV_BOOL, cv::detail::OpaqueKind::CV_BOOL);
			SETOWNPROP(objs[3], CV_DOUBLE, cv::detail::OpaqueKind::CV_DOUBLE);
			SETOWNPROP(objs[3], CV_DRAW_PRIM, cv::detail::OpaqueKind::CV_DRAW_PRIM);
			SETOWNPROP(objs[3], CV_FLOAT, cv::detail::OpaqueKind::CV_FLOAT);
			SETOWNPROP(objs[3], CV_INT, cv::detail::OpaqueKind::CV_INT);
			SETOWNPROP(objs[3], CV_INT64, cv::detail::OpaqueKind::CV_INT64);
			SETOWNPROP(objs[3], CV_MAT, cv::detail::OpaqueKind::CV_MAT);
			SETOWNPROP(objs[3], CV_POINT, cv::detail::OpaqueKind::CV_POINT);
			SETOWNPROP(objs[3], CV_POINT2F, cv::detail::OpaqueKind::CV_POINT2F);
			SETOWNPROP(objs[3], CV_RECT, cv::detail::OpaqueKind::CV_RECT);
			SETOWNPROP(objs[3], CV_SCALAR, cv::detail::OpaqueKind::CV_SCALAR);
			SETOWNPROP(objs[3], CV_SIZE, cv::detail::OpaqueKind::CV_SIZE);
			SETOWNPROP(objs[3], CV_STRING, cv::detail::OpaqueKind::CV_STRING);
			SETOWNPROP(objs[3], CV_UINT64, cv::detail::OpaqueKind::CV_UINT64);
			SETOWNPROP(objs[3], CV_UNKNOWN, cv::detail::OpaqueKind::CV_UNKNOWN);
			objs[3] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[2], SeamFinder, objs[3]);
			SETOWNPROP(objs[3], DP_SEAM, cv::detail::SeamFinder::DP_SEAM);
			SETOWNPROP(objs[3], NO, cv::detail::SeamFinder::NO);
			SETOWNPROP(objs[3], VORONOI_SEAM, cv::detail::SeamFinder::VORONOI_SEAM);
			SETOWNPROP(objs[2], TEST_CUSTOM, cv::detail::TEST_CUSTOM);
			SETOWNPROP(objs[2], TEST_EQ, cv::detail::TEST_EQ);
			SETOWNPROP(objs[2], TEST_GE, cv::detail::TEST_GE);
			SETOWNPROP(objs[2], TEST_GT, cv::detail::TEST_GT);
			SETOWNPROP(objs[2], TEST_LE, cv::detail::TEST_LE);
			SETOWNPROP(objs[2], TEST_LT, cv::detail::TEST_LT);
			SETOWNPROP(objs[2], TEST_NE, cv::detail::TEST_NE);
			objs[3] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[2], Timelapser, objs[3]);
			SETOWNPROP(objs[3], AS_IS, cv::detail::Timelapser::AS_IS);
			SETOWNPROP(objs[3], CROP, cv::detail::Timelapser::CROP);
			objs[3] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[2], TrackerSamplerCSC, objs[3]);
			SETOWNPROP(objs[3], MODE_DETECT, cv::detail::TrackerSamplerCSC::MODE_DETECT);
			SETOWNPROP(objs[3], MODE_INIT_NEG, cv::detail::TrackerSamplerCSC::MODE_INIT_NEG);
			SETOWNPROP(objs[3], MODE_INIT_POS, cv::detail::TrackerSamplerCSC::MODE_INIT_POS);
			SETOWNPROP(objs[3], MODE_TRACK_NEG, cv::detail::TrackerSamplerCSC::MODE_TRACK_NEG);
			SETOWNPROP(objs[3], MODE_TRACK_POS, cv::detail::TrackerSamplerCSC::MODE_TRACK_POS);
			SETOWNPROP(objs[2], WAVE_CORRECT_AUTO, cv::detail::WAVE_CORRECT_AUTO);
			SETOWNPROP(objs[2], WAVE_CORRECT_HORIZ, cv::detail::WAVE_CORRECT_HORIZ);
			SETOWNPROP(objs[2], WAVE_CORRECT_VERT, cv::detail::WAVE_CORRECT_VERT);
			objs[2] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[1], dnn, objs[2]);
			SETOWNPROP(objs[2], DNN_BACKEND_CUDA, cv::dnn::DNN_BACKEND_CUDA);
			SETOWNPROP(objs[2], DNN_BACKEND_DEFAULT, cv::dnn::DNN_BACKEND_DEFAULT);
			SETOWNPROP(objs[2], DNN_BACKEND_HALIDE, cv::dnn::DNN_BACKEND_HALIDE);
			SETOWNPROP(objs[2], DNN_BACKEND_INFERENCE_ENGINE, cv::dnn::DNN_BACKEND_INFERENCE_ENGINE);
			SETOWNPROP(objs[2], DNN_BACKEND_OPENCV, cv::dnn::DNN_BACKEND_OPENCV);
			SETOWNPROP(objs[2], DNN_BACKEND_VKCOM, cv::dnn::DNN_BACKEND_VKCOM);
			SETOWNPROP(objs[2], DNN_BACKEND_WEBNN, cv::dnn::DNN_BACKEND_WEBNN);
			SETOWNPROP(objs[2], DNN_TARGET_CPU, cv::dnn::DNN_TARGET_CPU);
			SETOWNPROP(objs[2], DNN_TARGET_CUDA, cv::dnn::DNN_TARGET_CUDA);
			SETOWNPROP(objs[2], DNN_TARGET_CUDA_FP16, cv::dnn::DNN_TARGET_CUDA_FP16);
			SETOWNPROP(objs[2], DNN_TARGET_FPGA, cv::dnn::DNN_TARGET_FPGA);
			SETOWNPROP(objs[2], DNN_TARGET_HDDL, cv::dnn::DNN_TARGET_HDDL);
			SETOWNPROP(objs[2], DNN_TARGET_MYRIAD, cv::dnn::DNN_TARGET_MYRIAD);
			SETOWNPROP(objs[2], DNN_TARGET_OPENCL, cv::dnn::DNN_TARGET_OPENCL);
			SETOWNPROP(objs[2], DNN_TARGET_OPENCL_FP16, cv::dnn::DNN_TARGET_OPENCL_FP16);
			SETOWNPROP(objs[2], DNN_TARGET_VULKAN, cv::dnn::DNN_TARGET_VULKAN);
			objs[3] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[2], SoftNMSMethod, objs[3]);
			SETOWNPROP(objs[3], SOFTNMS_GAUSSIAN, cv::dnn::SoftNMSMethod::SOFTNMS_GAUSSIAN);
			SETOWNPROP(objs[3], SOFTNMS_LINEAR, cv::dnn::SoftNMSMethod::SOFTNMS_LINEAR);
			objs[2] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[1], fisheye, objs[2]);
			SETOWNPROP(objs[2], CALIB_CHECK_COND, cv::fisheye::CALIB_CHECK_COND);
			SETOWNPROP(objs[2], CALIB_FIX_FOCAL_LENGTH, cv::fisheye::CALIB_FIX_FOCAL_LENGTH);
			SETOWNPROP(objs[2], CALIB_FIX_INTRINSIC, cv::fisheye::CALIB_FIX_INTRINSIC);
			SETOWNPROP(objs[2], CALIB_FIX_K1, cv::fisheye::CALIB_FIX_K1);
			SETOWNPROP(objs[2], CALIB_FIX_K2, cv::fisheye::CALIB_FIX_K2);
			SETOWNPROP(objs[2], CALIB_FIX_K3, cv::fisheye::CALIB_FIX_K3);
			SETOWNPROP(objs[2], CALIB_FIX_K4, cv::fisheye::CALIB_FIX_K4);
			SETOWNPROP(objs[2], CALIB_FIX_PRINCIPAL_POINT, cv::fisheye::CALIB_FIX_PRINCIPAL_POINT);
			SETOWNPROP(objs[2], CALIB_FIX_SKEW, cv::fisheye::CALIB_FIX_SKEW);
			SETOWNPROP(objs[2], CALIB_RECOMPUTE_EXTRINSIC, cv::fisheye::CALIB_RECOMPUTE_EXTRINSIC);
			SETOWNPROP(objs[2], CALIB_USE_INTRINSIC_GUESS, cv::fisheye::CALIB_USE_INTRINSIC_GUESS);
			SETOWNPROP(objs[2], CALIB_ZERO_DISPARITY, cv::fisheye::CALIB_ZERO_DISPARITY);
			objs[2] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[1], flann, objs[2]);
			SETOWNPROP(objs[2], FLANN_INDEX_TYPE_16S, cv::flann::FLANN_INDEX_TYPE_16S);
			SETOWNPROP(objs[2], FLANN_INDEX_TYPE_16U, cv::flann::FLANN_INDEX_TYPE_16U);
			SETOWNPROP(objs[2], FLANN_INDEX_TYPE_32F, cv::flann::FLANN_INDEX_TYPE_32F);
			SETOWNPROP(objs[2], FLANN_INDEX_TYPE_32S, cv::flann::FLANN_INDEX_TYPE_32S);
			SETOWNPROP(objs[2], FLANN_INDEX_TYPE_64F, cv::flann::FLANN_INDEX_TYPE_64F);
			SETOWNPROP(objs[2], FLANN_INDEX_TYPE_8S, cv::flann::FLANN_INDEX_TYPE_8S);
			SETOWNPROP(objs[2], FLANN_INDEX_TYPE_8U, cv::flann::FLANN_INDEX_TYPE_8U);
			SETOWNPROP(objs[2], FLANN_INDEX_TYPE_ALGORITHM, cv::flann::FLANN_INDEX_TYPE_ALGORITHM);
			SETOWNPROP(objs[2], FLANN_INDEX_TYPE_BOOL, cv::flann::FLANN_INDEX_TYPE_BOOL);
			SETOWNPROP(objs[2], FLANN_INDEX_TYPE_STRING, cv::flann::FLANN_INDEX_TYPE_STRING);
			SETOWNPROP(objs[2], LAST_VALUE_FLANN_INDEX_TYPE, cv::flann::LAST_VALUE_FLANN_INDEX_TYPE);
			objs[2] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[1], gapi, objs[2]);
			objs[3] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[2], StereoOutputFormat, objs[3]);
			SETOWNPROP(objs[3], DEPTH_16F, cv::gapi::StereoOutputFormat::DEPTH_16F);
			SETOWNPROP(objs[3], DEPTH_32F, cv::gapi::StereoOutputFormat::DEPTH_32F);
			SETOWNPROP(objs[3], DEPTH_FLOAT16, cv::gapi::StereoOutputFormat::DEPTH_FLOAT16);
			SETOWNPROP(objs[3], DEPTH_FLOAT32, cv::gapi::StereoOutputFormat::DEPTH_FLOAT32);
			SETOWNPROP(objs[3], DISPARITY_16Q_10_5, cv::gapi::StereoOutputFormat::DISPARITY_16Q_10_5);
			SETOWNPROP(objs[3], DISPARITY_16Q_11_4, cv::gapi::StereoOutputFormat::DISPARITY_16Q_11_4);
			SETOWNPROP(objs[3], DISPARITY_FIXED16_11_5, cv::gapi::StereoOutputFormat::DISPARITY_FIXED16_11_5);
			SETOWNPROP(objs[3], DISPARITY_FIXED16_12_4, cv::gapi::StereoOutputFormat::DISPARITY_FIXED16_12_4);
			objs[3] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[2], ie, objs[3]);
			objs[4] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[3], TraitAs, objs[4]);
			SETOWNPROP(objs[4], IMAGE, cv::gapi::ie::TraitAs::IMAGE);
			SETOWNPROP(objs[4], TENSOR, cv::gapi::ie::TraitAs::TENSOR);
			objs[4] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[3], detail, objs[4]);
			objs[5] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[4], ParamDesc, objs[5]);
			objs[6] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[5], Kind, objs[6]);
			SETOWNPROP(objs[6], Import, cv::gapi::ie::detail::ParamDesc::Kind::Import);
			SETOWNPROP(objs[6], Load, cv::gapi::ie::detail::ParamDesc::Kind::Load);
			objs[3] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[2], onnx, objs[3]);
			objs[4] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[3], TraitAs, objs[4]);
			SETOWNPROP(objs[4], IMAGE, cv::gapi::onnx::TraitAs::IMAGE);
			SETOWNPROP(objs[4], TENSOR, cv::gapi::onnx::TraitAs::TENSOR);
			objs[3] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[2], own, objs[3]);
			objs[4] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[3], detail, objs[4]);
			objs[5] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[4], MatHeader, objs[5]);
			SETOWNPROP(objs[5], AUTO_STEP, cv::gapi::own::detail::MatHeader::AUTO_STEP);
			SETOWNPROP(objs[5], TYPE_MASK, cv::gapi::own::detail::MatHeader::TYPE_MASK);
			objs[3] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[2], streaming, objs[3]);
			objs[4] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[3], sync_policy, objs[4]);
			SETOWNPROP(objs[4], dont_sync, cv::gapi::streaming::sync_policy::dont_sync);
			SETOWNPROP(objs[4], drop, cv::gapi::streaming::sync_policy::drop);
			objs[3] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[2], video, objs[3]);
			SETOWNPROP(objs[3], TYPE_BS_KNN, cv::gapi::video::TYPE_BS_KNN);
			SETOWNPROP(objs[3], TYPE_BS_MOG2, cv::gapi::video::TYPE_BS_MOG2);
			objs[3] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[2], wip, objs[3]);
			objs[4] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[3], gst, objs[4]);
			objs[5] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[4], GStreamerSource, objs[5]);
			objs[6] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[5], OutputType, objs[6]);
			SETOWNPROP(objs[6], FRAME, cv::gapi::wip::gst::GStreamerSource::OutputType::FRAME);
			SETOWNPROP(objs[6], MAT, cv::gapi::wip::gst::GStreamerSource::OutputType::MAT);
			objs[4] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[3], onevpl, objs[4]);
			objs[5] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[4], AccelType, objs[5]);
			SETOWNPROP(objs[5], DX11, cv::gapi::wip::onevpl::AccelType::DX11);
			SETOWNPROP(objs[5], HOST, cv::gapi::wip::onevpl::AccelType::HOST);
			SETOWNPROP(objs[5], LAST_VALUE, cv::gapi::wip::onevpl::AccelType::LAST_VALUE);
			objs[2] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[1], ml, objs[2]);
			objs[3] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[2], ANN_MLP, objs[3]);
			SETOWNPROP(objs[3], ANNEAL, cv::ml::ANN_MLP::ANNEAL);
			SETOWNPROP(objs[3], BACKPROP, cv::ml::ANN_MLP::BACKPROP);
			SETOWNPROP(objs[3], GAUSSIAN, cv::ml::ANN_MLP::GAUSSIAN);
			SETOWNPROP(objs[3], IDENTITY, cv::ml::ANN_MLP::IDENTITY);
			SETOWNPROP(objs[3], LEAKYRELU, cv::ml::ANN_MLP::LEAKYRELU);
			SETOWNPROP(objs[3], NO_INPUT_SCALE, cv::ml::ANN_MLP::NO_INPUT_SCALE);
			SETOWNPROP(objs[3], NO_OUTPUT_SCALE, cv::ml::ANN_MLP::NO_OUTPUT_SCALE);
			SETOWNPROP(objs[3], RELU, cv::ml::ANN_MLP::RELU);
			SETOWNPROP(objs[3], RPROP, cv::ml::ANN_MLP::RPROP);
			SETOWNPROP(objs[3], SIGMOID_SYM, cv::ml::ANN_MLP::SIGMOID_SYM);
			SETOWNPROP(objs[3], UPDATE_WEIGHTS, cv::ml::ANN_MLP::UPDATE_WEIGHTS);
			objs[3] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[2], Boost, objs[3]);
			SETOWNPROP(objs[3], DISCRETE, cv::ml::Boost::DISCRETE);
			SETOWNPROP(objs[3], GENTLE, cv::ml::Boost::GENTLE);
			SETOWNPROP(objs[3], LOGIT, cv::ml::Boost::LOGIT);
			SETOWNPROP(objs[3], REAL, cv::ml::Boost::REAL);
			SETOWNPROP(objs[2], COL_SAMPLE, cv::ml::COL_SAMPLE);
			objs[3] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[2], DTrees, objs[3]);
			SETOWNPROP(objs[3], PREDICT_AUTO, cv::ml::DTrees::PREDICT_AUTO);
			SETOWNPROP(objs[3], PREDICT_MASK, cv::ml::DTrees::PREDICT_MASK);
			SETOWNPROP(objs[3], PREDICT_MAX_VOTE, cv::ml::DTrees::PREDICT_MAX_VOTE);
			SETOWNPROP(objs[3], PREDICT_SUM, cv::ml::DTrees::PREDICT_SUM);
			objs[3] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[2], EM, objs[3]);
			SETOWNPROP(objs[3], COV_MAT_DEFAULT, cv::ml::EM::COV_MAT_DEFAULT);
			SETOWNPROP(objs[3], COV_MAT_DIAGONAL, cv::ml::EM::COV_MAT_DIAGONAL);
			SETOWNPROP(objs[3], COV_MAT_GENERIC, cv::ml::EM::COV_MAT_GENERIC);
			SETOWNPROP(objs[3], COV_MAT_SPHERICAL, cv::ml::EM::COV_MAT_SPHERICAL);
			SETOWNPROP(objs[3], DEFAULT_MAX_ITERS, cv::ml::EM::DEFAULT_MAX_ITERS);
			SETOWNPROP(objs[3], DEFAULT_NCLUSTERS, cv::ml::EM::DEFAULT_NCLUSTERS);
			SETOWNPROP(objs[3], START_AUTO_STEP, cv::ml::EM::START_AUTO_STEP);
			SETOWNPROP(objs[3], START_E_STEP, cv::ml::EM::START_E_STEP);
			SETOWNPROP(objs[3], START_M_STEP, cv::ml::EM::START_M_STEP);
			objs[3] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[2], KNearest, objs[3]);
			SETOWNPROP(objs[3], BRUTE_FORCE, cv::ml::KNearest::BRUTE_FORCE);
			SETOWNPROP(objs[3], KDTREE, cv::ml::KNearest::KDTREE);
			objs[3] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[2], LogisticRegression, objs[3]);
			SETOWNPROP(objs[3], BATCH, cv::ml::LogisticRegression::BATCH);
			SETOWNPROP(objs[3], MINI_BATCH, cv::ml::LogisticRegression::MINI_BATCH);
			SETOWNPROP(objs[3], REG_DISABLE, cv::ml::LogisticRegression::REG_DISABLE);
			SETOWNPROP(objs[3], REG_L1, cv::ml::LogisticRegression::REG_L1);
			SETOWNPROP(objs[3], REG_L2, cv::ml::LogisticRegression::REG_L2);
			SETOWNPROP(objs[2], ROW_SAMPLE, cv::ml::ROW_SAMPLE);
			objs[3] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[2], SVM, objs[3]);
			SETOWNPROP(objs[3], C, cv::ml::SVM::C);
			SETOWNPROP(objs[3], CHI2, cv::ml::SVM::CHI2);
			SETOWNPROP(objs[3], COEF, cv::ml::SVM::COEF);
			SETOWNPROP(objs[3], CUSTOM, cv::ml::SVM::CUSTOM);
			SETOWNPROP(objs[3], C_SVC, cv::ml::SVM::C_SVC);
			SETOWNPROP(objs[3], DEGREE, cv::ml::SVM::DEGREE);
			SETOWNPROP(objs[3], EPS_SVR, cv::ml::SVM::EPS_SVR);
			SETOWNPROP(objs[3], GAMMA, cv::ml::SVM::GAMMA);
			SETOWNPROP(objs[3], INTER, cv::ml::SVM::INTER);
			SETOWNPROP(objs[3], LINEAR, cv::ml::SVM::LINEAR);
			SETOWNPROP(objs[3], NU, cv::ml::SVM::NU);
			SETOWNPROP(objs[3], NU_SVC, cv::ml::SVM::NU_SVC);
			SETOWNPROP(objs[3], NU_SVR, cv::ml::SVM::NU_SVR);
			SETOWNPROP(objs[3], ONE_CLASS, cv::ml::SVM::ONE_CLASS);
			SETOWNPROP(objs[3], P, cv::ml::SVM::P);
			SETOWNPROP(objs[3], POLY, cv::ml::SVM::POLY);
			SETOWNPROP(objs[3], RBF, cv::ml::SVM::RBF);
			SETOWNPROP(objs[3], SIGMOID, cv::ml::SVM::SIGMOID);
			objs[3] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[2], SVMSGD, objs[3]);
			SETOWNPROP(objs[3], ASGD, cv::ml::SVMSGD::ASGD);
			SETOWNPROP(objs[3], HARD_MARGIN, cv::ml::SVMSGD::HARD_MARGIN);
			SETOWNPROP(objs[3], SGD, cv::ml::SVMSGD::SGD);
			SETOWNPROP(objs[3], SOFT_MARGIN, cv::ml::SVMSGD::SOFT_MARGIN);
			objs[3] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[2], StatModel, objs[3]);
			SETOWNPROP(objs[3], COMPRESSED_INPUT, cv::ml::StatModel::COMPRESSED_INPUT);
			SETOWNPROP(objs[3], PREPROCESSED_INPUT, cv::ml::StatModel::PREPROCESSED_INPUT);
			SETOWNPROP(objs[3], RAW_OUTPUT, cv::ml::StatModel::RAW_OUTPUT);
			SETOWNPROP(objs[3], UPDATE_MODEL, cv::ml::StatModel::UPDATE_MODEL);
			SETOWNPROP(objs[2], TEST_ERROR, cv::ml::TEST_ERROR);
			SETOWNPROP(objs[2], TRAIN_ERROR, cv::ml::TRAIN_ERROR);
			SETOWNPROP(objs[2], VAR_CATEGORICAL, cv::ml::VAR_CATEGORICAL);
			SETOWNPROP(objs[2], VAR_NUMERICAL, cv::ml::VAR_NUMERICAL);
			SETOWNPROP(objs[2], VAR_ORDERED, cv::ml::VAR_ORDERED);
			objs[2] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[1], ocl, objs[2]);
			objs[3] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[2], Device, objs[3]);
			SETOWNPROP(objs[3], EXEC_KERNEL, cv::ocl::Device::EXEC_KERNEL);
			SETOWNPROP(objs[3], EXEC_NATIVE_KERNEL, cv::ocl::Device::EXEC_NATIVE_KERNEL);
			SETOWNPROP(objs[3], FP_CORRECTLY_ROUNDED_DIVIDE_SQRT, cv::ocl::Device::FP_CORRECTLY_ROUNDED_DIVIDE_SQRT);
			SETOWNPROP(objs[3], FP_DENORM, cv::ocl::Device::FP_DENORM);
			SETOWNPROP(objs[3], FP_FMA, cv::ocl::Device::FP_FMA);
			SETOWNPROP(objs[3], FP_INF_NAN, cv::ocl::Device::FP_INF_NAN);
			SETOWNPROP(objs[3], FP_ROUND_TO_INF, cv::ocl::Device::FP_ROUND_TO_INF);
			SETOWNPROP(objs[3], FP_ROUND_TO_NEAREST, cv::ocl::Device::FP_ROUND_TO_NEAREST);
			SETOWNPROP(objs[3], FP_ROUND_TO_ZERO, cv::ocl::Device::FP_ROUND_TO_ZERO);
			SETOWNPROP(objs[3], FP_SOFT_FLOAT, cv::ocl::Device::FP_SOFT_FLOAT);
			SETOWNPROP(objs[3], LOCAL_IS_GLOBAL, cv::ocl::Device::LOCAL_IS_GLOBAL);
			SETOWNPROP(objs[3], LOCAL_IS_LOCAL, cv::ocl::Device::LOCAL_IS_LOCAL);
			SETOWNPROP(objs[3], NO_CACHE, cv::ocl::Device::NO_CACHE);
			SETOWNPROP(objs[3], NO_LOCAL_MEM, cv::ocl::Device::NO_LOCAL_MEM);
			SETOWNPROP(objs[3], READ_ONLY_CACHE, cv::ocl::Device::READ_ONLY_CACHE);
			SETOWNPROP(objs[3], READ_WRITE_CACHE, cv::ocl::Device::READ_WRITE_CACHE);
			SETOWNPROP(objs[3], TYPE_ACCELERATOR, cv::ocl::Device::TYPE_ACCELERATOR);
			SETOWNPROP(objs[3], TYPE_ALL, cv::ocl::Device::TYPE_ALL);
			SETOWNPROP(objs[3], TYPE_CPU, cv::ocl::Device::TYPE_CPU);
			SETOWNPROP(objs[3], TYPE_DEFAULT, cv::ocl::Device::TYPE_DEFAULT);
			SETOWNPROP(objs[3], TYPE_DGPU, cv::ocl::Device::TYPE_DGPU);
			SETOWNPROP(objs[3], TYPE_GPU, cv::ocl::Device::TYPE_GPU);
			SETOWNPROP(objs[3], TYPE_IGPU, cv::ocl::Device::TYPE_IGPU);
			SETOWNPROP(objs[3], UNKNOWN_VENDOR, cv::ocl::Device::UNKNOWN_VENDOR);
			SETOWNPROP(objs[3], VENDOR_AMD, cv::ocl::Device::VENDOR_AMD);
			SETOWNPROP(objs[3], VENDOR_INTEL, cv::ocl::Device::VENDOR_INTEL);
			SETOWNPROP(objs[3], VENDOR_NVIDIA, cv::ocl::Device::VENDOR_NVIDIA);
			objs[3] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[2], KernelArg, objs[3]);
			SETOWNPROP(objs[3], CONSTANT, cv::ocl::KernelArg::CONSTANT);
			SETOWNPROP(objs[3], LOCAL, cv::ocl::KernelArg::LOCAL);
			SETOWNPROP(objs[3], NO_SIZE, cv::ocl::KernelArg::NO_SIZE);
			SETOWNPROP(objs[3], PTR_ONLY, cv::ocl::KernelArg::PTR_ONLY);
			SETOWNPROP(objs[3], READ_ONLY, cv::ocl::KernelArg::READ_ONLY);
			SETOWNPROP(objs[3], READ_WRITE, cv::ocl::KernelArg::READ_WRITE);
			SETOWNPROP(objs[3], WRITE_ONLY, cv::ocl::KernelArg::WRITE_ONLY);
			SETOWNPROP(objs[2], OCL_VECTOR_DEFAULT, cv::ocl::OCL_VECTOR_DEFAULT);
			SETOWNPROP(objs[2], OCL_VECTOR_MAX, cv::ocl::OCL_VECTOR_MAX);
			SETOWNPROP(objs[2], OCL_VECTOR_OWN, cv::ocl::OCL_VECTOR_OWN);
			objs[2] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[1], ogl, objs[2]);
			objs[3] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[2], Buffer, objs[3]);
			SETOWNPROP(objs[3], ARRAY_BUFFER, cv::ogl::Buffer::ARRAY_BUFFER);
			SETOWNPROP(objs[3], ELEMENT_ARRAY_BUFFER, cv::ogl::Buffer::ELEMENT_ARRAY_BUFFER);
			SETOWNPROP(objs[3], PIXEL_PACK_BUFFER, cv::ogl::Buffer::PIXEL_PACK_BUFFER);
			SETOWNPROP(objs[3], PIXEL_UNPACK_BUFFER, cv::ogl::Buffer::PIXEL_UNPACK_BUFFER);
			SETOWNPROP(objs[3], READ_ONLY, cv::ogl::Buffer::READ_ONLY);
			SETOWNPROP(objs[3], READ_WRITE, cv::ogl::Buffer::READ_WRITE);
			SETOWNPROP(objs[3], WRITE_ONLY, cv::ogl::Buffer::WRITE_ONLY);
			SETOWNPROP(objs[2], LINES, cv::ogl::LINES);
			SETOWNPROP(objs[2], LINE_LOOP, cv::ogl::LINE_LOOP);
			SETOWNPROP(objs[2], LINE_STRIP, cv::ogl::LINE_STRIP);
			SETOWNPROP(objs[2], POINTS, cv::ogl::POINTS);
			SETOWNPROP(objs[2], POLYGON, cv::ogl::POLYGON);
			SETOWNPROP(objs[2], QUADS, cv::ogl::QUADS);
			SETOWNPROP(objs[2], QUAD_STRIP, cv::ogl::QUAD_STRIP);
			SETOWNPROP(objs[2], TRIANGLES, cv::ogl::TRIANGLES);
			SETOWNPROP(objs[2], TRIANGLE_FAN, cv::ogl::TRIANGLE_FAN);
			SETOWNPROP(objs[2], TRIANGLE_STRIP, cv::ogl::TRIANGLE_STRIP);
			objs[3] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[2], Texture2D, objs[3]);
			SETOWNPROP(objs[3], DEPTH_COMPONENT, cv::ogl::Texture2D::DEPTH_COMPONENT);
			SETOWNPROP(objs[3], NONE, cv::ogl::Texture2D::NONE);
			SETOWNPROP(objs[3], RGB, cv::ogl::Texture2D::RGB);
			SETOWNPROP(objs[3], RGBA, cv::ogl::Texture2D::RGBA);
			objs[1] = (Object*)g_ahkapi->Object_New(IAhkApi::ObjectType::Object);
			SETOWNPROP2(objs[0], cvflann, objs[1]);
			SETOWNPROP(objs[1], AUTOTUNED, cvflann::AUTOTUNED);
			SETOWNPROP(objs[1], CENTERS_GONZALES, cvflann::CENTERS_GONZALES);
			SETOWNPROP(objs[1], CENTERS_KMEANSPP, cvflann::CENTERS_KMEANSPP);
			SETOWNPROP(objs[1], CENTERS_RANDOM, cvflann::CENTERS_RANDOM);
			SETOWNPROP(objs[1], COMPOSITE, cvflann::COMPOSITE);
			SETOWNPROP(objs[1], CS, cvflann::CS);
			SETOWNPROP(objs[1], EUCLIDEAN, cvflann::EUCLIDEAN);
			SETOWNPROP(objs[1], FLANN_CENTERS_GONZALES, cvflann::FLANN_CENTERS_GONZALES);
			SETOWNPROP(objs[1], FLANN_CENTERS_GROUPWISE, cvflann::FLANN_CENTERS_GROUPWISE);
			SETOWNPROP(objs[1], FLANN_CENTERS_KMEANSPP, cvflann::FLANN_CENTERS_KMEANSPP);
			SETOWNPROP(objs[1], FLANN_CENTERS_RANDOM, cvflann::FLANN_CENTERS_RANDOM);
			SETOWNPROP(objs[1], FLANN_CHECKS_AUTOTUNED, cvflann::FLANN_CHECKS_AUTOTUNED);
			SETOWNPROP(objs[1], FLANN_CHECKS_UNLIMITED, cvflann::FLANN_CHECKS_UNLIMITED);
			SETOWNPROP(objs[1], FLANN_DIST_CHI_SQUARE, cvflann::FLANN_DIST_CHI_SQUARE);
			SETOWNPROP(objs[1], FLANN_DIST_CS, cvflann::FLANN_DIST_CS);
			SETOWNPROP(objs[1], FLANN_DIST_DNAMMING, cvflann::FLANN_DIST_DNAMMING);
			SETOWNPROP(objs[1], FLANN_DIST_EUCLIDEAN, cvflann::FLANN_DIST_EUCLIDEAN);
			SETOWNPROP(objs[1], FLANN_DIST_HAMMING, cvflann::FLANN_DIST_HAMMING);
			SETOWNPROP(objs[1], FLANN_DIST_HELLINGER, cvflann::FLANN_DIST_HELLINGER);
			SETOWNPROP(objs[1], FLANN_DIST_HIST_INTERSECT, cvflann::FLANN_DIST_HIST_INTERSECT);
			SETOWNPROP(objs[1], FLANN_DIST_KL, cvflann::FLANN_DIST_KL);
			SETOWNPROP(objs[1], FLANN_DIST_KULLBACK_LEIBLER, cvflann::FLANN_DIST_KULLBACK_LEIBLER);
			SETOWNPROP(objs[1], FLANN_DIST_L1, cvflann::FLANN_DIST_L1);
			SETOWNPROP(objs[1], FLANN_DIST_L2, cvflann::FLANN_DIST_L2);
			SETOWNPROP(objs[1], FLANN_DIST_MANHATTAN, cvflann::FLANN_DIST_MANHATTAN);
			SETOWNPROP(objs[1], FLANN_DIST_MAX, cvflann::FLANN_DIST_MAX);
			SETOWNPROP(objs[1], FLANN_DIST_MINKOWSKI, cvflann::FLANN_DIST_MINKOWSKI);
			SETOWNPROP(objs[1], FLANN_FLOAT32, cvflann::FLANN_FLOAT32);
			SETOWNPROP(objs[1], FLANN_FLOAT64, cvflann::FLANN_FLOAT64);
			SETOWNPROP(objs[1], FLANN_INDEX_AUTOTUNED, cvflann::FLANN_INDEX_AUTOTUNED);
			SETOWNPROP(objs[1], FLANN_INDEX_COMPOSITE, cvflann::FLANN_INDEX_COMPOSITE);
			SETOWNPROP(objs[1], FLANN_INDEX_HIERARCHICAL, cvflann::FLANN_INDEX_HIERARCHICAL);
			SETOWNPROP(objs[1], FLANN_INDEX_KDTREE, cvflann::FLANN_INDEX_KDTREE);
			SETOWNPROP(objs[1], FLANN_INDEX_KDTREE_SINGLE, cvflann::FLANN_INDEX_KDTREE_SINGLE);
			SETOWNPROP(objs[1], FLANN_INDEX_KMEANS, cvflann::FLANN_INDEX_KMEANS);
			SETOWNPROP(objs[1], FLANN_INDEX_LINEAR, cvflann::FLANN_INDEX_LINEAR);
			SETOWNPROP(objs[1], FLANN_INDEX_LSH, cvflann::FLANN_INDEX_LSH);
			SETOWNPROP(objs[1], FLANN_INDEX_SAVED, cvflann::FLANN_INDEX_SAVED);
			SETOWNPROP(objs[1], FLANN_INT16, cvflann::FLANN_INT16);
			SETOWNPROP(objs[1], FLANN_INT32, cvflann::FLANN_INT32);
			SETOWNPROP(objs[1], FLANN_INT64, cvflann::FLANN_INT64);
			SETOWNPROP(objs[1], FLANN_INT8, cvflann::FLANN_INT8);
			SETOWNPROP(objs[1], FLANN_LOG_ERROR, cvflann::FLANN_LOG_ERROR);
			SETOWNPROP(objs[1], FLANN_LOG_FATAL, cvflann::FLANN_LOG_FATAL);
			SETOWNPROP(objs[1], FLANN_LOG_INFO, cvflann::FLANN_LOG_INFO);
			SETOWNPROP(objs[1], FLANN_LOG_NONE, cvflann::FLANN_LOG_NONE);
			SETOWNPROP(objs[1], FLANN_LOG_WARN, cvflann::FLANN_LOG_WARN);
			SETOWNPROP(objs[1], FLANN_UINT16, cvflann::FLANN_UINT16);
			SETOWNPROP(objs[1], FLANN_UINT32, cvflann::FLANN_UINT32);
			SETOWNPROP(objs[1], FLANN_UINT64, cvflann::FLANN_UINT64);
			SETOWNPROP(objs[1], FLANN_UINT8, cvflann::FLANN_UINT8);
			SETOWNPROP(objs[1], HELLINGER, cvflann::HELLINGER);
			SETOWNPROP(objs[1], HIST_INTERSECT, cvflann::HIST_INTERSECT);
			SETOWNPROP(objs[1], KDTREE, cvflann::KDTREE);
			SETOWNPROP(objs[1], KDTREE_SINGLE, cvflann::KDTREE_SINGLE);
			SETOWNPROP(objs[1], KL, cvflann::KL);
			SETOWNPROP(objs[1], KMEANS, cvflann::KMEANS);
			SETOWNPROP(objs[1], KULLBACK_LEIBLER, cvflann::KULLBACK_LEIBLER);
			SETOWNPROP(objs[1], LINEAR, cvflann::LINEAR);
			SETOWNPROP(objs[1], MANHATTAN, cvflann::MANHATTAN);
			SETOWNPROP(objs[1], MAX_DIST, cvflann::MAX_DIST);
			SETOWNPROP(objs[1], MINKOWSKI, cvflann::MINKOWSKI);
			SETOWNPROP(objs[1], SAVED, cvflann::SAVED);

	#undef SETOWNPROP
	#undef SETOWNPROP1
	#undef SETOWNPROP2
		}
		return _cv;
	}
	return nullptr;
}
