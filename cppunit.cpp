#include "cppunit.h"

const std::vector<std::string> CppClassUnit::ACCESS_MODIFIERS = {
    "public:",
    "protected:",
    "private:"
};


CppClassUnit::CppClassUnit(const std::string& name) : m_name(name) {
    m_fields.resize(ACCESS_MODIFIERS.size());
}

void CppClassUnit::add(const std::shared_ptr<Unit>& unit, Flags flags) {
    int accessModifier = PRIVATE;
    if (flags <ACCESS_MODIFIERS.size()) {
        accessModifier = flags;
    }
    m_fields[accessModifier].push_back(unit);
}

std::string CppClassUnit::compile(unsigned int level) const {
    std::string result = generateShift(level) + "class " + m_name + " {\n";

    for (size_t i = 0; i <ACCESS_MODIFIERS.size(); ++i) {
        if (m_fields[i].empty()) continue;

        result += generateShift(level + 1) + ACCESS_MODIFIERS[i] + "\n";
        for (const auto& f : m_fields[i]) {
            result += f->compile(level + 2);
        }
        result += "\n";
    }

    result += generateShift(level) + "};\n";
    return result;
}

CppMethodUnit::CppMethodUnit(const std::string& name, const std::string& returnType, Flags flags)
    : m_name(name), m_returnType(returnType), m_flags(flags) {}

void CppMethodUnit::add(const std::shared_ptr<Unit>& unit, Flags) {
    m_body.push_back(unit);
}

std::string CppMethodUnit::compile(unsigned int level) const {
    std::string result = generateShift(level);

    if (m_flags & STATIC) result += "static ";
    else if (m_flags & VIRTUAL) result += "virtual ";

    result += m_returnType + " " + m_name + "()";
    if (m_flags & CONST) result += " const";
    result += " {\n";

    for (const auto& b : m_body) {
        result += b->compile(level + 1);
    }

    result += generateShift(level) + "}\n";
    return result;
}

CppPrintUnit::CppPrintUnit(const std::string& text) : m_text(text) {}

std::string CppPrintUnit::compile(unsigned int level) const {
    return generateShift(level) + "printf(\"" + m_text + "\");\n";
}
