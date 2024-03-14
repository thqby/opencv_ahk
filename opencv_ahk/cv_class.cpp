#include "pch.h"
#include "cv_ahk.h"
#include "cv_class.h"
#include "util.h"
#include "cv_mat.h"



void CirclesGridFinderParameters::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: return;
	case M___New: new (&mC) cv::CirclesGridFinderParameters; return;
	case P_densityNeighborhoodSize: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.densityNeighborhoodSize))
				_o_return_result;
			return;
		}
		else {
			return ValToResult(mC.densityNeighborhoodSize, aResultToken);
		}
	}
	case P_minDensity: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.minDensity))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue((double)mC.minDensity);
		}
	}
	case P_kmeansAttempts: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.kmeansAttempts))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue((__int64)mC.kmeansAttempts);
		}
	}
	case P_minDistanceToAddKeypoint: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.minDistanceToAddKeypoint))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue((__int64)mC.minDistanceToAddKeypoint);
		}
	}
	case P_keypointScale: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.keypointScale))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue((__int64)mC.keypointScale);
		}
	}
	case P_minGraphConfidence: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.minGraphConfidence))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue((double)mC.minGraphConfidence);
		}
	}
	case P_vertexGain: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.vertexGain))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue((double)mC.vertexGain);
		}
	}
	case P_vertexPenalty: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.vertexPenalty))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue((double)mC.vertexPenalty);
		}
	}
	case P_existingVertexGain: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.existingVertexGain))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue((double)mC.existingVertexGain);
		}
	}
	case P_edgeGain: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.edgeGain))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue((double)mC.edgeGain);
		}
	}
	case P_edgePenalty: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.edgePenalty))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue((double)mC.edgePenalty);
		}
	}
	case P_convexHullFactor: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.convexHullFactor))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue((double)mC.convexHullFactor);
		}
	}
	case P_minRNGEdgeSwitchDist: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.minRNGEdgeSwitchDist))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue((double)mC.minRNGEdgeSwitchDist);
		}
	}
	case P_squareSize: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.squareSize))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue((double)mC.squareSize);
		}
	}
	case P_maxRectifiedDistance: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.maxRectifiedDistance))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue((double)mC.maxRectifiedDistance);
		}
	}
	}
}

#ifdef HAS_GAPI
void GArrayDesc::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: new (&mC) cv::GArrayDesc; return;
	}
}

void GMatDesc::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::GMatDesc;
		if (aParamCount == 0 || aParam[0] == g_invalid) return;
		if (3 <= aParamCount && aParamCount <= 4) {
			bool p = false;
			cv::Size s;
			int d, c;
			if (ParamIndexToVal(0, d))
				_o_return_result;
			if (ParamIndexToVal(1, c))
				_o_return_result;
			if (ParamIndexToVal(2, s))
				_o_return_result;
			if (aParamCount > 3 && aParam[3]->symbol != SYM_MISSING)
				TokenToVal(*aParam[3], (char&)p);
			new (&mC) cv::GMatDesc(d, c, s, p);
			return;
		}
		else if (aParamCount == 2) {
			int d;
			std::vector<int> dd;
			if (ParamIndexToVal(0, d))
				_o_return_result;
			if (ParamIndexToVal(1, dd))
				_o_return_result;
			new (&mC) cv::GMatDesc(d, dd);
			return;
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case M_asInterleaved: {
		auto __retval = (GMatDesc*)GMatDesc::sPrototype->New(g_invalidparam, 1);
		__retval->mC = mC.asInterleaved();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_asPlanar: {
		if (aParamCount == 0) {
			auto __retval = (GMatDesc*)GMatDesc::sPrototype->New(g_invalidparam, 1);
			__retval->mC = mC.asPlanar();
			return (void)(aResultToken.SetValue(__retval));
		}
		else if (aParamCount == 1) {
			int planes;
			if (ParamIndexToVal(0, planes))
				_o_return_result;
			auto __retval = (GMatDesc*)GMatDesc::sPrototype->New(g_invalidparam, 1);
			__retval->mC = mC.asPlanar(planes);
			return (void)(aResultToken.SetValue(__retval));
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case M_withDepth: {
		int ddepth;
		if (ParamIndexToVal(0, ddepth))
			_o_return_result;
		auto __retval = (GMatDesc*)GMatDesc::sPrototype->New(g_invalidparam, 1);
		__retval->mC = mC.withDepth(ddepth);
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_withSize: {
		cv::Size sz;
		if (ParamIndexToVal(0, sz))
			_o_return_result;
		auto __retval = (GMatDesc*)GMatDesc::sPrototype->New(g_invalidparam, 1);
		__retval->mC = mC.withSize(sz);
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_withSizeDelta: {
		if (aParamCount == 1) {
			cv::Size delta;
			if (ParamIndexToVal(0, delta))
				_o_return_result;
			auto __retval = (GMatDesc*)GMatDesc::sPrototype->New(g_invalidparam, 1);
			__retval->mC = mC.withSizeDelta(delta);
			return (void)(aResultToken.SetValue(__retval));
		}
		else if (aParamCount == 2) {
			int dx, dy;
			if (ParamIndexToVal(0, dx))
				_o_return_result;
			if (ParamIndexToVal(1, dy))
				_o_return_result;
			auto __retval = (GMatDesc*)GMatDesc::sPrototype->New(g_invalidparam, 1);
			__retval->mC = mC.withSizeDelta(dx, dy);
			return (void)(aResultToken.SetValue(__retval));
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case M_withType: {
		int ddepth, dchan;
		if (ParamIndexToVal(0, ddepth))
			_o_return_result;
		if (ParamIndexToVal(1, dchan))
			_o_return_result;
		auto __retval = (GMatDesc*)GMatDesc::sPrototype->New(g_invalidparam, 1);
		__retval->mC = mC.withType(ddepth, dchan);
		return (void)(aResultToken.SetValue(__retval));
	}
	case P_depth: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.depth))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue((__int64)mC.depth);
		}
	}
	case P_chan: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.chan))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue((__int64)mC.chan);
		}
	}
	case P_size: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.size))
				_o_return_result;
			return;
		}
		else {
			return ValToResult(mC.size, aResultToken);
		}
	}
	case P_planar: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, (char&)mC.planar))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue((__int64)mC.planar);
		}
	}
	case P_dims: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.dims))
				_o_return_result;
			return;
		}
		else {
			return ValToResult(mC.dims, aResultToken);
		}
	}
	}
}

void GOpaqueDesc::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: new (&mC) cv::GOpaqueDesc; return;
	}
}

void GScalarDesc::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: new (&mC) cv::GScalarDesc; return;
	}
}
#endif

void HOGDescriptor::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC.~HOGDescriptor(); return;
	case M___New: {
		new (&mC) cv::HOGDescriptor;
		if (aParamCount == 0 || aParam[0] == g_invalid) return;
		if (5 <= aParamCount && aParamCount <= 12) {
			bool _gammaCorrection = false, _signedGradient = false;
			cv::Size _winSize, _blockSize, _blockStride, _cellSize;
			double _winSigma = -1, _L2HysThreshold = 0.2;
			int _nbins, _derivAperture = 1, _histogramNormType = cv::HOGDescriptor::L2Hys, _nlevels = cv::HOGDescriptor::DEFAULT_NLEVELS;
			if (ParamIndexToVal(0, _winSize))
				_o_return_result;
			if (ParamIndexToVal(1, _blockSize))
				_o_return_result;
			if (ParamIndexToVal(2, _blockStride))
				_o_return_result;
			if (ParamIndexToVal(3, _cellSize))
				_o_return_result;
			if (ParamIndexToVal(4, _nbins))
				_o_return_result;
			if (aParamCount > 5 && aParam[5]->symbol != SYM_MISSING)
				TokenToVal(*aParam[5], _derivAperture);
			if (aParamCount > 6 && aParam[6]->symbol != SYM_MISSING)
				TokenToVal(*aParam[6], _winSigma);
			if (aParamCount > 7 && aParam[7]->symbol != SYM_MISSING)
				TokenToVal(*aParam[7], _histogramNormType);
			if (aParamCount > 8 && aParam[8]->symbol != SYM_MISSING)
				TokenToVal(*aParam[8], _L2HysThreshold);
			if (aParamCount > 9 && aParam[9]->symbol != SYM_MISSING)
				TokenToVal(*aParam[9], (char&)_gammaCorrection);
			if (aParamCount > 10 && aParam[10]->symbol != SYM_MISSING)
				TokenToVal(*aParam[10], _nlevels);
			if (aParamCount > 11 && aParam[11]->symbol != SYM_MISSING)
				TokenToVal(*aParam[11], (char&)_signedGradient);
			new (&mC) cv::HOGDescriptor(_winSize, _blockSize, _blockStride, _cellSize, _nbins, _derivAperture, _winSigma, (cv::HOGDescriptor::HistogramNormType)_histogramNormType, _L2HysThreshold, _gammaCorrection, _nlevels, _signedGradient);
			return;
		}
		else if (aParamCount == 1) {
			cv::String filename;
			if (ParamIndexToVal(0, filename))
				_o_return_result;
			new (&mC) cv::HOGDescriptor(filename);
			return;
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case M_checkDetectorSize: {
		auto __retval = (__int64)mC.checkDetectorSize();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_compute: {
		cv::_InputArray img;
		cv::Size winStride = cv::Size(), padding = cv::Size();
		std::vector<cv::Point> locations = std::vector<cv::Point>();
		std::vector<float> descriptors;
		if (ParamIndexToVal(0, img))
			_o_return_result;
		VarRef* var_descriptors = nullptr;
		if (ParamIndexToVal(1, var_descriptors))
			_o_return_result;
		if (aParamCount > 2 && aParam[2]->symbol != SYM_MISSING)
			TokenToVal(*aParam[2], winStride);
		if (aParamCount > 3 && aParam[3]->symbol != SYM_MISSING)
			TokenToVal(*aParam[3], padding);
		if (aParamCount > 4 && aParam[4]->symbol != SYM_MISSING)
			TokenToVal(*aParam[4], locations);
		mC.compute(img, descriptors, winStride, padding, locations);
		ValToResult(descriptors, aResultToken);
		g_ahkapi->VarAssign(var_descriptors, aResultToken);
		g_ahkapi->ResultTokenFree(aResultToken);
		return;
	}
	case M_computeGradient: {
		cv::_InputArray img;
		cv::_InputOutputArray grad, angleOfs;
		cv::Size paddingTL = cv::Size(), paddingBR = cv::Size();
		if (ParamIndexToVal(0, img))
			_o_return_result;
		if (ParamIndexToVal(1, grad))
			_o_return_result;
		if (ParamIndexToVal(2, angleOfs))
			_o_return_result;
		if (aParamCount > 3 && aParam[3]->symbol != SYM_MISSING)
			TokenToVal(*aParam[3], paddingTL);
		if (aParamCount > 4 && aParam[4]->symbol != SYM_MISSING)
			TokenToVal(*aParam[4], paddingBR);
		mC.computeGradient(img, grad, angleOfs, paddingTL, paddingBR);
		return;
	}
	case M_detect: {
		cv::_InputArray img;
		cv::Size winStride = cv::Size(), padding = cv::Size();
		double hitThreshold = 0;
		std::vector<cv::Point> foundLocations, searchLocations = std::vector<cv::Point>();
		std::vector<double> weights;
		if (ParamIndexToVal(0, img))
			_o_return_result;
		VarRef* var_foundLocations = nullptr;
		if (ParamIndexToVal(1, var_foundLocations))
			_o_return_result;
		VarRef* var_weights = nullptr;
		if (ParamIndexToVal(2, var_weights))
			_o_return_result;
		if (aParamCount > 3 && aParam[3]->symbol != SYM_MISSING)
			TokenToVal(*aParam[3], hitThreshold);
		if (aParamCount > 4 && aParam[4]->symbol != SYM_MISSING)
			TokenToVal(*aParam[4], winStride);
		if (aParamCount > 5 && aParam[5]->symbol != SYM_MISSING)
			TokenToVal(*aParam[5], padding);
		if (aParamCount > 6 && aParam[6]->symbol != SYM_MISSING)
			TokenToVal(*aParam[6], searchLocations);
		mC.detect(img, foundLocations, weights, hitThreshold, winStride, padding, searchLocations);
		ValToResult(foundLocations, aResultToken);
		g_ahkapi->VarAssign(var_foundLocations, aResultToken);
		g_ahkapi->ResultTokenFree(aResultToken);
		ValToResult(weights, aResultToken);
		g_ahkapi->VarAssign(var_weights, aResultToken);
		g_ahkapi->ResultTokenFree(aResultToken);
		return;
	}
	case M_detectMultiScale: {
		bool useMeanshiftGrouping = false;
		cv::_InputArray img;
		cv::Size winStride = cv::Size(), padding = cv::Size();
		double hitThreshold = 0, scale = 1.05, finalThreshold = 2.0;
		std::vector<cv::Rect> foundLocations;
		std::vector<double> foundWeights;
		if (ParamIndexToVal(0, img))
			_o_return_result;
		VarRef* var_foundLocations = nullptr;
		if (ParamIndexToVal(1, var_foundLocations))
			_o_return_result;
		VarRef* var_foundWeights = nullptr;
		if (ParamIndexToVal(2, var_foundWeights))
			_o_return_result;
		if (aParamCount > 3 && aParam[3]->symbol != SYM_MISSING)
			TokenToVal(*aParam[3], hitThreshold);
		if (aParamCount > 4 && aParam[4]->symbol != SYM_MISSING)
			TokenToVal(*aParam[4], winStride);
		if (aParamCount > 5 && aParam[5]->symbol != SYM_MISSING)
			TokenToVal(*aParam[5], padding);
		if (aParamCount > 6 && aParam[6]->symbol != SYM_MISSING)
			TokenToVal(*aParam[6], scale);
		if (aParamCount > 7 && aParam[7]->symbol != SYM_MISSING)
			TokenToVal(*aParam[7], finalThreshold);
		if (aParamCount > 8 && aParam[8]->symbol != SYM_MISSING)
			TokenToVal(*aParam[8], (char&)useMeanshiftGrouping);
		mC.detectMultiScale(img, foundLocations, foundWeights, hitThreshold, winStride, padding, scale, finalThreshold, useMeanshiftGrouping);
		ValToResult(foundLocations, aResultToken);
		g_ahkapi->VarAssign(var_foundLocations, aResultToken);
		g_ahkapi->ResultTokenFree(aResultToken);
		ValToResult(foundWeights, aResultToken);
		g_ahkapi->VarAssign(var_foundWeights, aResultToken);
		g_ahkapi->ResultTokenFree(aResultToken);
		return;
	}
	case M_getDaimlerPeopleDetector: {
		auto __retval = mC.getDaimlerPeopleDetector();
		return ValToResult(__retval, aResultToken);
	}
	case M_getDefaultPeopleDetector: {
		auto __retval = mC.getDefaultPeopleDetector();
		return ValToResult(__retval, aResultToken);
	}
	case M_getDescriptorSize: {
		auto __retval = (__int64)mC.getDescriptorSize();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getWinSigma: {
		auto __retval = mC.getWinSigma();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_load: {
		cv::String filename, objname = cv::String();
		if (ParamIndexToVal(0, filename))
			_o_return_result;
		if (aParamCount > 1 && aParam[1]->symbol != SYM_MISSING)
			TokenToVal(*aParam[1], objname);
		auto __retval = (__int64)mC.load(filename, objname);
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_save: {
		cv::String filename, objname = cv::String();
		if (ParamIndexToVal(0, filename))
			_o_return_result;
		if (aParamCount > 1 && aParam[1]->symbol != SYM_MISSING)
			TokenToVal(*aParam[1], objname);
		mC.save(filename, objname);
		return;
	}
	case M_setSVMDetector: {
		cv::_InputArray svmdetector;
		if (ParamIndexToVal(0, svmdetector))
			_o_return_result;
		mC.setSVMDetector(svmdetector);
		return;
	}
	case P_winSize: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.winSize))
				_o_return_result;
			return;
		}
		else {
			return ValToResult(mC.winSize, aResultToken);
		}
	}
	case P_blockSize: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.blockSize))
				_o_return_result;
			return;
		}
		else {
			return ValToResult(mC.blockSize, aResultToken);
		}
	}
	case P_blockStride: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.blockStride))
				_o_return_result;
			return;
		}
		else {
			return ValToResult(mC.blockStride, aResultToken);
		}
	}
	case P_cellSize: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.cellSize))
				_o_return_result;
			return;
		}
		else {
			return ValToResult(mC.cellSize, aResultToken);
		}
	}
	case P_nbins: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.nbins))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue((__int64)mC.nbins);
		}
	}
	case P_derivAperture: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.derivAperture))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue((__int64)mC.derivAperture);
		}
	}
	case P_winSigma: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.winSigma))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue((double)mC.winSigma);
		}
	}
	case P_histogramNormType: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, (int&)mC.histogramNormType))
				_o_return_result;
			return;
		}
		else {
			return ValToResult(mC.histogramNormType, aResultToken);
		}
	}
	case P_L2HysThreshold: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.L2HysThreshold))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue((double)mC.L2HysThreshold);
		}
	}
	case P_gammaCorrection: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, (char&)mC.gammaCorrection))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue((__int64)mC.gammaCorrection);
		}
	}
	case P_svmDetector: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.svmDetector))
				_o_return_result;
			return;
		}
		else {
			return ValToResult(mC.svmDetector, aResultToken);
		}
	}
	case P_nlevels: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.nlevels))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue((__int64)mC.nlevels);
		}
	}
	case P_signedGradient: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, (char&)mC.signedGradient))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue((__int64)mC.signedGradient);
		}
	}
	}
}

void QRCodeEncoder_Params::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: return;
	case M___New: new (&mC) cv::QRCodeEncoder::Params; return;
	case P_version: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.version))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue((__int64)mC.version);
		}
	}
	case P_correction_level: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, (int&)mC.correction_level))
				_o_return_result;
			return;
		}
		else {
			return ValToResult(mC.correction_level, aResultToken);
		}
	}
	case P_mode: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, (int&)mC.mode))
				_o_return_result;
			return;
		}
		else {
			return ValToResult(mC.mode, aResultToken);
		}
	}
	case P_structure_number: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.structure_number))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue((__int64)mC.structure_number);
		}
	}
	}
}

void SimpleBlobDetector_Params::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: return;
	case M___New: new (&mC) cv::SimpleBlobDetector::Params; return;
	case P_thresholdStep: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.thresholdStep))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue((double)mC.thresholdStep);
		}
	}
	case P_minThreshold: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.minThreshold))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue((double)mC.minThreshold);
		}
	}
	case P_maxThreshold: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.maxThreshold))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue((double)mC.maxThreshold);
		}
	}
	case P_minRepeatability: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, (intptr_t&)mC.minRepeatability))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue((__int64)mC.minRepeatability);
		}
	}
	case P_minDistBetweenBlobs: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.minDistBetweenBlobs))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue((double)mC.minDistBetweenBlobs);
		}
	}
	case P_filterByColor: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, (char&)mC.filterByColor))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue((__int64)mC.filterByColor);
		}
	}
	case P_blobColor: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, (char&)mC.blobColor))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue((__int64)mC.blobColor);
		}
	}
	case P_filterByArea: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, (char&)mC.filterByArea))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue((__int64)mC.filterByArea);
		}
	}
	case P_minArea: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.minArea))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue((double)mC.minArea);
		}
	}
	case P_maxArea: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.maxArea))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue((double)mC.maxArea);
		}
	}
	case P_filterByCircularity: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, (char&)mC.filterByCircularity))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue((__int64)mC.filterByCircularity);
		}
	}
	case P_minCircularity: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.minCircularity))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue((double)mC.minCircularity);
		}
	}
	case P_maxCircularity: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.maxCircularity))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue((double)mC.maxCircularity);
		}
	}
	case P_filterByInertia: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, (char&)mC.filterByInertia))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue((__int64)mC.filterByInertia);
		}
	}
	case P_minInertiaRatio: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.minInertiaRatio))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue((double)mC.minInertiaRatio);
		}
	}
	case P_maxInertiaRatio: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.maxInertiaRatio))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue((double)mC.maxInertiaRatio);
		}
	}
	case P_filterByConvexity: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, (char&)mC.filterByConvexity))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue((__int64)mC.filterByConvexity);
		}
	}
	case P_minConvexity: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.minConvexity))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue((double)mC.minConvexity);
		}
	}
	case P_maxConvexity: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.maxConvexity))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue((double)mC.maxConvexity);
		}
	}
	}
}

void TrackerDaSiamRPN_Params::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: return;
	case M___New: new (&mC) cv::TrackerDaSiamRPN::Params; return;
	case P_model: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.model))
				_o_return_result;
			return;
		}
		else {
			return ValToResult(mC.model, aResultToken);
		}
	}
	case P_kernel_cls1: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.kernel_cls1))
				_o_return_result;
			return;
		}
		else {
			return ValToResult(mC.kernel_cls1, aResultToken);
		}
	}
	case P_kernel_r1: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.kernel_r1))
				_o_return_result;
			return;
		}
		else {
			return ValToResult(mC.kernel_r1, aResultToken);
		}
	}
	case P_backend: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.backend))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue((__int64)mC.backend);
		}
	}
	case P_target: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.target))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue((__int64)mC.target);
		}
	}
	}
}

void TrackerGOTURN_Params::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC.modelBin; return;
	case M___New: new (&mC) cv::TrackerGOTURN::Params; return;
	case P_modelTxt: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.modelTxt))
				_o_return_result;
			return;
		}
		else {
			return ValToResult(mC.modelTxt, aResultToken);
		}
	}
	case P_modelBin: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.modelBin))
				_o_return_result;
			return;
		}
		else {
			return ValToResult(mC.modelBin, aResultToken);
		}
	}
	}
}

void TrackerMIL_Params::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: new (&mC) cv::TrackerMIL::Params; return;
	case P_samplerInitInRadius: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.samplerInitInRadius))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue((double)mC.samplerInitInRadius);
		}
	}
	case P_samplerInitMaxNegNum: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.samplerInitMaxNegNum))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue((__int64)mC.samplerInitMaxNegNum);
		}
	}
	case P_samplerSearchWinSize: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.samplerSearchWinSize))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue((double)mC.samplerSearchWinSize);
		}
	}
	case P_samplerTrackInRadius: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.samplerTrackInRadius))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue((double)mC.samplerTrackInRadius);
		}
	}
	case P_samplerTrackMaxPosNum: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.samplerTrackMaxPosNum))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue((__int64)mC.samplerTrackMaxPosNum);
		}
	}
	case P_samplerTrackMaxNegNum: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.samplerTrackMaxNegNum))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue((__int64)mC.samplerTrackMaxNegNum);
		}
	}
	case P_featureSetNumFeatures: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.featureSetNumFeatures))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue((__int64)mC.featureSetNumFeatures);
		}
	}
	}
}

void UsacParams::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: new (&mC) cv::UsacParams; return;
	case P_confidence: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.confidence))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue((double)mC.confidence);
		}
	}
	case P_isParallel: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, (char&)mC.isParallel))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue((__int64)mC.isParallel);
		}
	}
	case P_loIterations: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.loIterations))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue((__int64)mC.loIterations);
		}
	}
	case P_loMethod: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, (int&)mC.loMethod))
				_o_return_result;
			return;
		}
		else {
			return ValToResult(mC.loMethod, aResultToken);
		}
	}
	case P_loSampleSize: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.loSampleSize))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue((__int64)mC.loSampleSize);
		}
	}
	case P_maxIterations: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.maxIterations))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue((__int64)mC.maxIterations);
		}
	}
	case P_neighborsSearch: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, (int&)mC.neighborsSearch))
				_o_return_result;
			return;
		}
		else {
			return ValToResult(mC.neighborsSearch, aResultToken);
		}
	}
	case P_randomGeneratorState: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.randomGeneratorState))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue((__int64)mC.randomGeneratorState);
		}
	}
	case P_sampler: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, (int&)mC.sampler))
				_o_return_result;
			return;
		}
		else {
			return ValToResult(mC.sampler, aResultToken);
		}
	}
	case P_score: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, (int&)mC.score))
				_o_return_result;
			return;
		}
		else {
			return ValToResult(mC.score, aResultToken);
		}
	}
	case P_threshold: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.threshold))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue((double)mC.threshold);
		}
	}
	}
}

void detail_CameraParams::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: new (&mC) cv::detail::CameraParams; return;
	case M_K: {
		auto __retval = (Mat*)Mat::sPrototype->New(g_invalidparam, 1);
		__retval->mC = mC.K();
		return (void)(aResultToken.SetValue(__retval));
	}
	case P_focal: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.focal))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue((double)mC.focal);
		}
	}
	case P_aspect: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.aspect))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue((double)mC.aspect);
		}
	}
	case P_ppx: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.ppx))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue((double)mC.ppx);
		}
	}
	case P_ppy: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.ppy))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue((double)mC.ppy);
		}
	}
	case P_R: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.R))
				_o_return_result;
			return;
		}
		else {
			auto __retval = (Mat*)Mat::sPrototype->New(g_invalidparam, 1);
			__retval->mC = mC.R; return (void)aResultToken.SetValue(__retval);
		}
	}
	case P_t: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.t))
				_o_return_result;
			return;
		}
		else {
			auto __retval = (Mat*)Mat::sPrototype->New(g_invalidparam, 1);
			__retval->mC = mC.t; return (void)aResultToken.SetValue(__retval);
		}
	}
	}
}

void detail_ImageFeatures::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: new (&mC) cv::detail::ImageFeatures; return;
	case M_getKeypoints: {
		auto __retval = mC.getKeypoints();
		return ValToResult(__retval, aResultToken);
	}
	case P_img_idx: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.img_idx))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue((__int64)mC.img_idx);
		}
	}
	case P_img_size: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.img_size))
				_o_return_result;
			return;
		}
		else {
			return ValToResult(mC.img_size, aResultToken);
		}
	}
	case P_keypoints: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.keypoints))
				_o_return_result;
			return;
		}
		else {
			return ValToResult(mC.keypoints, aResultToken);
		}
	}
	case P_descriptors: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.descriptors))
				_o_return_result;
			return;
		}
		else {
			auto __retval = (UMat*)UMat::sPrototype->New(g_invalidparam, 1);
			__retval->mC = mC.descriptors; return (void)aResultToken.SetValue(__retval);
		}
	}
	}
}

void detail_MatchesInfo::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: new (&mC) cv::detail::MatchesInfo; return;
	case M_getInliers: {
		auto __retval = mC.getInliers();
		return ValToResult(__retval, aResultToken);
	}
	case M_getMatches: {
		auto __retval = mC.getMatches();
		return ValToResult(__retval, aResultToken);
	}
	case P_src_img_idx: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.src_img_idx))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue((__int64)mC.src_img_idx);
		}
	}
	case P_dst_img_idx: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.dst_img_idx))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue((__int64)mC.dst_img_idx);
		}
	}
	case P_num_inliers: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.num_inliers))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue((__int64)mC.num_inliers);
		}
	}
	case P_H: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.H))
				_o_return_result;
			return;
		}
		else {
			auto __retval = (Mat*)Mat::sPrototype->New(g_invalidparam, 1);
			__retval->mC = mC.H; return (void)aResultToken.SetValue(__retval);
		}
	}
	case P_confidence: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.confidence))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue((double)mC.confidence);
		}
	}
	}
}

void detail_ProjectorBase::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: new (&mC) cv::detail::ProjectorBase; return;
	case M_setCameraParams: {
		cv::_InputArray K, R, T;
		if (ParamIndexToVal(0, K))
			_o_return_result;
		if (ParamIndexToVal(1, R))
			_o_return_result;
		if (ParamIndexToVal(2, T))
			_o_return_result;
		mC.setCameraParams(K, R, T);
		return;
	}
	case P_scale: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.scale))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue((double)mC.scale);
		}
	}
	case P_k:
	case P_rinv:
	case P_r_kinv:
	case P_k_rinv: {
		auto p = aID == P_k ? mC.k : aID == P_rinv ? mC.rinv : aID == P_r_kinv ? mC.r_kinv : mC.k_rinv;
		if (aFlags & IT_SET) {
			Array* arr = dynamic_cast<Array*>(TokenToObject(*aParam[0]));
			if (!arr)
				return (void)(aResultToken.result = g_ahkapi->TypeError(_T("Array"), *aParam[0]));
			ArrayToCArr(arr, p, 9);
			return;
		}
		else {
			return (void)aResultToken.SetValue(BinToArray((char*)p, "fffffffff"));
		}
	}
	case P_t: {
		if (aFlags & IT_SET) {
			Array* arr = dynamic_cast<Array*>(TokenToObject(*aParam[0]));
			if (!arr)
				return (void)(aResultToken.result = g_ahkapi->TypeError(_T("Array"), *aParam[0]));
			ArrayToCArr(arr, mC.t, 3);
			return;
		}
		else {
			return (void)aResultToken.SetValue(BinToArray((char*)mC.t, "fff"));
		}
	}
	}
}

void detail_SphericalProjector::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: new (&mC) cv::detail::SphericalProjector; return;
	case M_mapBackward: {
		float u, v, x, y;
		if (ParamIndexToVal(0, u))
			_o_return_result;
		if (ParamIndexToVal(1, v))
			_o_return_result;
		if (ParamIndexToVal(2, x))
			_o_return_result;
		if (ParamIndexToVal(3, y))
			_o_return_result;
		mC.mapBackward(u, v, x, y);
		return;
	}
	case M_mapForward: {
		float x, y, u, v;
		if (ParamIndexToVal(0, x))
			_o_return_result;
		if (ParamIndexToVal(1, y))
			_o_return_result;
		if (ParamIndexToVal(2, u))
			_o_return_result;
		if (ParamIndexToVal(3, v))
			_o_return_result;
		mC.mapForward(x, y, u, v);
		return;
	}
	}
}

void dnn_DictValue::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC.~DictValue(); return;
	case M___New: {
		new (&mC) cv::dnn::DictValue;
		if (aParamCount == 0 || aParam[0] == g_invalid) return;
		if (!MatchTypes("i")) {
			int i;
			if (ParamIndexToVal(0, i))
				_o_return_result;
			new (&mC) cv::dnn::DictValue(i);
			return;
		}
		else if (!MatchTypes("f")) {
			double p;
			if (ParamIndexToVal(0, p))
				_o_return_result;
			new (&mC) cv::dnn::DictValue(p);
			return;
		}
		else if (!MatchTypes("s")) {
			cv::String s;
			if (ParamIndexToVal(0, s))
				_o_return_result;
			new (&mC) cv::dnn::DictValue(s);
			return;
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case M_getIntValue: {
		int idx = -1;
		if (aParamCount > 0 && aParam[0]->symbol != SYM_MISSING)
			TokenToVal(*aParam[0], idx);
		auto __retval = (__int64)mC.getIntValue(idx);
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getRealValue: {
		int idx = -1;
		if (aParamCount > 0 && aParam[0]->symbol != SYM_MISSING)
			TokenToVal(*aParam[0], idx);
		auto __retval = mC.getRealValue(idx);
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getStringValue: {
		int idx = -1;
		if (aParamCount > 0 && aParam[0]->symbol != SYM_MISSING)
			TokenToVal(*aParam[0], idx);
		auto __retval = mC.getStringValue(idx);
		return ValToResult(__retval, aResultToken);
	}
	case M_isInt: {
		auto __retval = (__int64)mC.isInt();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_isReal: {
		auto __retval = (__int64)mC.isReal();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_isString: {
		auto __retval = (__int64)mC.isString();
		return (void)(aResultToken.SetValue(__retval));
	}
	}
}

#ifdef HAS_GAPI
void gapi_GNetPackage::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::gapi::GNetPackage;
		if (aParamCount == 0 || aParam[0] == g_invalid) return;
		std::vector<cv::gapi::GNetParam> nets;
		if (ParamIndexToVal(0, nets))
			_o_return_result;
		new (&mC) cv::gapi::GNetPackage(nets);
		return;
	}
	}
}

void gapi_GNetParam::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: new (&mC) cv::gapi::GNetParam; return;
	}
}

void gapi_streaming_queue_capacity::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::gapi::streaming::queue_capacity;
		if (aParamCount == 0 || aParam[0] == g_invalid) return;
		size_t cap = 1;
		if (aParamCount > 0 && aParam[0]->symbol != SYM_MISSING)
			TokenToVal(*aParam[0], (intptr_t&)cap);
		new (&mC) cv::gapi::streaming::queue_capacity(cap);
		return;
	}
	case P_capacity: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, (intptr_t&)mC.capacity))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue((__int64)mC.capacity);
		}
	}
	}
}

void gapi_wip_draw_Circle::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::gapi::wip::draw::Circle;
		if (aParamCount == 0 || aParam[0] == g_invalid) return;
		cv::Point center_;
		cv::Scalar color_;
		int radius_, thick_ = 1, lt_ = 8, shift_ = 0;
		if (ParamIndexToVal(0, center_))
			_o_return_result;
		if (ParamIndexToVal(1, radius_))
			_o_return_result;
		if (ParamIndexToVal(2, color_))
			_o_return_result;
		if (aParamCount > 3 && aParam[3]->symbol != SYM_MISSING)
			TokenToVal(*aParam[3], thick_);
		if (aParamCount > 4 && aParam[4]->symbol != SYM_MISSING)
			TokenToVal(*aParam[4], lt_);
		if (aParamCount > 5 && aParam[5]->symbol != SYM_MISSING)
			TokenToVal(*aParam[5], shift_);
		new (&mC) cv::gapi::wip::draw::Circle(center_, radius_, color_, thick_, lt_, shift_);
		return;
	}
	case P_center: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.center))
				_o_return_result;
			return;
		}
		else {
			return ValToResult(mC.center, aResultToken);
		}
	}
	case P_radius: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.radius))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue((__int64)mC.radius);
		}
	}
	case P_color: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.color))
				_o_return_result;
			return;
		}
		else {
			return ValToResult(mC.color, aResultToken);
		}
	}
	case P_thick: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.thick))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue((__int64)mC.thick);
		}
	}
	case P_lt: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.lt))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue((__int64)mC.lt);
		}
	}
	case P_shift: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.shift))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue((__int64)mC.shift);
		}
	}
	}
}

void gapi_wip_draw_Image::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::gapi::wip::draw::Image;
		if (aParamCount == 0 || aParam[0] == g_invalid) return;
		cv::Mat img_, alpha_;
		cv::Point org_;
		if (ParamIndexToVal(0, org_))
			_o_return_result;
		if (ParamIndexToVal(1, img_))
			_o_return_result;
		if (ParamIndexToVal(2, alpha_))
			_o_return_result;
		new (&mC) cv::gapi::wip::draw::Image(org_, img_, alpha_);
		return;
	}
	case P_org: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.org))
				_o_return_result;
			return;
		}
		else {
			return ValToResult(mC.org, aResultToken);
		}
	}
	case P_img: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.img))
				_o_return_result;
			return;
		}
		else {
			auto __retval = (Mat*)Mat::sPrototype->New(g_invalidparam, 1);
			__retval->mC = mC.img; return (void)aResultToken.SetValue(__retval);
		}
	}
	case P_alpha: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.alpha))
				_o_return_result;
			return;
		}
		else {
			auto __retval = (Mat*)Mat::sPrototype->New(g_invalidparam, 1);
			__retval->mC = mC.alpha; return (void)aResultToken.SetValue(__retval);
		}
	}
	}
}

void gapi_wip_draw_Line::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::gapi::wip::draw::Line;
		if (aParamCount == 0 || aParam[0] == g_invalid) return;
		cv::Point pt1_, pt2_;
		cv::Scalar color_;
		int thick_ = 1, lt_ = 8, shift_ = 0;
		if (ParamIndexToVal(0, pt1_))
			_o_return_result;
		if (ParamIndexToVal(1, pt2_))
			_o_return_result;
		if (ParamIndexToVal(2, color_))
			_o_return_result;
		if (aParamCount > 3 && aParam[3]->symbol != SYM_MISSING)
			TokenToVal(*aParam[3], thick_);
		if (aParamCount > 4 && aParam[4]->symbol != SYM_MISSING)
			TokenToVal(*aParam[4], lt_);
		if (aParamCount > 5 && aParam[5]->symbol != SYM_MISSING)
			TokenToVal(*aParam[5], shift_);
		new (&mC) cv::gapi::wip::draw::Line(pt1_, pt2_, color_, thick_, lt_, shift_);
		return;
	}
	case P_pt1: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.pt1))
				_o_return_result;
			return;
		}
		else {
			return ValToResult(mC.pt1, aResultToken);
		}
	}
	case P_pt2: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.pt2))
				_o_return_result;
			return;
		}
		else {
			return ValToResult(mC.pt2, aResultToken);
		}
	}
	case P_color: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.color))
				_o_return_result;
			return;
		}
		else {
			return ValToResult(mC.color, aResultToken);
		}
	}
	case P_thick: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.thick))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue((__int64)mC.thick);
		}
	}
	case P_lt: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.lt))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue((__int64)mC.lt);
		}
	}
	case P_shift: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.shift))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue((__int64)mC.shift);
		}
	}
	}
}

void gapi_wip_draw_Mosaic::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: new (&mC) cv::gapi::wip::draw::Mosaic; return;
	case P_mos: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.mos))
				_o_return_result;
			return;
		}
		else {
			return ValToResult(mC.mos, aResultToken);
		}
	}
	case P_cellSz: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.cellSz))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue((__int64)mC.cellSz);
		}
	}
	case P_decim: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.decim))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue((__int64)mC.decim);
		}
	}
	}
}

void gapi_wip_draw_Poly::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::gapi::wip::draw::Poly;
		if (aParamCount == 0 || aParam[0] == g_invalid) return;
		cv::Scalar color_;
		int thick_ = 1, lt_ = 8, shift_ = 0;
		std::vector<cv::Point> points_;
		if (ParamIndexToVal(0, points_))
			_o_return_result;
		if (ParamIndexToVal(1, color_))
			_o_return_result;
		if (aParamCount > 2 && aParam[2]->symbol != SYM_MISSING)
			TokenToVal(*aParam[2], thick_);
		if (aParamCount > 3 && aParam[3]->symbol != SYM_MISSING)
			TokenToVal(*aParam[3], lt_);
		if (aParamCount > 4 && aParam[4]->symbol != SYM_MISSING)
			TokenToVal(*aParam[4], shift_);
		new (&mC) cv::gapi::wip::draw::Poly(points_, color_, thick_, lt_, shift_);
		return;
	}
	case P_points: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.points))
				_o_return_result;
			return;
		}
		else {
			return ValToResult(mC.points, aResultToken);
		}
	}
	case P_color: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.color))
				_o_return_result;
			return;
		}
		else {
			return ValToResult(mC.color, aResultToken);
		}
	}
	case P_thick: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.thick))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue((__int64)mC.thick);
		}
	}
	case P_lt: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.lt))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue((__int64)mC.lt);
		}
	}
	case P_shift: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.shift))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue((__int64)mC.shift);
		}
	}
	}
}

void gapi_wip_draw_Rect::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: new (&mC) cv::gapi::wip::draw::Rect; return;
	case P_rect: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.rect))
				_o_return_result;
			return;
		}
		else {
			return ValToResult(mC.rect, aResultToken);
		}
	}
	case P_color: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.color))
				_o_return_result;
			return;
		}
		else {
			return ValToResult(mC.color, aResultToken);
		}
	}
	case P_thick: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.thick))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue((__int64)mC.thick);
		}
	}
	case P_lt: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.lt))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue((__int64)mC.lt);
		}
	}
	case P_shift: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.shift))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue((__int64)mC.shift);
		}
	}
	}
}

void gapi_wip_draw_Text::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::gapi::wip::draw::Text;
		if (aParamCount == 0 || aParam[0] == g_invalid) return;
		bool bottom_left_origin_ = false;
		cv::Point org_;
		cv::Scalar color_;
		cv::String text_;
		double fs_;
		int ff_, thick_ = 1, lt_ = 8;
		if (ParamIndexToVal(0, text_))
			_o_return_result;
		if (ParamIndexToVal(1, org_))
			_o_return_result;
		if (ParamIndexToVal(2, ff_))
			_o_return_result;
		if (ParamIndexToVal(3, fs_))
			_o_return_result;
		if (ParamIndexToVal(4, color_))
			_o_return_result;
		if (aParamCount > 5 && aParam[5]->symbol != SYM_MISSING)
			TokenToVal(*aParam[5], thick_);
		if (aParamCount > 6 && aParam[6]->symbol != SYM_MISSING)
			TokenToVal(*aParam[6], lt_);
		if (aParamCount > 7 && aParam[7]->symbol != SYM_MISSING)
			TokenToVal(*aParam[7], (char&)bottom_left_origin_);
		new (&mC) cv::gapi::wip::draw::Text(text_, org_, ff_, fs_, color_, thick_, lt_, bottom_left_origin_);
		return;
	}
	case P_text: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.text))
				_o_return_result;
			return;
		}
		else {
			return ValToResult(mC.text, aResultToken);
		}
	}
	case P_org: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.org))
				_o_return_result;
			return;
		}
		else {
			return ValToResult(mC.org, aResultToken);
		}
	}
	case P_ff: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.ff))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue((__int64)mC.ff);
		}
	}
	case P_fs: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.fs))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue((double)mC.fs);
		}
	}
	case P_color: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.color))
				_o_return_result;
			return;
		}
		else {
			return ValToResult(mC.color, aResultToken);
		}
	}
	case P_thick: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.thick))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue((__int64)mC.thick);
		}
	}
	case P_lt: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC.lt))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue((__int64)mC.lt);
		}
	}
	case P_bottom_left_origin: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, (char&)mC.bottom_left_origin))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue((__int64)mC.bottom_left_origin);
		}
	}
	}
}
#endif

thread_local IAhkApi::Prototype* CirclesGridFinderParameters::sPrototype = nullptr;
ObjectMember CirclesGridFinderParameters::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Property_get_set(densityNeighborhoodSize),
Object_Property_get_set(minDensity),
Object_Property_get_set(kmeansAttempts),
Object_Property_get_set(minDistanceToAddKeypoint),
Object_Property_get_set(keypointScale),
Object_Property_get_set(minGraphConfidence),
Object_Property_get_set(vertexGain),
Object_Property_get_set(vertexPenalty),
Object_Property_get_set(existingVertexGain),
Object_Property_get_set(edgeGain),
Object_Property_get_set(edgePenalty),
Object_Property_get_set(convexHullFactor),
Object_Property_get_set(minRNGEdgeSwitchDist),
Object_Property_get_set(squareSize),
Object_Property_get_set(maxRectifiedDistance),
};
int CirclesGridFinderParameters::sMemberCount = _countof(sMember);
#ifdef HAS_GAPI
thread_local IAhkApi::Prototype* GArrayDesc::sPrototype = nullptr;
ObjectMember GArrayDesc::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
};
int GArrayDesc::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* GMatDesc::sPrototype = nullptr;
ObjectMember GMatDesc::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(asInterleaved, 0, 0),
Object_Method(asPlanar, 0, 1),
Object_Method(withDepth, 1, 1),
Object_Method(withSize, 1, 1),
Object_Method(withSizeDelta, 1, 2),
Object_Method(withType, 2, 2),
Object_Property_get_set(depth),
Object_Property_get_set(chan),
Object_Property_get_set(size),
Object_Property_get_set(planar),
Object_Property_get_set(dims),
};
int GMatDesc::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* GOpaqueDesc::sPrototype = nullptr;
ObjectMember GOpaqueDesc::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
};
int GOpaqueDesc::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* GScalarDesc::sPrototype = nullptr;
ObjectMember GScalarDesc::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
};
int GScalarDesc::sMemberCount = _countof(sMember);
#endif
thread_local IAhkApi::Prototype* HOGDescriptor::sPrototype = nullptr;
ObjectMember HOGDescriptor::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(checkDetectorSize, 0, 0),
Object_Method(compute, 2, 5),
Object_Method(computeGradient, 3, 5),
Object_Method(detect, 3, 7),
Object_Method(detectMultiScale, 3, 9),
Object_Method(getDaimlerPeopleDetector, 0, 0),
Object_Method(getDefaultPeopleDetector, 0, 0),
Object_Method(getDescriptorSize, 0, 0),
Object_Method(getWinSigma, 0, 0),
Object_Method(load, 1, 2),
Object_Method(save, 1, 2),
Object_Method(setSVMDetector, 1, 1),
Object_Property_get_set(winSize),
Object_Property_get_set(blockSize),
Object_Property_get_set(blockStride),
Object_Property_get_set(cellSize),
Object_Property_get_set(nbins),
Object_Property_get_set(derivAperture),
Object_Property_get_set(winSigma),
Object_Property_get_set(histogramNormType),
Object_Property_get_set(L2HysThreshold),
Object_Property_get_set(gammaCorrection),
Object_Property_get_set(svmDetector),
Object_Property_get_set(nlevels),
Object_Property_get_set(signedGradient),
};
int HOGDescriptor::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* QRCodeEncoder_Params::sPrototype = nullptr;
ObjectMember QRCodeEncoder_Params::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Property_get_set(version),
Object_Property_get_set(correction_level),
Object_Property_get_set(mode),
Object_Property_get_set(structure_number),
};
int QRCodeEncoder_Params::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* SimpleBlobDetector_Params::sPrototype = nullptr;
ObjectMember SimpleBlobDetector_Params::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Property_get_set(thresholdStep),
Object_Property_get_set(minThreshold),
Object_Property_get_set(maxThreshold),
Object_Property_get_set(minRepeatability),
Object_Property_get_set(minDistBetweenBlobs),
Object_Property_get_set(filterByColor),
Object_Property_get_set(blobColor),
Object_Property_get_set(filterByArea),
Object_Property_get_set(minArea),
Object_Property_get_set(maxArea),
Object_Property_get_set(filterByCircularity),
Object_Property_get_set(minCircularity),
Object_Property_get_set(maxCircularity),
Object_Property_get_set(filterByInertia),
Object_Property_get_set(minInertiaRatio),
Object_Property_get_set(maxInertiaRatio),
Object_Property_get_set(filterByConvexity),
Object_Property_get_set(minConvexity),
Object_Property_get_set(maxConvexity),
};
int SimpleBlobDetector_Params::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* TrackerDaSiamRPN_Params::sPrototype = nullptr;
ObjectMember TrackerDaSiamRPN_Params::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Property_get_set(model),
Object_Property_get_set(kernel_cls1),
Object_Property_get_set(kernel_r1),
Object_Property_get_set(backend),
Object_Property_get_set(target),
};
int TrackerDaSiamRPN_Params::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* TrackerGOTURN_Params::sPrototype = nullptr;
ObjectMember TrackerGOTURN_Params::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Property_get_set(modelTxt),
Object_Property_get_set(modelBin),
};
int TrackerGOTURN_Params::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* TrackerMIL_Params::sPrototype = nullptr;
ObjectMember TrackerMIL_Params::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Property_get_set(samplerInitInRadius),
Object_Property_get_set(samplerInitMaxNegNum),
Object_Property_get_set(samplerSearchWinSize),
Object_Property_get_set(samplerTrackInRadius),
Object_Property_get_set(samplerTrackMaxPosNum),
Object_Property_get_set(samplerTrackMaxNegNum),
Object_Property_get_set(featureSetNumFeatures),
};
int TrackerMIL_Params::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* UsacParams::sPrototype = nullptr;
ObjectMember UsacParams::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Property_get_set(confidence),
Object_Property_get_set(isParallel),
Object_Property_get_set(loIterations),
Object_Property_get_set(loMethod),
Object_Property_get_set(loSampleSize),
Object_Property_get_set(maxIterations),
Object_Property_get_set(neighborsSearch),
Object_Property_get_set(randomGeneratorState),
Object_Property_get_set(sampler),
Object_Property_get_set(score),
Object_Property_get_set(threshold),
};
int UsacParams::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* detail_CameraParams::sPrototype = nullptr;
ObjectMember detail_CameraParams::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(K, 0, 0),
Object_Property_get_set(focal),
Object_Property_get_set(aspect),
Object_Property_get_set(ppx),
Object_Property_get_set(ppy),
Object_Property_get_set(R),
Object_Property_get_set(t),
};
int detail_CameraParams::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* detail_ImageFeatures::sPrototype = nullptr;
ObjectMember detail_ImageFeatures::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(getKeypoints, 0, 0),
Object_Property_get_set(img_idx),
Object_Property_get_set(img_size),
Object_Property_get_set(keypoints),
Object_Property_get_set(descriptors),
};
int detail_ImageFeatures::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* detail_MatchesInfo::sPrototype = nullptr;
ObjectMember detail_MatchesInfo::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(getInliers, 0, 0),
Object_Method(getMatches, 0, 0),
Object_Property_get_set(src_img_idx),
Object_Property_get_set(dst_img_idx),
Object_Property_get_set(num_inliers),
Object_Property_get_set(H),
Object_Property_get_set(confidence),
};
int detail_MatchesInfo::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* detail_ProjectorBase::sPrototype = nullptr;
ObjectMember detail_ProjectorBase::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
};
int detail_ProjectorBase::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* detail_SphericalProjector::sPrototype = nullptr;
ObjectMember detail_SphericalProjector::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(mapBackward, 4, 4),
Object_Method(mapForward, 4, 4),
};
int detail_SphericalProjector::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* dnn_DictValue::sPrototype = nullptr;
ObjectMember dnn_DictValue::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(getIntValue, 0, 1),
Object_Method(getRealValue, 0, 1),
Object_Method(getStringValue, 0, 1),
Object_Method(isInt, 0, 0),
Object_Method(isReal, 0, 0),
Object_Method(isString, 0, 0),
};
int dnn_DictValue::sMemberCount = _countof(sMember);

#ifdef HAS_GAPI
thread_local IAhkApi::Prototype* gapi_GNetPackage::sPrototype = nullptr;
ObjectMember gapi_GNetPackage::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
};
int gapi_GNetPackage::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* gapi_GNetParam::sPrototype = nullptr;
ObjectMember gapi_GNetParam::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
};
int gapi_GNetParam::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* gapi_streaming_queue_capacity::sPrototype = nullptr;
ObjectMember gapi_streaming_queue_capacity::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Property_get_set(capacity),
};
int gapi_streaming_queue_capacity::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* gapi_wip_draw_Circle::sPrototype = nullptr;
ObjectMember gapi_wip_draw_Circle::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Property_get_set(center),
Object_Property_get_set(radius),
Object_Property_get_set(color),
Object_Property_get_set(thick),
Object_Property_get_set(lt),
Object_Property_get_set(shift),
};
int gapi_wip_draw_Circle::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* gapi_wip_draw_Image::sPrototype = nullptr;
ObjectMember gapi_wip_draw_Image::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Property_get_set(org),
Object_Property_get_set(img),
Object_Property_get_set(alpha),
};
int gapi_wip_draw_Image::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* gapi_wip_draw_Line::sPrototype = nullptr;
ObjectMember gapi_wip_draw_Line::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Property_get_set(pt1),
Object_Property_get_set(pt2),
Object_Property_get_set(color),
Object_Property_get_set(thick),
Object_Property_get_set(lt),
Object_Property_get_set(shift),
};
int gapi_wip_draw_Line::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* gapi_wip_draw_Mosaic::sPrototype = nullptr;
ObjectMember gapi_wip_draw_Mosaic::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Property_get_set(mos),
Object_Property_get_set(cellSz),
Object_Property_get_set(decim),
};
int gapi_wip_draw_Mosaic::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* gapi_wip_draw_Poly::sPrototype = nullptr;
ObjectMember gapi_wip_draw_Poly::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Property_get_set(points),
Object_Property_get_set(color),
Object_Property_get_set(thick),
Object_Property_get_set(lt),
Object_Property_get_set(shift),
};
int gapi_wip_draw_Poly::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* gapi_wip_draw_Rect::sPrototype = nullptr;
ObjectMember gapi_wip_draw_Rect::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Property_get_set(rect),
Object_Property_get_set(color),
Object_Property_get_set(thick),
Object_Property_get_set(lt),
Object_Property_get_set(shift),
};
int gapi_wip_draw_Rect::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* gapi_wip_draw_Text::sPrototype = nullptr;
ObjectMember gapi_wip_draw_Text::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Property_get_set(text),
Object_Property_get_set(org),
Object_Property_get_set(ff),
Object_Property_get_set(fs),
Object_Property_get_set(color),
Object_Property_get_set(thick),
Object_Property_get_set(lt),
Object_Property_get_set(bottom_left_origin),
};
int gapi_wip_draw_Text::sMemberCount = _countof(sMember);
#endif

void AKAZE::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::AKAZE>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		float threshold = 0.001f;
		int descriptor_type = cv::AKAZE::DESCRIPTOR_MLDB, descriptor_size = 0, descriptor_channels = 3, nOctaves = 4, nOctaveLayers = 4, diffusivity = cv::KAZE::DIFF_PM_G2;
		if (aParamCount > 0 && aParam[0]->symbol != SYM_MISSING)
			TokenToVal(*aParam[0], descriptor_type);
		if (aParamCount > 1 && aParam[1]->symbol != SYM_MISSING)
			TokenToVal(*aParam[1], descriptor_size);
		if (aParamCount > 2 && aParam[2]->symbol != SYM_MISSING)
			TokenToVal(*aParam[2], descriptor_channels);
		if (aParamCount > 3 && aParam[3]->symbol != SYM_MISSING)
			TokenToVal(*aParam[3], threshold);
		if (aParamCount > 4 && aParam[4]->symbol != SYM_MISSING)
			TokenToVal(*aParam[4], nOctaves);
		if (aParamCount > 5 && aParam[5]->symbol != SYM_MISSING)
			TokenToVal(*aParam[5], nOctaveLayers);
		if (aParamCount > 6 && aParam[6]->symbol != SYM_MISSING)
			TokenToVal(*aParam[6], diffusivity);
		mC = cv::AKAZE::create((cv::AKAZE::DescriptorType)descriptor_type, descriptor_size, descriptor_channels, threshold, nOctaves, nOctaveLayers, (cv::KAZE::DiffusivityType)diffusivity);
		return;
	}
	case M_getDefaultName: {
		auto __retval = mC->getDefaultName();
		return ValToResult(__retval, aResultToken);
	}
	case M_getDescriptorChannels: {
		auto __retval = (__int64)mC->getDescriptorChannels();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getDescriptorSize: {
		auto __retval = (__int64)mC->getDescriptorSize();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getDescriptorType: {
		auto __retval = mC->getDescriptorType();
		return ValToResult(__retval, aResultToken);
	}
	case M_getDiffusivity: {
		auto __retval = mC->getDiffusivity();
		return ValToResult(__retval, aResultToken);
	}
	case M_getNOctaveLayers: {
		auto __retval = (__int64)mC->getNOctaveLayers();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getNOctaves: {
		auto __retval = (__int64)mC->getNOctaves();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getThreshold: {
		auto __retval = mC->getThreshold();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_setDescriptorChannels: {
		int dch;
		if (ParamIndexToVal(0, dch))
			_o_return_result;
		mC->setDescriptorChannels(dch);
		return;
	}
	case M_setDescriptorSize: {
		int dsize;
		if (ParamIndexToVal(0, dsize))
			_o_return_result;
		mC->setDescriptorSize(dsize);
		return;
	}
	case M_setDescriptorType: {
		int dtype;
		if (ParamIndexToVal(0, dtype))
			_o_return_result;
		mC->setDescriptorType((cv::AKAZE::DescriptorType)dtype);
		return;
	}
	case M_setDiffusivity: {
		int diff;
		if (ParamIndexToVal(0, diff))
			_o_return_result;
		mC->setDiffusivity((cv::KAZE::DiffusivityType)diff);
		return;
	}
	case M_setNOctaveLayers: {
		int octaveLayers;
		if (ParamIndexToVal(0, octaveLayers))
			_o_return_result;
		mC->setNOctaveLayers(octaveLayers);
		return;
	}
	case M_setNOctaves: {
		int octaves;
		if (ParamIndexToVal(0, octaves))
			_o_return_result;
		mC->setNOctaves(octaves);
		return;
	}
	case M_setThreshold: {
		double threshold;
		if (ParamIndexToVal(0, threshold))
			_o_return_result;
		mC->setThreshold(threshold);
		return;
	}
	}
}

void AffineFeature::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::AffineFeature>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		cv::Ptr<cv::Feature2D> backend;
		float tiltStep = 1.4142135623730951f, rotateStepBase = 72;
		int maxTilt = 5, minTilt = 0;
		if (ParamIndexToVal(0, backend))
			_o_return_result;
		if (aParamCount > 1 && aParam[1]->symbol != SYM_MISSING)
			TokenToVal(*aParam[1], maxTilt);
		if (aParamCount > 2 && aParam[2]->symbol != SYM_MISSING)
			TokenToVal(*aParam[2], minTilt);
		if (aParamCount > 3 && aParam[3]->symbol != SYM_MISSING)
			TokenToVal(*aParam[3], tiltStep);
		if (aParamCount > 4 && aParam[4]->symbol != SYM_MISSING)
			TokenToVal(*aParam[4], rotateStepBase);
		mC = cv::AffineFeature::create(backend, maxTilt, minTilt, tiltStep, rotateStepBase);
		return;
	}
	case M_getDefaultName: {
		auto __retval = mC->getDefaultName();
		return ValToResult(__retval, aResultToken);
	}
	case M_getViewParams: {
		std::vector<float> tilts, rolls;
		if (ParamIndexToVal(0, tilts))
			_o_return_result;
		if (ParamIndexToVal(1, rolls))
			_o_return_result;
		mC->getViewParams(tilts, rolls);
		return;
	}
	case M_setViewParams: {
		std::vector<float> tilts, rolls;
		if (ParamIndexToVal(0, tilts))
			_o_return_result;
		if (ParamIndexToVal(1, rolls))
			_o_return_result;
		mC->setViewParams(tilts, rolls);
		return;
	}
	}
}

void AgastFeatureDetector::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::AgastFeatureDetector>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		bool nonmaxSuppression = true;
		int threshold = 10, type = cv::AgastFeatureDetector::OAST_9_16;
		if (aParamCount > 0 && aParam[0]->symbol != SYM_MISSING)
			TokenToVal(*aParam[0], threshold);
		if (aParamCount > 1 && aParam[1]->symbol != SYM_MISSING)
			TokenToVal(*aParam[1], (char&)nonmaxSuppression);
		if (aParamCount > 2 && aParam[2]->symbol != SYM_MISSING)
			TokenToVal(*aParam[2], type);
		mC = cv::AgastFeatureDetector::create(threshold, nonmaxSuppression, (cv::AgastFeatureDetector::DetectorType)type);
		return;
	}
	case M_getDefaultName: {
		auto __retval = mC->getDefaultName();
		return ValToResult(__retval, aResultToken);
	}
	case M_getNonmaxSuppression: {
		auto __retval = (__int64)mC->getNonmaxSuppression();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getThreshold: {
		auto __retval = (__int64)mC->getThreshold();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getType: {
		auto __retval = mC->getType();
		return ValToResult(__retval, aResultToken);
	}
	case M_setNonmaxSuppression: {
		bool f;
		if (ParamIndexToVal(0, (char&)f))
			_o_return_result;
		mC->setNonmaxSuppression(f);
		return;
	}
	case M_setThreshold: {
		int threshold;
		if (ParamIndexToVal(0, threshold))
			_o_return_result;
		mC->setThreshold(threshold);
		return;
	}
	case M_setType: {
		int type;
		if (ParamIndexToVal(0, type))
			_o_return_result;
		mC->setType((cv::AgastFeatureDetector::DetectorType)type);
		return;
	}
	}
}

void Algorithm::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::Algorithm>;
		mC = new cv::Algorithm;
		return;
	}
	case M_clear: {
		mC->clear();
		return;
	}
	case M_empty: {
		auto __retval = (__int64)mC->empty();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getDefaultName: {
		auto __retval = mC->getDefaultName();
		return ValToResult(__retval, aResultToken);
	}
	case M_read: {
		cv::FileNode* fn;
		if (ParamIndexToVal(0, fn))
			_o_return_result;
		mC->read(*fn);
		return;
	}
	case M_save: {
		cv::String filename;
		if (ParamIndexToVal(0, filename))
			_o_return_result;
		mC->save(filename);
		return;
	}
	case M_write: {
		cv::Ptr<cv::FileStorage> fs;
		cv::String name = cv::String();
		if (ParamIndexToVal(0, fs))
			_o_return_result;
		if (aParamCount > 1 && aParam[1]->symbol != SYM_MISSING)
			TokenToVal(*aParam[1], name);
		mC->write(fs, name);
		return;
	}
	}
}

void AlignExposures::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M_process: {
		cv::_InputArray src, times, response;
		std::vector<cv::Mat> dst;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, dst))
			_o_return_result;
		if (ParamIndexToVal(2, times))
			_o_return_result;
		if (ParamIndexToVal(3, response))
			_o_return_result;
		mC->process(src, dst, times, response);
		return;
	}
	}
}

void AlignMTB::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::AlignMTB>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		else _o_invalid_param;
		return;
	}
	case M_calculateShift: {
		cv::_InputArray img0, img1;
		if (ParamIndexToVal(0, img0))
			_o_return_result;
		if (ParamIndexToVal(1, img1))
			_o_return_result;
		auto __retval = mC->calculateShift(img0, img1);
		return ValToResult(__retval, aResultToken);
	}
	case M_computeBitmaps: {
		cv::_InputArray img;
		cv::_OutputArray tb, eb;
		if (ParamIndexToVal(0, img))
			_o_return_result;
		if (ParamIndexToVal(1, tb))
			_o_return_result;
		if (ParamIndexToVal(2, eb))
			_o_return_result;
		mC->computeBitmaps(img, tb, eb);
		return;
	}
	case M_getCut: {
		auto __retval = (__int64)mC->getCut();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getExcludeRange: {
		auto __retval = (__int64)mC->getExcludeRange();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getMaxBits: {
		auto __retval = (__int64)mC->getMaxBits();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_process: {
		if (aParamCount == 4) {
			cv::_InputArray src, times, response;
			std::vector<cv::Mat> dst;
			if (ParamIndexToVal(0, src))
				_o_return_result;
			if (ParamIndexToVal(1, dst))
				_o_return_result;
			if (ParamIndexToVal(2, times))
				_o_return_result;
			if (ParamIndexToVal(3, response))
				_o_return_result;
			mC->process(src, dst, times, response);
			return;
		}
		else if (aParamCount == 2) {
			cv::_InputArray src;
			std::vector<cv::Mat> dst;
			if (ParamIndexToVal(0, src))
				_o_return_result;
			if (ParamIndexToVal(1, dst))
				_o_return_result;
			mC->process(src, dst);
			return;
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case M_setCut: {
		bool value;
		if (ParamIndexToVal(0, (char&)value))
			_o_return_result;
		mC->setCut(value);
		return;
	}
	case M_setExcludeRange: {
		int exclude_range;
		if (ParamIndexToVal(0, exclude_range))
			_o_return_result;
		mC->setExcludeRange(exclude_range);
		return;
	}
	case M_setMaxBits: {
		int max_bits;
		if (ParamIndexToVal(0, max_bits))
			_o_return_result;
		mC->setMaxBits(max_bits);
		return;
	}
	case M_shiftMat: {
		cv::_InputArray src;
		cv::_OutputArray dst;
		cv::Point shift;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, dst))
			_o_return_result;
		if (ParamIndexToVal(2, shift))
			_o_return_result;
		mC->shiftMat(src, dst, shift);
		return;
	}
	}
}

void AsyncArray::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::AsyncArray>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		mC = new cv::AsyncArray();
		return;
	}
	case M_get: {
		if (aParamCount == 1) {
			cv::_OutputArray dst;
			if (ParamIndexToVal(0, dst))
				_o_return_result;
			mC->get(dst);
			return;
		}
		else if (aParamCount == 2) {
			cv::_OutputArray dst;
			double timeoutNs;
			if (ParamIndexToVal(0, dst))
				_o_return_result;
			if (ParamIndexToVal(1, timeoutNs))
				_o_return_result;
			auto __retval = (__int64)mC->get(dst, timeoutNs);
			return (void)(aResultToken.SetValue(__retval));
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case M_release: {
		mC->release();
		return;
	}
	case M_valid: {
		auto __retval = (__int64)mC->valid();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_wait_for: {
		double timeoutNs;
		if (ParamIndexToVal(0, timeoutNs))
			_o_return_result;
		auto __retval = (__int64)mC->wait_for(timeoutNs);
		return (void)(aResultToken.SetValue(__retval));
	}
	}
}

void BFMatcher::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::BFMatcher>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		bool crossCheck = false;
		int normType = cv::NORM_L2;
		if (aParamCount > 0 && aParam[0]->symbol != SYM_MISSING)
			TokenToVal(*aParam[0], normType);
		if (aParamCount > 1 && aParam[1]->symbol != SYM_MISSING)
			TokenToVal(*aParam[1], (char&)crossCheck);
		mC = new cv::BFMatcher(normType, crossCheck);
		return;
	}
	}
}

void BOWImgDescriptorExtractor::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::BOWImgDescriptorExtractor>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		cv::Ptr<cv::DescriptorExtractor> dextractor;
		cv::Ptr<cv::DescriptorMatcher> dmatcher;
		if (ParamIndexToVal(0, dextractor))
			_o_return_result;
		if (ParamIndexToVal(1, dmatcher))
			_o_return_result;
		mC = new cv::BOWImgDescriptorExtractor(dextractor, dmatcher);
		return;
	}
	case M_compute2: {
		cv::Mat image, imgDescriptor;
		std::vector<cv::KeyPoint> keypoints;
		if (ParamIndexToVal(0, image))
			_o_return_result;
		if (ParamIndexToVal(1, keypoints))
			_o_return_result;
		VarRef* var_imgDescriptor = nullptr;
		if (ParamIndexToVal(2, var_imgDescriptor))
			_o_return_result;
		mC->compute2(image, keypoints, imgDescriptor);
		ValToResult(imgDescriptor, aResultToken);
		g_ahkapi->VarAssign(var_imgDescriptor, aResultToken);
		g_ahkapi->ResultTokenFree(aResultToken);
		return;
	}
	case M_descriptorSize: {
		auto __retval = (__int64)mC->descriptorSize();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_descriptorType: {
		auto __retval = (__int64)mC->descriptorType();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getVocabulary: {
		auto __retval = (Mat*)Mat::sPrototype->New(g_invalidparam, 1);
		__retval->mC = mC->getVocabulary();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_setVocabulary: {
		cv::Mat vocabulary;
		if (ParamIndexToVal(0, vocabulary))
			_o_return_result;
		mC->setVocabulary(vocabulary);
		return;
	}
	}
}

void BOWKMeansTrainer::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::BOWKMeansTrainer>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		if (1 <= aParamCount && aParamCount <= 4) {
			cv::TermCriteria termcrit = cv::TermCriteria();
			;
			int clusterCount, attempts = 3, flags = cv::KMEANS_PP_CENTERS;
			if (ParamIndexToVal(0, clusterCount))
				_o_return_result;
			if (aParamCount > 1 && aParam[1]->symbol != SYM_MISSING)
				TokenToVal(*aParam[1], termcrit);
			if (aParamCount > 2 && aParam[2]->symbol != SYM_MISSING)
				TokenToVal(*aParam[2], attempts);
			if (aParamCount > 3 && aParam[3]->symbol != SYM_MISSING)
				TokenToVal(*aParam[3], flags);
			mC = new cv::BOWKMeansTrainer(clusterCount, termcrit, attempts, flags);
			return;
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case M_cluster: {
		if (aParamCount == 0) {
			auto __retval = (Mat*)Mat::sPrototype->New(g_invalidparam, 1);
			__retval->mC = mC->cluster();
			return (void)(aResultToken.SetValue(__retval));
		}
		else if (aParamCount == 1) {
			cv::Mat descriptors;
			if (ParamIndexToVal(0, descriptors))
				_o_return_result;
			auto __retval = (Mat*)Mat::sPrototype->New(g_invalidparam, 1);
			__retval->mC = mC->cluster(descriptors);
			return (void)(aResultToken.SetValue(__retval));
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	}
}

void BOWTrainer::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M_add: {
		cv::Mat descriptors;
		if (ParamIndexToVal(0, descriptors))
			_o_return_result;
		mC->add(descriptors);
		return;
	}
	case M_clear: {
		mC->clear();
		return;
	}
	case M_cluster: {
		if (aParamCount == 0) {
			auto __retval = (Mat*)Mat::sPrototype->New(g_invalidparam, 1);
			__retval->mC = mC->cluster();
			return (void)(aResultToken.SetValue(__retval));
		}
		else if (aParamCount == 1) {
			cv::Mat descriptors;
			if (ParamIndexToVal(0, descriptors))
				_o_return_result;
			auto __retval = (Mat*)Mat::sPrototype->New(g_invalidparam, 1);
			__retval->mC = mC->cluster(descriptors);
			return (void)(aResultToken.SetValue(__retval));
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case M_descriptorsCount: {
		auto __retval = (__int64)mC->descriptorsCount();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getDescriptors: {
		auto __retval = mC->getDescriptors();
		return ValToResult(__retval, aResultToken);
	}
	}
}

void BRISK::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::BRISK>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		if (!MatchTypes("i?if")) {
			float patternScale = 1.0f;
			int thresh = 30, octaves = 3;
			if (aParamCount > 0 && aParam[0]->symbol != SYM_MISSING)
				TokenToVal(*aParam[0], thresh);
			if (aParamCount > 1 && aParam[1]->symbol != SYM_MISSING)
				TokenToVal(*aParam[1], octaves);
			if (aParamCount > 2 && aParam[2]->symbol != SYM_MISSING)
				TokenToVal(*aParam[2], patternScale);
			mC = cv::BRISK::create(thresh, octaves, patternScale);
			return;
		}
		else if (!MatchTypes("oof?fo")) {
			float dMax = 5.85f, dMin = 8.2f;
			std::vector<float> radiusList;
			std::vector<int> numberList, indexChange = std::vector<int>();
			if (ParamIndexToVal(0, radiusList))
				_o_return_result;
			if (ParamIndexToVal(1, numberList))
				_o_return_result;
			if (aParamCount > 2 && aParam[2]->symbol != SYM_MISSING)
				TokenToVal(*aParam[2], dMax);
			if (aParamCount > 3 && aParam[3]->symbol != SYM_MISSING)
				TokenToVal(*aParam[3], dMin);
			if (aParamCount > 4 && aParam[4]->symbol != SYM_MISSING)
				TokenToVal(*aParam[4], indexChange);
			mC = cv::BRISK::create(radiusList, numberList, dMax, dMin, indexChange);
			return;
		}
		else if (!MatchTypes("iioof?fo")) {
			float dMax = 5.85f, dMin = 8.2f;
			int thresh, octaves;
			std::vector<float> radiusList;
			std::vector<int> numberList, indexChange = std::vector<int>();
			if (ParamIndexToVal(0, thresh))
				_o_return_result;
			if (ParamIndexToVal(1, octaves))
				_o_return_result;
			if (ParamIndexToVal(2, radiusList))
				_o_return_result;
			if (ParamIndexToVal(3, numberList))
				_o_return_result;
			if (aParamCount > 4 && aParam[4]->symbol != SYM_MISSING)
				TokenToVal(*aParam[4], dMax);
			if (aParamCount > 5 && aParam[5]->symbol != SYM_MISSING)
				TokenToVal(*aParam[5], dMin);
			if (aParamCount > 6 && aParam[6]->symbol != SYM_MISSING)
				TokenToVal(*aParam[6], indexChange);
			mC = cv::BRISK::create(thresh, octaves, radiusList, numberList, dMax, dMin, indexChange);
			return;
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case M_getDefaultName: {
		auto __retval = mC->getDefaultName();
		return ValToResult(__retval, aResultToken);
	}
	case M_getOctaves: {
		auto __retval = (__int64)mC->getOctaves();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getThreshold: {
		auto __retval = (__int64)mC->getThreshold();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_setOctaves: {
		int octaves;
		if (ParamIndexToVal(0, octaves))
			_o_return_result;
		mC->setOctaves(octaves);
		return;
	}
	case M_setThreshold: {
		int threshold;
		if (ParamIndexToVal(0, threshold))
			_o_return_result;
		mC->setThreshold(threshold);
		return;
	}
	}
}

void BackgroundSubtractor::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M_apply: {
		cv::_InputArray image;
		cv::_OutputArray fgmask;
		double learningRate = -1;
		if (ParamIndexToVal(0, image))
			_o_return_result;
		if (ParamIndexToVal(1, fgmask))
			_o_return_result;
		if (aParamCount > 2 && aParam[2]->symbol != SYM_MISSING)
			TokenToVal(*aParam[2], learningRate);
		mC->apply(image, fgmask, learningRate);
		return;
	}
	case M_getBackgroundImage: {
		cv::_OutputArray backgroundImage;
		if (ParamIndexToVal(0, backgroundImage))
			_o_return_result;
		mC->getBackgroundImage(backgroundImage);
		return;
	}
	}
}

void BackgroundSubtractorKNN::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::BackgroundSubtractorKNN>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		else _o_invalid_param;
		return;
	}
	case M_getDetectShadows: {
		auto __retval = (__int64)mC->getDetectShadows();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getDist2Threshold: {
		auto __retval = mC->getDist2Threshold();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getHistory: {
		auto __retval = (__int64)mC->getHistory();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getNSamples: {
		auto __retval = (__int64)mC->getNSamples();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getShadowThreshold: {
		auto __retval = mC->getShadowThreshold();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getShadowValue: {
		auto __retval = (__int64)mC->getShadowValue();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getkNNSamples: {
		auto __retval = (__int64)mC->getkNNSamples();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_setDetectShadows: {
		bool detectShadows;
		if (ParamIndexToVal(0, (char&)detectShadows))
			_o_return_result;
		mC->setDetectShadows(detectShadows);
		return;
	}
	case M_setDist2Threshold: {
		double _dist2Threshold;
		if (ParamIndexToVal(0, _dist2Threshold))
			_o_return_result;
		mC->setDist2Threshold(_dist2Threshold);
		return;
	}
	case M_setHistory: {
		int history;
		if (ParamIndexToVal(0, history))
			_o_return_result;
		mC->setHistory(history);
		return;
	}
	case M_setNSamples: {
		int _nN;
		if (ParamIndexToVal(0, _nN))
			_o_return_result;
		mC->setNSamples(_nN);
		return;
	}
	case M_setShadowThreshold: {
		double threshold;
		if (ParamIndexToVal(0, threshold))
			_o_return_result;
		mC->setShadowThreshold(threshold);
		return;
	}
	case M_setShadowValue: {
		int value;
		if (ParamIndexToVal(0, value))
			_o_return_result;
		mC->setShadowValue(value);
		return;
	}
	case M_setkNNSamples: {
		int _nkNN;
		if (ParamIndexToVal(0, _nkNN))
			_o_return_result;
		mC->setkNNSamples(_nkNN);
		return;
	}
	}
}

void BackgroundSubtractorMOG2::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::BackgroundSubtractorMOG2>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		else _o_invalid_param;
		return;
	}
	case M_apply: {
		cv::_InputArray image;
		cv::_OutputArray fgmask;
		double learningRate = -1;
		if (ParamIndexToVal(0, image))
			_o_return_result;
		if (ParamIndexToVal(1, fgmask))
			_o_return_result;
		if (aParamCount > 2 && aParam[2]->symbol != SYM_MISSING)
			TokenToVal(*aParam[2], learningRate);
		mC->apply(image, fgmask, learningRate);
		return;
	}
	case M_getBackgroundRatio: {
		auto __retval = mC->getBackgroundRatio();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getComplexityReductionThreshold: {
		auto __retval = mC->getComplexityReductionThreshold();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getDetectShadows: {
		auto __retval = (__int64)mC->getDetectShadows();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getHistory: {
		auto __retval = (__int64)mC->getHistory();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getNMixtures: {
		auto __retval = (__int64)mC->getNMixtures();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getShadowThreshold: {
		auto __retval = mC->getShadowThreshold();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getShadowValue: {
		auto __retval = (__int64)mC->getShadowValue();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getVarInit: {
		auto __retval = mC->getVarInit();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getVarMax: {
		auto __retval = mC->getVarMax();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getVarMin: {
		auto __retval = mC->getVarMin();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getVarThreshold: {
		auto __retval = mC->getVarThreshold();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getVarThresholdGen: {
		auto __retval = mC->getVarThresholdGen();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_setBackgroundRatio: {
		double ratio;
		if (ParamIndexToVal(0, ratio))
			_o_return_result;
		mC->setBackgroundRatio(ratio);
		return;
	}
	case M_setComplexityReductionThreshold: {
		double ct;
		if (ParamIndexToVal(0, ct))
			_o_return_result;
		mC->setComplexityReductionThreshold(ct);
		return;
	}
	case M_setDetectShadows: {
		bool detectShadows;
		if (ParamIndexToVal(0, (char&)detectShadows))
			_o_return_result;
		mC->setDetectShadows(detectShadows);
		return;
	}
	case M_setHistory: {
		int history;
		if (ParamIndexToVal(0, history))
			_o_return_result;
		mC->setHistory(history);
		return;
	}
	case M_setNMixtures: {
		int nmixtures;
		if (ParamIndexToVal(0, nmixtures))
			_o_return_result;
		mC->setNMixtures(nmixtures);
		return;
	}
	case M_setShadowThreshold: {
		double threshold;
		if (ParamIndexToVal(0, threshold))
			_o_return_result;
		mC->setShadowThreshold(threshold);
		return;
	}
	case M_setShadowValue: {
		int value;
		if (ParamIndexToVal(0, value))
			_o_return_result;
		mC->setShadowValue(value);
		return;
	}
	case M_setVarInit: {
		double varInit;
		if (ParamIndexToVal(0, varInit))
			_o_return_result;
		mC->setVarInit(varInit);
		return;
	}
	case M_setVarMax: {
		double varMax;
		if (ParamIndexToVal(0, varMax))
			_o_return_result;
		mC->setVarMax(varMax);
		return;
	}
	case M_setVarMin: {
		double varMin;
		if (ParamIndexToVal(0, varMin))
			_o_return_result;
		mC->setVarMin(varMin);
		return;
	}
	case M_setVarThreshold: {
		double varThreshold;
		if (ParamIndexToVal(0, varThreshold))
			_o_return_result;
		mC->setVarThreshold(varThreshold);
		return;
	}
	case M_setVarThresholdGen: {
		double varThresholdGen;
		if (ParamIndexToVal(0, varThresholdGen))
			_o_return_result;
		mC->setVarThresholdGen(varThresholdGen);
		return;
	}
	}
}

void BaseCascadeClassifier::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: new (&mC) cv::Ptr<cv::BaseCascadeClassifier>; return;
	}
}

void CLAHE::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::CLAHE>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		else _o_invalid_param;
		return;
	}
	case M_apply: {
		cv::_InputArray src;
		cv::_OutputArray dst;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, dst))
			_o_return_result;
		mC->apply(src, dst);
		return;
	}
	case M_collectGarbage: {
		mC->collectGarbage();
		return;
	}
	case M_getClipLimit: {
		auto __retval = mC->getClipLimit();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getTilesGridSize: {
		auto __retval = mC->getTilesGridSize();
		return ValToResult(__retval, aResultToken);
	}
	case M_setClipLimit: {
		double clipLimit;
		if (ParamIndexToVal(0, clipLimit))
			_o_return_result;
		mC->setClipLimit(clipLimit);
		return;
	}
	case M_setTilesGridSize: {
		cv::Size tileGridSize;
		if (ParamIndexToVal(0, tileGridSize))
			_o_return_result;
		mC->setTilesGridSize(tileGridSize);
		return;
	}
	}
}

void CalibrateCRF::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M_process: {
		cv::_InputArray src, times;
		cv::_OutputArray dst;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, dst))
			_o_return_result;
		if (ParamIndexToVal(2, times))
			_o_return_result;
		mC->process(src, dst, times);
		return;
	}
	}
}

void CalibrateDebevec::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::CalibrateDebevec>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		else _o_invalid_param;
		return;
	}
	case M_getLambda: {
		auto __retval = (double)mC->getLambda();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getRandom: {
		auto __retval = (__int64)mC->getRandom();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getSamples: {
		auto __retval = (__int64)mC->getSamples();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_setLambda: {
		float lambda;
		if (ParamIndexToVal(0, lambda))
			_o_return_result;
		mC->setLambda(lambda);
		return;
	}
	case M_setRandom: {
		bool random;
		if (ParamIndexToVal(0, (char&)random))
			_o_return_result;
		mC->setRandom(random);
		return;
	}
	case M_setSamples: {
		int samples;
		if (ParamIndexToVal(0, samples))
			_o_return_result;
		mC->setSamples(samples);
		return;
	}
	}
}

void CalibrateRobertson::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::CalibrateRobertson>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		else _o_invalid_param;
		return;
	}
	case M_getMaxIter: {
		auto __retval = (__int64)mC->getMaxIter();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getRadiance: {
		auto __retval = (Mat*)Mat::sPrototype->New(g_invalidparam, 1);
		__retval->mC = mC->getRadiance();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getThreshold: {
		auto __retval = (double)mC->getThreshold();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_setMaxIter: {
		int max_iter;
		if (ParamIndexToVal(0, max_iter))
			_o_return_result;
		mC->setMaxIter(max_iter);
		return;
	}
	case M_setThreshold: {
		float threshold;
		if (ParamIndexToVal(0, threshold))
			_o_return_result;
		mC->setThreshold(threshold);
		return;
	}
	}
}

void CascadeClassifier::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::CascadeClassifier>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		if (aParamCount == 0) {
			mC = new cv::CascadeClassifier();
			return;
		}
		else if (aParamCount == 1) {
			cv::String filename;
			if (ParamIndexToVal(0, filename))
				_o_return_result;
			mC = new cv::CascadeClassifier(filename);
			return;
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case M_convert: {
		cv::String oldcascade, newcascade;
		if (ParamIndexToVal(0, oldcascade))
			_o_return_result;
		if (ParamIndexToVal(1, newcascade))
			_o_return_result;
		auto __retval = (__int64)mC->convert(oldcascade, newcascade);
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_detectMultiScale: {
		if (!MatchTypes("oof?iioo")) {
			cv::_InputArray image;
			cv::Size minSize = cv::Size(), maxSize = cv::Size();
			double scaleFactor = 1.1;
			int minNeighbors = 3, flags = 0;
			std::vector<cv::Rect> objects;
			if (ParamIndexToVal(0, image))
				_o_return_result;
			VarRef* var_objects = nullptr;
			if (ParamIndexToVal(1, var_objects))
				_o_return_result;
			if (aParamCount > 2 && aParam[2]->symbol != SYM_MISSING)
				TokenToVal(*aParam[2], scaleFactor);
			if (aParamCount > 3 && aParam[3]->symbol != SYM_MISSING)
				TokenToVal(*aParam[3], minNeighbors);
			if (aParamCount > 4 && aParam[4]->symbol != SYM_MISSING)
				TokenToVal(*aParam[4], flags);
			if (aParamCount > 5 && aParam[5]->symbol != SYM_MISSING)
				TokenToVal(*aParam[5], minSize);
			if (aParamCount > 6 && aParam[6]->symbol != SYM_MISSING)
				TokenToVal(*aParam[6], maxSize);
			mC->detectMultiScale(image, objects, scaleFactor, minNeighbors, flags, minSize, maxSize);
			ValToResult(objects, aResultToken);
			g_ahkapi->VarAssign(var_objects, aResultToken);
			g_ahkapi->ResultTokenFree(aResultToken);
			return;
		}
		else if (!MatchTypes("ooof?iioo")) {
			cv::_InputArray image;
			cv::Size minSize = cv::Size(), maxSize = cv::Size();
			double scaleFactor = 1.1;
			int minNeighbors = 3, flags = 0;
			std::vector<cv::Rect> objects;
			std::vector<int> numDetections;
			if (ParamIndexToVal(0, image))
				_o_return_result;
			VarRef* var_objects = nullptr;
			if (ParamIndexToVal(1, var_objects))
				_o_return_result;
			VarRef* var_numDetections = nullptr;
			if (ParamIndexToVal(2, var_numDetections))
				_o_return_result;
			if (aParamCount > 3 && aParam[3]->symbol != SYM_MISSING)
				TokenToVal(*aParam[3], scaleFactor);
			if (aParamCount > 4 && aParam[4]->symbol != SYM_MISSING)
				TokenToVal(*aParam[4], minNeighbors);
			if (aParamCount > 5 && aParam[5]->symbol != SYM_MISSING)
				TokenToVal(*aParam[5], flags);
			if (aParamCount > 6 && aParam[6]->symbol != SYM_MISSING)
				TokenToVal(*aParam[6], minSize);
			if (aParamCount > 7 && aParam[7]->symbol != SYM_MISSING)
				TokenToVal(*aParam[7], maxSize);
			mC->detectMultiScale(image, objects, numDetections, scaleFactor, minNeighbors, flags, minSize, maxSize);
			ValToResult(objects, aResultToken);
			g_ahkapi->VarAssign(var_objects, aResultToken);
			g_ahkapi->ResultTokenFree(aResultToken);
			ValToResult(numDetections, aResultToken);
			g_ahkapi->VarAssign(var_numDetections, aResultToken);
			g_ahkapi->ResultTokenFree(aResultToken);
			return;
		}
		else if (!MatchTypes("oooof?iiooi")) {
			bool outputRejectLevels = false;
			cv::_InputArray image;
			cv::Size minSize = cv::Size(), maxSize = cv::Size();
			double scaleFactor = 1.1;
			int minNeighbors = 3, flags = 0;
			std::vector<cv::Rect> objects;
			std::vector<double> levelWeights;
			std::vector<int> rejectLevels;
			if (ParamIndexToVal(0, image))
				_o_return_result;
			VarRef* var_objects = nullptr;
			if (ParamIndexToVal(1, var_objects))
				_o_return_result;
			VarRef* var_rejectLevels = nullptr;
			if (ParamIndexToVal(2, var_rejectLevels))
				_o_return_result;
			VarRef* var_levelWeights = nullptr;
			if (ParamIndexToVal(3, var_levelWeights))
				_o_return_result;
			if (aParamCount > 4 && aParam[4]->symbol != SYM_MISSING)
				TokenToVal(*aParam[4], scaleFactor);
			if (aParamCount > 5 && aParam[5]->symbol != SYM_MISSING)
				TokenToVal(*aParam[5], minNeighbors);
			if (aParamCount > 6 && aParam[6]->symbol != SYM_MISSING)
				TokenToVal(*aParam[6], flags);
			if (aParamCount > 7 && aParam[7]->symbol != SYM_MISSING)
				TokenToVal(*aParam[7], minSize);
			if (aParamCount > 8 && aParam[8]->symbol != SYM_MISSING)
				TokenToVal(*aParam[8], maxSize);
			if (aParamCount > 9 && aParam[9]->symbol != SYM_MISSING)
				TokenToVal(*aParam[9], (char&)outputRejectLevels);
			mC->detectMultiScale(image, objects, rejectLevels, levelWeights, scaleFactor, minNeighbors, flags, minSize, maxSize, outputRejectLevels);
			ValToResult(objects, aResultToken);
			g_ahkapi->VarAssign(var_objects, aResultToken);
			g_ahkapi->ResultTokenFree(aResultToken);
			ValToResult(rejectLevels, aResultToken);
			g_ahkapi->VarAssign(var_rejectLevels, aResultToken);
			g_ahkapi->ResultTokenFree(aResultToken);
			ValToResult(levelWeights, aResultToken);
			g_ahkapi->VarAssign(var_levelWeights, aResultToken);
			g_ahkapi->ResultTokenFree(aResultToken);
			return;
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case M_empty: {
		auto __retval = (__int64)mC->empty();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getFeatureType: {
		auto __retval = (__int64)mC->getFeatureType();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getOriginalWindowSize: {
		auto __retval = mC->getOriginalWindowSize();
		return ValToResult(__retval, aResultToken);
	}
	case M_isOldFormatCascade: {
		auto __retval = (__int64)mC->isOldFormatCascade();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_load: {
		cv::String filename;
		if (ParamIndexToVal(0, filename))
			_o_return_result;
		auto __retval = (__int64)mC->load(filename);
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_read: {
		cv::FileNode* node;
		if (ParamIndexToVal(0, node))
			_o_return_result;
		auto __retval = (__int64)mC->read(*node);
		return (void)(aResultToken.SetValue(__retval));
	}
	}
}

void DISOpticalFlow::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::DISOpticalFlow>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		int preset = cv::DISOpticalFlow::PRESET_FAST;
		if (aParamCount > 0 && aParam[0]->symbol != SYM_MISSING)
			TokenToVal(*aParam[0], preset);
		mC = cv::DISOpticalFlow::create(preset);
		return;
	}
	case M_getFinestScale: {
		auto __retval = (__int64)mC->getFinestScale();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getGradientDescentIterations: {
		auto __retval = (__int64)mC->getGradientDescentIterations();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getPatchSize: {
		auto __retval = (__int64)mC->getPatchSize();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getPatchStride: {
		auto __retval = (__int64)mC->getPatchStride();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getUseMeanNormalization: {
		auto __retval = (__int64)mC->getUseMeanNormalization();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getUseSpatialPropagation: {
		auto __retval = (__int64)mC->getUseSpatialPropagation();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getVariationalRefinementAlpha: {
		auto __retval = (double)mC->getVariationalRefinementAlpha();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getVariationalRefinementDelta: {
		auto __retval = (double)mC->getVariationalRefinementDelta();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getVariationalRefinementGamma: {
		auto __retval = (double)mC->getVariationalRefinementGamma();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getVariationalRefinementIterations: {
		auto __retval = (__int64)mC->getVariationalRefinementIterations();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_setFinestScale: {
		int val;
		if (ParamIndexToVal(0, val))
			_o_return_result;
		mC->setFinestScale(val);
		return;
	}
	case M_setGradientDescentIterations: {
		int val;
		if (ParamIndexToVal(0, val))
			_o_return_result;
		mC->setGradientDescentIterations(val);
		return;
	}
	case M_setPatchSize: {
		int val;
		if (ParamIndexToVal(0, val))
			_o_return_result;
		mC->setPatchSize(val);
		return;
	}
	case M_setPatchStride: {
		int val;
		if (ParamIndexToVal(0, val))
			_o_return_result;
		mC->setPatchStride(val);
		return;
	}
	case M_setUseMeanNormalization: {
		bool val;
		if (ParamIndexToVal(0, (char&)val))
			_o_return_result;
		mC->setUseMeanNormalization(val);
		return;
	}
	case M_setUseSpatialPropagation: {
		bool val;
		if (ParamIndexToVal(0, (char&)val))
			_o_return_result;
		mC->setUseSpatialPropagation(val);
		return;
	}
	case M_setVariationalRefinementAlpha: {
		float val;
		if (ParamIndexToVal(0, val))
			_o_return_result;
		mC->setVariationalRefinementAlpha(val);
		return;
	}
	case M_setVariationalRefinementDelta: {
		float val;
		if (ParamIndexToVal(0, val))
			_o_return_result;
		mC->setVariationalRefinementDelta(val);
		return;
	}
	case M_setVariationalRefinementGamma: {
		float val;
		if (ParamIndexToVal(0, val))
			_o_return_result;
		mC->setVariationalRefinementGamma(val);
		return;
	}
	case M_setVariationalRefinementIterations: {
		int val;
		if (ParamIndexToVal(0, val))
			_o_return_result;
		mC->setVariationalRefinementIterations(val);
		return;
	}
	}
}

void DMatch::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::DMatch>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		if (aParamCount == 0) {
			mC = new cv::DMatch();
			return;
		}
		else if (aParamCount == 3) {
			float _distance;
			int _queryIdx, _trainIdx;
			if (ParamIndexToVal(0, _queryIdx))
				_o_return_result;
			if (ParamIndexToVal(1, _trainIdx))
				_o_return_result;
			if (ParamIndexToVal(2, _distance))
				_o_return_result;
			mC = new cv::DMatch(_queryIdx, _trainIdx, _distance);
			return;
		}
		else if (aParamCount == 4) {
			float _distance;
			int _queryIdx, _trainIdx, _imgIdx;
			if (ParamIndexToVal(0, _queryIdx))
				_o_return_result;
			if (ParamIndexToVal(1, _trainIdx))
				_o_return_result;
			if (ParamIndexToVal(2, _imgIdx))
				_o_return_result;
			if (ParamIndexToVal(3, _distance))
				_o_return_result;
			mC = new cv::DMatch(_queryIdx, _trainIdx, _imgIdx, _distance);
			return;
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case P_trainIdx:
	case P_imgIdx:
	case P_queryIdx: {
		int& val = aID == P_queryIdx ? mC->queryIdx : aID == P_trainIdx ? mC->trainIdx : mC->imgIdx;
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, val))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue(val);
		}
	}
	case P_distance: {
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, mC->distance))
				_o_return_result;
			return;
		}
		else {
			return (void)aResultToken.SetValue((double)mC->distance);
		}
	}
	}
}

void DenseOpticalFlow::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M_calc: {
		cv::_InputArray I0, I1;
		cv::_InputOutputArray flow;
		if (ParamIndexToVal(0, I0))
			_o_return_result;
		if (ParamIndexToVal(1, I1))
			_o_return_result;
		if (ParamIndexToVal(2, flow))
			_o_return_result;
		mC->calc(I0, I1, flow);
		return;
	}
	case M_collectGarbage: {
		mC->collectGarbage();
		return;
	}
	}
}

void DescriptorMatcher::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::DescriptorMatcher>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		if (!MatchTypes("s")) {
			cv::String descriptorMatcherType;
			if (ParamIndexToVal(0, descriptorMatcherType))
				_o_return_result;
			mC = cv::DescriptorMatcher::create(descriptorMatcherType);
			return;
		}
		else if (!MatchTypes("o")) {
			int matcherType;
			if (ParamIndexToVal(0, matcherType))
				_o_return_result;
			mC = cv::DescriptorMatcher::create((cv::DescriptorMatcher::MatcherType)matcherType);
			return;
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case M_add: {
		cv::_InputArray descriptors;
		if (ParamIndexToVal(0, descriptors))
			_o_return_result;
		mC->add(descriptors);
		return;
	}
	case M_clear: {
		mC->clear();
		return;
	}
	case M_clone: {
		bool emptyTrainData = false;
		if (aParamCount > 0 && aParam[0]->symbol != SYM_MISSING)
			TokenToVal(*aParam[0], (char&)emptyTrainData);
		auto __retval = (DescriptorMatcher*)DescriptorMatcher::sPrototype->New(g_invalidparam, 1);
		__retval->mC = mC->clone(emptyTrainData);
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_empty: {
		auto __retval = (__int64)mC->empty();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getTrainDescriptors: {
		auto __retval = mC->getTrainDescriptors();
		return ValToResult(__retval, aResultToken);
	}
	case M_isMaskSupported: {
		auto __retval = (__int64)mC->isMaskSupported();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_knnMatch: {
		if (!MatchTypes("oooio?i")) {
			bool compactResult = false;
			cv::_InputArray queryDescriptors, trainDescriptors, mask = cv::noArray();
			int k;
			std::vector<std::vector<cv::DMatch>> matches;
			if (ParamIndexToVal(0, queryDescriptors))
				_o_return_result;
			if (ParamIndexToVal(1, trainDescriptors))
				_o_return_result;
			VarRef* var_matches = nullptr;
			if (ParamIndexToVal(2, var_matches))
				_o_return_result;
			if (ParamIndexToVal(3, k))
				_o_return_result;
			if (aParamCount > 4 && aParam[4]->symbol != SYM_MISSING)
				TokenToVal(*aParam[4], mask);
			if (aParamCount > 5 && aParam[5]->symbol != SYM_MISSING)
				TokenToVal(*aParam[5], (char&)compactResult);
			mC->knnMatch(queryDescriptors, trainDescriptors, matches, k, mask, compactResult);
			ValToResult(matches, aResultToken);
			g_ahkapi->VarAssign(var_matches, aResultToken);
			g_ahkapi->ResultTokenFree(aResultToken);
			return;
		}
		else if (!MatchTypes("ooio?i")) {
			bool compactResult = false;
			cv::_InputArray queryDescriptors, masks = cv::noArray();
			int k;
			std::vector<std::vector<cv::DMatch>> matches;
			if (ParamIndexToVal(0, queryDescriptors))
				_o_return_result;
			VarRef* var_matches = nullptr;
			if (ParamIndexToVal(1, var_matches))
				_o_return_result;
			if (ParamIndexToVal(2, k))
				_o_return_result;
			if (aParamCount > 3 && aParam[3]->symbol != SYM_MISSING)
				TokenToVal(*aParam[3], masks);
			if (aParamCount > 4 && aParam[4]->symbol != SYM_MISSING)
				TokenToVal(*aParam[4], (char&)compactResult);
			mC->knnMatch(queryDescriptors, matches, k, masks, compactResult);
			ValToResult(matches, aResultToken);
			g_ahkapi->VarAssign(var_matches, aResultToken);
			g_ahkapi->ResultTokenFree(aResultToken);
			return;
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case M_match: {
		if (!MatchTypes("oooo?")) {
			cv::_InputArray queryDescriptors, trainDescriptors, mask = cv::noArray();
			std::vector<cv::DMatch> matches;
			if (ParamIndexToVal(0, queryDescriptors))
				_o_return_result;
			if (ParamIndexToVal(1, trainDescriptors))
				_o_return_result;
			VarRef* var_matches = nullptr;
			if (ParamIndexToVal(2, var_matches))
				_o_return_result;
			if (aParamCount > 3 && aParam[3]->symbol != SYM_MISSING)
				TokenToVal(*aParam[3], mask);
			mC->match(queryDescriptors, trainDescriptors, matches, mask);
			ValToResult(matches, aResultToken);
			g_ahkapi->VarAssign(var_matches, aResultToken);
			g_ahkapi->ResultTokenFree(aResultToken);
			return;
		}
		else if (!MatchTypes("ooo?")) {
			cv::_InputArray queryDescriptors, masks = cv::noArray();
			std::vector<cv::DMatch> matches;
			if (ParamIndexToVal(0, queryDescriptors))
				_o_return_result;
			VarRef* var_matches = nullptr;
			if (ParamIndexToVal(1, var_matches))
				_o_return_result;
			if (aParamCount > 2 && aParam[2]->symbol != SYM_MISSING)
				TokenToVal(*aParam[2], masks);
			mC->match(queryDescriptors, matches, masks);
			ValToResult(matches, aResultToken);
			g_ahkapi->VarAssign(var_matches, aResultToken);
			g_ahkapi->ResultTokenFree(aResultToken);
			return;
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case M_radiusMatch: {
		if (!MatchTypes("ooofo?i")) {
			bool compactResult = false;
			cv::_InputArray queryDescriptors, trainDescriptors, mask = cv::noArray();
			float maxDistance;
			std::vector<std::vector<cv::DMatch>> matches;
			if (ParamIndexToVal(0, queryDescriptors))
				_o_return_result;
			if (ParamIndexToVal(1, trainDescriptors))
				_o_return_result;
			VarRef* var_matches = nullptr;
			if (ParamIndexToVal(2, var_matches))
				_o_return_result;
			if (ParamIndexToVal(3, maxDistance))
				_o_return_result;
			if (aParamCount > 4 && aParam[4]->symbol != SYM_MISSING)
				TokenToVal(*aParam[4], mask);
			if (aParamCount > 5 && aParam[5]->symbol != SYM_MISSING)
				TokenToVal(*aParam[5], (char&)compactResult);
			mC->radiusMatch(queryDescriptors, trainDescriptors, matches, maxDistance, mask, compactResult);
			ValToResult(matches, aResultToken);
			g_ahkapi->VarAssign(var_matches, aResultToken);
			g_ahkapi->ResultTokenFree(aResultToken);
			return;
		}
		else if (!MatchTypes("oofo?i")) {
			bool compactResult = false;
			cv::_InputArray queryDescriptors, masks = cv::noArray();
			float maxDistance;
			std::vector<std::vector<cv::DMatch>> matches;
			if (ParamIndexToVal(0, queryDescriptors))
				_o_return_result;
			VarRef* var_matches = nullptr;
			if (ParamIndexToVal(1, var_matches))
				_o_return_result;
			if (ParamIndexToVal(2, maxDistance))
				_o_return_result;
			if (aParamCount > 3 && aParam[3]->symbol != SYM_MISSING)
				TokenToVal(*aParam[3], masks);
			if (aParamCount > 4 && aParam[4]->symbol != SYM_MISSING)
				TokenToVal(*aParam[4], (char&)compactResult);
			mC->radiusMatch(queryDescriptors, matches, maxDistance, masks, compactResult);
			ValToResult(matches, aResultToken);
			g_ahkapi->VarAssign(var_matches, aResultToken);
			g_ahkapi->ResultTokenFree(aResultToken);
			return;
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case M_read: {
		if (!MatchTypes("s")) {
			cv::String fileName;
			if (ParamIndexToVal(0, fileName))
				_o_return_result;
			mC->read(fileName);
			return;
		}
		else if (!MatchTypes("o")) {
			cv::FileNode* arg1;
			if (ParamIndexToVal(0, arg1))
				_o_return_result;
			mC->read(*arg1);
			return;
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case M_train: {
		mC->train();
		return;
	}
	case M_write: {
		if (!MatchTypes("s")) {
			cv::String fileName;
			if (ParamIndexToVal(0, fileName))
				_o_return_result;
			mC->write(fileName);
			return;
		}
		else if (!MatchTypes("os?")) {
			cv::Ptr<cv::FileStorage> fs;
			cv::String name = cv::String();
			if (ParamIndexToVal(0, fs))
				_o_return_result;
			if (aParamCount > 1 && aParam[1]->symbol != SYM_MISSING)
				TokenToVal(*aParam[1], name);
			mC->write(fs, name);
			return;
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	}
}

void FaceDetectorYN::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::FaceDetectorYN>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		cv::Size input_size;
		cv::String model, config;
		float score_threshold = 0.9f, nms_threshold = 0.3f;
		int top_k = 5000, backend_id = 0, target_id = 0;
		if (ParamIndexToVal(0, model))
			_o_return_result;
		if (ParamIndexToVal(1, config))
			_o_return_result;
		if (ParamIndexToVal(2, input_size))
			_o_return_result;
		if (aParamCount > 3 && aParam[3]->symbol != SYM_MISSING)
			TokenToVal(*aParam[3], score_threshold);
		if (aParamCount > 4 && aParam[4]->symbol != SYM_MISSING)
			TokenToVal(*aParam[4], nms_threshold);
		if (aParamCount > 5 && aParam[5]->symbol != SYM_MISSING)
			TokenToVal(*aParam[5], top_k);
		if (aParamCount > 6 && aParam[6]->symbol != SYM_MISSING)
			TokenToVal(*aParam[6], backend_id);
		if (aParamCount > 7 && aParam[7]->symbol != SYM_MISSING)
			TokenToVal(*aParam[7], target_id);
		mC = cv::FaceDetectorYN::create(model, config, input_size, score_threshold, nms_threshold, top_k, backend_id, target_id);
		return;
	}
	case M_detect: {
		cv::_InputArray image;
		cv::_OutputArray faces;
		if (ParamIndexToVal(0, image))
			_o_return_result;
		if (ParamIndexToVal(1, faces))
			_o_return_result;
		auto __retval = (__int64)mC->detect(image, faces);
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getInputSize: {
		auto __retval = mC->getInputSize();
		return ValToResult(__retval, aResultToken);
	}
	case M_getNMSThreshold: {
		auto __retval = (double)mC->getNMSThreshold();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getScoreThreshold: {
		auto __retval = (double)mC->getScoreThreshold();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getTopK: {
		auto __retval = (__int64)mC->getTopK();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_setInputSize: {
		cv::Size input_size;
		if (ParamIndexToVal(0, input_size))
			_o_return_result;
		mC->setInputSize(input_size);
		return;
	}
	case M_setNMSThreshold: {
		float nms_threshold;
		if (ParamIndexToVal(0, nms_threshold))
			_o_return_result;
		mC->setNMSThreshold(nms_threshold);
		return;
	}
	case M_setScoreThreshold: {
		float score_threshold;
		if (ParamIndexToVal(0, score_threshold))
			_o_return_result;
		mC->setScoreThreshold(score_threshold);
		return;
	}
	case M_setTopK: {
		int top_k;
		if (ParamIndexToVal(0, top_k))
			_o_return_result;
		mC->setTopK(top_k);
		return;
	}
	}
}

void FaceRecognizerSF::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::FaceRecognizerSF>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		cv::String model, config;
		int backend_id = 0, target_id = 0;
		if (ParamIndexToVal(0, model))
			_o_return_result;
		if (ParamIndexToVal(1, config))
			_o_return_result;
		if (aParamCount > 2 && aParam[2]->symbol != SYM_MISSING)
			TokenToVal(*aParam[2], backend_id);
		if (aParamCount > 3 && aParam[3]->symbol != SYM_MISSING)
			TokenToVal(*aParam[3], target_id);
		mC = cv::FaceRecognizerSF::create(model, config, backend_id, target_id);
		return;
	}
	case M_alignCrop: {
		cv::_InputArray src_img, face_box;
		cv::_OutputArray aligned_img;
		if (ParamIndexToVal(0, src_img))
			_o_return_result;
		if (ParamIndexToVal(1, face_box))
			_o_return_result;
		if (ParamIndexToVal(2, aligned_img))
			_o_return_result;
		mC->alignCrop(src_img, face_box, aligned_img);
		return;
	}
	case M_feature: {
		cv::_InputArray aligned_img;
		cv::_OutputArray face_feature;
		if (ParamIndexToVal(0, aligned_img))
			_o_return_result;
		if (ParamIndexToVal(1, face_feature))
			_o_return_result;
		mC->feature(aligned_img, face_feature);
		return;
	}
	case M_match: {
		cv::_InputArray _face_feature1, _face_feature2;
		int dis_type = cv::FaceRecognizerSF::FR_COSINE;
		if (ParamIndexToVal(0, _face_feature1))
			_o_return_result;
		if (ParamIndexToVal(1, _face_feature2))
			_o_return_result;
		if (aParamCount > 2 && aParam[2]->symbol != SYM_MISSING)
			TokenToVal(*aParam[2], dis_type);
		auto __retval = mC->match(_face_feature1, _face_feature2, dis_type);
		return (void)(aResultToken.SetValue(__retval));
	}
	}
}

void FarnebackOpticalFlow::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::FarnebackOpticalFlow>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		bool fastPyramids = false;
		double pyrScale = 0.5, polySigma = 1.1;
		int numLevels = 5, winSize = 13, numIters = 10, polyN = 5, flags = 0;
		if (aParamCount > 0 && aParam[0]->symbol != SYM_MISSING)
			TokenToVal(*aParam[0], numLevels);
		if (aParamCount > 1 && aParam[1]->symbol != SYM_MISSING)
			TokenToVal(*aParam[1], pyrScale);
		if (aParamCount > 2 && aParam[2]->symbol != SYM_MISSING)
			TokenToVal(*aParam[2], (char&)fastPyramids);
		if (aParamCount > 3 && aParam[3]->symbol != SYM_MISSING)
			TokenToVal(*aParam[3], winSize);
		if (aParamCount > 4 && aParam[4]->symbol != SYM_MISSING)
			TokenToVal(*aParam[4], numIters);
		if (aParamCount > 5 && aParam[5]->symbol != SYM_MISSING)
			TokenToVal(*aParam[5], polyN);
		if (aParamCount > 6 && aParam[6]->symbol != SYM_MISSING)
			TokenToVal(*aParam[6], polySigma);
		if (aParamCount > 7 && aParam[7]->symbol != SYM_MISSING)
			TokenToVal(*aParam[7], flags);
		mC = cv::FarnebackOpticalFlow::create(numLevels, pyrScale, fastPyramids, winSize, numIters, polyN, polySigma, flags);
		return;
	}
	case M_getFastPyramids: {
		auto __retval = (__int64)mC->getFastPyramids();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getFlags: {
		auto __retval = (__int64)mC->getFlags();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getNumIters: {
		auto __retval = (__int64)mC->getNumIters();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getNumLevels: {
		auto __retval = (__int64)mC->getNumLevels();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getPolyN: {
		auto __retval = (__int64)mC->getPolyN();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getPolySigma: {
		auto __retval = mC->getPolySigma();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getPyrScale: {
		auto __retval = mC->getPyrScale();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getWinSize: {
		auto __retval = (__int64)mC->getWinSize();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_setFastPyramids: {
		bool fastPyramids;
		if (ParamIndexToVal(0, (char&)fastPyramids))
			_o_return_result;
		mC->setFastPyramids(fastPyramids);
		return;
	}
	case M_setFlags: {
		int flags;
		if (ParamIndexToVal(0, flags))
			_o_return_result;
		mC->setFlags(flags);
		return;
	}
	case M_setNumIters: {
		int numIters;
		if (ParamIndexToVal(0, numIters))
			_o_return_result;
		mC->setNumIters(numIters);
		return;
	}
	case M_setNumLevels: {
		int numLevels;
		if (ParamIndexToVal(0, numLevels))
			_o_return_result;
		mC->setNumLevels(numLevels);
		return;
	}
	case M_setPolyN: {
		int polyN;
		if (ParamIndexToVal(0, polyN))
			_o_return_result;
		mC->setPolyN(polyN);
		return;
	}
	case M_setPolySigma: {
		double polySigma;
		if (ParamIndexToVal(0, polySigma))
			_o_return_result;
		mC->setPolySigma(polySigma);
		return;
	}
	case M_setPyrScale: {
		double pyrScale;
		if (ParamIndexToVal(0, pyrScale))
			_o_return_result;
		mC->setPyrScale(pyrScale);
		return;
	}
	case M_setWinSize: {
		int winSize;
		if (ParamIndexToVal(0, winSize))
			_o_return_result;
		mC->setWinSize(winSize);
		return;
	}
	}
}

void FastFeatureDetector::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::FastFeatureDetector>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		bool nonmaxSuppression = true;
		int threshold = 10, type = cv::FastFeatureDetector::TYPE_9_16;
		if (aParamCount > 0 && aParam[0]->symbol != SYM_MISSING)
			TokenToVal(*aParam[0], threshold);
		if (aParamCount > 1 && aParam[1]->symbol != SYM_MISSING)
			TokenToVal(*aParam[1], (char&)nonmaxSuppression);
		if (aParamCount > 2 && aParam[2]->symbol != SYM_MISSING)
			TokenToVal(*aParam[2], type);
		mC = cv::FastFeatureDetector::create(threshold, nonmaxSuppression, (cv::FastFeatureDetector::DetectorType)type);
		return;
	}
	case M_getDefaultName: {
		auto __retval = mC->getDefaultName();
		return ValToResult(__retval, aResultToken);
	}
	case M_getNonmaxSuppression: {
		auto __retval = (__int64)mC->getNonmaxSuppression();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getThreshold: {
		auto __retval = (__int64)mC->getThreshold();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getType: {
		auto __retval = mC->getType();
		return ValToResult(__retval, aResultToken);
	}
	case M_setNonmaxSuppression: {
		bool f;
		if (ParamIndexToVal(0, (char&)f))
			_o_return_result;
		mC->setNonmaxSuppression(f);
		return;
	}
	case M_setThreshold: {
		int threshold;
		if (ParamIndexToVal(0, threshold))
			_o_return_result;
		mC->setThreshold(threshold);
		return;
	}
	case M_setType: {
		int type;
		if (ParamIndexToVal(0, type))
			_o_return_result;
		mC->setType((cv::FastFeatureDetector::DetectorType)type);
		return;
	}
	}
}

void Feature2D::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::Feature2D>;
		mC = new cv::Feature2D;
		return;
	}
	case M_compute: {
		cv::_InputArray image;
		cv::_OutputArray descriptors;
		std::vector<cv::KeyPoint> keypoints;
		if (ParamIndexToVal(0, image))
			_o_return_result;
		VarRef* var_keypoints = nullptr;
		if (ParamIndexToVal(1, var_keypoints))
			_o_return_result;
		if (TokenToVal(VarRefToToken(var_keypoints), keypoints) != CONDITION_TRUE)
			_o_return_result;
		if (ParamIndexToVal(2, descriptors))
			_o_return_result;
		mC->compute(image, keypoints, descriptors);
		ValToResult(keypoints, aResultToken);
		g_ahkapi->VarAssign(var_keypoints, aResultToken);
		g_ahkapi->ResultTokenFree(aResultToken);
		return;
	}
	case M_defaultNorm: {
		auto __retval = (__int64)mC->defaultNorm();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_descriptorSize: {
		auto __retval = (__int64)mC->descriptorSize();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_descriptorType: {
		auto __retval = (__int64)mC->descriptorType();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_detect: {
		cv::_InputArray image, mask = cv::noArray();
		std::vector<cv::KeyPoint> keypoints;
		if (ParamIndexToVal(0, image))
			_o_return_result;
		VarRef* var_keypoints = nullptr;
		if (ParamIndexToVal(1, var_keypoints))
			_o_return_result;
		if (aParamCount > 2 && aParam[2]->symbol != SYM_MISSING)
			TokenToVal(*aParam[2], mask);
		mC->detect(image, keypoints, mask);
		ValToResult(keypoints, aResultToken);
		g_ahkapi->VarAssign(var_keypoints, aResultToken);
		g_ahkapi->ResultTokenFree(aResultToken);
		return;
	}
	case M_detectAndCompute: {
		bool useProvidedKeypoints = false;
		cv::_InputArray image, mask;
		cv::_OutputArray descriptors;
		std::vector<cv::KeyPoint> keypoints;
		if (ParamIndexToVal(0, image))
			_o_return_result;
		if (ParamIndexToVal(1, mask))
			_o_return_result;
		VarRef* var_keypoints = nullptr;
		if (ParamIndexToVal(2, var_keypoints))
			_o_return_result;
		if (ParamIndexToVal(3, descriptors))
			_o_return_result;
		if (aParamCount > 4 && aParam[4]->symbol != SYM_MISSING)
			TokenToVal(*aParam[4], (char&)useProvidedKeypoints);
		mC->detectAndCompute(image, mask, keypoints, descriptors, useProvidedKeypoints);
		ValToResult(keypoints, aResultToken);
		g_ahkapi->VarAssign(var_keypoints, aResultToken);
		g_ahkapi->ResultTokenFree(aResultToken);
		return;
	}
	case M_empty: {
		auto __retval = (__int64)mC->empty();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getDefaultName: {
		auto __retval = mC->getDefaultName();
		return ValToResult(__retval, aResultToken);
	}
	case M_read: {
		if (!MatchTypes("s")) {
			cv::String fileName;
			if (ParamIndexToVal(0, fileName))
				_o_return_result;
			mC->read(fileName);
			return;
		}
		else if (!MatchTypes("o")) {
			cv::FileNode* arg1;
			if (ParamIndexToVal(0, arg1))
				_o_return_result;
			mC->read(*arg1);
			return;
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case M_write: {
		if (!MatchTypes("s")) {
			cv::String fileName;
			if (ParamIndexToVal(0, fileName))
				_o_return_result;
			mC->write(fileName);
			return;
		}
		else if (!MatchTypes("os?")) {
			cv::Ptr<cv::FileStorage> fs;
			cv::String name = cv::String();
			if (ParamIndexToVal(0, fs))
				_o_return_result;
			if (aParamCount > 1 && aParam[1]->symbol != SYM_MISSING)
				TokenToVal(*aParam[1], name);
			mC->write(fs, name);
			return;
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	}
}

void FileNode::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::FileNode>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		mC = new cv::FileNode();
		return;
	}
	case M_empty: {
		auto __retval = (__int64)mC->empty();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_isInt: {
		auto __retval = (__int64)mC->isInt();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_isMap: {
		auto __retval = (__int64)mC->isMap();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_isNamed: {
		auto __retval = (__int64)mC->isNamed();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_isNone: {
		auto __retval = (__int64)mC->isNone();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_isReal: {
		auto __retval = (__int64)mC->isReal();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_isSeq: {
		auto __retval = (__int64)mC->isSeq();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_isString: {
		auto __retval = (__int64)mC->isString();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_keys: {
		auto __retval = mC->keys();
		return ValToResult(__retval, aResultToken);
	}
	case M_mat: {
		auto __retval = (Mat*)Mat::sPrototype->New(g_invalidparam, 1);
		__retval->mC = mC->mat();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_name: {
		auto __retval = mC->name();
		return ValToResult(__retval, aResultToken);
	}
	case P___Item: {
		if (!MatchTypes("s")) {
			cv::String nodename;
			if (ParamIndexToVal(0, nodename))
				_o_return_result;
			auto __retval = (FileNode*)FileNode::sPrototype->New(g_invalidparam, 1);
			__retval->mC = cv::makePtr<cv::FileNode>((*mC)[nodename]);
			return (void)(aResultToken.SetValue(__retval));
		}
		else if (!MatchTypes("i")) {
			int i;
			if (ParamIndexToVal(0, i))
				_o_return_result;
			auto __retval = (FileNode*)FileNode::sPrototype->New(g_invalidparam, 1);
			__retval->mC = cv::makePtr<cv::FileNode>((*mC)[i]);
			return (void)(aResultToken.SetValue(__retval));
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case M_rawSize: {
		auto __retval = (__int64)mC->rawSize();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_real: {
		auto __retval = mC->real();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_size: {
		auto __retval = (__int64)mC->size();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_string: {
		auto __retval = mC->string();
		return ValToResult(__retval, aResultToken);
	}
	case M_type: {
		auto __retval = (__int64)mC->type();
		return (void)(aResultToken.SetValue(__retval));
	}
	}
}

void FileStorage::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::FileStorage>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		if (aParamCount == 0) {
			mC = new cv::FileStorage();
			return;
		}
		else if (2 <= aParamCount && aParamCount <= 3) {
			cv::String filename, encoding = cv::String();
			int flags;
			if (ParamIndexToVal(0, filename))
				_o_return_result;
			if (ParamIndexToVal(1, flags))
				_o_return_result;
			if (aParamCount > 2 && aParam[2]->symbol != SYM_MISSING)
				TokenToVal(*aParam[2], encoding);
			mC = new cv::FileStorage(filename, flags, encoding);
			return;
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case M_endWriteStruct: {
		mC->endWriteStruct();
		return;
	}
	case M_getFirstTopLevelNode: {
		auto __retval = (FileNode*)FileNode::sPrototype->New(g_invalidparam, 1);
		__retval->mC = cv::makePtr<cv::FileNode>(mC->getFirstTopLevelNode());
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getFormat: {
		auto __retval = (__int64)mC->getFormat();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_isOpened: {
		auto __retval = (__int64)mC->isOpened();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_open: {
		cv::String filename, encoding = cv::String();
		int flags;
		if (ParamIndexToVal(0, filename))
			_o_return_result;
		if (ParamIndexToVal(1, flags))
			_o_return_result;
		if (aParamCount > 2 && aParam[2]->symbol != SYM_MISSING)
			TokenToVal(*aParam[2], encoding);
		auto __retval = (__int64)mC->open(filename, flags, encoding);
		return (void)(aResultToken.SetValue(__retval));
	}
	case P___Item: {
		cv::String nodename;
		if (ParamIndexToVal(0, nodename))
			_o_return_result;
		auto __retval = (FileNode*)FileNode::sPrototype->New(g_invalidparam, 1);
		__retval->mC = cv::makePtr<cv::FileNode>((*mC)[nodename]);
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_release: {
		mC->release();
		return;
	}
	case M_releaseAndGetString: {
		auto __retval = mC->releaseAndGetString();
		return ValToResult(__retval, aResultToken);
	}
	case M_root: {
		int streamidx = 0;
		if (aParamCount > 0 && aParam[0]->symbol != SYM_MISSING)
			TokenToVal(*aParam[0], streamidx);
		auto __retval = (FileNode*)FileNode::sPrototype->New(g_invalidparam, 1);
		__retval->mC = cv::makePtr<cv::FileNode>(mC->root(streamidx));
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_startWriteStruct: {
		cv::String name, typeName = cv::String();
		int flags;
		if (ParamIndexToVal(0, name))
			_o_return_result;
		if (ParamIndexToVal(1, flags))
			_o_return_result;
		if (aParamCount > 2 && aParam[2]->symbol != SYM_MISSING)
			TokenToVal(*aParam[2], typeName);
		mC->startWriteStruct(name, flags, typeName);
		return;
	}
	case M_write: {
		if (!MatchTypes("si")) {
			cv::String name;
			int val;
			if (ParamIndexToVal(0, name))
				_o_return_result;
			if (ParamIndexToVal(1, val))
				_o_return_result;
			mC->write(name, val);
			return;
		}
		else if (!MatchTypes("sf")) {
			cv::String name;
			double val;
			if (ParamIndexToVal(0, name))
				_o_return_result;
			if (ParamIndexToVal(1, val))
				_o_return_result;
			mC->write(name, val);
			return;
		}
		else if (!MatchTypes("ss")) {
			cv::String name, val;
			if (ParamIndexToVal(0, name))
				_o_return_result;
			if (ParamIndexToVal(1, val))
				_o_return_result;
			mC->write(name, val);
			return;
		}
		else if (!MatchTypes("so")) {
			cv::Mat val;
			std::vector<cv::String> val2;
			cv::String name;
			if (ParamIndexToVal(0, name))
				_o_return_result;
			auto obj = TokenToObject(*aParam[1]);
			if (dynamic_cast<Array*>(obj)) {
				if (ParamIndexToVal(1, val2))
					_o_return_result;
				mC->write(name, val2);
			}
			else {
				if (ParamIndexToVal(1, val))
					_o_return_result;
				mC->write(name, val);
			}
			return;
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case M_writeComment: {
		bool append = false;
		cv::String comment;
		if (ParamIndexToVal(0, comment))
			_o_return_result;
		if (aParamCount > 1 && aParam[1]->symbol != SYM_MISSING)
			TokenToVal(*aParam[1], (char&)append);
		mC->writeComment(comment, append);
		return;
	}
	}
}

void FlannBasedMatcher::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::FlannBasedMatcher>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		mC = cv::FlannBasedMatcher::create();
		return;
	}
	}
}

void GFTTDetector::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::GFTTDetector>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		if (0 <= aParamCount && aParamCount <= 6) {
			bool useHarrisDetector = false;
			double qualityLevel = 0.01, minDistance = 1, k = 0.04;
			int maxCorners = 1000, blockSize = 3;
			if (aParamCount > 0 && aParam[0]->symbol != SYM_MISSING)
				TokenToVal(*aParam[0], maxCorners);
			if (aParamCount > 1 && aParam[1]->symbol != SYM_MISSING)
				TokenToVal(*aParam[1], qualityLevel);
			if (aParamCount > 2 && aParam[2]->symbol != SYM_MISSING)
				TokenToVal(*aParam[2], minDistance);
			if (aParamCount > 3 && aParam[3]->symbol != SYM_MISSING)
				TokenToVal(*aParam[3], blockSize);
			if (aParamCount > 4 && aParam[4]->symbol != SYM_MISSING)
				TokenToVal(*aParam[4], (char&)useHarrisDetector);
			if (aParamCount > 5 && aParam[5]->symbol != SYM_MISSING)
				TokenToVal(*aParam[5], k);
			mC = cv::GFTTDetector::create(maxCorners, qualityLevel, minDistance, blockSize, useHarrisDetector, k);
			return;
		}
		else if (5 <= aParamCount && aParamCount <= 7) {
			bool useHarrisDetector = false;
			double qualityLevel, minDistance, k = 0.04;
			int maxCorners, blockSize, gradiantSize;
			if (ParamIndexToVal(0, maxCorners))
				_o_return_result;
			if (ParamIndexToVal(1, qualityLevel))
				_o_return_result;
			if (ParamIndexToVal(2, minDistance))
				_o_return_result;
			if (ParamIndexToVal(3, blockSize))
				_o_return_result;
			if (ParamIndexToVal(4, gradiantSize))
				_o_return_result;
			if (aParamCount > 5 && aParam[5]->symbol != SYM_MISSING)
				TokenToVal(*aParam[5], (char&)useHarrisDetector);
			if (aParamCount > 6 && aParam[6]->symbol != SYM_MISSING)
				TokenToVal(*aParam[6], k);
			mC = cv::GFTTDetector::create(maxCorners, qualityLevel, minDistance, blockSize, gradiantSize, useHarrisDetector, k);
			return;
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case M_getBlockSize: {
		auto __retval = (__int64)mC->getBlockSize();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getDefaultName: {
		auto __retval = mC->getDefaultName();
		return ValToResult(__retval, aResultToken);
	}
	case M_getHarrisDetector: {
		auto __retval = (__int64)mC->getHarrisDetector();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getK: {
		auto __retval = mC->getK();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getMaxFeatures: {
		auto __retval = (__int64)mC->getMaxFeatures();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getMinDistance: {
		auto __retval = mC->getMinDistance();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getQualityLevel: {
		auto __retval = mC->getQualityLevel();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_setBlockSize: {
		int blockSize;
		if (ParamIndexToVal(0, blockSize))
			_o_return_result;
		mC->setBlockSize(blockSize);
		return;
	}
	case M_setHarrisDetector: {
		bool val;
		if (ParamIndexToVal(0, (char&)val))
			_o_return_result;
		mC->setHarrisDetector(val);
		return;
	}
	case M_setK: {
		double k;
		if (ParamIndexToVal(0, k))
			_o_return_result;
		mC->setK(k);
		return;
	}
	case M_setMaxFeatures: {
		int maxFeatures;
		if (ParamIndexToVal(0, maxFeatures))
			_o_return_result;
		mC->setMaxFeatures(maxFeatures);
		return;
	}
	case M_setMinDistance: {
		double minDistance;
		if (ParamIndexToVal(0, minDistance))
			_o_return_result;
		mC->setMinDistance(minDistance);
		return;
	}
	case M_setQualityLevel: {
		double qlevel;
		if (ParamIndexToVal(0, qlevel))
			_o_return_result;
		mC->setQualityLevel(qlevel);
		return;
	}
	}
}

#ifdef HAS_GAPI
void GFrame::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::GFrame>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		mC = new cv::GFrame();
		return;
	}
	}
}

void GMat::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::GMat>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		mC = new cv::GMat();
		return;
	}
	}
}

void GScalar::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::GScalar>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		mC = new cv::GScalar();
		return;
	}
	}
}

void GStreamingCompiled::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::GStreamingCompiled>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		mC = new cv::GStreamingCompiled();
		return;
	}
	case M_running: {
		auto __retval = (__int64)mC->running();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_start: {
		mC->start();
		return;
	}
	case M_stop: {
		mC->stop();
		return;
	}
	}
}
#endif

void GeneralizedHough::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M_detect: {
		if (2 <= aParamCount && aParamCount <= 3) {
			cv::_InputArray image;
			cv::_OutputArray positions, votes = cv::noArray();
			if (ParamIndexToVal(0, image))
				_o_return_result;
			if (ParamIndexToVal(1, positions))
				_o_return_result;
			if (aParamCount > 2 && aParam[2]->symbol != SYM_MISSING)
				TokenToVal(*aParam[2], votes);
			mC->detect(image, positions, votes);
			return;
		}
		else if (4 <= aParamCount && aParamCount <= 5) {
			cv::_InputArray edges, dx, dy;
			cv::_OutputArray positions, votes = cv::noArray();
			if (ParamIndexToVal(0, edges))
				_o_return_result;
			if (ParamIndexToVal(1, dx))
				_o_return_result;
			if (ParamIndexToVal(2, dy))
				_o_return_result;
			if (ParamIndexToVal(3, positions))
				_o_return_result;
			if (aParamCount > 4 && aParam[4]->symbol != SYM_MISSING)
				TokenToVal(*aParam[4], votes);
			mC->detect(edges, dx, dy, positions, votes);
			return;
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case M_getCannyHighThresh: {
		auto __retval = (__int64)mC->getCannyHighThresh();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getCannyLowThresh: {
		auto __retval = (__int64)mC->getCannyLowThresh();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getDp: {
		auto __retval = mC->getDp();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getMaxBufferSize: {
		auto __retval = (__int64)mC->getMaxBufferSize();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getMinDist: {
		auto __retval = mC->getMinDist();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_setCannyHighThresh: {
		int cannyHighThresh;
		if (ParamIndexToVal(0, cannyHighThresh))
			_o_return_result;
		mC->setCannyHighThresh(cannyHighThresh);
		return;
	}
	case M_setCannyLowThresh: {
		int cannyLowThresh;
		if (ParamIndexToVal(0, cannyLowThresh))
			_o_return_result;
		mC->setCannyLowThresh(cannyLowThresh);
		return;
	}
	case M_setDp: {
		double dp;
		if (ParamIndexToVal(0, dp))
			_o_return_result;
		mC->setDp(dp);
		return;
	}
	case M_setMaxBufferSize: {
		int maxBufferSize;
		if (ParamIndexToVal(0, maxBufferSize))
			_o_return_result;
		mC->setMaxBufferSize(maxBufferSize);
		return;
	}
	case M_setMinDist: {
		double minDist;
		if (ParamIndexToVal(0, minDist))
			_o_return_result;
		mC->setMinDist(minDist);
		return;
	}
	case M_setTemplate: {
		if (1 <= aParamCount && aParamCount <= 2) {
			cv::_InputArray templ;
			cv::Point templCenter = cv::Point(-1, -1);
			if (ParamIndexToVal(0, templ))
				_o_return_result;
			if (aParamCount > 1 && aParam[1]->symbol != SYM_MISSING)
				TokenToVal(*aParam[1], templCenter);
			mC->setTemplate(templ, templCenter);
			return;
		}
		else if (3 <= aParamCount && aParamCount <= 4) {
			cv::_InputArray edges, dx, dy;
			cv::Point templCenter = cv::Point(-1, -1);
			if (ParamIndexToVal(0, edges))
				_o_return_result;
			if (ParamIndexToVal(1, dx))
				_o_return_result;
			if (ParamIndexToVal(2, dy))
				_o_return_result;
			if (aParamCount > 3 && aParam[3]->symbol != SYM_MISSING)
				TokenToVal(*aParam[3], templCenter);
			mC->setTemplate(edges, dx, dy, templCenter);
			return;
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	}
}

void GeneralizedHoughBallard::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::GeneralizedHoughBallard>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		else _o_invalid_param;
		return;
	}
	case M_getLevels: {
		auto __retval = (__int64)mC->getLevels();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getVotesThreshold: {
		auto __retval = (__int64)mC->getVotesThreshold();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_setLevels: {
		int levels;
		if (ParamIndexToVal(0, levels))
			_o_return_result;
		mC->setLevels(levels);
		return;
	}
	case M_setVotesThreshold: {
		int votesThreshold;
		if (ParamIndexToVal(0, votesThreshold))
			_o_return_result;
		mC->setVotesThreshold(votesThreshold);
		return;
	}
	}
}

void GeneralizedHoughGuil::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::GeneralizedHoughGuil>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		else _o_invalid_param;
		return;
	}
	case M_getAngleEpsilon: {
		auto __retval = mC->getAngleEpsilon();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getAngleStep: {
		auto __retval = mC->getAngleStep();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getAngleThresh: {
		auto __retval = (__int64)mC->getAngleThresh();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getLevels: {
		auto __retval = (__int64)mC->getLevels();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getMaxAngle: {
		auto __retval = mC->getMaxAngle();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getMaxScale: {
		auto __retval = mC->getMaxScale();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getMinAngle: {
		auto __retval = mC->getMinAngle();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getMinScale: {
		auto __retval = mC->getMinScale();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getPosThresh: {
		auto __retval = (__int64)mC->getPosThresh();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getScaleStep: {
		auto __retval = mC->getScaleStep();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getScaleThresh: {
		auto __retval = (__int64)mC->getScaleThresh();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getXi: {
		auto __retval = mC->getXi();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_setAngleEpsilon: {
		double angleEpsilon;
		if (ParamIndexToVal(0, angleEpsilon))
			_o_return_result;
		mC->setAngleEpsilon(angleEpsilon);
		return;
	}
	case M_setAngleStep: {
		double angleStep;
		if (ParamIndexToVal(0, angleStep))
			_o_return_result;
		mC->setAngleStep(angleStep);
		return;
	}
	case M_setAngleThresh: {
		int angleThresh;
		if (ParamIndexToVal(0, angleThresh))
			_o_return_result;
		mC->setAngleThresh(angleThresh);
		return;
	}
	case M_setLevels: {
		int levels;
		if (ParamIndexToVal(0, levels))
			_o_return_result;
		mC->setLevels(levels);
		return;
	}
	case M_setMaxAngle: {
		double maxAngle;
		if (ParamIndexToVal(0, maxAngle))
			_o_return_result;
		mC->setMaxAngle(maxAngle);
		return;
	}
	case M_setMaxScale: {
		double maxScale;
		if (ParamIndexToVal(0, maxScale))
			_o_return_result;
		mC->setMaxScale(maxScale);
		return;
	}
	case M_setMinAngle: {
		double minAngle;
		if (ParamIndexToVal(0, minAngle))
			_o_return_result;
		mC->setMinAngle(minAngle);
		return;
	}
	case M_setMinScale: {
		double minScale;
		if (ParamIndexToVal(0, minScale))
			_o_return_result;
		mC->setMinScale(minScale);
		return;
	}
	case M_setPosThresh: {
		int posThresh;
		if (ParamIndexToVal(0, posThresh))
			_o_return_result;
		mC->setPosThresh(posThresh);
		return;
	}
	case M_setScaleStep: {
		double scaleStep;
		if (ParamIndexToVal(0, scaleStep))
			_o_return_result;
		mC->setScaleStep(scaleStep);
		return;
	}
	case M_setScaleThresh: {
		int scaleThresh;
		if (ParamIndexToVal(0, scaleThresh))
			_o_return_result;
		mC->setScaleThresh(scaleThresh);
		return;
	}
	case M_setXi: {
		double xi;
		if (ParamIndexToVal(0, xi))
			_o_return_result;
		mC->setXi(xi);
		return;
	}
	}
}

void KAZE::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::KAZE>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		bool extended = false, upright = false;
		float threshold = 0.001f;
		int nOctaves = 4, nOctaveLayers = 4, diffusivity = cv::KAZE::DIFF_PM_G2;
		if (aParamCount > 0 && aParam[0]->symbol != SYM_MISSING)
			TokenToVal(*aParam[0], (char&)extended);
		if (aParamCount > 1 && aParam[1]->symbol != SYM_MISSING)
			TokenToVal(*aParam[1], (char&)upright);
		if (aParamCount > 2 && aParam[2]->symbol != SYM_MISSING)
			TokenToVal(*aParam[2], threshold);
		if (aParamCount > 3 && aParam[3]->symbol != SYM_MISSING)
			TokenToVal(*aParam[3], nOctaves);
		if (aParamCount > 4 && aParam[4]->symbol != SYM_MISSING)
			TokenToVal(*aParam[4], nOctaveLayers);
		if (aParamCount > 5 && aParam[5]->symbol != SYM_MISSING)
			TokenToVal(*aParam[5], diffusivity);
		mC = cv::KAZE::create(extended, upright, threshold, nOctaves, nOctaveLayers, (cv::KAZE::DiffusivityType)diffusivity);
		return;
	}
	case M_getDefaultName: {
		auto __retval = mC->getDefaultName();
		return ValToResult(__retval, aResultToken);
	}
	case M_getDiffusivity: {
		auto __retval = mC->getDiffusivity();
		return ValToResult(__retval, aResultToken);
	}
	case M_getExtended: {
		auto __retval = (__int64)mC->getExtended();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getNOctaveLayers: {
		auto __retval = (__int64)mC->getNOctaveLayers();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getNOctaves: {
		auto __retval = (__int64)mC->getNOctaves();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getThreshold: {
		auto __retval = mC->getThreshold();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getUpright: {
		auto __retval = (__int64)mC->getUpright();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_setDiffusivity: {
		int diff;
		if (ParamIndexToVal(0, diff))
			_o_return_result;
		mC->setDiffusivity((cv::KAZE::DiffusivityType)diff);
		return;
	}
	case M_setExtended: {
		bool extended;
		if (ParamIndexToVal(0, (char&)extended))
			_o_return_result;
		mC->setExtended(extended);
		return;
	}
	case M_setNOctaveLayers: {
		int octaveLayers;
		if (ParamIndexToVal(0, octaveLayers))
			_o_return_result;
		mC->setNOctaveLayers(octaveLayers);
		return;
	}
	case M_setNOctaves: {
		int octaves;
		if (ParamIndexToVal(0, octaves))
			_o_return_result;
		mC->setNOctaves(octaves);
		return;
	}
	case M_setThreshold: {
		double threshold;
		if (ParamIndexToVal(0, threshold))
			_o_return_result;
		mC->setThreshold(threshold);
		return;
	}
	case M_setUpright: {
		bool upright;
		if (ParamIndexToVal(0, (char&)upright))
			_o_return_result;
		mC->setUpright(upright);
		return;
	}
	}
}

void KalmanFilter::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::KalmanFilter>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		if (aParamCount == 0) {
			mC = new cv::KalmanFilter();
			return;
		}
		else if (2 <= aParamCount && aParamCount <= 4) {
			int dynamParams, measureParams, controlParams = 0, type = CV_32F;
			if (ParamIndexToVal(0, dynamParams))
				_o_return_result;
			if (ParamIndexToVal(1, measureParams))
				_o_return_result;
			if (aParamCount > 2 && aParam[2]->symbol != SYM_MISSING)
				TokenToVal(*aParam[2], controlParams);
			if (aParamCount > 3 && aParam[3]->symbol != SYM_MISSING)
				TokenToVal(*aParam[3], type);
			mC = new cv::KalmanFilter(dynamParams, measureParams, controlParams, type);
			return;
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case M_correct: {
		cv::Mat measurement;
		if (ParamIndexToVal(0, measurement))
			_o_return_result;
		auto __retval = (Mat*)Mat::sPrototype->New(g_invalidparam, 1);
		__retval->mC = mC->correct(measurement);
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_predict: {
		cv::Mat control = cv::Mat();
		if (aParamCount > 0 && aParam[0]->symbol != SYM_MISSING)
			TokenToVal(*aParam[0], control);
		auto __retval = (Mat*)Mat::sPrototype->New(g_invalidparam, 1);
		__retval->mC = mC->predict(control);
		return (void)(aResultToken.SetValue(__retval));
	}
	}
}

void KeyPoint::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::KeyPoint>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		if (aParamCount == 0) {
			mC = new cv::KeyPoint();
			return;
		}
		else if (3 <= aParamCount && aParamCount <= 7) {
			float x, y, size, angle = -1, response = 0;
			int octave = 0, class_id = -1;
			if (ParamIndexToVal(0, x))
				_o_return_result;
			if (ParamIndexToVal(1, y))
				_o_return_result;
			if (ParamIndexToVal(2, size))
				_o_return_result;
			if (aParamCount > 3 && aParam[3]->symbol != SYM_MISSING)
				TokenToVal(*aParam[3], angle);
			if (aParamCount > 4 && aParam[4]->symbol != SYM_MISSING)
				TokenToVal(*aParam[4], response);
			if (aParamCount > 5 && aParam[5]->symbol != SYM_MISSING)
				TokenToVal(*aParam[5], octave);
			if (aParamCount > 6 && aParam[6]->symbol != SYM_MISSING)
				TokenToVal(*aParam[6], class_id);
			mC = new cv::KeyPoint(x, y, size, angle, response, octave, class_id);
			return;
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case M_convert: {
		if (!MatchTypes("ooo?")) {
			std::vector<cv::KeyPoint> keypoints;
			std::vector<cv::Point2f> points2f;
			std::vector<int> keypointIndexes = std::vector<int>();
			if (ParamIndexToVal(0, keypoints))
				_o_return_result;
			VarRef* var_points2f = nullptr;
			if (ParamIndexToVal(1, var_points2f))
				_o_return_result;
			if (aParamCount > 2 && aParam[2]->symbol != SYM_MISSING)
				TokenToVal(*aParam[2], keypointIndexes);
			mC->convert(keypoints, points2f, keypointIndexes);
			ValToResult(points2f, aResultToken);
			g_ahkapi->VarAssign(var_points2f, aResultToken);
			g_ahkapi->ResultTokenFree(aResultToken);
			return;
		}
		else if (!MatchTypes("oof?fii")) {
			float size = 1, response = 1;
			int octave = 0, class_id = -1;
			std::vector<cv::KeyPoint> keypoints;
			std::vector<cv::Point2f> points2f;
			if (ParamIndexToVal(0, points2f))
				_o_return_result;
			VarRef* var_keypoints = nullptr;
			if (ParamIndexToVal(1, var_keypoints))
				_o_return_result;
			if (aParamCount > 2 && aParam[2]->symbol != SYM_MISSING)
				TokenToVal(*aParam[2], size);
			if (aParamCount > 3 && aParam[3]->symbol != SYM_MISSING)
				TokenToVal(*aParam[3], response);
			if (aParamCount > 4 && aParam[4]->symbol != SYM_MISSING)
				TokenToVal(*aParam[4], octave);
			if (aParamCount > 5 && aParam[5]->symbol != SYM_MISSING)
				TokenToVal(*aParam[5], class_id);
			mC->convert(points2f, keypoints, size, response, octave, class_id);
			ValToResult(keypoints, aResultToken);
			g_ahkapi->VarAssign(var_keypoints, aResultToken);
			g_ahkapi->ResultTokenFree(aResultToken);
			return;
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case M_overlap: {
		cv::KeyPoint* kp1, * kp2;
		if (ParamIndexToVal(0, kp1))
			_o_return_result;
		if (ParamIndexToVal(1, kp2))
			_o_return_result;
		auto __retval = (double)mC->overlap(*kp1, *kp2);
		return (void)(aResultToken.SetValue(__retval));
	}
	}
}

void LineSegmentDetector::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::LineSegmentDetector>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		else _o_invalid_param;
		return;
	}
	case M_compareSegments: {
		cv::_InputArray lines1, lines2;
		cv::_InputOutputArray image = cv::noArray();
		cv::Size size;
		if (ParamIndexToVal(0, size))
			_o_return_result;
		if (ParamIndexToVal(1, lines1))
			_o_return_result;
		if (ParamIndexToVal(2, lines2))
			_o_return_result;
		if (aParamCount > 3 && aParam[3]->symbol != SYM_MISSING)
			TokenToVal(*aParam[3], image);
		auto __retval = (__int64)mC->compareSegments(size, lines1, lines2, image);
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_detect: {
		cv::_InputArray image;
		cv::_OutputArray lines, width = cv::noArray(), prec = cv::noArray(), nfa = cv::noArray();
		if (ParamIndexToVal(0, image))
			_o_return_result;
		if (ParamIndexToVal(1, lines))
			_o_return_result;
		if (aParamCount > 2 && aParam[2]->symbol != SYM_MISSING)
			TokenToVal(*aParam[2], width);
		if (aParamCount > 3 && aParam[3]->symbol != SYM_MISSING)
			TokenToVal(*aParam[3], prec);
		if (aParamCount > 4 && aParam[4]->symbol != SYM_MISSING)
			TokenToVal(*aParam[4], nfa);
		mC->detect(image, lines, width, prec, nfa);
		return;
	}
	case M_drawSegments: {
		cv::_InputArray lines;
		cv::_InputOutputArray image;
		if (ParamIndexToVal(0, image))
			_o_return_result;
		if (ParamIndexToVal(1, lines))
			_o_return_result;
		mC->drawSegments(image, lines);
		return;
	}
	}
}

void MSER::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::MSER>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		double max_variation = 0.25, min_diversity = .2, area_threshold = 1.01, min_margin = 0.003;
		int delta = 5, min_area = 60, max_area = 14400, max_evolution = 200, edge_blur_size = 5;
		if (aParamCount > 0 && aParam[0]->symbol != SYM_MISSING)
			TokenToVal(*aParam[0], delta);
		if (aParamCount > 1 && aParam[1]->symbol != SYM_MISSING)
			TokenToVal(*aParam[1], min_area);
		if (aParamCount > 2 && aParam[2]->symbol != SYM_MISSING)
			TokenToVal(*aParam[2], max_area);
		if (aParamCount > 3 && aParam[3]->symbol != SYM_MISSING)
			TokenToVal(*aParam[3], max_variation);
		if (aParamCount > 4 && aParam[4]->symbol != SYM_MISSING)
			TokenToVal(*aParam[4], min_diversity);
		if (aParamCount > 5 && aParam[5]->symbol != SYM_MISSING)
			TokenToVal(*aParam[5], max_evolution);
		if (aParamCount > 6 && aParam[6]->symbol != SYM_MISSING)
			TokenToVal(*aParam[6], area_threshold);
		if (aParamCount > 7 && aParam[7]->symbol != SYM_MISSING)
			TokenToVal(*aParam[7], min_margin);
		if (aParamCount > 8 && aParam[8]->symbol != SYM_MISSING)
			TokenToVal(*aParam[8], edge_blur_size);
		mC = cv::MSER::create(delta, min_area, max_area, max_variation, min_diversity, max_evolution, area_threshold, min_margin, edge_blur_size);
		return;
	}
	case M_detectRegions: {
		cv::_InputArray image;
		std::vector<cv::Rect> bboxes;
		std::vector<std::vector<cv::Point>> msers;
		if (ParamIndexToVal(0, image))
			_o_return_result;
		VarRef* var_msers = nullptr;
		if (ParamIndexToVal(1, var_msers))
			_o_return_result;
		VarRef* var_bboxes = nullptr;
		if (ParamIndexToVal(2, var_bboxes))
			_o_return_result;
		mC->detectRegions(image, msers, bboxes);
		ValToResult(msers, aResultToken);
		g_ahkapi->VarAssign(var_msers, aResultToken);
		g_ahkapi->ResultTokenFree(aResultToken);
		ValToResult(bboxes, aResultToken);
		g_ahkapi->VarAssign(var_bboxes, aResultToken);
		g_ahkapi->ResultTokenFree(aResultToken);
		return;
	}
	case M_getDefaultName: {
		auto __retval = mC->getDefaultName();
		return ValToResult(__retval, aResultToken);
	}
	case M_getDelta: {
		auto __retval = (__int64)mC->getDelta();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getMaxArea: {
		auto __retval = (__int64)mC->getMaxArea();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getMinArea: {
		auto __retval = (__int64)mC->getMinArea();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getPass2Only: {
		auto __retval = (__int64)mC->getPass2Only();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_setDelta: {
		int delta;
		if (ParamIndexToVal(0, delta))
			_o_return_result;
		mC->setDelta(delta);
		return;
	}
	case M_setMaxArea: {
		int maxArea;
		if (ParamIndexToVal(0, maxArea))
			_o_return_result;
		mC->setMaxArea(maxArea);
		return;
	}
	case M_setMinArea: {
		int minArea;
		if (ParamIndexToVal(0, minArea))
			_o_return_result;
		mC->setMinArea(minArea);
		return;
	}
	case M_setPass2Only: {
		bool f;
		if (ParamIndexToVal(0, (char&)f))
			_o_return_result;
		mC->setPass2Only(f);
		return;
	}
	}
}

void MergeDebevec::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::MergeDebevec>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		else _o_invalid_param;
		return;
	}
	case M_process: {
		if (aParamCount == 4) {
			cv::_InputArray src, times, response;
			cv::_OutputArray dst;
			if (ParamIndexToVal(0, src))
				_o_return_result;
			if (ParamIndexToVal(1, dst))
				_o_return_result;
			if (ParamIndexToVal(2, times))
				_o_return_result;
			if (ParamIndexToVal(3, response))
				_o_return_result;
			mC->process(src, dst, times, response);
			return;
		}
		else if (aParamCount == 3) {
			cv::_InputArray src, times;
			cv::_OutputArray dst;
			if (ParamIndexToVal(0, src))
				_o_return_result;
			if (ParamIndexToVal(1, dst))
				_o_return_result;
			if (ParamIndexToVal(2, times))
				_o_return_result;
			mC->process(src, dst, times);
			return;
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	}
}

void MergeExposures::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M_process: {
		cv::_InputArray src, times, response;
		cv::_OutputArray dst;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, dst))
			_o_return_result;
		if (ParamIndexToVal(2, times))
			_o_return_result;
		if (ParamIndexToVal(3, response))
			_o_return_result;
		mC->process(src, dst, times, response);
		return;
	}
	}
}

void MergeMertens::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::MergeMertens>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		else _o_invalid_param;
		return;
	}
	case M_getContrastWeight: {
		auto __retval = (double)mC->getContrastWeight();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getExposureWeight: {
		auto __retval = (double)mC->getExposureWeight();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getSaturationWeight: {
		auto __retval = (double)mC->getSaturationWeight();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_process: {
		if (aParamCount == 4) {
			cv::_InputArray src, times, response;
			cv::_OutputArray dst;
			if (ParamIndexToVal(0, src))
				_o_return_result;
			if (ParamIndexToVal(1, dst))
				_o_return_result;
			if (ParamIndexToVal(2, times))
				_o_return_result;
			if (ParamIndexToVal(3, response))
				_o_return_result;
			mC->process(src, dst, times, response);
			return;
		}
		else if (aParamCount == 2) {
			cv::_InputArray src;
			cv::_OutputArray dst;
			if (ParamIndexToVal(0, src))
				_o_return_result;
			if (ParamIndexToVal(1, dst))
				_o_return_result;
			mC->process(src, dst);
			return;
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case M_setContrastWeight: {
		float contrast_weiht;
		if (ParamIndexToVal(0, contrast_weiht))
			_o_return_result;
		mC->setContrastWeight(contrast_weiht);
		return;
	}
	case M_setExposureWeight: {
		float exposure_weight;
		if (ParamIndexToVal(0, exposure_weight))
			_o_return_result;
		mC->setExposureWeight(exposure_weight);
		return;
	}
	case M_setSaturationWeight: {
		float saturation_weight;
		if (ParamIndexToVal(0, saturation_weight))
			_o_return_result;
		mC->setSaturationWeight(saturation_weight);
		return;
	}
	}
}

void MergeRobertson::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::MergeRobertson>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		else _o_invalid_param;
		return;
	}
	case M_process: {
		if (aParamCount == 4) {
			cv::_InputArray src, times, response;
			cv::_OutputArray dst;
			if (ParamIndexToVal(0, src))
				_o_return_result;
			if (ParamIndexToVal(1, dst))
				_o_return_result;
			if (ParamIndexToVal(2, times))
				_o_return_result;
			if (ParamIndexToVal(3, response))
				_o_return_result;
			mC->process(src, dst, times, response);
			return;
		}
		else if (aParamCount == 3) {
			cv::_InputArray src, times;
			cv::_OutputArray dst;
			if (ParamIndexToVal(0, src))
				_o_return_result;
			if (ParamIndexToVal(1, dst))
				_o_return_result;
			if (ParamIndexToVal(2, times))
				_o_return_result;
			mC->process(src, dst, times);
			return;
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	}
}

void Moments::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::Moments>; 
		if (aParamCount == 1 && aParam[0] == g_invalid) return;
		if (aParamCount == 0)
			mC = new cv::Moments;
		else if (aParamCount > 0 && aParamCount < 3) {
			bool binaryImage = false;
			cv::_InputArray array;
			if (ParamIndexToVal(0, array))
				_o_return_result;
			if (aParamCount > 1 && aParam[1]->symbol != SYM_MISSING)
				TokenToVal(*aParam[1], (char&)binaryImage);
			mC = new cv::Moments;
			*mC = cv::moments(array, binaryImage);
		}
		else if (aParamCount == 10) {
			double  m[10];
			for (int i = 0; i < 10; i++) {
				if (ParamIndexToVal(i, m[i]))
					_o_return_result;
			}
			mC = new cv::Moments(m[0], m[1], m[2], m[3], m[4], m[5], m[6], m[7], m[8], m[9]);
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count"));
		return;
	}
	default: {
		double* p = 0;
#define TEST(n) case P_##n: p = &mC->n; break
		switch (aID)
		{
			TEST(m00);
			TEST(m10);
			TEST(m01);
			TEST(m20);
			TEST(m11);
			TEST(m02);
			TEST(m30);
			TEST(m21);
			TEST(m12);
			TEST(m03);
			TEST(mu20);
			TEST(mu11);
			TEST(mu02);
			TEST(mu30);
			TEST(mu21);
			TEST(mu12);
			TEST(mu03);
			TEST(nu20);
			TEST(nu11);
			TEST(nu02);
			TEST(nu30);
			TEST(nu21);
			TEST(nu12);
			TEST(nu03);
		}
#undef TEST
		if (aFlags & IT_SET) {
			if (ParamIndexToVal(0, *p))
				_o_return_result;
			return;
		}
		else
			return (void)aResultToken.SetValue(*p);
	}
	}
}

void ORB::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::ORB>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		float scaleFactor = 1.2f;
		int nfeatures = 500, nlevels = 8, edgeThreshold = 31, firstLevel = 0, WTA_K = 2, scoreType = cv::ORB::HARRIS_SCORE, patchSize = 31, fastThreshold = 20;
		if (aParamCount > 0 && aParam[0]->symbol != SYM_MISSING)
			TokenToVal(*aParam[0], nfeatures);
		if (aParamCount > 1 && aParam[1]->symbol != SYM_MISSING)
			TokenToVal(*aParam[1], scaleFactor);
		if (aParamCount > 2 && aParam[2]->symbol != SYM_MISSING)
			TokenToVal(*aParam[2], nlevels);
		if (aParamCount > 3 && aParam[3]->symbol != SYM_MISSING)
			TokenToVal(*aParam[3], edgeThreshold);
		if (aParamCount > 4 && aParam[4]->symbol != SYM_MISSING)
			TokenToVal(*aParam[4], firstLevel);
		if (aParamCount > 5 && aParam[5]->symbol != SYM_MISSING)
			TokenToVal(*aParam[5], WTA_K);
		if (aParamCount > 6 && aParam[6]->symbol != SYM_MISSING)
			TokenToVal(*aParam[6], scoreType);
		if (aParamCount > 7 && aParam[7]->symbol != SYM_MISSING)
			TokenToVal(*aParam[7], patchSize);
		if (aParamCount > 8 && aParam[8]->symbol != SYM_MISSING)
			TokenToVal(*aParam[8], fastThreshold);
		mC = cv::ORB::create(nfeatures, scaleFactor, nlevels, edgeThreshold, firstLevel, WTA_K, (cv::ORB::ScoreType)scoreType, patchSize, fastThreshold);
		return;
	}
	case M_getDefaultName: {
		auto __retval = mC->getDefaultName();
		return ValToResult(__retval, aResultToken);
	}
	case M_getEdgeThreshold: {
		auto __retval = (__int64)mC->getEdgeThreshold();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getFastThreshold: {
		auto __retval = (__int64)mC->getFastThreshold();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getFirstLevel: {
		auto __retval = (__int64)mC->getFirstLevel();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getMaxFeatures: {
		auto __retval = (__int64)mC->getMaxFeatures();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getNLevels: {
		auto __retval = (__int64)mC->getNLevels();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getPatchSize: {
		auto __retval = (__int64)mC->getPatchSize();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getScaleFactor: {
		auto __retval = mC->getScaleFactor();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getScoreType: {
		auto __retval = mC->getScoreType();
		return ValToResult(__retval, aResultToken);
	}
	case M_getWTA_K: {
		auto __retval = (__int64)mC->getWTA_K();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_setEdgeThreshold: {
		int edgeThreshold;
		if (ParamIndexToVal(0, edgeThreshold))
			_o_return_result;
		mC->setEdgeThreshold(edgeThreshold);
		return;
	}
	case M_setFastThreshold: {
		int fastThreshold;
		if (ParamIndexToVal(0, fastThreshold))
			_o_return_result;
		mC->setFastThreshold(fastThreshold);
		return;
	}
	case M_setFirstLevel: {
		int firstLevel;
		if (ParamIndexToVal(0, firstLevel))
			_o_return_result;
		mC->setFirstLevel(firstLevel);
		return;
	}
	case M_setMaxFeatures: {
		int maxFeatures;
		if (ParamIndexToVal(0, maxFeatures))
			_o_return_result;
		mC->setMaxFeatures(maxFeatures);
		return;
	}
	case M_setNLevels: {
		int nlevels;
		if (ParamIndexToVal(0, nlevels))
			_o_return_result;
		mC->setNLevels(nlevels);
		return;
	}
	case M_setPatchSize: {
		int patchSize;
		if (ParamIndexToVal(0, patchSize))
			_o_return_result;
		mC->setPatchSize(patchSize);
		return;
	}
	case M_setScaleFactor: {
		double scaleFactor;
		if (ParamIndexToVal(0, scaleFactor))
			_o_return_result;
		mC->setScaleFactor(scaleFactor);
		return;
	}
	case M_setScoreType: {
		int scoreType;
		if (ParamIndexToVal(0, scoreType))
			_o_return_result;
		mC->setScoreType((cv::ORB::ScoreType)scoreType);
		return;
	}
	case M_setWTA_K: {
		int wta_k;
		if (ParamIndexToVal(0, wta_k))
			_o_return_result;
		mC->setWTA_K(wta_k);
		return;
	}
	}
}

void PyRotationWarper::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::PyRotationWarper>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		if (aParamCount == 2) {
			cv::String type;
			float scale;
			if (ParamIndexToVal(0, type))
				_o_return_result;
			if (ParamIndexToVal(1, scale))
				_o_return_result;
			mC = new cv::PyRotationWarper(type, scale);
			return;
		}
		else 			mC = new cv::PyRotationWarper();
		return;
	}
	case M_buildMaps: {
		cv::_InputArray K, R;
		cv::_OutputArray xmap, ymap;
		cv::Size src_size;
		if (ParamIndexToVal(0, src_size))
			_o_return_result;
		if (ParamIndexToVal(1, K))
			_o_return_result;
		if (ParamIndexToVal(2, R))
			_o_return_result;
		if (ParamIndexToVal(3, xmap))
			_o_return_result;
		if (ParamIndexToVal(4, ymap))
			_o_return_result;
		auto __retval = mC->buildMaps(src_size, K, R, xmap, ymap);
		return ValToResult(__retval, aResultToken);
	}
	case M_getScale: {
		auto __retval = (double)mC->getScale();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_setScale: {
		float arg1;
		if (ParamIndexToVal(0, arg1))
			_o_return_result;
		mC->setScale(arg1);
		return;
	}
	case M_warp: {
		cv::_InputArray src, K, R;
		cv::_OutputArray dst;
		int interp_mode, border_mode;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, K))
			_o_return_result;
		if (ParamIndexToVal(2, R))
			_o_return_result;
		if (ParamIndexToVal(3, interp_mode))
			_o_return_result;
		if (ParamIndexToVal(4, border_mode))
			_o_return_result;
		if (ParamIndexToVal(5, dst))
			_o_return_result;
		auto __retval = mC->warp(src, K, R, interp_mode, border_mode, dst);
		return ValToResult(__retval, aResultToken);
	}
	case M_warpBackward: {
		cv::_InputArray src, K, R;
		cv::_OutputArray dst;
		cv::Size dst_size;
		int interp_mode, border_mode;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, K))
			_o_return_result;
		if (ParamIndexToVal(2, R))
			_o_return_result;
		if (ParamIndexToVal(3, interp_mode))
			_o_return_result;
		if (ParamIndexToVal(4, border_mode))
			_o_return_result;
		if (ParamIndexToVal(5, dst_size))
			_o_return_result;
		if (ParamIndexToVal(6, dst))
			_o_return_result;
		mC->warpBackward(src, K, R, interp_mode, border_mode, dst_size, dst);
		return;
	}
	case M_warpPoint: {
		cv::_InputArray K, R;
		cv::Point2f pt;
		if (ParamIndexToVal(0, pt))
			_o_return_result;
		if (ParamIndexToVal(1, K))
			_o_return_result;
		if (ParamIndexToVal(2, R))
			_o_return_result;
		auto __retval = mC->warpPoint(pt, K, R);
		return ValToResult(__retval, aResultToken);
	}
	case M_warpPointBackward: {
		cv::_InputArray K, R;
		cv::Point2f pt;
		if (ParamIndexToVal(0, pt))
			_o_return_result;
		if (ParamIndexToVal(1, K))
			_o_return_result;
		if (ParamIndexToVal(2, R))
			_o_return_result;
		auto __retval = mC->warpPointBackward(pt, K, R);
		return ValToResult(__retval, aResultToken);
	}
	case M_warpRoi: {
		cv::_InputArray K, R;
		cv::Size src_size;
		if (ParamIndexToVal(0, src_size))
			_o_return_result;
		if (ParamIndexToVal(1, K))
			_o_return_result;
		if (ParamIndexToVal(2, R))
			_o_return_result;
		auto __retval = mC->warpRoi(src_size, K, R);
		return ValToResult(__retval, aResultToken);
	}
	}
}

void QRCodeDetector::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::QRCodeDetector>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		mC = new cv::QRCodeDetector();
		return;
	}
	case M_decode: {
		cv::_InputArray img, points;
		cv::_OutputArray straight_qrcode = cv::noArray();
		if (ParamIndexToVal(0, img))
			_o_return_result;
		if (ParamIndexToVal(1, points))
			_o_return_result;
		if (aParamCount > 2 && aParam[2]->symbol != SYM_MISSING)
			TokenToVal(*aParam[2], straight_qrcode);
		auto __retval = mC->decode(img, points, straight_qrcode);
		return ValToResult(__retval, aResultToken);
	}
	case M_decodeCurved: {
		cv::_InputArray img, points;
		cv::_OutputArray straight_qrcode = cv::noArray();
		if (ParamIndexToVal(0, img))
			_o_return_result;
		if (ParamIndexToVal(1, points))
			_o_return_result;
		if (aParamCount > 2 && aParam[2]->symbol != SYM_MISSING)
			TokenToVal(*aParam[2], straight_qrcode);
		auto __retval = mC->decodeCurved(img, points, straight_qrcode);
		return ValToResult(__retval, aResultToken);
	}
	case M_decodeMulti: {
		cv::_InputArray img, points;
		cv::_OutputArray straight_qrcode = cv::noArray();
		std::vector<cv::String> decoded_info;
		if (ParamIndexToVal(0, img))
			_o_return_result;
		if (ParamIndexToVal(1, points))
			_o_return_result;
		VarRef* var_decoded_info = nullptr;
		if (ParamIndexToVal(2, var_decoded_info))
			_o_return_result;
		if (aParamCount > 3 && aParam[3]->symbol != SYM_MISSING)
			TokenToVal(*aParam[3], straight_qrcode);
		auto __retval = (__int64)mC->decodeMulti(img, points, decoded_info, straight_qrcode);
		ValToResult(decoded_info, aResultToken);
		g_ahkapi->VarAssign(var_decoded_info, aResultToken);
		g_ahkapi->ResultTokenFree(aResultToken);
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_detect: {
		cv::_InputArray img;
		cv::_OutputArray points;
		if (ParamIndexToVal(0, img))
			_o_return_result;
		if (ParamIndexToVal(1, points))
			_o_return_result;
		auto __retval = (__int64)mC->detect(img, points);
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_detectAndDecode: {
		cv::_InputArray img;
		cv::_OutputArray points = cv::noArray(), straight_qrcode = cv::noArray();
		if (ParamIndexToVal(0, img))
			_o_return_result;
		if (aParamCount > 1 && aParam[1]->symbol != SYM_MISSING)
			TokenToVal(*aParam[1], points);
		if (aParamCount > 2 && aParam[2]->symbol != SYM_MISSING)
			TokenToVal(*aParam[2], straight_qrcode);
		auto __retval = mC->detectAndDecode(img, points, straight_qrcode);
		return ValToResult(__retval, aResultToken);
	}
	case M_detectAndDecodeCurved: {
		cv::_InputArray img;
		cv::_OutputArray points = cv::noArray(), straight_qrcode = cv::noArray();
		if (ParamIndexToVal(0, img))
			_o_return_result;
		if (aParamCount > 1 && aParam[1]->symbol != SYM_MISSING)
			TokenToVal(*aParam[1], points);
		if (aParamCount > 2 && aParam[2]->symbol != SYM_MISSING)
			TokenToVal(*aParam[2], straight_qrcode);
		auto __retval = mC->detectAndDecodeCurved(img, points, straight_qrcode);
		return ValToResult(__retval, aResultToken);
	}
	case M_detectAndDecodeMulti: {
		cv::_InputArray img;
		cv::_OutputArray points = cv::noArray(), straight_qrcode = cv::noArray();
		std::vector<cv::String> decoded_info;
		if (ParamIndexToVal(0, img))
			_o_return_result;
		VarRef* var_decoded_info = nullptr;
		if (ParamIndexToVal(1, var_decoded_info))
			_o_return_result;
		if (aParamCount > 2 && aParam[2]->symbol != SYM_MISSING)
			TokenToVal(*aParam[2], points);
		if (aParamCount > 3 && aParam[3]->symbol != SYM_MISSING)
			TokenToVal(*aParam[3], straight_qrcode);
		auto __retval = (__int64)mC->detectAndDecodeMulti(img, decoded_info, points, straight_qrcode);
		ValToResult(decoded_info, aResultToken);
		g_ahkapi->VarAssign(var_decoded_info, aResultToken);
		g_ahkapi->ResultTokenFree(aResultToken);
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_detectMulti: {
		cv::_InputArray img;
		cv::_OutputArray points;
		if (ParamIndexToVal(0, img))
			_o_return_result;
		if (ParamIndexToVal(1, points))
			_o_return_result;
		auto __retval = (__int64)mC->detectMulti(img, points);
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_setEpsX: {
		double epsX;
		if (ParamIndexToVal(0, epsX))
			_o_return_result;
		mC->setEpsX(epsX);
		return;
	}
	case M_setEpsY: {
		double epsY;
		if (ParamIndexToVal(0, epsY))
			_o_return_result;
		mC->setEpsY(epsY);
		return;
	}
	}
}

void QRCodeEncoder::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::QRCodeEncoder>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		cv::QRCodeEncoder::Params parameters = cv::QRCodeEncoder::Params();
		if (aParamCount > 0 && aParam[0]->symbol != SYM_MISSING)
			TokenToVal(*aParam[0], parameters);
		mC = cv::QRCodeEncoder::create(parameters);
		return;
	}
	case M_encode: {
		cv::_OutputArray qrcode;
		cv::String encoded_info;
		if (ParamIndexToVal(0, encoded_info))
			_o_return_result;
		if (ParamIndexToVal(1, qrcode))
			_o_return_result;
		mC->encode(encoded_info, qrcode);
		return;
	}
	case M_encodeStructuredAppend: {
		cv::_OutputArray qrcodes;
		cv::String encoded_info;
		if (ParamIndexToVal(0, encoded_info))
			_o_return_result;
		if (ParamIndexToVal(1, qrcodes))
			_o_return_result;
		mC->encodeStructuredAppend(encoded_info, qrcodes);
		return;
	}
	}
}

void SIFT::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::SIFT>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		if (0 <= aParamCount && aParamCount <= 5) {
			double contrastThreshold = 0.04, edgeThreshold = 10, sigma = 1.6;
			int nfeatures = 0, nOctaveLayers = 3;
			if (aParamCount > 0 && aParam[0]->symbol != SYM_MISSING)
				TokenToVal(*aParam[0], nfeatures);
			if (aParamCount > 1 && aParam[1]->symbol != SYM_MISSING)
				TokenToVal(*aParam[1], nOctaveLayers);
			if (aParamCount > 2 && aParam[2]->symbol != SYM_MISSING)
				TokenToVal(*aParam[2], contrastThreshold);
			if (aParamCount > 3 && aParam[3]->symbol != SYM_MISSING)
				TokenToVal(*aParam[3], edgeThreshold);
			if (aParamCount > 4 && aParam[4]->symbol != SYM_MISSING)
				TokenToVal(*aParam[4], sigma);
			mC = cv::SIFT::create(nfeatures, nOctaveLayers, contrastThreshold, edgeThreshold, sigma);
			return;
		}
		else if (aParamCount == 6) {
			double contrastThreshold, edgeThreshold, sigma;
			int nfeatures, nOctaveLayers, descriptorType;
			if (ParamIndexToVal(0, nfeatures))
				_o_return_result;
			if (ParamIndexToVal(1, nOctaveLayers))
				_o_return_result;
			if (ParamIndexToVal(2, contrastThreshold))
				_o_return_result;
			if (ParamIndexToVal(3, edgeThreshold))
				_o_return_result;
			if (ParamIndexToVal(4, sigma))
				_o_return_result;
			if (ParamIndexToVal(5, descriptorType))
				_o_return_result;
			mC = cv::SIFT::create(nfeatures, nOctaveLayers, contrastThreshold, edgeThreshold, sigma, descriptorType);
			return;
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case M_getDefaultName: {
		auto __retval = mC->getDefaultName();
		return ValToResult(__retval, aResultToken);
	}
	}
}

void SimpleBlobDetector::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::SimpleBlobDetector>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		cv::SimpleBlobDetector::Params parameters = cv::SimpleBlobDetector::Params();
		if (aParamCount > 0 && aParam[0]->symbol != SYM_MISSING)
			TokenToVal(*aParam[0], parameters);
		mC = cv::SimpleBlobDetector::create(parameters);
		return;
	}
	case M_getDefaultName: {
		auto __retval = mC->getDefaultName();
		return ValToResult(__retval, aResultToken);
	}
	}
}

void SparseOpticalFlow::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M_calc: {
		cv::_InputArray prevImg, nextImg, prevPts;
		cv::_InputOutputArray nextPts;
		cv::_OutputArray status, err = cv::noArray();
		if (ParamIndexToVal(0, prevImg))
			_o_return_result;
		if (ParamIndexToVal(1, nextImg))
			_o_return_result;
		if (ParamIndexToVal(2, prevPts))
			_o_return_result;
		if (ParamIndexToVal(3, nextPts))
			_o_return_result;
		if (ParamIndexToVal(4, status))
			_o_return_result;
		if (aParamCount > 5 && aParam[5]->symbol != SYM_MISSING)
			TokenToVal(*aParam[5], err);
		mC->calc(prevImg, nextImg, prevPts, nextPts, status, err);
		return;
	}
	}
}

void SparsePyrLKOpticalFlow::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::SparsePyrLKOpticalFlow>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		if (0 <= aParamCount && aParamCount <= 5) {
			cv::Size winSize = cv::Size(21, 21);
			cv::TermCriteria crit = cv::TermCriteria(cv::TermCriteria::COUNT + cv::TermCriteria::EPS, 30, 0.01);
			;
			double minEigThreshold = 1e-4;
			int maxLevel = 3, flags = 0;
			if (aParamCount > 0 && aParam[0]->symbol != SYM_MISSING)
				TokenToVal(*aParam[0], winSize);
			if (aParamCount > 1 && aParam[1]->symbol != SYM_MISSING)
				TokenToVal(*aParam[1], maxLevel);
			if (aParamCount > 2 && aParam[2]->symbol != SYM_MISSING)
				TokenToVal(*aParam[2], crit);
			if (aParamCount > 3 && aParam[3]->symbol != SYM_MISSING)
				TokenToVal(*aParam[3], flags);
			if (aParamCount > 4 && aParam[4]->symbol != SYM_MISSING)
				TokenToVal(*aParam[4], minEigThreshold);
			mC = cv::SparsePyrLKOpticalFlow::create(winSize, maxLevel, crit, flags, minEigThreshold);
			return;
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case M_getFlags: {
		auto __retval = (__int64)mC->getFlags();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getMaxLevel: {
		auto __retval = (__int64)mC->getMaxLevel();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getMinEigThreshold: {
		auto __retval = mC->getMinEigThreshold();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getTermCriteria: {
		auto __retval = mC->getTermCriteria();
		return ValToResult(__retval, aResultToken);
	}
	case M_getWinSize: {
		auto __retval = mC->getWinSize();
		return ValToResult(__retval, aResultToken);
	}
	case M_setFlags: {
		int flags;
		if (ParamIndexToVal(0, flags))
			_o_return_result;
		mC->setFlags(flags);
		return;
	}
	case M_setMaxLevel: {
		int maxLevel;
		if (ParamIndexToVal(0, maxLevel))
			_o_return_result;
		mC->setMaxLevel(maxLevel);
		return;
	}
	case M_setMinEigThreshold: {
		double minEigThreshold;
		if (ParamIndexToVal(0, minEigThreshold))
			_o_return_result;
		mC->setMinEigThreshold(minEigThreshold);
		return;
	}
	case M_setTermCriteria: {
		cv::TermCriteria crit;
		if (ParamIndexToVal(0, crit))
			_o_return_result;
		mC->setTermCriteria(crit);
		return;
	}
	case M_setWinSize: {
		cv::Size winSize;
		if (ParamIndexToVal(0, winSize))
			_o_return_result;
		mC->setWinSize(winSize);
		return;
	}
	}
}

void StereoBM::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::StereoBM>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		int numDisparities = 0, blockSize = 21;
		if (aParamCount > 0 && aParam[0]->symbol != SYM_MISSING)
			TokenToVal(*aParam[0], numDisparities);
		if (aParamCount > 1 && aParam[1]->symbol != SYM_MISSING)
			TokenToVal(*aParam[1], blockSize);
		mC = cv::StereoBM::create(numDisparities, blockSize);
		return;
	}
	case M_getPreFilterCap: {
		auto __retval = (__int64)mC->getPreFilterCap();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getPreFilterSize: {
		auto __retval = (__int64)mC->getPreFilterSize();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getPreFilterType: {
		auto __retval = (__int64)mC->getPreFilterType();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getROI1: {
		auto __retval = mC->getROI1();
		return ValToResult(__retval, aResultToken);
	}
	case M_getROI2: {
		auto __retval = mC->getROI2();
		return ValToResult(__retval, aResultToken);
	}
	case M_getSmallerBlockSize: {
		auto __retval = (__int64)mC->getSmallerBlockSize();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getTextureThreshold: {
		auto __retval = (__int64)mC->getTextureThreshold();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getUniquenessRatio: {
		auto __retval = (__int64)mC->getUniquenessRatio();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_setPreFilterCap: {
		int preFilterCap;
		if (ParamIndexToVal(0, preFilterCap))
			_o_return_result;
		mC->setPreFilterCap(preFilterCap);
		return;
	}
	case M_setPreFilterSize: {
		int preFilterSize;
		if (ParamIndexToVal(0, preFilterSize))
			_o_return_result;
		mC->setPreFilterSize(preFilterSize);
		return;
	}
	case M_setPreFilterType: {
		int preFilterType;
		if (ParamIndexToVal(0, preFilterType))
			_o_return_result;
		mC->setPreFilterType(preFilterType);
		return;
	}
	case M_setROI1: {
		cv::Rect roi1;
		if (ParamIndexToVal(0, roi1))
			_o_return_result;
		mC->setROI1(roi1);
		return;
	}
	case M_setROI2: {
		cv::Rect roi2;
		if (ParamIndexToVal(0, roi2))
			_o_return_result;
		mC->setROI2(roi2);
		return;
	}
	case M_setSmallerBlockSize: {
		int blockSize;
		if (ParamIndexToVal(0, blockSize))
			_o_return_result;
		mC->setSmallerBlockSize(blockSize);
		return;
	}
	case M_setTextureThreshold: {
		int textureThreshold;
		if (ParamIndexToVal(0, textureThreshold))
			_o_return_result;
		mC->setTextureThreshold(textureThreshold);
		return;
	}
	case M_setUniquenessRatio: {
		int uniquenessRatio;
		if (ParamIndexToVal(0, uniquenessRatio))
			_o_return_result;
		mC->setUniquenessRatio(uniquenessRatio);
		return;
	}
	}
}

void StereoMatcher::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M_compute: {
		cv::_InputArray left, right;
		cv::_OutputArray disparity;
		if (ParamIndexToVal(0, left))
			_o_return_result;
		if (ParamIndexToVal(1, right))
			_o_return_result;
		if (ParamIndexToVal(2, disparity))
			_o_return_result;
		mC->compute(left, right, disparity);
		return;
	}
	case M_getBlockSize: {
		auto __retval = (__int64)mC->getBlockSize();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getDisp12MaxDiff: {
		auto __retval = (__int64)mC->getDisp12MaxDiff();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getMinDisparity: {
		auto __retval = (__int64)mC->getMinDisparity();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getNumDisparities: {
		auto __retval = (__int64)mC->getNumDisparities();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getSpeckleRange: {
		auto __retval = (__int64)mC->getSpeckleRange();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getSpeckleWindowSize: {
		auto __retval = (__int64)mC->getSpeckleWindowSize();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_setBlockSize: {
		int blockSize;
		if (ParamIndexToVal(0, blockSize))
			_o_return_result;
		mC->setBlockSize(blockSize);
		return;
	}
	case M_setDisp12MaxDiff: {
		int disp12MaxDiff;
		if (ParamIndexToVal(0, disp12MaxDiff))
			_o_return_result;
		mC->setDisp12MaxDiff(disp12MaxDiff);
		return;
	}
	case M_setMinDisparity: {
		int minDisparity;
		if (ParamIndexToVal(0, minDisparity))
			_o_return_result;
		mC->setMinDisparity(minDisparity);
		return;
	}
	case M_setNumDisparities: {
		int numDisparities;
		if (ParamIndexToVal(0, numDisparities))
			_o_return_result;
		mC->setNumDisparities(numDisparities);
		return;
	}
	case M_setSpeckleRange: {
		int speckleRange;
		if (ParamIndexToVal(0, speckleRange))
			_o_return_result;
		mC->setSpeckleRange(speckleRange);
		return;
	}
	case M_setSpeckleWindowSize: {
		int speckleWindowSize;
		if (ParamIndexToVal(0, speckleWindowSize))
			_o_return_result;
		mC->setSpeckleWindowSize(speckleWindowSize);
		return;
	}
	}
}

void StereoSGBM::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::StereoSGBM>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		int minDisparity = 0, numDisparities = 16, blockSize = 3, P1 = 0, P2 = 0, disp12MaxDiff = 0, preFilterCap = 0, uniquenessRatio = 0, speckleWindowSize = 0, speckleRange = 0, mode = cv::StereoSGBM::MODE_SGBM;
		if (aParamCount > 0 && aParam[0]->symbol != SYM_MISSING)
			TokenToVal(*aParam[0], minDisparity);
		if (aParamCount > 1 && aParam[1]->symbol != SYM_MISSING)
			TokenToVal(*aParam[1], numDisparities);
		if (aParamCount > 2 && aParam[2]->symbol != SYM_MISSING)
			TokenToVal(*aParam[2], blockSize);
		if (aParamCount > 3 && aParam[3]->symbol != SYM_MISSING)
			TokenToVal(*aParam[3], P1);
		if (aParamCount > 4 && aParam[4]->symbol != SYM_MISSING)
			TokenToVal(*aParam[4], P2);
		if (aParamCount > 5 && aParam[5]->symbol != SYM_MISSING)
			TokenToVal(*aParam[5], disp12MaxDiff);
		if (aParamCount > 6 && aParam[6]->symbol != SYM_MISSING)
			TokenToVal(*aParam[6], preFilterCap);
		if (aParamCount > 7 && aParam[7]->symbol != SYM_MISSING)
			TokenToVal(*aParam[7], uniquenessRatio);
		if (aParamCount > 8 && aParam[8]->symbol != SYM_MISSING)
			TokenToVal(*aParam[8], speckleWindowSize);
		if (aParamCount > 9 && aParam[9]->symbol != SYM_MISSING)
			TokenToVal(*aParam[9], speckleRange);
		if (aParamCount > 10 && aParam[10]->symbol != SYM_MISSING)
			TokenToVal(*aParam[10], mode);
		mC = cv::StereoSGBM::create(minDisparity, numDisparities, blockSize, P1, P2, disp12MaxDiff, preFilterCap, uniquenessRatio, speckleWindowSize, speckleRange, mode);
		return;
	}
	case M_getMode: {
		auto __retval = (__int64)mC->getMode();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getP1: {
		auto __retval = (__int64)mC->getP1();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getP2: {
		auto __retval = (__int64)mC->getP2();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getPreFilterCap: {
		auto __retval = (__int64)mC->getPreFilterCap();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getUniquenessRatio: {
		auto __retval = (__int64)mC->getUniquenessRatio();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_setMode: {
		int mode;
		if (ParamIndexToVal(0, mode))
			_o_return_result;
		mC->setMode(mode);
		return;
	}
	case M_setP1: {
		int P1;
		if (ParamIndexToVal(0, P1))
			_o_return_result;
		mC->setP1(P1);
		return;
	}
	case M_setP2: {
		int P2;
		if (ParamIndexToVal(0, P2))
			_o_return_result;
		mC->setP2(P2);
		return;
	}
	case M_setPreFilterCap: {
		int preFilterCap;
		if (ParamIndexToVal(0, preFilterCap))
			_o_return_result;
		mC->setPreFilterCap(preFilterCap);
		return;
	}
	case M_setUniquenessRatio: {
		int uniquenessRatio;
		if (ParamIndexToVal(0, uniquenessRatio))
			_o_return_result;
		mC->setUniquenessRatio(uniquenessRatio);
		return;
	}
	}
}

void Stitcher::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::Stitcher>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		int mode = cv::Stitcher::PANORAMA;
		if (aParamCount > 0 && aParam[0]->symbol != SYM_MISSING)
			TokenToVal(*aParam[0], mode);
		mC = cv::Stitcher::create((cv::Stitcher::Mode)mode);
		return;
	}
	case M_composePanorama: {
		if (aParamCount == 1) {
			cv::_OutputArray pano;
			if (ParamIndexToVal(0, pano))
				_o_return_result;
			auto __retval = mC->composePanorama(pano);
			return ValToResult(__retval, aResultToken);
		}
		else if (aParamCount == 2) {
			cv::_InputArray images;
			cv::_OutputArray pano;
			if (ParamIndexToVal(0, images))
				_o_return_result;
			if (ParamIndexToVal(1, pano))
				_o_return_result;
			auto __retval = mC->composePanorama(images, pano);
			return ValToResult(__retval, aResultToken);
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case M_compositingResol: {
		auto __retval = mC->compositingResol();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_estimateTransform: {
		cv::_InputArray images, masks = cv::noArray();
		if (ParamIndexToVal(0, images))
			_o_return_result;
		if (aParamCount > 1 && aParam[1]->symbol != SYM_MISSING)
			TokenToVal(*aParam[1], masks);
		auto __retval = mC->estimateTransform(images, masks);
		return ValToResult(__retval, aResultToken);
	}
	case M_interpolationFlags: {
		auto __retval = mC->interpolationFlags();
		return ValToResult(__retval, aResultToken);
	}
	case M_panoConfidenceThresh: {
		auto __retval = mC->panoConfidenceThresh();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_registrationResol: {
		auto __retval = mC->registrationResol();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_seamEstimationResol: {
		auto __retval = mC->seamEstimationResol();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_setCompositingResol: {
		double resol_mpx;
		if (ParamIndexToVal(0, resol_mpx))
			_o_return_result;
		mC->setCompositingResol(resol_mpx);
		return;
	}
	case M_setInterpolationFlags: {
		int interp_flags;
		if (ParamIndexToVal(0, interp_flags))
			_o_return_result;
		mC->setInterpolationFlags((cv::InterpolationFlags)interp_flags);
		return;
	}
	case M_setPanoConfidenceThresh: {
		double conf_thresh;
		if (ParamIndexToVal(0, conf_thresh))
			_o_return_result;
		mC->setPanoConfidenceThresh(conf_thresh);
		return;
	}
	case M_setRegistrationResol: {
		double resol_mpx;
		if (ParamIndexToVal(0, resol_mpx))
			_o_return_result;
		mC->setRegistrationResol(resol_mpx);
		return;
	}
	case M_setSeamEstimationResol: {
		double resol_mpx;
		if (ParamIndexToVal(0, resol_mpx))
			_o_return_result;
		mC->setSeamEstimationResol(resol_mpx);
		return;
	}
	case M_setWaveCorrection: {
		bool flag;
		if (ParamIndexToVal(0, (char&)flag))
			_o_return_result;
		mC->setWaveCorrection(flag);
		return;
	}
	case M_stitch: {
		if (aParamCount == 2) {
			cv::_InputArray images;
			cv::_OutputArray pano;
			if (ParamIndexToVal(0, images))
				_o_return_result;
			if (ParamIndexToVal(1, pano))
				_o_return_result;
			auto __retval = mC->stitch(images, pano);
			return ValToResult(__retval, aResultToken);
		}
		else if (aParamCount == 3) {
			cv::_InputArray images, masks;
			cv::_OutputArray pano;
			if (ParamIndexToVal(0, images))
				_o_return_result;
			if (ParamIndexToVal(1, masks))
				_o_return_result;
			if (ParamIndexToVal(2, pano))
				_o_return_result;
			auto __retval = mC->stitch(images, masks, pano);
			return ValToResult(__retval, aResultToken);
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case M_waveCorrection: {
		auto __retval = (__int64)mC->waveCorrection();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_workScale: {
		auto __retval = mC->workScale();
		return (void)(aResultToken.SetValue(__retval));
	}
	}
}

void Subdiv2D::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::Subdiv2D>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		if (aParamCount == 0) {
			mC = new cv::Subdiv2D();
			return;
		}
		else if (aParamCount == 1) {
			cv::Rect rect;
			if (ParamIndexToVal(0, rect))
				_o_return_result;
			mC = new cv::Subdiv2D(rect);
			return;
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case M_edgeDst: {
		if (1 <= aParamCount && aParamCount <= 2) {
			cv::Point2f dstpt;
			int edge;
			if (ParamIndexToVal(0, edge))
				_o_return_result;
			VarRef* var_dstpt = nullptr;
			if (aParamCount > 1 && aParam[1]->symbol != SYM_MISSING) {
				TokenToVal(*aParam[1], var_dstpt);
			}
			auto __retval = (__int64)mC->edgeDst(edge, &dstpt);
			if (var_dstpt) {
				ValToResult(dstpt, aResultToken);
				g_ahkapi->VarAssign(var_dstpt, aResultToken);
				g_ahkapi->ResultTokenFree(aResultToken);
			}
			return (void)(aResultToken.SetValue(__retval));
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case M_edgeOrg: {
		if (1 <= aParamCount && aParamCount <= 2) {
			cv::Point2f orgpt;
			int edge;
			if (ParamIndexToVal(0, edge))
				_o_return_result;
			VarRef* var_orgpt = nullptr;
			if (aParamCount > 1 && aParam[1]->symbol != SYM_MISSING) {
				TokenToVal(*aParam[1], var_orgpt);
			}
			auto __retval = (__int64)mC->edgeOrg(edge, &orgpt);
			if (var_orgpt) {
				ValToResult(orgpt, aResultToken);
				g_ahkapi->VarAssign(var_orgpt, aResultToken);
				g_ahkapi->ResultTokenFree(aResultToken);
			}
			return (void)(aResultToken.SetValue(__retval));
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case M_findNearest: {
		if (1 <= aParamCount && aParamCount <= 2) {
			cv::Point2f pt, nearestPt;
			if (ParamIndexToVal(0, pt))
				_o_return_result;
			VarRef* var_nearestPt = nullptr;
			if (aParamCount > 1 && aParam[1]->symbol != SYM_MISSING) {
				TokenToVal(*aParam[1], var_nearestPt);
			}
			auto __retval = (__int64)mC->findNearest(pt, &nearestPt);
			if (var_nearestPt) {
				ValToResult(nearestPt, aResultToken);
				g_ahkapi->VarAssign(var_nearestPt, aResultToken);
				g_ahkapi->ResultTokenFree(aResultToken);
			}
			return (void)(aResultToken.SetValue(__retval));
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case M_getEdge: {
		int edge, nextEdgeType;
		if (ParamIndexToVal(0, edge))
			_o_return_result;
		if (ParamIndexToVal(1, nextEdgeType))
			_o_return_result;
		auto __retval = (__int64)mC->getEdge(edge, nextEdgeType);
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getEdgeList: {
		std::vector<cv::Vec4f> edgeList;
		VarRef* var_edgeList = nullptr;
		if (ParamIndexToVal(0, var_edgeList))
			_o_return_result;
		mC->getEdgeList(edgeList);
		ValToResult(edgeList, aResultToken);
		g_ahkapi->VarAssign(var_edgeList, aResultToken);
		g_ahkapi->ResultTokenFree(aResultToken);
		return;
	}
	case M_getLeadingEdgeList: {
		std::vector<int> leadingEdgeList;
		VarRef* var_leadingEdgeList = nullptr;
		if (ParamIndexToVal(0, var_leadingEdgeList))
			_o_return_result;
		mC->getLeadingEdgeList(leadingEdgeList);
		ValToResult(leadingEdgeList, aResultToken);
		g_ahkapi->VarAssign(var_leadingEdgeList, aResultToken);
		g_ahkapi->ResultTokenFree(aResultToken);
		return;
	}
	case M_getTriangleList: {
		std::vector<cv::Vec6f> triangleList;
		VarRef* var_triangleList = nullptr;
		if (ParamIndexToVal(0, var_triangleList))
			_o_return_result;
		mC->getTriangleList(triangleList);
		ValToResult(triangleList, aResultToken);
		g_ahkapi->VarAssign(var_triangleList, aResultToken);
		g_ahkapi->ResultTokenFree(aResultToken);
		return;
	}
	case M_getVertex: {
		if (1 <= aParamCount && aParamCount <= 2) {
			int vertex, firstEdge;
			if (ParamIndexToVal(0, vertex))
				_o_return_result;
			VarRef* var_firstEdge = nullptr;
			if (aParamCount > 1 && aParam[1]->symbol != SYM_MISSING) {
				TokenToVal(*aParam[1], var_firstEdge);
			}
			auto __retval = mC->getVertex(vertex, &firstEdge);
			if (var_firstEdge) g_ahkapi->VarAssign(var_firstEdge, ExprTokenType((__int64)firstEdge));
			return ValToResult(__retval, aResultToken);
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case M_getVoronoiFacetList: {
		std::vector<cv::Point2f> facetCenters;
		std::vector<int> idx;
		std::vector<std::vector<cv::Point2f>> facetList;
		if (ParamIndexToVal(0, idx))
			_o_return_result;
		VarRef* var_facetList = nullptr;
		if (ParamIndexToVal(1, var_facetList))
			_o_return_result;
		VarRef* var_facetCenters = nullptr;
		if (ParamIndexToVal(2, var_facetCenters))
			_o_return_result;
		mC->getVoronoiFacetList(idx, facetList, facetCenters);
		ValToResult(facetList, aResultToken);
		g_ahkapi->VarAssign(var_facetList, aResultToken);
		g_ahkapi->ResultTokenFree(aResultToken);
		ValToResult(facetCenters, aResultToken);
		g_ahkapi->VarAssign(var_facetCenters, aResultToken);
		g_ahkapi->ResultTokenFree(aResultToken);
		return;
	}
	case M_initDelaunay: {
		cv::Rect rect;
		if (ParamIndexToVal(0, rect))
			_o_return_result;
		mC->initDelaunay(rect);
		return;
	}
	case M_insert: {
		cv::Point2f pt;
		std::vector<cv::Point2f> ptvec;
		auto arr = dynamic_cast<Array*>(TokenToObject(*aParam[0]));
		if (arr && arr->mLength && arr->mItem[0].symbol == SYM_OBJECT) {
			if (ParamIndexToVal(0, ptvec))
				_o_return_result;
			mC->insert(ptvec);
			return;
		}
		else {
			if (ParamIndexToVal(0, pt))
				_o_return_result;
			auto __retval = (__int64)mC->insert(pt);
			return (void)(aResultToken.SetValue(__retval));
		}
	}
	case M_locate: {
		cv::Point2f pt;
		int edge, vertex;
		if (ParamIndexToVal(0, pt))
			_o_return_result;
		VarRef* var_edge = nullptr;
		if (ParamIndexToVal(1, var_edge))
			_o_return_result;
		VarRef* var_vertex = nullptr;
		if (ParamIndexToVal(2, var_vertex))
			_o_return_result;
		auto __retval = (__int64)mC->locate(pt, edge, vertex);
		g_ahkapi->VarAssign(var_edge, ExprTokenType((__int64)edge));
		g_ahkapi->VarAssign(var_vertex, ExprTokenType((__int64)vertex));
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_nextEdge: {
		int edge;
		if (ParamIndexToVal(0, edge))
			_o_return_result;
		auto __retval = (__int64)mC->nextEdge(edge);
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_rotateEdge: {
		int edge, rotate;
		if (ParamIndexToVal(0, edge))
			_o_return_result;
		if (ParamIndexToVal(1, rotate))
			_o_return_result;
		auto __retval = (__int64)mC->rotateEdge(edge, rotate);
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_symEdge: {
		int edge;
		if (ParamIndexToVal(0, edge))
			_o_return_result;
		auto __retval = (__int64)mC->symEdge(edge);
		return (void)(aResultToken.SetValue(__retval));
	}
	}
}

void TickMeter::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::TickMeter>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		mC = new cv::TickMeter();
		return;
	}
	case M_getAvgTimeMilli: {
		auto __retval = mC->getAvgTimeMilli();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getAvgTimeSec: {
		auto __retval = mC->getAvgTimeSec();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getCounter: {
		auto __retval = mC->getCounter();
		return ValToResult(__retval, aResultToken);
	}
	case M_getFPS: {
		auto __retval = mC->getFPS();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getTimeMicro: {
		auto __retval = mC->getTimeMicro();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getTimeMilli: {
		auto __retval = mC->getTimeMilli();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getTimeSec: {
		auto __retval = mC->getTimeSec();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getTimeTicks: {
		auto __retval = mC->getTimeTicks();
		return ValToResult(__retval, aResultToken);
	}
	case M_reset: {
		mC->reset();
		return;
	}
	case M_start: {
		mC->start();
		return;
	}
	case M_stop: {
		mC->stop();
		return;
	}
	}
}

void Tonemap::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::Tonemap>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		else _o_invalid_param;
		return;
	}
	case M_getGamma: {
		auto __retval = (double)mC->getGamma();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_process: {
		cv::_InputArray src;
		cv::_OutputArray dst;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, dst))
			_o_return_result;
		mC->process(src, dst);
		return;
	}
	case M_setGamma: {
		float gamma;
		if (ParamIndexToVal(0, gamma))
			_o_return_result;
		mC->setGamma(gamma);
		return;
	}
	}
}

void TonemapDrago::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::TonemapDrago>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		else _o_invalid_param;
		return;
	}
	case M_getBias: {
		auto __retval = (double)mC->getBias();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getSaturation: {
		auto __retval = (double)mC->getSaturation();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_setBias: {
		float bias;
		if (ParamIndexToVal(0, bias))
			_o_return_result;
		mC->setBias(bias);
		return;
	}
	case M_setSaturation: {
		float saturation;
		if (ParamIndexToVal(0, saturation))
			_o_return_result;
		mC->setSaturation(saturation);
		return;
	}
	}
}

void TonemapMantiuk::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::TonemapMantiuk>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		else _o_invalid_param;
		return;
	}
	case M_getSaturation: {
		auto __retval = (double)mC->getSaturation();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getScale: {
		auto __retval = (double)mC->getScale();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_setSaturation: {
		float saturation;
		if (ParamIndexToVal(0, saturation))
			_o_return_result;
		mC->setSaturation(saturation);
		return;
	}
	case M_setScale: {
		float scale;
		if (ParamIndexToVal(0, scale))
			_o_return_result;
		mC->setScale(scale);
		return;
	}
	}
}

void TonemapReinhard::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::TonemapReinhard>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		else _o_invalid_param;
		return;
	}
	case M_getColorAdaptation: {
		auto __retval = (double)mC->getColorAdaptation();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getIntensity: {
		auto __retval = (double)mC->getIntensity();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getLightAdaptation: {
		auto __retval = (double)mC->getLightAdaptation();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_setColorAdaptation: {
		float color_adapt;
		if (ParamIndexToVal(0, color_adapt))
			_o_return_result;
		mC->setColorAdaptation(color_adapt);
		return;
	}
	case M_setIntensity: {
		float intensity;
		if (ParamIndexToVal(0, intensity))
			_o_return_result;
		mC->setIntensity(intensity);
		return;
	}
	case M_setLightAdaptation: {
		float light_adapt;
		if (ParamIndexToVal(0, light_adapt))
			_o_return_result;
		mC->setLightAdaptation(light_adapt);
		return;
	}
	}
}

void Tracker::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M_init: {
		cv::_InputArray image;
		cv::Rect boundingBox;
		if (ParamIndexToVal(0, image))
			_o_return_result;
		if (ParamIndexToVal(1, boundingBox))
			_o_return_result;
		mC->init(image, boundingBox);
		return;
	}
	case M_update: {
		cv::_InputArray image;
		cv::Rect boundingBox;
		if (ParamIndexToVal(0, image))
			_o_return_result;
		VarRef* var_boundingBox = nullptr;
		if (ParamIndexToVal(1, var_boundingBox))
			_o_return_result;
		auto __retval = (__int64)mC->update(image, boundingBox);
		ValToResult(boundingBox, aResultToken);
		g_ahkapi->VarAssign(var_boundingBox, aResultToken);
		g_ahkapi->ResultTokenFree(aResultToken);
		return (void)(aResultToken.SetValue(__retval));
	}
	}
}

void TrackerDaSiamRPN::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::TrackerDaSiamRPN>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		cv::TrackerDaSiamRPN::Params parameters = cv::TrackerDaSiamRPN::Params();
		if (aParamCount > 0 && aParam[0]->symbol != SYM_MISSING)
			TokenToVal(*aParam[0], parameters);
		mC = cv::TrackerDaSiamRPN::create(parameters);
		return;
	}
	case M_getTrackingScore: {
		auto __retval = (double)mC->getTrackingScore();
		return (void)(aResultToken.SetValue(__retval));
	}
	}
}

void TrackerGOTURN::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::TrackerGOTURN>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		cv::TrackerGOTURN::Params parameters = cv::TrackerGOTURN::Params();
		if (aParamCount > 0 && aParam[0]->symbol != SYM_MISSING)
			TokenToVal(*aParam[0], parameters);
		mC = cv::TrackerGOTURN::create(parameters);
		return;
	}
	}
}

void TrackerMIL::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::TrackerMIL>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		cv::TrackerMIL::Params parameters = cv::TrackerMIL::Params();
		if (aParamCount > 0 && aParam[0]->symbol != SYM_MISSING)
			TokenToVal(*aParam[0], parameters);
		mC = cv::TrackerMIL::create(parameters);
		return;
	}
	}
}

void VariationalRefinement::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::VariationalRefinement>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		mC = cv::VariationalRefinement::create();
		return;
	}
	case M_calcUV: {
		cv::_InputArray I0, I1;
		cv::_InputOutputArray flow_u, flow_v;
		if (ParamIndexToVal(0, I0))
			_o_return_result;
		if (ParamIndexToVal(1, I1))
			_o_return_result;
		if (ParamIndexToVal(2, flow_u))
			_o_return_result;
		if (ParamIndexToVal(3, flow_v))
			_o_return_result;
		mC->calcUV(I0, I1, flow_u, flow_v);
		return;
	}
	case M_getAlpha: {
		auto __retval = (double)mC->getAlpha();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getDelta: {
		auto __retval = (double)mC->getDelta();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getFixedPointIterations: {
		auto __retval = (__int64)mC->getFixedPointIterations();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getGamma: {
		auto __retval = (double)mC->getGamma();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getOmega: {
		auto __retval = (double)mC->getOmega();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getSorIterations: {
		auto __retval = (__int64)mC->getSorIterations();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_setAlpha: {
		float val;
		if (ParamIndexToVal(0, val))
			_o_return_result;
		mC->setAlpha(val);
		return;
	}
	case M_setDelta: {
		float val;
		if (ParamIndexToVal(0, val))
			_o_return_result;
		mC->setDelta(val);
		return;
	}
	case M_setFixedPointIterations: {
		int val;
		if (ParamIndexToVal(0, val))
			_o_return_result;
		mC->setFixedPointIterations(val);
		return;
	}
	case M_setGamma: {
		float val;
		if (ParamIndexToVal(0, val))
			_o_return_result;
		mC->setGamma(val);
		return;
	}
	case M_setOmega: {
		float val;
		if (ParamIndexToVal(0, val))
			_o_return_result;
		mC->setOmega(val);
		return;
	}
	case M_setSorIterations: {
		int val;
		if (ParamIndexToVal(0, val))
			_o_return_result;
		mC->setSorIterations(val);
		return;
	}
	}
}

void VideoCapture::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::VideoCapture>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		if (aParamCount == 0) {
			mC = new cv::VideoCapture();
			return;
		}
		else if (!MatchTypes("si?")) {
			cv::String filename;
			int apiPreference = cv::CAP_ANY;
			if (ParamIndexToVal(0, filename))
				_o_return_result;
			if (aParamCount > 1 && aParam[1]->symbol != SYM_MISSING)
				TokenToVal(*aParam[1], apiPreference);
			mC = new cv::VideoCapture(filename, apiPreference);
			return;
		}
		else if (!MatchTypes("sio")) {
			cv::String filename;
			int apiPreference;
			std::vector<int> params;
			if (ParamIndexToVal(0, filename))
				_o_return_result;
			if (ParamIndexToVal(1, apiPreference))
				_o_return_result;
			if (ParamIndexToVal(2, params))
				_o_return_result;
			mC = new cv::VideoCapture(filename, apiPreference, params);
			return;
		}
		else if (!MatchTypes("ii?")) {
			int index, apiPreference = cv::CAP_ANY;
			if (ParamIndexToVal(0, index))
				_o_return_result;
			if (aParamCount > 1 && aParam[1]->symbol != SYM_MISSING)
				TokenToVal(*aParam[1], apiPreference);
			mC = new cv::VideoCapture(index, apiPreference);
			return;
		}
		else if (!MatchTypes("iio")) {
			int index, apiPreference;
			std::vector<int> params;
			if (ParamIndexToVal(0, index))
				_o_return_result;
			if (ParamIndexToVal(1, apiPreference))
				_o_return_result;
			if (ParamIndexToVal(2, params))
				_o_return_result;
			mC = new cv::VideoCapture(index, apiPreference, params);
			return;
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case M_get: {
		int propId;
		if (ParamIndexToVal(0, propId))
			_o_return_result;
		auto __retval = mC->get(propId);
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getBackendName: {
		auto __retval = mC->getBackendName();
		return ValToResult(__retval, aResultToken);
	}
	case M_getExceptionMode: {
		auto __retval = (__int64)mC->getExceptionMode();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_grab: {
		auto __retval = (__int64)mC->grab();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_isOpened: {
		auto __retval = (__int64)mC->isOpened();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_open: {
		if (!MatchTypes("si?")) {
			cv::String filename;
			int apiPreference = cv::CAP_ANY;
			if (ParamIndexToVal(0, filename))
				_o_return_result;
			if (aParamCount > 1 && aParam[1]->symbol != SYM_MISSING)
				TokenToVal(*aParam[1], apiPreference);
			auto __retval = (__int64)mC->open(filename, apiPreference);
			return (void)(aResultToken.SetValue(__retval));
		}
		else if (!MatchTypes("sio")) {
			cv::String filename;
			int apiPreference;
			std::vector<int> params;
			if (ParamIndexToVal(0, filename))
				_o_return_result;
			if (ParamIndexToVal(1, apiPreference))
				_o_return_result;
			if (ParamIndexToVal(2, params))
				_o_return_result;
			auto __retval = (__int64)mC->open(filename, apiPreference, params);
			return (void)(aResultToken.SetValue(__retval));
		}
		else if (!MatchTypes("ii?")) {
			int index, apiPreference = cv::CAP_ANY;
			if (ParamIndexToVal(0, index))
				_o_return_result;
			if (aParamCount > 1 && aParam[1]->symbol != SYM_MISSING)
				TokenToVal(*aParam[1], apiPreference);
			auto __retval = (__int64)mC->open(index, apiPreference);
			return (void)(aResultToken.SetValue(__retval));
		}
		else if (!MatchTypes("iio")) {
			int index, apiPreference;
			std::vector<int> params;
			if (ParamIndexToVal(0, index))
				_o_return_result;
			if (ParamIndexToVal(1, apiPreference))
				_o_return_result;
			if (ParamIndexToVal(2, params))
				_o_return_result;
			auto __retval = (__int64)mC->open(index, apiPreference, params);
			return (void)(aResultToken.SetValue(__retval));
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case M_read: {
		cv::_OutputArray image;
		if (ParamIndexToVal(0, image))
			_o_return_result;
		auto __retval = (__int64)mC->read(image);
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_release: {
		mC->release();
		return;
	}
	case M_retrieve: {
		cv::_OutputArray image;
		int flag = 0;
		if (ParamIndexToVal(0, image))
			_o_return_result;
		if (aParamCount > 1 && aParam[1]->symbol != SYM_MISSING)
			TokenToVal(*aParam[1], flag);
		auto __retval = (__int64)mC->retrieve(image, flag);
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_set: {
		double value;
		int propId;
		if (ParamIndexToVal(0, propId))
			_o_return_result;
		if (ParamIndexToVal(1, value))
			_o_return_result;
		auto __retval = (__int64)mC->set(propId, value);
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_setExceptionMode: {
		bool enable;
		if (ParamIndexToVal(0, (char&)enable))
			_o_return_result;
		mC->setExceptionMode(enable);
		return;
	}
	}
}

void VideoWriter::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::VideoWriter>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		if (aParamCount == 0) {
			mC = new cv::VideoWriter();
			return;
		}
		else if (!MatchTypes("sifoi?")) {
			bool isColor = true;
			cv::Size frameSize;
			cv::String filename;
			double fps;
			int fourcc;
			if (ParamIndexToVal(0, filename))
				_o_return_result;
			if (ParamIndexToVal(1, fourcc))
				_o_return_result;
			if (ParamIndexToVal(2, fps))
				_o_return_result;
			if (ParamIndexToVal(3, frameSize))
				_o_return_result;
			if (aParamCount > 4 && aParam[4]->symbol != SYM_MISSING)
				TokenToVal(*aParam[4], (char&)isColor);
			mC = new cv::VideoWriter(filename, fourcc, fps, frameSize, isColor);
			return;
		}
		else if (!MatchTypes("siifoi?")) {
			bool isColor = true;
			cv::Size frameSize;
			cv::String filename;
			double fps;
			int apiPreference, fourcc;
			if (ParamIndexToVal(0, filename))
				_o_return_result;
			if (ParamIndexToVal(1, apiPreference))
				_o_return_result;
			if (ParamIndexToVal(2, fourcc))
				_o_return_result;
			if (ParamIndexToVal(3, fps))
				_o_return_result;
			if (ParamIndexToVal(4, frameSize))
				_o_return_result;
			if (aParamCount > 5 && aParam[5]->symbol != SYM_MISSING)
				TokenToVal(*aParam[5], (char&)isColor);
			mC = new cv::VideoWriter(filename, apiPreference, fourcc, fps, frameSize, isColor);
			return;
		}
		else if (!MatchTypes("sifoo")) {
			cv::Size frameSize;
			cv::String filename;
			double fps;
			int fourcc;
			std::vector<int> params;
			if (ParamIndexToVal(0, filename))
				_o_return_result;
			if (ParamIndexToVal(1, fourcc))
				_o_return_result;
			if (ParamIndexToVal(2, fps))
				_o_return_result;
			if (ParamIndexToVal(3, frameSize))
				_o_return_result;
			if (ParamIndexToVal(4, params))
				_o_return_result;
			mC = new cv::VideoWriter(filename, fourcc, fps, frameSize, params);
			return;
		}
		else if (!MatchTypes("siifoo")) {
			cv::Size frameSize;
			cv::String filename;
			double fps;
			int apiPreference, fourcc;
			std::vector<int> params;
			if (ParamIndexToVal(0, filename))
				_o_return_result;
			if (ParamIndexToVal(1, apiPreference))
				_o_return_result;
			if (ParamIndexToVal(2, fourcc))
				_o_return_result;
			if (ParamIndexToVal(3, fps))
				_o_return_result;
			if (ParamIndexToVal(4, frameSize))
				_o_return_result;
			if (ParamIndexToVal(5, params))
				_o_return_result;
			mC = new cv::VideoWriter(filename, apiPreference, fourcc, fps, frameSize, params);
			return;
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case M_fourcc: {
		char c1, c2, c3, c4;
		if (ParamIndexToVal(0, c1))
			_o_return_result;
		if (ParamIndexToVal(1, c2))
			_o_return_result;
		if (ParamIndexToVal(2, c3))
			_o_return_result;
		if (ParamIndexToVal(3, c4))
			_o_return_result;
		auto __retval = (__int64)mC->fourcc(c1, c2, c3, c4);
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_get: {
		int propId;
		if (ParamIndexToVal(0, propId))
			_o_return_result;
		auto __retval = mC->get(propId);
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getBackendName: {
		auto __retval = mC->getBackendName();
		return ValToResult(__retval, aResultToken);
	}
	case M_isOpened: {
		auto __retval = (__int64)mC->isOpened();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_open: {
		if (!MatchTypes("sifoi?")) {
			bool isColor = true;
			cv::Size frameSize;
			cv::String filename;
			double fps;
			int fourcc;
			if (ParamIndexToVal(0, filename))
				_o_return_result;
			if (ParamIndexToVal(1, fourcc))
				_o_return_result;
			if (ParamIndexToVal(2, fps))
				_o_return_result;
			if (ParamIndexToVal(3, frameSize))
				_o_return_result;
			if (aParamCount > 4 && aParam[4]->symbol != SYM_MISSING)
				TokenToVal(*aParam[4], (char&)isColor);
			auto __retval = (__int64)mC->open(filename, fourcc, fps, frameSize, isColor);
			return (void)(aResultToken.SetValue(__retval));
		}
		else if (!MatchTypes("siifoi?")) {
			bool isColor = true;
			cv::Size frameSize;
			cv::String filename;
			double fps;
			int apiPreference, fourcc;
			if (ParamIndexToVal(0, filename))
				_o_return_result;
			if (ParamIndexToVal(1, apiPreference))
				_o_return_result;
			if (ParamIndexToVal(2, fourcc))
				_o_return_result;
			if (ParamIndexToVal(3, fps))
				_o_return_result;
			if (ParamIndexToVal(4, frameSize))
				_o_return_result;
			if (aParamCount > 5 && aParam[5]->symbol != SYM_MISSING)
				TokenToVal(*aParam[5], (char&)isColor);
			auto __retval = (__int64)mC->open(filename, apiPreference, fourcc, fps, frameSize, isColor);
			return (void)(aResultToken.SetValue(__retval));
		}
		else if (!MatchTypes("sifoo")) {
			cv::Size frameSize;
			cv::String filename;
			double fps;
			int fourcc;
			std::vector<int> params;
			if (ParamIndexToVal(0, filename))
				_o_return_result;
			if (ParamIndexToVal(1, fourcc))
				_o_return_result;
			if (ParamIndexToVal(2, fps))
				_o_return_result;
			if (ParamIndexToVal(3, frameSize))
				_o_return_result;
			if (ParamIndexToVal(4, params))
				_o_return_result;
			auto __retval = (__int64)mC->open(filename, fourcc, fps, frameSize, params);
			return (void)(aResultToken.SetValue(__retval));
		}
		else if (!MatchTypes("siifoo")) {
			cv::Size frameSize;
			cv::String filename;
			double fps;
			int apiPreference, fourcc;
			std::vector<int> params;
			if (ParamIndexToVal(0, filename))
				_o_return_result;
			if (ParamIndexToVal(1, apiPreference))
				_o_return_result;
			if (ParamIndexToVal(2, fourcc))
				_o_return_result;
			if (ParamIndexToVal(3, fps))
				_o_return_result;
			if (ParamIndexToVal(4, frameSize))
				_o_return_result;
			if (ParamIndexToVal(5, params))
				_o_return_result;
			auto __retval = (__int64)mC->open(filename, apiPreference, fourcc, fps, frameSize, params);
			return (void)(aResultToken.SetValue(__retval));
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case M_release: {
		mC->release();
		return;
	}
	case M_set: {
		double value;
		int propId;
		if (ParamIndexToVal(0, propId))
			_o_return_result;
		if (ParamIndexToVal(1, value))
			_o_return_result;
		auto __retval = (__int64)mC->set(propId, value);
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_write: {
		cv::_InputArray image;
		if (ParamIndexToVal(0, image))
			_o_return_result;
		mC->write(image);
		return;
	}
	}
}

void WarperCreator::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: new (&mC) cv::Ptr<cv::WarperCreator>; return;
	}
}

void cuda_BufferPool::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::cuda::BufferPool>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		if (aParamCount) {
			cv::cuda::Stream* stream;
			if (ParamIndexToVal(0, stream))
				_o_return_result;
			mC = new cv::cuda::BufferPool(*stream);
		}
		else _o_invalid_param;
		return;
	}
	case M_getAllocator: {
		auto __retval = (cuda_GpuMat_Allocator*)cuda_GpuMat_Allocator::sPrototype->New(g_invalidparam, 1);
		__retval->mC = mC->getAllocator();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getBuffer: {
		if (aParamCount == 3) {
			int rows, cols, type;
			if (ParamIndexToVal(0, rows))
				_o_return_result;
			if (ParamIndexToVal(1, cols))
				_o_return_result;
			if (ParamIndexToVal(2, type))
				_o_return_result;
			auto __retval = (cuda_GpuMat*)cuda_GpuMat::sPrototype->New(g_invalidparam, 1);
			__retval->mC = mC->getBuffer(rows, cols, type);
			return (void)(aResultToken.SetValue(__retval));
		}
		else if (aParamCount == 2) {
			cv::Size size;
			int type;
			if (ParamIndexToVal(0, size))
				_o_return_result;
			if (ParamIndexToVal(1, type))
				_o_return_result;
			auto __retval = (cuda_GpuMat*)cuda_GpuMat::sPrototype->New(g_invalidparam, 1);
			__retval->mC = mC->getBuffer(size, type);
			return (void)(aResultToken.SetValue(__retval));
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	}
}

void cuda_DeviceInfo::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::cuda::DeviceInfo>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		if (aParamCount == 0) {
			mC = new cv::cuda::DeviceInfo();
			return;
		}
		else if (aParamCount == 1) {
			int device_id;
			if (ParamIndexToVal(0, device_id))
				_o_return_result;
			mC = new cv::cuda::DeviceInfo(device_id);
			return;
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case M_ECCEnabled: {
		auto __retval = (__int64)mC->ECCEnabled();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_asyncEngineCount: {
		auto __retval = (__int64)mC->asyncEngineCount();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_canMapHostMemory: {
		auto __retval = (__int64)mC->canMapHostMemory();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_clockRate: {
		auto __retval = (__int64)mC->clockRate();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_computeMode: {
		auto __retval = mC->computeMode();
		return ValToResult(__retval, aResultToken);
	}
	case M_concurrentKernels: {
		auto __retval = (__int64)mC->concurrentKernels();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_deviceID: {
		auto __retval = (__int64)mC->deviceID();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_freeMemory: {
		auto __retval = (__int64)mC->freeMemory();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_integrated: {
		auto __retval = (__int64)mC->integrated();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_isCompatible: {
		auto __retval = (__int64)mC->isCompatible();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_kernelExecTimeoutEnabled: {
		auto __retval = (__int64)mC->kernelExecTimeoutEnabled();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_l2CacheSize: {
		auto __retval = (__int64)mC->l2CacheSize();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_majorVersion: {
		auto __retval = (__int64)mC->majorVersion();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_maxGridSize: {
		auto __retval = mC->maxGridSize();
		return ValToResult(__retval, aResultToken);
	}
	case M_maxSurface1D: {
		auto __retval = (__int64)mC->maxSurface1D();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_maxSurface1DLayered: {
		auto __retval = mC->maxSurface1DLayered();
		return ValToResult(__retval, aResultToken);
	}
	case M_maxSurface2D: {
		auto __retval = mC->maxSurface2D();
		return ValToResult(__retval, aResultToken);
	}
	case M_maxSurface2DLayered: {
		auto __retval = mC->maxSurface2DLayered();
		return ValToResult(__retval, aResultToken);
	}
	case M_maxSurface3D: {
		auto __retval = mC->maxSurface3D();
		return ValToResult(__retval, aResultToken);
	}
	case M_maxSurfaceCubemap: {
		auto __retval = (__int64)mC->maxSurfaceCubemap();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_maxSurfaceCubemapLayered: {
		auto __retval = mC->maxSurfaceCubemapLayered();
		return ValToResult(__retval, aResultToken);
	}
	case M_maxTexture1D: {
		auto __retval = (__int64)mC->maxTexture1D();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_maxTexture1DLayered: {
		auto __retval = mC->maxTexture1DLayered();
		return ValToResult(__retval, aResultToken);
	}
	case M_maxTexture1DLinear: {
		auto __retval = (__int64)mC->maxTexture1DLinear();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_maxTexture1DMipmap: {
		auto __retval = (__int64)mC->maxTexture1DMipmap();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_maxTexture2D: {
		auto __retval = mC->maxTexture2D();
		return ValToResult(__retval, aResultToken);
	}
	case M_maxTexture2DGather: {
		auto __retval = mC->maxTexture2DGather();
		return ValToResult(__retval, aResultToken);
	}
	case M_maxTexture2DLayered: {
		auto __retval = mC->maxTexture2DLayered();
		return ValToResult(__retval, aResultToken);
	}
	case M_maxTexture2DLinear: {
		auto __retval = mC->maxTexture2DLinear();
		return ValToResult(__retval, aResultToken);
	}
	case M_maxTexture2DMipmap: {
		auto __retval = mC->maxTexture2DMipmap();
		return ValToResult(__retval, aResultToken);
	}
	case M_maxTexture3D: {
		auto __retval = mC->maxTexture3D();
		return ValToResult(__retval, aResultToken);
	}
	case M_maxTextureCubemap: {
		auto __retval = (__int64)mC->maxTextureCubemap();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_maxTextureCubemapLayered: {
		auto __retval = mC->maxTextureCubemapLayered();
		return ValToResult(__retval, aResultToken);
	}
	case M_maxThreadsDim: {
		auto __retval = mC->maxThreadsDim();
		return ValToResult(__retval, aResultToken);
	}
	case M_maxThreadsPerBlock: {
		auto __retval = (__int64)mC->maxThreadsPerBlock();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_maxThreadsPerMultiProcessor: {
		auto __retval = (__int64)mC->maxThreadsPerMultiProcessor();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_memPitch: {
		auto __retval = (__int64)mC->memPitch();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_memoryBusWidth: {
		auto __retval = (__int64)mC->memoryBusWidth();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_memoryClockRate: {
		auto __retval = (__int64)mC->memoryClockRate();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_minorVersion: {
		auto __retval = (__int64)mC->minorVersion();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_multiProcessorCount: {
		auto __retval = (__int64)mC->multiProcessorCount();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_pciBusID: {
		auto __retval = (__int64)mC->pciBusID();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_pciDeviceID: {
		auto __retval = (__int64)mC->pciDeviceID();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_pciDomainID: {
		auto __retval = (__int64)mC->pciDomainID();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_queryMemory: {
		size_t totalMemory, freeMemory;
		if (ParamIndexToVal(0, (intptr_t&)totalMemory))
			_o_return_result;
		if (ParamIndexToVal(1, (intptr_t&)freeMemory))
			_o_return_result;
		mC->queryMemory(totalMemory, freeMemory);
		return;
	}
	case M_regsPerBlock: {
		auto __retval = (__int64)mC->regsPerBlock();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_sharedMemPerBlock: {
		auto __retval = (__int64)mC->sharedMemPerBlock();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_surfaceAlignment: {
		auto __retval = (__int64)mC->surfaceAlignment();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_tccDriver: {
		auto __retval = (__int64)mC->tccDriver();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_textureAlignment: {
		auto __retval = (__int64)mC->textureAlignment();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_texturePitchAlignment: {
		auto __retval = (__int64)mC->texturePitchAlignment();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_totalConstMem: {
		auto __retval = (__int64)mC->totalConstMem();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_totalGlobalMem: {
		auto __retval = (__int64)mC->totalGlobalMem();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_totalMemory: {
		auto __retval = (__int64)mC->totalMemory();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_unifiedAddressing: {
		auto __retval = (__int64)mC->unifiedAddressing();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_warpSize: {
		auto __retval = (__int64)mC->warpSize();
		return (void)(aResultToken.SetValue(__retval));
	}
	}
}

void cuda_Event::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::cuda::Event>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		int flags = cv::cuda::Event::CreateFlags::DEFAULT;
		if (aParamCount > 0 && aParam[0]->symbol != SYM_MISSING)
			TokenToVal(*aParam[0], flags);
		mC = new cv::cuda::Event((cv::cuda::Event::CreateFlags)flags);
		return;
	}
	case M_elapsedTime: {
		cv::cuda::Event* start, * end;
		if (ParamIndexToVal(0, start))
			_o_return_result;
		if (ParamIndexToVal(1, end))
			_o_return_result;
		auto __retval = (double)mC->elapsedTime(*start, *end);
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_queryIfComplete: {
		auto __retval = (__int64)mC->queryIfComplete();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_record: {
		cv::cuda::Stream _stream = cv::cuda::Stream::Null(), * stream = &_stream;
		if (aParamCount > 0 && aParam[0]->symbol != SYM_MISSING)
			TokenToVal(*aParam[0], stream);
		mC->record(*stream);
		return;
	}
	case M_waitForCompletion: {
		mC->waitForCompletion();
		return;
	}
	}
}

void cuda_GpuMat::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC.~GpuMat(); return;
	case M___New: {
		new (&mC) cv::Ptr<cv::cuda::GpuMat>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		if (!MatchTypes("o?")) {
			cv::cuda::GpuMat::Allocator* allocator = cv::cuda::GpuMat::defaultAllocator();
			if (aParamCount > 0 && aParam[0]->symbol != SYM_MISSING)
				TokenToVal(*aParam[0], allocator);
			new (&mC) cv::cuda::GpuMat(allocator);
			return;
		}
		else if (!MatchTypes("iiio?")) {
			cv::cuda::GpuMat::Allocator* allocator = cv::cuda::GpuMat::defaultAllocator();
			int rows, cols, type;
			if (ParamIndexToVal(0, rows))
				_o_return_result;
			if (ParamIndexToVal(1, cols))
				_o_return_result;
			if (ParamIndexToVal(2, type))
				_o_return_result;
			if (aParamCount > 3 && aParam[3]->symbol != SYM_MISSING)
				TokenToVal(*aParam[3], allocator);
			new (&mC) cv::cuda::GpuMat(rows, cols, type, allocator);
			return;
		}
		else if (!MatchTypes("oio?")) {
			cv::Size size;
			cv::cuda::GpuMat::Allocator* allocator = cv::cuda::GpuMat::defaultAllocator();
			int type;
			if (ParamIndexToVal(0, size))
				_o_return_result;
			if (ParamIndexToVal(1, type))
				_o_return_result;
			if (aParamCount > 2 && aParam[2]->symbol != SYM_MISSING)
				TokenToVal(*aParam[2], allocator);
			new (&mC) cv::cuda::GpuMat(size, type, allocator);
			return;
		}
		else if (!MatchTypes("iiioo?")) {
			cv::Scalar s;
			cv::cuda::GpuMat::Allocator* allocator = cv::cuda::GpuMat::defaultAllocator();
			int rows, cols, type;
			if (ParamIndexToVal(0, rows))
				_o_return_result;
			if (ParamIndexToVal(1, cols))
				_o_return_result;
			if (ParamIndexToVal(2, type))
				_o_return_result;
			if (ParamIndexToVal(3, s))
				_o_return_result;
			if (aParamCount > 4 && aParam[4]->symbol != SYM_MISSING)
				TokenToVal(*aParam[4], allocator);
			new (&mC) cv::cuda::GpuMat(rows, cols, type, s, allocator);
			return;
		}
		else if (!MatchTypes("oioo?")) {
			cv::Scalar s;
			cv::Size size;
			cv::cuda::GpuMat::Allocator* allocator = cv::cuda::GpuMat::defaultAllocator();
			int type;
			if (ParamIndexToVal(0, size))
				_o_return_result;
			if (ParamIndexToVal(1, type))
				_o_return_result;
			if (ParamIndexToVal(2, s))
				_o_return_result;
			if (aParamCount > 3 && aParam[3]->symbol != SYM_MISSING)
				TokenToVal(*aParam[3], allocator);
			new (&mC) cv::cuda::GpuMat(size, type, s, allocator);
			return;
		}
		else if (!MatchTypes("o")) {
			cv::cuda::GpuMat* m;
			if (ParamIndexToVal(0, m))
				_o_return_result;
			new (&mC) cv::cuda::GpuMat(*m);
			return;
		}
		else if (!MatchTypes("ooo")) {
			cv::Range rowRange, colRange;
			cv::cuda::GpuMat* m;
			if (ParamIndexToVal(0, m))
				_o_return_result;
			if (ParamIndexToVal(1, rowRange))
				_o_return_result;
			if (ParamIndexToVal(2, colRange))
				_o_return_result;
			new (&mC) cv::cuda::GpuMat(*m, rowRange, colRange);
			return;
		}
		else if (!MatchTypes("oo")) {
			cv::Rect roi;
			cv::cuda::GpuMat* m;
			if (ParamIndexToVal(0, m))
				_o_return_result;
			if (ParamIndexToVal(1, roi))
				_o_return_result;
			new (&mC) cv::cuda::GpuMat(*m, roi);
			return;
		}
		else if (!MatchTypes("oo?")) {
			cv::_InputArray arr;
			cv::cuda::GpuMat::Allocator* allocator = cv::cuda::GpuMat::defaultAllocator();
			if (ParamIndexToVal(0, arr))
				_o_return_result;
			if (aParamCount > 1 && aParam[1]->symbol != SYM_MISSING)
				TokenToVal(*aParam[1], allocator);
			new (&mC) cv::cuda::GpuMat(arr, allocator);
			return;
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case M_adjustROI: {
		int dtop, dbottom, dleft, dright;
		if (ParamIndexToVal(0, dtop))
			_o_return_result;
		if (ParamIndexToVal(1, dbottom))
			_o_return_result;
		if (ParamIndexToVal(2, dleft))
			_o_return_result;
		if (ParamIndexToVal(3, dright))
			_o_return_result;
		mC.adjustROI(dtop, dbottom, dleft, dright);
		aResultToken.SetValue(this);
		AddRef();
		return;
	}
	case M_assignTo: {
		cv::cuda::GpuMat* m;
		int type = -1;
		if (ParamIndexToVal(0, m))
			_o_return_result;
		if (aParamCount > 1 && aParam[1]->symbol != SYM_MISSING)
			TokenToVal(*aParam[1], type);
		mC.assignTo(*m, type);
		return;
	}
	case P_channels: {
		auto __retval = (__int64)mC.channels();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_clone: {
		auto __retval = (cuda_GpuMat*)cuda_GpuMat::sPrototype->New(g_invalidparam, 1);
		__retval->mC = mC.clone();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_col: {
		int x;
		if (ParamIndexToVal(0, x))
			_o_return_result;
		auto __retval = (cuda_GpuMat*)cuda_GpuMat::sPrototype->New(g_invalidparam, 1);
		__retval->mC = mC.col(x);
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_colRange: {
		if (aParamCount == 2) {
			int startcol, endcol;
			if (ParamIndexToVal(0, startcol))
				_o_return_result;
			if (ParamIndexToVal(1, endcol))
				_o_return_result;
			auto __retval = (cuda_GpuMat*)cuda_GpuMat::sPrototype->New(g_invalidparam, 1);
			__retval->mC = mC.colRange(startcol, endcol);
			return (void)(aResultToken.SetValue(__retval));
		}
		else if (aParamCount == 1) {
			cv::Range r;
			if (ParamIndexToVal(0, r))
				_o_return_result;
			auto __retval = (cuda_GpuMat*)cuda_GpuMat::sPrototype->New(g_invalidparam, 1);
			__retval->mC = mC.colRange(r);
			return (void)(aResultToken.SetValue(__retval));
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case M_convertTo: {
		if (!MatchTypes("oi")) {
			cv::_OutputArray dst;
			int rtype;
			if (ParamIndexToVal(0, dst))
				_o_return_result;
			if (ParamIndexToVal(1, rtype))
				_o_return_result;
			mC.convertTo(dst, rtype);
			return;
		}
		else if (!MatchTypes("oio")) {
			cv::_OutputArray dst;
			cv::cuda::Stream* stream;
			int rtype;
			if (ParamIndexToVal(0, dst))
				_o_return_result;
			if (ParamIndexToVal(1, rtype))
				_o_return_result;
			if (ParamIndexToVal(2, stream))
				_o_return_result;
			mC.convertTo(dst, rtype, *stream);
			return;
		}
		else if (!MatchTypes("oiff?")) {
			cv::_OutputArray dst;
			double alpha, beta = 0.0;
			int rtype;
			if (ParamIndexToVal(0, dst))
				_o_return_result;
			if (ParamIndexToVal(1, rtype))
				_o_return_result;
			if (ParamIndexToVal(2, alpha))
				_o_return_result;
			if (aParamCount > 3 && aParam[3]->symbol != SYM_MISSING)
				TokenToVal(*aParam[3], beta);
			mC.convertTo(dst, rtype, alpha, beta);
			return;
		}
		else if (!MatchTypes("oifo")) {
			cv::_OutputArray dst;
			cv::cuda::Stream* stream;
			double alpha;
			int rtype;
			if (ParamIndexToVal(0, dst))
				_o_return_result;
			if (ParamIndexToVal(1, rtype))
				_o_return_result;
			if (ParamIndexToVal(2, alpha))
				_o_return_result;
			if (ParamIndexToVal(3, stream))
				_o_return_result;
			mC.convertTo(dst, rtype, alpha, *stream);
			return;
		}
		else if (!MatchTypes("oiffo")) {
			cv::_OutputArray dst;
			cv::cuda::Stream* stream;
			double alpha, beta;
			int rtype;
			if (ParamIndexToVal(0, dst))
				_o_return_result;
			if (ParamIndexToVal(1, rtype))
				_o_return_result;
			if (ParamIndexToVal(2, alpha))
				_o_return_result;
			if (ParamIndexToVal(3, beta))
				_o_return_result;
			if (ParamIndexToVal(4, stream))
				_o_return_result;
			mC.convertTo(dst, rtype, alpha, beta, *stream);
			return;
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case M_copyTo: {
		if (aParamCount == 1) {
			cv::_OutputArray dst;
			if (ParamIndexToVal(0, dst))
				_o_return_result;
			mC.copyTo(dst);
			return;
		}
		else if (aParamCount == 2) {
			cv::_OutputArray dst;
			cv::cuda::Stream* stream = nullptr;
			cv::_InputArray mask;
			if (ParamIndexToVal(0, dst))
				_o_return_result;
			if (ParamIndexToVal(1, stream, true) && stream)
				mC.copyTo(dst, *stream);
			else {
				if (ParamIndexToVal(1, mask))
					_o_return_result;
				mC.copyTo(dst, mask);
			}
			return;
		}
		else if (aParamCount == 3) {
			cv::_InputArray mask;
			cv::_OutputArray dst;
			cv::cuda::Stream* stream;
			if (ParamIndexToVal(0, dst))
				_o_return_result;
			if (ParamIndexToVal(1, mask))
				_o_return_result;
			if (ParamIndexToVal(2, stream))
				_o_return_result;
			mC.copyTo(dst, mask, *stream);
			return;
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case M_create: {
		if (aParamCount == 3) {
			int rows, cols, type;
			if (ParamIndexToVal(0, rows))
				_o_return_result;
			if (ParamIndexToVal(1, cols))
				_o_return_result;
			if (ParamIndexToVal(2, type))
				_o_return_result;
			mC.create(rows, cols, type);
			return;
		}
		else if (aParamCount == 2) {
			cv::Size size;
			int type;
			if (ParamIndexToVal(0, size))
				_o_return_result;
			if (ParamIndexToVal(1, type))
				_o_return_result;
			mC.create(size, type);
			return;
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case M_cudaPtr: {
		auto __retval = (__int64)mC.cudaPtr();
		return (void)aResultToken.SetValue(__retval);
	}
	case M_defaultAllocator: {
		auto __retval = (cuda_GpuMat_Allocator*)cuda_GpuMat_Allocator::sPrototype->New(g_invalidparam, 1);
		__retval->mC = mC.defaultAllocator();
		return (void)(aResultToken.SetValue(__retval));
	}
	case P_depth: {
		auto __retval = (__int64)mC.depth();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_download: {
		if (aParamCount == 1) {
			cv::_OutputArray dst;
			if (ParamIndexToVal(0, dst))
				_o_return_result;
			mC.download(dst);
			return;
		}
		else if (aParamCount == 2) {
			cv::_OutputArray dst;
			cv::cuda::Stream* stream;
			if (ParamIndexToVal(0, dst))
				_o_return_result;
			if (ParamIndexToVal(1, stream))
				_o_return_result;
			mC.download(dst, *stream);
			return;
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case P_elemSize: {
		auto __retval = (__int64)mC.elemSize();
		return (void)(aResultToken.SetValue(__retval));
	}
	case P_elemSize1: {
		auto __retval = (__int64)mC.elemSize1();
		return (void)(aResultToken.SetValue(__retval));
	}
	case P_empty: {
		auto __retval = (__int64)mC.empty();
		return (void)(aResultToken.SetValue(__retval));
	}
	case P_isContinuous: {
		auto __retval = (__int64)mC.isContinuous();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_locateROI: {
		cv::Point ofs;
		cv::Size wholeSize;
		if (ParamIndexToVal(0, wholeSize))
			_o_return_result;
		if (ParamIndexToVal(1, ofs))
			_o_return_result;
		mC.locateROI(wholeSize, ofs);
		return;
	}
	case M_reshape: {
		int cn, rows = 0;
		if (ParamIndexToVal(0, cn))
			_o_return_result;
		if (aParamCount > 1 && aParam[1]->symbol != SYM_MISSING)
			TokenToVal(*aParam[1], rows);
		auto __retval = (cuda_GpuMat*)cuda_GpuMat::sPrototype->New(g_invalidparam, 1);
		__retval->mC = mC.reshape(cn, rows);
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_row: {
		int y;
		if (ParamIndexToVal(0, y))
			_o_return_result;
		auto __retval = (cuda_GpuMat*)cuda_GpuMat::sPrototype->New(g_invalidparam, 1);
		__retval->mC = mC.row(y);
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_rowRange: {
		if (aParamCount == 2) {
			int startrow, endrow;
			if (ParamIndexToVal(0, startrow))
				_o_return_result;
			if (ParamIndexToVal(1, endrow))
				_o_return_result;
			auto __retval = (cuda_GpuMat*)cuda_GpuMat::sPrototype->New(g_invalidparam, 1);
			__retval->mC = mC.rowRange(startrow, endrow);
			return (void)(aResultToken.SetValue(__retval));
		}
		else if (aParamCount == 1) {
			cv::Range r;
			if (ParamIndexToVal(0, r))
				_o_return_result;
			auto __retval = (cuda_GpuMat*)cuda_GpuMat::sPrototype->New(g_invalidparam, 1);
			__retval->mC = mC.rowRange(r);
			return (void)(aResultToken.SetValue(__retval));
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case M_setDefaultAllocator: {
		cv::cuda::GpuMat::Allocator* allocator;
		if (ParamIndexToVal(0, allocator))
			_o_return_result;
		mC.setDefaultAllocator(allocator);
		return;
	}
	case M_setTo: {
		if (aParamCount == 1) {
			cv::Scalar s;
			if (ParamIndexToVal(0, s))
				_o_return_result;
			mC.setTo(s);
			aResultToken.SetValue(this);
			AddRef();
			return;
		}
		else if (aParamCount == 2) {
			cv::Scalar s;
			cv::cuda::Stream* stream = nullptr;
			cv::_InputArray mask;
			if (ParamIndexToVal(0, s))
				_o_return_result;
			if (ParamIndexToVal(1, stream, true) && stream)
				mC.setTo(s, *stream);
			else {
				if (ParamIndexToVal(1, mask))
					_o_return_result;
				mC.setTo(s, mask);
			}
			aResultToken.SetValue(this);
			AddRef();
			return;
		}
		else if (aParamCount == 3) {
			cv::_InputArray mask;
			cv::Scalar s;
			cv::cuda::Stream* stream;
			if (ParamIndexToVal(0, s))
				_o_return_result;
			if (ParamIndexToVal(1, mask))
				_o_return_result;
			if (ParamIndexToVal(2, stream))
				_o_return_result;
			mC.setTo(s, mask, *stream);
			aResultToken.SetValue(this);
			AddRef();
			return;
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case P_size: {
		auto __retval = mC.size();
		return ValToResult(__retval, aResultToken);
	}
	case P_step1: {
		auto __retval = (__int64)mC.step1();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_swap: {
		cv::cuda::GpuMat* mat;
		if (ParamIndexToVal(0, mat))
			_o_return_result;
		mC.swap(*mat);
		return;
	}
	case P_type: {
		auto __retval = (__int64)mC.type();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_updateContinuityFlag: {
		mC.updateContinuityFlag();
		return;
	}
	case M_upload: {
		if (aParamCount == 1) {
			cv::_InputArray arr;
			if (ParamIndexToVal(0, arr))
				_o_return_result;
			mC.upload(arr);
			return;
		}
		else if (aParamCount == 2) {
			cv::_InputArray arr;
			cv::cuda::Stream* stream;
			if (ParamIndexToVal(0, arr))
				_o_return_result;
			if (ParamIndexToVal(1, stream))
				_o_return_result;
			mC.upload(arr, *stream);
			return;
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	}
}

void cuda_GpuMat_Allocator::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: new (&mC) cv::Ptr<cv::cuda::GpuMat::Allocator>; return;
	}
}

void cuda_GpuMatND::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: new (&mC) cv::Ptr<cv::cuda::GpuMatND>; return;
	}
}

void cuda_HostMem::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC.~HostMem(); return;
	case M___New: {
		new (&mC) cv::cuda::HostMem;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		if (!MatchTypes("o?")) {
			int alloc_type = cv::cuda::HostMem::AllocType::PAGE_LOCKED;
			if (aParamCount > 0 && aParam[0]->symbol != SYM_MISSING)
				TokenToVal(*aParam[0], alloc_type);
			new (&mC) cv::cuda::HostMem((cv::cuda::HostMem::AllocType)alloc_type);
			return;
		}
		else if (!MatchTypes("iiio?")) {
			int rows, cols, type, alloc_type = cv::cuda::HostMem::AllocType::PAGE_LOCKED;
			if (ParamIndexToVal(0, rows))
				_o_return_result;
			if (ParamIndexToVal(1, cols))
				_o_return_result;
			if (ParamIndexToVal(2, type))
				_o_return_result;
			if (aParamCount > 3 && aParam[3]->symbol != SYM_MISSING)
				TokenToVal(*aParam[3], alloc_type);
			new (&mC) cv::cuda::HostMem(rows, cols, type, (cv::cuda::HostMem::AllocType)alloc_type);
			return;
		}
		else if (!MatchTypes("oio?")) {
			cv::Size size;
			int type, alloc_type = cv::cuda::HostMem::AllocType::PAGE_LOCKED;
			if (ParamIndexToVal(0, size))
				_o_return_result;
			if (ParamIndexToVal(1, type))
				_o_return_result;
			if (aParamCount > 2 && aParam[2]->symbol != SYM_MISSING)
				TokenToVal(*aParam[2], alloc_type);
			new (&mC) cv::cuda::HostMem(size, type, (cv::cuda::HostMem::AllocType)alloc_type);
			return;
		}
		else if (!MatchTypes("oo?")) {
			cv::_InputArray arr;
			int alloc_type = cv::cuda::HostMem::AllocType::PAGE_LOCKED;
			if (ParamIndexToVal(0, arr))
				_o_return_result;
			if (aParamCount > 1 && aParam[1]->symbol != SYM_MISSING)
				TokenToVal(*aParam[1], alloc_type);
			new (&mC) cv::cuda::HostMem(arr, (cv::cuda::HostMem::AllocType)alloc_type);
			return;
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case P_channels: {
		auto __retval = (__int64)mC.channels();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_clone: {
		auto __retval = (cuda_HostMem*)cuda_HostMem::sPrototype->New(g_invalidparam, 1);
		__retval->mC = mC.clone();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_create: {
		int rows, cols, type;
		if (ParamIndexToVal(0, rows))
			_o_return_result;
		if (ParamIndexToVal(1, cols))
			_o_return_result;
		if (ParamIndexToVal(2, type))
			_o_return_result;
		mC.create(rows, cols, type);
		return;
	}
	case M_createMatHeader: {
		auto __retval = (Mat*)Mat::sPrototype->New(g_invalidparam, 1);
		__retval->mC = mC.createMatHeader();
		return (void)(aResultToken.SetValue(__retval));
	}
	case P_depth: {
		auto __retval = (__int64)mC.depth();
		return (void)(aResultToken.SetValue(__retval));
	}
	case P_elemSize: {
		auto __retval = (__int64)mC.elemSize();
		return (void)(aResultToken.SetValue(__retval));
	}
	case P_elemSize1: {
		auto __retval = (__int64)mC.elemSize1();
		return (void)(aResultToken.SetValue(__retval));
	}
	case P_empty: {
		auto __retval = (__int64)mC.empty();
		return (void)(aResultToken.SetValue(__retval));
	}
	case P_isContinuous: {
		auto __retval = (__int64)mC.isContinuous();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_reshape: {
		int cn, rows = 0;
		if (ParamIndexToVal(0, cn))
			_o_return_result;
		if (aParamCount > 1 && aParam[1]->symbol != SYM_MISSING)
			TokenToVal(*aParam[1], rows);
		auto __retval = (cuda_HostMem*)cuda_HostMem::sPrototype->New(g_invalidparam, 1);
		__retval->mC = mC.reshape(cn, rows);
		return (void)(aResultToken.SetValue(__retval));
	}
	case P_size: {
		auto __retval = mC.size();
		return ValToResult(__retval, aResultToken);
	}
	case P_step1: {
		auto __retval = (__int64)mC.step1();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_swap: {
		cv::cuda::HostMem* b;
		if (ParamIndexToVal(0, b))
			_o_return_result;
		mC.swap(*b);
		return;
	}
	case P_type: {
		auto __retval = (__int64)mC.type();
		return (void)(aResultToken.SetValue(__retval));
	}
	}
}

void cuda_Stream::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::cuda::Stream>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		if (aParamCount == 0) {
			mC = new cv::cuda::Stream();
			return;
		}
		else if (!MatchTypes("o")) {
			cv::Ptr<cv::cuda::GpuMat::Allocator> allocator;
			if (ParamIndexToVal(0, allocator))
				_o_return_result;
			mC = new cv::cuda::Stream(allocator);
			return;
		}
		else if (!MatchTypes("i")) {
			size_t cudaFlags;
			if (ParamIndexToVal(0, (intptr_t&)cudaFlags))
				_o_return_result;
			mC = new cv::cuda::Stream(cudaFlags);
			return;
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case M_Null: {
		auto __retval = (cuda_Stream*)cuda_Stream::sPrototype->New(g_invalidparam, 1);
		__retval->mC = cv::makePtr<cv::cuda::Stream>(cv::cuda::Stream::Null());
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_cudaPtr: {
		auto __retval = (__int64)mC->cudaPtr();
		return (void)aResultToken.SetValue(__retval);
	}
	case M_queryIfComplete: {
		auto __retval = (__int64)mC->queryIfComplete();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_waitEvent: {
		cv::cuda::Event* event;
		if (ParamIndexToVal(0, event))
			_o_return_result;
		mC->waitEvent(*event);
		return;
	}
	case M_waitForCompletion: {
		mC->waitForCompletion();
		return;
	}
	}
}

void cuda_TargetArchs::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: new (&mC) cv::Ptr<cv::cuda::TargetArchs>;	return;
	case M_has: {
		int major, minor;
		if (ParamIndexToVal(0, major))
			_o_return_result;
		if (ParamIndexToVal(1, minor))
			_o_return_result;
		auto __retval = (__int64)cv::cuda::TargetArchs::has(major, minor);
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_hasBin: {
		int major, minor;
		if (ParamIndexToVal(0, major))
			_o_return_result;
		if (ParamIndexToVal(1, minor))
			_o_return_result;
		auto __retval = (__int64)cv::cuda::TargetArchs::hasBin(major, minor);
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_hasEqualOrGreater: {
		int major, minor;
		if (ParamIndexToVal(0, major))
			_o_return_result;
		if (ParamIndexToVal(1, minor))
			_o_return_result;
		auto __retval = (__int64)cv::cuda::TargetArchs::hasEqualOrGreater(major, minor);
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_hasEqualOrGreaterBin: {
		int major, minor;
		if (ParamIndexToVal(0, major))
			_o_return_result;
		if (ParamIndexToVal(1, minor))
			_o_return_result;
		auto __retval = (__int64)cv::cuda::TargetArchs::hasEqualOrGreaterBin(major, minor);
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_hasEqualOrGreaterPtx: {
		int major, minor;
		if (ParamIndexToVal(0, major))
			_o_return_result;
		if (ParamIndexToVal(1, minor))
			_o_return_result;
		auto __retval = (__int64)cv::cuda::TargetArchs::hasEqualOrGreaterPtx(major, minor);
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_hasEqualOrLessPtx: {
		int major, minor;
		if (ParamIndexToVal(0, major))
			_o_return_result;
		if (ParamIndexToVal(1, minor))
			_o_return_result;
		auto __retval = (__int64)cv::cuda::TargetArchs::hasEqualOrLessPtx(major, minor);
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_hasPtx: {
		int major, minor;
		if (ParamIndexToVal(0, major))
			_o_return_result;
		if (ParamIndexToVal(1, minor))
			_o_return_result;
		auto __retval = (__int64)cv::cuda::TargetArchs::hasPtx(major, minor);
		return (void)(aResultToken.SetValue(__retval));
	}
	}
}

void detail_AffineBasedEstimator::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::detail::AffineBasedEstimator>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		mC = new cv::detail::AffineBasedEstimator();
		return;
	}
	}
}

void detail_AffineBestOf2NearestMatcher::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::detail::AffineBestOf2NearestMatcher>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		bool full_affine = false, try_use_gpu = false;
		float match_conf = 0.3f;
		int num_matches_thresh1 = 6;
		if (aParamCount > 0 && aParam[0]->symbol != SYM_MISSING)
			TokenToVal(*aParam[0], (char&)full_affine);
		if (aParamCount > 1 && aParam[1]->symbol != SYM_MISSING)
			TokenToVal(*aParam[1], (char&)try_use_gpu);
		if (aParamCount > 2 && aParam[2]->symbol != SYM_MISSING)
			TokenToVal(*aParam[2], match_conf);
		if (aParamCount > 3 && aParam[3]->symbol != SYM_MISSING)
			TokenToVal(*aParam[3], num_matches_thresh1);
		mC = new cv::detail::AffineBestOf2NearestMatcher(full_affine, try_use_gpu, match_conf, num_matches_thresh1);
		return;
	}
	}
}

void detail_BestOf2NearestMatcher::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::detail::BestOf2NearestMatcher>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		bool try_use_gpu = false;
		float match_conf = 0.3f;
		int num_matches_thresh1 = 6, num_matches_thresh2 = 6;
		if (aParamCount > 0 && aParam[0]->symbol != SYM_MISSING)
			TokenToVal(*aParam[0], (char&)try_use_gpu);
		if (aParamCount > 1 && aParam[1]->symbol != SYM_MISSING)
			TokenToVal(*aParam[1], match_conf);
		if (aParamCount > 2 && aParam[2]->symbol != SYM_MISSING)
			TokenToVal(*aParam[2], num_matches_thresh1);
		if (aParamCount > 3 && aParam[3]->symbol != SYM_MISSING)
			TokenToVal(*aParam[3], num_matches_thresh2);
		mC = new cv::detail::BestOf2NearestMatcher(try_use_gpu, match_conf, num_matches_thresh1, num_matches_thresh2);
		return;
	}
	case M_collectGarbage: {
		mC->collectGarbage();
		return;
	}
	}
}

void detail_BestOf2NearestRangeMatcher::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::detail::BestOf2NearestRangeMatcher>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		bool try_use_gpu = false;
		float match_conf = 0.3f;
		int range_width = 5, num_matches_thresh1 = 6, num_matches_thresh2 = 6;
		if (aParamCount > 0 && aParam[0]->symbol != SYM_MISSING)
			TokenToVal(*aParam[0], range_width);
		if (aParamCount > 1 && aParam[1]->symbol != SYM_MISSING)
			TokenToVal(*aParam[1], (char&)try_use_gpu);
		if (aParamCount > 2 && aParam[2]->symbol != SYM_MISSING)
			TokenToVal(*aParam[2], match_conf);
		if (aParamCount > 3 && aParam[3]->symbol != SYM_MISSING)
			TokenToVal(*aParam[3], num_matches_thresh1);
		if (aParamCount > 4 && aParam[4]->symbol != SYM_MISSING)
			TokenToVal(*aParam[4], num_matches_thresh2);
		mC = new cv::detail::BestOf2NearestRangeMatcher(range_width, try_use_gpu, match_conf, num_matches_thresh1, num_matches_thresh2);
		return;
	}
	}
}

void detail_Blender::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::detail::Blender>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		bool try_gpu = false;
		int type;
		if (!aParamCount || aParamCount > 2)
			_o_invalid_param;
		if (ParamIndexToVal(0, type))
			_o_return_result;
		if (aParamCount > 1 && aParam[1]->symbol != SYM_MISSING)
			TokenToVal(*aParam[1], (char&)try_gpu);
		mC = cv::detail::Blender::createDefault(type, try_gpu);
		return;
	}
	case M_blend: {
		cv::_InputOutputArray dst, dst_mask;
		if (ParamIndexToVal(0, dst))
			_o_return_result;
		if (ParamIndexToVal(1, dst_mask))
			_o_return_result;
		mC->blend(dst, dst_mask);
		return;
	}
	case M_feed: {
		cv::_InputArray img, mask;
		cv::Point tl;
		if (ParamIndexToVal(0, img))
			_o_return_result;
		if (ParamIndexToVal(1, mask))
			_o_return_result;
		if (ParamIndexToVal(2, tl))
			_o_return_result;
		mC->feed(img, mask, tl);
		return;
	}
	case M_prepare: {
		if (aParamCount == 2) {
			std::vector<cv::Point> corners;
			std::vector<cv::Size> sizes;
			if (ParamIndexToVal(0, corners))
				_o_return_result;
			if (ParamIndexToVal(1, sizes))
				_o_return_result;
			mC->prepare(corners, sizes);
			return;
		}
		else if (aParamCount == 1) {
			cv::Rect dst_roi;
			if (ParamIndexToVal(0, dst_roi))
				_o_return_result;
			mC->prepare(dst_roi);
			return;
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	}
}

void detail_BlocksChannelsCompensator::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::detail::BlocksChannelsCompensator>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		int bl_width = 32, bl_height = 32, nr_feeds = 1;
		if (aParamCount > 0 && aParam[0]->symbol != SYM_MISSING)
			TokenToVal(*aParam[0], bl_width);
		if (aParamCount > 1 && aParam[1]->symbol != SYM_MISSING)
			TokenToVal(*aParam[1], bl_height);
		if (aParamCount > 2 && aParam[2]->symbol != SYM_MISSING)
			TokenToVal(*aParam[2], nr_feeds);
		mC = new cv::detail::BlocksChannelsCompensator(bl_width, bl_height, nr_feeds);
		return;
	}
	}
}

void detail_BlocksCompensator::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::detail::BlocksChannelsCompensator>;
		int bl_width = 32, bl_height = 32, nr_feeds = 1;
		if (aParamCount)
			TokenToVal(*aParam[0], bl_width, 2);
		if (aParamCount > 1)
			TokenToVal(*aParam[1], bl_height, 2);
		if (aParamCount > 2)
			TokenToVal(*aParam[2], nr_feeds, 2);
		mC = new cv::detail::BlocksChannelsCompensator(bl_width, bl_height, nr_feeds);
		return;
	}
	case M_apply: {
		cv::_InputArray mask;
		cv::_InputOutputArray image;
		cv::Point corner;
		int index;
		if (ParamIndexToVal(0, index))
			_o_return_result;
		if (ParamIndexToVal(1, corner))
			_o_return_result;
		if (ParamIndexToVal(2, image))
			_o_return_result;
		if (ParamIndexToVal(3, mask))
			_o_return_result;
		mC->apply(index, corner, image, mask);
		return;
	}
	case M_getBlockSize: {
		auto __retval = mC->getBlockSize();
		return ValToResult(__retval, aResultToken);
	}
	case M_getMatGains: {
		std::vector<cv::Mat> umv;
		VarRef* var_umv = nullptr;
		if (ParamIndexToVal(0, var_umv))
			_o_return_result;
		mC->getMatGains(umv);
		ValToResult(umv, aResultToken);
		g_ahkapi->VarAssign(var_umv, aResultToken);
		g_ahkapi->ResultTokenFree(aResultToken);
		return;
	}
	case M_getNrFeeds: {
		auto __retval = (__int64)mC->getNrFeeds();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getNrGainsFilteringIterations: {
		auto __retval = (__int64)mC->getNrGainsFilteringIterations();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getSimilarityThreshold: {
		auto __retval = mC->getSimilarityThreshold();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_setBlockSize: {
		if (aParamCount == 2) {
			int width, height;
			if (ParamIndexToVal(0, width))
				_o_return_result;
			if (ParamIndexToVal(1, height))
				_o_return_result;
			mC->setBlockSize(width, height);
			return;
		}
		else if (aParamCount == 1) {
			cv::Size size;
			if (ParamIndexToVal(0, size))
				_o_return_result;
			mC->setBlockSize(size);
			return;
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case M_setMatGains: {
		std::vector<cv::Mat> umv;
		if (ParamIndexToVal(0, umv))
			_o_return_result;
		mC->setMatGains(umv);
		return;
	}
	case M_setNrFeeds: {
		int nr_feeds;
		if (ParamIndexToVal(0, nr_feeds))
			_o_return_result;
		mC->setNrFeeds(nr_feeds);
		return;
	}
	case M_setNrGainsFilteringIterations: {
		int nr_iterations;
		if (ParamIndexToVal(0, nr_iterations))
			_o_return_result;
		mC->setNrGainsFilteringIterations(nr_iterations);
		return;
	}
	case M_setSimilarityThreshold: {
		double similarity_threshold;
		if (ParamIndexToVal(0, similarity_threshold))
			_o_return_result;
		mC->setSimilarityThreshold(similarity_threshold);
		return;
	}
	}
}

void detail_BlocksGainCompensator::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::detail::BlocksGainCompensator>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		if (0 <= aParamCount && aParamCount <= 2) {
			int bl_width = 32, bl_height = 32;
			if (aParamCount > 0 && aParam[0]->symbol != SYM_MISSING)
				TokenToVal(*aParam[0], bl_width);
			if (aParamCount > 1 && aParam[1]->symbol != SYM_MISSING)
				TokenToVal(*aParam[1], bl_height);
			mC = new cv::detail::BlocksGainCompensator(bl_width, bl_height);
			return;
		}
		else if (aParamCount == 3) {
			int bl_width, bl_height, nr_feeds;
			if (ParamIndexToVal(0, bl_width))
				_o_return_result;
			if (ParamIndexToVal(1, bl_height))
				_o_return_result;
			if (ParamIndexToVal(2, nr_feeds))
				_o_return_result;
			mC = new cv::detail::BlocksGainCompensator(bl_width, bl_height, nr_feeds);
			return;
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case M_apply: {
		cv::_InputArray mask;
		cv::_InputOutputArray image;
		cv::Point corner;
		int index;
		if (ParamIndexToVal(0, index))
			_o_return_result;
		if (ParamIndexToVal(1, corner))
			_o_return_result;
		if (ParamIndexToVal(2, image))
			_o_return_result;
		if (ParamIndexToVal(3, mask))
			_o_return_result;
		mC->apply(index, corner, image, mask);
		return;
	}
	case M_getMatGains: {
		std::vector<cv::Mat> umv;
		VarRef* var_umv = nullptr;
		if (ParamIndexToVal(0, var_umv))
			_o_return_result;
		mC->getMatGains(umv);
		ValToResult(umv, aResultToken);
		g_ahkapi->VarAssign(var_umv, aResultToken);
		g_ahkapi->ResultTokenFree(aResultToken);
		return;
	}
	case M_setMatGains: {
		std::vector<cv::Mat> umv;
		if (ParamIndexToVal(0, umv))
			_o_return_result;
		mC->setMatGains(umv);
		return;
	}
	}
}

void detail_BundleAdjusterAffine::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::detail::BundleAdjusterAffine>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		mC = new cv::detail::BundleAdjusterAffine();
		return;
	}
	}
}

void detail_BundleAdjusterAffinePartial::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::detail::BundleAdjusterAffinePartial>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		mC = new cv::detail::BundleAdjusterAffinePartial();
		return;
	}
	}
}

void detail_BundleAdjusterBase::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M_confThresh: {
		auto __retval = mC->confThresh();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_refinementMask: {
		auto __retval = (Mat*)Mat::sPrototype->New(g_invalidparam, 1);
		__retval->mC = mC->refinementMask();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_setConfThresh: {
		double conf_thresh;
		if (ParamIndexToVal(0, conf_thresh))
			_o_return_result;
		mC->setConfThresh(conf_thresh);
		return;
	}
	case M_setRefinementMask: {
		cv::Mat mask;
		if (ParamIndexToVal(0, mask))
			_o_return_result;
		mC->setRefinementMask(mask);
		return;
	}
	case M_setTermCriteria: {
		cv::TermCriteria term_criteria;
		if (ParamIndexToVal(0, term_criteria))
			_o_return_result;
		mC->setTermCriteria(term_criteria);
		return;
	}
	case M_termCriteria: {
		auto __retval = mC->termCriteria();
		return ValToResult(__retval, aResultToken);
	}
	}
}

void detail_BundleAdjusterRay::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::detail::BundleAdjusterRay>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		mC = new cv::detail::BundleAdjusterRay();
		return;
	}
	}
}

void detail_BundleAdjusterReproj::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::detail::BundleAdjusterReproj>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		mC = new cv::detail::BundleAdjusterReproj();
		return;
	}
	}
}

void detail_ChannelsCompensator::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::detail::ChannelsCompensator>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		int nr_feeds = 1;
		if (aParamCount > 0 && aParam[0]->symbol != SYM_MISSING)
			TokenToVal(*aParam[0], nr_feeds);
		mC = new cv::detail::ChannelsCompensator(nr_feeds);
		return;
	}
	case M_apply: {
		cv::_InputArray mask;
		cv::_InputOutputArray image;
		cv::Point corner;
		int index;
		if (ParamIndexToVal(0, index))
			_o_return_result;
		if (ParamIndexToVal(1, corner))
			_o_return_result;
		if (ParamIndexToVal(2, image))
			_o_return_result;
		if (ParamIndexToVal(3, mask))
			_o_return_result;
		mC->apply(index, corner, image, mask);
		return;
	}
	case M_getMatGains: {
		std::vector<cv::Mat> umv;
		VarRef* var_umv = nullptr;
		if (ParamIndexToVal(0, var_umv))
			_o_return_result;
		mC->getMatGains(umv);
		ValToResult(umv, aResultToken);
		g_ahkapi->VarAssign(var_umv, aResultToken);
		g_ahkapi->ResultTokenFree(aResultToken);
		return;
	}
	case M_getNrFeeds: {
		auto __retval = (__int64)mC->getNrFeeds();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getSimilarityThreshold: {
		auto __retval = mC->getSimilarityThreshold();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_setMatGains: {
		std::vector<cv::Mat> umv;
		if (ParamIndexToVal(0, umv))
			_o_return_result;
		mC->setMatGains(umv);
		return;
	}
	case M_setNrFeeds: {
		int nr_feeds;
		if (ParamIndexToVal(0, nr_feeds))
			_o_return_result;
		mC->setNrFeeds(nr_feeds);
		return;
	}
	case M_setSimilarityThreshold: {
		double similarity_threshold;
		if (ParamIndexToVal(0, similarity_threshold))
			_o_return_result;
		mC->setSimilarityThreshold(similarity_threshold);
		return;
	}
	}
}

void detail_DpSeamFinder::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::detail::DpSeamFinder>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		cv::String costFunc;
		if (ParamIndexToVal(0, costFunc))
			_o_return_result;
		mC = new cv::detail::DpSeamFinder(costFunc);
		return;
	}
	case M_setCostFunction: {
		cv::String val;
		if (ParamIndexToVal(0, val))
			_o_return_result;
		mC->setCostFunction(val);
		return;
	}
	}
}

void detail_Estimator::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M_Call: {
		std::vector<cv::detail::CameraParams> cameras;
		std::vector<cv::detail::ImageFeatures> features;
		std::vector<cv::detail::MatchesInfo> pairwise_matches;
		if (ParamIndexToVal(0, features))
			_o_return_result;
		if (ParamIndexToVal(1, pairwise_matches))
			_o_return_result;
		VarRef* var_cameras = nullptr;
		if (ParamIndexToVal(2, var_cameras))
			_o_return_result;
		if (TokenToVal(VarRefToToken(var_cameras), cameras) != CONDITION_TRUE)
			_o_return_result;
		auto __retval = (__int64)(*mC)(features, pairwise_matches, cameras);
		ValToResult(cameras, aResultToken);
		g_ahkapi->VarAssign(var_cameras, aResultToken);
		g_ahkapi->ResultTokenFree(aResultToken);
		return (void)(aResultToken.SetValue(__retval));
	}
	}
}

void detail_ExposureCompensator::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M_apply: {
		cv::_InputArray mask;
		cv::_InputOutputArray image;
		cv::Point corner;
		int index;
		if (ParamIndexToVal(0, index))
			_o_return_result;
		if (ParamIndexToVal(1, corner))
			_o_return_result;
		if (ParamIndexToVal(2, image))
			_o_return_result;
		if (ParamIndexToVal(3, mask))
			_o_return_result;
		mC->apply(index, corner, image, mask);
		return;
	}
	case M_createDefault: {
		int type;
		if (ParamIndexToVal(0, type))
			_o_return_result;
		auto __retval = (detail_ExposureCompensator*)detail_ExposureCompensator::sPrototype->New(g_invalidparam, 1);
		__retval->mC = mC->createDefault(type);
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_feed: {
		std::vector<cv::Point> corners;
		std::vector<cv::UMat> images, masks;
		if (ParamIndexToVal(0, corners))
			_o_return_result;
		if (ParamIndexToVal(1, images))
			_o_return_result;
		if (ParamIndexToVal(2, masks))
			_o_return_result;
		mC->feed(corners, images, masks);
		return;
	}
	case M_getMatGains: {
		std::vector<cv::Mat> arg1;
		VarRef* var_arg1 = nullptr;
		if (ParamIndexToVal(0, var_arg1))
			_o_return_result;
		mC->getMatGains(arg1);
		ValToResult(arg1, aResultToken);
		g_ahkapi->VarAssign(var_arg1, aResultToken);
		g_ahkapi->ResultTokenFree(aResultToken);
		return;
	}
	case M_getUpdateGain: {
		auto __retval = (__int64)mC->getUpdateGain();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_setMatGains: {
		std::vector<cv::Mat> arg1;
		if (ParamIndexToVal(0, arg1))
			_o_return_result;
		mC->setMatGains(arg1);
		return;
	}
	case M_setUpdateGain: {
		bool b;
		if (ParamIndexToVal(0, (char&)b))
			_o_return_result;
		mC->setUpdateGain(b);
		return;
	}
	}
}

void detail_FeatherBlender::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::detail::FeatherBlender>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		float sharpness = 0.02f;
		if (aParamCount > 0 && aParam[0]->symbol != SYM_MISSING)
			TokenToVal(*aParam[0], sharpness);
		mC = new cv::detail::FeatherBlender(sharpness);
		return;
	}
	case M_blend: {
		cv::_InputOutputArray dst, dst_mask;
		if (ParamIndexToVal(0, dst))
			_o_return_result;
		if (ParamIndexToVal(1, dst_mask))
			_o_return_result;
		mC->blend(dst, dst_mask);
		return;
	}
	case M_createWeightMaps: {
		std::vector<cv::Point> corners;
		std::vector<cv::UMat> masks, weight_maps;
		if (ParamIndexToVal(0, masks))
			_o_return_result;
		if (ParamIndexToVal(1, corners))
			_o_return_result;
		VarRef* var_weight_maps = nullptr;
		if (ParamIndexToVal(2, var_weight_maps))
			_o_return_result;
		if (TokenToVal(VarRefToToken(var_weight_maps), weight_maps) != CONDITION_TRUE)
			_o_return_result;
		auto __retval = mC->createWeightMaps(masks, corners, weight_maps);
		ValToResult(weight_maps, aResultToken);
		g_ahkapi->VarAssign(var_weight_maps, aResultToken);
		g_ahkapi->ResultTokenFree(aResultToken);
		return ValToResult(__retval, aResultToken);
	}
	case M_feed: {
		cv::_InputArray img, mask;
		cv::Point tl;
		if (ParamIndexToVal(0, img))
			_o_return_result;
		if (ParamIndexToVal(1, mask))
			_o_return_result;
		if (ParamIndexToVal(2, tl))
			_o_return_result;
		mC->feed(img, mask, tl);
		return;
	}
	case M_prepare: {
		cv::Rect dst_roi;
		if (ParamIndexToVal(0, dst_roi))
			_o_return_result;
		mC->prepare(dst_roi);
		return;
	}
	case M_setSharpness: {
		float val;
		if (ParamIndexToVal(0, val))
			_o_return_result;
		mC->setSharpness(val);
		return;
	}
	case M_sharpness: {
		auto __retval = (double)mC->sharpness();
		return (void)(aResultToken.SetValue(__retval));
	}
	}
}

void detail_FeaturesMatcher::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M_collectGarbage: {
		mC->collectGarbage();
		return;
	}
	case M_isThreadSafe: {
		auto __retval = (__int64)mC->isThreadSafe();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_Call: {
		if (!MatchTypes("ooo")) {
			cv::detail::ImageFeatures features1, features2;
			cv::detail::MatchesInfo matches_info;
			if (ParamIndexToVal(0, features1))
				_o_return_result;
			if (ParamIndexToVal(1, features2))
				_o_return_result;
			VarRef* var_matches_info = nullptr;
			if (ParamIndexToVal(2, var_matches_info))
				_o_return_result;
			(*mC)(features1, features2, matches_info);
			ValToResult(matches_info, aResultToken);
			g_ahkapi->VarAssign(var_matches_info, aResultToken);
			g_ahkapi->ResultTokenFree(aResultToken);
			return;
		}
		else if (!MatchTypes("ooo?")) {
			cv::UMat mask = cv::UMat();
			std::vector<cv::detail::ImageFeatures> features;
			std::vector<cv::detail::MatchesInfo> pairwise_matches;
			if (ParamIndexToVal(0, features))
				_o_return_result;
			VarRef* var_pairwise_matches = nullptr;
			if (ParamIndexToVal(1, var_pairwise_matches))
				_o_return_result;
			if (aParamCount > 2 && aParam[2]->symbol != SYM_MISSING)
				TokenToVal(*aParam[2], mask);
			(*mC)(features, pairwise_matches, mask);
			ValToResult(pairwise_matches, aResultToken);
			g_ahkapi->VarAssign(var_pairwise_matches, aResultToken);
			g_ahkapi->ResultTokenFree(aResultToken);
			return;
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	}
}

void detail_GainCompensator::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::detail::GainCompensator>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		if (aParamCount == 0) {
			mC = new cv::detail::GainCompensator();
			return;
		}
		else if (aParamCount == 1) {
			int nr_feeds;
			if (ParamIndexToVal(0, nr_feeds))
				_o_return_result;
			mC = new cv::detail::GainCompensator(nr_feeds);
			return;
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case M_apply: {
		cv::_InputArray mask;
		cv::_InputOutputArray image;
		cv::Point corner;
		int index;
		if (ParamIndexToVal(0, index))
			_o_return_result;
		if (ParamIndexToVal(1, corner))
			_o_return_result;
		if (ParamIndexToVal(2, image))
			_o_return_result;
		if (ParamIndexToVal(3, mask))
			_o_return_result;
		mC->apply(index, corner, image, mask);
		return;
	}
	case M_getMatGains: {
		std::vector<cv::Mat> umv;
		VarRef* var_umv = nullptr;
		if (ParamIndexToVal(0, var_umv))
			_o_return_result;
		mC->getMatGains(umv);
		ValToResult(umv, aResultToken);
		g_ahkapi->VarAssign(var_umv, aResultToken);
		g_ahkapi->ResultTokenFree(aResultToken);
		return;
	}
	case M_getNrFeeds: {
		auto __retval = (__int64)mC->getNrFeeds();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getSimilarityThreshold: {
		auto __retval = mC->getSimilarityThreshold();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_setMatGains: {
		std::vector<cv::Mat> umv;
		if (ParamIndexToVal(0, umv))
			_o_return_result;
		mC->setMatGains(umv);
		return;
	}
	case M_setNrFeeds: {
		int nr_feeds;
		if (ParamIndexToVal(0, nr_feeds))
			_o_return_result;
		mC->setNrFeeds(nr_feeds);
		return;
	}
	case M_setSimilarityThreshold: {
		double similarity_threshold;
		if (ParamIndexToVal(0, similarity_threshold))
			_o_return_result;
		mC->setSimilarityThreshold(similarity_threshold);
		return;
	}
	}
}

void detail_GraphCutSeamFinder::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::detail::GraphCutSeamFinder>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		cv::String cost_type;
		float terminal_cost = 10000.f, bad_region_penalty = 1000.f;
		if (ParamIndexToVal(0, cost_type))
			_o_return_result;
		if (aParamCount > 1 && aParam[1]->symbol != SYM_MISSING)
			TokenToVal(*aParam[1], terminal_cost);
		if (aParamCount > 2 && aParam[2]->symbol != SYM_MISSING)
			TokenToVal(*aParam[2], bad_region_penalty);
		mC = new cv::detail::GraphCutSeamFinder(cost_type, terminal_cost, bad_region_penalty);
		return;
	}
	case M_find: {
		std::vector<cv::Point> corners;
		std::vector<cv::UMat> src, masks;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, corners))
			_o_return_result;
		if (ParamIndexToVal(2, masks))
			_o_return_result;
		mC->find(src, corners, masks);
		return;
	}
	}
}

void detail_HomographyBasedEstimator::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::detail::HomographyBasedEstimator>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		bool is_focals_estimated = false;
		if (aParamCount > 0 && aParam[0]->symbol != SYM_MISSING)
			TokenToVal(*aParam[0], (char&)is_focals_estimated);
		mC = new cv::detail::HomographyBasedEstimator(is_focals_estimated);
		return;
	}
	}
}

void detail_MultiBandBlender::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::detail::MultiBandBlender>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		int try_gpu = false, num_bands = 5, weight_type = CV_32F;
		if (aParamCount > 0 && aParam[0]->symbol != SYM_MISSING)
			TokenToVal(*aParam[0], try_gpu);
		if (aParamCount > 1 && aParam[1]->symbol != SYM_MISSING)
			TokenToVal(*aParam[1], num_bands);
		if (aParamCount > 2 && aParam[2]->symbol != SYM_MISSING)
			TokenToVal(*aParam[2], weight_type);
		mC = new cv::detail::MultiBandBlender(try_gpu, num_bands, weight_type);
		return;
	}
	case M_blend: {
		cv::_InputOutputArray dst, dst_mask;
		if (ParamIndexToVal(0, dst))
			_o_return_result;
		if (ParamIndexToVal(1, dst_mask))
			_o_return_result;
		mC->blend(dst, dst_mask);
		return;
	}
	case M_feed: {
		cv::_InputArray img, mask;
		cv::Point tl;
		if (ParamIndexToVal(0, img))
			_o_return_result;
		if (ParamIndexToVal(1, mask))
			_o_return_result;
		if (ParamIndexToVal(2, tl))
			_o_return_result;
		mC->feed(img, mask, tl);
		return;
	}
	case M_numBands: {
		auto __retval = (__int64)mC->numBands();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_prepare: {
		cv::Rect dst_roi;
		if (ParamIndexToVal(0, dst_roi))
			_o_return_result;
		mC->prepare(dst_roi);
		return;
	}
	case M_setNumBands: {
		int val;
		if (ParamIndexToVal(0, val))
			_o_return_result;
		mC->setNumBands(val);
		return;
	}
	}
}

void detail_NoBundleAdjuster::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::detail::NoBundleAdjuster>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		mC = new cv::detail::NoBundleAdjuster();
		return;
	}
	}
}

void detail_NoExposureCompensator::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::detail::NoExposureCompensator>;
		mC = new cv::detail::NoExposureCompensator;
		return;
	}
	case M_apply: {
		cv::_InputArray arg4;
		cv::_InputOutputArray arg3;
		cv::Point arg2;
		int arg1;
		if (ParamIndexToVal(0, arg1))
			_o_return_result;
		if (ParamIndexToVal(1, arg2))
			_o_return_result;
		if (ParamIndexToVal(2, arg3))
			_o_return_result;
		if (ParamIndexToVal(3, arg4))
			_o_return_result;
		mC->apply(arg1, arg2, arg3, arg4);
		return;
	}
	case M_getMatGains: {
		std::vector<cv::Mat> umv;
		VarRef* var_umv = nullptr;
		if (ParamIndexToVal(0, var_umv))
			_o_return_result;
		mC->getMatGains(umv);
		ValToResult(umv, aResultToken);
		g_ahkapi->VarAssign(var_umv, aResultToken);
		g_ahkapi->ResultTokenFree(aResultToken);
		return;
	}
	case M_setMatGains: {
		std::vector<cv::Mat> umv;
		if (ParamIndexToVal(0, umv))
			_o_return_result;
		mC->setMatGains(umv);
		return;
	}
	}
}

void detail_NoSeamFinder::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::detail::NoSeamFinder>;
		mC = new cv::detail::NoSeamFinder;
		return;
	}
	case M_find: {
		std::vector<cv::Point> arg2;
		std::vector<cv::UMat> arg1, arg3;
		if (ParamIndexToVal(0, arg1))
			_o_return_result;
		if (ParamIndexToVal(1, arg2))
			_o_return_result;
		VarRef* var_arg3 = nullptr;
		if (ParamIndexToVal(2, var_arg3))
			_o_return_result;
		if (TokenToVal(VarRefToToken(var_arg3), arg3) != CONDITION_TRUE)
			_o_return_result;
		mC->find(arg1, arg2, arg3);
		ValToResult(arg3, aResultToken);
		g_ahkapi->VarAssign(var_arg3, aResultToken);
		g_ahkapi->ResultTokenFree(aResultToken);
		return;
	}
	}
}

void detail_PairwiseSeamFinder::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M_find: {
		std::vector<cv::Point> corners;
		std::vector<cv::UMat> src, masks;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, corners))
			_o_return_result;
		VarRef* var_masks = nullptr;
		if (ParamIndexToVal(2, var_masks))
			_o_return_result;
		if (TokenToVal(VarRefToToken(var_masks), masks) != CONDITION_TRUE)
			_o_return_result;
		mC->find(src, corners, masks);
		ValToResult(masks, aResultToken);
		g_ahkapi->VarAssign(var_masks, aResultToken);
		g_ahkapi->ResultTokenFree(aResultToken);
		return;
	}
	}
}

void detail_SeamFinder::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::detail::SeamFinder>;
		int type;
		if (aParamCount != 1)
			_o_invalid_param;
		if (ParamIndexToVal(0, type))
			_o_return_result;
		mC = cv::detail::SeamFinder::createDefault(type);
		return;
	}
	case M_find: {
		std::vector<cv::Point> corners;
		std::vector<cv::UMat> src, masks;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, corners))
			_o_return_result;
		VarRef* var_masks = nullptr;
		if (ParamIndexToVal(2, var_masks))
			_o_return_result;
		if (TokenToVal(VarRefToToken(var_masks), masks) != CONDITION_TRUE)
			_o_return_result;
		mC->find(src, corners, masks);
		ValToResult(masks, aResultToken);
		g_ahkapi->VarAssign(var_masks, aResultToken);
		g_ahkapi->ResultTokenFree(aResultToken);
		return;
	}
	}
}

void detail_Timelapser::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::detail::Timelapser>;
		int type;
		if (aParamCount != 1)
			_o_invalid_param;
		if (ParamIndexToVal(0, type))
			_o_return_result;
		mC = cv::detail::Timelapser::createDefault(type);
		return;
	}
	case M_getDst: {
		auto __retval = (UMat*)UMat::sPrototype->New(g_invalidparam, 1);
		__retval->mC = mC->getDst();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_initialize: {
		std::vector<cv::Point> corners;
		std::vector<cv::Size> sizes;
		if (ParamIndexToVal(0, corners))
			_o_return_result;
		if (ParamIndexToVal(1, sizes))
			_o_return_result;
		mC->initialize(corners, sizes);
		return;
	}
	case M_process: {
		cv::_InputArray img, mask;
		cv::Point tl;
		if (ParamIndexToVal(0, img))
			_o_return_result;
		if (ParamIndexToVal(1, mask))
			_o_return_result;
		if (ParamIndexToVal(2, tl))
			_o_return_result;
		mC->process(img, mask, tl);
		return;
	}
	}
}

void detail_TimelapserCrop::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: new (&mC) cv::Ptr<cv::detail::TimelapserCrop>; return;
	}
}

void detail_VoronoiSeamFinder::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::detail::VoronoiSeamFinder>;
		mC = new cv::detail::VoronoiSeamFinder;
		return;
	}
	case M_find: {
		std::vector<cv::Point> corners;
		std::vector<cv::UMat> src, masks;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, corners))
			_o_return_result;
		VarRef* var_masks = nullptr;
		if (ParamIndexToVal(2, var_masks))
			_o_return_result;
		if (TokenToVal(VarRefToToken(var_masks), masks) != CONDITION_TRUE)
			_o_return_result;
		mC->find(src, corners, masks);
		ValToResult(masks, aResultToken);
		g_ahkapi->VarAssign(var_masks, aResultToken);
		g_ahkapi->ResultTokenFree(aResultToken);
		return;
	}
	}
}

void dnn_ClassificationModel::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::dnn::ClassificationModel>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		if (!MatchTypes("ss?")) {
			cv::String model, config = "";
			if (ParamIndexToVal(0, model))
				_o_return_result;
			if (aParamCount > 1 && aParam[1]->symbol != SYM_MISSING)
				TokenToVal(*aParam[1], config);
			mC = new cv::dnn::ClassificationModel(model, config);
			return;
		}
		else if (!MatchTypes("o")) {
			cv::dnn::Net* network;
			if (ParamIndexToVal(0, network))
				_o_return_result;
			mC = new cv::dnn::ClassificationModel(*network);
			return;
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case M_classify: {
		cv::_InputArray frame;
		float conf;
		int classId;
		if (ParamIndexToVal(0, frame))
			_o_return_result;
		VarRef* var_classId = nullptr;
		if (ParamIndexToVal(1, var_classId))
			_o_return_result;
		VarRef* var_conf = nullptr;
		if (ParamIndexToVal(2, var_conf))
			_o_return_result;
		mC->classify(frame, classId, conf);
		g_ahkapi->VarAssign(var_classId, ExprTokenType((__int64)classId));
		g_ahkapi->VarAssign(var_conf, ExprTokenType((double)conf));
		return;
	}
	}
}

void dnn_DetectionModel::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::dnn::DetectionModel>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		if (!MatchTypes("ss?")) {
			cv::String model, config = "";
			if (ParamIndexToVal(0, model))
				_o_return_result;
			if (aParamCount > 1 && aParam[1]->symbol != SYM_MISSING)
				TokenToVal(*aParam[1], config);
			mC = new cv::dnn::DetectionModel(model, config);
			return;
		}
		else if (!MatchTypes("o")) {
			cv::dnn::Net* network;
			if (ParamIndexToVal(0, network))
				_o_return_result;
			mC = new cv::dnn::DetectionModel(*network);
			return;
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case M_detect: {
		cv::_InputArray frame;
		float confThreshold = 0.5f, nmsThreshold = 0.0f;
		std::vector<cv::Rect> boxes;
		std::vector<float> confidences;
		std::vector<int> classIds;
		if (ParamIndexToVal(0, frame))
			_o_return_result;
		VarRef* var_classIds = nullptr;
		if (ParamIndexToVal(1, var_classIds))
			_o_return_result;
		VarRef* var_confidences = nullptr;
		if (ParamIndexToVal(2, var_confidences))
			_o_return_result;
		VarRef* var_boxes = nullptr;
		if (ParamIndexToVal(3, var_boxes))
			_o_return_result;
		if (aParamCount > 4 && aParam[4]->symbol != SYM_MISSING)
			TokenToVal(*aParam[4], confThreshold);
		if (aParamCount > 5 && aParam[5]->symbol != SYM_MISSING)
			TokenToVal(*aParam[5], nmsThreshold);
		mC->detect(frame, classIds, confidences, boxes, confThreshold, nmsThreshold);
		ValToResult(classIds, aResultToken);
		g_ahkapi->VarAssign(var_classIds, aResultToken);
		g_ahkapi->ResultTokenFree(aResultToken);
		ValToResult(confidences, aResultToken);
		g_ahkapi->VarAssign(var_confidences, aResultToken);
		g_ahkapi->ResultTokenFree(aResultToken);
		ValToResult(boxes, aResultToken);
		g_ahkapi->VarAssign(var_boxes, aResultToken);
		g_ahkapi->ResultTokenFree(aResultToken);
		return;
	}
	case M_getNmsAcrossClasses: {
		auto __retval = (__int64)mC->getNmsAcrossClasses();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_setNmsAcrossClasses: {
		bool value;
		if (ParamIndexToVal(0, (char&)value))
			_o_return_result;
		mC->setNmsAcrossClasses(value);
		aResultToken.SetValue(this);
		AddRef();
		return;
	}
	}
}

void dnn_KeypointsModel::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::dnn::KeypointsModel>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		if (!MatchTypes("ss?")) {
			cv::String model, config = "";
			if (ParamIndexToVal(0, model))
				_o_return_result;
			if (aParamCount > 1 && aParam[1]->symbol != SYM_MISSING)
				TokenToVal(*aParam[1], config);
			mC = new cv::dnn::KeypointsModel(model, config);
			return;
		}
		else if (!MatchTypes("o")) {
			cv::dnn::Net* network;
			if (ParamIndexToVal(0, network))
				_o_return_result;
			mC = new cv::dnn::KeypointsModel(*network);
			return;
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case M_estimate: {
		cv::_InputArray frame;
		float thresh = 0.5;
		if (ParamIndexToVal(0, frame))
			_o_return_result;
		if (aParamCount > 1 && aParam[1]->symbol != SYM_MISSING)
			TokenToVal(*aParam[1], thresh);
		auto __retval = mC->estimate(frame, thresh);
		return ValToResult(__retval, aResultToken);
	}
	}
}

void dnn_Layer::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::dnn::Layer>;
		mC = new cv::dnn::Layer;
		return;
	}
	case M_finalize: {
		cv::_InputArray inputs;
		cv::_OutputArray outputs;
		if (ParamIndexToVal(0, inputs))
			_o_return_result;
		if (ParamIndexToVal(1, outputs))
			_o_return_result;
		mC->finalize(inputs, outputs);
		return;
	}
	case M_outputNameToIndex: {
		cv::String outputName;
		if (ParamIndexToVal(0, outputName))
			_o_return_result;
		auto __retval = (__int64)mC->outputNameToIndex(outputName);
		return (void)(aResultToken.SetValue(__retval));
	}
	}
}

void dnn_Model::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::dnn::Model>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		if (!MatchTypes("ss?")) {
			cv::String model, config = "";
			if (ParamIndexToVal(0, model))
				_o_return_result;
			if (aParamCount > 1 && aParam[1]->symbol != SYM_MISSING)
				TokenToVal(*aParam[1], config);
			mC = new cv::dnn::Model(model, config);
			return;
		}
		else if (!MatchTypes("o")) {
			cv::dnn::Net* network;
			if (ParamIndexToVal(0, network))
				_o_return_result;
			mC = new cv::dnn::Model(*network);
			return;
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case M_predict: {
		cv::_InputArray frame;
		cv::_OutputArray outs;
		if (ParamIndexToVal(0, frame))
			_o_return_result;
		if (ParamIndexToVal(1, outs))
			_o_return_result;
		mC->predict(frame, outs);
		return;
	}
	case M_setInputCrop: {
		bool crop;
		if (ParamIndexToVal(0, (char&)crop))
			_o_return_result;
		mC->setInputCrop(crop);
		aResultToken.SetValue(this);
		AddRef();
		return;
	}
	case M_setInputMean: {
		cv::Scalar mean;
		if (ParamIndexToVal(0, mean))
			_o_return_result;
		mC->setInputMean(mean);
		aResultToken.SetValue(this);
		AddRef();
		return;
	}
	case M_setInputParams: {
		bool swapRB = false, crop = false;
		cv::Scalar mean = cv::Scalar();
		cv::Size size = cv::Size();
		double scale = 1.0;
		if (aParamCount > 0 && aParam[0]->symbol != SYM_MISSING)
			TokenToVal(*aParam[0], scale);
		if (aParamCount > 1 && aParam[1]->symbol != SYM_MISSING)
			TokenToVal(*aParam[1], size);
		if (aParamCount > 2 && aParam[2]->symbol != SYM_MISSING)
			TokenToVal(*aParam[2], mean);
		if (aParamCount > 3 && aParam[3]->symbol != SYM_MISSING)
			TokenToVal(*aParam[3], (char&)swapRB);
		if (aParamCount > 4 && aParam[4]->symbol != SYM_MISSING)
			TokenToVal(*aParam[4], (char&)crop);
		mC->setInputParams(scale, size, mean, swapRB, crop);
		return;
	}
	case M_setInputScale: {
		double scale;
		if (ParamIndexToVal(0, scale))
			_o_return_result;
		mC->setInputScale(scale);
		aResultToken.SetValue(this);
		AddRef();
		return;
	}
	case M_setInputSize: {
		if (aParamCount == 1) {
			cv::Size size;
			if (ParamIndexToVal(0, size))
				_o_return_result;
			mC->setInputSize(size);
			aResultToken.SetValue(this);
			AddRef();
			return;
		}
		else if (aParamCount == 2) {
			int width, height;
			if (ParamIndexToVal(0, width))
				_o_return_result;
			if (ParamIndexToVal(1, height))
				_o_return_result;
			mC->setInputSize(width, height);
			aResultToken.SetValue(this);
			AddRef();
			return;
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case M_setInputSwapRB: {
		bool swapRB;
		if (ParamIndexToVal(0, (char&)swapRB))
			_o_return_result;
		mC->setInputSwapRB(swapRB);
		aResultToken.SetValue(this);
		AddRef();
		return;
	}
	case M_setPreferableBackend: {
		int backendId;
		if (ParamIndexToVal(0, backendId))
			_o_return_result;
		mC->setPreferableBackend((cv::dnn::Backend)backendId);
		aResultToken.SetValue(this);
		AddRef();
		return;
	}
	case M_setPreferableTarget: {
		int targetId;
		if (ParamIndexToVal(0, targetId))
			_o_return_result;
		mC->setPreferableTarget((cv::dnn::Target)targetId);
		aResultToken.SetValue(this);
		AddRef();
		return;
	}
	}
}

void dnn_Net::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::dnn::Net>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		mC = new cv::dnn::Net();
		return;
	}
	case M_connect: {
		cv::String outPin, inpPin;
		if (ParamIndexToVal(0, outPin))
			_o_return_result;
		if (ParamIndexToVal(1, inpPin))
			_o_return_result;
		mC->connect(outPin, inpPin);
		return;
	}
	case M_dump: {
		auto __retval = mC->dump();
		return ValToResult(__retval, aResultToken);
	}
	case M_dumpToFile: {
		cv::String path;
		if (ParamIndexToVal(0, path))
			_o_return_result;
		mC->dumpToFile(path);
		return;
	}
	case M_empty: {
		auto __retval = (__int64)mC->empty();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_enableFusion: {
		bool fusion;
		if (ParamIndexToVal(0, (char&)fusion))
			_o_return_result;
		mC->enableFusion(fusion);
		return;
	}
	case M_forward: {
		if (!MatchTypes("s?")) {
			cv::String outputName = cv::String();
			if (aParamCount > 0 && aParam[0]->symbol != SYM_MISSING)
				TokenToVal(*aParam[0], outputName);
			auto __retval = (Mat*)Mat::sPrototype->New(g_invalidparam, 1);
			__retval->mC = mC->forward(outputName);
			return (void)(aResultToken.SetValue(__retval));
		}
		else if (!MatchTypes("os?")) {
			cv::_OutputArray outputBlobs;
			cv::String outputName = cv::String();
			if (ParamIndexToVal(0, outputBlobs))
				_o_return_result;
			if (aParamCount > 1 && aParam[1]->symbol != SYM_MISSING)
				TokenToVal(*aParam[1], outputName);
			mC->forward(outputBlobs, outputName);
			return;
		}
		else if (!MatchTypes("oo")) {
			VarRef* var_outputBlobs = dynamic_cast<VarRef*>(TokenToObject(*aParam[0]));
			std::vector<cv::String> outBlobNames;
			if (var_outputBlobs) {
				std::vector<std::vector<cv::Mat>> outputBlobs;
				if (ParamIndexToVal(1, outBlobNames))
					_o_return_result;
				mC->forward(outputBlobs, outBlobNames);
				ValToResult(outputBlobs, aResultToken);
				g_ahkapi->VarAssign(var_outputBlobs, aResultToken);
				g_ahkapi->ResultTokenFree(aResultToken);
				return;
			}
			else {
				cv::_OutputArray outputBlobs;
				if (ParamIndexToVal(0, outputBlobs))
					_o_return_result;
				if (ParamIndexToVal(1, outBlobNames))
					_o_return_result;
				mC->forward(outputBlobs, outBlobNames);
				return;
			}
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case M_forwardAsync: {
		cv::String outputName = cv::String();
		if (aParamCount > 0 && aParam[0]->symbol != SYM_MISSING)
			TokenToVal(*aParam[0], outputName);
		auto __retval = (AsyncArray*)AsyncArray::sPrototype->New(g_invalidparam, 1);
		__retval->mC = cv::makePtr<cv::AsyncArray>(mC->forwardAsync(outputName));
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getFLOPS: {
		if (aParamCount == 1) {
			auto arr = dynamic_cast<Array*>(TokenToObject(*aParam[0]));
			if (arr && arr->mLength && arr->mItem[0].symbol == SYM_OBJECT) {
				std::vector<cv::dnn::MatShape> netInputShapes;
				if (ParamIndexToVal(0, netInputShapes))
					_o_return_result;
				auto __retval = mC->getFLOPS(netInputShapes);
				return ValToResult(__retval, aResultToken);
			}
			else {
				cv::dnn::MatShape netInputShape;
				if (ParamIndexToVal(0, netInputShape))
					_o_return_result;
				auto __retval = mC->getFLOPS(netInputShape);
				return ValToResult(__retval, aResultToken);
			}
		}
		else if (aParamCount == 2) {
			int layerId;
			auto arr = dynamic_cast<Array*>(TokenToObject(*aParam[1]));
			if (arr && arr->mLength && arr->mItem[0].symbol == SYM_OBJECT) {
				std::vector<cv::dnn::MatShape> netInputShapes;
				if (ParamIndexToVal(0, layerId))
					_o_return_result;
				if (ParamIndexToVal(1, netInputShapes))
					_o_return_result;
				auto __retval = mC->getFLOPS(layerId, netInputShapes);
				return ValToResult(__retval, aResultToken);
			}
			else {
				cv::dnn::MatShape netInputShape;
				int layerId;
				if (ParamIndexToVal(0, layerId))
					_o_return_result;
				if (ParamIndexToVal(1, netInputShape))
					_o_return_result;
				auto __retval = mC->getFLOPS(layerId, netInputShape);
				return ValToResult(__retval, aResultToken);
			}
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case M_getInputDetails: {
		std::vector<float> scales;
		std::vector<int> zeropoints;
		VarRef* var_scales = nullptr;
		if (ParamIndexToVal(0, var_scales))
			_o_return_result;
		VarRef* var_zeropoints = nullptr;
		if (ParamIndexToVal(1, var_zeropoints))
			_o_return_result;
		mC->getInputDetails(scales, zeropoints);
		ValToResult(scales, aResultToken);
		g_ahkapi->VarAssign(var_scales, aResultToken);
		g_ahkapi->ResultTokenFree(aResultToken);
		ValToResult(zeropoints, aResultToken);
		g_ahkapi->VarAssign(var_zeropoints, aResultToken);
		g_ahkapi->ResultTokenFree(aResultToken);
		return;
	}
	case M_getLayer: {
		cv::dnn::Net::LayerId layerId;
		if (ParamIndexToVal(0, layerId))
			_o_return_result;
		auto __retval = (dnn_Layer*)dnn_Layer::sPrototype->New(g_invalidparam, 1);
		__retval->mC = mC->getLayer(layerId);
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getLayerId: {
		cv::String layer;
		if (ParamIndexToVal(0, layer))
			_o_return_result;
		auto __retval = (__int64)mC->getLayerId(layer);
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getLayerNames: {
		auto __retval = mC->getLayerNames();
		return ValToResult(__retval, aResultToken);
	}
	case M_getLayerTypes: {
		std::vector<cv::String> layersTypes;
		VarRef* var_layersTypes = nullptr;
		if (ParamIndexToVal(0, var_layersTypes))
			_o_return_result;
		mC->getLayerTypes(layersTypes);
		ValToResult(layersTypes, aResultToken);
		g_ahkapi->VarAssign(var_layersTypes, aResultToken);
		g_ahkapi->ResultTokenFree(aResultToken);
		return;
	}
	case M_getLayersCount: {
		cv::String layerType;
		if (ParamIndexToVal(0, layerType))
			_o_return_result;
		auto __retval = (__int64)mC->getLayersCount(layerType);
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getLayersShapes: {
		auto arr = dynamic_cast<Array*>(TokenToObject(*aParam[0]));
		if (arr && arr->mLength && arr->mItem[0].symbol == SYM_OBJECT) {
			std::vector<cv::dnn::MatShape> netInputShapes;
			std::vector<int> layersIds;
			std::vector<std::vector<cv::dnn::MatShape>> inLayersShapes, outLayersShapes;
			if (ParamIndexToVal(0, netInputShapes))
				_o_return_result;
			VarRef* var_layersIds = nullptr;
			if (ParamIndexToVal(1, var_layersIds))
				_o_return_result;
			VarRef* var_inLayersShapes = nullptr;
			if (ParamIndexToVal(2, var_inLayersShapes))
				_o_return_result;
			VarRef* var_outLayersShapes = nullptr;
			if (ParamIndexToVal(3, var_outLayersShapes))
				_o_return_result;
			mC->getLayersShapes(netInputShapes, layersIds, inLayersShapes, outLayersShapes);
			ValToResult(layersIds, aResultToken);
			g_ahkapi->VarAssign(var_layersIds, aResultToken);
			g_ahkapi->ResultTokenFree(aResultToken);
			ValToResult(inLayersShapes, aResultToken);
			g_ahkapi->VarAssign(var_inLayersShapes, aResultToken);
			g_ahkapi->ResultTokenFree(aResultToken);
			ValToResult(outLayersShapes, aResultToken);
			g_ahkapi->VarAssign(var_outLayersShapes, aResultToken);
			g_ahkapi->ResultTokenFree(aResultToken);
			return;
		}
		else {
			cv::dnn::MatShape netInputShape;
			std::vector<int> layersIds;
			std::vector<std::vector<cv::dnn::MatShape>> inLayersShapes, outLayersShapes;
			if (ParamIndexToVal(0, netInputShape))
				_o_return_result;
			VarRef* var_layersIds = nullptr;
			if (ParamIndexToVal(1, var_layersIds))
				_o_return_result;
			VarRef* var_inLayersShapes = nullptr;
			if (ParamIndexToVal(2, var_inLayersShapes))
				_o_return_result;
			VarRef* var_outLayersShapes = nullptr;
			if (ParamIndexToVal(3, var_outLayersShapes))
				_o_return_result;
			mC->getLayersShapes(netInputShape, layersIds, inLayersShapes, outLayersShapes);
			ValToResult(layersIds, aResultToken);
			g_ahkapi->VarAssign(var_layersIds, aResultToken);
			g_ahkapi->ResultTokenFree(aResultToken);
			ValToResult(inLayersShapes, aResultToken);
			g_ahkapi->VarAssign(var_inLayersShapes, aResultToken);
			g_ahkapi->ResultTokenFree(aResultToken);
			ValToResult(outLayersShapes, aResultToken);
			g_ahkapi->VarAssign(var_outLayersShapes, aResultToken);
			g_ahkapi->ResultTokenFree(aResultToken);
			return;
		}
	}
	case M_getMemoryConsumption: {
		if (aParamCount == 3) {
			cv::dnn::MatShape netInputShape;
			size_t weights, blobs;
			if (ParamIndexToVal(0, netInputShape))
				_o_return_result;
			VarRef* var_weights = nullptr;
			if (ParamIndexToVal(1, var_weights))
				_o_return_result;
			VarRef* var_blobs = nullptr;
			if (ParamIndexToVal(2, var_blobs))
				_o_return_result;
			mC->getMemoryConsumption(netInputShape, weights, blobs);
			g_ahkapi->VarAssign(var_weights, ExprTokenType((__int64)weights));
			g_ahkapi->VarAssign(var_blobs, ExprTokenType((__int64)blobs));
			return;
		}
		else if (aParamCount == 4) {
			auto arr = dynamic_cast<Array*>(TokenToObject(*aParam[1]));
			if (arr && arr->mLength && arr->mItem[0].symbol == SYM_OBJECT) {
				int layerId;
				size_t weights, blobs;
				std::vector<cv::dnn::MatShape> netInputShapes;
				if (ParamIndexToVal(0, layerId))
					_o_return_result;
				if (ParamIndexToVal(1, netInputShapes))
					_o_return_result;
				VarRef* var_weights = nullptr;
				if (ParamIndexToVal(2, var_weights))
					_o_return_result;
				VarRef* var_blobs = nullptr;
				if (ParamIndexToVal(3, var_blobs))
					_o_return_result;
				mC->getMemoryConsumption(layerId, netInputShapes, weights, blobs);
				g_ahkapi->VarAssign(var_weights, ExprTokenType((__int64)weights));
				g_ahkapi->VarAssign(var_blobs, ExprTokenType((__int64)blobs));
				return;
			}
			else {
				cv::dnn::MatShape netInputShape;
				int layerId;
				size_t weights, blobs;
				if (ParamIndexToVal(0, layerId))
					_o_return_result;
				if (ParamIndexToVal(1, netInputShape))
					_o_return_result;
				VarRef* var_weights = nullptr;
				if (ParamIndexToVal(2, var_weights))
					_o_return_result;
				VarRef* var_blobs = nullptr;
				if (ParamIndexToVal(3, var_blobs))
					_o_return_result;
				mC->getMemoryConsumption(layerId, netInputShape, weights, blobs);
				g_ahkapi->VarAssign(var_weights, ExprTokenType((__int64)weights));
				g_ahkapi->VarAssign(var_blobs, ExprTokenType((__int64)blobs));
				return;
			}
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case M_getOutputDetails: {
		std::vector<float> scales;
		std::vector<int> zeropoints;
		VarRef* var_scales = nullptr;
		if (ParamIndexToVal(0, var_scales))
			_o_return_result;
		VarRef* var_zeropoints = nullptr;
		if (ParamIndexToVal(1, var_zeropoints))
			_o_return_result;
		mC->getOutputDetails(scales, zeropoints);
		ValToResult(scales, aResultToken);
		g_ahkapi->VarAssign(var_scales, aResultToken);
		g_ahkapi->ResultTokenFree(aResultToken);
		ValToResult(zeropoints, aResultToken);
		g_ahkapi->VarAssign(var_zeropoints, aResultToken);
		g_ahkapi->ResultTokenFree(aResultToken);
		return;
	}
	case M_getParam: {
		int layer;
		int numParam = 0;
		if (aParam[0]->symbol == SYM_STRING) {
			cv::String layerName;
			if (ParamIndexToVal(0, layerName))
				_o_return_result;
			layer = mC->getLayerId(layerName);
		}
		else if (ParamIndexToVal(0, layer))
			_o_return_result;
		if (aParamCount > 1 && aParam[1]->symbol != SYM_MISSING)
			TokenToVal(*aParam[1], numParam);
		auto __retval = (Mat*)Mat::sPrototype->New(g_invalidparam, 1);
		__retval->mC = mC->getParam(layer, numParam);
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getPerfProfile: {
		std::vector<double> timings;
		VarRef* var_timings = nullptr;
		if (ParamIndexToVal(0, var_timings))
			_o_return_result;
		auto __retval = mC->getPerfProfile(timings);
		ValToResult(timings, aResultToken);
		g_ahkapi->VarAssign(var_timings, aResultToken);
		g_ahkapi->ResultTokenFree(aResultToken);
		return ValToResult(__retval, aResultToken);
	}
	case M_getUnconnectedOutLayers: {
		auto __retval = mC->getUnconnectedOutLayers();
		return ValToResult(__retval, aResultToken);
	}
	case M_getUnconnectedOutLayersNames: {
		auto __retval = mC->getUnconnectedOutLayersNames();
		return ValToResult(__retval, aResultToken);
	}
	case M_quantize: {
		cv::_InputArray calibData;
		int inputsDtype, outputsDtype;
		if (ParamIndexToVal(0, calibData))
			_o_return_result;
		if (ParamIndexToVal(1, inputsDtype))
			_o_return_result;
		if (ParamIndexToVal(2, outputsDtype))
			_o_return_result;
		auto __retval = (dnn_Net*)dnn_Net::sPrototype->New(g_invalidparam, 1);
		__retval->mC = cv::makePtr<cv::dnn::Net>(mC->quantize(calibData, inputsDtype, outputsDtype));
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_readFromModelOptimizer: {
		if (!MatchTypes("ss")) {
			cv::String xml, bin;
			if (ParamIndexToVal(0, xml))
				_o_return_result;
			if (ParamIndexToVal(1, bin))
				_o_return_result;
			auto __retval = (dnn_Net*)dnn_Net::sPrototype->New(g_invalidparam, 1);
			__retval->mC = cv::makePtr<cv::dnn::Net>(cv::dnn::Net::readFromModelOptimizer(xml, bin));
			return (void)(aResultToken.SetValue(__retval));
		}
		else if (!MatchTypes("oo")) {
			std::vector<uchar> bufferModelConfig, bufferWeights;
			if (ParamIndexToVal(0, bufferModelConfig))
				_o_return_result;
			if (ParamIndexToVal(1, bufferWeights))
				_o_return_result;
			auto __retval = (dnn_Net*)dnn_Net::sPrototype->New(g_invalidparam, 1);
			__retval->mC = cv::makePtr<cv::dnn::Net>(cv::dnn::Net::readFromModelOptimizer(bufferModelConfig, bufferWeights));
			return (void)(aResultToken.SetValue(__retval));
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case M_setHalideScheduler: {
		cv::String scheduler;
		if (ParamIndexToVal(0, scheduler))
			_o_return_result;
		mC->setHalideScheduler(scheduler);
		return;
	}
	case M_setInput: {
		cv::_InputArray blob;
		cv::Scalar mean = cv::Scalar();
		cv::String name = "";
		double scalefactor = 1.0;
		if (ParamIndexToVal(0, blob))
			_o_return_result;
		if (aParamCount > 1 && aParam[1]->symbol != SYM_MISSING)
			TokenToVal(*aParam[1], name);
		if (aParamCount > 2 && aParam[2]->symbol != SYM_MISSING)
			TokenToVal(*aParam[2], scalefactor);
		if (aParamCount > 3 && aParam[3]->symbol != SYM_MISSING)
			TokenToVal(*aParam[3], mean);
		mC->setInput(blob, name, scalefactor, mean);
		return;
	}
	case M_setInputShape: {
		cv::String inputName;
		cv::dnn::MatShape shape;
		if (ParamIndexToVal(0, inputName))
			_o_return_result;
		if (ParamIndexToVal(1, shape))
			_o_return_result;
		mC->setInputShape(inputName, shape);
		return;
	}
	case M_setInputsNames: {
		std::vector<cv::String> inputBlobNames;
		if (ParamIndexToVal(0, inputBlobNames))
			_o_return_result;
		mC->setInputsNames(inputBlobNames);
		return;
	}
	case M_setParam: {
		cv::Mat blob;
		int layer;
		int numParam;
		if (aParam[0]->symbol == SYM_STRING) {
			cv::String layerName;
			if (ParamIndexToVal(0, layerName))
				_o_return_result;
			layer = mC->getLayerId(layerName);
		} else if (ParamIndexToVal(0, layer))
			_o_return_result;
		if (ParamIndexToVal(1, numParam))
			_o_return_result;
		if (ParamIndexToVal(2, blob))
			_o_return_result;
		mC->setParam(layer, numParam, blob);
		return;
	}
	case M_setPreferableBackend: {
		int backendId;
		if (ParamIndexToVal(0, backendId))
			_o_return_result;
		mC->setPreferableBackend(backendId);
		return;
	}
	case M_setPreferableTarget: {
		int targetId;
		if (ParamIndexToVal(0, targetId))
			_o_return_result;
		mC->setPreferableTarget(targetId);
		return;
	}
	}
}

void dnn_SegmentationModel::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::dnn::SegmentationModel>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		if (!MatchTypes("ss?")) {
			cv::String model, config = "";
			if (ParamIndexToVal(0, model))
				_o_return_result;
			if (aParamCount > 1 && aParam[1]->symbol != SYM_MISSING)
				TokenToVal(*aParam[1], config);
			mC = new cv::dnn::SegmentationModel(model, config);
			return;
		}
		else if (!MatchTypes("o")) {
			cv::dnn::Net* network;
			if (ParamIndexToVal(0, network))
				_o_return_result;
			mC = new cv::dnn::SegmentationModel(*network);
			return;
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case M_segment: {
		cv::_InputArray frame;
		cv::_OutputArray mask;
		if (ParamIndexToVal(0, frame))
			_o_return_result;
		if (ParamIndexToVal(1, mask))
			_o_return_result;
		mC->segment(frame, mask);
		return;
	}
	}
}

void dnn_TextDetectionModel::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M_detect: {
		if (aParamCount == 3) {
			cv::_InputArray frame;
			std::vector<float> confidences;
			std::vector<std::vector<cv::Point>> detections;
			if (ParamIndexToVal(0, frame))
				_o_return_result;
			VarRef* var_detections = nullptr;
			if (ParamIndexToVal(1, var_detections))
				_o_return_result;
			VarRef* var_confidences = nullptr;
			if (ParamIndexToVal(2, var_confidences))
				_o_return_result;
			mC->detect(frame, detections, confidences);
			ValToResult(detections, aResultToken);
			g_ahkapi->VarAssign(var_detections, aResultToken);
			g_ahkapi->ResultTokenFree(aResultToken);
			ValToResult(confidences, aResultToken);
			g_ahkapi->VarAssign(var_confidences, aResultToken);
			g_ahkapi->ResultTokenFree(aResultToken);
			return;
		}
		else if (aParamCount == 2) {
			cv::_InputArray frame;
			std::vector<std::vector<cv::Point>> detections;
			if (ParamIndexToVal(0, frame))
				_o_return_result;
			VarRef* var_detections = nullptr;
			if (ParamIndexToVal(1, var_detections))
				_o_return_result;
			mC->detect(frame, detections);
			ValToResult(detections, aResultToken);
			g_ahkapi->VarAssign(var_detections, aResultToken);
			g_ahkapi->ResultTokenFree(aResultToken);
			return;
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case M_detectTextRectangles: {
		if (aParamCount == 3) {
			cv::_InputArray frame;
			std::vector<cv::RotatedRect> detections;
			std::vector<float> confidences;
			if (ParamIndexToVal(0, frame))
				_o_return_result;
			VarRef* var_detections = nullptr;
			if (ParamIndexToVal(1, var_detections))
				_o_return_result;
			VarRef* var_confidences = nullptr;
			if (ParamIndexToVal(2, var_confidences))
				_o_return_result;
			mC->detectTextRectangles(frame, detections, confidences);
			ValToResult(detections, aResultToken);
			g_ahkapi->VarAssign(var_detections, aResultToken);
			g_ahkapi->ResultTokenFree(aResultToken);
			ValToResult(confidences, aResultToken);
			g_ahkapi->VarAssign(var_confidences, aResultToken);
			g_ahkapi->ResultTokenFree(aResultToken);
			return;
		}
		else if (aParamCount == 2) {
			cv::_InputArray frame;
			std::vector<cv::RotatedRect> detections;
			if (ParamIndexToVal(0, frame))
				_o_return_result;
			VarRef* var_detections = nullptr;
			if (ParamIndexToVal(1, var_detections))
				_o_return_result;
			mC->detectTextRectangles(frame, detections);
			ValToResult(detections, aResultToken);
			g_ahkapi->VarAssign(var_detections, aResultToken);
			g_ahkapi->ResultTokenFree(aResultToken);
			return;
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	}
}

void dnn_TextDetectionModel_DB::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::dnn::TextDetectionModel_DB>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		if (!MatchTypes("o")) {
			cv::dnn::Net* network;
			if (ParamIndexToVal(0, network))
				_o_return_result;
			mC = new cv::dnn::TextDetectionModel_DB(*network);
			return;
		}
		else if (!MatchTypes("ss?")) {
			cv::String model, config = "";
			if (ParamIndexToVal(0, model))
				_o_return_result;
			if (aParamCount > 1 && aParam[1]->symbol != SYM_MISSING)
				TokenToVal(*aParam[1], config);
			mC = new cv::dnn::TextDetectionModel_DB(model, config);
			return;
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case M_getBinaryThreshold: {
		auto __retval = (double)mC->getBinaryThreshold();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getMaxCandidates: {
		auto __retval = (__int64)mC->getMaxCandidates();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getPolygonThreshold: {
		auto __retval = (double)mC->getPolygonThreshold();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getUnclipRatio: {
		auto __retval = mC->getUnclipRatio();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_setBinaryThreshold: {
		float binaryThreshold;
		if (ParamIndexToVal(0, binaryThreshold))
			_o_return_result;
		mC->setBinaryThreshold(binaryThreshold);
		aResultToken.SetValue(this);
		AddRef();
		return;
	}
	case M_setMaxCandidates: {
		int maxCandidates;
		if (ParamIndexToVal(0, maxCandidates))
			_o_return_result;
		mC->setMaxCandidates(maxCandidates);
		aResultToken.SetValue(this);
		AddRef();
		return;
	}
	case M_setPolygonThreshold: {
		float polygonThreshold;
		if (ParamIndexToVal(0, polygonThreshold))
			_o_return_result;
		mC->setPolygonThreshold(polygonThreshold);
		aResultToken.SetValue(this);
		AddRef();
		return;
	}
	case M_setUnclipRatio: {
		double unclipRatio;
		if (ParamIndexToVal(0, unclipRatio))
			_o_return_result;
		mC->setUnclipRatio(unclipRatio);
		aResultToken.SetValue(this);
		AddRef();
		return;
	}
	}
}

void dnn_TextDetectionModel_EAST::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::dnn::TextDetectionModel_EAST>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		if (!MatchTypes("o")) {
			cv::dnn::Net* network;
			if (ParamIndexToVal(0, network))
				_o_return_result;
			mC = new cv::dnn::TextDetectionModel_EAST(*network);
			return;
		}
		else if (!MatchTypes("ss?")) {
			cv::String model, config = "";
			if (ParamIndexToVal(0, model))
				_o_return_result;
			if (aParamCount > 1 && aParam[1]->symbol != SYM_MISSING)
				TokenToVal(*aParam[1], config);
			mC = new cv::dnn::TextDetectionModel_EAST(model, config);
			return;
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case M_getConfidenceThreshold: {
		auto __retval = (double)mC->getConfidenceThreshold();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getNMSThreshold: {
		auto __retval = (double)mC->getNMSThreshold();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_setConfidenceThreshold: {
		float confThreshold;
		if (ParamIndexToVal(0, confThreshold))
			_o_return_result;
		mC->setConfidenceThreshold(confThreshold);
		aResultToken.SetValue(this);
		AddRef();
		return;
	}
	case M_setNMSThreshold: {
		float nmsThreshold;
		if (ParamIndexToVal(0, nmsThreshold))
			_o_return_result;
		mC->setNMSThreshold(nmsThreshold);
		aResultToken.SetValue(this);
		AddRef();
		return;
	}
	}
}

void dnn_TextRecognitionModel::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::dnn::TextRecognitionModel>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		if (!MatchTypes("o")) {
			cv::dnn::Net* network;
			if (ParamIndexToVal(0, network))
				_o_return_result;
			mC = new cv::dnn::TextRecognitionModel(*network);
			return;
		}
		else if (!MatchTypes("ss?")) {
			cv::String model, config = "";
			if (ParamIndexToVal(0, model))
				_o_return_result;
			if (aParamCount > 1 && aParam[1]->symbol != SYM_MISSING)
				TokenToVal(*aParam[1], config);
			mC = new cv::dnn::TextRecognitionModel(model, config);
			return;
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case M_getDecodeType: {
		auto __retval = mC->getDecodeType();
		return ValToResult(__retval, aResultToken);
	}
	case M_getVocabulary: {
		auto __retval = mC->getVocabulary();
		return ValToResult(__retval, aResultToken);
	}
	case M_recognize: {
		if (aParamCount == 1) {
			cv::_InputArray frame;
			if (ParamIndexToVal(0, frame))
				_o_return_result;
			auto __retval = mC->recognize(frame);
			return ValToResult(__retval, aResultToken);
		}
		else if (aParamCount == 3) {
			cv::_InputArray frame, roiRects;
			std::vector<cv::String> results;
			if (ParamIndexToVal(0, frame))
				_o_return_result;
			if (ParamIndexToVal(1, roiRects))
				_o_return_result;
			VarRef* var_results = nullptr;
			if (ParamIndexToVal(2, var_results))
				_o_return_result;
			mC->recognize(frame, roiRects, results);
			ValToResult(results, aResultToken);
			g_ahkapi->VarAssign(var_results, aResultToken);
			g_ahkapi->ResultTokenFree(aResultToken);
			return;
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case M_setDecodeOptsCTCPrefixBeamSearch: {
		int beamSize, vocPruneSize = 0;
		if (ParamIndexToVal(0, beamSize))
			_o_return_result;
		if (aParamCount > 1 && aParam[1]->symbol != SYM_MISSING)
			TokenToVal(*aParam[1], vocPruneSize);
		mC->setDecodeOptsCTCPrefixBeamSearch(beamSize, vocPruneSize);
		aResultToken.SetValue(this);
		AddRef();
		return;
	}
	case M_setDecodeType: {
		cv::String decodeType;
		if (ParamIndexToVal(0, decodeType))
			_o_return_result;
		mC->setDecodeType(decodeType);
		aResultToken.SetValue(this);
		AddRef();
		return;
	}
	case M_setVocabulary: {
		std::vector<cv::String> vocabulary;
		if (ParamIndexToVal(0, vocabulary))
			_o_return_result;
		mC->setVocabulary(vocabulary);
		aResultToken.SetValue(this);
		AddRef();
		return;
	}
	}
}

void flann_Index::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::flann::Index>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		if (aParamCount == 0) {
			mC = new cv::flann::Index();
			return;
		}
		else if (2 <= aParamCount && aParamCount <= 3) {
			cv::_InputArray features;
			cv::flann::IndexParams params;
			int distType = cvflann::FLANN_DIST_L2;
			if (ParamIndexToVal(0, features))
				_o_return_result;
			//if (ParamIndexToVal(1, params))
				//_o_return_result;
			if (aParamCount > 2 && aParam[2]->symbol != SYM_MISSING)
				TokenToVal(*aParam[2], distType);
			mC = new cv::flann::Index(features, params, (cvflann::flann_distance_t)distType);
			return;
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case M_build: {
		cv::_InputArray features;
		cv::flann::IndexParams params;
		int distType = cvflann::FLANN_DIST_L2;
		if (ParamIndexToVal(0, features))
			_o_return_result;
		//if (ParamIndexToVal(1, params))
			//_o_return_result;
		if (aParamCount > 2 && aParam[2]->symbol != SYM_MISSING)
			TokenToVal(*aParam[2], distType);
		mC->build(features, params, (cvflann::flann_distance_t)distType);
		return;
	}
	case M_getAlgorithm: {
		auto __retval = mC->getAlgorithm();
		return ValToResult(__retval, aResultToken);
	}
	case M_getDistance: {
		auto __retval = mC->getDistance();
		return ValToResult(__retval, aResultToken);
	}
	case M_knnSearch: {
		cv::_InputArray query;
		cv::_OutputArray indices, dists;
		cv::flann::SearchParams& params = cv::flann::SearchParams();
		int knn;
		if (ParamIndexToVal(0, query))
			_o_return_result;
		if (ParamIndexToVal(1, indices))
			_o_return_result;
		if (ParamIndexToVal(2, dists))
			_o_return_result;
		if (ParamIndexToVal(3, knn))
			_o_return_result;
		//if (aParamCount > 4)
			//TokenToVal(*aParam[4], params, true);
		mC->knnSearch(query, indices, dists, knn, params);
		return;
	}
	case M_load: {
		cv::_InputArray features;
		cv::String filename;
		if (ParamIndexToVal(0, features))
			_o_return_result;
		if (ParamIndexToVal(1, filename))
			_o_return_result;
		auto __retval = (__int64)mC->load(features, filename);
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_radiusSearch: {
		cv::_InputArray query;
		cv::_OutputArray indices, dists;
		cv::flann::SearchParams& params = cv::flann::SearchParams();
		double radius;
		int maxResults;
		if (ParamIndexToVal(0, query))
			_o_return_result;
		if (ParamIndexToVal(1, indices))
			_o_return_result;
		if (ParamIndexToVal(2, dists))
			_o_return_result;
		if (ParamIndexToVal(3, radius))
			_o_return_result;
		if (ParamIndexToVal(4, maxResults))
			_o_return_result;
		//if (aParamCount > 5)
			//TokenToVal(*aParam[5], params, true);
		auto __retval = (__int64)mC->radiusSearch(query, indices, dists, radius, maxResults, params);
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_release: {
		mC->release();
		return;
	}
	case M_save: {
		cv::String filename;
		if (ParamIndexToVal(0, filename))
			_o_return_result;
		mC->save(filename);
		return;
	}
	}
}

#ifdef HAS_GAPI
void gapi_GKernelPackage::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: new (&mC) cv::Ptr<cv::gapi::GKernelPackage>; return;
	}
}

void gapi_ie_PyParams::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::gapi::ie::PyParams>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		if (aParamCount == 0) {
			mC = new cv::gapi::ie::PyParams();
			return;
		}
		else if (aParamCount == 4) {
			cv::String tag, model, weights, device;
			if (ParamIndexToVal(0, tag))
				_o_return_result;
			if (ParamIndexToVal(1, model))
				_o_return_result;
			if (ParamIndexToVal(2, weights))
				_o_return_result;
			if (ParamIndexToVal(3, device))
				_o_return_result;
			mC = new cv::gapi::ie::PyParams(tag, model, weights, device);
			return;
		}
		else if (aParamCount == 3) {
			cv::String tag, model, device;
			if (ParamIndexToVal(0, tag))
				_o_return_result;
			if (ParamIndexToVal(1, model))
				_o_return_result;
			if (ParamIndexToVal(2, device))
				_o_return_result;
			mC = new cv::gapi::ie::PyParams(tag, model, device);
			return;
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case M_cfgBatchSize: {
		size_t size;
		if (ParamIndexToVal(0, (intptr_t&)size))
			_o_return_result;
		auto __retval = (gapi_ie_PyParams*)gapi_ie_PyParams::sPrototype->New(g_invalidparam, 1);
		__retval->mC = cv::makePtr<cv::gapi::ie::PyParams>(mC->cfgBatchSize(size));
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_cfgNumRequests: {
		size_t nireq;
		if (ParamIndexToVal(0, (intptr_t&)nireq))
			_o_return_result;
		auto __retval = (gapi_ie_PyParams*)gapi_ie_PyParams::sPrototype->New(g_invalidparam, 1);
		__retval->mC = cv::makePtr<cv::gapi::ie::PyParams>(mC->cfgNumRequests(nireq));
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_constInput: {
		cv::Mat data;
		cv::String layer_name;
		int hint = (int)cv::gapi::ie::TraitAs::TENSOR;
		if (ParamIndexToVal(0, layer_name))
			_o_return_result;
		if (ParamIndexToVal(1, data))
			_o_return_result;
		if (aParamCount > 2 && aParam[2]->symbol != SYM_MISSING)
			TokenToVal(*aParam[2], hint);
		auto __retval = (gapi_ie_PyParams*)gapi_ie_PyParams::sPrototype->New(g_invalidparam, 1);
		__retval->mC = cv::makePtr<cv::gapi::ie::PyParams>(mC->constInput(layer_name, data, (cv::gapi::ie::TraitAs)hint));
		return (void)(aResultToken.SetValue(__retval));
	}
	}
}
#endif

void ml_ANN_MLP::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::ml::ANN_MLP>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		mC = cv::ml::ANN_MLP::create();
		return;
	}
	case M_getAnnealCoolingRatio: {
		auto __retval = mC->getAnnealCoolingRatio();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getAnnealFinalT: {
		auto __retval = mC->getAnnealFinalT();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getAnnealInitialT: {
		auto __retval = mC->getAnnealInitialT();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getAnnealItePerStep: {
		auto __retval = (__int64)mC->getAnnealItePerStep();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getBackpropMomentumScale: {
		auto __retval = mC->getBackpropMomentumScale();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getBackpropWeightScale: {
		auto __retval = mC->getBackpropWeightScale();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getLayerSizes: {
		auto __retval = (Mat*)Mat::sPrototype->New(g_invalidparam, 1);
		__retval->mC = mC->getLayerSizes();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getRpropDW0: {
		auto __retval = mC->getRpropDW0();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getRpropDWMax: {
		auto __retval = mC->getRpropDWMax();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getRpropDWMin: {
		auto __retval = mC->getRpropDWMin();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getRpropDWMinus: {
		auto __retval = mC->getRpropDWMinus();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getRpropDWPlus: {
		auto __retval = mC->getRpropDWPlus();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getTermCriteria: {
		auto __retval = mC->getTermCriteria();
		return ValToResult(__retval, aResultToken);
	}
	case M_getTrainMethod: {
		auto __retval = (__int64)mC->getTrainMethod();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getWeights: {
		int layerIdx;
		if (ParamIndexToVal(0, layerIdx))
			_o_return_result;
		auto __retval = (Mat*)Mat::sPrototype->New(g_invalidparam, 1);
		__retval->mC = mC->getWeights(layerIdx);
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_load: {
		cv::String filepath;
		if (ParamIndexToVal(0, filepath))
			_o_return_result;
		auto __retval = (ml_ANN_MLP*)ml_ANN_MLP::sPrototype->New(g_invalidparam, 1);
		__retval->mC = mC->load(filepath);
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_setActivationFunction: {
		double param1 = 0, param2 = 0;
		int type;
		if (ParamIndexToVal(0, type))
			_o_return_result;
		if (aParamCount > 1 && aParam[1]->symbol != SYM_MISSING)
			TokenToVal(*aParam[1], param1);
		if (aParamCount > 2 && aParam[2]->symbol != SYM_MISSING)
			TokenToVal(*aParam[2], param2);
		mC->setActivationFunction(type, param1, param2);
		return;
	}
	case M_setAnnealCoolingRatio: {
		double val;
		if (ParamIndexToVal(0, val))
			_o_return_result;
		mC->setAnnealCoolingRatio(val);
		return;
	}
	case M_setAnnealFinalT: {
		double val;
		if (ParamIndexToVal(0, val))
			_o_return_result;
		mC->setAnnealFinalT(val);
		return;
	}
	case M_setAnnealInitialT: {
		double val;
		if (ParamIndexToVal(0, val))
			_o_return_result;
		mC->setAnnealInitialT(val);
		return;
	}
	case M_setAnnealItePerStep: {
		int val;
		if (ParamIndexToVal(0, val))
			_o_return_result;
		mC->setAnnealItePerStep(val);
		return;
	}
	case M_setBackpropMomentumScale: {
		double val;
		if (ParamIndexToVal(0, val))
			_o_return_result;
		mC->setBackpropMomentumScale(val);
		return;
	}
	case M_setBackpropWeightScale: {
		double val;
		if (ParamIndexToVal(0, val))
			_o_return_result;
		mC->setBackpropWeightScale(val);
		return;
	}
	case M_setLayerSizes: {
		cv::_InputArray _layer_sizes;
		if (ParamIndexToVal(0, _layer_sizes))
			_o_return_result;
		mC->setLayerSizes(_layer_sizes);
		return;
	}
	case M_setRpropDW0: {
		double val;
		if (ParamIndexToVal(0, val))
			_o_return_result;
		mC->setRpropDW0(val);
		return;
	}
	case M_setRpropDWMax: {
		double val;
		if (ParamIndexToVal(0, val))
			_o_return_result;
		mC->setRpropDWMax(val);
		return;
	}
	case M_setRpropDWMin: {
		double val;
		if (ParamIndexToVal(0, val))
			_o_return_result;
		mC->setRpropDWMin(val);
		return;
	}
	case M_setRpropDWMinus: {
		double val;
		if (ParamIndexToVal(0, val))
			_o_return_result;
		mC->setRpropDWMinus(val);
		return;
	}
	case M_setRpropDWPlus: {
		double val;
		if (ParamIndexToVal(0, val))
			_o_return_result;
		mC->setRpropDWPlus(val);
		return;
	}
	case M_setTermCriteria: {
		cv::TermCriteria val;
		if (ParamIndexToVal(0, val))
			_o_return_result;
		mC->setTermCriteria(val);
		return;
	}
	case M_setTrainMethod: {
		double param1 = 0, param2 = 0;
		int method;
		if (ParamIndexToVal(0, method))
			_o_return_result;
		if (aParamCount > 1 && aParam[1]->symbol != SYM_MISSING)
			TokenToVal(*aParam[1], param1);
		if (aParamCount > 2 && aParam[2]->symbol != SYM_MISSING)
			TokenToVal(*aParam[2], param2);
		mC->setTrainMethod(method, param1, param2);
		return;
	}
	}
}

void ml_Boost::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::ml::Boost>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		mC = cv::ml::Boost::create();
		return;
	}
	case M_getBoostType: {
		auto __retval = (__int64)mC->getBoostType();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getWeakCount: {
		auto __retval = (__int64)mC->getWeakCount();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getWeightTrimRate: {
		auto __retval = mC->getWeightTrimRate();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_load: {
		cv::String filepath, nodeName = cv::String();
		if (ParamIndexToVal(0, filepath))
			_o_return_result;
		if (aParamCount > 1 && aParam[1]->symbol != SYM_MISSING)
			TokenToVal(*aParam[1], nodeName);
		auto __retval = (ml_Boost*)ml_Boost::sPrototype->New(g_invalidparam, 1);
		__retval->mC = mC->load(filepath, nodeName);
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_setBoostType: {
		int val;
		if (ParamIndexToVal(0, val))
			_o_return_result;
		mC->setBoostType(val);
		return;
	}
	case M_setWeakCount: {
		int val;
		if (ParamIndexToVal(0, val))
			_o_return_result;
		mC->setWeakCount(val);
		return;
	}
	case M_setWeightTrimRate: {
		double val;
		if (ParamIndexToVal(0, val))
			_o_return_result;
		mC->setWeightTrimRate(val);
		return;
	}
	}
}

void ml_DTrees::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::ml::DTrees>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		mC = cv::ml::DTrees::create();
		return;
	}
	case M_getCVFolds: {
		auto __retval = (__int64)mC->getCVFolds();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getMaxCategories: {
		auto __retval = (__int64)mC->getMaxCategories();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getMaxDepth: {
		auto __retval = (__int64)mC->getMaxDepth();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getMinSampleCount: {
		auto __retval = (__int64)mC->getMinSampleCount();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getPriors: {
		auto __retval = (Mat*)Mat::sPrototype->New(g_invalidparam, 1);
		__retval->mC = mC->getPriors();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getRegressionAccuracy: {
		auto __retval = (double)mC->getRegressionAccuracy();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getTruncatePrunedTree: {
		auto __retval = (__int64)mC->getTruncatePrunedTree();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getUse1SERule: {
		auto __retval = (__int64)mC->getUse1SERule();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getUseSurrogates: {
		auto __retval = (__int64)mC->getUseSurrogates();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_load: {
		cv::String filepath, nodeName = cv::String();
		if (ParamIndexToVal(0, filepath))
			_o_return_result;
		if (aParamCount > 1 && aParam[1]->symbol != SYM_MISSING)
			TokenToVal(*aParam[1], nodeName);
		auto __retval = (ml_DTrees*)ml_DTrees::sPrototype->New(g_invalidparam, 1);
		__retval->mC = mC->load(filepath, nodeName);
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_setCVFolds: {
		int val;
		if (ParamIndexToVal(0, val))
			_o_return_result;
		mC->setCVFolds(val);
		return;
	}
	case M_setMaxCategories: {
		int val;
		if (ParamIndexToVal(0, val))
			_o_return_result;
		mC->setMaxCategories(val);
		return;
	}
	case M_setMaxDepth: {
		int val;
		if (ParamIndexToVal(0, val))
			_o_return_result;
		mC->setMaxDepth(val);
		return;
	}
	case M_setMinSampleCount: {
		int val;
		if (ParamIndexToVal(0, val))
			_o_return_result;
		mC->setMinSampleCount(val);
		return;
	}
	case M_setPriors: {
		cv::Mat val;
		if (ParamIndexToVal(0, val))
			_o_return_result;
		mC->setPriors(val);
		return;
	}
	case M_setRegressionAccuracy: {
		float val;
		if (ParamIndexToVal(0, val))
			_o_return_result;
		mC->setRegressionAccuracy(val);
		return;
	}
	case M_setTruncatePrunedTree: {
		bool val;
		if (ParamIndexToVal(0, (char&)val))
			_o_return_result;
		mC->setTruncatePrunedTree(val);
		return;
	}
	case M_setUse1SERule: {
		bool val;
		if (ParamIndexToVal(0, (char&)val))
			_o_return_result;
		mC->setUse1SERule(val);
		return;
	}
	case M_setUseSurrogates: {
		bool val;
		if (ParamIndexToVal(0, (char&)val))
			_o_return_result;
		mC->setUseSurrogates(val);
		return;
	}
	}
}

void ml_EM::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::ml::EM>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		mC = cv::ml::EM::create();
		return;
	}
	case M_getClustersNumber: {
		auto __retval = (__int64)mC->getClustersNumber();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getCovarianceMatrixType: {
		auto __retval = (__int64)mC->getCovarianceMatrixType();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getCovs: {
		std::vector<cv::Mat> covs;
		VarRef* var_covs = nullptr;
		if (ParamIndexToVal(0, var_covs))
			_o_return_result;
		mC->getCovs(covs);
		ValToResult(covs, aResultToken);
		g_ahkapi->VarAssign(var_covs, aResultToken);
		g_ahkapi->ResultTokenFree(aResultToken);
		return;
	}
	case M_getMeans: {
		auto __retval = (Mat*)Mat::sPrototype->New(g_invalidparam, 1);
		__retval->mC = mC->getMeans();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getTermCriteria: {
		auto __retval = mC->getTermCriteria();
		return ValToResult(__retval, aResultToken);
	}
	case M_getWeights: {
		auto __retval = (Mat*)Mat::sPrototype->New(g_invalidparam, 1);
		__retval->mC = mC->getWeights();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_load: {
		cv::String filepath, nodeName = cv::String();
		if (ParamIndexToVal(0, filepath))
			_o_return_result;
		if (aParamCount > 1 && aParam[1]->symbol != SYM_MISSING)
			TokenToVal(*aParam[1], nodeName);
		auto __retval = (ml_EM*)ml_EM::sPrototype->New(g_invalidparam, 1);
		__retval->mC = mC->load(filepath, nodeName);
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_predict: {
		cv::_InputArray samples;
		cv::_OutputArray results = cv::noArray();
		int flags = 0;
		if (ParamIndexToVal(0, samples))
			_o_return_result;
		if (aParamCount > 1 && aParam[1]->symbol != SYM_MISSING)
			TokenToVal(*aParam[1], results);
		if (aParamCount > 2 && aParam[2]->symbol != SYM_MISSING)
			TokenToVal(*aParam[2], flags);
		auto __retval = (double)mC->predict(samples, results, flags);
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_predict2: {
		cv::_InputArray sample;
		cv::_OutputArray probs;
		if (ParamIndexToVal(0, sample))
			_o_return_result;
		if (ParamIndexToVal(1, probs))
			_o_return_result;
		auto __retval = mC->predict2(sample, probs);
		return ValToResult(__retval, aResultToken);
	}
	case M_setClustersNumber: {
		int val;
		if (ParamIndexToVal(0, val))
			_o_return_result;
		mC->setClustersNumber(val);
		return;
	}
	case M_setCovarianceMatrixType: {
		int val;
		if (ParamIndexToVal(0, val))
			_o_return_result;
		mC->setCovarianceMatrixType(val);
		return;
	}
	case M_setTermCriteria: {
		cv::TermCriteria val;
		if (ParamIndexToVal(0, val))
			_o_return_result;
		mC->setTermCriteria(val);
		return;
	}
	case M_trainE: {
		cv::_InputArray samples, means0, covs0 = cv::noArray(), weights0 = cv::noArray();
		cv::_OutputArray logLikelihoods = cv::noArray(), labels = cv::noArray(), probs = cv::noArray();
		if (ParamIndexToVal(0, samples))
			_o_return_result;
		if (ParamIndexToVal(1, means0))
			_o_return_result;
		if (aParamCount > 2 && aParam[2]->symbol != SYM_MISSING)
			TokenToVal(*aParam[2], covs0);
		if (aParamCount > 3 && aParam[3]->symbol != SYM_MISSING)
			TokenToVal(*aParam[3], weights0);
		if (aParamCount > 4 && aParam[4]->symbol != SYM_MISSING)
			TokenToVal(*aParam[4], logLikelihoods);
		if (aParamCount > 5 && aParam[5]->symbol != SYM_MISSING)
			TokenToVal(*aParam[5], labels);
		if (aParamCount > 6 && aParam[6]->symbol != SYM_MISSING)
			TokenToVal(*aParam[6], probs);
		auto __retval = (__int64)mC->trainE(samples, means0, covs0, weights0, logLikelihoods, labels, probs);
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_trainEM: {
		cv::_InputArray samples;
		cv::_OutputArray logLikelihoods = cv::noArray(), labels = cv::noArray(), probs = cv::noArray();
		if (ParamIndexToVal(0, samples))
			_o_return_result;
		if (aParamCount > 1 && aParam[1]->symbol != SYM_MISSING)
			TokenToVal(*aParam[1], logLikelihoods);
		if (aParamCount > 2 && aParam[2]->symbol != SYM_MISSING)
			TokenToVal(*aParam[2], labels);
		if (aParamCount > 3 && aParam[3]->symbol != SYM_MISSING)
			TokenToVal(*aParam[3], probs);
		auto __retval = (__int64)mC->trainEM(samples, logLikelihoods, labels, probs);
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_trainM: {
		cv::_InputArray samples, probs0;
		cv::_OutputArray logLikelihoods = cv::noArray(), labels = cv::noArray(), probs = cv::noArray();
		if (ParamIndexToVal(0, samples))
			_o_return_result;
		if (ParamIndexToVal(1, probs0))
			_o_return_result;
		if (aParamCount > 2 && aParam[2]->symbol != SYM_MISSING)
			TokenToVal(*aParam[2], logLikelihoods);
		if (aParamCount > 3 && aParam[3]->symbol != SYM_MISSING)
			TokenToVal(*aParam[3], labels);
		if (aParamCount > 4 && aParam[4]->symbol != SYM_MISSING)
			TokenToVal(*aParam[4], probs);
		auto __retval = (__int64)mC->trainM(samples, probs0, logLikelihoods, labels, probs);
		return (void)(aResultToken.SetValue(__retval));
	}
	}
}

void ml_KNearest::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::ml::KNearest>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		mC = cv::ml::KNearest::create();
		return;
	}
	case M_findNearest: {
		cv::_InputArray samples;
		cv::_OutputArray results, neighborResponses = cv::noArray(), dist = cv::noArray();
		int k;
		if (ParamIndexToVal(0, samples))
			_o_return_result;
		if (ParamIndexToVal(1, k))
			_o_return_result;
		if (ParamIndexToVal(2, results))
			_o_return_result;
		if (aParamCount > 3 && aParam[3]->symbol != SYM_MISSING)
			TokenToVal(*aParam[3], neighborResponses);
		if (aParamCount > 4 && aParam[4]->symbol != SYM_MISSING)
			TokenToVal(*aParam[4], dist);
		auto __retval = (double)mC->findNearest(samples, k, results, neighborResponses, dist);
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getAlgorithmType: {
		auto __retval = (__int64)mC->getAlgorithmType();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getDefaultK: {
		auto __retval = (__int64)mC->getDefaultK();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getEmax: {
		auto __retval = (__int64)mC->getEmax();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getIsClassifier: {
		auto __retval = (__int64)mC->getIsClassifier();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_load: {
		cv::String filepath;
		if (ParamIndexToVal(0, filepath))
			_o_return_result;
		auto __retval = (ml_KNearest*)ml_KNearest::sPrototype->New(g_invalidparam, 1);
		__retval->mC = mC->load(filepath);
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_setAlgorithmType: {
		int val;
		if (ParamIndexToVal(0, val))
			_o_return_result;
		mC->setAlgorithmType(val);
		return;
	}
	case M_setDefaultK: {
		int val;
		if (ParamIndexToVal(0, val))
			_o_return_result;
		mC->setDefaultK(val);
		return;
	}
	case M_setEmax: {
		int val;
		if (ParamIndexToVal(0, val))
			_o_return_result;
		mC->setEmax(val);
		return;
	}
	case M_setIsClassifier: {
		bool val;
		if (ParamIndexToVal(0, (char&)val))
			_o_return_result;
		mC->setIsClassifier(val);
		return;
	}
	}
}

void ml_LogisticRegression::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::ml::LogisticRegression>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		mC = cv::ml::LogisticRegression::create();
		return;
	}
	case M_getIterations: {
		auto __retval = (__int64)mC->getIterations();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getLearningRate: {
		auto __retval = mC->getLearningRate();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getMiniBatchSize: {
		auto __retval = (__int64)mC->getMiniBatchSize();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getRegularization: {
		auto __retval = (__int64)mC->getRegularization();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getTermCriteria: {
		auto __retval = mC->getTermCriteria();
		return ValToResult(__retval, aResultToken);
	}
	case M_getTrainMethod: {
		auto __retval = (__int64)mC->getTrainMethod();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_get_learnt_thetas: {
		auto __retval = (Mat*)Mat::sPrototype->New(g_invalidparam, 1);
		__retval->mC = mC->get_learnt_thetas();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_load: {
		cv::String filepath, nodeName = cv::String();
		if (ParamIndexToVal(0, filepath))
			_o_return_result;
		if (aParamCount > 1 && aParam[1]->symbol != SYM_MISSING)
			TokenToVal(*aParam[1], nodeName);
		auto __retval = (ml_LogisticRegression*)ml_LogisticRegression::sPrototype->New(g_invalidparam, 1);
		__retval->mC = mC->load(filepath, nodeName);
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_predict: {
		cv::_InputArray samples;
		cv::_OutputArray results = cv::noArray();
		int flags = 0;
		if (ParamIndexToVal(0, samples))
			_o_return_result;
		if (aParamCount > 1 && aParam[1]->symbol != SYM_MISSING)
			TokenToVal(*aParam[1], results);
		if (aParamCount > 2 && aParam[2]->symbol != SYM_MISSING)
			TokenToVal(*aParam[2], flags);
		auto __retval = (double)mC->predict(samples, results, flags);
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_setIterations: {
		int val;
		if (ParamIndexToVal(0, val))
			_o_return_result;
		mC->setIterations(val);
		return;
	}
	case M_setLearningRate: {
		double val;
		if (ParamIndexToVal(0, val))
			_o_return_result;
		mC->setLearningRate(val);
		return;
	}
	case M_setMiniBatchSize: {
		int val;
		if (ParamIndexToVal(0, val))
			_o_return_result;
		mC->setMiniBatchSize(val);
		return;
	}
	case M_setRegularization: {
		int val;
		if (ParamIndexToVal(0, val))
			_o_return_result;
		mC->setRegularization(val);
		return;
	}
	case M_setTermCriteria: {
		cv::TermCriteria val;
		if (ParamIndexToVal(0, val))
			_o_return_result;
		mC->setTermCriteria(val);
		return;
	}
	case M_setTrainMethod: {
		int val;
		if (ParamIndexToVal(0, val))
			_o_return_result;
		mC->setTrainMethod(val);
		return;
	}
	}
}

void ml_NormalBayesClassifier::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::ml::NormalBayesClassifier>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		mC = cv::ml::NormalBayesClassifier::create();
		return;
	}
	case M_load: {
		cv::String filepath, nodeName = cv::String();
		if (ParamIndexToVal(0, filepath))
			_o_return_result;
		if (aParamCount > 1 && aParam[1]->symbol != SYM_MISSING)
			TokenToVal(*aParam[1], nodeName);
		auto __retval = (ml_NormalBayesClassifier*)ml_NormalBayesClassifier::sPrototype->New(g_invalidparam, 1);
		__retval->mC = mC->load(filepath, nodeName);
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_predictProb: {
		cv::_InputArray inputs;
		cv::_OutputArray outputs, outputProbs;
		int flags = 0;
		if (ParamIndexToVal(0, inputs))
			_o_return_result;
		if (ParamIndexToVal(1, outputs))
			_o_return_result;
		if (ParamIndexToVal(2, outputProbs))
			_o_return_result;
		if (aParamCount > 3 && aParam[3]->symbol != SYM_MISSING)
			TokenToVal(*aParam[3], flags);
		auto __retval = (double)mC->predictProb(inputs, outputs, outputProbs, flags);
		return (void)(aResultToken.SetValue(__retval));
	}
	}
}

void ml_ParamGrid::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::ml::ParamGrid>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		double minVal = 0., maxVal = 0., logstep = 1.;
		if (aParamCount > 0 && aParam[0]->symbol != SYM_MISSING)
			TokenToVal(*aParam[0], minVal);
		if (aParamCount > 1 && aParam[1]->symbol != SYM_MISSING)
			TokenToVal(*aParam[1], maxVal);
		if (aParamCount > 2 && aParam[2]->symbol != SYM_MISSING)
			TokenToVal(*aParam[2], logstep);
		mC = cv::ml::ParamGrid::create(minVal, maxVal, logstep);
		return;
	}
	}
}

void ml_RTrees::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::ml::RTrees>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		mC = cv::ml::RTrees::create();
		return;
	}
	case M_getActiveVarCount: {
		auto __retval = (__int64)mC->getActiveVarCount();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getCalculateVarImportance: {
		auto __retval = (__int64)mC->getCalculateVarImportance();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getOOBError: {
		auto __retval = mC->getOOBError();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getTermCriteria: {
		auto __retval = mC->getTermCriteria();
		return ValToResult(__retval, aResultToken);
	}
	case M_getVarImportance: {
		auto __retval = (Mat*)Mat::sPrototype->New(g_invalidparam, 1);
		__retval->mC = mC->getVarImportance();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getVotes: {
		cv::_InputArray samples;
		cv::_OutputArray results;
		int flags;
		if (ParamIndexToVal(0, samples))
			_o_return_result;
		if (ParamIndexToVal(1, results))
			_o_return_result;
		if (ParamIndexToVal(2, flags))
			_o_return_result;
		mC->getVotes(samples, results, flags);
		return;
	}
	case M_load: {
		cv::String filepath, nodeName = cv::String();
		if (ParamIndexToVal(0, filepath))
			_o_return_result;
		if (aParamCount > 1 && aParam[1]->symbol != SYM_MISSING)
			TokenToVal(*aParam[1], nodeName);
		auto __retval = (ml_RTrees*)ml_RTrees::sPrototype->New(g_invalidparam, 1);
		__retval->mC = mC->load(filepath, nodeName);
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_setActiveVarCount: {
		int val;
		if (ParamIndexToVal(0, val))
			_o_return_result;
		mC->setActiveVarCount(val);
		return;
	}
	case M_setCalculateVarImportance: {
		bool val;
		if (ParamIndexToVal(0, (char&)val))
			_o_return_result;
		mC->setCalculateVarImportance(val);
		return;
	}
	case M_setTermCriteria: {
		cv::TermCriteria val;
		if (ParamIndexToVal(0, val))
			_o_return_result;
		mC->setTermCriteria(val);
		return;
	}
	}
}

void ml_SVM::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::ml::SVM>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		mC = cv::ml::SVM::create();
		return;
	}
	case M_getC: {
		auto __retval = mC->getC();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getClassWeights: {
		auto __retval = (Mat*)Mat::sPrototype->New(g_invalidparam, 1);
		__retval->mC = mC->getClassWeights();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getCoef0: {
		auto __retval = mC->getCoef0();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getDecisionFunction: {
		cv::_OutputArray alpha, svidx;
		int i;
		if (ParamIndexToVal(0, i))
			_o_return_result;
		if (ParamIndexToVal(1, alpha))
			_o_return_result;
		if (ParamIndexToVal(2, svidx))
			_o_return_result;
		auto __retval = mC->getDecisionFunction(i, alpha, svidx);
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getDefaultGridPtr: {
		int param_id;
		if (ParamIndexToVal(0, param_id))
			_o_return_result;
		auto __retval = (ml_ParamGrid*)ml_ParamGrid::sPrototype->New(g_invalidparam, 1);
		__retval->mC = mC->getDefaultGridPtr(param_id);
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getDegree: {
		auto __retval = mC->getDegree();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getGamma: {
		auto __retval = mC->getGamma();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getKernelType: {
		auto __retval = (__int64)mC->getKernelType();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getNu: {
		auto __retval = mC->getNu();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getP: {
		auto __retval = mC->getP();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getSupportVectors: {
		auto __retval = (Mat*)Mat::sPrototype->New(g_invalidparam, 1);
		__retval->mC = mC->getSupportVectors();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getTermCriteria: {
		auto __retval = mC->getTermCriteria();
		return ValToResult(__retval, aResultToken);
	}
	case M_getType: {
		auto __retval = (__int64)mC->getType();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getUncompressedSupportVectors: {
		auto __retval = (Mat*)Mat::sPrototype->New(g_invalidparam, 1);
		__retval->mC = mC->getUncompressedSupportVectors();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_load: {
		cv::String filepath;
		if (ParamIndexToVal(0, filepath))
			_o_return_result;
		auto __retval = (ml_SVM*)ml_SVM::sPrototype->New(g_invalidparam, 1);
		__retval->mC = mC->load(filepath);
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_setC: {
		double val;
		if (ParamIndexToVal(0, val))
			_o_return_result;
		mC->setC(val);
		return;
	}
	case M_setClassWeights: {
		cv::Mat val;
		if (ParamIndexToVal(0, val))
			_o_return_result;
		mC->setClassWeights(val);
		return;
	}
	case M_setCoef0: {
		double val;
		if (ParamIndexToVal(0, val))
			_o_return_result;
		mC->setCoef0(val);
		return;
	}
	case M_setDegree: {
		double val;
		if (ParamIndexToVal(0, val))
			_o_return_result;
		mC->setDegree(val);
		return;
	}
	case M_setGamma: {
		double val;
		if (ParamIndexToVal(0, val))
			_o_return_result;
		mC->setGamma(val);
		return;
	}
	case M_setKernel: {
		int kernelType;
		if (ParamIndexToVal(0, kernelType))
			_o_return_result;
		mC->setKernel(kernelType);
		return;
	}
	case M_setNu: {
		double val;
		if (ParamIndexToVal(0, val))
			_o_return_result;
		mC->setNu(val);
		return;
	}
	case M_setP: {
		double val;
		if (ParamIndexToVal(0, val))
			_o_return_result;
		mC->setP(val);
		return;
	}
	case M_setTermCriteria: {
		cv::TermCriteria val;
		if (ParamIndexToVal(0, val))
			_o_return_result;
		mC->setTermCriteria(val);
		return;
	}
	case M_setType: {
		int val;
		if (ParamIndexToVal(0, val))
			_o_return_result;
		mC->setType(val);
		return;
	}
	case M_trainAuto: {
		bool balanced = false;
		cv::_InputArray samples, responses;
		cv::Ptr<cv::ml::ParamGrid> Cgrid = cv::ml::SVM::getDefaultGridPtr(cv::ml::SVM::C), gammaGrid = cv::ml::SVM::getDefaultGridPtr(cv::ml::SVM::GAMMA), pGrid = cv::ml::SVM::getDefaultGridPtr(cv::ml::SVM::P), nuGrid = cv::ml::SVM::getDefaultGridPtr(cv::ml::SVM::NU), coeffGrid = cv::ml::SVM::getDefaultGridPtr(cv::ml::SVM::COEF), degreeGrid = cv::ml::SVM::getDefaultGridPtr(cv::ml::SVM::DEGREE);
		int layout, kFold = 10;
		if (ParamIndexToVal(0, samples))
			_o_return_result;
		if (ParamIndexToVal(1, layout))
			_o_return_result;
		if (ParamIndexToVal(2, responses))
			_o_return_result;
		if (aParamCount > 3 && aParam[3]->symbol != SYM_MISSING)
			TokenToVal(*aParam[3], kFold);
		if (aParamCount > 4 && aParam[4]->symbol != SYM_MISSING)
			TokenToVal(*aParam[4], Cgrid);
		if (aParamCount > 5 && aParam[5]->symbol != SYM_MISSING)
			TokenToVal(*aParam[5], gammaGrid);
		if (aParamCount > 6 && aParam[6]->symbol != SYM_MISSING)
			TokenToVal(*aParam[6], pGrid);
		if (aParamCount > 7 && aParam[7]->symbol != SYM_MISSING)
			TokenToVal(*aParam[7], nuGrid);
		if (aParamCount > 8 && aParam[8]->symbol != SYM_MISSING)
			TokenToVal(*aParam[8], coeffGrid);
		if (aParamCount > 9 && aParam[9]->symbol != SYM_MISSING)
			TokenToVal(*aParam[9], degreeGrid);
		if (aParamCount > 10 && aParam[10]->symbol != SYM_MISSING)
			TokenToVal(*aParam[10], (char&)balanced);
		auto __retval = (__int64)mC->trainAuto(samples, layout, responses, kFold, Cgrid, gammaGrid, pGrid, nuGrid, coeffGrid, degreeGrid, balanced);
		return (void)(aResultToken.SetValue(__retval));
	}
	}
}

void ml_SVMSGD::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::ml::SVMSGD>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		mC = cv::ml::SVMSGD::create();
		return;
	}
	case M_getInitialStepSize: {
		auto __retval = (double)mC->getInitialStepSize();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getMarginRegularization: {
		auto __retval = (double)mC->getMarginRegularization();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getMarginType: {
		auto __retval = (__int64)mC->getMarginType();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getShift: {
		auto __retval = (double)mC->getShift();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getStepDecreasingPower: {
		auto __retval = (double)mC->getStepDecreasingPower();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getSvmsgdType: {
		auto __retval = (__int64)mC->getSvmsgdType();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getTermCriteria: {
		auto __retval = mC->getTermCriteria();
		return ValToResult(__retval, aResultToken);
	}
	case M_getWeights: {
		auto __retval = (Mat*)Mat::sPrototype->New(g_invalidparam, 1);
		__retval->mC = mC->getWeights();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_load: {
		cv::String filepath, nodeName = cv::String();
		if (ParamIndexToVal(0, filepath))
			_o_return_result;
		if (aParamCount > 1 && aParam[1]->symbol != SYM_MISSING)
			TokenToVal(*aParam[1], nodeName);
		auto __retval = (ml_SVMSGD*)ml_SVMSGD::sPrototype->New(g_invalidparam, 1);
		__retval->mC = mC->load(filepath, nodeName);
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_setInitialStepSize: {
		float InitialStepSize;
		if (ParamIndexToVal(0, InitialStepSize))
			_o_return_result;
		mC->setInitialStepSize(InitialStepSize);
		return;
	}
	case M_setMarginRegularization: {
		float marginRegularization;
		if (ParamIndexToVal(0, marginRegularization))
			_o_return_result;
		mC->setMarginRegularization(marginRegularization);
		return;
	}
	case M_setMarginType: {
		int marginType;
		if (ParamIndexToVal(0, marginType))
			_o_return_result;
		mC->setMarginType(marginType);
		return;
	}
	case M_setOptimalParameters: {
		int svmsgdType = cv::ml::SVMSGD::ASGD, marginType = cv::ml::SVMSGD::SOFT_MARGIN;
		if (aParamCount > 0 && aParam[0]->symbol != SYM_MISSING)
			TokenToVal(*aParam[0], svmsgdType);
		if (aParamCount > 1 && aParam[1]->symbol != SYM_MISSING)
			TokenToVal(*aParam[1], marginType);
		mC->setOptimalParameters(svmsgdType, marginType);
		return;
	}
	case M_setStepDecreasingPower: {
		float stepDecreasingPower;
		if (ParamIndexToVal(0, stepDecreasingPower))
			_o_return_result;
		mC->setStepDecreasingPower(stepDecreasingPower);
		return;
	}
	case M_setSvmsgdType: {
		int svmsgdType;
		if (ParamIndexToVal(0, svmsgdType))
			_o_return_result;
		mC->setSvmsgdType(svmsgdType);
		return;
	}
	case M_setTermCriteria: {
		cv::TermCriteria val;
		if (ParamIndexToVal(0, val))
			_o_return_result;
		mC->setTermCriteria(val);
		return;
	}
	}
}

void ml_StatModel::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M_calcError: {
		bool test;
		cv::_OutputArray resp;
		cv::Ptr<cv::ml::TrainData> data;
		if (ParamIndexToVal(0, data))
			_o_return_result;
		if (ParamIndexToVal(1, (char&)test))
			_o_return_result;
		if (ParamIndexToVal(2, resp))
			_o_return_result;
		auto __retval = (double)mC->calcError(data, test, resp);
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_empty: {
		auto __retval = (__int64)mC->empty();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getVarCount: {
		auto __retval = (__int64)mC->getVarCount();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_isClassifier: {
		auto __retval = (__int64)mC->isClassifier();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_isTrained: {
		auto __retval = (__int64)mC->isTrained();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_predict: {
		cv::_InputArray samples;
		cv::_OutputArray results = cv::noArray();
		int flags = 0;
		if (ParamIndexToVal(0, samples))
			_o_return_result;
		if (aParamCount > 1 && aParam[1]->symbol != SYM_MISSING)
			TokenToVal(*aParam[1], results);
		if (aParamCount > 2 && aParam[2]->symbol != SYM_MISSING)
			TokenToVal(*aParam[2], flags);
		auto __retval = (double)mC->predict(samples, results, flags);
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_train: {
		if (1 <= aParamCount && aParamCount <= 2) {
			cv::Ptr<cv::ml::TrainData> trainData;
			int flags = 0;
			if (ParamIndexToVal(0, trainData))
				_o_return_result;
			if (aParamCount > 1 && aParam[1]->symbol != SYM_MISSING)
				TokenToVal(*aParam[1], flags);
			auto __retval = (__int64)mC->train(trainData, flags);
			return (void)(aResultToken.SetValue(__retval));
		}
		else if (aParamCount == 3) {
			cv::_InputArray samples, responses;
			int layout;
			if (ParamIndexToVal(0, samples))
				_o_return_result;
			if (ParamIndexToVal(1, layout))
				_o_return_result;
			if (ParamIndexToVal(2, responses))
				_o_return_result;
			auto __retval = (__int64)mC->train(samples, layout, responses);
			return (void)(aResultToken.SetValue(__retval));
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	}
}

void ml_TrainData::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::ml::TrainData>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		cv::_InputArray samples, responses, varIdx = cv::noArray(), sampleIdx = cv::noArray(), sampleWeights = cv::noArray(), varType = cv::noArray();
		int layout;
		if (ParamIndexToVal(0, samples))
			_o_return_result;
		if (ParamIndexToVal(1, layout))
			_o_return_result;
		if (ParamIndexToVal(2, responses))
			_o_return_result;
		if (aParamCount > 3 && aParam[3]->symbol != SYM_MISSING)
			TokenToVal(*aParam[3], varIdx);
		if (aParamCount > 4 && aParam[4]->symbol != SYM_MISSING)
			TokenToVal(*aParam[4], sampleIdx);
		if (aParamCount > 5 && aParam[5]->symbol != SYM_MISSING)
			TokenToVal(*aParam[5], sampleWeights);
		if (aParamCount > 6 && aParam[6]->symbol != SYM_MISSING)
			TokenToVal(*aParam[6], varType);
		mC = cv::ml::TrainData::create(samples, layout, responses, varIdx, sampleIdx, sampleWeights, varType);
		return;
	}
	case M_getCatCount: {
		int vi;
		if (ParamIndexToVal(0, vi))
			_o_return_result;
		auto __retval = (__int64)mC->getCatCount(vi);
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getCatMap: {
		auto __retval = (Mat*)Mat::sPrototype->New(g_invalidparam, 1);
		__retval->mC = mC->getCatMap();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getCatOfs: {
		auto __retval = (Mat*)Mat::sPrototype->New(g_invalidparam, 1);
		__retval->mC = mC->getCatOfs();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getClassLabels: {
		auto __retval = (Mat*)Mat::sPrototype->New(g_invalidparam, 1);
		__retval->mC = mC->getClassLabels();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getDefaultSubstValues: {
		auto __retval = (Mat*)Mat::sPrototype->New(g_invalidparam, 1);
		__retval->mC = mC->getDefaultSubstValues();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getLayout: {
		auto __retval = (__int64)mC->getLayout();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getMissing: {
		auto __retval = (Mat*)Mat::sPrototype->New(g_invalidparam, 1);
		__retval->mC = mC->getMissing();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getNAllVars: {
		auto __retval = (__int64)mC->getNAllVars();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getNSamples: {
		auto __retval = (__int64)mC->getNSamples();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getNTestSamples: {
		auto __retval = (__int64)mC->getNTestSamples();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getNTrainSamples: {
		auto __retval = (__int64)mC->getNTrainSamples();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getNVars: {
		auto __retval = (__int64)mC->getNVars();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getNames: {
		std::vector<cv::String> names;
		if (ParamIndexToVal(0, names))
			_o_return_result;
		mC->getNames(names);
		return;
	}
	case M_getNormCatResponses: {
		auto __retval = (Mat*)Mat::sPrototype->New(g_invalidparam, 1);
		__retval->mC = mC->getNormCatResponses();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getResponseType: {
		auto __retval = (__int64)mC->getResponseType();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getResponses: {
		auto __retval = (Mat*)Mat::sPrototype->New(g_invalidparam, 1);
		__retval->mC = mC->getResponses();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getSample: {
		cv::_InputArray varIdx;
		float buf;
		int sidx;
		if (ParamIndexToVal(0, varIdx))
			_o_return_result;
		if (ParamIndexToVal(1, sidx))
			_o_return_result;
		VarRef* var_buf = nullptr;
		if (ParamIndexToVal(2, var_buf))
			_o_return_result;
		mC->getSample(varIdx, sidx, &buf);
		g_ahkapi->VarAssign(var_buf, ExprTokenType((double)buf));
		return;
	}
	case M_getSampleWeights: {
		auto __retval = (Mat*)Mat::sPrototype->New(g_invalidparam, 1);
		__retval->mC = mC->getSampleWeights();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getSamples: {
		auto __retval = (Mat*)Mat::sPrototype->New(g_invalidparam, 1);
		__retval->mC = mC->getSamples();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getSubMatrix: {
		cv::Mat matrix, idx;
		int layout;
		if (ParamIndexToVal(0, matrix))
			_o_return_result;
		if (ParamIndexToVal(1, idx))
			_o_return_result;
		if (ParamIndexToVal(2, layout))
			_o_return_result;
		auto __retval = (Mat*)Mat::sPrototype->New(g_invalidparam, 1);
		__retval->mC = mC->getSubMatrix(matrix, idx, layout);
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getSubVector: {
		cv::Mat vec, idx;
		if (ParamIndexToVal(0, vec))
			_o_return_result;
		if (ParamIndexToVal(1, idx))
			_o_return_result;
		auto __retval = (Mat*)Mat::sPrototype->New(g_invalidparam, 1);
		__retval->mC = mC->getSubVector(vec, idx);
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getTestNormCatResponses: {
		auto __retval = (Mat*)Mat::sPrototype->New(g_invalidparam, 1);
		__retval->mC = mC->getTestNormCatResponses();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getTestResponses: {
		auto __retval = (Mat*)Mat::sPrototype->New(g_invalidparam, 1);
		__retval->mC = mC->getTestResponses();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getTestSampleIdx: {
		auto __retval = (Mat*)Mat::sPrototype->New(g_invalidparam, 1);
		__retval->mC = mC->getTestSampleIdx();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getTestSampleWeights: {
		auto __retval = (Mat*)Mat::sPrototype->New(g_invalidparam, 1);
		__retval->mC = mC->getTestSampleWeights();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getTestSamples: {
		auto __retval = (Mat*)Mat::sPrototype->New(g_invalidparam, 1);
		__retval->mC = mC->getTestSamples();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getTrainNormCatResponses: {
		auto __retval = (Mat*)Mat::sPrototype->New(g_invalidparam, 1);
		__retval->mC = mC->getTrainNormCatResponses();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getTrainResponses: {
		auto __retval = (Mat*)Mat::sPrototype->New(g_invalidparam, 1);
		__retval->mC = mC->getTrainResponses();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getTrainSampleIdx: {
		auto __retval = (Mat*)Mat::sPrototype->New(g_invalidparam, 1);
		__retval->mC = mC->getTrainSampleIdx();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getTrainSampleWeights: {
		auto __retval = (Mat*)Mat::sPrototype->New(g_invalidparam, 1);
		__retval->mC = mC->getTrainSampleWeights();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getTrainSamples: {
		bool compressSamples = true, compressVars = true;
		int layout = cv::ml::ROW_SAMPLE;
		if (aParamCount > 0 && aParam[0]->symbol != SYM_MISSING)
			TokenToVal(*aParam[0], layout);
		if (aParamCount > 1 && aParam[1]->symbol != SYM_MISSING)
			TokenToVal(*aParam[1], (char&)compressSamples);
		if (aParamCount > 2 && aParam[2]->symbol != SYM_MISSING)
			TokenToVal(*aParam[2], (char&)compressVars);
		auto __retval = (Mat*)Mat::sPrototype->New(g_invalidparam, 1);
		__retval->mC = mC->getTrainSamples(layout, compressSamples, compressVars);
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getValues: {
		cv::_InputArray sidx;
		float values;
		int vi;
		if (ParamIndexToVal(0, vi))
			_o_return_result;
		if (ParamIndexToVal(1, sidx))
			_o_return_result;
		VarRef* var_values = nullptr;
		if (ParamIndexToVal(2, var_values))
			_o_return_result;
		mC->getValues(vi, sidx, &values);
		g_ahkapi->VarAssign(var_values, ExprTokenType((double)values));
		return;
	}
	case M_getVarIdx: {
		auto __retval = (Mat*)Mat::sPrototype->New(g_invalidparam, 1);
		__retval->mC = mC->getVarIdx();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getVarSymbolFlags: {
		auto __retval = (Mat*)Mat::sPrototype->New(g_invalidparam, 1);
		__retval->mC = mC->getVarSymbolFlags();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_getVarType: {
		auto __retval = (Mat*)Mat::sPrototype->New(g_invalidparam, 1);
		__retval->mC = mC->getVarType();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_setTrainTestSplit: {
		bool shuffle = true;
		int count;
		if (ParamIndexToVal(0, count))
			_o_return_result;
		if (aParamCount > 1 && aParam[1]->symbol != SYM_MISSING)
			TokenToVal(*aParam[1], (char&)shuffle);
		mC->setTrainTestSplit(count, shuffle);
		return;
	}
	case M_setTrainTestSplitRatio: {
		bool shuffle = true;
		double ratio;
		if (ParamIndexToVal(0, ratio))
			_o_return_result;
		if (aParamCount > 1 && aParam[1]->symbol != SYM_MISSING)
			TokenToVal(*aParam[1], (char&)shuffle);
		mC->setTrainTestSplitRatio(ratio, shuffle);
		return;
	}
	case M_shuffleTrainTest: {
		mC->shuffleTrainTest();
		return;
	}
	}
}

void ocl_Device::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::ocl::Device>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		mC = new cv::ocl::Device();
		return;
	}
	case M_OpenCLVersion: {
		auto __retval = mC->OpenCLVersion();
		return ValToResult(__retval, aResultToken);
	}
	case M_OpenCL_C_Version: {
		auto __retval = mC->OpenCL_C_Version();
		return ValToResult(__retval, aResultToken);
	}
	case M_addressBits: {
		auto __retval = (__int64)mC->addressBits();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_available: {
		auto __retval = (__int64)mC->available();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_compilerAvailable: {
		auto __retval = (__int64)mC->compilerAvailable();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_deviceVersionMajor: {
		auto __retval = (__int64)mC->deviceVersionMajor();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_deviceVersionMinor: {
		auto __retval = (__int64)mC->deviceVersionMinor();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_doubleFPConfig: {
		auto __retval = (__int64)mC->doubleFPConfig();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_driverVersion: {
		auto __retval = mC->driverVersion();
		return ValToResult(__retval, aResultToken);
	}
	case M_endianLittle: {
		auto __retval = (__int64)mC->endianLittle();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_errorCorrectionSupport: {
		auto __retval = (__int64)mC->errorCorrectionSupport();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_executionCapabilities: {
		auto __retval = (__int64)mC->executionCapabilities();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_extensions: {
		auto __retval = mC->extensions();
		return ValToResult(__retval, aResultToken);
	}
	case M_getDefault: {
		auto __retval = (ocl_Device*)ocl_Device::sPrototype->New(g_invalidparam, 1);
		__retval->mC = cv::makePtr<cv::ocl::Device>(cv::ocl::Device::getDefault());
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_globalMemCacheLineSize: {
		auto __retval = (__int64)mC->globalMemCacheLineSize();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_globalMemCacheSize: {
		auto __retval = (__int64)mC->globalMemCacheSize();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_globalMemCacheType: {
		auto __retval = (__int64)mC->globalMemCacheType();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_globalMemSize: {
		auto __retval = (__int64)mC->globalMemSize();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_halfFPConfig: {
		auto __retval = (__int64)mC->halfFPConfig();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_hostUnifiedMemory: {
		auto __retval = (__int64)mC->hostUnifiedMemory();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_image2DMaxHeight: {
		auto __retval = (__int64)mC->image2DMaxHeight();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_image2DMaxWidth: {
		auto __retval = (__int64)mC->image2DMaxWidth();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_image3DMaxDepth: {
		auto __retval = (__int64)mC->image3DMaxDepth();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_image3DMaxHeight: {
		auto __retval = (__int64)mC->image3DMaxHeight();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_image3DMaxWidth: {
		auto __retval = (__int64)mC->image3DMaxWidth();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_imageFromBufferSupport: {
		auto __retval = (__int64)mC->imageFromBufferSupport();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_imageMaxArraySize: {
		auto __retval = (__int64)mC->imageMaxArraySize();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_imageMaxBufferSize: {
		auto __retval = (__int64)mC->imageMaxBufferSize();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_imageSupport: {
		auto __retval = (__int64)mC->imageSupport();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_intelSubgroupsSupport: {
		auto __retval = (__int64)mC->intelSubgroupsSupport();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_isAMD: {
		auto __retval = (__int64)mC->isAMD();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_isExtensionSupported: {
		cv::String extensionName;
		if (ParamIndexToVal(0, extensionName))
			_o_return_result;
		auto __retval = (__int64)mC->isExtensionSupported(extensionName);
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_isIntel: {
		auto __retval = (__int64)mC->isIntel();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_isNVidia: {
		auto __retval = (__int64)mC->isNVidia();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_linkerAvailable: {
		auto __retval = (__int64)mC->linkerAvailable();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_localMemSize: {
		auto __retval = (__int64)mC->localMemSize();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_localMemType: {
		auto __retval = (__int64)mC->localMemType();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_maxClockFrequency: {
		auto __retval = (__int64)mC->maxClockFrequency();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_maxComputeUnits: {
		auto __retval = (__int64)mC->maxComputeUnits();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_maxConstantArgs: {
		auto __retval = (__int64)mC->maxConstantArgs();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_maxConstantBufferSize: {
		auto __retval = (__int64)mC->maxConstantBufferSize();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_maxMemAllocSize: {
		auto __retval = (__int64)mC->maxMemAllocSize();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_maxParameterSize: {
		auto __retval = (__int64)mC->maxParameterSize();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_maxReadImageArgs: {
		auto __retval = (__int64)mC->maxReadImageArgs();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_maxSamplers: {
		auto __retval = (__int64)mC->maxSamplers();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_maxWorkGroupSize: {
		auto __retval = (__int64)mC->maxWorkGroupSize();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_maxWorkItemDims: {
		auto __retval = (__int64)mC->maxWorkItemDims();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_maxWriteImageArgs: {
		auto __retval = (__int64)mC->maxWriteImageArgs();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_memBaseAddrAlign: {
		auto __retval = (__int64)mC->memBaseAddrAlign();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_name: {
		auto __retval = mC->name();
		return ValToResult(__retval, aResultToken);
	}
	case M_nativeVectorWidthChar: {
		auto __retval = (__int64)mC->nativeVectorWidthChar();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_nativeVectorWidthDouble: {
		auto __retval = (__int64)mC->nativeVectorWidthDouble();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_nativeVectorWidthFloat: {
		auto __retval = (__int64)mC->nativeVectorWidthFloat();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_nativeVectorWidthHalf: {
		auto __retval = (__int64)mC->nativeVectorWidthHalf();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_nativeVectorWidthInt: {
		auto __retval = (__int64)mC->nativeVectorWidthInt();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_nativeVectorWidthLong: {
		auto __retval = (__int64)mC->nativeVectorWidthLong();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_nativeVectorWidthShort: {
		auto __retval = (__int64)mC->nativeVectorWidthShort();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_preferredVectorWidthChar: {
		auto __retval = (__int64)mC->preferredVectorWidthChar();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_preferredVectorWidthDouble: {
		auto __retval = (__int64)mC->preferredVectorWidthDouble();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_preferredVectorWidthFloat: {
		auto __retval = (__int64)mC->preferredVectorWidthFloat();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_preferredVectorWidthHalf: {
		auto __retval = (__int64)mC->preferredVectorWidthHalf();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_preferredVectorWidthInt: {
		auto __retval = (__int64)mC->preferredVectorWidthInt();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_preferredVectorWidthLong: {
		auto __retval = (__int64)mC->preferredVectorWidthLong();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_preferredVectorWidthShort: {
		auto __retval = (__int64)mC->preferredVectorWidthShort();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_printfBufferSize: {
		auto __retval = (__int64)mC->printfBufferSize();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_profilingTimerResolution: {
		auto __retval = (__int64)mC->profilingTimerResolution();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_singleFPConfig: {
		auto __retval = (__int64)mC->singleFPConfig();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_type: {
		auto __retval = (__int64)mC->type();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_vendorID: {
		auto __retval = (__int64)mC->vendorID();
		return (void)(aResultToken.SetValue(__retval));
	}
	case M_vendorName: {
		auto __retval = mC->vendorName();
		return ValToResult(__retval, aResultToken);
	}
	case M_version: {
		auto __retval = mC->version();
		return ValToResult(__retval, aResultToken);
	}
	}
}

void ocl_OpenCLExecutionContext::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: new (&mC) cv::Ptr<cv::ocl::OpenCLExecutionContext>; return;
	}
}

void segmentation_IntelligentScissorsMB::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aID) {
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::segmentation::IntelligentScissorsMB>;
		if (aParamCount == 1 && aParam[0] == g_invalid)return;
		mC = new cv::segmentation::IntelligentScissorsMB();
		return;
	}
	case M_applyImage: {
		cv::_InputArray image;
		if (ParamIndexToVal(0, image))
			_o_return_result;
		mC->applyImage(image);
		aResultToken.SetValue(this);
		AddRef();
		return;
	}
	case M_applyImageFeatures: {
		cv::_InputArray non_edge, gradient_direction, gradient_magnitude, image = cv::noArray();
		if (ParamIndexToVal(0, non_edge))
			_o_return_result;
		if (ParamIndexToVal(1, gradient_direction))
			_o_return_result;
		if (ParamIndexToVal(2, gradient_magnitude))
			_o_return_result;
		if (aParamCount > 3 && aParam[3]->symbol != SYM_MISSING)
			TokenToVal(*aParam[3], image);
		auto __retval = (segmentation_IntelligentScissorsMB*)segmentation_IntelligentScissorsMB::sPrototype->New(g_invalidparam, 1);
		mC->applyImageFeatures(non_edge, gradient_direction, gradient_magnitude, image);
		aResultToken.SetValue(this);
		AddRef();
		return;
	}
	case M_buildMap: {
		cv::Point sourcePt;
		if (ParamIndexToVal(0, sourcePt))
			_o_return_result;
		mC->buildMap(sourcePt);
		return;
	}
	case M_getContour: {
		bool backward = false;
		cv::_OutputArray contour;
		cv::Point targetPt;
		if (ParamIndexToVal(0, targetPt))
			_o_return_result;
		if (ParamIndexToVal(1, contour))
			_o_return_result;
		if (aParamCount > 2 && aParam[2]->symbol != SYM_MISSING)
			TokenToVal(*aParam[2], (char&)backward);
		mC->getContour(targetPt, contour, backward);
		return;
	}
	case M_setEdgeFeatureCannyParameters: {
		bool L2gradient = false;
		double threshold1, threshold2;
		int apertureSize = 3;
		if (ParamIndexToVal(0, threshold1))
			_o_return_result;
		if (ParamIndexToVal(1, threshold2))
			_o_return_result;
		if (aParamCount > 2 && aParam[2]->symbol != SYM_MISSING)
			TokenToVal(*aParam[2], apertureSize);
		if (aParamCount > 3 && aParam[3]->symbol != SYM_MISSING)
			TokenToVal(*aParam[3], (char&)L2gradient);
		mC->setEdgeFeatureCannyParameters(threshold1, threshold2, apertureSize, L2gradient);
		aResultToken.SetValue(this);
		AddRef();
		return;
	}
	case M_setEdgeFeatureZeroCrossingParameters: {
		float gradient_magnitude_min_value = 0.0f;
		if (aParamCount > 0 && aParam[0]->symbol != SYM_MISSING)
			TokenToVal(*aParam[0], gradient_magnitude_min_value);
		mC->setEdgeFeatureZeroCrossingParameters(gradient_magnitude_min_value);
		aResultToken.SetValue(this);
		AddRef();
		return;
	}
	case M_setGradientMagnitudeMaxLimit: {
		float gradient_magnitude_threshold_max = 0.0f;
		if (aParamCount > 0 && aParam[0]->symbol != SYM_MISSING)
			TokenToVal(*aParam[0], gradient_magnitude_threshold_max);
		mC->setGradientMagnitudeMaxLimit(gradient_magnitude_threshold_max);
		aResultToken.SetValue(this);
		AddRef();
		return;
	}
	case M_setWeights: {
		float weight_non_edge, weight_gradient_direction, weight_gradient_magnitude;
		if (ParamIndexToVal(0, weight_non_edge))
			_o_return_result;
		if (ParamIndexToVal(1, weight_gradient_direction))
			_o_return_result;
		if (ParamIndexToVal(2, weight_gradient_magnitude))
			_o_return_result;
		mC->setWeights(weight_non_edge, weight_gradient_direction, weight_gradient_magnitude);
		aResultToken.SetValue(this);
		AddRef();
		return;
	}
	}
}

thread_local IAhkApi::Prototype* AKAZE::sPrototype = nullptr;
ObjectMember AKAZE::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(getDefaultName, 0, 0),
Object_Method(getDescriptorChannels, 0, 0),
Object_Method(getDescriptorSize, 0, 0),
Object_Method(getDescriptorType, 0, 0),
Object_Method(getDiffusivity, 0, 0),
Object_Method(getNOctaveLayers, 0, 0),
Object_Method(getNOctaves, 0, 0),
Object_Method(getThreshold, 0, 0),
Object_Method(setDescriptorChannels, 1, 1),
Object_Method(setDescriptorSize, 1, 1),
Object_Method(setDescriptorType, 1, 1),
Object_Method(setDiffusivity, 1, 1),
Object_Method(setNOctaveLayers, 1, 1),
Object_Method(setNOctaves, 1, 1),
Object_Method(setThreshold, 1, 1),
};
int AKAZE::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* AffineFeature::sPrototype = nullptr;
ObjectMember AffineFeature::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(getDefaultName, 0, 0),
Object_Method(getViewParams, 2, 2),
Object_Method(setViewParams, 2, 2),
};
int AffineFeature::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* AgastFeatureDetector::sPrototype = nullptr;
ObjectMember AgastFeatureDetector::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(getDefaultName, 0, 0),
Object_Method(getNonmaxSuppression, 0, 0),
Object_Method(getThreshold, 0, 0),
Object_Method(getType, 0, 0),
Object_Method(setNonmaxSuppression, 1, 1),
Object_Method(setThreshold, 1, 1),
Object_Method(setType, 1, 1),
};
int AgastFeatureDetector::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* Algorithm::sPrototype = nullptr;
ObjectMember Algorithm::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(clear, 0, 0),
Object_Method(empty, 0, 0),
Object_Method(getDefaultName, 0, 0),
Object_Method(read, 1, 1),
Object_Method(save, 1, 1),
Object_Method(write, 1, 2),
};
int Algorithm::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* AlignExposures::sPrototype = nullptr;
ObjectMember AlignExposures::sMember[] = {
Object_Method(process, 4, 4),
};
int AlignExposures::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* AlignMTB::sPrototype = nullptr;
ObjectMember AlignMTB::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(calculateShift, 2, 2),
Object_Method(computeBitmaps, 3, 3),
Object_Method(getCut, 0, 0),
Object_Method(getExcludeRange, 0, 0),
Object_Method(getMaxBits, 0, 0),
Object_Method(process, 2, 4),
Object_Method(setCut, 1, 1),
Object_Method(setExcludeRange, 1, 1),
Object_Method(setMaxBits, 1, 1),
Object_Method(shiftMat, 3, 3),
};
int AlignMTB::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* AsyncArray::sPrototype = nullptr;
ObjectMember AsyncArray::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(get, 1, 2),
Object_Method(release, 0, 0),
Object_Method(valid, 0, 0),
Object_Method(wait_for, 1, 1),
};
int AsyncArray::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* BFMatcher::sPrototype = nullptr;
ObjectMember BFMatcher::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
};
int BFMatcher::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* BOWImgDescriptorExtractor::sPrototype = nullptr;
ObjectMember BOWImgDescriptorExtractor::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(compute2, 3, 3),
Object_Method(descriptorSize, 0, 0),
Object_Method(descriptorType, 0, 0),
Object_Method(getVocabulary, 0, 0),
Object_Method(setVocabulary, 1, 1),
};
int BOWImgDescriptorExtractor::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* BOWKMeansTrainer::sPrototype = nullptr;
ObjectMember BOWKMeansTrainer::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(cluster, 0, 1),
};
int BOWKMeansTrainer::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* BOWTrainer::sPrototype = nullptr;
ObjectMember BOWTrainer::sMember[] = {
Object_Method(add, 1, 1),
Object_Method(clear, 0, 0),
Object_Method(cluster, 0, 1),
Object_Method(descriptorsCount, 0, 0),
Object_Method(getDescriptors, 0, 0),
};
int BOWTrainer::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* BRISK::sPrototype = nullptr;
ObjectMember BRISK::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(getDefaultName, 0, 0),
Object_Method(getOctaves, 0, 0),
Object_Method(getThreshold, 0, 0),
Object_Method(setOctaves, 1, 1),
Object_Method(setThreshold, 1, 1),
};
int BRISK::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* BackgroundSubtractor::sPrototype = nullptr;
ObjectMember BackgroundSubtractor::sMember[] = {
Object_Method(apply, 2, 3),
Object_Method(getBackgroundImage, 1, 1),
};
int BackgroundSubtractor::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* BackgroundSubtractorKNN::sPrototype = nullptr;
ObjectMember BackgroundSubtractorKNN::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(getDetectShadows, 0, 0),
Object_Method(getDist2Threshold, 0, 0),
Object_Method(getHistory, 0, 0),
Object_Method(getNSamples, 0, 0),
Object_Method(getShadowThreshold, 0, 0),
Object_Method(getShadowValue, 0, 0),
Object_Method(getkNNSamples, 0, 0),
Object_Method(setDetectShadows, 1, 1),
Object_Method(setDist2Threshold, 1, 1),
Object_Method(setHistory, 1, 1),
Object_Method(setNSamples, 1, 1),
Object_Method(setShadowThreshold, 1, 1),
Object_Method(setShadowValue, 1, 1),
Object_Method(setkNNSamples, 1, 1),
};
int BackgroundSubtractorKNN::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* BackgroundSubtractorMOG2::sPrototype = nullptr;
ObjectMember BackgroundSubtractorMOG2::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(apply, 2, 3),
Object_Method(getBackgroundRatio, 0, 0),
Object_Method(getComplexityReductionThreshold, 0, 0),
Object_Method(getDetectShadows, 0, 0),
Object_Method(getHistory, 0, 0),
Object_Method(getNMixtures, 0, 0),
Object_Method(getShadowThreshold, 0, 0),
Object_Method(getShadowValue, 0, 0),
Object_Method(getVarInit, 0, 0),
Object_Method(getVarMax, 0, 0),
Object_Method(getVarMin, 0, 0),
Object_Method(getVarThreshold, 0, 0),
Object_Method(getVarThresholdGen, 0, 0),
Object_Method(setBackgroundRatio, 1, 1),
Object_Method(setComplexityReductionThreshold, 1, 1),
Object_Method(setDetectShadows, 1, 1),
Object_Method(setHistory, 1, 1),
Object_Method(setNMixtures, 1, 1),
Object_Method(setShadowThreshold, 1, 1),
Object_Method(setShadowValue, 1, 1),
Object_Method(setVarInit, 1, 1),
Object_Method(setVarMax, 1, 1),
Object_Method(setVarMin, 1, 1),
Object_Method(setVarThreshold, 1, 1),
Object_Method(setVarThresholdGen, 1, 1),
};
int BackgroundSubtractorMOG2::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* BaseCascadeClassifier::sPrototype = nullptr;
ObjectMember BaseCascadeClassifier::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
};
int BaseCascadeClassifier::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* CLAHE::sPrototype = nullptr;
ObjectMember CLAHE::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(apply, 2, 2),
Object_Method(collectGarbage, 0, 0),
Object_Method(getClipLimit, 0, 0),
Object_Method(getTilesGridSize, 0, 0),
Object_Method(setClipLimit, 1, 1),
Object_Method(setTilesGridSize, 1, 1),
};
int CLAHE::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* CalibrateCRF::sPrototype = nullptr;
ObjectMember CalibrateCRF::sMember[] = {
Object_Method(process, 3, 3),
};
int CalibrateCRF::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* CalibrateDebevec::sPrototype = nullptr;
ObjectMember CalibrateDebevec::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(getLambda, 0, 0),
Object_Method(getRandom, 0, 0),
Object_Method(getSamples, 0, 0),
Object_Method(setLambda, 1, 1),
Object_Method(setRandom, 1, 1),
Object_Method(setSamples, 1, 1),
};
int CalibrateDebevec::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* CalibrateRobertson::sPrototype = nullptr;
ObjectMember CalibrateRobertson::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(getMaxIter, 0, 0),
Object_Method(getRadiance, 0, 0),
Object_Method(getThreshold, 0, 0),
Object_Method(setMaxIter, 1, 1),
Object_Method(setThreshold, 1, 1),
};
int CalibrateRobertson::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* CascadeClassifier::sPrototype = nullptr;
ObjectMember CascadeClassifier::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(convert, 2, 2),
Object_Method(detectMultiScale, 2, 10),
Object_Method(empty, 0, 0),
Object_Method(getFeatureType, 0, 0),
Object_Method(getOriginalWindowSize, 0, 0),
Object_Method(isOldFormatCascade, 0, 0),
Object_Method(load, 1, 1),
Object_Method(read, 1, 1),
};
int CascadeClassifier::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* DISOpticalFlow::sPrototype = nullptr;
ObjectMember DISOpticalFlow::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(getFinestScale, 0, 0),
Object_Method(getGradientDescentIterations, 0, 0),
Object_Method(getPatchSize, 0, 0),
Object_Method(getPatchStride, 0, 0),
Object_Method(getUseMeanNormalization, 0, 0),
Object_Method(getUseSpatialPropagation, 0, 0),
Object_Method(getVariationalRefinementAlpha, 0, 0),
Object_Method(getVariationalRefinementDelta, 0, 0),
Object_Method(getVariationalRefinementGamma, 0, 0),
Object_Method(getVariationalRefinementIterations, 0, 0),
Object_Method(setFinestScale, 1, 1),
Object_Method(setGradientDescentIterations, 1, 1),
Object_Method(setPatchSize, 1, 1),
Object_Method(setPatchStride, 1, 1),
Object_Method(setUseMeanNormalization, 1, 1),
Object_Method(setUseSpatialPropagation, 1, 1),
Object_Method(setVariationalRefinementAlpha, 1, 1),
Object_Method(setVariationalRefinementDelta, 1, 1),
Object_Method(setVariationalRefinementGamma, 1, 1),
Object_Method(setVariationalRefinementIterations, 1, 1),
};
int DISOpticalFlow::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* DMatch::sPrototype = nullptr;
ObjectMember DMatch::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
};
int DMatch::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* DenseOpticalFlow::sPrototype = nullptr;
ObjectMember DenseOpticalFlow::sMember[] = {
Object_Method(calc, 3, 3),
Object_Method(collectGarbage, 0, 0),
};
int DenseOpticalFlow::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* DescriptorMatcher::sPrototype = nullptr;
ObjectMember DescriptorMatcher::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(add, 1, 1),
Object_Method(clear, 0, 0),
Object_Method(clone, 0, 1),
Object_Method(empty, 0, 0),
Object_Method(getTrainDescriptors, 0, 0),
Object_Method(isMaskSupported, 0, 0),
Object_Method(knnMatch, 3, 6),
Object_Method(match, 2, 4),
Object_Method(radiusMatch, 3, 6),
Object_Method(read, 1, 1),
Object_Method(train, 0, 0),
Object_Method(write, 1, 2),
};
int DescriptorMatcher::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* FaceDetectorYN::sPrototype = nullptr;
ObjectMember FaceDetectorYN::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(detect, 2, 2),
Object_Method(getInputSize, 0, 0),
Object_Method(getNMSThreshold, 0, 0),
Object_Method(getScoreThreshold, 0, 0),
Object_Method(getTopK, 0, 0),
Object_Method(setInputSize, 1, 1),
Object_Method(setNMSThreshold, 1, 1),
Object_Method(setScoreThreshold, 1, 1),
Object_Method(setTopK, 1, 1),
};
int FaceDetectorYN::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* FaceRecognizerSF::sPrototype = nullptr;
ObjectMember FaceRecognizerSF::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(alignCrop, 3, 3),
Object_Method(feature, 2, 2),
Object_Method(match, 2, 3),
};
int FaceRecognizerSF::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* FarnebackOpticalFlow::sPrototype = nullptr;
ObjectMember FarnebackOpticalFlow::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(getFastPyramids, 0, 0),
Object_Method(getFlags, 0, 0),
Object_Method(getNumIters, 0, 0),
Object_Method(getNumLevels, 0, 0),
Object_Method(getPolyN, 0, 0),
Object_Method(getPolySigma, 0, 0),
Object_Method(getPyrScale, 0, 0),
Object_Method(getWinSize, 0, 0),
Object_Method(setFastPyramids, 1, 1),
Object_Method(setFlags, 1, 1),
Object_Method(setNumIters, 1, 1),
Object_Method(setNumLevels, 1, 1),
Object_Method(setPolyN, 1, 1),
Object_Method(setPolySigma, 1, 1),
Object_Method(setPyrScale, 1, 1),
Object_Method(setWinSize, 1, 1),
};
int FarnebackOpticalFlow::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* FastFeatureDetector::sPrototype = nullptr;
ObjectMember FastFeatureDetector::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(getDefaultName, 0, 0),
Object_Method(getNonmaxSuppression, 0, 0),
Object_Method(getThreshold, 0, 0),
Object_Method(getType, 0, 0),
Object_Method(setNonmaxSuppression, 1, 1),
Object_Method(setThreshold, 1, 1),
Object_Method(setType, 1, 1),
};
int FastFeatureDetector::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* Feature2D::sPrototype = nullptr;
ObjectMember Feature2D::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(compute, 3, 3),
Object_Method(defaultNorm, 0, 0),
Object_Method(descriptorSize, 0, 0),
Object_Method(descriptorType, 0, 0),
Object_Method(detect, 2, 3),
Object_Method(detectAndCompute, 4, 5),
Object_Method(empty, 0, 0),
Object_Method(getDefaultName, 0, 0),
Object_Method(read, 1, 1),
Object_Method(write, 1, 2),
};
int Feature2D::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* FileNode::sPrototype = nullptr;
ObjectMember FileNode::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(empty, 0, 0),
Object_Method(isInt, 0, 0),
Object_Method(isMap, 0, 0),
Object_Method(isNamed, 0, 0),
Object_Method(isNone, 0, 0),
Object_Method(isReal, 0, 0),
Object_Method(isSeq, 0, 0),
Object_Method(isString, 0, 0),
Object_Method(keys, 0, 0),
Object_Method(mat, 0, 0),
Object_Method(name, 0, 0),
Object_Property_get(__Item, 1, 1),
Object_Method(rawSize, 0, 0),
Object_Method(real, 0, 0),
Object_Method(size, 0, 0),
Object_Method(string, 0, 0),
Object_Method(type, 0, 0),
};
int FileNode::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* FileStorage::sPrototype = nullptr;
ObjectMember FileStorage::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(endWriteStruct, 0, 0),
Object_Method(getFirstTopLevelNode, 0, 0),
Object_Method(getFormat, 0, 0),
Object_Method(isOpened, 0, 0),
Object_Method(open, 2, 3),
Object_Property_get(__Item, 1, 1),
Object_Method(release, 0, 0),
Object_Method(releaseAndGetString, 0, 0),
Object_Method(root, 0, 1),
Object_Method(startWriteStruct, 2, 3),
Object_Method(write, 2, 2),
Object_Method(writeComment, 1, 2),
};
int FileStorage::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* FlannBasedMatcher::sPrototype = nullptr;
ObjectMember FlannBasedMatcher::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
};
int FlannBasedMatcher::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* GFTTDetector::sPrototype = nullptr;
ObjectMember GFTTDetector::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(getBlockSize, 0, 0),
Object_Method(getDefaultName, 0, 0),
Object_Method(getHarrisDetector, 0, 0),
Object_Method(getK, 0, 0),
Object_Method(getMaxFeatures, 0, 0),
Object_Method(getMinDistance, 0, 0),
Object_Method(getQualityLevel, 0, 0),
Object_Method(setBlockSize, 1, 1),
Object_Method(setHarrisDetector, 1, 1),
Object_Method(setK, 1, 1),
Object_Method(setMaxFeatures, 1, 1),
Object_Method(setMinDistance, 1, 1),
Object_Method(setQualityLevel, 1, 1),
};
int GFTTDetector::sMemberCount = _countof(sMember);

#ifdef HAS_GAPI
thread_local IAhkApi::Prototype* GFrame::sPrototype = nullptr;
ObjectMember GFrame::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
};
int GFrame::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* GMat::sPrototype = nullptr;
ObjectMember GMat::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
};
int GMat::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* GScalar::sPrototype = nullptr;
ObjectMember GScalar::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
};
int GScalar::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* GStreamingCompiled::sPrototype = nullptr;
ObjectMember GStreamingCompiled::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(pull, 0, 0),
Object_Method(running, 0, 0),
Object_Method(setSource, 1, 1),
Object_Method(start, 0, 0),
Object_Method(stop, 0, 0),
};
int GStreamingCompiled::sMemberCount = _countof(sMember);
#endif

thread_local IAhkApi::Prototype* GeneralizedHough::sPrototype = nullptr;
ObjectMember GeneralizedHough::sMember[] = {
Object_Method(detect, 2, 5),
Object_Method(getCannyHighThresh, 0, 0),
Object_Method(getCannyLowThresh, 0, 0),
Object_Method(getDp, 0, 0),
Object_Method(getMaxBufferSize, 0, 0),
Object_Method(getMinDist, 0, 0),
Object_Method(setCannyHighThresh, 1, 1),
Object_Method(setCannyLowThresh, 1, 1),
Object_Method(setDp, 1, 1),
Object_Method(setMaxBufferSize, 1, 1),
Object_Method(setMinDist, 1, 1),
Object_Method(setTemplate, 1, 4),
};
int GeneralizedHough::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* GeneralizedHoughBallard::sPrototype = nullptr;
ObjectMember GeneralizedHoughBallard::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(getLevels, 0, 0),
Object_Method(getVotesThreshold, 0, 0),
Object_Method(setLevels, 1, 1),
Object_Method(setVotesThreshold, 1, 1),
};
int GeneralizedHoughBallard::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* GeneralizedHoughGuil::sPrototype = nullptr;
ObjectMember GeneralizedHoughGuil::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(getAngleEpsilon, 0, 0),
Object_Method(getAngleStep, 0, 0),
Object_Method(getAngleThresh, 0, 0),
Object_Method(getLevels, 0, 0),
Object_Method(getMaxAngle, 0, 0),
Object_Method(getMaxScale, 0, 0),
Object_Method(getMinAngle, 0, 0),
Object_Method(getMinScale, 0, 0),
Object_Method(getPosThresh, 0, 0),
Object_Method(getScaleStep, 0, 0),
Object_Method(getScaleThresh, 0, 0),
Object_Method(getXi, 0, 0),
Object_Method(setAngleEpsilon, 1, 1),
Object_Method(setAngleStep, 1, 1),
Object_Method(setAngleThresh, 1, 1),
Object_Method(setLevels, 1, 1),
Object_Method(setMaxAngle, 1, 1),
Object_Method(setMaxScale, 1, 1),
Object_Method(setMinAngle, 1, 1),
Object_Method(setMinScale, 1, 1),
Object_Method(setPosThresh, 1, 1),
Object_Method(setScaleStep, 1, 1),
Object_Method(setScaleThresh, 1, 1),
Object_Method(setXi, 1, 1),
};
int GeneralizedHoughGuil::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* KAZE::sPrototype = nullptr;
ObjectMember KAZE::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(getDefaultName, 0, 0),
Object_Method(getDiffusivity, 0, 0),
Object_Method(getExtended, 0, 0),
Object_Method(getNOctaveLayers, 0, 0),
Object_Method(getNOctaves, 0, 0),
Object_Method(getThreshold, 0, 0),
Object_Method(getUpright, 0, 0),
Object_Method(setDiffusivity, 1, 1),
Object_Method(setExtended, 1, 1),
Object_Method(setNOctaveLayers, 1, 1),
Object_Method(setNOctaves, 1, 1),
Object_Method(setThreshold, 1, 1),
Object_Method(setUpright, 1, 1),
};
int KAZE::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* KalmanFilter::sPrototype = nullptr;
ObjectMember KalmanFilter::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(correct, 1, 1),
Object_Method(predict, 0, 1),
};
int KalmanFilter::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* KeyPoint::sPrototype = nullptr;
ObjectMember KeyPoint::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(convert, 2, 6),
Object_Method(overlap, 2, 2),
};
int KeyPoint::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* LineSegmentDetector::sPrototype = nullptr;
ObjectMember LineSegmentDetector::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(compareSegments, 3, 4),
Object_Method(detect, 2, 5),
Object_Method(drawSegments, 2, 2),
};
int LineSegmentDetector::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* MSER::sPrototype = nullptr;
ObjectMember MSER::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(detectRegions, 3, 3),
Object_Method(getDefaultName, 0, 0),
Object_Method(getDelta, 0, 0),
Object_Method(getMaxArea, 0, 0),
Object_Method(getMinArea, 0, 0),
Object_Method(getPass2Only, 0, 0),
Object_Method(setDelta, 1, 1),
Object_Method(setMaxArea, 1, 1),
Object_Method(setMinArea, 1, 1),
Object_Method(setPass2Only, 1, 1),
};
int MSER::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* MergeDebevec::sPrototype = nullptr;
ObjectMember MergeDebevec::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(process, 3, 4),
};
int MergeDebevec::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* MergeExposures::sPrototype = nullptr;
ObjectMember MergeExposures::sMember[] = {
Object_Method(process, 4, 4),
};
int MergeExposures::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* MergeMertens::sPrototype = nullptr;
ObjectMember MergeMertens::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(getContrastWeight, 0, 0),
Object_Method(getExposureWeight, 0, 0),
Object_Method(getSaturationWeight, 0, 0),
Object_Method(process, 2, 4),
Object_Method(setContrastWeight, 1, 1),
Object_Method(setExposureWeight, 1, 1),
Object_Method(setSaturationWeight, 1, 1),
};
int MergeMertens::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* MergeRobertson::sPrototype = nullptr;
ObjectMember MergeRobertson::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(process, 3, 4),
};
int MergeRobertson::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* Moments::sPrototype = nullptr;
ObjectMember Moments::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Property_get_set(m00),
Object_Property_get_set(m10),
Object_Property_get_set(m01),
Object_Property_get_set(m20),
Object_Property_get_set(m11),
Object_Property_get_set(m02),
Object_Property_get_set(m30),
Object_Property_get_set(m21),
Object_Property_get_set(m12),
Object_Property_get_set(m03),
Object_Property_get_set(mu20),
Object_Property_get_set(mu11),
Object_Property_get_set(mu02),
Object_Property_get_set(mu30),
Object_Property_get_set(mu21),
Object_Property_get_set(mu12),
Object_Property_get_set(mu03),
Object_Property_get_set(nu20),
Object_Property_get_set(nu11),
Object_Property_get_set(nu02),
Object_Property_get_set(nu30),
Object_Property_get_set(nu21),
Object_Property_get_set(nu12),
Object_Property_get_set(nu03),
};
int Moments::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* ORB::sPrototype = nullptr;
ObjectMember ORB::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(getDefaultName, 0, 0),
Object_Method(getEdgeThreshold, 0, 0),
Object_Method(getFastThreshold, 0, 0),
Object_Method(getFirstLevel, 0, 0),
Object_Method(getMaxFeatures, 0, 0),
Object_Method(getNLevels, 0, 0),
Object_Method(getPatchSize, 0, 0),
Object_Method(getScaleFactor, 0, 0),
Object_Method(getScoreType, 0, 0),
Object_Method(getWTA_K, 0, 0),
Object_Method(setEdgeThreshold, 1, 1),
Object_Method(setFastThreshold, 1, 1),
Object_Method(setFirstLevel, 1, 1),
Object_Method(setMaxFeatures, 1, 1),
Object_Method(setNLevels, 1, 1),
Object_Method(setPatchSize, 1, 1),
Object_Method(setScaleFactor, 1, 1),
Object_Method(setScoreType, 1, 1),
Object_Method(setWTA_K, 1, 1),
};
int ORB::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* PyRotationWarper::sPrototype = nullptr;
ObjectMember PyRotationWarper::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(buildMaps, 5, 5),
Object_Method(getScale, 0, 0),
Object_Method(setScale, 1, 1),
Object_Method(warp, 6, 6),
Object_Method(warpBackward, 7, 7),
Object_Method(warpPoint, 3, 3),
Object_Method(warpPointBackward, 3, 3),
Object_Method(warpRoi, 3, 3),
};
int PyRotationWarper::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* QRCodeDetector::sPrototype = nullptr;
ObjectMember QRCodeDetector::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(decode, 2, 3),
Object_Method(decodeCurved, 2, 3),
Object_Method(decodeMulti, 3, 4),
Object_Method(detect, 2, 2),
Object_Method(detectAndDecode, 1, 3),
Object_Method(detectAndDecodeCurved, 1, 3),
Object_Method(detectAndDecodeMulti, 2, 4),
Object_Method(detectMulti, 2, 2),
Object_Method(setEpsX, 1, 1),
Object_Method(setEpsY, 1, 1),
};
int QRCodeDetector::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* QRCodeEncoder::sPrototype = nullptr;
ObjectMember QRCodeEncoder::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(encode, 2, 2),
Object_Method(encodeStructuredAppend, 2, 2),
};
int QRCodeEncoder::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* SIFT::sPrototype = nullptr;
ObjectMember SIFT::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(getDefaultName, 0, 0),
};
int SIFT::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* SimpleBlobDetector::sPrototype = nullptr;
ObjectMember SimpleBlobDetector::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(getDefaultName, 0, 0),
};
int SimpleBlobDetector::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* SparseOpticalFlow::sPrototype = nullptr;
ObjectMember SparseOpticalFlow::sMember[] = {
Object_Method(calc, 5, 6),
};
int SparseOpticalFlow::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* SparsePyrLKOpticalFlow::sPrototype = nullptr;
ObjectMember SparsePyrLKOpticalFlow::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(getFlags, 0, 0),
Object_Method(getMaxLevel, 0, 0),
Object_Method(getMinEigThreshold, 0, 0),
Object_Method(getTermCriteria, 0, 0),
Object_Method(getWinSize, 0, 0),
Object_Method(setFlags, 1, 1),
Object_Method(setMaxLevel, 1, 1),
Object_Method(setMinEigThreshold, 1, 1),
Object_Method(setTermCriteria, 1, 1),
Object_Method(setWinSize, 1, 1),
};
int SparsePyrLKOpticalFlow::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* StereoBM::sPrototype = nullptr;
ObjectMember StereoBM::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(getPreFilterCap, 0, 0),
Object_Method(getPreFilterSize, 0, 0),
Object_Method(getPreFilterType, 0, 0),
Object_Method(getROI1, 0, 0),
Object_Method(getROI2, 0, 0),
Object_Method(getSmallerBlockSize, 0, 0),
Object_Method(getTextureThreshold, 0, 0),
Object_Method(getUniquenessRatio, 0, 0),
Object_Method(setPreFilterCap, 1, 1),
Object_Method(setPreFilterSize, 1, 1),
Object_Method(setPreFilterType, 1, 1),
Object_Method(setROI1, 1, 1),
Object_Method(setROI2, 1, 1),
Object_Method(setSmallerBlockSize, 1, 1),
Object_Method(setTextureThreshold, 1, 1),
Object_Method(setUniquenessRatio, 1, 1),
};
int StereoBM::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* StereoMatcher::sPrototype = nullptr;
ObjectMember StereoMatcher::sMember[] = {
Object_Method(compute, 3, 3),
Object_Method(getBlockSize, 0, 0),
Object_Method(getDisp12MaxDiff, 0, 0),
Object_Method(getMinDisparity, 0, 0),
Object_Method(getNumDisparities, 0, 0),
Object_Method(getSpeckleRange, 0, 0),
Object_Method(getSpeckleWindowSize, 0, 0),
Object_Method(setBlockSize, 1, 1),
Object_Method(setDisp12MaxDiff, 1, 1),
Object_Method(setMinDisparity, 1, 1),
Object_Method(setNumDisparities, 1, 1),
Object_Method(setSpeckleRange, 1, 1),
Object_Method(setSpeckleWindowSize, 1, 1),
};
int StereoMatcher::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* StereoSGBM::sPrototype = nullptr;
ObjectMember StereoSGBM::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(getMode, 0, 0),
Object_Method(getP1, 0, 0),
Object_Method(getP2, 0, 0),
Object_Method(getPreFilterCap, 0, 0),
Object_Method(getUniquenessRatio, 0, 0),
Object_Method(setMode, 1, 1),
Object_Method(setP1, 1, 1),
Object_Method(setP2, 1, 1),
Object_Method(setPreFilterCap, 1, 1),
Object_Method(setUniquenessRatio, 1, 1),
};
int StereoSGBM::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* Stitcher::sPrototype = nullptr;
ObjectMember Stitcher::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(composePanorama, 1, 2),
Object_Method(compositingResol, 0, 0),
Object_Method(estimateTransform, 1, 2),
Object_Method(interpolationFlags, 0, 0),
Object_Method(panoConfidenceThresh, 0, 0),
Object_Method(registrationResol, 0, 0),
Object_Method(seamEstimationResol, 0, 0),
Object_Method(setCompositingResol, 1, 1),
Object_Method(setInterpolationFlags, 1, 1),
Object_Method(setPanoConfidenceThresh, 1, 1),
Object_Method(setRegistrationResol, 1, 1),
Object_Method(setSeamEstimationResol, 1, 1),
Object_Method(setWaveCorrection, 1, 1),
Object_Method(stitch, 2, 3),
Object_Method(waveCorrection, 0, 0),
Object_Method(workScale, 0, 0),
};
int Stitcher::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* Subdiv2D::sPrototype = nullptr;
ObjectMember Subdiv2D::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(edgeDst, 1, 2),
Object_Method(edgeOrg, 1, 2),
Object_Method(findNearest, 1, 2),
Object_Method(getEdge, 2, 2),
Object_Method(getEdgeList, 1, 1),
Object_Method(getLeadingEdgeList, 1, 1),
Object_Method(getTriangleList, 1, 1),
Object_Method(getVertex, 1, 2),
Object_Method(getVoronoiFacetList, 3, 3),
Object_Method(initDelaunay, 1, 1),
Object_Method(insert, 1, 1),
Object_Method(locate, 3, 3),
Object_Method(nextEdge, 1, 1),
Object_Method(rotateEdge, 2, 2),
Object_Method(symEdge, 1, 1),
};
int Subdiv2D::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* TickMeter::sPrototype = nullptr;
ObjectMember TickMeter::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(getAvgTimeMilli, 0, 0),
Object_Method(getAvgTimeSec, 0, 0),
Object_Method(getCounter, 0, 0),
Object_Method(getFPS, 0, 0),
Object_Method(getTimeMicro, 0, 0),
Object_Method(getTimeMilli, 0, 0),
Object_Method(getTimeSec, 0, 0),
Object_Method(getTimeTicks, 0, 0),
Object_Method(reset, 0, 0),
Object_Method(start, 0, 0),
Object_Method(stop, 0, 0),
};
int TickMeter::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* Tonemap::sPrototype = nullptr;
ObjectMember Tonemap::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(getGamma, 0, 0),
Object_Method(process, 2, 2),
Object_Method(setGamma, 1, 1),
};
int Tonemap::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* TonemapDrago::sPrototype = nullptr;
ObjectMember TonemapDrago::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(getBias, 0, 0),
Object_Method(getSaturation, 0, 0),
Object_Method(setBias, 1, 1),
Object_Method(setSaturation, 1, 1),
};
int TonemapDrago::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* TonemapMantiuk::sPrototype = nullptr;
ObjectMember TonemapMantiuk::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(getSaturation, 0, 0),
Object_Method(getScale, 0, 0),
Object_Method(setSaturation, 1, 1),
Object_Method(setScale, 1, 1),
};
int TonemapMantiuk::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* TonemapReinhard::sPrototype = nullptr;
ObjectMember TonemapReinhard::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(getColorAdaptation, 0, 0),
Object_Method(getIntensity, 0, 0),
Object_Method(getLightAdaptation, 0, 0),
Object_Method(setColorAdaptation, 1, 1),
Object_Method(setIntensity, 1, 1),
Object_Method(setLightAdaptation, 1, 1),
};
int TonemapReinhard::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* Tracker::sPrototype = nullptr;
ObjectMember Tracker::sMember[] = {
Object_Method(init, 2, 2),
Object_Method(update, 2, 2),
};
int Tracker::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* TrackerDaSiamRPN::sPrototype = nullptr;
ObjectMember TrackerDaSiamRPN::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(getTrackingScore, 0, 0),
};
int TrackerDaSiamRPN::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* TrackerGOTURN::sPrototype = nullptr;
ObjectMember TrackerGOTURN::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
};
int TrackerGOTURN::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* TrackerMIL::sPrototype = nullptr;
ObjectMember TrackerMIL::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
};
int TrackerMIL::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* VariationalRefinement::sPrototype = nullptr;
ObjectMember VariationalRefinement::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(calcUV, 4, 4),
Object_Method(getAlpha, 0, 0),
Object_Method(getDelta, 0, 0),
Object_Method(getFixedPointIterations, 0, 0),
Object_Method(getGamma, 0, 0),
Object_Method(getOmega, 0, 0),
Object_Method(getSorIterations, 0, 0),
Object_Method(setAlpha, 1, 1),
Object_Method(setDelta, 1, 1),
Object_Method(setFixedPointIterations, 1, 1),
Object_Method(setGamma, 1, 1),
Object_Method(setOmega, 1, 1),
Object_Method(setSorIterations, 1, 1),
};
int VariationalRefinement::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* VideoCapture::sPrototype = nullptr;
ObjectMember VideoCapture::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(get, 1, 1),
Object_Method(getBackendName, 0, 0),
Object_Method(getExceptionMode, 0, 0),
Object_Method(grab, 0, 0),
Object_Method(isOpened, 0, 0),
Object_Method(open, 1, 3),
Object_Method(read, 1, 1),
Object_Method(release, 0, 0),
Object_Method(retrieve, 1, 2),
Object_Method(set, 2, 2),
Object_Method(setExceptionMode, 1, 1),
};
int VideoCapture::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* VideoWriter::sPrototype = nullptr;
ObjectMember VideoWriter::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(fourcc, 4, 4),
Object_Method(get, 1, 1),
Object_Method(getBackendName, 0, 0),
Object_Method(isOpened, 0, 0),
Object_Method(open, 4, 6),
Object_Method(release, 0, 0),
Object_Method(set, 2, 2),
Object_Method(write, 1, 1),
};
int VideoWriter::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* WarperCreator::sPrototype = nullptr;
ObjectMember WarperCreator::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
};
int WarperCreator::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* cuda_BufferPool::sPrototype = nullptr;
ObjectMember cuda_BufferPool::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(getAllocator, 0, 0),
Object_Method(getBuffer, 2, 3),
};
int cuda_BufferPool::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* cuda_DeviceInfo::sPrototype = nullptr;
ObjectMember cuda_DeviceInfo::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(ECCEnabled, 0, 0),
Object_Method(asyncEngineCount, 0, 0),
Object_Method(canMapHostMemory, 0, 0),
Object_Method(clockRate, 0, 0),
Object_Method(computeMode, 0, 0),
Object_Method(concurrentKernels, 0, 0),
Object_Method(deviceID, 0, 0),
Object_Method(freeMemory, 0, 0),
Object_Method(integrated, 0, 0),
Object_Method(isCompatible, 0, 0),
Object_Method(kernelExecTimeoutEnabled, 0, 0),
Object_Method(l2CacheSize, 0, 0),
Object_Method(majorVersion, 0, 0),
Object_Method(maxGridSize, 0, 0),
Object_Method(maxSurface1D, 0, 0),
Object_Method(maxSurface1DLayered, 0, 0),
Object_Method(maxSurface2D, 0, 0),
Object_Method(maxSurface2DLayered, 0, 0),
Object_Method(maxSurface3D, 0, 0),
Object_Method(maxSurfaceCubemap, 0, 0),
Object_Method(maxSurfaceCubemapLayered, 0, 0),
Object_Method(maxTexture1D, 0, 0),
Object_Method(maxTexture1DLayered, 0, 0),
Object_Method(maxTexture1DLinear, 0, 0),
Object_Method(maxTexture1DMipmap, 0, 0),
Object_Method(maxTexture2D, 0, 0),
Object_Method(maxTexture2DGather, 0, 0),
Object_Method(maxTexture2DLayered, 0, 0),
Object_Method(maxTexture2DLinear, 0, 0),
Object_Method(maxTexture2DMipmap, 0, 0),
Object_Method(maxTexture3D, 0, 0),
Object_Method(maxTextureCubemap, 0, 0),
Object_Method(maxTextureCubemapLayered, 0, 0),
Object_Method(maxThreadsDim, 0, 0),
Object_Method(maxThreadsPerBlock, 0, 0),
Object_Method(maxThreadsPerMultiProcessor, 0, 0),
Object_Method(memPitch, 0, 0),
Object_Method(memoryBusWidth, 0, 0),
Object_Method(memoryClockRate, 0, 0),
Object_Method(minorVersion, 0, 0),
Object_Method(multiProcessorCount, 0, 0),
Object_Method(pciBusID, 0, 0),
Object_Method(pciDeviceID, 0, 0),
Object_Method(pciDomainID, 0, 0),
Object_Method(queryMemory, 2, 2),
Object_Method(regsPerBlock, 0, 0),
Object_Method(sharedMemPerBlock, 0, 0),
Object_Method(surfaceAlignment, 0, 0),
Object_Method(tccDriver, 0, 0),
Object_Method(textureAlignment, 0, 0),
Object_Method(texturePitchAlignment, 0, 0),
Object_Method(totalConstMem, 0, 0),
Object_Method(totalGlobalMem, 0, 0),
Object_Method(totalMemory, 0, 0),
Object_Method(unifiedAddressing, 0, 0),
Object_Method(warpSize, 0, 0),
};
int cuda_DeviceInfo::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* cuda_Event::sPrototype = nullptr;
ObjectMember cuda_Event::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(elapsedTime, 2, 2),
Object_Method(queryIfComplete, 0, 0),
Object_Method(record, 0, 1),
Object_Method(waitForCompletion, 0, 0),
};
int cuda_Event::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* cuda_GpuMat::sPrototype = nullptr;
ObjectMember cuda_GpuMat::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(adjustROI, 4, 4),
Object_Method(assignTo, 1, 2),
Object_Property_get(channels),
Object_Method(clone, 0, 0),
Object_Method(col, 1, 1),
Object_Method(colRange, 1, 2),
Object_Method(convertTo, 2, 5),
Object_Method(copyTo, 1, 3),
Object_Method(create, 2, 3),
Object_Method(cudaPtr, 0, 0),
Object_Method(defaultAllocator, 0, 0),
Object_Property_get(depth),
Object_Method(download, 1, 2),
Object_Property_get(elemSize),
Object_Property_get(elemSize1),
Object_Property_get(empty),
Object_Property_get(isContinuous),
Object_Method(locateROI, 2, 2),
Object_Method(reshape, 1, 2),
Object_Method(row, 1, 1),
Object_Method(rowRange, 1, 2),
Object_Method(setDefaultAllocator, 1, 1),
Object_Method(setTo, 1, 3),
Object_Property_get(size),
Object_Property_get(step1),
Object_Method(swap, 1, 1),
Object_Property_get(type),
Object_Method(updateContinuityFlag, 0, 0),
Object_Method(upload, 1, 2),
};
int cuda_GpuMat::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* cuda_GpuMat_Allocator::sPrototype = nullptr;
ObjectMember cuda_GpuMat_Allocator::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
};
int cuda_GpuMat_Allocator::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* cuda_GpuMatND::sPrototype = nullptr;
ObjectMember cuda_GpuMatND::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
};
int cuda_GpuMatND::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* cuda_HostMem::sPrototype = nullptr;
ObjectMember cuda_HostMem::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Property_get(channels),
Object_Method(clone, 0, 0),
Object_Method(create, 3, 3),
Object_Method(createMatHeader, 0, 0),
Object_Property_get(depth),
Object_Property_get(elemSize),
Object_Property_get(elemSize1),
Object_Property_get(empty),
Object_Property_get(isContinuous),
Object_Method(reshape, 1, 2),
Object_Property_get(size),
Object_Property_get(step1),
Object_Method(swap, 1, 1),
Object_Property_get(type),
};
int cuda_HostMem::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* cuda_Stream::sPrototype = nullptr;
ObjectMember cuda_Stream::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(Null, 0, 0),
Object_Method(cudaPtr, 0, 0),
Object_Method(queryIfComplete, 0, 0),
Object_Method(waitEvent, 1, 1),
Object_Method(waitForCompletion, 0, 0),
};
int cuda_Stream::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* cuda_TargetArchs::sPrototype = nullptr;
ObjectMember cuda_TargetArchs::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(has, 2, 2),
Object_Method(hasBin, 2, 2),
Object_Method(hasEqualOrGreater, 2, 2),
Object_Method(hasEqualOrGreaterBin, 2, 2),
Object_Method(hasEqualOrGreaterPtx, 2, 2),
Object_Method(hasEqualOrLessPtx, 2, 2),
Object_Method(hasPtx, 2, 2),
};
int cuda_TargetArchs::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* detail_AffineBasedEstimator::sPrototype = nullptr;
ObjectMember detail_AffineBasedEstimator::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
};
int detail_AffineBasedEstimator::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* detail_AffineBestOf2NearestMatcher::sPrototype = nullptr;
ObjectMember detail_AffineBestOf2NearestMatcher::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
};
int detail_AffineBestOf2NearestMatcher::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* detail_BestOf2NearestMatcher::sPrototype = nullptr;
ObjectMember detail_BestOf2NearestMatcher::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(collectGarbage, 0, 0),
};
int detail_BestOf2NearestMatcher::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* detail_BestOf2NearestRangeMatcher::sPrototype = nullptr;
ObjectMember detail_BestOf2NearestRangeMatcher::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
};
int detail_BestOf2NearestRangeMatcher::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* detail_Blender::sPrototype = nullptr;
ObjectMember detail_Blender::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(blend, 2, 2),
Object_Method(feed, 3, 3),
Object_Method(prepare, 1, 2),
};
int detail_Blender::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* detail_BlocksChannelsCompensator::sPrototype = nullptr;
ObjectMember detail_BlocksChannelsCompensator::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
};
int detail_BlocksChannelsCompensator::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* detail_BlocksCompensator::sPrototype = nullptr;
ObjectMember detail_BlocksCompensator::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(apply, 4, 4),
Object_Method(getBlockSize, 0, 0),
Object_Method(getMatGains, 1, 1),
Object_Method(getNrFeeds, 0, 0),
Object_Method(getNrGainsFilteringIterations, 0, 0),
Object_Method(getSimilarityThreshold, 0, 0),
Object_Method(setBlockSize, 1, 2),
Object_Method(setMatGains, 1, 1),
Object_Method(setNrFeeds, 1, 1),
Object_Method(setNrGainsFilteringIterations, 1, 1),
Object_Method(setSimilarityThreshold, 1, 1),
};
int detail_BlocksCompensator::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* detail_BlocksGainCompensator::sPrototype = nullptr;
ObjectMember detail_BlocksGainCompensator::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(apply, 4, 4),
Object_Method(getMatGains, 1, 1),
Object_Method(setMatGains, 1, 1),
};
int detail_BlocksGainCompensator::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* detail_BundleAdjusterAffine::sPrototype = nullptr;
ObjectMember detail_BundleAdjusterAffine::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
};
int detail_BundleAdjusterAffine::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* detail_BundleAdjusterAffinePartial::sPrototype = nullptr;
ObjectMember detail_BundleAdjusterAffinePartial::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
};
int detail_BundleAdjusterAffinePartial::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* detail_BundleAdjusterBase::sPrototype = nullptr;
ObjectMember detail_BundleAdjusterBase::sMember[] = {
Object_Method(confThresh, 0, 0),
Object_Method(refinementMask, 0, 0),
Object_Method(setConfThresh, 1, 1),
Object_Method(setRefinementMask, 1, 1),
Object_Method(setTermCriteria, 1, 1),
Object_Method(termCriteria, 0, 0),
};
int detail_BundleAdjusterBase::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* detail_BundleAdjusterRay::sPrototype = nullptr;
ObjectMember detail_BundleAdjusterRay::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
};
int detail_BundleAdjusterRay::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* detail_BundleAdjusterReproj::sPrototype = nullptr;
ObjectMember detail_BundleAdjusterReproj::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
};
int detail_BundleAdjusterReproj::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* detail_ChannelsCompensator::sPrototype = nullptr;
ObjectMember detail_ChannelsCompensator::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(apply, 4, 4),
Object_Method(getMatGains, 1, 1),
Object_Method(getNrFeeds, 0, 0),
Object_Method(getSimilarityThreshold, 0, 0),
Object_Method(setMatGains, 1, 1),
Object_Method(setNrFeeds, 1, 1),
Object_Method(setSimilarityThreshold, 1, 1),
};
int detail_ChannelsCompensator::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* detail_DpSeamFinder::sPrototype = nullptr;
ObjectMember detail_DpSeamFinder::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(setCostFunction, 1, 1),
};
int detail_DpSeamFinder::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* detail_Estimator::sPrototype = nullptr;
ObjectMember detail_Estimator::sMember[] = {
Object_Method(Call, 3, 3),
};
int detail_Estimator::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* detail_ExposureCompensator::sPrototype = nullptr;
ObjectMember detail_ExposureCompensator::sMember[] = {
Object_Method(apply, 4, 4),
Object_Method(createDefault, 1, 1),
Object_Method(feed, 3, 3),
Object_Method(getMatGains, 1, 1),
Object_Method(getUpdateGain, 0, 0),
Object_Method(setMatGains, 1, 1),
Object_Method(setUpdateGain, 1, 1),
};
int detail_ExposureCompensator::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* detail_FeatherBlender::sPrototype = nullptr;
ObjectMember detail_FeatherBlender::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(blend, 2, 2),
Object_Method(createWeightMaps, 3, 3),
Object_Method(feed, 3, 3),
Object_Method(prepare, 1, 1),
Object_Method(setSharpness, 1, 1),
Object_Method(sharpness, 0, 0),
};
int detail_FeatherBlender::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* detail_FeaturesMatcher::sPrototype = nullptr;
ObjectMember detail_FeaturesMatcher::sMember[] = {
Object_Method(collectGarbage, 0, 0),
Object_Method(isThreadSafe, 0, 0),
Object_Method(Call, 2, 3),
};
int detail_FeaturesMatcher::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* detail_GainCompensator::sPrototype = nullptr;
ObjectMember detail_GainCompensator::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(apply, 4, 4),
Object_Method(getMatGains, 1, 1),
Object_Method(getNrFeeds, 0, 0),
Object_Method(getSimilarityThreshold, 0, 0),
Object_Method(setMatGains, 1, 1),
Object_Method(setNrFeeds, 1, 1),
Object_Method(setSimilarityThreshold, 1, 1),
};
int detail_GainCompensator::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* detail_GraphCutSeamFinder::sPrototype = nullptr;
ObjectMember detail_GraphCutSeamFinder::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(find, 3, 3),
};
int detail_GraphCutSeamFinder::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* detail_HomographyBasedEstimator::sPrototype = nullptr;
ObjectMember detail_HomographyBasedEstimator::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
};
int detail_HomographyBasedEstimator::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* detail_MultiBandBlender::sPrototype = nullptr;
ObjectMember detail_MultiBandBlender::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(blend, 2, 2),
Object_Method(feed, 3, 3),
Object_Method(numBands, 0, 0),
Object_Method(prepare, 1, 1),
Object_Method(setNumBands, 1, 1),
};
int detail_MultiBandBlender::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* detail_NoBundleAdjuster::sPrototype = nullptr;
ObjectMember detail_NoBundleAdjuster::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
};
int detail_NoBundleAdjuster::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* detail_NoExposureCompensator::sPrototype = nullptr;
ObjectMember detail_NoExposureCompensator::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(apply, 4, 4),
Object_Method(getMatGains, 1, 1),
Object_Method(setMatGains, 1, 1),
};
int detail_NoExposureCompensator::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* detail_NoSeamFinder::sPrototype = nullptr;
ObjectMember detail_NoSeamFinder::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(find, 3, 3),
};
int detail_NoSeamFinder::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* detail_PairwiseSeamFinder::sPrototype = nullptr;
ObjectMember detail_PairwiseSeamFinder::sMember[] = {
Object_Method(find, 3, 3),
};
int detail_PairwiseSeamFinder::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* detail_SeamFinder::sPrototype = nullptr;
ObjectMember detail_SeamFinder::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(find, 3, 3),
};
int detail_SeamFinder::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* detail_Timelapser::sPrototype = nullptr;
ObjectMember detail_Timelapser::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(getDst, 0, 0),
Object_Method(initialize, 2, 2),
Object_Method(process, 3, 3),
};
int detail_Timelapser::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* detail_TimelapserCrop::sPrototype = nullptr;
ObjectMember detail_TimelapserCrop::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
};
int detail_TimelapserCrop::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* detail_VoronoiSeamFinder::sPrototype = nullptr;
ObjectMember detail_VoronoiSeamFinder::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(find, 3, 3),
};
int detail_VoronoiSeamFinder::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* dnn_ClassificationModel::sPrototype = nullptr;
ObjectMember dnn_ClassificationModel::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(classify, 3, 3),
};
int dnn_ClassificationModel::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* dnn_DetectionModel::sPrototype = nullptr;
ObjectMember dnn_DetectionModel::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(detect, 4, 6),
Object_Method(getNmsAcrossClasses, 0, 0),
Object_Method(setNmsAcrossClasses, 1, 1),
};
int dnn_DetectionModel::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* dnn_KeypointsModel::sPrototype = nullptr;
ObjectMember dnn_KeypointsModel::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(estimate, 1, 2),
};
int dnn_KeypointsModel::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* dnn_Layer::sPrototype = nullptr;
ObjectMember dnn_Layer::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(finalize, 2, 2),
Object_Method(outputNameToIndex, 1, 1),
Object_Method(run, 3, 3),
};
int dnn_Layer::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* dnn_Model::sPrototype = nullptr;
ObjectMember dnn_Model::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(predict, 2, 2),
Object_Method(setInputCrop, 1, 1),
Object_Method(setInputMean, 1, 1),
Object_Method(setInputParams, 0, 5),
Object_Method(setInputScale, 1, 1),
Object_Method(setInputSize, 1, 2),
Object_Method(setInputSwapRB, 1, 1),
Object_Method(setPreferableBackend, 1, 1),
Object_Method(setPreferableTarget, 1, 1),
};
int dnn_Model::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* dnn_Net::sPrototype = nullptr;
ObjectMember dnn_Net::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(connect, 2, 2),
Object_Method(dump, 0, 0),
Object_Method(dumpToFile, 1, 1),
Object_Method(empty, 0, 0),
Object_Method(enableFusion, 1, 1),
Object_Method(forward, 0, 2),
Object_Method(forwardAsync, 0, 1),
Object_Method(getFLOPS, 1, 2),
Object_Method(getInputDetails, 2, 2),
Object_Method(getLayer, 1, 1),
Object_Method(getLayerId, 1, 1),
Object_Method(getLayerNames, 0, 0),
Object_Method(getLayerTypes, 1, 1),
Object_Method(getLayersCount, 1, 1),
Object_Method(getLayersShapes, 4, 4),
Object_Method(getMemoryConsumption, 3, 4),
Object_Method(getOutputDetails, 2, 2),
Object_Method(getParam, 1, 2),
Object_Method(getPerfProfile, 1, 1),
Object_Method(getUnconnectedOutLayers, 0, 0),
Object_Method(getUnconnectedOutLayersNames, 0, 0),
Object_Method(quantize, 3, 3),
Object_Method(readFromModelOptimizer, 2, 2),
Object_Method(setHalideScheduler, 1, 1),
Object_Method(setInput, 1, 4),
Object_Method(setInputShape, 2, 2),
Object_Method(setInputsNames, 1, 1),
Object_Method(setParam, 3, 3),
Object_Method(setPreferableBackend, 1, 1),
Object_Method(setPreferableTarget, 1, 1),
};
int dnn_Net::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* dnn_SegmentationModel::sPrototype = nullptr;
ObjectMember dnn_SegmentationModel::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(segment, 2, 2),
};
int dnn_SegmentationModel::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* dnn_TextDetectionModel::sPrototype = nullptr;
ObjectMember dnn_TextDetectionModel::sMember[] = {
Object_Method(detect, 2, 3),
Object_Method(detectTextRectangles, 2, 3),
};
int dnn_TextDetectionModel::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* dnn_TextDetectionModel_DB::sPrototype = nullptr;
ObjectMember dnn_TextDetectionModel_DB::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(getBinaryThreshold, 0, 0),
Object_Method(getMaxCandidates, 0, 0),
Object_Method(getPolygonThreshold, 0, 0),
Object_Method(getUnclipRatio, 0, 0),
Object_Method(setBinaryThreshold, 1, 1),
Object_Method(setMaxCandidates, 1, 1),
Object_Method(setPolygonThreshold, 1, 1),
Object_Method(setUnclipRatio, 1, 1),
};
int dnn_TextDetectionModel_DB::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* dnn_TextDetectionModel_EAST::sPrototype = nullptr;
ObjectMember dnn_TextDetectionModel_EAST::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(getConfidenceThreshold, 0, 0),
Object_Method(getNMSThreshold, 0, 0),
Object_Method(setConfidenceThreshold, 1, 1),
Object_Method(setNMSThreshold, 1, 1),
};
int dnn_TextDetectionModel_EAST::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* dnn_TextRecognitionModel::sPrototype = nullptr;
ObjectMember dnn_TextRecognitionModel::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(getDecodeType, 0, 0),
Object_Method(getVocabulary, 0, 0),
Object_Method(recognize, 1, 3),
Object_Method(setDecodeOptsCTCPrefixBeamSearch, 1, 2),
Object_Method(setDecodeType, 1, 1),
Object_Method(setVocabulary, 1, 1),
};
int dnn_TextRecognitionModel::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* flann_Index::sPrototype = nullptr;
ObjectMember flann_Index::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(build, 2, 3),
Object_Method(getAlgorithm, 0, 0),
Object_Method(getDistance, 0, 0),
Object_Method(knnSearch, 4, 5),
Object_Method(load, 2, 2),
Object_Method(radiusSearch, 5, 6),
Object_Method(release, 0, 0),
Object_Method(save, 1, 1),
};
int flann_Index::sMemberCount = _countof(sMember);
#ifdef HAS_GAPI
thread_local IAhkApi::Prototype* gapi_GKernelPackage::sPrototype = nullptr;
ObjectMember gapi_GKernelPackage::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
};
int gapi_GKernelPackage::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* gapi_ie_PyParams::sPrototype = nullptr;
ObjectMember gapi_ie_PyParams::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(cfgBatchSize, 1, 1),
Object_Method(cfgNumRequests, 1, 1),
Object_Method(constInput, 2, 3),
};
int gapi_ie_PyParams::sMemberCount = _countof(sMember);
#endif
thread_local IAhkApi::Prototype* ml_ANN_MLP::sPrototype = nullptr;
ObjectMember ml_ANN_MLP::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(getAnnealCoolingRatio, 0, 0),
Object_Method(getAnnealFinalT, 0, 0),
Object_Method(getAnnealInitialT, 0, 0),
Object_Method(getAnnealItePerStep, 0, 0),
Object_Method(getBackpropMomentumScale, 0, 0),
Object_Method(getBackpropWeightScale, 0, 0),
Object_Method(getLayerSizes, 0, 0),
Object_Method(getRpropDW0, 0, 0),
Object_Method(getRpropDWMax, 0, 0),
Object_Method(getRpropDWMin, 0, 0),
Object_Method(getRpropDWMinus, 0, 0),
Object_Method(getRpropDWPlus, 0, 0),
Object_Method(getTermCriteria, 0, 0),
Object_Method(getTrainMethod, 0, 0),
Object_Method(getWeights, 1, 1),
Object_Method(load, 1, 1),
Object_Method(setActivationFunction, 1, 3),
Object_Method(setAnnealCoolingRatio, 1, 1),
Object_Method(setAnnealFinalT, 1, 1),
Object_Method(setAnnealInitialT, 1, 1),
Object_Method(setAnnealItePerStep, 1, 1),
Object_Method(setBackpropMomentumScale, 1, 1),
Object_Method(setBackpropWeightScale, 1, 1),
Object_Method(setLayerSizes, 1, 1),
Object_Method(setRpropDW0, 1, 1),
Object_Method(setRpropDWMax, 1, 1),
Object_Method(setRpropDWMin, 1, 1),
Object_Method(setRpropDWMinus, 1, 1),
Object_Method(setRpropDWPlus, 1, 1),
Object_Method(setTermCriteria, 1, 1),
Object_Method(setTrainMethod, 1, 3),
};
int ml_ANN_MLP::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* ml_Boost::sPrototype = nullptr;
ObjectMember ml_Boost::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(getBoostType, 0, 0),
Object_Method(getWeakCount, 0, 0),
Object_Method(getWeightTrimRate, 0, 0),
Object_Method(load, 1, 2),
Object_Method(setBoostType, 1, 1),
Object_Method(setWeakCount, 1, 1),
Object_Method(setWeightTrimRate, 1, 1),
};
int ml_Boost::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* ml_DTrees::sPrototype = nullptr;
ObjectMember ml_DTrees::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(getCVFolds, 0, 0),
Object_Method(getMaxCategories, 0, 0),
Object_Method(getMaxDepth, 0, 0),
Object_Method(getMinSampleCount, 0, 0),
Object_Method(getPriors, 0, 0),
Object_Method(getRegressionAccuracy, 0, 0),
Object_Method(getTruncatePrunedTree, 0, 0),
Object_Method(getUse1SERule, 0, 0),
Object_Method(getUseSurrogates, 0, 0),
Object_Method(load, 1, 2),
Object_Method(setCVFolds, 1, 1),
Object_Method(setMaxCategories, 1, 1),
Object_Method(setMaxDepth, 1, 1),
Object_Method(setMinSampleCount, 1, 1),
Object_Method(setPriors, 1, 1),
Object_Method(setRegressionAccuracy, 1, 1),
Object_Method(setTruncatePrunedTree, 1, 1),
Object_Method(setUse1SERule, 1, 1),
Object_Method(setUseSurrogates, 1, 1),
};
int ml_DTrees::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* ml_EM::sPrototype = nullptr;
ObjectMember ml_EM::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(getClustersNumber, 0, 0),
Object_Method(getCovarianceMatrixType, 0, 0),
Object_Method(getCovs, 1, 1),
Object_Method(getMeans, 0, 0),
Object_Method(getTermCriteria, 0, 0),
Object_Method(getWeights, 0, 0),
Object_Method(load, 1, 2),
Object_Method(predict, 1, 3),
Object_Method(predict2, 2, 2),
Object_Method(setClustersNumber, 1, 1),
Object_Method(setCovarianceMatrixType, 1, 1),
Object_Method(setTermCriteria, 1, 1),
Object_Method(trainE, 2, 7),
Object_Method(trainEM, 1, 4),
Object_Method(trainM, 2, 5),
};
int ml_EM::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* ml_KNearest::sPrototype = nullptr;
ObjectMember ml_KNearest::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(findNearest, 3, 5),
Object_Method(getAlgorithmType, 0, 0),
Object_Method(getDefaultK, 0, 0),
Object_Method(getEmax, 0, 0),
Object_Method(getIsClassifier, 0, 0),
Object_Method(load, 1, 1),
Object_Method(setAlgorithmType, 1, 1),
Object_Method(setDefaultK, 1, 1),
Object_Method(setEmax, 1, 1),
Object_Method(setIsClassifier, 1, 1),
};
int ml_KNearest::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* ml_LogisticRegression::sPrototype = nullptr;
ObjectMember ml_LogisticRegression::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(getIterations, 0, 0),
Object_Method(getLearningRate, 0, 0),
Object_Method(getMiniBatchSize, 0, 0),
Object_Method(getRegularization, 0, 0),
Object_Method(getTermCriteria, 0, 0),
Object_Method(getTrainMethod, 0, 0),
Object_Method(get_learnt_thetas, 0, 0),
Object_Method(load, 1, 2),
Object_Method(predict, 1, 3),
Object_Method(setIterations, 1, 1),
Object_Method(setLearningRate, 1, 1),
Object_Method(setMiniBatchSize, 1, 1),
Object_Method(setRegularization, 1, 1),
Object_Method(setTermCriteria, 1, 1),
Object_Method(setTrainMethod, 1, 1),
};
int ml_LogisticRegression::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* ml_NormalBayesClassifier::sPrototype = nullptr;
ObjectMember ml_NormalBayesClassifier::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(load, 1, 2),
Object_Method(predictProb, 3, 4),
};
int ml_NormalBayesClassifier::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* ml_ParamGrid::sPrototype = nullptr;
ObjectMember ml_ParamGrid::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
};
int ml_ParamGrid::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* ml_RTrees::sPrototype = nullptr;
ObjectMember ml_RTrees::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(getActiveVarCount, 0, 0),
Object_Method(getCalculateVarImportance, 0, 0),
Object_Method(getOOBError, 0, 0),
Object_Method(getTermCriteria, 0, 0),
Object_Method(getVarImportance, 0, 0),
Object_Method(getVotes, 3, 3),
Object_Method(load, 1, 2),
Object_Method(setActiveVarCount, 1, 1),
Object_Method(setCalculateVarImportance, 1, 1),
Object_Method(setTermCriteria, 1, 1),
};
int ml_RTrees::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* ml_SVM::sPrototype = nullptr;
ObjectMember ml_SVM::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(getC, 0, 0),
Object_Method(getClassWeights, 0, 0),
Object_Method(getCoef0, 0, 0),
Object_Method(getDecisionFunction, 3, 3),
Object_Method(getDefaultGridPtr, 1, 1),
Object_Method(getDegree, 0, 0),
Object_Method(getGamma, 0, 0),
Object_Method(getKernelType, 0, 0),
Object_Method(getNu, 0, 0),
Object_Method(getP, 0, 0),
Object_Method(getSupportVectors, 0, 0),
Object_Method(getTermCriteria, 0, 0),
Object_Method(getType, 0, 0),
Object_Method(getUncompressedSupportVectors, 0, 0),
Object_Method(load, 1, 1),
Object_Method(setC, 1, 1),
Object_Method(setClassWeights, 1, 1),
Object_Method(setCoef0, 1, 1),
Object_Method(setDegree, 1, 1),
Object_Method(setGamma, 1, 1),
Object_Method(setKernel, 1, 1),
Object_Method(setNu, 1, 1),
Object_Method(setP, 1, 1),
Object_Method(setTermCriteria, 1, 1),
Object_Method(setType, 1, 1),
Object_Method(trainAuto, 3, 11),
};
int ml_SVM::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* ml_SVMSGD::sPrototype = nullptr;
ObjectMember ml_SVMSGD::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(getInitialStepSize, 0, 0),
Object_Method(getMarginRegularization, 0, 0),
Object_Method(getMarginType, 0, 0),
Object_Method(getShift, 0, 0),
Object_Method(getStepDecreasingPower, 0, 0),
Object_Method(getSvmsgdType, 0, 0),
Object_Method(getTermCriteria, 0, 0),
Object_Method(getWeights, 0, 0),
Object_Method(load, 1, 2),
Object_Method(setInitialStepSize, 1, 1),
Object_Method(setMarginRegularization, 1, 1),
Object_Method(setMarginType, 1, 1),
Object_Method(setOptimalParameters, 0, 2),
Object_Method(setStepDecreasingPower, 1, 1),
Object_Method(setSvmsgdType, 1, 1),
Object_Method(setTermCriteria, 1, 1),
};
int ml_SVMSGD::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* ml_StatModel::sPrototype = nullptr;
ObjectMember ml_StatModel::sMember[] = {
Object_Method(calcError, 3, 3),
Object_Method(empty, 0, 0),
Object_Method(getVarCount, 0, 0),
Object_Method(isClassifier, 0, 0),
Object_Method(isTrained, 0, 0),
Object_Method(predict, 1, 3),
Object_Method(train, 1, 3),
};
int ml_StatModel::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* ml_TrainData::sPrototype = nullptr;
ObjectMember ml_TrainData::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(getCatCount, 1, 1),
Object_Method(getCatMap, 0, 0),
Object_Method(getCatOfs, 0, 0),
Object_Method(getClassLabels, 0, 0),
Object_Method(getDefaultSubstValues, 0, 0),
Object_Method(getLayout, 0, 0),
Object_Method(getMissing, 0, 0),
Object_Method(getNAllVars, 0, 0),
Object_Method(getNSamples, 0, 0),
Object_Method(getNTestSamples, 0, 0),
Object_Method(getNTrainSamples, 0, 0),
Object_Method(getNVars, 0, 0),
Object_Method(getNames, 1, 1),
Object_Method(getNormCatResponses, 0, 0),
Object_Method(getResponseType, 0, 0),
Object_Method(getResponses, 0, 0),
Object_Method(getSample, 3, 3),
Object_Method(getSampleWeights, 0, 0),
Object_Method(getSamples, 0, 0),
Object_Method(getSubMatrix, 3, 3),
Object_Method(getSubVector, 2, 2),
Object_Method(getTestNormCatResponses, 0, 0),
Object_Method(getTestResponses, 0, 0),
Object_Method(getTestSampleIdx, 0, 0),
Object_Method(getTestSampleWeights, 0, 0),
Object_Method(getTestSamples, 0, 0),
Object_Method(getTrainNormCatResponses, 0, 0),
Object_Method(getTrainResponses, 0, 0),
Object_Method(getTrainSampleIdx, 0, 0),
Object_Method(getTrainSampleWeights, 0, 0),
Object_Method(getTrainSamples, 0, 3),
Object_Method(getValues, 3, 3),
Object_Method(getVarIdx, 0, 0),
Object_Method(getVarSymbolFlags, 0, 0),
Object_Method(getVarType, 0, 0),
Object_Method(setTrainTestSplit, 1, 2),
Object_Method(setTrainTestSplitRatio, 1, 2),
Object_Method(shuffleTrainTest, 0, 0),
};
int ml_TrainData::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* ocl_Device::sPrototype = nullptr;
ObjectMember ocl_Device::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(OpenCLVersion, 0, 0),
Object_Method(OpenCL_C_Version, 0, 0),
Object_Method(addressBits, 0, 0),
Object_Method(available, 0, 0),
Object_Method(compilerAvailable, 0, 0),
Object_Method(deviceVersionMajor, 0, 0),
Object_Method(deviceVersionMinor, 0, 0),
Object_Method(doubleFPConfig, 0, 0),
Object_Method(driverVersion, 0, 0),
Object_Method(endianLittle, 0, 0),
Object_Method(errorCorrectionSupport, 0, 0),
Object_Method(executionCapabilities, 0, 0),
Object_Method(extensions, 0, 0),
Object_Method(getDefault, 0, 0),
Object_Method(globalMemCacheLineSize, 0, 0),
Object_Method(globalMemCacheSize, 0, 0),
Object_Method(globalMemCacheType, 0, 0),
Object_Method(globalMemSize, 0, 0),
Object_Method(halfFPConfig, 0, 0),
Object_Method(hostUnifiedMemory, 0, 0),
Object_Method(image2DMaxHeight, 0, 0),
Object_Method(image2DMaxWidth, 0, 0),
Object_Method(image3DMaxDepth, 0, 0),
Object_Method(image3DMaxHeight, 0, 0),
Object_Method(image3DMaxWidth, 0, 0),
Object_Method(imageFromBufferSupport, 0, 0),
Object_Method(imageMaxArraySize, 0, 0),
Object_Method(imageMaxBufferSize, 0, 0),
Object_Method(imageSupport, 0, 0),
Object_Method(intelSubgroupsSupport, 0, 0),
Object_Method(isAMD, 0, 0),
Object_Method(isExtensionSupported, 1, 1),
Object_Method(isIntel, 0, 0),
Object_Method(isNVidia, 0, 0),
Object_Method(linkerAvailable, 0, 0),
Object_Method(localMemSize, 0, 0),
Object_Method(localMemType, 0, 0),
Object_Method(maxClockFrequency, 0, 0),
Object_Method(maxComputeUnits, 0, 0),
Object_Method(maxConstantArgs, 0, 0),
Object_Method(maxConstantBufferSize, 0, 0),
Object_Method(maxMemAllocSize, 0, 0),
Object_Method(maxParameterSize, 0, 0),
Object_Method(maxReadImageArgs, 0, 0),
Object_Method(maxSamplers, 0, 0),
Object_Method(maxWorkGroupSize, 0, 0),
Object_Method(maxWorkItemDims, 0, 0),
Object_Method(maxWriteImageArgs, 0, 0),
Object_Method(memBaseAddrAlign, 0, 0),
Object_Method(name, 0, 0),
Object_Method(nativeVectorWidthChar, 0, 0),
Object_Method(nativeVectorWidthDouble, 0, 0),
Object_Method(nativeVectorWidthFloat, 0, 0),
Object_Method(nativeVectorWidthHalf, 0, 0),
Object_Method(nativeVectorWidthInt, 0, 0),
Object_Method(nativeVectorWidthLong, 0, 0),
Object_Method(nativeVectorWidthShort, 0, 0),
Object_Method(preferredVectorWidthChar, 0, 0),
Object_Method(preferredVectorWidthDouble, 0, 0),
Object_Method(preferredVectorWidthFloat, 0, 0),
Object_Method(preferredVectorWidthHalf, 0, 0),
Object_Method(preferredVectorWidthInt, 0, 0),
Object_Method(preferredVectorWidthLong, 0, 0),
Object_Method(preferredVectorWidthShort, 0, 0),
Object_Method(printfBufferSize, 0, 0),
Object_Method(profilingTimerResolution, 0, 0),
Object_Method(singleFPConfig, 0, 0),
Object_Method(type, 0, 0),
Object_Method(vendorID, 0, 0),
Object_Method(vendorName, 0, 0),
Object_Method(version, 0, 0),
};
int ocl_Device::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* ocl_OpenCLExecutionContext::sPrototype = nullptr;
ObjectMember ocl_OpenCLExecutionContext::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
};
int ocl_OpenCLExecutionContext::sMemberCount = _countof(sMember);
thread_local IAhkApi::Prototype* segmentation_IntelligentScissorsMB::sPrototype = nullptr;
ObjectMember segmentation_IntelligentScissorsMB::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(applyImage, 1, 1),
Object_Method(applyImageFeatures, 3, 4),
Object_Method(buildMap, 1, 1),
Object_Method(getContour, 2, 3),
Object_Method(setEdgeFeatureCannyParameters, 2, 4),
Object_Method(setEdgeFeatureZeroCrossingParameters, 0, 1),
Object_Method(setGradientMagnitudeMaxLimit, 0, 1),
Object_Method(setWeights, 3, 3),
};
int segmentation_IntelligentScissorsMB::sMemberCount = _countof(sMember);


void RNG::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	ResultType __result;
	switch (aID)
	{
	case M___Delete: mC = {}; return;
	case M___New: {
		new (&mC) cv::Ptr<cv::RNG>;
		if (aParamCount == 1 && aParam[0] == g_invalid) return;
		if (!aParamCount)
			mC = new cv::RNG;
		else {
			uint64 state;
			if (ParamIndexToVal(0, (__int64&)state))
				_o_return_result;
			mC = new cv::RNG(state);
		}
		return;
	}
	case M_Call: {
		if (aParamCount) {
			uint N;
			if (ParamIndexToVal(0, (int&)N))
				_o_return_result;
			return (void)aResultToken.SetValue((__int64)(*mC)(N));
		}
		return (void)aResultToken.SetValue((__int64)(*mC)());
	}
	case M_fill: {
		cv::_InputOutputArray mat;
		cv::_InputArray a, b;
		int distType, saturateRange = 0;
		if (ParamIndexToVal(0, mat))
			_o_return_result;
		if (ParamIndexToVal(1, distType))
			_o_return_result;
		if (ParamIndexToVal(2, a))
			_o_return_result;
		if (ParamIndexToVal(3, b))
			_o_return_result;
		if (aParamCount > 4 && ParamIndexToVal(4, saturateRange, 2))
			_o_return_result;
		mC->fill(mat, distType, a, b, saturateRange);
		return;
	}
	case M_gaussian: {
		double sigma;
		if (ParamIndexToVal(0, sigma))
			_o_return_result;
		return (void)aResultToken.SetValue(mC->gaussian(sigma));
	}
	case M_next: {
		return (void)aResultToken.SetValue((__int64)mC->next());
	}
	case M_uniform: {
		if (!MatchTypes("ff")) {
			return (void)aResultToken.SetValue(mC->uniform(TokenToDouble(*aParam[0]), TokenToDouble(*aParam[1])));
		}
		else {
			int a, b;
			if (ParamIndexToVal(0, a))
				_o_return_result;
			if (ParamIndexToVal(1, b))
				_o_return_result;
			return (void)aResultToken.SetValue((__int64)mC->uniform(a, b));
		}
	}
	default:
		break;
	}
}

#ifdef HAS_GAPI
void GOpaque_Size::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	switch (aID)
	{
	case M___Delete: mC = {}; return;
	case M___New: new (&mC) cv::GOpaque<cv::Size>; return;
	default:
		break;
	}
}

void GOpaque_Rect::Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount) {
	switch (aID)
	{
	case M___Delete: mC = {}; return;
	case M___New: new (&mC) cv::GOpaque<cv::Rect>; return;
	default:
		break;
	}
}
#endif

thread_local IAhkApi::Prototype* RNG::sPrototype = nullptr;
ObjectMember RNG::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
Object_Method(Call, 0, 1),
Object_Method(next, 0, 0),
Object_Method(uniform, 2, 2),
Object_Method(fill, 4, 5),
Object_Method(gaussian, 1, 1),
};
int RNG::sMemberCount = _countof(sMember);

#ifdef HAS_GAPI
thread_local IAhkApi::Prototype* GOpaque_Size::sPrototype = nullptr;
ObjectMember GOpaque_Size::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
};
int GOpaque_Size::sMemberCount = _countof(sMember);

thread_local IAhkApi::Prototype* GOpaque_Rect::sPrototype = nullptr;
ObjectMember GOpaque_Rect::sMember[] = {
Object_Method(__New, 0, NA),
Object_Method(__Delete, 0, 0),
};
int GOpaque_Rect::sMemberCount = _countof(sMember);
#endif