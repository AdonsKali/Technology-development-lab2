#include "CSharpUnit.h"


const std::vector<std::string> CSharpClassUnit::ACCESS_MODIFIERS = {
    "public",
    "protected",
    "private",
    "internal"
};

CSharpClassUnit::CSharpClassUnit(const std::string& name) : m_name(name) {
    m_fields.resize(ACCESS_MODIFIERS.size());
}

void CSharpClassUnit::add(const std::shared_ptr<Unit>& unit, Flags flags) {
    int accessModifier = PRIVATE;
    if (flags < ACCESS_MODIFIERS.size()) {
        accessModifier = flags;
    }
    m_fields[accessModifier].push_back(unit);
}

std::string CSharpClassUnit::compile(unsigned int level) const {
    std::string result = generateShift(level) + "class " + m_name + "\n";
    result += generateShift(level) + "{\n";

    for (size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i) {
        if (m_fields[i].empty()) continue;

        result += generateShift(level + 1) + ACCESS_MODIFIERS[i] + "\n";
        result += generateShift(level + 1) + "{\n";
        for (const auto& f : m_fields[i]) {
            result += f->compile(level + 2);
        }
        result += generateShift(level + 1) + "}\n\n";
    }

    result += generateShift(level) + "}\n";
    return result;
}


CSharpMethodUnit::CSharpMethodUnit(const std::string& name, const std::string& returnType, Flags flags)
    : m_name(name), m_returnType(returnType), m_flags(flags) {}

void CSharpMethodUnit::add(const std::shared_ptr<Unit>& unit, Flags) {
    m_body.push_back(unit);
}

std::string CSharpMethodUnit::compile(unsigned int level) const {
    std::string result = generateShift(level);

    if (m_flags & STATIC) {
        result += "static ";
    } else if (m_flags & VIRTUAL) {
        result += "virtual ";
    }

    result += m_returnType + " " + m_name + "()";

    result += "\n" + generateShift(level) + "{\n";

    for (const auto& b : m_body) {
        result += b->compile(level + 1);
    }

    result += generateShift(level) + "}\n";
    return result;
}

CSharpPrintUnit::CSharpPrintUnit(const std::string& text) : m_text(text) {}

std::string CSharpPrintUnit::compile(unsigned int level) const {
    return generateShift(level) + "Console.WriteLine(\"" + m_text + "\");\n";
}
