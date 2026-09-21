#!/usr/bin/env bash
# build, run ctest, render HTML via lcov
set -euo pipefail

BUILD_DIR=build-coverage
cd "$(dirname "$0")"

cmake -S . -B "$BUILD_DIR" \
  -DCMAKE_BUILD_TYPE=Debug \
  -DBUILD_CLIENT=OFF \
  -DBUILD_SERVER=OFF \
  -DBUILD_TESTS=ON \
  -DENABLE_COVERAGE=ON
cmake --build "$BUILD_DIR" -j"$(nproc)"


lcov --directory "$BUILD_DIR" --zerocounters

# baseline, includes all files
lcov --capture --initial --directory "$BUILD_DIR" -o "$BUILD_DIR/base.info" --ignore-errors mismatch,gcov,source,empty

ctest --test-dir "$BUILD_DIR" --output-on-failure

lcov --capture --directory "$BUILD_DIR" -o "$BUILD_DIR/test.info" --ignore-errors mismatch,gcov,source,empty
lcov -a "$BUILD_DIR/base.info" -a "$BUILD_DIR/test.info" -o "$BUILD_DIR/all.info"

# keep only our own sources 
lcov --extract "$BUILD_DIR/all.info" "$PWD/game/*" "$PWD/libs/*" -o "$BUILD_DIR/coverage.info"
lcov --list "$BUILD_DIR/coverage.info"

genhtml "$BUILD_DIR/coverage.info" -o "$BUILD_DIR/html" --legend --demangle-cpp
echo "HTML report: $PWD/$BUILD_DIR/html/index.html"
