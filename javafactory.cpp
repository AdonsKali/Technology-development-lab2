#include "javafactory.h"
#include "javaunit.h"

std::shared_ptr<Unit> JavaFactory::CreateClass(const std::string& name) {
    return std::make_shared<JavaClassUnit>(name);
}

std::shared_ptr<Unit> JavaFactory::CreateMethod(const std::string& name,
                                                const std::string& returnType,
                                                Unit::Flags flags) {
    return std::make_shared<JavaMethodUnit>(name, returnType, flags);
}

std::shared_ptr<Unit> JavaFactory::CreatePrint(const std::string& text) {
    return std::make_shared<JavaPrintUnit>(text);
}