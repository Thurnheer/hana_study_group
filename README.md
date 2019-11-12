# hana_study_group

## Builds with Conan: (not working for Windows)
first make a directory build
then switch to the build directory (cd build) and run
conan install .. --build=missing

then go out again (cd ..)
then run cmake -Bbuild -GNinja  // for ninja builds
then run ninja -C build

## Builds with Path to local boost:
then run cmake -Bbuild -Dboost_path="path_to_boost"  // for ninja builds


