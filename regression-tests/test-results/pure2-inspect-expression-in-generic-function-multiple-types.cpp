
#define CPP2_USE_MODULES         Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"



//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-inspect-expression-in-generic-function-multiple-types.cpp2"
[[nodiscard]] auto main() -> int;
    

#line 20 "pure2-inspect-expression-in-generic-function-multiple-types.cpp2"
auto test_generic(auto const& x, auto const& msg) -> void;
    

//=== Cpp2 function definitions =================================================

#line 1 "pure2-inspect-expression-in-generic-function-multiple-types.cpp2"
[[nodiscard]] auto main() -> int{
    std::variant<int,int,double> v {42.0}; 
    std::any a {cpp2::as_<std::string>("xyzzy")}; 
    std::optional<int> o {}; 

    test_generic(3.14, "double");
    test_generic(v,    "variant<int, int, double>");
    test_generic(a,    "any");
    test_generic(o,    "optional<int>");

    static_cast<void>(CPP2_UFCS_TEMPLATE(emplace, (<0>), v, 1));
    a = 2;
    o = 3;
    test_generic(42,   "int");
    test_generic(std::move(v), "variant<int, int, double>");
    test_generic(std::move(a), "any");
    test_generic(std::move(o), "optional<int>");
}

auto test_generic(auto const& x, auto const& msg) -> void{
    std::cout 
        << std::setw(30) << msg 
        << " value is " 
        << [&] () -> std::string { auto&& __expr = x;
            if (cpp2::is<int>(__expr)) { if constexpr( requires{"integer " + std::to_string(cpp2::as<int>(x));} ) if constexpr( std::is_convertible_v<CPP2_TYPEOF(("integer " + std::to_string(cpp2::as<int>(x)))),std::string> ) return "integer " + std::to_string(cpp2::as<int>(x)); else return std::string{}; else return std::string{}; }
            else if (cpp2::is<std::string>(__expr)) { if constexpr( requires{'"' + cpp2::as<std::string>(x) + '"';} ) if constexpr( std::is_convertible_v<CPP2_TYPEOF(('"' + cpp2::as<std::string>(x) + '"')),std::string> ) return '"' + cpp2::as<std::string>(x) + '"'; else return std::string{}; else return std::string{}; }
            else return "not an int or string"; }
        () 
        << "\n";
}

