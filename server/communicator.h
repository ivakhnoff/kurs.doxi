#pragma once
#include <string>
#include <vector>
#include <map>
#include "log.h"
#include "error.h"

using namespace std;

/** @file
 * @author Шурманов И.С.
 * @version 1.0
 * @date 17.12.2024
 * @brief Заголовочный файл для коммуникатора сервера
 */

/** @brief Класс коммуникатора
 * @details Устанавливает соединение с сервером, производит авторизацию клиента.
 * В качестве метода хэширования выбран SHA224.
 */
class communicator
{
public:
    /**
     * @brief Соединение с сервером
     * 
     * @details Производит соединение с сервером, авторизует пользователя.
     * Передает вектор с данными для вычисления в класс calc.
     * @param [in] port Номер порта.
     * @param [in] base Контейнер с базой данных.
     * @param [in] l Указатель на объект logger для записи всех событий в журнал.
     * @throw crit_err, если произошел сбой на этапе соединения с сервером, на этапе авторизации или отправки данных.
     */
    int connection(int port, std::map<std::string, std::string> base, logger* l);

    /**
     * @brief Формирование хэша методом SHA224
     * 
     * @details Производит формирование хэша методом SHA224 библиотеки Crypto++.
     * Формирует хэш соли и пароля.
     * @param [in] input_str Входная строка для хэширования.
     * @return Результат хэширования.
     */
    std::string sha224(std::string input_str);
};
