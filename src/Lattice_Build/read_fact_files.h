#ifndef READ_FACT_FILES_H
#define READ_FACT_FILES_H

#include <iostream>
#include <list>
#include <map>
#include <vector>
#include <set>
#include <string>
#include <utility>
using namespace std;

#include <algorithm>

using namespace std;

class read_fact_filest {
public:
    read_fact_filest() {}
    virtual ~read_fact_filest() {}

    // Getters/ Setters
    int get_facts_size() {return facts.size(); }

    // Logic
    bool load_facts(std::string facts_decl_file_name, std::string facts_file_name, std::string facts_file_name_and); // All Stages
    
    // Get pair of facts index i
    std::pair<std::string, std::string> get_pair_facts(std::string index);
    
    // Get a list of facts
    std::set<std::string> get_facts_name() { return facts_keys; }
    
    // Get the vector as a vector of sets
    std::vector<std::set<std::string>> get_facts_name_as_sets();
    
    // Get Declaration
    std::string get_decl_str() { return str_decls; }
    
    // Get implication format fact
    std::string get_and_fact(std::string index);
    
    // Load previous results - co-exists to facts_sat_sets
    void load_co_exists_list(std::string filename);
    void load_none_co_exists_list(std::string filename);
    
    // Check if prev. SAT AND
    bool is_prev_SAT_and_facts(set<std::string>* set2check);
    
    // Check if prev. UNSAT AND
    bool is_prev_UNSAT_and_facts(std::set<std::string> *set2check);
  
private:
    std::string str_decls="";
    std::vector<std::string> decls; // All stages
    std::set<std::string> facts_keys; 
    std::map<std::string,std::string> facts; // All Stages
    std::map<std::string,std::string> facts_and; // All Stages
    
    std::string original_header_function;
    
    std::set<std::set<std::string>> facts_sat_sets;
    
    std::set<std::set<std::string>> facts_sat_sets_unsat;
    
    // Private methods:
    bool load(std::string facts_file_name, bool is_and=false);
    
    // Compare two sets of facts
    bool set_compare(std::set<std::string> const &lhs, std::set<std::string> const &rhs){
        if (lhs.size() != rhs.size()) return false;
        return (equal(lhs.begin(), lhs.end(), rhs.begin()));
    }
};

#endif /* READ_FACT_FILES_H */

