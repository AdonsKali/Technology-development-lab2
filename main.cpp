#include <iostream>
#include "csharpfactory.h"
#include "cppfactory.h"
#include "javafactory.h"
#include "factorylanguage.h"

std::string generateProgram(FactoryLanguage* factory, const std::string& className) {
    auto myClass = factory->CreateClass(className);
    myClass->add(
        factory->CreateMethod("testFunc1", "void", 0),
        0
        );
    myClass->add(
        factory->CreateMethod("testFunc2", "void", 1),
        2
        );
    myClass->add(
        factory->CreateMethod("testFunc3", "void", 6),
        0
        );

    auto method = factory->CreateMethod("testFunc4", "void", 1);
    method->add(factory->CreatePrint("Hello, world!\\n"), 0);
    myClass->add(method, 1);

    return myClass->compile();
}

int main() {
    std::cout << "=== Code Generator with Abstract Factory Pattern ===\n\n";

    CppFactory cppFactory;
    std::cout << generateProgram(&cppFactory, "MyCppClass");

    std::cout << "=====================================\n\n";

    CSharpFactory csharpFactory;
    std::cout << generateProgram(&csharpFactory, "MyCSharpClass");

    std::cout << "=====================================\n\n";

    JavaFactory javafactory;
    std::cout << generateProgram(&javafactory, "MyJavaClass");

    return 0;
}
