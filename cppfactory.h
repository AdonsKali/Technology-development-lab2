#ifndef CPP_FACTORY_H
#define CPP_FACTORY_H

#include "factorylanguage.h"

class CppFactory : public FactoryLanguage {
public:
    std::shared_ptr<Unit> CreateClass(const std::string& name) override;
    std::shared_ptr<Unit> CreateMethod(const std::string& name,
                                       const std::string& returnType,
                                       Unit::Flags flags) override;
    std::shared_ptr<Unit> CreatePrint(const std::string& text) override;
};

#endif
