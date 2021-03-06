## Оглавление

1. [Практическое занятие 1 UML концепт. модель и диаграмма классов](#Практическое-занятие-1-UML-концепт.-модель-и-диаграмма-классов)
2. [Практическое занятие 2 4diac IEC61499](#Практическое-занятие-2-4diac-IEC61499)
    
## Практическое занятие 1 UML концепт. модель и диаграмма классов
Вини пух хочет долететь до меда. У него есть вентилятор. Вентилятором у вентилятора можно управлять тягой от 0 до 100%. У Винипуха есть высотомер, который позволяет определять высоту. Необходимо разработать систему управления.

1. Разработать концептуальную модель (сущности и связи между сущностями)

2. Разработать диаграмму классов

    2.1. Определяются прецеденты в виде use-case диаграммы (Взлет, посадка, экстренная посадка)

    2.2. Для каждого из прецедентов - диаграмму последовательности (действующее лицо + система черным ящиком)

    2.3. Для каждой операции из диаграммы последовательности - диаграмма последовательности ее реализации при помощи классов

    2.4. Перенести методы в диаграмму классов

    Практически:

    2.5. Нарисовать детальную диаграмму последовательности для посадки. И перенести операции в диаграмму классов

    2.6. Высокоуровневую диаграмму последовательности для экстренной посадки. Детальную диаграмму последовательности и перенести методы в диаграмму классов

3. Разработать макет кода и залить на github

Инструменты:

umbrello uml modeller - https://download.kde.org/stable/umbrello/latest/win64/umbrello-mingw64-2.32.0-126.1-setup.exe

argo uml  (требует java)

Литература

1. https://www.ozon.ru/context/detail/id/3105480/
Крег Ларман - применение UML и шаблонов проектирования
2. https://habr.com/ru/post/511798/
3. https://ru.wikipedia.org/wiki/ПИД-регулятор


[:arrow_up:Оглавление](#Оглавление)
___
## Практическое занятие 2 4diac IEC61499

Разработка программ для систем управления с использованием 4diac

1. Установить 4diac IDE 12.2 (https://www.eclipse.org/4diac/en_dow.php)

2. Установить forte для PC (там же)

3. Разработать и запустить программу с моргающими лампочками и по инструкции запустить в forte

https://www.eclipse.org/4diac/documentation/html/4diacIDE/use4diacLocally.html

4. Разработать программу формирующую на выходе пилу

- при помощи экспорта в папку эспортировать проект и выложить на github

- ссылку на проекту прислать на почту преподавателю

Литература

1. Установить 4diac и forte для x86 (https://www.eclipse.org/4diac/en_dow.php)

2. Попробовать простое приложение https://www.eclipse.org/4diac/en_help.php?helppage=html/4diacIDE/use4diacLocally.html

3. Туториал http://akshaim.github.io/4DIAC/4DIAC.html

[:arrow_up:Оглавление](#Оглавление)
____
