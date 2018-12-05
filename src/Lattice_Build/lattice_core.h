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
    
    void checkShrinkLattice();
    
private:
    read_fact_filest* m_facts_container=0;
    std::string m_base_name="";
    
    std::map<std::set<std::string>, std::set<std::string>> m_lattice_graph;

    bool is_sat(std::set<std::string>* curr_set);
    
    void write2log(std::set<std::string>*, std::string);
    
    void write2log(std::string fact, std::set<std::string>* curr_set, std::string name);
    
    std::string build_query_and(std::set<std::string>* curr_set);
    
    std::string facts_and_subset_to_string(std::set<std::string>* curr_set);
    
    bool is_set_coexist(std::set<std::string>* curr_set);
    
    std::string build_query_or_not(std::string curr_fact, std::set<std::string>* curr_set);
    
    bool is_unsat_implication(std::string a, std::set<std::string>* b);
    
    bool is_connected(std::set<std::string>* set_smaller, std::set<std::string>* set_bigger);
    
    bool has_edge_ab(std::set<std::string>* a, std::set<std::string>* b); // in the meet-semilattice
    
    std::set<std::string>* node_reduce(std::set<std::string>* a);
    
    bool is_nodes_equal(std::set<std::string>* a, std::set<std::string>* b);
    
    bool is_edge_exist(std::set<std::string>* a, std::set<std::string>* b);
    
    void add_node(std::set<std::string>* a, std::set<std::string>* b);
    
    bool checkImplicationsAndAdd2Log(std::string a, std::set<std::string>* b);
    
    // Compare two sets of facts
    bool set_compare(std::set<std::string> const &lhs, std::set<std::string> const &rhs){
        if (lhs.size() != rhs.size()) return false;
        return (equal(lhs.begin(), lhs.end(), rhs.begin()));
    }
};

#endif /* LATTICE_CORE_H */

