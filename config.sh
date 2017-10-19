#!/bin/bash
function prompt()
{
  #2 variables expected, prompt followed by receiving variable.
  read -p "$1" $2
}

function promptr()
{
  #2 variables expected, prompt followed by receiving variable.
  local promptr_runflag=1
  local output=""
  while [ $promptr_runflag -eq 1 ]
  do
    prompt "$1" output
    local varification=""
    prompt "Is the following the intended input? (Y/n): \"$output\": " varification
    if [ "$varification" = "Y" ]
    then
      promptr_runflag=0
    fi
  done
  read $2 <<< $output
}

promptr "Enter your full name: " fullname
promptr "Enter your git username: " username
promptr "Enter your email: " email
promptr "Enter the repository name: " repository

git config --global core.editor "nano"
git config --global user.name  "$fullname"
git config --global user.email "$email"
git remote set-url origin "https://$username@github.com/$username/$repository"