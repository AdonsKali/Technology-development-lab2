#ifndef FACTORY_LANGUAGE_H
#define FACTORY_LANGUAGE_H

#include <memory>
#include <string>
#include "Unit.h"


class FactoryLanguage {
public:
    virtual ~FactoryLanguage() = default;
    virtual std::shared_ptr<IClassUnit> CreateClass(const std::string& name) = 0;
    virtual std::shared_ptr<IMethodUnit> CreateMethod(const std::string& name, const std::string& returnType, Flags flags) = 0;
    virtual std::shared_ptr<IPrintOperatorUnit> CreatePrint(const std::string& text) = 0;
};

#endif
