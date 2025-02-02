// Copyright (c) 2021  Carnegie Mellon University
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
// Author: Daisuke Sato <daisukes@cmu.edu>

#include <pluginlib/class_list_macros.h>
#include <nodelet/nodelet.h>

#include "detect_darknet_opencv.hpp"

namespace TrackPeopleCPP
{
  class DetectDarknetOpencvNodelet : public nodelet::Nodelet
  {
  public:
    DetectDarknetOpencvNodelet()
    {
      ROS_INFO("NodeletClass Constructor");
      impl = new DetectDarknetOpencv();
    }

    ~DetectDarknetOpencvNodelet()
    {
      ROS_INFO("NodeletClass Destructor");
    }

  private:
    DetectDarknetOpencv* impl;

    void onInit()
    {
      ros::NodeHandle &nh = getNodeHandle();
      impl->onInit(nh);
    }
  }; // class DetectDarknetOpencvNodelet

  PLUGINLIB_EXPORT_CLASS(TrackPeopleCPP::DetectDarknetOpencvNodelet, nodelet::Nodelet)
} // namespace TrackPeopleCPP
