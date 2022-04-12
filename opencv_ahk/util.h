#pragma once
#include <ahkapi.h>
#include "cv_ahk.h"
#include <opencv2/core.hpp>
#include <opencv2/features2d.hpp>


ResultType TokenToVal(ExprTokenType& token, char& val, char ignore = false);
ResultType TokenToVal(ExprTokenType& token, int& val, char ignore = false);
ResultType TokenToVal(ExprTokenType& token, __int64& val, char ignore = false);
ResultType TokenToVal(ExprTokenType& token, double& val, char ignore = false);
ResultType TokenToVal(ExprTokenType& token, float& val, char ignore = false);
ResultType TokenToVal(ExprTokenType& token, VarRef*& val, char ignore = false);
ResultType TokenToVal(ExprTokenType& token, cv::String& val, char ignore = false);
ResultType TokenToVal(ExprTokenType& token, cv::Mat& val, char ignore = false);
ResultType TokenToVal(ExprTokenType& token, cv::UMat& val, char ignore = false);
ResultType TokenToVal(ExprTokenType& token, cv::_InputArray& val, char ignore = false);
ResultType TokenToVal(ExprTokenType& token, cv::_OutputArray& val, char ignore = false);
ResultType TokenToVal(ExprTokenType& token, cv::Scalar& val, char ignore = false);
ResultType TokenToVal(ExprTokenType& token, cv::Rect& val, char ignore = false);
ResultType TokenToVal(ExprTokenType& token, cv::Rect2d& val, char ignore = false);
ResultType TokenToVal(ExprTokenType& token, cv::Point& val, char ignore = false);
ResultType TokenToVal(ExprTokenType& token, cv::Point2f& val, char ignore = false);
ResultType TokenToVal(ExprTokenType& token, cv::Point2d& val, char ignore = false);
ResultType TokenToVal(ExprTokenType& token, cv::RotatedRect& val, char ignore = false);
ResultType TokenToVal(ExprTokenType& token, cv::Range& val, char ignore = false);
ResultType TokenToVal(ExprTokenType& token, cv::Size& val, char ignore = false);
ResultType TokenToVal(ExprTokenType& token, cv::Size2f& val, char ignore = false);
ResultType TokenToVal(ExprTokenType& token, cv::UsacParams& val, char ignore = false);
ResultType TokenToVal(ExprTokenType& token, cv::QRCodeEncoder::Params& val, char ignore = false);
ResultType TokenToVal(ExprTokenType& token, cv::SimpleBlobDetector::Params& val, char ignore = false);
ResultType TokenToVal(ExprTokenType& token, cv::detail::CameraParams& val, char ignore = false);
ResultType TokenToVal(ExprTokenType& token, cv::detail::ImageFeatures& val, char ignore = false);
ResultType TokenToVal(ExprTokenType& token, cv::detail::MatchesInfo& val, char ignore = false);
ResultType TokenToVal(ExprTokenType& token, std::vector<cv::detail::MatchesInfo>& val, char ignore = false);
ResultType TokenToVal(ExprTokenType& token, std::vector<cv::detail::CameraParams>& val, char ignore = false);
ResultType TokenToVal(ExprTokenType& token, std::vector<cv::detail::ImageFeatures>& val, char ignore = false);
ResultType TokenToVal(ExprTokenType& token, cv::gapi::GNetParam& val, char ignore);
ResultType TokenToVal(ExprTokenType& token, cv::TermCriteria& val, char ignore = false);
ResultType TokenToVal(ExprTokenType& token, cv::CirclesGridFinderParameters& val, char ignore = false);
ResultType TokenToVal(ExprTokenType& token, cv::TrackerMIL::Params& val, char ignore = false);
ResultType TokenToVal(ExprTokenType& token, cv::TrackerGOTURN::Params& val, char ignore = false);
ResultType TokenToVal(ExprTokenType& token, cv::TrackerDaSiamRPN::Params& val, char ignore = false);
ResultType TokenToVal(ExprTokenType& token, cv::dnn::DictValue& val, char ignore = false);
ResultType TokenToVal(ExprTokenType& token, std::vector<uchar>& val, char ignore = false);
ResultType TokenToVal(ExprTokenType& token, std::vector<std::vector<char>>& val, char ignore = false);
ResultType TokenToVal(ExprTokenType& token, std::vector<int>& val, char ignore = false);
ResultType TokenToVal(ExprTokenType& token, std::vector<std::vector<int>>& val, char ignore = false);
ResultType TokenToVal(ExprTokenType& token, std::vector<std::vector<std::vector<int>>>& val, char ignore = false);
ResultType TokenToVal(ExprTokenType& token, std::vector<float>& val, char ignore = false);
ResultType TokenToVal(ExprTokenType& token, std::vector<double>& val, char ignore = false);
ResultType TokenToVal(ExprTokenType& token, std::vector<cv::String>& val, char ignore = false);
ResultType TokenToVal(ExprTokenType& token, std::vector<cv::Size>& val, char ignore = false);
ResultType TokenToVal(ExprTokenType& token, std::vector<cv::Rect>& val, char ignore = false);
ResultType TokenToVal(ExprTokenType& token, std::vector<cv::Rect2d>& val, char ignore = false);
ResultType TokenToVal(ExprTokenType& token, std::vector<cv::RotatedRect>& val, char ignore = false);
ResultType TokenToVal(ExprTokenType& token, std::vector<cv::Point>& val, char ignore = false);
ResultType TokenToVal(ExprTokenType& token, std::vector<cv::Point2f>& val, char ignore = false);
ResultType TokenToVal(ExprTokenType& token, std::vector<cv::Mat>& val, char ignore = false);
ResultType TokenToVal(ExprTokenType& token, std::vector<cv::UMat>& val, char ignore = false);
ResultType TokenToVal(ExprTokenType& token, std::vector<cv::KeyPoint>& val, char ignore = false);
ResultType TokenToVal(ExprTokenType& token, std::vector<cv::DMatch>& val, char ignore = false);
ResultType TokenToVal(ExprTokenType& token, std::vector<std::vector<cv::DMatch>>& val, char ignore = false);
ResultType TokenToVal(ExprTokenType& token, std::vector<cv::gapi::GNetParam>& val, char ignore = false);
ResultType TokenToVal(ExprTokenType& token, std::vector<std::vector<cv::KeyPoint>>& val, char ignore = false);

