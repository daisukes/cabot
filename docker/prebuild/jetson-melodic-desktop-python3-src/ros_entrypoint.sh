#!/bin/bash
set -e

# setup ros environment
source "/opt/ros/$ROS_DISTRO/install_isolated/setup.bash"
export ROS_PYTHON_VERSION=3

exec "$@"