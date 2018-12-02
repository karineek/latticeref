#include "lattice_core.h"

#include <set>
#include <string>
#include <assert.h>

#include <chrono>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std::chrono_literals;

// basic file operations
#include <iostream>
#include <fstream>
using namespace std;

#include "mathsat.h" // mathsat5

#include <z3++.h> // Z3
using namespace z3;

lattice_core::lattice_core(read_fact_filest* _facts_container, std::string _base_name)
    : m_facts_container(_facts_container),
      m_base_name(_base_name)
{ }

lattice_core::lattice_core(const lattice_core& orig) {
}

lattice_core::~lattice_core() {
}

std::string lattice_core::build_query_and(std::set<std::string>* curr_set)
{
    if (curr_set->size() == 0 ) return "";
    
    std::string query = "";
    if (curr_set->size() > 1)
        query += "(and " + facts_and_subset_to_string(curr_set) + ")\n"; // Add facts
    else
        query += facts_and_subset_to_string(curr_set) + " \n"; // Add facts
    
    return query;
}

std::string lattice_core::facts_and_subset_to_string(std::set<std::string>* curr_set)
{
    std::string ret="";
    
    for(std::set<std::string>::iterator it = curr_set->begin(); it != curr_set->end(); ++it) {
        ret += m_facts_container->get_and_fact(*it) + "\n";
    }
    
    return ret;
}

bool lattice_core::is_sat(std::set<std::string>* curr_set)
{
    /* Create the formula */
    std::string query = build_query_and(curr_set);
    
    
    /***************  Z3  *******************/
    std::string assert_str = "\n (assert ";
    std::string z3_query =  "(declare-fun x () Real)\n(declare-fun y () Real)\n(declare-fun z () Real)\n(declare-fun r () Real)\n(declare-fun k () Int)"
                + assert_str + m_facts_container->get_decl_str() + ")" 
                + assert_str + query + ")\n(check-sat-using qfnra-nlsat)";
   
    /* Replace |cos#0| in cos for z3++ */
    size_t index = 0;
    while (true) {
         /* Locate the substring to replace. */
         index = z3_query.find("|_cos#0|", index);
         if (index == std::string::npos) break;

         /* Make the replacement.  "|_cos#0|" */
         z3_query.replace(index, 8,   "cos     ");

         /* Advance index forward so the next iteration doesn't pick it up as well. */
         index += 8;
    }
    
    /* Try with z3 */
    z3::context query_context;
    Z3_ast parsed = Z3_parse_smtlib2_string(query_context,z3_query.c_str(),0,0,0,0,0,0);
    z3::expr e(query_context, parsed);
    z3::solver s(query_context);
    s.add(e);
    Z3_error_code error = query_context.check_error();
    if (error != Z3_OK)
    {
        std::cout << ">> ERROR:  Z3 query context error, exit" << std::endl;
        exit(0);
    }
    z3::check_result r = s.check();
    if (r == z3::sat) return true;
    if (r == z3::unsat) return false;
   
    /* r is unknown: continue and try with mathsat5 */
 
    
    /***************  MathSAT5  *******************/
    std::string mathsat_query = m_facts_container->get_decl_str() + 
                "   (and (= (g_cos x) (sin (+ (/ pi 2) x)))\n" + query + ")\n";

    /* Same for mathsat5 */
    index = 0;
    while (true) {
         /* Locate the substring to replace. */
         index = mathsat_query.find("|_cos#0|", index);
         if (index == std::string::npos) break;

         /* Make the replacement.   "|_cos#0|" */
         mathsat_query.replace(index, 8, "g_cos   ");

         /* Advance index forward so the next iteration doesn't pick it up as well. */
         index += 8;
    }
    
    /* Create the solver - mathsat 5*/
    msat_config cfg = msat_create_config();
    /* enable interpolation support */
    msat_set_option(cfg, "theory.na.nta_enabled", "true");
    msat_set_option(cfg, "theory.na.nta_sat_mode", "2");
    
    msat_env env = msat_create_env(cfg);
    assert(!MSAT_ERROR_ENV(env));
    msat_type rat_tp = msat_get_rational_type(env);
    assert(!MSAT_ERROR_TYPE(rat_tp));    
    msat_type int_tp = msat_get_integer_type(env);
    assert(!MSAT_ERROR_TYPE(int_tp));
    
    /* Add vars */
    msat_decl var_x = msat_declare_function(env, "x", rat_tp);
    assert(!MSAT_ERROR_DECL(var_x));
    msat_decl var_y = msat_declare_function(env, "y", rat_tp);
    assert(!MSAT_ERROR_DECL(var_y));
    msat_decl var_z = msat_declare_function(env, "z", rat_tp);
    assert(!MSAT_ERROR_DECL(var_z));
    msat_decl var_r = msat_declare_function(env, "r", rat_tp);
    assert(!MSAT_ERROR_DECL(var_r));
    msat_decl var_k = msat_declare_function(env, "k", int_tp);
    assert(!MSAT_ERROR_DECL(var_k));    
    msat_type paramtps[1];
    paramtps[0] = rat_tp;
    msat_type func_tp = msat_get_function_type(env, paramtps, 1, rat_tp);
    msat_decl d = msat_declare_function(env, "g_cos", func_tp);
    assert(!MSAT_ERROR_DECL(d));
    
    /* Add the formula as a string to the solver */
    msat_term formula = msat_from_string(env, mathsat_query.c_str());
    assert(!MSAT_ERROR_TERM(formula));
    
    /* Assert the formula */
    int res = msat_assert_formula(env, formula);
    assert(res == 0);
    
    /* check satisfiability */
    return (msat_solve(env) == msat_result::MSAT_SAT); // Unknown and UNSAT are here the same, if we don't know, we don't put the facts together
}

