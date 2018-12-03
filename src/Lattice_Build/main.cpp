#include "read_fact_files.h"
#include "lattice_core.h"
#include <iostream>

// Call: ./extractsum <declaration file name> <facts file name> <output smt file base name> <flag_all_subsets>
// E.g., ./extractsum facts_decl.txt Coq_translate.txt build_output/smt_
// 1: input with all the facts
// 2: [optional] input files of last known state of the search
// 3: output subsets of the facts for the build of the lattice (true flag)
//    output an smt file with all the facts as query (false flag)
// 
// Input init search: facts_decl.txt lattice_construction_cos.txt lattice_construction_cos_and.txt
// ./dist/Debug/GNU-Linux/lattice_build data/facts_decl.txt data/lattice_construction_sin.txt data/lattice_construction_sin_and.txt output/output_sin output/output_sin_SAT_lattice.txt output/output_sin_UNSAT_lattice.txt 
//
int main(int argc, const char **argv)
{
    if (argc <=1) {
        std::cout << "---------------- HELP: Lattice Construction Util ----------------\n";
        std::cout << "1> Extra facts or declarations \n";
        std::cout << "2> Original set of facts \n";
        std::cout << "3> Facts where guards are in (and ...) form \n";
        std::cout << "4> Output file base name and location \n";
        std::cout << "5> Logs SAT of AND form \n";
        std::cout << "6> Logs UNSAT of AND form \n";
        std::cout << "---------------- ------------------------------------------------\n";
        exit(0);
    }
    if (argc < 4) {
        std::cerr << "Missing file facts name or/and declaration facts name and/or output smt file name." << std::endl;
        return 1;
    }

    // Read all the facts and the header
    read_fact_filest* facts_subsets_writer = new read_fact_filest();
    if (!facts_subsets_writer->load_facts(argv[1], argv[2], argv[3])) {
        std::cerr << "Error reading the input file: " << argv[1] << " and/or " << argv[2] << " and/or " << argv[3] << std::endl;
        return 1;
    }
    std::cout << ";; Load Facts and And Facts is Successful\n";
    
    // Load prev. state
    if (argc > 5) facts_subsets_writer->load_co_exists_list(argv[5]);
    if (argc > 6) facts_subsets_writer->load_none_co_exists_list(argv[6]);
        
    
    // Init base point for the search
    int n=facts_subsets_writer->get_facts_size();
    std::vector<std::set<std::string>> base = facts_subsets_writer->get_facts_name_as_sets();
    std::set<std::string> list_of_facts = facts_subsets_writer->get_facts_name();
    
    // Core algorithm object - find the lattice
    std::string base_name = (argc < 5) ? "output\\trigo_" : argv[4];
    std::cout << ";; Use base name output file prefix --" << base_name << "--" << std::endl; 
    lattice_core* core = new lattice_core(facts_subsets_writer, base_name);
    
    // Restore prev-state:
    //if (argc == 7) {
    //    // Update n too
    //}
    
    // Start the calculations with MathSAT 5
    for (int i=0; i < n; i++)
    {
        // Call recursively to all subset of facts
        
        // Build the input data for the build process
        for(std::set<std::string>::iterator it = base[i].begin(); it != base[i].end(); ++it) {  
            std::string curr = *it; list_of_facts.erase(curr);
        }

        // Send the current set of facts to check against each fact in the list
        core->checkNadd2lattice(&base[i] , &list_of_facts);
         
        // Restore the set for the next iteration
        //list_of_facts.insert(base[i].begin(),base[i].end());
        // For optimization do not restore the set, as it has been checked with the call above
    }

    // Clear the memory
    delete facts_subsets_writer;
    delete core;
    
    return 0;
}
