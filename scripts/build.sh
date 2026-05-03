#!/usr/bin/env bash
set -euo pipefail

cmake -S . -B build
cmake --build build

echo
echo "Executable: out/orderbook"