ResultType TokenToVal(ExprTokenType& token, cv::Ptr<cv::ml::ParamGrid>& val, char ignore = false);
ResultType TokenToVal(ExprTokenType& token, cv::Ptr<cv::ml::TrainData>& val, char ignore = false);
ResultType TokenToVal(ExprTokenType& token, cv::Ptr<cv::cuda::GpuMat::Allocator>& val, char ignore = false);
ResultType TokenToVal(ExprTokenType& token, cv::Ptr<cv::Feature2D>& val, char ignore = false);
ResultType TokenToVal(ExprTokenType& token, cv::Ptr<cv::DescriptorMatcher>& val, char ignore = false);
ResultType TokenToVal(ExprTokenType& token, cv::FileNode*& val, char ignore = false);
ResultType TokenToVal(ExprTokenType& token, cv::cuda::HostMem*& val, char ignore = false);
ResultType TokenToVal(ExprTokenType& token, cv::Ptr<cv::FileStorage>& val, char ignore = false);
ResultType TokenToVal(ExprTokenType& token, cv::GMat*& val, char ignore = false);
ResultType TokenToVal(ExprTokenType& token, cv::KeyPoint*& val, char ignore = false);
ResultType TokenToVal(ExprTokenType& token, cv::GScalar*& val, char ignore = false);
ResultType TokenToVal(ExprTokenType& token, cv::Moments*& val, char ignore = false);
ResultType TokenToVal(ExprTokenType& token, cv::RNG*& val, char ignore = false);
ResultType TokenToVal(ExprTokenType& token, cv::dnn::Net*& val, char ignore = false);
ResultType TokenToVal(ExprTokenType& token, cv::cuda::Event*& val, char ignore = false);
ResultType TokenToVal(ExprTokenType& token, cv::cuda::Stream*& val, char ignore = false);
ResultType TokenToVal(ExprTokenType& token, cv::cuda::GpuMat*& val, char ignore = false);
ResultType TokenToVal(ExprTokenType& token, cv::cuda::GpuMat::Allocator*& val, char ignore = false);

