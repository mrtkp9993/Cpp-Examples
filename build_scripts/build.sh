#!/bin/bash

if [[ "`uname`" == "Darwin" ]]; then
  xcodebuild -project ../../polyroot/polyroot.xcodeproj -scheme polyroot
  xcodebuild -project ../../finiteDifferences/finiteDifferences.xcodeproj -scheme finiteDifferences
  xcodebuild -project ../../CubicSplineInterpolation/CubicSplineInterpolation.xcodeproj -scheme CubicSplineInterpolation
  xcodebuild -project ../../CompositeSimpsonsRule/CompositeSimpsonsRule.xcodeproj -scheme CompositeSimpsonsRule
  xcodebuild -project ../../EigenExamples/EigenExamples.xcodeproj -scheme EigenExamples
  xcodebuild -project ../../FixedPointIteration/FixedPointIteration.xcodeproj -scheme FixedPointIteration
  xcodebuild -project ../../RandomNumberGenerators/RandomNumberGenerators.xcodeproj -scheme RandomNumberGenerators
  xcodebuild -project ../../RungeKutta/RungeKutta.xcodeproj -scheme RungeKutta
  xcodebuild -project ../../GoldenSectionSearch/GoldenSectionSearch.xcodeproj -scheme GoldenSectionSearch
fi
