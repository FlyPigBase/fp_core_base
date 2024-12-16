#!/usr/bin/env sh
 
issue_id=$(cat $1 | sed -n 's/^\(#[0-9]*\) .*/\1/p')
 
if [ ! $issue_id ]
then
    echo "commit msg 必须开头添加 issue id"
    exit 1
fi