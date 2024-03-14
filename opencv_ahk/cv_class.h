#pragma once
#include "cv_ahk.h"
#include <ahkapi.h>

class CirclesGridFinderParameters : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		P_densityNeighborhoodSize,
		P_minDensity,
		P_kmeansAttempts,
		P_minDistanceToAddKeypoint,
		P_keypointScale,
		P_minGraphConfidence,
		P_vertexGain,
		P_vertexPenalty,
		P_existingVertexGain,
		P_edgeGain,
		P_edgePenalty,
		P_convexHullFactor,
		P_minRNGEdgeSwitchDist,
		P_squareSize,
		P_maxRectifiedDistance,
	};

public:
	cv::CirclesGridFinderParameters mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

#ifdef HAS_GAPI
class GArrayDesc : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
	};

public:
	cv::GArrayDesc mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class GMatDesc : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		P_depth,
		P_chan,
		P_size,
		P_planar,
		P_dims,
		M_asInterleaved,
		M_asPlanar,
		M_withDepth,
		M_withSize,
		M_withSizeDelta,
		M_withType,
	};

public:
	cv::GMatDesc mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class GOpaqueDesc : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
	};

public:
	cv::GOpaqueDesc mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class GScalarDesc : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
	};

public:
	cv::GScalarDesc mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};
#endif

class HOGDescriptor : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		P_winSize,
		P_blockSize,
		P_blockStride,
		P_cellSize,
		P_nbins,
		P_derivAperture,
		P_winSigma,
		P_histogramNormType,
		P_L2HysThreshold,
		P_gammaCorrection,
		P_svmDetector,
		P_nlevels,
		P_signedGradient,
		M_checkDetectorSize,
		M_compute,
		M_computeGradient,
		M_detect,
		M_detectMultiScale,
		M_getDaimlerPeopleDetector,
		M_getDefaultPeopleDetector,
		M_getDescriptorSize,
		M_getWinSigma,
		M_load,
		M_save,
		M_setSVMDetector,
	};

public:
	cv::HOGDescriptor mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class QRCodeEncoder_Params : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		P_version,
		P_correction_level,
		P_mode,
		P_structure_number,
	};

public:
	cv::QRCodeEncoder::Params mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class SimpleBlobDetector_Params : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		P_thresholdStep,
		P_minThreshold,
		P_maxThreshold,
		P_minRepeatability,
		P_minDistBetweenBlobs,
		P_filterByColor,
		P_blobColor,
		P_filterByArea,
		P_minArea,
		P_maxArea,
		P_filterByCircularity,
		P_minCircularity,
		P_maxCircularity,
		P_filterByInertia,
		P_minInertiaRatio,
		P_maxInertiaRatio,
		P_filterByConvexity,
		P_minConvexity,
		P_maxConvexity,
	};

public:
	cv::SimpleBlobDetector::Params mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class TrackerDaSiamRPN_Params : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		P_model,
		P_kernel_cls1,
		P_kernel_r1,
		P_backend,
		P_target,
	};

public:
	cv::TrackerDaSiamRPN::Params mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class TrackerGOTURN_Params : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		P_modelTxt,
		P_modelBin,
	};

public:
	cv::TrackerGOTURN::Params mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class TrackerMIL_Params : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		P_samplerInitInRadius,
		P_samplerInitMaxNegNum,
		P_samplerSearchWinSize,
		P_samplerTrackInRadius,
		P_samplerTrackMaxPosNum,
		P_samplerTrackMaxNegNum,
		P_featureSetNumFeatures,
	};

public:
	cv::TrackerMIL::Params mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class UsacParams : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		P_confidence,
		P_isParallel,
		P_loIterations,
		P_loMethod,
		P_loSampleSize,
		P_maxIterations,
		P_neighborsSearch,
		P_randomGeneratorState,
		P_sampler,
		P_score,
		P_threshold,
	};

public:
	cv::UsacParams mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class detail_CameraParams : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		P_focal,
		P_aspect,
		P_ppx,
		P_ppy,
		P_R,
		P_t,
		M_K,
	};

public:
	cv::detail::CameraParams mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class detail_ImageFeatures : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		P_img_idx,
		P_img_size,
		P_keypoints,
		P_descriptors,
		M_getKeypoints,
	};

public:
	cv::detail::ImageFeatures mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class detail_MatchesInfo : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		P_src_img_idx,
		P_dst_img_idx,
		P_num_inliers,
		P_H,
		P_confidence,
		M_getInliers,
		M_getMatches,
	};

public:
	cv::detail::MatchesInfo mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class detail_ProjectorBase : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_setCameraParams,
		P_scale,
		P_k,
		P_rinv,
		P_r_kinv,
		P_k_rinv,
		P_t,
	};

public:
	cv::detail::ProjectorBase mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class detail_SphericalProjector : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_mapBackward,
		M_mapForward,
	};

public:
	cv::detail::SphericalProjector mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class dnn_DictValue : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_getIntValue,
		M_getRealValue,
		M_getStringValue,
		M_isInt,
		M_isReal,
		M_isString,
	};

public:
	cv::dnn::DictValue mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

#ifdef HAS_GAPI
class gapi_GNetPackage : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
	};

public:
	cv::gapi::GNetPackage mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class gapi_GNetParam : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
	};

public:
	cv::gapi::GNetParam mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class gapi_streaming_queue_capacity : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		P_capacity,
	};

public:
	cv::gapi::streaming::queue_capacity mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class gapi_wip_draw_Circle : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		P_center,
		P_radius,
		P_color,
		P_thick,
		P_lt,
		P_shift,
	};

public:
	cv::gapi::wip::draw::Circle mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class gapi_wip_draw_Image : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		P_org,
		P_img,
		P_alpha,
	};

public:
	cv::gapi::wip::draw::Image mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class gapi_wip_draw_Line : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		P_pt1,
		P_pt2,
		P_color,
		P_thick,
		P_lt,
		P_shift,
	};

public:
	cv::gapi::wip::draw::Line mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class gapi_wip_draw_Mosaic : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		P_mos,
		P_cellSz,
		P_decim,
	};

public:
	cv::gapi::wip::draw::Mosaic mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class gapi_wip_draw_Poly : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		P_points,
		P_color,
		P_thick,
		P_lt,
		P_shift,
	};

public:
	cv::gapi::wip::draw::Poly mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class gapi_wip_draw_Rect : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		P_rect,
		P_color,
		P_thick,
		P_lt,
		P_shift,
	};

