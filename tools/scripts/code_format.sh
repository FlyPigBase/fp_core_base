#!/bin/sh
set -x
base_dir=$(git rev-parse --show-toplevel)
os=${1}

if test "$os" = "linux"; then
  platform=linux
else
  echo "not support ${os} platform code format"
  exit 1
fi

astyle_bin=$base_dir/tools/astyle/${os}/astyle_${os}
astyle_options=$base_dir/tools/astyle/google.ini
astyle="${astyle_bin} --options=${astyle_options} -n ${base_dir}/src/*.cc ${base_dir}/src/logs/*.cc ${base_dir}/src/common/*.h ${base_dir}/src/logs/*.h"

${astyle}