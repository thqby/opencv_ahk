#pragma once
#include "cv_ahk.h"


class Mat : public Object
{
	enum MemberID {
		M___New,
		M___Delete,
		M_adjustROI,
		M_assignTo,
		M_Call,
		M_clone,
		M_col,
		M_colRange,
		M_convertTo,
		M_copyTo,
		M_create,
		M_cross,
		M_diag,
		M_dot,
		M_eye,
		M_getUMat,
		M_inv,
		M_locateROI,
		M_mul,
		M_ones,
		M_ptr,
		M_reshape,
		M_row,
		M_rowRange,
		M_setTo,
		M_step1,
		M_t,
		M_zeros,
		P___Item,
		P_channels,
		P_cols,
		P_depth,
		P_dims,
		P_elemSize,
		P_elemSize1,
		P_empty,
		P_isContinuous,
		P_isSubmatrix,
		P_ptr,
		P_rows,
		P_total,
		P_type,
		M_add,
		M_subtract,
		M_multiply,
		M_divide,
	};
public:
	cv::Mat mC;

	operator cv::Mat* () { return &mC; };
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};

class UMat : public Object
{
	enum MemberID {
		M___New,
		M___Delete,
		M_adjustROI,
		M_assignTo,
		M_Call,
		M_clone,
		M_col,
		M_colRange,
		M_convertTo,
		M_copyTo,
		M_create,
		M_diag,
		M_dot,
		M_eye,
		M_getMat,
		M_inv,
		M_locateROI,
		M_mul,
		M_ones,
		M_reshape,
		M_row,
		M_rowRange,
		M_setTo,
		M_step1,
		M_t,
		M_zeros,
		P_channels,
		P_cols,
		P_depth,
		P_dims,
		P_elemSize,
		P_elemSize1,
		P_empty,
		P_isContinuous,
		P_isSubmatrix,
		P_ptr,
		P_rows,
		P_total,
		P_type,
	};
public:
	cv::UMat mC;

	operator cv::UMat* () { return &mC; };
	void Invoke(ResultToken& aResultToken, int aID, int aFlags, ExprTokenType* aParam[], int aParamCount);
	thread_local static IAhkApi::Prototype* sPrototype;
	static ObjectMember sMember[];
	static int sMemberCount;
};