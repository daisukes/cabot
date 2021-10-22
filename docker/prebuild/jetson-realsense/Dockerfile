ARG from=ros:melodic-ros-desktop-l4t-r32.4.4

FROM $from AS build

# install required packages
RUN apt update && apt install -y \
	wget software-properties-common apt-utils curl git \
	unzip usbutils \
	&& \
	apt-get clean && \
	rm -rf /var/lib/apt/lists/*

# install librealsense
RUN apt-key adv --keyserver keys.gnupg.net --recv-key F6E65AC044F831AC80A06380C8B3A55A6F3EFCDE || apt-key adv --keyserver hkp://keyserver.ubuntu.com:80 --recv-key F6E65AC044F831AC80A06380C8B3A55A6F3EFCDE
RUN add-apt-repository "deb http://realsense-hw-public.s3.amazonaws.com/Debian/apt-repo bionic main" -u
RUN apt update && apt install -y \
	librealsense2-utils librealsense2-dev \
	&& \
	apt-get clean && \
	rm -rf /var/lib/apt/lists/*


ENV UNDERLAY_WS=/opt/underlay_ws
RUN mkdir -p $UNDERLAY_WS/src
WORKDIR $UNDERLAY_WS

ARG REALSENSE_ROS_V=2.2.21

# clone ddynamic_reconfigure source to build realsense-ros
# if ROS is installed by package, use apt package to install ddynamic_reconfigure
RUN cd src && \
	git clone https://github.com/pal-robotics/ddynamic_reconfigure.git

# clone realsense-ros source
RUN cd src && \
	wget https://github.com/IntelRealSense/realsense-ros/archive/${REALSENSE_ROS_V}.zip && \
	unzip ${REALSENSE_ROS_V}.zip

# copy customized RealSense setting
COPY ./rs_aligned_depth_1280x720_30fps.launch $UNDERLAY_WS/src/realsense-ros-${REALSENSE_ROS_V}/realsense2_camera/launch/

# catkin_make
WORKDIR $UNDERLAY_WS/
RUN . /opt/ros/$ROS_DISTRO/install_isolated/setup.sh && \
	catkin_make install -DPYTHON_EXECUTABLE=/usr/bin/python3 && \
	sed -i 's:ros/$ROS_DISTRO/install_isolated:underlay_ws/install:g' /ros_entrypoint.sh


