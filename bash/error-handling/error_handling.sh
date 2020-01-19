#!/usr/bin/env bash
USAGE="Usage: ./error_handling <greetee>"

if [ "$#" -ne 1 ]; then
  echo $USAGE
  exit 1
else
  echo "Hello, $1"
fi
exit 0