ResultType TokenToVal(ExprTokenType& token, cv::GOpaque<cv::Rect>*& val, char ignore = false);
ResultType TokenToVal(ExprTokenType& token, cv::GOpaque<cv::Size>*& val, char ignore = false);

ResultType TokenToObject(ExprTokenType& token, IObject*& val, LPTSTR type = _T("Object"));
ResultType ObjectGetPtrSize(Object* obj, void*& ptr, size_t* size = nullptr, char ignore = false);
ExprTokenType VarRefToToken(VarRef* var);
__int64 TokenToInt64(ExprTokenType& token);
double TokenToDouble(ExprTokenType& token);
IObject* TokenToObject(ExprTokenType& token);
VarRef* TokenToVarRef(ExprTokenType& token);
int MatchParamTypes(ExprTokenType* aParam[], int aParamCount, char* def);

ResultType ArrayToBin(Array* arr, char* pval, char* def, char ignore);
Array* BinToArray(char* pval, char* def);

template<typename T>
bool ArrayToCArr(Array* obj, T arr[], int n) {
	for (int i = 0; i < n; i++) {
		if (i >= obj->mLength) {
			arr[i] = 0;
			continue;
		}
		auto& it = obj->mItem[i];
		if (it.symbol == SYM_INTEGER)
			arr[i] = (T)it.n_int64;
		else if (it.symbol == SYM_FLOAT)
			arr[i] = (T)it.n_double;
		else if (it.symbol == SYM_MISSING)
			arr[i] = 0;
		else
			return false;
	}
	return true;
}

template<typename T>
ResultType TokenToCArr(ExprTokenType& token, T arr[], int n, char ignore = false) {
	IObject* obj;
	TokenToObject(token, obj, nullptr);
	if (!obj || !dynamic_cast<Array*>(obj))
		return token.symbol == SYM_MISSING ? CONDITION_TRUE : g_ahkapi->TypeError(_T("Array"), token);
	if (!ArrayToCArr((Array*)obj, arr, n) && !ignore)
		return g_ahkapi->Error(_T("param is not an array of numbers"));
	return CONDITION_TRUE;
}

template<typename T>
ResultType TokenToVector(ExprTokenType& token, std::vector<T>& val, char ignore = false) {
	IObject* obj;
	TokenToObject(token, obj, nullptr);
	if (!obj || !dynamic_cast<Array*>(obj))
		return token.symbol == SYM_MISSING ? CONDITION_TRUE : g_ahkapi->TypeError(_T("Array"), token);
	if (auto l = ((Array*)obj)->mLength) {
		val.resize(l);
		if (!ArrayToCArr((Array*)obj, (T*)val.data(), (int)l) && !ignore)
			return g_ahkapi->Error(_T("param is not an array of numbers"));
	}
	return CONDITION_TRUE;
}

template<typename T>
ResultType TokenToVector_vector(ExprTokenType& token, std::vector<std::vector<T>>& val, char ignore) {
	IObject* obj;
	TokenToObject(token, obj, nullptr);
	if (!obj || !dynamic_cast<Array*>(obj))
		return token.symbol == SYM_MISSING ? CONDITION_TRUE : g_ahkapi->TypeError(_T("Array"), token);
	auto arr = (Array*)obj;
	if (auto l = arr->mLength) {
		val.resize(l);
		for (UINT i = 0; i < l; i++) {
			auto& it = val[i];
			auto& item = arr->mItem[i];
			if (item.symbol == SYM_MISSING)
				continue;
			if (item.symbol != SYM_OBJECT || !dynamic_cast<Array*>(item.object)) {
				ExprTokenType tk;
				tk.symbol = item.symbol, tk.value_int64 = item.n_int64;
				return g_ahkapi->TypeError(_T("Array"), tk);
			}
			auto l = ((Array*)item.object)->mLength;
			it.resize(l);
			if (!ArrayToCArr((Array*)obj, (T*)it.data(), (int)l) && !ignore)
				return g_ahkapi->Error(_T("param is not an array of array of numbers"));
		}
	}
	return CONDITION_TRUE;
}

inline void ValToResult(int val, ResultToken& result);
void ValToResult(__int64 val, ResultToken& result);
inline void ValToResult(float val, ResultToken& result);
inline void ValToResult(double val, ResultToken& result);
void ValToResult(cv::String& val, ResultToken& result);
void ValToResult(cv::Size& val, ResultToken& result);
void ValToResult(cv::Size2f& val, ResultToken& result);
void ValToResult(std::vector<cv::Size>& val, ResultToken& result);
void ValToResult(std::vector<cv::Rect>& val, ResultToken& result);