public:
	cv::gapi::wip::draw::Rect mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class gapi_wip_draw_Text : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		P_text,
		P_org,
		P_ff,
		P_fs,
		P_color,
		P_thick,
		P_lt,
		P_bottom_left_origin,
	};

public:
	cv::gapi::wip::draw::Text mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};
#endif

class AKAZE : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_create,
		M_getDefaultName,
		M_getDescriptorChannels,
		M_getDescriptorSize,
		M_getDescriptorType,
		M_getDiffusivity,
		M_getNOctaveLayers,
		M_getNOctaves,
		M_getThreshold,
		M_setDescriptorChannels,
		M_setDescriptorSize,
		M_setDescriptorType,
		M_setDiffusivity,
		M_setNOctaveLayers,
		M_setNOctaves,
		M_setThreshold,
	};

public:
	cv::Ptr<cv::AKAZE> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class AffineFeature : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_create,
		M_getDefaultName,
		M_getViewParams,
		M_setViewParams,
	};

public:
	cv::Ptr<cv::AffineFeature> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class AgastFeatureDetector : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_create,
		M_getDefaultName,
		M_getNonmaxSuppression,
		M_getThreshold,
		M_getType,
		M_setNonmaxSuppression,
		M_setThreshold,
		M_setType,
	};

public:
	cv::Ptr<cv::AgastFeatureDetector> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class Algorithm : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_clear,
		M_empty,
		M_getDefaultName,
		M_read,
		M_save,
		M_write,
	};

public:
	cv::Ptr<cv::Algorithm> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class AlignExposures : public Object
{
	enum MemBerID {
		M_process,
	};

public:
	cv::Ptr<cv::AlignExposures> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class AlignMTB : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_calculateShift,
		M_computeBitmaps,
		M_getCut,
		M_getExcludeRange,
		M_getMaxBits,
		M_process,
		M_setCut,
		M_setExcludeRange,
		M_setMaxBits,
		M_shiftMat,
	};

public:
	cv::Ptr<cv::AlignMTB> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class AsyncArray : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_get,
		M_release,
		M_valid,
		M_wait_for,
	};

public:
	cv::Ptr<cv::AsyncArray> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class BFMatcher : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_create,
	};

public:
	cv::Ptr<cv::BFMatcher> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class BOWImgDescriptorExtractor : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_compute2,
		M_descriptorSize,
		M_descriptorType,
		M_getVocabulary,
		M_setVocabulary,
	};

public:
	cv::Ptr<cv::BOWImgDescriptorExtractor> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class BOWKMeansTrainer : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_cluster,
	};

public:
	cv::Ptr<cv::BOWKMeansTrainer> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class BOWTrainer : public Object
{
	enum MemBerID {
		M_add,
		M_clear,
		M_cluster,
		M_descriptorsCount,
		M_getDescriptors,
	};

public:
	cv::Ptr<cv::BOWTrainer> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class BRISK : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_create,
		M_getDefaultName,
		M_getOctaves,
		M_getThreshold,
		M_setOctaves,
		M_setThreshold,
	};

public:
	cv::Ptr<cv::BRISK> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class BackgroundSubtractor : public Object
{
	enum MemBerID {
		M_apply,
		M_getBackgroundImage,
	};

public:
	cv::Ptr<cv::BackgroundSubtractor> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class BackgroundSubtractorKNN : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_getDetectShadows,
		M_getDist2Threshold,
		M_getHistory,
		M_getNSamples,
		M_getShadowThreshold,
		M_getShadowValue,
		M_getkNNSamples,
		M_setDetectShadows,
		M_setDist2Threshold,
		M_setHistory,
		M_setNSamples,
		M_setShadowThreshold,
		M_setShadowValue,
		M_setkNNSamples,
	};

public:
	cv::Ptr<cv::BackgroundSubtractorKNN> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class BackgroundSubtractorMOG2 : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_apply,
		M_getBackgroundRatio,
		M_getComplexityReductionThreshold,
		M_getDetectShadows,
		M_getHistory,
		M_getNMixtures,
		M_getShadowThreshold,
		M_getShadowValue,
		M_getVarInit,
		M_getVarMax,
		M_getVarMin,
		M_getVarThreshold,
		M_getVarThresholdGen,
		M_setBackgroundRatio,
		M_setComplexityReductionThreshold,
		M_setDetectShadows,
		M_setHistory,
		M_setNMixtures,
		M_setShadowThreshold,
		M_setShadowValue,
		M_setVarInit,
		M_setVarMax,
		M_setVarMin,
		M_setVarThreshold,
		M_setVarThresholdGen,
	};

public:
	cv::Ptr<cv::BackgroundSubtractorMOG2> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class BaseCascadeClassifier : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
	};

public:
	cv::Ptr<cv::BaseCascadeClassifier> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class CLAHE : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_apply,
		M_collectGarbage,
		M_getClipLimit,
		M_getTilesGridSize,
		M_setClipLimit,
		M_setTilesGridSize,
	};

public:
	cv::Ptr<cv::CLAHE> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class CalibrateCRF : public Object
{
	enum MemBerID {
		M_process,
	};

public:
	cv::Ptr<cv::CalibrateCRF> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class CalibrateDebevec : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_getLambda,
		M_getRandom,
		M_getSamples,
		M_setLambda,
		M_setRandom,
		M_setSamples,
	};

public:
	cv::Ptr<cv::CalibrateDebevec> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class CalibrateRobertson : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_getMaxIter,
		M_getRadiance,
		M_getThreshold,
		M_setMaxIter,
		M_setThreshold,
	};

public:
	cv::Ptr<cv::CalibrateRobertson> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class CascadeClassifier : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_convert,
		M_detectMultiScale,
		M_empty,
		M_getFeatureType,
		M_getOriginalWindowSize,
		M_isOldFormatCascade,
		M_load,
		M_read,
	};

public:
	cv::Ptr<cv::CascadeClassifier> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class DISOpticalFlow : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_create,
		M_getFinestScale,
		M_getGradientDescentIterations,
		M_getPatchSize,
		M_getPatchStride,
		M_getUseMeanNormalization,
		M_getUseSpatialPropagation,
		M_getVariationalRefinementAlpha,
		M_getVariationalRefinementDelta,
		M_getVariationalRefinementGamma,
		M_getVariationalRefinementIterations,
		M_setFinestScale,
		M_setGradientDescentIterations,
		M_setPatchSize,
		M_setPatchStride,
		M_setUseMeanNormalization,
		M_setUseSpatialPropagation,
		M_setVariationalRefinementAlpha,
		M_setVariationalRefinementDelta,
		M_setVariationalRefinementGamma,
		M_setVariationalRefinementIterations,
	};

