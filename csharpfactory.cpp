#include "csharpfactory.h"
#include "csharpunit.h"

std::shared_ptr<IClassUnit> CSharpFactory::CreateClass(const std::string& name) {
    return std::make_shared<CSharpClassUnit>(name);
}

std::shared_ptr<IMethodUnit> CSharpFactory::CreateMethod(const std::string& name,
                                                  const std::string& returnType,
                                                  Flags flags) {
    return std::make_shared<CSharpMethodUnit>(name, returnType, flags);
}

std::shared_ptr<IPrintOperatorUnit> CSharpFactory::CreatePrint(const std::string& text) {
    return std::make_shared<CSharpPrintUnit>(text);
}
