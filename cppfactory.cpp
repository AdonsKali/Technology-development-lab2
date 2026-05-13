#include "cppfactory.h"
#include "cppunit.h"

std::shared_ptr<Unit> CppFactory::CreateClass(const std::string& name) {
    return std::make_shared<CppClassUnit>(name);
}

std::shared_ptr<Unit> CppFactory::CreateMethod(const std::string& name,
                                               const std::string& returnType,
                                               Unit::Flags flags) {
    return std::make_shared<CppMethodUnit>(name, returnType, flags);
}

std::shared_ptr<Unit> CppFactory::CreatePrint(const std::string& text) {
    return std::make_shared<CppPrintUnit>(text);
}