public:
	cv::Ptr<cv::DISOpticalFlow> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class DMatch : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		P_queryIdx,
		P_trainIdx,
		P_imgIdx,
		P_distance,
	};

public:
	cv::Ptr<cv::DMatch> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class DenseOpticalFlow : public Object
{
	enum MemBerID {
		M_calc,
		M_collectGarbage,
	};

public:
	cv::Ptr<cv::DenseOpticalFlow> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class DescriptorMatcher : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_add,
		M_clear,
		M_clone,
		M_create,
		M_empty,
		M_getTrainDescriptors,
		M_isMaskSupported,
		M_knnMatch,
		M_match,
		M_radiusMatch,
		M_read,
		M_train,
		M_write,
	};

public:
	cv::Ptr<cv::DescriptorMatcher> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class FaceDetectorYN : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_create,
		M_detect,
		M_getInputSize,
		M_getNMSThreshold,
		M_getScoreThreshold,
		M_getTopK,
		M_setInputSize,
		M_setNMSThreshold,
		M_setScoreThreshold,
		M_setTopK,
	};

public:
	cv::Ptr<cv::FaceDetectorYN> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class FaceRecognizerSF : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_alignCrop,
		M_create,
		M_feature,
		M_match,
	};

public:
	cv::Ptr<cv::FaceRecognizerSF> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class FarnebackOpticalFlow : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_create,
		M_getFastPyramids,
		M_getFlags,
		M_getNumIters,
		M_getNumLevels,
		M_getPolyN,
		M_getPolySigma,
		M_getPyrScale,
		M_getWinSize,
		M_setFastPyramids,
		M_setFlags,
		M_setNumIters,
		M_setNumLevels,
		M_setPolyN,
		M_setPolySigma,
		M_setPyrScale,
		M_setWinSize,
	};

public:
	cv::Ptr<cv::FarnebackOpticalFlow> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class FastFeatureDetector : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_create,
		M_getDefaultName,
		M_getNonmaxSuppression,
		M_getThreshold,
		M_getType,
		M_setNonmaxSuppression,
		M_setThreshold,
		M_setType,
	};

public:
	cv::Ptr<cv::FastFeatureDetector> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class Feature2D : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_compute,
		M_defaultNorm,
		M_descriptorSize,
		M_descriptorType,
		M_detect,
		M_detectAndCompute,
		M_empty,
		M_getDefaultName,
		M_read,
		M_write,
	};

public:
	cv::Ptr<cv::Feature2D> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class FileNode : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_empty,
		M_isInt,
		M_isMap,
		M_isNamed,
		M_isNone,
		M_isReal,
		M_isSeq,
		M_isString,
		M_keys,
		M_mat,
		M_name,
		P___Item,
		M_rawSize,
		M_real,
		M_size,
		M_string,
		M_type,
	};

public:
	cv::Ptr<cv::FileNode> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class FileStorage : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_endWriteStruct,
		M_getFirstTopLevelNode,
		M_getFormat,
		M_isOpened,
		M_open,
		P___Item,
		M_release,
		M_releaseAndGetString,
		M_root,
		M_startWriteStruct,
		M_write,
		M_writeComment,
	};

public:
	cv::Ptr<cv::FileStorage> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class FlannBasedMatcher : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_create,
	};

public:
	cv::Ptr<cv::FlannBasedMatcher> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class GFTTDetector : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_create,
		M_getBlockSize,
		M_getDefaultName,
		M_getHarrisDetector,
		M_getK,
		M_getMaxFeatures,
		M_getMinDistance,
		M_getQualityLevel,
		M_setBlockSize,
		M_setHarrisDetector,
		M_setK,
		M_setMaxFeatures,
		M_setMinDistance,
		M_setQualityLevel,
	};

public:
	cv::Ptr<cv::GFTTDetector> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

#ifdef HAS_GAPI
class GFrame : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
	};

public:
	cv::Ptr<cv::GFrame> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class GMat : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
	};

public:
	cv::Ptr<cv::GMat> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class GScalar : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
	};

public:
	cv::Ptr<cv::GScalar> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class GStreamingCompiled : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_pull,
		M_running,
		M_setSource,
		M_start,
		M_stop,
	};

public:
	cv::Ptr<cv::GStreamingCompiled> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};
#endif

class GeneralizedHough : public Object
{
	enum MemBerID {
		M_detect,
		M_getCannyHighThresh,
		M_getCannyLowThresh,
		M_getDp,
		M_getMaxBufferSize,
		M_getMinDist,
		M_setCannyHighThresh,
		M_setCannyLowThresh,
		M_setDp,
		M_setMaxBufferSize,
		M_setMinDist,
		M_setTemplate,
	};

public:
	cv::Ptr<cv::GeneralizedHough> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class GeneralizedHoughBallard : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_getLevels,
		M_getVotesThreshold,
		M_setLevels,
		M_setVotesThreshold,
	};

public:
	cv::Ptr<cv::GeneralizedHoughBallard> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class GeneralizedHoughGuil : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_getAngleEpsilon,
		M_getAngleStep,
		M_getAngleThresh,
		M_getLevels,
		M_getMaxAngle,
		M_getMaxScale,
		M_getMinAngle,
		M_getMinScale,
		M_getPosThresh,
		M_getScaleStep,
		M_getScaleThresh,
		M_getXi,
		M_setAngleEpsilon,
		M_setAngleStep,
		M_setAngleThresh,
		M_setLevels,
		M_setMaxAngle,
		M_setMaxScale,
		M_setMinAngle,
		M_setMinScale,
		M_setPosThresh,
		M_setScaleStep,
		M_setScaleThresh,
		M_setXi,
	};

public:
	cv::Ptr<cv::GeneralizedHoughGuil> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class KAZE : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_create,
		M_getDefaultName,
		M_getDiffusivity,
		M_getExtended,
		M_getNOctaveLayers,
		M_getNOctaves,
		M_getThreshold,
		M_getUpright,
		M_setDiffusivity,
		M_setExtended,
		M_setNOctaveLayers,
		M_setNOctaves,
		M_setThreshold,
		M_setUpright,
	};

public:
	cv::Ptr<cv::KAZE> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class KalmanFilter : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_correct,
		M_predict,
	};

public:
	cv::Ptr<cv::KalmanFilter> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class KeyPoint : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_convert,
		M_overlap,
	};

public:
	cv::Ptr<cv::KeyPoint> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class LineSegmentDetector : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_compareSegments,
		M_detect,
		M_drawSegments,
	};

