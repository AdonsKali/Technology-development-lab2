#include <iostream>
#include "csharpfactory.h"
#include "cppfactory.h"
#include "javafactory.h"
#include "factorylanguage.h"

// ==================== C++ ====================
// Проверка модификаторов методов
std::string testCppModifiers(FactoryLanguage* factory, const std::string& className) {
    auto myClass = factory->CreateClass(className);
    myClass->add(factory->CreateMethod("normalMethod", "void", 0), 0);
    myClass->add(factory->CreateMethod("staticMethod", "void", 1), 0);
    myClass->add(factory->CreateMethod("constMethod", "void", 2), 0);
    myClass->add(factory->CreateMethod("virtualMethod", "void", 4), 0);
    myClass->add(factory->CreateMethod("virtualConstMethod", "void", 6), 0);
    return myClass->compile();
}

// Проверка модификаторов доступа
std::string testCppAccess(FactoryLanguage* factory, const std::string& className) {
    auto myClass = factory->CreateClass(className);
    myClass->add(factory->CreateMethod("publicMethod", "void", 0), 0);
    myClass->add(factory->CreateMethod("protectedMethod", "void", 0), 1);
    myClass->add(factory->CreateMethod("privateMethod", "void", 0), 2);
    return myClass->compile();
}

// Проверка методов с телом (вложенные операторы)
std::string testCppBody(FactoryLanguage* factory, const std::string& className) {
    auto myClass = factory->CreateClass(className);
    auto method = factory->CreateMethod("methodWithBody", "void", 1);
    method->add(factory->CreatePrint("First line"), 0);
    method->add(factory->CreatePrint("Second line"), 0);
    method->add(factory->CreatePrint("Third line"), 0);
    myClass->add(method, 0);
    return myClass->compile();
}

// ==================== C# ====================
// Проверка модификаторов методов
std::string testCSharpModifiers(FactoryLanguage* factory, const std::string& className) {
    auto myClass = factory->CreateClass(className);
    myClass->add(factory->CreateMethod("normalMethod", "void", 0), 0);
    myClass->add(factory->CreateMethod("staticMethod", "void", 1), 0);
    myClass->add(factory->CreateMethod("virtualMethod", "void", 4), 0);
    return myClass->compile();
}

// Проверка модификаторов доступа
std::string testCSharpAccess(FactoryLanguage* factory, const std::string& className) {
    auto myClass = factory->CreateClass(className);
    myClass->add(factory->CreateMethod("publicMethod", "void", 0), 0);
    myClass->add(factory->CreateMethod("protectedMethod", "void", 0), 1);
    myClass->add(factory->CreateMethod("privateMethod", "void", 0), 2);
    myClass->add(factory->CreateMethod("internalMethod", "void", 0), 3);
    return myClass->compile();
}

// Проверка методов с телом (вложенные операторы)
std::string testCSharpBody(FactoryLanguage* factory, const std::string& className) {
    auto myClass = factory->CreateClass(className);
    auto method = factory->CreateMethod("methodWithBody", "void", 1);
    method->add(factory->CreatePrint("First line"), 0);
    method->add(factory->CreatePrint("Second line"), 0);
    method->add(factory->CreatePrint("Third line"), 0);
    myClass->add(method, 0);
    return myClass->compile();
}

// ==================== JAVA ====================
// Проверка модификаторов методов
std::string testJavaModifiers(FactoryLanguage* factory, const std::string& className) {
    auto myClass = factory->CreateClass(className);
    myClass->add(factory->CreateMethod("normalMethod", "void", 0), 0);
    myClass->add(factory->CreateMethod("staticMethod", "void", 1), 0);
    myClass->add(factory->CreateMethod("finalMethod", "void", 2), 0);
    myClass->add(factory->CreateMethod("synchronizedMethod", "void", 8), 0);
    return myClass->compile();
}

// Проверка модификаторов доступа
std::string testJavaAccess(FactoryLanguage* factory, const std::string& className) {
    auto myClass = factory->CreateClass(className);
    myClass->add(factory->CreateMethod("publicMethod", "void", 0), 0);
    myClass->add(factory->CreateMethod("protectedMethod", "void", 0), 1);
    myClass->add(factory->CreateMethod("privateMethod", "void", 0), 2);
    myClass->add(factory->CreateMethod("packagePrivateMethod", "void", 0), 3);
    return myClass->compile();
}

// Проверка методов с телом
std::string testJavaBody(FactoryLanguage* factory, const std::string& className) {
    auto myClass = factory->CreateClass(className);
    auto method = factory->CreateMethod("methodWithBody", "void", 1);
    method->add(factory->CreatePrint("First line"), 0);
    method->add(factory->CreatePrint("Second line"), 0);
    method->add(factory->CreatePrint("Third line"), 0);
    myClass->add(method, 0);
    return myClass->compile();
}


int main() {
    std::cout << "=== Code Generator with Abstract Factory Pattern ===\n\n";

    std::cout << "==================== C++ ====================\n\n";

    CppFactory cppFactory;

    std::cout << "[TEST 1] (STATIC, CONST, VIRTUAL):\n";
    std::cout << testCppModifiers(&cppFactory, "CppModifiersTest") << "\n";

    std::cout << "[TEST 2] (public, protected, private):\n";
    std::cout << testCppAccess(&cppFactory, "CppAccessTest") << "\n";

    std::cout << "[TEST 3] (inputs operators):\n";
    std::cout << testCppBody(&cppFactory, "CppBodyTest") << "\n";

    std::cout << "==================== C# ====================\n\n";

    CSharpFactory csharpFactory;

    std::cout << "[TEST 1] (STATIC, VIRTUAL):\n";
    std::cout << testCSharpModifiers(&csharpFactory, "CSharpModifiersTest") << "\n";

    std::cout << "[TEST 2] (public, protected, private, internal):\n";
    std::cout << testCSharpAccess(&csharpFactory, "CSharpAccessTest") << "\n";

    std::cout << "[TEST 3] (inputs operators):\n";
    std::cout << testCSharpBody(&csharpFactory, "CSharpBodyTest") << "\n";

    std::cout << "==================== JAVA ====================\n\n";

    JavaFactory javaFactory;

    std::cout << "[TEST 1] (STATIC, FINAL, SYNCHRONIZED):\n";
    std::cout << testJavaModifiers(&javaFactory, "JavaModifiersTest") << "\n";

    std::cout << "[TEST 2] (public, protected, private, package-private):\n";
    std::cout << testJavaAccess(&javaFactory, "JavaAccessTest") << "\n";

    std::cout << "[TEST 3] (inputs operators):\n";
    std::cout << testJavaBody(&javaFactory, "JavaBodyTest") << "\n";

    return 0;
}
