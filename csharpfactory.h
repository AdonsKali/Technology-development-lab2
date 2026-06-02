#ifndef CSHARP_FACTORY_H
#define CSHARP_FACTORY_H

#include "factorylanguage.h"

class CSharpFactory : public FactoryLanguage {
public:
    std::shared_ptr<IClassUnit> CreateClass(const std::string& name) override;
    std::shared_ptr<IMethodUnit> CreateMethod(const std::string& name,
                                       const std::string& returnType,
                                       Flags flags) override;
    std::shared_ptr<IPrintOperatorUnit> CreatePrint(const std::string& text) override;
};

#endif
