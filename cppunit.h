#ifndef CPP_UNIT_H
#define CPP_UNIT_H

#include "Unit.h"
#include <vector>


class CppClassUnit : public Unit {
public:
    enum AccessModifier { PUBLIC, PROTECTED, PRIVATE };
    static const std::vector<std::string> ACCESS_MODIFIERS;

    explicit CppClassUnit(const std::string& name);
    void add(const std::shared_ptr<Unit>& unit, Flags flags) override;
    std::string compile(unsigned int level = 0) const override;

private:
    std::string m_name;
    using Fields = std::vector<std::shared_ptr<Unit>>;
    std::vector<Fields> m_fields;
};


class CppMethodUnit : public Unit {
public:
    enum Modifier { STATIC = 1, CONST = 1 << 1, VIRTUAL = 1 << 2 };

    CppMethodUnit(const std::string& name, const std::string& returnType, Flags flags);
    void add(const std::shared_ptr<Unit>& unit, Flags flags = 0) override;
    std::string compile(unsigned int level = 0) const override;

private:
    std::string m_name;
    std::string m_returnType;
    Flags m_flags;
    std::vector<std::shared_ptr<Unit>> m_body;
};



class CppPrintUnit : public Unit {
public:
    explicit CppPrintUnit(const std::string& text);
    std::string compile(unsigned int level = 0) const override;

private:
    std::string m_text;
};

#endif
