#include "csharpfactory.h"
#include "csharpunit.h"

std::shared_ptr<Unit> CSharpFactory::CreateClass(const std::string& name) {
    return std::make_shared<CSharpClassUnit>(name);
}

std::shared_ptr<Unit> CSharpFactory::CreateMethod(const std::string& name,
                                                  const std::string& returnType,
                                                  Unit::Flags flags) {
    return std::make_shared<CSharpMethodUnit>(name, returnType, flags);
}

std::shared_ptr<Unit> CSharpFactory::CreatePrint(const std::string& text) {
    return std::make_shared<CSharpPrintUnit>(text);
}
