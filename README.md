# hana_study_group

first make a directory build
then switch to the build directory (cd build) and run
conan install .. --build=missing

then go out again (cd ..)
then run cmake -Bbuild -GNinja  // for ninja builds
then run ninja -C build

