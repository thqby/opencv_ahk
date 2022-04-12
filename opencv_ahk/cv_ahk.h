#pragma once
#include <opencv2/opencv.hpp>
#include <opencv2/core/quaternion.hpp>
#include <opencv2/core/opengl.hpp>
#include <opencv2/gapi/core.hpp>
#include <opencv2/gapi/video.hpp>
#include <opencv2/gapi/stereo.hpp>
#include <opencv2/gapi/infer/ie.hpp>
#include <opencv2/gapi/infer/onnx.hpp>
#include <opencv2/gapi/streaming/sync.hpp>
#include <opencv2/gapi/streaming/onevpl/device_selector_interface.hpp>
#include <opencv2/gapi/streaming/gstreamer/gstreamersource.hpp>
#include <opencv2/gapi/fluid/gfluidkernel.hpp>
#include <opencv2/stitching/detail/timelapsers.hpp>
#include <opencv2/video/detail/tracking.detail.hpp>
#include <opencv2/gapi/infer/bindings_ie.hpp>
#include <ahkapi.h>

extern IAhkApi* g_ahkapi;
extern ExprTokenType g_invalid[1];
extern ExprTokenType* g_invalidparam[1];