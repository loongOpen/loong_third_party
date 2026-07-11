# loong_third_party
cd build
cmake ..
make

cd build
cmake -DAARCH64=ON ..
make

cd build
cmake -DRISCV64=ON ..
make