## Calculator

Приложение состоит из исполняемого файла - .exe, который имеет консольный интерфейс и способен
вычислять выражения с операциями + - / * ().

**Ввод: 16 + 4 * (3 – 1)**

**Вывод: 24**

При запуске приложение обращается в папку ./plugins, и из каждой dll загружает и распознает
соответствующую функцию.

*./calc.exe*

*./plugins/funcsin.dll*

*./plugins/funcdeg.dll*

Что приводит к возможности использовать эти функции сразу же после запуска приложения, делая
валидными вычисления:
2^4 + Sin(90)

Каждый плагин содержит ровно одну функцию. Имя файла dll не должно участвовать на определение самой
функции и ее имени.

Необходимо определить и обработать исключительные случаи (некорректная dll, нет никаких dll,
какая-то из функций бросает исключение, например, Ln(-100) )

Оценивается корректность работы с памятью и исключениями, архитектура приложения, работоспособность.