void ValToResult(std::vector<uchar>& val, ResultToken& result);
void ValToResult(std::vector<int>& val, ResultToken& result);
void ValToResult(std::vector<std::vector<int>>& val, ResultToken& result);
void ValToResult(std::vector<std::vector<std::vector<int>>>& val, ResultToken& result);
void ValToResult(std::vector<float>& val, ResultToken& result);
void ValToResult(std::vector<double>& val, ResultToken& result);
void ValToResult(cv::_OutputArray& val, ResultToken& result);
void ValToResult(cv::Rect& val, ResultToken& result);
void ValToResult(cv::Point& val, ResultToken& result);
void ValToResult(cv::Point2f& val, ResultToken& result);
void ValToResult(cv::Point2d& val, ResultToken& result);
void ValToResult(cv::Point2f* val, ResultToken& result);
void ValToResult(cv::Mat& val, ResultToken& result);
void ValToResult(cv::FileNode& val, ResultToken& result);
void ValToResult(cv::KeyPoint& val, ResultToken& result);
void ValToResult(cv::detail::MatchesInfo& val, ResultToken& result);
void ValToResult(std::vector<cv::detail::MatchesInfo>& val, ResultToken& result);
void ValToResult(cv::detail::CameraParams& val, ResultToken& result);
void ValToResult(std::vector<cv::detail::CameraParams>& val, ResultToken& result);
void ValToResult(cv::TermCriteria& val, ResultToken& result);
void ValToResult(cv::DMatch& val, ResultToken& result);
void ValToResult(std::vector<cv::DMatch>& val, ResultToken& result);
void ValToResult(std::vector<std::vector<cv::DMatch>>& val, ResultToken& result);
void ValToResult(cv::Scalar& val, ResultToken& result);
void ValToResult(cv::Vec2i& val, ResultToken& result);
void ValToResult(cv::Vec2d& val, ResultToken& result);
void ValToResult(cv::Vec3d& val, ResultToken& result);
void ValToResult(cv::Vec3i& val, ResultToken& result);
void ValToResult(cv::Vec4f& val, ResultToken& result);
void ValToResult(std::vector<cv::Vec4f>& val, ResultToken& result);
void ValToResult(cv::Vec6f& val, ResultToken& result);
void ValToResult(std::vector<cv::Vec6f>& val, ResultToken& result);
void ValToResult(std::vector<cv::Point>& val, ResultToken& result);
void ValToResult(std::vector<std::vector<cv::Point>>& val, ResultToken& result);
void ValToResult(std::vector<cv::KeyPoint>& val, ResultToken& result);
void ValToResult(std::vector<std::vector<cv::KeyPoint>>& val, ResultToken& result);
void ValToResult(std::vector<cv::Mat>& val, ResultToken& result);
void ValToResult(std::vector<cv::UMat>& val, ResultToken& result);
void ValToResult(std::vector<std::vector<cv::Mat>>& val, ResultToken& result);
void ValToResult(std::vector<cv::Point2f>& val, ResultToken& result);
void ValToResult(std::vector<cv::String>& val, ResultToken& result);
void ValToResult(std::vector<std::vector<cv::Point2f>>& val, ResultToken& result);
void ValToResult(cv::RotatedRect& val, ResultToken& result);
void ValToResult(std::vector<cv::RotatedRect>& val, ResultToken& result);
void ValToResult(cv::detail::ImageFeatures& val, ResultToken& result);
void ValToResult(std::vector<cv::detail::ImageFeatures>& val, ResultToken& result);
void ValToResult(cv::gapi::core::GMat2& val, ResultToken& result);
void ValToResult(cv::gapi::core::GMat3& val, ResultToken& result);
void ValToResult(cv::gapi::core::GMatScalar& val, ResultToken& result);

#define MatchTypes(types) MatchParamTypes(aParam, aParamCount, types)
#define _o_return_result return (void)(aResultToken.result = __result)
#define ParamIndexToVal(i, val, ...) (__result = TokenToVal(*aParam[i], val, __VA_ARGS__)) != CONDITION_TRUE

