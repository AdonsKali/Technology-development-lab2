#ifndef UNIT_H
#define UNIT_H

#include <string>
#include <memory>

using Flags = unsigned int;

class Unit
{
public:
    virtual ~Unit() = default;
    virtual std::string compile(unsigned int level = 0) const = 0;

protected:
    std::string generateShift(unsigned int level) const {
        static const std::string DEFAULT_SHIFT = "    ";
        std::string result;
        for (unsigned int i = 0; i < level; ++i) {
            result += DEFAULT_SHIFT;
        }
        return result;
    }
};

class IClassUnit : public Unit
{
public:
    virtual ~IClassUnit() = default;
    virtual void add(const std::shared_ptr<Unit>& unit, Flags flags = 0) = 0;
};

class IMethodUnit : public Unit
{
public:
    virtual ~IMethodUnit() = default;
    virtual void add(const std::shared_ptr<Unit>& unit, Flags flags = 0) = 0;
};

class IPrintOperatorUnit : public Unit {};

#endif