public:
	cv::Ptr<cv::LineSegmentDetector> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class MSER : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_create,
		M_detectRegions,
		M_getDefaultName,
		M_getDelta,
		M_getMaxArea,
		M_getMinArea,
		M_getPass2Only,
		M_setDelta,
		M_setMaxArea,
		M_setMinArea,
		M_setPass2Only,
	};

public:
	cv::Ptr<cv::MSER> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class MergeDebevec : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_process,
	};

public:
	cv::Ptr<cv::MergeDebevec> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class MergeExposures : public Object
{
	enum MemBerID {
		M_process,
	};

public:
	cv::Ptr<cv::MergeExposures> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class MergeMertens : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_getContrastWeight,
		M_getExposureWeight,
		M_getSaturationWeight,
		M_process,
		M_setContrastWeight,
		M_setExposureWeight,
		M_setSaturationWeight,
	};

public:
	cv::Ptr<cv::MergeMertens> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class MergeRobertson : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_process,
	};

public:
	cv::Ptr<cv::MergeRobertson> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class Moments : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		P_m00,
		P_m10,
		P_m01,
		P_m20,
		P_m11,
		P_m02,
		P_m30,
		P_m21,
		P_m12,
		P_m03,
		P_mu20,
		P_mu11,
		P_mu02,
		P_mu30,
		P_mu21,
		P_mu12,
		P_mu03,
		P_nu20,
		P_nu11,
		P_nu02,
		P_nu30,
		P_nu21,
		P_nu12,
		P_nu03,
	};

public:
	cv::Ptr<cv::Moments> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class ORB : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_create,
		M_getDefaultName,
		M_getEdgeThreshold,
		M_getFastThreshold,
		M_getFirstLevel,
		M_getMaxFeatures,
		M_getNLevels,
		M_getPatchSize,
		M_getScaleFactor,
		M_getScoreType,
		M_getWTA_K,
		M_setEdgeThreshold,
		M_setFastThreshold,
		M_setFirstLevel,
		M_setMaxFeatures,
		M_setNLevels,
		M_setPatchSize,
		M_setScaleFactor,
		M_setScoreType,
		M_setWTA_K,
	};

public:
	cv::Ptr<cv::ORB> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class PyRotationWarper : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_buildMaps,
		M_getScale,
		M_setScale,
		M_warp,
		M_warpBackward,
		M_warpPoint,
		M_warpPointBackward,
		M_warpRoi,
	};

public:
	cv::Ptr<cv::PyRotationWarper> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class QRCodeDetector : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_decode,
		M_decodeCurved,
		M_decodeMulti,
		M_detect,
		M_detectAndDecode,
		M_detectAndDecodeCurved,
		M_detectAndDecodeMulti,
		M_detectMulti,
		M_setEpsX,
		M_setEpsY,
	};

public:
	cv::Ptr<cv::QRCodeDetector> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class QRCodeEncoder : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_create,
		M_encode,
		M_encodeStructuredAppend,
	};

public:
	cv::Ptr<cv::QRCodeEncoder> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class SIFT : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_create,
		M_getDefaultName,
	};

public:
	cv::Ptr<cv::SIFT> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class SimpleBlobDetector : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_create,
		M_getDefaultName,
	};

public:
	cv::Ptr<cv::SimpleBlobDetector> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class SparseOpticalFlow : public Object
{
	enum MemBerID {
		M_calc,
	};

public:
	cv::Ptr<cv::SparseOpticalFlow> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class SparsePyrLKOpticalFlow : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_create,
		M_getFlags,
		M_getMaxLevel,
		M_getMinEigThreshold,
		M_getTermCriteria,
		M_getWinSize,
		M_setFlags,
		M_setMaxLevel,
		M_setMinEigThreshold,
		M_setTermCriteria,
		M_setWinSize,
	};

public:
	cv::Ptr<cv::SparsePyrLKOpticalFlow> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class StereoBM : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_create,
		M_getPreFilterCap,
		M_getPreFilterSize,
		M_getPreFilterType,
		M_getROI1,
		M_getROI2,
		M_getSmallerBlockSize,
		M_getTextureThreshold,
		M_getUniquenessRatio,
		M_setPreFilterCap,
		M_setPreFilterSize,
		M_setPreFilterType,
		M_setROI1,
		M_setROI2,
		M_setSmallerBlockSize,
		M_setTextureThreshold,
		M_setUniquenessRatio,
	};

public:
	cv::Ptr<cv::StereoBM> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class StereoMatcher : public Object
{
	enum MemBerID {
		M_compute,
		M_getBlockSize,
		M_getDisp12MaxDiff,
		M_getMinDisparity,
		M_getNumDisparities,
		M_getSpeckleRange,
		M_getSpeckleWindowSize,
		M_setBlockSize,
		M_setDisp12MaxDiff,
		M_setMinDisparity,
		M_setNumDisparities,
		M_setSpeckleRange,
		M_setSpeckleWindowSize,
	};

public:
	cv::Ptr<cv::StereoMatcher> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class StereoSGBM : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_create,
		M_getMode,
		M_getP1,
		M_getP2,
		M_getPreFilterCap,
		M_getUniquenessRatio,
		M_setMode,
		M_setP1,
		M_setP2,
		M_setPreFilterCap,
		M_setUniquenessRatio,
	};

public:
	cv::Ptr<cv::StereoSGBM> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class Stitcher : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_composePanorama,
		M_compositingResol,
		M_create,
		M_estimateTransform,
		M_interpolationFlags,
		M_panoConfidenceThresh,
		M_registrationResol,
		M_seamEstimationResol,
		M_setCompositingResol,
		M_setInterpolationFlags,
		M_setPanoConfidenceThresh,
		M_setRegistrationResol,
		M_setSeamEstimationResol,
		M_setWaveCorrection,
		M_stitch,
		M_waveCorrection,
		M_workScale,
	};

public:
	cv::Ptr<cv::Stitcher> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class Subdiv2D : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_edgeDst,
		M_edgeOrg,
		M_findNearest,
		M_getEdge,
		M_getEdgeList,
		M_getLeadingEdgeList,
		M_getTriangleList,
		M_getVertex,
		M_getVoronoiFacetList,
		M_initDelaunay,
		M_insert,
		M_locate,
		M_nextEdge,
		M_rotateEdge,
		M_symEdge,
	};

public:
	cv::Ptr<cv::Subdiv2D> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class TickMeter : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_getAvgTimeMilli,
		M_getAvgTimeSec,
		M_getCounter,
		M_getFPS,
		M_getTimeMicro,
		M_getTimeMilli,
		M_getTimeSec,
		M_getTimeTicks,
		M_reset,
		M_start,
		M_stop,
	};

