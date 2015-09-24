#!/bin/sh
set -e
if [ "${HORIZON_BUILD_TOOL_ROOT}" == "" ]
then
	export HORIZON_BUILD_TOOL_ROOT=$(cd ../../HorizonBuildTool/; pwd)
fi
${HORIZON_BUILD_TOOL_ROOT}/shell/win32/generateProject.sh ../