//
//  CompositeSimpsonsRule.hpp
//  CompositeSimpsonsRule
//
//

#ifndef CompositeSimpsonsRule_hpp
#define CompositeSimpsonsRule_hpp

#include <stdio.h>
#include <functional>
#include <iostream>

double compositeSimpsons(double a, double b, unsigned long n,
                         std::function<double(double)> func);

#endif /* CompositeSimpsonsRule_hpp */
