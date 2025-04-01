#!/usr/bin/env bash

set -e

BUILD_DIR="build"

# Ensure build exists
if [ ! -d "$BUILD_DIR" ]; then
  echo "🔧 No build directory found. Running meson setup..."
  meson setup "$BUILD_DIR"
fi

echo "🔨 Building..."
ninja -C "$BUILD_DIR"

echo "🔨 Running..."
./build/examples/example_form

echo "✅ Done!"