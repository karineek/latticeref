#include "read_fact_files.h"

#include <assert.h>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>


/*******************************************************************

 Function: read_fact_filest::load_facts

 Inputs: file name where all the declarations of the vars of the facts 
         are, and another file with all the facts
  
 Outputs: 

 Purpose: Good for the build of sub-sets of facts as .smt file for
          both stages, guard && fact and guard => facts.
 
\*******************************************************************/
bool read_fact_filest::load_facts(string facts_decl_file_name, string facts_file_name, string facts_file_name_and) 
{
    /* Reads Declarations of SMT file */
    std::ifstream input_decl(facts_decl_file_name);
    if (!input_decl.is_open())
    {
        std::cout << "Cannot find the facts's declarations file: " << facts_decl_file_name << std::endl;
        return false;
    }
    
    std::string line;
    while(std::getline(input_decl, line))
    {
        str_decls += line + "\n";
        decls.push_back(line);
    }
    input_decl.close();
    
    /* Read Facts */
    if (!load(facts_file_name))
        return false;
    
    /* Read Facts AND format */
    if (!load(facts_file_name_and, true))
        return false;
    
    
    // Complete only if load facts
    return (facts_and.size() == facts.size());
}

bool read_fact_filest::load(string facts_file_name, bool is_and)
{
    /* Reads the facts */
    std::ifstream input_facts(facts_file_name);
    if (!input_facts.is_open())
    {
        std::cout << "Cannot open the facts' file: " <<  facts_file_name << std::endl;
        return false;
    }
    
    //std::cout << "==> Reading facts: ";
    
    std::string fact="";
    std::string name="";
    while (std::getline(input_facts, name)) {
        if (name[0] == ';') continue;
        if (!std::getline(input_facts, fact)) {
            return false;
        }

        // Add name,fact
        if (is_and)
            facts_and.insert(pair<string, string> (name, fact));
        else {
            facts.insert(pair<string, string> (name, fact));
            facts_keys.insert(name);
        }
        
        //std::cout << ";; ADDING: <" << name << ", " << fact << ">\n"; 
    }
    //std::cout << std::endl;
    input_facts.close();
    
    std::cout << "** (" << facts_file_name << ") Added: " << (is_and ? facts_and.size() : facts.size()) << " facts **" << std::endl;
    
    return is_and ? (facts_and.size() > 0) : (facts.size() > 0);
}

// Get pair of facts index i
std::pair<std::string, std::string> read_fact_filest::get_pair_facts(std::string index)
{ 
    if (facts_and.size() != facts.size()) return std::make_pair("", "");
    if (facts_and.count(index) == 0) return std::make_pair("", "");
    
    return std::make_pair(facts[index], facts_and[index]);
}

// Get pair of facts index i
std::string read_fact_filest::get_and_fact(std::string index)
{ 
    if (facts_and.size() != facts.size()) return "";
    if (facts_and.count(index) == 0) return "";
    
    return facts_and[index];
}

// Get the vector as a vector of sets
std::vector<std::set<std::string>> read_fact_filest::get_facts_name_as_sets()
{
    std::vector<std::set<std::string>> v;
    for(std::set<std::string>::iterator it = facts_keys.begin(); it != facts_keys.end(); ++it) {  
        std::set<std::string> s = {*it};
        v.push_back(s);
    }

    return v;
}

// Load previous results - co-exists to facts_sat_sets
void read_fact_filest::load_co_exists_list(std::string filename)    
{
    std::cout << ";; Loading prev-results: " << filename << std::endl;
    
    /* Reads Declarations of SMT file */
    std::ifstream input_prev(filename);
    if (!input_prev.is_open())
    {
        std::cout << "Cannot find the facts's prev. state file: " << filename << std::endl;
        std::cout << "** SKIP PREV. STATE LOADING... **" << std::endl;
        return;
    }
    
    std::string line;
    while(std::getline(input_prev, line))
    {
        std::istringstream iss(line);
        std::string token;
        std::set<std::string> subset;
        while(std::getline(iss, token, '\t'))  // but we can specify a different one
        {
            token.erase(std::remove(token.begin(), token.end(), '\t'), token.end());
            token.erase(std::remove(token.begin(), token.end(), ' '), token.end());
            subset.insert(token);
        }
        facts_sat_sets.insert(subset);
    }
    input_prev.close();
}

// Check if prev. SAT AND
bool read_fact_filest::is_prev_SAT_and_facts(std::set<std::string> *set2check)
{
    if (set2check->size() == 1) return true;
    
    // Else check manually
    for(auto it_facts_set = facts_sat_sets.begin(); it_facts_set != facts_sat_sets.end(); ++it_facts_set) {
        if (set_compare(*it_facts_set, *set2check)) return true;
    }

    return false;
}

