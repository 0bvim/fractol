#!/bin/sh

check_command() {
  if [ $? -ne 0 ]; then
    echo "Error: $1"
    exit 1
  fi
}

echo "Checking dependencies"

make --version >/dev/null 2>&1
check_command "Make not installed"

cmake --version >/dev/null 2>&1
check_command "CMake not installed"

clang --version >/dev/null 2>&1
check_command "Missing not installed"

gcc --version >/dev/null 2>&1
check_command "Missing not installed"

echo "OK"