void lattice_core::write2log(std::set<std::string>* curr_set, std::string name)
{
    std::ofstream out_lattice;
    out_lattice.open(name, std::ofstream::out | std::ofstream::app);
    
    for(std::set<std::string>::iterator it = curr_set->begin(); it != curr_set->end(); ++it) {
        out_lattice << *it << "\t";
    }
    out_lattice << "\n";
    out_lattice.close();
}

bool lattice_core::is_set_coexist(std::set<std::string>* curr_set) 
{   
    // First check the cache
    if (m_facts_container->is_prev_SAT_and_facts(curr_set)) return true;
    if (m_facts_container->is_prev_UNSAT_and_facts(curr_set)) return false;
    
    // We need to test against a SAT solver
    std::mutex m;
    std::condition_variable cv;
    int retValue;

    std::thread t([&cv, &retValue, curr_set, this]() 
    {
        retValue = this->is_sat(curr_set);
        cv.notify_one();
    });
    
    t.detach();
    
    {
        std::unique_lock<std::mutex> l(m);
        if(cv.wait_for(l, 3000s) == std::cv_status::timeout) {
            // Add to UNSAT list, and exit
            write2log(curr_set, m_base_name+"_UNSAT_lattice.txt");
            throw std::runtime_error("Timeout");
        }
    }    

    // Add to UNSAT list
    if (!retValue) write2log(curr_set, m_base_name+"_UNSAT_lattice.txt");
    // Else, keep the set as an element: write curr_set
    else write2log(curr_set, m_base_name+"_SAT_lattice.txt");
        
    // Return value
    return retValue;
}

void lattice_core::checkNadd2lattice(std::set<std::string>* curr_set, std::set<std::string>* candidates) 
{
    if (!curr_set) return;
    if (!candidates) return;
    if (!is_set_coexist(curr_set)) return;
    
    // End the recursion
    if (candidates->size() == 0) return;
        
    // Continue the build
    std::set<std::string>* temp_candidates = new std::set<std::string>();
    temp_candidates->insert(candidates->begin(), candidates->end());
    for(std::set<std::string>::iterator it = candidates->begin(); it != candidates->end(); ++it) {
        std::string curr = *it;
        temp_candidates->erase(curr);
        
        curr_set->insert(curr);
        checkNadd2lattice(curr_set, temp_candidates);
        curr_set->erase(curr);
    }
}