// Load previous results - co-exists to facts_sat_sets
void read_fact_filest::load_none_co_exists_list(std::string filename)    
{
    std::cout << ";; Loading prev-results: " << filename << std::endl;
    
    /* Reads Declarations of SMT file */
    std::ifstream input_prev(filename);
    if (!input_prev.is_open())
    {
        std::cout << "Cannot find the facts's prev. state file: " << filename << std::endl;
        std::cout << "** SKIP PREV. STATE LOADING... **" << std::endl;
        return;
    }
    
    std::string line;
    while(std::getline(input_prev, line))
    {
        std::istringstream iss(line);
        std::string token;
        std::set<std::string> subset;
        while(std::getline(iss, token, '\t'))  // but we can specify a different one
        {
            token.erase(std::remove(token.begin(), token.end(), '\t'), token.end());
            token.erase(std::remove(token.begin(), token.end(), ' '), token.end());
            subset.insert(token);
        }
        facts_sat_sets_unsat.insert(subset);
    }
    input_prev.close();
}

// Check if prev. SAT AND
bool read_fact_filest::is_prev_UNSAT_and_facts(std::set<std::string> *set2check)
{
    if (set2check->size() == 1) return true;
    
    // Else check manually
    for(auto it_facts_set = facts_sat_sets_unsat.begin(); it_facts_set != facts_sat_sets_unsat.end(); ++it_facts_set) {
        if (set_compare(*it_facts_set, *set2check)) return true;
    }

    return false;
}

////////// IMPLICATION CODE !
// Load previous results - co-exists to facts_sat_sets

void read_fact_filest::load_implication_list(std::string filename)    
{
    std::cout << ";; Loading prev-results: " << filename << std::endl;
    
    /* Reads Declarations of SMT file */
    std::ifstream input_prev(filename);
    if (!input_prev.is_open())
    {
        std::cout << "Cannot find the facts's prev. state file: " << filename << std::endl;
        std::cout << "** SKIP PREV. STATE LOADING... **" << std::endl;
        return;
    }
    
    std::string line;
    while(std::getline(input_prev, line))
    {
        std::istringstream iss(line);
        std::string token;
        std::set<std::string> subset;
        std::string fact;
        bool first=true;
        while(std::getline(iss, token, '\t'))  // but we can specify a different one
        {
            token.erase(std::remove(token.begin(), token.end(), '\t'), token.end());
            token.erase(std::remove(token.begin(), token.end(), ' '), token.end());
            if (first)
                fact=token;
            else
                subset.insert(token);
        }
        facts_implication_sets.insert(make_pair(fact, subset));
    }
    input_prev.close();
}

bool read_fact_filest::is_prev_implication(std::string a, std::set<std::string>* b)
{
    if (facts_implication_sets.empty()) return false;

    // Else check manually
    for(auto it = facts_implication_sets.begin(); it != facts_implication_sets.end(); ++it) {
        if (it->first == a) {
            if (set_compare(it->second,*b)) return true;
        }
    }

    return false;
}

void read_fact_filest::load_no_implication_list(std::string filename)    
{
    std::cout << ";; Loading prev-results: " << filename << std::endl;
    
    /* Reads Declarations of SMT file */
    std::ifstream input_prev(filename);
    if (!input_prev.is_open())
    {
        std::cout << "Cannot find the facts's prev. state file: " << filename << std::endl;
        std::cout << "** SKIP PREV. STATE LOADING... **" << std::endl;
        return;
    }
    
    std::string line;
    while(std::getline(input_prev, line))
    {
        std::istringstream iss(line);
        std::string token;
        std::set<std::string> subset;
        std::string fact;
        bool first=true;
        while(std::getline(iss, token, '\t'))  // but we can specify a different one
        {
            token.erase(std::remove(token.begin(), token.end(), '\t'), token.end());
            token.erase(std::remove(token.begin(), token.end(), ' '), token.end());
            if (first)
                fact=token;
            else
                subset.insert(token);
        }
        facts_no_implication_sets.insert(make_pair(fact, subset));
    }
    input_prev.close();
}

bool read_fact_filest::is_prev_no_implication(std::string a, std::set<std::string>* b)
{
    if (facts_no_implication_sets.empty()) return false;

    // Else check manually
    for(auto it = facts_no_implication_sets.begin(); it != facts_no_implication_sets.end(); ++it) {
        if (it->first == a) {
            if (set_compare(it->second,*b)) return true;
        }
    }

    return false;
}