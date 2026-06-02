#ifndef JAVA_UNIT_H
#define JAVA_UNIT_H

#include "Unit.h"
#include <vector>
#include <string>
#include <memory>

class JavaClassUnit : public IClassUnit {
public:
    enum AccessModifier {
        PUBLIC,
        PROTECTED,
        PRIVATE,
        PACKAGE
    };

    static const std::vector<std::string> ACCESS_MODIFIERS;

    explicit JavaClassUnit(const std::string& name);
    void add(const std::shared_ptr<Unit>& unit, Flags flags) override;
    std::string compile(unsigned int level = 0) const override;

private:
    std::string m_name;
    using Fields = std::vector<std::shared_ptr<Unit>>;
    std::vector<Fields> m_fields;
};

class JavaMethodUnit : public IMethodUnit {
public:
    enum Modifier {
        STATIC = 1,
        FINAL = 1 << 1,     
        ABSTRACT = 1 << 2,   
        SYNCHRONIZED = 1 << 3
    };

    JavaMethodUnit(const std::string& name, const std::string& returnType, Flags flags);
    void add(const std::shared_ptr<Unit>& unit, Flags flags = 0) override;
    std::string compile(unsigned int level = 0) const override;

private:
    std::string m_name;
    std::string m_returnType;
    Flags m_flags;
    std::vector<std::shared_ptr<Unit>> m_body;
};

class JavaPrintUnit : public IPrintOperatorUnit {
public:
    explicit JavaPrintUnit(const std::string& text);
    std::string compile(unsigned int level = 0) const override;

private:
    std::string m_text;
};

#endif
