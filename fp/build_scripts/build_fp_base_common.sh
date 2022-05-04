#!/bin/bash

show_info() {
  echo -e "\033[1;32m$(date "+%Y-%m-%d %H:%M:%S ")$1\033[0m"
}

show_warning() {
  echo -e "\033[0;33m$(date "+%Y-%m-%d %H:%M:%S ")$1\033[0m"
}

show_error() {
  echo -e "\033[1;31m$(date "+%Y-%m-%d %H:%M:%S ")$1\033[0m"
}

root_dir=$(git rev-parse --show-toplevel)

prepare_build(){
  target_os=$1
  case ${target_os} in
    linux)
    show_info "start prepare build fp basecore for linux platform"
    ;;
  case ${target_os} in
    windows)
    show_info "start prepare build fp basecore for windows platform"
    ;;
    *)
    show_error "current not support build fp basecore for $target_os platform"
    exit 1
    ;;
  esac  #the used case end
}

exec_and_check(){
  show_info "${1} start"

  ${1}
  
  if [[ $? -ne 0 ]]; then
    show_error "'${1}' failed"
    exit 1
  fi
  show_info "${1} end"
}