public:
	cv::Ptr<cv::TickMeter> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class Tonemap : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_getGamma,
		M_process,
		M_setGamma,
	};

public:
	cv::Ptr<cv::Tonemap> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class TonemapDrago : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_getBias,
		M_getSaturation,
		M_setBias,
		M_setSaturation,
	};

public:
	cv::Ptr<cv::TonemapDrago> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class TonemapMantiuk : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_getSaturation,
		M_getScale,
		M_setSaturation,
		M_setScale,
	};

public:
	cv::Ptr<cv::TonemapMantiuk> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class TonemapReinhard : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_getColorAdaptation,
		M_getIntensity,
		M_getLightAdaptation,
		M_setColorAdaptation,
		M_setIntensity,
		M_setLightAdaptation,
	};

public:
	cv::Ptr<cv::TonemapReinhard> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class Tracker : public Object
{
	enum MemBerID {
		M_init,
		M_update,
	};

public:
	cv::Ptr<cv::Tracker> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class TrackerDaSiamRPN : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_create,
		M_getTrackingScore,
	};

public:
	cv::Ptr<cv::TrackerDaSiamRPN> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class TrackerGOTURN : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_create,
	};

public:
	cv::Ptr<cv::TrackerGOTURN> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class TrackerMIL : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_create,
	};

public:
	cv::Ptr<cv::TrackerMIL> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class VariationalRefinement : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_calcUV,
		M_create,
		M_getAlpha,
		M_getDelta,
		M_getFixedPointIterations,
		M_getGamma,
		M_getOmega,
		M_getSorIterations,
		M_setAlpha,
		M_setDelta,
		M_setFixedPointIterations,
		M_setGamma,
		M_setOmega,
		M_setSorIterations,
	};

public:
	cv::Ptr<cv::VariationalRefinement> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class VideoCapture : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_get,
		M_getBackendName,
		M_getExceptionMode,
		M_grab,
		M_isOpened,
		M_open,
		M_read,
		M_release,
		M_retrieve,
		M_set,
		M_setExceptionMode,
	};

public:
	cv::Ptr<cv::VideoCapture> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class VideoWriter : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_fourcc,
		M_get,
		M_getBackendName,
		M_isOpened,
		M_open,
		M_release,
		M_set,
		M_write,
	};

public:
	cv::Ptr<cv::VideoWriter> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class WarperCreator : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
	};

public:
	cv::Ptr<cv::WarperCreator> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class cuda_BufferPool : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_getAllocator,
		M_getBuffer,
	};

public:
	cv::Ptr<cv::cuda::BufferPool> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class cuda_DeviceInfo : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_ECCEnabled,
		M_asyncEngineCount,
		M_canMapHostMemory,
		M_clockRate,
		M_computeMode,
		M_concurrentKernels,
		M_deviceID,
		M_freeMemory,
		M_integrated,
		M_isCompatible,
		M_kernelExecTimeoutEnabled,
		M_l2CacheSize,
		M_majorVersion,
		M_maxGridSize,
		M_maxSurface1D,
		M_maxSurface1DLayered,
		M_maxSurface2D,
		M_maxSurface2DLayered,
		M_maxSurface3D,
		M_maxSurfaceCubemap,
		M_maxSurfaceCubemapLayered,
		M_maxTexture1D,
		M_maxTexture1DLayered,
		M_maxTexture1DLinear,
		M_maxTexture1DMipmap,
		M_maxTexture2D,
		M_maxTexture2DGather,
		M_maxTexture2DLayered,
		M_maxTexture2DLinear,
		M_maxTexture2DMipmap,
		M_maxTexture3D,
		M_maxTextureCubemap,
		M_maxTextureCubemapLayered,
		M_maxThreadsDim,
		M_maxThreadsPerBlock,
		M_maxThreadsPerMultiProcessor,
		M_memPitch,
		M_memoryBusWidth,
		M_memoryClockRate,
		M_minorVersion,
		M_multiProcessorCount,
		M_pciBusID,
		M_pciDeviceID,
		M_pciDomainID,
		M_queryMemory,
		M_regsPerBlock,
		M_sharedMemPerBlock,
		M_surfaceAlignment,
		M_tccDriver,
		M_textureAlignment,
		M_texturePitchAlignment,
		M_totalConstMem,
		M_totalGlobalMem,
		M_totalMemory,
		M_unifiedAddressing,
		M_warpSize,
	};

public:
	cv::Ptr<cv::cuda::DeviceInfo> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class cuda_Event : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_elapsedTime,
		M_queryIfComplete,
		M_record,
		M_waitForCompletion,
	};

public:
	cv::Ptr<cv::cuda::Event> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class cuda_GpuMat : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_adjustROI,
		M_assignTo,
		P_channels,
		M_clone,
		M_col,
		M_colRange,
		M_convertTo,
		M_copyTo,
		M_create,
		M_cudaPtr,
		M_defaultAllocator,
		P_depth,
		M_download,
		P_elemSize,
		P_elemSize1,
		P_empty,
		P_isContinuous,
		M_locateROI,
		M_reshape,
		M_row,
		M_rowRange,
		M_setDefaultAllocator,
		M_setTo,
		P_size,
		P_step1,
		M_swap,
		P_type,
		M_updateContinuityFlag,
		M_upload,
	};

public:
	cv::cuda::GpuMat mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class cuda_GpuMat_Allocator : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
	};

public:
	cv::Ptr<cv::cuda::GpuMat::Allocator> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class cuda_GpuMatND : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
	};

public:
	cv::Ptr<cv::cuda::GpuMatND> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class cuda_HostMem : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		P_channels,
		M_clone,
		M_create,
		M_createMatHeader,
		P_depth,
		P_elemSize,
		P_elemSize1,
		P_empty,
		P_isContinuous,
		M_reshape,
		P_size,
		P_step1,
		M_swap,
		P_type,
	};

public:
	cv::cuda::HostMem mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class cuda_Stream : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_Null,
		M_cudaPtr,
		M_queryIfComplete,
		M_waitEvent,
		M_waitForCompletion,
	};

public:
	cv::Ptr<cv::cuda::Stream> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class cuda_TargetArchs : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_has,
		M_hasBin,
		M_hasEqualOrGreater,
		M_hasEqualOrGreaterBin,
		M_hasEqualOrGreaterPtx,
		M_hasEqualOrLessPtx,
		M_hasPtx,
	};

public:
	cv::Ptr<cv::cuda::TargetArchs> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class detail_AffineBasedEstimator : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
	};

