

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"



//=== Cpp2 type definitions and function declarations ===========================


#include <algorithm>
#include <vector>

#line 5 "mixed-captures-in-expressions-and-postconditions.cpp2"
[[nodiscard]] auto main() -> int;
    

#line 17 "mixed-captures-in-expressions-and-postconditions.cpp2"
extern std::vector<int> vec;

auto insert_at(cpp2::in<int> where, cpp2::in<int> val) -> void;


//=== Cpp2 function definitions =================================================


#line 5 "mixed-captures-in-expressions-and-postconditions.cpp2"
[[nodiscard]] auto main() -> int{
    std::vector<std::string> vec {
            "hello", "2022"}; 

    std::string y {"\n"}; 
    auto callback {[_0 = (&y)](auto const& x) -> void{std::cout << x << *cpp2::assert_not_null(_0); }}; 

    std::ranges::for_each(vec, callback);
    y = "-ish\n";
    std::ranges::for_each(std::move(vec), std::move(callback));
}

std::vector<int> vec {}; 

auto insert_at(cpp2::in<int> where, cpp2::in<int> val) -> void

#line 22 "mixed-captures-in-expressions-and-postconditions.cpp2"
{
    cpp2::Default.expects(cpp2::cmp_less_eq(0,where) && cpp2::cmp_less_eq(where,CPP2_UFCS_0(ssize, vec)), "");
    auto post_21_5 = cpp2::finally_success([_0 = CPP2_UFCS_0(ssize, vec)]{cpp2::Default.expects(CPP2_UFCS_0(ssize, vec)==_0 + 1, "");} );
#line 23 "mixed-captures-in-expressions-and-postconditions.cpp2"
    static_cast<void>(CPP2_UFCS(insert, vec, CPP2_UFCS_0(begin, vec) + where, val));
}

