#ifndef CPP_FACTORY_H
#define CPP_FACTORY_H

#include "factorylanguage.h"

class CppFactory : public FactoryLanguage {
public:
    std::shared_ptr<IClassUnit> CreateClass(const std::string& name) override;
    std::shared_ptr<IMethodUnit> CreateMethod(const std::string& name,
                                       const std::string& returnType,
                                       Flags flags) override;
    std::shared_ptr<IPrintOperatorUnit> CreatePrint(const std::string& text) override;
};

#endif
