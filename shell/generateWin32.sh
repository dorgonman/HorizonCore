#!/bin/sh
set -e
if [ "${HORIZON_SCRIPT_ROOT}" == "" ]
then
	export HORIZON_SCRIPT_ROOT=$(cd ../../HorizonScript/; pwd)
fi
${HORIZON_SCRIPT_ROOT}/shell/win32/generateProject.sh ../