public:
	cv::Ptr<cv::detail::AffineBasedEstimator> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class detail_AffineBestOf2NearestMatcher : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
	};

public:
	cv::Ptr<cv::detail::AffineBestOf2NearestMatcher> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class detail_BestOf2NearestMatcher : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_collectGarbage,
		M_create,
	};

public:
	cv::Ptr<cv::detail::BestOf2NearestMatcher> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class detail_BestOf2NearestRangeMatcher : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
	};

public:
	cv::Ptr<cv::detail::BestOf2NearestRangeMatcher> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class detail_Blender : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_blend,
		M_feed,
		M_prepare,
	};

public:
	cv::Ptr<cv::detail::Blender> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class detail_BlocksChannelsCompensator : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
	};

public:
	cv::Ptr<cv::detail::BlocksChannelsCompensator> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class detail_BlocksCompensator : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_apply,
		M_getBlockSize,
		M_getMatGains,
		M_getNrFeeds,
		M_getNrGainsFilteringIterations,
		M_getSimilarityThreshold,
		M_setBlockSize,
		M_setMatGains,
		M_setNrFeeds,
		M_setNrGainsFilteringIterations,
		M_setSimilarityThreshold,
	};

public:
	cv::Ptr<cv::detail::BlocksCompensator> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class detail_BlocksGainCompensator : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_apply,
		M_getMatGains,
		M_setMatGains,
	};

public:
	cv::Ptr<cv::detail::BlocksGainCompensator> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class detail_BundleAdjusterAffine : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
	};

public:
	cv::Ptr<cv::detail::BundleAdjusterAffine> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class detail_BundleAdjusterAffinePartial : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
	};

public:
	cv::Ptr<cv::detail::BundleAdjusterAffinePartial> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class detail_BundleAdjusterBase : public Object
{
	enum MemBerID {
		M_confThresh,
		M_refinementMask,
		M_setConfThresh,
		M_setRefinementMask,
		M_setTermCriteria,
		M_termCriteria,
	};

public:
	cv::Ptr<cv::detail::BundleAdjusterBase> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class detail_BundleAdjusterRay : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
	};

public:
	cv::Ptr<cv::detail::BundleAdjusterRay> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class detail_BundleAdjusterReproj : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
	};

public:
	cv::Ptr<cv::detail::BundleAdjusterReproj> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class detail_ChannelsCompensator : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_apply,
		M_getMatGains,
		M_getNrFeeds,
		M_getSimilarityThreshold,
		M_setMatGains,
		M_setNrFeeds,
		M_setSimilarityThreshold,
	};

public:
	cv::Ptr<cv::detail::ChannelsCompensator> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class detail_DpSeamFinder : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_setCostFunction,
	};

public:
	cv::Ptr<cv::detail::DpSeamFinder> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class detail_Estimator : public Object
{
	enum MemBerID {
		M_Call,
	};

public:
	cv::Ptr<cv::detail::Estimator> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class detail_ExposureCompensator : public Object
{
	enum MemBerID {
		M_apply,
		M_createDefault,
		M_feed,
		M_getMatGains,
		M_getUpdateGain,
		M_setMatGains,
		M_setUpdateGain,
	};

public:
	cv::Ptr<cv::detail::ExposureCompensator> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class detail_FeatherBlender : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_blend,
		M_createWeightMaps,
		M_feed,
		M_prepare,
		M_setSharpness,
		M_sharpness,
	};

public:
	cv::Ptr<cv::detail::FeatherBlender> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class detail_FeaturesMatcher : public Object
{
	enum MemBerID {
		M_collectGarbage,
		M_isThreadSafe,
		M_Call,
	};

public:
	cv::Ptr<cv::detail::FeaturesMatcher> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class detail_GainCompensator : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_apply,
		M_getMatGains,
		M_getNrFeeds,
		M_getSimilarityThreshold,
		M_setMatGains,
		M_setNrFeeds,
		M_setSimilarityThreshold,
	};

public:
	cv::Ptr<cv::detail::GainCompensator> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class detail_GraphCutSeamFinder : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_find,
	};

public:
	cv::Ptr<cv::detail::GraphCutSeamFinder> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class detail_HomographyBasedEstimator : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
	};

public:
	cv::Ptr<cv::detail::HomographyBasedEstimator> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class detail_MultiBandBlender : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_blend,
		M_feed,
		M_numBands,
		M_prepare,
		M_setNumBands,
	};

public:
	cv::Ptr<cv::detail::MultiBandBlender> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class detail_NoBundleAdjuster : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
	};

public:
	cv::Ptr<cv::detail::NoBundleAdjuster> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class detail_NoExposureCompensator : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_apply,
		M_getMatGains,
		M_setMatGains,
	};

public:
	cv::Ptr<cv::detail::NoExposureCompensator> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class detail_NoSeamFinder : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_find,
	};

public:
	cv::Ptr<cv::detail::NoSeamFinder> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class detail_PairwiseSeamFinder : public Object
{
	enum MemBerID {
		M_find,
	};

public:
	cv::Ptr<cv::detail::PairwiseSeamFinder> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class detail_SeamFinder : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_find,
	};

public:
	cv::Ptr<cv::detail::SeamFinder> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class detail_Timelapser : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_getDst,
		M_initialize,
		M_process,
	};

public:
	cv::Ptr<cv::detail::Timelapser> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class detail_TimelapserCrop : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
	};

public:
	cv::Ptr<cv::detail::TimelapserCrop> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class detail_VoronoiSeamFinder : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_find,
	};

public:
	cv::Ptr<cv::detail::VoronoiSeamFinder> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class dnn_ClassificationModel : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_classify,
	};

public:
	cv::Ptr<cv::dnn::ClassificationModel> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class dnn_DetectionModel : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_detect,
		M_getNmsAcrossClasses,
		M_setNmsAcrossClasses,
	};

public:
	cv::Ptr<cv::dnn::DetectionModel> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class dnn_KeypointsModel : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_estimate,
	};

public:
	cv::Ptr<cv::dnn::KeypointsModel> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class dnn_Layer : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_finalize,
		M_outputNameToIndex,
		M_run,
	};

public:
	cv::Ptr<cv::dnn::Layer> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class dnn_Model : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_predict,
		M_setInputCrop,
		M_setInputMean,
		M_setInputParams,
		M_setInputScale,
		M_setInputSize,
		M_setInputSwapRB,
		M_setPreferableBackend,
		M_setPreferableTarget,
	};

