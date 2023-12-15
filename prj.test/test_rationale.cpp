#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <rational/rational.hpp>

TEST_CASE("Конструкторы и методы доступа к числителю и знаменателю") {
    SUBCASE("Конструктор по умолчанию") {
        Rational r;
        CHECK(r.num() == 0);
        CHECK(r.den() == 1);
    }

    SUBCASE("Конструктор с числителем") {
        Rational r(5);
        CHECK(r.num() == 5);
        CHECK(r.den() == 1);
    }

    SUBCASE("Конструктор с числителем и знаменателем") {
        Rational r(3, 4);
        CHECK(r.num() == 3);
        CHECK(r.den() == 4);
    }
}

TEST_CASE("Арифметические операции с рациональными числами") {
    Rational r1(1, 2);
    Rational r2(1, 3);

    SUBCASE("Сложение") {
        Rational sum = r1 + r2;
        CHECK(sum.num() == 5);
        CHECK(sum.den() == 6);
    }

    SUBCASE("Вычитание") {
        Rational diff = r1 - r2;
        CHECK(diff.num() == 1);
        CHECK(diff.den() == 6);
    }

    SUBCASE("Умножение") {
        Rational prod = r1 * r2;
        CHECK(prod.num() == 1);
        CHECK(prod.den() == 6);
    }

    SUBCASE("Деление") {
        Rational quotient = r1 / r2;
        CHECK(quotient.num() == 3);
        CHECK(quotient.den() == 2);
    }
}

TEST_CASE("Операции сравнения рациональных чисел") {
    Rational r1(1, 2);
    Rational r2(1, 3);
    Rational r3(1, 2);

    CHECK(r1 == r3);
    CHECK(r1 != r2);
    CHECK(r1 > r2);
    CHECK(r1 >= r2);
    CHECK(r2 < r1);
    CHECK(r2 <= r1);
}

TEST_CASE("Унарные операции с рациональными числами") {
    Rational r1(2, 3);
    Rational r2 = -r1;

    CHECK(r2.num() == -2);
    CHECK(r2.den() == 3);
}

TEST_CASE("Операции присваивания с рациональными числами") {
    Rational r1(1, 2);
    Rational r2(1, 3);

    r1 += r2;
    CHECK(r1.num() == 5);
    CHECK(r1.den() == 6);
    r1 = Rational(1, 2);
    r2 = Rational(1, 3);
    r1 -= r2;
    CHECK(r1.num() == 1);
    CHECK(r1.den() == 6);
    r1 = Rational(1, 2);
    r2 = Rational(1, 3);
    r1 *= r2;
    CHECK(r1.num() == 1);
    CHECK(r1.den() == 6);
    r1 = Rational(1, 2);
    r2 = Rational(1, 3);
    r1 /= r2;
    CHECK(r1.num() == 3);
    CHECK(r1.den() == 2);
}

TEST_CASE("Операции ввода и вывода для рациональных чисел") {
    std::stringstream ss;

    SUBCASE("Вывод в поток") {
        Rational r(3, 5);
        ss << r;
        CHECK(ss.str() == "3/5");
    }

    SUBCASE("Ввод из потока") {
        std::istringstream iss("5/6");
        Rational rational;
        iss >> rational;
        CHECK(rational.num() == 5);
        CHECK(rational.den() == 6);
    }
    SUBCASE("Некорректный ввод") {
        std::istringstream iss("invalid_input");
        Rational rational;
        iss >> rational;
        CHECK(iss.fail());
    }
}

TEST_CASE("Дополнительные тесты для рациональных чисел") {
    SUBCASE("Проверка деления на ноль") {
        Rational r(3, 4);
        Rational zero;

        CHECK_THROWS_AS(r / zero, std::invalid_argument);
    }

    SUBCASE("Операторы с целыми числами") {
        Rational r(3, 4);

        SUBCASE("Сложение с целым числом") {
            Rational sum = r + 2;
            CHECK(sum.num() == 11);
            CHECK(sum.den() == 4);
        }

        SUBCASE("Вычитание целого числа") {
            Rational diff = r - 1;
            CHECK(diff.num() == -1);
            CHECK(diff.den() == 4);
        }

        SUBCASE("Умножение на целое число") {
            Rational prod = r * 2;
            CHECK(prod.num() == 3);
            CHECK(prod.den() == 2);
        }

        SUBCASE("Деление на целое число") {
            Rational quotient = r / 2;
            CHECK(quotient.num() == 3);
            CHECK(quotient.den() == 8);
        }
    }

    SUBCASE("Операторы для работы с объектами класса вне класса") {
        Rational r1(3, 4);
        Rational r2(1, 3);

        SUBCASE("Сложение с рациональным числом") {
            Rational sum = r1 + r2;
            CHECK(sum.num() == 13);
            CHECK(sum.den() == 12);
        }

        SUBCASE("Вычитание рационального числа") {
            Rational diff = r1 - r2;
            CHECK(diff.num() == 5);
            CHECK(diff.den() == 12);
        }

        SUBCASE("Умножение на рациональное число") {
            Rational prod = r1 * r2;
            CHECK(prod.num() == 1);
            CHECK(prod.den() == 4);
        }

        SUBCASE("Деление на рациональное число") {
            Rational quotient = r1 / r2;
            CHECK(quotient.num() == 9);
            CHECK(quotient.den() == 4);
        }

        SUBCASE("Операторы с целыми числами") {
            SUBCASE("Сложение с целым числом") {
                Rational sum = r1 + 2;
                CHECK(sum.num() == 11);
                CHECK(sum.den() == 4);
            }

            SUBCASE("Вычитание целого числа") {
                Rational diff = r1 - 1;
                CHECK(diff.num() == -1);
                CHECK(diff.den() == 4);
            }

            SUBCASE("Умножение на целое число") {
                Rational prod = r1 * 2;
                CHECK(prod.num() == 3);
                CHECK(prod.den() == 2);
            }

            SUBCASE("Деление на целое число") {
                Rational quotient = r1 / 2;
                CHECK(quotient.num() == 3);
                CHECK(quotient.den() == 8);
            }

            SUBCASE("Операторы для целых чисел слева") {
                SUBCASE("Сложение с целым числом") {
                    Rational sum = 2 + r1;
                    CHECK(sum.num() == 11);
                    CHECK(sum.den() == 4);
                }

                SUBCASE("Вычитание из целого числа") {
                    Rational diff = 2 - r1;
                    CHECK(diff.num() == 5);
                    CHECK(diff.den() == 4);
                }

                SUBCASE("Умножение на целое число") {
                    Rational prod = 2 * r1;
                    CHECK(prod.num() == 3);
                    CHECK(prod.den() == 2);
                }

                SUBCASE("Деление целого числа") {
                    Rational quotient = 2 / r1;
                    CHECK(quotient.num() == 8);
                    CHECK(quotient.den() == 3);
                }
            }
        }
    }
}
