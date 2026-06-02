#ifndef CSHARP_UNIT_H
#define CSHARP_UNIT_H

#include "Unit.h"
#include <vector>
#include <string>
#include <memory>

class CSharpClassUnit : public IClassUnit {
public:
    enum AccessModifier {
        PUBLIC,
        PROTECTED,
        PRIVATE,
        INTERNAL
    };

    static const std::vector<std::string> ACCESS_MODIFIERS;

    explicit CSharpClassUnit(const std::string& name);
    void add(const std::shared_ptr<Unit>& unit, Flags flags) override;
    std::string compile(unsigned int level = 0) const override;

private:
    std::string m_name;
    using Fields = std::vector<std::shared_ptr<Unit>>;
    std::vector<Fields> m_fields;
};


class CSharpMethodUnit : public IMethodUnit {
public:
    enum Modifier {
        STATIC = 1,
        CONST = 1 << 1,
        VIRTUAL = 1 << 2
    };

    CSharpMethodUnit(const std::string& name, const std::string& returnType, Flags flags);
    void add(const std::shared_ptr<Unit>& unit, Flags flags = 0) override;
    std::string compile(unsigned int level = 0) const override;

private:
    std::string m_name;
    std::string m_returnType;
    Flags m_flags;
    std::vector<std::shared_ptr<Unit>> m_body;
};


class CSharpPrintUnit : public IPrintOperatorUnit {
public:
    explicit CSharpPrintUnit(const std::string& text);
    std::string compile(unsigned int level = 0) const override;

private:
    std::string m_text;
};

#endif
