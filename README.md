# latticeref
Lattice Refinement Algorithms and Benchmarks



Lattice-based refinement for modulo function:
=============================================
Tools required: HiFrog, OpenSMT, z3

HiFrog Version (for VSTTE 2018): https://scm.ti-edu.ch/projects/hifrog/repository?utf8=%E2%9C%93&rev=latticeref-v1-mod 

Original results: https://drive.google.com/drive/folders/1WjX8FKcLqg1apNxrHZzHxXWIKo7z9ZLI

Additional information: http://verify.inf.usi.ch/content/lattice-refinement 



Lattice-based refinement for trigonometric functions:
=====================================================
Tools required: HiFrog, OpenSMT, z3

HiFrog Version: https://scm.ti-edu.ch/projects/hifrog/repository?utf8=%E2%9C%93&rev=latticeref-v2-trigo 

Additional information and evaluation: https://drive.google.com/drive/folders/1QthdYYhUBNJMfJ6CNcrJZ_M03BWWIp-c?usp=sharing 


Data for Experiments
~~~~~~~~~~~~~~~~~~~~
All data and benchmarks are available in our git repository:
https://scm.ti-edu.ch/projects/hi-bench/repository/revisions/master/show/main-bench/lattice_summaries/trigonometric_ex

In addition, we put a copy of these files in Google Drive:
All the lattices and the summaries are found in the following zip file: https://drive.google.com/open?id=1_lPLkBwPn4nJvdBpL9QZvLHDpX6LyfCy.
All the benchmarks are found: https://drive.google.com/open?id=1q-Bh_jtTZI5GT7AIWgdI-MoPuedPut84.

We aware of some issues with the zip file of all our experimental results. In case you experience any, you can either access the folder in Google drive: https://drive.google.com/drive/folders/18hQMN_jvOxdCGWM5Bj8iqHqPY8brFgeK?usp=sharing or email us: karine.even_mendoza@kcl.ac.uk and we can send any of the files, unzipped.


How to Run the Code
HiFrog has a support for 4 logics in SMT: qfuf, qflia, qflra, and prop. Lattice approach is implemented only for qfuf with OpenSMT, and qflia, qflra with Z3. The options are:
--solver osmt, --solver z3 with solving mode: --solving-mode inc, --solving-mode semi, --solving-mode no, and logics:  --logic qfuf, --logic qflra or --logic qflia.

The name of the input data refers in the following commands to LRA, to change it to LIA replace lra in lia, and to change it to EUF, replace lra in uf.
 
Run HiFrog 
./hifrog <c-file> --logic <logic> --save-summaries __summaries --claim 1 --solver <solver>
Run HiFrog with Summaries
./hifrog <c-file> --logic <logic> --save-summaries __summaries --claim 1 --solver <solver> --solving-mode inc --no-slicing --load-summaries user_defined_summaries/__summaries_cos_lra_single,user_defined_summaries/__summaries_sin_lra_single,user_defined_summaries/__summaries_const_sin_cos --load-sum-model lattices/flat_cos_lattice_lra,lattices/flat_sin_lattice_lra 
Run HiFrog with a Single Lattice
./hifrog <c-file> --logic <logic> --save-summaries __summaries --claim 1 --solver <solver> --solving-mode inc --no-slicing --load-summaries user_defined_summaries/__summaries_sin_lra,user_defined_summaries/__summaries_cos_lra,user_defined_summaries/__summaries_const_sin_cos --load-sum-model lattices/sin_lattice_lra,lattices/cos_lattice_lra 

Run HiFrog with Several Lattices:

To run the new lattice-based refinement algorithm with many lattices, we run HiFrog like this,

./hifrog <c-file> --logic <logic> --save-summaries __summaries --claim 1 --solver <solver> --solving-mode inc --no-slicing --load-summaries user_defined_summaries/__summaries_cos_lra,user_defined_summaries/__summaries_sin_lra,user_defined_summaries/__summaries_const_sin_cos --load-sum-model lattices/cos_lattice_lra,lattices/sin_lattice_lra --no-error-trace
