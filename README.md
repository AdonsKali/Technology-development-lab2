ОТЧЕТ ПО ЛАБОРАТОРНОЙ РАБОТЕ №2
«Генератора кода с использованием паттерна "Абстрактная фабрика"»



Выполнил: Деревянкин Я.В
Группа: 932321



# Постановка задачи
Разработать расширяемую систему для генерации исходного кода на различных языках программирования (C++, C#, Java). Программа должна позволять:

1.Генерировать код классов с методами и беЗ, а также со вложенными элементами (оператор печати)

2.Поддерживать различные языки программирования

3.Обеспечить лёгкое добавление новых языков программирования

4.Генерировать корректный компилируемый код для каждого языка

# Предлагаемое решение
Реализовать программу с использованием паттерна проектирования "Абстрактная фабрика". Создать абстрактную фабрику FactoryLanguage, которая будет определять интерфейс для создания семейства связанных объектов. Создать конкретные фабрики для каждого языка (CppFactory, CSharpFactory, JavaFactory). Создать абстрактный класс Unit, представляющий синтаксическую конструкцию, и конкретные реализации для каждого языка.

# Сущности и классы
**1.Unit (Абстрактный базовый класс)**
Абстрактный класс для всех синтаксических конструкций. Определяет интерфейс для добавления вложенных элементов и генерации кода.

Методы:

add() - добавление вложенного элемента

compile() - генерация кода

generateShift() - генерация отступов

**2.FactoryLanguage (Абстрактная фабрика)**
Интерфейс для создания семейства связанных объектов языка программирования.

Методы:

CreateClass() - создание класса

CreateMethod() - создание метода

CreatePrint() - создание оператора вывода

**3.CppFactory (Конкретная фабрика C++)**
Реализация фабрики для создания C++ объектов.

**4.CSharpFactory (Конкретная фабрика C#)**
Реализация фабрики для создания C# объектов.

**5.JavaFactory (Конкретная фабрика Java)**
Реализация фабрики для создания Java объектов.

**6.CppClassUnit / CppMethodUnit / CppPrintUnit**
Представления классов, методов и операторов вывода для C++.

Модификаторы доступа: public:, protected:, private:

**7.CSharpClassUnit / CSharpMethodUnit / CSharpPrintUnit**
Представления классов, методов и операторов вывода для C#.

Модификаторы доступа: public, protected, private, internal

**8.JavaClassUnit / JavaMethodUnit / JavaPrintUnit**
Представления классов, методов и операторов вывода для Java.

Модификаторы доступа: public, protected, private, package-private

# UML

Ссылка: https://drive.google.com/file/d/1FoBTfm1hNew9HU7YhqJMhFKfYklcrjVZ/view?usp=sharing

# Инструкция пользователя

Программа не требует пользовательского ввода. При запуске автоматически генерируется код на трёх языках программирования.

# Тесты

Case 1: Генерация C++ кода
Результат:
```
class CppModifiersTest {
    public:
        void normalMethod() {
        }
        static void staticMethod() {
        }
        void constMethod() const {
        }
        virtual void virtualMethod() {
        }
        virtual void virtualConstMethod() const {
        }

};

class CppAccessTest {
    public:
        void publicMethod() {
        }

    protected:
        void protectedMethod() {
        }

    private:
        void privateMethod() {
        }

};

class CppBodyTest {
    public:
        static void methodWithBody() {
            printf("First line");
            printf("Second line");
            printf("Third line");
        }

};
```
Case 2: Генерация C# кода
```
class CSharpModifiersTest
{
    public
    {
        void normalMethod()
        {
        }
        static void staticMethod()
        {
        }
        virtual void virtualMethod()
        {
        }
    }

}

class CSharpAccessTest
{
    public
    {
        void publicMethod()
        {
        }
    }

    protected
    {
        void protectedMethod()
        {
        }
    }

    private
    {
        void privateMethod()
        {
        }
    }

    internal
    {
        void internalMethod()
        {
        }
    }

}

class CSharpBodyTest
{
    public
    {
        static void methodWithBody()
        {
            Console.WriteLine("First line");
            Console.WriteLine("Second line");
            Console.WriteLine("Third line");
        }
    }

}
```
Case 3: Генерация Java кода

```
class JavaModifiersTest {
    public {
        void normalMethod() {
        }
        static void staticMethod() {
        }
        final void finalMethod() {
        }
        synchronized void synchronizedMethod() {
        }
    }

}

class JavaAccessTest {
    public {
        void publicMethod() {
        }
    }

    protected {
        void protectedMethod() {
        }
    }

    private {
        void privateMethod() {
        }
    }

    {
        void packagePrivateMethod() {
        }
    }

}

class JavaBodyTest {
    public {
        static void methodWithBody() {
            System.out.println("First line");
            System.out.println("Second line");
            System.out.println("Third line");
        }
    }

}

```

