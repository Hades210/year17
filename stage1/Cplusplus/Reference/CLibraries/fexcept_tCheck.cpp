// file : fegetexceptflagCheck.cpp
// int fegetexceptflag (fexcept_t* flagp, int excepts);
// Get floating-point exception flags
// fexcept_t : Floating-point exceptions type
// excepts: see feclearexcept
// c++ 11 only

// fesetexceptflag
// int fesetexceptflag(const fexcept_t* flagp, int excepts);
// set floating-point exception flags
// C++ 11 only
// Programs calling this function shall ensure that prgama FENV_ACCESS is enabled for the call.

#include <iostream>
#include <cfenv>



