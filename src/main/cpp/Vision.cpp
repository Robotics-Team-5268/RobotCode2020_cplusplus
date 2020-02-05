#include "Vision.hpp"

#include "cameraserver/CameraServer.h"
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <thread>

static void VisionThread()
{
    cs::UsbCamera camera = frc::CameraServer::GetInstance()->StartAutomaticCapture();
    camera.SetResolution(320, 240);
    cs::CvSink cvSink = frc::CameraServer::GetInstance()->GetVideo();
    cs::CvSource outputStreamStd = frc::CameraServer::GetInstance()->PutVideo("Gray", 320, 240);
    cv::Mat source;
    cv::Mat output;
    while(true) {
        if (cvSink.GrabFrame(source) == 0) {
        continue;
        }
    cvtColor(source, output, cv::COLOR_BGR2GRAY);
    outputStreamStd.PutFrame(output);
    }
}

Vision::Vision()
{
    std::thread visionThread( VisionThread );
    visionThread.detach();
}
