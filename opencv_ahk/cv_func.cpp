#include "pch.h"
#include "util.h"
#include "cv_mat.h"
#include "cv_class.h"
#include "cv_func.h"
#include <opencv2/core/bindings_utils.hpp>
#include <opencv2/core/parallel/parallel_backend.hpp>
#include <opencv2/dnn/dnn.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/gapi/imgproc.hpp>
#include <opencv2/gapi/infer.hpp>
#include <opencv2/gapi/infer/parsers.hpp>
#include <opencv2/imgproc/bindings.hpp>
#include <opencv2/stitching/detail/autocalib.hpp>
#include <opencv2/videoio/registry.hpp>
#include <opencv2/gapi/streaming/cap.hpp>
#include <opencv2/gapi/render.hpp>
#include <opencv2/gapi/render/render_types.hpp>
#include <opencv2/gapi/ocl/core.hpp>
#include <opencv2/gapi/cpu/core.hpp>
#include <opencv2/gapi/fluid/core.hpp>


BIF_DECL(CV_FUNC) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aResultToken.func->mFID) {
	case FID_CamShift: {
		cv::_InputArray probImage;
		cv::Rect window;
		cv::TermCriteria criteria;
		if (ParamIndexToVal(0, probImage))
			_o_return_result;
		VarRef* var_window = nullptr;
		if (ParamIndexToVal(1, var_window))
			_o_return_result;
		if (TokenToVal(VarRefToToken(var_window), window) != CONDITION_TRUE)
			_o_return_result;
		if (ParamIndexToVal(2, criteria))
			_o_return_result;
		auto __retval = cv::CamShift(probImage, window, criteria);
		ValToResult(window, aResultToken);
		g_ahkapi->VarAssign(var_window, aResultToken);
		g_ahkapi->ResultTokenFree(aResultToken);
		return ValToResult(__retval, aResultToken);
	}
	case FID_Canny: {
		if (!MatchTypes("ooffi?i")) {
			bool L2gradient = false;
			cv::_InputArray image;
			cv::_OutputArray edges;
			double threshold1, threshold2;
			int apertureSize = 3;
			if (ParamIndexToVal(0, image))
				_o_return_result;
			if (ParamIndexToVal(1, edges))
				_o_return_result;
			if (ParamIndexToVal(2, threshold1))
				_o_return_result;
			if (ParamIndexToVal(3, threshold2))
				_o_return_result;
			if (aParamCount > 4)
				TokenToVal(*aParam[4], apertureSize, true);
			if (aParamCount > 5)
				TokenToVal(*aParam[5], (char&)L2gradient, true);
			cv::Canny(image, edges, threshold1, threshold2, apertureSize, L2gradient);
			return;
		}
		else if (!MatchTypes("oooffi?")) {
			bool L2gradient = false;
			cv::_InputArray dx, dy;
			cv::_OutputArray edges;
			double threshold1, threshold2;
			if (ParamIndexToVal(0, dx))
				_o_return_result;
			if (ParamIndexToVal(1, dy))
				_o_return_result;
			if (ParamIndexToVal(2, edges))
				_o_return_result;
			if (ParamIndexToVal(3, threshold1))
				_o_return_result;
			if (ParamIndexToVal(4, threshold2))
				_o_return_result;
			if (aParamCount > 5)
				TokenToVal(*aParam[5], (char&)L2gradient, true);
			cv::Canny(dx, dy, edges, threshold1, threshold2, L2gradient);
			return;
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case FID_GaussianBlur: {
		cv::_InputArray src;
		cv::_OutputArray dst;
		cv::Size ksize;
		double sigmaX, sigmaY = 0;
		int borderType = cv::BORDER_DEFAULT;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, dst))
			_o_return_result;
		if (ParamIndexToVal(2, ksize))
			_o_return_result;
		if (ParamIndexToVal(3, sigmaX))
			_o_return_result;
		if (aParamCount > 4)
			TokenToVal(*aParam[4], sigmaY, true);
		if (aParamCount > 5)
			TokenToVal(*aParam[5], borderType, true);
		cv::GaussianBlur(src, dst, ksize, sigmaX, sigmaY, borderType);
		return;
	}
	case FID_HoughCircles: {
		cv::_InputArray image;
		cv::_OutputArray circles;
		double dp, minDist, param1 = 100, param2 = 100;
		int method, minRadius = 0, maxRadius = 0;
		if (ParamIndexToVal(0, image))
			_o_return_result;
		if (ParamIndexToVal(1, circles))
			_o_return_result;
		if (ParamIndexToVal(2, method))
			_o_return_result;
		if (ParamIndexToVal(3, dp))
			_o_return_result;
		if (ParamIndexToVal(4, minDist))
			_o_return_result;
		if (aParamCount > 5)
			TokenToVal(*aParam[5], param1, true);
		if (aParamCount > 6)
			TokenToVal(*aParam[6], param2, true);
		if (aParamCount > 7)
			TokenToVal(*aParam[7], minRadius, true);
		if (aParamCount > 8)
			TokenToVal(*aParam[8], maxRadius, true);
		cv::HoughCircles(image, circles, method, dp, minDist, param1, param2, minRadius, maxRadius);
		return;
	}
	case FID_HoughLines: {
		cv::_InputArray image;
		cv::_OutputArray lines;
		double rho, theta, srn = 0, stn = 0, min_theta = 0, max_theta = CV_PI;
		int threshold;
		if (ParamIndexToVal(0, image))
			_o_return_result;
		if (ParamIndexToVal(1, lines))
			_o_return_result;
		if (ParamIndexToVal(2, rho))
			_o_return_result;
		if (ParamIndexToVal(3, theta))
			_o_return_result;
		if (ParamIndexToVal(4, threshold))
			_o_return_result;
		if (aParamCount > 5)
			TokenToVal(*aParam[5], srn, true);
		if (aParamCount > 6)
			TokenToVal(*aParam[6], stn, true);
		if (aParamCount > 7)
			TokenToVal(*aParam[7], min_theta, true);
		if (aParamCount > 8)
			TokenToVal(*aParam[8], max_theta, true);
		cv::HoughLines(image, lines, rho, theta, threshold, srn, stn, min_theta, max_theta);
		return;
	}
	case FID_HoughLinesP: {
		cv::_InputArray image;
		cv::_OutputArray lines;
		double rho, theta, minLineLength = 0, maxLineGap = 0;
		int threshold;
		if (ParamIndexToVal(0, image))
			_o_return_result;
		if (ParamIndexToVal(1, lines))
			_o_return_result;
		if (ParamIndexToVal(2, rho))
			_o_return_result;
		if (ParamIndexToVal(3, theta))
			_o_return_result;
		if (ParamIndexToVal(4, threshold))
			_o_return_result;
		if (aParamCount > 5)
			TokenToVal(*aParam[5], minLineLength, true);
		if (aParamCount > 6)
			TokenToVal(*aParam[6], maxLineGap, true);
		cv::HoughLinesP(image, lines, rho, theta, threshold, minLineLength, maxLineGap);
		return;
	}
	case FID_HoughLinesPointSet: {
		cv::_InputArray point;
		cv::_OutputArray lines;
		double min_rho, max_rho, rho_step, min_theta, max_theta, theta_step;
		int lines_max, threshold;
		if (ParamIndexToVal(0, point))
			_o_return_result;
		if (ParamIndexToVal(1, lines))
			_o_return_result;
		if (ParamIndexToVal(2, lines_max))
			_o_return_result;
		if (ParamIndexToVal(3, threshold))
			_o_return_result;
		if (ParamIndexToVal(4, min_rho))
			_o_return_result;
		if (ParamIndexToVal(5, max_rho))
			_o_return_result;
		if (ParamIndexToVal(6, rho_step))
			_o_return_result;
		if (ParamIndexToVal(7, min_theta))
			_o_return_result;
		if (ParamIndexToVal(8, max_theta))
			_o_return_result;
		if (ParamIndexToVal(9, theta_step))
			_o_return_result;
		cv::HoughLinesPointSet(point, lines, lines_max, threshold, min_rho, max_rho, rho_step, min_theta, max_theta, theta_step);
		return;
	}
	case FID_HoughLinesWithAccumulator: {
		cv::_InputArray image;
		cv::_OutputArray lines;
		double rho, theta, srn = 0, stn = 0, min_theta = 0, max_theta = CV_PI;
		int threshold;
		if (ParamIndexToVal(0, image))
			_o_return_result;
		if (ParamIndexToVal(1, lines))
			_o_return_result;
		if (ParamIndexToVal(2, rho))
			_o_return_result;
		if (ParamIndexToVal(3, theta))
			_o_return_result;
		if (ParamIndexToVal(4, threshold))
			_o_return_result;
		if (aParamCount > 5)
			TokenToVal(*aParam[5], srn, true);
		if (aParamCount > 6)
			TokenToVal(*aParam[6], stn, true);
		if (aParamCount > 7)
			TokenToVal(*aParam[7], min_theta, true);
		if (aParamCount > 8)
			TokenToVal(*aParam[8], max_theta, true);
		cv::HoughLinesWithAccumulator(image, lines, rho, theta, threshold, srn, stn, min_theta, max_theta);
		return;
	}
	case FID_HuMoments: {
		cv::Moments* m;
		cv::_OutputArray hu;
		if (ParamIndexToVal(0, m))
			_o_return_result;
		if (ParamIndexToVal(1, hu))
			_o_return_result;
		cv::HuMoments(*m, hu);
		return;
	}
	case FID_LUT: {
		cv::_InputArray src, lut;
		cv::_OutputArray dst;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, lut))
			_o_return_result;
		if (ParamIndexToVal(2, dst))
			_o_return_result;
		cv::LUT(src, lut, dst);
		return;
	}
	case FID_Laplacian: {
		cv::_InputArray src;
		cv::_OutputArray dst;
		double scale = 1, delta = 0;
		int ddepth, ksize = 1, borderType = cv::BORDER_DEFAULT;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, dst))
			_o_return_result;
		if (ParamIndexToVal(2, ddepth))
			_o_return_result;
		if (aParamCount > 3)
			TokenToVal(*aParam[3], ksize, true);
		if (aParamCount > 4)
			TokenToVal(*aParam[4], scale, true);
		if (aParamCount > 5)
			TokenToVal(*aParam[5], delta, true);
		if (aParamCount > 6)
			TokenToVal(*aParam[6], borderType, true);
		cv::Laplacian(src, dst, ddepth, ksize, scale, delta, borderType);
		return;
	}
	case FID_Mahalanobis: {
		cv::_InputArray v1, v2, icovar;
		if (ParamIndexToVal(0, v1))
			_o_return_result;
		if (ParamIndexToVal(1, v2))
			_o_return_result;
		if (ParamIndexToVal(2, icovar))
			_o_return_result;
		auto __retval = cv::Mahalanobis(v1, v2, icovar);
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_PCABackProject: {
		cv::_InputArray data, mean, eigenvectors;
		cv::_OutputArray result;
		if (ParamIndexToVal(0, data))
			_o_return_result;
		if (ParamIndexToVal(1, mean))
			_o_return_result;
		if (ParamIndexToVal(2, eigenvectors))
			_o_return_result;
		if (ParamIndexToVal(3, result))
			_o_return_result;
		cv::PCABackProject(data, mean, eigenvectors, result);
		return;
	}
	case FID_PCACompute: {
		if (!MatchTypes("oooi?")) {
			cv::_InputArray data;
			cv::_InputOutputArray mean;
			cv::_OutputArray eigenvectors;
			int maxComponents = 0;
			if (ParamIndexToVal(0, data))
				_o_return_result;
			if (ParamIndexToVal(1, mean))
				_o_return_result;
			if (ParamIndexToVal(2, eigenvectors))
				_o_return_result;
			if (aParamCount > 3)
				TokenToVal(*aParam[3], maxComponents, true);
			cv::PCACompute(data, mean, eigenvectors, maxComponents);
			return;
		}
		else if (!MatchTypes("ooooi?")) {
			cv::_InputArray data;
			cv::_InputOutputArray mean;
			cv::_OutputArray eigenvectors, eigenvalues;
			int maxComponents = 0;
			if (ParamIndexToVal(0, data))
				_o_return_result;
			if (ParamIndexToVal(1, mean))
				_o_return_result;
			if (ParamIndexToVal(2, eigenvectors))
				_o_return_result;
			if (ParamIndexToVal(3, eigenvalues))
				_o_return_result;
			if (aParamCount > 4)
				TokenToVal(*aParam[4], maxComponents, true);
			cv::PCACompute(data, mean, eigenvectors, eigenvalues, maxComponents);
			return;
		}
		else if (!MatchTypes("ooof")) {
			cv::_InputArray data;
			cv::_InputOutputArray mean;
			cv::_OutputArray eigenvectors;
			double retainedVariance;
			if (ParamIndexToVal(0, data))
				_o_return_result;
			if (ParamIndexToVal(1, mean))
				_o_return_result;
			if (ParamIndexToVal(2, eigenvectors))
				_o_return_result;
			if (ParamIndexToVal(3, retainedVariance))
				_o_return_result;
			cv::PCACompute(data, mean, eigenvectors, retainedVariance);
			return;
		}
		else if (!MatchTypes("oooof")) {
			cv::_InputArray data;
			cv::_InputOutputArray mean;
			cv::_OutputArray eigenvectors, eigenvalues;
			double retainedVariance;
			if (ParamIndexToVal(0, data))
				_o_return_result;
			if (ParamIndexToVal(1, mean))
				_o_return_result;
			if (ParamIndexToVal(2, eigenvectors))
				_o_return_result;
			if (ParamIndexToVal(3, eigenvalues))
				_o_return_result;
			if (ParamIndexToVal(4, retainedVariance))
				_o_return_result;
			cv::PCACompute(data, mean, eigenvectors, eigenvalues, retainedVariance);
			return;
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case FID_PCAProject: {
		cv::_InputArray data, mean, eigenvectors;
		cv::_OutputArray result;
		if (ParamIndexToVal(0, data))
			_o_return_result;
		if (ParamIndexToVal(1, mean))
			_o_return_result;
		if (ParamIndexToVal(2, eigenvectors))
			_o_return_result;
		if (ParamIndexToVal(3, result))
			_o_return_result;
		cv::PCAProject(data, mean, eigenvectors, result);
		return;
	}
	case FID_PSNR: {
		cv::_InputArray src1, src2;
		double R = 255.;
		if (ParamIndexToVal(0, src1))
			_o_return_result;
		if (ParamIndexToVal(1, src2))
			_o_return_result;
		if (aParamCount > 2)
			TokenToVal(*aParam[2], R, true);
		auto __retval = cv::PSNR(src1, src2, R);
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_RQDecomp3x3: {
		cv::_InputArray src;
		cv::_OutputArray mtxR, mtxQ, Qx = cv::noArray(), Qy = cv::noArray(), Qz = cv::noArray();
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, mtxR))
			_o_return_result;
		if (ParamIndexToVal(2, mtxQ))
			_o_return_result;
		if (aParamCount > 3)
			TokenToVal(*aParam[3], Qx, true);
		if (aParamCount > 4)
			TokenToVal(*aParam[4], Qy, true);
		if (aParamCount > 5)
			TokenToVal(*aParam[5], Qz, true);
		auto __retval = cv::RQDecomp3x3(src, mtxR, mtxQ, Qx, Qy, Qz);
		return ValToResult(__retval, aResultToken);
	}
	case FID_Rodrigues: {
		cv::_InputArray src;
		cv::_OutputArray dst, jacobian = cv::noArray();
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, dst))
			_o_return_result;
		if (aParamCount > 2)
			TokenToVal(*aParam[2], jacobian, true);
		cv::Rodrigues(src, dst, jacobian);
		return;
	}
	case FID_SVBackSubst: {
		cv::_InputArray w, u, vt, rhs;
		cv::_OutputArray dst;
		if (ParamIndexToVal(0, w))
			_o_return_result;
		if (ParamIndexToVal(1, u))
			_o_return_result;
		if (ParamIndexToVal(2, vt))
			_o_return_result;
		if (ParamIndexToVal(3, rhs))
			_o_return_result;
		if (ParamIndexToVal(4, dst))
			_o_return_result;
		cv::SVBackSubst(w, u, vt, rhs, dst);
		return;
	}
	case FID_SVDecomp: {
		cv::_InputArray src;
		cv::_OutputArray w, u, vt;
		int flags = 0;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, w))
			_o_return_result;
		if (ParamIndexToVal(2, u))
			_o_return_result;
		if (ParamIndexToVal(3, vt))
			_o_return_result;
		if (aParamCount > 4)
			TokenToVal(*aParam[4], flags, true);
		cv::SVDecomp(src, w, u, vt, flags);
		return;
	}
	case FID_Scharr: {
		cv::_InputArray src;
		cv::_OutputArray dst;
		double scale = 1, delta = 0;
		int ddepth, dx, dy, borderType = cv::BORDER_DEFAULT;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, dst))
			_o_return_result;
		if (ParamIndexToVal(2, ddepth))
			_o_return_result;
		if (ParamIndexToVal(3, dx))
			_o_return_result;
		if (ParamIndexToVal(4, dy))
			_o_return_result;
		if (aParamCount > 5)
			TokenToVal(*aParam[5], scale, true);
		if (aParamCount > 6)
			TokenToVal(*aParam[6], delta, true);
		if (aParamCount > 7)
			TokenToVal(*aParam[7], borderType, true);
		cv::Scharr(src, dst, ddepth, dx, dy, scale, delta, borderType);
		return;
	}
	case FID_Sobel: {
		cv::_InputArray src;
		cv::_OutputArray dst;
		double scale = 1, delta = 0;
		int ddepth, dx, dy, ksize = 3, borderType = cv::BORDER_DEFAULT;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, dst))
			_o_return_result;
		if (ParamIndexToVal(2, ddepth))
			_o_return_result;
		if (ParamIndexToVal(3, dx))
			_o_return_result;
		if (ParamIndexToVal(4, dy))
			_o_return_result;
		if (aParamCount > 5)
			TokenToVal(*aParam[5], ksize, true);
		if (aParamCount > 6)
			TokenToVal(*aParam[6], scale, true);
		if (aParamCount > 7)
			TokenToVal(*aParam[7], delta, true);
		if (aParamCount > 8)
			TokenToVal(*aParam[8], borderType, true);
		cv::Sobel(src, dst, ddepth, dx, dy, ksize, scale, delta, borderType);
		return;
	}
	case FID_absdiff: {
		cv::_InputArray src1, src2;
		cv::_OutputArray dst;
		if (ParamIndexToVal(0, src1))
			_o_return_result;
		if (ParamIndexToVal(1, src2))
			_o_return_result;
		if (ParamIndexToVal(2, dst))
			_o_return_result;
		cv::absdiff(src1, src2, dst);
		return;
	}
	case FID_accumulate: {
		cv::_InputArray src, mask = cv::noArray();
		cv::_InputOutputArray dst;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, dst))
			_o_return_result;
		if (aParamCount > 2)
			TokenToVal(*aParam[2], mask, true);
		cv::accumulate(src, dst, mask);
		return;
	}
	case FID_accumulateProduct: {
		cv::_InputArray src1, src2, mask = cv::noArray();
		cv::_InputOutputArray dst;
		if (ParamIndexToVal(0, src1))
			_o_return_result;
		if (ParamIndexToVal(1, src2))
			_o_return_result;
		if (ParamIndexToVal(2, dst))
			_o_return_result;
		if (aParamCount > 3)
			TokenToVal(*aParam[3], mask, true);
		cv::accumulateProduct(src1, src2, dst, mask);
		return;
	}
	case FID_accumulateSquare: {
		cv::_InputArray src, mask = cv::noArray();
		cv::_InputOutputArray dst;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, dst))
			_o_return_result;
		if (aParamCount > 2)
			TokenToVal(*aParam[2], mask, true);
		cv::accumulateSquare(src, dst, mask);
		return;
	}
	case FID_accumulateWeighted: {
		cv::_InputArray src, mask = cv::noArray();
		cv::_InputOutputArray dst;
		double alpha;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, dst))
			_o_return_result;
		if (ParamIndexToVal(2, alpha))
			_o_return_result;
		if (aParamCount > 3)
			TokenToVal(*aParam[3], mask, true);
		cv::accumulateWeighted(src, dst, alpha, mask);
		return;
	}
	case FID_adaptiveThreshold: {
		cv::_InputArray src;
		cv::_OutputArray dst;
		double maxValue, C;
		int adaptiveMethod, thresholdType, blockSize;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, dst))
			_o_return_result;
		if (ParamIndexToVal(2, maxValue))
			_o_return_result;
		if (ParamIndexToVal(3, adaptiveMethod))
			_o_return_result;
		if (ParamIndexToVal(4, thresholdType))
			_o_return_result;
		if (ParamIndexToVal(5, blockSize))
			_o_return_result;
		if (ParamIndexToVal(6, C))
			_o_return_result;
		cv::adaptiveThreshold(src, dst, maxValue, adaptiveMethod, thresholdType, blockSize, C);
		return;
	}
	case FID_add: {
		cv::_InputArray src1, src2, mask = cv::noArray();
		cv::_OutputArray dst;
		int dtype = -1;
		if (ParamIndexToVal(0, src1))
			_o_return_result;
		if (ParamIndexToVal(1, src2))
			_o_return_result;
		if (ParamIndexToVal(2, dst))
			_o_return_result;
		if (aParamCount > 3)
			TokenToVal(*aParam[3], mask, true);
		if (aParamCount > 4)
			TokenToVal(*aParam[4], dtype, true);
		cv::add(src1, src2, dst, mask, dtype);
		return;
	}
	case FID_addText: {
		cv::Mat img;
		cv::Point org;
		cv::Scalar color = cv::Scalar::all(0);
		cv::String text, nameFont;
		int pointSize = -1, weight = cv::QT_FONT_NORMAL, style = cv::QT_STYLE_NORMAL, spacing = 0;
		if (ParamIndexToVal(0, img))
			_o_return_result;
		if (ParamIndexToVal(1, text))
			_o_return_result;
		if (ParamIndexToVal(2, org))
			_o_return_result;
		if (ParamIndexToVal(3, nameFont))
			_o_return_result;
		if (aParamCount > 4)
			TokenToVal(*aParam[4], pointSize, true);
		if (aParamCount > 5)
			TokenToVal(*aParam[5], color, true);
		if (aParamCount > 6)
			TokenToVal(*aParam[6], weight, true);
		if (aParamCount > 7)
			TokenToVal(*aParam[7], style, true);
		if (aParamCount > 8)
			TokenToVal(*aParam[8], spacing, true);
		cv::addText(img, text, org, nameFont, pointSize, color, weight, style, spacing);
		return;
	}
	case FID_addWeighted: {
		cv::_InputArray src1, src2;
		cv::_OutputArray dst;
		double alpha, beta, gamma;
		int dtype = -1;
		if (ParamIndexToVal(0, src1))
			_o_return_result;
		if (ParamIndexToVal(1, alpha))
			_o_return_result;
		if (ParamIndexToVal(2, src2))
			_o_return_result;
		if (ParamIndexToVal(3, beta))
			_o_return_result;
		if (ParamIndexToVal(4, gamma))
			_o_return_result;
		if (ParamIndexToVal(5, dst))
			_o_return_result;
		if (aParamCount > 6)
			TokenToVal(*aParam[6], dtype, true);
		cv::addWeighted(src1, alpha, src2, beta, gamma, dst, dtype);
		return;
	}
	case FID_applyColorMap: {
		if (!MatchTypes("ooi")) {
			cv::_InputArray src;
			cv::_OutputArray dst;
			int colormap;
			if (ParamIndexToVal(0, src))
				_o_return_result;
			if (ParamIndexToVal(1, dst))
				_o_return_result;
			if (ParamIndexToVal(2, colormap))
				_o_return_result;
			cv::applyColorMap(src, dst, colormap);
			return;
		}
		else if (!MatchTypes("ooo")) {
			cv::_InputArray src, userColor;
			cv::_OutputArray dst;
			if (ParamIndexToVal(0, src))
				_o_return_result;
			if (ParamIndexToVal(1, dst))
				_o_return_result;
			if (ParamIndexToVal(2, userColor))
				_o_return_result;
			cv::applyColorMap(src, dst, userColor);
			return;
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case FID_approxPolyDP: {
		bool closed;
		cv::_InputArray curve;
		cv::_OutputArray approxCurve;
		double epsilon;
		if (ParamIndexToVal(0, curve))
			_o_return_result;
		if (ParamIndexToVal(1, approxCurve))
			_o_return_result;
		if (ParamIndexToVal(2, epsilon))
			_o_return_result;
		if (ParamIndexToVal(3, (char&)closed))
			_o_return_result;
		cv::approxPolyDP(curve, approxCurve, epsilon, closed);
		return;
	}
	case FID_arcLength: {
		bool closed;
		cv::_InputArray curve;
		if (ParamIndexToVal(0, curve))
			_o_return_result;
		if (ParamIndexToVal(1, (char&)closed))
			_o_return_result;
		auto __retval = cv::arcLength(curve, closed);
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_arrowedLine: {
		cv::_InputOutputArray img;
		cv::Point pt1, pt2;
		cv::Scalar color;
		double tipLength = 0.1;
		int thickness = 1, line_type = 8, shift = 0;
		if (ParamIndexToVal(0, img))
			_o_return_result;
		if (ParamIndexToVal(1, pt1))
			_o_return_result;
		if (ParamIndexToVal(2, pt2))
			_o_return_result;
		if (ParamIndexToVal(3, color))
			_o_return_result;
		if (aParamCount > 4)
			TokenToVal(*aParam[4], thickness, true);
		if (aParamCount > 5)
			TokenToVal(*aParam[5], line_type, true);
		if (aParamCount > 6)
			TokenToVal(*aParam[6], shift, true);
		if (aParamCount > 7)
			TokenToVal(*aParam[7], tipLength, true);
		cv::arrowedLine(img, pt1, pt2, color, thickness, line_type, shift, tipLength);
		return;
	}
	case FID_batchDistance: {
		bool crosscheck = false;
		cv::_InputArray src1, src2, mask = cv::noArray();
		cv::_OutputArray dist, nidx;
		int dtype, normType = cv::NORM_L2, K = 0, update = 0;
		if (ParamIndexToVal(0, src1))
			_o_return_result;
		if (ParamIndexToVal(1, src2))
			_o_return_result;
		if (ParamIndexToVal(2, dist))
			_o_return_result;
		if (ParamIndexToVal(3, dtype))
			_o_return_result;
		if (ParamIndexToVal(4, nidx))
			_o_return_result;
		if (aParamCount > 5)
			TokenToVal(*aParam[5], normType, true);
		if (aParamCount > 6)
			TokenToVal(*aParam[6], K, true);
		if (aParamCount > 7)
			TokenToVal(*aParam[7], mask, true);
		if (aParamCount > 8)
			TokenToVal(*aParam[8], update, true);
		if (aParamCount > 9)
			TokenToVal(*aParam[9], (char&)crosscheck, true);
		cv::batchDistance(src1, src2, dist, dtype, nidx, normType, K, mask, update, crosscheck);
		return;
	}
	case FID_bilateralFilter: {
		cv::_InputArray src;
		cv::_OutputArray dst;
		double sigmaColor, sigmaSpace;
		int d, borderType = cv::BORDER_DEFAULT;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, dst))
			_o_return_result;
		if (ParamIndexToVal(2, d))
			_o_return_result;
		if (ParamIndexToVal(3, sigmaColor))
			_o_return_result;
		if (ParamIndexToVal(4, sigmaSpace))
			_o_return_result;
		if (aParamCount > 5)
			TokenToVal(*aParam[5], borderType, true);
		cv::bilateralFilter(src, dst, d, sigmaColor, sigmaSpace, borderType);
		return;
	}
	case FID_bitwise_and: {
		cv::_InputArray src1, src2, mask = cv::noArray();
		cv::_OutputArray dst;
		if (ParamIndexToVal(0, src1))
			_o_return_result;
		if (ParamIndexToVal(1, src2))
			_o_return_result;
		if (ParamIndexToVal(2, dst))
			_o_return_result;
		if (aParamCount > 3)
			TokenToVal(*aParam[3], mask, true);
		cv::bitwise_and(src1, src2, dst, mask);
		return;
	}
	case FID_bitwise_not: {
		cv::_InputArray src, mask = cv::noArray();
		cv::_OutputArray dst;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, dst))
			_o_return_result;
		if (aParamCount > 2)
			TokenToVal(*aParam[2], mask, true);
		cv::bitwise_not(src, dst, mask);
		return;
	}
	case FID_bitwise_or: {
		cv::_InputArray src1, src2, mask = cv::noArray();
		cv::_OutputArray dst;
		if (ParamIndexToVal(0, src1))
			_o_return_result;
		if (ParamIndexToVal(1, src2))
			_o_return_result;
		if (ParamIndexToVal(2, dst))
			_o_return_result;
		if (aParamCount > 3)
			TokenToVal(*aParam[3], mask, true);
		cv::bitwise_or(src1, src2, dst, mask);
		return;
	}
	case FID_bitwise_xor: {
		cv::_InputArray src1, src2, mask = cv::noArray();
		cv::_OutputArray dst;
		if (ParamIndexToVal(0, src1))
			_o_return_result;
		if (ParamIndexToVal(1, src2))
			_o_return_result;
		if (ParamIndexToVal(2, dst))
			_o_return_result;
		if (aParamCount > 3)
			TokenToVal(*aParam[3], mask, true);
		cv::bitwise_xor(src1, src2, dst, mask);
		return;
	}
	case FID_blendLinear: {
		cv::_InputArray src1, src2, weights1, weights2;
		cv::_OutputArray dst;
		if (ParamIndexToVal(0, src1))
			_o_return_result;
		if (ParamIndexToVal(1, src2))
			_o_return_result;
		if (ParamIndexToVal(2, weights1))
			_o_return_result;
		if (ParamIndexToVal(3, weights2))
			_o_return_result;
		if (ParamIndexToVal(4, dst))
			_o_return_result;
		cv::blendLinear(src1, src2, weights1, weights2, dst);
		return;
	}
	case FID_blur: {
		cv::_InputArray src;
		cv::_OutputArray dst;
		cv::Point anchor = cv::Point(-1, -1);
		cv::Size ksize;
		int borderType = cv::BORDER_DEFAULT;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, dst))
			_o_return_result;
		if (ParamIndexToVal(2, ksize))
			_o_return_result;
		if (aParamCount > 3)
			TokenToVal(*aParam[3], anchor, true);
		if (aParamCount > 4)
			TokenToVal(*aParam[4], borderType, true);
		cv::blur(src, dst, ksize, anchor, borderType);
		return;
	}
	case FID_borderInterpolate: {
		int p, len, borderType;
		if (ParamIndexToVal(0, p))
			_o_return_result;
		if (ParamIndexToVal(1, len))
			_o_return_result;
		if (ParamIndexToVal(2, borderType))
			_o_return_result;
		auto __retval = (__int64)cv::borderInterpolate(p, len, borderType);
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_boundingRect: {
		cv::_InputArray array;
		if (ParamIndexToVal(0, array))
			_o_return_result;
		auto __retval = cv::boundingRect(array);
		return ValToResult(__retval, aResultToken);
	}
	case FID_boxFilter: {
		bool normalize = true;
		cv::_InputArray src;
		cv::_OutputArray dst;
		cv::Point anchor = cv::Point(-1, -1);
		cv::Size ksize;
		int ddepth, borderType = cv::BORDER_DEFAULT;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, dst))
			_o_return_result;
		if (ParamIndexToVal(2, ddepth))
			_o_return_result;
		if (ParamIndexToVal(3, ksize))
			_o_return_result;
		if (aParamCount > 4)
			TokenToVal(*aParam[4], anchor, true);
		if (aParamCount > 5)
			TokenToVal(*aParam[5], (char&)normalize, true);
		if (aParamCount > 6)
			TokenToVal(*aParam[6], borderType, true);
		cv::boxFilter(src, dst, ddepth, ksize, anchor, normalize, borderType);
		return;
	}
	case FID_boxPoints: {
		cv::_OutputArray points;
		cv::RotatedRect box;
		if (ParamIndexToVal(0, box))
			_o_return_result;
		if (ParamIndexToVal(1, points))
			_o_return_result;
		cv::boxPoints(box, points);
		return;
	}
	case FID_buildOpticalFlowPyramid: {
		bool withDerivatives = true, tryReuseInputImage = true;
		cv::_InputArray img;
		cv::_OutputArray pyramid;
		cv::Size winSize;
		int maxLevel, pyrBorder = cv::BORDER_REFLECT_101, derivBorder = cv::BORDER_CONSTANT;
		if (ParamIndexToVal(0, img))
			_o_return_result;
		if (ParamIndexToVal(1, pyramid))
			_o_return_result;
		if (ParamIndexToVal(2, winSize))
			_o_return_result;
		if (ParamIndexToVal(3, maxLevel))
			_o_return_result;
		if (aParamCount > 4)
			TokenToVal(*aParam[4], (char&)withDerivatives, true);
		if (aParamCount > 5)
			TokenToVal(*aParam[5], pyrBorder, true);
		if (aParamCount > 6)
			TokenToVal(*aParam[6], derivBorder, true);
		if (aParamCount > 7)
			TokenToVal(*aParam[7], (char&)tryReuseInputImage, true);
		auto __retval = (__int64)cv::buildOpticalFlowPyramid(img, pyramid, winSize, maxLevel, withDerivatives, pyrBorder, derivBorder, tryReuseInputImage);
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_calcBackProject: {
		cv::_InputArray images, hist;
		cv::_OutputArray dst;
		double scale;
		std::vector<float> ranges;
		std::vector<int> channels;
		if (ParamIndexToVal(0, images))
			_o_return_result;
		if (ParamIndexToVal(1, channels))
			_o_return_result;
		if (ParamIndexToVal(2, hist))
			_o_return_result;
		if (ParamIndexToVal(3, dst))
			_o_return_result;
		if (ParamIndexToVal(4, ranges))
			_o_return_result;
		if (ParamIndexToVal(5, scale))
			_o_return_result;
		cv::calcBackProject(images, channels, hist, dst, ranges, scale);
		return;
	}
	case FID_calcCovarMatrix: {
		cv::_InputArray samples;
		cv::_InputOutputArray mean;
		cv::_OutputArray covar;
		int flags, ctype = CV_64F;
		if (ParamIndexToVal(0, samples))
			_o_return_result;
		if (ParamIndexToVal(1, covar))
			_o_return_result;
		if (ParamIndexToVal(2, mean))
			_o_return_result;
		if (ParamIndexToVal(3, flags))
			_o_return_result;
		if (aParamCount > 4)
			TokenToVal(*aParam[4], ctype, true);
		cv::calcCovarMatrix(samples, covar, mean, flags, ctype);
		return;
	}
	case FID_calcHist: {
		bool accumulate = false;
		cv::_InputArray images, mask;
		cv::_OutputArray hist;
		std::vector<float> ranges;
		std::vector<int> channels, histSize;
		if (ParamIndexToVal(0, images))
			_o_return_result;
		if (ParamIndexToVal(1, channels))
			_o_return_result;
		if (ParamIndexToVal(2, mask))
			_o_return_result;
		if (ParamIndexToVal(3, hist))
			_o_return_result;
		if (ParamIndexToVal(4, histSize))
			_o_return_result;
		if (ParamIndexToVal(5, ranges))
			_o_return_result;
		if (aParamCount > 6)
			TokenToVal(*aParam[6], (char&)accumulate, true);
		cv::calcHist(images, channels, mask, hist, histSize, ranges, accumulate);
		return;
	}
	case FID_calcOpticalFlowFarneback: {
		cv::_InputArray prev, next;
		cv::_InputOutputArray flow;
		double pyr_scale, poly_sigma;
		int levels, winsize, iterations, poly_n, flags;
		if (ParamIndexToVal(0, prev))
			_o_return_result;
		if (ParamIndexToVal(1, next))
			_o_return_result;
		if (ParamIndexToVal(2, flow))
			_o_return_result;
		if (ParamIndexToVal(3, pyr_scale))
			_o_return_result;
		if (ParamIndexToVal(4, levels))
			_o_return_result;
		if (ParamIndexToVal(5, winsize))
			_o_return_result;
		if (ParamIndexToVal(6, iterations))
			_o_return_result;
		if (ParamIndexToVal(7, poly_n))
			_o_return_result;
		if (ParamIndexToVal(8, poly_sigma))
			_o_return_result;
		if (ParamIndexToVal(9, flags))
			_o_return_result;
		cv::calcOpticalFlowFarneback(prev, next, flow, pyr_scale, levels, winsize, iterations, poly_n, poly_sigma, flags);
		return;
	}
	case FID_calcOpticalFlowPyrLK: {
		cv::_InputArray prevImg, nextImg, prevPts;
		cv::_InputOutputArray nextPts;
		cv::_OutputArray status, err;
		cv::Size winSize = cv::Size(21, 21);
		cv::TermCriteria criteria = cv::TermCriteria(cv::TermCriteria::COUNT + cv::TermCriteria::EPS, 30, 0.01);
		;
		double minEigThreshold = 1e-4;
		int maxLevel = 3, flags = 0;
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
		if (ParamIndexToVal(5, err))
			_o_return_result;
		if (aParamCount > 6)
			TokenToVal(*aParam[6], winSize, true);
		if (aParamCount > 7)
			TokenToVal(*aParam[7], maxLevel, true);
		if (aParamCount > 8)
			TokenToVal(*aParam[8], criteria, true);
		if (aParamCount > 9)
			TokenToVal(*aParam[9], flags, true);
		if (aParamCount > 10)
			TokenToVal(*aParam[10], minEigThreshold, true);
		cv::calcOpticalFlowPyrLK(prevImg, nextImg, prevPts, nextPts, status, err, winSize, maxLevel, criteria, flags, minEigThreshold);
		return;
	}
	case FID_calibrateCamera: {
		if (10 <= aParamCount && aParamCount <= 12) {
			cv::_InputArray objectPoints, imagePoints;
			cv::_InputOutputArray cameraMatrix, distCoeffs;
			cv::_OutputArray rvecs, tvecs, stdDeviationsIntrinsics, stdDeviationsExtrinsics, perViewErrors;
			cv::Size imageSize;
			cv::TermCriteria criteria = cv::TermCriteria(cv::TermCriteria::COUNT + cv::TermCriteria::EPS, 30, DBL_EPSILON);
			;
			int flags = 0;
			if (ParamIndexToVal(0, objectPoints))
				_o_return_result;
			if (ParamIndexToVal(1, imagePoints))
				_o_return_result;
			if (ParamIndexToVal(2, imageSize))
				_o_return_result;
			if (ParamIndexToVal(3, cameraMatrix))
				_o_return_result;
			if (ParamIndexToVal(4, distCoeffs))
				_o_return_result;
			if (ParamIndexToVal(5, rvecs))
				_o_return_result;
			if (ParamIndexToVal(6, tvecs))
				_o_return_result;
			if (ParamIndexToVal(7, stdDeviationsIntrinsics))
				_o_return_result;
			if (ParamIndexToVal(8, stdDeviationsExtrinsics))
				_o_return_result;
			if (ParamIndexToVal(9, perViewErrors))
				_o_return_result;
			if (aParamCount > 10)
				TokenToVal(*aParam[10], flags, true);
			if (aParamCount > 11)
				TokenToVal(*aParam[11], criteria, true);
			auto __retval = cv::calibrateCamera(objectPoints, imagePoints, imageSize, cameraMatrix, distCoeffs, rvecs, tvecs, stdDeviationsIntrinsics, stdDeviationsExtrinsics, perViewErrors, flags, criteria);
			return (void)(aResultToken.SetValue(__retval));
		}
		else if (7 <= aParamCount && aParamCount <= 9) {
			cv::_InputArray objectPoints, imagePoints;
			cv::_InputOutputArray cameraMatrix, distCoeffs;
			cv::_OutputArray rvecs, tvecs;
			cv::Size imageSize;
			cv::TermCriteria criteria = cv::TermCriteria(cv::TermCriteria::COUNT + cv::TermCriteria::EPS, 30, DBL_EPSILON);
			;
			int flags = 0;
			if (ParamIndexToVal(0, objectPoints))
				_o_return_result;
			if (ParamIndexToVal(1, imagePoints))
				_o_return_result;
			if (ParamIndexToVal(2, imageSize))
				_o_return_result;
			if (ParamIndexToVal(3, cameraMatrix))
				_o_return_result;
			if (ParamIndexToVal(4, distCoeffs))
				_o_return_result;
			if (ParamIndexToVal(5, rvecs))
				_o_return_result;
			if (ParamIndexToVal(6, tvecs))
				_o_return_result;
			if (aParamCount > 7)
				TokenToVal(*aParam[7], flags, true);
			if (aParamCount > 8)
				TokenToVal(*aParam[8], criteria, true);
			auto __retval = cv::calibrateCamera(objectPoints, imagePoints, imageSize, cameraMatrix, distCoeffs, rvecs, tvecs, flags, criteria);
			return (void)(aResultToken.SetValue(__retval));
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case FID_calibrateCameraRO: {
		if (13 <= aParamCount && aParamCount <= 15) {
			cv::_InputArray objectPoints, imagePoints;
			cv::_InputOutputArray cameraMatrix, distCoeffs;
			cv::_OutputArray rvecs, tvecs, newObjPoints, stdDeviationsIntrinsics, stdDeviationsExtrinsics, stdDeviationsObjPoints, perViewErrors;
			cv::Size imageSize;
			cv::TermCriteria criteria = cv::TermCriteria(cv::TermCriteria::COUNT + cv::TermCriteria::EPS, 30, DBL_EPSILON);
			;
			int iFixedPoint, flags = 0;
			if (ParamIndexToVal(0, objectPoints))
				_o_return_result;
			if (ParamIndexToVal(1, imagePoints))
				_o_return_result;
			if (ParamIndexToVal(2, imageSize))
				_o_return_result;
			if (ParamIndexToVal(3, iFixedPoint))
				_o_return_result;
			if (ParamIndexToVal(4, cameraMatrix))
				_o_return_result;
			if (ParamIndexToVal(5, distCoeffs))
				_o_return_result;
			if (ParamIndexToVal(6, rvecs))
				_o_return_result;
			if (ParamIndexToVal(7, tvecs))
				_o_return_result;
			if (ParamIndexToVal(8, newObjPoints))
				_o_return_result;
			if (ParamIndexToVal(9, stdDeviationsIntrinsics))
				_o_return_result;
			if (ParamIndexToVal(10, stdDeviationsExtrinsics))
				_o_return_result;
			if (ParamIndexToVal(11, stdDeviationsObjPoints))
				_o_return_result;
			if (ParamIndexToVal(12, perViewErrors))
				_o_return_result;
			if (aParamCount > 13)
				TokenToVal(*aParam[13], flags, true);
			if (aParamCount > 14)
				TokenToVal(*aParam[14], criteria, true);
			auto __retval = cv::calibrateCameraRO(objectPoints, imagePoints, imageSize, iFixedPoint, cameraMatrix, distCoeffs, rvecs, tvecs, newObjPoints, stdDeviationsIntrinsics, stdDeviationsExtrinsics, stdDeviationsObjPoints, perViewErrors, flags, criteria);
			return (void)(aResultToken.SetValue(__retval));
		}
		else if (9 <= aParamCount && aParamCount <= 11) {
			cv::_InputArray objectPoints, imagePoints;
			cv::_InputOutputArray cameraMatrix, distCoeffs;
			cv::_OutputArray rvecs, tvecs, newObjPoints;
			cv::Size imageSize;
			cv::TermCriteria criteria = cv::TermCriteria(cv::TermCriteria::COUNT + cv::TermCriteria::EPS, 30, DBL_EPSILON);
			;
			int iFixedPoint, flags = 0;
			if (ParamIndexToVal(0, objectPoints))
				_o_return_result;
			if (ParamIndexToVal(1, imagePoints))
				_o_return_result;
			if (ParamIndexToVal(2, imageSize))
				_o_return_result;
			if (ParamIndexToVal(3, iFixedPoint))
				_o_return_result;
			if (ParamIndexToVal(4, cameraMatrix))
				_o_return_result;
			if (ParamIndexToVal(5, distCoeffs))
				_o_return_result;
			if (ParamIndexToVal(6, rvecs))
				_o_return_result;
			if (ParamIndexToVal(7, tvecs))
				_o_return_result;
			if (ParamIndexToVal(8, newObjPoints))
				_o_return_result;
			if (aParamCount > 9)
				TokenToVal(*aParam[9], flags, true);
			if (aParamCount > 10)
				TokenToVal(*aParam[10], criteria, true);
			auto __retval = cv::calibrateCameraRO(objectPoints, imagePoints, imageSize, iFixedPoint, cameraMatrix, distCoeffs, rvecs, tvecs, newObjPoints, flags, criteria);
			return (void)(aResultToken.SetValue(__retval));
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case FID_calibrateHandEye: {
		cv::_InputArray R_gripper2base, t_gripper2base, R_target2cam, t_target2cam;
		cv::_OutputArray R_cam2gripper, t_cam2gripper;
		int method = cv::CALIB_HAND_EYE_TSAI;
		if (ParamIndexToVal(0, R_gripper2base))
			_o_return_result;
		if (ParamIndexToVal(1, t_gripper2base))
			_o_return_result;
		if (ParamIndexToVal(2, R_target2cam))
			_o_return_result;
		if (ParamIndexToVal(3, t_target2cam))
			_o_return_result;
		if (ParamIndexToVal(4, R_cam2gripper))
			_o_return_result;
		if (ParamIndexToVal(5, t_cam2gripper))
			_o_return_result;
		if (aParamCount > 6)
			TokenToVal(*aParam[6], method, true);
		cv::calibrateHandEye(R_gripper2base, t_gripper2base, R_target2cam, t_target2cam, R_cam2gripper, t_cam2gripper, (cv::HandEyeCalibrationMethod)method);
		return;
	}
	case FID_calibrateRobotWorldHandEye: {
		cv::_InputArray R_world2cam, t_world2cam, R_base2gripper, t_base2gripper;
		cv::_OutputArray R_base2world, t_base2world, R_gripper2cam, t_gripper2cam;
		int method = cv::CALIB_ROBOT_WORLD_HAND_EYE_SHAH;
		if (ParamIndexToVal(0, R_world2cam))
			_o_return_result;
		if (ParamIndexToVal(1, t_world2cam))
			_o_return_result;
		if (ParamIndexToVal(2, R_base2gripper))
			_o_return_result;
		if (ParamIndexToVal(3, t_base2gripper))
			_o_return_result;
		if (ParamIndexToVal(4, R_base2world))
			_o_return_result;
		if (ParamIndexToVal(5, t_base2world))
			_o_return_result;
		if (ParamIndexToVal(6, R_gripper2cam))
			_o_return_result;
		if (ParamIndexToVal(7, t_gripper2cam))
			_o_return_result;
		if (aParamCount > 8)
			TokenToVal(*aParam[8], method, true);
		cv::calibrateRobotWorldHandEye(R_world2cam, t_world2cam, R_base2gripper, t_base2gripper, R_base2world, t_base2world, R_gripper2cam, t_gripper2cam, (cv::RobotWorldHandEyeCalibrationMethod)method);
		return;
	}
	case FID_calibrationMatrixValues: {
		cv::_InputArray cameraMatrix;
		cv::Point2d principalPoint;
		cv::Size imageSize;
		double apertureWidth, apertureHeight, fovx, fovy, focalLength, aspectRatio;
		if (ParamIndexToVal(0, cameraMatrix))
			_o_return_result;
		if (ParamIndexToVal(1, imageSize))
			_o_return_result;
		if (ParamIndexToVal(2, apertureWidth))
			_o_return_result;
		if (ParamIndexToVal(3, apertureHeight))
			_o_return_result;
		VarRef* var_fovx = nullptr;
		if (ParamIndexToVal(4, var_fovx))
			_o_return_result;
		VarRef* var_fovy = nullptr;
		if (ParamIndexToVal(5, var_fovy))
			_o_return_result;
		VarRef* var_focalLength = nullptr;
		if (ParamIndexToVal(6, var_focalLength))
			_o_return_result;
		VarRef* var_principalPoint = nullptr;
		if (ParamIndexToVal(7, var_principalPoint))
			_o_return_result;
		VarRef* var_aspectRatio = nullptr;
		if (ParamIndexToVal(8, var_aspectRatio))
			_o_return_result;
		cv::calibrationMatrixValues(cameraMatrix, imageSize, apertureWidth, apertureHeight, fovx, fovy, focalLength, principalPoint, aspectRatio);
		g_ahkapi->VarAssign(var_fovx, ExprTokenType((double)fovx));
		g_ahkapi->VarAssign(var_fovy, ExprTokenType((double)fovy));
		g_ahkapi->VarAssign(var_focalLength, ExprTokenType((double)focalLength));
		ValToResult(principalPoint, aResultToken);
		g_ahkapi->VarAssign(var_principalPoint, aResultToken);
		g_ahkapi->ResultTokenFree(aResultToken);
		g_ahkapi->VarAssign(var_aspectRatio, ExprTokenType((double)aspectRatio));
		return;
	}
	case FID_cartToPolar: {
		bool angleInDegrees = false;
		cv::_InputArray x, y;
		cv::_OutputArray magnitude, angle;
		if (ParamIndexToVal(0, x))
			_o_return_result;
		if (ParamIndexToVal(1, y))
			_o_return_result;
		if (ParamIndexToVal(2, magnitude))
			_o_return_result;
		if (ParamIndexToVal(3, angle))
			_o_return_result;
		if (aParamCount > 4)
			TokenToVal(*aParam[4], (char&)angleInDegrees, true);
		cv::cartToPolar(x, y, magnitude, angle, angleInDegrees);
		return;
	}
	case FID_checkChessboard: {
		cv::_InputArray img;
		cv::Size size;
		if (ParamIndexToVal(0, img))
			_o_return_result;
		if (ParamIndexToVal(1, size))
			_o_return_result;
		auto __retval = (__int64)cv::checkChessboard(img, size);
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_checkHardwareSupport: {
		int feature;
		if (ParamIndexToVal(0, feature))
			_o_return_result;
		auto __retval = (__int64)cv::checkHardwareSupport(feature);
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_checkRange: {
		bool quiet = true;
		cv::_InputArray a;
		cv::Point pos;
		double minVal = -DBL_MAX, maxVal = DBL_MAX;
		if (ParamIndexToVal(0, a))
			_o_return_result;
		if (aParamCount > 1)
			TokenToVal(*aParam[1], (char&)quiet, true);
		VarRef* var_pos = nullptr;
		if (aParamCount > 2) {
			TokenToVal(*aParam[2], var_pos, true);
		}
		if (aParamCount > 3)
			TokenToVal(*aParam[3], minVal, true);
		if (aParamCount > 4)
			TokenToVal(*aParam[4], maxVal, true);
		auto __retval = (__int64)cv::checkRange(a, quiet, &pos, minVal, maxVal);
		if (var_pos) {
			ValToResult(pos, aResultToken);
			g_ahkapi->VarAssign(var_pos, aResultToken);
			g_ahkapi->ResultTokenFree(aResultToken);
		}
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_circle: {
		cv::_InputOutputArray img;
		cv::Point center;
		cv::Scalar color;
		int radius, thickness = 1, lineType = cv::LINE_8, shift = 0;
		if (ParamIndexToVal(0, img))
			_o_return_result;
		if (ParamIndexToVal(1, center))
			_o_return_result;
		if (ParamIndexToVal(2, radius))
			_o_return_result;
		if (ParamIndexToVal(3, color))
			_o_return_result;
		if (aParamCount > 4)
			TokenToVal(*aParam[4], thickness, true);
		if (aParamCount > 5)
			TokenToVal(*aParam[5], lineType, true);
		if (aParamCount > 6)
			TokenToVal(*aParam[6], shift, true);
		cv::circle(img, center, radius, color, thickness, lineType, shift);
		return;
	}
	case FID_clipLine: {
		cv::Point pt1, pt2;
		cv::Rect imgRect;
		if (ParamIndexToVal(0, imgRect))
			_o_return_result;
		VarRef* var_pt1 = nullptr;
		if (ParamIndexToVal(1, var_pt1))
			_o_return_result;
		if (TokenToVal(VarRefToToken(var_pt1), pt1) != CONDITION_TRUE)
			_o_return_result;
		VarRef* var_pt2 = nullptr;
		if (ParamIndexToVal(2, var_pt2))
			_o_return_result;
		if (TokenToVal(VarRefToToken(var_pt2), pt2) != CONDITION_TRUE)
			_o_return_result;
		auto __retval = (__int64)cv::clipLine(imgRect, pt1, pt2);
		ValToResult(pt1, aResultToken);
		g_ahkapi->VarAssign(var_pt1, aResultToken);
		g_ahkapi->ResultTokenFree(aResultToken);
		ValToResult(pt2, aResultToken);
		g_ahkapi->VarAssign(var_pt2, aResultToken);
		g_ahkapi->ResultTokenFree(aResultToken);
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_colorChange: {
		cv::_InputArray src, mask;
		cv::_OutputArray dst;
		float red_mul = 1.0f, green_mul = 1.0f, blue_mul = 1.0f;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, mask))
			_o_return_result;
		if (ParamIndexToVal(2, dst))
			_o_return_result;
		if (aParamCount > 3)
			TokenToVal(*aParam[3], red_mul, true);
		if (aParamCount > 4)
			TokenToVal(*aParam[4], green_mul, true);
		if (aParamCount > 5)
			TokenToVal(*aParam[5], blue_mul, true);
		cv::colorChange(src, mask, dst, red_mul, green_mul, blue_mul);
		return;
	}
	case FID_compare: {
		cv::_InputArray src1, src2;
		cv::_OutputArray dst;
		int cmpop;
		if (ParamIndexToVal(0, src1))
			_o_return_result;
		if (ParamIndexToVal(1, src2))
			_o_return_result;
		if (ParamIndexToVal(2, dst))
			_o_return_result;
		if (ParamIndexToVal(3, cmpop))
			_o_return_result;
		cv::compare(src1, src2, dst, cmpop);
		return;
	}
	case FID_compareHist: {
		cv::_InputArray H1, H2;
		int method;
		if (ParamIndexToVal(0, H1))
			_o_return_result;
		if (ParamIndexToVal(1, H2))
			_o_return_result;
		if (ParamIndexToVal(2, method))
			_o_return_result;
		auto __retval = cv::compareHist(H1, H2, method);
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_completeSymm: {
		bool lowerToUpper = false;
		cv::_InputOutputArray m;
		if (ParamIndexToVal(0, m))
			_o_return_result;
		if (aParamCount > 1)
			TokenToVal(*aParam[1], (char&)lowerToUpper, true);
		cv::completeSymm(m, lowerToUpper);
		return;
	}
	case FID_composeRT: {
		cv::_InputArray rvec1, tvec1, rvec2, tvec2;
		cv::_OutputArray rvec3, tvec3, dr3dr1 = cv::noArray(), dr3dt1 = cv::noArray(), dr3dr2 = cv::noArray(), dr3dt2 = cv::noArray(), dt3dr1 = cv::noArray(), dt3dt1 = cv::noArray(), dt3dr2 = cv::noArray(), dt3dt2 = cv::noArray();
		if (ParamIndexToVal(0, rvec1))
			_o_return_result;
		if (ParamIndexToVal(1, tvec1))
			_o_return_result;
		if (ParamIndexToVal(2, rvec2))
			_o_return_result;
		if (ParamIndexToVal(3, tvec2))
			_o_return_result;
		if (ParamIndexToVal(4, rvec3))
			_o_return_result;
		if (ParamIndexToVal(5, tvec3))
			_o_return_result;
		if (aParamCount > 6)
			TokenToVal(*aParam[6], dr3dr1, true);
		if (aParamCount > 7)
			TokenToVal(*aParam[7], dr3dt1, true);
		if (aParamCount > 8)
			TokenToVal(*aParam[8], dr3dr2, true);
		if (aParamCount > 9)
			TokenToVal(*aParam[9], dr3dt2, true);
		if (aParamCount > 10)
			TokenToVal(*aParam[10], dt3dr1, true);
		if (aParamCount > 11)
			TokenToVal(*aParam[11], dt3dt1, true);
		if (aParamCount > 12)
			TokenToVal(*aParam[12], dt3dr2, true);
		if (aParamCount > 13)
			TokenToVal(*aParam[13], dt3dt2, true);
		cv::composeRT(rvec1, tvec1, rvec2, tvec2, rvec3, tvec3, dr3dr1, dr3dt1, dr3dr2, dr3dt2, dt3dr1, dt3dt1, dt3dr2, dt3dt2);
		return;
	}
	case FID_computeCorrespondEpilines: {
		cv::_InputArray points, F;
		cv::_OutputArray lines;
		int whichImage;
		if (ParamIndexToVal(0, points))
			_o_return_result;
		if (ParamIndexToVal(1, whichImage))
			_o_return_result;
		if (ParamIndexToVal(2, F))
			_o_return_result;
		if (ParamIndexToVal(3, lines))
			_o_return_result;
		cv::computeCorrespondEpilines(points, whichImage, F, lines);
		return;
	}
	case FID_computeECC: {
		cv::_InputArray templateImage, inputImage, inputMask = cv::noArray();
		if (ParamIndexToVal(0, templateImage))
			_o_return_result;
		if (ParamIndexToVal(1, inputImage))
			_o_return_result;
		if (aParamCount > 2)
			TokenToVal(*aParam[2], inputMask, true);
		auto __retval = cv::computeECC(templateImage, inputImage, inputMask);
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_connectedComponents: {
		if (aParamCount == 5) {
			cv::_InputArray image;
			cv::_OutputArray labels;
			int connectivity, ltype, ccltype;
			if (ParamIndexToVal(0, image))
				_o_return_result;
			if (ParamIndexToVal(1, labels))
				_o_return_result;
			if (ParamIndexToVal(2, connectivity))
				_o_return_result;
			if (ParamIndexToVal(3, ltype))
				_o_return_result;
			if (ParamIndexToVal(4, ccltype))
				_o_return_result;
			auto __retval = (__int64)cv::connectedComponents(image, labels, connectivity, ltype, ccltype);
			return (void)(aResultToken.SetValue(__retval));
		}
		else if (2 <= aParamCount && aParamCount <= 4) {
			cv::_InputArray image;
			cv::_OutputArray labels;
			int connectivity = 8, ltype = CV_32S;
			if (ParamIndexToVal(0, image))
				_o_return_result;
			if (ParamIndexToVal(1, labels))
				_o_return_result;
			if (aParamCount > 2)
				TokenToVal(*aParam[2], connectivity, true);
			if (aParamCount > 3)
				TokenToVal(*aParam[3], ltype, true);
			auto __retval = (__int64)cv::connectedComponents(image, labels, connectivity, ltype);
			return (void)(aResultToken.SetValue(__retval));
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case FID_connectedComponentsWithStats: {
		if (aParamCount == 7) {
			cv::_InputArray image;
			cv::_OutputArray labels, stats, centroids;
			int connectivity, ltype, ccltype;
			if (ParamIndexToVal(0, image))
				_o_return_result;
			if (ParamIndexToVal(1, labels))
				_o_return_result;
			if (ParamIndexToVal(2, stats))
				_o_return_result;
			if (ParamIndexToVal(3, centroids))
				_o_return_result;
			if (ParamIndexToVal(4, connectivity))
				_o_return_result;
			if (ParamIndexToVal(5, ltype))
				_o_return_result;
			if (ParamIndexToVal(6, ccltype))
				_o_return_result;
			auto __retval = (__int64)cv::connectedComponentsWithStats(image, labels, stats, centroids, connectivity, ltype, ccltype);
			return (void)(aResultToken.SetValue(__retval));
		}
		else if (4 <= aParamCount && aParamCount <= 6) {
			cv::_InputArray image;
			cv::_OutputArray labels, stats, centroids;
			int connectivity = 8, ltype = CV_32S;
			if (ParamIndexToVal(0, image))
				_o_return_result;
			if (ParamIndexToVal(1, labels))
				_o_return_result;
			if (ParamIndexToVal(2, stats))
				_o_return_result;
			if (ParamIndexToVal(3, centroids))
				_o_return_result;
			if (aParamCount > 4)
				TokenToVal(*aParam[4], connectivity, true);
			if (aParamCount > 5)
				TokenToVal(*aParam[5], ltype, true);
			auto __retval = (__int64)cv::connectedComponentsWithStats(image, labels, stats, centroids, connectivity, ltype);
			return (void)(aResultToken.SetValue(__retval));
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case FID_contourArea: {
		bool oriented = false;
		cv::_InputArray contour;
		if (ParamIndexToVal(0, contour))
			_o_return_result;
		if (aParamCount > 1)
			TokenToVal(*aParam[1], (char&)oriented, true);
		auto __retval = cv::contourArea(contour, oriented);
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_convertFp16: {
		cv::_InputArray src;
		cv::_OutputArray dst;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, dst))
			_o_return_result;
		cv::convertFp16(src, dst);
		return;
	}
	case FID_convertMaps: {
		bool nninterpolation = false;
		cv::_InputArray map1, map2;
		cv::_OutputArray dstmap1, dstmap2;
		int dstmap1type;
		if (ParamIndexToVal(0, map1))
			_o_return_result;
		if (ParamIndexToVal(1, map2))
			_o_return_result;
		if (ParamIndexToVal(2, dstmap1))
			_o_return_result;
		if (ParamIndexToVal(3, dstmap2))
			_o_return_result;
		if (ParamIndexToVal(4, dstmap1type))
			_o_return_result;
		if (aParamCount > 5)
			TokenToVal(*aParam[5], (char&)nninterpolation, true);
		cv::convertMaps(map1, map2, dstmap1, dstmap2, dstmap1type, nninterpolation);
		return;
	}
	case FID_convertPointsFromHomogeneous: {
		cv::_InputArray src;
		cv::_OutputArray dst;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, dst))
			_o_return_result;
		cv::convertPointsFromHomogeneous(src, dst);
		return;
	}
	case FID_convertPointsToHomogeneous: {
		cv::_InputArray src;
		cv::_OutputArray dst;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, dst))
			_o_return_result;
		cv::convertPointsToHomogeneous(src, dst);
		return;
	}
	case FID_convertScaleAbs: {
		cv::_InputArray src;
		cv::_OutputArray dst;
		double alpha = 1, beta = 0;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, dst))
			_o_return_result;
		if (aParamCount > 2)
			TokenToVal(*aParam[2], alpha, true);
		if (aParamCount > 3)
			TokenToVal(*aParam[3], beta, true);
		cv::convertScaleAbs(src, dst, alpha, beta);
		return;
	}
	case FID_convexHull: {
		bool clockwise = false, returnPoints = true;
		cv::_InputArray points;
		cv::_OutputArray hull;
		if (ParamIndexToVal(0, points))
			_o_return_result;
		if (ParamIndexToVal(1, hull))
			_o_return_result;
		if (aParamCount > 2)
			TokenToVal(*aParam[2], (char&)clockwise, true);
		if (aParamCount > 3)
			TokenToVal(*aParam[3], (char&)returnPoints, true);
		cv::convexHull(points, hull, clockwise, returnPoints);
		return;
	}
	case FID_convexityDefects: {
		cv::_InputArray contour, convexhull;
		cv::_OutputArray convexityDefects;
		if (ParamIndexToVal(0, contour))
			_o_return_result;
		if (ParamIndexToVal(1, convexhull))
			_o_return_result;
		if (ParamIndexToVal(2, convexityDefects))
			_o_return_result;
		cv::convexityDefects(contour, convexhull, convexityDefects);
		return;
	}
	case FID_copyMakeBorder: {
		cv::_InputArray src;
		cv::_OutputArray dst;
		cv::Scalar value = cv::Scalar();
		int top, bottom, left, right, borderType;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, dst))
			_o_return_result;
		if (ParamIndexToVal(2, top))
			_o_return_result;
		if (ParamIndexToVal(3, bottom))
			_o_return_result;
		if (ParamIndexToVal(4, left))
			_o_return_result;
		if (ParamIndexToVal(5, right))
			_o_return_result;
		if (ParamIndexToVal(6, borderType))
			_o_return_result;
		if (aParamCount > 7)
			TokenToVal(*aParam[7], value, true);
		cv::copyMakeBorder(src, dst, top, bottom, left, right, borderType, value);
		return;
	}
	case FID_copyTo: {
		cv::_InputArray src, mask;
		cv::_OutputArray dst;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, dst))
			_o_return_result;
		if (ParamIndexToVal(2, mask))
			_o_return_result;
		cv::copyTo(src, dst, mask);
		return;
	}
	case FID_cornerEigenValsAndVecs: {
		cv::_InputArray src;
		cv::_OutputArray dst;
		int blockSize, ksize, borderType = cv::BORDER_DEFAULT;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, dst))
			_o_return_result;
		if (ParamIndexToVal(2, blockSize))
			_o_return_result;
		if (ParamIndexToVal(3, ksize))
			_o_return_result;
		if (aParamCount > 4)
			TokenToVal(*aParam[4], borderType, true);
		cv::cornerEigenValsAndVecs(src, dst, blockSize, ksize, borderType);
		return;
	}
	case FID_cornerHarris: {
		cv::_InputArray src;
		cv::_OutputArray dst;
		double k;
		int blockSize, ksize, borderType = cv::BORDER_DEFAULT;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, dst))
			_o_return_result;
		if (ParamIndexToVal(2, blockSize))
			_o_return_result;
		if (ParamIndexToVal(3, ksize))
			_o_return_result;
		if (ParamIndexToVal(4, k))
			_o_return_result;
		if (aParamCount > 5)
			TokenToVal(*aParam[5], borderType, true);
		cv::cornerHarris(src, dst, blockSize, ksize, k, borderType);
		return;
	}
	case FID_cornerMinEigenVal: {
		cv::_InputArray src;
		cv::_OutputArray dst;
		int blockSize, ksize = 3, borderType = cv::BORDER_DEFAULT;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, dst))
			_o_return_result;
		if (ParamIndexToVal(2, blockSize))
			_o_return_result;
		if (aParamCount > 3)
			TokenToVal(*aParam[3], ksize, true);
		if (aParamCount > 4)
			TokenToVal(*aParam[4], borderType, true);
		cv::cornerMinEigenVal(src, dst, blockSize, ksize, borderType);
		return;
	}
	case FID_cornerSubPix: {
		cv::_InputArray image;
		cv::_InputOutputArray corners;
		cv::Size winSize, zeroZone;
		cv::TermCriteria criteria;
		if (ParamIndexToVal(0, image))
			_o_return_result;
		if (ParamIndexToVal(1, corners))
			_o_return_result;
		if (ParamIndexToVal(2, winSize))
			_o_return_result;
		if (ParamIndexToVal(3, zeroZone))
			_o_return_result;
		if (ParamIndexToVal(4, criteria))
			_o_return_result;
		cv::cornerSubPix(image, corners, winSize, zeroZone, criteria);
		return;
	}
	case FID_correctMatches: {
		cv::_InputArray F, points1, points2;
		cv::_OutputArray newPoints1, newPoints2;
		if (ParamIndexToVal(0, F))
			_o_return_result;
		if (ParamIndexToVal(1, points1))
			_o_return_result;
		if (ParamIndexToVal(2, points2))
			_o_return_result;
		if (ParamIndexToVal(3, newPoints1))
			_o_return_result;
		if (ParamIndexToVal(4, newPoints2))
			_o_return_result;
		cv::correctMatches(F, points1, points2, newPoints1, newPoints2);
		return;
	}
	case FID_countNonZero: {
		cv::_InputArray src;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		auto __retval = (__int64)cv::countNonZero(src);
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_createAlignMTB: {
		bool cut = true;
		int max_bits = 6, exclude_range = 4;
		if (aParamCount > 0)
			TokenToVal(*aParam[0], max_bits, true);
		if (aParamCount > 1)
			TokenToVal(*aParam[1], exclude_range, true);
		if (aParamCount > 2)
			TokenToVal(*aParam[2], (char&)cut, true);
		auto __retval = (AlignMTB*)AlignMTB::sPrototype->New(g_invalidparam, 1);
		__retval->mC = cv::createAlignMTB(max_bits, exclude_range, cut);
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_createBackgroundSubtractorKNN: {
		bool detectShadows = true;
		double dist2Threshold = 400.0;
		int history = 500;
		if (aParamCount > 0)
			TokenToVal(*aParam[0], history, true);
		if (aParamCount > 1)
			TokenToVal(*aParam[1], dist2Threshold, true);
		if (aParamCount > 2)
			TokenToVal(*aParam[2], (char&)detectShadows, true);
		auto __retval = (BackgroundSubtractorKNN*)BackgroundSubtractorKNN::sPrototype->New(g_invalidparam, 1);
		__retval->mC = cv::createBackgroundSubtractorKNN(history, dist2Threshold, detectShadows);
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_createBackgroundSubtractorMOG2: {
		bool detectShadows = true;
		double varThreshold = 16;
		int history = 500;
		if (aParamCount > 0)
			TokenToVal(*aParam[0], history, true);
		if (aParamCount > 1)
			TokenToVal(*aParam[1], varThreshold, true);
		if (aParamCount > 2)
			TokenToVal(*aParam[2], (char&)detectShadows, true);
		auto __retval = (BackgroundSubtractorMOG2*)BackgroundSubtractorMOG2::sPrototype->New(g_invalidparam, 1);
		__retval->mC = cv::createBackgroundSubtractorMOG2(history, varThreshold, detectShadows);
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_createCLAHE: {
		cv::Size tileGridSize = cv::Size(8, 8);
		double clipLimit = 40.0;
		if (aParamCount > 0)
			TokenToVal(*aParam[0], clipLimit, true);
		if (aParamCount > 1)
			TokenToVal(*aParam[1], tileGridSize, true);
		auto __retval = (CLAHE*)CLAHE::sPrototype->New(g_invalidparam, 1);
		__retval->mC = cv::createCLAHE(clipLimit, tileGridSize);
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_createCalibrateDebevec: {
		bool random = false;
		float lambda = 10.0f;
		int samples = 70;
		if (aParamCount > 0)
			TokenToVal(*aParam[0], samples, true);
		if (aParamCount > 1)
			TokenToVal(*aParam[1], lambda, true);
		if (aParamCount > 2)
			TokenToVal(*aParam[2], (char&)random, true);
		auto __retval = (CalibrateDebevec*)CalibrateDebevec::sPrototype->New(g_invalidparam, 1);
		__retval->mC = cv::createCalibrateDebevec(samples, lambda, random);
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_createCalibrateRobertson: {
		float threshold = 0.01f;
		int max_iter = 30;
		if (aParamCount > 0)
			TokenToVal(*aParam[0], max_iter, true);
		if (aParamCount > 1)
			TokenToVal(*aParam[1], threshold, true);
		auto __retval = (CalibrateRobertson*)CalibrateRobertson::sPrototype->New(g_invalidparam, 1);
		__retval->mC = cv::createCalibrateRobertson(max_iter, threshold);
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_createGeneralizedHoughBallard: {
		auto __retval = (GeneralizedHoughBallard*)GeneralizedHoughBallard::sPrototype->New(g_invalidparam, 1);
		__retval->mC = cv::createGeneralizedHoughBallard();
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_createGeneralizedHoughGuil: {
		auto __retval = (GeneralizedHoughGuil*)GeneralizedHoughGuil::sPrototype->New(g_invalidparam, 1);
		__retval->mC = cv::createGeneralizedHoughGuil();
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_createHanningWindow: {
		cv::_OutputArray dst;
		cv::Size winSize;
		int type;
		if (ParamIndexToVal(0, dst))
			_o_return_result;
		if (ParamIndexToVal(1, winSize))
			_o_return_result;
		if (ParamIndexToVal(2, type))
			_o_return_result;
		cv::createHanningWindow(dst, winSize, type);
		return;
	}
	case FID_createLineSegmentDetector: {
		double scale = 0.8, sigma_scale = 0.6, quant = 2.0, ang_th = 22.5, log_eps = 0, density_th = 0.7;
		int refine = cv::LSD_REFINE_STD, n_bins = 1024;
		if (aParamCount > 0)
			TokenToVal(*aParam[0], refine, true);
		if (aParamCount > 1)
			TokenToVal(*aParam[1], scale, true);
		if (aParamCount > 2)
			TokenToVal(*aParam[2], sigma_scale, true);
		if (aParamCount > 3)
			TokenToVal(*aParam[3], quant, true);
		if (aParamCount > 4)
			TokenToVal(*aParam[4], ang_th, true);
		if (aParamCount > 5)
			TokenToVal(*aParam[5], log_eps, true);
		if (aParamCount > 6)
			TokenToVal(*aParam[6], density_th, true);
		if (aParamCount > 7)
			TokenToVal(*aParam[7], n_bins, true);
		auto __retval = (LineSegmentDetector*)LineSegmentDetector::sPrototype->New(g_invalidparam, 1);
		__retval->mC = cv::createLineSegmentDetector(refine, scale, sigma_scale, quant, ang_th, log_eps, density_th, n_bins);
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_createMergeDebevec: {
		auto __retval = (MergeDebevec*)MergeDebevec::sPrototype->New(g_invalidparam, 1);
		__retval->mC = cv::createMergeDebevec();
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_createMergeMertens: {
		float contrast_weight = 1.0f, saturation_weight = 1.0f, exposure_weight = 0.0f;
		if (aParamCount > 0)
			TokenToVal(*aParam[0], contrast_weight, true);
		if (aParamCount > 1)
			TokenToVal(*aParam[1], saturation_weight, true);
		if (aParamCount > 2)
			TokenToVal(*aParam[2], exposure_weight, true);
		auto __retval = (MergeMertens*)MergeMertens::sPrototype->New(g_invalidparam, 1);
		__retval->mC = cv::createMergeMertens(contrast_weight, saturation_weight, exposure_weight);
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_createMergeRobertson: {
		auto __retval = (MergeRobertson*)MergeRobertson::sPrototype->New(g_invalidparam, 1);
		__retval->mC = cv::createMergeRobertson();
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_createTonemap: {
		float gamma = 1.0f;
		if (aParamCount > 0)
			TokenToVal(*aParam[0], gamma, true);
		auto __retval = (Tonemap*)Tonemap::sPrototype->New(g_invalidparam, 1);
		__retval->mC = cv::createTonemap(gamma);
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_createTonemapDrago: {
		float gamma = 1.0f, saturation = 1.0f, bias = 0.85f;
		if (aParamCount > 0)
			TokenToVal(*aParam[0], gamma, true);
		if (aParamCount > 1)
			TokenToVal(*aParam[1], saturation, true);
		if (aParamCount > 2)
			TokenToVal(*aParam[2], bias, true);
		auto __retval = (TonemapDrago*)TonemapDrago::sPrototype->New(g_invalidparam, 1);
		__retval->mC = cv::createTonemapDrago(gamma, saturation, bias);
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_createTonemapMantiuk: {
		float gamma = 1.0f, scale = 0.7f, saturation = 1.0f;
		if (aParamCount > 0)
			TokenToVal(*aParam[0], gamma, true);
		if (aParamCount > 1)
			TokenToVal(*aParam[1], scale, true);
		if (aParamCount > 2)
			TokenToVal(*aParam[2], saturation, true);
		auto __retval = (TonemapMantiuk*)TonemapMantiuk::sPrototype->New(g_invalidparam, 1);
		__retval->mC = cv::createTonemapMantiuk(gamma, scale, saturation);
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_createTonemapReinhard: {
		float gamma = 1.0f, intensity = 0.0f, light_adapt = 1.0f, color_adapt = 0.0f;
		if (aParamCount > 0)
			TokenToVal(*aParam[0], gamma, true);
		if (aParamCount > 1)
			TokenToVal(*aParam[1], intensity, true);
		if (aParamCount > 2)
			TokenToVal(*aParam[2], light_adapt, true);
		if (aParamCount > 3)
			TokenToVal(*aParam[3], color_adapt, true);
		auto __retval = (TonemapReinhard*)TonemapReinhard::sPrototype->New(g_invalidparam, 1);
		__retval->mC = cv::createTonemapReinhard(gamma, intensity, light_adapt, color_adapt);
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_cubeRoot: {
		float val;
		if (ParamIndexToVal(0, val))
			_o_return_result;
		auto __retval = (double)cv::cubeRoot(val);
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_cvtColor: {
		cv::_InputArray src;
		cv::_OutputArray dst;
		int code, dstCn = 0;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, dst))
			_o_return_result;
		if (ParamIndexToVal(2, code))
			_o_return_result;
		if (aParamCount > 3)
			TokenToVal(*aParam[3], dstCn, true);
		cv::cvtColor(src, dst, code, dstCn);
		return;
	}
	case FID_cvtColorTwoPlane: {
		cv::_InputArray src1, src2;
		cv::_OutputArray dst;
		int code;
		if (ParamIndexToVal(0, src1))
			_o_return_result;
		if (ParamIndexToVal(1, src2))
			_o_return_result;
		if (ParamIndexToVal(2, dst))
			_o_return_result;
		if (ParamIndexToVal(3, code))
			_o_return_result;
		cv::cvtColorTwoPlane(src1, src2, dst, code);
		return;
	}
	case FID_dct: {
		cv::_InputArray src;
		cv::_OutputArray dst;
		int flags = 0;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, dst))
			_o_return_result;
		if (aParamCount > 2)
			TokenToVal(*aParam[2], flags, true);
		cv::dct(src, dst, flags);
		return;
	}
	case FID_decolor: {
		cv::_InputArray src;
		cv::_OutputArray grayscale, color_boost;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, grayscale))
			_o_return_result;
		if (ParamIndexToVal(2, color_boost))
			_o_return_result;
		cv::decolor(src, grayscale, color_boost);
		return;
	}
	case FID_decomposeEssentialMat: {
		cv::_InputArray E;
		cv::_OutputArray R1, R2, t;
		if (ParamIndexToVal(0, E))
			_o_return_result;
		if (ParamIndexToVal(1, R1))
			_o_return_result;
		if (ParamIndexToVal(2, R2))
			_o_return_result;
		if (ParamIndexToVal(3, t))
			_o_return_result;
		cv::decomposeEssentialMat(E, R1, R2, t);
		return;
	}
	case FID_decomposeHomographyMat: {
		cv::_InputArray H, K;
		cv::_OutputArray rotations, translations, normals;
		if (ParamIndexToVal(0, H))
			_o_return_result;
		if (ParamIndexToVal(1, K))
			_o_return_result;
		if (ParamIndexToVal(2, rotations))
			_o_return_result;
		if (ParamIndexToVal(3, translations))
			_o_return_result;
		if (ParamIndexToVal(4, normals))
			_o_return_result;
		auto __retval = (__int64)cv::decomposeHomographyMat(H, K, rotations, translations, normals);
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_decomposeProjectionMatrix: {
		cv::_InputArray projMatrix;
		cv::_OutputArray cameraMatrix, rotMatrix, transVect, rotMatrixX = cv::noArray(), rotMatrixY = cv::noArray(), rotMatrixZ = cv::noArray(), eulerAngles = cv::noArray();
		if (ParamIndexToVal(0, projMatrix))
			_o_return_result;
		if (ParamIndexToVal(1, cameraMatrix))
			_o_return_result;
		if (ParamIndexToVal(2, rotMatrix))
			_o_return_result;
		if (ParamIndexToVal(3, transVect))
			_o_return_result;
		if (aParamCount > 4)
			TokenToVal(*aParam[4], rotMatrixX, true);
		if (aParamCount > 5)
			TokenToVal(*aParam[5], rotMatrixY, true);
		if (aParamCount > 6)
			TokenToVal(*aParam[6], rotMatrixZ, true);
		if (aParamCount > 7)
			TokenToVal(*aParam[7], eulerAngles, true);
		cv::decomposeProjectionMatrix(projMatrix, cameraMatrix, rotMatrix, transVect, rotMatrixX, rotMatrixY, rotMatrixZ, eulerAngles);
		return;
	}
	case FID_demosaicing: {
		cv::_InputArray src;
		cv::_OutputArray dst;
		int code, dstCn = 0;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, dst))
			_o_return_result;
		if (ParamIndexToVal(2, code))
			_o_return_result;
		if (aParamCount > 3)
			TokenToVal(*aParam[3], dstCn, true);
		cv::demosaicing(src, dst, code, dstCn);
		return;
	}
	case FID_denoise_TVL1: {
		cv::Mat result;
		double lambda = 1.0;
		int niters = 30;
		std::vector<cv::Mat> observations;
		if (ParamIndexToVal(0, observations))
			_o_return_result;
		if (ParamIndexToVal(1, result))
			_o_return_result;
		if (aParamCount > 2)
			TokenToVal(*aParam[2], lambda, true);
		if (aParamCount > 3)
			TokenToVal(*aParam[3], niters, true);
		cv::denoise_TVL1(observations, result, lambda, niters);
		return;
	}
	case FID_destroyAllWindows: {
		cv::destroyAllWindows();
		return;
	}
	case FID_destroyWindow: {
		cv::String winname;
		if (ParamIndexToVal(0, winname))
			_o_return_result;
		cv::destroyWindow(winname);
		return;
	}
	case FID_detailEnhance: {
		cv::_InputArray src;
		cv::_OutputArray dst;
		float sigma_s = 10, sigma_r = 0.15f;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, dst))
			_o_return_result;
		if (aParamCount > 2)
			TokenToVal(*aParam[2], sigma_s, true);
		if (aParamCount > 3)
			TokenToVal(*aParam[3], sigma_r, true);
		cv::detailEnhance(src, dst, sigma_s, sigma_r);
		return;
	}
	case FID_determinant: {
		cv::_InputArray mtx;
		if (ParamIndexToVal(0, mtx))
			_o_return_result;
		auto __retval = cv::determinant(mtx);
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_dft: {
		cv::_InputArray src;
		cv::_OutputArray dst;
		int flags = 0, nonzeroRows = 0;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, dst))
			_o_return_result;
		if (aParamCount > 2)
			TokenToVal(*aParam[2], flags, true);
		if (aParamCount > 3)
			TokenToVal(*aParam[3], nonzeroRows, true);
		cv::dft(src, dst, flags, nonzeroRows);
		return;
	}
	case FID_dilate: {
		cv::_InputArray src, kernel;
		cv::_OutputArray dst;
		cv::Point anchor = cv::Point(-1, -1);
		cv::Scalar borderValue = cv::morphologyDefaultBorderValue();
		int iterations = 1, borderType = cv::BORDER_CONSTANT;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, dst))
			_o_return_result;
		if (ParamIndexToVal(2, kernel))
			_o_return_result;
		if (aParamCount > 3)
			TokenToVal(*aParam[3], anchor, true);
		if (aParamCount > 4)
			TokenToVal(*aParam[4], iterations, true);
		if (aParamCount > 5)
			TokenToVal(*aParam[5], borderType, true);
		if (aParamCount > 6)
			TokenToVal(*aParam[6], borderValue, true);
		cv::dilate(src, dst, kernel, anchor, iterations, borderType, borderValue);
		return;
	}
	case FID_displayOverlay: {
		cv::String winname, text;
		int delayms = 0;
		if (ParamIndexToVal(0, winname))
			_o_return_result;
		if (ParamIndexToVal(1, text))
			_o_return_result;
		if (aParamCount > 2)
			TokenToVal(*aParam[2], delayms, true);
		cv::displayOverlay(winname, text, delayms);
		return;
	}
	case FID_displayStatusBar: {
		cv::String winname, text;
		int delayms = 0;
		if (ParamIndexToVal(0, winname))
			_o_return_result;
		if (ParamIndexToVal(1, text))
			_o_return_result;
		if (aParamCount > 2)
			TokenToVal(*aParam[2], delayms, true);
		cv::displayStatusBar(winname, text, delayms);
		return;
	}
	case FID_distanceTransform: {
		if (!MatchTypes("oooiii?")) {
			cv::_InputArray src;
			cv::_OutputArray dst, labels;
			int distanceType, maskSize, labelType = cv::DIST_LABEL_CCOMP;
			if (ParamIndexToVal(0, src))
				_o_return_result;
			if (ParamIndexToVal(1, dst))
				_o_return_result;
			if (ParamIndexToVal(2, labels))
				_o_return_result;
			if (ParamIndexToVal(3, distanceType))
				_o_return_result;
			if (ParamIndexToVal(4, maskSize))
				_o_return_result;
			if (aParamCount > 5)
				TokenToVal(*aParam[5], labelType, true);
			cv::distanceTransform(src, dst, labels, distanceType, maskSize, labelType);
			return;
		}
		else if (!MatchTypes("ooiii?")) {
			cv::_InputArray src;
			cv::_OutputArray dst;
			int distanceType, maskSize, dstType = CV_32F;
			if (ParamIndexToVal(0, src))
				_o_return_result;
			if (ParamIndexToVal(1, dst))
				_o_return_result;
			if (ParamIndexToVal(2, distanceType))
				_o_return_result;
			if (ParamIndexToVal(3, maskSize))
				_o_return_result;
			if (aParamCount > 4)
				TokenToVal(*aParam[4], dstType, true);
			cv::distanceTransform(src, dst, distanceType, maskSize, dstType);
			return;
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case FID_divSpectrums: {
		bool conjB = false;
		cv::_InputArray a, b;
		cv::_OutputArray c;
		int flags;
		if (ParamIndexToVal(0, a))
			_o_return_result;
		if (ParamIndexToVal(1, b))
			_o_return_result;
		if (ParamIndexToVal(2, c))
			_o_return_result;
		if (ParamIndexToVal(3, flags))
			_o_return_result;
		if (aParamCount > 4)
			TokenToVal(*aParam[4], (char&)conjB, true);
		cv::divSpectrums(a, b, c, flags, conjB);
		return;
	}
	case FID_divide: {
		if (!MatchTypes("ooof?i")) {
			cv::_InputArray src1, src2;
			cv::_OutputArray dst;
			double scale = 1;
			int dtype = -1;
			if (ParamIndexToVal(0, src1))
				_o_return_result;
			if (ParamIndexToVal(1, src2))
				_o_return_result;
			if (ParamIndexToVal(2, dst))
				_o_return_result;
			if (aParamCount > 3)
				TokenToVal(*aParam[3], scale, true);
			if (aParamCount > 4)
				TokenToVal(*aParam[4], dtype, true);
			cv::divide(src1, src2, dst, scale, dtype);
			return;
		}
		else if (!MatchTypes("fooi?")) {
			cv::_InputArray src2;
			cv::_OutputArray dst;
			double scale;
			int dtype = -1;
			if (ParamIndexToVal(0, scale))
				_o_return_result;
			if (ParamIndexToVal(1, src2))
				_o_return_result;
			if (ParamIndexToVal(2, dst))
				_o_return_result;
			if (aParamCount > 3)
				TokenToVal(*aParam[3], dtype, true);
			cv::divide(scale, src2, dst, dtype);
			return;
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case FID_drawChessboardCorners: {
		bool patternWasFound;
		cv::_InputArray corners;
		cv::_InputOutputArray image;
		cv::Size patternSize;
		if (ParamIndexToVal(0, image))
			_o_return_result;
		if (ParamIndexToVal(1, patternSize))
			_o_return_result;
		if (ParamIndexToVal(2, corners))
			_o_return_result;
		if (ParamIndexToVal(3, (char&)patternWasFound))
			_o_return_result;
		cv::drawChessboardCorners(image, patternSize, corners, patternWasFound);
		return;
	}
	case FID_drawContours: {
		cv::_InputArray contours, hierarchy = cv::noArray();
		cv::_InputOutputArray image;
		cv::Point offset = cv::Point();
		cv::Scalar color;
		int contourIdx, thickness = 1, lineType = cv::LINE_8, maxLevel = INT_MAX;
		if (ParamIndexToVal(0, image))
			_o_return_result;
		if (ParamIndexToVal(1, contours))
			_o_return_result;
		if (ParamIndexToVal(2, contourIdx))
			_o_return_result;
		if (ParamIndexToVal(3, color))
			_o_return_result;
		if (aParamCount > 4)
			TokenToVal(*aParam[4], thickness, true);
		if (aParamCount > 5)
			TokenToVal(*aParam[5], lineType, true);
		if (aParamCount > 6)
			TokenToVal(*aParam[6], hierarchy, true);
		if (aParamCount > 7)
			TokenToVal(*aParam[7], maxLevel, true);
		if (aParamCount > 8)
			TokenToVal(*aParam[8], offset, true);
		cv::drawContours(image, contours, contourIdx, color, thickness, lineType, hierarchy, maxLevel, offset);
		return;
	}
	case FID_drawFrameAxes: {
		cv::_InputArray cameraMatrix, distCoeffs, rvec, tvec;
		cv::_InputOutputArray image;
		float length;
		int thickness = 3;
		if (ParamIndexToVal(0, image))
			_o_return_result;
		if (ParamIndexToVal(1, cameraMatrix))
			_o_return_result;
		if (ParamIndexToVal(2, distCoeffs))
			_o_return_result;
		if (ParamIndexToVal(3, rvec))
			_o_return_result;
		if (ParamIndexToVal(4, tvec))
			_o_return_result;
		if (ParamIndexToVal(5, length))
			_o_return_result;
		if (aParamCount > 6)
			TokenToVal(*aParam[6], thickness, true);
		cv::drawFrameAxes(image, cameraMatrix, distCoeffs, rvec, tvec, length, thickness);
		return;
	}
	case FID_drawKeypoints: {
		cv::_InputArray image;
		cv::_InputOutputArray outImage;
		cv::Scalar color = cv::Scalar::all(-1);
		int flags = (int)cv::DrawMatchesFlags::DEFAULT;
		std::vector<cv::KeyPoint> keypoints;
		if (ParamIndexToVal(0, image))
			_o_return_result;
		if (ParamIndexToVal(1, keypoints))
			_o_return_result;
		if (ParamIndexToVal(2, outImage))
			_o_return_result;
		if (aParamCount > 3)
			TokenToVal(*aParam[3], color, true);
		if (aParamCount > 4)
			TokenToVal(*aParam[4], flags, true);
		cv::drawKeypoints(image, keypoints, outImage, color, (cv::DrawMatchesFlags)flags);
		return;
	}
	case FID_drawMarker: {
		cv::_InputOutputArray img;
		cv::Point position;
		cv::Scalar color;
		int markerType = cv::MARKER_CROSS, markerSize = 20, thickness = 1, line_type = 8;
		if (ParamIndexToVal(0, img))
			_o_return_result;
		if (ParamIndexToVal(1, position))
			_o_return_result;
		if (ParamIndexToVal(2, color))
			_o_return_result;
		if (aParamCount > 3)
			TokenToVal(*aParam[3], markerType, true);
		if (aParamCount > 4)
			TokenToVal(*aParam[4], markerSize, true);
		if (aParamCount > 5)
			TokenToVal(*aParam[5], thickness, true);
		if (aParamCount > 6)
			TokenToVal(*aParam[6], line_type, true);
		cv::drawMarker(img, position, color, markerType, markerSize, thickness, line_type);
		return;
	}
	case FID_drawMatches: {
		if (!MatchTypes("ooooooo?ooi")) {
			cv::_InputArray img1, img2;
			cv::_InputOutputArray outImg;
			cv::Scalar matchColor = cv::Scalar::all(-1), singlePointColor = cv::Scalar::all(-1);
			int flags = (int)cv::DrawMatchesFlags::DEFAULT;
			std::vector<char> matchesMask = std::vector<char>();
			std::vector<cv::DMatch> matches1to2;
			std::vector<cv::KeyPoint> keypoints1, keypoints2;
			if (ParamIndexToVal(0, img1))
				_o_return_result;
			if (ParamIndexToVal(1, keypoints1))
				_o_return_result;
			if (ParamIndexToVal(2, img2))
				_o_return_result;
			if (ParamIndexToVal(3, keypoints2))
				_o_return_result;
			if (ParamIndexToVal(4, matches1to2))
				_o_return_result;
			if (ParamIndexToVal(5, outImg))
				_o_return_result;
			if (aParamCount > 6)
				TokenToVal(*aParam[6], matchColor, true);
			if (aParamCount > 7)
				TokenToVal(*aParam[7], singlePointColor, true);
			if (aParamCount > 8)
				TokenToVal(*aParam[8], (std::vector<uchar>&)matchesMask, true);
			if (aParamCount > 9)
				TokenToVal(*aParam[9], flags, true);
			cv::drawMatches(img1, keypoints1, img2, keypoints2, matches1to2, outImg, matchColor, singlePointColor, matchesMask, (cv::DrawMatchesFlags)flags);
			return;
		}
		else if (!MatchTypes("ooooooio?ooi")) {
			cv::_InputArray img1, img2;
			cv::_InputOutputArray outImg;
			cv::Scalar matchColor = cv::Scalar::all(-1), singlePointColor = cv::Scalar::all(-1);
			int matchesThickness, flags = (int)cv::DrawMatchesFlags::DEFAULT;
			std::vector<char> matchesMask = std::vector<char>();
			std::vector<cv::DMatch> matches1to2;
			std::vector<cv::KeyPoint> keypoints1, keypoints2;
			if (ParamIndexToVal(0, img1))
				_o_return_result;
			if (ParamIndexToVal(1, keypoints1))
				_o_return_result;
			if (ParamIndexToVal(2, img2))
				_o_return_result;
			if (ParamIndexToVal(3, keypoints2))
				_o_return_result;
			if (ParamIndexToVal(4, matches1to2))
				_o_return_result;
			if (ParamIndexToVal(5, outImg))
				_o_return_result;
			if (ParamIndexToVal(6, matchesThickness))
				_o_return_result;
			if (aParamCount > 7)
				TokenToVal(*aParam[7], matchColor, true);
			if (aParamCount > 8)
				TokenToVal(*aParam[8], singlePointColor, true);
			if (aParamCount > 9)
				TokenToVal(*aParam[9], (std::vector<uchar>&)matchesMask, true);
			if (aParamCount > 10)
				TokenToVal(*aParam[10], flags, true);
			cv::drawMatches(img1, keypoints1, img2, keypoints2, matches1to2, outImg, matchesThickness, matchColor, singlePointColor, matchesMask, (cv::DrawMatchesFlags)flags);
			return;
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case FID_drawMatches2: {
		cv::_InputArray img1, img2;
		cv::_InputOutputArray outImg;
		cv::Scalar matchColor = cv::Scalar::all(-1), singlePointColor = cv::Scalar::all(-1);
		int flags = (int)cv::DrawMatchesFlags::DEFAULT;
		std::vector<cv::KeyPoint> keypoints1, keypoints2;
		std::vector<std::vector<char>> matchesMask = std::vector<std::vector<char>>();
		std::vector<std::vector<cv::DMatch>> matches1to2;
		if (ParamIndexToVal(0, img1))
			_o_return_result;
		if (ParamIndexToVal(1, keypoints1))
			_o_return_result;
		if (ParamIndexToVal(2, img2))
			_o_return_result;
		if (ParamIndexToVal(3, keypoints2))
			_o_return_result;
		if (ParamIndexToVal(4, matches1to2))
			_o_return_result;
		if (ParamIndexToVal(5, outImg))
			_o_return_result;
		if (aParamCount > 6)
			TokenToVal(*aParam[6], matchColor, true);
		if (aParamCount > 7)
			TokenToVal(*aParam[7], singlePointColor, true);
		if (aParamCount > 8)
			TokenToVal(*aParam[8], matchesMask, true);
		if (aParamCount > 9)
			TokenToVal(*aParam[9], flags, true);
		cv::drawMatches(img1, keypoints1, img2, keypoints2, matches1to2, outImg, matchColor, singlePointColor, matchesMask, (cv::DrawMatchesFlags)flags);
		return;
	}
	case FID_edgePreservingFilter: {
		cv::_InputArray src;
		cv::_OutputArray dst;
		float sigma_s = 60, sigma_r = 0.4f;
		int flags = 1;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, dst))
			_o_return_result;
		if (aParamCount > 2)
			TokenToVal(*aParam[2], flags, true);
		if (aParamCount > 3)
			TokenToVal(*aParam[3], sigma_s, true);
		if (aParamCount > 4)
			TokenToVal(*aParam[4], sigma_r, true);
		cv::edgePreservingFilter(src, dst, flags, sigma_s, sigma_r);
		return;
	}
	case FID_eigen: {
		cv::_InputArray src;
		cv::_OutputArray eigenvalues, eigenvectors = cv::noArray();
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, eigenvalues))
			_o_return_result;
		if (aParamCount > 2)
			TokenToVal(*aParam[2], eigenvectors, true);
		auto __retval = (__int64)cv::eigen(src, eigenvalues, eigenvectors);
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_eigenNonSymmetric: {
		cv::_InputArray src;
		cv::_OutputArray eigenvalues, eigenvectors;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, eigenvalues))
			_o_return_result;
		if (ParamIndexToVal(2, eigenvectors))
			_o_return_result;
		cv::eigenNonSymmetric(src, eigenvalues, eigenvectors);
		return;
	}
	case FID_ellipse: {
		if (7 <= aParamCount && aParamCount <= 10) {
			cv::_InputOutputArray img;
			cv::Point center;
			cv::Scalar color;
			cv::Size axes;
			double angle, startAngle, endAngle;
			int thickness = 1, lineType = cv::LINE_8, shift = 0;
			if (ParamIndexToVal(0, img))
				_o_return_result;
			if (ParamIndexToVal(1, center))
				_o_return_result;
			if (ParamIndexToVal(2, axes))
				_o_return_result;
			if (ParamIndexToVal(3, angle))
				_o_return_result;
			if (ParamIndexToVal(4, startAngle))
				_o_return_result;
			if (ParamIndexToVal(5, endAngle))
				_o_return_result;
			if (ParamIndexToVal(6, color))
				_o_return_result;
			if (aParamCount > 7)
				TokenToVal(*aParam[7], thickness, true);
			if (aParamCount > 8)
				TokenToVal(*aParam[8], lineType, true);
			if (aParamCount > 9)
				TokenToVal(*aParam[9], shift, true);
			cv::ellipse(img, center, axes, angle, startAngle, endAngle, color, thickness, lineType, shift);
			return;
		}
		else if (3 <= aParamCount && aParamCount <= 5) {
			cv::_InputOutputArray img;
			cv::RotatedRect box;
			cv::Scalar color;
			int thickness = 1, lineType = cv::LINE_8;
			if (ParamIndexToVal(0, img))
				_o_return_result;
			if (ParamIndexToVal(1, box))
				_o_return_result;
			if (ParamIndexToVal(2, color))
				_o_return_result;
			if (aParamCount > 3)
				TokenToVal(*aParam[3], thickness, true);
			if (aParamCount > 4)
				TokenToVal(*aParam[4], lineType, true);
			cv::ellipse(img, box, color, thickness, lineType);
			return;
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case FID_ellipse2Poly: {
		cv::Point center;
		cv::Size axes;
		int angle, arcStart, arcEnd, delta;
		std::vector<cv::Point> pts;
		if (ParamIndexToVal(0, center))
			_o_return_result;
		if (ParamIndexToVal(1, axes))
			_o_return_result;
		if (ParamIndexToVal(2, angle))
			_o_return_result;
		if (ParamIndexToVal(3, arcStart))
			_o_return_result;
		if (ParamIndexToVal(4, arcEnd))
			_o_return_result;
		if (ParamIndexToVal(5, delta))
			_o_return_result;
		VarRef* var_pts = nullptr;
		if (ParamIndexToVal(6, var_pts))
			_o_return_result;
		cv::ellipse2Poly(center, axes, angle, arcStart, arcEnd, delta, pts);
		ValToResult(pts, aResultToken);
		g_ahkapi->VarAssign(var_pts, aResultToken);
		g_ahkapi->ResultTokenFree(aResultToken);
		return;
	}
	case FID_empty_array_desc: {
		auto __retval = (GArrayDesc*)GArrayDesc::sPrototype->New(g_invalidparam, 1);
		__retval->mC = cv::empty_array_desc();
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_empty_gopaque_desc: {
		auto __retval = (GOpaqueDesc*)GOpaqueDesc::sPrototype->New(g_invalidparam, 1);
		__retval->mC = cv::empty_gopaque_desc();
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_empty_scalar_desc: {
		auto __retval = (GScalarDesc*)GScalarDesc::sPrototype->New(g_invalidparam, 1);
		__retval->mC = cv::empty_scalar_desc();
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_equalizeHist: {
		cv::_InputArray src;
		cv::_OutputArray dst;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, dst))
			_o_return_result;
		cv::equalizeHist(src, dst);
		return;
	}
	case FID_erode: {
		cv::_InputArray src, kernel;
		cv::_OutputArray dst;
		cv::Point anchor = cv::Point(-1, -1);
		cv::Scalar borderValue = cv::morphologyDefaultBorderValue();
		int iterations = 1, borderType = cv::BORDER_CONSTANT;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, dst))
			_o_return_result;
		if (ParamIndexToVal(2, kernel))
			_o_return_result;
		if (aParamCount > 3)
			TokenToVal(*aParam[3], anchor, true);
		if (aParamCount > 4)
			TokenToVal(*aParam[4], iterations, true);
		if (aParamCount > 5)
			TokenToVal(*aParam[5], borderType, true);
		if (aParamCount > 6)
			TokenToVal(*aParam[6], borderValue, true);
		cv::erode(src, dst, kernel, anchor, iterations, borderType, borderValue);
		return;
	}
	case FID_estimateAffine2D: {
		if (!MatchTypes("ooo?ififi")) {
			cv::_InputArray from, to;
			cv::_OutputArray inliers = cv::noArray();
			double ransacReprojThreshold = 3, confidence = 0.99;
			int method = cv::RANSAC;
			size_t maxIters = 2000, refineIters = 10;
			if (ParamIndexToVal(0, from))
				_o_return_result;
			if (ParamIndexToVal(1, to))
				_o_return_result;
			if (aParamCount > 2)
				TokenToVal(*aParam[2], inliers, true);
			if (aParamCount > 3)
				TokenToVal(*aParam[3], method, true);
			if (aParamCount > 4)
				TokenToVal(*aParam[4], ransacReprojThreshold, true);
			if (aParamCount > 5)
				TokenToVal(*aParam[5], (intptr_t&)maxIters, true);
			if (aParamCount > 6)
				TokenToVal(*aParam[6], confidence, true);
			if (aParamCount > 7)
				TokenToVal(*aParam[7], (intptr_t&)refineIters, true);
			auto __retval = (Mat*)Mat::sPrototype->New(g_invalidparam, 1);
			__retval->mC = cv::estimateAffine2D(from, to, inliers, method, ransacReprojThreshold, maxIters, confidence, refineIters);
			return (void)(aResultToken.SetValue(__retval));
		}
		else if (!MatchTypes("oooo")) {
			cv::_InputArray pts1, pts2;
			cv::_OutputArray inliers;
			cv::UsacParams params;
			if (ParamIndexToVal(0, pts1))
				_o_return_result;
			if (ParamIndexToVal(1, pts2))
				_o_return_result;
			if (ParamIndexToVal(2, inliers))
				_o_return_result;
			if (ParamIndexToVal(3, params))
				_o_return_result;
			auto __retval = (Mat*)Mat::sPrototype->New(g_invalidparam, 1);
			__retval->mC = cv::estimateAffine2D(pts1, pts2, inliers, params);
			return (void)(aResultToken.SetValue(__retval));
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case FID_estimateAffine3D: {
		if (!MatchTypes("oooof?f")) {
			cv::_InputArray src, dst;
			cv::_OutputArray out, inliers;
			double ransacThreshold = 3, confidence = 0.99;
			if (ParamIndexToVal(0, src))
				_o_return_result;
			if (ParamIndexToVal(1, dst))
				_o_return_result;
			if (ParamIndexToVal(2, out))
				_o_return_result;
			if (ParamIndexToVal(3, inliers))
				_o_return_result;
			if (aParamCount > 4)
				TokenToVal(*aParam[4], ransacThreshold, true);
			if (aParamCount > 5)
				TokenToVal(*aParam[5], confidence, true);
			auto __retval = (__int64)cv::estimateAffine3D(src, dst, out, inliers, ransacThreshold, confidence);
			return (void)(aResultToken.SetValue(__retval));
		}
		else if (!MatchTypes("ooo?i")) {
			bool force_rotation = true;
			cv::_InputArray src, dst;
			double scale;
			if (ParamIndexToVal(0, src))
				_o_return_result;
			if (ParamIndexToVal(1, dst))
				_o_return_result;
			VarRef* var_scale = nullptr;
			if (aParamCount > 2) {
				TokenToVal(*aParam[2], var_scale, true);
			}
			if (aParamCount > 3)
				TokenToVal(*aParam[3], (char&)force_rotation, true);
			auto __retval = (Mat*)Mat::sPrototype->New(g_invalidparam, 1);
			__retval->mC = cv::estimateAffine3D(src, dst, &scale, force_rotation);
			if (var_scale) g_ahkapi->VarAssign(var_scale, ExprTokenType((double)scale));
			return (void)(aResultToken.SetValue(__retval));
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case FID_estimateAffinePartial2D: {
		cv::_InputArray from, to;
		cv::_OutputArray inliers = cv::noArray();
		double ransacReprojThreshold = 3, confidence = 0.99;
		int method = cv::RANSAC;
		size_t maxIters = 2000, refineIters = 10;
		if (ParamIndexToVal(0, from))
			_o_return_result;
		if (ParamIndexToVal(1, to))
			_o_return_result;
		if (aParamCount > 2)
			TokenToVal(*aParam[2], inliers, true);
		if (aParamCount > 3)
			TokenToVal(*aParam[3], method, true);
		if (aParamCount > 4)
			TokenToVal(*aParam[4], ransacReprojThreshold, true);
		if (aParamCount > 5)
			TokenToVal(*aParam[5], (intptr_t&)maxIters, true);
		if (aParamCount > 6)
			TokenToVal(*aParam[6], confidence, true);
		if (aParamCount > 7)
			TokenToVal(*aParam[7], (intptr_t&)refineIters, true);
		auto __retval = (Mat*)Mat::sPrototype->New(g_invalidparam, 1);
		__retval->mC = cv::estimateAffinePartial2D(from, to, inliers, method, ransacReprojThreshold, maxIters, confidence, refineIters);
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_estimateChessboardSharpness: {
		bool vertical = false;
		cv::_InputArray image, corners;
		cv::_OutputArray sharpness = cv::noArray();
		cv::Size patternSize;
		float rise_distance = 0.8F;
		if (ParamIndexToVal(0, image))
			_o_return_result;
		if (ParamIndexToVal(1, patternSize))
			_o_return_result;
		if (ParamIndexToVal(2, corners))
			_o_return_result;
		if (aParamCount > 3)
			TokenToVal(*aParam[3], rise_distance, true);
		if (aParamCount > 4)
			TokenToVal(*aParam[4], (char&)vertical, true);
		if (aParamCount > 5)
			TokenToVal(*aParam[5], sharpness, true);
		auto __retval = cv::estimateChessboardSharpness(image, patternSize, corners, rise_distance, vertical, sharpness);
		return ValToResult(__retval, aResultToken);
	}
	case FID_estimateTranslation3D: {
		cv::_InputArray src, dst;
		cv::_OutputArray out, inliers;
		double ransacThreshold = 3, confidence = 0.99;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, dst))
			_o_return_result;
		if (ParamIndexToVal(2, out))
			_o_return_result;
		if (ParamIndexToVal(3, inliers))
			_o_return_result;
		if (aParamCount > 4)
			TokenToVal(*aParam[4], ransacThreshold, true);
		if (aParamCount > 5)
			TokenToVal(*aParam[5], confidence, true);
		auto __retval = (__int64)cv::estimateTranslation3D(src, dst, out, inliers, ransacThreshold, confidence);
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_exp: {
		cv::_InputArray src;
		cv::_OutputArray dst;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, dst))
			_o_return_result;
		cv::exp(src, dst);
		return;
	}
	case FID_extractChannel: {
		cv::_InputArray src;
		cv::_OutputArray dst;
		int coi;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, dst))
			_o_return_result;
		if (ParamIndexToVal(2, coi))
			_o_return_result;
		cv::extractChannel(src, dst, coi);
		return;
	}
	case FID_fastAtan2: {
		float y, x;
		if (ParamIndexToVal(0, y))
			_o_return_result;
		if (ParamIndexToVal(1, x))
			_o_return_result;
		auto __retval = (double)cv::fastAtan2(y, x);
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_fastNlMeansDenoising: {
		if (!MatchTypes("oof?ii")) {
			cv::_InputArray src;
			cv::_OutputArray dst;
			float h = 3;
			int templateWindowSize = 7, searchWindowSize = 21;
			if (ParamIndexToVal(0, src))
				_o_return_result;
			if (ParamIndexToVal(1, dst))
				_o_return_result;
			if (aParamCount > 2)
				TokenToVal(*aParam[2], h, true);
			if (aParamCount > 3)
				TokenToVal(*aParam[3], templateWindowSize, true);
			if (aParamCount > 4)
				TokenToVal(*aParam[4], searchWindowSize, true);
			cv::fastNlMeansDenoising(src, dst, h, templateWindowSize, searchWindowSize);
			return;
		}
		else if (!MatchTypes("oooi?ii")) {
			cv::_InputArray src;
			cv::_OutputArray dst;
			int templateWindowSize = 7, searchWindowSize = 21, normType = cv::NORM_L2;
			std::vector<float> h;
			if (ParamIndexToVal(0, src))
				_o_return_result;
			if (ParamIndexToVal(1, dst))
				_o_return_result;
			if (ParamIndexToVal(2, h))
				_o_return_result;
			if (aParamCount > 3)
				TokenToVal(*aParam[3], templateWindowSize, true);
			if (aParamCount > 4)
				TokenToVal(*aParam[4], searchWindowSize, true);
			if (aParamCount > 5)
				TokenToVal(*aParam[5], normType, true);
			cv::fastNlMeansDenoising(src, dst, h, templateWindowSize, searchWindowSize, normType);
			return;
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case FID_fastNlMeansDenoisingColored: {
		cv::_InputArray src;
		cv::_OutputArray dst;
		float h = 3, hColor = 3;
		int templateWindowSize = 7, searchWindowSize = 21;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, dst))
			_o_return_result;
		if (aParamCount > 2)
			TokenToVal(*aParam[2], h, true);
		if (aParamCount > 3)
			TokenToVal(*aParam[3], hColor, true);
		if (aParamCount > 4)
			TokenToVal(*aParam[4], templateWindowSize, true);
		if (aParamCount > 5)
			TokenToVal(*aParam[5], searchWindowSize, true);
		cv::fastNlMeansDenoisingColored(src, dst, h, hColor, templateWindowSize, searchWindowSize);
		return;
	}
	case FID_fastNlMeansDenoisingColoredMulti: {
		cv::_InputArray srcImgs;
		cv::_OutputArray dst;
		float h = 3, hColor = 3;
		int imgToDenoiseIndex, temporalWindowSize, templateWindowSize = 7, searchWindowSize = 21;
		if (ParamIndexToVal(0, srcImgs))
			_o_return_result;
		if (ParamIndexToVal(1, dst))
			_o_return_result;
		if (ParamIndexToVal(2, imgToDenoiseIndex))
			_o_return_result;
		if (ParamIndexToVal(3, temporalWindowSize))
			_o_return_result;
		if (aParamCount > 4)
			TokenToVal(*aParam[4], h, true);
		if (aParamCount > 5)
			TokenToVal(*aParam[5], hColor, true);
		if (aParamCount > 6)
			TokenToVal(*aParam[6], templateWindowSize, true);
		if (aParamCount > 7)
			TokenToVal(*aParam[7], searchWindowSize, true);
		cv::fastNlMeansDenoisingColoredMulti(srcImgs, dst, imgToDenoiseIndex, temporalWindowSize, h, hColor, templateWindowSize, searchWindowSize);
		return;
	}
	case FID_fastNlMeansDenoisingMulti: {
		if (!MatchTypes("ooiif?ii")) {
			cv::_InputArray srcImgs;
			cv::_OutputArray dst;
			float h = 3;
			int imgToDenoiseIndex, temporalWindowSize, templateWindowSize = 7, searchWindowSize = 21;
			if (ParamIndexToVal(0, srcImgs))
				_o_return_result;
			if (ParamIndexToVal(1, dst))
				_o_return_result;
			if (ParamIndexToVal(2, imgToDenoiseIndex))
				_o_return_result;
			if (ParamIndexToVal(3, temporalWindowSize))
				_o_return_result;
			if (aParamCount > 4)
				TokenToVal(*aParam[4], h, true);
			if (aParamCount > 5)
				TokenToVal(*aParam[5], templateWindowSize, true);
			if (aParamCount > 6)
				TokenToVal(*aParam[6], searchWindowSize, true);
			cv::fastNlMeansDenoisingMulti(srcImgs, dst, imgToDenoiseIndex, temporalWindowSize, h, templateWindowSize, searchWindowSize);
			return;
		}
		else if (!MatchTypes("ooiioi?ii")) {
			cv::_InputArray srcImgs;
			cv::_OutputArray dst;
			int imgToDenoiseIndex, temporalWindowSize, templateWindowSize = 7, searchWindowSize = 21, normType = cv::NORM_L2;
			std::vector<float> h;
			if (ParamIndexToVal(0, srcImgs))
				_o_return_result;
			if (ParamIndexToVal(1, dst))
				_o_return_result;
			if (ParamIndexToVal(2, imgToDenoiseIndex))
				_o_return_result;
			if (ParamIndexToVal(3, temporalWindowSize))
				_o_return_result;
			if (ParamIndexToVal(4, h))
				_o_return_result;
			if (aParamCount > 5)
				TokenToVal(*aParam[5], templateWindowSize, true);
			if (aParamCount > 6)
				TokenToVal(*aParam[6], searchWindowSize, true);
			if (aParamCount > 7)
				TokenToVal(*aParam[7], normType, true);
			cv::fastNlMeansDenoisingMulti(srcImgs, dst, imgToDenoiseIndex, temporalWindowSize, h, templateWindowSize, searchWindowSize, normType);
			return;
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case FID_fillConvexPoly: {
		cv::_InputArray points;
		cv::_InputOutputArray img;
		cv::Scalar color;
		int lineType = cv::LINE_8, shift = 0;
		if (ParamIndexToVal(0, img))
			_o_return_result;
		if (ParamIndexToVal(1, points))
			_o_return_result;
		if (ParamIndexToVal(2, color))
			_o_return_result;
		if (aParamCount > 3)
			TokenToVal(*aParam[3], lineType, true);
		if (aParamCount > 4)
			TokenToVal(*aParam[4], shift, true);
		cv::fillConvexPoly(img, points, color, lineType, shift);
		return;
	}
	case FID_fillPoly: {
		cv::_InputArray pts;
		cv::_InputOutputArray img;
		cv::Point offset = cv::Point();
		cv::Scalar color;
		int lineType = cv::LINE_8, shift = 0;
		if (ParamIndexToVal(0, img))
			_o_return_result;
		if (ParamIndexToVal(1, pts))
			_o_return_result;
		if (ParamIndexToVal(2, color))
			_o_return_result;
		if (aParamCount > 3)
			TokenToVal(*aParam[3], lineType, true);
		if (aParamCount > 4)
			TokenToVal(*aParam[4], shift, true);
		if (aParamCount > 5)
			TokenToVal(*aParam[5], offset, true);
		cv::fillPoly(img, pts, color, lineType, shift, offset);
		return;
	}
	case FID_filter2D: {
		cv::_InputArray src, kernel;
		cv::_OutputArray dst;
		cv::Point anchor = cv::Point(-1, -1);
		double delta = 0;
		int ddepth, borderType = cv::BORDER_DEFAULT;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, dst))
			_o_return_result;
		if (ParamIndexToVal(2, ddepth))
			_o_return_result;
		if (ParamIndexToVal(3, kernel))
			_o_return_result;
		if (aParamCount > 4)
			TokenToVal(*aParam[4], anchor, true);
		if (aParamCount > 5)
			TokenToVal(*aParam[5], delta, true);
		if (aParamCount > 6)
			TokenToVal(*aParam[6], borderType, true);
		cv::filter2D(src, dst, ddepth, kernel, anchor, delta, borderType);
		return;
	}
	case FID_filterHomographyDecompByVisibleRefpoints: {
		cv::_InputArray rotations, normals, beforePoints, afterPoints, pointsMask = cv::noArray();
		cv::_OutputArray possibleSolutions;
		if (ParamIndexToVal(0, rotations))
			_o_return_result;
		if (ParamIndexToVal(1, normals))
			_o_return_result;
		if (ParamIndexToVal(2, beforePoints))
			_o_return_result;
		if (ParamIndexToVal(3, afterPoints))
			_o_return_result;
		if (ParamIndexToVal(4, possibleSolutions))
			_o_return_result;
		if (aParamCount > 5)
			TokenToVal(*aParam[5], pointsMask, true);
		cv::filterHomographyDecompByVisibleRefpoints(rotations, normals, beforePoints, afterPoints, possibleSolutions, pointsMask);
		return;
	}
	case FID_filterSpeckles: {
		cv::_InputOutputArray img, buf = cv::noArray();
		double newVal, maxDiff;
		int maxSpeckleSize;
		if (ParamIndexToVal(0, img))
			_o_return_result;
		if (ParamIndexToVal(1, newVal))
			_o_return_result;
		if (ParamIndexToVal(2, maxSpeckleSize))
			_o_return_result;
		if (ParamIndexToVal(3, maxDiff))
			_o_return_result;
		if (aParamCount > 4)
			TokenToVal(*aParam[4], buf, true);
		cv::filterSpeckles(img, newVal, maxSpeckleSize, maxDiff, buf);
		return;
	}
	case FID_find4QuadCornerSubpix: {
		cv::_InputArray img;
		cv::_InputOutputArray corners;
		cv::Size region_size;
		if (ParamIndexToVal(0, img))
			_o_return_result;
		if (ParamIndexToVal(1, corners))
			_o_return_result;
		if (ParamIndexToVal(2, region_size))
			_o_return_result;
		auto __retval = (__int64)cv::find4QuadCornerSubpix(img, corners, region_size);
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_findChessboardCorners: {
		cv::_InputArray image;
		cv::_OutputArray corners;
		cv::Size patternSize;
		int flags = cv::CALIB_CB_ADAPTIVE_THRESH + cv::CALIB_CB_NORMALIZE_IMAGE;
		if (ParamIndexToVal(0, image))
			_o_return_result;
		if (ParamIndexToVal(1, patternSize))
			_o_return_result;
		if (ParamIndexToVal(2, corners))
			_o_return_result;
		if (aParamCount > 3)
			TokenToVal(*aParam[3], flags, true);
		auto __retval = (__int64)cv::findChessboardCorners(image, patternSize, corners, flags);
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_findChessboardCornersSB: {
		if (aParamCount == 5) {
			cv::_InputArray image;
			cv::_OutputArray corners, meta;
			cv::Size patternSize;
			int flags;
			if (ParamIndexToVal(0, image))
				_o_return_result;
			if (ParamIndexToVal(1, patternSize))
				_o_return_result;
			if (ParamIndexToVal(2, corners))
				_o_return_result;
			if (ParamIndexToVal(3, flags))
				_o_return_result;
			if (ParamIndexToVal(4, meta))
				_o_return_result;
			auto __retval = (__int64)cv::findChessboardCornersSB(image, patternSize, corners, flags, meta);
			return (void)(aResultToken.SetValue(__retval));
		}
		else if (3 <= aParamCount && aParamCount <= 4) {
			cv::_InputArray image;
			cv::_OutputArray corners;
			cv::Size patternSize;
			int flags = 0;
			if (ParamIndexToVal(0, image))
				_o_return_result;
			if (ParamIndexToVal(1, patternSize))
				_o_return_result;
			if (ParamIndexToVal(2, corners))
				_o_return_result;
			if (aParamCount > 3)
				TokenToVal(*aParam[3], flags, true);
			auto __retval = (__int64)cv::findChessboardCornersSB(image, patternSize, corners, flags);
			return (void)(aResultToken.SetValue(__retval));
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case FID_findCirclesGrid: {
		if (aParamCount == 6) {
			cv::CirclesGridFinderParameters parameters;
			cv::_InputArray image;
			cv::_OutputArray centers;
			cv::Ptr<cv::FeatureDetector> blobDetector;
			cv::Size patternSize;
			int flags;
			if (ParamIndexToVal(0, image))
				_o_return_result;
			if (ParamIndexToVal(1, patternSize))
				_o_return_result;
			if (ParamIndexToVal(2, centers))
				_o_return_result;
			if (ParamIndexToVal(3, flags))
				_o_return_result;
			if (ParamIndexToVal(4, blobDetector))
				_o_return_result;
			if (ParamIndexToVal(5, parameters))
				_o_return_result;
			auto __retval = (__int64)cv::findCirclesGrid(image, patternSize, centers, flags, blobDetector, parameters);
			return (void)(aResultToken.SetValue(__retval));
		}
		else if (3 <= aParamCount && aParamCount <= 5) {
			cv::_InputArray image;
			cv::_OutputArray centers;
			cv::Ptr<cv::FeatureDetector> blobDetector = cv::SimpleBlobDetector::create();
			cv::Size patternSize;
			int flags = cv::CALIB_CB_SYMMETRIC_GRID;
			if (ParamIndexToVal(0, image))
				_o_return_result;
			if (ParamIndexToVal(1, patternSize))
				_o_return_result;
			if (ParamIndexToVal(2, centers))
				_o_return_result;
			if (aParamCount > 3)
				TokenToVal(*aParam[3], flags, true);
			if (aParamCount > 4)
				TokenToVal(*aParam[4], blobDetector, true);
			auto __retval = (__int64)cv::findCirclesGrid(image, patternSize, centers, flags, blobDetector);
			return (void)(aResultToken.SetValue(__retval));
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case FID_findContours: {
		cv::_InputArray image;
		cv::_OutputArray contours, hierarchy;
		cv::Point offset = cv::Point();
		int mode, method;
		if (ParamIndexToVal(0, image))
			_o_return_result;
		if (ParamIndexToVal(1, contours))
			_o_return_result;
		if (aParamCount > 4 && TokenToObject(*aParam[2])) {
			if (ParamIndexToVal(2, hierarchy))
				_o_return_result;
			if (ParamIndexToVal(3, mode))
				_o_return_result;
			if (ParamIndexToVal(4, method))
				_o_return_result;
			if (aParamCount > 5)
				TokenToVal(*aParam[5], offset, true);
			cv::findContours(image, contours, hierarchy, mode, method, offset);
		}
		else {
			if (ParamIndexToVal(2, mode))
				_o_return_result;
			if (ParamIndexToVal(3, method))
				_o_return_result;
			if (aParamCount > 4)
				TokenToVal(*aParam[4], offset, true);
			cv::findContours(image, contours, mode, method, offset);
		}
		return;
	}
	case FID_findEssentialMat: {
		if (!MatchTypes("oooi?ffio")) {
			cv::_InputArray points1, points2, cameraMatrix;
			cv::_OutputArray mask = cv::noArray();
			double prob = 0.999, threshold = 1.0;
			int method = cv::RANSAC, maxIters = 1000;
			if (ParamIndexToVal(0, points1))
				_o_return_result;
			if (ParamIndexToVal(1, points2))
				_o_return_result;
			if (ParamIndexToVal(2, cameraMatrix))
				_o_return_result;
			if (aParamCount > 3)
				TokenToVal(*aParam[3], method, true);
			if (aParamCount > 4)
				TokenToVal(*aParam[4], prob, true);
			if (aParamCount > 5)
				TokenToVal(*aParam[5], threshold, true);
			if (aParamCount > 6)
				TokenToVal(*aParam[6], maxIters, true);
			if (aParamCount > 7)
				TokenToVal(*aParam[7], mask, true);
			auto __retval = (Mat*)Mat::sPrototype->New(g_invalidparam, 1);
			__retval->mC = cv::findEssentialMat(points1, points2, cameraMatrix, method, prob, threshold, maxIters, mask);
			return (void)(aResultToken.SetValue(__retval));
		}
		else if (!MatchTypes("oof?oiffio")) {
			cv::_InputArray points1, points2;
			cv::_OutputArray mask = cv::noArray();
			cv::Point2d pp = cv::Point2d(0, 0);
			double focal = 1.0, prob = 0.999, threshold = 1.0;
			int method = cv::RANSAC, maxIters = 1000;
			if (ParamIndexToVal(0, points1))
				_o_return_result;
			if (ParamIndexToVal(1, points2))
				_o_return_result;
			if (aParamCount > 2)
				TokenToVal(*aParam[2], focal, true);
			if (aParamCount > 3)
				TokenToVal(*aParam[3], pp, true);
			if (aParamCount > 4)
				TokenToVal(*aParam[4], method, true);
			if (aParamCount > 5)
				TokenToVal(*aParam[5], prob, true);
			if (aParamCount > 6)
				TokenToVal(*aParam[6], threshold, true);
			if (aParamCount > 7)
				TokenToVal(*aParam[7], maxIters, true);
			if (aParamCount > 8)
				TokenToVal(*aParam[8], mask, true);
			auto __retval = (Mat*)Mat::sPrototype->New(g_invalidparam, 1);
			__retval->mC = cv::findEssentialMat(points1, points2, focal, pp, method, prob, threshold, maxIters, mask);
			return (void)(aResultToken.SetValue(__retval));
		}
		else if (!MatchTypes("ooooooi?ffo")) {
			cv::_InputArray points1, points2, cameraMatrix1, distCoeffs1, cameraMatrix2, distCoeffs2;
			cv::_OutputArray mask = cv::noArray();
			double prob = 0.999, threshold = 1.0;
			int method = cv::RANSAC;
			if (ParamIndexToVal(0, points1))
				_o_return_result;
			if (ParamIndexToVal(1, points2))
				_o_return_result;
			if (ParamIndexToVal(2, cameraMatrix1))
				_o_return_result;
			if (ParamIndexToVal(3, distCoeffs1))
				_o_return_result;
			if (ParamIndexToVal(4, cameraMatrix2))
				_o_return_result;
			if (ParamIndexToVal(5, distCoeffs2))
				_o_return_result;
			if (aParamCount > 6)
				TokenToVal(*aParam[6], method, true);
			if (aParamCount > 7)
				TokenToVal(*aParam[7], prob, true);
			if (aParamCount > 8)
				TokenToVal(*aParam[8], threshold, true);
			if (aParamCount > 9)
				TokenToVal(*aParam[9], mask, true);
			auto __retval = (Mat*)Mat::sPrototype->New(g_invalidparam, 1);
			__retval->mC = cv::findEssentialMat(points1, points2, cameraMatrix1, distCoeffs1, cameraMatrix2, distCoeffs2, method, prob, threshold, mask);
			return (void)(aResultToken.SetValue(__retval));
		}
		else if (!MatchTypes("oooooooo")) {
			cv::_InputArray points1, points2, cameraMatrix1, cameraMatrix2, dist_coeff1, dist_coeff2;
			cv::_OutputArray mask;
			cv::UsacParams params;
			if (ParamIndexToVal(0, points1))
				_o_return_result;
			if (ParamIndexToVal(1, points2))
				_o_return_result;
			if (ParamIndexToVal(2, cameraMatrix1))
				_o_return_result;
			if (ParamIndexToVal(3, cameraMatrix2))
				_o_return_result;
			if (ParamIndexToVal(4, dist_coeff1))
				_o_return_result;
			if (ParamIndexToVal(5, dist_coeff2))
				_o_return_result;
			if (ParamIndexToVal(6, mask))
				_o_return_result;
			if (ParamIndexToVal(7, params))
				_o_return_result;
			auto __retval = (Mat*)Mat::sPrototype->New(g_invalidparam, 1);
			__retval->mC = cv::findEssentialMat(points1, points2, cameraMatrix1, cameraMatrix2, dist_coeff1, dist_coeff2, mask, params);
			return (void)(aResultToken.SetValue(__retval));
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case FID_findFundamentalMat: {
		if (!MatchTypes("ooiffio?")) {
			cv::_InputArray points1, points2;
			cv::_OutputArray mask = cv::noArray();
			double ransacReprojThreshold, confidence;
			int method, maxIters;
			if (ParamIndexToVal(0, points1))
				_o_return_result;
			if (ParamIndexToVal(1, points2))
				_o_return_result;
			if (ParamIndexToVal(2, method))
				_o_return_result;
			if (ParamIndexToVal(3, ransacReprojThreshold))
				_o_return_result;
			if (ParamIndexToVal(4, confidence))
				_o_return_result;
			if (ParamIndexToVal(5, maxIters))
				_o_return_result;
			if (aParamCount > 6)
				TokenToVal(*aParam[6], mask, true);
			auto __retval = (Mat*)Mat::sPrototype->New(g_invalidparam, 1);
			__retval->mC = cv::findFundamentalMat(points1, points2, method, ransacReprojThreshold, confidence, maxIters, mask);
			return (void)(aResultToken.SetValue(__retval));
		}
		else if (!MatchTypes("ooi?ffo")) {
			cv::_InputArray points1, points2;
			cv::_OutputArray mask = cv::noArray();
			double ransacReprojThreshold = 3., confidence = 0.99;
			int method = cv::FM_RANSAC;
			if (ParamIndexToVal(0, points1))
				_o_return_result;
			if (ParamIndexToVal(1, points2))
				_o_return_result;
			if (aParamCount > 2)
				TokenToVal(*aParam[2], method, true);
			if (aParamCount > 3)
				TokenToVal(*aParam[3], ransacReprojThreshold, true);
			if (aParamCount > 4)
				TokenToVal(*aParam[4], confidence, true);
			if (aParamCount > 5)
				TokenToVal(*aParam[5], mask, true);
			auto __retval = (Mat*)Mat::sPrototype->New(g_invalidparam, 1);
			__retval->mC = cv::findFundamentalMat(points1, points2, method, ransacReprojThreshold, confidence, mask);
			return (void)(aResultToken.SetValue(__retval));
		}
		else if (!MatchTypes("oooo")) {
			cv::_InputArray points1, points2;
			cv::_OutputArray mask;
			cv::UsacParams params;
			if (ParamIndexToVal(0, points1))
				_o_return_result;
			if (ParamIndexToVal(1, points2))
				_o_return_result;
			if (ParamIndexToVal(2, mask))
				_o_return_result;
			if (ParamIndexToVal(3, params))
				_o_return_result;
			auto __retval = (Mat*)Mat::sPrototype->New(g_invalidparam, 1);
			__retval->mC = cv::findFundamentalMat(points1, points2, mask, params);
			return (void)(aResultToken.SetValue(__retval));
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case FID_findHomography: {
		if (!MatchTypes("ooi?foif")) {
			cv::_InputArray srcPoints, dstPoints;
			cv::_OutputArray mask = cv::noArray();
			double ransacReprojThreshold = 3, confidence = 0.995;
			int method = 0, maxIters = 2000;
			if (ParamIndexToVal(0, srcPoints))
				_o_return_result;
			if (ParamIndexToVal(1, dstPoints))
				_o_return_result;
			if (aParamCount > 2)
				TokenToVal(*aParam[2], method, true);
			if (aParamCount > 3)
				TokenToVal(*aParam[3], ransacReprojThreshold, true);
			if (aParamCount > 4)
				TokenToVal(*aParam[4], mask, true);
			if (aParamCount > 5)
				TokenToVal(*aParam[5], maxIters, true);
			if (aParamCount > 6)
				TokenToVal(*aParam[6], confidence, true);
			auto __retval = (Mat*)Mat::sPrototype->New(g_invalidparam, 1);
			__retval->mC = cv::findHomography(srcPoints, dstPoints, method, ransacReprojThreshold, mask, maxIters, confidence);
			return (void)(aResultToken.SetValue(__retval));
		}
		else if (!MatchTypes("oooo")) {
			cv::_InputArray srcPoints, dstPoints;
			cv::_OutputArray mask;
			cv::UsacParams params;
			if (ParamIndexToVal(0, srcPoints))
				_o_return_result;
			if (ParamIndexToVal(1, dstPoints))
				_o_return_result;
			if (ParamIndexToVal(2, mask))
				_o_return_result;
			if (ParamIndexToVal(3, params))
				_o_return_result;
			auto __retval = (Mat*)Mat::sPrototype->New(g_invalidparam, 1);
			__retval->mC = cv::findHomography(srcPoints, dstPoints, mask, params);
			return (void)(aResultToken.SetValue(__retval));
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case FID_findNonZero: {
		cv::_InputArray src;
		cv::_OutputArray idx;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, idx))
			_o_return_result;
		cv::findNonZero(src, idx);
		return;
	}
	case FID_findTransformECC: {
		if (aParamCount == 7) {
			cv::_InputArray templateImage, inputImage, inputMask;
			cv::_InputOutputArray warpMatrix;
			cv::TermCriteria criteria;
			int motionType, gaussFiltSize;
			if (ParamIndexToVal(0, templateImage))
				_o_return_result;
			if (ParamIndexToVal(1, inputImage))
				_o_return_result;
			if (ParamIndexToVal(2, warpMatrix))
				_o_return_result;
			if (ParamIndexToVal(3, motionType))
				_o_return_result;
			if (ParamIndexToVal(4, criteria))
				_o_return_result;
			if (ParamIndexToVal(5, inputMask))
				_o_return_result;
			if (ParamIndexToVal(6, gaussFiltSize))
				_o_return_result;
			auto __retval = cv::findTransformECC(templateImage, inputImage, warpMatrix, motionType, criteria, inputMask, gaussFiltSize);
			return (void)(aResultToken.SetValue(__retval));
		}
		else if (3 <= aParamCount && aParamCount <= 6) {
			cv::_InputArray templateImage, inputImage, inputMask = cv::noArray();
			cv::_InputOutputArray warpMatrix;
			cv::TermCriteria criteria = cv::TermCriteria(cv::TermCriteria::COUNT + cv::TermCriteria::EPS, 50, 0.001);
			;
			int motionType = cv::MOTION_AFFINE;
			if (ParamIndexToVal(0, templateImage))
				_o_return_result;
			if (ParamIndexToVal(1, inputImage))
				_o_return_result;
			if (ParamIndexToVal(2, warpMatrix))
				_o_return_result;
			if (aParamCount > 3)
				TokenToVal(*aParam[3], motionType, true);
			if (aParamCount > 4)
				TokenToVal(*aParam[4], criteria, true);
			if (aParamCount > 5)
				TokenToVal(*aParam[5], inputMask, true);
			auto __retval = cv::findTransformECC(templateImage, inputImage, warpMatrix, motionType, criteria, inputMask);
			return (void)(aResultToken.SetValue(__retval));
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case FID_fitEllipse: {
		cv::_InputArray points;
		if (ParamIndexToVal(0, points))
			_o_return_result;
		auto __retval = cv::fitEllipse(points);
		return ValToResult(__retval, aResultToken);
	}
	case FID_fitEllipseAMS: {
		cv::_InputArray points;
		if (ParamIndexToVal(0, points))
			_o_return_result;
		auto __retval = cv::fitEllipseAMS(points);
		return ValToResult(__retval, aResultToken);
	}
	case FID_fitEllipseDirect: {
		cv::_InputArray points;
		if (ParamIndexToVal(0, points))
			_o_return_result;
		auto __retval = cv::fitEllipseDirect(points);
		return ValToResult(__retval, aResultToken);
	}
	case FID_fitLine: {
		cv::_InputArray points;
		cv::_OutputArray line;
		double param, reps, aeps;
		int distType;
		if (ParamIndexToVal(0, points))
			_o_return_result;
		if (ParamIndexToVal(1, line))
			_o_return_result;
		if (ParamIndexToVal(2, distType))
			_o_return_result;
		if (ParamIndexToVal(3, param))
			_o_return_result;
		if (ParamIndexToVal(4, reps))
			_o_return_result;
		if (ParamIndexToVal(5, aeps))
			_o_return_result;
		cv::fitLine(points, line, distType, param, reps, aeps);
		return;
	}
	case FID_flip: {
		cv::_InputArray src;
		cv::_OutputArray dst;
		int flipCode;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, dst))
			_o_return_result;
		if (ParamIndexToVal(2, flipCode))
			_o_return_result;
		cv::flip(src, dst, flipCode);
		return;
	}
	case FID_floodFill: {
		cv::_InputOutputArray image, mask;
		cv::Point seedPoint;
		cv::Rect rect;
		cv::Scalar newVal, loDiff = cv::Scalar(), upDiff = cv::Scalar();
		int flags = 4;
		if (ParamIndexToVal(0, image))
			_o_return_result;
		if (ParamIndexToVal(1, mask))
			_o_return_result;
		if (ParamIndexToVal(2, seedPoint))
			_o_return_result;
		if (ParamIndexToVal(3, newVal))
			_o_return_result;
		VarRef* var_rect = nullptr;
		if (aParamCount > 4) {
			TokenToVal(*aParam[4], var_rect, true);
		}
		if (aParamCount > 5)
			TokenToVal(*aParam[5], loDiff, true);
		if (aParamCount > 6)
			TokenToVal(*aParam[6], upDiff, true);
		if (aParamCount > 7)
			TokenToVal(*aParam[7], flags, true);
		auto __retval = (__int64)cv::floodFill(image, mask, seedPoint, newVal, &rect, loDiff, upDiff, flags);
		if (var_rect) {
			ValToResult(rect, aResultToken);
			g_ahkapi->VarAssign(var_rect, aResultToken);
			g_ahkapi->ResultTokenFree(aResultToken);
		}
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_gemm: {
		cv::_InputArray src1, src2, src3;
		cv::_OutputArray dst;
		double alpha, beta;
		int flags = 0;
		if (ParamIndexToVal(0, src1))
			_o_return_result;
		if (ParamIndexToVal(1, src2))
			_o_return_result;
		if (ParamIndexToVal(2, alpha))
			_o_return_result;
		if (ParamIndexToVal(3, src3))
			_o_return_result;
		if (ParamIndexToVal(4, beta))
			_o_return_result;
		if (ParamIndexToVal(5, dst))
			_o_return_result;
		if (aParamCount > 6)
			TokenToVal(*aParam[6], flags, true);
		cv::gemm(src1, src2, alpha, src3, beta, dst, flags);
		return;
	}
	}
}

BIF_DECL(CV_FUNC2) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aResultToken.func->mFID) {
	case FID_getAffineTransform: {
		cv::_InputArray src, dst;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, dst))
			_o_return_result;
		auto __retval = (Mat*)Mat::sPrototype->New(g_invalidparam, 1);
		__retval->mC = cv::getAffineTransform(src, dst);
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_getBuildInformation: {
		auto __retval = cv::getBuildInformation();
		return ValToResult(__retval, aResultToken);
	}
	case FID_getCPUFeaturesLine: {
		auto __retval = cv::getCPUFeaturesLine();
		return ValToResult(__retval, aResultToken);
	}
	case FID_getCPUTickCount: {
		auto __retval = cv::getCPUTickCount();
		return ValToResult(__retval, aResultToken);
	}
	case FID_getDefaultNewCameraMatrix: {
		bool centerPrincipalPoint = false;
		cv::_InputArray cameraMatrix;
		cv::Size imgsize = cv::Size();
		if (ParamIndexToVal(0, cameraMatrix))
			_o_return_result;
		if (aParamCount > 1)
			TokenToVal(*aParam[1], imgsize, true);
		if (aParamCount > 2)
			TokenToVal(*aParam[2], (char&)centerPrincipalPoint, true);
		auto __retval = (Mat*)Mat::sPrototype->New(g_invalidparam, 1);
		__retval->mC = cv::getDefaultNewCameraMatrix(cameraMatrix, imgsize, centerPrincipalPoint);
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_getDerivKernels: {
		bool normalize = false;
		cv::_OutputArray kx, ky;
		int dx, dy, ksize, ktype = CV_32F;
		if (ParamIndexToVal(0, kx))
			_o_return_result;
		if (ParamIndexToVal(1, ky))
			_o_return_result;
		if (ParamIndexToVal(2, dx))
			_o_return_result;
		if (ParamIndexToVal(3, dy))
			_o_return_result;
		if (ParamIndexToVal(4, ksize))
			_o_return_result;
		if (aParamCount > 5)
			TokenToVal(*aParam[5], (char&)normalize, true);
		if (aParamCount > 6)
			TokenToVal(*aParam[6], ktype, true);
		cv::getDerivKernels(kx, ky, dx, dy, ksize, normalize, ktype);
		return;
	}
	case FID_getFontScaleFromHeight: {
		int fontFace, pixelHeight, thickness = 1;
		if (ParamIndexToVal(0, fontFace))
			_o_return_result;
		if (ParamIndexToVal(1, pixelHeight))
			_o_return_result;
		if (aParamCount > 2)
			TokenToVal(*aParam[2], thickness, true);
		auto __retval = cv::getFontScaleFromHeight(fontFace, pixelHeight, thickness);
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_getGaborKernel: {
		cv::Size ksize;
		double sigma, theta, lambd, gamma, psi = CV_PI * 0.5;
		int ktype = CV_64F;
		if (ParamIndexToVal(0, ksize))
			_o_return_result;
		if (ParamIndexToVal(1, sigma))
			_o_return_result;
		if (ParamIndexToVal(2, theta))
			_o_return_result;
		if (ParamIndexToVal(3, lambd))
			_o_return_result;
		if (ParamIndexToVal(4, gamma))
			_o_return_result;
		if (aParamCount > 5)
			TokenToVal(*aParam[5], psi, true);
		if (aParamCount > 6)
			TokenToVal(*aParam[6], ktype, true);
		auto __retval = (Mat*)Mat::sPrototype->New(g_invalidparam, 1);
		__retval->mC = cv::getGaborKernel(ksize, sigma, theta, lambd, gamma, psi, ktype);
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_getGaussianKernel: {
		double sigma;
		int ksize, ktype = CV_64F;
		if (ParamIndexToVal(0, ksize))
			_o_return_result;
		if (ParamIndexToVal(1, sigma))
			_o_return_result;
		if (aParamCount > 2)
			TokenToVal(*aParam[2], ktype, true);
		auto __retval = (Mat*)Mat::sPrototype->New(g_invalidparam, 1);
		__retval->mC = cv::getGaussianKernel(ksize, sigma, ktype);
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_getHardwareFeatureName: {
		int feature;
		if (ParamIndexToVal(0, feature))
			_o_return_result;
		auto __retval = cv::getHardwareFeatureName(feature);
		return ValToResult(__retval, aResultToken);
	}
	case FID_getLogLevel: {
		auto __retval = (__int64)cv::getLogLevel();
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_getNumThreads: {
		auto __retval = (__int64)cv::getNumThreads();
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_getNumberOfCPUs: {
		auto __retval = (__int64)cv::getNumberOfCPUs();
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_getOptimalDFTSize: {
		int vecsize;
		if (ParamIndexToVal(0, vecsize))
			_o_return_result;
		auto __retval = (__int64)cv::getOptimalDFTSize(vecsize);
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_getOptimalNewCameraMatrix: {
		bool centerPrincipalPoint = false;
		cv::_InputArray cameraMatrix, distCoeffs;
		cv::Rect validPixROI;
		cv::Size imageSize, newImgSize = cv::Size();
		double alpha;
		if (ParamIndexToVal(0, cameraMatrix))
			_o_return_result;
		if (ParamIndexToVal(1, distCoeffs))
			_o_return_result;
		if (ParamIndexToVal(2, imageSize))
			_o_return_result;
		if (ParamIndexToVal(3, alpha))
			_o_return_result;
		if (aParamCount > 4)
			TokenToVal(*aParam[4], newImgSize, true);
		VarRef* var_validPixROI = nullptr;
		if (aParamCount > 5) {
			TokenToVal(*aParam[5], var_validPixROI, true);
		}
		if (aParamCount > 6)
			TokenToVal(*aParam[6], (char&)centerPrincipalPoint, true);
		auto __retval = (Mat*)Mat::sPrototype->New(g_invalidparam, 1);
		__retval->mC = cv::getOptimalNewCameraMatrix(cameraMatrix, distCoeffs, imageSize, alpha, newImgSize, &validPixROI, centerPrincipalPoint);
		if (var_validPixROI) {
			ValToResult(validPixROI, aResultToken);
			g_ahkapi->VarAssign(var_validPixROI, aResultToken);
			g_ahkapi->ResultTokenFree(aResultToken);
		}
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_getPerspectiveTransform: {
		cv::_InputArray src, dst;
		int solveMethod = cv::DECOMP_LU;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, dst))
			_o_return_result;
		if (aParamCount > 2)
			TokenToVal(*aParam[2], solveMethod, true);
		auto __retval = (Mat*)Mat::sPrototype->New(g_invalidparam, 1);
		__retval->mC = cv::getPerspectiveTransform(src, dst, solveMethod);
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_getRectSubPix: {
		cv::_InputArray image;
		cv::_OutputArray patch;
		cv::Point2f center;
		cv::Size patchSize;
		int patchType = -1;
		if (ParamIndexToVal(0, image))
			_o_return_result;
		if (ParamIndexToVal(1, patchSize))
			_o_return_result;
		if (ParamIndexToVal(2, center))
			_o_return_result;
		if (ParamIndexToVal(3, patch))
			_o_return_result;
		if (aParamCount > 4)
			TokenToVal(*aParam[4], patchType, true);
		cv::getRectSubPix(image, patchSize, center, patch, patchType);
		return;
	}
	case FID_getRotationMatrix2D: {
		cv::Point2f center;
		double angle, scale;
		if (ParamIndexToVal(0, center))
			_o_return_result;
		if (ParamIndexToVal(1, angle))
			_o_return_result;
		if (ParamIndexToVal(2, scale))
			_o_return_result;
		auto __retval = (Mat*)Mat::sPrototype->New(g_invalidparam, 1);
		__retval->mC = cv::getRotationMatrix2D(center, angle, scale);
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_getStructuringElement: {
		cv::Point anchor = cv::Point(-1, -1);
		cv::Size ksize;
		int shape;
		if (ParamIndexToVal(0, shape))
			_o_return_result;
		if (ParamIndexToVal(1, ksize))
			_o_return_result;
		if (aParamCount > 2)
			TokenToVal(*aParam[2], anchor, true);
		auto __retval = (Mat*)Mat::sPrototype->New(g_invalidparam, 1);
		__retval->mC = cv::getStructuringElement(shape, ksize, anchor);
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_getTextSize: {
		cv::String text;
		double fontScale;
		int fontFace, thickness, baseLine;
		if (ParamIndexToVal(0, text))
			_o_return_result;
		if (ParamIndexToVal(1, fontFace))
			_o_return_result;
		if (ParamIndexToVal(2, fontScale))
			_o_return_result;
		if (ParamIndexToVal(3, thickness))
			_o_return_result;
		VarRef* var_baseLine = nullptr;
		if (ParamIndexToVal(4, var_baseLine))
			_o_return_result;
		auto __retval = cv::getTextSize(text, fontFace, fontScale, thickness, &baseLine);
		g_ahkapi->VarAssign(var_baseLine, ExprTokenType((__int64)baseLine));
		return ValToResult(__retval, aResultToken);
	}
	case FID_getThreadNum: {
		auto __retval = (__int64)cv::getThreadNum();
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_getTickCount: {
		auto __retval = cv::getTickCount();
		return ValToResult(__retval, aResultToken);
	}
	case FID_getTickFrequency: {
		auto __retval = cv::getTickFrequency();
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_getTrackbarPos: {
		cv::String trackbarname, winname;
		if (ParamIndexToVal(0, trackbarname))
			_o_return_result;
		if (ParamIndexToVal(1, winname))
			_o_return_result;
		auto __retval = (__int64)cv::getTrackbarPos(trackbarname, winname);
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_getValidDisparityROI: {
		cv::Rect roi1, roi2;
		int minDisparity, numberOfDisparities, blockSize;
		if (ParamIndexToVal(0, roi1))
			_o_return_result;
		if (ParamIndexToVal(1, roi2))
			_o_return_result;
		if (ParamIndexToVal(2, minDisparity))
			_o_return_result;
		if (ParamIndexToVal(3, numberOfDisparities))
			_o_return_result;
		if (ParamIndexToVal(4, blockSize))
			_o_return_result;
		auto __retval = cv::getValidDisparityROI(roi1, roi2, minDisparity, numberOfDisparities, blockSize);
		return ValToResult(__retval, aResultToken);
	}
	case FID_getVersionMajor: {
		auto __retval = (__int64)cv::getVersionMajor();
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_getVersionMinor: {
		auto __retval = (__int64)cv::getVersionMinor();
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_getVersionRevision: {
		auto __retval = (__int64)cv::getVersionRevision();
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_getVersionString: {
		auto __retval = cv::getVersionString();
		return ValToResult(__retval, aResultToken);
	}
	case FID_getWindowImageRect: {
		cv::String winname;
		if (ParamIndexToVal(0, winname))
			_o_return_result;
		auto __retval = cv::getWindowImageRect(winname);
		return ValToResult(__retval, aResultToken);
	}
	case FID_getWindowProperty: {
		cv::String winname;
		int prop_id;
		if (ParamIndexToVal(0, winname))
			_o_return_result;
		if (ParamIndexToVal(1, prop_id))
			_o_return_result;
		auto __retval = cv::getWindowProperty(winname, prop_id);
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_goodFeaturesToTrack: {
		if (!MatchTypes("ooiffo?iif")) {
			bool useHarrisDetector = false;
			cv::_InputArray image, mask = cv::noArray();
			cv::_OutputArray corners;
			double qualityLevel, minDistance, k = 0.04;
			int maxCorners, blockSize = 3;
			if (ParamIndexToVal(0, image))
				_o_return_result;
			if (ParamIndexToVal(1, corners))
				_o_return_result;
			if (ParamIndexToVal(2, maxCorners))
				_o_return_result;
			if (ParamIndexToVal(3, qualityLevel))
				_o_return_result;
			if (ParamIndexToVal(4, minDistance))
				_o_return_result;
			if (aParamCount > 5)
				TokenToVal(*aParam[5], mask, true);
			if (aParamCount > 6)
				TokenToVal(*aParam[6], blockSize, true);
			if (aParamCount > 7)
				TokenToVal(*aParam[7], (char&)useHarrisDetector, true);
			if (aParamCount > 8)
				TokenToVal(*aParam[8], k, true);
			cv::goodFeaturesToTrack(image, corners, maxCorners, qualityLevel, minDistance, mask, blockSize, useHarrisDetector, k);
			return;
		}
		else if (!MatchTypes("ooiffoiii?f")) {
			bool useHarrisDetector = false;
			cv::_InputArray image, mask;
			cv::_OutputArray corners;
			double qualityLevel, minDistance, k = 0.04;
			int maxCorners, blockSize, gradientSize;
			if (ParamIndexToVal(0, image))
				_o_return_result;
			if (ParamIndexToVal(1, corners))
				_o_return_result;
			if (ParamIndexToVal(2, maxCorners))
				_o_return_result;
			if (ParamIndexToVal(3, qualityLevel))
				_o_return_result;
			if (ParamIndexToVal(4, minDistance))
				_o_return_result;
			if (ParamIndexToVal(5, mask))
				_o_return_result;
			if (ParamIndexToVal(6, blockSize))
				_o_return_result;
			if (ParamIndexToVal(7, gradientSize))
				_o_return_result;
			if (aParamCount > 8)
				TokenToVal(*aParam[8], (char&)useHarrisDetector, true);
			if (aParamCount > 9)
				TokenToVal(*aParam[9], k, true);
			cv::goodFeaturesToTrack(image, corners, maxCorners, qualityLevel, minDistance, mask, blockSize, gradientSize, useHarrisDetector, k);
			return;
		}
		else if (!MatchTypes("ooiffooi?iif")) {
			bool useHarrisDetector = false;
			cv::_InputArray image, mask;
			cv::_OutputArray corners, cornersQuality;
			double qualityLevel, minDistance, k = 0.04;
			int maxCorners, blockSize = 3, gradientSize = 3;
			if (ParamIndexToVal(0, image))
				_o_return_result;
			if (ParamIndexToVal(1, corners))
				_o_return_result;
			if (ParamIndexToVal(2, maxCorners))
				_o_return_result;
			if (ParamIndexToVal(3, qualityLevel))
				_o_return_result;
			if (ParamIndexToVal(4, minDistance))
				_o_return_result;
			if (ParamIndexToVal(5, mask))
				_o_return_result;
			if (ParamIndexToVal(6, cornersQuality))
				_o_return_result;
			if (aParamCount > 7)
				TokenToVal(*aParam[7], blockSize, true);
			if (aParamCount > 8)
				TokenToVal(*aParam[8], gradientSize, true);
			if (aParamCount > 9)
				TokenToVal(*aParam[9], (char&)useHarrisDetector, true);
			if (aParamCount > 10)
				TokenToVal(*aParam[10], k, true);
			cv::goodFeaturesToTrack(image, corners, maxCorners, qualityLevel, minDistance, mask, cornersQuality, blockSize, gradientSize, useHarrisDetector, k);
			return;
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case FID_grabCut: {
		cv::_InputArray img;
		cv::_InputOutputArray mask, bgdModel, fgdModel;
		cv::Rect rect;
		int iterCount, mode = cv::GC_EVAL;
		if (ParamIndexToVal(0, img))
			_o_return_result;
		if (ParamIndexToVal(1, mask))
			_o_return_result;
		if (ParamIndexToVal(2, rect))
			_o_return_result;
		if (ParamIndexToVal(3, bgdModel))
			_o_return_result;
		if (ParamIndexToVal(4, fgdModel))
			_o_return_result;
		if (ParamIndexToVal(5, iterCount))
			_o_return_result;
		if (aParamCount > 6)
			TokenToVal(*aParam[6], mode, true);
		cv::grabCut(img, mask, rect, bgdModel, fgdModel, iterCount, mode);
		return;
	}
	case FID_groupRectangles: {
		double eps = 0.2;
		int groupThreshold;
		std::vector<cv::Rect> rectList;
		std::vector<int> weights;
		VarRef* var_rectList = nullptr;
		if (ParamIndexToVal(0, var_rectList))
			_o_return_result;
		if (TokenToVal(VarRefToToken(var_rectList), rectList) != CONDITION_TRUE)
			_o_return_result;
		VarRef* var_weights = nullptr;
		if (ParamIndexToVal(1, var_weights))
			_o_return_result;
		if (ParamIndexToVal(2, groupThreshold))
			_o_return_result;
		if (aParamCount > 3)
			TokenToVal(*aParam[3], eps, true);
		cv::groupRectangles(rectList, weights, groupThreshold, eps);
		ValToResult(rectList, aResultToken);
		g_ahkapi->VarAssign(var_rectList, aResultToken);
		g_ahkapi->ResultTokenFree(aResultToken);
		ValToResult(weights, aResultToken);
		g_ahkapi->VarAssign(var_weights, aResultToken);
		g_ahkapi->ResultTokenFree(aResultToken);
		return;
	}
	case FID_haveImageReader: {
		cv::String filename;
		if (ParamIndexToVal(0, filename))
			_o_return_result;
		auto __retval = (__int64)cv::haveImageReader(filename);
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_haveImageWriter: {
		cv::String filename;
		if (ParamIndexToVal(0, filename))
			_o_return_result;
		auto __retval = (__int64)cv::haveImageWriter(filename);
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_haveOpenVX: {
		auto __retval = (__int64)cv::haveOpenVX();
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_hconcat: {
		cv::_InputArray src;
		cv::_OutputArray dst;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, dst))
			_o_return_result;
		cv::hconcat(src, dst);
		return;
	}
	case FID_idct: {
		cv::_InputArray src;
		cv::_OutputArray dst;
		int flags = 0;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, dst))
			_o_return_result;
		if (aParamCount > 2)
			TokenToVal(*aParam[2], flags, true);
		cv::idct(src, dst, flags);
		return;
	}
	case FID_idft: {
		cv::_InputArray src;
		cv::_OutputArray dst;
		int flags = 0, nonzeroRows = 0;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, dst))
			_o_return_result;
		if (aParamCount > 2)
			TokenToVal(*aParam[2], flags, true);
		if (aParamCount > 3)
			TokenToVal(*aParam[3], nonzeroRows, true);
		cv::idft(src, dst, flags, nonzeroRows);
		return;
	}
	case FID_illuminationChange: {
		cv::_InputArray src, mask;
		cv::_OutputArray dst;
		float alpha = 0.2f, beta = 0.4f;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, mask))
			_o_return_result;
		if (ParamIndexToVal(2, dst))
			_o_return_result;
		if (aParamCount > 3)
			TokenToVal(*aParam[3], alpha, true);
		if (aParamCount > 4)
			TokenToVal(*aParam[4], beta, true);
		cv::illuminationChange(src, mask, dst, alpha, beta);
		return;
	}
	case FID_imcount: {
		cv::String filename;
		int flags = cv::IMREAD_ANYCOLOR;
		if (ParamIndexToVal(0, filename))
			_o_return_result;
		if (aParamCount > 1)
			TokenToVal(*aParam[1], flags, true);
		auto __retval = (__int64)cv::imcount(filename, flags);
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_imdecode: {
		cv::_InputArray buf;
		int flags;
		if (ParamIndexToVal(0, buf))
			_o_return_result;
		if (ParamIndexToVal(1, flags))
			_o_return_result;
		auto __retval = (Mat*)Mat::sPrototype->New(g_invalidparam, 1);
		__retval->mC = cv::imdecode(buf, flags);
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_imencode: {
		cv::_InputArray img;
		cv::String ext;
		std::vector<int> params = std::vector<int>();
		std::vector<uchar> buf;
		if (ParamIndexToVal(0, ext))
			_o_return_result;
		if (ParamIndexToVal(1, img))
			_o_return_result;
		VarRef* var_buf = nullptr;
		if (ParamIndexToVal(2, var_buf))
			_o_return_result;
		if (aParamCount > 3)
			TokenToVal(*aParam[3], params, true);
		auto __retval = (__int64)cv::imencode(ext, img, buf, params);
		ValToResult(buf, aResultToken);
		g_ahkapi->VarAssign(var_buf, aResultToken);
		g_ahkapi->ResultTokenFree(aResultToken);
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_imread: {
		cv::String filename;
		int flags = cv::IMREAD_COLOR;
		if (ParamIndexToVal(0, filename))
			_o_return_result;
		if (aParamCount > 1)
			TokenToVal(*aParam[1], flags, true);
		auto __retval = (Mat*)Mat::sPrototype->New(g_invalidparam, 1);
		__retval->mC = cv::imread(filename, flags);
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_imreadmulti: {
		if (2 <= aParamCount && aParamCount <= 3) {
			cv::String filename;
			int flags = cv::IMREAD_ANYCOLOR;
			std::vector<cv::Mat> mats;
			if (ParamIndexToVal(0, filename))
				_o_return_result;
			VarRef* var_mats = nullptr;
			if (ParamIndexToVal(1, var_mats))
				_o_return_result;
			if (aParamCount > 2)
				TokenToVal(*aParam[2], flags, true);
			auto __retval = (__int64)cv::imreadmulti(filename, mats, flags);
			ValToResult(mats, aResultToken);
			g_ahkapi->VarAssign(var_mats, aResultToken);
			g_ahkapi->ResultTokenFree(aResultToken);
			return (void)(aResultToken.SetValue(__retval));
		}
		else if (4 <= aParamCount && aParamCount <= 5) {
			cv::String filename;
			int start, count, flags = cv::IMREAD_ANYCOLOR;
			std::vector<cv::Mat> mats;
			if (ParamIndexToVal(0, filename))
				_o_return_result;
			VarRef* var_mats = nullptr;
			if (ParamIndexToVal(1, var_mats))
				_o_return_result;
			if (ParamIndexToVal(2, start))
				_o_return_result;
			if (ParamIndexToVal(3, count))
				_o_return_result;
			if (aParamCount > 4)
				TokenToVal(*aParam[4], flags, true);
			auto __retval = (__int64)cv::imreadmulti(filename, mats, start, count, flags);
			ValToResult(mats, aResultToken);
			g_ahkapi->VarAssign(var_mats, aResultToken);
			g_ahkapi->ResultTokenFree(aResultToken);
			return (void)(aResultToken.SetValue(__retval));
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case FID_imshow: {
		cv::_InputArray mat;
		cv::String winname;
		if (ParamIndexToVal(0, winname))
			_o_return_result;
		if (ParamIndexToVal(1, mat))
			_o_return_result;
		cv::imshow(winname, mat);
		return;
	}
	case FID_imwrite: {
		cv::_InputArray img;
		cv::String filename;
		std::vector<int> params = std::vector<int>();
		if (ParamIndexToVal(0, filename))
			_o_return_result;
		if (ParamIndexToVal(1, img))
			_o_return_result;
		if (aParamCount > 2)
			TokenToVal(*aParam[2], params, true);
		auto __retval = (__int64)cv::imwrite(filename, img, params);
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_imwritemulti: {
		cv::_InputArray img;
		cv::String filename;
		std::vector<int> params = std::vector<int>();
		if (ParamIndexToVal(0, filename))
			_o_return_result;
		if (ParamIndexToVal(1, img))
			_o_return_result;
		if (aParamCount > 2)
			TokenToVal(*aParam[2], params, true);
		auto __retval = (__int64)cv::imwritemulti(filename, img, params);
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_inRange: {
		cv::_InputArray src, lowerb, upperb;
		cv::_OutputArray dst;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, lowerb))
			_o_return_result;
		if (ParamIndexToVal(2, upperb))
			_o_return_result;
		if (ParamIndexToVal(3, dst))
			_o_return_result;
		cv::inRange(src, lowerb, upperb, dst);
		return;
	}
	case FID_initCameraMatrix2D: {
		cv::_InputArray objectPoints, imagePoints;
		cv::Size imageSize;
		double aspectRatio = 1.0;
		if (ParamIndexToVal(0, objectPoints))
			_o_return_result;
		if (ParamIndexToVal(1, imagePoints))
			_o_return_result;
		if (ParamIndexToVal(2, imageSize))
			_o_return_result;
		if (aParamCount > 3)
			TokenToVal(*aParam[3], aspectRatio, true);
		auto __retval = (Mat*)Mat::sPrototype->New(g_invalidparam, 1);
		__retval->mC = cv::initCameraMatrix2D(objectPoints, imagePoints, imageSize, aspectRatio);
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_initInverseRectificationMap: {
		cv::_InputArray cameraMatrix, distCoeffs, R, newCameraMatrix;
		cv::_OutputArray map1, map2;
		cv::Size size;
		int m1type;
		if (ParamIndexToVal(0, cameraMatrix))
			_o_return_result;
		if (ParamIndexToVal(1, distCoeffs))
			_o_return_result;
		if (ParamIndexToVal(2, R))
			_o_return_result;
		if (ParamIndexToVal(3, newCameraMatrix))
			_o_return_result;
		if (ParamIndexToVal(4, size))
			_o_return_result;
		if (ParamIndexToVal(5, m1type))
			_o_return_result;
		if (ParamIndexToVal(6, map1))
			_o_return_result;
		if (ParamIndexToVal(7, map2))
			_o_return_result;
		cv::initInverseRectificationMap(cameraMatrix, distCoeffs, R, newCameraMatrix, size, m1type, map1, map2);
		return;
	}
	case FID_initUndistortRectifyMap: {
		cv::_InputArray cameraMatrix, distCoeffs, R, newCameraMatrix;
		cv::_OutputArray map1, map2;
		cv::Size size;
		int m1type;
		if (ParamIndexToVal(0, cameraMatrix))
			_o_return_result;
		if (ParamIndexToVal(1, distCoeffs))
			_o_return_result;
		if (ParamIndexToVal(2, R))
			_o_return_result;
		if (ParamIndexToVal(3, newCameraMatrix))
			_o_return_result;
		if (ParamIndexToVal(4, size))
			_o_return_result;
		if (ParamIndexToVal(5, m1type))
			_o_return_result;
		if (ParamIndexToVal(6, map1))
			_o_return_result;
		if (ParamIndexToVal(7, map2))
			_o_return_result;
		cv::initUndistortRectifyMap(cameraMatrix, distCoeffs, R, newCameraMatrix, size, m1type, map1, map2);
		return;
	}
	case FID_inpaint: {
		cv::_InputArray src, inpaintMask;
		cv::_OutputArray dst;
		double inpaintRadius;
		int flags;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, inpaintMask))
			_o_return_result;
		if (ParamIndexToVal(2, dst))
			_o_return_result;
		if (ParamIndexToVal(3, inpaintRadius))
			_o_return_result;
		if (ParamIndexToVal(4, flags))
			_o_return_result;
		cv::inpaint(src, inpaintMask, dst, inpaintRadius, flags);
		return;
	}
	case FID_insertChannel: {
		cv::_InputArray src;
		cv::_InputOutputArray dst;
		int coi;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, dst))
			_o_return_result;
		if (ParamIndexToVal(2, coi))
			_o_return_result;
		cv::insertChannel(src, dst, coi);
		return;
	}
	case FID_integral: {
		if (!MatchTypes("ooooi?i")) {
			cv::_InputArray src;
			cv::_OutputArray sum, sqsum, tilted;
			int sdepth = -1, sqdepth = -1;
			if (ParamIndexToVal(0, src))
				_o_return_result;
			if (ParamIndexToVal(1, sum))
				_o_return_result;
			if (ParamIndexToVal(2, sqsum))
				_o_return_result;
			if (ParamIndexToVal(3, tilted))
				_o_return_result;
			if (aParamCount > 4)
				TokenToVal(*aParam[4], sdepth, true);
			if (aParamCount > 5)
				TokenToVal(*aParam[5], sqdepth, true);
			cv::integral(src, sum, sqsum, tilted, sdepth, sqdepth);
			return;
		}
		else if (!MatchTypes("ooi?")) {
			cv::_InputArray src;
			cv::_OutputArray sum;
			int sdepth = -1;
			if (ParamIndexToVal(0, src))
				_o_return_result;
			if (ParamIndexToVal(1, sum))
				_o_return_result;
			if (aParamCount > 2)
				TokenToVal(*aParam[2], sdepth, true);
			cv::integral(src, sum, sdepth);
			return;
		}
		else if (!MatchTypes("oooi?i")) {
			cv::_InputArray src;
			cv::_OutputArray sum, sqsum;
			int sdepth = -1, sqdepth = -1;
			if (ParamIndexToVal(0, src))
				_o_return_result;
			if (ParamIndexToVal(1, sum))
				_o_return_result;
			if (ParamIndexToVal(2, sqsum))
				_o_return_result;
			if (aParamCount > 3)
				TokenToVal(*aParam[3], sdepth, true);
			if (aParamCount > 4)
				TokenToVal(*aParam[4], sqdepth, true);
			cv::integral(src, sum, sqsum, sdepth, sqdepth);
			return;
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case FID_intersectConvexConvex: {
		bool handleNested = true;
		cv::_InputArray p1, p2;
		cv::_OutputArray p12;
		if (ParamIndexToVal(0, p1))
			_o_return_result;
		if (ParamIndexToVal(1, p2))
			_o_return_result;
		if (ParamIndexToVal(2, p12))
			_o_return_result;
		if (aParamCount > 3)
			TokenToVal(*aParam[3], (char&)handleNested, true);
		auto __retval = (double)cv::intersectConvexConvex(p1, p2, p12, handleNested);
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_invert: {
		cv::_InputArray src;
		cv::_OutputArray dst;
		int flags = cv::DECOMP_LU;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, dst))
			_o_return_result;
		if (aParamCount > 2)
			TokenToVal(*aParam[2], flags, true);
		auto __retval = cv::invert(src, dst, flags);
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_invertAffineTransform: {
		cv::_InputArray M;
		cv::_OutputArray iM;
		if (ParamIndexToVal(0, M))
			_o_return_result;
		if (ParamIndexToVal(1, iM))
			_o_return_result;
		cv::invertAffineTransform(M, iM);
		return;
	}
	case FID_isContourConvex: {
		cv::_InputArray contour;
		if (ParamIndexToVal(0, contour))
			_o_return_result;
		auto __retval = (__int64)cv::isContourConvex(contour);
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_kmeans: {
		cv::_InputArray data;
		cv::_InputOutputArray bestLabels;
		cv::_OutputArray centers = cv::noArray();
		cv::TermCriteria criteria;
		int K, attempts, flags;
		if (ParamIndexToVal(0, data))
			_o_return_result;
		if (ParamIndexToVal(1, K))
			_o_return_result;
		if (ParamIndexToVal(2, bestLabels))
			_o_return_result;
		if (ParamIndexToVal(3, criteria))
			_o_return_result;
		if (ParamIndexToVal(4, attempts))
			_o_return_result;
		if (ParamIndexToVal(5, flags))
			_o_return_result;
		if (aParamCount > 6)
			TokenToVal(*aParam[6], centers, true);
		auto __retval = cv::kmeans(data, K, bestLabels, criteria, attempts, flags, centers);
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_line: {
		cv::_InputOutputArray img;
		cv::Point pt1, pt2;
		cv::Scalar color;
		int thickness = 1, lineType = cv::LINE_8, shift = 0;
		if (ParamIndexToVal(0, img))
			_o_return_result;
		if (ParamIndexToVal(1, pt1))
			_o_return_result;
		if (ParamIndexToVal(2, pt2))
			_o_return_result;
		if (ParamIndexToVal(3, color))
			_o_return_result;
		if (aParamCount > 4)
			TokenToVal(*aParam[4], thickness, true);
		if (aParamCount > 5)
			TokenToVal(*aParam[5], lineType, true);
		if (aParamCount > 6)
			TokenToVal(*aParam[6], shift, true);
		cv::line(img, pt1, pt2, color, thickness, lineType, shift);
		return;
	}
	case FID_linearPolar: {
		cv::_InputArray src;
		cv::_OutputArray dst;
		cv::Point2f center;
		double maxRadius;
		int flags;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, dst))
			_o_return_result;
		if (ParamIndexToVal(2, center))
			_o_return_result;
		if (ParamIndexToVal(3, maxRadius))
			_o_return_result;
		if (ParamIndexToVal(4, flags))
			_o_return_result;
		cv::linearPolar(src, dst, center, maxRadius, flags);
		return;
	}
	case FID_log: {
		cv::_InputArray src;
		cv::_OutputArray dst;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, dst))
			_o_return_result;
		cv::log(src, dst);
		return;
	}
	case FID_logPolar: {
		cv::_InputArray src;
		cv::_OutputArray dst;
		cv::Point2f center;
		double M;
		int flags;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, dst))
			_o_return_result;
		if (ParamIndexToVal(2, center))
			_o_return_result;
		if (ParamIndexToVal(3, M))
			_o_return_result;
		if (ParamIndexToVal(4, flags))
			_o_return_result;
		cv::logPolar(src, dst, center, M, flags);
		return;
	}
	case FID_magnitude: {
		cv::_InputArray x, y;
		cv::_OutputArray magnitude;
		if (ParamIndexToVal(0, x))
			_o_return_result;
		if (ParamIndexToVal(1, y))
			_o_return_result;
		if (ParamIndexToVal(2, magnitude))
			_o_return_result;
		cv::magnitude(x, y, magnitude);
		return;
	}
	case FID_matMulDeriv: {
		cv::_InputArray A, B;
		cv::_OutputArray dABdA, dABdB;
		if (ParamIndexToVal(0, A))
			_o_return_result;
		if (ParamIndexToVal(1, B))
			_o_return_result;
		if (ParamIndexToVal(2, dABdA))
			_o_return_result;
		if (ParamIndexToVal(3, dABdB))
			_o_return_result;
		cv::matMulDeriv(A, B, dABdA, dABdB);
		return;
	}
	case FID_matchShapes: {
		cv::_InputArray contour1, contour2;
		double parameter;
		int method;
		if (ParamIndexToVal(0, contour1))
			_o_return_result;
		if (ParamIndexToVal(1, contour2))
			_o_return_result;
		if (ParamIndexToVal(2, method))
			_o_return_result;
		if (ParamIndexToVal(3, parameter))
			_o_return_result;
		auto __retval = cv::matchShapes(contour1, contour2, method, parameter);
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_matchTemplate: {
		cv::_InputArray image, templ, mask = cv::noArray();
		cv::_OutputArray result;
		int method;
		if (ParamIndexToVal(0, image))
			_o_return_result;
		if (ParamIndexToVal(1, templ))
			_o_return_result;
		if (ParamIndexToVal(2, result))
			_o_return_result;
		if (ParamIndexToVal(3, method))
			_o_return_result;
		if (aParamCount > 4)
			TokenToVal(*aParam[4], mask, true);
		cv::matchTemplate(image, templ, result, method, mask);
		return;
	}
	case FID_max: {
		cv::_InputArray src1, src2;
		cv::_OutputArray dst;
		if (ParamIndexToVal(0, src1))
			_o_return_result;
		if (ParamIndexToVal(1, src2))
			_o_return_result;
		if (ParamIndexToVal(2, dst))
			_o_return_result;
		cv::max(src1, src2, dst);
		return;
	}
	case FID_mean: {
		cv::_InputArray src, mask = cv::noArray();
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (aParamCount > 1)
			TokenToVal(*aParam[1], mask, true);
		auto __retval = cv::mean(src, mask);
		return ValToResult(__retval, aResultToken);
	}
	case FID_meanShift: {
		cv::_InputArray probImage;
		cv::Rect window;
		cv::TermCriteria criteria;
		if (ParamIndexToVal(0, probImage))
			_o_return_result;
		VarRef* var_window = nullptr;
		if (ParamIndexToVal(1, var_window))
			_o_return_result;
		if (TokenToVal(VarRefToToken(var_window), window) != CONDITION_TRUE)
			_o_return_result;
		if (ParamIndexToVal(2, criteria))
			_o_return_result;
		auto __retval = (__int64)cv::meanShift(probImage, window, criteria);
		ValToResult(window, aResultToken);
		g_ahkapi->VarAssign(var_window, aResultToken);
		g_ahkapi->ResultTokenFree(aResultToken);
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_meanStdDev: {
		cv::_InputArray src, mask = cv::noArray();
		cv::_OutputArray mean, stddev;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, mean))
			_o_return_result;
		if (ParamIndexToVal(2, stddev))
			_o_return_result;
		if (aParamCount > 3)
			TokenToVal(*aParam[3], mask, true);
		cv::meanStdDev(src, mean, stddev, mask);
		return;
	}
	case FID_medianBlur: {
		cv::_InputArray src;
		cv::_OutputArray dst;
		int ksize;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, dst))
			_o_return_result;
		if (ParamIndexToVal(2, ksize))
			_o_return_result;
		cv::medianBlur(src, dst, ksize);
		return;
	}
	case FID_merge: {
		cv::_InputArray mv;
		cv::_OutputArray dst;
		if (ParamIndexToVal(0, mv))
			_o_return_result;
		if (ParamIndexToVal(1, dst))
			_o_return_result;
		cv::merge(mv, dst);
		return;
	}
	case FID_min: {
		cv::_InputArray src1, src2;
		cv::_OutputArray dst;
		if (ParamIndexToVal(0, src1))
			_o_return_result;
		if (ParamIndexToVal(1, src2))
			_o_return_result;
		if (ParamIndexToVal(2, dst))
			_o_return_result;
		cv::min(src1, src2, dst);
		return;
	}
	case FID_minAreaRect: {
		cv::_InputArray points;
		if (ParamIndexToVal(0, points))
			_o_return_result;
		auto __retval = cv::minAreaRect(points);
		return ValToResult(__retval, aResultToken);
	}
	case FID_minEnclosingCircle: {
		cv::_InputArray points;
		cv::Point2f center;
		float radius;
		if (ParamIndexToVal(0, points))
			_o_return_result;
		VarRef* var_center = nullptr;
		if (ParamIndexToVal(1, var_center))
			_o_return_result;
		VarRef* var_radius = nullptr;
		if (ParamIndexToVal(2, var_radius))
			_o_return_result;
		cv::minEnclosingCircle(points, center, radius);
		ValToResult(center, aResultToken);
		g_ahkapi->VarAssign(var_center, aResultToken);
		g_ahkapi->ResultTokenFree(aResultToken);
		g_ahkapi->VarAssign(var_radius, ExprTokenType((double)radius));
		return;
	}
	case FID_minEnclosingTriangle: {
		cv::_InputArray points;
		cv::_OutputArray triangle;
		if (ParamIndexToVal(0, points))
			_o_return_result;
		if (ParamIndexToVal(1, triangle))
			_o_return_result;
		auto __retval = cv::minEnclosingTriangle(points, triangle);
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_minMaxLoc: {
		cv::_InputArray src, mask = cv::noArray();
		cv::Point minLoc, maxLoc;
		double minVal, maxVal;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		VarRef* var_minVal = nullptr;
		if (ParamIndexToVal(1, var_minVal))
			_o_return_result;
		VarRef* var_maxVal = nullptr;
		if (aParamCount > 2) {
			TokenToVal(*aParam[2], var_maxVal, true);
		}
		VarRef* var_minLoc = nullptr;
		if (aParamCount > 3) {
			TokenToVal(*aParam[3], var_minLoc, true);
		}
		VarRef* var_maxLoc = nullptr;
		if (aParamCount > 4) {
			TokenToVal(*aParam[4], var_maxLoc, true);
		}
		if (aParamCount > 5)
			TokenToVal(*aParam[5], mask, true);
		cv::minMaxLoc(src, &minVal, &maxVal, &minLoc, &maxLoc, mask);
		g_ahkapi->VarAssign(var_minVal, ExprTokenType((double)minVal));
		if (var_maxVal) g_ahkapi->VarAssign(var_maxVal, ExprTokenType((double)maxVal));
		if (var_minLoc) {
			ValToResult(minLoc, aResultToken);
			g_ahkapi->VarAssign(var_minLoc, aResultToken);
			g_ahkapi->ResultTokenFree(aResultToken);
		}
		if (var_maxLoc) {
			ValToResult(maxLoc, aResultToken);
			g_ahkapi->VarAssign(var_maxLoc, aResultToken);
			g_ahkapi->ResultTokenFree(aResultToken);
		}
		return;
	}
	case FID_mixChannels: {
		cv::_InputOutputArray dst;
		cv::_InputArray src;
		std::vector<int> fromTo;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, dst))
			_o_return_result;
		if (ParamIndexToVal(2, fromTo))
			_o_return_result;
		cv::mixChannels(src, dst, fromTo);
		return;
	}
	case FID_moments: {
		bool binaryImage = false;
		cv::_InputArray array;
		if (ParamIndexToVal(0, array))
			_o_return_result;
		if (aParamCount > 1)
			TokenToVal(*aParam[1], (char&)binaryImage, true);
		auto __retval = (Moments*)Moments::sPrototype->New(g_invalidparam, 1);
		__retval->mC = cv::makePtr<cv::Moments>(cv::moments(array, binaryImage));
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_morphologyEx: {
		cv::_InputArray src, kernel;
		cv::_OutputArray dst;
		cv::Point anchor = cv::Point(-1, -1);
		cv::Scalar borderValue = cv::morphologyDefaultBorderValue();
		int op, iterations = 1, borderType = cv::BORDER_CONSTANT;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, dst))
			_o_return_result;
		if (ParamIndexToVal(2, op))
			_o_return_result;
		if (ParamIndexToVal(3, kernel))
			_o_return_result;
		if (aParamCount > 4)
			TokenToVal(*aParam[4], anchor, true);
		if (aParamCount > 5)
			TokenToVal(*aParam[5], iterations, true);
		if (aParamCount > 6)
			TokenToVal(*aParam[6], borderType, true);
		if (aParamCount > 7)
			TokenToVal(*aParam[7], borderValue, true);
		cv::morphologyEx(src, dst, op, kernel, anchor, iterations, borderType, borderValue);
		return;
	}
	case FID_moveWindow: {
		cv::String winname;
		int x, y;
		if (ParamIndexToVal(0, winname))
			_o_return_result;
		if (ParamIndexToVal(1, x))
			_o_return_result;
		if (ParamIndexToVal(2, y))
			_o_return_result;
		cv::moveWindow(winname, x, y);
		return;
	}
	case FID_mulSpectrums: {
		bool conjB = false;
		cv::_InputArray a, b;
		cv::_OutputArray c;
		int flags;
		if (ParamIndexToVal(0, a))
			_o_return_result;
		if (ParamIndexToVal(1, b))
			_o_return_result;
		if (ParamIndexToVal(2, c))
			_o_return_result;
		if (ParamIndexToVal(3, flags))
			_o_return_result;
		if (aParamCount > 4)
			TokenToVal(*aParam[4], (char&)conjB, true);
		cv::mulSpectrums(a, b, c, flags, conjB);
		return;
	}
	case FID_mulTransposed: {
		bool aTa;
		cv::_InputArray src, delta = cv::noArray();
		cv::_OutputArray dst;
		double scale = 1;
		int dtype = -1;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, dst))
			_o_return_result;
		if (ParamIndexToVal(2, (char&)aTa))
			_o_return_result;
		if (aParamCount > 3)
			TokenToVal(*aParam[3], delta, true);
		if (aParamCount > 4)
			TokenToVal(*aParam[4], scale, true);
		if (aParamCount > 5)
			TokenToVal(*aParam[5], dtype, true);
		cv::mulTransposed(src, dst, aTa, delta, scale, dtype);
		return;
	}
	case FID_multiply: {
		cv::_InputArray src1, src2;
		cv::_OutputArray dst;
		double scale = 1;
		int dtype = -1;
		if (ParamIndexToVal(0, src1))
			_o_return_result;
		if (ParamIndexToVal(1, src2))
			_o_return_result;
		if (ParamIndexToVal(2, dst))
			_o_return_result;
		if (aParamCount > 3)
			TokenToVal(*aParam[3], scale, true);
		if (aParamCount > 4)
			TokenToVal(*aParam[4], dtype, true);
		cv::multiply(src1, src2, dst, scale, dtype);
		return;
	}
	case FID_namedWindow: {
		cv::String winname;
		int flags = cv::WINDOW_AUTOSIZE;
		if (ParamIndexToVal(0, winname))
			_o_return_result;
		if (aParamCount > 1)
			TokenToVal(*aParam[1], flags, true);
		cv::namedWindow(winname, flags);
		return;
	}
	case FID_norm: {
		if (!MatchTypes("oi?o")) {
			cv::_InputArray src1, mask = cv::noArray();
			int normType = cv::NORM_L2;
			if (ParamIndexToVal(0, src1))
				_o_return_result;
			if (aParamCount > 1)
				TokenToVal(*aParam[1], normType, true);
			if (aParamCount > 2)
				TokenToVal(*aParam[2], mask, true);
			auto __retval = cv::norm(src1, normType, mask);
			return (void)(aResultToken.SetValue(__retval));
		}
		else if (!MatchTypes("ooi?o")) {
			cv::_InputArray src1, src2, mask = cv::noArray();
			int normType = cv::NORM_L2;
			if (ParamIndexToVal(0, src1))
				_o_return_result;
			if (ParamIndexToVal(1, src2))
				_o_return_result;
			if (aParamCount > 2)
				TokenToVal(*aParam[2], normType, true);
			if (aParamCount > 3)
				TokenToVal(*aParam[3], mask, true);
			auto __retval = cv::norm(src1, src2, normType, mask);
			return (void)(aResultToken.SetValue(__retval));
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case FID_normalize: {
		cv::_InputArray src, mask = cv::noArray();
		cv::_InputOutputArray dst;
		double alpha = 1, beta = 0;
		int norm_type = cv::NORM_L2, dtype = -1;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, dst))
			_o_return_result;
		if (aParamCount > 2)
			TokenToVal(*aParam[2], alpha, true);
		if (aParamCount > 3)
			TokenToVal(*aParam[3], beta, true);
		if (aParamCount > 4)
			TokenToVal(*aParam[4], norm_type, true);
		if (aParamCount > 5)
			TokenToVal(*aParam[5], dtype, true);
		if (aParamCount > 6)
			TokenToVal(*aParam[6], mask, true);
		cv::normalize(src, dst, alpha, beta, norm_type, dtype, mask);
		return;
	}
	case FID_patchNaNs: {
		cv::_InputOutputArray a;
		double val = 0;
		if (ParamIndexToVal(0, a))
			_o_return_result;
		if (aParamCount > 1)
			TokenToVal(*aParam[1], val, true);
		cv::patchNaNs(a, val);
		return;
	}
	case FID_pencilSketch: {
		cv::_InputArray src;
		cv::_OutputArray dst1, dst2;
		float sigma_s = 60, sigma_r = 0.07f, shade_factor = 0.02f;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, dst1))
			_o_return_result;
		if (ParamIndexToVal(2, dst2))
			_o_return_result;
		if (aParamCount > 3)
			TokenToVal(*aParam[3], sigma_s, true);
		if (aParamCount > 4)
			TokenToVal(*aParam[4], sigma_r, true);
		if (aParamCount > 5)
			TokenToVal(*aParam[5], shade_factor, true);
		cv::pencilSketch(src, dst1, dst2, sigma_s, sigma_r, shade_factor);
		return;
	}
	case FID_perspectiveTransform: {
		cv::_InputArray src, m;
		cv::_OutputArray dst;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, dst))
			_o_return_result;
		if (ParamIndexToVal(2, m))
			_o_return_result;
		cv::perspectiveTransform(src, dst, m);
		return;
	}
	case FID_phase: {
		bool angleInDegrees = false;
		cv::_InputArray x, y;
		cv::_OutputArray angle;
		if (ParamIndexToVal(0, x))
			_o_return_result;
		if (ParamIndexToVal(1, y))
			_o_return_result;
		if (ParamIndexToVal(2, angle))
			_o_return_result;
		if (aParamCount > 3)
			TokenToVal(*aParam[3], (char&)angleInDegrees, true);
		cv::phase(x, y, angle, angleInDegrees);
		return;
	}
	case FID_phaseCorrelate: {
		cv::_InputArray src1, src2, window = cv::noArray();
		double response;
		if (ParamIndexToVal(0, src1))
			_o_return_result;
		if (ParamIndexToVal(1, src2))
			_o_return_result;
		if (aParamCount > 2)
			TokenToVal(*aParam[2], window, true);
		VarRef* var_response = nullptr;
		if (aParamCount > 3) {
			TokenToVal(*aParam[3], var_response, true);
		}
		auto __retval = cv::phaseCorrelate(src1, src2, window, &response);
		if (var_response) g_ahkapi->VarAssign(var_response, ExprTokenType((double)response));
		return ValToResult(__retval, aResultToken);
	}
	case FID_pointPolygonTest: {
		bool measureDist;
		cv::_InputArray contour;
		cv::Point2f pt;
		if (ParamIndexToVal(0, contour))
			_o_return_result;
		if (ParamIndexToVal(1, pt))
			_o_return_result;
		if (ParamIndexToVal(2, (char&)measureDist))
			_o_return_result;
		auto __retval = cv::pointPolygonTest(contour, pt, measureDist);
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_polarToCart: {
		bool angleInDegrees = false;
		cv::_InputArray magnitude, angle;
		cv::_OutputArray x, y;
		if (ParamIndexToVal(0, magnitude))
			_o_return_result;
		if (ParamIndexToVal(1, angle))
			_o_return_result;
		if (ParamIndexToVal(2, x))
			_o_return_result;
		if (ParamIndexToVal(3, y))
			_o_return_result;
		if (aParamCount > 4)
			TokenToVal(*aParam[4], (char&)angleInDegrees, true);
		cv::polarToCart(magnitude, angle, x, y, angleInDegrees);
		return;
	}
	case FID_pollKey: {
		auto __retval = (__int64)cv::pollKey();
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_polylines: {
		bool isClosed;
		cv::_InputArray pts;
		cv::_InputOutputArray img;
		cv::Scalar color;
		int thickness = 1, lineType = cv::LINE_8, shift = 0;
		if (ParamIndexToVal(0, img))
			_o_return_result;
		if (ParamIndexToVal(1, pts))
			_o_return_result;
		if (ParamIndexToVal(2, (char&)isClosed))
			_o_return_result;
		if (ParamIndexToVal(3, color))
			_o_return_result;
		if (aParamCount > 4)
			TokenToVal(*aParam[4], thickness, true);
		if (aParamCount > 5)
			TokenToVal(*aParam[5], lineType, true);
		if (aParamCount > 6)
			TokenToVal(*aParam[6], shift, true);
		cv::polylines(img, pts, isClosed, color, thickness, lineType, shift);
		return;
	}
	case FID_pow: {
		cv::_InputArray src;
		cv::_OutputArray dst;
		double power;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, power))
			_o_return_result;
		if (ParamIndexToVal(2, dst))
			_o_return_result;
		cv::pow(src, power, dst);
		return;
	}
	case FID_preCornerDetect: {
		cv::_InputArray src;
		cv::_OutputArray dst;
		int ksize, borderType = cv::BORDER_DEFAULT;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, dst))
			_o_return_result;
		if (ParamIndexToVal(2, ksize))
			_o_return_result;
		if (aParamCount > 3)
			TokenToVal(*aParam[3], borderType, true);
		cv::preCornerDetect(src, dst, ksize, borderType);
		return;
	}
	case FID_projectPoints: {
		cv::_InputArray objectPoints, rvec, tvec, cameraMatrix, distCoeffs;
		cv::_OutputArray imagePoints, jacobian = cv::noArray();
		double aspectRatio = 0;
		if (ParamIndexToVal(0, objectPoints))
			_o_return_result;
		if (ParamIndexToVal(1, rvec))
			_o_return_result;
		if (ParamIndexToVal(2, tvec))
			_o_return_result;
		if (ParamIndexToVal(3, cameraMatrix))
			_o_return_result;
		if (ParamIndexToVal(4, distCoeffs))
			_o_return_result;
		if (ParamIndexToVal(5, imagePoints))
			_o_return_result;
		if (aParamCount > 6)
			TokenToVal(*aParam[6], jacobian, true);
		if (aParamCount > 7)
			TokenToVal(*aParam[7], aspectRatio, true);
		cv::projectPoints(objectPoints, rvec, tvec, cameraMatrix, distCoeffs, imagePoints, jacobian, aspectRatio);
		return;
	}
	case FID_putText: {
		bool bottomLeftOrigin = false;
		cv::_InputOutputArray img;
		cv::Point org;
		cv::Scalar color;
		cv::String text;
		double fontScale;
		int fontFace, thickness = 1, lineType = cv::LINE_8;
		if (ParamIndexToVal(0, img))
			_o_return_result;
		if (ParamIndexToVal(1, text))
			_o_return_result;
		if (ParamIndexToVal(2, org))
			_o_return_result;
		if (ParamIndexToVal(3, fontFace))
			_o_return_result;
		if (ParamIndexToVal(4, fontScale))
			_o_return_result;
		if (ParamIndexToVal(5, color))
			_o_return_result;
		if (aParamCount > 6)
			TokenToVal(*aParam[6], thickness, true);
		if (aParamCount > 7)
			TokenToVal(*aParam[7], lineType, true);
		if (aParamCount > 8)
			TokenToVal(*aParam[8], (char&)bottomLeftOrigin, true);
		cv::putText(img, text, org, fontFace, fontScale, color, thickness, lineType, bottomLeftOrigin);
		return;
	}
	case FID_pyrDown: {
		cv::_InputArray src;
		cv::_OutputArray dst;
		cv::Size dstsize = cv::Size();
		int borderType = cv::BORDER_DEFAULT;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, dst))
			_o_return_result;
		if (aParamCount > 2)
			TokenToVal(*aParam[2], dstsize, true);
		if (aParamCount > 3)
			TokenToVal(*aParam[3], borderType, true);
		cv::pyrDown(src, dst, dstsize, borderType);
		return;
	}
	case FID_pyrMeanShiftFiltering: {
		cv::_InputArray src;
		cv::_OutputArray dst;
		cv::TermCriteria termcrit = cv::TermCriteria(cv::TermCriteria::MAX_ITER + cv::TermCriteria::EPS, 5, 1);
		;
		double sp, sr;
		int maxLevel = 1;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, dst))
			_o_return_result;
		if (ParamIndexToVal(2, sp))
			_o_return_result;
		if (ParamIndexToVal(3, sr))
			_o_return_result;
		if (aParamCount > 4)
			TokenToVal(*aParam[4], maxLevel, true);
		if (aParamCount > 5)
			TokenToVal(*aParam[5], termcrit, true);
		cv::pyrMeanShiftFiltering(src, dst, sp, sr, maxLevel, termcrit);
		return;
	}
	case FID_pyrUp: {
		cv::_InputArray src;
		cv::_OutputArray dst;
		cv::Size dstsize = cv::Size();
		int borderType = cv::BORDER_DEFAULT;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, dst))
			_o_return_result;
		if (aParamCount > 2)
			TokenToVal(*aParam[2], dstsize, true);
		if (aParamCount > 3)
			TokenToVal(*aParam[3], borderType, true);
		cv::pyrUp(src, dst, dstsize, borderType);
		return;
	}
	case FID_randShuffle: {
		cv::_InputOutputArray dst;
		cv::RNG* rng = 0;
		double iterFactor = 1.;
		if (ParamIndexToVal(0, dst))
			_o_return_result;
		if (aParamCount > 1)
			TokenToVal(*aParam[1], iterFactor, true);
		if (aParamCount > 2)
			TokenToVal(*aParam[2], rng, true);
		cv::randShuffle(dst, iterFactor, rng);
		return;
	}
	case FID_randn: {
		cv::_InputArray mean, stddev;
		cv::_InputOutputArray dst;
		if (ParamIndexToVal(0, dst))
			_o_return_result;
		if (ParamIndexToVal(1, mean))
			_o_return_result;
		if (ParamIndexToVal(2, stddev))
			_o_return_result;
		cv::randn(dst, mean, stddev);
		return;
	}
	case FID_randu: {
		cv::_InputArray low, high;
		cv::_InputOutputArray dst;
		if (ParamIndexToVal(0, dst))
			_o_return_result;
		if (ParamIndexToVal(1, low))
			_o_return_result;
		if (ParamIndexToVal(2, high))
			_o_return_result;
		cv::randu(dst, low, high);
		return;
	}
	case FID_readOpticalFlow: {
		cv::String path;
		if (ParamIndexToVal(0, path))
			_o_return_result;
		auto __retval = (Mat*)Mat::sPrototype->New(g_invalidparam, 1);
		__retval->mC = cv::readOpticalFlow(path);
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_recoverPose: {
		if (!MatchTypes("oooooooooi?ffo")) {
			cv::_InputArray points1, points2, cameraMatrix1, distCoeffs1, cameraMatrix2, distCoeffs2;
			cv::_InputOutputArray mask = cv::noArray();
			cv::_OutputArray E, R, t;
			double prob = 0.999, threshold = 1.0;
			int method = cv::RANSAC;
			if (ParamIndexToVal(0, points1))
				_o_return_result;
			if (ParamIndexToVal(1, points2))
				_o_return_result;
			if (ParamIndexToVal(2, cameraMatrix1))
				_o_return_result;
			if (ParamIndexToVal(3, distCoeffs1))
				_o_return_result;
			if (ParamIndexToVal(4, cameraMatrix2))
				_o_return_result;
			if (ParamIndexToVal(5, distCoeffs2))
				_o_return_result;
			if (ParamIndexToVal(6, E))
				_o_return_result;
			if (ParamIndexToVal(7, R))
				_o_return_result;
			if (ParamIndexToVal(8, t))
				_o_return_result;
			if (aParamCount > 9)
				TokenToVal(*aParam[9], method, true);
			if (aParamCount > 10)
				TokenToVal(*aParam[10], prob, true);
			if (aParamCount > 11)
				TokenToVal(*aParam[11], threshold, true);
			if (aParamCount > 12)
				TokenToVal(*aParam[12], mask, true);
			auto __retval = (__int64)cv::recoverPose(points1, points2, cameraMatrix1, distCoeffs1, cameraMatrix2, distCoeffs2, E, R, t, method, prob, threshold, mask);
			return (void)(aResultToken.SetValue(__retval));
		}
		else if (!MatchTypes("ooooooo?")) {
			cv::_InputArray E, points1, points2, cameraMatrix;
			cv::_InputOutputArray mask = cv::noArray();
			cv::_OutputArray R, t;
			if (ParamIndexToVal(0, E))
				_o_return_result;
			if (ParamIndexToVal(1, points1))
				_o_return_result;
			if (ParamIndexToVal(2, points2))
				_o_return_result;
			if (ParamIndexToVal(3, cameraMatrix))
				_o_return_result;
			if (ParamIndexToVal(4, R))
				_o_return_result;
			if (ParamIndexToVal(5, t))
				_o_return_result;
			if (aParamCount > 6)
				TokenToVal(*aParam[6], mask, true);
			auto __retval = (__int64)cv::recoverPose(E, points1, points2, cameraMatrix, R, t, mask);
			return (void)(aResultToken.SetValue(__retval));
		}
		else if (!MatchTypes("ooooof?oo")) {
			cv::_InputArray E, points1, points2;
			cv::_InputOutputArray mask = cv::noArray();
			cv::_OutputArray R, t;
			cv::Point2d pp = cv::Point2d(0, 0);
			double focal = 1.0;
			if (ParamIndexToVal(0, E))
				_o_return_result;
			if (ParamIndexToVal(1, points1))
				_o_return_result;
			if (ParamIndexToVal(2, points2))
				_o_return_result;
			if (ParamIndexToVal(3, R))
				_o_return_result;
			if (ParamIndexToVal(4, t))
				_o_return_result;
			if (aParamCount > 5)
				TokenToVal(*aParam[5], focal, true);
			if (aParamCount > 6)
				TokenToVal(*aParam[6], pp, true);
			if (aParamCount > 7)
				TokenToVal(*aParam[7], mask, true);
			auto __retval = (__int64)cv::recoverPose(E, points1, points2, R, t, focal, pp, mask);
			return (void)(aResultToken.SetValue(__retval));
		}
		else if (!MatchTypes("oooooofo?o")) {
			cv::_InputArray E, points1, points2, cameraMatrix;
			cv::_InputOutputArray mask = cv::noArray();
			cv::_OutputArray R, t, triangulatedPoints = cv::noArray();
			double distanceThresh;
			if (ParamIndexToVal(0, E))
				_o_return_result;
			if (ParamIndexToVal(1, points1))
				_o_return_result;
			if (ParamIndexToVal(2, points2))
				_o_return_result;
			if (ParamIndexToVal(3, cameraMatrix))
				_o_return_result;
			if (ParamIndexToVal(4, R))
				_o_return_result;
			if (ParamIndexToVal(5, t))
				_o_return_result;
			if (ParamIndexToVal(6, distanceThresh))
				_o_return_result;
			if (aParamCount > 7)
				TokenToVal(*aParam[7], mask, true);
			if (aParamCount > 8)
				TokenToVal(*aParam[8], triangulatedPoints, true);
			auto __retval = (__int64)cv::recoverPose(E, points1, points2, cameraMatrix, R, t, distanceThresh, mask, triangulatedPoints);
			return (void)(aResultToken.SetValue(__retval));
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case FID_rectangle: {
		if (!MatchTypes("ooooi?ii")) {
			cv::_InputOutputArray img;
			cv::Point pt1, pt2;
			cv::Scalar color;
			int thickness = 1, lineType = cv::LINE_8, shift = 0;
			if (ParamIndexToVal(0, img))
				_o_return_result;
			if (ParamIndexToVal(1, pt1))
				_o_return_result;
			if (ParamIndexToVal(2, pt2))
				_o_return_result;
			if (ParamIndexToVal(3, color))
				_o_return_result;
			if (aParamCount > 4)
				TokenToVal(*aParam[4], thickness, true);
			if (aParamCount > 5)
				TokenToVal(*aParam[5], lineType, true);
			if (aParamCount > 6)
				TokenToVal(*aParam[6], shift, true);
			cv::rectangle(img, pt1, pt2, color, thickness, lineType, shift);
			return;
		}
		else if (!MatchTypes("oooi?ii")) {
			cv::_InputOutputArray img;
			cv::Rect rec;
			cv::Scalar color;
			int thickness = 1, lineType = cv::LINE_8, shift = 0;
			if (ParamIndexToVal(0, img))
				_o_return_result;
			if (ParamIndexToVal(1, rec))
				_o_return_result;
			if (ParamIndexToVal(2, color))
				_o_return_result;
			if (aParamCount > 3)
				TokenToVal(*aParam[3], thickness, true);
			if (aParamCount > 4)
				TokenToVal(*aParam[4], lineType, true);
			if (aParamCount > 5)
				TokenToVal(*aParam[5], shift, true);
			cv::rectangle(img, rec, color, thickness, lineType, shift);
			return;
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case FID_rectify3Collinear: {
		cv::_InputArray cameraMatrix1, distCoeffs1, cameraMatrix2, distCoeffs2, cameraMatrix3, distCoeffs3, imgpt1, imgpt3, R12, T12, R13, T13;
		cv::_OutputArray R1, R2, R3, P1, P2, P3, Q;
		cv::Rect roi1, roi2;
		cv::Size imageSize, newImgSize;
		double alpha;
		int flags;
		if (ParamIndexToVal(0, cameraMatrix1))
			_o_return_result;
		if (ParamIndexToVal(1, distCoeffs1))
			_o_return_result;
		if (ParamIndexToVal(2, cameraMatrix2))
			_o_return_result;
		if (ParamIndexToVal(3, distCoeffs2))
			_o_return_result;
		if (ParamIndexToVal(4, cameraMatrix3))
			_o_return_result;
		if (ParamIndexToVal(5, distCoeffs3))
			_o_return_result;
		if (ParamIndexToVal(6, imgpt1))
			_o_return_result;
		if (ParamIndexToVal(7, imgpt3))
			_o_return_result;
		if (ParamIndexToVal(8, imageSize))
			_o_return_result;
		if (ParamIndexToVal(9, R12))
			_o_return_result;
		if (ParamIndexToVal(10, T12))
			_o_return_result;
		if (ParamIndexToVal(11, R13))
			_o_return_result;
		if (ParamIndexToVal(12, T13))
			_o_return_result;
		if (ParamIndexToVal(13, R1))
			_o_return_result;
		if (ParamIndexToVal(14, R2))
			_o_return_result;
		if (ParamIndexToVal(15, R3))
			_o_return_result;
		if (ParamIndexToVal(16, P1))
			_o_return_result;
		if (ParamIndexToVal(17, P2))
			_o_return_result;
		if (ParamIndexToVal(18, P3))
			_o_return_result;
		if (ParamIndexToVal(19, Q))
			_o_return_result;
		if (ParamIndexToVal(20, alpha))
			_o_return_result;
		if (ParamIndexToVal(21, newImgSize))
			_o_return_result;
		VarRef* var_roi1 = nullptr;
		if (ParamIndexToVal(22, var_roi1))
			_o_return_result;
		VarRef* var_roi2 = nullptr;
		if (ParamIndexToVal(23, var_roi2))
			_o_return_result;
		if (ParamIndexToVal(24, flags))
			_o_return_result;
		auto __retval = (double)cv::rectify3Collinear(cameraMatrix1, distCoeffs1, cameraMatrix2, distCoeffs2, cameraMatrix3, distCoeffs3, imgpt1, imgpt3, imageSize, R12, T12, R13, T13, R1, R2, R3, P1, P2, P3, Q, alpha, newImgSize, &roi1, &roi2, flags);
		ValToResult(roi1, aResultToken);
		g_ahkapi->VarAssign(var_roi1, aResultToken);
		g_ahkapi->ResultTokenFree(aResultToken);
		ValToResult(roi2, aResultToken);
		g_ahkapi->VarAssign(var_roi2, aResultToken);
		g_ahkapi->ResultTokenFree(aResultToken);
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_reduce: {
		cv::_InputArray src;
		cv::_OutputArray dst;
		int dim, rtype, dtype = -1;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, dst))
			_o_return_result;
		if (ParamIndexToVal(2, dim))
			_o_return_result;
		if (ParamIndexToVal(3, rtype))
			_o_return_result;
		if (aParamCount > 4)
			TokenToVal(*aParam[4], dtype, true);
		cv::reduce(src, dst, dim, rtype, dtype);
		return;
	}
	case FID_reduceArgMax: {
		bool lastIndex = false;
		cv::_InputArray src;
		cv::_OutputArray dst;
		int axis;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, dst))
			_o_return_result;
		if (ParamIndexToVal(2, axis))
			_o_return_result;
		if (aParamCount > 3)
			TokenToVal(*aParam[3], (char&)lastIndex, true);
		cv::reduceArgMax(src, dst, axis, lastIndex);
		return;
	}
	case FID_reduceArgMin: {
		bool lastIndex = false;
		cv::_InputArray src;
		cv::_OutputArray dst;
		int axis;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, dst))
			_o_return_result;
		if (ParamIndexToVal(2, axis))
			_o_return_result;
		if (aParamCount > 3)
			TokenToVal(*aParam[3], (char&)lastIndex, true);
		cv::reduceArgMin(src, dst, axis, lastIndex);
		return;
	}
	case FID_remap: {
		cv::_InputArray src, map1, map2;
		cv::_OutputArray dst;
		cv::Scalar borderValue = cv::Scalar();
		int interpolation, borderMode = cv::BORDER_CONSTANT;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, dst))
			_o_return_result;
		if (ParamIndexToVal(2, map1))
			_o_return_result;
		if (ParamIndexToVal(3, map2))
			_o_return_result;
		if (ParamIndexToVal(4, interpolation))
			_o_return_result;
		if (aParamCount > 5)
			TokenToVal(*aParam[5], borderMode, true);
		if (aParamCount > 6)
			TokenToVal(*aParam[6], borderValue, true);
		cv::remap(src, dst, map1, map2, interpolation, borderMode, borderValue);
		return;
	}
	case FID_repeat: {
		cv::_InputArray src;
		cv::_OutputArray dst;
		int ny, nx;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, ny))
			_o_return_result;
		if (ParamIndexToVal(2, nx))
			_o_return_result;
		if (ParamIndexToVal(3, dst))
			_o_return_result;
		cv::repeat(src, ny, nx, dst);
		return;
	}
	case FID_reprojectImageTo3D: {
		bool handleMissingValues = false;
		cv::_InputArray disparity, Q;
		cv::_OutputArray _3dImage;
		int ddepth = -1;
		if (ParamIndexToVal(0, disparity))
			_o_return_result;
		if (ParamIndexToVal(1, _3dImage))
			_o_return_result;
		if (ParamIndexToVal(2, Q))
			_o_return_result;
		if (aParamCount > 3)
			TokenToVal(*aParam[3], (char&)handleMissingValues, true);
		if (aParamCount > 4)
			TokenToVal(*aParam[4], ddepth, true);
		cv::reprojectImageTo3D(disparity, _3dImage, Q, handleMissingValues, ddepth);
		return;
	}
	case FID_resize: {
		cv::_InputArray src;
		cv::_OutputArray dst;
		cv::Size dsize;
		double fx = 0, fy = 0;
		int interpolation = cv::INTER_LINEAR;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, dst))
			_o_return_result;
		if (ParamIndexToVal(2, dsize))
			_o_return_result;
		if (aParamCount > 3)
			TokenToVal(*aParam[3], fx, true);
		if (aParamCount > 4)
			TokenToVal(*aParam[4], fy, true);
		if (aParamCount > 5)
			TokenToVal(*aParam[5], interpolation, true);
		cv::resize(src, dst, dsize, fx, fy, interpolation);
		return;
	}
	case FID_resizeWindow: {
		if (aParamCount == 3) {
			cv::String winname;
			int width, height;
			if (ParamIndexToVal(0, winname))
				_o_return_result;
			if (ParamIndexToVal(1, width))
				_o_return_result;
			if (ParamIndexToVal(2, height))
				_o_return_result;
			cv::resizeWindow(winname, width, height);
			return;
		}
		else if (aParamCount == 2) {
			cv::Size size;
			cv::String winname;
			if (ParamIndexToVal(0, winname))
				_o_return_result;
			if (ParamIndexToVal(1, size))
				_o_return_result;
			cv::resizeWindow(winname, size);
			return;
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case FID_rotate: {
		cv::_InputArray src;
		cv::_OutputArray dst;
		int rotateCode;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, dst))
			_o_return_result;
		if (ParamIndexToVal(2, rotateCode))
			_o_return_result;
		cv::rotate(src, dst, rotateCode);
		return;
	}
	case FID_rotatedRectangleIntersection: {
		cv::_OutputArray intersectingRegion;
		cv::RotatedRect rect1, rect2;
		if (ParamIndexToVal(0, rect1))
			_o_return_result;
		if (ParamIndexToVal(1, rect2))
			_o_return_result;
		if (ParamIndexToVal(2, intersectingRegion))
			_o_return_result;
		auto __retval = (__int64)cv::rotatedRectangleIntersection(rect1, rect2, intersectingRegion);
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_sampsonDistance: {
		cv::_InputArray pt1, pt2, F;
		if (ParamIndexToVal(0, pt1))
			_o_return_result;
		if (ParamIndexToVal(1, pt2))
			_o_return_result;
		if (ParamIndexToVal(2, F))
			_o_return_result;
		auto __retval = cv::sampsonDistance(pt1, pt2, F);
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_scaleAdd: {
		cv::_InputArray src1, src2;
		cv::_OutputArray dst;
		double alpha;
		if (ParamIndexToVal(0, src1))
			_o_return_result;
		if (ParamIndexToVal(1, alpha))
			_o_return_result;
		if (ParamIndexToVal(2, src2))
			_o_return_result;
		if (ParamIndexToVal(3, dst))
			_o_return_result;
		cv::scaleAdd(src1, alpha, src2, dst);
		return;
	}
	case FID_seamlessClone: {
		cv::_InputArray src, dst, mask;
		cv::_OutputArray blend;
		cv::Point p;
		int flags;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, dst))
			_o_return_result;
		if (ParamIndexToVal(2, mask))
			_o_return_result;
		if (ParamIndexToVal(3, p))
			_o_return_result;
		if (ParamIndexToVal(4, blend))
			_o_return_result;
		if (ParamIndexToVal(5, flags))
			_o_return_result;
		cv::seamlessClone(src, dst, mask, p, blend, flags);
		return;
	}
	case FID_selectROI: {
		if (!MatchTypes("soi?i")) {
			bool showCrosshair = true, fromCenter = false;
			cv::_InputArray img;
			cv::String windowName;
			if (ParamIndexToVal(0, windowName))
				_o_return_result;
			if (ParamIndexToVal(1, img))
				_o_return_result;
			if (aParamCount > 2)
				TokenToVal(*aParam[2], (char&)showCrosshair, true);
			if (aParamCount > 3)
				TokenToVal(*aParam[3], (char&)fromCenter, true);
			auto __retval = cv::selectROI(windowName, img, showCrosshair, fromCenter);
			return ValToResult(__retval, aResultToken);
		}
		else if (!MatchTypes("oi?i")) {
			bool showCrosshair = true, fromCenter = false;
			cv::_InputArray img;
			if (ParamIndexToVal(0, img))
				_o_return_result;
			if (aParamCount > 1)
				TokenToVal(*aParam[1], (char&)showCrosshair, true);
			if (aParamCount > 2)
				TokenToVal(*aParam[2], (char&)fromCenter, true);
			auto __retval = cv::selectROI(img, showCrosshair, fromCenter);
			return ValToResult(__retval, aResultToken);
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case FID_selectROIs: {
		bool showCrosshair = true, fromCenter = false;
		cv::_InputArray img;
		cv::String windowName;
		std::vector<cv::Rect> boundingBoxes;
		if (ParamIndexToVal(0, windowName))
			_o_return_result;
		if (ParamIndexToVal(1, img))
			_o_return_result;
		VarRef* var_boundingBoxes = nullptr;
		if (ParamIndexToVal(2, var_boundingBoxes))
			_o_return_result;
		if (aParamCount > 3)
			TokenToVal(*aParam[3], (char&)showCrosshair, true);
		if (aParamCount > 4)
			TokenToVal(*aParam[4], (char&)fromCenter, true);
		cv::selectROIs(windowName, img, boundingBoxes, showCrosshair, fromCenter);
		ValToResult(boundingBoxes, aResultToken);
		g_ahkapi->VarAssign(var_boundingBoxes, aResultToken);
		g_ahkapi->ResultTokenFree(aResultToken);
		return;
	}
	case FID_sepFilter2D: {
		cv::_InputArray src, kernelX, kernelY;
		cv::_OutputArray dst;
		cv::Point anchor = cv::Point(-1, -1);
		double delta = 0;
		int ddepth, borderType = cv::BORDER_DEFAULT;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, dst))
			_o_return_result;
		if (ParamIndexToVal(2, ddepth))
			_o_return_result;
		if (ParamIndexToVal(3, kernelX))
			_o_return_result;
		if (ParamIndexToVal(4, kernelY))
			_o_return_result;
		if (aParamCount > 5)
			TokenToVal(*aParam[5], anchor, true);
		if (aParamCount > 6)
			TokenToVal(*aParam[6], delta, true);
		if (aParamCount > 7)
			TokenToVal(*aParam[7], borderType, true);
		cv::sepFilter2D(src, dst, ddepth, kernelX, kernelY, anchor, delta, borderType);
		return;
	}
	case FID_setIdentity: {
		cv::_InputOutputArray mtx;
		cv::Scalar s = cv::Scalar(1);
		if (ParamIndexToVal(0, mtx))
			_o_return_result;
		if (aParamCount > 1)
			TokenToVal(*aParam[1], s, true);
		cv::setIdentity(mtx, s);
		return;
	}
	case FID_setLogLevel: {
		int level;
		if (ParamIndexToVal(0, level))
			_o_return_result;
		auto __retval = (__int64)cv::setLogLevel(level);
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_setNumThreads: {
		int nthreads;
		if (ParamIndexToVal(0, nthreads))
			_o_return_result;
		cv::setNumThreads(nthreads);
		return;
	}
	case FID_setMouseCallback: {
		static cv::MouseCallback cb = [](int event, int x, int y, int flags, void* userdata) {
			ExprTokenType param[4], * params[] = { param,param + 1,param + 2,param + 3 };
			ResultToken result{};
			TCHAR buf[256];
			result.SetValue(_T(""));
			result.buf = buf, result.result = OK;
			param[0].SetValue(event);
			param[1].SetValue(x);
			param[2].SetValue(y);
			param[3].SetValue(flags);
			((IObject*)userdata)->Invoke(result, IT_CALL, nullptr, ExprTokenType((IObject*)userdata), params, 4);
			g_ahkapi->ResultTokenFree(result);
		};
		cv::String winname;
		IObject* ahkobj;
		if (ParamIndexToVal(0, winname))
			_o_return_result;
		if ((__result = TokenToObject(*aParam[1], ahkobj, _T("Func"))) != CONDITION_TRUE)
			_o_return_result;
		cv::setMouseCallback(winname, cb, ahkobj);
		return;
	}
	case FID_setRNGSeed: {
		int seed;
		if (ParamIndexToVal(0, seed))
			_o_return_result;
		cv::setRNGSeed(seed);
		return;
	}
	case FID_setTrackbarMax: {
		cv::String trackbarname, winname;
		int maxval;
		if (ParamIndexToVal(0, trackbarname))
			_o_return_result;
		if (ParamIndexToVal(1, winname))
			_o_return_result;
		if (ParamIndexToVal(2, maxval))
			_o_return_result;
		cv::setTrackbarMax(trackbarname, winname, maxval);
		return;
	}
	case FID_setTrackbarMin: {
		cv::String trackbarname, winname;
		int minval;
		if (ParamIndexToVal(0, trackbarname))
			_o_return_result;
		if (ParamIndexToVal(1, winname))
			_o_return_result;
		if (ParamIndexToVal(2, minval))
			_o_return_result;
		cv::setTrackbarMin(trackbarname, winname, minval);
		return;
	}
	case FID_setTrackbarPos: {
		cv::String trackbarname, winname;
		int pos;
		if (ParamIndexToVal(0, trackbarname))
			_o_return_result;
		if (ParamIndexToVal(1, winname))
			_o_return_result;
		if (ParamIndexToVal(2, pos))
			_o_return_result;
		cv::setTrackbarPos(trackbarname, winname, pos);
		return;
	}
	case FID_setUseOpenVX: {
		bool flag;
		if (ParamIndexToVal(0, (char&)flag))
			_o_return_result;
		cv::setUseOpenVX(flag);
		return;
	}
	case FID_setUseOptimized: {
		bool onoff;
		if (ParamIndexToVal(0, (char&)onoff))
			_o_return_result;
		cv::setUseOptimized(onoff);
		return;
	}
	case FID_setWindowProperty: {
		cv::String winname;
		double prop_value;
		int prop_id;
		if (ParamIndexToVal(0, winname))
			_o_return_result;
		if (ParamIndexToVal(1, prop_id))
			_o_return_result;
		if (ParamIndexToVal(2, prop_value))
			_o_return_result;
		cv::setWindowProperty(winname, prop_id, prop_value);
		return;
	}
	case FID_setWindowTitle: {
		cv::String winname, title;
		if (ParamIndexToVal(0, winname))
			_o_return_result;
		if (ParamIndexToVal(1, title))
			_o_return_result;
		cv::setWindowTitle(winname, title);
		return;
	}
	case FID_solve: {
		cv::_InputArray src1, src2;
		cv::_OutputArray dst;
		int flags = cv::DECOMP_LU;
		if (ParamIndexToVal(0, src1))
			_o_return_result;
		if (ParamIndexToVal(1, src2))
			_o_return_result;
		if (ParamIndexToVal(2, dst))
			_o_return_result;
		if (aParamCount > 3)
			TokenToVal(*aParam[3], flags, true);
		auto __retval = (__int64)cv::solve(src1, src2, dst, flags);
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_solveCubic: {
		cv::_InputArray coeffs;
		cv::_OutputArray roots;
		if (ParamIndexToVal(0, coeffs))
			_o_return_result;
		if (ParamIndexToVal(1, roots))
			_o_return_result;
		auto __retval = (__int64)cv::solveCubic(coeffs, roots);
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_solveLP: {
		cv::_InputArray Func, Constr;
		cv::_OutputArray z;
		if (ParamIndexToVal(0, Func))
			_o_return_result;
		if (ParamIndexToVal(1, Constr))
			_o_return_result;
		if (ParamIndexToVal(2, z))
			_o_return_result;
		auto __retval = (__int64)cv::solveLP(Func, Constr, z);
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_solveP3P: {
		cv::_InputArray objectPoints, imagePoints, cameraMatrix, distCoeffs;
		cv::_OutputArray rvecs, tvecs;
		int flags;
		if (ParamIndexToVal(0, objectPoints))
			_o_return_result;
		if (ParamIndexToVal(1, imagePoints))
			_o_return_result;
		if (ParamIndexToVal(2, cameraMatrix))
			_o_return_result;
		if (ParamIndexToVal(3, distCoeffs))
			_o_return_result;
		if (ParamIndexToVal(4, rvecs))
			_o_return_result;
		if (ParamIndexToVal(5, tvecs))
			_o_return_result;
		if (ParamIndexToVal(6, flags))
			_o_return_result;
		auto __retval = (__int64)cv::solveP3P(objectPoints, imagePoints, cameraMatrix, distCoeffs, rvecs, tvecs, flags);
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_solvePnP: {
		bool useExtrinsicGuess = false;
		cv::_InputArray objectPoints, imagePoints, cameraMatrix, distCoeffs;
		cv::_OutputArray rvec, tvec;
		int flags = cv::SOLVEPNP_ITERATIVE;
		if (ParamIndexToVal(0, objectPoints))
			_o_return_result;
		if (ParamIndexToVal(1, imagePoints))
			_o_return_result;
		if (ParamIndexToVal(2, cameraMatrix))
			_o_return_result;
		if (ParamIndexToVal(3, distCoeffs))
			_o_return_result;
		if (ParamIndexToVal(4, rvec))
			_o_return_result;
		if (ParamIndexToVal(5, tvec))
			_o_return_result;
		if (aParamCount > 6)
			TokenToVal(*aParam[6], (char&)useExtrinsicGuess, true);
		if (aParamCount > 7)
			TokenToVal(*aParam[7], flags, true);
		auto __retval = (__int64)cv::solvePnP(objectPoints, imagePoints, cameraMatrix, distCoeffs, rvec, tvec, useExtrinsicGuess, flags);
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_solvePnPGeneric: {
		bool useExtrinsicGuess = false;
		cv::_InputArray objectPoints, imagePoints, cameraMatrix, distCoeffs, rvec = cv::noArray(), tvec = cv::noArray();
		cv::_OutputArray rvecs, tvecs, reprojectionError = cv::noArray();
		int flags = cv::SOLVEPNP_ITERATIVE;
		if (ParamIndexToVal(0, objectPoints))
			_o_return_result;
		if (ParamIndexToVal(1, imagePoints))
			_o_return_result;
		if (ParamIndexToVal(2, cameraMatrix))
			_o_return_result;
		if (ParamIndexToVal(3, distCoeffs))
			_o_return_result;
		if (ParamIndexToVal(4, rvecs))
			_o_return_result;
		if (ParamIndexToVal(5, tvecs))
			_o_return_result;
		if (aParamCount > 6)
			TokenToVal(*aParam[6], (char&)useExtrinsicGuess, true);
		if (aParamCount > 7)
			TokenToVal(*aParam[7], flags, true);
		if (aParamCount > 8)
			TokenToVal(*aParam[8], rvec, true);
		if (aParamCount > 9)
			TokenToVal(*aParam[9], tvec, true);
		if (aParamCount > 10)
			TokenToVal(*aParam[10], reprojectionError, true);
		auto __retval = (__int64)cv::solvePnPGeneric(objectPoints, imagePoints, cameraMatrix, distCoeffs, rvecs, tvecs, useExtrinsicGuess, (cv::SolvePnPMethod)flags, rvec, tvec, reprojectionError);
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_solvePnPRansac: {
		if (!MatchTypes("ooooooi?iffoi")) {
			bool useExtrinsicGuess = false;
			cv::_InputArray objectPoints, imagePoints, cameraMatrix, distCoeffs;
			cv::_OutputArray rvec, tvec, inliers = cv::noArray();
			double confidence = 0.99;
			float reprojectionError = 8.0;
			int iterationsCount = 100, flags = cv::SOLVEPNP_ITERATIVE;
			if (ParamIndexToVal(0, objectPoints))
				_o_return_result;
			if (ParamIndexToVal(1, imagePoints))
				_o_return_result;
			if (ParamIndexToVal(2, cameraMatrix))
				_o_return_result;
			if (ParamIndexToVal(3, distCoeffs))
				_o_return_result;
			if (ParamIndexToVal(4, rvec))
				_o_return_result;
			if (ParamIndexToVal(5, tvec))
				_o_return_result;
			if (aParamCount > 6)
				TokenToVal(*aParam[6], (char&)useExtrinsicGuess, true);
			if (aParamCount > 7)
				TokenToVal(*aParam[7], iterationsCount, true);
			if (aParamCount > 8)
				TokenToVal(*aParam[8], reprojectionError, true);
			if (aParamCount > 9)
				TokenToVal(*aParam[9], confidence, true);
			if (aParamCount > 10)
				TokenToVal(*aParam[10], inliers, true);
			if (aParamCount > 11)
				TokenToVal(*aParam[11], flags, true);
			auto __retval = (__int64)cv::solvePnPRansac(objectPoints, imagePoints, cameraMatrix, distCoeffs, rvec, tvec, useExtrinsicGuess, iterationsCount, reprojectionError, confidence, inliers, flags);
			return (void)(aResultToken.SetValue(__retval));
		}
		else if (!MatchTypes("oooooooo?")) {
			cv::_InputArray objectPoints, imagePoints, distCoeffs;
			cv::_InputOutputArray cameraMatrix;
			cv::_OutputArray rvec, tvec, inliers;
			cv::UsacParams params = cv::UsacParams();
			if (ParamIndexToVal(0, objectPoints))
				_o_return_result;
			if (ParamIndexToVal(1, imagePoints))
				_o_return_result;
			if (ParamIndexToVal(2, cameraMatrix))
				_o_return_result;
			if (ParamIndexToVal(3, distCoeffs))
				_o_return_result;
			if (ParamIndexToVal(4, rvec))
				_o_return_result;
			if (ParamIndexToVal(5, tvec))
				_o_return_result;
			if (ParamIndexToVal(6, inliers))
				_o_return_result;
			if (aParamCount > 7)
				TokenToVal(*aParam[7], params, true);
			auto __retval = (__int64)cv::solvePnPRansac(objectPoints, imagePoints, cameraMatrix, distCoeffs, rvec, tvec, inliers, params);
			return (void)(aResultToken.SetValue(__retval));
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case FID_solvePnPRefineLM: {
		cv::_InputArray objectPoints, imagePoints, cameraMatrix, distCoeffs;
		cv::_InputOutputArray rvec, tvec;
		cv::TermCriteria criteria = cv::TermCriteria(cv::TermCriteria::EPS + cv::TermCriteria::COUNT, 20, FLT_EPSILON);
		;
		if (ParamIndexToVal(0, objectPoints))
			_o_return_result;
		if (ParamIndexToVal(1, imagePoints))
			_o_return_result;
		if (ParamIndexToVal(2, cameraMatrix))
			_o_return_result;
		if (ParamIndexToVal(3, distCoeffs))
			_o_return_result;
		if (ParamIndexToVal(4, rvec))
			_o_return_result;
		if (ParamIndexToVal(5, tvec))
			_o_return_result;
		if (aParamCount > 6)
			TokenToVal(*aParam[6], criteria, true);
		cv::solvePnPRefineLM(objectPoints, imagePoints, cameraMatrix, distCoeffs, rvec, tvec, criteria);
		return;
	}
	case FID_solvePnPRefineVVS: {
		cv::_InputArray objectPoints, imagePoints, cameraMatrix, distCoeffs;
		cv::_InputOutputArray rvec, tvec;
		cv::TermCriteria criteria = cv::TermCriteria(cv::TermCriteria::EPS + cv::TermCriteria::COUNT, 20, FLT_EPSILON);
		;
		double VVSlambda = 1;
		if (ParamIndexToVal(0, objectPoints))
			_o_return_result;
		if (ParamIndexToVal(1, imagePoints))
			_o_return_result;
		if (ParamIndexToVal(2, cameraMatrix))
			_o_return_result;
		if (ParamIndexToVal(3, distCoeffs))
			_o_return_result;
		if (ParamIndexToVal(4, rvec))
			_o_return_result;
		if (ParamIndexToVal(5, tvec))
			_o_return_result;
		if (aParamCount > 6)
			TokenToVal(*aParam[6], criteria, true);
		if (aParamCount > 7)
			TokenToVal(*aParam[7], VVSlambda, true);
		cv::solvePnPRefineVVS(objectPoints, imagePoints, cameraMatrix, distCoeffs, rvec, tvec, criteria, VVSlambda);
		return;
	}
	case FID_solvePoly: {
		cv::_InputArray coeffs;
		cv::_OutputArray roots;
		int maxIters = 300;
		if (ParamIndexToVal(0, coeffs))
			_o_return_result;
		if (ParamIndexToVal(1, roots))
			_o_return_result;
		if (aParamCount > 2)
			TokenToVal(*aParam[2], maxIters, true);
		auto __retval = cv::solvePoly(coeffs, roots, maxIters);
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_sort: {
		cv::_InputArray src;
		cv::_OutputArray dst;
		int flags;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, dst))
			_o_return_result;
		if (ParamIndexToVal(2, flags))
			_o_return_result;
		cv::sort(src, dst, flags);
		return;
	}
	case FID_sortIdx: {
		cv::_InputArray src;
		cv::_OutputArray dst;
		int flags;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, dst))
			_o_return_result;
		if (ParamIndexToVal(2, flags))
			_o_return_result;
		cv::sortIdx(src, dst, flags);
		return;
	}
	case FID_spatialGradient: {
		cv::_InputArray src;
		cv::_OutputArray dx, dy;
		int ksize = 3, borderType = cv::BORDER_DEFAULT;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, dx))
			_o_return_result;
		if (ParamIndexToVal(2, dy))
			_o_return_result;
		if (aParamCount > 3)
			TokenToVal(*aParam[3], ksize, true);
		if (aParamCount > 4)
			TokenToVal(*aParam[4], borderType, true);
		cv::spatialGradient(src, dx, dy, ksize, borderType);
		return;
	}
	case FID_split: {
		cv::_InputArray m;
		cv::_OutputArray mv;
		if (ParamIndexToVal(0, m))
			_o_return_result;
		if (ParamIndexToVal(1, mv))
			_o_return_result;
		cv::split(m, mv);
		return;
	}
	case FID_sqrBoxFilter: {
		bool normalize = true;
		cv::_InputArray src;
		cv::_OutputArray dst;
		cv::Point anchor = cv::Point(-1, -1);
		cv::Size ksize;
		int ddepth, borderType = cv::BORDER_DEFAULT;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, dst))
			_o_return_result;
		if (ParamIndexToVal(2, ddepth))
			_o_return_result;
		if (ParamIndexToVal(3, ksize))
			_o_return_result;
		if (aParamCount > 4)
			TokenToVal(*aParam[4], anchor, true);
		if (aParamCount > 5)
			TokenToVal(*aParam[5], (char&)normalize, true);
		if (aParamCount > 6)
			TokenToVal(*aParam[6], borderType, true);
		cv::sqrBoxFilter(src, dst, ddepth, ksize, anchor, normalize, borderType);
		return;
	}
	case FID_sqrt: {
		cv::_InputArray src;
		cv::_OutputArray dst;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, dst))
			_o_return_result;
		cv::sqrt(src, dst);
		return;
	}
	case FID_startWindowThread: {
		auto __retval = (__int64)cv::startWindowThread();
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_stereoCalibrate: {
		if (!MatchTypes("oooooooooooooi?o")) {
			cv::_InputArray objectPoints, imagePoints1, imagePoints2;
			cv::_InputOutputArray cameraMatrix1, distCoeffs1, cameraMatrix2, distCoeffs2, R, T;
			cv::_OutputArray E, F, perViewErrors;
			cv::Size imageSize;
			cv::TermCriteria criteria = cv::TermCriteria(cv::TermCriteria::COUNT + cv::TermCriteria::EPS, 30, 1e-6);
			;
			int flags = cv::CALIB_FIX_INTRINSIC;
			if (ParamIndexToVal(0, objectPoints))
				_o_return_result;
			if (ParamIndexToVal(1, imagePoints1))
				_o_return_result;
			if (ParamIndexToVal(2, imagePoints2))
				_o_return_result;
			if (ParamIndexToVal(3, cameraMatrix1))
				_o_return_result;
			if (ParamIndexToVal(4, distCoeffs1))
				_o_return_result;
			if (ParamIndexToVal(5, cameraMatrix2))
				_o_return_result;
			if (ParamIndexToVal(6, distCoeffs2))
				_o_return_result;
			if (ParamIndexToVal(7, imageSize))
				_o_return_result;
			if (ParamIndexToVal(8, R))
				_o_return_result;
			if (ParamIndexToVal(9, T))
				_o_return_result;
			if (ParamIndexToVal(10, E))
				_o_return_result;
			if (ParamIndexToVal(11, F))
				_o_return_result;
			if (ParamIndexToVal(12, perViewErrors))
				_o_return_result;
			if (aParamCount > 13)
				TokenToVal(*aParam[13], flags, true);
			if (aParamCount > 14)
				TokenToVal(*aParam[14], criteria, true);
			auto __retval = cv::stereoCalibrate(objectPoints, imagePoints1, imagePoints2, cameraMatrix1, distCoeffs1, cameraMatrix2, distCoeffs2, imageSize, R, T, E, F, perViewErrors, flags, criteria);
			return (void)(aResultToken.SetValue(__retval));
		}
		else if (!MatchTypes("ooooooooooooi?o")) {
			cv::_InputArray objectPoints, imagePoints1, imagePoints2;
			cv::_InputOutputArray cameraMatrix1, distCoeffs1, cameraMatrix2, distCoeffs2;
			cv::_OutputArray R, T, E, F;
			cv::Size imageSize;
			cv::TermCriteria criteria = cv::TermCriteria(cv::TermCriteria::COUNT + cv::TermCriteria::EPS, 30, 1e-6);
			;
			int flags = cv::CALIB_FIX_INTRINSIC;
			if (ParamIndexToVal(0, objectPoints))
				_o_return_result;
			if (ParamIndexToVal(1, imagePoints1))
				_o_return_result;
			if (ParamIndexToVal(2, imagePoints2))
				_o_return_result;
			if (ParamIndexToVal(3, cameraMatrix1))
				_o_return_result;
			if (ParamIndexToVal(4, distCoeffs1))
				_o_return_result;
			if (ParamIndexToVal(5, cameraMatrix2))
				_o_return_result;
			if (ParamIndexToVal(6, distCoeffs2))
				_o_return_result;
			if (ParamIndexToVal(7, imageSize))
				_o_return_result;
			if (ParamIndexToVal(8, R))
				_o_return_result;
			if (ParamIndexToVal(9, T))
				_o_return_result;
			if (ParamIndexToVal(10, E))
				_o_return_result;
			if (ParamIndexToVal(11, F))
				_o_return_result;
			if (aParamCount > 12)
				TokenToVal(*aParam[12], flags, true);
			if (aParamCount > 13)
				TokenToVal(*aParam[13], criteria, true);
			auto __retval = cv::stereoCalibrate(objectPoints, imagePoints1, imagePoints2, cameraMatrix1, distCoeffs1, cameraMatrix2, distCoeffs2, imageSize, R, T, E, F, flags, criteria);
			return (void)(aResultToken.SetValue(__retval));
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case FID_stereoRectify: {
		cv::_InputArray cameraMatrix1, distCoeffs1, cameraMatrix2, distCoeffs2, R, T;
		cv::_OutputArray R1, R2, P1, P2, Q;
		cv::Rect validPixROI1, validPixROI2;
		cv::Size imageSize, newImageSize = cv::Size();
		double alpha = -1;
		int flags = cv::CALIB_ZERO_DISPARITY;
		if (ParamIndexToVal(0, cameraMatrix1))
			_o_return_result;
		if (ParamIndexToVal(1, distCoeffs1))
			_o_return_result;
		if (ParamIndexToVal(2, cameraMatrix2))
			_o_return_result;
		if (ParamIndexToVal(3, distCoeffs2))
			_o_return_result;
		if (ParamIndexToVal(4, imageSize))
			_o_return_result;
		if (ParamIndexToVal(5, R))
			_o_return_result;
		if (ParamIndexToVal(6, T))
			_o_return_result;
		if (ParamIndexToVal(7, R1))
			_o_return_result;
		if (ParamIndexToVal(8, R2))
			_o_return_result;
		if (ParamIndexToVal(9, P1))
			_o_return_result;
		if (ParamIndexToVal(10, P2))
			_o_return_result;
		if (ParamIndexToVal(11, Q))
			_o_return_result;
		if (aParamCount > 12)
			TokenToVal(*aParam[12], flags, true);
		if (aParamCount > 13)
			TokenToVal(*aParam[13], alpha, true);
		if (aParamCount > 14)
			TokenToVal(*aParam[14], newImageSize, true);
		VarRef* var_validPixROI1 = nullptr;
		if (aParamCount > 15) {
			TokenToVal(*aParam[15], var_validPixROI1, true);
		}
		VarRef* var_validPixROI2 = nullptr;
		if (aParamCount > 16) {
			TokenToVal(*aParam[16], var_validPixROI2, true);
		}
		cv::stereoRectify(cameraMatrix1, distCoeffs1, cameraMatrix2, distCoeffs2, imageSize, R, T, R1, R2, P1, P2, Q, flags, alpha, newImageSize, &validPixROI1, &validPixROI2);
		if (var_validPixROI1) {
			ValToResult(validPixROI1, aResultToken);
			g_ahkapi->VarAssign(var_validPixROI1, aResultToken);
			g_ahkapi->ResultTokenFree(aResultToken);
		}
		if (var_validPixROI2) {
			ValToResult(validPixROI2, aResultToken);
			g_ahkapi->VarAssign(var_validPixROI2, aResultToken);
			g_ahkapi->ResultTokenFree(aResultToken);
		}
		return;
	}
	case FID_stereoRectifyUncalibrated: {
		cv::_InputArray points1, points2, F;
		cv::_OutputArray H1, H2;
		cv::Size imgSize;
		double threshold = 5;
		if (ParamIndexToVal(0, points1))
			_o_return_result;
		if (ParamIndexToVal(1, points2))
			_o_return_result;
		if (ParamIndexToVal(2, F))
			_o_return_result;
		if (ParamIndexToVal(3, imgSize))
			_o_return_result;
		if (ParamIndexToVal(4, H1))
			_o_return_result;
		if (ParamIndexToVal(5, H2))
			_o_return_result;
		if (aParamCount > 6)
			TokenToVal(*aParam[6], threshold, true);
		auto __retval = (__int64)cv::stereoRectifyUncalibrated(points1, points2, F, imgSize, H1, H2, threshold);
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_stylization: {
		cv::_InputArray src;
		cv::_OutputArray dst;
		float sigma_s = 60, sigma_r = 0.45f;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, dst))
			_o_return_result;
		if (aParamCount > 2)
			TokenToVal(*aParam[2], sigma_s, true);
		if (aParamCount > 3)
			TokenToVal(*aParam[3], sigma_r, true);
		cv::stylization(src, dst, sigma_s, sigma_r);
		return;
	}
	case FID_subtract: {
		cv::_InputArray src1, src2, mask = cv::noArray();
		cv::_OutputArray dst;
		int dtype = -1;
		if (ParamIndexToVal(0, src1))
			_o_return_result;
		if (ParamIndexToVal(1, src2))
			_o_return_result;
		if (ParamIndexToVal(2, dst))
			_o_return_result;
		if (aParamCount > 3)
			TokenToVal(*aParam[3], mask, true);
		if (aParamCount > 4)
			TokenToVal(*aParam[4], dtype, true);
		cv::subtract(src1, src2, dst, mask, dtype);
		return;
	}
	case FID_sum: {
		cv::_InputArray src;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		auto __retval = cv::sum(src);
		return ValToResult(__retval, aResultToken);
	}
	case FID_textureFlattening: {
		cv::_InputArray src, mask;
		cv::_OutputArray dst;
		float low_threshold = 30, high_threshold = 45;
		int kernel_size = 3;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, mask))
			_o_return_result;
		if (ParamIndexToVal(2, dst))
			_o_return_result;
		if (aParamCount > 3)
			TokenToVal(*aParam[3], low_threshold, true);
		if (aParamCount > 4)
			TokenToVal(*aParam[4], high_threshold, true);
		if (aParamCount > 5)
			TokenToVal(*aParam[5], kernel_size, true);
		cv::textureFlattening(src, mask, dst, low_threshold, high_threshold, kernel_size);
		return;
	}
	case FID_threshold: {
		cv::_InputArray src;
		cv::_OutputArray dst;
		double thresh, maxval;
		int type;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, dst))
			_o_return_result;
		if (ParamIndexToVal(2, thresh))
			_o_return_result;
		if (ParamIndexToVal(3, maxval))
			_o_return_result;
		if (ParamIndexToVal(4, type))
			_o_return_result;
		auto __retval = cv::threshold(src, dst, thresh, maxval, type);
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_trace: {
		cv::_InputArray mtx;
		if (ParamIndexToVal(0, mtx))
			_o_return_result;
		auto __retval = cv::trace(mtx);
		return ValToResult(__retval, aResultToken);
	}
	case FID_transform: {
		cv::_InputArray src, m;
		cv::_OutputArray dst;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, dst))
			_o_return_result;
		if (ParamIndexToVal(2, m))
			_o_return_result;
		cv::transform(src, dst, m);
		return;
	}
	case FID_transpose: {
		cv::_InputArray src;
		cv::_OutputArray dst;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, dst))
			_o_return_result;
		cv::transpose(src, dst);
		return;
	}
	case FID_triangulatePoints: {
		cv::_InputArray projMatr1, projMatr2, projPoints1, projPoints2;
		cv::_OutputArray points4D;
		if (ParamIndexToVal(0, projMatr1))
			_o_return_result;
		if (ParamIndexToVal(1, projMatr2))
			_o_return_result;
		if (ParamIndexToVal(2, projPoints1))
			_o_return_result;
		if (ParamIndexToVal(3, projPoints2))
			_o_return_result;
		if (ParamIndexToVal(4, points4D))
			_o_return_result;
		cv::triangulatePoints(projMatr1, projMatr2, projPoints1, projPoints2, points4D);
		return;
	}
	case FID_undistort: {
		cv::_InputArray src, cameraMatrix, distCoeffs, newCameraMatrix = cv::noArray();
		cv::_OutputArray dst;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, dst))
			_o_return_result;
		if (ParamIndexToVal(2, cameraMatrix))
			_o_return_result;
		if (ParamIndexToVal(3, distCoeffs))
			_o_return_result;
		if (aParamCount > 4)
			TokenToVal(*aParam[4], newCameraMatrix, true);
		cv::undistort(src, dst, cameraMatrix, distCoeffs, newCameraMatrix);
		return;
	}
	case FID_undistortPoints: {
		if (4 <= aParamCount && aParamCount <= 6) {
			cv::_InputArray src, cameraMatrix, distCoeffs, R = cv::noArray(), P = cv::noArray();
			cv::_OutputArray dst;
			if (ParamIndexToVal(0, src))
				_o_return_result;
			if (ParamIndexToVal(1, dst))
				_o_return_result;
			if (ParamIndexToVal(2, cameraMatrix))
				_o_return_result;
			if (ParamIndexToVal(3, distCoeffs))
				_o_return_result;
			if (aParamCount > 4)
				TokenToVal(*aParam[4], R, true);
			if (aParamCount > 5)
				TokenToVal(*aParam[5], P, true);
			cv::undistortPoints(src, dst, cameraMatrix, distCoeffs, R, P);
			return;
		}
		else if (aParamCount == 7) {
			cv::_InputArray src, cameraMatrix, distCoeffs, R, P;
			cv::_OutputArray dst;
			cv::TermCriteria criteria;
			if (ParamIndexToVal(0, src))
				_o_return_result;
			if (ParamIndexToVal(1, dst))
				_o_return_result;
			if (ParamIndexToVal(2, cameraMatrix))
				_o_return_result;
			if (ParamIndexToVal(3, distCoeffs))
				_o_return_result;
			if (ParamIndexToVal(4, R))
				_o_return_result;
			if (ParamIndexToVal(5, P))
				_o_return_result;
			if (ParamIndexToVal(6, criteria))
				_o_return_result;
			cv::undistortPoints(src, dst, cameraMatrix, distCoeffs, R, P, criteria);
			return;
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case FID_useOpenVX: {
		auto __retval = (__int64)cv::useOpenVX();
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_useOptimized: {
		auto __retval = (__int64)cv::useOptimized();
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_validateDisparity: {
		cv::_InputArray cost;
		cv::_InputOutputArray disparity;
		int minDisparity, numberOfDisparities, disp12MaxDisp = 1;
		if (ParamIndexToVal(0, disparity))
			_o_return_result;
		if (ParamIndexToVal(1, cost))
			_o_return_result;
		if (ParamIndexToVal(2, minDisparity))
			_o_return_result;
		if (ParamIndexToVal(3, numberOfDisparities))
			_o_return_result;
		if (aParamCount > 4)
			TokenToVal(*aParam[4], disp12MaxDisp, true);
		cv::validateDisparity(disparity, cost, minDisparity, numberOfDisparities, disp12MaxDisp);
		return;
	}
	case FID_vconcat: {
		cv::_InputArray src;
		cv::_OutputArray dst;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, dst))
			_o_return_result;
		cv::vconcat(src, dst);
		return;
	}
	case FID_waitKey: {
		int delay = 0;
		if (aParamCount > 0)
			TokenToVal(*aParam[0], delay, true);
		auto __retval = (__int64)cv::waitKey(delay);
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_waitKeyEx: {
		int delay = 0;
		if (aParamCount > 0)
			TokenToVal(*aParam[0], delay, true);
		auto __retval = (__int64)cv::waitKeyEx(delay);
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_warpAffine: {
		cv::_InputArray src, M;
		cv::_OutputArray dst;
		cv::Scalar borderValue = cv::Scalar();
		cv::Size dsize;
		int flags = cv::INTER_LINEAR, borderMode = cv::BORDER_CONSTANT;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, dst))
			_o_return_result;
		if (ParamIndexToVal(2, M))
			_o_return_result;
		if (ParamIndexToVal(3, dsize))
			_o_return_result;
		if (aParamCount > 4)
			TokenToVal(*aParam[4], flags, true);
		if (aParamCount > 5)
			TokenToVal(*aParam[5], borderMode, true);
		if (aParamCount > 6)
			TokenToVal(*aParam[6], borderValue, true);
		cv::warpAffine(src, dst, M, dsize, flags, borderMode, borderValue);
		return;
	}
	case FID_warpPerspective: {
		cv::_InputArray src, M;
		cv::_OutputArray dst;
		cv::Scalar borderValue = cv::Scalar();
		cv::Size dsize;
		int flags = cv::INTER_LINEAR, borderMode = cv::BORDER_CONSTANT;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, dst))
			_o_return_result;
		if (ParamIndexToVal(2, M))
			_o_return_result;
		if (ParamIndexToVal(3, dsize))
			_o_return_result;
		if (aParamCount > 4)
			TokenToVal(*aParam[4], flags, true);
		if (aParamCount > 5)
			TokenToVal(*aParam[5], borderMode, true);
		if (aParamCount > 6)
			TokenToVal(*aParam[6], borderValue, true);
		cv::warpPerspective(src, dst, M, dsize, flags, borderMode, borderValue);
		return;
	}
	case FID_warpPolar: {
		cv::_InputArray src;
		cv::_OutputArray dst;
		cv::Point2f center;
		cv::Size dsize;
		double maxRadius;
		int flags;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, dst))
			_o_return_result;
		if (ParamIndexToVal(2, dsize))
			_o_return_result;
		if (ParamIndexToVal(3, center))
			_o_return_result;
		if (ParamIndexToVal(4, maxRadius))
			_o_return_result;
		if (ParamIndexToVal(5, flags))
			_o_return_result;
		cv::warpPolar(src, dst, dsize, center, maxRadius, flags);
		return;
	}
	case FID_watershed: {
		cv::_InputArray image;
		cv::_InputOutputArray markers;
		if (ParamIndexToVal(0, image))
			_o_return_result;
		if (ParamIndexToVal(1, markers))
			_o_return_result;
		cv::watershed(image, markers);
		return;
	}
	case FID_wrapperEMD: {
		cv::_InputArray signature1, signature2, cost = cv::noArray();
		cv::_OutputArray flow = cv::noArray();
		cv::Ptr<float> lowerBound = cv::Ptr<float>();
		int distType;
		if (ParamIndexToVal(0, signature1))
			_o_return_result;
		if (ParamIndexToVal(1, signature2))
			_o_return_result;
		if (ParamIndexToVal(2, distType))
			_o_return_result;
		if (aParamCount > 3)
			TokenToVal(*aParam[3], cost, true);
		VarRef* var_lowerBound = nullptr;
		if (aParamCount > 4) {
			TokenToVal(*aParam[4], var_lowerBound, true);
			if (var_lowerBound)
				TokenToVal(VarRefToToken(var_lowerBound), *lowerBound, true);
		}
		if (aParamCount > 5)
			TokenToVal(*aParam[5], flow, true);
		auto __retval = (double)cv::wrapperEMD(signature1, signature2, distType, cost, lowerBound, flow);
		if (var_lowerBound) {
			g_ahkapi->VarAssign(var_lowerBound, ExprTokenType((double)*lowerBound));
		}
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_writeOpticalFlow: {
		cv::_InputArray flow;
		cv::String path;
		if (ParamIndexToVal(0, path))
			_o_return_result;
		if (ParamIndexToVal(1, flow))
			_o_return_result;
		auto __retval = (__int64)cv::writeOpticalFlow(path, flow);
		return (void)(aResultToken.SetValue(__retval));
	}
	}
}


BIF_DECL(CV_CUDA_FUNC) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aResultToken.func->mFID) {
	case FID_createContinuous: {
		cv::_OutputArray arr;
		int rows, cols, type;
		if (ParamIndexToVal(0, rows))
			_o_return_result;
		if (ParamIndexToVal(1, cols))
			_o_return_result;
		if (ParamIndexToVal(2, type))
			_o_return_result;
		if (ParamIndexToVal(3, arr))
			_o_return_result;
		cv::cuda::createContinuous(rows, cols, type, arr);
		return;
	}
	case FID_ensureSizeIsEnough: {
		cv::_OutputArray arr;
		int rows, cols, type;
		if (ParamIndexToVal(0, rows))
			_o_return_result;
		if (ParamIndexToVal(1, cols))
			_o_return_result;
		if (ParamIndexToVal(2, type))
			_o_return_result;
		if (ParamIndexToVal(3, arr))
			_o_return_result;
		cv::cuda::ensureSizeIsEnough(rows, cols, type, arr);
		return;
	}
	case FID_getCudaEnabledDeviceCount: {
		auto __retval = (__int64)cv::cuda::getCudaEnabledDeviceCount();
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_getDevice: {
		auto __retval = (__int64)cv::cuda::getDevice();
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_printCudaDeviceInfo: {
		int device;
		if (ParamIndexToVal(0, device))
			_o_return_result;
		cv::cuda::printCudaDeviceInfo(device);
		return;
	}
	case FID_printShortCudaDeviceInfo: {
		int device;
		if (ParamIndexToVal(0, device))
			_o_return_result;
		cv::cuda::printShortCudaDeviceInfo(device);
		return;
	}
	case FID_registerPageLocked: {
		cv::Mat m;
		if (ParamIndexToVal(0, m))
			_o_return_result;
		cv::cuda::registerPageLocked(m);
		return;
	}
	case FID_resetDevice: {
		cv::cuda::resetDevice();
		return;
	}
	case FID_setBufferPoolConfig: {
		int deviceId, stackCount;
		size_t stackSize;
		if (ParamIndexToVal(0, deviceId))
			_o_return_result;
		if (ParamIndexToVal(1, (intptr_t&)stackSize))
			_o_return_result;
		if (ParamIndexToVal(2, stackCount))
			_o_return_result;
		cv::cuda::setBufferPoolConfig(deviceId, stackSize, stackCount);
		return;
	}
	case FID_setBufferPoolUsage: {
		bool on;
		if (ParamIndexToVal(0, (char&)on))
			_o_return_result;
		cv::cuda::setBufferPoolUsage(on);
		return;
	}
	case FID_setDevice: {
		int device;
		if (ParamIndexToVal(0, device))
			_o_return_result;
		cv::cuda::setDevice(device);
		return;
	}
	case FID_unregisterPageLocked: {
		cv::Mat m;
		if (ParamIndexToVal(0, m))
			_o_return_result;
		cv::cuda::unregisterPageLocked(m);
		return;
	}
	}
}


BIF_DECL(CV_DETAIL_FUNC) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aResultToken.func->mFID) {
	case FID_calibrateRotatingCamera: {
		cv::Mat K;
		std::vector<cv::Mat> Hs;
		if (ParamIndexToVal(0, Hs))
			_o_return_result;
		VarRef* var_K = nullptr;
		if (ParamIndexToVal(1, var_K))
			_o_return_result;
		auto __retval = (__int64)cv::detail::calibrateRotatingCamera(Hs, K);
		ValToResult(K, aResultToken);
		g_ahkapi->VarAssign(var_K, aResultToken);
		g_ahkapi->ResultTokenFree(aResultToken);
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_computeImageFeatures: {
		cv::_InputArray image, mask = cv::noArray();
		cv::Ptr<cv::Feature2D> featuresFinder;
		cv::detail::ImageFeatures features;
		if (ParamIndexToVal(0, featuresFinder))
			_o_return_result;
		if (ParamIndexToVal(1, image))
			_o_return_result;
		VarRef* var_features = nullptr;
		if (ParamIndexToVal(2, var_features))
			_o_return_result;
		if (aParamCount > 3)
			TokenToVal(*aParam[3], mask, true);
		cv::detail::computeImageFeatures(featuresFinder, image, features, mask);
		ValToResult(features, aResultToken);
		g_ahkapi->VarAssign(var_features, aResultToken);
		g_ahkapi->ResultTokenFree(aResultToken);
		return;
	}
	case FID_computeImageFeatures2: {
		cv::_InputArray images, masks = cv::noArray();
		cv::Ptr<cv::Feature2D> featuresFinder;
		std::vector<cv::detail::ImageFeatures> features;
		if (ParamIndexToVal(0, featuresFinder))
			_o_return_result;
		if (ParamIndexToVal(1, images))
			_o_return_result;
		VarRef* var_features = nullptr;
		if (ParamIndexToVal(2, var_features))
			_o_return_result;
		if (aParamCount > 3)
			TokenToVal(*aParam[3], masks, true);
		cv::detail::computeImageFeatures(featuresFinder, images, features, masks);
		ValToResult(features, aResultToken);
		g_ahkapi->VarAssign(var_features, aResultToken);
		g_ahkapi->ResultTokenFree(aResultToken);
		return;
	}
	case FID_createLaplacePyr: {
		cv::_InputArray img;
		int num_levels;
		std::vector<cv::UMat> pyr;
		if (ParamIndexToVal(0, img))
			_o_return_result;
		if (ParamIndexToVal(1, num_levels))
			_o_return_result;
		VarRef* var_pyr = nullptr;
		if (ParamIndexToVal(2, var_pyr))
			_o_return_result;
		if (TokenToVal(VarRefToToken(var_pyr), pyr) != CONDITION_TRUE)
			_o_return_result;
		cv::detail::createLaplacePyr(img, num_levels, pyr);
		ValToResult(pyr, aResultToken);
		g_ahkapi->VarAssign(var_pyr, aResultToken);
		g_ahkapi->ResultTokenFree(aResultToken);
		return;
	}
	case FID_createLaplacePyrGpu: {
		cv::_InputArray img;
		int num_levels;
		std::vector<cv::UMat> pyr;
		if (ParamIndexToVal(0, img))
			_o_return_result;
		if (ParamIndexToVal(1, num_levels))
			_o_return_result;
		VarRef* var_pyr = nullptr;
		if (ParamIndexToVal(2, var_pyr))
			_o_return_result;
		if (TokenToVal(VarRefToToken(var_pyr), pyr) != CONDITION_TRUE)
			_o_return_result;
		cv::detail::createLaplacePyrGpu(img, num_levels, pyr);
		ValToResult(pyr, aResultToken);
		g_ahkapi->VarAssign(var_pyr, aResultToken);
		g_ahkapi->ResultTokenFree(aResultToken);
		return;
	}
	case FID_createWeightMap: {
		cv::_InputArray mask;
		cv::_InputOutputArray weight;
		float sharpness;
		if (ParamIndexToVal(0, mask))
			_o_return_result;
		if (ParamIndexToVal(1, sharpness))
			_o_return_result;
		if (ParamIndexToVal(2, weight))
			_o_return_result;
		cv::detail::createWeightMap(mask, sharpness, weight);
		return;
	}
	case FID_focalsFromHomography: {
		bool f0_ok, f1_ok;
		cv::Mat H;
		double f0, f1;
		if (ParamIndexToVal(0, H))
			_o_return_result;
		if (ParamIndexToVal(1, f0))
			_o_return_result;
		if (ParamIndexToVal(2, f1))
			_o_return_result;
		if (ParamIndexToVal(3, (char&)f0_ok))
			_o_return_result;
		if (ParamIndexToVal(4, (char&)f1_ok))
			_o_return_result;
		cv::detail::focalsFromHomography(H, f0, f1, f0_ok, f1_ok);
		return;
	}
	case FID_leaveBiggestComponent: {
		float conf_threshold;
		std::vector<cv::detail::ImageFeatures> features;
		std::vector<cv::detail::MatchesInfo> pairwise_matches;
		if (ParamIndexToVal(0, features))
			_o_return_result;
		if (ParamIndexToVal(1, pairwise_matches))
			_o_return_result;
		if (ParamIndexToVal(2, conf_threshold))
			_o_return_result;
		auto __retval = cv::detail::leaveBiggestComponent(features, pairwise_matches, conf_threshold);
		return ValToResult(__retval, aResultToken);
	}
	case FID_matchesGraphAsString: {
		float conf_threshold;
		std::vector<cv::String> pathes;
		std::vector<cv::detail::MatchesInfo> pairwise_matches;
		if (ParamIndexToVal(0, pathes))
			_o_return_result;
		if (ParamIndexToVal(1, pairwise_matches))
			_o_return_result;
		if (ParamIndexToVal(2, conf_threshold))
			_o_return_result;
		auto __retval = cv::detail::matchesGraphAsString(pathes, pairwise_matches, conf_threshold);
		return ValToResult(__retval, aResultToken);
	}
	case FID_normalizeUsingWeightMap: {
		cv::_InputArray weight;
		cv::_InputOutputArray src;
		if (ParamIndexToVal(0, weight))
			_o_return_result;
		if (ParamIndexToVal(1, src))
			_o_return_result;
		cv::detail::normalizeUsingWeightMap(weight, src);
		return;
	}
	case FID_overlapRoi: {
		cv::Point tl1, tl2;
		cv::Rect roi;
		cv::Size sz1, sz2;
		if (ParamIndexToVal(0, tl1))
			_o_return_result;
		if (ParamIndexToVal(1, tl2))
			_o_return_result;
		if (ParamIndexToVal(2, sz1))
			_o_return_result;
		if (ParamIndexToVal(3, sz2))
			_o_return_result;
		if (ParamIndexToVal(4, roi))
			_o_return_result;
		auto __retval = (__int64)cv::detail::overlapRoi(tl1, tl2, sz1, sz2, roi);
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_restoreImageFromLaplacePyr: {
		std::vector<cv::UMat> pyr;
		VarRef* var_pyr = nullptr;
		if (ParamIndexToVal(0, var_pyr))
			_o_return_result;
		if (TokenToVal(VarRefToToken(var_pyr), pyr) != CONDITION_TRUE)
			_o_return_result;
		cv::detail::restoreImageFromLaplacePyr(pyr);
		ValToResult(pyr, aResultToken);
		g_ahkapi->VarAssign(var_pyr, aResultToken);
		g_ahkapi->ResultTokenFree(aResultToken);
		return;
	}
	case FID_restoreImageFromLaplacePyrGpu: {
		std::vector<cv::UMat> pyr;
		VarRef* var_pyr = nullptr;
		if (ParamIndexToVal(0, var_pyr))
			_o_return_result;
		if (TokenToVal(VarRefToToken(var_pyr), pyr) != CONDITION_TRUE)
			_o_return_result;
		cv::detail::restoreImageFromLaplacePyrGpu(pyr);
		ValToResult(pyr, aResultToken);
		g_ahkapi->VarAssign(var_pyr, aResultToken);
		g_ahkapi->ResultTokenFree(aResultToken);
		return;
	}
	case FID_resultRoi: {
		std::vector<cv::Point> corners;
		auto arr = dynamic_cast<Array*>(TokenToObject(*aParam[1]));
		if (arr && arr->mLength && arr->mItem[0].symbol == SYM_OBJECT && arr->mItem[0].object->IsOfType(UMat::sPrototype)) {
			std::vector<cv::UMat> images;
			if (ParamIndexToVal(0, corners))
				_o_return_result;
			if (ParamIndexToVal(1, images))
				_o_return_result;
			auto __retval = cv::detail::resultRoi(corners, images);
			return ValToResult(__retval, aResultToken);
		}
		else {
			std::vector<cv::Size> sizes;
			if (ParamIndexToVal(0, corners))
				_o_return_result;
			if (ParamIndexToVal(1, sizes))
				_o_return_result;
			auto __retval = cv::detail::resultRoi(corners, sizes);
			return ValToResult(__retval, aResultToken);
		}
	}
	case FID_resultRoiIntersection: {
		std::vector<cv::Point> corners;
		std::vector<cv::Size> sizes;
		if (ParamIndexToVal(0, corners))
			_o_return_result;
		if (ParamIndexToVal(1, sizes))
			_o_return_result;
		auto __retval = cv::detail::resultRoiIntersection(corners, sizes);
		return ValToResult(__retval, aResultToken);
	}
	case FID_resultTl: {
		std::vector<cv::Point> corners;
		if (ParamIndexToVal(0, corners))
			_o_return_result;
		auto __retval = cv::detail::resultTl(corners);
		return ValToResult(__retval, aResultToken);
	}
	case FID_selectRandomSubset: {
		int count, size;
		std::vector<int> subset;
		if (ParamIndexToVal(0, count))
			_o_return_result;
		if (ParamIndexToVal(1, size))
			_o_return_result;
		if (ParamIndexToVal(2, subset))
			_o_return_result;
		cv::detail::selectRandomSubset(count, size, subset);
		return;
	}
	case FID_stitchingLogLevel: {
		auto __retval = (__int64)cv::detail::stitchingLogLevel();
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_waveCorrect: {
		int kind;
		std::vector<cv::Mat> rmats;
		VarRef* var_rmats = nullptr;
		if (ParamIndexToVal(0, var_rmats))
			_o_return_result;
		if (TokenToVal(VarRefToToken(var_rmats), rmats) != CONDITION_TRUE)
			_o_return_result;
		if (ParamIndexToVal(1, kind))
			_o_return_result;
		cv::detail::waveCorrect(rmats, (cv::detail::WaveCorrectKind)kind);
		ValToResult(rmats, aResultToken);
		g_ahkapi->VarAssign(var_rmats, aResultToken);
		g_ahkapi->ResultTokenFree(aResultToken);
		return;
	}
	}
}


BIF_DECL(CV_DNN_FUNC) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aResultToken.func->mFID) {
	case FID_NMSBoxes: {
		float score_threshold, nms_threshold, eta = 1.f;
		int top_k = 0;
		std::vector<cv::Rect2d> bboxes;
		std::vector<float> scores;
		std::vector<int> indices;
		if (ParamIndexToVal(0, bboxes))
			_o_return_result;
		if (ParamIndexToVal(1, scores))
			_o_return_result;
		if (ParamIndexToVal(2, score_threshold))
			_o_return_result;
		if (ParamIndexToVal(3, nms_threshold))
			_o_return_result;
		VarRef* var_indices = nullptr;
		if (ParamIndexToVal(4, var_indices))
			_o_return_result;
		if (aParamCount > 5)
			TokenToVal(*aParam[5], eta, true);
		if (aParamCount > 6)
			TokenToVal(*aParam[6], top_k, true);
		cv::dnn::NMSBoxes(bboxes, scores, score_threshold, nms_threshold, indices, eta, top_k);
		ValToResult(indices, aResultToken);
		g_ahkapi->VarAssign(var_indices, aResultToken);
		g_ahkapi->ResultTokenFree(aResultToken);
		return;
	}
	case FID_NMSBoxesRotated: {
		float score_threshold, nms_threshold, eta = 1.f;
		int top_k = 0;
		std::vector<cv::RotatedRect> bboxes;
		std::vector<float> scores;
		std::vector<int> indices;
		if (ParamIndexToVal(0, bboxes))
			_o_return_result;
		if (ParamIndexToVal(1, scores))
			_o_return_result;
		if (ParamIndexToVal(2, score_threshold))
			_o_return_result;
		if (ParamIndexToVal(3, nms_threshold))
			_o_return_result;
		VarRef* var_indices = nullptr;
		if (ParamIndexToVal(4, var_indices))
			_o_return_result;
		if (aParamCount > 5)
			TokenToVal(*aParam[5], eta, true);
		if (aParamCount > 6)
			TokenToVal(*aParam[6], top_k, true);
		cv::dnn::NMSBoxes(bboxes, scores, score_threshold, nms_threshold, indices, eta, top_k);
		ValToResult(indices, aResultToken);
		g_ahkapi->VarAssign(var_indices, aResultToken);
		g_ahkapi->ResultTokenFree(aResultToken);
		return;
	}
	case FID_blobFromImage: {
		bool swapRB = false, crop = false;
		cv::_InputArray image;
		cv::Scalar mean = cv::Scalar();
		cv::Size size = cv::Size();
		double scalefactor = 1.0;
		int ddepth = CV_32F;
		if (ParamIndexToVal(0, image))
			_o_return_result;
		if (aParamCount > 1)
			TokenToVal(*aParam[1], scalefactor, true);
		if (aParamCount > 2)
			TokenToVal(*aParam[2], size, true);
		if (aParamCount > 3)
			TokenToVal(*aParam[3], mean, true);
		if (aParamCount > 4)
			TokenToVal(*aParam[4], (char&)swapRB, true);
		if (aParamCount > 5)
			TokenToVal(*aParam[5], (char&)crop, true);
		if (aParamCount > 6)
			TokenToVal(*aParam[6], ddepth, true);
		auto __retval = (Mat*)Mat::sPrototype->New(g_invalidparam, 1);
		__retval->mC = cv::dnn::blobFromImage(image, scalefactor, size, mean, swapRB, crop, ddepth);
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_blobFromImages: {
		bool swapRB = false, crop = false;
		cv::_InputArray images;
		cv::Scalar mean = cv::Scalar();
		cv::Size size = cv::Size();
		double scalefactor = 1.0;
		int ddepth = CV_32F;
		if (ParamIndexToVal(0, images))
			_o_return_result;
		if (aParamCount > 1)
			TokenToVal(*aParam[1], scalefactor, true);
		if (aParamCount > 2)
			TokenToVal(*aParam[2], size, true);
		if (aParamCount > 3)
			TokenToVal(*aParam[3], mean, true);
		if (aParamCount > 4)
			TokenToVal(*aParam[4], (char&)swapRB, true);
		if (aParamCount > 5)
			TokenToVal(*aParam[5], (char&)crop, true);
		if (aParamCount > 6)
			TokenToVal(*aParam[6], ddepth, true);
		auto __retval = (Mat*)Mat::sPrototype->New(g_invalidparam, 1);
		__retval->mC = cv::dnn::blobFromImages(images, scalefactor, size, mean, swapRB, crop, ddepth);
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_getAvailableTargets: {
		int be;
		if (ParamIndexToVal(0, be))
			_o_return_result;
		auto __retval = cv::dnn::getAvailableTargets((cv::dnn::Backend)be);
		return ValToResult((std::vector<int>&)__retval, aResultToken);
	}
	case FID_imagesFromBlob: {
		cv::Mat blob_;
		cv::_OutputArray images_;
		if (ParamIndexToVal(0, blob_))
			_o_return_result;
		if (ParamIndexToVal(1, images_))
			_o_return_result;
		cv::dnn::imagesFromBlob(blob_, images_);
		return;
	}
	case FID_readNet: {
		if (!MatchTypes("ss?s")) {
			cv::String model, config = "", framework = "";
			if (ParamIndexToVal(0, model))
				_o_return_result;
			if (aParamCount > 1)
				TokenToVal(*aParam[1], config, true);
			if (aParamCount > 2)
				TokenToVal(*aParam[2], framework, true);
			auto __retval = (dnn_Net*)dnn_Net::sPrototype->New(g_invalidparam, 1);
			__retval->mC = cv::makePtr<cv::dnn::Net>(cv::dnn::readNet(model, config, framework));
			return (void)(aResultToken.SetValue(__retval));
		}
		else if (!MatchTypes("soo?")) {
			cv::String framework;
			std::vector<uchar> bufferModel, bufferConfig = std::vector<uchar>();
			if (ParamIndexToVal(0, framework))
				_o_return_result;
			if (ParamIndexToVal(1, bufferModel))
				_o_return_result;
			if (aParamCount > 2)
				TokenToVal(*aParam[2], bufferConfig, true);
			auto __retval = (dnn_Net*)dnn_Net::sPrototype->New(g_invalidparam, 1);
			__retval->mC = cv::makePtr<cv::dnn::Net>(cv::dnn::readNet(framework, bufferModel, bufferConfig));
			return (void)(aResultToken.SetValue(__retval));
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case FID_readNetFromCaffe: {
		if (!MatchTypes("ss?")) {
			cv::String prototxt, caffeModel = cv::String();
			if (ParamIndexToVal(0, prototxt))
				_o_return_result;
			if (aParamCount > 1)
				TokenToVal(*aParam[1], caffeModel, true);
			auto __retval = (dnn_Net*)dnn_Net::sPrototype->New(g_invalidparam, 1);
			__retval->mC = cv::makePtr<cv::dnn::Net>(cv::dnn::readNetFromCaffe(prototxt, caffeModel));
			return (void)(aResultToken.SetValue(__retval));
		}
		else if (!MatchTypes("oo?")) {
			std::vector<uchar> bufferProto, bufferModel = std::vector<uchar>();
			if (ParamIndexToVal(0, bufferProto))
				_o_return_result;
			if (aParamCount > 1)
				TokenToVal(*aParam[1], bufferModel, true);
			auto __retval = (dnn_Net*)dnn_Net::sPrototype->New(g_invalidparam, 1);
			__retval->mC = cv::makePtr<cv::dnn::Net>(cv::dnn::readNetFromCaffe(bufferProto, bufferModel));
			return (void)(aResultToken.SetValue(__retval));
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case FID_readNetFromDarknet: {
		if (!MatchTypes("ss?")) {
			cv::String cfgFile, darknetModel = cv::String();
			if (ParamIndexToVal(0, cfgFile))
				_o_return_result;
			if (aParamCount > 1)
				TokenToVal(*aParam[1], darknetModel, true);
			auto __retval = (dnn_Net*)dnn_Net::sPrototype->New(g_invalidparam, 1);
			__retval->mC = cv::makePtr<cv::dnn::Net>(cv::dnn::readNetFromDarknet(cfgFile, darknetModel));
			return (void)(aResultToken.SetValue(__retval));
		}
		else if (!MatchTypes("oo?")) {
			std::vector<uchar> bufferCfg, bufferModel = std::vector<uchar>();
			if (ParamIndexToVal(0, bufferCfg))
				_o_return_result;
			if (aParamCount > 1)
				TokenToVal(*aParam[1], bufferModel, true);
			auto __retval = (dnn_Net*)dnn_Net::sPrototype->New(g_invalidparam, 1);
			__retval->mC = cv::makePtr<cv::dnn::Net>(cv::dnn::readNetFromDarknet(bufferCfg, bufferModel));
			return (void)(aResultToken.SetValue(__retval));
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case FID_readNetFromModelOptimizer: {
		if (!MatchTypes("ss")) {
			cv::String xml, bin;
			if (ParamIndexToVal(0, xml))
				_o_return_result;
			if (ParamIndexToVal(1, bin))
				_o_return_result;
			auto __retval = (dnn_Net*)dnn_Net::sPrototype->New(g_invalidparam, 1);
			__retval->mC = cv::makePtr<cv::dnn::Net>(cv::dnn::readNetFromModelOptimizer(xml, bin));
			return (void)(aResultToken.SetValue(__retval));
		}
		else if (!MatchTypes("oo")) {
			std::vector<uchar> bufferModelConfig, bufferWeights;
			if (ParamIndexToVal(0, bufferModelConfig))
				_o_return_result;
			if (ParamIndexToVal(1, bufferWeights))
				_o_return_result;
			auto __retval = (dnn_Net*)dnn_Net::sPrototype->New(g_invalidparam, 1);
			__retval->mC = cv::makePtr<cv::dnn::Net>(cv::dnn::readNetFromModelOptimizer(bufferModelConfig, bufferWeights));
			return (void)(aResultToken.SetValue(__retval));
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case FID_readNetFromONNX: {
		if (!MatchTypes("s")) {
			cv::String onnxFile;
			if (ParamIndexToVal(0, onnxFile))
				_o_return_result;
			auto __retval = (dnn_Net*)dnn_Net::sPrototype->New(g_invalidparam, 1);
			__retval->mC = cv::makePtr<cv::dnn::Net>(cv::dnn::readNetFromONNX(onnxFile));
			return (void)(aResultToken.SetValue(__retval));
		}
		else if (!MatchTypes("o")) {
			std::vector<uchar> buffer;
			if (ParamIndexToVal(0, buffer))
				_o_return_result;
			auto __retval = (dnn_Net*)dnn_Net::sPrototype->New(g_invalidparam, 1);
			__retval->mC = cv::makePtr<cv::dnn::Net>(cv::dnn::readNetFromONNX(buffer));
			return (void)(aResultToken.SetValue(__retval));
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case FID_readNetFromTensorflow: {
		if (!MatchTypes("ss?")) {
			cv::String model, config = cv::String();
			if (ParamIndexToVal(0, model))
				_o_return_result;
			if (aParamCount > 1)
				TokenToVal(*aParam[1], config, true);
			auto __retval = (dnn_Net*)dnn_Net::sPrototype->New(g_invalidparam, 1);
			__retval->mC = cv::makePtr<cv::dnn::Net>(cv::dnn::readNetFromTensorflow(model, config));
			return (void)(aResultToken.SetValue(__retval));
		}
		else if (!MatchTypes("oo?")) {
			std::vector<uchar> bufferModel, bufferConfig = std::vector<uchar>();
			if (ParamIndexToVal(0, bufferModel))
				_o_return_result;
			if (aParamCount > 1)
				TokenToVal(*aParam[1], bufferConfig, true);
			auto __retval = (dnn_Net*)dnn_Net::sPrototype->New(g_invalidparam, 1);
			__retval->mC = cv::makePtr<cv::dnn::Net>(cv::dnn::readNetFromTensorflow(bufferModel, bufferConfig));
			return (void)(aResultToken.SetValue(__retval));
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case FID_readNetFromTorch: {
		bool isBinary = true, evaluate = true;
		cv::String model;
		if (ParamIndexToVal(0, model))
			_o_return_result;
		if (aParamCount > 1)
			TokenToVal(*aParam[1], (char&)isBinary, true);
		if (aParamCount > 2)
			TokenToVal(*aParam[2], (char&)evaluate, true);
		auto __retval = (dnn_Net*)dnn_Net::sPrototype->New(g_invalidparam, 1);
		__retval->mC = cv::makePtr<cv::dnn::Net>(cv::dnn::readNetFromTorch(model, isBinary, evaluate));
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_readTensorFromONNX: {
		cv::String path;
		if (ParamIndexToVal(0, path))
			_o_return_result;
		auto __retval = (Mat*)Mat::sPrototype->New(g_invalidparam, 1);
		__retval->mC = cv::dnn::readTensorFromONNX(path);
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_readTorchBlob: {
		bool isBinary = true;
		cv::String filename;
		if (ParamIndexToVal(0, filename))
			_o_return_result;
		if (aParamCount > 1)
			TokenToVal(*aParam[1], (char&)isBinary, true);
		auto __retval = (Mat*)Mat::sPrototype->New(g_invalidparam, 1);
		__retval->mC = cv::dnn::readTorchBlob(filename, isBinary);
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_shrinkCaffeModel: {
		cv::String src, dst;
		std::vector<cv::String> layersTypes = std::vector<cv::String>();
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, dst))
			_o_return_result;
		if (aParamCount > 2)
			TokenToVal(*aParam[2], layersTypes, true);
		cv::dnn::shrinkCaffeModel(src, dst, layersTypes);
		return;
	}
	case FID_softNMSBoxes: {
		float score_threshold, nms_threshold, sigma = 0.5;
		int method = (int)cv::dnn::SoftNMSMethod::SOFTNMS_GAUSSIAN;
		size_t top_k = 0;
		std::vector<cv::Rect> bboxes;
		std::vector<float> scores, updated_scores;
		std::vector<int> indices;
		if (ParamIndexToVal(0, bboxes))
			_o_return_result;
		if (ParamIndexToVal(1, scores))
			_o_return_result;
		VarRef* var_updated_scores = nullptr;
		if (ParamIndexToVal(2, var_updated_scores))
			_o_return_result;
		if (ParamIndexToVal(3, score_threshold))
			_o_return_result;
		if (ParamIndexToVal(4, nms_threshold))
			_o_return_result;
		VarRef* var_indices = nullptr;
		if (ParamIndexToVal(5, var_indices))
			_o_return_result;
		if (aParamCount > 6)
			TokenToVal(*aParam[6], (intptr_t&)top_k, true);
		if (aParamCount > 7)
			TokenToVal(*aParam[7], sigma, true);
		if (aParamCount > 8)
			TokenToVal(*aParam[8], method, true);
		cv::dnn::softNMSBoxes(bboxes, scores, updated_scores, score_threshold, nms_threshold, indices, top_k, sigma, (cv::dnn::SoftNMSMethod)method);
		ValToResult(updated_scores, aResultToken);
		g_ahkapi->VarAssign(var_updated_scores, aResultToken);
		g_ahkapi->ResultTokenFree(aResultToken);
		ValToResult(indices, aResultToken);
		g_ahkapi->VarAssign(var_indices, aResultToken);
		g_ahkapi->ResultTokenFree(aResultToken);
		return;
	}
	case FID_writeTextGraph: {
		cv::String model, output;
		if (ParamIndexToVal(0, model))
			_o_return_result;
		if (ParamIndexToVal(1, output))
			_o_return_result;
		cv::dnn::writeTextGraph(model, output);
		return;
	}
	}
}


BIF_DECL(CV_FISHEYE_FUNC) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aResultToken.func->mFID) {
	case FID_calibrate: {
		cv::_InputArray objectPoints, imagePoints;
		cv::_InputOutputArray K, D;
		cv::_OutputArray rvecs, tvecs;
		cv::Size image_size;
		cv::TermCriteria criteria = cv::TermCriteria(cv::TermCriteria::COUNT + cv::TermCriteria::EPS, 100, DBL_EPSILON);
		;
		int flags = 0;
		if (ParamIndexToVal(0, objectPoints))
			_o_return_result;
		if (ParamIndexToVal(1, imagePoints))
			_o_return_result;
		if (ParamIndexToVal(2, image_size))
			_o_return_result;
		if (ParamIndexToVal(3, K))
			_o_return_result;
		if (ParamIndexToVal(4, D))
			_o_return_result;
		if (ParamIndexToVal(5, rvecs))
			_o_return_result;
		if (ParamIndexToVal(6, tvecs))
			_o_return_result;
		if (aParamCount > 7)
			TokenToVal(*aParam[7], flags, true);
		if (aParamCount > 8)
			TokenToVal(*aParam[8], criteria, true);
		auto __retval = cv::fisheye::calibrate(objectPoints, imagePoints, image_size, K, D, rvecs, tvecs, flags, criteria);
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_distortPoints: {
		cv::_InputArray undistorted, K, D;
		cv::_OutputArray distorted;
		double alpha = 0;
		if (ParamIndexToVal(0, undistorted))
			_o_return_result;
		if (ParamIndexToVal(1, distorted))
			_o_return_result;
		if (ParamIndexToVal(2, K))
			_o_return_result;
		if (ParamIndexToVal(3, D))
			_o_return_result;
		if (aParamCount > 4)
			TokenToVal(*aParam[4], alpha, true);
		cv::fisheye::distortPoints(undistorted, distorted, K, D, alpha);
		return;
	}
	case FID_estimateNewCameraMatrixForUndistortRectify: {
		cv::_InputArray K, D, R;
		cv::_OutputArray P;
		cv::Size image_size, new_size = cv::Size();
		double balance = 0.0, fov_scale = 1.0;
		if (ParamIndexToVal(0, K))
			_o_return_result;
		if (ParamIndexToVal(1, D))
			_o_return_result;
		if (ParamIndexToVal(2, image_size))
			_o_return_result;
		if (ParamIndexToVal(3, R))
			_o_return_result;
		if (ParamIndexToVal(4, P))
			_o_return_result;
		if (aParamCount > 5)
			TokenToVal(*aParam[5], balance, true);
		if (aParamCount > 6)
			TokenToVal(*aParam[6], new_size, true);
		if (aParamCount > 7)
			TokenToVal(*aParam[7], fov_scale, true);
		cv::fisheye::estimateNewCameraMatrixForUndistortRectify(K, D, image_size, R, P, balance, new_size, fov_scale);
		return;
	}
	case FID_fisheye_initUndistortRectifyMap: {
		cv::_InputArray K, D, R, P;
		cv::_OutputArray map1, map2;
		cv::Size size;
		int m1type;
		if (ParamIndexToVal(0, K))
			_o_return_result;
		if (ParamIndexToVal(1, D))
			_o_return_result;
		if (ParamIndexToVal(2, R))
			_o_return_result;
		if (ParamIndexToVal(3, P))
			_o_return_result;
		if (ParamIndexToVal(4, size))
			_o_return_result;
		if (ParamIndexToVal(5, m1type))
			_o_return_result;
		if (ParamIndexToVal(6, map1))
			_o_return_result;
		if (ParamIndexToVal(7, map2))
			_o_return_result;
		cv::fisheye::initUndistortRectifyMap(K, D, R, P, size, m1type, map1, map2);
		return;
	}
	case FID_fisheye_projectPoints: {
		cv::_InputArray objectPoints, rvec, tvec, K, D;
		cv::_OutputArray imagePoints, jacobian = cv::noArray();
		double alpha = 0;
		if (ParamIndexToVal(0, objectPoints))
			_o_return_result;
		if (ParamIndexToVal(1, imagePoints))
			_o_return_result;
		if (ParamIndexToVal(2, rvec))
			_o_return_result;
		if (ParamIndexToVal(3, tvec))
			_o_return_result;
		if (ParamIndexToVal(4, K))
			_o_return_result;
		if (ParamIndexToVal(5, D))
			_o_return_result;
		if (aParamCount > 6)
			TokenToVal(*aParam[6], alpha, true);
		if (aParamCount > 7)
			TokenToVal(*aParam[7], jacobian, true);
		cv::fisheye::projectPoints(objectPoints, imagePoints, rvec, tvec, K, D, alpha, jacobian);
		return;
	}
	case FID_fisheye_stereoCalibrate: {
		cv::_InputArray objectPoints, imagePoints1, imagePoints2;
		cv::_InputOutputArray K1, D1, K2, D2;
		cv::_OutputArray R, T;
		cv::Size imageSize;
		cv::TermCriteria criteria = cv::TermCriteria(cv::TermCriteria::COUNT + cv::TermCriteria::EPS, 100, DBL_EPSILON);
		;
		int flags = cv::fisheye::CALIB_FIX_INTRINSIC;
		if (ParamIndexToVal(0, objectPoints))
			_o_return_result;
		if (ParamIndexToVal(1, imagePoints1))
			_o_return_result;
		if (ParamIndexToVal(2, imagePoints2))
			_o_return_result;
		if (ParamIndexToVal(3, K1))
			_o_return_result;
		if (ParamIndexToVal(4, D1))
			_o_return_result;
		if (ParamIndexToVal(5, K2))
			_o_return_result;
		if (ParamIndexToVal(6, D2))
			_o_return_result;
		if (ParamIndexToVal(7, imageSize))
			_o_return_result;
		if (ParamIndexToVal(8, R))
			_o_return_result;
		if (ParamIndexToVal(9, T))
			_o_return_result;
		if (aParamCount > 10)
			TokenToVal(*aParam[10], flags, true);
		if (aParamCount > 11)
			TokenToVal(*aParam[11], criteria, true);
		auto __retval = cv::fisheye::stereoCalibrate(objectPoints, imagePoints1, imagePoints2, K1, D1, K2, D2, imageSize, R, T, flags, criteria);
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_fisheye_stereoRectify: {
		cv::_InputArray K1, D1, K2, D2, R, tvec;
		cv::_OutputArray R1, R2, P1, P2, Q;
		cv::Size imageSize, newImageSize = cv::Size();
		double balance = 0.0, fov_scale = 1.0;
		int flags;
		if (ParamIndexToVal(0, K1))
			_o_return_result;
		if (ParamIndexToVal(1, D1))
			_o_return_result;
		if (ParamIndexToVal(2, K2))
			_o_return_result;
		if (ParamIndexToVal(3, D2))
			_o_return_result;
		if (ParamIndexToVal(4, imageSize))
			_o_return_result;
		if (ParamIndexToVal(5, R))
			_o_return_result;
		if (ParamIndexToVal(6, tvec))
			_o_return_result;
		if (ParamIndexToVal(7, R1))
			_o_return_result;
		if (ParamIndexToVal(8, R2))
			_o_return_result;
		if (ParamIndexToVal(9, P1))
			_o_return_result;
		if (ParamIndexToVal(10, P2))
			_o_return_result;
		if (ParamIndexToVal(11, Q))
			_o_return_result;
		if (ParamIndexToVal(12, flags))
			_o_return_result;
		if (aParamCount > 13)
			TokenToVal(*aParam[13], newImageSize, true);
		if (aParamCount > 14)
			TokenToVal(*aParam[14], balance, true);
		if (aParamCount > 15)
			TokenToVal(*aParam[15], fov_scale, true);
		cv::fisheye::stereoRectify(K1, D1, K2, D2, imageSize, R, tvec, R1, R2, P1, P2, Q, flags, newImageSize, balance, fov_scale);
		return;
	}
	case FID_undistortImage: {
		cv::_InputArray distorted, K, D, Knew = cv::noArray();
		cv::_OutputArray undistorted;
		cv::Size new_size = cv::Size();
		if (ParamIndexToVal(0, distorted))
			_o_return_result;
		if (ParamIndexToVal(1, undistorted))
			_o_return_result;
		if (ParamIndexToVal(2, K))
			_o_return_result;
		if (ParamIndexToVal(3, D))
			_o_return_result;
		if (aParamCount > 4)
			TokenToVal(*aParam[4], Knew, true);
		if (aParamCount > 5)
			TokenToVal(*aParam[5], new_size, true);
		cv::fisheye::undistortImage(distorted, undistorted, K, D, Knew, new_size);
		return;
	}
	case FID_fisheye_undistortPoints: {
		cv::_InputArray distorted, K, D, R = cv::noArray(), P = cv::noArray();
		cv::_OutputArray undistorted;
		if (ParamIndexToVal(0, distorted))
			_o_return_result;
		if (ParamIndexToVal(1, undistorted))
			_o_return_result;
		if (ParamIndexToVal(2, K))
			_o_return_result;
		if (ParamIndexToVal(3, D))
			_o_return_result;
		if (aParamCount > 4)
			TokenToVal(*aParam[4], R, true);
		if (aParamCount > 5)
			TokenToVal(*aParam[5], P, true);
		cv::fisheye::undistortPoints(distorted, undistorted, K, D, R, P);
		return;
	}
	}
}


BIF_DECL(CV_GAPI_FUNC) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aResultToken.func->mFID) {
	case FID_BGR2RGB: {
		cv::GMat* src;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		auto __retval = (GMat*)GMat::sPrototype->New(g_invalidparam, 1);
		__retval->mC = cv::makePtr<cv::GMat>(cv::gapi::BGR2RGB(*src));
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_RGB2Gray: {
		cv::GMat* src;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		auto __retval = (GMat*)GMat::sPrototype->New(g_invalidparam, 1);
		__retval->mC = cv::makePtr<cv::GMat>(cv::gapi::RGB2Gray(*src));
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_gapi_add: {
		cv::GMat* src1, * src2;
		int ddepth = -1;
		if (ParamIndexToVal(0, src1))
			_o_return_result;
		if (ParamIndexToVal(1, src2))
			_o_return_result;
		if (aParamCount > 2)
			TokenToVal(*aParam[2], ddepth, true);
		auto __retval = (GMat*)GMat::sPrototype->New(g_invalidparam, 1);
		__retval->mC = cv::makePtr<cv::GMat>(cv::gapi::add(*src1, *src2, ddepth));
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_addC: {
		cv::GMat* src1;
		cv::GScalar* c;
		int ddepth = -1;
		if (ParamIndexToVal(0, src1))
			_o_return_result;
		if (ParamIndexToVal(1, c))
			_o_return_result;
		if (aParamCount > 2)
			TokenToVal(*aParam[2], ddepth, true);
		auto __retval = (GMat*)GMat::sPrototype->New(g_invalidparam, 1);
		__retval->mC = cv::makePtr<cv::GMat>(cv::gapi::addC(*src1, *c, ddepth));
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_gapi_boundingRect: {
		if (dynamic_cast<Array*>(TokenToObject(*aParam[0]))) {
			std::vector<cv::Point2i> src;
			//cv::GArray<cv::Point2i> src;
			if (ParamIndexToVal(0, src))
				_o_return_result;
			auto __retval = (GOpaque_Rect*)GOpaque_Size::sPrototype->New(g_invalidparam, 1);
			__retval->mC = cv::gapi::boundingRect(cv::GArray<cv::Point2i>(src));
			return (void)aResultToken.SetValue(__retval);
		}
		else {
			cv::GMat* src;
			if (ParamIndexToVal(0, src))
				_o_return_result;
			auto __retval = (GOpaque_Rect*)GOpaque_Size::sPrototype->New(g_invalidparam, 1);
			__retval->mC = cv::gapi::boundingRect(*src);
			return (void)aResultToken.SetValue(__retval);
		}
	}
	case FID_copy: {
		cv::GMat* in;
		if (ParamIndexToVal(0, in))
			_o_return_result;
		auto __retval = (GMat*)GMat::sPrototype->New(g_invalidparam, 1);
		__retval->mC = cv::makePtr<cv::GMat>(cv::gapi::copy(*in));
		return (void)(aResultToken.SetValue(__retval));
	}
/*
	case FID_goodFeaturesToTrack: {
		bool useHarrisDetector = false;
		cv::GMat* image;
		cv::Mat mask = cv::Mat();
		double qualityLevel, minDistance, k = 0.04;
		int maxCorners, blockSize = 3;
		if (ParamIndexToVal(0, image))
			_o_return_result;
		if (ParamIndexToVal(1, maxCorners))
			_o_return_result;
		if (ParamIndexToVal(2, qualityLevel))
			_o_return_result;
		if (ParamIndexToVal(3, minDistance))
			_o_return_result;
		if (aParamCount > 4)
			TokenToVal(*aParam[4], mask, true);
		if (aParamCount > 5)
			TokenToVal(*aParam[5], blockSize, true);
		if (aParamCount > 6)
			TokenToVal(*aParam[6], (char&)useHarrisDetector, true);
		if (aParamCount > 7)
			TokenToVal(*aParam[7], k, true);
		auto __retval = cv::gapi::goodFeaturesToTrack(*image, maxCorners, qualityLevel, minDistance, mask, blockSize, useHarrisDetector, k);
		return ValToResult(__retval, aResultToken);
	}

	case FID_kmeans: {
		if (aParamCount == 5) {
			cv::GMat* data;
			cv::TermCriteria criteria;
			int K, attempts, flags;
			if (ParamIndexToVal(0, data))
				_o_return_result;
			if (ParamIndexToVal(1, K))
				_o_return_result;
			if (ParamIndexToVal(2, criteria))
				_o_return_result;
			if (ParamIndexToVal(3, attempts))
				_o_return_result;
			if (ParamIndexToVal(4, flags))
				_o_return_result;
			auto __retval = cv::gapi::kmeans(*data, K, criteria, attempts, (cv::KmeansFlags)flags);
			return ValToResult(__retval, aResultToken);
		}
		else if (aParamCount == 6) {
			std::vector<cv::Point2f> data;
			std::vector<int> bestLabels;
			cv::TermCriteria criteria;
			int K, attempts, flags;
			if (ParamIndexToVal(0, data))
				_o_return_result;
			if (ParamIndexToVal(1, K))
				_o_return_result;
			if (ParamIndexToVal(2, bestLabels))
				_o_return_result;
			if (ParamIndexToVal(3, criteria))
				_o_return_result;
			if (ParamIndexToVal(4, attempts))
				_o_return_result;
			if (ParamIndexToVal(5, flags))
				_o_return_result;
			auto __retval = cv::gapi::kmeans(cv::GArray<cv::Point2f>(data), K, cv::GArray<int>(bestLabels), criteria, attempts, (cv::KmeansFlags)flags);
			return ValToResult(__retval, aResultToken);
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
*/
	case FID_gapi_mean: {
		cv::GMat* src;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		auto __retval = (GScalar*)GScalar::sPrototype->New(g_invalidparam, 1);
		__retval->mC = cv::makePtr<cv::GScalar>(cv::gapi::mean(*src));
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_gapi_medianBlur: {
		cv::GMat* src;
		int ksize;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, ksize))
			_o_return_result;
		auto __retval = (GMat*)GMat::sPrototype->New(g_invalidparam, 1);
		__retval->mC = cv::makePtr<cv::GMat>(cv::gapi::medianBlur(*src, ksize));
		return (void)(aResultToken.SetValue(__retval));
	}
/*
	case FID_parseSSD: {
		if (2 <= aParamCount && aParamCount <= 4) {
			cv::GMat* in;
			cv::GOpaque<cv::Size>* inSz;
			float confidenceThreshold = 0.5f;
			int filterLabel = -1;
			if (ParamIndexToVal(0, in))
				_o_return_result;
			if (ParamIndexToVal(1, inSz))
				_o_return_result;
			if (aParamCount > 2)
				TokenToVal(*aParam[2], confidenceThreshold, true);
			if (aParamCount > 3)
				TokenToVal(*aParam[3], filterLabel, true);
			auto __retval = cv::gapi::parseSSD(*in, *inSz, confidenceThreshold, filterLabel);
			return ValToResult(__retval, aResultToken);
		}
		else if (aParamCount == 5) {
			bool alignmentToSquare, filterOutOfBounds;
			cv::GMat* in;
			cv::GOpaque<cv::Size>* inSz;
			float confidenceThreshold;
			if (ParamIndexToVal(0, in))
				_o_return_result;
			if (ParamIndexToVal(1, inSz))
				_o_return_result;
			if (ParamIndexToVal(2, confidenceThreshold))
				_o_return_result;
			if (ParamIndexToVal(3, (char&)alignmentToSquare))
				_o_return_result;
			if (ParamIndexToVal(4, (char&)filterOutOfBounds))
				_o_return_result;
			auto __retval = cv::gapi::parseSSD(*in, *inSz, confidenceThreshold, alignmentToSquare, filterOutOfBounds);
			return ValToResult(__retval, aResultToken);
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}

	case FID_parseYolo: {
		cv::GMat* in;
		cv::GOpaque<cv::Size>* inSz;
		float confidenceThreshold = 0.5f, nmsThreshold = 0.5f;
		std::vector<float> anchors = cv::gapi::nn::parsers::GParseYolo::defaultAnchors();
		if (ParamIndexToVal(0, in))
			_o_return_result;
		if (ParamIndexToVal(1, inSz))
			_o_return_result;
		if (aParamCount > 2)
			TokenToVal(*aParam[2], confidenceThreshold, true);
		if (aParamCount > 3)
			TokenToVal(*aParam[3], nmsThreshold, true);
		if (aParamCount > 4)
			TokenToVal(*aParam[4], anchors, true);
		auto __retval = cv::gapi::parseYolo(*in, *inSz, confidenceThreshold, nmsThreshold, anchors);
		return ValToResult(__retval, aResultToken);
	}
*/
	case FID_gapi_resize: {
		cv::GMat* src;
		cv::Size dsize;
		double fx = 0, fy = 0;
		int interpolation = cv::INTER_LINEAR;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, dsize))
			_o_return_result;
		if (aParamCount > 2)
			TokenToVal(*aParam[2], fx, true);
		if (aParamCount > 3)
			TokenToVal(*aParam[3], fy, true);
		if (aParamCount > 4)
			TokenToVal(*aParam[4], interpolation, true);
		auto __retval = (GMat*)GMat::sPrototype->New(g_invalidparam, 1);
		__retval->mC = cv::makePtr<cv::GMat>(cv::gapi::resize(*src, dsize, fx, fy, interpolation));
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_split3: {
		cv::GMat* src;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		auto __retval = cv::gapi::split3(*src);
		return ValToResult(__retval, aResultToken);
	}
	case FID_gapi_threshold: {
		cv::GMat* src;
		cv::GScalar* maxval;
		int type;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, maxval))
			_o_return_result;
		if (ParamIndexToVal(2, type))
			_o_return_result;
		auto __retval = cv::gapi::threshold(*src, *maxval, type);
		return ValToResult(__retval, aResultToken);
	}
	}
}


BIF_DECL(CV_GAPI_CORE_CPU_FUNC) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aResultToken.func->mFID) {
	case FID_kernels: {
		auto __retval = (gapi_GKernelPackage*)gapi_GKernelPackage::sPrototype->New(g_invalidparam, 1);
		__retval->mC = cv::makePtr<cv::gapi::GKernelPackage>(cv::gapi::core::cpu::kernels());
		return (void)(aResultToken.SetValue(__retval));
	}
	}
}


BIF_DECL(CV_GAPI_CORE_FLUID_FUNC) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aResultToken.func->mFID) {
	case FID_fluid_kernels: {
		auto __retval = (gapi_GKernelPackage*)gapi_GKernelPackage::sPrototype->New(g_invalidparam, 1);
		__retval->mC = cv::makePtr<cv::gapi::GKernelPackage>(cv::gapi::core::fluid::kernels());
		return (void)(aResultToken.SetValue(__retval));
	}
	}
}


BIF_DECL(CV_GAPI_CORE_OCL_FUNC) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aResultToken.func->mFID) {
	case FID_ocl_kernels: {
		auto __retval = (gapi_GKernelPackage*)gapi_GKernelPackage::sPrototype->New(g_invalidparam, 1);
		__retval->mC = cv::makePtr<cv::gapi::GKernelPackage>(cv::gapi::core::ocl::kernels());
		return (void)(aResultToken.SetValue(__retval));
	}
	}
}


BIF_DECL(CV_GAPI_IE_FUNC) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aResultToken.func->mFID) {
	case FID_params: {
		if (aParamCount == 4) {
			cv::String tag, model, weights, device;
			if (ParamIndexToVal(0, tag))
				_o_return_result;
			if (ParamIndexToVal(1, model))
				_o_return_result;
			if (ParamIndexToVal(2, weights))
				_o_return_result;
			if (ParamIndexToVal(3, device))
				_o_return_result;
			auto __retval = (gapi_ie_PyParams*)gapi_ie_PyParams::sPrototype->New(g_invalidparam, 1);
			__retval->mC = cv::makePtr<cv::gapi::ie::PyParams>(cv::gapi::ie::params(tag, model, weights, device));
			return (void)(aResultToken.SetValue(__retval));
		}
		else if (aParamCount == 3) {
			cv::String tag, model, device;
			if (ParamIndexToVal(0, tag))
				_o_return_result;
			if (ParamIndexToVal(1, model))
				_o_return_result;
			if (ParamIndexToVal(2, device))
				_o_return_result;
			auto __retval = (gapi_ie_PyParams*)gapi_ie_PyParams::sPrototype->New(g_invalidparam, 1);
			__retval->mC = cv::makePtr<cv::gapi::ie::PyParams>(cv::gapi::ie::params(tag, model, device));
			return (void)(aResultToken.SetValue(__retval));
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	}
}


BIF_DECL(CV_GAPI_RENDER_OCV_FUNC) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aResultToken.func->mFID) {
	case FID_ocv_kernels: {
		auto __retval = (gapi_GKernelPackage*)gapi_GKernelPackage::sPrototype->New(g_invalidparam, 1);
		__retval->mC = cv::makePtr<cv::gapi::GKernelPackage>(cv::gapi::render::ocv::kernels());
		return (void)(aResultToken.SetValue(__retval));
	}
	}
}


BIF_DECL(CV_GAPI_STREAMING_FUNC) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aResultToken.func->mFID) {
	case FID_size: {
		auto obj = TokenToObject(*aParam[0]);
		if (obj && obj->IsOfType(GOpaque_Size::sPrototype)) {
			cv::GOpaque<cv::Rect>* r;
			if (ParamIndexToVal(0, r))
				_o_return_result;
			auto __retval = (GOpaque_Size*)GOpaque_Size::sPrototype->New(g_invalidparam, 1);
			__retval->mC = cv::gapi::streaming::size(*r);
			return (void)aResultToken.SetValue(__retval);
		}
		else {
			cv::GMat* src;
			if (ParamIndexToVal(0, src))
				_o_return_result;
			auto __retval = (GOpaque_Size*)GOpaque_Size::sPrototype->New(g_invalidparam, 1);
			__retval->mC = cv::gapi::streaming::size(*src);
			return (void)aResultToken.SetValue(__retval);
		}
	}
	}
}

/*
BIF_DECL(CV_GAPI_WIP_FUNC) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aResultToken.func->mFID) {
	case FID_make_capture_src: {
		cv::String path;
		if (ParamIndexToVal(0, path))
			_o_return_result;
		auto __retval = (IStreamSource*)IStreamSource::sPrototype->New(g_invalidparam, 1);
		__retval->mC = cv::gapi::wip::make_capture_src(path);
		return (void)(aResultToken.SetValue(__retval));
	}
	}
}

BIF_DECL(CV_GAPI_WIP_DRAW_FUNC) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aResultToken.func->mFID) {
	case FID_render: {
		if (!MatchTypes("ooo?")) {
			cv::Mat bgr;
			cv::gapi::wip::draw::Prims prims;
			//std::vector<cv::GCompileArg> args = {};
			if (ParamIndexToVal(0, bgr))
				_o_return_result;
			if (ParamIndexToVal(1, prims))
				_o_return_result;
			//if (aParamCount > 2)
				//TokenToVal(*aParam[2], args, true);
			cv::gapi::wip::draw::render(bgr, prims, {});
			return;
		}
		else if (!MatchTypes("oooo?")) {
			cv::Mat y_plane, uv_plane;
			cv::gapi::wip::draw::Prims prims;
			//std::vector<cv::GCompileArg> args = {};
			if (ParamIndexToVal(0, y_plane))
				_o_return_result;
			if (ParamIndexToVal(1, uv_plane))
				_o_return_result;
			if (ParamIndexToVal(2, prims))
				_o_return_result;
			//if (aParamCount > 3)
				//TokenToVal(*aParam[3], args, true);
			cv::gapi::wip::draw::render(y_plane, uv_plane, prims, {});
			return;
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case FID_render3ch: {
		cv::GArray<cv::gapi::wip::draw::Prim> prims;
		cv::GMat* src;
		if (ParamIndexToVal(0, src))
			_o_return_result;
		if (ParamIndexToVal(1, prims))
			_o_return_result;
		auto __retval = (GMat*)GMat::sPrototype->New(g_invalidparam, 1);
		__retval->mC = cv::makePtr<cv::GMat>(cv::gapi::wip::draw::render3ch(*src, prims));
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_renderNV12: {
		cv::GArray<cv::gapi::wip::draw::Prim> prims;
		cv::GMat* y, * uv;
		if (ParamIndexToVal(0, y))
			_o_return_result;
		if (ParamIndexToVal(1, uv))
			_o_return_result;
		if (ParamIndexToVal(2, prims))
			_o_return_result;
		auto __retval = cv::gapi::wip::draw::renderNV12(*y, *uv, prims);
		return ValToResult(__retval, aResultToken);
	}
	}
}
*/


BIF_DECL(CV_IPP_FUNC) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aResultToken.func->mFID) {
	case FID_getIppVersion: {
		auto __retval = cv::ipp::getIppVersion();
		return ValToResult(__retval, aResultToken);
	}
	case FID_setUseIPP: {
		bool flag;
		if (ParamIndexToVal(0, (char&)flag))
			_o_return_result;
		cv::ipp::setUseIPP(flag);
		return;
	}
	case FID_setUseIPP_NotExact: {
		bool flag;
		if (ParamIndexToVal(0, (char&)flag))
			_o_return_result;
		cv::ipp::setUseIPP_NotExact(flag);
		return;
	}
	case FID_useIPP: {
		auto __retval = (__int64)cv::ipp::useIPP();
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_useIPP_NotExact: {
		auto __retval = (__int64)cv::ipp::useIPP_NotExact();
		return (void)(aResultToken.SetValue(__retval));
	}
	}
}


BIF_DECL(CV_OCL_FUNC) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aResultToken.func->mFID) {
	case FID_finish: {
		cv::ocl::finish();
		return;
	}
	case FID_haveAmdBlas: {
		auto __retval = (__int64)cv::ocl::haveAmdBlas();
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_haveAmdFft: {
		auto __retval = (__int64)cv::ocl::haveAmdFft();
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_haveOpenCL: {
		auto __retval = (__int64)cv::ocl::haveOpenCL();
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_setUseOpenCL: {
		bool flag;
		if (ParamIndexToVal(0, (char&)flag))
			_o_return_result;
		cv::ocl::setUseOpenCL(flag);
		return;
	}
	case FID_useOpenCL: {
		auto __retval = (__int64)cv::ocl::useOpenCL();
		return (void)(aResultToken.SetValue(__retval));
	}
	}
}


BIF_DECL(CV_PARALLEL_FUNC) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aResultToken.func->mFID) {
	case FID_setParallelForBackend: {
		bool propagateNumThreads = true;
		cv::String backendName;
		if (ParamIndexToVal(0, backendName))
			_o_return_result;
		if (aParamCount > 1)
			TokenToVal(*aParam[1], (char&)propagateNumThreads, true);
		auto __retval = (__int64)cv::parallel::setParallelForBackend(backendName, propagateNumThreads);
		return (void)(aResultToken.SetValue(__retval));
	}
	}
}


BIF_DECL(CV_SAMPLES_FUNC) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aResultToken.func->mFID) {
	case FID_addSamplesDataSearchPath: {
		cv::String path;
		if (ParamIndexToVal(0, path))
			_o_return_result;
		cv::samples::addSamplesDataSearchPath(path);
		return;
	}
	case FID_addSamplesDataSearchSubDirectory: {
		cv::String subdir;
		if (ParamIndexToVal(0, subdir))
			_o_return_result;
		cv::samples::addSamplesDataSearchSubDirectory(subdir);
		return;
	}
	case FID_findFile: {
		bool required = true, silentMode = false;
		cv::String relative_path;
		if (ParamIndexToVal(0, relative_path))
			_o_return_result;
		if (aParamCount > 1)
			TokenToVal(*aParam[1], (char&)required, true);
		if (aParamCount > 2)
			TokenToVal(*aParam[2], (char&)silentMode, true);
		auto __retval = cv::samples::findFile(relative_path, required, silentMode);
		return ValToResult(__retval, aResultToken);
	}
	case FID_findFileOrKeep: {
		bool silentMode = false;
		cv::String relative_path;
		if (ParamIndexToVal(0, relative_path))
			_o_return_result;
		if (aParamCount > 1)
			TokenToVal(*aParam[1], (char&)silentMode, true);
		auto __retval = cv::samples::findFileOrKeep(relative_path, silentMode);
		return ValToResult(__retval, aResultToken);
	}
	}
}


BIF_DECL(CV_UTILS_FUNC) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aResultToken.func->mFID) {
	case FID_dumpBool: {
		bool argument;
		if (ParamIndexToVal(0, (char&)argument))
			_o_return_result;
		auto __retval = cv::utils::dumpBool(argument);
		return ValToResult(__retval, aResultToken);
	}
	case FID_dumpCString: {
		cv::String argument;
		if (ParamIndexToVal(0, argument))
			_o_return_result;
		auto __retval = cv::utils::dumpCString(argument.data());
		return ValToResult(__retval, aResultToken);
	}
	case FID_dumpDouble: {
		double argument;
		if (ParamIndexToVal(0, argument))
			_o_return_result;
		auto __retval = cv::utils::dumpDouble(argument);
		return ValToResult(__retval, aResultToken);
	}
	case FID_dumpFloat: {
		float argument;
		if (ParamIndexToVal(0, argument))
			_o_return_result;
		auto __retval = cv::utils::dumpFloat(argument);
		return ValToResult(__retval, aResultToken);
	}
	case FID_dumpInputArray: {
		cv::_InputArray argument;
		if (ParamIndexToVal(0, argument))
			_o_return_result;
		auto __retval = cv::utils::dumpInputArray(argument);
		return ValToResult(__retval, aResultToken);
	}
	case FID_dumpInputArrayOfArrays: {
		cv::_InputArray argument;
		if (ParamIndexToVal(0, argument))
			_o_return_result;
		auto __retval = cv::utils::dumpInputArrayOfArrays(argument);
		return ValToResult(__retval, aResultToken);
	}
	case FID_dumpInputOutputArray: {
		cv::_InputOutputArray argument;
		if (ParamIndexToVal(0, argument))
			_o_return_result;
		auto __retval = cv::utils::dumpInputOutputArray(argument);
		return ValToResult(__retval, aResultToken);
	}
	case FID_dumpInputOutputArrayOfArrays: {
		cv::_InputOutputArray argument;
		if (ParamIndexToVal(0, argument))
			_o_return_result;
		auto __retval = cv::utils::dumpInputOutputArrayOfArrays(argument);
		return ValToResult(__retval, aResultToken);
	}
	case FID_dumpInt: {
		int argument;
		if (ParamIndexToVal(0, argument))
			_o_return_result;
		auto __retval = cv::utils::dumpInt(argument);
		return ValToResult(__retval, aResultToken);
	}
	case FID_dumpRange: {
		cv::Range argument;
		if (ParamIndexToVal(0, argument))
			_o_return_result;
		auto __retval = cv::utils::dumpRange(argument);
		return ValToResult(__retval, aResultToken);
	}
	case FID_dumpRect: {
		cv::Rect argument;
		if (ParamIndexToVal(0, argument))
			_o_return_result;
		auto __retval = cv::utils::dumpRect(argument);
		return ValToResult(__retval, aResultToken);
	}
	case FID_dumpRotatedRect: {
		cv::RotatedRect argument;
		if (ParamIndexToVal(0, argument))
			_o_return_result;
		auto __retval = cv::utils::dumpRotatedRect(argument);
		return ValToResult(__retval, aResultToken);
	}
	case FID_dumpSizeT: {
		size_t argument;
		if (ParamIndexToVal(0, (intptr_t&)argument))
			_o_return_result;
		auto __retval = cv::utils::dumpSizeT(argument);
		return ValToResult(__retval, aResultToken);
	}
	case FID_dumpString: {
		cv::String argument;
		if (ParamIndexToVal(0, argument))
			_o_return_result;
		auto __retval = cv::utils::dumpString(argument);
		return ValToResult(__retval, aResultToken);
	}
	case FID_dumpTermCriteria: {
		cv::TermCriteria argument;
		if (ParamIndexToVal(0, argument))
			_o_return_result;
		auto __retval = cv::utils::dumpTermCriteria(argument);
		return ValToResult(__retval, aResultToken);
	}
	case FID_dumpVectorOfDouble: {
		std::vector<double> vec;
		if (ParamIndexToVal(0, vec))
			_o_return_result;
		auto __retval = cv::utils::dumpVectorOfDouble(vec);
		return ValToResult(__retval, aResultToken);
	}
	case FID_dumpVectorOfInt: {
		std::vector<int> vec;
		if (ParamIndexToVal(0, vec))
			_o_return_result;
		auto __retval = cv::utils::dumpVectorOfInt(vec);
		return ValToResult(__retval, aResultToken);
	}
	case FID_dumpVectorOfRect: {
		std::vector<cv::Rect> vec;
		if (ParamIndexToVal(0, vec))
			_o_return_result;
		auto __retval = cv::utils::dumpVectorOfRect(vec);
		return ValToResult(__retval, aResultToken);
	}
	case FID_generateVectorOfInt: {
		size_t len;
		std::vector<int> vec;
		if (ParamIndexToVal(0, (intptr_t&)len))
			_o_return_result;
		VarRef* var_vec = nullptr;
		if (ParamIndexToVal(1, var_vec))
			_o_return_result;
		cv::utils::generateVectorOfInt(len, vec);
		ValToResult(vec, aResultToken);
		g_ahkapi->VarAssign(var_vec, aResultToken);
		g_ahkapi->ResultTokenFree(aResultToken);
		return;
	}
	case FID_generateVectorOfMat: {
		int rows, cols, dtype;
		size_t len;
		std::vector<cv::Mat> vec;
		if (ParamIndexToVal(0, (intptr_t&)len))
			_o_return_result;
		if (ParamIndexToVal(1, rows))
			_o_return_result;
		if (ParamIndexToVal(2, cols))
			_o_return_result;
		if (ParamIndexToVal(3, dtype))
			_o_return_result;
		VarRef* var_vec = nullptr;
		if (ParamIndexToVal(4, var_vec))
			_o_return_result;
		cv::utils::generateVectorOfMat(len, rows, cols, dtype, vec);
		ValToResult(vec, aResultToken);
		g_ahkapi->VarAssign(var_vec, aResultToken);
		g_ahkapi->ResultTokenFree(aResultToken);
		return;
	}
	case FID_generateVectorOfRect: {
		size_t len;
		std::vector<cv::Rect> vec;
		if (ParamIndexToVal(0, (intptr_t&)len))
			_o_return_result;
		VarRef* var_vec = nullptr;
		if (ParamIndexToVal(1, var_vec))
			_o_return_result;
		cv::utils::generateVectorOfRect(len, vec);
		ValToResult(vec, aResultToken);
		g_ahkapi->VarAssign(var_vec, aResultToken);
		g_ahkapi->ResultTokenFree(aResultToken);
		return;
	}
	case FID_testAsyncArray: {
		cv::_InputArray argument;
		if (ParamIndexToVal(0, argument))
			_o_return_result;
		auto __retval = (AsyncArray*)AsyncArray::sPrototype->New(g_invalidparam, 1);
		__retval->mC = cv::makePtr<cv::AsyncArray>(cv::utils::testAsyncArray(argument));
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_testAsyncException: {
		auto __retval = (AsyncArray*)AsyncArray::sPrototype->New(g_invalidparam, 1);
		__retval->mC = cv::makePtr<cv::AsyncArray>(cv::utils::testAsyncException());
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_testOverloadResolution: {
		if (!MatchTypes("io?")) {
			cv::Point point = cv::Point(42, 24);
			int value;
			if (ParamIndexToVal(0, value))
				_o_return_result;
			if (aParamCount > 1)
				TokenToVal(*aParam[1], point, true);
			auto __retval = cv::utils::testOverloadResolution(value, point);
			return ValToResult(__retval, aResultToken);
		}
		else if (!MatchTypes("o")) {
			cv::Rect rect;
			if (ParamIndexToVal(0, rect))
				_o_return_result;
			auto __retval = cv::utils::testOverloadResolution(rect);
			return ValToResult(__retval, aResultToken);
		}
		else aResultToken.result = g_ahkapi->Error(_T("invalid param count or type"));
		return;
	}
	case FID_testOverwriteNativeMethod: {
		int argument;
		if (ParamIndexToVal(0, argument))
			_o_return_result;
		auto __retval = (__int64)cv::utils::testOverwriteNativeMethod(argument);
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_testRaiseGeneralException: {
		cv::utils::testRaiseGeneralException();
		return;
	}
	case FID_testReservedKeywordConversion: {
		int positional_argument, lambda = 2, from = 3;
		if (ParamIndexToVal(0, positional_argument))
			_o_return_result;
		if (aParamCount > 1)
			TokenToVal(*aParam[1], lambda, true);
		if (aParamCount > 2)
			TokenToVal(*aParam[2], from, true);
		auto __retval = cv::utils::testReservedKeywordConversion(positional_argument, lambda, from);
		return ValToResult(__retval, aResultToken);
	}
	case FID_testRotatedRect: {
		float x, y, w, h, angle;
		if (ParamIndexToVal(0, x))
			_o_return_result;
		if (ParamIndexToVal(1, y))
			_o_return_result;
		if (ParamIndexToVal(2, w))
			_o_return_result;
		if (ParamIndexToVal(3, h))
			_o_return_result;
		if (ParamIndexToVal(4, angle))
			_o_return_result;
		auto __retval = cv::utils::testRotatedRect(x, y, w, h, angle);
		return ValToResult(__retval, aResultToken);
	}
	case FID_testRotatedRectVector: {
		float x, y, w, h, angle;
		if (ParamIndexToVal(0, x))
			_o_return_result;
		if (ParamIndexToVal(1, y))
			_o_return_result;
		if (ParamIndexToVal(2, w))
			_o_return_result;
		if (ParamIndexToVal(3, h))
			_o_return_result;
		if (ParamIndexToVal(4, angle))
			_o_return_result;
		auto __retval = cv::utils::testRotatedRectVector(x, y, w, h, angle);
		return ValToResult(__retval, aResultToken);
	}
	}
}


BIF_DECL(CV_UTILS_FS_FUNC) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aResultToken.func->mFID) {
	case FID_getCacheDirectoryForDownloads: {
		auto __retval = cv::utils::fs::getCacheDirectoryForDownloads();
		return ValToResult(__retval, aResultToken);
	}
	}
}


BIF_DECL(CV_VIDEOIO_REGISTRY_FUNC) {
	ResultType __result;
	UNREFERENCED_PARAMETER(__result);
	switch (aResultToken.func->mFID) {
	case FID_getBackendName: {
		int api;
		if (ParamIndexToVal(0, api))
			_o_return_result;
		auto __retval = cv::videoio_registry::getBackendName((cv::VideoCaptureAPIs)api);
		return ValToResult(__retval, aResultToken);
	}
	case FID_getBackends: {
		auto __retval = cv::videoio_registry::getBackends();
		return ValToResult((std::vector<int>&)__retval, aResultToken);
	}
	case FID_getCameraBackendPluginVersion: {
		int api, version_ABI, version_API;
		if (ParamIndexToVal(0, api))
			_o_return_result;
		VarRef* var_version_ABI = nullptr;
		if (ParamIndexToVal(1, var_version_ABI))
			_o_return_result;
		VarRef* var_version_API = nullptr;
		if (ParamIndexToVal(2, var_version_API))
			_o_return_result;
		auto __retval = cv::videoio_registry::getCameraBackendPluginVersion((cv::VideoCaptureAPIs)api, version_ABI, version_API);
		g_ahkapi->VarAssign(var_version_ABI, ExprTokenType((__int64)version_ABI));
		g_ahkapi->VarAssign(var_version_API, ExprTokenType((__int64)version_API));
		return ValToResult(__retval, aResultToken);
	}
	case FID_getCameraBackends: {
		auto __retval = cv::videoio_registry::getCameraBackends();
		return ValToResult((std::vector<int>&)__retval, aResultToken);
	}
	case FID_getStreamBackendPluginVersion: {
		int api, version_ABI, version_API;
		if (ParamIndexToVal(0, api))
			_o_return_result;
		VarRef* var_version_ABI = nullptr;
		if (ParamIndexToVal(1, var_version_ABI))
			_o_return_result;
		VarRef* var_version_API = nullptr;
		if (ParamIndexToVal(2, var_version_API))
			_o_return_result;
		auto __retval = cv::videoio_registry::getStreamBackendPluginVersion((cv::VideoCaptureAPIs)api, version_ABI, version_API);
		g_ahkapi->VarAssign(var_version_ABI, ExprTokenType((__int64)version_ABI));
		g_ahkapi->VarAssign(var_version_API, ExprTokenType((__int64)version_API));
		return ValToResult(__retval, aResultToken);
	}
	case FID_getStreamBackends: {
		auto __retval = cv::videoio_registry::getStreamBackends();
		return ValToResult((std::vector<int>&)__retval, aResultToken);
	}
	case FID_getWriterBackendPluginVersion: {
		int api, version_ABI, version_API;
		if (ParamIndexToVal(0, api))
			_o_return_result;
		VarRef* var_version_ABI = nullptr;
		if (ParamIndexToVal(1, var_version_ABI))
			_o_return_result;
		VarRef* var_version_API = nullptr;
		if (ParamIndexToVal(2, var_version_API))
			_o_return_result;
		auto __retval = cv::videoio_registry::getWriterBackendPluginVersion((cv::VideoCaptureAPIs)api, version_ABI, version_API);
		g_ahkapi->VarAssign(var_version_ABI, ExprTokenType((__int64)version_ABI));
		g_ahkapi->VarAssign(var_version_API, ExprTokenType((__int64)version_API));
		return ValToResult(__retval, aResultToken);
	}
	case FID_getWriterBackends: {
		auto __retval = cv::videoio_registry::getWriterBackends();
		return ValToResult((std::vector<int>&)__retval, aResultToken);
	}
	case FID_hasBackend: {
		int api;
		if (ParamIndexToVal(0, api))
			_o_return_result;
		auto __retval = (__int64)cv::videoio_registry::hasBackend((cv::VideoCaptureAPIs)api);
		return (void)(aResultToken.SetValue(__retval));
	}
	case FID_isBackendBuiltIn: {
		int api;
		if (ParamIndexToVal(0, api))
			_o_return_result;
		auto __retval = (__int64)cv::videoio_registry::isBackendBuiltIn((cv::VideoCaptureAPIs)api);
		return (void)(aResultToken.SetValue(__retval));
	}
	}
}


