#!/bin/bash

show_help() {
  echo "Usage: $0  [Type] [evt]"
  echo ""
  echo "Options:"
  echo "  --help       Show this help message and exit"
  echo ""
  echo "Arguments:"
  echo "  Event Type       Choose "Signal" or "Empty" event (default: Signal)"
  echo "  evt              Event number to process (default: 0)"
  echo ""
  echo "Example:"
  echo "  $0 1         Process event 1"
  echo""
  echo "Plot (test.pdf) will be saved in the current directory ."

}

# Default values
evt=0
mode="Signal"


if [[ "$1" == "--help" ]] || [[ "$2" == "--help" ]]; then
  show_help
  exit 0
fi

# If first argument is a number (assumed to be event number), set mode to "Signal" and assign evt
if [[ "$1" =~ ^[0-9]+$ ]]; then
  mode="Signal"
  evt=$1
else
  # If first argument exists assign to mode
  if [ -n "$1" ]; then
    mode=$1
  fi

  # If next argument exists and is not a flag, assign to mode
  if [ -n "$2" ]; then
    evt=$2
  fi
fi

root -l -b -q "EventDisplay.C(${evt},\"${mode}\")"