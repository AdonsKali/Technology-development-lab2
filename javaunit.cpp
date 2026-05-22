#include "javaunit.h"

const std::vector<std::string> JavaClassUnit::ACCESS_MODIFIERS = {
    "public",     
    "protected",   
    "private",     
    ""             
};

JavaClassUnit::JavaClassUnit(const std::string& name) : m_name(name) {
    m_fields.resize(ACCESS_MODIFIERS.size());
}

void JavaClassUnit::add(const std::shared_ptr<Unit>& unit, Flags flags) {
    int accessModifier = PACKAGE;
    if (flags < ACCESS_MODIFIERS.size()) {
        accessModifier = flags;
    }
    m_fields[accessModifier].push_back(unit);
}

std::string JavaClassUnit::compile(unsigned int level) const {
    std::string result = generateShift(level) + "class " + m_name + " {\n";

    for (size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i) {
        if (m_fields[i].empty()) continue;

        if (!ACCESS_MODIFIERS[i].empty()) {
            result += generateShift(level + 1) + ACCESS_MODIFIERS[i] + " {\n";
        } else {
            result += generateShift(level + 1) + "{\n";  
        }
        
        for (const auto& f : m_fields[i]) {
            result += f->compile(level + 2);
        }
        result += generateShift(level + 1) + "}\n\n";
    }

    result += generateShift(level) + "}\n";
    return result;
}

JavaMethodUnit::JavaMethodUnit(const std::string& name, const std::string& returnType, Flags flags)
    : m_name(name), m_returnType(returnType), m_flags(flags) {}

void JavaMethodUnit::add(const std::shared_ptr<Unit>& unit, Flags) {
    m_body.push_back(unit);
}

std::string JavaMethodUnit::compile(unsigned int level) const {
    std::string result = generateShift(level);

    if (m_flags & STATIC) result += "static ";
    if (m_flags & FINAL) result += "final ";
    if (m_flags & ABSTRACT) result += "abstract ";
    if (m_flags & SYNCHRONIZED) result += "synchronized ";

    result += m_returnType + " " + m_name + "()";

    if (m_flags & ABSTRACT) {
        result += ";\n";
    } else {
        result += " {\n";
        for (const auto& b : m_body) {
            result += b->compile(level + 1);
        }
        result += generateShift(level) + "}\n";
    }
    return result;
}

JavaPrintUnit::JavaPrintUnit(const std::string& text) : m_text(text) {}

std::string JavaPrintUnit::compile(unsigned int level) const {
    return generateShift(level) + "System.out.println(\"" + m_text + "\");\n";
}