public:
	cv::Ptr<cv::dnn::Model> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class dnn_Net : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_connect,
		M_dump,
		M_dumpToFile,
		M_empty,
		M_enableFusion,
		M_forward,
		M_forwardAsync,
		M_getFLOPS,
		M_getInputDetails,
		M_getLayer,
		M_getLayerId,
		M_getLayerNames,
		M_getLayerTypes,
		M_getLayersCount,
		M_getLayersShapes,
		M_getMemoryConsumption,
		M_getOutputDetails,
		M_getParam,
		M_getPerfProfile,
		M_getUnconnectedOutLayers,
		M_getUnconnectedOutLayersNames,
		M_quantize,
		M_readFromModelOptimizer,
		M_setHalideScheduler,
		M_setInput,
		M_setInputShape,
		M_setInputsNames,
		M_setParam,
		M_setPreferableBackend,
		M_setPreferableTarget,
	};

public:
	cv::Ptr<cv::dnn::Net> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class dnn_SegmentationModel : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_segment,
	};

public:
	cv::Ptr<cv::dnn::SegmentationModel> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class dnn_TextDetectionModel : public Object
{
	enum MemBerID {
		M_detect,
		M_detectTextRectangles,
	};

public:
	cv::Ptr<cv::dnn::TextDetectionModel> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class dnn_TextDetectionModel_DB : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_getBinaryThreshold,
		M_getMaxCandidates,
		M_getPolygonThreshold,
		M_getUnclipRatio,
		M_setBinaryThreshold,
		M_setMaxCandidates,
		M_setPolygonThreshold,
		M_setUnclipRatio,
	};

public:
	cv::Ptr<cv::dnn::TextDetectionModel_DB> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class dnn_TextDetectionModel_EAST : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_getConfidenceThreshold,
		M_getNMSThreshold,
		M_setConfidenceThreshold,
		M_setNMSThreshold,
	};

public:
	cv::Ptr<cv::dnn::TextDetectionModel_EAST> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class dnn_TextRecognitionModel : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_getDecodeType,
		M_getVocabulary,
		M_recognize,
		M_setDecodeOptsCTCPrefixBeamSearch,
		M_setDecodeType,
		M_setVocabulary,
	};

public:
	cv::Ptr<cv::dnn::TextRecognitionModel> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class flann_Index : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_build,
		M_getAlgorithm,
		M_getDistance,
		M_knnSearch,
		M_load,
		M_radiusSearch,
		M_release,
		M_save,
	};

public:
	cv::Ptr<cv::flann::Index> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

#ifdef HAS_GAPI
class gapi_GKernelPackage : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
	};

public:
	cv::Ptr<cv::gapi::GKernelPackage> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class gapi_ie_PyParams : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_cfgBatchSize,
		M_cfgNumRequests,
		M_constInput,
	};

public:
	cv::Ptr<cv::gapi::ie::PyParams> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};
#endif

class ml_ANN_MLP : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_create,
		M_getAnnealCoolingRatio,
		M_getAnnealFinalT,
		M_getAnnealInitialT,
		M_getAnnealItePerStep,
		M_getBackpropMomentumScale,
		M_getBackpropWeightScale,
		M_getLayerSizes,
		M_getRpropDW0,
		M_getRpropDWMax,
		M_getRpropDWMin,
		M_getRpropDWMinus,
		M_getRpropDWPlus,
		M_getTermCriteria,
		M_getTrainMethod,
		M_getWeights,
		M_load,
		M_setActivationFunction,
		M_setAnnealCoolingRatio,
		M_setAnnealFinalT,
		M_setAnnealInitialT,
		M_setAnnealItePerStep,
		M_setBackpropMomentumScale,
		M_setBackpropWeightScale,
		M_setLayerSizes,
		M_setRpropDW0,
		M_setRpropDWMax,
		M_setRpropDWMin,
		M_setRpropDWMinus,
		M_setRpropDWPlus,
		M_setTermCriteria,
		M_setTrainMethod,
	};

public:
	cv::Ptr<cv::ml::ANN_MLP> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class ml_Boost : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_create,
		M_getBoostType,
		M_getWeakCount,
		M_getWeightTrimRate,
		M_load,
		M_setBoostType,
		M_setWeakCount,
		M_setWeightTrimRate,
	};

public:
	cv::Ptr<cv::ml::Boost> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class ml_DTrees : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_create,
		M_getCVFolds,
		M_getMaxCategories,
		M_getMaxDepth,
		M_getMinSampleCount,
		M_getPriors,
		M_getRegressionAccuracy,
		M_getTruncatePrunedTree,
		M_getUse1SERule,
		M_getUseSurrogates,
		M_load,
		M_setCVFolds,
		M_setMaxCategories,
		M_setMaxDepth,
		M_setMinSampleCount,
		M_setPriors,
		M_setRegressionAccuracy,
		M_setTruncatePrunedTree,
		M_setUse1SERule,
		M_setUseSurrogates,
	};

public:
	cv::Ptr<cv::ml::DTrees> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class ml_EM : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_create,
		M_getClustersNumber,
		M_getCovarianceMatrixType,
		M_getCovs,
		M_getMeans,
		M_getTermCriteria,
		M_getWeights,
		M_load,
		M_predict,
		M_predict2,
		M_setClustersNumber,
		M_setCovarianceMatrixType,
		M_setTermCriteria,
		M_trainE,
		M_trainEM,
		M_trainM,
	};

public:
	cv::Ptr<cv::ml::EM> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class ml_KNearest : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_create,
		M_findNearest,
		M_getAlgorithmType,
		M_getDefaultK,
		M_getEmax,
		M_getIsClassifier,
		M_load,
		M_setAlgorithmType,
		M_setDefaultK,
		M_setEmax,
		M_setIsClassifier,
	};

public:
	cv::Ptr<cv::ml::KNearest> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class ml_LogisticRegression : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_create,
		M_getIterations,
		M_getLearningRate,
		M_getMiniBatchSize,
		M_getRegularization,
		M_getTermCriteria,
		M_getTrainMethod,
		M_get_learnt_thetas,
		M_load,
		M_predict,
		M_setIterations,
		M_setLearningRate,
		M_setMiniBatchSize,
		M_setRegularization,
		M_setTermCriteria,
		M_setTrainMethod,
	};

public:
	cv::Ptr<cv::ml::LogisticRegression> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class ml_NormalBayesClassifier : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_create,
		M_load,
		M_predictProb,
	};

public:
	cv::Ptr<cv::ml::NormalBayesClassifier> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class ml_ParamGrid : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_create,
	};

