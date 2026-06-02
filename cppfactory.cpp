#include "cppfactory.h"
#include "cppunit.h"

std::shared_ptr<IClassUnit> CppFactory::CreateClass(const std::string& name) {
    return std::make_shared<CppClassUnit>(name);
}

std::shared_ptr<IMethodUnit> CppFactory::CreateMethod(const std::string& name,
                                               const std::string& returnType,
                                               Flags flags) {
    return std::make_shared<CppMethodUnit>(name, returnType, flags);
}

std::shared_ptr<IPrintOperatorUnit> CppFactory::CreatePrint(const std::string& text) {
    return std::make_shared<CppPrintUnit>(text);
}
