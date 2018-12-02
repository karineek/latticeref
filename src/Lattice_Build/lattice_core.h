#ifndef LATTICE_CORE_H
#define LATTICE_CORE_H

#include <set>
#include <string>

#include "read_fact_files.h"

// Linkage of this class: g++     -o dist/Debug/GNU-Linux/lattice_build build/Debug/GNU-Linux/lattice_core.o build/Debug/GNU-Linux/main.o build/Debug/GNU-Linux/read_fact_files.o -lmathsat -lz3  -std=c++11 -pthread
class lattice_core {
public:
    lattice_core(read_fact_filest* facts_container, std::string _base_name);
    lattice_core(const lattice_core& orig);
    virtual ~lattice_core();
    
    void checkNadd2lattice(std::set<std::string>* curr_set, std::set<std::string>*  candidates);
    
private:
    read_fact_filest* m_facts_container=0;
    std::string m_base_name="";
    
    bool is_sat(std::set<std::string>* curr_set);
    
    void write2log(std::set<std::string>*, std::string);
    
    std::string build_query_and(std::set<std::string>* curr_set);
    
    std::string facts_and_subset_to_string(std::set<std::string>* curr_set);
    
    bool is_set_coexist(std::set<std::string>* curr_set);
};

#endif /* LATTICE_CORE_H */

