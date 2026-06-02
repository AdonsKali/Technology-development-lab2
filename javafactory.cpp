#include "javafactory.h"
#include "javaunit.h"

std::shared_ptr<IClassUnit> JavaFactory::CreateClass(const std::string& name) {
    return std::make_shared<JavaClassUnit>(name);
}

std::shared_ptr<IMethodUnit> JavaFactory::CreateMethod(const std::string& name,
                                                const std::string& returnType,
                                                Flags flags) {
    return std::make_shared<JavaMethodUnit>(name, returnType, flags);
}

std::shared_ptr<IPrintOperatorUnit> JavaFactory::CreatePrint(const std::string& text) {
    return std::make_shared<JavaPrintUnit>(text);
}
