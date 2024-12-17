#pragma once
#include <boost/program_options.hpp>
#include <iostream>
#include <string>
#include <fstream>
#include "log.h"
#include "base.h"
#include "communicator.h"
#include "error.h"

/** @file
 * @author Шурманов И.С.
 * @version 1.0
 * @date 17.12.2024
 * @brief Заголовочный файл для интерфейса
 */

/** @brief Класс интерфейса
 * @details Получает порт, по умолчанию 33333.
 * Парсер выполняет чтение операндов командной строки.
 * Устанавливается соединение с базой данных и журналом лога.
 * Выполняется вызов справки.
 */
class interface {
    int port; ///< Переменная с номером порта
    string basefile; ///< Путь к файлу базы данных
    string logfile; ///< Путь к файлу журнала

public:
    interface() : port(33333), basefile("base.txt"), logfile("log.txt") {} ///< Конструктор по умолчанию

    /**
     * @brief Парсер
     * 
     * @details Читает операнды командной строки.
     * В случае передачи операнда -h производится вызов справки.
     * @param [in] argc Количество операндов.
     * @param [in] argv Значение операндов.
     * @throw crit_err в случае передачи некорректного значения порта.
     * @return true или false в случае корректной или некорректной передачи аргументов.
     */
    bool parser(int argc, const char** argv);

    /**
     * @brief Установка соединения с базой данных и журналом лога
     * 
     * @details Устанавливает соединение с базой данных и журналом лога.
     * @param [in] basefile Путь к файлу базы данных.
     * @param [in] logfile Путь к файлу журнала лога.
     */
    void setup_connection(const std::string& basefile, const std::string& logfile);

    /**
     * @brief Справка
     * 
     * Вызов справки.
     * @param [in] opts Описание опций для справки.
     */
    void spravka(const boost::program_options::options_description& opts);

    /**
     * @brief Получение порта
     * 
     * Этот метод передает значение порта в коммуникатор.
     * @return Номер порта.
     */
    int get_port() const { return port; }

    /**
     * @brief Получение пути к базе данных
     * @return Путь к базе данных.
     */
    std::string get_base() { return basefile; }

    /**
     * @brief Получение пути к журналу лога
     * @return Путь к журналу лога.
     */
    std::string get_log() { return logfile; }
};