public:
	cv::Ptr<cv::ml::ParamGrid> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class ml_RTrees : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_create,
		M_getActiveVarCount,
		M_getCalculateVarImportance,
		M_getOOBError,
		M_getTermCriteria,
		M_getVarImportance,
		M_getVotes,
		M_load,
		M_setActiveVarCount,
		M_setCalculateVarImportance,
		M_setTermCriteria,
	};

public:
	cv::Ptr<cv::ml::RTrees> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class ml_SVM : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_create,
		M_getC,
		M_getClassWeights,
		M_getCoef0,
		M_getDecisionFunction,
		M_getDefaultGridPtr,
		M_getDegree,
		M_getGamma,
		M_getKernelType,
		M_getNu,
		M_getP,
		M_getSupportVectors,
		M_getTermCriteria,
		M_getType,
		M_getUncompressedSupportVectors,
		M_load,
		M_setC,
		M_setClassWeights,
		M_setCoef0,
		M_setDegree,
		M_setGamma,
		M_setKernel,
		M_setNu,
		M_setP,
		M_setTermCriteria,
		M_setType,
		M_trainAuto,
	};

public:
	cv::Ptr<cv::ml::SVM> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class ml_SVMSGD : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_create,
		M_getInitialStepSize,
		M_getMarginRegularization,
		M_getMarginType,
		M_getShift,
		M_getStepDecreasingPower,
		M_getSvmsgdType,
		M_getTermCriteria,
		M_getWeights,
		M_load,
		M_setInitialStepSize,
		M_setMarginRegularization,
		M_setMarginType,
		M_setOptimalParameters,
		M_setStepDecreasingPower,
		M_setSvmsgdType,
		M_setTermCriteria,
	};

public:
	cv::Ptr<cv::ml::SVMSGD> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class ml_StatModel : public Object
{
	enum MemBerID {
		M_calcError,
		M_empty,
		M_getVarCount,
		M_isClassifier,
		M_isTrained,
		M_predict,
		M_train,
	};

public:
	cv::Ptr<cv::ml::StatModel> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class ml_TrainData : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_create,
		M_getCatCount,
		M_getCatMap,
		M_getCatOfs,
		M_getClassLabels,
		M_getDefaultSubstValues,
		M_getLayout,
		M_getMissing,
		M_getNAllVars,
		M_getNSamples,
		M_getNTestSamples,
		M_getNTrainSamples,
		M_getNVars,
		M_getNames,
		M_getNormCatResponses,
		M_getResponseType,
		M_getResponses,
		M_getSample,
		M_getSampleWeights,
		M_getSamples,
		M_getSubMatrix,
		M_getSubVector,
		M_getTestNormCatResponses,
		M_getTestResponses,
		M_getTestSampleIdx,
		M_getTestSampleWeights,
		M_getTestSamples,
		M_getTrainNormCatResponses,
		M_getTrainResponses,
		M_getTrainSampleIdx,
		M_getTrainSampleWeights,
		M_getTrainSamples,
		M_getValues,
		M_getVarIdx,
		M_getVarSymbolFlags,
		M_getVarType,
		M_setTrainTestSplit,
		M_setTrainTestSplitRatio,
		M_shuffleTrainTest,
	};

public:
	cv::Ptr<cv::ml::TrainData> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class ocl_Device : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_OpenCLVersion,
		M_OpenCL_C_Version,
		M_addressBits,
		M_available,
		M_compilerAvailable,
		M_deviceVersionMajor,
		M_deviceVersionMinor,
		M_doubleFPConfig,
		M_driverVersion,
		M_endianLittle,
		M_errorCorrectionSupport,
		M_executionCapabilities,
		M_extensions,
		M_getDefault,
		M_globalMemCacheLineSize,
		M_globalMemCacheSize,
		M_globalMemCacheType,
		M_globalMemSize,
		M_halfFPConfig,
		M_hostUnifiedMemory,
		M_image2DMaxHeight,
		M_image2DMaxWidth,
		M_image3DMaxDepth,
		M_image3DMaxHeight,
		M_image3DMaxWidth,
		M_imageFromBufferSupport,
		M_imageMaxArraySize,
		M_imageMaxBufferSize,
		M_imageSupport,
		M_intelSubgroupsSupport,
		M_isAMD,
		M_isExtensionSupported,
		M_isIntel,
		M_isNVidia,
		M_linkerAvailable,
		M_localMemSize,
		M_localMemType,
		M_maxClockFrequency,
		M_maxComputeUnits,
		M_maxConstantArgs,
		M_maxConstantBufferSize,
		M_maxMemAllocSize,
		M_maxParameterSize,
		M_maxReadImageArgs,
		M_maxSamplers,
		M_maxWorkGroupSize,
		M_maxWorkItemDims,
		M_maxWriteImageArgs,
		M_memBaseAddrAlign,
		M_name,
		M_nativeVectorWidthChar,
		M_nativeVectorWidthDouble,
		M_nativeVectorWidthFloat,
		M_nativeVectorWidthHalf,
		M_nativeVectorWidthInt,
		M_nativeVectorWidthLong,
		M_nativeVectorWidthShort,
		M_preferredVectorWidthChar,
		M_preferredVectorWidthDouble,
		M_preferredVectorWidthFloat,
		M_preferredVectorWidthHalf,
		M_preferredVectorWidthInt,
		M_preferredVectorWidthLong,
		M_preferredVectorWidthShort,
		M_printfBufferSize,
		M_profilingTimerResolution,
		M_singleFPConfig,
		M_type,
		M_vendorID,
		M_vendorName,
		M_version,
	};

public:
	cv::Ptr<cv::ocl::Device> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class ocl_OpenCLExecutionContext : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
	};

public:
	cv::Ptr<cv::ocl::OpenCLExecutionContext> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class segmentation_IntelligentScissorsMB : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_applyImage,
		M_applyImageFeatures,
		M_buildMap,
		M_getContour,
		M_setEdgeFeatureCannyParameters,
		M_setEdgeFeatureZeroCrossingParameters,
		M_setGradientMagnitudeMaxLimit,
		M_setWeights,
	};

public:
	cv::Ptr<cv::segmentation::IntelligentScissorsMB> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class RNG : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
		M_Call,
		M_next,
		M_uniform,
		M_fill,
		M_gaussian,
	};
public:
	cv::Ptr<cv::RNG> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

#ifdef HAS_GAPI
class GOpaque_Size : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
	};
public:
	cv::GOpaque<cv::Size> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class GOpaque_Rect : public Object
{
	enum MemBerID {
		M___New,
		M___Delete,
	};
public:
	cv::GOpaque<cv::Rect> mC;
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};
#endif