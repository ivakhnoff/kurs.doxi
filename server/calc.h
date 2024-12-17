#pragma once
#include <vector>
#include <iostream>
#include <limits>
#include <stdexcept> // Для исключений
#include <boost/numeric/conversion/cast.hpp> // Для проверки на переполнение

/** @file
 * @author Шурманов И.С.
 * @version 1.0
 * @date 17.12.2024
 * @brief Заголовочный файл для модуля вычислений
 */

/** @brief Класс для вычисления суммы элементов вектора
 * @details Вектор указывается в параметрах конструктора.
 * Для получения результата вычислений используется метод send_res.
 */
class calc {
public:
    uint32_t res; ///< Переменная, в которую будет записан результат

    /**
     * @brief Конструктор для вычисления суммы элементов вектора
     * @param [in] chisla Вектор данных. Не должен быть пустым.
     * @throw no_crit_err, если вектор пуст.
     * @throw boost::numeric::positive_overflow, если происходит переполнение.
     */
    calc(std::vector<uint32_t> chisla);

    /**
     * @brief Метод для отправки результата
     * @return Результат вычислений.
     */
    uint32_t send_res();
};
