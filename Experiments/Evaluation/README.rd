For Evaluation of Trigonometric Function with Multiple Meet-semilattices:
-------------------------------------------------------------------------

Z3 installation part:
1. unzip into a new folder z3 version 4.7.1: https://github.com/Z3Prover/z3/releases/tag/z3-4.7.1 (sorry I couldn't sent it the file is big).

2. Build z3 via cmake:
mkdir build
cd build
cmake -G "Unix Makefiles" ../
make -j4 # Replace 4 with an appropriate number
make
sudo make install

3. OpenSMT part:
git clone https://scm.ti-edu.ch/repogit/opensmt2.git
mkdir build; cd build; cmake -DPRODUCE_PROOF=ON -DCMAKE_BUILD_TYPE=release; make; make install

HiFrog build part:
4. git pull latticeref-v2-trigo
5. Build latticeref-v2-trigo: cd hifrog/trunk/cprover; mkdir build; cd build; cmake ../ -DUSE_Z3=ON -DCMAKE_BUILD_TYPE=Release; make hifrog

You shall check if the cmake found the z3 lib, it print this:
Located z3 version: 4.7.1.0

Experiments part:
6. Copy into the directory the benchmarks data

7. Copy into this folder the executable of hifrog and cbmc from the build directory of the version you pulled earlier (and compiled).

8. Run: ./run-test.sh >> out_final_HiFrog.txt

9. Run: ./cbmc_run_all.sh >> out_final_CBMC.txt 2>&1

10. Send back the results in the files: out_final_HiFrog.txt and out_final_CBMC.txt, and the folder mainReg_output/
