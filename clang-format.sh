#!/usr/bin/env bash
find examples/ -iname *.h -o -iname *.cpp | xargs clang-format -i
find src/ -iname *.h -o -iname *.cpp | xargs clang-format -i
find tests/ -iname *.h -o -iname *.cpp | xargs clang-format -i